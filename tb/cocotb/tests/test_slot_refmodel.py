from __future__ import annotations

from awr_payload_model import SLOT_TOTAL_ALIGNED, SLOT_TOTAL_UNALIGNED, gen_awr_payload
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
    assert expectation.padding_region.offset == SLOT_TOTAL_UNALIGNED
    assert expectation.padding_region.length == SLOT_TOTAL_ALIGNED - SLOT_TOTAL_UNALIGNED
    assert expectation.padding_region.data == b"\x00" * expectation.padding_region.length


def test_slot_refmodel_wraps_write_pointer():
    refmodel = SlotRefModel()
    ring_size_bytes = SLOT_TOTAL_ALIGNED * 2

    wr_ptr = refmodel.advance_wr_ptr(0, ring_size_bytes, SLOT_TOTAL_ALIGNED)
    assert wr_ptr == SLOT_TOTAL_ALIGNED

    wr_ptr = refmodel.advance_wr_ptr(wr_ptr, ring_size_bytes, SLOT_TOTAL_ALIGNED)
    assert wr_ptr == 0


def test_slot_refmodel_maps_host_visible_slot_across_wrap():
    refmodel = SlotRefModel()
    payload = gen_awr_payload(chirp_num=9, ns=32, pattern="channel_tag")
    expectation = refmodel.build_expectation(payload, seq=7)

    ring_base_addr = 0x2000
    ring_size_bytes = SLOT_TOTAL_ALIGNED * 2
    start_addr = ring_base_addr + ring_size_bytes - 64
    host_slot = refmodel.map_host_slot(
        expectation,
        ring_base_addr=ring_base_addr,
        ring_size_bytes=ring_size_bytes,
        addr=start_addr,
    )

    assert host_slot.wraps is True
    assert len(host_slot.spans) == 2
    assert host_slot.spans[0].addr == start_addr
    assert host_slot.spans[0].length == 64
    assert host_slot.spans[1].addr == ring_base_addr
    assert host_slot.spans[1].length == SLOT_TOTAL_ALIGNED - 64
    assert host_slot.read() == expectation.slot_data
    assert host_slot.read(start_addr=start_addr + 48, byte_count=80) == expectation.slot_data[48:128]
