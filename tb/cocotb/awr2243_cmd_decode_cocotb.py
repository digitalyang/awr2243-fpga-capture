from __future__ import annotations

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge

from awr2243_script_helpers import (
    ERR_FAULT_ACTIVE,
    ERR_SPI_MISMATCH,
    OP_CHECK_FAULT,
    OP_DELAY_US,
    OP_END,
    OP_FAIL,
    OP_SPI_RD,
    OP_SPI_WR,
    OP_WAIT_IRQ,
    SPI_RD_FLAG_COMPARE_BIT,
    encode_cmd,
)


async def apply_reset(dut) -> None:
    cocotb.start_soon(Clock(dut.clk_i, 10, unit="ns").start())

    dut.rst_ni.value = 0
    dut.cmd_valid_i.value = 0
    dut.cmd_word_i.value = 0
    dut.pc_i.value = 0
    dut.spi_cmd_ready_i.value = 1
    dut.spi_rsp_valid_i.value = 0
    dut.spi_rsp_word_i.value = 0
    dut.spi_busy_i.value = 0
    dut.spi_done_i.value = 0
    dut.spi_timeout_i.value = 0
    dut.timer_busy_i.value = 0
    dut.timer_done_i.value = 0
    dut.timer_expired_i.value = 0
    dut.host_irq_rise_i.value = 0
    dut.host_irq_sticky_i.value = 0
    dut.fault_active_i.value = 0
    dut.fault_sticky_i.value = 0

    await ClockCycles(dut.clk_i, 4)
    dut.rst_ni.value = 1
    await ClockCycles(dut.clk_i, 2)


async def present_command(dut, word: int, *, pc: int = 0) -> None:
    dut.cmd_word_i.value = word
    dut.pc_i.value = pc
    dut.cmd_valid_i.value = 1


async def clear_command(dut) -> None:
    dut.cmd_valid_i.value = 0
    dut.cmd_word_i.value = 0
    await RisingEdge(dut.clk_i)


async def pulse(dut, sig, *, hold_cycles: int = 1) -> None:
    sig.value = 1
    await ClockCycles(dut.clk_i, hold_cycles)
    sig.value = 0


async def wait_until_high(dut, sig, timeout_cycles: int = 30) -> None:
    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)
        if int(sig.value):
            return
    raise TimeoutError("timed out waiting for signal")


async def wait_for_done(dut, timeout_cycles: int = 30) -> None:
    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.cmd_done_o.value):
            return
    raise TimeoutError("timed out waiting for cmd_done_o")


async def wait_for_error(dut, timeout_cycles: int = 30) -> None:
    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.cmd_error_o.value):
            return
    raise TimeoutError("timed out waiting for cmd_error_o")


@cocotb.test()
async def test_spi_write_and_end(dut) -> None:
    await apply_reset(dut)

    await present_command(dut, encode_cmd(OP_SPI_WR, step_id=0x11, imm_b=0x1234), pc=3)
    await wait_until_high(dut, dut.spi_cmd_valid_o)
    assert int(dut.spi_cmd_is_read_o.value) == 0
    assert int(dut.spi_cmd_word_o.value) == 0x1234

    await pulse(dut, dut.spi_done_i)
    await wait_for_done(dut)
    assert int(dut.fetch_advance_o.value) == 1
    assert int(dut.step_id_o.value) == 0x11
    assert int(dut.last_opcode_o.value) == OP_SPI_WR
    await clear_command(dut)

    await present_command(dut, encode_cmd(OP_END, step_id=0x12), pc=4)
    await wait_for_done(dut)
    assert int(dut.fetch_advance_o.value) == 1
    assert int(dut.last_opcode_o.value) == OP_END
    await clear_command(dut)


@cocotb.test()
async def test_delay_and_wait_irq(dut) -> None:
    await apply_reset(dut)

    await present_command(dut, encode_cmd(OP_DELAY_US, step_id=0x21, imm_a=0, imm_b=25), pc=0)
    await wait_until_high(dut, dut.timer_start_o)
    assert int(dut.timer_period_value_o.value) == 25
    assert int(dut.timer_period_unit_o.value) == 1

    await pulse(dut, dut.timer_done_i)
    await wait_for_done(dut)
    assert int(dut.fetch_advance_o.value) == 1
    await clear_command(dut)

    await present_command(dut, encode_cmd(OP_WAIT_IRQ, step_id=0x22, imm_a=0, imm_b=100), pc=1)
    await wait_until_high(dut, dut.clr_irq_sticky_o)
    assert int(dut.timer_start_o.value) == 1
    assert int(dut.timer_period_value_o.value) == 100

    await pulse(dut, dut.host_irq_rise_i)
    await wait_for_done(dut)
    assert int(dut.fetch_advance_o.value) == 1
    await clear_command(dut)


@cocotb.test()
async def test_error_paths(dut) -> None:
    await apply_reset(dut)

    flags = 1 << SPI_RD_FLAG_COMPARE_BIT
    await present_command(
        dut,
        encode_cmd(OP_SPI_RD, step_id=0x30, flags=flags, imm_a=0xAAAA, imm_b=0x55AA),
        pc=2,
    )
    await wait_until_high(dut, dut.spi_cmd_valid_o)
    assert int(dut.spi_cmd_is_read_o.value) == 1
    assert int(dut.spi_cmd_word_o.value) == 0x55AA

    dut.spi_rsp_word_i.value = 0xBBBB
    dut.spi_rsp_valid_i.value = 1
    dut.spi_done_i.value = 1
    await RisingEdge(dut.clk_i)
    dut.spi_rsp_valid_i.value = 0
    dut.spi_done_i.value = 0

    await wait_for_error(dut)
    assert int(dut.error_code_o.value) == ERR_SPI_MISMATCH
    assert int(dut.fetch_advance_o.value) == 0
    await clear_command(dut)

    dut.fault_active_i.value = 1
    await present_command(dut, encode_cmd(OP_CHECK_FAULT, step_id=0x31), pc=3)
    await wait_for_error(dut)
    assert int(dut.error_code_o.value) == ERR_FAULT_ACTIVE
    await clear_command(dut)
    dut.fault_active_i.value = 0

    await present_command(dut, encode_cmd(OP_FAIL, step_id=0x32, imm_b=0x33), pc=4)
    await wait_for_error(dut)
    assert int(dut.fetch_advance_o.value) == 1
    assert int(dut.error_code_o.value) == 0x33
    await clear_command(dut)
