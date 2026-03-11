// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_axi4_mm_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if__0(Vtop_axi4_mm_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_mm_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.awready = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awready;
    vlSelfRef.wready = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wready;
    vlSelfRef.bresp = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_bresp;
    vlSelfRef.bvalid = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_bvalid;
    vlSelfRef.arready = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arready;
    vlSelfRef.rdata[0U] = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[0U];
    vlSelfRef.rdata[1U] = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[1U];
    vlSelfRef.rdata[2U] = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[2U];
    vlSelfRef.rdata[3U] = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[3U];
    vlSelfRef.rdata[4U] = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[4U];
    vlSelfRef.rdata[5U] = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[5U];
    vlSelfRef.rdata[6U] = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[6U];
    vlSelfRef.rdata[7U] = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[7U];
    vlSelfRef.rresp = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rresp;
    vlSelfRef.rlast = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rlast;
    vlSelfRef.rvalid = vlSymsp->TOP.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rvalid;
}

std::string VL_TO_STRING(const Vtop_axi4_mm_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_mm_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->vlNamep : "null");
}
