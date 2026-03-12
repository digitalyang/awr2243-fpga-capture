from __future__ import annotations

import random
from dataclasses import dataclass
from typing import Any

import cocotb
from cocotb.triggers import RisingEdge

from awr_payload_model import (
    CQ_BYTES,
    RX_HEADER_BYTES_EACH as RX_HEADER_BYTES,
    RX_HEADER_BYTES_TOTAL as RX_HEADERS_TOTAL_BYTES,
    SAMPLE_BYTES as SAMPLE_PACKED_BYTES,
    gen_awr_payload as model_gen_awr_payload,
    gen_one_sample as model_gen_one_sample,
    pack_rx_header as model_pack_rx_header,
    pack_u12_list_le as model_pack_u12_list_le,
    sign_to_u12 as model_sign_to_u12,
)


# -----------------------------------------------------------------------------
# CSI-2 constants
# -----------------------------------------------------------------------------
VC_MASK = 0x3
DT_MASK = 0x3F
SHORT_DATA_MASK = 0xFFFF
WORD_COUNT_MASK = 0xFFFF
U12_MASK = 0xFFF
U12_SIGN_BIT = 0x800
U12_SIGNED_MIN = -(1 << 11)
U12_SIGNED_MAX = (1 << 11) - 1

DT_FS = 0x00
DT_FE = 0x01
DT_LS = 0x02
DT_LE = 0x03
DT_AWR_RAW = 0x2A

VC_DEFAULT = 0
NUM_LANES_DEFAULT = 4

RX_HEADER_COUNT = 4
SAMPLE_COMPONENTS = 8

CRC16_INIT = 0xFFFF
CRC16_POLY_REVERSED = 0x8408


# -----------------------------------------------------------------------------
# DUT port assumptions for send coroutines
# Adjust these name tuples if your DUT uses different names.
# -----------------------------------------------------------------------------
CLOCK_CANDIDATES = ("clk_i", "clk", "clock")

BYTE_DATA_CANDIDATES = ("byte_data", "data_i", "rx_byte_data", "rx_data")
BYTE_VALID_CANDIDATES = ("byte_valid", "valid_i", "rx_byte_valid", "rx_valid")
BYTE_READY_CANDIDATES = ("byte_ready", "ready_o", "rx_byte_ready", "rx_ready")

PPI_DATA_CANDIDATES = ("rxdata_hs", "rxdatahs", "lane_data", "lane_bytes")
PPI_VALID_CANDIDATES = ("rxvalidhs", "rx_valid_hs", "lane_valid", "valid_mask")
PPI_READY_CANDIDATES = ("rxreadyhs", "rx_ready_hs", "lane_ready", "ready")


@dataclass(frozen=True)
class PpiCycle:
    lane_bytes: list[int]
    valid_mask: int


def _check_range(name: str, value: int, min_value: int, max_value: int) -> None:
    if not (min_value <= value <= max_value):
        raise ValueError(f"{name} out of range: {value} not in [{min_value}, {max_value}]")


def _data_id(dt: int, vc: int) -> int:
    _check_range("dt", dt, 0, DT_MASK)
    _check_range("vc", vc, 0, VC_MASK)
    return ((vc & VC_MASK) << 6) | (dt & DT_MASK)


def _resolve_signal(dut: Any, candidates: tuple[str, ...], what: str):
    for name in candidates:
        if hasattr(dut, name):
            return getattr(dut, name)
    raise AttributeError(f"Unable to find DUT signal for {what}. Tried: {', '.join(candidates)}")


def _resolve_optional_signal(dut: Any, candidates: tuple[str, ...]):
    for name in candidates:
        if hasattr(dut, name):
            return getattr(dut, name)
    return None


def _resolve_clock(dut: Any):
    return _resolve_signal(dut, CLOCK_CANDIDATES, "clock")


def _pack_lane_bundle(lane_bytes: list[int]) -> int:
    packed = 0
    for lane_idx, value in enumerate(lane_bytes):
        packed |= (value & 0xFF) << (8 * lane_idx)
    return packed


async def _drive_with_optional_ready(clk, valid_sig, ready_sig) -> None:
    while True:
        await RisingEdge(clk)
        if ready_sig is None or int(ready_sig.value):
            return


