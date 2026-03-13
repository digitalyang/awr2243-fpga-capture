from __future__ import annotations

from dataclasses import dataclass

from awr_payload_model import SLOT_TOTAL_ALIGNED, gen_awr_payload
from model.axi_memory import AxiMemoryModel
from scoreboard.slot_scoreboard import SlotScoreboard


@dataclass
class DummyReadback:
    seq: int
    slot_bytes: int
    valid_good: int
    overflow_err: int
    payload: bytes


class DummyMemory:
    def __init__(self, blob: bytes):
        self.blob = blob

    def read_ring_bytes(self, ring_base: int, ring_size: int, start_addr: int, byte_count: int) -> bytes:
        assert ring_base == 0x1000
        assert ring_size == SLOT_TOTAL_ALIGNED * 4
        assert start_addr == 0x1000
        assert byte_count == SLOT_TOTAL_ALIGNED
        return self.blob


def test_slot_scoreboard_commit_and_readback():
    payload = gen_awr_payload(chirp_num=1, ns=16, pattern="const")
    scoreboard = SlotScoreboard(ring_base_addr=0x1000, ring_size_bytes=SLOT_TOTAL_ALIGNED * 4)
    expectation = scoreboard.push_expectation(payload, seq=0)

    scoreboard.check_commit(
        seq=0,
        slot_bytes=expectation.slot_bytes,
        valid_good=expectation.valid_good,
        overflow_err=expectation.overflow_err,
        addr=expectation.addr,
    )
    scoreboard.check_memory(DummyMemory(expectation.slot_data), expectation)
    scoreboard.check_readback(
        DummyReadback(
            seq=0,
            slot_bytes=expectation.slot_bytes,
            valid_good=expectation.valid_good,
            overflow_err=expectation.overflow_err,
            payload=expectation.slot_data,
        )
    )

    assert scoreboard.summary()["matches"] == 3


def test_slot_scoreboard_checks_host_dma_reads_across_wrap():
    ring_base_addr = 0x2000
    ring_size_bytes = (SLOT_TOTAL_ALIGNED * 2) - 64
    scoreboard = SlotScoreboard(ring_base_addr=ring_base_addr, ring_size_bytes=ring_size_bytes)
    memory = AxiMemoryModel(dut=None, beat_bytes=32)

    payload0 = gen_awr_payload(chirp_num=2, ns=8, pattern="ramp")
    exp0 = scoreboard.push_expectation(payload0, seq=0)
    scoreboard.check_commit(
        seq=0,
        slot_bytes=exp0.slot_bytes,
        valid_good=exp0.valid_good,
        overflow_err=exp0.overflow_err,
        addr=exp0.addr,
    )
    memory.write_ring_bytes(
        ring_base=ring_base_addr,
        ring_size=ring_size_bytes,
        start_addr=exp0.addr,
        data=exp0.slot_data,
    )
    scoreboard.check_memory(memory, exp0)

    payload1 = gen_awr_payload(chirp_num=3, ns=24, pattern="channel_tag")
    exp1 = scoreboard.push_expectation(payload1, seq=1)
    scoreboard.check_commit(
        seq=1,
        slot_bytes=exp1.slot_bytes,
        valid_good=exp1.valid_good,
        overflow_err=exp1.overflow_err,
        addr=exp1.addr,
    )
    memory.write_ring_bytes(
        ring_base=ring_base_addr,
        ring_size=ring_size_bytes,
        start_addr=exp1.addr,
        data=exp1.slot_data,
    )
    scoreboard.check_memory(memory, exp1)

    wrapped_start_addr = exp1.ring_spans[0].end_addr - 32
    host_dma_bytes = memory.read_ring_bytes(
        ring_base=ring_base_addr,
        ring_size=ring_size_bytes,
        start_addr=wrapped_start_addr,
        byte_count=96,
    )
    scoreboard.check_host_dma_read(addr=wrapped_start_addr, data=host_dma_bytes, expectation=exp1, seq=1)

    assert exp1.wraps is True
    assert len(exp1.ring_spans) == 2
    assert scoreboard.summary()["matches"] == 5
