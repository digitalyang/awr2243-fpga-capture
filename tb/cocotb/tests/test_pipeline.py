from __future__ import annotations

import cocotb

from platform_env import PlatformConfig, SimulationPlatformEnv
from test_csi2_awr_packets import (
    DT_AWR_RAW,
    DT_FE,
    DT_FS,
    DT_LE,
    DT_LS,
    build_awr_frame_packets,
    build_long_packet,
    build_short_packet,
)

SP_ERR_NONE = 0
SP_ERR_FS_WHILE_ACTIVE = 1
SP_ERR_FE_WITHOUT_FS = 2
SP_ERR_FE_BEFORE_LE = 3
SP_ERR_LS_WITHOUT_FS = 4
SP_ERR_NESTED_LS = 5
SP_ERR_LE_WITHOUT_LS = 6


def gen_payload(length: int, seed: int = 0) -> bytes:
    return bytes(((seed + idx * 17 + length) & 0xFF) for idx in range(length))


def assert_csi_rx_state(
    dut,
    *,
    frame_active: int,
    line_active: int,
    frame_count: int,
    line_count: int,
    short_packet_count: int,
    last_short_dt: int,
    short_packet_error: int | None = None,
    short_packet_error_count: int | None = None,
    last_short_error_code: int | None = None,
) -> None:
    assert int(dut.csi_rx_frame_active.value) == frame_active
    assert int(dut.csi_rx_line_active.value) == line_active
    assert int(dut.csi_rx_frame_count.value) == frame_count
    assert int(dut.csi_rx_line_count.value) == line_count
    assert int(dut.csi_rx_short_packet_count.value) == short_packet_count
    assert int(dut.csi_rx_last_short_dt.value) == last_short_dt
    if short_packet_error is not None:
        assert int(dut.csi_rx_short_packet_error.value) == short_packet_error
    if short_packet_error_count is not None:
        assert int(dut.csi_rx_short_packet_error_count.value) == short_packet_error_count
    if last_short_error_code is not None:
        assert int(dut.csi_rx_last_short_error_code.value) == last_short_error_code


async def run_raw_sequence(env: SimulationPlatformEnv, raw_packets: list[bytes]) -> int:
    long_packet_seq = 0
    for raw_packet in raw_packets:
        info = await env.send_raw_csi2_packet(raw_packet, seq=long_packet_seq)
        if info.is_long:
            commit = await env.wait_for_commit()
            await env.verify_memory_for_last_commit()
            readback = await env.readback_next_slot()
            assert commit.seq == long_packet_seq
            assert readback.seq == long_packet_seq
            long_packet_seq += 1

    await env.wait_for_cdc_idle()
    return long_packet_seq


