from __future__ import annotations

from dataclasses import dataclass

from awr_payload_model import SLOT_TOTAL_ALIGNED, SLOT_TOTAL_UNALIGNED, build_expected_slot_bytes, expected_sample_count


@dataclass
class SlotExpectation:
    seq: int
    payload: bytes
    slot_data: bytes
    slot_bytes: int
    valid_good: int
    overflow_err: int
    sample_count: int
    addr: int | None = None


class SlotRefModel:
    def build_expectation(
        self,
        payload: bytes,
        *,
        seq: int,
        pkt_crc_err: int = 0,
        pkt_ecc_err: int = 0,
        pkt_trunc_err: int = 0,
    ) -> SlotExpectation:
        valid_good = int(not (pkt_crc_err or pkt_ecc_err or pkt_trunc_err))
        overflow_err = int(len(payload) > SLOT_TOTAL_UNALIGNED)
        sample_count = expected_sample_count(payload, pkt_trunc_err=bool(pkt_trunc_err))
        slot_data = build_expected_slot_bytes(payload, pkt_trunc_err=bool(pkt_trunc_err))
        return SlotExpectation(
            seq=seq,
            payload=payload,
            slot_data=slot_data,
            slot_bytes=SLOT_TOTAL_ALIGNED,
            valid_good=valid_good,
            overflow_err=overflow_err,
            sample_count=sample_count,
        )

    @staticmethod
    def predict_commit_addr(ring_base_addr: int, wr_ptr: int) -> int:
        return ring_base_addr + wr_ptr

    @staticmethod
    def advance_wr_ptr(wr_ptr: int, ring_size_bytes: int, slot_bytes: int) -> int:
        return (wr_ptr + slot_bytes) % ring_size_bytes
