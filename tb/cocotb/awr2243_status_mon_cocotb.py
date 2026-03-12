from __future__ import annotations

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, FallingEdge, RisingEdge, Timer, with_timeout


CLK_PERIOD_NS = 10


async def reset_dut(dut) -> None:
    cocotb.start_soon(Clock(dut.sys_clk, CLK_PERIOD_NS, unit="ns").start())

    dut.host_irq_i.value = 0
    dut.nerror_out_i.value = 1
    dut.warm_reset_i.value = 0
    dut.arm_i.value = 0
    dut.clr_irq_sticky_i.value = 0
    dut.clr_fault_sticky_i.value = 0
    dut.clr_warm_reset_sticky_i.value = 0
    dut.sys_rst_n.value = 0

    await ClockCycles(dut.sys_clk, 5)
    dut.sys_rst_n.value = 1
    await ClockCycles(dut.sys_clk, 2)


def unsigned_value(handle) -> int:
    return handle.value.to_unsigned()


async def async_pulse(signal, *, start_offset_ns: int = 3, high_time_ns: int = 17) -> None:
    await Timer(start_offset_ns, unit="ns")
    signal.value = 1
    await Timer(high_time_ns, unit="ns")
    signal.value = 0


async def async_fault_assert(
    signal, *, start_offset_ns: int = 3, low_time_ns: int | None = None
) -> None:
    await Timer(start_offset_ns, unit="ns")
    signal.value = 0
    if low_time_ns is not None:
        await Timer(low_time_ns, unit="ns")
        signal.value = 1


@cocotb.test()
async def test_reset_defaults(dut):
    await reset_dut(dut)

    assert dut.host_irq_rise_o.value == 0
    assert dut.host_irq_sticky_o.value == 0
    assert dut.fault_active_o.value == 0
    assert dut.fault_sticky_o.value == 0
    assert dut.warm_reset_rise_o.value == 0
    assert dut.warm_reset_sticky_o.value == 0
    assert unsigned_value(dut.irq_count_o) == 0
    assert unsigned_value(dut.fault_count_o) == 0
    assert unsigned_value(dut.warm_reset_count_o) == 0
    assert dut.host_irq_sync_o.value == 0
    assert dut.nerror_out_sync_o.value == 1
    assert dut.warm_reset_sync_o.value == 0


@cocotb.test()
async def test_irq_capture_and_clear(dut):
    await reset_dut(dut)

    dut.arm_i.value = 1
    cocotb.start_soon(async_pulse(dut.host_irq_i))

    await with_timeout(RisingEdge(dut.host_irq_rise_o), 200, "ns")
    assert dut.host_irq_sticky_o.value == 1
    assert unsigned_value(dut.irq_count_o) == 1
    assert dut.host_irq_sync_o.value == 1

    await ClockCycles(dut.sys_clk, 3)
    assert dut.host_irq_rise_o.value == 0
    assert dut.host_irq_sync_o.value == 0

    dut.clr_irq_sticky_i.value = 1
    await ClockCycles(dut.sys_clk, 1)
    dut.clr_irq_sticky_i.value = 0
    await ClockCycles(dut.sys_clk, 1)

    assert dut.host_irq_sticky_o.value == 0
    assert unsigned_value(dut.irq_count_o) == 1


@cocotb.test()
async def test_fault_capture_and_live_clear(dut):
    await reset_dut(dut)

    dut.arm_i.value = 1
    cocotb.start_soon(async_fault_assert(dut.nerror_out_i))

    await with_timeout(RisingEdge(dut.fault_active_o), 200, "ns")
    await ClockCycles(dut.sys_clk, 1)
    assert dut.fault_sticky_o.value == 1
    assert unsigned_value(dut.fault_count_o) == 1
    assert dut.nerror_out_sync_o.value == 0

    dut.clr_fault_sticky_i.value = 1
    await ClockCycles(dut.sys_clk, 1)
    dut.clr_fault_sticky_i.value = 0
    await ClockCycles(dut.sys_clk, 1)
    assert dut.fault_active_o.value == 1
    assert dut.fault_sticky_o.value == 0

    dut.nerror_out_i.value = 1
    await with_timeout(FallingEdge(dut.fault_active_o), 200, "ns")
    assert dut.fault_active_o.value == 0

    cocotb.start_soon(async_fault_assert(dut.nerror_out_i))
    await with_timeout(RisingEdge(dut.fault_active_o), 200, "ns")
    await ClockCycles(dut.sys_clk, 1)
    assert dut.fault_sticky_o.value == 1
    assert unsigned_value(dut.fault_count_o) == 2


@cocotb.test()
async def test_arm_masks_prearm_history(dut):
    await reset_dut(dut)

    cocotb.start_soon(async_pulse(dut.host_irq_i))
    await ClockCycles(dut.sys_clk, 6)
    assert dut.host_irq_sticky_o.value == 0
    assert unsigned_value(dut.irq_count_o) == 0

    cocotb.start_soon(async_fault_assert(dut.nerror_out_i))
    await with_timeout(RisingEdge(dut.fault_active_o), 200, "ns")
    assert dut.fault_sticky_o.value == 0
    assert unsigned_value(dut.fault_count_o) == 0

    dut.arm_i.value = 1
    await ClockCycles(dut.sys_clk, 2)
    assert dut.fault_sticky_o.value == 0
    assert unsigned_value(dut.fault_count_o) == 0

    dut.nerror_out_i.value = 1
    await ClockCycles(dut.sys_clk, 3)
    cocotb.start_soon(async_fault_assert(dut.nerror_out_i))
    await with_timeout(RisingEdge(dut.fault_active_o), 200, "ns")
    await ClockCycles(dut.sys_clk, 1)
    assert dut.fault_sticky_o.value == 1
    assert unsigned_value(dut.fault_count_o) == 1


@cocotb.test()
async def test_warm_reset_capture(dut):
    await reset_dut(dut)

    dut.arm_i.value = 1
    cocotb.start_soon(async_pulse(dut.warm_reset_i))

    await with_timeout(RisingEdge(dut.warm_reset_rise_o), 200, "ns")
    assert dut.warm_reset_sticky_o.value == 1
    assert unsigned_value(dut.warm_reset_count_o) == 1
    assert dut.warm_reset_sync_o.value == 1

    await ClockCycles(dut.sys_clk, 3)
    assert dut.warm_reset_rise_o.value == 0
    assert dut.warm_reset_sync_o.value == 0

    dut.clr_warm_reset_sticky_i.value = 1
    await ClockCycles(dut.sys_clk, 1)
    dut.clr_warm_reset_sticky_i.value = 0
    await ClockCycles(dut.sys_clk, 1)
    assert dut.warm_reset_sticky_o.value == 0
