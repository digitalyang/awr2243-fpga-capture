from __future__ import annotations

import random
import sys
from dataclasses import dataclass
from typing import List

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge

from awr_payload_model import (
    ALIGN_BYTES,
    CQ_BYTES as CQ_AREA_BYTES,
    RX_HEADER_BYTES_TOTAL as HEADER_BYTES,
    SAMPLE_AREA_BYTES,
    SAMPLE_BYTES as SAMPLE_UNIT_BYTES,
    SLOT_TOTAL_ALIGNED,
    SLOT_TOTAL_UNALIGNED,
    build_expected_slot_bytes,
    expected_sample_count,
)

# ────────────────────────────────────────────────────────────────
#  DUT parameters (must match cocotb_top defaults)
# ────────────────────────────────────────────────────────────────
AXIS_DATA_W = 256
AXIS_BEAT_BYTES = AXIS_DATA_W // 8  # 32
SLOT_TOTAL_BEATS = SLOT_TOTAL_ALIGNED // AXIS_BEAT_BYTES

# Waveform (run with --waves): sim_build/fixed_slot_packer_cocotb/test/dump.fst
# For 64-byte / beat1 debug, inspect under dut:
#   state_r, wr_shadow_valid_r, wr_shadow_idx_r, wr_shadow_data_r (beat1 write),
#   zero_fill_idx_r (ST_ZERO_MID start), mem_wr_en_c, mem_wr_addr_c.
# For no-partial (e.g. 32-byte): ST_CAP_FLUSH should set zero_fill_idx_n = 1 (from wr_shadow_idx_r+1 when partial, else wr_abs_pos_r/32).

# ────────────────────────────────────────────────────────────────
#  Helpers
# ────────────────────────────────────────────────────────────────
def int_to_bytes_le(value: int, n: int) -> bytes:
    return int(value).to_bytes(n, "little", signed=False)


def bytes_to_int_le(data: bytes) -> int:
    return int.from_bytes(data, "little", signed=False)


def keep_mask(valid_bytes: int, beat_bytes: int) -> int:
    if valid_bytes >= beat_bytes:
        return (1 << beat_bytes) - 1
    return (1 << valid_bytes) - 1


def gen_payload(length: int, seed: int = 0) -> bytes:
    return bytes(((i * 13 + length) & 0xFF) for i in range(length))


@dataclass
class SlotCapture:
    data: bytes = b""
    beat_count: int = 0
    sb_slot_seq: int = 0
    sb_slot_bytes: int = 0
    sb_slot_valid_good: int = 0
    sb_slot_overflow_err: int = 0
    saw_slot_start: bool = False
    saw_slot_done: bool = False


# ────────────────────────────────────────────────────────────────
#  Reset
# ────────────────────────────────────────────────────────────────
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


# ────────────────────────────────────────────────────────────────
#  Backpressure coroutine
# ────────────────────────────────────────────────────────────────
async def random_backpressure(dut, stop_event: list) -> None:
    while not stop_event[0]:
        dut.m_axis_tready.value = random.randint(0, 1)
        await RisingEdge(dut.clk_i)
    dut.m_axis_tready.value = 1


