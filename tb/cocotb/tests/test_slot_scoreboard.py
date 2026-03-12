from __future__ import annotations

from dataclasses import dataclass

from awr_payload_model import SLOT_TOTAL_ALIGNED, gen_awr_payload
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
