from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, FallingEdge, RisingEdge


AXIS_DATA_W = 256
AXIS_BEAT_BYTES = AXIS_DATA_W // 8
AXI_DATA_W = 256
AXI_BEAT_BYTES = AXI_DATA_W // 8
RD_TUSER_FIRST_BIT = 0
RD_TUSER_LAST_BIT = 1
RD_TUSER_VALID_BIT = 2
RD_TUSER_OVF_BIT = 3
RD_TUSER_SEQ_LSB = 8
RD_TUSER_BYTES_LSB = 32
RING_BASE_ADDR = 0x1000


def signal_width(sig) -> int:
    return len(sig)


def int_to_bytes(value: int, byte_count: int) -> bytes:
    return int(value).to_bytes(byte_count, byteorder="little", signed=False)


def bytes_to_int(data: bytes) -> int:
    return int.from_bytes(data, byteorder="little", signed=False)


def keep_mask(valid_bytes: int, beat_bytes: int) -> int:
    if valid_bytes <= 0:
        return 0
    if valid_bytes >= beat_bytes:
        return (1 << beat_bytes) - 1
    return (1 << valid_bytes) - 1


def align_up(value: int, align_bytes: int) -> int:
    return ((value + align_bytes - 1) // align_bytes) * align_bytes


@dataclass
class SlotResult:
    seq: int
    slot_bytes: int
    valid_good: int
    overflow_err: int
    addr: int = 0
    payload: bytes = b""


class AxiMemoryModel:
    def __init__(self, dut):
        self.dut = dut
        self.mem: Dict[int, int] = {}
        self._wr_active = False
        self._rd_active = False
        self._wr_addr = 0
        self._rd_addr = 0
        self._wr_beats_rem = 0
        self._rd_beats_rem = 0
        self._wr_step_bytes = AXI_BEAT_BYTES
        self._rd_step_bytes = AXI_BEAT_BYTES
        self._bvalid = 0
        self._bresp = 0
        self._rvalid = 0
        self._rdata = 0
        self._rresp = 0
        self._rlast = 0

    def reset_bus(self) -> None:
        self._wr_active = False
        self._rd_active = False
        self._wr_beats_rem = 0
        self._rd_beats_rem = 0
        self._wr_addr = 0
        self._rd_addr = 0
        self._bvalid = 0
        self._bresp = 0
        self._rvalid = 0
        self._rdata = 0
        self._rresp = 0
        self._rlast = 0

    def drive_outputs(self) -> None:
        awready = int((not self._wr_active) and (not self._bvalid))
        wready = int(self._wr_active)
        arready = int((not self._rd_active) and (not self._rvalid))

        self.dut.m_axi_awready.value = awready
        self.dut.m_axi_wready.value = wready
        self.dut.m_axi_bresp.value = self._bresp
        self.dut.m_axi_bvalid.value = self._bvalid
        self.dut.m_axi_arready.value = arready
        self.dut.m_axi_rdata.value = self._rdata
        self.dut.m_axi_rresp.value = self._rresp
        self.dut.m_axi_rlast.value = self._rlast
        self.dut.m_axi_rvalid.value = self._rvalid

    def write_mem_word(self, addr: int, data: int, strb: int) -> None:
        raw = int_to_bytes(data, AXI_BEAT_BYTES)
        for lane in range(AXI_BEAT_BYTES):
            if (strb >> lane) & 0x1:
                self.mem[addr + lane] = raw[lane]

    def read_mem_word(self, addr: int) -> int:
        raw = bytes(self.mem.get(addr + lane, 0) for lane in range(AXI_BEAT_BYTES))
        return bytes_to_int(raw)

    def read_ring_bytes(self, ring_base: int, ring_size: int, start_addr: int, byte_count: int) -> bytes:
        data: List[int] = []
        addr = start_addr
        ring_end = ring_base + ring_size
        for _ in range(byte_count):
            if addr >= ring_end:
                addr = ring_base
            data.append(self.mem.get(addr, 0))
            addr += 1
        return bytes(data)

    async def run(self) -> None:
        self.reset_bus()
        while True:
            await FallingEdge(self.dut.clk_i)
            if int(self.dut.rst_ni.value) == 0:
                self.reset_bus()
            self.drive_outputs()

            await RisingEdge(self.dut.clk_i)
            if int(self.dut.rst_ni.value) == 0:
                self.reset_bus()
                continue

            awready = int((not self._wr_active) and (not self._bvalid))
            wready = int(self._wr_active)
            arready = int((not self._rd_active) and (not self._rvalid))

            if self._bvalid and int(self.dut.m_axi_bready.value):
                self._bvalid = 0

            if int(self.dut.m_axi_awvalid.value) and awready:
                self._wr_active = True
                self._wr_addr = int(self.dut.m_axi_awaddr.value)
                self._wr_beats_rem = int(self.dut.m_axi_awlen.value) + 1
                self._wr_step_bytes = 1 << int(self.dut.m_axi_awsize.value)

            if int(self.dut.m_axi_wvalid.value) and wready:
                self.write_mem_word(
                    self._wr_addr,
                    int(self.dut.m_axi_wdata.value),
                    int(self.dut.m_axi_wstrb.value),
                )
                self._wr_addr += self._wr_step_bytes
                if self._wr_beats_rem > 0:
                    self._wr_beats_rem -= 1
                if int(self.dut.m_axi_wlast.value) or self._wr_beats_rem == 0:
                    self._wr_active = False
                    self._bresp = 0
                    self._bvalid = 1

            if self._rvalid and int(self.dut.m_axi_rready.value):
                self._rvalid = 0
                self._rlast = 0

            if int(self.dut.m_axi_arvalid.value) and arready:
                self._rd_active = True
                self._rd_addr = int(self.dut.m_axi_araddr.value)
                self._rd_beats_rem = int(self.dut.m_axi_arlen.value) + 1
                self._rd_step_bytes = 1 << int(self.dut.m_axi_arsize.value)

            if (not self._rvalid) and self._rd_active:
                self._rdata = self.read_mem_word(self._rd_addr)
                self._rresp = 0
                self._rlast = int(self._rd_beats_rem == 1)
                self._rvalid = 1
                self._rd_addr += self._rd_step_bytes
                if self._rd_beats_rem > 0:
                    self._rd_beats_rem -= 1
                if self._rd_beats_rem == 0:
                    self._rd_active = False


async def apply_reset(dut) -> None:
    cocotb.start_soon(Clock(dut.clk_i, 10, unit="ns").start())

    dut.rst_ni.value = 0
    dut.cfg_enable_i.value = 0
    dut.cfg_allow_overwrite_i.value = 0
    dut.cfg_drop_invalid_slot_i.value = 1
    dut.cfg_drop_on_no_space_i.value = 0
    dut.cfg_ring_base_addr_i.value = 0
    dut.cfg_ring_size_bytes_i.value = 0
    dut.slot_start_i.value = 0
    dut.slot_done_i.value = 0
    dut.slot_bytes_i.value = 0
    dut.slot_seq_i.value = 0
    dut.slot_valid_good_i.value = 0
    dut.slot_overflow_err_i.value = 0
    dut.rd_slot_req_i.value = 0
    dut.rd_consume_i.value = 0
    dut.s_axis_slot_tdata.value = 0
    dut.s_axis_slot_tkeep.value = 0
    dut.s_axis_slot_tvalid.value = 0
    dut.s_axis_slot_tlast.value = 0
    dut.s_axis_slot_tuser.value = 0
    dut.m_axis_rd_tready.value = 1
    dut.m_axi_awready.value = 0
    dut.m_axi_wready.value = 0
    dut.m_axi_bresp.value = 0
    dut.m_axi_bvalid.value = 0
    dut.m_axi_arready.value = 0
    dut.m_axi_rdata.value = 0
    dut.m_axi_rresp.value = 0
    dut.m_axi_rlast.value = 0
    dut.m_axi_rvalid.value = 0

    await ClockCycles(dut.clk_i, 8)
    dut.rst_ni.value = 1
    await ClockCycles(dut.clk_i, 2)


async def configure_ring(
    dut,
    ring_base_addr: int = RING_BASE_ADDR,
    ring_size_bytes: int = 256,
    allow_overwrite: int = 0,
    drop_invalid_slot: int = 1,
    drop_on_no_space: int = 0,
) -> None:
    dut.cfg_enable_i.value = 0
    dut.cfg_ring_base_addr_i.value = ring_base_addr
    dut.cfg_ring_size_bytes_i.value = ring_size_bytes
    dut.cfg_allow_overwrite_i.value = allow_overwrite
    dut.cfg_drop_invalid_slot_i.value = drop_invalid_slot
    dut.cfg_drop_on_no_space_i.value = drop_on_no_space
    await ClockCycles(dut.clk_i, 2)
    dut.cfg_enable_i.value = 1
    await ClockCycles(dut.clk_i, 2)


async def drive_slot(
    dut,
    payload: bytes,
    slot_seq: int,
    slot_valid_good: int = 1,
    slot_overflow_err: int = 0,
) -> None:
    beat_count = (len(payload) + AXIS_BEAT_BYTES - 1) // AXIS_BEAT_BYTES
    for beat_idx in range(beat_count):
        beat = payload[beat_idx * AXIS_BEAT_BYTES : (beat_idx + 1) * AXIS_BEAT_BYTES]
        dut.s_axis_slot_tdata.value = bytes_to_int(beat.ljust(AXIS_BEAT_BYTES, b"\x00"))
        dut.s_axis_slot_tkeep.value = keep_mask(len(beat), AXIS_BEAT_BYTES)
        dut.s_axis_slot_tvalid.value = 1
        dut.s_axis_slot_tlast.value = int(beat_idx == beat_count - 1)
        dut.s_axis_slot_tuser.value = 0
        dut.slot_start_i.value = int(beat_idx == 0)
        dut.slot_done_i.value = int(beat_idx == beat_count - 1)
        dut.slot_bytes_i.value = len(payload)
        dut.slot_seq_i.value = slot_seq
        dut.slot_valid_good_i.value = slot_valid_good
        dut.slot_overflow_err_i.value = slot_overflow_err

        while True:
            await RisingEdge(dut.clk_i)
            if int(dut.s_axis_slot_tvalid.value) and int(dut.s_axis_slot_tready.value):
                break

    dut.s_axis_slot_tdata.value = 0
    dut.s_axis_slot_tkeep.value = 0
    dut.s_axis_slot_tvalid.value = 0
    dut.s_axis_slot_tlast.value = 0
    dut.slot_start_i.value = 0
    dut.slot_done_i.value = 0
    dut.slot_bytes_i.value = 0
    dut.slot_seq_i.value = 0
    dut.slot_valid_good_i.value = 0
    dut.slot_overflow_err_i.value = 0
    await RisingEdge(dut.clk_i)


async def wait_commit(dut, timeout_cycles: int = 500) -> SlotResult:
    saw_awvalid = False
    saw_awready = False
    saw_aw_handshake = False
    saw_wvalid = False
    saw_wready = False
    saw_w_handshake = False
    saw_bvalid = False
    saw_bready = False
    saw_b_handshake = False
    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)
        saw_awvalid |= bool(int(dut.m_axi_awvalid.value))
        saw_awready |= bool(int(dut.m_axi_awready.value))
        saw_aw_handshake |= bool(int(dut.m_axi_awvalid.value) and int(dut.m_axi_awready.value))
        saw_wvalid |= bool(int(dut.m_axi_wvalid.value))
        saw_wready |= bool(int(dut.m_axi_wready.value))
        saw_w_handshake |= bool(int(dut.m_axi_wvalid.value) and int(dut.m_axi_wready.value))
        saw_bvalid |= bool(int(dut.m_axi_bvalid.value))
        saw_bready |= bool(int(dut.m_axi_bready.value))
        saw_b_handshake |= bool(int(dut.m_axi_bvalid.value) and int(dut.m_axi_bready.value))
        if int(dut.wr_slot_commit_o.value):
            return SlotResult(
                seq=int(dut.wr_slot_seq_o.value),
                slot_bytes=int(dut.wr_slot_bytes_o.value),
                valid_good=int(dut.wr_slot_valid_good_o.value),
                overflow_err=int(dut.wr_slot_overflow_err_o.value),
                addr=int(dut.wr_slot_addr_o.value),
            )
    raise TimeoutError(
        "Timed out waiting for wr_slot_commit_o "
        f"(awvalid={int(saw_awvalid)} awready={int(saw_awready)} aw_hs={int(saw_aw_handshake)} "
        f"wvalid={int(saw_wvalid)} wready={int(saw_wready)} w_hs={int(saw_w_handshake)} "
        f"bvalid={int(saw_bvalid)} "
        f"bready={int(saw_bready)} b_hs={int(saw_b_handshake)} "
        f"err_no_space={int(dut.err_no_space_o.value)} err_slot_proto={int(dut.err_slot_proto_o.value)} "
        f"err_slot_too_large={int(dut.err_slot_too_large_o.value)} "
        f"dbg_wr_state={int(dut.dbg_wr_state_o.value)} dbg_wr_burst_beats={int(dut.dbg_wr_burst_beats_o.value)} "
        f"dbg_wr_burst_sent={int(dut.dbg_wr_burst_sent_o.value)} "
        f"used_bytes={int(dut.used_bytes_o.value)} wr_ptr=0x{int(dut.wr_ptr_o.value):x} "
        f"commit_ptr=0x{int(dut.commit_ptr_o.value):x})"
    )


