// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__s_axis_if__0(Vtop_axis_stream_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__s_axis_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tdata[0U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tdata[0U];
    vlSelfRef.tdata[1U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tdata[1U];
    vlSelfRef.tdata[2U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tdata[2U];
    vlSelfRef.tdata[3U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tdata[3U];
    vlSelfRef.tdata[4U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tdata[4U];
    vlSelfRef.tdata[5U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tdata[5U];
    vlSelfRef.tdata[6U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tdata[6U];
    vlSelfRef.tdata[7U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tdata[7U];
    vlSelfRef.tkeep = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tkeep;
    vlSelfRef.tlast = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tlast;
    vlSelfRef.tuser = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tuser;
    vlSelfRef.tvalid = vlSymsp->TOP.pipeline_cocotb_top__DOT__s_axis_tvalid;
}

void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__pkt_axis_if__0(Vtop_axis_stream_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__pkt_axis_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdfgRegularize_hebeb780c_0_0 = ((IData)(vlSelfRef.tready) 
                                                & (IData)(vlSelfRef.tvalid));
}

void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__slot_axis_if__0(Vtop_axis_stream_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__slot_axis_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tready = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__s_axis_ready_c;
}

void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__m_axis_rd_if__0(Vtop_axis_stream_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__m_axis_rd_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tdata[0U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[0U];
    vlSelfRef.tdata[1U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[1U];
    vlSelfRef.tdata[2U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[2U];
    vlSelfRef.tdata[3U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[3U];
    vlSelfRef.tdata[4U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[4U];
    vlSelfRef.tdata[5U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[5U];
    vlSelfRef.tdata[6U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[6U];
    vlSelfRef.tdata[7U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[7U];
    vlSelfRef.tkeep = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_r;
    vlSelfRef.tvalid = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r;
    vlSelfRef.tlast = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_r;
    vlSelfRef.tuser = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_r;
    vlSelfRef.tready = vlSymsp->TOP.pipeline_cocotb_top__DOT__m_axis_rd_tready;
}

void Vtop_axis_stream_if___nba_sequent__TOP__pipeline_cocotb_top__DOT__m_axis_rd_if__0(Vtop_axis_stream_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axis_stream_if___nba_sequent__TOP__pipeline_cocotb_top__DOT__m_axis_rd_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tdata[0U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[0U];
    vlSelfRef.tdata[1U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[1U];
    vlSelfRef.tdata[2U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[2U];
    vlSelfRef.tdata[3U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[3U];
    vlSelfRef.tdata[4U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[4U];
    vlSelfRef.tdata[5U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[5U];
    vlSelfRef.tdata[6U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[6U];
    vlSelfRef.tdata[7U] = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[7U];
    vlSelfRef.tkeep = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_r;
    vlSelfRef.tuser = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_r;
    vlSelfRef.tlast = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_r;
    vlSelfRef.tvalid = vlSymsp->TOP.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r;
}

std::string VL_TO_STRING(const Vtop_axis_stream_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axis_stream_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->vlNamep : "null");
}
