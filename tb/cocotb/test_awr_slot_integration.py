"""End-to-end integration: AWR2243 chirp payloads → fixed_slot_packer → slot verification.

Generates realistic radar ADC payloads (headers + 12-bit IQ samples + CQ)
and verifies the slot packer correctly wraps them into fixed-size slots.
"""
from __future__ import annotations

import struct
from typing import List

import cocotb
from cocotb.triggers import ClockCycles

from test_awr_payload import (
    NUM_RX_CHANNELS,
    RX_HEADER_BYTES_TOTAL,
    SAMPLE_BYTES,
    CQ_BYTES,
    calc_expected_payload_size,
    gen_awr2243_payload,
    pack_u12_list_le,
    sign_to_u12,
)
from fixed_slot_packer_cocotb import (
    AXIS_BEAT_BYTES,
    HEADER_BYTES,
    SAMPLE_AREA_BYTES,
    CQ_AREA_BYTES,
    SLOT_TOTAL_ALIGNED,
    SLOT_TOTAL_BEATS,
    SLOT_MAGIC,
    SLOT_VERSION,
    HDR_MAGIC_OFS,
    HDR_VERSION_OFS,
    HDR_FLAGS_OFS,
    HDR_PKT_SEQ_OFS,
    HDR_PKT_BYTES_OFS,
    HDR_SAMPLE_CNT_OFS,
    FLAG_VALID_GOOD_BIT,
    FLAG_OVERFLOW_BIT,
    SAMPLE_UNIT_BYTES,
    apply_reset,
    drive_packet,
    collect_slot,
    verify_slot,
    run_and_verify,
    random_backpressure,
)

# The slot packer treats the AWR payload as an opaque byte blob.
# AWR payload size = 8 (rx_hdr) + ns*12 (samples) + 8 (cq).
# Slot sample area = 4096 bytes → fits payloads up to 4096 bytes.
# ns=340 → payload = 8+340*12+8 = 4096 (exact fit)
# ns=341 → payload = 4108 (overflow)

NS_EXACT_FIT = (SAMPLE_AREA_BYTES - RX_HEADER_BYTES_TOTAL - CQ_BYTES) // SAMPLE_BYTES  # 340


def _extract_slot_payload(slot_data: bytes, payload_len: int) -> bytes:
    """Extract the raw payload region from a captured slot."""
    eff = min(payload_len, SAMPLE_AREA_BYTES)
    return slot_data[HEADER_BYTES : HEADER_BYTES + eff]


# ================================================================
#  Tests
# ================================================================

@cocotb.test()
async def test_awr_ramp_ns64(dut):
    """64-sample ramp chirp → full slot pipeline verification."""
    await apply_reset(dut)

    ns = 64
    payload = gen_awr2243_payload(chirp_num=0, ns=ns, pattern="ramp")
    assert len(payload) == calc_expected_payload_size(ns)  # 784

    cap = await run_and_verify(dut, payload, pkt_seq=0)

    recovered = _extract_slot_payload(cap.data, len(payload))
    assert recovered == payload, "Payload bytes not preserved through slot packer"
    dut._log.info(f"PASS: ramp ns={ns}, {len(payload)}B payload intact in slot")


@cocotb.test()
async def test_awr_const_ns1(dut):
    """1-sample const chirp (28 bytes) → minimal payload in slot."""
    await apply_reset(dut)

    ns = 1
    cq_val = 0xCAFE_BABE_DEAD_BEEF
    payload = gen_awr2243_payload(
        chirp_num=42, ns=ns, chirp_profile=5,
        cq_data=cq_val, pattern="const",
    )
    assert len(payload) == 28

    cap = await run_and_verify(dut, payload, pkt_seq=1)
    recovered = _extract_slot_payload(cap.data, len(payload))
    assert recovered == payload

    # Verify IQ values survive: unpack 12-bit from slot sample area
    iq_ofs = HEADER_BYTES + RX_HEADER_BYTES_TOTAL
    iq_raw = cap.data[iq_ofs : iq_ofs + SAMPLE_BYTES]
    bitstream = int.from_bytes(iq_raw, "little")
    expected_iq = [0x011, 0xFEE, 0x022, 0xFDD, 0x033, 0xFCC, 0x044, 0xFBB]
    for i, exp_v in enumerate(expected_iq):
        act_v = (bitstream >> (i * 12)) & 0xFFF
        assert act_v == exp_v, f"IQ[{i}] after slot: exp=0x{exp_v:03x} act=0x{act_v:03x}"

    dut._log.info("PASS: const ns=1, all 8 IQ values intact after slot packing")


