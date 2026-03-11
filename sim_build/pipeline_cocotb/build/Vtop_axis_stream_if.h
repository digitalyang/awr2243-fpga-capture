// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_AXIS_STREAM_IF_H_
#define VERILATED_VTOP_AXIS_STREAM_IF_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_axis_stream_if final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tvalid;
    CData/*0:0*/ tready;
    CData/*0:0*/ tlast;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_0;
    VlWide<8>/*255:0*/ tdata;
    IData/*31:0*/ tkeep;
    QData/*63:0*/ tuser;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ DATA_W = 0x00000100U;
    static constexpr IData/*31:0*/ USER_W = 0x00000040U;
    static constexpr IData/*31:0*/ KEEP_W = 0x00000020U;

    // CONSTRUCTORS
    Vtop_axis_stream_if();
    ~Vtop_axis_stream_if();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_axis_stream_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};

std::string VL_TO_STRING(const Vtop_axis_stream_if* obj);

#endif  // guard
