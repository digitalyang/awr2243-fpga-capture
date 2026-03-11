// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_csi_packet_pkg
constexpr IData/*31:0*/ Vtop_csi_packet_pkg::CSI_VC_W;
constexpr IData/*31:0*/ Vtop_csi_packet_pkg::CSI_DT_W;
constexpr IData/*31:0*/ Vtop_csi_packet_pkg::CSI_WORD_COUNT_W;
constexpr IData/*31:0*/ Vtop_csi_packet_pkg::CSI_TUSER_PKT_START_BIT_DFLT;
constexpr IData/*31:0*/ Vtop_csi_packet_pkg::CSI_TUSER_CRC_ERR_BIT_DFLT;
constexpr IData/*31:0*/ Vtop_csi_packet_pkg::CSI_TUSER_ECC_ERR_BIT_DFLT;
constexpr IData/*31:0*/ Vtop_csi_packet_pkg::CSI_TUSER_TRUNC_ERR_BIT_DFLT;
constexpr IData/*31:0*/ Vtop_csi_packet_pkg::CSI_TUSER_VC_LSB_DFLT;
constexpr IData/*31:0*/ Vtop_csi_packet_pkg::CSI_TUSER_DT_LSB_DFLT;
constexpr IData/*31:0*/ Vtop_csi_packet_pkg::CSI_TUSER_PAYLOAD_LEN_LSB_DFLT;


void Vtop_csi_packet_pkg___ctor_var_reset(Vtop_csi_packet_pkg* vlSelf);

Vtop_csi_packet_pkg::Vtop_csi_packet_pkg() = default;
Vtop_csi_packet_pkg::~Vtop_csi_packet_pkg() = default;

void Vtop_csi_packet_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_csi_packet_pkg___ctor_var_reset(this);
}

void Vtop_csi_packet_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_csi_packet_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
