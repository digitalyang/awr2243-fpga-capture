from __future__ import annotations

import random
from typing import List, Optional, Tuple


NUM_RX_CHANNELS = 4
RX_HEADER_BYTES_EACH = 3
RX_HEADER_BYTES_TOTAL = NUM_RX_CHANNELS * RX_HEADER_BYTES_EACH

IQ_PER_SAMPLE = NUM_RX_CHANNELS * 2
SAMPLE_BITS = IQ_PER_SAMPLE * 12
SAMPLE_BYTES = SAMPLE_BITS // 8

SAMPLE_SLOT_NUM = 1024
SAMPLE_AREA_BYTES = SAMPLE_SLOT_NUM * SAMPLE_BYTES

CQ_WORD_COUNT = 6
CQ_BYTES = (CQ_WORD_COUNT * 12) // 8

ALIGN_BYTES = 64
SLOT_TOTAL_UNALIGNED = RX_HEADER_BYTES_TOTAL + SAMPLE_AREA_BYTES + CQ_BYTES
SLOT_TOTAL_ALIGNED = ((SLOT_TOTAL_UNALIGNED + ALIGN_BYTES - 1) // ALIGN_BYTES) * ALIGN_BYTES
SLOT_PADDING_BYTES = SLOT_TOTAL_ALIGNED - SLOT_TOTAL_UNALIGNED

U12_MASK = 0xFFF
U12_SIGNED_MIN = -(1 << 11)
U12_SIGNED_MAX = (1 << 11) - 1


def sign_to_u12(value: int) -> int:
    if 0 <= value <= U12_MASK:
        return value
    if U12_SIGNED_MIN <= value <= U12_SIGNED_MAX:
        return value & U12_MASK
    raise ValueError(f"value does not fit 12-bit signed/raw encoding: {value}")


def pack_u12_list_le(values: List[int]) -> bytes:
    bitstream = 0
    for idx, value in enumerate(values):
        bitstream |= (value & U12_MASK) << (idx * 12)
    return bitstream.to_bytes((len(values) * 12 + 7) // 8, "little")


def unpack_u12_list_le(data: bytes, value_count: int) -> List[int]:
    bitstream = int.from_bytes(data, "little", signed=False)
    return [(bitstream >> (idx * 12)) & U12_MASK for idx in range(value_count)]


def pack_rx_header(channel_id: int, chirp_profile: int, chirp_num: int) -> bytes:
    if not 0 <= channel_id <= 0x3:
        raise ValueError(f"channel_id out of range: {channel_id}")
    if not 0 <= chirp_profile <= 0xF:
        raise ValueError(f"chirp_profile out of range: {chirp_profile}")
    if not 0 <= chirp_num <= U12_MASK:
        raise ValueError(f"chirp_num out of range: {chirp_num}")

    word0 = ((chirp_profile & 0xF) << 2) | (channel_id & 0x3)
    word1 = chirp_num & U12_MASK
    return pack_u12_list_le([word0, word1])


def unpack_rx_header(data: bytes) -> Tuple[int, int, int]:
    if len(data) != RX_HEADER_BYTES_EACH:
        raise ValueError(f"rx header must be {RX_HEADER_BYTES_EACH} bytes, got {len(data)}")

    word0, word1 = unpack_u12_list_le(data, 2)
    channel_id = word0 & 0x3
    chirp_profile = (word0 >> 2) & 0xF
    chirp_num = word1 & U12_MASK
    return channel_id, chirp_profile, chirp_num


def pack_cq_raw12(cq_data: int) -> bytes:
    if not 0 <= cq_data <= ((1 << 64) - 1):
        raise ValueError(f"cq_data out of 64-bit range: {cq_data}")

    return pack_u12_list_le([(cq_data >> (12 * idx)) & U12_MASK for idx in range(CQ_WORD_COUNT)])


def unpack_cq_raw12(data: bytes) -> int:
    if len(data) != CQ_BYTES:
        raise ValueError(f"cq payload must be {CQ_BYTES} bytes, got {len(data)}")

    words = unpack_u12_list_le(data, CQ_WORD_COUNT)
    cq_data = 0
    for idx, word in enumerate(words):
        cq_data |= (word & U12_MASK) << (12 * idx)
    return cq_data & ((1 << 64) - 1)


def gen_one_sample(sample_idx: int, pattern: str = "ramp", rng: Optional[random.Random] = None) -> List[int]:
    if pattern == "ramp":
        values: List[int] = []
        for channel_id in range(NUM_RX_CHANNELS):
            base = channel_id * 0x100 + sample_idx
            values.append(sign_to_u12(base))
            values.append(sign_to_u12(-base))
        return values

    if pattern == "const":
        return [0x011, 0xFEE, 0x022, 0xFDD, 0x033, 0xFCC, 0x044, 0xFBB]

    if pattern == "channel_tag":
        return [0x001, 0x101, 0x002, 0x102, 0x003, 0x103, 0x004, 0x104]

    if pattern == "random":
        local_rng = rng if rng is not None else random.Random()
        return [sign_to_u12(local_rng.randint(U12_SIGNED_MIN, U12_SIGNED_MAX)) for _ in range(IQ_PER_SAMPLE)]

    raise ValueError(f"unsupported pattern: {pattern}")


def calc_expected_payload_size(ns: int) -> int:
    return RX_HEADER_BYTES_TOTAL + ns * SAMPLE_BYTES + CQ_BYTES


def gen_awr_payload(
    chirp_num: int,
    ns: int,
    chirp_profile: int = 0,
    cq_data: int = 0,
    pattern: str = "ramp",
    seed: Optional[int] = None,
) -> bytes:
    if not 0 <= ns <= SAMPLE_SLOT_NUM:
        raise ValueError(f"ns must be 0..{SAMPLE_SLOT_NUM}, got {ns}")

    rng = random.Random(chirp_num if seed is None else seed) if pattern == "random" else None

    payload = bytearray()
    for channel_id in range(NUM_RX_CHANNELS):
        payload.extend(pack_rx_header(channel_id=channel_id, chirp_profile=chirp_profile, chirp_num=chirp_num))

    for sample_idx in range(ns):
        payload.extend(pack_u12_list_le(gen_one_sample(sample_idx=sample_idx, pattern=pattern, rng=rng)))

    payload.extend(pack_cq_raw12(cq_data))
    return bytes(payload)


def split_payload_regions(payload: bytes, *, pkt_trunc_err: bool = False) -> Tuple[bytes, bytes, bytes]:
    header = payload[:RX_HEADER_BYTES_TOTAL]
    remainder = payload[RX_HEADER_BYTES_TOTAL:]

    if pkt_trunc_err:
        sample = remainder[:SAMPLE_AREA_BYTES]
        cq = remainder[SAMPLE_AREA_BYTES : SAMPLE_AREA_BYTES + CQ_BYTES]
        return header, sample, cq

    if len(remainder) <= CQ_BYTES:
        return header, b"", remainder

    sample_len = min(len(remainder) - CQ_BYTES, SAMPLE_AREA_BYTES)
    sample = remainder[:sample_len]
    cq = remainder[sample_len : sample_len + CQ_BYTES]
    return header, sample, cq


def build_expected_slot_bytes(payload: bytes, *, pkt_trunc_err: bool = False) -> bytes:
    header, sample, cq = split_payload_regions(payload, pkt_trunc_err=pkt_trunc_err)

    slot = bytearray()
    slot.extend(header[:RX_HEADER_BYTES_TOTAL].ljust(RX_HEADER_BYTES_TOTAL, b"\x00"))
    slot.extend(sample[:SAMPLE_AREA_BYTES].ljust(SAMPLE_AREA_BYTES, b"\x00"))
    slot.extend(cq[:CQ_BYTES].ljust(CQ_BYTES, b"\x00"))
    slot.extend(b"\x00" * SLOT_PADDING_BYTES)
    return bytes(slot)


def expected_sample_count(payload: bytes, *, pkt_trunc_err: bool = False) -> int:
    _, sample, _ = split_payload_regions(payload, pkt_trunc_err=pkt_trunc_err)
    return len(sample) // SAMPLE_BYTES
