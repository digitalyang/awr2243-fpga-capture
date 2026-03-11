from __future__ import annotations

import random
from dataclasses import dataclass

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge


AXIS_DATA_W = 256
AXIS_USER_W = 64
AXIS_BEAT_BYTES = AXIS_DATA_W // 8
VC_W = 2
DT_W = 6
PAYLOAD_LEN_W = 16
PKT_SEQ_W = 16

TUSER_PKT_START_BIT = 0
TUSER_CRC_ERR_BIT = 1
TUSER_ECC_ERR_BIT = 2
TUSER_TRUNC_ERR_BIT = 3
TUSER_VC_LSB = 8
TUSER_DT_LSB = 16
TUSER_PAYLOAD_LEN_LSB = 24


def keep_mask(valid_bytes: int) -> int:
    if valid_bytes <= 0:
        return 0
    if valid_bytes >= AXIS_BEAT_BYTES:
        return (1 << AXIS_BEAT_BYTES) - 1
    return (1 << valid_bytes) - 1


def bytes_to_int(data: bytes) -> int:
    return int.from_bytes(data, byteorder="little", signed=False)


def int_to_bytes(value: int, nbytes: int) -> bytes:
    return int(value).to_bytes(nbytes, byteorder="little", signed=False)


def build_tuser(
    vc: int,
    dt: int,
    declared_payload_len: int,
    *,
    pkt_start: int = 0,
    crc_err: int = 0,
    ecc_err: int = 0,
    trunc_err: int = 0,
) -> int:
    user = 0
    user |= (int(pkt_start) & 0x1) << TUSER_PKT_START_BIT
    user |= (int(crc_err) & 0x1) << TUSER_CRC_ERR_BIT
    user |= (int(ecc_err) & 0x1) << TUSER_ECC_ERR_BIT
    user |= (int(trunc_err) & 0x1) << TUSER_TRUNC_ERR_BIT
    user |= (vc & ((1 << VC_W) - 1)) << TUSER_VC_LSB
    user |= (dt & ((1 << DT_W) - 1)) << TUSER_DT_LSB
    user |= (declared_payload_len & ((1 << PAYLOAD_LEN_W) - 1)) << TUSER_PAYLOAD_LEN_LSB
    return user


def gen_payload(length: int, seed: int = 0) -> bytes:
    return bytes(((seed + idx * 13 + length) & 0xFF) for idx in range(length))


@dataclass
class PacketSpec:
    vc: int
    dt: int
    payload: bytes
    declared_payload_len: int
    crc_err_first: int = 0
    ecc_err_first: int = 0
    trunc_err_first: int = 0
    crc_err_last: int = 0
    ecc_err_last: int = 0
    trunc_err_last: int = 0


@dataclass
class PacketCapture:
    payload: bytes
    start_seen: bool
    done_seen: bool
    pkt_seq_start: int
    pkt_seq_done: int
    pkt_bytes_done: int
    pkt_valid_good_done: int
    pkt_crc_err_done: int
    pkt_ecc_err_done: int
    pkt_trunc_err_done: int
    first_vc: int
    first_dt: int
    first_declared_len: int


async def apply_reset(dut) -> None:
    cocotb.start_soon(Clock(dut.clk_i, 10, unit="ns").start())

    dut.rst_ni.value = 0
    dut.cfg_vc_en_i.value = 0
    dut.cfg_dt_en_i.value = 0
    dut.cfg_vc_i.value = 0
    dut.cfg_dt_i.value = 0

    dut.s_axis_tdata.value = 0
    dut.s_axis_tkeep.value = 0
    dut.s_axis_tvalid.value = 0
    dut.s_axis_tlast.value = 0
    dut.s_axis_tuser.value = 0

    dut.m_axis_tready.value = 1

    await ClockCycles(dut.clk_i, 8)
    dut.rst_ni.value = 1
    await ClockCycles(dut.clk_i, 2)


async def configure_filter(
    dut,
    *,
    vc_en: int = 1,
    dt_en: int = 1,
    vc: int = 0x1,
    dt: int = 0x2A,
) -> None:
    dut.cfg_vc_en_i.value = vc_en
    dut.cfg_dt_en_i.value = dt_en
    dut.cfg_vc_i.value = vc
    dut.cfg_dt_i.value = dt
    await ClockCycles(dut.clk_i, 2)


