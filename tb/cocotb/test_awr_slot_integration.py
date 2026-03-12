"""End-to-end integration: AWR2243 chirp payloads → fixed_slot_packer → slot verification.

Generates realistic radar ADC payloads (headers + 12-bit IQ samples + CQ)
and verifies the slot packer correctly wraps them into fixed-size slots.
"""
from __future__ import annotations

from typing import List

import cocotb
from cocotb.triggers import ClockCycles

from awr_payload_model import (
    ALIGN_BYTES,
    SLOT_TOTAL_UNALIGNED,
    NUM_RX_CHANNELS,
    RX_HEADER_BYTES_TOTAL,
    SAMPLE_BYTES,
    CQ_BYTES,
    build_expected_slot_bytes,
    calc_expected_payload_size,
    gen_awr_payload,
    sign_to_u12,
    unpack_cq_raw12,
    unpack_u12_list_le,
)
from fixed_slot_packer_cocotb import (
    HEADER_BYTES,
    SAMPLE_AREA_BYTES,
    SLOT_TOTAL_ALIGNED,
    SLOT_TOTAL_BEATS,
    apply_reset,
    drive_packet,
    collect_slot,
    verify_slot,
    run_and_verify,
    random_backpressure,
)

NS_MAX = SAMPLE_AREA_BYTES // SAMPLE_BYTES


# ================================================================
#  Tests
# ================================================================

@cocotb.test()
async def test_awr_ramp_ns64(dut):
    """64-sample ramp chirp → full slot pipeline verification."""
    await apply_reset(dut)

    ns = 64
    payload = gen_awr_payload(chirp_num=0, ns=ns, pattern="ramp")
    assert len(payload) == calc_expected_payload_size(ns)  # 789

    cap = await run_and_verify(dut, payload, pkt_seq=0)
    assert cap.data == build_expected_slot_bytes(payload), "Payload bytes not preserved through slot packer"
    dut._log.info(f"PASS: ramp ns={ns}, {len(payload)}B payload intact in slot")


@cocotb.test()
async def test_awr_const_ns1(dut):
    """1-sample const chirp (33 bytes) → minimal payload in slot."""
    await apply_reset(dut)

    ns = 1
    cq_val = 0xCAFE_BABE_DEAD_BEEF
    payload = gen_awr_payload(
        chirp_num=42, ns=ns, chirp_profile=5,
        cq_data=cq_val, pattern="const",
    )
    assert len(payload) == 33

    cap = await run_and_verify(dut, payload, pkt_seq=1)
    assert cap.data == build_expected_slot_bytes(payload)

    # Verify IQ values survive: unpack 12-bit from slot sample area
    iq_ofs = HEADER_BYTES + RX_HEADER_BYTES_TOTAL
    iq_raw = cap.data[iq_ofs : iq_ofs + SAMPLE_BYTES]
    expected_iq = [0x011, 0xFEE, 0x022, 0xFDD, 0x033, 0xFCC, 0x044, 0xFBB]
    for i, act_v in enumerate(unpack_u12_list_le(iq_raw, len(expected_iq))):
        exp_v = expected_iq[i]
        assert act_v == exp_v, f"IQ[{i}] after slot: exp=0x{exp_v:03x} act=0x{act_v:03x}"

    cq_ofs = HEADER_BYTES + SAMPLE_AREA_BYTES
    assert unpack_cq_raw12(cap.data[cq_ofs : cq_ofs + CQ_BYTES]) == cq_val

    dut._log.info("PASS: const ns=1, all 8 IQ values intact after slot packing")


@cocotb.test()
async def test_awr_ramp_ns256(dut):
    """256-sample ramp chirp (3088 bytes) → medium payload."""
    await apply_reset(dut)

    ns = 256
    payload = gen_awr_payload(chirp_num=100, ns=ns, pattern="ramp")
    assert len(payload) == calc_expected_payload_size(ns)

    cap = await run_and_verify(dut, payload, pkt_seq=2)
    assert cap.data == build_expected_slot_bytes(payload)
    dut._log.info(f"PASS: ramp ns={ns}, {len(payload)}B all verified")


@cocotb.test()
async def test_awr_exact_fit(dut):
    """ns=1024 → payload exactly fills the fixed raw payload envelope."""
    await apply_reset(dut)

    ns = NS_MAX
    payload = gen_awr_payload(chirp_num=999, ns=ns, pattern="ramp")
    assert len(payload) == SLOT_TOTAL_UNALIGNED, (
        f"Exact-fit: exp={SLOT_TOTAL_UNALIGNED} got={len(payload)}"
    )

    cap = await run_and_verify(dut, payload, pkt_seq=3)

    assert cap.sb_slot_overflow_err == 0
    assert cap.data == build_expected_slot_bytes(payload)
    dut._log.info(f"PASS: exact-fit ns={ns}, full 12309B payload captured without overflow")


