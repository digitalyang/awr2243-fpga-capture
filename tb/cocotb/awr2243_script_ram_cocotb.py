from __future__ import annotations

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, ReadOnly, RisingEdge, Timer


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
    dut.rd_en_i.value = 0
    dut.rd_addr_i.value = 0
    dut.script_id_i.value = 0

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


async def request_read(dut, addr: int) -> int:
    dut.rd_en_i.value = 1
    dut.rd_addr_i.value = addr
    await RisingEdge(dut.clk_i)
    dut.rd_en_i.value = 0
    await ReadOnly()

    assert int(dut.rd_valid_o.value) == 1
    return int(dut.rd_data_o.value)


@cocotb.test()
async def test_metadata_and_sync_read(dut) -> None:
    await apply_reset(dut)

    await write_meta(dut, script_id=3, base_addr=5, length=4)
    await write_word(dut, addr=5, data=0x1122334455667788)
    await write_word(dut, addr=6, data=0x8877665544332211)

    dut.script_id_i.value = 3
    await Timer(1, unit="ns")
    assert int(dut.script_base_addr_o.value) == 5
    assert int(dut.script_len_o.value) == 4

    read_data = await request_read(dut, addr=6)
    assert read_data == 0x8877665544332211


@cocotb.test()
async def test_same_cycle_write_read_bypass(dut) -> None:
    await apply_reset(dut)

    dut.wr_en_i.value = 1
    dut.wr_addr_i.value = 9
    dut.wr_data_i.value = 0xDEADBEEF01234567
    dut.rd_en_i.value = 1
    dut.rd_addr_i.value = 9
    await RisingEdge(dut.clk_i)

    dut.wr_en_i.value = 0
    dut.rd_en_i.value = 0
    await ReadOnly()

    assert int(dut.rd_valid_o.value) == 1
    assert int(dut.rd_data_o.value) == 0xDEADBEEF01234567
