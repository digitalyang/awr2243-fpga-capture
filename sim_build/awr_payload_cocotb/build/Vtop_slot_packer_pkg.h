// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_SLOT_PACKER_PKG_H_
#define VERILATED_VTOP_SLOT_PACKER_PKG_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_slot_packer_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*7:0*/ SLOT_HDR_VERSION_VAL_DFLT = 1U;
    static constexpr IData/*31:0*/ SLOT_HDR_MAGIC_BYTE_OFS = 0U;
    static constexpr IData/*31:0*/ SLOT_HDR_MAGIC_BYTES = 4U;
    static constexpr IData/*31:0*/ SLOT_HDR_VERSION_BYTE_OFS = 4U;
    static constexpr IData/*31:0*/ SLOT_HDR_VERSION_BYTES = 1U;
    static constexpr IData/*31:0*/ SLOT_HDR_FLAGS_BYTE_OFS = 5U;
    static constexpr IData/*31:0*/ SLOT_HDR_FLAGS_BYTES = 1U;
    static constexpr IData/*31:0*/ SLOT_HDR_RSVD0_BYTE_OFS = 6U;
    static constexpr IData/*31:0*/ SLOT_HDR_PKT_SEQ_BYTE_OFS = 8U;
    static constexpr IData/*31:0*/ SLOT_HDR_PKT_SEQ_BYTES = 2U;
    static constexpr IData/*31:0*/ SLOT_HDR_PKT_BYTES_BYTE_OFS = 0x0000000aU;
    static constexpr IData/*31:0*/ SLOT_HDR_PKT_BYTES_BYTES = 2U;
    static constexpr IData/*31:0*/ SLOT_HDR_SAMPLE_CNT_BYTE_OFS = 0x0000000cU;
    static constexpr IData/*31:0*/ SLOT_HDR_SAMPLE_CNT_BYTES = 2U;
    static constexpr IData/*31:0*/ SLOT_HDR_RSVD1_BYTE_OFS = 0x0000000eU;
    static constexpr IData/*31:0*/ SLOT_HDR_SLOT_BYTES_BYTE_OFS = 0x00000010U;
    static constexpr IData/*31:0*/ SLOT_HDR_SLOT_BYTES_SIZE = 4U;
    static constexpr IData/*31:0*/ SLOT_HDR_SAMPLE_AREA_BYTE_OFS = 0x00000014U;
    static constexpr IData/*31:0*/ SLOT_HDR_SAMPLE_AREA_SIZE = 4U;
    static constexpr IData/*31:0*/ SLOT_HDR_CQ_AREA_BYTE_OFS = 0x00000018U;
    static constexpr IData/*31:0*/ SLOT_HDR_CQ_AREA_SIZE = 2U;
    static constexpr IData/*31:0*/ SLOT_HDR_FLAG_CRC_ERR_BIT = 0U;
    static constexpr IData/*31:0*/ SLOT_HDR_FLAG_ECC_ERR_BIT = 1U;
    static constexpr IData/*31:0*/ SLOT_HDR_FLAG_TRUNC_ERR_BIT = 2U;
    static constexpr IData/*31:0*/ SLOT_HDR_FLAG_VALID_GOOD_BIT = 3U;
    static constexpr IData/*31:0*/ SLOT_HDR_FLAG_OVERFLOW_BIT = 4U;
    static constexpr IData/*31:0*/ SLOT_HDR_MAGIC_VAL_DFLT = 0xaa551024U;

    // CONSTRUCTORS
    Vtop_slot_packer_pkg();
    ~Vtop_slot_packer_pkg();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_slot_packer_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
