"""AWR2243 chirp payload generator and cocotb AXI-Stream driver tests.

Generates radar ADC payloads in the native AWR2243 4RX format:
  payload = rx_header[0..3] + sample[0..Ns-1] + cq_data

All bit-packing follows the rules documented in the module docstrings.
"""
from __future__ import annotations

import random
import struct
from dataclasses import dataclass
from math import ceil
from typing import List, Optional

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge

# ================================================================
#  Constants
# ================================================================
NUM_RX_CHANNELS = 4
RX_HEADER_BYTES_EACH = 2
RX_HEADER_BYTES_TOTAL = NUM_RX_CHANNELS * RX_HEADER_BYTES_EACH  # 8
IQ_PER_SAMPLE = NUM_RX_CHANNELS * 2  # 8 (I+Q per channel)
SAMPLE_BITS = IQ_PER_SAMPLE * 12  # 96
SAMPLE_BYTES = SAMPLE_BITS // 8  # 12
CQ_BYTES = 8

# ================================================================
#  Utility: signed → unsigned 12-bit
# ================================================================

def sign_to_u12(x: int) -> int:
    """Convert a signed integer to its unsigned 12-bit representation.

    Negative values are converted via two's complement truncation:
      sign_to_u12(-1)    → 0xFFF
      sign_to_u12(-2048) → 0x800
      sign_to_u12(2047)  → 0x7FF
    """
    return x & 0xFFF


# ================================================================
#  12-bit tight packing
# ================================================================

def pack_u12_list_le(values: List[int]) -> bytes:
    """Pack *N* unsigned 12-bit values into a continuous little-endian byte stream.

    Bit layout (LSB-first):
      bit  0..11  = values[0]
      bit 12..23  = values[1]
      bit 24..35  = values[2]
      ...

    The resulting integer is converted to ``ceil(N*12/8)`` bytes, little-endian.

    Example for 2 values (0xABC, 0xDEF):
      bitstream = 0xDEF_ABC  →  bytes: [0xBC, 0xFA, 0xDE]
    """
    bitstream = 0
    for i, v in enumerate(values):
        bitstream |= (v & 0xFFF) << (i * 12)
    byte_count = (len(values) * 12 + 7) // 8
    return bitstream.to_bytes(byte_count, "little")


# ================================================================
#  RX header packing
# ================================================================

def pack_rx_header(channel_id: int, chirp_profile: int, chirp_num: int) -> bytes:
    """Pack one RX header into 2 bytes (16-bit little-endian).

    Bit mapping:
      [1:0]   = channel_id   (2 bits)
      [4:2]   = chirp_profile (3 bits)
      [15:5]  = chirp_num[10:0] (11 bits, MSB-truncated)

    Returns 2 bytes in little-endian order.
    """
    word = (
        ((channel_id & 0x3) << 0)
        | ((chirp_profile & 0x7) << 2)
        | ((chirp_num & 0x7FF) << 5)
    )
    return struct.pack("<H", word)


# ================================================================
#  Single-sample IQ generation
# ================================================================

def gen_one_sample(
    k: int,
    pattern: str,
    rng: Optional[random.Random] = None,
) -> List[int]:
    """Generate 8 unsigned 12-bit IQ values for sample index *k*.

    Return order: [ch0_i, ch0_q, ch1_i, ch1_q, ch2_i, ch2_q, ch3_i, ch3_q]

    Supported patterns:
      "ramp"        – per-channel linear ramp with sign inversion on Q
      "const"       – fixed diagnostic values
      "channel_tag" – unique per-channel ID for cross-talk checks
      "random"      – seeded pseudo-random 12-bit signed values
    """
    if pattern == "ramp":
        vals = []
        for ch in range(NUM_RX_CHANNELS):
            base = ch * 0x100 + k
            vals.append(sign_to_u12(base))
            vals.append(sign_to_u12(-base))
        return vals

    if pattern == "const":
        return [
            0x011, 0xFEE,
            0x022, 0xFDD,
            0x033, 0xFCC,
            0x044, 0xFBB,
        ]

    if pattern == "channel_tag":
        return [
            0x001, 0x101,
            0x002, 0x102,
            0x003, 0x103,
            0x004, 0x104,
        ]

    if pattern == "random":
        if rng is None:
            rng = random.Random(42)
        return [sign_to_u12(rng.randint(-2048, 2047)) for _ in range(IQ_PER_SAMPLE)]

    raise ValueError(f"Unknown pattern: {pattern!r}")


# ================================================================
#  Payload size calculation
# ================================================================

def calc_expected_payload_size(ns: int) -> int:
    """Return the expected payload byte count for *ns* samples.

    Formula: 8 (header) + ns × 12 (samples) + 8 (CQ)
    """
    return RX_HEADER_BYTES_TOTAL + ns * SAMPLE_BYTES + CQ_BYTES


