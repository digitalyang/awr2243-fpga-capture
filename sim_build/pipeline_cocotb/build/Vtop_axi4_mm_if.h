// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_AXI4_MM_IF_H_
#define VERILATED_VTOP_AXI4_MM_IF_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_axi4_mm_if final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*7:0*/ awlen;
    CData/*2:0*/ awsize;
    CData/*1:0*/ awburst;
    CData/*0:0*/ awvalid;
    CData/*0:0*/ awready;
    CData/*0:0*/ wlast;
    CData/*0:0*/ wvalid;
    CData/*0:0*/ wready;
    CData/*1:0*/ bresp;
    CData/*0:0*/ bvalid;
    CData/*0:0*/ bready;
    CData/*7:0*/ arlen;
    CData/*2:0*/ arsize;
    CData/*1:0*/ arburst;
    CData/*0:0*/ arvalid;
    CData/*0:0*/ arready;
    CData/*1:0*/ rresp;
    CData/*0:0*/ rlast;
    CData/*0:0*/ rvalid;
    CData/*0:0*/ rready;
    VlWide<8>/*255:0*/ wdata;
    IData/*31:0*/ wstrb;
    VlWide<8>/*255:0*/ rdata;
    QData/*33:0*/ awaddr;
    QData/*33:0*/ araddr;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ ADDR_W = 0x00000022U;
    static constexpr IData/*31:0*/ DATA_W = 0x00000100U;
    static constexpr IData/*31:0*/ STRB_W = 0x00000020U;

    // CONSTRUCTORS
    Vtop_axi4_mm_if();
    ~Vtop_axi4_mm_if();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_axi4_mm_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtop_axi4_mm_if* obj);

#endif  // guard
