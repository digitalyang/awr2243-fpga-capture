// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if__0(Vtop_axis_stream_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tdata[0U] = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[0U];
    vlSelfRef.tdata[1U] = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[1U];
    vlSelfRef.tdata[2U] = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[2U];
    vlSelfRef.tdata[3U] = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[3U];
    vlSelfRef.tdata[4U] = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[4U];
    vlSelfRef.tdata[5U] = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[5U];
    vlSelfRef.tdata[6U] = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[6U];
    vlSelfRef.tdata[7U] = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[7U];
    vlSelfRef.tkeep = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tkeep;
    vlSelfRef.tlast = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tlast;
    vlSelfRef.tuser = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tuser;
    vlSelfRef.tvalid = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tvalid;
}

void Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if__0(Vtop_axis_stream_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tready = vlSymsp->TOP.csi_packet_extractor_cocotb_top__DOT__m_axis_tready;
}

std::string VL_TO_STRING(const Vtop_axis_stream_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axis_stream_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->vlNamep : "null");
}
