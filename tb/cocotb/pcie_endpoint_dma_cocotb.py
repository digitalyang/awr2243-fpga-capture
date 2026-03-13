from __future__ import annotations

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, with_timeout

from drivers.pcie_host_rc import PcieHostRcMaster


REG_CONTROL = 0x0000
REG_STATUS = 0x0004
REG_DESC_ADDR_LO = 0x0010
REG_DESC_ADDR_HI = 0x0014
REG_DESC_LEN = 0x0018
REG_DESC_PATTERN = 0x001C
REG_DESC_META = 0x0020
REG_DOORBELL = 0x0024
REG_COMPLETION = 0x0028
REG_COMPLETION_LEN = 0x002C

CTRL_ENABLE = 1 << 0
CTRL_IRQ_ENABLE = 1 << 1
STATUS_BUSY_BIT = 8
STATUS_IRQ_PENDING_BIT = 9
STATUS_ERROR_BIT = 10
BAR0_FORWARD_BASE = 0x1000


def apply_strb(current: int, new_value: int, strb: int, *, width_bytes: int = 4) -> int:
    merged = current
    for lane in range(width_bytes):
        if (strb >> lane) & 0x1:
            mask = 0xFF << (lane * 8)
            merged = (merged & ~mask) | (new_value & mask)
    return merged


async def reset_dut(dut) -> None:
    dut.rst_ni.value = 0
    dut.host_rc_req_valid.value = 0
    dut.host_rc_rsp_ready.value = 0
    await RisingEdge(dut.clk_i)
    await RisingEdge(dut.clk_i)
    dut.rst_ni.value = 1
    await RisingEdge(dut.clk_i)
    await RisingEdge(dut.clk_i)


async def axil_bar0_slave(dut, backing_store: dict[int, int]) -> None:
    awaddr = None
    wdata = None
    wstrb = 0
    pending_b = False
    pending_r = None

    while True:
        dut.m_axil_awready.value = int(not pending_b and awaddr is None)
        dut.m_axil_wready.value = int(not pending_b and wdata is None)
        dut.m_axil_bvalid.value = int(pending_b)
        dut.m_axil_bresp.value = 0
        dut.m_axil_arready.value = int(pending_r is None)
        dut.m_axil_rvalid.value = int(pending_r is not None)
        dut.m_axil_rresp.value = 0
        dut.m_axil_rdata.value = 0 if pending_r is None else pending_r

        await RisingEdge(dut.clk_i)

        if awaddr is None and int(dut.m_axil_awvalid.value) and int(dut.m_axil_awready.value):
            awaddr = int(dut.m_axil_awaddr.value)

        if wdata is None and int(dut.m_axil_wvalid.value) and int(dut.m_axil_wready.value):
            wdata = int(dut.m_axil_wdata.value)
            wstrb = int(dut.m_axil_wstrb.value)

        if (awaddr is not None) and (wdata is not None) and not pending_b:
            current = backing_store.get(awaddr, 0)
            backing_store[awaddr] = apply_strb(current, wdata, wstrb)
            awaddr = None
            wdata = None
            pending_b = True

        if pending_b and int(dut.m_axil_bvalid.value) and int(dut.m_axil_bready.value):
            pending_b = False

        if pending_r is None and int(dut.m_axil_arvalid.value) and int(dut.m_axil_arready.value):
            pending_r = backing_store.get(int(dut.m_axil_araddr.value), 0)
        elif pending_r is not None and int(dut.m_axil_rvalid.value) and int(dut.m_axil_rready.value):
            pending_r = None


async def axi_dma_sink(dut, observed: list[dict[str, int | bytes]]) -> None:
    awaddr = None
    awlen = 0
    awsize = 0
    payload = bytearray()
    pending_b = False

    while True:
        dut.m_axi_awready.value = int((awaddr is None) and not pending_b)
        dut.m_axi_wready.value = int((awaddr is not None) and not pending_b)
        dut.m_axi_bvalid.value = int(pending_b)
        dut.m_axi_bresp.value = 0
        dut.m_axi_arready.value = 0
        dut.m_axi_rdata.value = 0
        dut.m_axi_rresp.value = 0
        dut.m_axi_rlast.value = 0
        dut.m_axi_rvalid.value = 0

        await RisingEdge(dut.clk_i)

        if awaddr is None and int(dut.m_axi_awvalid.value) and int(dut.m_axi_awready.value):
            awaddr = int(dut.m_axi_awaddr.value)
            awlen = int(dut.m_axi_awlen.value)
            awsize = int(dut.m_axi_awsize.value)
            payload = bytearray()

        if awaddr is not None and int(dut.m_axi_wvalid.value) and int(dut.m_axi_wready.value):
            data = int(dut.m_axi_wdata.value)
            strb = int(dut.m_axi_wstrb.value)
            beat_bytes = len(dut.m_axi_wdata) // 8
            beat = data.to_bytes(beat_bytes, byteorder="little", signed=False)
            for lane in range(beat_bytes):
                if (strb >> lane) & 0x1:
                    payload.append(beat[lane])

            if int(dut.m_axi_wlast.value):
                observed.append(
                    {
                        "awaddr": awaddr,
                        "awlen": awlen,
                        "awsize": awsize,
                        "payload": bytes(payload),
                    }
                )
                awaddr = None
                pending_b = True

        if pending_b and int(dut.m_axi_bvalid.value) and int(dut.m_axi_bready.value):
            pending_b = False


