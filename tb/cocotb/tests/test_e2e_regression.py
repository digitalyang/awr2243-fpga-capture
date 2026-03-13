from __future__ import annotations

import cocotb
from cocotb.triggers import RisingEdge

from awr_payload_model import SLOT_TOTAL_ALIGNED, SLOT_TOTAL_UNALIGNED
from platform_env import PlatformConfig, SimulationPlatformEnv


def gen_payload(length: int, seed: int = 0) -> bytes:
    return bytes(((seed + idx * 13 + length) & 0xFF) for idx in range(length))


async def wait_until(clock, predicate, *, timeout_cycles: int, description: str) -> None:
    for _ in range(timeout_cycles):
        await RisingEdge(clock)
        if predicate():
            return
    raise TimeoutError(f"Timed out waiting for {description}")


@cocotb.test()
async def test_e2e_host_burst_read(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure(PlatformConfig(ring_size_bytes=0x10000))

    payload = gen_payload(768, seed=0x31)
    await env.send_packet(payload, seq=0)
    commit = await env.wait_for_commit(timeout_cycles=4000)
    await env.verify_memory_for_last_commit()

    env.memory.clear_activity()
    slot = await env.host.read_next_slot(timeout_cycles=20000)
    expectation = env.scoreboard.check_readback(slot)
    await env.host.consume_slot()
    await env.wait_for_cdc_idle()

    assert slot.seq == 0
    assert slot.payload == expectation.slot_data
    assert len(env.memory.read_bursts) > 1
    assert env.memory.read_bursts[0].addr == commit.addr
    assert all(burst.observed_beats == burst.beats for burst in env.memory.read_bursts)
    assert all(burst.end_cycle is not None for burst in env.memory.read_bursts)
    assert sum(burst.byte_count for burst in env.memory.read_bursts) == slot.slot_bytes
    assert max(burst.beats for burst in env.memory.read_bursts) > 1
    assert int(dut.err_axi_rd_resp_o.value) == 0


@cocotb.test()
async def test_e2e_host_read_while_write(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure(PlatformConfig(ring_size_bytes=0x10000))
    env.memory.set_backpressure(ar_ready_delay=1, r_valid_delay=4, w_ready_delay=1, b_valid_delay=1)

    payload0 = gen_payload(640, seed=0x44)
    payload1 = gen_payload(960, seed=0x55)

    await env.send_packet(payload0, seq=0)
    await env.wait_for_commit(timeout_cycles=4000)
    await env.verify_memory_for_last_commit()

    env.memory.clear_activity()
    read_task = cocotb.start_soon(env.host.read_next_slot(timeout_cycles=25000))
    await wait_until(
        env.dut.axis_clk,
        lambda: len(env.memory.read_bursts) >= 1,
        timeout_cycles=4000,
        description="host read burst launch",
    )

    send_task = cocotb.start_soon(env.send_packet(payload1, seq=1))
    await wait_until(
        env.dut.axis_clk,
        lambda: len(env.memory.write_bursts) >= 1,
        timeout_cycles=8000,
        description="second slot AXI write launch",
    )
    assert not read_task.done(), "Host read completed before the second slot write reached DDR"

    await send_task
    commit1 = await env.wait_for_commit(timeout_cycles=12000)
    await env.verify_memory_for_last_commit()

    assert int(dut.used_bytes_o.value) == SLOT_TOTAL_ALIGNED * 2
    assert int(dut.rd_slot_valid_o.value) == 1

    slot0 = await read_task
    env.scoreboard.check_readback(slot0)

    read_start = env.memory.read_bursts[0].start_cycle
    read_end = max(burst.end_cycle or 0 for burst in env.memory.read_bursts)
    assert any(read_start <= burst.start_cycle <= read_end for burst in env.memory.write_bursts)

    await env.host.consume_slot()
    slot1 = await env.host.read_next_slot(timeout_cycles=20000)
    env.scoreboard.check_readback(slot1)
    await env.host.consume_slot()
    await RisingEdge(env.dut.axis_clk)

    assert slot0.seq == 0
    assert slot1.seq == 1
    assert commit1.seq == 1
    assert int(dut.used_bytes_o.value) == 0


@cocotb.test()
async def test_e2e_payload_truncation(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure()

    payload = gen_payload(704, seed=0x6A)
    await env.send_packet(
        payload,
        seq=0,
        declared_payload_len=len(payload) + 23,
        pkt_trunc_err=1,
    )
    commit = await env.wait_for_commit(timeout_cycles=4000)
    await env.verify_memory_for_last_commit()

    slot = await env.host.read_next_slot(timeout_cycles=20000)
    env.scoreboard.check_readback(slot)
    await env.host.consume_slot()
    await env.wait_for_cdc_idle()

    assert commit.valid_good == 0
    assert commit.overflow_err == 0
    assert slot.valid_good == 0
    assert slot.overflow_err == 0


@cocotb.test()
async def test_e2e_axi_backpressure(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure(PlatformConfig(ring_size_bytes=0x10000))
    env.memory.set_backpressure(
        aw_ready_delay=3,
        w_ready_delay=2,
        b_valid_delay=4,
        ar_ready_delay=5,
        r_valid_delay=2,
    )

    payload = gen_payload(896, seed=0x82)
    env.memory.clear_activity()
    await env.send_packet(payload, seq=0)
    commit = await env.wait_for_commit(timeout_cycles=20000)
    await env.verify_memory_for_last_commit()

    slot = await env.host.read_next_slot(timeout_cycles=25000)
    env.scoreboard.check_readback(slot)
    await env.host.consume_slot()
    await env.wait_for_cdc_idle()

    stall_counters = env.memory.stall_counters()

    assert commit.seq == 0
    assert slot.seq == 0
    assert env.memory.write_bursts
    assert env.memory.read_bursts
    assert all(value > 0 for value in stall_counters.values())
    assert int(dut.err_axi_wr_resp_o.value) == 0
    assert int(dut.err_axi_rd_resp_o.value) == 0
    assert int(dut.rd_error_o.value) == 0


@cocotb.test()
async def test_e2e_overflow_condition(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure()

    payload = gen_payload(SLOT_TOTAL_UNALIGNED + 29, seed=0xA4)
    await env.send_packet(payload, seq=0)
    commit = await env.wait_for_commit(timeout_cycles=5000)
    await env.verify_memory_for_last_commit()

    slot = await env.host.read_next_slot(timeout_cycles=20000)
    env.scoreboard.check_readback(slot)
    await env.host.consume_slot()
    await env.wait_for_cdc_idle()

    assert commit.overflow_err == 1
    assert commit.valid_good == 1
    assert slot.overflow_err == 1
    assert slot.valid_good == 1
    assert int(dut.overflow_count_o.value) == 1
