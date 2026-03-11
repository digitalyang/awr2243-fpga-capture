// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_ddr_ringbuffer_pkg
constexpr CData/*1:0*/ Vtop_ddr_ringbuffer_pkg::AXI_RESP_OKAY;
constexpr CData/*1:0*/ Vtop_ddr_ringbuffer_pkg::AXI_BURST_INCR;
constexpr IData/*31:0*/ Vtop_ddr_ringbuffer_pkg::DDR_RING_ADDR_W_DFLT;
constexpr IData/*31:0*/ Vtop_ddr_ringbuffer_pkg::DDR_RING_BYTES_W_DFLT;
constexpr IData/*31:0*/ Vtop_ddr_ringbuffer_pkg::DDR_RING_SLOT_BYTES_W_DFLT;
constexpr IData/*31:0*/ Vtop_ddr_ringbuffer_pkg::DDR_RING_SLOT_SEQ_W_DFLT;
constexpr IData/*31:0*/ Vtop_ddr_ringbuffer_pkg::DDR_RING_COUNTER_W_DFLT;


void Vtop_ddr_ringbuffer_pkg___ctor_var_reset(Vtop_ddr_ringbuffer_pkg* vlSelf);

Vtop_ddr_ringbuffer_pkg::Vtop_ddr_ringbuffer_pkg() = default;
Vtop_ddr_ringbuffer_pkg::~Vtop_ddr_ringbuffer_pkg() = default;

void Vtop_ddr_ringbuffer_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_ddr_ringbuffer_pkg___ctor_var_reset(this);
}

void Vtop_ddr_ringbuffer_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_ddr_ringbuffer_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
