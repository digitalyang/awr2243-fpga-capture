from __future__ import annotations

from dataclasses import dataclass

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, Timer


@dataclass(frozen=True)
class ClockBundle:
    video_period_ns: float = 5.0
    axis_period_ns: float = 4.0
    axi_period_ns: float = 4.0
    video_start_delay_ns: float = 0.0
    axis_start_delay_ns: float = 0.0
    axi_start_delay_ns: float = 0.0


def initialize_platform_inputs(dut) -> None:
    dut.sys_rst_n.value = 0
    dut.cfg_vc_en_i.value = 0
    dut.cfg_dt_en_i.value = 0
    dut.cfg_vc_i.value = 0
    dut.cfg_dt_i.value = 0
    dut.cfg_drop_invalid_pkt_i.value = 0
    dut.cfg_enable_i.value = 0
    dut.cfg_allow_overwrite_i.value = 0
    dut.cfg_drop_invalid_slot_i.value = 0
    dut.cfg_drop_on_no_space_i.value = 0
    dut.cfg_ring_base_addr_i.value = 0
    dut.cfg_ring_size_bytes_i.value = 0
    dut.rd_slot_req_i.value = 0
    dut.rd_consume_i.value = 0
    dut.s_axis_tdata.value = 0
    dut.s_axis_tkeep.value = 0
    dut.s_axis_tvalid.value = 0
    dut.s_axis_tlast.value = 0
    dut.s_axis_tuser.value = 0
    dut.csi_rx_short_pkt_valid.value = 0
    dut.csi_rx_short_pkt_dt.value = 0
    dut.csi_rx_short_pkt_vc.value = 0
    dut.csi_rx_short_pkt_data.value = 0
    dut.csi_rx_startup_latency_cycles.value = 0
    dut.csi_rx_interpacket_gap_cycles.value = 0
    dut.csi_rx_beat_gap_cycles.value = 0
    dut.cdc_sink_pause.value = 0
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


async def _start_clock(signal, period_ns: float, start_delay_ns: float) -> None:
    if start_delay_ns > 0.0:
        await Timer(start_delay_ns, unit="ns")
    await Clock(signal, period_ns, unit="ns").start()


def start_platform_clocks(dut, clocks: ClockBundle | None = None) -> ClockBundle:
    clocks = clocks or ClockBundle()
    cocotb.start_soon(_start_clock(dut.video_aclk, clocks.video_period_ns, clocks.video_start_delay_ns))
    cocotb.start_soon(_start_clock(dut.axis_clk, clocks.axis_period_ns, clocks.axis_start_delay_ns))
    cocotb.start_soon(_start_clock(dut.axi_clk, clocks.axi_period_ns, clocks.axi_start_delay_ns))
    return clocks


async def reset_platform(dut, reset_cycles: int = 8, settle_cycles: int = 3) -> None:
    initialize_platform_inputs(dut)
    dut.sys_rst_n.value = 0
    await ClockCycles(dut.axis_clk, reset_cycles)
    dut.sys_rst_n.value = 1
    await ClockCycles(dut.axis_clk, settle_cycles)
    await ClockCycles(dut.video_aclk, settle_cycles)
    await ClockCycles(dut.axi_clk, settle_cycles)
