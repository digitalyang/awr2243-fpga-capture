// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i__0 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni__0 
        = vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
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
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/csi_packet_extractor_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if__0((&vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if));
        Vtop_axis_stream_if___ico_sequent__TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if__0((&vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if));
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge csi_packet_extractor_cocotb_top.dut.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge csi_packet_extractor_cocotb_top.dut.rst_ni)\n");
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
    vlSelf->cfg_vc_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9206215874403365532ull);
    vlSelf->cfg_dt_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13245585909817139736ull);
    vlSelf->cfg_vc_i = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13016925778563225337ull);
    vlSelf->cfg_dt_i = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 7205747298248696774ull);
    vlSelf->pkt_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17153074482495418097ull);
    vlSelf->pkt_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 81805878517030488ull);
    vlSelf->pkt_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5220079347674660263ull);
    vlSelf->pkt_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16636537043600033524ull);
    vlSelf->pkt_bytes_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9382384257393170247ull);
    vlSelf->pkt_crc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7676084566834659157ull);
    vlSelf->pkt_ecc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1806629213507780402ull);
    vlSelf->pkt_trunc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13517678886990542437ull);
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
    vlSelf->csi_packet_extractor_cocotb_top__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6266567689891140252ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8819744893862608620ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__cfg_vc_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7824011274401497903ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__cfg_dt_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16985593438206877355ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__cfg_vc_i = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9640380017348109157ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__cfg_dt_i = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 11594384025212225473ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__pkt_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14713542756847367649ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__pkt_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15492140921581320321ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__pkt_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15488482046022279245ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__pkt_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9531418759026685863ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__pkt_bytes_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8336346200668999844ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__pkt_crc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13130476348852662579ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__pkt_ecc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2802992158225884441ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__pkt_trunc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7194235632239191962ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->csi_packet_extractor_cocotb_top__DOT__s_axis_tdata, __VscopeHash, 5575116259513784189ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__s_axis_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2835798392793148914ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__s_axis_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5407595462460754277ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__s_axis_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3523793991244122272ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__s_axis_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16842088145828013130ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__s_axis_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6817646730249910331ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->csi_packet_extractor_cocotb_top__DOT__m_axis_tdata, __VscopeHash, 3288307933187752496ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__m_axis_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10495856726741410863ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__m_axis_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13538921541623309832ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__m_axis_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14844806871850808909ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__m_axis_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14015998320636465885ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__m_axis_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12697144549855758455ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11627372825797235636ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3935956962861633916ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8656900715554722290ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9635170795399671492ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_i = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 685371729527998378ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_i = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8890833629656596915ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12981063628219652153ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15711917812197544635ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5834743845669857724ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5772923982759110595ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6215949687160753209ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2884326679433251690ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3417736594558015652ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13415785665277994205ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11671327049444707642ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17897114703576460019ull);
    VL_SCOPED_RAND_RESET_W(353, vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r, __VscopeHash, 17380190586025743850ull);
    VL_SCOPED_RAND_RESET_W(353, vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n, __VscopeHash, 4790460814290332845ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2311880227256675343ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17677741247130030650ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16578394874040737860ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9916855203764139920ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13663243556911231844ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7701723893873448616ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17394365112935321217ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6528154266582786727ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7385829834552856818ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3886200327632986542ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15529415958063682731ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3549762902014149829ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14271107995440802394ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16408502673458879006ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3997954410939626765ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17054446598737621233ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14376024229975094372ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 1946827552322419140ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_vc_c = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7645712817301453157ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_dt_c = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 5233882854357180328ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8178795445152501369ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_crc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1371375984221914089ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_ecc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11617356487056765614ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16028879505122961444ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_crc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13429604039479936925ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_ecc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8303392189981047655ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16858066119152892032ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13219783016732191491ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2995705557169571306ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11416293346914191588ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11576908576495131866ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3513342083119879207ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12302226471448659708ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3613526141920042996ull);
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h503bf3ac__0 = 0;
    vlSelf->csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h5ac0cf88__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
