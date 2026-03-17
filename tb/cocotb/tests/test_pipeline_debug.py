from __future__ import annotations

import cocotb
from cocotb.triggers import RisingEdge

from platform_env import PlatformConfig, SimulationPlatformEnv


def gen_payload(length: int, seed: int = 0) -> bytes:
    return bytes(((seed + idx * 17 + length) & 0xFF) for idx in range(length))


def _first_diff(lhs: bytes, rhs: bytes) -> tuple[int | None, bytes, bytes]:
    limit = min(len(lhs), len(rhs))
    for idx in range(limit):
        if lhs[idx] != rhs[idx]:
            beat_start = (idx // 32) * 32
            beat_end = beat_start + 32
            return idx, lhs[beat_start:beat_end], rhs[beat_start:beat_end]
    if len(lhs) != len(rhs):
        idx = limit
        beat_start = (idx // 32) * 32
        beat_end = beat_start + 32
        return idx, lhs[beat_start:beat_end], rhs[beat_start:beat_end]
    return None, b"", b""


@cocotb.test()
async def test_debug_slot_signal_path(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure()

    payload = gen_payload(96, seed=0x11)

    counts = {
        "src_fire": 0,
        "csi_rx_fire": 0,
        "cdc_fire": 0,
        "pkt_start": 0,
        "pkt_done": 0,
        "slot_start": 0,
        "slot_done": 0,
        "wr_commit": 0,
    }
    first_seen: dict[str, tuple[int, int, int]] = {}

    send_task = cocotb.start_soon(env.send_packet(payload, seq=0))

    for cycle in range(2500):
        await RisingEdge(dut.axis_clk)

        if int(dut.s_axis_tvalid.value) and int(dut.s_axis_tready.value):
            counts["src_fire"] += 1
        if int(dut.csi_rx_axis_tvalid.value) and int(dut.csi_rx_axis_tready.value):
            counts["csi_rx_fire"] += 1
        if int(dut.cdc_axis_tvalid.value) and int(dut.cdc_axis_tready.value):
            counts["cdc_fire"] += 1

        if int(dut.pkt_start_o.value):
            counts["pkt_start"] += 1
            first_seen.setdefault(
                "pkt_start",
                (cycle, int(dut.pkt_seq_o.value), int(dut.pkt_bytes_o.value)),
            )

        if int(dut.pkt_done_o.value):
            counts["pkt_done"] += 1
            first_seen.setdefault(
                "pkt_done",
                (cycle, int(dut.pkt_seq_o.value), int(dut.pkt_bytes_o.value)),
            )

        if int(dut.slot_start_o.value):
            counts["slot_start"] += 1
            first_seen.setdefault(
                "slot_start",
                (cycle, int(dut.slot_seq_o.value), int(dut.slot_bytes_o.value)),
            )

        if int(dut.slot_done_o.value):
            counts["slot_done"] += 1
            first_seen.setdefault(
                "slot_done",
                (cycle, int(dut.slot_seq_o.value), int(dut.slot_bytes_o.value)),
            )

        if int(dut.wr_slot_commit_o.value):
            counts["wr_commit"] += 1
            first_seen.setdefault(
                "wr_commit",
                (cycle, int(dut.wr_slot_seq_o.value), int(dut.wr_slot_bytes_o.value)),
            )

    await send_task

    dut._log.info("debug counts=%s", counts)
    dut._log.info(
        "debug first_seen=%s dbg_wr_state=%d used_bytes=%d committed_bytes=%d",
        first_seen,
        int(dut.dbg_wr_state_o.value),
        int(dut.used_bytes_o.value),
        int(dut.committed_bytes_o.value),
    )


@cocotb.test()
async def test_debug_back_to_back_second_slot(dut):
    env = SimulationPlatformEnv(dut)
    await env.start()
    await env.reset()
    await env.configure(PlatformConfig(ring_size_bytes=0x10000))

    payloads = [
        gen_payload(64, seed=0x20),
        gen_payload(257, seed=0x40),
    ]

    seen_slots: dict[int, bytes] = {}
    slot_cycles: dict[int, dict[str, int]] = {}
    stop_flag = [False]

    async def monitor_slot_axis() -> None:
        active_seq = None
        raw = bytearray()

        while not stop_flag[0]:
            await RisingEdge(dut.axis_clk)

            fire = int(dut.pipeline_u.slot_axis_if.tvalid.value) and int(dut.pipeline_u.slot_axis_if.tready.value)
            if not fire:
                continue

            if active_seq is None:
                active_seq = int(dut.slot_seq_o.value)
                raw = bytearray()
                slot_cycles.setdefault(active_seq, {})["start"] = env.memory.cycle

            raw.extend(int(dut.pipeline_u.slot_axis_if.tdata.value).to_bytes(32, byteorder="little", signed=False))

            if int(dut.pipeline_u.slot_axis_if.tlast.value):
                slot_cycles.setdefault(active_seq, {})["done"] = env.memory.cycle
                seen_slots[active_seq] = bytes(raw)
                active_seq = None

    monitor_task = cocotb.start_soon(monitor_slot_axis())

    commits = []
    for seq, payload in enumerate(payloads):
        await env.send_packet(payload, seq=seq)
        commit = await env.wait_for_commit()
        commits.append(commit)
        slot_cycles.setdefault(seq, {})["commit"] = env.memory.cycle

    stop_flag[0] = True
    await RisingEdge(dut.axis_clk)
    await monitor_task

    exp = env.scoreboard.last_committed_expectation()
    assert exp.seq == 1
    host_slot = env.scoreboard.host_slot_for(exp)
    expected = host_slot.data
    streamed = seen_slots[1]
    stored = env.memory.read_ring_bytes(
        ring_base=env.config.ring_base_addr,
        ring_size=env.config.ring_size_bytes,
        start_addr=commits[1].addr,
        byte_count=commits[1].slot_bytes,
    )

    dut._log.info(
        "seq1 slot cycles=%s commit_addr=0x%x wr_state=%d cap_beats=%d wr_buf_idx=%d rd_addr=%d desc_count=%d",
        slot_cycles.get(1, {}),
        commits[1].addr,
        int(dut.pipeline_u.ringbuffer_u.wr_state_r.value),
        int(dut.pipeline_u.ringbuffer_u.cap_beat_count_r.value),
        int(dut.pipeline_u.ringbuffer_u.wr_buf_beat_idx_r.value),
        int(dut.pipeline_u.ringbuffer_u.slot_buf_rd_addr_r.value),
        int(dut.pipeline_u.ringbuffer_u.desc_count_r.value),
    )

    for label, lhs, rhs in (
        ("stream_vs_expected", streamed, expected),
        ("stored_vs_stream", stored, streamed),
        ("stored_vs_expected", stored, expected),
    ):
        diff_idx, lhs_beat, rhs_beat = _first_diff(lhs, rhs)
        dut._log.info(
            "%s diff_idx=%s lhs_beat=%s rhs_beat=%s",
            label,
            diff_idx,
            lhs_beat.hex(),
            rhs_beat.hex(),
        )

    assert streamed == expected
    assert stored == expected