# ────────────────────────────────────────────────────────────────
#  Packet driver
# ────────────────────────────────────────────────────────────────
async def drive_packet(
    dut,
    payload: bytes,
    pkt_seq: int,
    pkt_crc_err: int = 0,
    pkt_ecc_err: int = 0,
    pkt_trunc_err: int = 0,
) -> None:
    valid_good = int(not (pkt_crc_err or pkt_ecc_err or pkt_trunc_err))
    beat_count = max(1, (len(payload) + AXIS_BEAT_BYTES - 1) // AXIS_BEAT_BYTES)

    for beat_idx in range(beat_count):
        chunk = payload[beat_idx * AXIS_BEAT_BYTES : (beat_idx + 1) * AXIS_BEAT_BYTES]
        padded = chunk.ljust(AXIS_BEAT_BYTES, b"\x00")
        is_last = beat_idx == beat_count - 1

        dut.s_axis_tdata.value = bytes_to_int_le(padded)
        dut.s_axis_tkeep.value = keep_mask(len(chunk), AXIS_BEAT_BYTES)
        dut.s_axis_tvalid.value = 1
        dut.s_axis_tlast.value = int(is_last)
        dut.s_axis_tuser.value = 0

        dut.pkt_start_i.value = int(beat_idx == 0)
        dut.pkt_done_i.value = int(is_last)
        dut.pkt_seq_i.value = pkt_seq & 0xFFFF
        dut.pkt_bytes_i.value = len(payload) & 0xFFFF
        dut.pkt_crc_err_i.value = pkt_crc_err
        dut.pkt_ecc_err_i.value = pkt_ecc_err
        dut.pkt_trunc_err_i.value = pkt_trunc_err
        dut.pkt_valid_good_i.value = valid_good if is_last else 0

        while True:
            await RisingEdge(dut.clk_i)
            if int(dut.s_axis_tvalid.value) and int(dut.s_axis_tready.value):
                break

    dut.s_axis_tdata.value = 0
    dut.s_axis_tkeep.value = 0
    dut.s_axis_tvalid.value = 0
    dut.s_axis_tlast.value = 0
    dut.pkt_start_i.value = 0
    dut.pkt_done_i.value = 0
    dut.pkt_bytes_i.value = 0
    dut.pkt_seq_i.value = 0
    dut.pkt_crc_err_i.value = 0
    dut.pkt_ecc_err_i.value = 0
    dut.pkt_trunc_err_i.value = 0
    dut.pkt_valid_good_i.value = 0


# ────────────────────────────────────────────────────────────────
#  Slot collector
# ────────────────────────────────────────────────────────────────
async def collect_slot(dut, timeout_cycles: int = 2000) -> SlotCapture:
    cap = SlotCapture()
    raw = bytearray()
    started = False

    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)

        if int(dut.m_axis_tvalid.value) and int(dut.m_axis_tready.value):
            if not started:
                started = True
                cap.saw_slot_start = bool(int(dut.slot_start_o.value))
                cap.sb_slot_seq = int(dut.slot_seq_o.value)
                cap.sb_slot_bytes = int(dut.slot_bytes_o.value)
                cap.sb_slot_valid_good = int(dut.slot_valid_good_o.value)
                cap.sb_slot_overflow_err = int(dut.slot_overflow_err_o.value)

            beat_data = int_to_bytes_le(int(dut.m_axis_tdata.value), AXIS_BEAT_BYTES)
            raw.extend(beat_data)
            cap.beat_count += 1

            if int(dut.m_axis_tlast.value):
                cap.saw_slot_done = bool(int(dut.slot_done_o.value))
                cap.data = bytes(raw)
                return cap

    raise TimeoutError("Timed out waiting for complete slot output")


async def expect_no_slot(dut, wait_cycles: int = 300) -> None:
    for _ in range(wait_cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.m_axis_tvalid.value) and int(dut.m_axis_tready.value):
            raise AssertionError("Unexpected slot output when drop was expected")


