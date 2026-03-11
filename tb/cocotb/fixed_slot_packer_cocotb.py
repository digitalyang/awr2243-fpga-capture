from __future__ import annotations

import random
import struct
from dataclasses import dataclass, field
from typing import List, Optional

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge

# ────────────────────────────────────────────────────────────────
#  DUT parameters (must match cocotb_top defaults)
# ────────────────────────────────────────────────────────────────
AXIS_DATA_W = 256
AXIS_BEAT_BYTES = AXIS_DATA_W // 8  # 32

SAMPLE_SLOT_NUM = 1024
SAMPLE_UNIT_BYTES = 4
SAMPLE_AREA_BYTES = SAMPLE_SLOT_NUM * SAMPLE_UNIT_BYTES  # 4096
CQ_AREA_BYTES = 128
HEADER_BYTES = 64
ALIGN_BYTES = 64

SLOT_TOTAL_UNALIGNED = HEADER_BYTES + SAMPLE_AREA_BYTES + CQ_AREA_BYTES
SLOT_TOTAL_ALIGNED = (
    ((SLOT_TOTAL_UNALIGNED + ALIGN_BYTES - 1) // ALIGN_BYTES) * ALIGN_BYTES
)
SLOT_TOTAL_BEATS = SLOT_TOTAL_ALIGNED // AXIS_BEAT_BYTES

HEADER_BEATS = HEADER_BYTES // AXIS_BEAT_BYTES

# Header field byte offsets (little-endian, mirrors slot_packer_pkg)
HDR_MAGIC_OFS = 0
HDR_VERSION_OFS = 4
HDR_FLAGS_OFS = 5
HDR_PKT_SEQ_OFS = 8
HDR_PKT_BYTES_OFS = 10
HDR_SAMPLE_CNT_OFS = 12
HDR_SLOT_BYTES_OFS = 16
HDR_SAMPLE_AREA_OFS = 20
HDR_CQ_AREA_OFS = 24

FLAG_CRC_ERR_BIT = 0
FLAG_ECC_ERR_BIT = 1
FLAG_TRUNC_ERR_BIT = 2
FLAG_VALID_GOOD_BIT = 3
FLAG_OVERFLOW_BIT = 4

SLOT_MAGIC = 0xAA551024
SLOT_VERSION = 0x01


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
    overflow = int(len(payload) > SAMPLE_AREA_BYTES)
    eff_bytes = min(len(payload), SAMPLE_AREA_BYTES)
    exp_sample_cnt = eff_bytes // SAMPLE_UNIT_BYTES
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

    # ── header fields ───────────────────────────────────────
    act_magic = struct.unpack_from("<I", d, HDR_MAGIC_OFS)[0]
    assert act_magic == SLOT_MAGIC, f"Header magic: exp=0x{SLOT_MAGIC:08x} act=0x{act_magic:08x}"

    act_ver = d[HDR_VERSION_OFS]
    assert act_ver == SLOT_VERSION, f"Header version: exp=0x{SLOT_VERSION:02x} act=0x{act_ver:02x}"

    act_flags = d[HDR_FLAGS_OFS]
    assert ((act_flags >> FLAG_CRC_ERR_BIT) & 1) == pkt_crc_err, "Header crc_err flag mismatch"
    assert ((act_flags >> FLAG_ECC_ERR_BIT) & 1) == pkt_ecc_err, "Header ecc_err flag mismatch"
    assert ((act_flags >> FLAG_TRUNC_ERR_BIT) & 1) == pkt_trunc_err, "Header trunc_err flag mismatch"
    assert ((act_flags >> FLAG_VALID_GOOD_BIT) & 1) == valid_good, "Header valid_good flag mismatch"
    assert ((act_flags >> FLAG_OVERFLOW_BIT) & 1) == overflow, "Header overflow flag mismatch"

    act_seq = struct.unpack_from("<H", d, HDR_PKT_SEQ_OFS)[0]
    assert act_seq == (pkt_seq & 0xFFFF), f"Header pkt_seq: exp={pkt_seq & 0xFFFF} act={act_seq}"

    act_pkt_bytes = struct.unpack_from("<H", d, HDR_PKT_BYTES_OFS)[0]
    assert act_pkt_bytes == (len(payload) & 0xFFFF), (
        f"Header pkt_bytes: exp={len(payload) & 0xFFFF} act={act_pkt_bytes}"
    )

    act_sample_cnt = struct.unpack_from("<H", d, HDR_SAMPLE_CNT_OFS)[0]
    assert act_sample_cnt == exp_sample_cnt, (
        f"Header sample_cnt: exp={exp_sample_cnt} act={act_sample_cnt}"
    )

    act_slot_bytes = struct.unpack_from("<I", d, HDR_SLOT_BYTES_OFS)[0]
    assert act_slot_bytes == SLOT_TOTAL_ALIGNED, (
        f"Header slot_bytes: exp={SLOT_TOTAL_ALIGNED} act={act_slot_bytes}"
    )

    act_sample_area = struct.unpack_from("<I", d, HDR_SAMPLE_AREA_OFS)[0]
    assert act_sample_area == SAMPLE_AREA_BYTES, (
        f"Header sample_area: exp={SAMPLE_AREA_BYTES} act={act_sample_area}"
    )

    act_cq_area = struct.unpack_from("<H", d, HDR_CQ_AREA_OFS)[0]
    assert act_cq_area == CQ_AREA_BYTES, (
        f"Header cq_area: exp={CQ_AREA_BYTES} act={act_cq_area}"
    )

    # ── payload data ────────────────────────────────────────
    sample_ofs = HEADER_BYTES
    for i in range(eff_bytes):
        assert d[sample_ofs + i] == payload[i], (
            f"Payload byte {i}: exp=0x{payload[i]:02x} act=0x{d[sample_ofs + i]:02x}"
        )

    # ── sample area zero-padding ────────────────────────────
    for i in range(eff_bytes, SAMPLE_AREA_BYTES):
        assert d[sample_ofs + i] == 0, (
            f"Sample pad not zero at offset {sample_ofs + i}: act=0x{d[sample_ofs + i]:02x}"
        )

    # ── CQ area zero-fill ───────────────────────────────────
    cq_ofs = HEADER_BYTES + SAMPLE_AREA_BYTES
    for i in range(CQ_AREA_BYTES):
        assert d[cq_ofs + i] == 0, (
            f"CQ area not zero at offset {cq_ofs + i}: act=0x{d[cq_ofs + i]:02x}"
        )


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
    """4-byte packet → verify extensive zero-padding in sample area."""
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
async def test_full_slot(dut):
    """Packet exactly fills sample area (4096 bytes) – no sample padding needed."""
    await apply_reset(dut)
    payload = gen_payload(SAMPLE_AREA_BYTES)
    await run_and_verify(dut, payload, pkt_seq=3)


@cocotb.test()
async def test_overflow(dut):
    """Packet exceeds sample area → verify truncation + overflow flag."""
    await apply_reset(dut)
    payload = gen_payload(SAMPLE_AREA_BYTES + 256)
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

    sizes = [32, 256, 1024, SAMPLE_AREA_BYTES, 64]
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
