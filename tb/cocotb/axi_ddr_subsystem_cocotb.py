from __future__ import annotations

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, Combine, RisingEdge

from model.axi_ddr_memory import AxiMasterBurstDriver, InstrumentedAxiMemoryModel


AXI_RESP_OKAY = 0
MASTER_RADAR = 1
MASTER_HOST = 2

RING_BASE_ADDR = 0x1000
DMA_DESC_BASE_ADDR = 0x20000
RING_SECOND_ADDR = RING_BASE_ADDR + 0x100


def sample_words(seed: int, count: int) -> list[int]:
    return [((seed << 20) ^ (idx * 0x1F1F_0101) ^ (idx << 8) ^ 0x55AA) for idx in range(count)]


async def reset_dut(dut) -> None:
    dut.rst_ni.value = 0
    dut.radar_axi_awaddr.value = 0
    dut.radar_axi_awlen.value = 0
    dut.radar_axi_awsize.value = 0
    dut.radar_axi_awburst.value = 0
    dut.radar_axi_awvalid.value = 0
    dut.radar_axi_wdata.value = 0
    dut.radar_axi_wstrb.value = 0
    dut.radar_axi_wlast.value = 0
    dut.radar_axi_wvalid.value = 0
    dut.radar_axi_bready.value = 0
    dut.radar_axi_araddr.value = 0
    dut.radar_axi_arlen.value = 0
    dut.radar_axi_arsize.value = 0
    dut.radar_axi_arburst.value = 0
    dut.radar_axi_arvalid.value = 0
    dut.radar_axi_rready.value = 0
    dut.host_axi_awaddr.value = 0
    dut.host_axi_awlen.value = 0
    dut.host_axi_awsize.value = 0
    dut.host_axi_awburst.value = 0
    dut.host_axi_awvalid.value = 0
    dut.host_axi_wdata.value = 0
    dut.host_axi_wstrb.value = 0
    dut.host_axi_wlast.value = 0
    dut.host_axi_wvalid.value = 0
    dut.host_axi_bready.value = 0
    dut.host_axi_araddr.value = 0
    dut.host_axi_arlen.value = 0
    dut.host_axi_arsize.value = 0
    dut.host_axi_arburst.value = 0
    dut.host_axi_arvalid.value = 0
    dut.host_axi_rready.value = 0
    await ClockCycles(dut.clk_i, 4)
    dut.rst_ni.value = 1
    await ClockCycles(dut.clk_i, 2)


async def sample_grants(dut, history: list[tuple[int, int, int, int]], cycles: int) -> None:
    for _ in range(cycles):
        await RisingEdge(dut.clk_i)
        history.append(
            (
                int(dut.wr_owner_valid_o.value),
                int(dut.wr_owner_o.value),
                int(dut.rd_owner_valid_o.value),
                int(dut.rd_owner_o.value),
            )
        )


@cocotb.test()
async def test_axi_ddr_subsystem_burst_smoke(dut):
    cocotb.start_soon(Clock(dut.clk_i, 4, unit="ns").start())
    await reset_dut(dut)

    ddr_model = InstrumentedAxiMemoryModel(dut, prefix="ddr_axi", clock_name="clk_i", reset_name="rst_ni")
    cocotb.start_soon(ddr_model.run())

    while int(dut.ddr_init_done_o.value) == 0:
        await RisingEdge(dut.clk_i)

    radar = AxiMasterBurstDriver(dut, prefix="radar_axi", clock_name="clk_i")
    host = AxiMasterBurstDriver(dut, prefix="host_axi", clock_name="clk_i")

    grant_history: list[tuple[int, int, int, int]] = []
    sampler = cocotb.start_soon(sample_grants(dut, grant_history, 160))

    radar_words0 = sample_words(seed=0x11, count=4)
    host_words0 = sample_words(seed=0x22, count=2)

    radar_write0 = cocotb.start_soon(radar.write_burst(RING_BASE_ADDR, radar_words0))
    host_write0 = cocotb.start_soon(host.write_burst(DMA_DESC_BASE_ADDR, host_words0))
    await Combine(radar_write0, host_write0)
    radar_resp0 = radar_write0.result()
    host_resp0 = host_write0.result()
    assert radar_resp0 == AXI_RESP_OKAY
    assert host_resp0 == AXI_RESP_OKAY

    assert ddr_model.read_mem_word(RING_BASE_ADDR) == radar_words0[0]
    assert ddr_model.read_mem_word(RING_BASE_ADDR + ddr_model.beat_bytes) == radar_words0[1]
    assert ddr_model.read_mem_word(DMA_DESC_BASE_ADDR) == host_words0[0]

    first_write_addrs = {burst.addr for burst in ddr_model.write_bursts[:2]}
    assert first_write_addrs == {RING_BASE_ADDR, DMA_DESC_BASE_ADDR}

    readback0 = await host.read_burst(RING_BASE_ADDR, len(radar_words0))
    assert readback0 == radar_words0

    radar_words1 = sample_words(seed=0x33, count=4)
    radar_write1 = cocotb.start_soon(radar.write_burst(RING_SECOND_ADDR, radar_words1))
    host_read1 = cocotb.start_soon(host.read_burst(RING_BASE_ADDR, len(radar_words0)))
    await Combine(host_read1, radar_write1)
    readback1 = host_read1.result()
    radar_resp1 = radar_write1.result()
    assert radar_resp1 == AXI_RESP_OKAY
    assert readback1 == radar_words0

    await sampler

    assert ddr_model.read_mem_word(RING_SECOND_ADDR) == radar_words1[0]
    assert len(ddr_model.write_bursts) >= 3
    assert len(ddr_model.read_bursts) >= 2

    assert any(valid and owner == MASTER_RADAR for valid, owner, _, _ in grant_history)
    assert any(valid and owner == MASTER_HOST for valid, owner, _, _ in grant_history)
    assert any(
        wr_valid and wr_owner == MASTER_RADAR and rd_valid and rd_owner == MASTER_HOST
        for wr_valid, wr_owner, rd_valid, rd_owner in grant_history
    ), "expected concurrent radar write and host read arbitration visibility"
