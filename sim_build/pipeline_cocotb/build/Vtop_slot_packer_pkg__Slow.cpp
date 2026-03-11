// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_slot_packer_pkg
constexpr CData/*7:0*/ Vtop_slot_packer_pkg::SLOT_HDR_VERSION_VAL_DFLT;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_MAGIC_BYTE_OFS;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_MAGIC_BYTES;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_VERSION_BYTE_OFS;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_VERSION_BYTES;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_FLAGS_BYTE_OFS;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_FLAGS_BYTES;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_RSVD0_BYTE_OFS;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_PKT_SEQ_BYTE_OFS;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_PKT_SEQ_BYTES;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_PKT_BYTES_BYTE_OFS;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_PKT_BYTES_BYTES;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_SAMPLE_CNT_BYTE_OFS;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_SAMPLE_CNT_BYTES;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_RSVD1_BYTE_OFS;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_SLOT_BYTES_BYTE_OFS;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_SLOT_BYTES_SIZE;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_SAMPLE_AREA_BYTE_OFS;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_SAMPLE_AREA_SIZE;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_CQ_AREA_BYTE_OFS;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_CQ_AREA_SIZE;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_FLAG_CRC_ERR_BIT;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_FLAG_ECC_ERR_BIT;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_FLAG_TRUNC_ERR_BIT;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_FLAG_VALID_GOOD_BIT;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_FLAG_OVERFLOW_BIT;
constexpr IData/*31:0*/ Vtop_slot_packer_pkg::SLOT_HDR_MAGIC_VAL_DFLT;


void Vtop_slot_packer_pkg___ctor_var_reset(Vtop_slot_packer_pkg* vlSelf);

Vtop_slot_packer_pkg::Vtop_slot_packer_pkg() = default;
Vtop_slot_packer_pkg::~Vtop_slot_packer_pkg() = default;

void Vtop_slot_packer_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_slot_packer_pkg___ctor_var_reset(this);
}

void Vtop_slot_packer_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_slot_packer_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