async def request_read(dut) -> None:
    while int(dut.rd_slot_valid_o.value) == 0:
        await RisingEdge(dut.clk_i)

    dut.rd_slot_req_i.value = 1
    await RisingEdge(dut.clk_i)
    dut.rd_slot_req_i.value = 0


async def collect_read_slot(dut, timeout_cycles: int = 500) -> SlotResult:
    payload = bytearray()
    meta = None
    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.m_axis_rd_tvalid.value) and int(dut.m_axis_rd_tready.value):
            if meta is None:
                tuser = int(dut.m_axis_rd_tuser.value)
                meta = SlotResult(
                    seq=(tuser >> RD_TUSER_SEQ_LSB) & ((1 << signal_width(dut.rd_slot_seq_o)) - 1),
                    slot_bytes=(tuser >> RD_TUSER_BYTES_LSB) & ((1 << signal_width(dut.rd_slot_bytes_o)) - 1),
                    valid_good=(tuser >> RD_TUSER_VALID_BIT) & 0x1,
                    overflow_err=(tuser >> RD_TUSER_OVF_BIT) & 0x1,
                )
                assert ((tuser >> RD_TUSER_FIRST_BIT) & 0x1) == 1, "first beat missing slot_first marker"

            beat_data = int_to_bytes(int(dut.m_axis_rd_tdata.value), AXI_BEAT_BYTES)
            beat_keep = int(dut.m_axis_rd_tkeep.value)
            for lane in range(AXI_BEAT_BYTES):
                if (beat_keep >> lane) & 0x1:
                    payload.append(beat_data[lane])

            if int(dut.m_axis_rd_tlast.value):
                assert meta is not None
                meta.payload = bytes(payload)
                return meta

    raise TimeoutError("Timed out collecting m_axis_rd slot")