# ================================================================
#  Full payload generation
# ================================================================

def gen_awr2243_payload(
    chirp_num: int,
    ns: int,
    chirp_profile: int = 0,
    cq_data: int = 0,
    pattern: str = "ramp",
    seed: int = 42,
) -> bytes:
    """Build a complete AWR2243 chirp payload.

    Parameters
    ----------
    chirp_num : int
        Chirp index (truncated to 11 bits in each RX header).
    ns : int
        Number of samples (1 .. 1024).
    chirp_profile : int
        Chirp profile index (3 bits).
    cq_data : int
        64-bit CQ word appended at the tail (LE).
    pattern : str
        Sample data pattern – "ramp", "const", "channel_tag", "random".
    seed : int
        PRNG seed for the "random" pattern.

    Returns
    -------
    bytes
        Complete payload: ``rx_headers || samples || cq``.
    """
    if not 1 <= ns <= 1024:
        raise ValueError(f"ns must be 1..1024, got {ns}")

    rng = random.Random(seed)
    buf = bytearray()

    # ── RX headers (4 channels × 2 bytes) ───────────────────
    for ch in range(NUM_RX_CHANNELS):
        buf.extend(pack_rx_header(ch, chirp_profile, chirp_num))

    # ── Sample data ─────────────────────────────────────────
    for k in range(ns):
        iq_vals = gen_one_sample(k, pattern, rng=rng)
        buf.extend(pack_u12_list_le(iq_vals))

    # ── CQ data (64-bit LE) ─────────────────────────────────
    buf.extend(struct.pack("<Q", cq_data & 0xFFFF_FFFF_FFFF_FFFF))

    assert len(buf) == calc_expected_payload_size(ns)
    return bytes(buf)


# ================================================================
#  AXI-Stream helpers
# ================================================================

def _keep_mask(valid_bytes: int, beat_bytes: int) -> int:
    if valid_bytes >= beat_bytes:
        return (1 << beat_bytes) - 1
    return (1 << valid_bytes) - 1


@dataclass
class AxisSendResult:
    """Metadata returned by :func:`send_payload_axis`."""
    beat_count: int
    total_bytes: int
    last_beat_valid_bytes: int
    last_beat_tkeep: int


@dataclass
class AxisMonitorResult:
    """Metadata captured by :func:`axis_input_monitor`."""
    beats: int = 0
    last_tkeep: int = 0
    saw_tlast: bool = False


# ================================================================
#  AXI-Stream driver
# ================================================================

async def send_payload_axis(
    dut,
    payload: bytes,
    data_width_bits: int = 256,
    idle_inserter: Optional[int] = None,
) -> AxisSendResult:
    """Drive *payload* onto DUT ``s_axis`` as AXI4-Stream beats.

    Parameters
    ----------
    dut
        cocotb DUT handle (must expose ``s_axis_tdata/tkeep/tvalid/tready/tlast``).
    payload : bytes
        Raw byte payload.
    data_width_bits : int
        AXIS data bus width in bits (e.g. 128, 256, 512).
    idle_inserter : int or None
        If set, insert an idle cycle (tvalid=0) every *N* beats.

    Returns
    -------
    AxisSendResult
        Beat count and tkeep metadata for post-hoc verification.
    """
    beat_bytes = data_width_bits // 8
    beat_count = max(1, ceil(len(payload) / beat_bytes))

    for beat_idx in range(beat_count):
        chunk = payload[beat_idx * beat_bytes : (beat_idx + 1) * beat_bytes]
        is_last = beat_idx == beat_count - 1
        valid_bytes = len(chunk)
        padded = chunk.ljust(beat_bytes, b"\x00")

        if idle_inserter and beat_idx > 0 and (beat_idx % idle_inserter) == 0:
            dut.s_axis_tvalid.value = 0
            await RisingEdge(dut.clk_i)

        dut.s_axis_tdata.value = int.from_bytes(padded, "little")
        dut.s_axis_tkeep.value = _keep_mask(valid_bytes, beat_bytes)
        dut.s_axis_tvalid.value = 1
        dut.s_axis_tlast.value = int(is_last)
        dut.s_axis_tuser.value = 0

        while True:
            await RisingEdge(dut.clk_i)
            if int(dut.s_axis_tvalid.value) and int(dut.s_axis_tready.value):
                break

    last_valid = len(payload) % beat_bytes or beat_bytes
    last_tkeep = _keep_mask(last_valid, beat_bytes)

    dut.s_axis_tvalid.value = 0
    dut.s_axis_tlast.value = 0

    return AxisSendResult(
        beat_count=beat_count,
        total_bytes=len(payload),
        last_beat_valid_bytes=last_valid,
        last_beat_tkeep=last_tkeep,
    )


