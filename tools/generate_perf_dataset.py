#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT))

from tb.cocotb.awr_payload_model import (  # noqa: E402
    SAMPLE_SLOT_NUM,
    SLOT_TOTAL_ALIGNED,
    build_expected_slot_bytes,
    calc_expected_payload_size,
    gen_awr_payload,
)


DT_FS = 0x00
DT_FE = 0x01
DT_LS = 0x02
DT_LE = 0x03
DT_AWR_RAW = 0x2A

VC_MASK = 0x3
DT_MASK = 0x3F
SHORT_DATA_MASK = 0xFFFF
WORD_COUNT_MASK = 0xFFFF
CRC16_INIT = 0xFFFF
CRC16_POLY_REVERSED = 0x8408


def parse_size(text: str) -> int:
    units = (
        ("gib", 1024**3),
        ("mib", 1024**2),
        ("kib", 1024),
        ("gb", 1000**3),
        ("mb", 1000**2),
        ("kb", 1000),
        ("b", 1),
    )

    value = text.strip().lower()
    if value.isdigit():
        return int(value)

    for suffix, scale in units:
        if value.endswith(suffix):
            number = value[: -len(suffix)].strip()
            try:
                return int(float(number) * scale)
            except ValueError as exc:
                raise argparse.ArgumentTypeError(f"invalid size: {text}") from exc

    raise argparse.ArgumentTypeError(f"unsupported size suffix: {text}")


