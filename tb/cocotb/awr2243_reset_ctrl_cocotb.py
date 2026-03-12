from __future__ import annotations

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, FallingEdge, RisingEdge, with_timeout


CLK_PERIOD_NS = 10

RST_IDLE = 0
RST_DRIVE_SOP = 1
RST_ASSERT_NRESET = 2
RST_HOLD = 3
RST_RELEASE = 4
RST_WAIT_BOOT = 5
RST_DONE = 6


def sop_value(dut) -> int:
    return (
        (int(dut.sop2_o.value) << 2)
        | (int(dut.sop1_o.value) << 1)
        | int(dut.sop0_o.value)
    )


def state_value(dut) -> int:
    return dut.state_o.value.to_unsigned()


async def reset_dut(dut) -> None:
    cocotb.start_soon(Clock(dut.sys_clk, CLK_PERIOD_NS, unit="ns").start())

    dut.req_enter_spi_mode_i.value = 0
    dut.req_hard_reset_i.value = 0
    dut.req_recovery_reset_i.value = 0
    dut.fault_active_i.value = 0
    dut.auto_recovery_en_i.value = 0
    dut.sop_mode_sel_i.value = 0b001
    dut.reset_hold_us_i.value = 5
    dut.post_reset_wait_us_i.value = 7
    dut.sys_rst_n.value = 0

    await ClockCycles(dut.sys_clk, 5)
    dut.sys_rst_n.value = 1
    await ClockCycles(dut.sys_clk, 2)


async def request_enter_spi_mode(dut) -> None:
    dut.req_enter_spi_mode_i.value = 1
    await ClockCycles(dut.sys_clk, 1)
    dut.req_enter_spi_mode_i.value = 0


async def request_hard_reset(dut) -> None:
    dut.req_hard_reset_i.value = 1
    await ClockCycles(dut.sys_clk, 1)
    dut.req_hard_reset_i.value = 0


async def request_recovery_reset(dut) -> None:
    dut.req_recovery_reset_i.value = 1
    await ClockCycles(dut.sys_clk, 1)
    dut.req_recovery_reset_i.value = 0


async def wait_for_done(dut) -> None:
    await with_timeout(RisingEdge(dut.done_o), 1000, "ns")
    await ClockCycles(dut.sys_clk, 1)


async def bring_up_spi_mode(dut) -> None:
    await request_enter_spi_mode(dut)
    await wait_for_done(dut)
    assert dut.nreset_o.value == 1
    assert sop_value(dut) == 0b001


@cocotb.test()
async def test_power_on_defaults(dut):
    await reset_dut(dut)

    assert dut.busy_o.value == 0
    assert dut.done_o.value == 0
    assert dut.err_o.value == 0
    assert dut.nreset_o.value == 0
    assert sop_value(dut) == 0b001
    assert state_value(dut) == RST_IDLE


@cocotb.test()
async def test_enter_spi_mode_sequence(dut):
    await reset_dut(dut)

    dut.reset_hold_us_i.value = 4
    dut.post_reset_wait_us_i.value = 6
    await request_enter_spi_mode(dut)

    await ClockCycles(dut.sys_clk, 1)
    assert state_value(dut) == RST_DRIVE_SOP
    assert dut.busy_o.value == 1

    await ClockCycles(dut.sys_clk, 1)
    assert sop_value(dut) == 0b001
    assert dut.nreset_o.value == 0

    await wait_for_done(dut)
    assert dut.nreset_o.value == 1
    assert dut.busy_o.value == 0
    assert state_value(dut) == RST_IDLE


@cocotb.test()
async def test_hard_reset_uses_selected_sop(dut):
    await reset_dut(dut)
    await bring_up_spi_mode(dut)

    dut.sop_mode_sel_i.value = 0b111
    dut.reset_hold_us_i.value = 5
    dut.post_reset_wait_us_i.value = 3
    await request_hard_reset(dut)

    await ClockCycles(dut.sys_clk, 2)
    assert sop_value(dut) == 0b111
    assert dut.nreset_o.value == 1

    await with_timeout(FallingEdge(dut.nreset_o), 200, "ns")
    low_cycles = 0
    while int(dut.nreset_o.value) == 0:
        await ClockCycles(dut.sys_clk, 1)
        low_cycles += 1

    assert low_cycles >= 5
    await wait_for_done(dut)
    assert sop_value(dut) == 0b111
    assert dut.nreset_o.value == 1


@cocotb.test()
async def test_manual_recovery_preserves_current_sop(dut):
    await reset_dut(dut)
    await bring_up_spi_mode(dut)

    dut.sop_mode_sel_i.value = 0b101
    await request_hard_reset(dut)
    await wait_for_done(dut)
    assert sop_value(dut) == 0b101

    dut.sop_mode_sel_i.value = 0b001
    await request_recovery_reset(dut)
    await wait_for_done(dut)
    assert sop_value(dut) == 0b101
    assert dut.nreset_o.value == 1


@cocotb.test()
async def test_auto_recovery_runs_once_per_fault_edge(dut):
    await reset_dut(dut)
    await bring_up_spi_mode(dut)

    dut.auto_recovery_en_i.value = 1
    dut.fault_active_i.value = 1

    await with_timeout(RisingEdge(dut.busy_o), 200, "ns")
    await wait_for_done(dut)
    assert dut.nreset_o.value == 1

    await ClockCycles(dut.sys_clk, 10)
    assert dut.busy_o.value == 0
    assert dut.done_o.value == 0

    dut.fault_active_i.value = 0
    await ClockCycles(dut.sys_clk, 2)
    dut.fault_active_i.value = 1
    await with_timeout(RisingEdge(dut.busy_o), 200, "ns")
    await wait_for_done(dut)


@cocotb.test()
async def test_conflicting_requests_raise_err(dut):
    await reset_dut(dut)

    dut.req_enter_spi_mode_i.value = 1
    dut.req_hard_reset_i.value = 1
    await ClockCycles(dut.sys_clk, 1)
    dut.req_enter_spi_mode_i.value = 0
    dut.req_hard_reset_i.value = 0

    await with_timeout(RisingEdge(dut.err_o), 100, "ns")
    assert dut.busy_o.value == 0
    assert state_value(dut) == RST_IDLE

    await with_timeout(FallingEdge(dut.err_o), 100, "ns")
    assert dut.err_o.value == 0