# ================================================================
#  AXI-Stream input monitor (runs concurrently with driver)
# ================================================================

async def axis_input_monitor(
    dut,
    timeout_cycles: int = 4000,
) -> AxisMonitorResult:
    """Watch ``s_axis`` and capture beat metadata until ``tlast``."""
    res = AxisMonitorResult()
    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.s_axis_tvalid.value) and int(dut.s_axis_tready.value):
            res.beats += 1
            res.last_tkeep = int(dut.s_axis_tkeep.value)
            if int(dut.s_axis_tlast.value):
                res.saw_tlast = True
                return res
    raise TimeoutError("axis_input_monitor timed out waiting for tlast")


# ================================================================
#  Reset helper (reuses fixed_slot_packer_cocotb_top DUT)
# ================================================================

async def apply_reset(dut) -> None:
    cocotb.start_soon(Clock(dut.clk_i, 10, unit="ns").start())
    dut.rst_ni.value = 0
    dut.cfg_drop_invalid_pkt_i.value = 0
    dut.pkt_start_i.value = 0
    dut.pkt_done_i.value = 0
    dut.pkt_bytes_i.value = 0
    dut.pkt_seq_i.value = 0
    dut.pkt_crc_err_i.value = 0
    dut.pkt_ecc_err_i.value = 0
    dut.pkt_trunc_err_i.value = 0
    dut.pkt_valid_good_i.value = 0
    dut.s_axis_tdata.value = 0
    dut.s_axis_tkeep.value = 0
    dut.s_axis_tvalid.value = 0
    dut.s_axis_tlast.value = 0
    dut.s_axis_tuser.value = 0
    dut.m_axis_tready.value = 1
    await ClockCycles(dut.clk_i, 8)
    dut.rst_ni.value = 1
    await ClockCycles(dut.clk_i, 2)


# ================================================================
#  Test cases
# ================================================================

@cocotb.test()
async def test_payload_ns_1(dut):
    """ns=1 ramp – verify payload length = 8 + 1*12 + 8 = 28 bytes."""
    await apply_reset(dut)
    payload = gen_awr2243_payload(chirp_num=0, ns=1, pattern="ramp")
    exp_len = calc_expected_payload_size(1)
    assert exp_len == 28, f"Formula check: exp=28 got={exp_len}"
    assert len(payload) == exp_len, f"Payload length: exp={exp_len} got={len(payload)}"


@cocotb.test()
async def test_payload_ns_64(dut):
    """ns=64 ramp – verify payload length = 8 + 64*12 + 8 = 784 bytes."""
    await apply_reset(dut)
    payload = gen_awr2243_payload(chirp_num=100, ns=64, pattern="ramp")
    exp_len = calc_expected_payload_size(64)
    assert exp_len == 784
    assert len(payload) == exp_len


@cocotb.test()
async def test_payload_ns_1024(dut):
    """ns=1024 ramp – maximum payload length = 8 + 1024*12 + 8 = 12304 bytes."""
    await apply_reset(dut)
    payload = gen_awr2243_payload(chirp_num=2047, ns=1024, pattern="ramp")
    exp_len = calc_expected_payload_size(1024)
    assert exp_len == 12304
    assert len(payload) == exp_len


@cocotb.test()
async def test_payload_const_pattern(dut):
    """Const pattern – byte-level verification of header, sample, and CQ."""
    await apply_reset(dut)
    chirp_num = 0x55
    chirp_profile = 3
    cq_val = 0xDEAD_BEEF_CAFE_1234

    payload = gen_awr2243_payload(
        chirp_num=chirp_num, ns=1,
        chirp_profile=chirp_profile,
        cq_data=cq_val,
        pattern="const",
    )

    # ── Verify RX headers ───────────────────────────────────
    for ch in range(NUM_RX_CHANNELS):
        hdr_word = struct.unpack_from("<H", payload, ch * 2)[0]
        act_ch = hdr_word & 0x3
        act_prof = (hdr_word >> 2) & 0x7
        act_chirp = (hdr_word >> 5) & 0x7FF
        assert act_ch == ch, f"Header ch={ch}: channel_id exp={ch} act={act_ch}"
        assert act_prof == chirp_profile, f"Header ch={ch}: profile exp={chirp_profile} act={act_prof}"
        assert act_chirp == chirp_num, f"Header ch={ch}: chirp_num exp={chirp_num} act={act_chirp}"

    # ── Verify sample IQ values (unpack 12-bit) ────────────
    sample_ofs = RX_HEADER_BYTES_TOTAL  # 8
    sample_raw = payload[sample_ofs : sample_ofs + SAMPLE_BYTES]
    bitstream = int.from_bytes(sample_raw, "little")
    expected_iq = [0x011, 0xFEE, 0x022, 0xFDD, 0x033, 0xFCC, 0x044, 0xFBB]
    for i, exp_val in enumerate(expected_iq):
        act_val = (bitstream >> (i * 12)) & 0xFFF
        assert act_val == exp_val, f"IQ[{i}]: exp=0x{exp_val:03x} act=0x{act_val:03x}"

    # ── Verify CQ ───────────────────────────────────────────
    cq_ofs = sample_ofs + SAMPLE_BYTES
    act_cq = struct.unpack_from("<Q", payload, cq_ofs)[0]
    assert act_cq == cq_val, f"CQ: exp=0x{cq_val:016x} act=0x{act_cq:016x}"