def csi2_calc_ecc(header3: bytes) -> int:
    if len(header3) != 3:
        raise ValueError(f"header3 must be exactly 3 bytes, got {len(header3)}")

    d = [(header3[i // 8] >> (i % 8)) & 0x1 for i in range(24)]

    p0 = d[0] ^ d[1] ^ d[2] ^ d[4] ^ d[5] ^ d[7] ^ d[10] ^ d[11] ^ d[13] ^ d[16] ^ d[20] ^ d[21] ^ d[22] ^ d[23]
    p1 = d[0] ^ d[1] ^ d[3] ^ d[4] ^ d[6] ^ d[8] ^ d[10] ^ d[12] ^ d[14] ^ d[17] ^ d[20] ^ d[21] ^ d[22] ^ d[23]
    p2 = d[0] ^ d[2] ^ d[3] ^ d[5] ^ d[6] ^ d[9] ^ d[11] ^ d[12] ^ d[15] ^ d[18] ^ d[20] ^ d[21] ^ d[22]
    p3 = d[1] ^ d[2] ^ d[3] ^ d[7] ^ d[8] ^ d[9] ^ d[13] ^ d[14] ^ d[15] ^ d[19] ^ d[20] ^ d[21] ^ d[23]
    p4 = d[4] ^ d[5] ^ d[6] ^ d[7] ^ d[8] ^ d[9] ^ d[16] ^ d[17] ^ d[18] ^ d[19] ^ d[20] ^ d[22] ^ d[23]
    p5 = d[10] ^ d[11] ^ d[12] ^ d[13] ^ d[14] ^ d[15] ^ d[16] ^ d[17] ^ d[18] ^ d[19] ^ d[21] ^ d[22] ^ d[23]

    return (p0 << 0) | (p1 << 1) | (p2 << 2) | (p3 << 3) | (p4 << 4) | (p5 << 5)


def csi2_calc_crc16(payload: bytes) -> int:
    crc = CRC16_INIT
    for byte in payload:
        crc ^= byte
        for _ in range(8):
            if crc & 0x1:
                crc = (crc >> 1) ^ CRC16_POLY_REVERSED
            else:
                crc >>= 1
    return crc & 0xFFFF


def _data_id(dt: int, vc: int) -> int:
    if not 0 <= dt <= DT_MASK:
        raise ValueError(f"dt out of range: {dt}")
    if not 0 <= vc <= VC_MASK:
        raise ValueError(f"vc out of range: {vc}")
    return ((vc & VC_MASK) << 6) | (dt & DT_MASK)


def build_short_packet(dt: int, vc: int, short_data: int = 0) -> bytes:
    if not 0 <= short_data <= SHORT_DATA_MASK:
        raise ValueError(f"short_data out of range: {short_data}")

    header3 = bytes(
        (
            _data_id(dt, vc),
            short_data & 0xFF,
            (short_data >> 8) & 0xFF,
        )
    )
    return header3 + bytes((csi2_calc_ecc(header3),))


def build_long_packet(dt: int, vc: int, payload: bytes) -> bytes:
    if len(payload) > WORD_COUNT_MASK:
        raise ValueError(f"payload too large for CSI-2 WC field: {len(payload)} bytes")

    header3 = bytes(
        (
            _data_id(dt, vc),
            len(payload) & 0xFF,
            (len(payload) >> 8) & 0xFF,
        )
    )
    return header3 + bytes((csi2_calc_ecc(header3),)) + payload + csi2_calc_crc16(payload).to_bytes(2, "little")


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Generate a large deterministic dataset for continuous read/write performance tests.")
    parser.add_argument("--size", type=parse_size, default=parse_size("400MiB"), help="Approximate output size. Supports B/KB/MB/GB/KiB/MiB/GiB. Default: 400MiB")
    parser.add_argument("--format", choices=("slot", "payload", "csi"), default="slot", help="Output record format. Default: slot")
    parser.add_argument("--output", type=Path, help="Output file path. Default: sim_build/perf_data/perf_<format>_<size>.bin")
    parser.add_argument("--ns", type=int, default=SAMPLE_SLOT_NUM, help=f"Samples per chirp payload, 0..{SAMPLE_SLOT_NUM}. Default: {SAMPLE_SLOT_NUM}")
    parser.add_argument("--chirps-per-frame", type=int, default=256, help="For --format csi, chirps per frame. Default: 256")
    parser.add_argument("--vc", type=int, default=0, help="CSI virtual channel for --format csi. Default: 0")
    parser.add_argument("--chirp-profile", type=int, default=-1, help="Fixed chirp profile 0..15. Default: vary with frame index")
    parser.add_argument("--pattern", choices=("ramp", "const", "channel_tag", "random"), default="ramp", help="Sample pattern. Default: ramp")
    parser.add_argument("--seed", type=int, default=0, help="Seed base used when pattern=random. Default: 0")
    parser.add_argument("--buffer-size", type=parse_size, default=parse_size("1MiB"), help="File write buffer size. Default: 1MiB")
    return parser.parse_args(argv)


def make_payload(*, chirp_index: int, chirp_num: int, frame_index: int, args: argparse.Namespace) -> bytes:
    chirp_profile = args.chirp_profile if args.chirp_profile >= 0 else (frame_index & 0xF)
    cq_data = ((frame_index & 0xFFFF) << 48) | ((chirp_index & 0xFFFF) << 16) | (chirp_num & 0xFFFF)
    seed = args.seed + chirp_index if args.pattern == "random" else None
    return gen_awr_payload(
        chirp_num=chirp_num,
        ns=args.ns,
        chirp_profile=chirp_profile,
        cq_data=cq_data,
        pattern=args.pattern,
        seed=seed,
    )


def generate_slot_dataset(args: argparse.Namespace, fout) -> tuple[int, int, int]:
    written = 0
    chirp_index = 0
    frame_index = 0

    while written < args.size:
        chirp_num = chirp_index & 0xFFF
        payload = make_payload(chirp_index=chirp_index, chirp_num=chirp_num, frame_index=frame_index, args=args)
        slot = build_expected_slot_bytes(payload)
        fout.write(slot)
        written += len(slot)
        chirp_index += 1
        if chirp_num == 0xFFF:
            frame_index += 1

    return written, chirp_index, frame_index + 1


def generate_payload_dataset(args: argparse.Namespace, fout) -> tuple[int, int, int]:
    written = 0
    chirp_index = 0
    frame_index = 0

    while written < args.size:
        chirp_num = chirp_index & 0xFFF
        payload = make_payload(chirp_index=chirp_index, chirp_num=chirp_num, frame_index=frame_index, args=args)
        fout.write(payload)
        written += len(payload)
        chirp_index += 1
        if chirp_num == 0xFFF:
            frame_index += 1

    return written, chirp_index, frame_index + 1


def generate_csi_dataset(args: argparse.Namespace, fout) -> tuple[int, int, int]:
    written = 0
    chirp_index = 0
    frame_index = 0
    chirp_bytes = calc_expected_payload_size(args.ns) + 14

    while written < args.size:
        remaining = args.size - written
        frame_chirps = args.chirps_per_frame
        if remaining > 0:
            needed_chirps = max(1, (max(remaining - 8, 0) + chirp_bytes - 1) // chirp_bytes)
            frame_chirps = min(frame_chirps, needed_chirps)

        frame_chirp_start = chirp_index & 0xFFF
        fout.write(build_short_packet(DT_FS, args.vc, 0))
        written += 4

        for local_chirp in range(frame_chirps):
            chirp_num = (frame_chirp_start + local_chirp) & 0xFFF
            payload = make_payload(chirp_index=chirp_index, chirp_num=chirp_num, frame_index=frame_index, args=args)
            fout.write(build_short_packet(DT_LS, args.vc, chirp_num))
            fout.write(build_long_packet(DT_AWR_RAW, args.vc, payload))
            fout.write(build_short_packet(DT_LE, args.vc, chirp_num))
            written += 4 + (4 + len(payload) + 2) + 4
            chirp_index += 1

        last_chirp_num = (frame_chirp_start + frame_chirps - 1) & 0xFFF
        fout.write(build_short_packet(DT_FE, args.vc, last_chirp_num))
        written += 4
        frame_index += 1

    return written, chirp_index, frame_index


def main(argv: list[str]) -> int:
    args = parse_args(argv)

    if not 0 <= args.ns <= SAMPLE_SLOT_NUM:
        raise SystemExit(f"--ns must be 0..{SAMPLE_SLOT_NUM}, got {args.ns}")
    if not 1 <= args.chirps_per_frame <= 4096:
        raise SystemExit("--chirps-per-frame must be 1..4096")
    if not 0 <= args.vc <= 3:
        raise SystemExit("--vc must be 0..3")
    if args.chirp_profile > 15:
        raise SystemExit("--chirp-profile must be -1 or 0..15")

    if args.output is None:
        perf_dir = REPO_ROOT / "sim_build" / "perf_data"
        perf_dir.mkdir(parents=True, exist_ok=True)
        args.output = perf_dir / f"perf_{args.format}_{args.size}.bin"
    else:
        args.output.parent.mkdir(parents=True, exist_ok=True)

    generator = {
        "slot": generate_slot_dataset,
        "payload": generate_payload_dataset,
        "csi": generate_csi_dataset,
    }[args.format]

    with args.output.open("wb", buffering=args.buffer_size) as fout:
        written, chirps_written, frames_written = generator(args, fout)

    meta = {
        "output": str(args.output),
        "format": args.format,
        "target_bytes": args.size,
        "actual_bytes": written,
        "overshoot_bytes": written - args.size,
        "ns": args.ns,
        "slot_bytes": SLOT_TOTAL_ALIGNED if args.format == "slot" else None,
        "payload_bytes_per_chirp": calc_expected_payload_size(args.ns),
        "chirps_written": chirps_written,
        "frames_written": frames_written,
        "chirps_per_frame": args.chirps_per_frame if args.format == "csi" else None,
        "vc": args.vc if args.format == "csi" else None,
        "chirp_profile": args.chirp_profile,
        "pattern": args.pattern,
        "seed": args.seed,
    }

    meta_path = args.output.with_suffix(args.output.suffix + ".json")
    meta_path.write_text(json.dumps(meta, indent=2) + "\n", encoding="utf-8")

    print(json.dumps(meta, indent=2))
    print(f"metadata: {meta_path}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