@cocotb.test()
async def test_awr_overflow(dut):
    """Payload longer than 12309B → overflow + truncation."""
    await apply_reset(dut)

    payload = gen_awr_payload(chirp_num=500, ns=NS_MAX, pattern="ramp") + bytes(range(17))
    assert len(payload) > SLOT_TOTAL_UNALIGNED

    cap = await run_and_verify(dut, payload, pkt_seq=4)

    assert cap.sb_slot_overflow_err == 1, "Overflow flag should be set"
    assert cap.data == build_expected_slot_bytes(payload)
    dut._log.info("PASS: overflow payload truncated to the fixed slot envelope")


@cocotb.test()
async def test_awr_channel_tag_integrity(dut):
    """Channel-tag pattern → verify per-channel markers survive end-to-end."""
    await apply_reset(dut)

    ns = 4
    payload = gen_awr_payload(chirp_num=7, ns=ns, pattern="channel_tag")
    cap = await run_and_verify(dut, payload, pkt_seq=5)

    expected_iq_per_sample = [0x001, 0x101, 0x002, 0x102, 0x003, 0x103, 0x004, 0x104]

    for s in range(ns):
        iq_ofs = HEADER_BYTES + RX_HEADER_BYTES_TOTAL + s * SAMPLE_BYTES
        iq_raw = cap.data[iq_ofs : iq_ofs + SAMPLE_BYTES]
        for i, act_v in enumerate(unpack_u12_list_le(iq_raw, len(expected_iq_per_sample))):
            exp_v = expected_iq_per_sample[i]
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
        {"chirp_num": 3,   "ns": NS_MAX, "pattern": "ramp", "profile": 3},
        {"chirp_num": 4,   "ns": 16,  "pattern": "random",      "profile": 4},
    ]

    for seq, c in enumerate(chirps):
        payload = gen_awr_payload(
            chirp_num=c["chirp_num"], ns=c["ns"],
            chirp_profile=c["profile"], pattern=c["pattern"],
        )
        dut._log.info(
            f"Chirp {seq}: ns={c['ns']} pattern={c['pattern']} "
            f"payload={len(payload)}B"
        )
        cap = await run_and_verify(dut, payload, pkt_seq=seq)
        assert cap.data == build_expected_slot_bytes(payload), f"Chirp {seq}: payload mismatch after slot packing"

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
        {"ns": NS_MAX, "pattern": "random"},
    ]

    for seq, c in enumerate(chirps):
        payload = gen_awr_payload(
            chirp_num=seq, ns=c["ns"], pattern=c["pattern"],
        )
        dut._log.info(f"Backpressure chirp {seq}: ns={c['ns']} size={len(payload)}B")
        slot_task = cocotb.start_soon(
            collect_slot(dut, timeout_cycles=SLOT_TOTAL_BEATS * 8)
        )
        await drive_packet(dut, payload, pkt_seq=seq)
        cap = await slot_task
        verify_slot(cap, payload, pkt_seq=seq)
        assert cap.data == build_expected_slot_bytes(payload), f"Chirp {seq}: data mismatch under backpressure"

    stop_flag[0] = True
    await ClockCycles(dut.clk_i, 4)
    dut._log.info("PASS: all chirps verified under random backpressure")


@cocotb.test()
async def test_awr_ramp_iq_spot_check(dut):
    """Ramp pattern ns=8: spot-check specific IQ values at sample boundaries."""
    await apply_reset(dut)

    ns = 8
    payload = gen_awr_payload(chirp_num=0, ns=ns, pattern="ramp")
    cap = await run_and_verify(dut, payload, pkt_seq=6)

    for k in [0, 3, 7]:
        iq_ofs = HEADER_BYTES + RX_HEADER_BYTES_TOTAL + k * SAMPLE_BYTES
        iq_raw = cap.data[iq_ofs : iq_ofs + SAMPLE_BYTES]
        unpacked = unpack_u12_list_le(iq_raw, NUM_RX_CHANNELS * 2)

        for ch in range(NUM_RX_CHANNELS):
            base = ch * 0x100 + k
            exp_i = sign_to_u12(base)
            exp_q = sign_to_u12(-base)
            act_i = unpacked[ch * 2]
            act_q = unpacked[ch * 2 + 1]
            assert act_i == exp_i, (
                f"Sample {k} ch{ch}_i: exp=0x{exp_i:03x} act=0x{act_i:03x}"
            )
            assert act_q == exp_q, (
                f"Sample {k} ch{ch}_q: exp=0x{exp_q:03x} act=0x{act_q:03x}"
            )

    dut._log.info(f"PASS: ramp ns={ns}, IQ spot-check at samples 0/3/7 all correct")
