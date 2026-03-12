from __future__ import annotations

import cocotb
from cocotb.triggers import RisingEdge

from drivers.axis_payload_source import TUSER_DT_LSB, TUSER_PAYLOAD_LEN_LSB, TUSER_VC_LSB
from drivers.clk_rst import ClockBundle
from monitors.axis_monitor import AxisStreamMonitor
from platform_env import PlatformConfig, SimulationPlatformEnv


def gen_payload(length: int, seed: int = 0) -> bytes:
    return bytes(((seed + idx * 7 + length) & 0xFF) for idx in range(length))


def tuser_field(value: int, lsb: int, width: int) -> int:
    return (value >> lsb) & ((1 << width) - 1)


async def wait_for_fifo_level_at_least(dut, level: int, timeout_cycles: int = 3000) -> int:
    high_watermark = 0
    for _ in range(timeout_cycles):
        await RisingEdge(dut.axis_clk)
        current = int(dut.cdc_fifo_level.value)
        high_watermark = max(high_watermark, current)
        if current >= level:
            return high_watermark
    raise TimeoutError(f"Timed out waiting for CDC FIFO level >= {level}, high watermark was {high_watermark}")


async def wait_for_source_backpressure(dut, timeout_cycles: int = 3000) -> None:
    for _ in range(timeout_cycles):
        await RisingEdge(dut.video_aclk)
        if int(dut.s_axis_tvalid.value) and not int(dut.s_axis_tready.value):
            return
    raise TimeoutError("Timed out waiting for source-side CDC backpressure")


@cocotb.test()
async def test_cdc_async_fifo_smoke(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure()

    monitor = AxisStreamMonitor(
        dut.axis_clk,
        dut.cdc_axis_tdata,
        dut.cdc_axis_tkeep,
        dut.cdc_axis_tvalid,
        dut.cdc_axis_tready,
        dut.cdc_axis_tlast,
        dut.cdc_axis_tuser,
    )

    payload = gen_payload(173, seed=0x12)
    frame_task = cocotb.start_soon(monitor.capture_frame(timeout_cycles=3000))
    await env.send_packet(payload, seq=0)
    frame = await frame_task
    commit = await env.wait_for_commit()
    await env.verify_memory_for_last_commit()
    await env.readback_next_slot()
    await env.wait_for_cdc_idle()

    assert frame.data == payload
    assert tuser_field(frame.first_tuser, TUSER_VC_LSB, 2) == env.config.vc
    assert tuser_field(frame.first_tuser, TUSER_DT_LSB, 6) == env.config.dt
    assert tuser_field(frame.first_tuser, TUSER_PAYLOAD_LEN_LSB, 16) == len(payload)
    assert commit.seq == 0
    assert int(dut.cdc_fifo_level.value) == 0


@cocotb.test()
async def test_cdc_timing_skewed_clocks_and_mock_gaps(dut):
    env = SimulationPlatformEnv(dut)
    await env.start(
        clocks=ClockBundle(
            video_period_ns=4.6,
            axis_period_ns=4.0,
            axi_period_ns=4.0,
            video_start_delay_ns=0.9,
            axis_start_delay_ns=0.2,
            axi_start_delay_ns=0.2,
        )
    )
    await env.reset()
    await env.configure(PlatformConfig(ring_size_bytes=0x10000))
    await env.configure_csi_rx_mock(startup_cycles=2, interpacket_gap_cycles=2, beat_gap_cycles=1)

    rx_monitor = AxisStreamMonitor(
        dut.video_aclk,
        dut.csi_rx_axis_tdata,
        dut.csi_rx_axis_tkeep,
        dut.csi_rx_axis_tvalid,
        dut.csi_rx_axis_tready,
        dut.csi_rx_axis_tlast,
        dut.csi_rx_axis_tuser,
    )

    cdc_monitor = AxisStreamMonitor(
        dut.axis_clk,
        dut.cdc_axis_tdata,
        dut.cdc_axis_tkeep,
        dut.cdc_axis_tvalid,
        dut.cdc_axis_tready,
        dut.cdc_axis_tlast,
        dut.cdc_axis_tuser,
    )

    payloads = [
        gen_payload(65, seed=0x31),
        gen_payload(222, seed=0x77),
        gen_payload(511, seed=0x4C),
    ]

    rx_frames = []
    cdc_frames = []
    for seq, payload in enumerate(payloads):
        rx_task = cocotb.start_soon(rx_monitor.capture_frame(timeout_cycles=4000))
        cdc_task = cocotb.start_soon(cdc_monitor.capture_frame(timeout_cycles=4000))
        await env.send_packet(payload, seq=seq)
        rx_frames.append(await rx_task)
        cdc_frames.append(await cdc_task)
        commit = await env.wait_for_commit()
        await env.verify_memory_for_last_commit()
        assert commit.seq == seq

    readbacks = []
    for _ in payloads:
        readbacks.append(await env.readback_next_slot())
    await env.wait_for_cdc_idle()

    assert [frame.data for frame in rx_frames] == payloads
    assert [frame.data for frame in cdc_frames] == payloads
    assert int(dut.csi_rx_packet_count.value) == len(payloads)
    assert int(dut.csi_rx_beat_count.value) >= sum(frame.beat_count for frame in rx_frames)
    assert tuser_field(cdc_frames[0].first_tuser, TUSER_VC_LSB, 2) == env.config.vc
    assert tuser_field(cdc_frames[0].first_tuser, TUSER_DT_LSB, 6) == env.config.dt
    assert [slot.seq for slot in readbacks] == [0, 1, 2]


@cocotb.test()
async def test_cdc_fifo_fill_and_backpressure(dut):
    env = SimulationPlatformEnv(dut)
    await env.start(
        clocks=ClockBundle(
            video_period_ns=3.2,
            axis_period_ns=5.0,
            axi_period_ns=5.0,
            video_start_delay_ns=0.4,
            axis_start_delay_ns=0.0,
            axi_start_delay_ns=0.0,
        )
    )
    await env.reset()
    await env.configure(PlatformConfig(ring_size_bytes=0x10000))
    await env.configure_csi_rx_mock(startup_cycles=0, interpacket_gap_cycles=0, beat_gap_cycles=0)

    payload = gen_payload(1024, seed=0x5A)
    await env.set_cdc_sink_pause(1)
    send_task = cocotb.start_soon(env.send_packet(payload, seq=0))

    high_watermark = await wait_for_fifo_level_at_least(dut, level=8)
    await wait_for_source_backpressure(dut)
    await env.expect_no_commit(cycles=32)

    await env.set_cdc_sink_pause(0)
    await send_task

    commit = await env.wait_for_commit(timeout_cycles=4000)
    await env.verify_memory_for_last_commit()
    readback = await env.readback_next_slot(timeout_cycles=4000)
    await env.wait_for_cdc_idle(timeout_cycles=2048)

    assert high_watermark >= 8
    assert int(dut.csi_rx_packet_count.value) == 1
    assert commit.seq == 0
    assert readback.seq == 0
