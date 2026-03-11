// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_DDR_RINGBUFFER_PKG_H_
#define VERILATED_VTOP_DDR_RINGBUFFER_PKG_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_ddr_ringbuffer_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*1:0*/ AXI_RESP_OKAY = 0U;
    static constexpr CData/*1:0*/ AXI_BURST_INCR = 1U;
    static constexpr IData/*31:0*/ DDR_RING_ADDR_W_DFLT = 0x00000022U;
    static constexpr IData/*31:0*/ DDR_RING_BYTES_W_DFLT = 0x00000011U;
    static constexpr IData/*31:0*/ DDR_RING_SLOT_BYTES_W_DFLT = 0x00000011U;
    static constexpr IData/*31:0*/ DDR_RING_SLOT_SEQ_W_DFLT = 0x00000010U;
    static constexpr IData/*31:0*/ DDR_RING_COUNTER_W_DFLT = 0x00000020U;

    // CONSTRUCTORS
    Vtop_ddr_ringbuffer_pkg();
    ~Vtop_ddr_ringbuffer_pkg();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_ddr_ringbuffer_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