# -----------------------------------------------------------------------------
# Layer 1: payload generation
# -----------------------------------------------------------------------------
def sign_to_u12(x: int) -> int:
    return model_sign_to_u12(x)


def pack_u12_list_le(values: list[int]) -> bytes:
    return model_pack_u12_list_le(values)


def pack_rx_header(chirp_profile: int, channel_id: int, chirp_num: int) -> bytes:
    return model_pack_rx_header(channel_id=channel_id, chirp_profile=chirp_profile, chirp_num=chirp_num)


def gen_one_sample(sample_idx: int, pattern: str = "ramp", rng=None) -> list[int]:
    return model_gen_one_sample(sample_idx=sample_idx, pattern=pattern, rng=rng)


def gen_awr_payload(
    chirp_num: int,
    ns: int,
    chirp_profile: int = 0,
    cq_data: int = 0,
    pattern: str = "ramp",
    seed: int | None = None,
) -> bytes:
    return model_gen_awr_payload(
        chirp_num=chirp_num,
        ns=ns,
        chirp_profile=chirp_profile,
        cq_data=cq_data,
        pattern=pattern,
        seed=seed,
    )


# -----------------------------------------------------------------------------
# Layer 2: CSI-2 packet generation
# -----------------------------------------------------------------------------
def csi2_calc_ecc(header3: bytes) -> int:
    """CSI-2 packet header ECC for the first 24 bits.

    The returned byte carries the 6 Hamming parity bits in [5:0].
    Bits [7:6] are zero.
    """

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
    """CSI-2 long packet payload CRC16.

    Polynomial: x^16 + x^12 + x^5 + 1
    Reflected implementation with init 0xFFFF.
    """

    crc = CRC16_INIT
    for byte in payload:
        crc ^= byte
        for _ in range(8):
            if crc & 0x1:
                crc = (crc >> 1) ^ CRC16_POLY_REVERSED
            else:
                crc >>= 1
    return crc & 0xFFFF


def build_short_packet(dt: int, vc: int, short_data: int = 0) -> bytes:
    _check_range("short_data", short_data, 0, SHORT_DATA_MASK)
    header3 = bytes(
        (
            _data_id(dt, vc),
            short_data & 0xFF,
            (short_data >> 8) & 0xFF,
        )
    )
    ecc = csi2_calc_ecc(header3)
    return header3 + bytes((ecc,))


def build_long_packet(dt: int, vc: int, payload: bytes) -> bytes:
    if len(payload) > WORD_COUNT_MASK:
        raise ValueError(f"payload too large for CSI-2 WC field: {len(payload)} bytes")

    word_count = len(payload)
    header3 = bytes(
        (
            _data_id(dt, vc),
            word_count & 0xFF,
            (word_count >> 8) & 0xFF,
        )
    )
    ecc = csi2_calc_ecc(header3)
    crc16 = csi2_calc_crc16(payload)
    return header3 + bytes((ecc,)) + payload + crc16.to_bytes(2, byteorder="little", signed=False)


def build_awr_chirp_packets(
    chirp_num: int,
    ns: int,
    vc: int = 0,
    chirp_profile: int = 0,
    cq_data: int = 0,
    pattern: str = "ramp",
) -> list[bytes]:
    payload = gen_awr_payload(
        chirp_num=chirp_num,
        ns=ns,
        chirp_profile=chirp_profile,
        cq_data=cq_data,
        pattern=pattern,
        seed=chirp_num,
    )
    return [
        build_short_packet(dt=DT_LS, vc=vc, short_data=chirp_num & SHORT_DATA_MASK),
        build_long_packet(dt=DT_AWR_RAW, vc=vc, payload=payload),
        build_short_packet(dt=DT_LE, vc=vc, short_data=chirp_num & SHORT_DATA_MASK),
    ]


def build_awr_frame_packets(
    num_chirps: int,
    ns: int,
    vc: int = 0,
    chirp_profile: int = 0,
    cq_data: int = 0,
    pattern: str = "ramp",
) -> list[bytes]:
    _check_range("num_chirps", num_chirps, 1, 0x7FF)

    packets = [build_short_packet(dt=DT_FS, vc=vc, short_data=0)]
    for chirp_num in range(num_chirps):
        packets.extend(
            build_awr_chirp_packets(
                chirp_num=chirp_num,
                ns=ns,
                vc=vc,
                chirp_profile=chirp_profile,
                cq_data=cq_data,
                pattern=pattern,
            )
        )
    packets.append(build_short_packet(dt=DT_FE, vc=vc, short_data=(num_chirps - 1) & SHORT_DATA_MASK))
    return packets


