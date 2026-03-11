// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__VC_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__DT_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__PAYLOAD_LEN_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__MAX_PACKET_BYTES;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__PKT_BYTE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__PKT_SEQ_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__VC_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__DT_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__PAYLOAD_LEN_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__MAX_PACKET_BYTES;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__PKT_BYTE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__PKT_SEQ_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__FIFO_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_PKT_START_BIT;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_CRC_ERR_BIT;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_ECC_ERR_BIT;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_TRUNC_ERR_BIT;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_VC_LSB;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_DT_LSB;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_PAYLOAD_LEN_LSB;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_KEEP_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_BEAT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__BEAT_BYTE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::csi_packet_extractor_cocotb_top__DOT__dut__DOT__FIFO_AW;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