async def random_backpressure(dut, stop_flag: list[bool]) -> None:
    while not stop_flag[0]:
        dut.m_axis_tready.value = random.randint(0, 1)
        await RisingEdge(dut.clk_i)
    dut.m_axis_tready.value = 1


async def drive_packet(dut, pkt: PacketSpec) -> None:
    beat_count = max(1, (len(pkt.payload) + AXIS_BEAT_BYTES - 1) // AXIS_BEAT_BYTES)

    for beat_idx in range(beat_count):
        beat = pkt.payload[beat_idx * AXIS_BEAT_BYTES : (beat_idx + 1) * AXIS_BEAT_BYTES]
        is_first = beat_idx == 0
        is_last = beat_idx == (beat_count - 1)

        dut.s_axis_tdata.value = bytes_to_int(beat.ljust(AXIS_BEAT_BYTES, b"\x00"))
        dut.s_axis_tkeep.value = keep_mask(len(beat))
        dut.s_axis_tvalid.value = 1
        dut.s_axis_tlast.value = int(is_last)
        dut.s_axis_tuser.value = build_tuser(
            pkt.vc,
            pkt.dt,
            pkt.declared_payload_len,
            pkt_start=int(is_first),
            crc_err=((pkt.crc_err_first if is_first else 0) | (pkt.crc_err_last if is_last else 0)),
            ecc_err=((pkt.ecc_err_first if is_first else 0) | (pkt.ecc_err_last if is_last else 0)),
            trunc_err=((pkt.trunc_err_first if is_first else 0) | (pkt.trunc_err_last if is_last else 0)),
        )

        while True:
            await RisingEdge(dut.clk_i)
            if int(dut.s_axis_tvalid.value) and int(dut.s_axis_tready.value):
                break

    dut.s_axis_tdata.value = 0
    dut.s_axis_tkeep.value = 0
    dut.s_axis_tvalid.value = 0
    dut.s_axis_tlast.value = 0
    dut.s_axis_tuser.value = 0
    await RisingEdge(dut.clk_i)


async def collect_output_packet(dut, timeout_cycles: int = 2000) -> PacketCapture:
    payload = bytearray()
    start_seen = False
    done_seen = False
    pkt_seq_start = 0
    pkt_seq_done = 0
    pkt_bytes_done = 0
    pkt_valid_good_done = 0
    pkt_crc_err_done = 0
    pkt_ecc_err_done = 0
    pkt_trunc_err_done = 0
    first_vc = 0
    first_dt = 0
    first_declared_len = 0
    started = False

    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.m_axis_tvalid.value) and int(dut.m_axis_tready.value):
            beat_data = int_to_bytes(int(dut.m_axis_tdata.value), AXIS_BEAT_BYTES)
            beat_keep = int(dut.m_axis_tkeep.value)
            beat_user = int(dut.m_axis_tuser.value)

            if not started:
                started = True
                start_seen = bool(int(dut.pkt_start_o.value))
                pkt_seq_start = int(dut.pkt_seq_o.value)
                first_vc = (beat_user >> TUSER_VC_LSB) & ((1 << VC_W) - 1)
                first_dt = (beat_user >> TUSER_DT_LSB) & ((1 << DT_W) - 1)
                first_declared_len = (beat_user >> TUSER_PAYLOAD_LEN_LSB) & ((1 << PAYLOAD_LEN_W) - 1)

            for lane in range(AXIS_BEAT_BYTES):
                if (beat_keep >> lane) & 0x1:
                    payload.append(beat_data[lane])

            if int(dut.m_axis_tlast.value):
                done_seen = bool(int(dut.pkt_done_o.value))
                pkt_seq_done = int(dut.pkt_seq_o.value)
                pkt_bytes_done = int(dut.pkt_bytes_o.value)
                pkt_valid_good_done = int(dut.pkt_valid_good_o.value)
                pkt_crc_err_done = int(dut.pkt_crc_err_o.value)
                pkt_ecc_err_done = int(dut.pkt_ecc_err_o.value)
                pkt_trunc_err_done = int(dut.pkt_trunc_err_o.value)
                return PacketCapture(
                    payload=bytes(payload),
                    start_seen=start_seen,
                    done_seen=done_seen,
                    pkt_seq_start=pkt_seq_start,
                    pkt_seq_done=pkt_seq_done,
                    pkt_bytes_done=pkt_bytes_done,
                    pkt_valid_good_done=pkt_valid_good_done,
                    pkt_crc_err_done=pkt_crc_err_done,
                    pkt_ecc_err_done=pkt_ecc_err_done,
                    pkt_trunc_err_done=pkt_trunc_err_done,
                    first_vc=first_vc,
                    first_dt=first_dt,
                    first_declared_len=first_declared_len,
                )

    raise TimeoutError("Timed out waiting for extractor output packet")