# -----------------------------------------------------------------------------
# Layer 3: byte / lane / PPI conversion
# -----------------------------------------------------------------------------
def flatten_packets(packets: list[bytes]) -> bytes:
    return b"".join(packets)


def bytes_to_lanes(data: bytes, num_lanes: int = 4) -> list[list[int]]:
    _check_range("num_lanes", num_lanes, 1, 32)
    lanes = [[] for _ in range(num_lanes)]
    for idx, byte in enumerate(data):
        lanes[idx % num_lanes].append(byte)
    return lanes


def bytes_to_ppi_cycles(data: bytes, num_lanes: int = 4) -> list[tuple[list[int], int]]:
    _check_range("num_lanes", num_lanes, 1, 32)
    cycles: list[tuple[list[int], int]] = []

    for offset in range(0, len(data), num_lanes):
        chunk = list(data[offset : offset + num_lanes])
        lane_bytes = chunk + [0] * (num_lanes - len(chunk))
        valid_mask = 0
        for lane_idx in range(len(chunk)):
            valid_mask |= 1 << lane_idx
        cycles.append((lane_bytes, valid_mask))

    return cycles


async def send_packet_bytes(dut, data: bytes) -> None:
    """Send one CSI-2 byte per clock.

    Assumed DUT signals:
    - data:  one of BYTE_DATA_CANDIDATES
    - valid: one of BYTE_VALID_CANDIDATES
    - ready: optional, one of BYTE_READY_CANDIDATES
    - clock: one of CLOCK_CANDIDATES

    If your DUT uses different port names, update the candidate tuples above.
    """

    clk = _resolve_clock(dut)
    data_sig = _resolve_signal(dut, BYTE_DATA_CANDIDATES, "byte stream data")
    valid_sig = _resolve_signal(dut, BYTE_VALID_CANDIDATES, "byte stream valid")
    ready_sig = _resolve_optional_signal(dut, BYTE_READY_CANDIDATES)

    valid_sig.value = 0
    data_sig.value = 0
    await RisingEdge(clk)

    for byte in data:
        data_sig.value = byte
        valid_sig.value = 1
        await _drive_with_optional_ready(clk, valid_sig, ready_sig)

    valid_sig.value = 0
    data_sig.value = 0
    await RisingEdge(clk)


async def send_csi2_lane_bytes(
    dut,
    data: bytes,
    num_lanes: int = 4,
) -> None:
    """Send a lane-interleaved CSI-2 byte stream as one lane bundle per cycle.

    Assumed packed interface:
    - rxdata_hs[8*num_lanes-1:0] / rxvalidhs[num_lanes-1:0]
    - optional rxreadyhs

    If your DUT uses different port names, update PPI_*_CANDIDATES.
    """

    clk = _resolve_clock(dut)
    data_sig = _resolve_signal(dut, PPI_DATA_CANDIDATES, "lane/PPI packed data")
    valid_sig = _resolve_signal(dut, PPI_VALID_CANDIDATES, "lane/PPI valid mask")
    ready_sig = _resolve_optional_signal(dut, PPI_READY_CANDIDATES)

    valid_sig.value = 0
    data_sig.value = 0
    await RisingEdge(clk)

    for lane_bytes, valid_mask in bytes_to_ppi_cycles(data=data, num_lanes=num_lanes):
        data_sig.value = _pack_lane_bundle(lane_bytes)
        valid_sig.value = valid_mask
        await _drive_with_optional_ready(clk, valid_sig, ready_sig)

    valid_sig.value = 0
    data_sig.value = 0
    await RisingEdge(clk)


async def send_ppi_cycles(
    dut,
    data: bytes,
    num_lanes: int = 4,
) -> None:
    """Send PPI-like cycles using rxdata_hs/rxvalidhs style signals.

    This is equivalent to driving the output of a digital D-PHY/PPI adapter:
    cycle_k -> [lane0_byte, lane1_byte, lane2_byte, lane3_byte, valid_mask]
    """

    await send_csi2_lane_bytes(dut=dut, data=data, num_lanes=num_lanes)