async def consume_slot(dut) -> None:
    dut.rd_consume_i.value = 1
    await RisingEdge(dut.clk_i)
    dut.rd_consume_i.value = 0
    await RisingEdge(dut.clk_i)


def gen_payload(length: int, seed: int) -> bytes:
    return bytes(((seed + idx) & 0xFF) for idx in range(length))


async def run_slot_roundtrip(
    dut,
    mem_model: AxiMemoryModel,
    payload: bytes,
    slot_seq: int,
    slot_valid_good: int = 1,
    slot_overflow_err: int = 0,
) -> SlotResult:
    await drive_slot(
        dut,
        payload=payload,
        slot_seq=slot_seq,
        slot_valid_good=slot_valid_good,
        slot_overflow_err=slot_overflow_err,
    )
    commit = await wait_commit(dut)
    assert commit.seq == slot_seq
    assert commit.slot_bytes == len(payload)
    assert commit.valid_good == slot_valid_good
    assert commit.overflow_err == slot_overflow_err

    stored = mem_model.read_ring_bytes(
        ring_base=int(dut.cfg_ring_base_addr_i.value),
        ring_size=int(dut.cfg_ring_size_bytes_i.value),
        start_addr=commit.addr,
        byte_count=len(payload),
    )
    assert stored == payload, "DDR memory image mismatch after commit"

    await request_read(dut)
    readback = await collect_read_slot(dut)
    assert readback.seq == slot_seq
    assert readback.slot_bytes == len(payload)
    assert readback.valid_good == slot_valid_good
    assert readback.overflow_err == slot_overflow_err
    assert readback.payload == payload
    await consume_slot(dut)
    return commit