async def expect_no_output(dut, cycles: int = 200) -> None:
    for _ in range(cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.m_axis_tvalid.value) and int(dut.m_axis_tready.value):
            raise AssertionError("Unexpected output packet observed")


async def detect_output_activity(dut, cycles: int = 200) -> bool:
    for _ in range(cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.m_axis_tvalid.value) and int(dut.m_axis_tready.value):
            return True
    return False


def verify_packet(cap: PacketCapture, pkt: PacketSpec, expected_seq: int) -> None:
    exp_crc_err = pkt.crc_err_first | pkt.crc_err_last
    exp_ecc_err = pkt.ecc_err_first | pkt.ecc_err_last
    exp_trunc_err = pkt.trunc_err_first | pkt.trunc_err_last | int(pkt.declared_payload_len != len(pkt.payload))
    exp_valid_good = int(not (exp_crc_err or exp_ecc_err or exp_trunc_err))

    assert cap.start_seen, "pkt_start_o must assert on first forwarded beat"
    assert cap.done_seen, "pkt_done_o must assert on last forwarded beat"
    assert cap.payload == pkt.payload, "Forwarded payload mismatch"
    assert cap.first_vc == pkt.vc, f"VC mismatch: exp={pkt.vc} act={cap.first_vc}"
    assert cap.first_dt == pkt.dt, f"DT mismatch: exp={pkt.dt} act={cap.first_dt}"
    assert cap.first_declared_len == pkt.declared_payload_len, (
        f"Declared payload len mismatch: exp={pkt.declared_payload_len} act={cap.first_declared_len}"
    )
    assert cap.pkt_seq_start == expected_seq, (
        f"pkt_seq start mismatch: exp={expected_seq} act={cap.pkt_seq_start}"
    )
    assert cap.pkt_seq_done == expected_seq, (
        f"pkt_seq done mismatch: exp={expected_seq} act={cap.pkt_seq_done}"
    )
    assert cap.pkt_bytes_done == len(pkt.payload), (
        f"pkt_bytes mismatch: exp={len(pkt.payload)} act={cap.pkt_bytes_done}"
    )
    assert cap.pkt_crc_err_done == exp_crc_err, (
        f"pkt_crc_err mismatch: exp={exp_crc_err} act={cap.pkt_crc_err_done}"
    )
    assert cap.pkt_ecc_err_done == exp_ecc_err, (
        f"pkt_ecc_err mismatch: exp={exp_ecc_err} act={cap.pkt_ecc_err_done}"
    )
    assert cap.pkt_trunc_err_done == exp_trunc_err, (
        f"pkt_trunc_err mismatch: exp={exp_trunc_err} act={cap.pkt_trunc_err_done}"
    )
    assert cap.pkt_valid_good_done == exp_valid_good, (
        f"pkt_valid_good mismatch: exp={exp_valid_good} act={cap.pkt_valid_good_done}"
    )


async def run_match_case(dut, pkt: PacketSpec, expected_seq: int, timeout_cycles: int = 2000) -> PacketCapture:
    collect_task = cocotb.start_soon(collect_output_packet(dut, timeout_cycles=timeout_cycles))
    await drive_packet(dut, pkt)
    cap = await collect_task
    verify_packet(cap, pkt, expected_seq)
    return cap


async def run_drop_case(dut, pkt: PacketSpec, monitor_cycles: int = 300) -> None:
    detect_task = cocotb.start_soon(detect_output_activity(dut, cycles=monitor_cycles))
    await drive_packet(dut, pkt)
    saw_output = await detect_task
    assert not saw_output, "Unexpected output packet observed for drop case"


