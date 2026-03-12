from __future__ import annotations

import cocotb

from awr_payload_model import SLOT_TOTAL_ALIGNED
from platform_env import PlatformConfig, RING_BASE_ADDR, SimulationPlatformEnv


def gen_payload(length: int, seed: int = 0) -> bytes:
    return bytes(((seed + idx * 29 + length) & 0xFF) for idx in range(length))


@cocotb.test()
async def test_ringbuffer_commit_addr_progression(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure(PlatformConfig(ring_size_bytes=0x10000))

    payload0 = gen_payload(80, seed=0x10)
    payload1 = gen_payload(144, seed=0x20)

    await env.send_packet(payload0, seq=0)
    commit0 = await env.wait_for_commit()
    await env.verify_memory_for_last_commit()
    await env.readback_next_slot()

    await env.send_packet(payload1, seq=1)
    commit1 = await env.wait_for_commit()
    await env.verify_memory_for_last_commit()
    await env.readback_next_slot()

    assert commit0.addr == RING_BASE_ADDR
    assert commit1.addr == RING_BASE_ADDR + SLOT_TOTAL_ALIGNED


@cocotb.test()
async def test_ringbuffer_wraparound(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure(PlatformConfig(ring_size_bytes=SLOT_TOTAL_ALIGNED * 2))

    addrs = []
    for seq in range(3):
        await env.send_packet(gen_payload(96 + seq * 8, seed=seq), seq=seq)
        commit = await env.wait_for_commit()
        addrs.append(commit.addr)
        await env.verify_memory_for_last_commit()
        await env.readback_next_slot()

    assert addrs == [
        RING_BASE_ADDR,
        RING_BASE_ADDR + SLOT_TOTAL_ALIGNED,
        RING_BASE_ADDR,
    ]
