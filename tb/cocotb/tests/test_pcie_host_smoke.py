from __future__ import annotations

import cocotb
from cocotb.triggers import Timer

from drivers.host_rc_driver import HostRootComplexModel
from model.ddr_ringbuffer_pcie_stub import DdrRingbufferPcieStubEndpoint


def gen_payload(length: int, seed: int) -> bytes:
    return bytes(((seed + idx * 19 + length) & 0xFF) for idx in range(length))


async def build_host():
    endpoint = DdrRingbufferPcieStubEndpoint()
    rc = HostRootComplexModel()
    rc.make_port().connect(endpoint.make_device())
    host = await rc.claim_host_rc_driver(vendor_id=endpoint.vendor_id, device_id=endpoint.device_id)
    return endpoint, host


@cocotb.test()
async def test_pcie_host_bringup_smoke(dut):
    del dut

    endpoint, host = await build_host()
    await host.program_ring(ring_base_addr=0x1000, ring_size_bytes=0x4000)

    payload = gen_payload(73, seed=0x31)
    expected = endpoint.push_slot(payload, seq=3)

    status = await host.read_status()
    assert status.empty == 0
    assert status.committed_bytes == len(payload)

    desc = await host.read_head_descriptor(issue_read=True)
    assert desc is not None
    assert desc.addr == expected.addr
    assert desc.slot_bytes == expected.slot_bytes
    assert desc.seq == expected.seq

    slot = await host.read_slot_data(desc, burst_bytes=17)
    assert slot.payload == payload

    last_commit = await host.read_last_commit()
    assert last_commit.valid == 1
    assert last_commit.addr == expected.addr
    assert last_commit.seq == expected.seq

    await host.consume_head()
    assert await host.read_head_descriptor() is None
    assert (await host.read_status()).empty == 1


@cocotb.test()
async def test_pcie_host_waits_for_concurrent_slot_and_wraps_readback(dut):
    del dut

    endpoint, host = await build_host()
    await host.program_ring(ring_base_addr=0x1000, ring_size_bytes=0x40)

    first_payload = gen_payload(24, seed=0x41)
    endpoint.push_slot(first_payload, seq=0)
    first_slot = await host.request_slot_read(burst_bytes=11)
    assert first_slot.payload == first_payload

    wrapped_payload = gen_payload(52, seed=0x57)
    reader = cocotb.start_soon(
        host.request_slot_read(timeout_ns=5_000, poll_interval_ns=50, burst_bytes=13)
    )
    await Timer(200, unit="ns")
    expected = endpoint.push_slot(wrapped_payload, seq=1)

    wrapped_slot = await reader
    assert wrapped_slot.descriptor.addr == expected.addr
    assert wrapped_slot.descriptor.slot_bytes == len(wrapped_payload)
    assert wrapped_slot.payload == wrapped_payload
    assert (await host.read_status()).empty == 1