@cocotb.test()
async def test_smoke_match(dut):
    await apply_reset(dut)
    await configure_filter(dut, vc_en=1, dt_en=1, vc=0x1, dt=0x2A)

    pkt = PacketSpec(
        vc=0x1,
        dt=0x2A,
        payload=gen_payload(64, seed=1),
        declared_payload_len=64,
    )
    await run_match_case(dut, pkt, expected_seq=0)


@cocotb.test()
async def test_single_beat_match(dut):
    await apply_reset(dut)
    await configure_filter(dut, vc_en=1, dt_en=1, vc=0x1, dt=0x2A)

    pkt = PacketSpec(
        vc=0x1,
        dt=0x2A,
        payload=gen_payload(16, seed=2),
        declared_payload_len=16,
    )
    await run_match_case(dut, pkt, expected_seq=0)


@cocotb.test()
async def test_mixed_filter(dut):
    await apply_reset(dut)
    await configure_filter(dut, vc_en=1, dt_en=1, vc=0x1, dt=0x2A)

    pkt0 = PacketSpec(vc=0x1, dt=0x2A, payload=gen_payload(40, seed=3), declared_payload_len=40)
    await run_match_case(dut, pkt0, expected_seq=0)

    pkt1 = PacketSpec(vc=0x2, dt=0x2A, payload=gen_payload(20, seed=4), declared_payload_len=20)
    await run_drop_case(dut, pkt1)

    pkt2 = PacketSpec(vc=0x1, dt=0x15, payload=gen_payload(12, seed=5), declared_payload_len=12)
    await run_drop_case(dut, pkt2)

    pkt3 = PacketSpec(vc=0x1, dt=0x2A, payload=gen_payload(70, seed=6), declared_payload_len=70)
    await run_match_case(dut, pkt3, expected_seq=1)


@cocotb.test()
async def test_error_latch(dut):
    await apply_reset(dut)
    await configure_filter(dut, vc_en=1, dt_en=1, vc=0x1, dt=0x2A)

    pkt = PacketSpec(
        vc=0x1,
        dt=0x2A,
        payload=gen_payload(80, seed=7),
        declared_payload_len=80,
        crc_err_first=1,
        ecc_err_last=1,
    )
    await run_match_case(dut, pkt, expected_seq=0)


@cocotb.test()
async def test_truncation_detection(dut):
    await apply_reset(dut)
    await configure_filter(dut, vc_en=1, dt_en=1, vc=0x1, dt=0x2A)

    pkt0 = PacketSpec(
        vc=0x1,
        dt=0x2A,
        payload=gen_payload(20, seed=8),
        declared_payload_len=24,
    )
    await run_match_case(dut, pkt0, expected_seq=0)

    pkt1 = PacketSpec(
        vc=0x1,
        dt=0x2A,
        payload=gen_payload(48, seed=9),
        declared_payload_len=32,
        trunc_err_last=1,
    )
    await run_match_case(dut, pkt1, expected_seq=1)


@cocotb.test()
async def test_backpressure(dut):
    await apply_reset(dut)
    await configure_filter(dut, vc_en=1, dt_en=1, vc=0x1, dt=0x2A)

    stop_flag = [False]
    cocotb.start_soon(random_backpressure(dut, stop_flag))

    try:
        pkt0 = PacketSpec(vc=0x1, dt=0x2A, payload=gen_payload(96, seed=10), declared_payload_len=96)
        await run_match_case(dut, pkt0, expected_seq=0, timeout_cycles=4000)

        pkt1 = PacketSpec(vc=0x1, dt=0x2A, payload=gen_payload(33, seed=11), declared_payload_len=33)
        await run_match_case(dut, pkt1, expected_seq=1, timeout_cycles=4000)
    finally:
        stop_flag[0] = True
        await ClockCycles(dut.clk_i, 4)


@cocotb.test()
async def test_disable_vc_filter(dut):
    await apply_reset(dut)
    await configure_filter(dut, vc_en=0, dt_en=1, vc=0x0, dt=0x2A)

    pkt0 = PacketSpec(vc=0x2, dt=0x2A, payload=gen_payload(24, seed=12), declared_payload_len=24)
    await run_match_case(dut, pkt0, expected_seq=0)

    pkt1 = PacketSpec(vc=0x3, dt=0x15, payload=gen_payload(24, seed=13), declared_payload_len=24)
    await run_drop_case(dut, pkt1)
