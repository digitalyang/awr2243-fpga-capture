// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_axis_stream_if
constexpr IData/*31:0*/ Vtop_axis_stream_if::DATA_W;
constexpr IData/*31:0*/ Vtop_axis_stream_if::USER_W;
constexpr IData/*31:0*/ Vtop_axis_stream_if::KEEP_W;


void Vtop_axis_stream_if___ctor_var_reset(Vtop_axis_stream_if* vlSelf);

Vtop_axis_stream_if::Vtop_axis_stream_if() = default;
Vtop_axis_stream_if::~Vtop_axis_stream_if() = default;

void Vtop_axis_stream_if::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_axis_stream_if___ctor_var_reset(this);
}

void Vtop_axis_stream_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_axis_stream_if::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
