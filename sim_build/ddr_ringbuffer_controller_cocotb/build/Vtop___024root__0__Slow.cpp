// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__clk_i__0 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rst_ni__0 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rst_ni;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk1__DOT__align_mask_addr_c = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 8345885611929070441ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk1__DOT__align_mask_size_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14510372966299748087ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__beat_valid_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 16221402521779633153ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 886078262513539159ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__last_beat_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4281940773833945788ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__lane_offset_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 991320156015350871ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__slot_byte_index_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3279491942544202666ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7641605899603864260ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_present_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1120161686126136823ull);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __Vfunc_is_pow2_u__21__Vfuncout;
    __Vfunc_is_pow2_u__21__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_pow2_u__21__value;
    __Vfunc_is_pow2_u__21__value = 0;
    CData/*0:0*/ __Vfunc_is_pow2_u__22__Vfuncout;
    __Vfunc_is_pow2_u__22__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_pow2_u__22__value;
    __Vfunc_is_pow2_u__22__value = 0;
    // Body
    if (VL_UNLIKELY(((1U & (~ ([&]() {
                                __Vfunc_is_pow2_u__21__value = 0x00000020U;
                                {
                                    __Vfunc_is_pow2_u__21__Vfuncout = 0U;
                                    if ((0U == __Vfunc_is_pow2_u__21__value)) {
                                        __Vfunc_is_pow2_u__21__Vfuncout = 0U;
                                        goto __Vlabel0;
                                    }
                                    __Vfunc_is_pow2_u__21__Vfuncout 
                                        = (0U == (__Vfunc_is_pow2_u__21__value 
                                                  & (__Vfunc_is_pow2_u__21__value 
                                                     - (IData)(1U))));
                                    __Vlabel0: ;
                                }
                            }(), (IData)(__Vfunc_is_pow2_u__21__Vfuncout))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ddr_ringbuffer_controller.sv:1263: Assertion failed in %Nddr_ringbuffer_controller_cocotb_top.dut.g_static_checks: %Nddr_ringbuffer_controller_cocotb_top.dut.g_static_checks static assertion failed: AXI beat bytes must be power of two\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/ddr_ringbuffer_controller.sv", 1263, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ddr_ringbuffer_controller.sv:1263: Assertion failed in %Nddr_ringbuffer_controller_cocotb_top.dut.g_static_checks\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/ddr_ringbuffer_controller.sv", 1263, "", false);
    }
    if (VL_UNLIKELY(((1U & (~ ([&]() {
                                __Vfunc_is_pow2_u__22__value = 0x00000020U;
                                {
                                    __Vfunc_is_pow2_u__22__Vfuncout = 0U;
                                    if ((0U == __Vfunc_is_pow2_u__22__value)) {
                                        __Vfunc_is_pow2_u__22__Vfuncout = 0U;
                                        goto __Vlabel1;
                                    }
                                    __Vfunc_is_pow2_u__22__Vfuncout 
                                        = (0U == (__Vfunc_is_pow2_u__22__value 
                                                  & (__Vfunc_is_pow2_u__22__value 
                                                     - (IData)(1U))));
                                    __Vlabel1: ;
                                }
                            }(), (IData)(__Vfunc_is_pow2_u__22__Vfuncout))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ddr_ringbuffer_controller.sv:1264: Assertion failed in %Nddr_ringbuffer_controller_cocotb_top.dut.g_static_checks: %Nddr_ringbuffer_controller_cocotb_top.dut.g_static_checks static assertion failed: ADDR_ALIGN_BYTES must be power of two\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/ddr_ringbuffer_controller.sv", 1264, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ddr_ringbuffer_controller.sv:1264: Assertion failed in %Nddr_ringbuffer_controller_cocotb_top.dut.g_static_checks\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/ddr_ringbuffer_controller.sv", 1264, "", false);
    }
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
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/ddr_ringbuffer_controller_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
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

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    QData/*33:0*/ __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__base_addr;
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__base_addr = 0;
    IData/*16:0*/ __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__ring_size_bytes;
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__ring_size_bytes = 0;
    QData/*33:0*/ __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__curr_addr;
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__curr_addr = 0;
    IData/*16:0*/ __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__advance_bytes;
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__advance_bytes = 0;
    // Body
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tuser 
        = vlSelfRef.s_axis_slot_tuser;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_rd_state_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_state_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_beats_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_sent_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__clk_i 
        = vlSelfRef.clk_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rst_ni 
        = vlSelfRef.rst_ni;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_valid_good_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_overflow_err_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_addr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_seq_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__empty_o 
        = (0U == vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_r);
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tdata[0U] 
        = vlSelfRef.s_axis_slot_tdata[0U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tdata[1U] 
        = vlSelfRef.s_axis_slot_tdata[1U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tdata[2U] 
        = vlSelfRef.s_axis_slot_tdata[2U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tdata[3U] 
        = vlSelfRef.s_axis_slot_tdata[3U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tdata[4U] 
        = vlSelfRef.s_axis_slot_tdata[4U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tdata[5U] 
        = vlSelfRef.s_axis_slot_tdata[5U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tdata[6U] 
        = vlSelfRef.s_axis_slot_tdata[6U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tdata[7U] 
        = vlSelfRef.s_axis_slot_tdata[7U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tvalid 
        = vlSelfRef.s_axis_slot_tvalid;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tlast 
        = vlSelfRef.s_axis_slot_tlast;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awready 
        = vlSelfRef.m_axi_awready;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wready 
        = vlSelfRef.m_axi_wready;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_bresp 
        = vlSelfRef.m_axi_bresp;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_bvalid 
        = vlSelfRef.m_axi_bvalid;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arready 
        = vlSelfRef.m_axi_arready;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[0U] 
        = vlSelfRef.m_axi_rdata[0U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[1U] 
        = vlSelfRef.m_axi_rdata[1U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[2U] 
        = vlSelfRef.m_axi_rdata[2U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[3U] 
        = vlSelfRef.m_axi_rdata[3U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[4U] 
        = vlSelfRef.m_axi_rdata[4U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[5U] 
        = vlSelfRef.m_axi_rdata[5U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[6U] 
        = vlSelfRef.m_axi_rdata[6U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata[7U] 
        = vlSelfRef.m_axi_rdata[7U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rresp 
        = vlSelfRef.m_axi_rresp;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rlast 
        = vlSelfRef.m_axi_rlast;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rvalid 
        = vlSelfRef.m_axi_rvalid;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_enable_i 
        = vlSelfRef.cfg_enable_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_allow_overwrite_i 
        = vlSelfRef.cfg_allow_overwrite_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_drop_on_no_space_i 
        = vlSelfRef.cfg_drop_on_no_space_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_start_i 
        = vlSelfRef.slot_start_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_done_i 
        = vlSelfRef.slot_done_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_seq_i 
        = vlSelfRef.slot_seq_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_valid_good_i 
        = vlSelfRef.slot_valid_good_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_overflow_err_i 
        = vlSelfRef.slot_overflow_err_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_req_i 
        = vlSelfRef.rd_slot_req_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_consume_i 
        = vlSelfRef.rd_consume_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_busy_o 
        = ((0U != (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r)) 
           | (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_drop_invalid_slot_i 
        = vlSelfRef.cfg_drop_invalid_slot_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_invalid_c 
        = (1U & ((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r)) 
                 | ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_r) 
                    | ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r) 
                       | ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_r) 
                          | (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_r))))));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_full_c 
        = (8U == (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_r));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tkeep 
        = vlSelfRef.s_axis_slot_tkeep;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tready 
        = vlSelfRef.m_axis_rd_tready;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_bytes_i 
        = vlSelfRef.slot_bytes_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_ring_base_addr_i 
        = vlSelfRef.cfg_ring_base_addr_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c 
        = (0U == (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_r));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_ring_size_bytes_i 
        = vlSelfRef.cfg_ring_size_bytes_i;
    vlSelfRef.dbg_rd_state_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_rd_state_o;
    vlSelfRef.dbg_wr_state_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_state_o;
    vlSelfRef.dbg_wr_burst_beats_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_beats_o;
    vlSelfRef.dbg_wr_burst_sent_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_sent_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__clk_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__clk_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rst_ni 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rst_ni;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_bytes_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__used_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_bytes_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_valid_good_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_valid_good_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_overflow_err_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_overflow_err_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_addr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_addr_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_seq_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_seq_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__commit_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__committed_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_bytes_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__empty_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__empty_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wrap_count_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__overflow_count_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__drop_count_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_cfg_align_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_no_space_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_slot_proto_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_slot_too_large_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_axi_wr_resp_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_axi_rd_resp_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_illegal_read_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_enable_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_enable_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_allow_overwrite_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_allow_overwrite_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_drop_on_no_space_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_drop_on_no_space_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_start_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_start_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_done_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_done_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_seq_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_seq_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_valid_good_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_valid_good_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_overflow_err_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_overflow_err_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_req_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_req_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_consume_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_consume_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_busy_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_busy_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_drop_invalid_slot_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_drop_invalid_slot_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_bytes_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__slot_bytes_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_ring_base_addr_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_o 
        = (1U & (~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c)));
    if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c) {
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_alloc_bytes_c = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c = 0ULL;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_seq_c = 0U;
    } else {
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_alloc_bytes_c 
            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_alloc_bytes_r
            [vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r];
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c 
            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r
            [vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r];
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c 
            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_bytes_r
            [vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r];
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_seq_c 
            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_seq_r
            [vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r];
    }
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_valid_good_c 
        = ((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c)) 
           & vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_valid_good_r
           [vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r]);
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_overflow_err_c 
        = ((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c)) 
           & vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_overflow_err_r
           [vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r]);
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__cfg_ring_size_bytes_i;
    vlSelfRef.wr_slot_bytes_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_bytes_o;
    vlSelfRef.used_bytes_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__used_bytes_o;
    vlSelfRef.wr_ptr_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_ptr_o;
    vlSelfRef.wr_slot_valid_good_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_valid_good_o;
    vlSelfRef.wr_slot_overflow_err_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_overflow_err_o;
    vlSelfRef.wr_slot_addr_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_addr_o;
    vlSelfRef.wr_slot_seq_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_seq_o;
    vlSelfRef.rd_ptr_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_ptr_o;
    vlSelfRef.commit_ptr_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__commit_ptr_o;
    vlSelfRef.committed_bytes_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__committed_bytes_o;
    vlSelfRef.empty_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__empty_o;
    vlSelfRef.wrap_count_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wrap_count_o;
    vlSelfRef.overflow_count_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__overflow_count_o;
    vlSelfRef.drop_count_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__drop_count_o;
    vlSelfRef.err_cfg_align_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_cfg_align_o;
    vlSelfRef.err_no_space_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_no_space_o;
    vlSelfRef.err_slot_proto_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_slot_proto_o;
    vlSelfRef.err_slot_too_large_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_slot_too_large_o;
    vlSelfRef.err_axi_wr_resp_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_axi_wr_resp_o;
    vlSelfRef.err_axi_rd_resp_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_axi_rd_resp_o;
    vlSelfRef.err_illegal_read_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__err_illegal_read_o;
    vlSelfRef.rd_busy_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_busy_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_drop_now_c 
        = ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_drop_invalid_slot_i) 
           & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_invalid_c));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_effective_bytes_in_c 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_bytes_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_valid_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_seq_c;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_valid_good_c;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_err_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_overflow_err_c;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk1__DOT__align_mask_addr_c = 0x000000000000001fULL;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk1__DOT__align_mask_size_c = 0x0000001fU;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_ok_c 
        = ((((0U != vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i) 
             & (0x00010000U >= vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i)) 
            & (0ULL == (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i 
                        & vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk1__DOT__align_mask_addr_c))) 
           & (0U == (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i 
                     & vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk1__DOT__align_mask_size_c)));
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__advance_bytes 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r;
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__curr_addr 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r;
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__ring_size_bytes 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i;
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__base_addr 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
    {
        vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__Vfuncout = 0;
        vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__ring_end_addr = 0;
        vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__to_end_bytes = 0;
        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__ring_end_addr 
            = (0x00000003ffffffffULL & (__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__base_addr 
                                        + (QData)((IData)(__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__ring_size_bytes))));
        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__to_end_bytes 
            = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__ring_end_addr) 
                              - (IData)(__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__curr_addr)));
        if ((__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__advance_bytes 
             < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__to_end_bytes)) {
            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__Vfuncout 
                = (0x00000003ffffffffULL & (__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__curr_addr 
                                            + (QData)((IData)(__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__advance_bytes))));
            goto __Vlabel0;
        } else if ((__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__advance_bytes 
                    == vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__to_end_bytes)) {
            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__Vfuncout 
                = __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__base_addr;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__Vfuncout 
            = (0x00000003ffffffffULL & (__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__base_addr 
                                        + ((QData)((IData)(__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__advance_bytes)) 
                                           - (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__to_end_bytes)))));
        __Vlabel0: ;
    }
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__next_wr_ptr_c 
        = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__Vfuncout;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_c 
        = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i 
                          - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_r));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_end_c 
        = (0x0001ffffU & (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i) 
                           + vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i) 
                          - (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r)));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_alloc_bytes_in_c 
        = (0x0001ffffU & ([&]() {
                vlSelfRef.__Vfunc_align_up_u__1__align_bytes = 0x00000020U;
                vlSelfRef.__Vfunc_align_up_u__1__value 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_effective_bytes_in_c;
                {
                    vlSelfRef.__Vfunc_align_up_u__1__Vfuncout = 0U;
                    if ((1U >= vlSelfRef.__Vfunc_align_up_u__1__align_bytes)) {
                        vlSelfRef.__Vfunc_align_up_u__1__Vfuncout 
                            = vlSelfRef.__Vfunc_align_up_u__1__value;
                        goto __Vlabel1;
                    }
                    vlSelfRef.__Vfunc_align_up_u__1__Vfuncout 
                        = (([&]() {
                                vlSelfRef.__Vfunc_ceil_div_u__2__denominator 
                                    = vlSelfRef.__Vfunc_align_up_u__1__align_bytes;
                                vlSelfRef.__Vfunc_ceil_div_u__2__numerator 
                                    = vlSelfRef.__Vfunc_align_up_u__1__value;
                                {
                                    vlSelfRef.__Vfunc_ceil_div_u__2__Vfuncout = 0U;
                                    if ((0U == vlSelfRef.__Vfunc_ceil_div_u__2__denominator)) {
                                        vlSelfRef.__Vfunc_ceil_div_u__2__Vfuncout = 0U;
                                        goto __Vlabel2;
                                    }
                                    vlSelfRef.__Vfunc_ceil_div_u__2__Vfuncout 
                                        = VL_DIV_III(32, 
                                                     ((vlSelfRef.__Vfunc_ceil_div_u__2__numerator 
                                                       + vlSelfRef.__Vfunc_ceil_div_u__2__denominator) 
                                                      - (IData)(1U)), vlSelfRef.__Vfunc_ceil_div_u__2__denominator);
                                    __Vlabel2: ;
                                }
                            }(), vlSelfRef.__Vfunc_ceil_div_u__2__Vfuncout) 
                           * vlSelfRef.__Vfunc_align_up_u__1__align_bytes);
                    __Vlabel1: ;
                }
            }(), vlSelfRef.__Vfunc_align_up_u__1__Vfuncout));
    vlSelfRef.rd_slot_valid_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_valid_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_addr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_seq_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_valid_good_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_overflow_err_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_err_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_c;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__full_o 
        = ((0U == vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_c) 
           | (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_full_c));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__almost_full_o 
        = ((0x00001000U >= vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_c) 
           | (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_full_c));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_can_fit_c 
        = ((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_full_c)) 
           & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r 
              <= vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_c));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__next_wr_wrap_c 
        = (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r 
           >= vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_end_c);
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__first_seg_bytes_c 
        = ((vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r 
            <= vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_end_c)
            ? vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r
            : vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_end_c);
    vlSelfRef.rd_slot_addr_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_addr_o;
    vlSelfRef.rd_slot_bytes_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_bytes_o;
    vlSelfRef.rd_slot_seq_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_seq_o;
    vlSelfRef.rd_slot_valid_good_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_valid_good_o;
    vlSelfRef.rd_slot_overflow_err_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_overflow_err_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__free_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__full_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__full_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__almost_full_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__almost_full_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__second_seg_bytes_c 
        = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r 
                          - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__first_seg_bytes_c));
    vlSelfRef.free_bytes_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__free_bytes_o;
    vlSelfRef.full_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__full_o;
    vlSelfRef.almost_full_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__almost_full_o;
}

extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h9e67c271_0;

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[0U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tdata[0U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[1U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tdata[1U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[2U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tdata[2U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[3U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tdata[3U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[4U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tdata[4U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[5U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tdata[5U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[6U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tdata[6U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[7U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tdata[7U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tkeep 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tkeep;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tvalid 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tvalid;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tlast 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tlast;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tuser 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tuser;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_fire_c 
        = ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r) 
           & (IData)(vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tready));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__s_axis_keep_bytes_c 
        = (0x0000003fU & (((1U & vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep) 
                           + (1U & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                    >> 1U))) + (((1U 
                                                  & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                     >> 2U)) 
                                                 + 
                                                 (1U 
                                                  & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                     >> 3U))) 
                                                + (
                                                   (1U 
                                                    & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                       >> 4U)) 
                                                   + 
                                                   ((1U 
                                                     & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                        >> 5U)) 
                                                    + 
                                                    ((1U 
                                                      & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                         >> 6U)) 
                                                     + 
                                                     ((1U 
                                                       & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                          >> 7U)) 
                                                      + 
                                                      ((1U 
                                                        & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                           >> 8U)) 
                                                       + 
                                                       ((1U 
                                                         & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                            >> 9U)) 
                                                        + 
                                                        ((1U 
                                                          & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                             >> 0x0000000aU)) 
                                                         + 
                                                         ((1U 
                                                           & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                              >> 0x0000000bU)) 
                                                          + 
                                                          ((1U 
                                                            & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                               >> 0x0000000cU)) 
                                                           + 
                                                           ((1U 
                                                             & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                >> 0x0000000dU)) 
                                                            + 
                                                            ((1U 
                                                              & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                 >> 0x0000000eU)) 
                                                             + 
                                                             ((1U 
                                                               & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                  >> 0x0000000fU)) 
                                                              + 
                                                              ((1U 
                                                                & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                   >> 0x00000010U)) 
                                                               + 
                                                               ((1U 
                                                                 & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                    >> 0x00000011U)) 
                                                                + 
                                                                ((1U 
                                                                  & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                     >> 0x00000012U)) 
                                                                 + 
                                                                 ((1U 
                                                                   & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                      >> 0x00000013U)) 
                                                                  + 
                                                                  ((1U 
                                                                    & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                       >> 0x00000014U)) 
                                                                   + 
                                                                   ((1U 
                                                                     & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                        >> 0x00000015U)) 
                                                                    + 
                                                                    ((1U 
                                                                      & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                         >> 0x00000016U)) 
                                                                     + 
                                                                     ((1U 
                                                                       & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                          >> 0x00000017U)) 
                                                                      + 
                                                                      ((1U 
                                                                        & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                           >> 0x00000018U)) 
                                                                       + 
                                                                       ((1U 
                                                                         & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                            >> 0x00000019U)) 
                                                                        + 
                                                                        ((1U 
                                                                          & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                             >> 0x0000001aU)) 
                                                                         + 
                                                                         ((1U 
                                                                           & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                              >> 0x0000001bU)) 
                                                                          + 
                                                                          ((1U 
                                                                            & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                               >> 0x0000001cU)) 
                                                                           + 
                                                                           ((1U 
                                                                             & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                                >> 0x0000001dU)) 
                                                                            + 
                                                                            ((1U 
                                                                              & (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                                >> 0x0000001eU)) 
                                                                             + 
                                                                             (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep 
                                                                              >> 0x0000001fU)))))))))))))))))))))))))))))));
    vlSelfRef.m_axis_rd_tdata[0U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[0U];
    vlSelfRef.m_axis_rd_tdata[1U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[1U];
    vlSelfRef.m_axis_rd_tdata[2U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[2U];
    vlSelfRef.m_axis_rd_tdata[3U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[3U];
    vlSelfRef.m_axis_rd_tdata[4U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[4U];
    vlSelfRef.m_axis_rd_tdata[5U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[5U];
    vlSelfRef.m_axis_rd_tdata[6U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[6U];
    vlSelfRef.m_axis_rd_tdata[7U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[7U];
    vlSelfRef.m_axis_rd_tkeep = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tkeep;
    vlSelfRef.m_axis_rd_tvalid = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tvalid;
    vlSelfRef.m_axis_rd_tlast = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tlast;
    vlSelfRef.m_axis_rd_tuser = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tuser;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_idx_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_idx_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_alloc_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_alloc_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_meta_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_meta_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_meta_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_meta_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_seg_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_seg_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_second_seg_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_second_seg_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_idx_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_idx_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_beat_pending_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_beat_pending_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[0U] 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[0U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[1U] 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[1U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[2U] 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[2U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[3U] 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[3U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[4U] 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[4U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[5U] 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[5U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[6U] 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[6U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[7U] 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[7U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_keep_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_keep_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_user_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_user_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_n 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__s_axis_ready_c = 0U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awaddr = 0ULL;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awlen = 0U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awsize = 5U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awburst = 1U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awvalid = 0U;
    VL_ASSIGN_W(256, vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wstrb = 0U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wlast = 0U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wvalid = 0U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.bready = 0U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.araddr = 0ULL;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.arlen = 0U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.arsize = 5U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.arburst = 1U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.arvalid = 0U;
    vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rready = 0U;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__axi_rready_c = 0U;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_en_c = 0U;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_idx_c = 0U;
    VL_ASSIGN_W(256, vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_keep_c = 0U;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_c = 0U;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_idx_c 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_cur_burst_bytes_c 
        = (0x0001ffffU & ([&]() {
                vlSelfRef.__Vfunc_min_u__5__rhs = 0x00000100U;
                vlSelfRef.__Vfunc_min_u__5__lhs = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_r;
                {
                    vlSelfRef.__Vfunc_min_u__5__Vfuncout = 0U;
                    if ((vlSelfRef.__Vfunc_min_u__5__lhs 
                         < vlSelfRef.__Vfunc_min_u__5__rhs)) {
                        vlSelfRef.__Vfunc_min_u__5__Vfuncout 
                            = vlSelfRef.__Vfunc_min_u__5__lhs;
                        goto __Vlabel0;
                    }
                    vlSelfRef.__Vfunc_min_u__5__Vfuncout 
                        = vlSelfRef.__Vfunc_min_u__5__rhs;
                    __Vlabel0: ;
                }
            }(), vlSelfRef.__Vfunc_min_u__5__Vfuncout));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_cur_burst_beats_c 
        = (0x0000000fU & ([&]() {
                vlSelfRef.__Vfunc_ceil_div_u__6__denominator = 0x00000020U;
                vlSelfRef.__Vfunc_ceil_div_u__6__numerator 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_cur_burst_bytes_c;
                {
                    vlSelfRef.__Vfunc_ceil_div_u__6__Vfuncout = 0U;
                    if ((0U == vlSelfRef.__Vfunc_ceil_div_u__6__denominator)) {
                        vlSelfRef.__Vfunc_ceil_div_u__6__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                    vlSelfRef.__Vfunc_ceil_div_u__6__Vfuncout 
                        = VL_DIV_III(32, ((vlSelfRef.__Vfunc_ceil_div_u__6__numerator 
                                           + vlSelfRef.__Vfunc_ceil_div_u__6__denominator) 
                                          - (IData)(1U)), vlSelfRef.__Vfunc_ceil_div_u__6__denominator);
                    __Vlabel1: ;
                }
            }(), vlSelfRef.__Vfunc_ceil_div_u__6__Vfuncout));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_cur_burst_bytes_c 
        = (0x0001ffffU & ([&]() {
                vlSelfRef.__Vfunc_min_u__7__rhs = 0x00000100U;
                vlSelfRef.__Vfunc_min_u__7__lhs = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_r;
                {
                    vlSelfRef.__Vfunc_min_u__7__Vfuncout = 0U;
                    if ((vlSelfRef.__Vfunc_min_u__7__lhs 
                         < vlSelfRef.__Vfunc_min_u__7__rhs)) {
                        vlSelfRef.__Vfunc_min_u__7__Vfuncout 
                            = vlSelfRef.__Vfunc_min_u__7__lhs;
                        goto __Vlabel2;
                    }
                    vlSelfRef.__Vfunc_min_u__7__Vfuncout 
                        = vlSelfRef.__Vfunc_min_u__7__rhs;
                    __Vlabel2: ;
                }
            }(), vlSelfRef.__Vfunc_min_u__7__Vfuncout));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_cur_burst_beats_c 
        = (0x0000000fU & ([&]() {
                vlSelfRef.__Vfunc_ceil_div_u__8__denominator = 0x00000020U;
                vlSelfRef.__Vfunc_ceil_div_u__8__numerator 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_cur_burst_bytes_c;
                {
                    vlSelfRef.__Vfunc_ceil_div_u__8__Vfuncout = 0U;
                    if ((0U == vlSelfRef.__Vfunc_ceil_div_u__8__denominator)) {
                        vlSelfRef.__Vfunc_ceil_div_u__8__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                    vlSelfRef.__Vfunc_ceil_div_u__8__Vfuncout 
                        = VL_DIV_III(32, ((vlSelfRef.__Vfunc_ceil_div_u__8__numerator 
                                           + vlSelfRef.__Vfunc_ceil_div_u__8__denominator) 
                                          - (IData)(1U)), vlSelfRef.__Vfunc_ceil_div_u__8__denominator);
                    __Vlabel3: ;
                }
            }(), vlSelfRef.__Vfunc_ceil_div_u__8__Vfuncout));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__beat_valid_bytes_c = 0U;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c = 0ULL;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__last_beat_c = 0U;
    VL_ASSIGN_W(256, vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wdata_c, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wstrb_c = 0U;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wlast_c 
        = ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_r) 
           == (0x0000000fU & ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_r) 
                              - (IData)(1U))));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx = 0U;
    while ((0x00000020U > vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx)) {
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__lane_offset_c 
            = (0x0001ffffU & vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx);
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__slot_byte_index_c 
            = (0x0001ffffU & VL_SHIFTL_III(17,17,32, 
                                           ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_r) 
                                            + (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_r)), 5U));
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c 
            = (0x0000000fU & ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_r) 
                              + (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_r)));
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_present_c 
            = ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c) 
               < (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_r));
        if (((0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__slot_byte_index_c 
                             + vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__lane_offset_c)) 
             < vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r)) {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wstrb_c 
                = (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wstrb_c 
                   | (0x00000000ffffffffULL & ((IData)(1U) 
                                               << (0x0000001fU 
                                                   & vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx))));
            if (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_present_c) 
                 & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_keep_r
                    [vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c] 
                    >> (0x0000001fU & vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx)))) {
                VL_ASSIGNSEL_WI(256, 8, (0x000000ffU 
                                         & VL_MULS_III(32, (IData)(8U), vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx)), vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wdata_c, 
                                (0x000000ffU & (((0U 
                                                  == 
                                                  (0x0000001fU 
                                                   & VL_MULS_III(32, (IData)(8U), vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx)))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r
                                                  [vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c]
                                                  [
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x000000ffU 
                                                     & VL_MULS_III(32, (IData)(8U), vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & VL_MULS_III(32, (IData)(8U), vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx))))) 
                                                | (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r
                                                   [vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c]
                                                   [
                                                   (7U 
                                                    & (VL_MULS_III(32, (IData)(8U), vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x0000001fU 
                                                    & VL_MULS_III(32, (IData)(8U), vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx))))));
            }
        }
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx 
            = ((IData)(1U) + vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx);
    }
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_commit_pulse_c = 0U;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_done_pulse_c = 0U;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_error_pulse_c = 0U;
    if (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_enable_i) 
         & (~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_ok_c)))) {
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_n = 1U;
    }
    if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_fire_c) {
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_n = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_n = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_keep_n = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_user_n = 0ULL;
    }
    if (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_consume_i) 
         & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_req_i))) {
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_n = 1U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_error_pulse_c = 1U;
    }
    if (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_consume_i) 
         & (~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_req_i)))) {
        if ((1U & ((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_busy_o)) 
                   & (~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c))))) {
            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__9__ptr 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r;
            {
                vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__9__Vfuncout = 0;
                if ((7U == (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__9__ptr))) {
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__9__Vfuncout = 0U;
                    goto __Vlabel4;
                }
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__9__Vfuncout 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__9__ptr)));
                __Vlabel4: ;
            }
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_n 
                = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__9__Vfuncout;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_n 
                = (0x0000000fU & ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_n) 
                                  - (IData)(1U)));
            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__advance_bytes 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_alloc_bytes_c;
            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__curr_addr 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_r;
            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__ring_size_bytes 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i;
            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__base_addr 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
            {
                vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__Vfuncout = 0;
                vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__ring_end_addr = 0;
                vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__to_end_bytes = 0;
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__ring_end_addr 
                    = (0x00000003ffffffffULL & (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__base_addr 
                                                + (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__ring_size_bytes))));
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__to_end_bytes 
                    = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__ring_end_addr) 
                                      - (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__curr_addr)));
                if ((vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__advance_bytes 
                     < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__to_end_bytes)) {
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__Vfuncout 
                        = (0x00000003ffffffffULL & 
                           (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__curr_addr 
                            + (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__advance_bytes))));
                    goto __Vlabel5;
                } else if ((vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__advance_bytes 
                            == vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__to_end_bytes)) {
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__Vfuncout 
                        = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__base_addr;
                    goto __Vlabel5;
                }
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__Vfuncout 
                    = (0x00000003ffffffffULL & (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__base_addr 
                                                + ((QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__advance_bytes)) 
                                                   - (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__to_end_bytes)))));
                __Vlabel5: ;
            }
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_n 
                = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__Vfuncout;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_n 
                = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_n 
                                  - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_alloc_bytes_c));
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_n 
                = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_n 
                                  - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_alloc_bytes_c));
        } else if (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c) 
                    | (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_busy_o))) {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_n = 1U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_error_pulse_c = 1U;
        }
    }
    if ((8U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) {
        if ((4U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 0U;
        } else if ((2U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 0U;
        } else if ((1U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 0U;
        } else {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_n 
                = ((IData)(1U) + vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_n);
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_n = 0ULL;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_n = 0ULL;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_n = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) {
        if ((2U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) {
            if ((1U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_n 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_r;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_n 
                    = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_n 
                                      + vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r));
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_c = 1U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_idx_c 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_r;
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__11__ptr 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_r;
                {
                    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__11__Vfuncout = 0;
                    if ((7U == (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__11__ptr))) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__11__Vfuncout = 0U;
                        goto __Vlabel6;
                    }
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__11__Vfuncout 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__11__ptr)));
                    __Vlabel6: ;
                }
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_n 
                    = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__11__Vfuncout;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_n 
                    = (0x0000000fU & ((IData)(1U) + (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_n)));
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_commit_pulse_c = 1U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_n = 0ULL;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_n = 0ULL;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_n = 0U;
            } else {
                vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.bready = 1U;
                if (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.bvalid) {
                    if ((0U != (IData)(vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.bresp))) {
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_n = 1U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_n 
                            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_n 
                            = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_n 
                                              - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r));
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_n 
                            = (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_n 
                               - (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_r));
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_n 
                            = ((IData)(1U) + vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_n);
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_n = 0ULL;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_n = 0ULL;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_n = 0U;
                    } else if ((0U != (0x0001ffffU 
                                       & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_r 
                                          - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_r)))) {
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_n 
                            = (0x00000003ffffffffULL 
                               & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_r 
                                  + (QData)((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_r))));
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_n 
                            = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_r 
                                              - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_r));
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_n 
                            = (0x0000000fU & ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_r) 
                                              + (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_r)));
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 4U;
                    } else if (((0U == (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_idx_r)) 
                                & (0U != vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_r))) {
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_idx_n = 1U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_n 
                            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_n 
                            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_r;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_n 
                            = (0x0000000fU & ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_r) 
                                              + (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_r)));
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 4U;
                    } else {
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 7U;
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) {
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[0U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wdata_c[0U];
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[1U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wdata_c[1U];
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[2U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wdata_c[2U];
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[3U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wdata_c[3U];
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[4U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wdata_c[4U];
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[5U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wdata_c[5U];
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[6U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wdata_c[6U];
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[7U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wdata_c[7U];
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wstrb 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wstrb_c;
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wlast 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wlast_c;
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wvalid = 1U;
            if (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wready) {
                if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wlast_c) {
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 6U;
                } else {
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_n 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_r)));
                }
            }
        } else {
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awaddr 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_r;
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awlen 
                = (0x000000ffU & ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_cur_burst_beats_c) 
                                  - (IData)(1U)));
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awvalid = 1U;
            if (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awready) {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_n 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_cur_burst_bytes_c;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_n 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_cur_burst_beats_c;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 5U;
            }
        }
    } else if ((2U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) {
        if ((1U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) {
            if ((1U & (((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_busy_o)) 
                        & (~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c))) 
                       & (~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_consume_i))))) {
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__12__ptr 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r;
                {
                    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__12__Vfuncout = 0;
                    if ((7U == (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__12__ptr))) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__12__Vfuncout = 0U;
                        goto __Vlabel7;
                    }
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__12__Vfuncout 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__12__ptr)));
                    __Vlabel7: ;
                }
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_n 
                    = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__12__Vfuncout;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_n 
                    = (0x0000000fU & ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_n) 
                                      - (IData)(1U)));
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__advance_bytes 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_alloc_bytes_c;
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__curr_addr 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_r;
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__ring_size_bytes 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i;
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__base_addr 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
                {
                    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__Vfuncout = 0;
                    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__ring_end_addr = 0;
                    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__to_end_bytes = 0;
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__ring_end_addr 
                        = (0x00000003ffffffffULL & 
                           (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__base_addr 
                            + (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__ring_size_bytes))));
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__to_end_bytes 
                        = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__ring_end_addr) 
                                          - (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__curr_addr)));
                    if ((vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__advance_bytes 
                         < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__to_end_bytes)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__Vfuncout 
                            = (0x00000003ffffffffULL 
                               & (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__curr_addr 
                                  + (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__advance_bytes))));
                        goto __Vlabel8;
                    } else if ((vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__advance_bytes 
                                == vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__to_end_bytes)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__Vfuncout 
                            = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__base_addr;
                        goto __Vlabel8;
                    }
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__Vfuncout 
                        = (0x00000003ffffffffULL & 
                           (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__base_addr 
                            + ((QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__advance_bytes)) 
                               - (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__to_end_bytes)))));
                    __Vlabel8: ;
                }
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_n 
                    = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__Vfuncout;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_n 
                    = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_n 
                                      - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_alloc_bytes_c));
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_n 
                    = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_n 
                                      - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_alloc_bytes_c));
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_n 
                    = ((IData)(1U) + vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_n);
            }
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 2U;
        } else if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_ok_c) {
            if (((((0U == vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r) 
                   | (0U == vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r)) 
                  | (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r 
                     > vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i)) 
                 | (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_r))) {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_n = 1U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 8U;
            } else if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_drop_now_c) {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 8U;
            } else if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_can_fit_c) {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_n 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_n 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__next_wr_ptr_c;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_n 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__first_seg_bytes_c;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_n 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__second_seg_bytes_c;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_n 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__next_wr_wrap_c;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_n 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__next_wr_ptr_c;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_n 
                    = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_n 
                                      + vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r));
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_n 
                    = (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_n 
                       + (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__next_wr_wrap_c));
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_idx_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_n 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_n 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__first_seg_bytes_c;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_n = 0U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n 
                    = ((0U != vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__first_seg_bytes_c)
                        ? 4U : 7U);
            } else {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_n = 1U;
                if ((((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_allow_overwrite_i) 
                      & (~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_busy_o))) 
                     & (~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c)))) {
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 3U;
                } else if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_drop_on_no_space_i) {
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 8U;
                }
            }
        } else {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_n = 1U;
        }
    } else if ((1U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) {
        if (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_enable_i) 
             & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_ok_c))) {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__s_axis_ready_c = 1U;
            if (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tvalid) {
                if ((0x10U > (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_r))) {
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_en_c = 1U;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_idx_c 
                        = (0x0000000fU & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_r));
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[0U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[0U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[1U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[1U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[2U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[2U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[3U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[3U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[4U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[4U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[5U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[5U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[6U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[6U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[7U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[7U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_keep_c 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_n 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_r)));
                } else {
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_n = 1U;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_n = 1U;
                }
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_n 
                    = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_r 
                                      + (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__s_axis_keep_bytes_c)));
                if (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_start_i) 
                     | ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_done_i) 
                        & (~ (IData)(vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tlast))))) {
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_n = 1U;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_n = 1U;
                }
                if (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tlast) {
                    if ((1U & ((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_done_i)) 
                               | ((0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_r 
                                                  + (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__s_axis_keep_bytes_c))) 
                                  != vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r)))) {
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_n = 1U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_n = 1U;
                    }
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 2U;
                }
            }
        }
    } else if (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_enable_i) 
                & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_ok_c))) {
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__s_axis_ready_c = 1U;
        if (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tvalid) {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_en_c = 1U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_idx_c = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[0U] 
                = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[0U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[1U] 
                = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[1U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[2U] 
                = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[2U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[3U] 
                = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[3U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[4U] 
                = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[4U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[5U] 
                = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[5U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[6U] 
                = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[6U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[7U] 
                = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tdata[7U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_keep_c 
                = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tkeep;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_n = 1U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__s_axis_keep_bytes_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_effective_bytes_in_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_alloc_bytes_in_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_seq_i;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_valid_good_i;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_overflow_err_i;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_n 
                = (1U & ((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_start_i)) 
                         | ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_done_i) 
                            & (~ (IData)(vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tlast)))));
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_n 
                = (0x00000200U < vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_effective_bytes_in_c);
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_n = 0ULL;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_n = 0ULL;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_n = 0U;
            if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_overflow_err_i) {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_n 
                    = ((IData)(1U) + vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_n);
            }
            if ((0x00000200U < vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_effective_bytes_in_c)) {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_n = 1U;
            }
            if (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tlast) {
                if ((1U & ((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_done_i)) 
                           | ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__s_axis_keep_bytes_c) 
                              != vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_effective_bytes_in_c)))) {
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_n = 1U;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_n = 1U;
                }
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 2U;
            } else {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = 1U;
            }
        }
    }
    if ((4U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r))) {
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n = 0U;
    } else if ((2U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r))) {
        if ((1U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r))) {
            if (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_fire_c) 
                 & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_r))) {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_done_pulse_c = 1U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n = 0U;
            } else if ((1U & (~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r)))) {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_done_pulse_c = 1U;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n = 0U;
            }
        } else {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__axi_rready_c 
                = (1U & ((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r)) 
                         | (IData)(vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tready)));
            vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rready 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__axi_rready_c;
            if (((IData)(vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rvalid) 
                 & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__axi_rready_c))) {
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__beat_valid_bytes_c 
                    = ((0x00000020U <= vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_r)
                        ? 0x00000020U : vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_r);
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__last_beat_c 
                    = (0x00000020U >= vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_r);
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c = 0ULL;
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c 
                    = ((0xfffffffffffffff1ULL & vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c) 
                       | ((QData)((IData)((((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_meta_r) 
                                            << 2U) 
                                           | (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_meta_r) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__last_beat_c))))) 
                          << 1U));
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c 
                    = ((0xffffffffff0000ffULL & vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c) 
                       | ((QData)((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_r)) 
                          << 8U));
                vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c 
                    = ((0xfffe0000ffffffffULL & vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c) 
                       | ((QData)((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_r)) 
                          << 0x00000020U));
                if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_beat_pending_r) {
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c 
                        = (1ULL | vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c);
                }
                if ((0U != (IData)(vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rresp))) {
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_n = 1U;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_n = 1U;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_error_pulse_c = 1U;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n = 0U;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_n = 0U;
                } else {
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[0U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rdata[0U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[1U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rdata[1U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[2U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rdata[2U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[3U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rdata[3U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[4U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rdata[4U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[5U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rdata[5U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[6U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rdata[6U];
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[7U] 
                        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rdata[7U];
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count 
                        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__beat_valid_bytes_c;
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c = 0U;
                    if ((0U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (1U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((1U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (2U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((2U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (4U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((3U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (8U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((4U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00000010U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((5U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00000020U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((6U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00000040U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((7U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00000080U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((8U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00000100U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((9U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00000200U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000000aU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00000400U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000000bU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00000800U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000000cU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00001000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000000dU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00002000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000000eU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00004000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000000fU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00008000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x00000010U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00010000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x00000011U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00020000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x00000012U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00040000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x00000013U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00080000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x00000014U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00100000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x00000015U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00200000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x00000016U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00400000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x00000017U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x00800000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x00000018U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x01000000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x00000019U < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x02000000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000001aU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x04000000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000001bU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x08000000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000001cU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x10000000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000001dU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x20000000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000001eU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x40000000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    if ((0x0000001fU < vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c 
                            = (0x80000000U | vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c);
                    }
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__Vfuncout 
                        = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_keep_n 
                        = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__Vfuncout;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_user_n 
                        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__axis_user_c;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_n 
                        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__last_beat_c;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_n = 1U;
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_n 
                        = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_r 
                                          - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__unnamedblk2__DOT__beat_valid_bytes_c));
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_n 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_r)));
                    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_beat_pending_n = 0U;
                    if (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_r) 
                         == (0x0000000fU & ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_r) 
                                            - (IData)(1U))))) {
                        if ((0U != (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_r 
                                                   - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_r)))) {
                            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_n 
                                = (0x00000003ffffffffULL 
                                   & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_r 
                                      + (QData)((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_r))));
                            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_n 
                                = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_r 
                                                  - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_r));
                            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n = 1U;
                        } else if (((0U == (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_idx_r)) 
                                    & (0U != vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_second_seg_bytes_r))) {
                            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_idx_n = 1U;
                            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_n 
                                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
                            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_n 
                                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_second_seg_bytes_r;
                            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n = 1U;
                        } else {
                            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n = 3U;
                        }
                    }
                    if (((IData)(vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rlast) 
                         != ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_r) 
                             == (0x0000000fU & ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_r) 
                                                - (IData)(1U)))))) {
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_n = 1U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_error_pulse_c = 1U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_keep_n = 0U;
                        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_user_n = 0ULL;
                    }
                }
            }
        }
    } else if ((1U & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r))) {
        vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.araddr 
            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_r;
        vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.arlen 
            = (0x000000ffU & ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_cur_burst_beats_c) 
                              - (IData)(1U)));
        vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.arvalid = 1U;
        if (vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.arready) {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_cur_burst_bytes_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_cur_burst_beats_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n = 2U;
        }
    } else if (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_req_i) 
                & (~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_consume_i)))) {
        if ((1U & ((((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_enable_i)) 
                     | (~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_ok_c))) 
                    | (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c)) 
                   | (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r)))) {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_n = 1U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_error_pulse_c = 1U;
        } else {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_alloc_bytes_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_alloc_bytes_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_seq_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_meta_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_valid_good_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_meta_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_overflow_err_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_seg_bytes_n 
                = ((vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c 
                    <= ([&]() {
                            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__curr_addr 
                                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c;
                            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__ring_size_bytes 
                                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i;
                            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__base_addr 
                                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
                            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__ring_end_addr 
                                = (0x00000003ffffffffULL 
                                   & (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__base_addr 
                                      + (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__ring_size_bytes))));
                            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__Vfuncout 
                                = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__ring_end_addr) 
                                                  - (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__curr_addr)));
                        }(), vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__Vfuncout))
                    ? vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c
                    : ([&]() {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__curr_addr 
                            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c;
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__ring_size_bytes 
                            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i;
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__base_addr 
                            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__ring_end_addr 
                            = (0x00000003ffffffffULL 
                               & (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__base_addr 
                                  + (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__ring_size_bytes))));
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__Vfuncout 
                            = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__ring_end_addr) 
                                              - (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__curr_addr)));
                    }(), vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__Vfuncout));
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_second_seg_bytes_n 
                = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c 
                                  - ((vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c 
                                      <= ([&]() {
                                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__curr_addr 
                                        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c;
                                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__ring_size_bytes 
                                        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i;
                                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__base_addr 
                                        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
                                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__ring_end_addr 
                                        = (0x00000003ffffffffULL 
                                           & (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__base_addr 
                                              + (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__ring_size_bytes))));
                                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__Vfuncout 
                                        = (0x0001ffffU 
                                           & ((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__ring_end_addr) 
                                              - (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__curr_addr)));
                                }(), vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__Vfuncout))
                                      ? vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c
                                      : ([&]() {
                                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__curr_addr 
                                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c;
                                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__ring_size_bytes 
                                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i;
                                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__base_addr 
                                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
                                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__ring_end_addr 
                                    = (0x00000003ffffffffULL 
                                       & (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__base_addr 
                                          + (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__ring_size_bytes))));
                                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__Vfuncout 
                                    = (0x0001ffffU 
                                       & ((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__ring_end_addr) 
                                          - (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__curr_addr)));
                            }(), vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__Vfuncout))));
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_idx_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_n 
                = ((vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c 
                    <= ([&]() {
                            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__curr_addr 
                                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c;
                            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__ring_size_bytes 
                                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i;
                            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__base_addr 
                                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
                            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__ring_end_addr 
                                = (0x00000003ffffffffULL 
                                   & (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__base_addr 
                                      + (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__ring_size_bytes))));
                            vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__Vfuncout 
                                = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__ring_end_addr) 
                                                  - (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__curr_addr)));
                        }(), vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__Vfuncout))
                    ? vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c
                    : ([&]() {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__curr_addr 
                            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c;
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__ring_size_bytes 
                            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i;
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__base_addr 
                            = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__ring_end_addr 
                            = (0x00000003ffffffffULL 
                               & (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__base_addr 
                                  + (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__ring_size_bytes))));
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__Vfuncout 
                            = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__ring_end_addr) 
                                              - (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__curr_addr)));
                    }(), vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__Vfuncout));
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_n 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_n = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_beat_pending_n = 1U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n = 1U;
        }
    }
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awaddr 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awaddr;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awlen 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awlen;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awsize 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awsize;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awburst 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awburst;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awvalid 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.awvalid;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[0U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[0U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[1U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[1U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[2U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[2U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[3U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[3U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[4U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[4U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[5U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[5U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[6U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[6U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[7U] 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wdata[7U];
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wstrb 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wstrb;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wlast 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wlast;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wvalid 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.wvalid;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_bready 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.bready;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_araddr 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.araddr;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arlen 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.arlen;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arsize 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.arsize;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arburst 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.arburst;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arvalid 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.arvalid;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rready 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if.rready;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_commit_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_commit_pulse_c;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_done_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_done_pulse_c;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_error_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_error_pulse_c;
    vlSelfRef.m_axi_awaddr = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awaddr;
    vlSelfRef.m_axi_awlen = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awlen;
    vlSelfRef.m_axi_awsize = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awsize;
    vlSelfRef.m_axi_awburst = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awburst;
    vlSelfRef.m_axi_awvalid = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awvalid;
    vlSelfRef.m_axi_wdata[0U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[0U];
    vlSelfRef.m_axi_wdata[1U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[1U];
    vlSelfRef.m_axi_wdata[2U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[2U];
    vlSelfRef.m_axi_wdata[3U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[3U];
    vlSelfRef.m_axi_wdata[4U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[4U];
    vlSelfRef.m_axi_wdata[5U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[5U];
    vlSelfRef.m_axi_wdata[6U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[6U];
    vlSelfRef.m_axi_wdata[7U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata[7U];
    vlSelfRef.m_axi_wstrb = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wstrb;
    vlSelfRef.m_axi_wlast = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wlast;
    vlSelfRef.m_axi_wvalid = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wvalid;
    vlSelfRef.m_axi_bready = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_bready;
    vlSelfRef.m_axi_araddr = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_araddr;
    vlSelfRef.m_axi_arlen = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arlen;
    vlSelfRef.m_axi_arsize = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arsize;
    vlSelfRef.m_axi_arburst = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arburst;
    vlSelfRef.m_axi_arvalid = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arvalid;
    vlSelfRef.m_axi_rready = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rready;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_commit_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_commit_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_done_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_done_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_error_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_error_o;
    vlSelfRef.wr_slot_commit_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_commit_o;
    vlSelfRef.rd_done_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_done_o;
    vlSelfRef.rd_error_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_error_o;
}

void Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axi4_mm_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if__0(Vtop_axi4_mm_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if__1(Vtop_axis_stream_if* vlSelf);
void Vtop___024root___ico_sequent__TOP__2(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if__0((&vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if));
        Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if__0((&vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if));
        Vtop_axi4_mm_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if__0((&vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if));
        Vtop___024root___stl_sequent__TOP__1(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if__1((&vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if));
        Vtop___024root___ico_sequent__TOP__2(vlSelf);
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge ddr_ringbuffer_controller_cocotb_top.dut.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge ddr_ringbuffer_controller_cocotb_top.dut.rst_ni)\n");
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
    vlSelf->cfg_enable_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8574283470568429695ull);
    vlSelf->cfg_allow_overwrite_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4053853332066994793ull);
    vlSelf->cfg_drop_invalid_slot_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9561319106844817856ull);
    vlSelf->cfg_drop_on_no_space_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9532459606635723755ull);
    vlSelf->cfg_ring_base_addr_i = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 4909204147935342120ull);
    vlSelf->cfg_ring_size_bytes_i = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9692597135029889435ull);
    vlSelf->slot_start_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4826260384883012537ull);
    vlSelf->slot_done_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3728551296904974621ull);
    vlSelf->slot_bytes_i = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10436988458224680460ull);
    vlSelf->slot_seq_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6756882667388549235ull);
    vlSelf->slot_valid_good_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1048577972213042148ull);
    vlSelf->slot_overflow_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6047345586872531771ull);
    vlSelf->wr_slot_commit_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3681659399404481916ull);
    vlSelf->wr_slot_addr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 4515414427466771197ull);
    vlSelf->wr_slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10383028891330412392ull);
    vlSelf->wr_slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12604105843175192207ull);
    vlSelf->wr_slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12382160575281430246ull);
    vlSelf->wr_slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4054532688649687155ull);
    vlSelf->rd_slot_req_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9217872020822696980ull);
    vlSelf->rd_consume_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8646905831470459879ull);
    vlSelf->rd_slot_valid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2673272906063126809ull);
    vlSelf->rd_slot_addr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 13040847719322431973ull);
    vlSelf->rd_slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10543742977542711602ull);
    vlSelf->rd_slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3270254366872532596ull);
    vlSelf->rd_slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13116500185850577577ull);
    vlSelf->rd_slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13440181763087509966ull);
    vlSelf->rd_busy_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18411612262857264557ull);
    vlSelf->rd_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8509512655296700662ull);
    vlSelf->rd_error_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7675855505965077ull);
    vlSelf->wr_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 14845439060775290475ull);
    vlSelf->rd_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 5471125147616523956ull);
    vlSelf->commit_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 8454357643489748878ull);
    vlSelf->used_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14080196247336730705ull);
    vlSelf->free_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3731313026355240503ull);
    vlSelf->committed_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9982965413965869874ull);
    vlSelf->full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6064445919729732869ull);
    vlSelf->almost_full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9402363639240035987ull);
    vlSelf->empty_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 123340495795469900ull);
    vlSelf->wrap_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10705744444105964971ull);
    vlSelf->overflow_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14518324670910447231ull);
    vlSelf->drop_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10291917112660355557ull);
    vlSelf->err_cfg_align_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8455334638499530352ull);
    vlSelf->err_no_space_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7442245282486306216ull);
    vlSelf->err_slot_proto_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4029616397310035313ull);
    vlSelf->err_slot_too_large_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4286755845642969562ull);
    vlSelf->err_axi_wr_resp_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7905221386629165429ull);
    vlSelf->err_axi_rd_resp_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4144333801452726632ull);
    vlSelf->err_illegal_read_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17397469005487728137ull);
    vlSelf->dbg_wr_state_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12008746172414568785ull);
    vlSelf->dbg_rd_state_o = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8886054752768454440ull);
    vlSelf->dbg_wr_burst_beats_o = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9789432067554707329ull);
    vlSelf->dbg_wr_burst_sent_o = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12790642876109522398ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->s_axis_slot_tdata, __VscopeHash, 10729096650701925718ull);
    vlSelf->s_axis_slot_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9676029624204207506ull);
    vlSelf->s_axis_slot_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11190850996220517082ull);
    vlSelf->s_axis_slot_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 981219360620673790ull);
    vlSelf->s_axis_slot_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2634938650839399338ull);
    vlSelf->s_axis_slot_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2232987364331643778ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->m_axis_rd_tdata, __VscopeHash, 12938975675155744835ull);
    vlSelf->m_axis_rd_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13745061360504249867ull);
    vlSelf->m_axis_rd_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4912593778937907128ull);
    vlSelf->m_axis_rd_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11577373036945535065ull);
    vlSelf->m_axis_rd_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15864578409519677261ull);
    vlSelf->m_axis_rd_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8499307309336324080ull);
    vlSelf->m_axi_awaddr = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 13558266821849222593ull);
    vlSelf->m_axi_awlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15527027863330074270ull);
    vlSelf->m_axi_awsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17768164634708584365ull);
    vlSelf->m_axi_awburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16027732775651784324ull);
    vlSelf->m_axi_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17994771565963626208ull);
    vlSelf->m_axi_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16573481163850279297ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->m_axi_wdata, __VscopeHash, 1286380785785437420ull);
    vlSelf->m_axi_wstrb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15721383833457952779ull);
    vlSelf->m_axi_wlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2914646395814725164ull);
    vlSelf->m_axi_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17462522629772039856ull);
    vlSelf->m_axi_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10076110868751280388ull);
    vlSelf->m_axi_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3179402000051064225ull);
    vlSelf->m_axi_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17532096651654485089ull);
    vlSelf->m_axi_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 919615779156835605ull);
    vlSelf->m_axi_araddr = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 1846461378547527168ull);
    vlSelf->m_axi_arlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16617312831593392701ull);
    vlSelf->m_axi_arsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17543111694348153197ull);
    vlSelf->m_axi_arburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1752602318331902070ull);
    vlSelf->m_axi_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16153593045339235853ull);
    vlSelf->m_axi_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14657891178303932712ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->m_axi_rdata, __VscopeHash, 7098886022588844013ull);
    vlSelf->m_axi_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9891928918972316509ull);
    vlSelf->m_axi_rlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5192182110111361339ull);
    vlSelf->m_axi_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10047683109683776937ull);
    vlSelf->m_axi_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4323339442303808258ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1935451077900849940ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18079373152841085269ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__cfg_enable_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3062501937136175519ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__cfg_allow_overwrite_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8343631263492085796ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__cfg_drop_invalid_slot_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4345154603227418166ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__cfg_drop_on_no_space_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3968576983099909780ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__cfg_ring_base_addr_i = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 15241005445212174231ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__cfg_ring_size_bytes_i = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15262980178443342619ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__slot_start_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1657225110506228457ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__slot_done_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15577695413544573357ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__slot_bytes_i = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14270379501092628154ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__slot_seq_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16207910507620307214ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__slot_valid_good_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8607485213073818319ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__slot_overflow_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8622360012029371563ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_commit_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3292640152357213099ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_addr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 12939183662291490786ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2395544511084642362ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17778051623432516124ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17101293414059999060ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6793586120788754186ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_req_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18211039397067286842ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_consume_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10022360637403328794ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_valid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5822342161001649913ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_addr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 8193372451998223708ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8353834462746690098ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17168101048681475601ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6131709016587016068ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3592866388000272392ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_busy_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9900711446726772686ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7048072918537825698ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_error_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3402974646701036934ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__wr_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 9376298156808915410ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__rd_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 6683227010106740512ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__commit_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 8592643925070979271ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__used_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15335434973008719786ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__free_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15167408953622824189ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__committed_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2091810345677207289ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16029943527237860242ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__almost_full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9081813489797913431ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__empty_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15303442645202793107ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__wrap_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2194440942145504657ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__overflow_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3661037528924107171ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__drop_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5273020231808292042ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__err_cfg_align_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14817509854196452536ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__err_no_space_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16612152703168091444ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__err_slot_proto_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15688727271246414846ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__err_slot_too_large_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6358117449019400134ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__err_axi_wr_resp_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4972325872571576604ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__err_axi_rd_resp_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4173803664035022705ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__err_illegal_read_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7317588571825975617ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_state_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4994718001821026ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dbg_rd_state_o = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3759464588079177540ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_beats_o = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17751080894080666887ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_sent_o = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7345651708985057198ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tdata, __VscopeHash, 13302243353737960229ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8629861764598754230ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1191663232669808093ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6392548748557226322ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12458312332360684465ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6081395169909631939ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata, __VscopeHash, 13341244012372774884ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1220606019747525468ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13232625597387690369ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6847631401171738084ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5263704870049641408ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 236361894565636357ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awaddr = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 15871612991762701713ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9430488235138207191ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11327177337036983959ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8610120682019457777ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13623365541068477544ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11446512613210822789ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wdata, __VscopeHash, 7520259559305529826ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wstrb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12874098476251099699ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11024620739595244498ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6654719119558098029ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6118211752030955625ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4277088996724536486ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5941758025369662080ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7282179082216903852ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_araddr = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 6243728701842019623ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6261298129953910326ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17057186379264256515ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5284661749347633638ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4611524266520799120ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1872064938834157973ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rdata, __VscopeHash, 3114431779962045854ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5567683702159369050ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15436514783248007995ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6443665711008627733ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4595177733212855083ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12763018706473705791ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13292200540462345258ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_enable_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9317076600133024274ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_allow_overwrite_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12917039197797851043ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_drop_invalid_slot_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10004544390119287838ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_drop_on_no_space_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9352679367186577008ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 6736854407636612022ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 364061823225424298ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_start_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15773503432556668414ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_done_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9901715658357021247ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_bytes_i = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 13150999999555216034ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_seq_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13359823420744349590ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_valid_good_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6385457893151185231ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_overflow_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9759467508002472287ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_commit_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17018618254996455429ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_addr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 10946353206442315700ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15109570565353297087ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1279679869405798510ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10613971588021429489ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14468283250688341757ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_req_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6734773763318286126ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_consume_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5226931345959537723ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18071199825482778780ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 5010259832010478785ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2072151538082364520ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10285982057416427052ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13168708610919063160ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2708996950303385083ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_busy_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15183178160005412882ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7127679423624384889ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_error_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 317867901366120144ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 14777511321467388727ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 10846204074796498904ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 17706515438953766164ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3393399155495561310ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 7685421666764935719ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17006308795573057411ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14547421721929799748ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__almost_full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2346703668483212901ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__empty_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8795795849818823703ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5789440865342365289ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13193142476341085020ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9487228424570953108ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 980769239391587820ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8679698650864286495ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14751222030551404700ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4868149037170558795ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7147723794829299561ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1922575758049337323ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9480822199848347801ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(256, vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r[__Vi0], __VscopeHash, 3479677940539884327ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_keep_r[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17971172206155380848ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r[__Vi0] = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 18192974098129846390ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_bytes_r[__Vi0] = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1595700490425378773ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_alloc_bytes_r[__Vi0] = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2853131073720470015ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_seq_r[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12982562907206983283ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_valid_good_r[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7538627549453473136ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_overflow_err_r[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16264372981823976524ull);
    }
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12316616612925390450ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14161579407166369044ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2431891220326141428ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 549269217480700742ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 2234530437071819212ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 4696521659429417927ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 16538388794383419590ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 13710369837453726724ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 7172388079160963127ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 402973306912774075ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 7758377830321091565ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9967213527310696194ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 13717180214914515489ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9631433039181506863ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10685104634948844429ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16310059827211258324ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17581541776324530646ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11902434304355876981ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 168851855216734756ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8184439581210736763ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10921626683637528497ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_n = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4295906187431466891ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1591749805152248552ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_n = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15508199106191229591ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12706738766390109874ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_n = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14926824151717422434ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4265300184804427991ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_n = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3963244754851546233ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14200531135410842044ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 4649406096255101538ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2087856356304339988ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3513938316820026578ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14920910504259349363ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 5125584176913767595ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16148341635301389461ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14407040033783681769ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1015879033800720575ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9537850199671988674ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9277621773376801637ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16466710576519601258ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14104800034790299628ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6777520270111700942ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12120840026274198972ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13539157667172858231ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11864274537290611978ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18124668556028390557ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 18429590123287474296ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 10780464776878490321ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 17368594707990590063ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 7713445653230740796ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3839292310559800212ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 6542381921518874580ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 18211326661571422338ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9650305719006726388ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10724445989403049254ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10774346691279623667ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_idx_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12987248456541209640ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_idx_n = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17495215418230505854ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 1972526789533773747ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 2175436701520605128ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10507360653198692567ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9814716967322032034ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3890944114325304234ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_n = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13392224841754289402ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15253890876428405130ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_n = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7159678192767427509ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15763144358774893099ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 16617432750669725282ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6051896247993287972ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_n = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7057467719230387211ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 12076678972255629386ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 15757061993344864747ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10652029136150121403ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1834600568180604717ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_alloc_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 18103045982326141604ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_alloc_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12194894385463315871ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11338755713044387680ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8239487971629226236ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_meta_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7973744990037495403ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_meta_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16888672027558595321ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_meta_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17253028348627098304ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_meta_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13774558056464130565ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_seg_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 4453756267302895170ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_seg_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 6974257877399089707ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_second_seg_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 13271392370139927546ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_second_seg_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 4499217164381208661ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_idx_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5349538580235911672ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_idx_n = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18296005279794288536ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 9062066321935353303ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 12811106270284102373ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17580061275673304567ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2885224049146488976ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17574386290399351671ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1854331239772223315ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9042909095728944709ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_n = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8331710456058453982ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8633097465813230682ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9860343264026332356ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 746086499974134259ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_n = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14616633383185216594ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_beat_pending_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12325191437292943365ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_beat_pending_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11764510535031525639ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r, __VscopeHash, 13025159446149173719ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n, __VscopeHash, 15235948237140605035ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_keep_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7591068138451268391ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_keep_n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6070708498858277040ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_user_r = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8696059623823411294ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_user_n = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14454938008848317359ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3081079650643274118ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13971400231161233650ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15524135923316262777ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15417340729084005367ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18302957321603157797ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13601561940299175472ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 233684314571791261ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4312769922026286829ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14462898612332152229ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1896184654957660475ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15055698547681808743ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16772310908015502439ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7597776244287375217ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9308994587414579823ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13342833477467030730ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4869020318247937068ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18270308482330393156ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5627269297391409257ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12168935887367438182ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_ok_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17509104000810663111ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_full_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11549048539627849154ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12901381584539715864ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_invalid_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7207450514310030569ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_can_fit_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10677041838200281365ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_drop_now_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17776042101673176656ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_end_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 5953990880955539342ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__first_seg_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3277531647796548717ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__second_seg_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17300035944333973516ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__next_wr_ptr_c = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 4386002927867443142ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__next_wr_wrap_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14891127263424121105ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__s_axis_keep_bytes_c = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 12280730005639271766ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__s_axis_ready_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16556631982967589806ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_fire_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1921576198450201013ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__axi_rready_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13385863440972951870ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_en_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11791185388084787830ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_idx_c = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1566575745697292993ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c, __VscopeHash, 9454749913037273322ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_keep_c = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6110580726149590502ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9201620638951213951ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_idx_c = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6037087557692329364ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_addr_c = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 16765629687465293173ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11127648444383065921ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_alloc_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1576896993914260478ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_seq_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2320889289766367982ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_valid_good_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2145293049845579515ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_overflow_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15190769269803647970ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_cur_burst_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14010441708610604137ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_cur_burst_beats_c = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6116662929663594424ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wdata_c, __VscopeHash, 16022402235304154954ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wstrb_c = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16973973280918029835ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_wlast_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14289207781456760518ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_cur_burst_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9686515216648991819ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_cur_burst_beats_c = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6934197879415055857ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_effective_bytes_in_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11955422279193320984ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_alloc_bytes_in_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 7572379687163550479ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_commit_pulse_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15657640879728968360ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_done_pulse_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3768038532510382280ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_error_pulse_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2188955185168308899ull);
    vlSelf->ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_lane_idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15330402213365950036ull);
    vlSelf->__Vfunc_align_up_u__1__Vfuncout = 0;
    vlSelf->__Vfunc_align_up_u__1__value = 0;
    vlSelf->__Vfunc_align_up_u__1__align_bytes = 0;
    vlSelf->__Vfunc_ceil_div_u__2__Vfuncout = 0;
    vlSelf->__Vfunc_ceil_div_u__2__numerator = 0;
    vlSelf->__Vfunc_ceil_div_u__2__denominator = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__ring_end_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__to_end_bytes = 0;
    vlSelf->__Vfunc_min_u__5__Vfuncout = 0;
    vlSelf->__Vfunc_min_u__5__lhs = 0;
    vlSelf->__Vfunc_min_u__5__rhs = 0;
    vlSelf->__Vfunc_ceil_div_u__6__Vfuncout = 0;
    vlSelf->__Vfunc_ceil_div_u__6__numerator = 0;
    vlSelf->__Vfunc_ceil_div_u__6__denominator = 0;
    vlSelf->__Vfunc_min_u__7__Vfuncout = 0;
    vlSelf->__Vfunc_min_u__7__lhs = 0;
    vlSelf->__Vfunc_min_u__7__rhs = 0;
    vlSelf->__Vfunc_ceil_div_u__8__Vfuncout = 0;
    vlSelf->__Vfunc_ceil_div_u__8__numerator = 0;
    vlSelf->__Vfunc_ceil_div_u__8__denominator = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__9__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__9__ptr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__base_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__ring_size_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__curr_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__advance_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__ring_end_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__to_end_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__11__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__11__ptr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__12__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__12__ptr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__base_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__ring_size_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__curr_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__advance_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__ring_end_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__to_end_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__byte_count = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__keep_mask_from_bytes__14__mask_c = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__base_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__ring_size_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__curr_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__15__ring_end_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__base_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__ring_size_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__curr_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__16__ring_end_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__base_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__ring_size_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__curr_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__17__ring_end_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__base_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__ring_size_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__curr_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__18__ring_end_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__base_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__ring_size_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__curr_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__19__ring_end_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__Vfuncout = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__base_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__ring_size_bytes = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__curr_addr = 0;
    vlSelf->__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_ring_end__20__ring_end_addr = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rst_ni__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
