from __future__ import annotations

from awr_payload_model import SLOT_TOTAL_ALIGNED, gen_awr_payload
from model.slot_refmodel import SlotRefModel


def test_slot_refmodel_builds_aligned_slot():
    refmodel = SlotRefModel()
    payload = gen_awr_payload(chirp_num=3, ns=64, pattern="ramp")
    expectation = refmodel.build_expectation(payload, seq=5)

    assert expectation.seq == 5
    assert expectation.slot_bytes == SLOT_TOTAL_ALIGNED
    assert len(expectation.slot_data) == SLOT_TOTAL_ALIGNED
    assert expectation.valid_good == 1
    assert expectation.overflow_err == 0


def test_slot_refmodel_wraps_write_pointer():
    refmodel = SlotRefModel()
    ring_size_bytes = SLOT_TOTAL_ALIGNED * 2

    wr_ptr = refmodel.advance_wr_ptr(0, ring_size_bytes, SLOT_TOTAL_ALIGNED)
    assert wr_ptr == SLOT_TOTAL_ALIGNED

    wr_ptr = refmodel.advance_wr_ptr(wr_ptr, ring_size_bytes, SLOT_TOTAL_ALIGNED)
    assert wr_ptr == 0
