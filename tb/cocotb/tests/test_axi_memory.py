from __future__ import annotations

from model.axi_memory import AxiMemoryModel


def test_axi_memory_ring_write_and_read_wrap():
    memory = AxiMemoryModel(dut=None, beat_bytes=32)
    ring_base = 0x4000
    ring_size = 32
    start_addr = ring_base + ring_size - 8
    payload = bytes(range(20))

    memory.write_ring_bytes(
        ring_base=ring_base,
        ring_size=ring_size,
        start_addr=start_addr,
        data=payload,
    )

    assert memory.read_ring_bytes(
        ring_base=ring_base,
        ring_size=ring_size,
        start_addr=start_addr,
        byte_count=len(payload),
    ) == payload
    assert memory.read_bytes(start_addr, 8) == payload[:8]
    assert memory.read_bytes(ring_base, 12) == payload[8:]


def test_axi_memory_normalizes_ring_addresses():
    assert AxiMemoryModel.normalize_ring_addr(ring_base=0x1000, ring_size=0x80, addr=0x1080) == 0x1000
    assert AxiMemoryModel.normalize_ring_addr(ring_base=0x1000, ring_size=0x80, addr=0x1094) == 0x1014