@cocotb.test()
async def test_axis_send_256bit(dut):
    """Drive payload on 256-bit s_axis – verify beat count, tkeep, tlast."""
    await apply_reset(dut)
    payload = gen_awr2243_payload(chirp_num=0, ns=64, pattern="ramp")
    data_w = 256
    beat_bytes = data_w // 8  # 32

    mon_task = cocotb.start_soon(axis_input_monitor(dut))
    result = await send_payload_axis(dut, payload, data_width_bits=data_w)
    mon = await mon_task

    expected_beats = ceil(len(payload) / beat_bytes)
    assert result.beat_count == expected_beats, (
        f"Driver beat count: exp={expected_beats} act={result.beat_count}"
    )
    assert mon.beats == expected_beats, (
        f"Monitor beat count: exp={expected_beats} act={mon.beats}"
    )
    assert mon.saw_tlast, "Monitor did not observe tlast"

    rem = len(payload) % beat_bytes
    expected_last_tkeep = (1 << beat_bytes) - 1 if rem == 0 else (1 << rem) - 1
    assert mon.last_tkeep == expected_last_tkeep, (
        f"Last tkeep: exp=0x{expected_last_tkeep:08x} act=0x{mon.last_tkeep:08x}"
    )


@cocotb.test()
async def test_axis_send_128bit(dut):
    """Verify 128-bit AXIS driver logic (computational – no 128-bit DUT needed)."""
    await apply_reset(dut)
    payload = gen_awr2243_payload(chirp_num=0, ns=32, pattern="ramp")
    data_w = 128
    beat_bytes = data_w // 8  # 16

    expected_beats = ceil(len(payload) / beat_bytes)
    rem = len(payload) % beat_bytes
    expected_last_tkeep = (1 << beat_bytes) - 1 if rem == 0 else (1 << rem) - 1

    exp_len = calc_expected_payload_size(32)  # 8 + 384 + 8 = 400
    assert len(payload) == exp_len
    assert expected_beats == ceil(400 / 16)  # 25
    assert expected_last_tkeep == (1 << beat_bytes) - 1  # 400 % 16 = 0 → full


@cocotb.test()
async def test_payload_random_reproducible(dut):
    """Random pattern with same seed produces identical payloads."""
    await apply_reset(dut)
    p1 = gen_awr2243_payload(chirp_num=7, ns=16, pattern="random", seed=12345)
    p2 = gen_awr2243_payload(chirp_num=7, ns=16, pattern="random", seed=12345)
    assert p1 == p2, "Random payloads with same seed must be identical"

    p3 = gen_awr2243_payload(chirp_num=7, ns=16, pattern="random", seed=99999)
    assert p1 != p3, "Different seeds should produce different payloads"


@cocotb.test()
async def test_payload_channel_tag(dut):
    """Channel-tag pattern – verify unique per-channel markers survive packing."""
    await apply_reset(dut)
    payload = gen_awr2243_payload(chirp_num=0, ns=1, pattern="channel_tag")

    sample_ofs = RX_HEADER_BYTES_TOTAL
    sample_raw = payload[sample_ofs : sample_ofs + SAMPLE_BYTES]
    bitstream = int.from_bytes(sample_raw, "little")

    expected = [0x001, 0x101, 0x002, 0x102, 0x003, 0x103, 0x004, 0x104]
    for i, exp_val in enumerate(expected):
        act_val = (bitstream >> (i * 12)) & 0xFFF
        assert act_val == exp_val, f"channel_tag IQ[{i}]: exp=0x{exp_val:03x} act=0x{act_val:03x}"


@cocotb.test()
async def test_axis_send_with_backpressure(dut):
    """Drive payload with idle insertion – verify all beats still arrive."""
    await apply_reset(dut)
    payload = gen_awr2243_payload(chirp_num=0, ns=8, pattern="ramp")
    data_w = 256
    beat_bytes = data_w // 8

    mon_task = cocotb.start_soon(axis_input_monitor(dut))
    result = await send_payload_axis(dut, payload, data_width_bits=data_w, idle_inserter=2)
    mon = await mon_task

    expected_beats = ceil(len(payload) / beat_bytes)
    assert mon.beats == expected_beats
    assert mon.saw_tlast