@cocotb.test()
async def test_awr_ramp_ns256(dut):
    """256-sample ramp chirp (3088 bytes) → medium payload."""
    await apply_reset(dut)

    ns = 256
    payload = gen_awr2243_payload(chirp_num=100, ns=ns, pattern="ramp")
    assert len(payload) == calc_expected_payload_size(ns)

    cap = await run_and_verify(dut, payload, pkt_seq=2)
    recovered = _extract_slot_payload(cap.data, len(payload))
    assert recovered == payload
    dut._log.info(f"PASS: ramp ns={ns}, {len(payload)}B all verified")


@cocotb.test()
async def test_awr_exact_fit(dut):
    """ns=340 → payload exactly 4096 bytes = sample area, no padding, no overflow."""
    await apply_reset(dut)

    ns = NS_EXACT_FIT  # 340
    payload = gen_awr2243_payload(chirp_num=999, ns=ns, pattern="ramp")
    assert len(payload) == SAMPLE_AREA_BYTES, (
        f"Exact-fit: exp={SAMPLE_AREA_BYTES} got={len(payload)}"
    )

    cap = await run_and_verify(dut, payload, pkt_seq=3)

    # No overflow
    assert cap.sb_slot_overflow_err == 0
    act_flags = cap.data[HDR_FLAGS_OFS]
    assert ((act_flags >> FLAG_OVERFLOW_BIT) & 1) == 0, "Overflow flag should be 0"

    # Full sample area used, no zero padding in sample region
    recovered = cap.data[HEADER_BYTES : HEADER_BYTES + SAMPLE_AREA_BYTES]
    assert recovered == payload, "Exact-fit payload should fill entire sample area"
    dut._log.info(f"PASS: exact-fit ns={ns}, sample area fully utilized, no overflow")


@cocotb.test()
async def test_awr_overflow(dut):
    """ns=341 → payload 4108 bytes > sample area → overflow + truncation."""
    await apply_reset(dut)

    ns = NS_EXACT_FIT + 1  # 341
    payload = gen_awr2243_payload(chirp_num=500, ns=ns, pattern="ramp")
    assert len(payload) > SAMPLE_AREA_BYTES

    cap = await run_and_verify(dut, payload, pkt_seq=4)

    assert cap.sb_slot_overflow_err == 1, "Overflow flag should be set"
    act_flags = cap.data[HDR_FLAGS_OFS]
    assert ((act_flags >> FLAG_OVERFLOW_BIT) & 1) == 1

    # First 4096 bytes should be preserved
    recovered = cap.data[HEADER_BYTES : HEADER_BYTES + SAMPLE_AREA_BYTES]
    assert recovered == payload[:SAMPLE_AREA_BYTES], "First 4096B should survive truncation"
    dut._log.info(f"PASS: overflow ns={ns}, truncated correctly, overflow flag set")


@cocotb.test()
async def test_awr_channel_tag_integrity(dut):
    """Channel-tag pattern → verify per-channel markers survive end-to-end."""
    await apply_reset(dut)

    ns = 4
    payload = gen_awr2243_payload(chirp_num=7, ns=ns, pattern="channel_tag")
    cap = await run_and_verify(dut, payload, pkt_seq=5)

    expected_iq_per_sample = [0x001, 0x101, 0x002, 0x102, 0x003, 0x103, 0x004, 0x104]

    for s in range(ns):
        iq_ofs = HEADER_BYTES + RX_HEADER_BYTES_TOTAL + s * SAMPLE_BYTES
        iq_raw = cap.data[iq_ofs : iq_ofs + SAMPLE_BYTES]
        bitstream = int.from_bytes(iq_raw, "little")
        for i, exp_v in enumerate(expected_iq_per_sample):
            act_v = (bitstream >> (i * 12)) & 0xFFF
            assert act_v == exp_v, (
                f"Sample {s} IQ[{i}]: exp=0x{exp_v:03x} act=0x{act_v:03x}"
            )

    dut._log.info(f"PASS: channel_tag ns={ns}, all {ns}×8 IQ markers intact")


