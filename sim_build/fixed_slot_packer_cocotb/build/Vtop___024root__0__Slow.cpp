// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i__0 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni__0 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop_axis_stream_if___eval_initial__TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if(Vtop_axis_stream_if* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    Vtop_axis_stream_if___eval_initial__TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if((&vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if));
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __Vfunc_is_pow2_u__2__Vfuncout;
    __Vfunc_is_pow2_u__2__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_pow2_u__2__value;
    __Vfunc_is_pow2_u__2__value = 0;
    CData/*0:0*/ __Vfunc_is_pow2_u__3__Vfuncout;
    __Vfunc_is_pow2_u__3__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_pow2_u__3__value;
    __Vfunc_is_pow2_u__3__value = 0;
    // Body
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_bytes_o = 0x10c0U;
    if (VL_UNLIKELY(((1U & (~ ([&]() {
                                __Vfunc_is_pow2_u__2__value = 0x00000020U;
                                {
                                    __Vfunc_is_pow2_u__2__Vfuncout = 0U;
                                    if ((0U == __Vfunc_is_pow2_u__2__value)) {
                                        __Vfunc_is_pow2_u__2__Vfuncout = 0U;
                                        goto __Vlabel0;
                                    }
                                    __Vfunc_is_pow2_u__2__Vfuncout 
                                        = (0U == (__Vfunc_is_pow2_u__2__value 
                                                  & (__Vfunc_is_pow2_u__2__value 
                                                     - (IData)(1U))));
                                    __Vlabel0: ;
                                }
                            }(), (IData)(__Vfunc_is_pow2_u__2__Vfuncout))))))) {
        VL_WRITEF_NX("[%0t] %%Error: fixed_slot_packer.sv:552: Assertion failed in %Nfixed_slot_packer_cocotb_top.dut.g_static_checks: %Nfixed_slot_packer_cocotb_top.dut.g_static_checks static assertion failed: AXIS_BEAT_BYTES must be a power of two\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/fixed_slot_packer.sv", 552, "");
        VL_WRITEF_NX("[%0t] %%Fatal: fixed_slot_packer.sv:552: Assertion failed in %Nfixed_slot_packer_cocotb_top.dut.g_static_checks\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/fixed_slot_packer.sv", 552, "", false);
    }
    if (VL_UNLIKELY(((1U & (~ ([&]() {
                                __Vfunc_is_pow2_u__3__value = 0x00000040U;
                                {
                                    __Vfunc_is_pow2_u__3__Vfuncout = 0U;
                                    if ((0U == __Vfunc_is_pow2_u__3__value)) {
                                        __Vfunc_is_pow2_u__3__Vfuncout = 0U;
                                        goto __Vlabel1;
                                    }
                                    __Vfunc_is_pow2_u__3__Vfuncout 
                                        = (0U == (__Vfunc_is_pow2_u__3__value 
                                                  & (__Vfunc_is_pow2_u__3__value 
                                                     - (IData)(1U))));
                                    __Vlabel1: ;
                                }
                            }(), (IData)(__Vfunc_is_pow2_u__3__Vfuncout))))))) {
        VL_WRITEF_NX("[%0t] %%Error: fixed_slot_packer.sv:570: Assertion failed in %Nfixed_slot_packer_cocotb_top.dut.g_static_checks: %Nfixed_slot_packer_cocotb_top.dut.g_static_checks static assertion failed: ALIGN_BYTES must be a power of two\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/fixed_slot_packer.sv", 570, "");
        VL_WRITEF_NX("[%0t] %%Fatal: fixed_slot_packer.sv:570: Assertion failed in %Nfixed_slot_packer_cocotb_top.dut.g_static_checks\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/fixed_slot_packer.sv", 570, "", false);
    }
    vlSelfRef.slot_bytes_o = 0x10c0U;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_bytes_o = 0x10c0U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/fixed_slot_packer_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtop___024root___eval_triggers_vec__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers_vec__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VExpandSel_WordIdx_1;
    IData/*31:0*/ __VExpandSel_LoShift_1;
    CData/*0:0*/ __VExpandSel_Aligned_1;
    IData/*31:0*/ __VExpandSel_HiShift_1;
    IData/*31:0*/ __VExpandSel_HiMask_1;
    // Body
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tlast 
        = vlSelfRef.s_axis_tlast;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tuser 
        = vlSelfRef.s_axis_tuser;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tuser 
        = vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tuser;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__clk_i 
        = vlSelfRef.clk_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__rst_ni 
        = vlSelfRef.rst_ni;
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
    vlSelfRef.m_axis_tuser = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tuser;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__clk_i;
    vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni 
        = vlSelfRef.fixed_slot_packer_cocotb_top__DOT__rst_ni;
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

