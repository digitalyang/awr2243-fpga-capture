from __future__ import annotations

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, RisingEdge

from awr2243_script_helpers import OP_END, OP_NOP, encode_cmd


async def apply_reset(dut) -> None:
    cocotb.start_soon(Clock(dut.clk_i, 10, unit="ns").start())

    dut.rst_ni.value = 0
    dut.wr_en_i.value = 0
    dut.wr_addr_i.value = 0
    dut.wr_data_i.value = 0
    dut.meta_wr_en_i.value = 0
    dut.meta_wr_script_id_i.value = 0
    dut.meta_wr_base_addr_i.value = 0
    dut.meta_wr_len_i.value = 0
    dut.start_i.value = 0
    dut.script_id_i.value = 0
    dut.advance_i.value = 0
    dut.hold_i.value = 0
    dut.jump_en_i.value = 0
    dut.jump_addr_i.value = 0

    await ClockCycles(dut.clk_i, 4)
    dut.rst_ni.value = 1
    await ClockCycles(dut.clk_i, 2)


async def write_word(dut, addr: int, data: int) -> None:
    dut.wr_en_i.value = 1
    dut.wr_addr_i.value = addr
    dut.wr_data_i.value = data
    await RisingEdge(dut.clk_i)
    dut.wr_en_i.value = 0


async def write_meta(dut, script_id: int, base_addr: int, length: int) -> None:
    dut.meta_wr_en_i.value = 1
    dut.meta_wr_script_id_i.value = script_id
    dut.meta_wr_base_addr_i.value = base_addr
    dut.meta_wr_len_i.value = length
    await RisingEdge(dut.clk_i)
    dut.meta_wr_en_i.value = 0


async def pulse(dut, sig) -> None:
    sig.value = 1
    await RisingEdge(dut.clk_i)
    sig.value = 0


async def wait_for_cmd(dut, timeout_cycles: int = 30) -> tuple[int, int]:
    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.cmd_valid_o.value):
            return int(dut.cmd_word_o.value), int(dut.pc_o.value)
    raise TimeoutError("timed out waiting for cmd_valid_o")


async def wait_for_done(dut, timeout_cycles: int = 20) -> None:
    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.script_done_o.value):
            return
    raise TimeoutError("timed out waiting for script_done_o")


@cocotb.test()
async def test_linear_fetch_and_done(dut) -> None:
    await apply_reset(dut)

    script = [
        encode_cmd(OP_NOP, step_id=1),
        encode_cmd(OP_NOP, step_id=2),
        encode_cmd(OP_END, step_id=3),
    ]

    await write_meta(dut, script_id=1, base_addr=4, length=len(script))
    for offset, word in enumerate(script):
        await write_word(dut, addr=4 + offset, data=word)

    dut.script_id_i.value = 1
    await pulse(dut, dut.start_i)

    word, pc = await wait_for_cmd(dut)
    assert pc == 0
    assert word == script[0]

    dut.hold_i.value = 1
    await ClockCycles(dut.clk_i, 3)
    assert int(dut.cmd_valid_o.value) == 1
    assert int(dut.cmd_word_o.value) == script[0]
    assert int(dut.pc_o.value) == 0
    dut.hold_i.value = 0

    await pulse(dut, dut.advance_i)
    word, pc = await wait_for_cmd(dut)
    assert pc == 1
    assert word == script[1]

    await pulse(dut, dut.advance_i)
    word, pc = await wait_for_cmd(dut)
    assert pc == 2
    assert word == script[2]

    await pulse(dut, dut.advance_i)
    await wait_for_done(dut)
    assert int(dut.busy_o.value) == 0


@cocotb.test()
async def test_relative_jump(dut) -> None:
    await apply_reset(dut)

    script = [
        encode_cmd(OP_NOP, step_id=10),
        encode_cmd(OP_NOP, step_id=11),
        encode_cmd(OP_END, step_id=12),
    ]

    await write_meta(dut, script_id=2, base_addr=12, length=len(script))
    for offset, word in enumerate(script):
        await write_word(dut, addr=12 + offset, data=word)

    dut.script_id_i.value = 2
    await pulse(dut, dut.start_i)

    word, pc = await wait_for_cmd(dut)
    assert pc == 0
    assert word == script[0]

    await pulse(dut, dut.advance_i)
    word, pc = await wait_for_cmd(dut)
    assert pc == 1
    assert word == script[1]

    dut.jump_addr_i.value = 0
    await pulse(dut, dut.jump_en_i)
    word, pc = await wait_for_cmd(dut)
    assert pc == 0
    assert word == script[0]