# ────────────────────────────────────────────────────────────────
#  Slot verification
# ────────────────────────────────────────────────────────────────
def verify_slot(
    cap: SlotCapture,
    payload: bytes,
    pkt_seq: int,
    pkt_crc_err: int = 0,
    pkt_ecc_err: int = 0,
    pkt_trunc_err: int = 0,
) -> None:
    valid_good = int(not (pkt_crc_err or pkt_ecc_err or pkt_trunc_err))
    overflow = int(len(payload) > SLOT_TOTAL_UNALIGNED)
    exp_sample_cnt = expected_sample_count(payload, pkt_trunc_err=bool(pkt_trunc_err))
    expected_slot = build_expected_slot_bytes(payload, pkt_trunc_err=bool(pkt_trunc_err))
    d = cap.data

    # ── protocol ────────────────────────────────────────────
    assert cap.saw_slot_start, "slot_start not asserted on first beat"
    assert cap.saw_slot_done, "slot_done not asserted on last beat"
    assert cap.beat_count == SLOT_TOTAL_BEATS, (
        f"Beat count mismatch: exp={SLOT_TOTAL_BEATS} act={cap.beat_count}"
    )
    assert len(d) == SLOT_TOTAL_ALIGNED, (
        f"Slot size mismatch: exp={SLOT_TOTAL_ALIGNED} act={len(d)}"
    )

    # ── sideband ────────────────────────────────────────────
    assert cap.sb_slot_seq == (pkt_seq & 0xFFFF), (
        f"slot_seq mismatch: exp={pkt_seq & 0xFFFF} act={cap.sb_slot_seq}"
    )
    assert cap.sb_slot_bytes == SLOT_TOTAL_ALIGNED, (
        f"slot_bytes mismatch: exp={SLOT_TOTAL_ALIGNED} act={cap.sb_slot_bytes}"
    )
    assert cap.sb_slot_valid_good == valid_good, (
        f"slot_valid_good mismatch: exp={valid_good} act={cap.sb_slot_valid_good}"
    )
    assert cap.sb_slot_overflow_err == overflow, (
        f"slot_overflow mismatch: exp={overflow} act={cap.sb_slot_overflow_err}"
    )

    assert exp_sample_cnt <= (SAMPLE_AREA_BYTES // SAMPLE_UNIT_BYTES)
    if d != expected_slot:
        # Diagnostic: first differing byte index and that beat's hex (to distinguish
        # same-beat byte order vs whole-beat misalignment)
        n = min(len(d), len(expected_slot))
        first_diff = n
        for i in range(n):
            if d[i] != expected_slot[i]:
                first_diff = i
                break
        beat_idx = first_diff // AXIS_BEAT_BYTES
        start = beat_idx * AXIS_BEAT_BYTES
        end = min(start + AXIS_BEAT_BYTES, max(len(d), len(expected_slot)))
        exp_beat = (expected_slot[start:end] if start < len(expected_slot) else b"").ljust(end - start, b"\x00")
        act_beat = (d[start:end] if start < len(d) else b"").ljust(end - start, b"\x00")
        msg = (
            f"[slot mismatch] first_diff_byte={first_diff} beat_idx={beat_idx} "
            f"len(actual)={len(d)} len(expected)={len(expected_slot)} "
            f"expected_beat_hex={exp_beat.hex()} actual_beat_hex={act_beat.hex()}"
        )
        print(msg, file=sys.stderr)
        assert d == expected_slot, "slot payload layout mismatch"


# ────────────────────────────────────────────────────────────────
#  Combined drive + collect + verify helper
# ────────────────────────────────────────────────────────────────
async def run_and_verify(
    dut,
    payload: bytes,
    pkt_seq: int,
    pkt_crc_err: int = 0,
    pkt_ecc_err: int = 0,
    pkt_trunc_err: int = 0,
    timeout: int = 2000,
) -> SlotCapture:
    slot_task = cocotb.start_soon(collect_slot(dut, timeout_cycles=timeout))
    await drive_packet(dut, payload, pkt_seq, pkt_crc_err, pkt_ecc_err, pkt_trunc_err)
    cap = await slot_task
    verify_slot(cap, payload, pkt_seq, pkt_crc_err, pkt_ecc_err, pkt_trunc_err)
    return cap


# ================================================================
#  Test cases
# ================================================================

@cocotb.test()
async def test_smoke(dut):
    """Basic 64-byte clean packet → verify complete slot format."""
    await apply_reset(dut)
    payload = gen_payload(64)
    await run_and_verify(dut, payload, pkt_seq=0)


@cocotb.test()
async def test_short_pkt(dut):
    """4-byte packet → verify short payload zero-fills the fixed slot layout."""
    await apply_reset(dut)
    payload = gen_payload(4)
    await run_and_verify(dut, payload, pkt_seq=1)


@cocotb.test()
async def test_single_beat(dut):
    """16-byte packet fitting in a single AXI beat (pkt_start + pkt_done same cycle)."""
    await apply_reset(dut)
    payload = gen_payload(16)
    await run_and_verify(dut, payload, pkt_seq=2)


@cocotb.test()
async def test_cq_crosses_before_last_beat(dut):
    """257-byte packet: CQ starts in the penultimate beat and must not leak into sample area."""
    await apply_reset(dut)
    payload = gen_payload(257, seed=7)
    await run_and_verify(dut, payload, pkt_seq=21)


@cocotb.test()
async def test_full_slot(dut):
    """Packet exactly fills the fixed raw payload area (12309 bytes)."""
    await apply_reset(dut)
    payload = gen_payload(SLOT_TOTAL_UNALIGNED)
    await run_and_verify(dut, payload, pkt_seq=3)


@cocotb.test()
async def test_overflow(dut):
    """Packet exceeds the fixed payload envelope → verify truncation + overflow flag."""
    await apply_reset(dut)
    payload = gen_payload(SLOT_TOTAL_UNALIGNED + 256)
    await run_and_verify(dut, payload, pkt_seq=4)


@cocotb.test()
async def test_mark_invalid(dut):
    """Packets with error flags (drop=0) → output with error flags set."""
    await apply_reset(dut)
    dut.cfg_drop_invalid_pkt_i.value = 0
    await ClockCycles(dut.clk_i, 2)

    p0 = gen_payload(64, seed=10)
    await run_and_verify(dut, p0, pkt_seq=0, pkt_crc_err=1)

    p1 = gen_payload(128, seed=20)
    await run_and_verify(dut, p1, pkt_seq=1, pkt_ecc_err=1)

    p2 = gen_payload(32, seed=30)
    await run_and_verify(dut, p2, pkt_seq=2, pkt_trunc_err=1)


@cocotb.test()
async def test_drop_invalid(dut):
    """Packets with error flags (drop=1) → no slot output."""
    await apply_reset(dut)
    dut.cfg_drop_invalid_pkt_i.value = 1
    await ClockCycles(dut.clk_i, 2)

    await drive_packet(dut, gen_payload(64), pkt_seq=0, pkt_crc_err=1)
    await expect_no_slot(dut, wait_cycles=200)

    await drive_packet(dut, gen_payload(128), pkt_seq=1, pkt_ecc_err=1)
    await expect_no_slot(dut, wait_cycles=200)

    dut.cfg_drop_invalid_pkt_i.value = 0
    await ClockCycles(dut.clk_i, 2)
    clean = gen_payload(48)
    await run_and_verify(dut, clean, pkt_seq=2)


@cocotb.test()
async def test_multi_pkt(dut):
    """Multiple packets in sequence → verify each slot independently."""
    await apply_reset(dut)

    sizes = [32, 256, 1024, SLOT_TOTAL_UNALIGNED, 64]
    for seq, sz in enumerate(sizes):
        payload = gen_payload(sz, seed=seq)
        dut._log.info(f"Sending packet seq={seq} size={sz}")
        await run_and_verify(dut, payload, pkt_seq=seq)


@cocotb.test()
async def test_backpressure(dut):
    """Random m_axis_tready toggling → verify correct slot output under backpressure."""
    await apply_reset(dut)

    stop_flag: List[bool] = [False]
    cocotb.start_soon(random_backpressure(dut, stop_flag))

    payloads = [gen_payload(128, seed=0), gen_payload(512, seed=1), gen_payload(2048, seed=2)]

    for seq, payload in enumerate(payloads):
        dut._log.info(f"Backpressure test: seq={seq} size={len(payload)}")
        await drive_packet(dut, payload, pkt_seq=seq)
        cap = await collect_slot(dut, timeout_cycles=SLOT_TOTAL_BEATS * 8)
        verify_slot(cap, payload, pkt_seq=seq)

    stop_flag[0] = True
    await ClockCycles(dut.clk_i, 4)
