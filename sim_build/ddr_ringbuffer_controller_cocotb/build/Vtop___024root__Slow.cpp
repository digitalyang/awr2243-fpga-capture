// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr CData/*0:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__SLOT_FIXED_EN;
constexpr CData/*0:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__SLOT_FIXED_EN;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__AXI_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__AXI_ADDR_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__RD_AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__SLOT_STRIDE_BYTES;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__SLOT_BUFFER_BYTES;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__DESC_FIFO_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__MAX_BURST_LEN;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__ADDR_ALIGN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__RING_SIZE_BYTES_MAX;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__ALMOST_FULL_MARGIN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__SLOT_SEQ_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__COUNTER_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__CFG_RING_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__SLOT_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__CFG_AXI_ADDR_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__AXI_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__RD_AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__SLOT_STRIDE_BYTES;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__SLOT_BUFFER_BYTES;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__DESC_FIFO_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__MAX_BURST_LEN;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ADDR_ALIGN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__RING_SIZE_BYTES_MAX;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ALMOST_FULL_MARGIN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__SLOT_SEQ_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__COUNTER_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__RD_TUSER_SLOT_FIRST_BIT;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__RD_TUSER_SLOT_LAST_BIT;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__RD_TUSER_VALID_GOOD_BIT;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__RD_TUSER_OVERFLOW_ERR_BIT;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__RD_TUSER_SEQ_LSB;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__RD_TUSER_BYTES_LSB;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__CFG_RING_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__SLOT_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__AXIS_KEEP_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__AXIS_BEAT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__AXI_ADDR_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__AXI_STRB_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__AXI_BEAT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__RD_AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__RD_AXIS_KEEP_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__RING_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__SLOT_BUF_BEATS;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__SLOT_BUF_IDX_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__SLOT_BUF_AW;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__DESC_FIFO_AW;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__KEEP_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__MAX_BURST_BYTES;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__BURST_LEN_W;
constexpr IData/*31:0*/ Vtop___024root::ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__AXI_SIZE_C;


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