void Vtop_axis_stream_if___ico_sequent__TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if__0((&vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if));
        Vtop_axis_stream_if___ico_sequent__TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if__0((&vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if));
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge fixed_slot_packer_cocotb_top.dut.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge fixed_slot_packer_cocotb_top.dut.rst_ni)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11908517815223722933ull);
    vlSelf->rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3161515032326629241ull);
    vlSelf->cfg_drop_invalid_pkt_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12153301888773253218ull);
    vlSelf->pkt_start_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11786318264182956706ull);
    vlSelf->pkt_done_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12477233471788383746ull);
    vlSelf->pkt_bytes_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6370866919695504715ull);
    vlSelf->pkt_seq_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1979998208696001308ull);
    vlSelf->pkt_crc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16138859533001290052ull);
    vlSelf->pkt_ecc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9323978491860304916ull);
    vlSelf->pkt_trunc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4426150129205143664ull);
    vlSelf->pkt_valid_good_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1676310650812813290ull);
    vlSelf->slot_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16414201820509555848ull);
    vlSelf->slot_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7037026714158015159ull);
    vlSelf->slot_bytes_o = 4288U;
    ;
    vlSelf->slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4069635512002436434ull);
    vlSelf->slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3207059873615457475ull);
    vlSelf->slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4615952249938211109ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->s_axis_tdata, __VscopeHash, 6413635470731068441ull);
    vlSelf->s_axis_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6494536958632130591ull);
    vlSelf->s_axis_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7678217216116487763ull);
    vlSelf->s_axis_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12236809265553805965ull);
    vlSelf->s_axis_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 750346815483064505ull);
    vlSelf->s_axis_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8856106712201831047ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->m_axis_tdata, __VscopeHash, 8796747702141925029ull);
    vlSelf->m_axis_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3915191572914464546ull);
    vlSelf->m_axis_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11050073027672567459ull);
    vlSelf->m_axis_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5619517951140101778ull);
    vlSelf->m_axis_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3666489172703407315ull);
    vlSelf->m_axis_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4289079287625486832ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17328753304546715881ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 579259570397363690ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__cfg_drop_invalid_pkt_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4808775857070589496ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__pkt_start_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4881470569710298041ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__pkt_done_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15450769548800900844ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__pkt_bytes_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13005451029652882368ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__pkt_seq_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7951710378807066938ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__pkt_crc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6559938159288813121ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__pkt_ecc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10250734500989034631ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__pkt_trunc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4851426435766506406ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__pkt_valid_good_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12746007298724866212ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__slot_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4254224290477889949ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__slot_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17926310250121074610ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__slot_bytes_o = 4288U;
    ;
    vlSelf->fixed_slot_packer_cocotb_top__DOT__slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12834599285241380273ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4549549791541492911ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 403417845263257032ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->fixed_slot_packer_cocotb_top__DOT__s_axis_tdata, __VscopeHash, 3373635457303875145ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__s_axis_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4691083586675491143ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__s_axis_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14818928037134251768ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__s_axis_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12552112223288851854ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__s_axis_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3574292764068597961ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__s_axis_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14136744828106083863ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->fixed_slot_packer_cocotb_top__DOT__m_axis_tdata, __VscopeHash, 400827551684054856ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__m_axis_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1809352344076799107ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__m_axis_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10240382446434990416ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__m_axis_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4530284217239868221ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__m_axis_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18092945007496297139ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__m_axis_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14272578538667381567ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11531228864550346632ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8125904254288649005ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cfg_drop_invalid_pkt_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14907558062215771943ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_start_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8928652881970057200ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7045897819477314141ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8450954632953979945ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_seq_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11556127351684067436ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_crc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13522679034310885490ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_ecc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12729097199143307087ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_trunc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7146205822840121949ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_valid_good_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18186272142780982431ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16013848231256762882ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16609003835018429415ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_bytes_o = 4288U;
    ;
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16006305510967369060ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5112599824690001859ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2678903321459957948ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1494382412085182184ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18062575826074922151ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12259967530553099435ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1580129167166873456ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12736483294610386356ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14773271962893597165ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1737606930145844949ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11056131337641937737ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14578090147050114338ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12652775158578266877ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5676993605454872245ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8255118664846264518ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11724017547754206885ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16625766006229242726ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17922872148761096900ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18042515610198968366ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15138441564201206522ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9739749734747579952ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 327768317172169926ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1021427919954191644ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13164132780493892698ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11634584754171429470ull);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(256, vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r[__Vi0], __VscopeHash, 7362920573568701060ull);
    }
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12936329619050099208ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8513300679104137274ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__keep_bytes_c = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 18376690768367717887ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c, __VscopeHash, 7782498819162284422ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4828164118088247703ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7893937062508937860ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__sample_pad_beats_c = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16860409896017678236ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c, __VscopeHash, 8789288463810789056ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__actual_sample_cnt_c = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 7698990901949665326ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2817926788723513930ull);
    vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16259674762122899702ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c, __VscopeHash, 15120306375683494305ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