@cocotb.test()
async def smoke_basic(dut):
    mem_model = AxiMemoryModel(dut)
    cocotb.start_soon(mem_model.run())
    await apply_reset(dut)
    await configure_ring(dut, ring_size_bytes=256)

    payload0 = gen_payload(48, 0x21)
    payload1 = gen_payload(80, 0x61)

    commit0 = await run_slot_roundtrip(dut, mem_model, payload0, slot_seq=0x10)
    commit1 = await run_slot_roundtrip(dut, mem_model, payload1, slot_seq=0x11)

    assert commit0.addr == RING_BASE_ADDR
    assert commit1.addr == RING_BASE_ADDR + align_up(len(payload0), 32)
    assert int(dut.err_axi_wr_resp_o.value) == 0
    assert int(dut.err_axi_rd_resp_o.value) == 0
    assert int(dut.err_illegal_read_o.value) == 0


@cocotb.test()
async def wraparound_basic(dut):
    mem_model = AxiMemoryModel(dut)
    cocotb.start_soon(mem_model.run())
    await apply_reset(dut)
    await configure_ring(dut, ring_size_bytes=160)

    payload0 = gen_payload(96, 0x10)
    payload1 = gen_payload(80, 0x90)

    commit0 = await run_slot_roundtrip(dut, mem_model, payload0, slot_seq=0x20)
    assert commit0.addr == RING_BASE_ADDR

    commit1 = await run_slot_roundtrip(dut, mem_model, payload1, slot_seq=0x21)
    assert commit1.addr == RING_BASE_ADDR + align_up(len(payload0), 32)
    assert int(dut.wrap_count_o.value) != 0, "wrap_count_o did not increment"
    assert int(dut.err_no_space_o.value) == 0
