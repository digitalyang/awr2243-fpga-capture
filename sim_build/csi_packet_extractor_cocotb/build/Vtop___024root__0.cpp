// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_triggers_vec__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__clk_i 
        = vlSelfRef.clk_i;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__rst_ni 
        = vlSelfRef.rst_ni;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[0U] 
        = vlSelfRef.s_axis_tdata[0U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[1U] 
        = vlSelfRef.s_axis_tdata[1U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[2U] 
        = vlSelfRef.s_axis_tdata[2U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[3U] 
        = vlSelfRef.s_axis_tdata[3U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[4U] 
        = vlSelfRef.s_axis_tdata[4U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[5U] 
        = vlSelfRef.s_axis_tdata[5U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[6U] 
        = vlSelfRef.s_axis_tdata[6U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata[7U] 
        = vlSelfRef.s_axis_tdata[7U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_crc_err_c 
        = (1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                 >> 1U));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_ecc_err_c 
        = (1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                 >> 2U));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tkeep 
        = vlSelfRef.s_axis_tkeep;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tlast 
        = vlSelfRef.s_axis_tlast;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c 
        = (0x0000ffffU & ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[1U] 
                           << 8U) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                                     >> 0x00000018U)));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c 
        = (0x0000003fU & (((1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                  >> 1U)) + (1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                   >> 2U))) 
                          + (((1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                     >> 3U)) + (1U 
                                                & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                   >> 4U))) 
                             + ((1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                       >> 5U)) + ((1U 
                                                   & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                      >> 6U)) 
                                                  + 
                                                  ((1U 
                                                    & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                       >> 7U)) 
                                                   + 
                                                   ((1U 
                                                     & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                        >> 8U)) 
                                                    + 
                                                    ((1U 
                                                      & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                         >> 9U)) 
                                                     + 
                                                     ((1U 
                                                       & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                          >> 0x0000000aU)) 
                                                      + 
                                                      ((1U 
                                                        & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                           >> 0x0000000bU)) 
                                                       + 
                                                       ((1U 
                                                         & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                            >> 0x0000000cU)) 
                                                        + 
                                                        ((1U 
                                                          & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                             >> 0x0000000dU)) 
                                                         + 
                                                         ((1U 
                                                           & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                              >> 0x0000000eU)) 
                                                          + 
                                                          ((1U 
                                                            & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                               >> 0x0000000fU)) 
                                                           + 
                                                           ((1U 
                                                             & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                >> 0x00000010U)) 
                                                            + 
                                                            ((1U 
                                                              & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                 >> 0x00000011U)) 
                                                             + 
                                                             ((1U 
                                                               & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                  >> 0x00000012U)) 
                                                              + 
                                                              ((1U 
                                                                & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                   >> 0x00000013U)) 
                                                               + 
                                                               ((1U 
                                                                 & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                    >> 0x00000014U)) 
                                                                + 
                                                                ((1U 
                                                                  & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                     >> 0x00000015U)) 
                                                                 + 
                                                                 ((1U 
                                                                   & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                      >> 0x00000016U)) 
                                                                  + 
                                                                  ((1U 
                                                                    & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                       >> 0x00000017U)) 
                                                                   + 
                                                                   ((1U 
                                                                     & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                        >> 0x00000018U)) 
                                                                    + 
                                                                    ((1U 
                                                                      & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                         >> 0x00000019U)) 
                                                                     + 
                                                                     ((1U 
                                                                       & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                          >> 0x0000001aU)) 
                                                                      + 
                                                                      ((1U 
                                                                        & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                           >> 0x0000001bU)) 
                                                                       + 
                                                                       ((1U 
                                                                         & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                            >> 0x0000001cU)) 
                                                                        + 
                                                                        ((1U 
                                                                          & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                             >> 0x0000001dU)) 
                                                                         + 
                                                                         ((1U 
                                                                           & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                              >> 0x0000001eU)) 
                                                                          + 
                                                                          ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                            >> 0x0000001fU) 
                                                                           + 
                                                                           (1U 
                                                                            & vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[3U])))))))))))))))))))))))))))))));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tuser 
        = vlSelfRef.s_axis_tuser;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c 
        = (1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                 >> 3U));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tready 
        = vlSelfRef.m_axis_tready;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tvalid 
        = vlSelfRef.s_axis_tvalid;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_vc_c 
        = (3U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                 >> 8U));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_dt_c 
        = (0x0000003fU & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                          >> 0x00000010U));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_vc_en_i 
        = vlSelfRef.cfg_vc_en_i;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_dt_en_i 
        = vlSelfRef.cfg_dt_en_i;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_vc_i 
        = vlSelfRef.cfg_vc_i;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_dt_i 
        = vlSelfRef.cfg_dt_i;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__clk_i;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__rst_ni;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h503bf3ac__0 
        = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c) 
           | ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c) 
              != (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c)));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h5ac0cf88__0 
        = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c) 
           | ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c) 
              > (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c)));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_en_i 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_vc_en_i;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_en_i 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_dt_en_i;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_i 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_vc_i;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_i 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_dt_i;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c 
        = (1U & (((~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_en_i)) 
                  | ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_i) 
                     == (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_vc_c))) 
                 & ((~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_en_i)) 
                    | ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_i) 
                       == (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_dt_c)))));
}

extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h9e67c271_0;

void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_ASSIGN_W(256, vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c 
        = (0x0000003fU & (((1U & vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep) 
                           + (1U & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                    >> 1U))) + (((1U 
                                                  & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                     >> 2U)) 
                                                 + 
                                                 (1U 
                                                  & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                     >> 3U))) 
                                                + (
                                                   (1U 
                                                    & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                       >> 4U)) 
                                                   + 
                                                   ((1U 
                                                     & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                        >> 5U)) 
                                                    + 
                                                    ((1U 
                                                      & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                         >> 6U)) 
                                                     + 
                                                     ((1U 
                                                       & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                          >> 7U)) 
                                                      + 
                                                      ((1U 
                                                        & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                           >> 8U)) 
                                                       + 
                                                       ((1U 
                                                         & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                            >> 9U)) 
                                                        + 
                                                        ((1U 
                                                          & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                             >> 0x0000000aU)) 
                                                         + 
                                                         ((1U 
                                                           & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                              >> 0x0000000bU)) 
                                                          + 
                                                          ((1U 
                                                            & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                               >> 0x0000000cU)) 
                                                           + 
                                                           ((1U 
                                                             & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                >> 0x0000000dU)) 
                                                            + 
                                                            ((1U 
                                                              & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                 >> 0x0000000eU)) 
                                                             + 
                                                             ((1U 
                                                               & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                  >> 0x0000000fU)) 
                                                              + 
                                                              ((1U 
                                                                & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                   >> 0x00000010U)) 
                                                               + 
                                                               ((1U 
                                                                 & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                    >> 0x00000011U)) 
                                                                + 
                                                                ((1U 
                                                                  & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                     >> 0x00000012U)) 
                                                                 + 
                                                                 ((1U 
                                                                   & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                      >> 0x00000013U)) 
                                                                  + 
                                                                  ((1U 
                                                                    & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                       >> 0x00000014U)) 
                                                                   + 
                                                                   ((1U 
                                                                     & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                        >> 0x00000015U)) 
                                                                    + 
                                                                    ((1U 
                                                                      & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                         >> 0x00000016U)) 
                                                                     + 
                                                                     ((1U 
                                                                       & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                          >> 0x00000017U)) 
                                                                      + 
                                                                      ((1U 
                                                                        & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                           >> 0x00000018U)) 
                                                                       + 
                                                                       ((1U 
                                                                         & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                            >> 0x00000019U)) 
                                                                        + 
                                                                        ((1U 
                                                                          & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                             >> 0x0000001aU)) 
                                                                         + 
                                                                         ((1U 
                                                                           & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                              >> 0x0000001bU)) 
                                                                          + 
                                                                          ((1U 
                                                                            & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                               >> 0x0000001cU)) 
                                                                           + 
                                                                           ((1U 
                                                                             & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                                >> 0x0000001dU)) 
                                                                            + 
                                                                            ((1U 
                                                                              & (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                                >> 0x0000001eU)) 
                                                                             + 
                                                                             (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                                                                              >> 0x0000001fU)))))))))))))))))))))))))))))));
    vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep = 0U;
    vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast = 0U;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_crc_err_c 
        = (1U & (IData)((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser 
                         >> 1U)));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_ecc_err_c 
        = (1U & (IData)((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser 
                         >> 2U)));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c 
        = (1U & (IData)((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser 
                         >> 3U)));
    vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser = 0ULL;
    vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid = 0U;
    vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready = 0U;
    if ((2U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
        if ((1U & (~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)))) {
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[0U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[0U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[1U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[1U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[2U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[2U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[3U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[3U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[4U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[4U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[5U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[5U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[6U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[6U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[7U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[7U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep;
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast;
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser;
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tvalid;
        }
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[0U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[0U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[1U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[1U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[2U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[2U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[3U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[3U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[4U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[4U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[5U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[5U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[6U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[6U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[7U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[7U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tkeep 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tlast 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tuser 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tvalid 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid;
        vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready 
            = ((1U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)) 
               || (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tready));
    } else {
        if ((1U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
            if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c) {
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[0U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[4U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[3U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[1U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[5U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[4U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[2U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[6U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[5U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[3U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[7U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[6U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[4U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[8U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[7U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[5U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[9U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[8U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[6U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[10U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[9U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[7U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[11U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[10U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[3U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast 
                    = (1U & vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U]);
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser 
                    = (((QData)((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[1U])) 
                        << 0x00000020U) | (QData)((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U])));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid = 1U;
            }
        }
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[0U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[0U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[1U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[1U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[2U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[2U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[3U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[3U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[4U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[4U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[5U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[5U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[6U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[6U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[7U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[7U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tkeep 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tlast 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tuser 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tvalid 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid;
        if ((1U & (~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)))) {
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready = 1U;
        }
    }
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c 
        = ((IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tready) 
           & (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tready 
        = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c 
        = ((IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready) 
           & (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tvalid));
    vlSelfRef.m_axis_tdata[0U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[0U];
    vlSelfRef.m_axis_tdata[1U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[1U];
    vlSelfRef.m_axis_tdata[2U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[2U];
    vlSelfRef.m_axis_tdata[3U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[3U];
    vlSelfRef.m_axis_tdata[4U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[4U];
    vlSelfRef.m_axis_tdata[5U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[5U];
    vlSelfRef.m_axis_tdata[6U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[6U];
    vlSelfRef.m_axis_tdata[7U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[7U];
    vlSelfRef.m_axis_tkeep = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tkeep;
    vlSelfRef.m_axis_tlast = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tlast;
    vlSelfRef.m_axis_tuser = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tuser;
    vlSelfRef.m_axis_tvalid = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tvalid;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_start_o 
        = ((1U == (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)) 
           & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c) 
              & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c)));
    vlSelfRef.s_axis_tready = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tready;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[0U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[1U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[1U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[2U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[3U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[3U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[4U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[4U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[5U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[5U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[6U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[6U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[7U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[7U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[8U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[8U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[9U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[9U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[10U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[10U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[11U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[11U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r;
    if ((1U & (~ ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r) 
                  >> 1U)))) {
        if ((1U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
            if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c) {
                if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c) {
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_n 
                        = (0x0000ffffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r)));
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_n 
                        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r;
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n 
                        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c;
                }
            }
        } else if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) {
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n = 0U;
        }
        if ((1U & (~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)))) {
            if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) {
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[0U] 
                    = (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser);
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[1U] 
                    = (IData)((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser 
                               >> 0x00000020U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[2U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                        << 1U) | (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[3U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[0U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[4U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[0U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[1U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[5U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[1U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[2U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[6U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[2U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[3U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[7U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[3U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[4U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[8U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[4U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[5U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[9U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[5U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[6U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[10U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[6U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[7U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[11U] 
                    = (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[7U] 
                       >> 0x0000001fU);
            }
        }
    }
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r;
    if ((2U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
        if ((1U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
            if (((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) 
                 & (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast))) {
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n = 0U;
            }
        } else if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) {
            if (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast) {
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n = 0U;
            }
        }
        if ((1U & (~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)))) {
            if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) {
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n 
                    = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r) 
                       | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_crc_err_c));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n 
                    = (0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                                      + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c)));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n 
                    = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r) 
                       | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_ecc_err_c));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
                    = (((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r) 
                        | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c)) 
                       | ((0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                                          + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c))) 
                          > (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r)));
                if (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast) {
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
                        = (((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r) 
                            | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c)) 
                           | ((0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                                              + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c))) 
                              != (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r)));
                }
            }
        }
    } else if ((1U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
        if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c) {
            if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c) {
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n 
                    = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_crc_err_c;
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n 
                    = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c;
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n 
                    = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_ecc_err_c;
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
                    = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c;
                if ((1U & vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U])) {
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n = 0U;
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
                        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h503bf3ac__0;
                } else {
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n = 2U;
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
                        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h5ac0cf88__0;
                }
            }
        } else {
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n 
                = ((1U & vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U])
                    ? 0U : 3U);
        }
    } else if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) {
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n = 1U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n = 0U;
    }
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c = 0U;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r;
    if ((((1U == (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)) 
          & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c)) 
         & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c))) {
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_crc_err_c;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_ecc_err_c;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c;
        if ((1U & vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U])) {
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c = 1U;
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
                = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h503bf3ac__0;
        } else {
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
                = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h5ac0cf88__0;
        }
    } else if (((2U == (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)) 
                & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c))) {
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c 
            = (0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                              + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c)));
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c 
            = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r) 
               | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_crc_err_c));
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c 
            = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r) 
               | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_ecc_err_c));
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
            = (((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r) 
                | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c)) 
               | ((0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                                  + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c))) 
                  > (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r)));
        if (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast) {
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c = 1U;
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
                = (((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r) 
                    | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c)) 
                   | ((0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                                      + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c))) 
                      != (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r)));
        }
    }
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_start_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_start_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_valid_good_o 
        = ((~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c)) 
           & ((~ ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c) 
                  | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c))) 
              & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c)));
    vlSelfRef.pkt_start_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_start_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_seq_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_bytes_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_done_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_crc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_ecc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_trunc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_valid_good_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_valid_good_o;
    vlSelfRef.pkt_seq_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_seq_o;
    vlSelfRef.pkt_bytes_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_bytes_o;
    vlSelfRef.pkt_done_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_done_o;
    vlSelfRef.pkt_crc_err_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_crc_err_o;
    vlSelfRef.pkt_ecc_err_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_ecc_err_o;
    vlSelfRef.pkt_trunc_err_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_trunc_err_o;
    vlSelfRef.pkt_valid_good_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_valid_good_o;
}

void Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if__0(Vtop_axis_stream_if* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if__0((&vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if));
        Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if__0((&vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if));
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers_vec__ico(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i__0 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni__0 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni;
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni) {
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_n;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_n;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[0U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[1U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[1U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[2U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[3U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[3U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[4U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[4U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[5U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[5U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[6U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[6U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[7U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[7U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[8U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[8U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[9U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[9U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[10U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[10U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[11U] 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[11U];
    } else {
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[1U] = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[3U] = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[4U] = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[5U] = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[6U] = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[7U] = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[8U] = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[9U] = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[10U] = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[11U] = 0U;
    }
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r 
        = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni) 
           && (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r 
        = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni) 
           && (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r 
        = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni) 
           && (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n));
    vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready = 0U;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_crc_err_c 
        = (1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                 >> 1U));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_ecc_err_c 
        = (1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                 >> 2U));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c 
        = (0x0000ffffU & ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[1U] 
                           << 8U) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                                     >> 0x00000018U)));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c 
        = (0x0000003fU & (((1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                  >> 1U)) + (1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                   >> 2U))) 
                          + (((1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                     >> 3U)) + (1U 
                                                & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                   >> 4U))) 
                             + ((1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                       >> 5U)) + ((1U 
                                                   & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                      >> 6U)) 
                                                  + 
                                                  ((1U 
                                                    & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                       >> 7U)) 
                                                   + 
                                                   ((1U 
                                                     & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                        >> 8U)) 
                                                    + 
                                                    ((1U 
                                                      & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                         >> 9U)) 
                                                     + 
                                                     ((1U 
                                                       & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                          >> 0x0000000aU)) 
                                                      + 
                                                      ((1U 
                                                        & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                           >> 0x0000000bU)) 
                                                       + 
                                                       ((1U 
                                                         & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                            >> 0x0000000cU)) 
                                                        + 
                                                        ((1U 
                                                          & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                             >> 0x0000000dU)) 
                                                         + 
                                                         ((1U 
                                                           & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                              >> 0x0000000eU)) 
                                                          + 
                                                          ((1U 
                                                            & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                               >> 0x0000000fU)) 
                                                           + 
                                                           ((1U 
                                                             & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                >> 0x00000010U)) 
                                                            + 
                                                            ((1U 
                                                              & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                 >> 0x00000011U)) 
                                                             + 
                                                             ((1U 
                                                               & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                  >> 0x00000012U)) 
                                                              + 
                                                              ((1U 
                                                                & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                   >> 0x00000013U)) 
                                                               + 
                                                               ((1U 
                                                                 & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                    >> 0x00000014U)) 
                                                                + 
                                                                ((1U 
                                                                  & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                     >> 0x00000015U)) 
                                                                 + 
                                                                 ((1U 
                                                                   & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                      >> 0x00000016U)) 
                                                                  + 
                                                                  ((1U 
                                                                    & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                       >> 0x00000017U)) 
                                                                   + 
                                                                   ((1U 
                                                                     & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                        >> 0x00000018U)) 
                                                                    + 
                                                                    ((1U 
                                                                      & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                         >> 0x00000019U)) 
                                                                     + 
                                                                     ((1U 
                                                                       & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                          >> 0x0000001aU)) 
                                                                      + 
                                                                      ((1U 
                                                                        & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                           >> 0x0000001bU)) 
                                                                       + 
                                                                       ((1U 
                                                                         & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                            >> 0x0000001cU)) 
                                                                        + 
                                                                        ((1U 
                                                                          & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                             >> 0x0000001dU)) 
                                                                         + 
                                                                         ((1U 
                                                                           & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                              >> 0x0000001eU)) 
                                                                          + 
                                                                          ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                                                            >> 0x0000001fU) 
                                                                           + 
                                                                           (1U 
                                                                            & vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[3U])))))))))))))))))))))))))))))));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c 
        = (1U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                 >> 3U));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_vc_c 
        = (3U & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                 >> 8U));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_dt_c 
        = (0x0000003fU & (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U] 
                          >> 0x00000010U));
    if ((2U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
        vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready 
            = ((1U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)) 
               || (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tready));
    } else if ((1U & (~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)))) {
        vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready = 1U;
    }
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tready 
        = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c 
        = ((IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready) 
           & (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tvalid));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h503bf3ac__0 
        = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c) 
           | ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c) 
              != (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c)));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h5ac0cf88__0 
        = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c) 
           | ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c) 
              > (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c)));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c 
        = (1U & (((~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_en_i)) 
                  | ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_i) 
                     == (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_vc_c))) 
                 & ((~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_en_i)) 
                    | ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_i) 
                       == (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_dt_c)))));
    vlSelfRef.s_axis_tready = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tready;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[0U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[1U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[1U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[2U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[3U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[3U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[4U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[4U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[5U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[5U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[6U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[6U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[7U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[7U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[8U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[8U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[9U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[9U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[10U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[10U];
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[11U] 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[11U];
    if ((1U & (~ ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r) 
                  >> 1U)))) {
        if ((1U & (~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)))) {
            if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) {
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[0U] 
                    = (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser);
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[1U] 
                    = (IData)((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser 
                               >> 0x00000020U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[2U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                        << 1U) | (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[3U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[0U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[4U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[0U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[1U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[5U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[1U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[2U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[6U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[2U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[3U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[7U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[3U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[4U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[8U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[4U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[5U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[9U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[5U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[6U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[10U] 
                    = ((vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[6U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[7U] 
                                           << 1U));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n[11U] 
                    = (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[7U] 
                       >> 0x0000001fU);
            }
        }
    }
    vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast = 0U;
    VL_ASSIGN_W(256, vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep = 0U;
    vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser = 0ULL;
    vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid = 0U;
    if ((2U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
        if ((1U & (~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)))) {
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast;
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[0U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[0U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[1U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[1U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[2U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[2U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[3U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[3U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[4U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[4U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[5U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[5U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[6U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[6U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[7U] 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata[7U];
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep;
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser;
            vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid 
                = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tvalid;
        }
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tlast 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[0U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[0U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[1U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[1U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[2U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[2U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[3U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[3U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[4U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[4U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[5U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[5U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[6U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[6U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[7U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[7U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tkeep 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tuser 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser;
    } else {
        if ((1U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
            if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c) {
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast 
                    = (1U & vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U]);
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[0U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[4U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[3U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[1U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[5U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[4U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[2U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[6U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[5U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[3U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[7U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[6U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[4U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[8U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[7U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[5U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[9U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[8U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[6U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[10U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[9U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[7U] 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[11U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[10U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep 
                    = ((vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[3U] 
                        << 0x0000001fU) | (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U] 
                                           >> 1U));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser 
                    = (((QData)((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[1U])) 
                        << 0x00000020U) | (QData)((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[0U])));
                vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid = 1U;
            }
        }
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tlast 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[0U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[0U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[1U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[1U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[2U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[2U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[3U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[3U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[4U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[4U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[5U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[5U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[6U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[6U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[7U] 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata[7U];
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tkeep 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tuser 
            = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser;
    }
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tvalid 
        = vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c 
        = ((IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tready) 
           & (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid));
    vlSelfRef.m_axis_tlast = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tlast;
    vlSelfRef.m_axis_tdata[0U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[0U];
    vlSelfRef.m_axis_tdata[1U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[1U];
    vlSelfRef.m_axis_tdata[2U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[2U];
    vlSelfRef.m_axis_tdata[3U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[3U];
    vlSelfRef.m_axis_tdata[4U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[4U];
    vlSelfRef.m_axis_tdata[5U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[5U];
    vlSelfRef.m_axis_tdata[6U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[6U];
    vlSelfRef.m_axis_tdata[7U] = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata[7U];
    vlSelfRef.m_axis_tkeep = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tkeep;
    vlSelfRef.m_axis_tuser = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tuser;
    vlSelfRef.m_axis_tvalid = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tvalid;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r;
    if ((1U & (~ ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r) 
                  >> 1U)))) {
        if ((1U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
            if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c) {
                if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c) {
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_n 
                        = (0x0000ffffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r)));
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_n 
                        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r;
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n 
                        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c;
                }
            }
        } else if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) {
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n = 0U;
        }
    }
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_start_o 
        = ((1U == (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)) 
           & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c) 
              & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c)));
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r;
    if ((2U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
        if ((1U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
            if (((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) 
                 & (IData)(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast))) {
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n = 0U;
            }
        } else if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) {
            if (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast) {
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n = 0U;
            }
        }
        if ((1U & (~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)))) {
            if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) {
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n 
                    = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r) 
                       | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_crc_err_c));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n 
                    = (0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                                      + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c)));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n 
                    = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r) 
                       | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_ecc_err_c));
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
                    = (((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r) 
                        | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c)) 
                       | ((0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                                          + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c))) 
                          > (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r)));
                if (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast) {
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
                        = (((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r) 
                            | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c)) 
                           | ((0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                                              + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c))) 
                              != (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r)));
                }
            }
        }
    } else if ((1U & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r))) {
        if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c) {
            if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c) {
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n 
                    = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_crc_err_c;
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n 
                    = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c;
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n 
                    = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_ecc_err_c;
                vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
                    = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c;
                if ((1U & vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U])) {
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n = 0U;
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
                        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h503bf3ac__0;
                } else {
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n = 2U;
                    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n 
                        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h5ac0cf88__0;
                }
            }
        } else {
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n 
                = ((1U & vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U])
                    ? 0U : 3U);
        }
    } else if (vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c) {
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n = 1U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n = 0U;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n = 0U;
    }
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c = 0U;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r;
    if ((((1U == (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)) 
          & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c)) 
         & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c))) {
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_crc_err_c;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_ecc_err_c;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c;
        if ((1U & vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r[2U])) {
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c = 1U;
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
                = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h503bf3ac__0;
        } else {
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
                = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h5ac0cf88__0;
        }
    } else if (((2U == (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r)) 
                & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c))) {
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c 
            = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r;
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c 
            = (0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                              + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c)));
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c 
            = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r) 
               | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_crc_err_c));
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c 
            = ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r) 
               | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_ecc_err_c));
        vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
            = (((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r) 
                | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c)) 
               | ((0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                                  + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c))) 
                  > (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r)));
        if (vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast) {
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c = 1U;
            vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c 
                = (((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r) 
                    | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c)) 
                   | ((0x0000ffffU & ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r) 
                                      + (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c))) 
                      != (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r)));
        }
    }
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_start_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_start_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_valid_good_o 
        = ((~ (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c)) 
           & ((~ ((IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c) 
                  | (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c))) 
              & (IData)(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c)));
    vlSelfRef.pkt_start_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_start_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_seq_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_bytes_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_done_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_crc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_ecc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_trunc_err_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_o;
    vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_valid_good_o 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_valid_good_o;
    vlSelfRef.pkt_seq_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_seq_o;
    vlSelfRef.pkt_bytes_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_bytes_o;
    vlSelfRef.pkt_done_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_done_o;
    vlSelfRef.pkt_crc_err_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_crc_err_o;
    vlSelfRef.pkt_ecc_err_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_ecc_err_o;
    vlSelfRef.pkt_trunc_err_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_trunc_err_o;
    vlSelfRef.pkt_valid_good_o = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_valid_good_o;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/csi_packet_extractor_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/csi_packet_extractor_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/csi_packet_extractor_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk_i & 0xfeU)))) {
        Verilated::overWidthError("clk_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_ni & 0xfeU)))) {
        Verilated::overWidthError("rst_ni");
    }
    if (VL_UNLIKELY(((vlSelfRef.cfg_vc_en_i & 0xfeU)))) {
        Verilated::overWidthError("cfg_vc_en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.cfg_dt_en_i & 0xfeU)))) {
        Verilated::overWidthError("cfg_dt_en_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.cfg_vc_i & 0xfcU)))) {
        Verilated::overWidthError("cfg_vc_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.cfg_dt_i & 0xc0U)))) {
        Verilated::overWidthError("cfg_dt_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.s_axis_tvalid & 0xfeU)))) {
        Verilated::overWidthError("s_axis_tvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.s_axis_tlast & 0xfeU)))) {
        Verilated::overWidthError("s_axis_tlast");
    }
    if (VL_UNLIKELY(((vlSelfRef.m_axis_tready & 0xfeU)))) {
        Verilated::overWidthError("m_axis_tready");
    }
}
#endif  // VL_DEBUG