# -----------------------------------------------------------------------------
# Test helpers
# -----------------------------------------------------------------------------
def _packet_dt(packet: bytes) -> int:
    return packet[0] & DT_MASK


def _packet_vc(packet: bytes) -> int:
    return (packet[0] >> 6) & VC_MASK


def _packet_wc(packet: bytes) -> int:
    return packet[1] | (packet[2] << 8)


def _payload_size_from_ns(ns: int) -> int:
    return RX_HEADERS_TOTAL_BYTES + ns * SAMPLE_PACKED_BYTES + CQ_BYTES


# -----------------------------------------------------------------------------
# Unit tests
# -----------------------------------------------------------------------------
def test_short_packet_fs() -> None:
    packet = build_short_packet(dt=DT_FS, vc=0, short_data=0x1234)

    assert len(packet) == 4
    assert _packet_dt(packet) == DT_FS
    assert _packet_vc(packet) == 0
    assert packet[1] == 0x34
    assert packet[2] == 0x12
    assert packet[3] == csi2_calc_ecc(packet[:3])


def test_short_packet_ls() -> None:
    packet = build_short_packet(dt=DT_LS, vc=1, short_data=0x00AA)

    assert len(packet) == 4
    assert _packet_dt(packet) == DT_LS
    assert _packet_vc(packet) == 1
    assert packet[1] == 0xAA
    assert packet[2] == 0x00
    assert packet[3] == csi2_calc_ecc(packet[:3])


def test_long_packet_ns_1() -> None:
    payload = gen_awr_payload(chirp_num=0, ns=1, pattern="ramp")
    packet = build_long_packet(dt=DT_AWR_RAW, vc=0, payload=payload)

    assert _packet_dt(packet) == DT_AWR_RAW
    assert _packet_vc(packet) == 0
    assert _packet_wc(packet) == len(payload)
    assert len(packet) == 4 + len(payload) + 2


def test_long_packet_ns_64() -> None:
    payload = gen_awr_payload(chirp_num=7, ns=64, chirp_profile=3, cq_data=0x1122334455667788, pattern="const")
    packet = build_long_packet(dt=DT_AWR_RAW, vc=2, payload=payload)
    crc16 = int.from_bytes(packet[-2:], byteorder="little", signed=False)

    assert _packet_wc(packet) == _payload_size_from_ns(64)
    assert crc16 == csi2_calc_crc16(payload)
    assert packet[4:-2] == payload


def test_awr_chirp_packet_sequence() -> None:
    chirp_packets = build_awr_chirp_packets(chirp_num=5, ns=8, vc=0, chirp_profile=2, pattern="channel_tag")
    frame_packets = build_awr_frame_packets(num_chirps=2, ns=8, vc=0, chirp_profile=2, pattern="channel_tag")

    assert [_packet_dt(pkt) for pkt in chirp_packets] == [DT_LS, DT_AWR_RAW, DT_LE]
    assert [_packet_dt(pkt) for pkt in frame_packets] == [DT_FS, DT_LS, DT_AWR_RAW, DT_LE, DT_LS, DT_AWR_RAW, DT_LE, DT_FE]


def test_lane_interleave_4lane() -> None:
    lanes = bytes_to_lanes(bytes(range(10)), num_lanes=4)

    assert lanes[0] == [0, 4, 8]
    assert lanes[1] == [1, 5, 9]
    assert lanes[2] == [2, 6]
    assert lanes[3] == [3, 7]


def test_ppi_cycle_generation() -> None:
    cycles = bytes_to_ppi_cycles(bytes(range(10)), num_lanes=4)

    assert cycles[0] == ([0, 1, 2, 3], 0b1111)
    assert cycles[1] == ([4, 5, 6, 7], 0b1111)
    assert cycles[2] == ([8, 9, 0, 0], 0b0011)


def test_frame_multi_chirp() -> None:
    packets = build_awr_frame_packets(num_chirps=4, ns=16, vc=0, chirp_profile=1, cq_data=0x55AA55AA55AA55AA, pattern="ramp")
    dts = [_packet_dt(pkt) for pkt in packets]

    assert dts.count(DT_FS) == 1
    assert dts.count(DT_FE) == 1
    assert dts.count(DT_LS) == 4
    assert dts.count(DT_LE) == 4
    assert dts.count(DT_AWR_RAW) == 4
