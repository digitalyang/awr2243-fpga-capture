// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr CData/*7:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_HDR_VERSION;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__PKT_SEQ_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__PKT_BYTE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__SAMPLE_SLOT_NUM;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__SAMPLE_UNIT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__CQ_AREA_BYTES;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__HEADER_BYTES;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__ALIGN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__SLOT_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__PKT_SEQ_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__PKT_BYTE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_SLOT_NUM;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_UNIT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__CQ_AREA_BYTES;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HEADER_BYTES;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__ALIGN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_HDR_MAGIC;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_KEEP_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_BEAT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__BEAT_BYTE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_UNIT_BITS;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_AREA_BYTES;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HEADER_BITS;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_TOTAL_UNALIGNED;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_TOTAL_ALIGNED;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__PAD_BYTES;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HEADER_BEATS;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_AREA_BEATS;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__CQ_AREA_BEATS;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__PAD_BEATS;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_TOTAL_BEATS;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__CAP_BUF_BEATS;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__BEAT_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_MAGIC_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_VERSION_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_FLAGS_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_SEQ_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_BYTES_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SAMPLE_CNT_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SLOT_BYTES_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SAMPLE_AREA_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_CQ_AREA_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_SEQ_FIELD_BITS;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_BYTES_FIELD_BITS;
constexpr IData/*31:0*/ Vtop___024root::fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SAMPLE_CNT_FIELD_BITS;


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
