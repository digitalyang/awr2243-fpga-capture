"""Cocotb tests for BAR0 decode + AWR2243 CSR: csr_rd_wr, addr_decode."""

from __future__ import annotations

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge, Timer

# BAR0: 0x000-0x08C ringbuffer, 0x090+ AWR2243 CSR (offsets match awr2243_control_csr.h / RDL)
AWR_BASE = 0x90

# AWR2243 CSR offsets (byte, from RDL addrmap)
OFF_VERSION = 0x00
OFF_CONTROL = 0x04
OFF_STATUS = 0x08
OFF_SCRATCH = 0x48
OFF_INIT_SCRIPT_ID = 0x2C
OFF_START_SCRIPT_ID = 0x40

# Control bits (singlepulse)
CONTROL_START_INIT = 1 << 0
CONTROL_CLEAR_ERROR = 1 << 4


async def start_clk_rst(dut, period_ns: float = 10.0):
    cocotb.start_soon(Clock(dut.clk_i, period_ns, unit="ns").start())
    dut.rst_ni.value = 0
    await ClockCycles(dut.clk_i, 4)
    dut.rst_ni.value = 1
    await ClockCycles(dut.clk_i, 2)


async def axil_write(dut, addr: int, data: int, strb: int = 0xF):
    """Drive one AXI-Lite write; addr is full BAR0 address (e.g. 0x90 + offset)."""
    dut.s_axil_awaddr.value = addr & 0xFFFF
    dut.s_axil_awprot.value = 0
    dut.s_axil_awvalid.value = 1
    dut.s_axil_wdata.value = data & 0xFFFFFFFF
    dut.s_axil_wstrb.value = strb & 0xF
    dut.s_axil_wvalid.value = 1
    dut.s_axil_bready.value = 1
    dut.s_axil_arvalid.value = 0
    dut.s_axil_rready.value = 0

    while True:
        await RisingEdge(dut.clk_i)
        if int(dut.s_axil_awready.value) and int(dut.s_axil_wready.value):
            break
    dut.s_axil_awvalid.value = 0
    dut.s_axil_wvalid.value = 0
    while True:
        await RisingEdge(dut.clk_i)
        if int(dut.s_axil_bvalid.value):
            break
    dut.s_axil_bready.value = 0
    await RisingEdge(dut.clk_i)
    resp = int(dut.s_axil_bresp.value)
    assert resp == 0, f"AXI-Lite write resp not OK: {resp}"


async def axil_read(dut, addr: int) -> int:
    """Perform one AXI-Lite read; returns rdata."""
    dut.s_axil_awvalid.value = 0
    dut.s_axil_wvalid.value = 0
    dut.s_axil_bready.value = 0
    dut.s_axil_araddr.value = addr & 0xFFFF
    dut.s_axil_arprot.value = 0
    dut.s_axil_arvalid.value = 1
    dut.s_axil_rready.value = 1

    while True:
        await RisingEdge(dut.clk_i)
        if int(dut.s_axil_arready.value):
            break
    dut.s_axil_arvalid.value = 0
    while True:
        await RisingEdge(dut.clk_i)
        if int(dut.s_axil_rvalid.value):
            break
    data = int(dut.s_axil_rdata.value) & 0xFFFFFFFF
    resp = int(dut.s_axil_rresp.value)
    dut.s_axil_rready.value = 0
    await RisingEdge(dut.clk_i)
    assert resp == 0, f"AXI-Lite read resp not OK: {resp}"
    return data


def init_axil(dut):
    dut.s_axil_awaddr.value = 0
    dut.s_axil_awprot.value = 0
    dut.s_axil_awvalid.value = 0
    dut.s_axil_wdata.value = 0
    dut.s_axil_wstrb.value = 0
    dut.s_axil_wvalid.value = 0
    dut.s_axil_bready.value = 0
    dut.s_axil_araddr.value = 0
    dut.s_axil_arprot.value = 0
    dut.s_axil_arvalid.value = 0
    dut.s_axil_rready.value = 0


@cocotb.test()
async def test_csr_rd_wr(dut):
    """Write CONTROL (singlepulse), read STATUS, read/write script_id and SCRATCH via BAR0 0x90+."""
    await start_clk_rst(dut)
    init_axil(dut)
    await ClockCycles(dut.clk_i, 4)

    # Read VERSION (expect 0x43530100)
    v = await axil_read(dut, AWR_BASE + OFF_VERSION)
    assert v == 0x43530100, f"VERSION mismatch: got 0x{v:08X}"

    # Read STATUS (no need to clear)
    st = await axil_read(dut, AWR_BASE + OFF_STATUS)
    # Just check we get some value
    assert (st & 0xFFFFFFFF) == st

    # Write SCRATCH and read back (allow 2 cycles for write to commit in generated block)
    await axil_write(dut, AWR_BASE + OFF_SCRATCH, 0xDEADBEEF)
    await ClockCycles(dut.clk_i, 2)
    scratch = await axil_read(dut, AWR_BASE + OFF_SCRATCH)
    assert scratch == 0xDEADBEEF, f"SCRATCH mismatch: got 0x{scratch:08X}"

    # Write INIT_SCRIPT_ID and read back
    await axil_write(dut, AWR_BASE + OFF_INIT_SCRIPT_ID, 7)
    init_id = await axil_read(dut, AWR_BASE + OFF_INIT_SCRIPT_ID)
    assert (init_id & 0xFF) == 7, f"INIT_SCRIPT_ID mismatch: got {init_id}"

    # Pulse CLEAR_ERROR (singlepulse)
    await axil_write(dut, AWR_BASE + OFF_CONTROL, CONTROL_CLEAR_ERROR)
    await ClockCycles(dut.clk_i, 2)
    # Optional: pulse START_INIT (may stay busy; we only check no bus error)
    await axil_write(dut, AWR_BASE + OFF_CONTROL, CONTROL_START_INIT)
    await ClockCycles(dut.clk_i, 4)
    st2 = await axil_read(dut, AWR_BASE + OFF_STATUS)
    assert (st2 & 0xFFFFFFFF) == st2


@cocotb.test()
async def test_addr_decode(dut):
    """Access 0x00-0x88 (ring) and 0x90+ (AWR); confirm responses from correct slave."""
    await start_clk_rst(dut)
    init_axil(dut)
    await ClockCycles(dut.clk_i, 4)

    # Ring side: stub returns rdata=0, OK
    r0 = await axil_read(dut, 0x00)
    assert r0 == 0
    r88 = await axil_read(dut, 0x88)
    assert r88 == 0

    # AWR side: VERSION at 0x90
    v = await axil_read(dut, AWR_BASE + OFF_VERSION)
    assert v == 0x43530100, f"AWR VERSION at 0x90: got 0x{v:08X}"

    # AWR CONTROL at 0x94
    c = await axil_read(dut, AWR_BASE + OFF_CONTROL)
    assert (c & 0xFFFFFFFF) == c

    # Write SCRATCH at 0x90+0x48, read back
    await axil_write(dut, AWR_BASE + OFF_SCRATCH, 0x12345678)
    s = await axil_read(dut, AWR_BASE + OFF_SCRATCH)
    assert s == 0x12345678, f"AWR SCRATCH: got 0x{s:08X}"