@cocotb.test()
async def test_top_sanity(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure()

    payload = gen_payload(96, seed=0x11)
    bridge_before = env.snapshot_bridge_counters()
    await env.send_packet(payload, seq=0)
    commit = await env.wait_for_commit()
    env.assert_bridge_write_activity(bridge_before, expected_byte_delta=commit.slot_bytes)
    await env.verify_memory_for_last_commit()
    readback = await env.readback_next_slot()

    assert commit.seq == 0
    assert readback.seq == 0


@cocotb.test()
async def test_pipeline_back_to_back_slots(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure(PlatformConfig(ring_size_bytes=0x10000))

    payloads = [
        gen_payload(64, seed=0x20),
        gen_payload(257, seed=0x40),
        gen_payload(768, seed=0x60),
    ]

    commits = []
    for seq, payload in enumerate(payloads):
        await env.send_packet(payload, seq=seq)
        commits.append(await env.wait_for_commit())
        await env.verify_memory_for_last_commit()

    readbacks = []
    for _ in payloads:
        readbacks.append(await env.readback_next_slot())

    assert [commit.seq for commit in commits] == [0, 1, 2]
    assert [slot.seq for slot in readbacks] == [0, 1, 2]
    assert commits[1].addr > commits[0].addr
    assert commits[2].addr > commits[1].addr


@cocotb.test()
async def test_pipeline_invalid_slot_roundtrip(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure(PlatformConfig(drop_invalid_slot=0))

    payload = gen_payload(128, seed=0x33)
    await env.send_packet(payload, seq=0, pkt_crc_err=1)
    commit = await env.wait_for_commit()
    await env.verify_memory_for_last_commit()
    readback = await env.readback_next_slot()

    assert commit.valid_good == 0
    assert readback.valid_good == 0


@cocotb.test()
async def test_pipeline_controller_drops_invalid(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure(PlatformConfig(drop_invalid_slot=1))

    payload = gen_payload(128, seed=0x55)
    await env.send_packet(payload, seq=0, pkt_crc_err=1)
    env.scoreboard.pending_commits.clear()
    await env.expect_no_commit(cycles=200)


@cocotb.test()
async def test_pipeline_awr_frame_roundtrip(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure()

    num_chirps = 2
    long_packet_seq = await run_raw_sequence(
        env,
        build_awr_frame_packets(num_chirps=num_chirps, ns=64, vc=env.config.vc),
    )

    assert long_packet_seq == num_chirps
    assert int(dut.csi_rx_packet_count.value) == num_chirps
    assert_csi_rx_state(
        dut,
        frame_active=0,
        line_active=0,
        frame_count=1,
        line_count=num_chirps,
        short_packet_count=(num_chirps * 2) + 2,
        last_short_dt=DT_FE,
        short_packet_error=0,
        short_packet_error_count=0,
        last_short_error_code=SP_ERR_NONE,
    )


@cocotb.test()
async def test_pipeline_short_packet_missing_ls(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure()

    payload = gen_payload(96, seed=0x71)
    long_packet_seq = await run_raw_sequence(
        env,
        [
            build_short_packet(dt=DT_FS, vc=env.config.vc, short_data=0),
            build_long_packet(dt=DT_AWR_RAW, vc=env.config.vc, payload=payload),
            build_short_packet(dt=DT_LE, vc=env.config.vc, short_data=0),
            build_short_packet(dt=DT_FE, vc=env.config.vc, short_data=0),
        ],
    )

    assert long_packet_seq == 1
    assert int(dut.csi_rx_packet_count.value) == 1
    assert_csi_rx_state(
        dut,
        frame_active=0,
        line_active=0,
        frame_count=1,
        line_count=0,
        short_packet_count=3,
        last_short_dt=DT_FE,
        short_packet_error=1,
        short_packet_error_count=1,
        last_short_error_code=SP_ERR_LE_WITHOUT_LS,
    )


@cocotb.test()
async def test_pipeline_short_packet_early_fe(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure()

    payload = gen_payload(128, seed=0x72)

    await env.inject_short_packet(dt=DT_FS, short_data=0)
    await env.inject_short_packet(dt=DT_LS, short_data=0)
    assert_csi_rx_state(
        dut,
        frame_active=1,
        line_active=1,
        frame_count=1,
        line_count=1,
        short_packet_count=2,
        last_short_dt=DT_LS,
    )

    await env.inject_short_packet(dt=DT_FE, short_data=0)
    assert_csi_rx_state(
        dut,
        frame_active=0,
        line_active=0,
        frame_count=1,
        line_count=1,
        short_packet_count=3,
        last_short_dt=DT_FE,
    )

    await env.send_packet(payload, seq=0)
    commit = await env.wait_for_commit()
    await env.verify_memory_for_last_commit()
    readback = await env.readback_next_slot()
    await env.wait_for_cdc_idle()

    assert commit.seq == 0
    assert readback.seq == 0
    assert int(dut.csi_rx_packet_count.value) == 1
    assert_csi_rx_state(
        dut,
        frame_active=0,
        line_active=0,
        frame_count=1,
        line_count=1,
        short_packet_count=3,
        last_short_dt=DT_FE,
        short_packet_error=1,
        short_packet_error_count=1,
        last_short_error_code=SP_ERR_FE_BEFORE_LE,
    )


@cocotb.test()
async def test_pipeline_short_packet_orphan_control_packets(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure()

    await env.inject_short_packet(dt=DT_LS, short_data=0)
    assert_csi_rx_state(
        dut,
        frame_active=0,
        line_active=0,
        frame_count=0,
        line_count=0,
        short_packet_count=1,
        last_short_dt=DT_LS,
        short_packet_error=1,
        short_packet_error_count=1,
        last_short_error_code=SP_ERR_LS_WITHOUT_FS,
    )

    await env.inject_short_packet(dt=DT_FE, short_data=0)
    await env.wait_for_cdc_idle()
    assert_csi_rx_state(
        dut,
        frame_active=0,
        line_active=0,
        frame_count=0,
        line_count=0,
        short_packet_count=2,
        last_short_dt=DT_FE,
        short_packet_error=1,
        short_packet_error_count=2,
        last_short_error_code=SP_ERR_FE_WITHOUT_FS,
    )


@cocotb.test()
async def test_pipeline_short_packet_cross_frame_recovery(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure()

    payload = gen_payload(160, seed=0x73)

    await env.inject_short_packet(dt=DT_FS, short_data=0)
    await env.inject_short_packet(dt=DT_LS, short_data=0)
    assert_csi_rx_state(
        dut,
        frame_active=1,
        line_active=1,
        frame_count=1,
        line_count=1,
        short_packet_count=2,
        last_short_dt=DT_LS,
        short_packet_error=0,
        short_packet_error_count=0,
        last_short_error_code=SP_ERR_NONE,
    )

    await env.inject_short_packet(dt=DT_FS, short_data=1)
    assert_csi_rx_state(
        dut,
        frame_active=1,
        line_active=0,
        frame_count=2,
        line_count=1,
        short_packet_count=3,
        last_short_dt=DT_FS,
        short_packet_error=1,
        short_packet_error_count=1,
        last_short_error_code=SP_ERR_FS_WHILE_ACTIVE,
    )

    await env.inject_short_packet(dt=DT_LS, short_data=1)
    await env.send_packet(payload, seq=0)
    commit = await env.wait_for_commit()
    await env.verify_memory_for_last_commit()
    readback = await env.readback_next_slot()
    await env.inject_short_packet(dt=DT_LE, short_data=1)
    await env.inject_short_packet(dt=DT_FE, short_data=1)
    await env.wait_for_cdc_idle()

    assert commit.seq == 0
    assert readback.seq == 0
    assert int(dut.csi_rx_packet_count.value) == 1
    assert_csi_rx_state(
        dut,
        frame_active=0,
        line_active=0,
        frame_count=2,
        line_count=2,
        short_packet_count=6,
        last_short_dt=DT_FE,
        short_packet_error=1,
        short_packet_error_count=1,
        last_short_error_code=SP_ERR_FS_WHILE_ACTIVE,
    )
