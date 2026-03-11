// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_CSI_PACKET_PKG_H_
#define VERILATED_VTOP_CSI_PACKET_PKG_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_csi_packet_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ CSI_VC_W = 2U;
    static constexpr IData/*31:0*/ CSI_DT_W = 6U;
    static constexpr IData/*31:0*/ CSI_WORD_COUNT_W = 0x00000010U;
    static constexpr IData/*31:0*/ CSI_TUSER_PKT_START_BIT_DFLT = 0U;
    static constexpr IData/*31:0*/ CSI_TUSER_CRC_ERR_BIT_DFLT = 1U;
    static constexpr IData/*31:0*/ CSI_TUSER_ECC_ERR_BIT_DFLT = 2U;
    static constexpr IData/*31:0*/ CSI_TUSER_TRUNC_ERR_BIT_DFLT = 3U;
    static constexpr IData/*31:0*/ CSI_TUSER_VC_LSB_DFLT = 8U;
    static constexpr IData/*31:0*/ CSI_TUSER_DT_LSB_DFLT = 0x00000010U;
    static constexpr IData/*31:0*/ CSI_TUSER_PAYLOAD_LEN_LSB_DFLT = 0x00000018U;

    // CONSTRUCTORS
    Vtop_csi_packet_pkg();
    ~Vtop_csi_packet_pkg();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_csi_packet_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
