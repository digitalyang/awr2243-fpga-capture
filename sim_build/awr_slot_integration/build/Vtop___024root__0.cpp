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

extern const VlWide<16>/*511:0*/ Vtop__ConstPool__CONST_h93e1b771_0;
extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h9e67c271_0;

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VExpandSel_WordIdx_1;
    IData/*31:0*/ __VExpandSel_LoShift_1;
    CData/*0:0*/ __VExpandSel_Aligned_1;
    IData/*31:0*/ __VExpandSel_HiShift_1;
    IData/*31:0*/ __VExpandSel_HiMask_1;
    // Body
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__clk_i 
        = vlSelfRef.clk_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__rst_ni 
        = vlSelfRef.rst_ni;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tlast 
        = vlSelfRef.s_axis_tlast;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tuser 
        = vlSelfRef.s_axis_tuser;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tuser 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tuser;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_start_i 
        = vlSelfRef.pkt_start_i;
    vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep = 0U;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_overflow_err_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_seq_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_valid_good_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_seq_i 
        = vlSelfRef.pkt_seq_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_crc_err_i 
        = vlSelfRef.pkt_crc_err_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_ecc_err_i 
        = vlSelfRef.pkt_ecc_err_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_trunc_err_i 
        = vlSelfRef.pkt_trunc_err_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_bytes_i 
        = vlSelfRef.pkt_bytes_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c 
        = (0x85U == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__sample_pad_beats_c 
        = (0x000000ffU & ((IData)(0x80U) - (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r)));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tdata[0U] 
        = vlSelfRef.s_axis_tdata[0U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tdata[1U] 
        = vlSelfRef.s_axis_tdata[1U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tdata[2U] 
        = vlSelfRef.s_axis_tdata[2U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tdata[3U] 
        = vlSelfRef.s_axis_tdata[3U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tdata[4U] 
        = vlSelfRef.s_axis_tdata[4U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tdata[5U] 
        = vlSelfRef.s_axis_tdata[5U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tdata[6U] 
        = vlSelfRef.s_axis_tdata[6U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tdata[7U] 
        = vlSelfRef.s_axis_tdata[7U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__actual_sample_cnt_c 
        = ((0x1000U <= (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r))
            ? 0x00000400U : (0x000007ffU & ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r) 
                                            >> 2U)));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tkeep 
        = vlSelfRef.s_axis_tkeep;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tready 
        = vlSelfRef.m_axis_tready;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__cfg_drop_invalid_pkt_i 
        = vlSelfRef.cfg_drop_invalid_pkt_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_valid_good_i 
        = vlSelfRef.pkt_valid_good_i;
    vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid = 0U;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_done_i 
        = vlSelfRef.pkt_done_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tvalid 
        = vlSelfRef.s_axis_tvalid;
    vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tready = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r) 
                      >> 1U)))) {
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tready = 1U;
        }
    }
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__clk_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__rst_ni;
    vlSelfRef.m_axis_tuser = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tuser;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_start_i 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_start_i;
    if ((4U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r)))) {
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep = 0xffffffffU;
            }
        } else {
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep = 0xffffffffU;
        }
    } else if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
        vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep = 0xffffffffU;
    }
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tkeep 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_overflow_err_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_overflow_err_o;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_seq_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_seq_o;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_valid_good_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_valid_good_o;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_seq_i 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_seq_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_crc_err_i 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_crc_err_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_ecc_err_i 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_ecc_err_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_trunc_err_i 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_trunc_err_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_bytes_i;
    vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast = 0U;
    VL_ASSIGN_W(512, vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c, Vtop__ConstPool__CONST_h93e1b771_0);
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[0U] 
        = (IData)((0x00000001aa551024ULL | (((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r)) 
                                             << 0x0000002aU) 
                                            | (((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r)) 
                                                << 0x00000029U) 
                                               | ((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r)) 
                                                  << 0x00000028U)))));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[1U] 
        = ((0xfffff800U & vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[1U]) 
           | (IData)(((0x00000001aa551024ULL | (((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r)) 
                                                 << 0x0000002aU) 
                                                | (((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r)) 
                                                    << 0x00000029U) 
                                                   | ((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r)) 
                                                      << 0x00000028U)))) 
                      >> 0x00000020U)));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[1U] 
        = ((0xffffe7ffU & vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[1U]) 
           | (0xfffff800U & (((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r) 
                              << 0x0000000cU) | ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r) 
                                                 << 0x0000000bU))));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[2U] 
        = (IData)((((QData)((IData)((((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__actual_sample_cnt_c) 
                                      << 0x00000010U) 
                                     | (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r)))) 
                    << 0x00000010U) | (QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r))));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[3U] 
        = ((0xffff0000U & vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[3U]) 
           | (IData)(((((QData)((IData)((((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__actual_sample_cnt_c) 
                                          << 0x00000010U) 
                                         | (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r)))) 
                        << 0x00000010U) | (QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r))) 
                      >> 0x00000020U)));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[4U] = 0x000010c0U;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[5U] = 0x00001000U;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[6U] 
        = (0x00000080U | (0xffff0000U & vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[6U]));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cfg_drop_invalid_pkt_i 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__cfg_drop_invalid_pkt_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_valid_good_i 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_valid_good_i;
    if ((4U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r)))) {
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid = 1U;
            }
        } else {
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
        vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid = 1U;
    }
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tvalid 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_start_o 
        = ((IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid) 
           & (0U == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_done_o 
        = ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c) 
           & (IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_done_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tready 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tready;
    vlSelfRef.m_axis_tkeep = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tkeep;
    vlSelfRef.slot_overflow_err_o = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_overflow_err_o;
    vlSelfRef.slot_seq_o = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_seq_o;
    vlSelfRef.slot_valid_good_o = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_valid_good_o;
    if ((4U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r)))) {
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c;
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tlast 
                    = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast;
                VL_ASSIGN_W(256, vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
                VL_ASSIGN_W(256, vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
            } else {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tlast 
                    = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast;
                VL_ASSIGN_W(256, vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
            }
        } else {
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c;
            vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tlast 
                = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast;
            VL_ASSIGN_W(256, vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
            VL_ASSIGN_W(256, vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
        }
    } else if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
        vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast 
            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c;
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tlast 
            = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast;
        VL_ASSIGN_W(256, vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
        __VExpandSel_WordIdx_1 = (0x0000000fU & (VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r), 8U) 
                                                 >> 5U));
        __VExpandSel_LoShift_1 = (0x0000001fU & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r), 8U));
        __VExpandSel_Aligned_1 = (0U == __VExpandSel_LoShift_1);
        if (__VExpandSel_Aligned_1) {
            __VExpandSel_HiShift_1 = 0U;
            __VExpandSel_HiMask_1 = 0U;
        } else {
            __VExpandSel_HiShift_1 = ((IData)(0x00000020U) 
                                      - __VExpandSel_LoShift_1);
            __VExpandSel_HiMask_1 = 0xffffffffU;
        }
        if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[0U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][0U];
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[1U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][1U];
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[2U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][2U];
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[3U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][3U];
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[4U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][4U];
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[5U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][5U];
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[6U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][6U];
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[7U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][7U];
        } else {
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[0U] 
                = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                     [((IData)(1U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                      [__VExpandSel_WordIdx_1] >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[1U] 
                = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                     [((IData)(2U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                      [((IData)(1U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[2U] 
                = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                     [((IData)(3U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                      [((IData)(2U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[3U] 
                = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                     [((IData)(4U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                      [((IData)(3U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[4U] 
                = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                     [((IData)(5U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                      [((IData)(4U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[5U] 
                = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                     [((IData)(6U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                      [((IData)(5U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[6U] 
                = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                     [((IData)(7U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                      [((IData)(6U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[7U] 
                = (((((8U <= __VExpandSel_WordIdx_1)
                       ? 0U : vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                      [((IData)(8U) + __VExpandSel_WordIdx_1)]) 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                      [((IData)(7U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
        }
    } else {
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tlast 
            = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast;
        VL_ASSIGN_W(256, vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
    }
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c 
        = ((~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_valid_good_i)) 
           & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cfg_drop_invalid_pkt_i));
    vlSelfRef.m_axis_tvalid = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tvalid;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_start_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_start_o;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_done_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_done_o;
    vlSelfRef.s_axis_tready = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tready;
    vlSelfRef.m_axis_tlast = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tlast;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[0U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[0U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[1U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[1U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[2U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[2U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[3U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[3U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[4U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[4U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[5U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[5U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[6U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[6U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[7U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[7U];
    vlSelfRef.slot_start_o = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_start_o;
    vlSelfRef.slot_done_o = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_done_o;
    vlSelfRef.m_axis_tdata[0U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[0U];
    vlSelfRef.m_axis_tdata[1U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[1U];
    vlSelfRef.m_axis_tdata[2U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[2U];
    vlSelfRef.m_axis_tdata[3U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[3U];
    vlSelfRef.m_axis_tdata[4U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[4U];
    vlSelfRef.m_axis_tdata[5U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[5U];
    vlSelfRef.m_axis_tdata[6U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[6U];
    vlSelfRef.m_axis_tdata[7U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[7U];
}

void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<8>/*255:0*/ __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout;
    VL_ZERO_W(256, __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout);
    VlWide<8>/*255:0*/ __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data;
    VL_ZERO_W(256, __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data);
    IData/*31:0*/ __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep;
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep = 0;
    VlWide<8>/*255:0*/ __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result;
    VL_ZERO_W(256, __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result);
    // Body
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__keep_bytes_c 
        = (0x0000003fU & (((1U & vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep) 
                           + (1U & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                    >> 1U))) + (((1U 
                                                  & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                     >> 2U)) 
                                                 + 
                                                 (1U 
                                                  & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                     >> 3U))) 
                                                + (
                                                   (1U 
                                                    & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                       >> 4U)) 
                                                   + 
                                                   ((1U 
                                                     & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                        >> 5U)) 
                                                    + 
                                                    ((1U 
                                                      & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                         >> 6U)) 
                                                     + 
                                                     ((1U 
                                                       & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                          >> 7U)) 
                                                      + 
                                                      ((1U 
                                                        & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                           >> 8U)) 
                                                       + 
                                                       ((1U 
                                                         & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                            >> 9U)) 
                                                        + 
                                                        ((1U 
                                                          & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                             >> 0x0000000aU)) 
                                                         + 
                                                         ((1U 
                                                           & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                              >> 0x0000000bU)) 
                                                          + 
                                                          ((1U 
                                                            & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                               >> 0x0000000cU)) 
                                                           + 
                                                           ((1U 
                                                             & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                >> 0x0000000dU)) 
                                                            + 
                                                            ((1U 
                                                              & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                 >> 0x0000000eU)) 
                                                             + 
                                                             ((1U 
                                                               & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                  >> 0x0000000fU)) 
                                                              + 
                                                              ((1U 
                                                                & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                   >> 0x00000010U)) 
                                                               + 
                                                               ((1U 
                                                                 & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                    >> 0x00000011U)) 
                                                                + 
                                                                ((1U 
                                                                  & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                     >> 0x00000012U)) 
                                                                 + 
                                                                 ((1U 
                                                                   & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                      >> 0x00000013U)) 
                                                                  + 
                                                                  ((1U 
                                                                    & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                       >> 0x00000014U)) 
                                                                   + 
                                                                   ((1U 
                                                                     & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                        >> 0x00000015U)) 
                                                                    + 
                                                                    ((1U 
                                                                      & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                         >> 0x00000016U)) 
                                                                     + 
                                                                     ((1U 
                                                                       & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                          >> 0x00000017U)) 
                                                                      + 
                                                                      ((1U 
                                                                        & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                           >> 0x00000018U)) 
                                                                       + 
                                                                       ((1U 
                                                                         & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                            >> 0x00000019U)) 
                                                                        + 
                                                                        ((1U 
                                                                          & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                             >> 0x0000001aU)) 
                                                                         + 
                                                                         ((1U 
                                                                           & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                              >> 0x0000001bU)) 
                                                                          + 
                                                                          ((1U 
                                                                            & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                               >> 0x0000001cU)) 
                                                                           + 
                                                                           ((1U 
                                                                             & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                                >> 0x0000001dU)) 
                                                                            + 
                                                                            ((1U 
                                                                              & (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                                >> 0x0000001eU)) 
                                                                             + 
                                                                             (vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep 
                                                                              >> 0x0000001fU)))))))))))))))))))))))))))))));
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep;
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[0U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tdata[0U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[1U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tdata[1U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[2U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tdata[2U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[3U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tdata[3U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[4U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tdata[4U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[5U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tdata[5U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[6U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tdata[6U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[7U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tdata[7U];
    VL_ASSIGN_W(256, __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result, Vtop__ConstPool__CONST_h9e67c271_0);
    if ((1U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[0U] 
            = ((0xffffff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[0U]) 
               | (0x000000ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[0U]));
    }
    if ((2U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[0U] 
            = ((0xffff00ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[0U]) 
               | (0x0000ff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[0U]));
    }
    if ((4U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[0U] 
            = ((0xff00ffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[0U]) 
               | (0x00ff0000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[0U]));
    }
    if ((8U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[0U] 
            = ((0x00ffffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[0U]) 
               | (0xff000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[0U]));
    }
    if ((0x00000010U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[1U] 
            = ((0xffffff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[1U]) 
               | (0x000000ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[1U]));
    }
    if ((0x00000020U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[1U] 
            = ((0xffff00ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[1U]) 
               | (0x0000ff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[1U]));
    }
    if ((0x00000040U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[1U] 
            = ((0xff00ffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[1U]) 
               | (0x00ff0000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[1U]));
    }
    if ((0x00000080U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[1U] 
            = ((0x00ffffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[1U]) 
               | (0xff000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[1U]));
    }
    if ((0x00000100U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[2U] 
            = ((0xffffff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[2U]) 
               | (0x000000ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[2U]));
    }
    if ((0x00000200U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[2U] 
            = ((0xffff00ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[2U]) 
               | (0x0000ff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[2U]));
    }
    if ((0x00000400U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[2U] 
            = ((0xff00ffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[2U]) 
               | (0x00ff0000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[2U]));
    }
    if ((0x00000800U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[2U] 
            = ((0x00ffffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[2U]) 
               | (0xff000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[2U]));
    }
    if ((0x00001000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[3U] 
            = ((0xffffff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[3U]) 
               | (0x000000ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[3U]));
    }
    if ((0x00002000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[3U] 
            = ((0xffff00ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[3U]) 
               | (0x0000ff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[3U]));
    }
    if ((0x00004000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[3U] 
            = ((0xff00ffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[3U]) 
               | (0x00ff0000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[3U]));
    }
    if ((0x00008000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[3U] 
            = ((0x00ffffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[3U]) 
               | (0xff000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[3U]));
    }
    if ((0x00010000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[4U] 
            = ((0xffffff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[4U]) 
               | (0x000000ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[4U]));
    }
    if ((0x00020000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[4U] 
            = ((0xffff00ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[4U]) 
               | (0x0000ff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[4U]));
    }
    if ((0x00040000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[4U] 
            = ((0xff00ffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[4U]) 
               | (0x00ff0000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[4U]));
    }
    if ((0x00080000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[4U] 
            = ((0x00ffffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[4U]) 
               | (0xff000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[4U]));
    }
    if ((0x00100000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[5U] 
            = ((0xffffff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[5U]) 
               | (0x000000ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[5U]));
    }
    if ((0x00200000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[5U] 
            = ((0xffff00ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[5U]) 
               | (0x0000ff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[5U]));
    }
    if ((0x00400000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[5U] 
            = ((0xff00ffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[5U]) 
               | (0x00ff0000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[5U]));
    }
    if ((0x00800000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[5U] 
            = ((0x00ffffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[5U]) 
               | (0xff000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[5U]));
    }
    if ((0x01000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[6U] 
            = ((0xffffff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[6U]) 
               | (0x000000ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[6U]));
    }
    if ((0x02000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[6U] 
            = ((0xffff00ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[6U]) 
               | (0x0000ff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[6U]));
    }
    if ((0x04000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[6U] 
            = ((0xff00ffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[6U]) 
               | (0x00ff0000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[6U]));
    }
    if ((0x08000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[6U] 
            = ((0x00ffffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[6U]) 
               | (0xff000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[6U]));
    }
    if ((0x10000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[7U] 
            = ((0xffffff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[7U]) 
               | (0x000000ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[7U]));
    }
    if ((0x20000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[7U] 
            = ((0xffff00ffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[7U]) 
               | (0x0000ff00U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[7U]));
    }
    if ((0x40000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[7U] 
            = ((0xff00ffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[7U]) 
               | (0x00ff0000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[7U]));
    }
    if ((__Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__keep 
         >> 0x1fU)) {
        __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[7U] 
            = ((0x00ffffffU & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[7U]) 
               | (0xff000000U & __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__data[7U]));
    }
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[0U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[0U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[1U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[1U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[2U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[2U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[3U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[3U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[4U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[4U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[5U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[5U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[6U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[6U];
    __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[7U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__result[7U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[0U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[0U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[1U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[1U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[2U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[2U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[3U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[3U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[4U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[4U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[5U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[5U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[6U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[6U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[7U] 
        = __Vfunc_fixed_slot_packer_cocotb_top__DOT__dut__DOT__mask_data_with_keep__1__Vfuncout[7U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c 
        = ((IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tready) 
           & (IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tvalid));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c 
        = ((IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tready) 
           & (IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c = 0U;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c = 0U;
    VL_ASSIGN_W(256, vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r;
    if ((1U & (~ ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                    if ((0x80U > (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c = 1U;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[0U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[0U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[1U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[1U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[2U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[2U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[3U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[3U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[4U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[4U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[5U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[5U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[6U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[6U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[7U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[7U];
                    }
                    if ((0x80U <= (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n = 1U;
                    }
                    if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_crc_err_i;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_ecc_err_i;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_trunc_err_i;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_valid_good_i;
                        if ((0x1000U < (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i))) {
                            vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n = 1U;
                        }
                    }
                }
            } else if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c = 0U;
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c = 1U;
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[0U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[0U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[1U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[1U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[2U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[2U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[3U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[3U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[4U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[4U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[5U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[5U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[6U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[6U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[7U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[7U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n = 0U;
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_crc_err_i;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_ecc_err_i;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_trunc_err_i;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_valid_good_i;
                    if ((0x1000U < (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n = 1U;
                    }
                }
            }
            if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r)))) {
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_seq_i;
                }
            }
        }
    }
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r;
    if ((4U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r)))) {
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
                    if ((0xffU == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n = 0U;
                    }
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r)));
                }
            }
            if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n = 0U;
            } else if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
                if ((0xffU == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r)));
                if ((3U == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n = 0U;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n = 0U;
                }
            }
        } else if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
            vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
                = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
            vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
                = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r)));
            if (((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r) 
                 == (0x000000ffU & ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__sample_pad_beats_c) 
                                    - (IData)(1U))))) {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n = 5U;
            }
        }
    } else {
        if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r)));
                    if (((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r) 
                         == (0x000000ffU & ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r) 
                                            - (IData)(1U))))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n 
                            = ((0x80U > (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r))
                                ? 4U : 5U);
                    }
                }
            } else if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r)));
                if ((1U == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n 
                        = ((0U < (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r))
                            ? 3U : 4U);
                }
            }
        } else if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                    if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c)))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n = 0U;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                    }
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n 
                        = ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c)
                            ? 0U : 2U);
                }
            }
        } else if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
            if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c)))) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n = 0U;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                }
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n 
                    = ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c)
                        ? 0U : 2U);
            } else {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n = 1U;
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                    if ((0x80U > (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n 
                            = (0x000000ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r)));
                    }
                    if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                        if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c) {
                            vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n = 0U;
                        }
                    }
                }
            } else if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n = 1U;
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                    if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n = 0U;
                    }
                }
            }
        }
    }
}

void Vtop_axis_stream_if___ico_sequent__TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if__0(Vtop_axis_stream_if* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if__0((&vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if));
        Vtop_axis_stream_if___ico_sequent__TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if__0((&vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if));
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
                                                    ((((~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i__0 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni__0 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni;
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
    // Locals
    VlWide<8>/*255:0*/ __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0;
    VL_ZERO_W(256, __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0);
    CData/*6:0*/ __VdlyDim0__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0;
    __VdlyDim0__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0 = 0;
    CData/*0:0*/ __VdlySet__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0;
    __VdlySet__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0 = 0;
    IData/*31:0*/ __VExpandSel_WordIdx_1;
    IData/*31:0*/ __VExpandSel_LoShift_1;
    CData/*0:0*/ __VExpandSel_Aligned_1;
    IData/*31:0*/ __VExpandSel_HiShift_1;
    IData/*31:0*/ __VExpandSel_HiMask_1;
    // Body
    __VdlySet__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0 = 0U;
    if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni) {
        if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c) {
            __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[0U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[0U];
            __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[1U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[1U];
            __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[2U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[2U];
            __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[3U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[3U];
            __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[4U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[4U];
            __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[5U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[5U];
            __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[6U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[6U];
            __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[7U] 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[7U];
            __VdlyDim0__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0 
                = (0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c));
            __VdlySet__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0 = 1U;
        }
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r 
            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_n;
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r 
            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n;
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r 
            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n;
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r 
            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n;
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r 
            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n;
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r 
            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n;
    } else {
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r = 0U;
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r = 0U;
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r = 0U;
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r = 0U;
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r = 0U;
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r = 0U;
    }
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r 
        = ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni) 
           && (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r 
        = ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni) 
           && (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r 
        = ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni) 
           && (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r 
        = ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni) 
           && (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r 
        = ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni) 
           && (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n));
    if (__VdlySet__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0) {
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r[__VdlyDim0__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0][0U] 
            = __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[0U];
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r[__VdlyDim0__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0][1U] 
            = __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[1U];
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r[__VdlyDim0__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0][2U] 
            = __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[2U];
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r[__VdlyDim0__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0][3U] 
            = __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[3U];
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r[__VdlyDim0__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0][4U] 
            = __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[4U];
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r[__VdlyDim0__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0][5U] 
            = __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[5U];
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r[__VdlyDim0__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0][6U] 
            = __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[6U];
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r[__VdlyDim0__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0][7U] 
            = __VdlyVal__fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r__v0[7U];
    }
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_seq_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_valid_good_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_overflow_err_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c 
        = (0x85U == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__actual_sample_cnt_c 
        = ((0x1000U <= (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r))
            ? 0x00000400U : (0x000007ffU & ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r) 
                                            >> 2U)));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__sample_pad_beats_c 
        = (0x000000ffU & ((IData)(0x80U) - (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r)));
    vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep = 0U;
    vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid = 0U;
    vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tready = 0U;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_seq_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_seq_o;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_valid_good_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_valid_good_o;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_overflow_err_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_overflow_err_o;
    vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast = 0U;
    VL_ASSIGN_W(512, vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c, Vtop__ConstPool__CONST_h93e1b771_0);
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[0U] 
        = (IData)((0x00000001aa551024ULL | (((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r)) 
                                             << 0x0000002aU) 
                                            | (((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r)) 
                                                << 0x00000029U) 
                                               | ((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r)) 
                                                  << 0x00000028U)))));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[1U] 
        = ((0xfffff800U & vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[1U]) 
           | (IData)(((0x00000001aa551024ULL | (((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r)) 
                                                 << 0x0000002aU) 
                                                | (((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r)) 
                                                    << 0x00000029U) 
                                                   | ((QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r)) 
                                                      << 0x00000028U)))) 
                      >> 0x00000020U)));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[1U] 
        = ((0xffffe7ffU & vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[1U]) 
           | (0xfffff800U & (((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r) 
                              << 0x0000000cU) | ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r) 
                                                 << 0x0000000bU))));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[2U] 
        = (IData)((((QData)((IData)((((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__actual_sample_cnt_c) 
                                      << 0x00000010U) 
                                     | (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r)))) 
                    << 0x00000010U) | (QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r))));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[3U] 
        = ((0xffff0000U & vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[3U]) 
           | (IData)(((((QData)((IData)((((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__actual_sample_cnt_c) 
                                          << 0x00000010U) 
                                         | (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r)))) 
                        << 0x00000010U) | (QData)((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r))) 
                      >> 0x00000020U)));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[4U] = 0x000010c0U;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[5U] = 0x00001000U;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[6U] 
        = (0x00000080U | (0xffff0000U & vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c[6U]));
    if ((4U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r)))) {
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep = 0xffffffffU;
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid = 1U;
            }
        } else {
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep = 0xffffffffU;
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid = 1U;
        }
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tkeep 
            = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep;
    } else {
        if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep = 0xffffffffU;
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid = 1U;
        }
        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tkeep 
            = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep;
    }
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tvalid 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_start_o 
        = ((IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid) 
           & (0U == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_done_o 
        = ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c) 
           & (IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid));
    if ((1U & (~ ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r) 
                      >> 1U)))) {
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tready = 1U;
        }
    }
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c 
        = ((IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tready) 
           & (IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid));
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tready 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tready;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c 
        = ((IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tready) 
           & (IData)(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tvalid));
    vlSelfRef.slot_seq_o = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_seq_o;
    vlSelfRef.slot_valid_good_o = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_valid_good_o;
    vlSelfRef.slot_overflow_err_o = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_overflow_err_o;
    if ((4U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r)))) {
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c;
            }
        } else {
            vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast 
                = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c;
        }
    } else if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
        vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast 
            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c;
    }
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tlast 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast;
    VL_ASSIGN_W(256, vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.m_axis_tkeep = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tkeep;
    vlSelfRef.m_axis_tvalid = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tvalid;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_start_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_start_o;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_done_o 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_done_o;
    vlSelfRef.s_axis_tready = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tready;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c = 0U;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c = 0U;
    VL_ASSIGN_W(256, vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r;
    if ((1U & (~ ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                    if ((0x80U > (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c = 1U;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[0U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[0U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[1U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[1U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[2U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[2U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[3U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[3U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[4U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[4U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[5U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[5U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[6U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[6U];
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[7U] 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[7U];
                    }
                    if ((0x80U <= (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n = 1U;
                    }
                    if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_crc_err_i;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_ecc_err_i;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_trunc_err_i;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n 
                            = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_valid_good_i;
                        if ((0x1000U < (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i))) {
                            vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n = 1U;
                        }
                    }
                }
            } else if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c = 0U;
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c = 1U;
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[0U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[0U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[1U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[1U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[2U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[2U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[3U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[3U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[4U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[4U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[5U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[5U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[6U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[6U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c[7U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c[7U];
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n = 0U;
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_crc_err_i;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_ecc_err_i;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_trunc_err_i;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_valid_good_i;
                    if ((0x1000U < (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n = 1U;
                    }
                }
            }
            if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r)))) {
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_n 
                        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_seq_i;
                }
            }
        }
    }
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r;
    if ((4U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r)))) {
                VL_ASSIGN_W(256, vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
                    if ((0xffU == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n = 0U;
                    }
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r)));
                }
            }
            if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n = 0U;
            } else if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
                if ((0xffU == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n = 0U;
                }
            }
        } else {
            VL_ASSIGN_W(256, vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
            if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r)));
                    if ((3U == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n = 0U;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n = 0U;
                    }
                }
            } else if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r)));
                if (((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r) 
                     == (0x000000ffU & ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__sample_pad_beats_c) 
                                        - (IData)(1U))))) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n = 5U;
                }
            }
        }
    } else {
        if ((2U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            __VExpandSel_WordIdx_1 = (0x0000000fU & 
                                      (VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r), 8U) 
                                       >> 5U));
            __VExpandSel_LoShift_1 = (0x0000001fU & 
                                      VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r), 8U));
            __VExpandSel_Aligned_1 = (0U == __VExpandSel_LoShift_1);
            if (__VExpandSel_Aligned_1) {
                __VExpandSel_HiShift_1 = 0U;
                __VExpandSel_HiMask_1 = 0U;
            } else {
                __VExpandSel_HiShift_1 = ((IData)(0x00000020U) 
                                          - __VExpandSel_LoShift_1);
                __VExpandSel_HiMask_1 = 0xffffffffU;
            }
            if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[0U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                    [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][0U];
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[1U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                    [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][1U];
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[2U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                    [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][2U];
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[3U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                    [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][3U];
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[4U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                    [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][4U];
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[5U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                    [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][5U];
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[6U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                    [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][6U];
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[7U] 
                    = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r
                    [(0x0000007fU & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))][7U];
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r)));
                    if (((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r) 
                         == (0x000000ffU & ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r) 
                                            - (IData)(1U))))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n 
                            = ((0x80U > (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r))
                                ? 4U : 5U);
                    }
                }
            } else {
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[0U] 
                    = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                         [((IData)(1U) + __VExpandSel_WordIdx_1)] 
                         << __VExpandSel_HiShift_1) 
                        & __VExpandSel_HiMask_1) | 
                       (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                        [__VExpandSel_WordIdx_1] >> __VExpandSel_LoShift_1));
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[1U] 
                    = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                         [((IData)(2U) + __VExpandSel_WordIdx_1)] 
                         << __VExpandSel_HiShift_1) 
                        & __VExpandSel_HiMask_1) | 
                       (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                        [((IData)(1U) + __VExpandSel_WordIdx_1)] 
                        >> __VExpandSel_LoShift_1));
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[2U] 
                    = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                         [((IData)(3U) + __VExpandSel_WordIdx_1)] 
                         << __VExpandSel_HiShift_1) 
                        & __VExpandSel_HiMask_1) | 
                       (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                        [((IData)(2U) + __VExpandSel_WordIdx_1)] 
                        >> __VExpandSel_LoShift_1));
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[3U] 
                    = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                         [((IData)(4U) + __VExpandSel_WordIdx_1)] 
                         << __VExpandSel_HiShift_1) 
                        & __VExpandSel_HiMask_1) | 
                       (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                        [((IData)(3U) + __VExpandSel_WordIdx_1)] 
                        >> __VExpandSel_LoShift_1));
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[4U] 
                    = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                         [((IData)(5U) + __VExpandSel_WordIdx_1)] 
                         << __VExpandSel_HiShift_1) 
                        & __VExpandSel_HiMask_1) | 
                       (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                        [((IData)(4U) + __VExpandSel_WordIdx_1)] 
                        >> __VExpandSel_LoShift_1));
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[5U] 
                    = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                         [((IData)(6U) + __VExpandSel_WordIdx_1)] 
                         << __VExpandSel_HiShift_1) 
                        & __VExpandSel_HiMask_1) | 
                       (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                        [((IData)(5U) + __VExpandSel_WordIdx_1)] 
                        >> __VExpandSel_LoShift_1));
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[6U] 
                    = (((vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                         [((IData)(7U) + __VExpandSel_WordIdx_1)] 
                         << __VExpandSel_HiShift_1) 
                        & __VExpandSel_HiMask_1) | 
                       (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                        [((IData)(6U) + __VExpandSel_WordIdx_1)] 
                        >> __VExpandSel_LoShift_1));
                vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[7U] 
                    = (((((8U <= __VExpandSel_WordIdx_1)
                           ? 0U : vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                          [((IData)(8U) + __VExpandSel_WordIdx_1)]) 
                         << __VExpandSel_HiShift_1) 
                        & __VExpandSel_HiMask_1) | 
                       (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c
                        [((IData)(7U) + __VExpandSel_WordIdx_1)] 
                        >> __VExpandSel_LoShift_1));
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r)));
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r)));
                    if ((1U == (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n 
                            = ((0U < (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r))
                                ? 3U : 4U);
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
            if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                    if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c)))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n = 0U;
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                    }
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n 
                        = ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c)
                            ? 0U : 2U);
                }
            }
        } else if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
            if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                if ((1U & (~ (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c)))) {
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n = 0U;
                    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = 0U;
                }
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n 
                    = ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c)
                        ? 0U : 2U);
            } else {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n = 1U;
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r))) {
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                    if ((0x80U > (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n 
                            = (0x000000ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r)));
                    }
                    if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                        if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c) {
                            vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n = 0U;
                        }
                    }
                }
            } else if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c) {
                vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n = 1U;
                if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i) {
                    if (vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c) {
                        vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n = 0U;
                    }
                }
            }
        }
    }
    vlSelfRef.m_axis_tlast = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tlast;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[0U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[0U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[1U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[1U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[2U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[2U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[3U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[3U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[4U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[4U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[5U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[5U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[6U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[6U];
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[7U] 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata[7U];
    vlSelfRef.slot_start_o = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_start_o;
    vlSelfRef.slot_done_o = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_done_o;
    vlSelfRef.m_axis_tdata[0U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[0U];
    vlSelfRef.m_axis_tdata[1U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[1U];
    vlSelfRef.m_axis_tdata[2U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[2U];
    vlSelfRef.m_axis_tdata[3U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[3U];
    vlSelfRef.m_axis_tdata[4U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[4U];
    vlSelfRef.m_axis_tdata[5U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[5U];
    vlSelfRef.m_axis_tdata[6U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[6U];
    vlSelfRef.m_axis_tdata[7U] = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata[7U];
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
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/fixed_slot_packer_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 100 tries");
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
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/fixed_slot_packer_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/fixed_slot_packer_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.cfg_drop_invalid_pkt_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("cfg_drop_invalid_pkt_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.pkt_start_i & 0xfeU)))) {
        Verilated::overWidthError("pkt_start_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.pkt_done_i & 0xfeU)))) {
        Verilated::overWidthError("pkt_done_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.pkt_crc_err_i & 0xfeU)))) {
        Verilated::overWidthError("pkt_crc_err_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.pkt_ecc_err_i & 0xfeU)))) {
        Verilated::overWidthError("pkt_ecc_err_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.pkt_trunc_err_i & 0xfeU)))) {
        Verilated::overWidthError("pkt_trunc_err_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.pkt_valid_good_i & 0xfeU)))) {
        Verilated::overWidthError("pkt_valid_good_i");
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