@cocotb.test()
async def test_awr_multi_chirp_sequence(dut):
    """Multiple chirps with different ns/patterns in sequence."""
    await apply_reset(dut)

    chirps = [
        {"chirp_num": 0,   "ns": 1,   "pattern": "const",       "profile": 0},
        {"chirp_num": 1,   "ns": 64,  "pattern": "ramp",        "profile": 1},
        {"chirp_num": 2,   "ns": 256, "pattern": "channel_tag", "profile": 2},
        {"chirp_num": 3,   "ns": NS_EXACT_FIT, "pattern": "ramp", "profile": 3},
        {"chirp_num": 4,   "ns": 16,  "pattern": "random",      "profile": 4},
    ]

    for seq, c in enumerate(chirps):
        payload = gen_awr2243_payload(
            chirp_num=c["chirp_num"], ns=c["ns"],
            chirp_profile=c["profile"], pattern=c["pattern"],
        )
        dut._log.info(
            f"Chirp {seq}: ns={c['ns']} pattern={c['pattern']} "
            f"payload={len(payload)}B"
        )
        cap = await run_and_verify(dut, payload, pkt_seq=seq)
        recovered = _extract_slot_payload(cap.data, len(payload))
        assert recovered == payload, f"Chirp {seq}: payload mismatch after slot packing"

    dut._log.info(f"PASS: {len(chirps)} chirps processed sequentially")


@cocotb.test()
async def test_awr_backpressure(dut):
    """Random tready toggling with real radar payloads."""
    await apply_reset(dut)

    stop_flag: List[bool] = [False]
    cocotb.start_soon(random_backpressure(dut, stop_flag))

    chirps = [
        {"ns": 32,  "pattern": "ramp"},
        {"ns": 128, "pattern": "const"},
        {"ns": NS_EXACT_FIT, "pattern": "random"},
    ]

    for seq, c in enumerate(chirps):
        payload = gen_awr2243_payload(
            chirp_num=seq, ns=c["ns"], pattern=c["pattern"],
        )
        dut._log.info(f"Backpressure chirp {seq}: ns={c['ns']} size={len(payload)}B")
        slot_task = cocotb.start_soon(
            collect_slot(dut, timeout_cycles=SLOT_TOTAL_BEATS * 8)
        )
        await drive_packet(dut, payload, pkt_seq=seq)
        cap = await slot_task
        verify_slot(cap, payload, pkt_seq=seq)
        recovered = _extract_slot_payload(cap.data, len(payload))
        assert recovered == payload, f"Chirp {seq}: data mismatch under backpressure"

    stop_flag[0] = True
    await ClockCycles(dut.clk_i, 4)
    dut._log.info("PASS: all chirps verified under random backpressure")


@cocotb.test()
async def test_awr_ramp_iq_spot_check(dut):
    """Ramp pattern ns=8: spot-check specific IQ values at sample boundaries."""
    await apply_reset(dut)

    ns = 8
    payload = gen_awr2243_payload(chirp_num=0, ns=ns, pattern="ramp")
    cap = await run_and_verify(dut, payload, pkt_seq=6)

    for k in [0, 3, 7]:
        iq_ofs = HEADER_BYTES + RX_HEADER_BYTES_TOTAL + k * SAMPLE_BYTES
        iq_raw = cap.data[iq_ofs : iq_ofs + SAMPLE_BYTES]
        bitstream = int.from_bytes(iq_raw, "little")

        for ch in range(NUM_RX_CHANNELS):
            base = ch * 0x100 + k
            exp_i = sign_to_u12(base)
            exp_q = sign_to_u12(-base)
            act_i = (bitstream >> ((ch * 2) * 12)) & 0xFFF
            act_q = (bitstream >> ((ch * 2 + 1) * 12)) & 0xFFF
            assert act_i == exp_i, (
                f"Sample {k} ch{ch}_i: exp=0x{exp_i:03x} act=0x{act_i:03x}"
            )
            assert act_q == exp_q, (
                f"Sample {k} ch{ch}_q: exp=0x{exp_q:03x} act=0x{act_q:03x}"
            )

    dut._log.info(f"PASS: ramp ns={ns}, IQ spot-check at samples 0/3/7 all correct")