@cocotb.test()
async def smoke_mmio_forward_and_dma_write(dut):
    cocotb.start_soon(Clock(dut.clk_i, 10, unit="ns").start())
    host = PcieHostRcMaster(dut)
    host.drive_idle()

    dut.m_axil_awready.value = 0
    dut.m_axil_wready.value = 0
    dut.m_axil_bresp.value = 0
    dut.m_axil_bvalid.value = 0
    dut.m_axil_arready.value = 0
    dut.m_axil_rdata.value = 0
    dut.m_axil_rresp.value = 0
    dut.m_axil_rvalid.value = 0

    dut.m_axi_awready.value = 0
    dut.m_axi_wready.value = 0
    dut.m_axi_bresp.value = 0
    dut.m_axi_bvalid.value = 0
    dut.m_axi_arready.value = 0
    dut.m_axi_rdata.value = 0
    dut.m_axi_rresp.value = 0
    dut.m_axi_rlast.value = 0
    dut.m_axi_rvalid.value = 0

    axil_store: dict[int, int] = {}
    dma_observed: list[dict[str, int | bytes]] = []
    cocotb.start_soon(axil_bar0_slave(dut, axil_store))
    cocotb.start_soon(axi_dma_sink(dut, dma_observed))

    await reset_dut(dut)

    completion = await host.write32(REG_CONTROL, CTRL_ENABLE | CTRL_IRQ_ENABLE)
    assert completion.status == 0

    completion = await host.write32(BAR0_FORWARD_BASE + 0x20, 0x11223344)
    assert completion.status == 0
    completion = await host.read32(BAR0_FORWARD_BASE + 0x20)
    assert completion.status == 0
    assert completion.data == 0x11223344
    assert axil_store[0x20] == 0x11223344

    assert (await host.write32(REG_DESC_ADDR_LO, 0x00004000)).status == 0
    assert (await host.write32(REG_DESC_ADDR_HI, 0x00000000)).status == 0
    assert (await host.write32(REG_DESC_LEN, 64)).status == 0
    assert (await host.write32(REG_DESC_PATTERN, 0x44332211)).status == 0
    assert (await host.write32(REG_DESC_META, (1 << 16) | 0x07)).status == 0
    assert (await host.write32(REG_DOORBELL, 1)).status == 0

    async def wait_for_dma() -> None:
        while not dma_observed:
            await RisingEdge(dut.clk_i)

    await with_timeout(wait_for_dma(), 2, "us")

    record = dma_observed[0]
    assert record["awaddr"] == 0x4000
    assert record["awlen"] == 1
    assert record["awsize"] == 5
    assert len(record["payload"]) == 64
    assert record["payload"][:4] == bytes([0x11, 0x23, 0x35, 0x47])

    await with_timeout(RisingEdge(dut.irq_o), 2, "us")
    assert int(dut.dma_busy_o.value) == 0
    assert int(dut.dma_done_desc_id_o.value) == 0x07

    completion = await host.read32(REG_COMPLETION)
    assert completion.status == 0
    assert completion.data & 0xFF == 0x07
    assert (completion.data >> 16) == 1

    completion = await host.read32(REG_COMPLETION_LEN)
    assert completion.status == 0
    assert completion.data == 64

    completion = await host.read32(REG_STATUS)
    assert completion.status == 0
    assert ((completion.data >> STATUS_BUSY_BIT) & 0x1) == 0
    assert ((completion.data >> STATUS_IRQ_PENDING_BIT) & 0x1) == 1
    assert ((completion.data >> STATUS_ERROR_BIT) & 0x1) == 0

    completion = await host.write32(REG_STATUS, 1 << STATUS_IRQ_PENDING_BIT)
    assert completion.status == 0

    completion = await host.read32(REG_STATUS)
    assert completion.status == 0
    assert ((completion.data >> STATUS_IRQ_PENDING_BIT) & 0x1) == 0
