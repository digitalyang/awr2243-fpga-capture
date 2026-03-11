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
    vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__extractor_u__DOT__clk_i__0 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__extractor_u__DOT__rst_ni__0 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__packer_u__DOT__clk_i__0 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni__0 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni;
    vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__clk_i__0 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rst_ni__0 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rst_ni;
}

VL_ATTR_COLD void Vtop___024root___eval_static__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk1__DOT__align_mask_addr_c = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 6554049573578223355ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk1__DOT__align_mask_size_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 18281542050888671826ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__beat_valid_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9707167282366758175ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10644411495136134602ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__last_beat_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17447537700720628607ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__lane_offset_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 6361657568199385991ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__slot_byte_index_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14862159577644463740ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10821160001372168062ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_present_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14051510238026143733ull);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop_axis_stream_if___eval_initial__TOP__pipeline_cocotb_top__DOT__slot_axis_if(Vtop_axis_stream_if* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
    Vtop_axis_stream_if___eval_initial__TOP__pipeline_cocotb_top__DOT__slot_axis_if((&vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if));
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __Vfunc_is_pow2_u__4__Vfuncout;
    __Vfunc_is_pow2_u__4__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_pow2_u__4__value;
    __Vfunc_is_pow2_u__4__value = 0;
    CData/*0:0*/ __Vfunc_is_pow2_u__5__Vfuncout;
    __Vfunc_is_pow2_u__5__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_pow2_u__5__value;
    __Vfunc_is_pow2_u__5__value = 0;
    IData/*31:0*/ __Vfunc_align_up_u__7__Vfuncout;
    __Vfunc_align_up_u__7__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_align_up_u__7__value;
    __Vfunc_align_up_u__7__value = 0;
    IData/*31:0*/ __Vfunc_align_up_u__7__align_bytes;
    __Vfunc_align_up_u__7__align_bytes = 0;
    IData/*31:0*/ __Vfunc_ceil_div_u__8__Vfuncout;
    __Vfunc_ceil_div_u__8__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_ceil_div_u__8__numerator;
    __Vfunc_ceil_div_u__8__numerator = 0;
    IData/*31:0*/ __Vfunc_ceil_div_u__8__denominator;
    __Vfunc_ceil_div_u__8__denominator = 0;
    CData/*0:0*/ __Vfunc_is_pow2_u__27__Vfuncout;
    __Vfunc_is_pow2_u__27__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_pow2_u__27__value;
    __Vfunc_is_pow2_u__27__value = 0;
    CData/*0:0*/ __Vfunc_is_pow2_u__28__Vfuncout;
    __Vfunc_is_pow2_u__28__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_is_pow2_u__28__value;
    __Vfunc_is_pow2_u__28__value = 0;
    // Body
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_alloc_bytes_in_c 
        = (0x0001ffffU & ([&]() {
                __Vfunc_align_up_u__7__align_bytes = 0x00000020U;
                __Vfunc_align_up_u__7__value = 0x000010c0U;
                {
                    __Vfunc_align_up_u__7__Vfuncout = 0U;
                    if ((1U >= __Vfunc_align_up_u__7__align_bytes)) {
                        __Vfunc_align_up_u__7__Vfuncout 
                            = __Vfunc_align_up_u__7__value;
                        goto __Vlabel0;
                    }
                    __Vfunc_align_up_u__7__Vfuncout 
                        = (([&]() {
                                __Vfunc_ceil_div_u__8__denominator 
                                    = __Vfunc_align_up_u__7__align_bytes;
                                __Vfunc_ceil_div_u__8__numerator 
                                    = __Vfunc_align_up_u__7__value;
                                {
                                    __Vfunc_ceil_div_u__8__Vfuncout = 0U;
                                    if ((0U == __Vfunc_ceil_div_u__8__denominator)) {
                                        __Vfunc_ceil_div_u__8__Vfuncout = 0U;
                                        goto __Vlabel1;
                                    }
                                    __Vfunc_ceil_div_u__8__Vfuncout 
                                        = VL_DIV_III(32, 
                                                     ((__Vfunc_ceil_div_u__8__numerator 
                                                       + __Vfunc_ceil_div_u__8__denominator) 
                                                      - (IData)(1U)), __Vfunc_ceil_div_u__8__denominator);
                                    __Vlabel1: ;
                                }
                            }(), __Vfunc_ceil_div_u__8__Vfuncout) 
                           * __Vfunc_align_up_u__7__align_bytes);
                    __Vlabel0: ;
                }
            }(), __Vfunc_align_up_u__7__Vfuncout));
    vlSelfRef.pipeline_cocotb_top__DOT__slot_bytes_o = 0x000010c0U;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_bytes_o = 0x10c0U;
    if (VL_UNLIKELY(((1U & (~ ([&]() {
                                __Vfunc_is_pow2_u__4__value = 0x00000020U;
                                {
                                    __Vfunc_is_pow2_u__4__Vfuncout = 0U;
                                    if ((0U == __Vfunc_is_pow2_u__4__value)) {
                                        __Vfunc_is_pow2_u__4__Vfuncout = 0U;
                                        goto __Vlabel2;
                                    }
                                    __Vfunc_is_pow2_u__4__Vfuncout 
                                        = (0U == (__Vfunc_is_pow2_u__4__value 
                                                  & (__Vfunc_is_pow2_u__4__value 
                                                     - (IData)(1U))));
                                    __Vlabel2: ;
                                }
                            }(), (IData)(__Vfunc_is_pow2_u__4__Vfuncout))))))) {
        VL_WRITEF_NX("[%0t] %%Error: fixed_slot_packer.sv:552: Assertion failed in %Npipeline_cocotb_top.packer_u.g_static_checks: %Npipeline_cocotb_top.packer_u.g_static_checks static assertion failed: AXIS_BEAT_BYTES must be a power of two\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/fixed_slot_packer.sv", 552, "");
        VL_WRITEF_NX("[%0t] %%Fatal: fixed_slot_packer.sv:552: Assertion failed in %Npipeline_cocotb_top.packer_u.g_static_checks\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/fixed_slot_packer.sv", 552, "", false);
    }
    if (VL_UNLIKELY(((1U & (~ ([&]() {
                                __Vfunc_is_pow2_u__5__value = 0x00000040U;
                                {
                                    __Vfunc_is_pow2_u__5__Vfuncout = 0U;
                                    if ((0U == __Vfunc_is_pow2_u__5__value)) {
                                        __Vfunc_is_pow2_u__5__Vfuncout = 0U;
                                        goto __Vlabel3;
                                    }
                                    __Vfunc_is_pow2_u__5__Vfuncout 
                                        = (0U == (__Vfunc_is_pow2_u__5__value 
                                                  & (__Vfunc_is_pow2_u__5__value 
                                                     - (IData)(1U))));
                                    __Vlabel3: ;
                                }
                            }(), (IData)(__Vfunc_is_pow2_u__5__Vfuncout))))))) {
        VL_WRITEF_NX("[%0t] %%Error: fixed_slot_packer.sv:570: Assertion failed in %Npipeline_cocotb_top.packer_u.g_static_checks: %Npipeline_cocotb_top.packer_u.g_static_checks static assertion failed: ALIGN_BYTES must be a power of two\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/fixed_slot_packer.sv", 570, "");
        VL_WRITEF_NX("[%0t] %%Fatal: fixed_slot_packer.sv:570: Assertion failed in %Npipeline_cocotb_top.packer_u.g_static_checks\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/fixed_slot_packer.sv", 570, "", false);
    }
    if (VL_UNLIKELY(((1U & (~ ([&]() {
                                __Vfunc_is_pow2_u__27__value = 0x00000020U;
                                {
                                    __Vfunc_is_pow2_u__27__Vfuncout = 0U;
                                    if ((0U == __Vfunc_is_pow2_u__27__value)) {
                                        __Vfunc_is_pow2_u__27__Vfuncout = 0U;
                                        goto __Vlabel4;
                                    }
                                    __Vfunc_is_pow2_u__27__Vfuncout 
                                        = (0U == (__Vfunc_is_pow2_u__27__value 
                                                  & (__Vfunc_is_pow2_u__27__value 
                                                     - (IData)(1U))));
                                    __Vlabel4: ;
                                }
                            }(), (IData)(__Vfunc_is_pow2_u__27__Vfuncout))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ddr_ringbuffer_controller.sv:1263: Assertion failed in %Npipeline_cocotb_top.ringbuffer_u.g_static_checks: %Npipeline_cocotb_top.ringbuffer_u.g_static_checks static assertion failed: AXI beat bytes must be power of two\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/ddr_ringbuffer_controller.sv", 1263, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ddr_ringbuffer_controller.sv:1263: Assertion failed in %Npipeline_cocotb_top.ringbuffer_u.g_static_checks\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/ddr_ringbuffer_controller.sv", 1263, "", false);
    }
    if (VL_UNLIKELY(((1U & (~ ([&]() {
                                __Vfunc_is_pow2_u__28__value = 0x00000020U;
                                {
                                    __Vfunc_is_pow2_u__28__Vfuncout = 0U;
                                    if ((0U == __Vfunc_is_pow2_u__28__value)) {
                                        __Vfunc_is_pow2_u__28__Vfuncout = 0U;
                                        goto __Vlabel5;
                                    }
                                    __Vfunc_is_pow2_u__28__Vfuncout 
                                        = (0U == (__Vfunc_is_pow2_u__28__value 
                                                  & (__Vfunc_is_pow2_u__28__value 
                                                     - (IData)(1U))));
                                    __Vlabel5: ;
                                }
                            }(), (IData)(__Vfunc_is_pow2_u__28__Vfuncout))))))) {
        VL_WRITEF_NX("[%0t] %%Error: ddr_ringbuffer_controller.sv:1264: Assertion failed in %Npipeline_cocotb_top.ringbuffer_u.g_static_checks: %Npipeline_cocotb_top.ringbuffer_u.g_static_checks static assertion failed: ADDR_ALIGN_BYTES must be power of two\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/ddr_ringbuffer_controller.sv", 1264, "");
        VL_WRITEF_NX("[%0t] %%Fatal: ddr_ringbuffer_controller.sv:1264: Assertion failed in %Npipeline_cocotb_top.ringbuffer_u.g_static_checks\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/ddr_ringbuffer_controller.sv", 1264, "", false);
    }
    vlSelfRef.pipeline_cocotb_top__DOT__slot_bytes_ctrl_c = 0x000010c0U;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_bytes_packer_c = 0x10c0U;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_bytes_i = 0x000010c0U;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_effective_bytes_in_c = 0x000010c0U;
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
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/pipeline_cocotb_top.sv", 5, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
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
    QData/*33:0*/ __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__base_addr;
    __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__base_addr = 0;
    IData/*16:0*/ __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__ring_size_bytes;
    __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__ring_size_bytes = 0;
    QData/*33:0*/ __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__curr_addr;
    __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__curr_addr = 0;
    IData/*16:0*/ __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__advance_bytes;
    __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__advance_bytes = 0;
    IData/*31:0*/ __VExpandSel_WordIdx_1;
    IData/*31:0*/ __VExpandSel_LoShift_1;
    CData/*0:0*/ __VExpandSel_Aligned_1;
    IData/*31:0*/ __VExpandSel_HiShift_1;
    IData/*31:0*/ __VExpandSel_HiMask_1;
    // Body
    vlSelfRef.slot_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__slot_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__dbg_rd_state_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r;
    vlSelfRef.pipeline_cocotb_top__DOT__dbg_wr_state_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_overflow_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_addr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__empty_o 
        = (0U == vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_r);
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_r;
    vlSelfRef.pipeline_cocotb_top__DOT__clk_i = vlSelfRef.clk_i;
    vlSelfRef.pipeline_cocotb_top__DOT__rst_ni = vlSelfRef.rst_ni;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__sample_pad_beats_c 
        = (0x000000ffU & ((IData)(0x80U) - (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r)));
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tdata[0U] 
        = vlSelfRef.s_axis_tdata[0U];
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tdata[1U] 
        = vlSelfRef.s_axis_tdata[1U];
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tdata[2U] 
        = vlSelfRef.s_axis_tdata[2U];
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tdata[3U] 
        = vlSelfRef.s_axis_tdata[3U];
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tdata[4U] 
        = vlSelfRef.s_axis_tdata[4U];
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tdata[5U] 
        = vlSelfRef.s_axis_tdata[5U];
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tdata[6U] 
        = vlSelfRef.s_axis_tdata[6U];
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tdata[7U] 
        = vlSelfRef.s_axis_tdata[7U];
    vlSelfRef.pipeline_cocotb_top__DOT__cfg_drop_invalid_pkt_i 
        = vlSelfRef.cfg_drop_invalid_pkt_i;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_crc_err_c 
        = (1U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
                 >> 1U));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_ecc_err_c 
        = (1U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
                 >> 2U));
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tkeep 
        = vlSelfRef.s_axis_tkeep;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_payload_len_c 
        = (0x0000ffffU & ((vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[1U] 
                           << 8U) | (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
                                     >> 0x00000018U)));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_bytes_c 
        = (0x0000003fU & (((1U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                  >> 1U)) + (1U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                   >> 2U))) 
                          + (((1U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                     >> 3U)) + (1U 
                                                & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                   >> 4U))) 
                             + ((1U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                       >> 5U)) + ((1U 
                                                   & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                      >> 6U)) 
                                                  + 
                                                  ((1U 
                                                    & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                       >> 7U)) 
                                                   + 
                                                   ((1U 
                                                     & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                        >> 8U)) 
                                                    + 
                                                    ((1U 
                                                      & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                         >> 9U)) 
                                                     + 
                                                     ((1U 
                                                       & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                          >> 0x0000000aU)) 
                                                      + 
                                                      ((1U 
                                                        & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                           >> 0x0000000bU)) 
                                                       + 
                                                       ((1U 
                                                         & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                            >> 0x0000000cU)) 
                                                        + 
                                                        ((1U 
                                                          & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                             >> 0x0000000dU)) 
                                                         + 
                                                         ((1U 
                                                           & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                              >> 0x0000000eU)) 
                                                          + 
                                                          ((1U 
                                                            & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                               >> 0x0000000fU)) 
                                                           + 
                                                           ((1U 
                                                             & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                >> 0x00000010U)) 
                                                            + 
                                                            ((1U 
                                                              & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                 >> 0x00000011U)) 
                                                             + 
                                                             ((1U 
                                                               & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                  >> 0x00000012U)) 
                                                              + 
                                                              ((1U 
                                                                & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                   >> 0x00000013U)) 
                                                               + 
                                                               ((1U 
                                                                 & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                    >> 0x00000014U)) 
                                                                + 
                                                                ((1U 
                                                                  & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                     >> 0x00000015U)) 
                                                                 + 
                                                                 ((1U 
                                                                   & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                      >> 0x00000016U)) 
                                                                  + 
                                                                  ((1U 
                                                                    & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                       >> 0x00000017U)) 
                                                                   + 
                                                                   ((1U 
                                                                     & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                        >> 0x00000018U)) 
                                                                    + 
                                                                    ((1U 
                                                                      & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                         >> 0x00000019U)) 
                                                                     + 
                                                                     ((1U 
                                                                       & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                          >> 0x0000001aU)) 
                                                                      + 
                                                                      ((1U 
                                                                        & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                           >> 0x0000001bU)) 
                                                                       + 
                                                                       ((1U 
                                                                         & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                            >> 0x0000001cU)) 
                                                                        + 
                                                                        ((1U 
                                                                          & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                             >> 0x0000001dU)) 
                                                                         + 
                                                                         ((1U 
                                                                           & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                              >> 0x0000001eU)) 
                                                                          + 
                                                                          ((vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                                                            >> 0x0000001fU) 
                                                                           + 
                                                                           (1U 
                                                                            & vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[3U])))))))))))))))))))))))))))))));
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tlast 
        = vlSelfRef.s_axis_tlast;
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tuser 
        = vlSelfRef.s_axis_tuser;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_trunc_err_c 
        = (1U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
                 >> 3U));
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_awready 
        = vlSelfRef.m_axi_awready;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wready 
        = vlSelfRef.m_axi_wready;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_bresp 
        = vlSelfRef.m_axi_bresp;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_bvalid 
        = vlSelfRef.m_axi_bvalid;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_arready 
        = vlSelfRef.m_axi_arready;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rdata[0U] 
        = vlSelfRef.m_axi_rdata[0U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rdata[1U] 
        = vlSelfRef.m_axi_rdata[1U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rdata[2U] 
        = vlSelfRef.m_axi_rdata[2U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rdata[3U] 
        = vlSelfRef.m_axi_rdata[3U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rdata[4U] 
        = vlSelfRef.m_axi_rdata[4U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rdata[5U] 
        = vlSelfRef.m_axi_rdata[5U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rdata[6U] 
        = vlSelfRef.m_axi_rdata[6U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rdata[7U] 
        = vlSelfRef.m_axi_rdata[7U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rresp 
        = vlSelfRef.m_axi_rresp;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rlast 
        = vlSelfRef.m_axi_rlast;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rvalid 
        = vlSelfRef.m_axi_rvalid;
    vlSelfRef.pipeline_cocotb_top__DOT__cfg_enable_i 
        = vlSelfRef.cfg_enable_i;
    vlSelfRef.pipeline_cocotb_top__DOT__cfg_allow_overwrite_i 
        = vlSelfRef.cfg_allow_overwrite_i;
    vlSelfRef.pipeline_cocotb_top__DOT__cfg_drop_on_no_space_i 
        = vlSelfRef.cfg_drop_on_no_space_i;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_req_i 
        = vlSelfRef.rd_slot_req_i;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_consume_i 
        = vlSelfRef.rd_consume_i;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_busy_o 
        = ((0U != (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r)) 
           | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r));
    vlSelfRef.pipeline_cocotb_top__DOT__cfg_drop_invalid_slot_i 
        = vlSelfRef.cfg_drop_invalid_slot_i;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_invalid_c 
        = (1U & ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r)) 
                 | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_r) 
                    | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r) 
                       | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_r) 
                          | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_r))))));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_overflow_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__actual_sample_cnt_c 
        = ((0x1000U <= (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_r))
            ? 0x00000400U : (0x000007ffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_r) 
                                            >> 2U)));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_full_c 
        = (0x20U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_r));
    vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tready 
        = vlSelfRef.m_axis_rd_tready;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__is_slot_last_beat_c 
        = (0x85U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r));
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tvalid 
        = vlSelfRef.s_axis_tvalid;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tready = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r) 
                      >> 1U)))) {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tready = 1U;
        }
    }
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_vc_c 
        = (3U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
                 >> 8U));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_dt_c 
        = (0x0000003fU & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
                          >> 0x00000010U));
    vlSelfRef.pipeline_cocotb_top__DOT__cfg_vc_en_i 
        = vlSelfRef.cfg_vc_en_i;
    vlSelfRef.pipeline_cocotb_top__DOT__cfg_dt_en_i 
        = vlSelfRef.cfg_dt_en_i;
    vlSelfRef.pipeline_cocotb_top__DOT__cfg_vc_i = vlSelfRef.cfg_vc_i;
    vlSelfRef.pipeline_cocotb_top__DOT__cfg_dt_i = vlSelfRef.cfg_dt_i;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tvalid = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__cfg_ring_base_addr_i 
        = vlSelfRef.cfg_ring_base_addr_i;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c 
        = (0U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_r));
    vlSelfRef.pipeline_cocotb_top__DOT__cfg_ring_size_bytes_i 
        = vlSelfRef.cfg_ring_size_bytes_i;
    vlSelfRef.dbg_rd_state_o = vlSelfRef.pipeline_cocotb_top__DOT__dbg_rd_state_o;
    vlSelfRef.dbg_wr_state_o = vlSelfRef.pipeline_cocotb_top__DOT__dbg_wr_state_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__used_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_ptr_o = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_valid_good_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_overflow_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_overflow_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_addr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_addr_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_seq_o;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_ptr_o = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_o;
    vlSelfRef.pipeline_cocotb_top__DOT__commit_ptr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_o;
    vlSelfRef.pipeline_cocotb_top__DOT__committed_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__empty_o = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__empty_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wrap_count_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_o;
    vlSelfRef.pipeline_cocotb_top__DOT__overflow_count_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_o;
    vlSelfRef.pipeline_cocotb_top__DOT__drop_count_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_o;
    vlSelfRef.pipeline_cocotb_top__DOT__err_cfg_align_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_o;
    vlSelfRef.pipeline_cocotb_top__DOT__err_no_space_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_o;
    vlSelfRef.pipeline_cocotb_top__DOT__err_slot_proto_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_o;
    vlSelfRef.pipeline_cocotb_top__DOT__err_slot_too_large_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_o;
    vlSelfRef.pipeline_cocotb_top__DOT__err_axi_wr_resp_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_o;
    vlSelfRef.pipeline_cocotb_top__DOT__err_axi_rd_resp_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_o;
    vlSelfRef.pipeline_cocotb_top__DOT__err_illegal_read_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_o;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__clk_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__clk_i;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__clk_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__clk_i;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__clk_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__clk_i;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__rst_ni 
        = vlSelfRef.pipeline_cocotb_top__DOT__rst_ni;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni 
        = vlSelfRef.pipeline_cocotb_top__DOT__rst_ni;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rst_ni 
        = vlSelfRef.pipeline_cocotb_top__DOT__rst_ni;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cfg_drop_invalid_pkt_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__cfg_drop_invalid_pkt_i;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h503bf3ac__0 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_trunc_err_c) 
           | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_bytes_c) 
              != (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_payload_len_c)));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h5ac0cf88__0 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_trunc_err_c) 
           | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_bytes_c) 
              > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_payload_len_c)));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_enable_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__cfg_enable_i;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_allow_overwrite_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__cfg_allow_overwrite_i;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_drop_on_no_space_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__cfg_drop_on_no_space_i;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_req_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_req_i;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_consume_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__rd_consume_i;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_busy_o = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_busy_o;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_drop_invalid_slot_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__cfg_drop_invalid_slot_i;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_overflow_err_packer_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_overflow_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_valid_good_packer_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_valid_good_o;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_packer_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_seq_o;
    VL_ASSIGN_W(512, vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c, Vtop__ConstPool__CONST_h93e1b771_0);
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[0U] 
        = (IData)((0x00000001aa551024ULL | (((QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_r)) 
                                             << 0x0000002aU) 
                                            | (((QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_r)) 
                                                << 0x00000029U) 
                                               | ((QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_r)) 
                                                  << 0x00000028U)))));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[1U] 
        = ((0xfffff800U & vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[1U]) 
           | (IData)(((0x00000001aa551024ULL | (((QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_r)) 
                                                 << 0x0000002aU) 
                                                | (((QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_r)) 
                                                    << 0x00000029U) 
                                                   | ((QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_r)) 
                                                      << 0x00000028U)))) 
                      >> 0x00000020U)));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[1U] 
        = ((0xffffe7ffU & vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[1U]) 
           | (0xfffff800U & (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_r) 
                              << 0x0000000cU) | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_r) 
                                                 << 0x0000000bU))));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[2U] 
        = (IData)((((QData)((IData)((((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__actual_sample_cnt_c) 
                                      << 0x00000010U) 
                                     | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_r)))) 
                    << 0x00000010U) | (QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_r))));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[3U] 
        = ((0xffff0000U & vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[3U]) 
           | (IData)(((((QData)((IData)((((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__actual_sample_cnt_c) 
                                          << 0x00000010U) 
                                         | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_r)))) 
                        << 0x00000010U) | (QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_r))) 
                      >> 0x00000020U)));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[4U] = 0x000010c0U;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[5U] = 0x00001000U;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[6U] 
        = (0x00000080U | (0xffff0000U & vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c[6U]));
    if ((4U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r)))) {
                vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep = 0xffffffffU;
            }
        } else {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep = 0xffffffffU;
        }
    } else if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
        vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep = 0xffffffffU;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__s_axis_keep_bytes_c 
        = (0x0000003fU & (((1U & vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep) 
                           + (1U & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                    >> 1U))) + (((1U 
                                                  & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                     >> 2U)) 
                                                 + 
                                                 (1U 
                                                  & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                     >> 3U))) 
                                                + (
                                                   (1U 
                                                    & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                       >> 4U)) 
                                                   + 
                                                   ((1U 
                                                     & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                        >> 5U)) 
                                                    + 
                                                    ((1U 
                                                      & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                         >> 6U)) 
                                                     + 
                                                     ((1U 
                                                       & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                          >> 7U)) 
                                                      + 
                                                      ((1U 
                                                        & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                           >> 8U)) 
                                                       + 
                                                       ((1U 
                                                         & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                            >> 9U)) 
                                                        + 
                                                        ((1U 
                                                          & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                             >> 0x0000000aU)) 
                                                         + 
                                                         ((1U 
                                                           & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                              >> 0x0000000bU)) 
                                                          + 
                                                          ((1U 
                                                            & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                               >> 0x0000000cU)) 
                                                           + 
                                                           ((1U 
                                                             & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                >> 0x0000000dU)) 
                                                            + 
                                                            ((1U 
                                                              & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                 >> 0x0000000eU)) 
                                                             + 
                                                             ((1U 
                                                               & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                  >> 0x0000000fU)) 
                                                              + 
                                                              ((1U 
                                                                & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                   >> 0x00000010U)) 
                                                               + 
                                                               ((1U 
                                                                 & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                    >> 0x00000011U)) 
                                                                + 
                                                                ((1U 
                                                                  & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                     >> 0x00000012U)) 
                                                                 + 
                                                                 ((1U 
                                                                   & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                      >> 0x00000013U)) 
                                                                  + 
                                                                  ((1U 
                                                                    & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                       >> 0x00000014U)) 
                                                                   + 
                                                                   ((1U 
                                                                     & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                        >> 0x00000015U)) 
                                                                    + 
                                                                    ((1U 
                                                                      & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                         >> 0x00000016U)) 
                                                                     + 
                                                                     ((1U 
                                                                       & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                          >> 0x00000017U)) 
                                                                      + 
                                                                      ((1U 
                                                                        & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                           >> 0x00000018U)) 
                                                                       + 
                                                                       ((1U 
                                                                         & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                            >> 0x00000019U)) 
                                                                        + 
                                                                        ((1U 
                                                                          & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                             >> 0x0000001aU)) 
                                                                         + 
                                                                         ((1U 
                                                                           & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                              >> 0x0000001bU)) 
                                                                          + 
                                                                          ((1U 
                                                                            & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                               >> 0x0000001cU)) 
                                                                           + 
                                                                           ((1U 
                                                                             & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                                >> 0x0000001dU)) 
                                                                            + 
                                                                            ((1U 
                                                                              & (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                                >> 0x0000001eU)) 
                                                                             + 
                                                                             (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep 
                                                                              >> 0x0000001fU)))))))))))))))))))))))))))))));
    vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tlast = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tready = 0U;
    if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
        vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tready 
            = ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)) 
               || (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tready));
    } else if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)))) {
        vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tready = 1U;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_vc_en_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__cfg_vc_en_i;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_dt_en_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__cfg_dt_en_i;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_vc_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__cfg_vc_i;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_dt_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__cfg_dt_i;
    if ((4U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r)))) {
                vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tvalid = 1U;
            }
        } else {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tvalid = 1U;
        }
    } else if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
        vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tvalid = 1U;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_start_o 
        = ((IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tvalid) 
           & (0U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r)));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_done_o 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__is_slot_last_beat_c) 
           & (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tvalid));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__cfg_ring_base_addr_i;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_o 
        = (1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c)));
    if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c) {
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_alloc_bytes_c = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c = 0ULL;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_seq_c = 0U;
    } else {
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_alloc_bytes_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_alloc_bytes_r
            [vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r];
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r
            [vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r];
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_bytes_r
            [vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r];
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_seq_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_seq_r
            [vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r];
    }
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_valid_good_c 
        = ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c)) 
           & vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_valid_good_r
           [vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r]);
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_overflow_err_c 
        = ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c)) 
           & vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_overflow_err_r
           [vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r]);
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__cfg_ring_size_bytes_i;
    vlSelfRef.wr_slot_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_bytes_o;
    vlSelfRef.used_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__used_bytes_o;
    vlSelfRef.wr_ptr_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_ptr_o;
    vlSelfRef.wr_slot_valid_good_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_valid_good_o;
    vlSelfRef.wr_slot_overflow_err_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_overflow_err_o;
    vlSelfRef.wr_slot_addr_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_addr_o;
    vlSelfRef.wr_slot_seq_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_seq_o;
    vlSelfRef.rd_ptr_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_ptr_o;
    vlSelfRef.commit_ptr_o = vlSelfRef.pipeline_cocotb_top__DOT__commit_ptr_o;
    vlSelfRef.committed_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__committed_bytes_o;
    vlSelfRef.empty_o = vlSelfRef.pipeline_cocotb_top__DOT__empty_o;
    vlSelfRef.wrap_count_o = vlSelfRef.pipeline_cocotb_top__DOT__wrap_count_o;
    vlSelfRef.overflow_count_o = vlSelfRef.pipeline_cocotb_top__DOT__overflow_count_o;
    vlSelfRef.drop_count_o = vlSelfRef.pipeline_cocotb_top__DOT__drop_count_o;
    vlSelfRef.err_cfg_align_o = vlSelfRef.pipeline_cocotb_top__DOT__err_cfg_align_o;
    vlSelfRef.err_no_space_o = vlSelfRef.pipeline_cocotb_top__DOT__err_no_space_o;
    vlSelfRef.err_slot_proto_o = vlSelfRef.pipeline_cocotb_top__DOT__err_slot_proto_o;
    vlSelfRef.err_slot_too_large_o = vlSelfRef.pipeline_cocotb_top__DOT__err_slot_too_large_o;
    vlSelfRef.err_axi_wr_resp_o = vlSelfRef.pipeline_cocotb_top__DOT__err_axi_wr_resp_o;
    vlSelfRef.err_axi_rd_resp_o = vlSelfRef.pipeline_cocotb_top__DOT__err_axi_rd_resp_o;
    vlSelfRef.err_illegal_read_o = vlSelfRef.pipeline_cocotb_top__DOT__err_illegal_read_o;
    vlSelfRef.rd_busy_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_busy_o;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_drop_now_c 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_drop_invalid_slot_i) 
           & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_invalid_c));
    vlSelfRef.pipeline_cocotb_top__DOT__slot_overflow_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_overflow_err_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_overflow_err_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_overflow_err_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_valid_good_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_valid_good_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_valid_good_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_ctrl_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_packer_c;
    VL_ASSIGN_W(256, vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
    if ((4U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r)))) {
                vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tlast 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__is_slot_last_beat_c;
                VL_ASSIGN_W(256, vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
            }
        } else {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tlast 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__is_slot_last_beat_c;
            VL_ASSIGN_W(256, vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
        }
    } else if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
        vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tlast 
            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__is_slot_last_beat_c;
        __VExpandSel_WordIdx_1 = (0x0000000fU & (VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r), 8U) 
                                                 >> 5U));
        __VExpandSel_LoShift_1 = (0x0000001fU & VL_SHIFTL_III(9,32,32, (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r), 8U));
        __VExpandSel_Aligned_1 = (0U == __VExpandSel_LoShift_1);
        if (__VExpandSel_Aligned_1) {
            __VExpandSel_HiShift_1 = 0U;
            __VExpandSel_HiMask_1 = 0U;
        } else {
            __VExpandSel_HiShift_1 = ((IData)(0x00000020U) 
                                      - __VExpandSel_LoShift_1);
            __VExpandSel_HiMask_1 = 0xffffffffU;
        }
        if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[0U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))][0U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[1U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))][1U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[2U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))][2U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[3U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))][3U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[4U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))][4U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[5U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))][5U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[6U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))][6U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[7U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r
                [(0x0000007fU & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))][7U];
        } else {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[0U] 
                = (((vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                     [((IData)(1U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                      [__VExpandSel_WordIdx_1] >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[1U] 
                = (((vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                     [((IData)(2U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                      [((IData)(1U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[2U] 
                = (((vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                     [((IData)(3U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                      [((IData)(2U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[3U] 
                = (((vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                     [((IData)(4U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                      [((IData)(3U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[4U] 
                = (((vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                     [((IData)(5U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                      [((IData)(4U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[5U] 
                = (((vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                     [((IData)(6U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                      [((IData)(5U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[6U] 
                = (((vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                     [((IData)(7U) + __VExpandSel_WordIdx_1)] 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                      [((IData)(6U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[7U] 
                = (((((8U <= __VExpandSel_WordIdx_1)
                       ? 0U : vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                      [((IData)(8U) + __VExpandSel_WordIdx_1)]) 
                     << __VExpandSel_HiShift_1) & __VExpandSel_HiMask_1) 
                   | (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c
                      [((IData)(7U) + __VExpandSel_WordIdx_1)] 
                      >> __VExpandSel_LoShift_1));
        }
    }
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tready 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tready;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c 
        = (1U & (((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_vc_en_i)) 
                  | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_vc_i) 
                     == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_vc_c))) 
                 & ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_dt_en_i)) 
                    | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_dt_i) 
                       == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_dt_c)))));
    vlSelfRef.pipeline_cocotb_top__DOT__slot_start_packer_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_start_o;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_done_packer_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_done_o;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_valid_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_o;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_seq_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_valid_good_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_overflow_err_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk1__DOT__align_mask_addr_c = 0x000000000000001fULL;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk1__DOT__align_mask_size_c = 0x0000001fU;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_ok_c 
        = ((((0U != vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i) 
             & (0x00010000U >= vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i)) 
            & (0ULL == (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i 
                        & vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk1__DOT__align_mask_addr_c))) 
           & (0U == (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i 
                     & vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk1__DOT__align_mask_size_c)));
    __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__advance_bytes 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r;
    __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__curr_addr 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r;
    __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__ring_size_bytes 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i;
    __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__base_addr 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
    {
        vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__Vfuncout = 0;
        vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__ring_end_addr = 0;
        vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__to_end_bytes = 0;
        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__ring_end_addr 
            = (0x00000003ffffffffULL & (__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__base_addr 
                                        + (QData)((IData)(__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__ring_size_bytes))));
        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__to_end_bytes 
            = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__ring_end_addr) 
                              - (IData)(__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__curr_addr)));
        if ((__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__advance_bytes 
             < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__to_end_bytes)) {
            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__Vfuncout 
                = (0x00000003ffffffffULL & (__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__curr_addr 
                                            + (QData)((IData)(__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__advance_bytes))));
            goto __Vlabel0;
        } else if ((__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__advance_bytes 
                    == vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__to_end_bytes)) {
            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__Vfuncout 
                = __Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__base_addr;
            goto __Vlabel0;
        }
        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__Vfuncout 
            = (0x00000003ffffffffULL & (__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__base_addr 
                                        + ((QData)((IData)(__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__advance_bytes)) 
                                           - (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__to_end_bytes)))));
        __Vlabel0: ;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__next_wr_ptr_c 
        = vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__Vfuncout;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_c 
        = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i 
                          - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_r));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_end_c 
        = (0x0001ffffU & (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i) 
                           + vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i) 
                          - (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r)));
    vlSelfRef.slot_overflow_err_o = vlSelfRef.pipeline_cocotb_top__DOT__slot_overflow_err_o;
    vlSelfRef.slot_valid_good_o = vlSelfRef.pipeline_cocotb_top__DOT__slot_valid_good_o;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_ctrl_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_seq_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_ctrl_c;
    vlSelfRef.s_axis_tready = vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tready;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_start_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_start_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_start_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_start_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_done_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_done_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_done_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_done_packer_c;
    vlSelfRef.rd_slot_valid_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_valid_o;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_addr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_o;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_o;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_o;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_overflow_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__full_o 
        = ((0U == vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_c) 
           | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_full_c));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__almost_full_o 
        = ((0x00001000U >= vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_c) 
           | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_full_c));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_can_fit_c 
        = ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_full_c)) 
           & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r 
              <= vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_c));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__next_wr_wrap_c 
        = (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r 
           >= vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_end_c);
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__first_seg_bytes_c 
        = ((vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r 
            <= vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_end_c)
            ? vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r
            : vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_end_c);
    vlSelfRef.slot_seq_o = vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_o;
    vlSelfRef.slot_start_o = vlSelfRef.pipeline_cocotb_top__DOT__slot_start_o;
    vlSelfRef.slot_done_o = vlSelfRef.pipeline_cocotb_top__DOT__slot_done_o;
    vlSelfRef.rd_slot_addr_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_addr_o;
    vlSelfRef.rd_slot_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_bytes_o;
    vlSelfRef.rd_slot_seq_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_seq_o;
    vlSelfRef.rd_slot_valid_good_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_valid_good_o;
    vlSelfRef.rd_slot_overflow_err_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_overflow_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__free_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__full_o = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__full_o;
    vlSelfRef.pipeline_cocotb_top__DOT__almost_full_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__almost_full_o;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__second_seg_bytes_c 
        = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r 
                          - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__first_seg_bytes_c));
    vlSelfRef.free_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__free_bytes_o;
    vlSelfRef.full_o = vlSelfRef.pipeline_cocotb_top__DOT__full_o;
    vlSelfRef.almost_full_o = vlSelfRef.pipeline_cocotb_top__DOT__almost_full_o;
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<8>/*255:0*/ __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout;
    VL_ZERO_W(256, __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout);
    VlWide<8>/*255:0*/ __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data;
    VL_ZERO_W(256, __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data);
    IData/*31:0*/ __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep;
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep = 0;
    VlWide<8>/*255:0*/ __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result;
    VL_ZERO_W(256, __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result);
    // Body
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[0U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tdata[0U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[1U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tdata[1U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[2U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tdata[2U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[3U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tdata[3U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[4U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tdata[4U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[5U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tdata[5U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[6U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tdata[6U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[7U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tdata[7U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tkeep 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tkeep;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tvalid 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tvalid;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tlast 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tlast;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tuser 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tuser;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_fire_c 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r) 
           & (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tready));
    VL_ASSIGN_W(256, vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c 
        = (0x0000003fU & (((1U & vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep) 
                           + (1U & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                    >> 1U))) + (((1U 
                                                  & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                     >> 2U)) 
                                                 + 
                                                 (1U 
                                                  & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                     >> 3U))) 
                                                + (
                                                   (1U 
                                                    & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                       >> 4U)) 
                                                   + 
                                                   ((1U 
                                                     & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                        >> 5U)) 
                                                    + 
                                                    ((1U 
                                                      & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                         >> 6U)) 
                                                     + 
                                                     ((1U 
                                                       & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                          >> 7U)) 
                                                      + 
                                                      ((1U 
                                                        & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                           >> 8U)) 
                                                       + 
                                                       ((1U 
                                                         & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                            >> 9U)) 
                                                        + 
                                                        ((1U 
                                                          & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                             >> 0x0000000aU)) 
                                                         + 
                                                         ((1U 
                                                           & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                              >> 0x0000000bU)) 
                                                          + 
                                                          ((1U 
                                                            & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                               >> 0x0000000cU)) 
                                                           + 
                                                           ((1U 
                                                             & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                >> 0x0000000dU)) 
                                                            + 
                                                            ((1U 
                                                              & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                 >> 0x0000000eU)) 
                                                             + 
                                                             ((1U 
                                                               & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                  >> 0x0000000fU)) 
                                                              + 
                                                              ((1U 
                                                                & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                   >> 0x00000010U)) 
                                                               + 
                                                               ((1U 
                                                                 & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                    >> 0x00000011U)) 
                                                                + 
                                                                ((1U 
                                                                  & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                     >> 0x00000012U)) 
                                                                 + 
                                                                 ((1U 
                                                                   & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                      >> 0x00000013U)) 
                                                                  + 
                                                                  ((1U 
                                                                    & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                       >> 0x00000014U)) 
                                                                   + 
                                                                   ((1U 
                                                                     & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                        >> 0x00000015U)) 
                                                                    + 
                                                                    ((1U 
                                                                      & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                         >> 0x00000016U)) 
                                                                     + 
                                                                     ((1U 
                                                                       & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                          >> 0x00000017U)) 
                                                                      + 
                                                                      ((1U 
                                                                        & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                           >> 0x00000018U)) 
                                                                       + 
                                                                       ((1U 
                                                                         & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                            >> 0x00000019U)) 
                                                                        + 
                                                                        ((1U 
                                                                          & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                             >> 0x0000001aU)) 
                                                                         + 
                                                                         ((1U 
                                                                           & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                              >> 0x0000001bU)) 
                                                                          + 
                                                                          ((1U 
                                                                            & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                               >> 0x0000001cU)) 
                                                                           + 
                                                                           ((1U 
                                                                             & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                                >> 0x0000001dU)) 
                                                                            + 
                                                                            ((1U 
                                                                              & (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                                >> 0x0000001eU)) 
                                                                             + 
                                                                             (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                                                                              >> 0x0000001fU)))))))))))))))))))))))))))))));
    vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tlast = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_crc_err_c 
        = (1U & (IData)((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tuser 
                         >> 1U)));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_ecc_err_c 
        = (1U & (IData)((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tuser 
                         >> 2U)));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_trunc_err_c 
        = (1U & (IData)((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tuser 
                         >> 3U)));
    vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tuser = 0ULL;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c 
        = ((IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tready) 
           & (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tvalid));
    vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tvalid = 0U;
    if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
        if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)))) {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[0U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[0U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[1U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[1U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[2U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[2U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[3U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[3U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[4U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[4U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[5U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[5U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[6U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[6U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[7U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[7U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep;
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tlast 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tlast;
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tuser 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tuser;
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tvalid 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tvalid;
        }
    } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
        if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c) {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[0U] 
                = ((vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[4U] 
                    << 0x0000001fU) | (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[3U] 
                                       >> 1U));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[1U] 
                = ((vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[5U] 
                    << 0x0000001fU) | (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[4U] 
                                       >> 1U));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[2U] 
                = ((vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[6U] 
                    << 0x0000001fU) | (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[5U] 
                                       >> 1U));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[3U] 
                = ((vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[7U] 
                    << 0x0000001fU) | (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[6U] 
                                       >> 1U));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[4U] 
                = ((vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[8U] 
                    << 0x0000001fU) | (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[7U] 
                                       >> 1U));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[5U] 
                = ((vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[9U] 
                    << 0x0000001fU) | (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[8U] 
                                       >> 1U));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[6U] 
                = ((vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[10U] 
                    << 0x0000001fU) | (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[9U] 
                                       >> 1U));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[7U] 
                = ((vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[11U] 
                    << 0x0000001fU) | (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[10U] 
                                       >> 1U));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                = ((vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[3U] 
                    << 0x0000001fU) | (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
                                       >> 1U));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tlast 
                = (1U & vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U]);
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tuser 
                = (((QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[1U])) 
                    << 0x00000020U) | (QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U])));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tvalid = 1U;
        }
    }
    vlSelfRef.m_axis_rd_tdata[0U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[0U];
    vlSelfRef.m_axis_rd_tdata[1U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[1U];
    vlSelfRef.m_axis_rd_tdata[2U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[2U];
    vlSelfRef.m_axis_rd_tdata[3U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[3U];
    vlSelfRef.m_axis_rd_tdata[4U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[4U];
    vlSelfRef.m_axis_rd_tdata[5U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[5U];
    vlSelfRef.m_axis_rd_tdata[6U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[6U];
    vlSelfRef.m_axis_rd_tdata[7U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[7U];
    vlSelfRef.m_axis_rd_tkeep = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tkeep;
    vlSelfRef.m_axis_rd_tvalid = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tvalid;
    vlSelfRef.m_axis_rd_tlast = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tlast;
    vlSelfRef.m_axis_rd_tuser = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tuser;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_idx_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_idx_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_alloc_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_alloc_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_meta_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_meta_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_meta_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_meta_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_seg_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_seg_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_second_seg_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_second_seg_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_idx_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_idx_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_beat_pending_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_beat_pending_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[0U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[0U];
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[1U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[1U];
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[2U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[2U];
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[3U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[3U];
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[4U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[4U];
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[5U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[5U];
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[6U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[6U];
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[7U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[7U];
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__s_axis_ready_c = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awaddr = 0ULL;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awlen = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awsize = 5U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awburst = 1U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awvalid = 0U;
    VL_ASSIGN_W(256, vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wstrb = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wlast = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wvalid = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.bready = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.araddr = 0ULL;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.arlen = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.arsize = 5U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.arburst = 1U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.arvalid = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rready = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__axi_rready_c = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_en_c = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_idx_c = 0U;
    VL_ASSIGN_W(256, vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_keep_c = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_c = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_idx_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_cur_burst_bytes_c 
        = (0x0001ffffU & ([&]() {
                vlSelfRef.__Vfunc_min_u__11__rhs = 0x00000200U;
                vlSelfRef.__Vfunc_min_u__11__lhs = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_r;
                {
                    vlSelfRef.__Vfunc_min_u__11__Vfuncout = 0U;
                    if ((vlSelfRef.__Vfunc_min_u__11__lhs 
                         < vlSelfRef.__Vfunc_min_u__11__rhs)) {
                        vlSelfRef.__Vfunc_min_u__11__Vfuncout 
                            = vlSelfRef.__Vfunc_min_u__11__lhs;
                        goto __Vlabel0;
                    }
                    vlSelfRef.__Vfunc_min_u__11__Vfuncout 
                        = vlSelfRef.__Vfunc_min_u__11__rhs;
                    __Vlabel0: ;
                }
            }(), vlSelfRef.__Vfunc_min_u__11__Vfuncout));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_cur_burst_beats_c 
        = (0x0000001fU & ([&]() {
                vlSelfRef.__Vfunc_ceil_div_u__12__denominator = 0x00000020U;
                vlSelfRef.__Vfunc_ceil_div_u__12__numerator 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_cur_burst_bytes_c;
                {
                    vlSelfRef.__Vfunc_ceil_div_u__12__Vfuncout = 0U;
                    if ((0U == vlSelfRef.__Vfunc_ceil_div_u__12__denominator)) {
                        vlSelfRef.__Vfunc_ceil_div_u__12__Vfuncout = 0U;
                        goto __Vlabel1;
                    }
                    vlSelfRef.__Vfunc_ceil_div_u__12__Vfuncout 
                        = VL_DIV_III(32, ((vlSelfRef.__Vfunc_ceil_div_u__12__numerator 
                                           + vlSelfRef.__Vfunc_ceil_div_u__12__denominator) 
                                          - (IData)(1U)), vlSelfRef.__Vfunc_ceil_div_u__12__denominator);
                    __Vlabel1: ;
                }
            }(), vlSelfRef.__Vfunc_ceil_div_u__12__Vfuncout));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_cur_burst_bytes_c 
        = (0x0001ffffU & ([&]() {
                vlSelfRef.__Vfunc_min_u__13__rhs = 0x00000200U;
                vlSelfRef.__Vfunc_min_u__13__lhs = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_r;
                {
                    vlSelfRef.__Vfunc_min_u__13__Vfuncout = 0U;
                    if ((vlSelfRef.__Vfunc_min_u__13__lhs 
                         < vlSelfRef.__Vfunc_min_u__13__rhs)) {
                        vlSelfRef.__Vfunc_min_u__13__Vfuncout 
                            = vlSelfRef.__Vfunc_min_u__13__lhs;
                        goto __Vlabel2;
                    }
                    vlSelfRef.__Vfunc_min_u__13__Vfuncout 
                        = vlSelfRef.__Vfunc_min_u__13__rhs;
                    __Vlabel2: ;
                }
            }(), vlSelfRef.__Vfunc_min_u__13__Vfuncout));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_cur_burst_beats_c 
        = (0x0000001fU & ([&]() {
                vlSelfRef.__Vfunc_ceil_div_u__14__denominator = 0x00000020U;
                vlSelfRef.__Vfunc_ceil_div_u__14__numerator 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_cur_burst_bytes_c;
                {
                    vlSelfRef.__Vfunc_ceil_div_u__14__Vfuncout = 0U;
                    if ((0U == vlSelfRef.__Vfunc_ceil_div_u__14__denominator)) {
                        vlSelfRef.__Vfunc_ceil_div_u__14__Vfuncout = 0U;
                        goto __Vlabel3;
                    }
                    vlSelfRef.__Vfunc_ceil_div_u__14__Vfuncout 
                        = VL_DIV_III(32, ((vlSelfRef.__Vfunc_ceil_div_u__14__numerator 
                                           + vlSelfRef.__Vfunc_ceil_div_u__14__denominator) 
                                          - (IData)(1U)), vlSelfRef.__Vfunc_ceil_div_u__14__denominator);
                    __Vlabel3: ;
                }
            }(), vlSelfRef.__Vfunc_ceil_div_u__14__Vfuncout));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__beat_valid_bytes_c = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c = 0ULL;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__last_beat_c = 0U;
    VL_ASSIGN_W(256, vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wdata_c, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wstrb_c = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wlast_c 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_r) 
           == (0x0000001fU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_r) 
                              - (IData)(1U))));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx = 0U;
    while ((0x00000020U > vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx)) {
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__lane_offset_c 
            = (0x0001ffffU & vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx);
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__slot_byte_index_c 
            = (0x0001ffffU & VL_SHIFTL_III(17,17,32, 
                                           ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_r) 
                                            + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_r)), 5U));
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c 
            = (0x000000ffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_r) 
                              + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_r)));
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_present_c 
            = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c) 
               < (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_r));
        if (((0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__slot_byte_index_c 
                             + vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__lane_offset_c)) 
             < vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r)) {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wstrb_c 
                = (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wstrb_c 
                   | (0x00000000ffffffffULL & ((IData)(1U) 
                                               << (0x0000001fU 
                                                   & vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx))));
            if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_present_c) 
                 & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_keep_r
                    [vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c] 
                    >> (0x0000001fU & vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx)))) {
                VL_ASSIGNSEL_WI(256, 8, (0x000000ffU 
                                         & VL_MULS_III(32, (IData)(8U), vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx)), vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wdata_c, 
                                (0x000000ffU & (((0U 
                                                  == 
                                                  (0x0000001fU 
                                                   & VL_MULS_III(32, (IData)(8U), vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx)))
                                                  ? 0U
                                                  : 
                                                 (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r
                                                  [vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c]
                                                  [
                                                  (((IData)(7U) 
                                                    + 
                                                    (0x000000ffU 
                                                     & VL_MULS_III(32, (IData)(8U), vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx))) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & VL_MULS_III(32, (IData)(8U), vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx))))) 
                                                | (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r
                                                   [vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__unnamedblk3__DOT__beat_index_c]
                                                   [
                                                   (7U 
                                                    & (VL_MULS_III(32, (IData)(8U), vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx) 
                                                       >> 5U))] 
                                                   >> 
                                                   (0x0000001fU 
                                                    & VL_MULS_III(32, (IData)(8U), vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx))))));
            }
        }
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx 
            = ((IData)(1U) + vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx);
    }
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_commit_pulse_c = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_done_pulse_c = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_error_pulse_c = 0U;
    if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_enable_i) 
         & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_ok_c)))) {
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_n = 1U;
    }
    if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_fire_c) {
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_n = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_n = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_n = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_n = 0ULL;
    }
    if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_consume_i) 
         & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_req_i))) {
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_n = 1U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_error_pulse_c = 1U;
    }
    if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_consume_i) 
         & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_req_i)))) {
        if ((1U & ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_busy_o)) 
                   & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c))))) {
            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__15__ptr 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r;
            {
                vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__15__Vfuncout = 0;
                if ((0x1fU == (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__15__ptr))) {
                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__15__Vfuncout = 0U;
                    goto __Vlabel4;
                }
                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__15__Vfuncout 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__15__ptr)));
                __Vlabel4: ;
            }
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_n 
                = vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__15__Vfuncout;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_n 
                = (0x0000003fU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_n) 
                                  - (IData)(1U)));
            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__advance_bytes 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_alloc_bytes_c;
            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__curr_addr 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_r;
            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__ring_size_bytes 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i;
            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__base_addr 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
            {
                vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__Vfuncout = 0;
                vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__ring_end_addr = 0;
                vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__to_end_bytes = 0;
                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__ring_end_addr 
                    = (0x00000003ffffffffULL & (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__base_addr 
                                                + (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__ring_size_bytes))));
                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__to_end_bytes 
                    = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__ring_end_addr) 
                                      - (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__curr_addr)));
                if ((vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__advance_bytes 
                     < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__to_end_bytes)) {
                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__Vfuncout 
                        = (0x00000003ffffffffULL & 
                           (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__curr_addr 
                            + (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__advance_bytes))));
                    goto __Vlabel5;
                } else if ((vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__advance_bytes 
                            == vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__to_end_bytes)) {
                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__Vfuncout 
                        = vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__base_addr;
                    goto __Vlabel5;
                }
                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__Vfuncout 
                    = (0x00000003ffffffffULL & (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__base_addr 
                                                + ((QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__advance_bytes)) 
                                                   - (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__to_end_bytes)))));
                __Vlabel5: ;
            }
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_n 
                = vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__Vfuncout;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_n 
                = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_n 
                                  - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_alloc_bytes_c));
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_n 
                = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_n 
                                  - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_alloc_bytes_c));
        } else if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c) 
                    | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_busy_o))) {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_n = 1U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_error_pulse_c = 1U;
        }
    }
    if ((8U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) {
        if ((4U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 0U;
        } else if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 0U;
        } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 0U;
        } else {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_n 
                = ((IData)(1U) + vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_n);
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_n = 0ULL;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_n = 0ULL;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_n = 0U;
        }
    } else if ((4U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) {
        if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) {
            if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_r;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_n 
                    = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_n 
                                      + vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r));
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_c = 1U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_idx_c 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_r;
                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__17__ptr 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_r;
                {
                    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__17__Vfuncout = 0;
                    if ((0x1fU == (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__17__ptr))) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__17__Vfuncout = 0U;
                        goto __Vlabel6;
                    }
                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__17__Vfuncout 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__17__ptr)));
                    __Vlabel6: ;
                }
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_n 
                    = vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__17__Vfuncout;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_n 
                    = (0x0000003fU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_n)));
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_commit_pulse_c = 1U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_n = 0ULL;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_n = 0ULL;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_n = 0U;
            } else {
                vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.bready = 1U;
                if (vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.bvalid) {
                    if ((0U != (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.bresp))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_n = 1U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_n 
                            = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_n 
                                              - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r));
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_n 
                            = (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_n 
                               - (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_r));
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_n 
                            = ((IData)(1U) + vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_n);
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_n = 0ULL;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_n = 0ULL;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_n = 0U;
                    } else if ((0U != (0x0001ffffU 
                                       & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_r 
                                          - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_r)))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_n 
                            = (0x00000003ffffffffULL 
                               & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_r 
                                  + (QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_r))));
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_n 
                            = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_r 
                                              - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_r));
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_n 
                            = (0x000000ffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_r) 
                                              + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_r)));
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 4U;
                    } else if (((0U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_idx_r)) 
                                & (0U != vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_r))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_idx_n = 1U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_r;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_n 
                            = (0x000000ffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_r) 
                                              + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_r)));
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 4U;
                    } else {
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 7U;
                    }
                }
            }
        } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[0U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wdata_c[0U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[1U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wdata_c[1U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[2U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wdata_c[2U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[3U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wdata_c[3U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[4U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wdata_c[4U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[5U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wdata_c[5U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[6U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wdata_c[6U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[7U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wdata_c[7U];
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wstrb 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wstrb_c;
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wlast 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wlast_c;
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wvalid = 1U;
            if (vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wready) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wlast_c) {
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 6U;
                } else {
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_n 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_r)));
                }
            }
        } else {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awaddr 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_r;
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awlen 
                = (0x000000ffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_cur_burst_beats_c) 
                                  - (IData)(1U)));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awvalid = 1U;
            if (vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awready) {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_cur_burst_bytes_c;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_cur_burst_beats_c;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 5U;
            }
        }
    } else if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) {
        if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) {
            if ((1U & (((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_busy_o)) 
                        & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c))) 
                       & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_consume_i))))) {
                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__18__ptr 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r;
                {
                    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__18__Vfuncout = 0;
                    if ((0x1fU == (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__18__ptr))) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__18__Vfuncout = 0U;
                        goto __Vlabel7;
                    }
                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__18__Vfuncout 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__18__ptr)));
                    __Vlabel7: ;
                }
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_n 
                    = vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__18__Vfuncout;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_n 
                    = (0x0000003fU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_n) 
                                      - (IData)(1U)));
                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__advance_bytes 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_alloc_bytes_c;
                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__curr_addr 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_r;
                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__ring_size_bytes 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i;
                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__base_addr 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
                {
                    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__Vfuncout = 0;
                    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__ring_end_addr = 0;
                    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__to_end_bytes = 0;
                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__ring_end_addr 
                        = (0x00000003ffffffffULL & 
                           (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__base_addr 
                            + (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__ring_size_bytes))));
                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__to_end_bytes 
                        = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__ring_end_addr) 
                                          - (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__curr_addr)));
                    if ((vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__advance_bytes 
                         < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__to_end_bytes)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__Vfuncout 
                            = (0x00000003ffffffffULL 
                               & (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__curr_addr 
                                  + (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__advance_bytes))));
                        goto __Vlabel8;
                    } else if ((vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__advance_bytes 
                                == vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__to_end_bytes)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__Vfuncout 
                            = vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__base_addr;
                        goto __Vlabel8;
                    }
                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__Vfuncout 
                        = (0x00000003ffffffffULL & 
                           (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__base_addr 
                            + ((QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__advance_bytes)) 
                               - (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__to_end_bytes)))));
                    __Vlabel8: ;
                }
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_n 
                    = vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__Vfuncout;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_n 
                    = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_n 
                                      - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_alloc_bytes_c));
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_n 
                    = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_n 
                                      - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_alloc_bytes_c));
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_n 
                    = ((IData)(1U) + vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_n);
            }
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 2U;
        } else if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_ok_c) {
            if (((((0U == vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r) 
                   | (0U == vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r)) 
                  | (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r 
                     > vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i)) 
                 | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_r))) {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_n = 1U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 8U;
            } else if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_drop_now_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 8U;
            } else if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_can_fit_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__next_wr_ptr_c;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__first_seg_bytes_c;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__second_seg_bytes_c;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__next_wr_wrap_c;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__next_wr_ptr_c;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_n 
                    = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_n 
                                      + vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r));
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_n 
                    = (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_n 
                       + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__next_wr_wrap_c));
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_idx_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__first_seg_bytes_c;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n 
                    = ((0U != vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__first_seg_bytes_c)
                        ? 4U : 7U);
            } else {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_n = 1U;
                if ((((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_allow_overwrite_i) 
                      & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_busy_o))) 
                     & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c)))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 3U;
                } else if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_drop_on_no_space_i) {
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 8U;
                }
            }
        } else {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_n = 1U;
        }
    } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) {
        if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_enable_i) 
             & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_ok_c))) {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__s_axis_ready_c = 1U;
            if (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tvalid) {
                if ((0x0100U > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_r))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_en_c = 1U;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_idx_c 
                        = (0x000000ffU & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_r));
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[0U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[0U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[1U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[1U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[2U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[2U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[3U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[3U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[4U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[4U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[5U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[5U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[6U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[6U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[7U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[7U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_keep_c 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_n 
                        = (0x000001ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_r)));
                } else {
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_n = 1U;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_n = 1U;
                }
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_n 
                    = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_r 
                                      + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__s_axis_keep_bytes_c)));
                if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_start_i) 
                     | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_done_i) 
                        & (~ (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tlast))))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_n = 1U;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_n = 1U;
                }
                if (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tlast) {
                    if ((1U & ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_done_i)) 
                               | ((0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_r 
                                                  + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__s_axis_keep_bytes_c))) 
                                  != vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r)))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_n = 1U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_n = 1U;
                    }
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 2U;
                }
            }
        }
    } else if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_enable_i) 
                & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_ok_c))) {
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__s_axis_ready_c = 1U;
        if (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tvalid) {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_en_c = 1U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_idx_c = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[0U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[0U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[1U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[1U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[2U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[2U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[3U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[3U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[4U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[4U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[5U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[5U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[6U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[6U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[7U] 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tdata[7U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_keep_c 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_n = 1U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__s_axis_keep_bytes_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_n = 0x000010c0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_alloc_bytes_in_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_seq_i;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_valid_good_i;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_overflow_err_i;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_n 
                = (1U & ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_start_i)) 
                         | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_done_i) 
                            & (~ (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tlast)))));
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_n = 0ULL;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_n = 0ULL;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_n = 0U;
            if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_overflow_err_i) {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_n 
                    = ((IData)(1U) + vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_n);
            }
            if (vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tlast) {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_n = 1U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_n = 1U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 2U;
            } else {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = 1U;
            }
        }
    }
    if ((4U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r))) {
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n = 0U;
    } else if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r))) {
        if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r))) {
            if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_fire_c) 
                 & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_r))) {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_done_pulse_c = 1U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n = 0U;
            } else if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r)))) {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_done_pulse_c = 1U;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n = 0U;
            }
        } else {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__axi_rready_c 
                = (1U & ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r)) 
                         | (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tready)));
            vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rready 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__axi_rready_c;
            if (((IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rvalid) 
                 & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__axi_rready_c))) {
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__beat_valid_bytes_c 
                    = ((0x00000020U <= vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_r)
                        ? 0x00000020U : vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_r);
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__last_beat_c 
                    = (0x00000020U >= vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_r);
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c = 0ULL;
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c 
                    = ((0xfffffffffffffff1ULL & vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c) 
                       | ((QData)((IData)((((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_meta_r) 
                                            << 2U) 
                                           | (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_meta_r) 
                                               << 1U) 
                                              | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__last_beat_c))))) 
                          << 1U));
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c 
                    = ((0xffffffffff0000ffULL & vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c) 
                       | ((QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_r)) 
                          << 8U));
                vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c 
                    = ((0xfffe0000ffffffffULL & vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c) 
                       | ((QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_r)) 
                          << 0x00000020U));
                if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_beat_pending_r) {
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c 
                        = (1ULL | vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c);
                }
                if ((0U != (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rresp))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_n = 1U;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_n = 1U;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_error_pulse_c = 1U;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n = 0U;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_n = 0U;
                } else {
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[0U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rdata[0U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[1U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rdata[1U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[2U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rdata[2U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[3U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rdata[3U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[4U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rdata[4U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[5U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rdata[5U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[6U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rdata[6U];
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[7U] 
                        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rdata[7U];
                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count 
                        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__beat_valid_bytes_c;
                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c = 0U;
                    if ((0U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (1U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((1U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (2U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((2U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (4U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((3U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (8U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((4U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00000010U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((5U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00000020U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((6U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00000040U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((7U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00000080U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((8U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00000100U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((9U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00000200U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000000aU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00000400U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000000bU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00000800U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000000cU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00001000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000000dU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00002000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000000eU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00004000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000000fU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00008000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x00000010U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00010000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x00000011U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00020000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x00000012U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00040000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x00000013U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00080000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x00000014U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00100000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x00000015U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00200000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x00000016U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00400000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x00000017U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x00800000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x00000018U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x01000000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x00000019U < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x02000000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000001aU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x04000000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000001bU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x08000000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000001cU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x10000000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000001dU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x20000000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000001eU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x40000000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    if ((0x0000001fU < vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count)) {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c 
                            = (0x80000000U | vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c);
                    }
                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__Vfuncout 
                        = vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_n 
                        = vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__Vfuncout;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__axis_user_c;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__last_beat_c;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_n = 1U;
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_n 
                        = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_r 
                                          - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__unnamedblk2__DOT__beat_valid_bytes_c));
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_n 
                        = (0x0000001fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_r)));
                    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_beat_pending_n = 0U;
                    if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_r) 
                         == (0x0000001fU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_r) 
                                            - (IData)(1U))))) {
                        if ((0U != (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_r 
                                                   - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_r)))) {
                            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_n 
                                = (0x00000003ffffffffULL 
                                   & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_r 
                                      + (QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_r))));
                            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_n 
                                = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_r 
                                                  - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_r));
                            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n = 1U;
                        } else if (((0U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_idx_r)) 
                                    & (0U != vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_second_seg_bytes_r))) {
                            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_idx_n = 1U;
                            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_n 
                                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
                            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_n 
                                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_second_seg_bytes_r;
                            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n = 1U;
                        } else {
                            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n = 3U;
                        }
                    }
                    if (((IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rlast) 
                         != ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_r) 
                             == (0x0000001fU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_r) 
                                                - (IData)(1U)))))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_n = 1U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_error_pulse_c = 1U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_n = 0ULL;
                    }
                }
            }
        }
    } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r))) {
        vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.araddr 
            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_r;
        vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.arlen 
            = (0x000000ffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_cur_burst_beats_c) 
                              - (IData)(1U)));
        vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.arvalid = 1U;
        if (vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.arready) {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_cur_burst_bytes_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_cur_burst_beats_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n = 2U;
        }
    } else if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_req_i) 
                & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_consume_i)))) {
        if ((1U & ((((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_enable_i)) 
                     | (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_ok_c))) 
                    | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c)) 
                   | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r)))) {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_n = 1U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_error_pulse_c = 1U;
        } else {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_alloc_bytes_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_alloc_bytes_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_seq_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_meta_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_valid_good_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_meta_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_overflow_err_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_seg_bytes_n 
                = ((vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c 
                    <= ([&]() {
                            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__curr_addr 
                                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c;
                            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__ring_size_bytes 
                                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i;
                            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__base_addr 
                                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
                            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__ring_end_addr 
                                = (0x00000003ffffffffULL 
                                   & (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__base_addr 
                                      + (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__ring_size_bytes))));
                            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__Vfuncout 
                                = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__ring_end_addr) 
                                                  - (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__curr_addr)));
                        }(), vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__Vfuncout))
                    ? vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c
                    : ([&]() {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__curr_addr 
                            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c;
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__ring_size_bytes 
                            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i;
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__base_addr 
                            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__ring_end_addr 
                            = (0x00000003ffffffffULL 
                               & (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__base_addr 
                                  + (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__ring_size_bytes))));
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__Vfuncout 
                            = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__ring_end_addr) 
                                              - (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__curr_addr)));
                    }(), vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__Vfuncout));
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_second_seg_bytes_n 
                = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c 
                                  - ((vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c 
                                      <= ([&]() {
                                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__curr_addr 
                                        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c;
                                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__ring_size_bytes 
                                        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i;
                                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__base_addr 
                                        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
                                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__ring_end_addr 
                                        = (0x00000003ffffffffULL 
                                           & (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__base_addr 
                                              + (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__ring_size_bytes))));
                                    vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__Vfuncout 
                                        = (0x0001ffffU 
                                           & ((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__ring_end_addr) 
                                              - (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__curr_addr)));
                                }(), vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__Vfuncout))
                                      ? vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c
                                      : ([&]() {
                                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__curr_addr 
                                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c;
                                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__ring_size_bytes 
                                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i;
                                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__base_addr 
                                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
                                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__ring_end_addr 
                                    = (0x00000003ffffffffULL 
                                       & (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__base_addr 
                                          + (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__ring_size_bytes))));
                                vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__Vfuncout 
                                    = (0x0001ffffU 
                                       & ((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__ring_end_addr) 
                                          - (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__curr_addr)));
                            }(), vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__Vfuncout))));
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_idx_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_n 
                = ((vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c 
                    <= ([&]() {
                            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__curr_addr 
                                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c;
                            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__ring_size_bytes 
                                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i;
                            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__base_addr 
                                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
                            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__ring_end_addr 
                                = (0x00000003ffffffffULL 
                                   & (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__base_addr 
                                      + (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__ring_size_bytes))));
                            vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__Vfuncout 
                                = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__ring_end_addr) 
                                                  - (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__curr_addr)));
                        }(), vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__Vfuncout))
                    ? vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c
                    : ([&]() {
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__curr_addr 
                            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c;
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__ring_size_bytes 
                            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i;
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__base_addr 
                            = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__ring_end_addr 
                            = (0x00000003ffffffffULL 
                               & (vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__base_addr 
                                  + (QData)((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__ring_size_bytes))));
                        vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__Vfuncout 
                            = (0x0001ffffU & ((IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__ring_end_addr) 
                                              - (IData)(vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__curr_addr)));
                    }(), vlSelfRef.__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__Vfuncout));
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_n 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_n = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_beat_pending_n = 1U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n = 1U;
        }
    }
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__keep_bytes_c 
        = (0x0000003fU & (((1U & vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep) 
                           + (1U & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                    >> 1U))) + (((1U 
                                                  & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                     >> 2U)) 
                                                 + 
                                                 (1U 
                                                  & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                     >> 3U))) 
                                                + (
                                                   (1U 
                                                    & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                       >> 4U)) 
                                                   + 
                                                   ((1U 
                                                     & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                        >> 5U)) 
                                                    + 
                                                    ((1U 
                                                      & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                         >> 6U)) 
                                                     + 
                                                     ((1U 
                                                       & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                          >> 7U)) 
                                                      + 
                                                      ((1U 
                                                        & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                           >> 8U)) 
                                                       + 
                                                       ((1U 
                                                         & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                            >> 9U)) 
                                                        + 
                                                        ((1U 
                                                          & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                             >> 0x0000000aU)) 
                                                         + 
                                                         ((1U 
                                                           & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                              >> 0x0000000bU)) 
                                                          + 
                                                          ((1U 
                                                            & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                               >> 0x0000000cU)) 
                                                           + 
                                                           ((1U 
                                                             & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                >> 0x0000000dU)) 
                                                            + 
                                                            ((1U 
                                                              & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                 >> 0x0000000eU)) 
                                                             + 
                                                             ((1U 
                                                               & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                  >> 0x0000000fU)) 
                                                              + 
                                                              ((1U 
                                                                & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                   >> 0x00000010U)) 
                                                               + 
                                                               ((1U 
                                                                 & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                    >> 0x00000011U)) 
                                                                + 
                                                                ((1U 
                                                                  & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                     >> 0x00000012U)) 
                                                                 + 
                                                                 ((1U 
                                                                   & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                      >> 0x00000013U)) 
                                                                  + 
                                                                  ((1U 
                                                                    & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                       >> 0x00000014U)) 
                                                                   + 
                                                                   ((1U 
                                                                     & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                        >> 0x00000015U)) 
                                                                    + 
                                                                    ((1U 
                                                                      & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                         >> 0x00000016U)) 
                                                                     + 
                                                                     ((1U 
                                                                       & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                          >> 0x00000017U)) 
                                                                      + 
                                                                      ((1U 
                                                                        & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                           >> 0x00000018U)) 
                                                                       + 
                                                                       ((1U 
                                                                         & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                            >> 0x00000019U)) 
                                                                        + 
                                                                        ((1U 
                                                                          & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                             >> 0x0000001aU)) 
                                                                         + 
                                                                         ((1U 
                                                                           & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                              >> 0x0000001bU)) 
                                                                          + 
                                                                          ((1U 
                                                                            & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                               >> 0x0000001cU)) 
                                                                           + 
                                                                           ((1U 
                                                                             & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                                >> 0x0000001dU)) 
                                                                            + 
                                                                            ((1U 
                                                                              & (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                                >> 0x0000001eU)) 
                                                                             + 
                                                                             (vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep 
                                                                              >> 0x0000001fU)))))))))))))))))))))))))))))));
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep;
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[0U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[0U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[1U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[1U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[2U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[2U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[3U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[3U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[4U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[4U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[5U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[5U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[6U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[6U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[7U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata[7U];
    VL_ASSIGN_W(256, __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result, Vtop__ConstPool__CONST_h9e67c271_0);
    if ((1U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[0U] 
            = ((0xffffff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[0U]) 
               | (0x000000ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[0U]));
    }
    if ((2U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[0U] 
            = ((0xffff00ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[0U]) 
               | (0x0000ff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[0U]));
    }
    if ((4U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[0U] 
            = ((0xff00ffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[0U]) 
               | (0x00ff0000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[0U]));
    }
    if ((8U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[0U] 
            = ((0x00ffffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[0U]) 
               | (0xff000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[0U]));
    }
    if ((0x00000010U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[1U] 
            = ((0xffffff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[1U]) 
               | (0x000000ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[1U]));
    }
    if ((0x00000020U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[1U] 
            = ((0xffff00ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[1U]) 
               | (0x0000ff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[1U]));
    }
    if ((0x00000040U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[1U] 
            = ((0xff00ffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[1U]) 
               | (0x00ff0000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[1U]));
    }
    if ((0x00000080U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[1U] 
            = ((0x00ffffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[1U]) 
               | (0xff000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[1U]));
    }
    if ((0x00000100U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[2U] 
            = ((0xffffff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[2U]) 
               | (0x000000ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[2U]));
    }
    if ((0x00000200U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[2U] 
            = ((0xffff00ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[2U]) 
               | (0x0000ff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[2U]));
    }
    if ((0x00000400U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[2U] 
            = ((0xff00ffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[2U]) 
               | (0x00ff0000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[2U]));
    }
    if ((0x00000800U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[2U] 
            = ((0x00ffffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[2U]) 
               | (0xff000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[2U]));
    }
    if ((0x00001000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[3U] 
            = ((0xffffff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[3U]) 
               | (0x000000ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[3U]));
    }
    if ((0x00002000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[3U] 
            = ((0xffff00ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[3U]) 
               | (0x0000ff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[3U]));
    }
    if ((0x00004000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[3U] 
            = ((0xff00ffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[3U]) 
               | (0x00ff0000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[3U]));
    }
    if ((0x00008000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[3U] 
            = ((0x00ffffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[3U]) 
               | (0xff000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[3U]));
    }
    if ((0x00010000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[4U] 
            = ((0xffffff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[4U]) 
               | (0x000000ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[4U]));
    }
    if ((0x00020000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[4U] 
            = ((0xffff00ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[4U]) 
               | (0x0000ff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[4U]));
    }
    if ((0x00040000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[4U] 
            = ((0xff00ffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[4U]) 
               | (0x00ff0000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[4U]));
    }
    if ((0x00080000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[4U] 
            = ((0x00ffffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[4U]) 
               | (0xff000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[4U]));
    }
    if ((0x00100000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[5U] 
            = ((0xffffff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[5U]) 
               | (0x000000ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[5U]));
    }
    if ((0x00200000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[5U] 
            = ((0xffff00ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[5U]) 
               | (0x0000ff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[5U]));
    }
    if ((0x00400000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[5U] 
            = ((0xff00ffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[5U]) 
               | (0x00ff0000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[5U]));
    }
    if ((0x00800000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[5U] 
            = ((0x00ffffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[5U]) 
               | (0xff000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[5U]));
    }
    if ((0x01000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[6U] 
            = ((0xffffff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[6U]) 
               | (0x000000ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[6U]));
    }
    if ((0x02000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[6U] 
            = ((0xffff00ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[6U]) 
               | (0x0000ff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[6U]));
    }
    if ((0x04000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[6U] 
            = ((0xff00ffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[6U]) 
               | (0x00ff0000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[6U]));
    }
    if ((0x08000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[6U] 
            = ((0x00ffffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[6U]) 
               | (0xff000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[6U]));
    }
    if ((0x10000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[7U] 
            = ((0xffffff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[7U]) 
               | (0x000000ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[7U]));
    }
    if ((0x20000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[7U] 
            = ((0xffff00ffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[7U]) 
               | (0x0000ff00U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[7U]));
    }
    if ((0x40000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[7U] 
            = ((0xff00ffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[7U]) 
               | (0x00ff0000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[7U]));
    }
    if ((__Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__keep 
         >> 0x1fU)) {
        __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[7U] 
            = ((0x00ffffffU & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[7U]) 
               | (0xff000000U & __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__data[7U]));
    }
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[0U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[0U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[1U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[1U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[2U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[2U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[3U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[3U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[4U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[4U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[5U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[5U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[6U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[6U];
    __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[7U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__result[7U];
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[0U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[0U];
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[1U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[1U];
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[2U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[2U];
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[3U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[3U];
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[4U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[4U];
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[5U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[5U];
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[6U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[6U];
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[7U] 
        = __Vfunc_pipeline_cocotb_top__DOT__packer_u__DOT__mask_data_with_keep__3__Vfuncout[7U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[0U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[1U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[1U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[2U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[3U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[3U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[4U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[4U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[5U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[5U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[6U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[6U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[7U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[7U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[8U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[8U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[9U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[9U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[10U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[10U];
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[11U] 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[11U];
    if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r) 
                  >> 1U)))) {
        if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)))) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[0U] 
                    = (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tuser);
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[1U] 
                    = (IData)((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tuser 
                               >> 0x00000020U));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[2U] 
                    = ((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                        << 1U) | (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tlast));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[3U] 
                    = ((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tkeep 
                        >> 0x0000001fU) | (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[0U] 
                                           << 1U));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[4U] 
                    = ((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[0U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[1U] 
                                           << 1U));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[5U] 
                    = ((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[1U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[2U] 
                                           << 1U));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[6U] 
                    = ((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[2U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[3U] 
                                           << 1U));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[7U] 
                    = ((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[3U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[4U] 
                                           << 1U));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[8U] 
                    = ((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[4U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[5U] 
                                           << 1U));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[9U] 
                    = ((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[5U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[6U] 
                                           << 1U));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[10U] 
                    = ((vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[6U] 
                        >> 0x0000001fU) | (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[7U] 
                                           << 1U));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[11U] 
                    = (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tdata[7U] 
                       >> 0x0000001fU);
            }
        }
    }
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_awaddr 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awaddr;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_awlen 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awlen;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_awsize 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awsize;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_awburst 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awburst;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_awvalid 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.awvalid;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[0U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[0U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[1U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[1U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[2U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[2U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[3U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[3U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[4U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[4U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[5U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[5U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[6U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[6U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[7U] 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wdata[7U];
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wstrb 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wstrb;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wlast 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wlast;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wvalid 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.wvalid;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_bready 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.bready;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_araddr 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.araddr;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_arlen 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.arlen;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_arsize 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.arsize;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_arburst 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.arburst;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_arvalid 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.arvalid;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rready 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if.rready;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_commit_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_commit_pulse_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_done_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_done_pulse_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_error_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_error_pulse_c;
    vlSelfRef.m_axi_awaddr = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_awaddr;
    vlSelfRef.m_axi_awlen = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_awlen;
    vlSelfRef.m_axi_awsize = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_awsize;
    vlSelfRef.m_axi_awburst = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_awburst;
    vlSelfRef.m_axi_awvalid = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_awvalid;
    vlSelfRef.m_axi_wdata[0U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[0U];
    vlSelfRef.m_axi_wdata[1U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[1U];
    vlSelfRef.m_axi_wdata[2U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[2U];
    vlSelfRef.m_axi_wdata[3U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[3U];
    vlSelfRef.m_axi_wdata[4U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[4U];
    vlSelfRef.m_axi_wdata[5U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[5U];
    vlSelfRef.m_axi_wdata[6U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[6U];
    vlSelfRef.m_axi_wdata[7U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wdata[7U];
    vlSelfRef.m_axi_wstrb = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wstrb;
    vlSelfRef.m_axi_wlast = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wlast;
    vlSelfRef.m_axi_wvalid = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_wvalid;
    vlSelfRef.m_axi_bready = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_bready;
    vlSelfRef.m_axi_araddr = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_araddr;
    vlSelfRef.m_axi_arlen = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_arlen;
    vlSelfRef.m_axi_arsize = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_arsize;
    vlSelfRef.m_axi_arburst = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_arburst;
    vlSelfRef.m_axi_arvalid = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_arvalid;
    vlSelfRef.m_axi_rready = vlSelfRef.pipeline_cocotb_top__DOT__m_axi_rready;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_commit_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_commit_o;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_done_o = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_done_o;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_error_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_error_o;
    vlSelfRef.wr_slot_commit_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_commit_o;
    vlSelfRef.rd_done_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_done_o;
    vlSelfRef.rd_error_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_error_o;
}

void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__m_axis_rd_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__s_axis_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axi4_mm_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__m_axi_if__0(Vtop_axi4_mm_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__pkt_axis_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__slot_axis_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop___024root___ico_sequent__TOP__2(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__m_axis_rd_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if));
        Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__s_axis_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if));
        Vtop_axi4_mm_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__m_axi_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if));
        Vtop___024root___stl_sequent__TOP__1(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__pkt_axis_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if));
        Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__slot_axis_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if));
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge pipeline_cocotb_top.extractor_u.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge pipeline_cocotb_top.extractor_u.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge pipeline_cocotb_top.packer_u.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge pipeline_cocotb_top.packer_u.rst_ni)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge pipeline_cocotb_top.ringbuffer_u.clk_i)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(negedge pipeline_cocotb_top.ringbuffer_u.rst_ni)\n");
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
    vlSelf->cfg_drop_invalid_pkt_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12153301888773253218ull);
    vlSelf->cfg_enable_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8574283470568429695ull);
    vlSelf->cfg_allow_overwrite_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4053853332066994793ull);
    vlSelf->cfg_drop_invalid_slot_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9561319106844817856ull);
    vlSelf->cfg_drop_on_no_space_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9532459606635723755ull);
    vlSelf->cfg_ring_base_addr_i = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 4909204147935342120ull);
    vlSelf->cfg_ring_size_bytes_i = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9692597135029889435ull);
    vlSelf->pkt_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17153074482495418097ull);
    vlSelf->pkt_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 81805878517030488ull);
    vlSelf->pkt_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5220079347674660263ull);
    vlSelf->pkt_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16636537043600033524ull);
    vlSelf->pkt_bytes_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9382384257393170247ull);
    vlSelf->pkt_crc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7676084566834659157ull);
    vlSelf->pkt_ecc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1806629213507780402ull);
    vlSelf->pkt_trunc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13517678886990542437ull);
    vlSelf->slot_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16414201820509555848ull);
    vlSelf->slot_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7037026714158015159ull);
    vlSelf->slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15229735725128963501ull);
    vlSelf->slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4069635512002436434ull);
    vlSelf->slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3207059873615457475ull);
    vlSelf->slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4615952249938211109ull);
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
    VL_SCOPED_RAND_RESET_W(256, vlSelf->s_axis_tdata, __VscopeHash, 6413635470731068441ull);
    vlSelf->s_axis_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6494536958632130591ull);
    vlSelf->s_axis_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7678217216116487763ull);
    vlSelf->s_axis_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12236809265553805965ull);
    vlSelf->s_axis_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 750346815483064505ull);
    vlSelf->s_axis_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8856106712201831047ull);
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
    vlSelf->pipeline_cocotb_top__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5695275431264671110ull);
    vlSelf->pipeline_cocotb_top__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9415158318101588050ull);
    vlSelf->pipeline_cocotb_top__DOT__cfg_vc_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3662510746958785799ull);
    vlSelf->pipeline_cocotb_top__DOT__cfg_dt_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2658555299159170198ull);
    vlSelf->pipeline_cocotb_top__DOT__cfg_vc_i = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17456139882050379008ull);
    vlSelf->pipeline_cocotb_top__DOT__cfg_dt_i = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 5894911220442274981ull);
    vlSelf->pipeline_cocotb_top__DOT__cfg_drop_invalid_pkt_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6390896815911863680ull);
    vlSelf->pipeline_cocotb_top__DOT__cfg_enable_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16195457775365508845ull);
    vlSelf->pipeline_cocotb_top__DOT__cfg_allow_overwrite_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15346157890283619135ull);
    vlSelf->pipeline_cocotb_top__DOT__cfg_drop_invalid_slot_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1847687059430374912ull);
    vlSelf->pipeline_cocotb_top__DOT__cfg_drop_on_no_space_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3306877975768344362ull);
    vlSelf->pipeline_cocotb_top__DOT__cfg_ring_base_addr_i = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 520672015792804366ull);
    vlSelf->pipeline_cocotb_top__DOT__cfg_ring_size_bytes_i = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 6008845286084848982ull);
    vlSelf->pipeline_cocotb_top__DOT__pkt_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7003994237095460536ull);
    vlSelf->pipeline_cocotb_top__DOT__pkt_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2394033350000857233ull);
    vlSelf->pipeline_cocotb_top__DOT__pkt_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5047483716109939634ull);
    vlSelf->pipeline_cocotb_top__DOT__pkt_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5152818843153405100ull);
    vlSelf->pipeline_cocotb_top__DOT__pkt_bytes_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12637568655486201928ull);
    vlSelf->pipeline_cocotb_top__DOT__pkt_crc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14139110364107404205ull);
    vlSelf->pipeline_cocotb_top__DOT__pkt_ecc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6667298563242844856ull);
    vlSelf->pipeline_cocotb_top__DOT__pkt_trunc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4736890782645101753ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9595153764600686866ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3224043394379708698ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 10068677209786043472ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3564040139072152157ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16825232339881749719ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14597202577906018997ull);
    vlSelf->pipeline_cocotb_top__DOT__wr_slot_commit_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2893296664163187686ull);
    vlSelf->pipeline_cocotb_top__DOT__wr_slot_addr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 6050634908309052741ull);
    vlSelf->pipeline_cocotb_top__DOT__wr_slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14133897788441931184ull);
    vlSelf->pipeline_cocotb_top__DOT__wr_slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 5921931279397384696ull);
    vlSelf->pipeline_cocotb_top__DOT__wr_slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7502711998352239512ull);
    vlSelf->pipeline_cocotb_top__DOT__wr_slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9097983373254461384ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_slot_req_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12055686657995376421ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_consume_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3883436359425506530ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_slot_valid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4190174985257515214ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_slot_addr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 8398667993997931621ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 16947626500832047126ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10083892048119448971ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4597361498659755476ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16282075233419816646ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_busy_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 467083866857952471ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10905287430677047893ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_error_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3623394144297363003ull);
    vlSelf->pipeline_cocotb_top__DOT__wr_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 12209884643173109521ull);
    vlSelf->pipeline_cocotb_top__DOT__rd_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 2088464401933330216ull);
    vlSelf->pipeline_cocotb_top__DOT__commit_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 11653018503814143502ull);
    vlSelf->pipeline_cocotb_top__DOT__used_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17992509882448138899ull);
    vlSelf->pipeline_cocotb_top__DOT__free_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15182255321011822413ull);
    vlSelf->pipeline_cocotb_top__DOT__committed_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17747145638532979570ull);
    vlSelf->pipeline_cocotb_top__DOT__full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10152309220390540469ull);
    vlSelf->pipeline_cocotb_top__DOT__almost_full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17743999645508608752ull);
    vlSelf->pipeline_cocotb_top__DOT__empty_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6995912904108413903ull);
    vlSelf->pipeline_cocotb_top__DOT__wrap_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16305949385649833930ull);
    vlSelf->pipeline_cocotb_top__DOT__overflow_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7248833866713031444ull);
    vlSelf->pipeline_cocotb_top__DOT__drop_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4310673895570206267ull);
    vlSelf->pipeline_cocotb_top__DOT__err_cfg_align_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 246321852399283868ull);
    vlSelf->pipeline_cocotb_top__DOT__err_no_space_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2560103267950162541ull);
    vlSelf->pipeline_cocotb_top__DOT__err_slot_proto_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6367602130477936658ull);
    vlSelf->pipeline_cocotb_top__DOT__err_slot_too_large_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12539925217305490779ull);
    vlSelf->pipeline_cocotb_top__DOT__err_axi_wr_resp_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17717842771796994463ull);
    vlSelf->pipeline_cocotb_top__DOT__err_axi_rd_resp_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11612740172510702843ull);
    vlSelf->pipeline_cocotb_top__DOT__err_illegal_read_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17256957453188504484ull);
    vlSelf->pipeline_cocotb_top__DOT__dbg_wr_state_o = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6234027302797808641ull);
    vlSelf->pipeline_cocotb_top__DOT__dbg_rd_state_o = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12821064302053835486ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__s_axis_tdata, __VscopeHash, 7484097487774962191ull);
    vlSelf->pipeline_cocotb_top__DOT__s_axis_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1096090431613348604ull);
    vlSelf->pipeline_cocotb_top__DOT__s_axis_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3359313814316174478ull);
    vlSelf->pipeline_cocotb_top__DOT__s_axis_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3294781499023088313ull);
    vlSelf->pipeline_cocotb_top__DOT__s_axis_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6659898427649246014ull);
    vlSelf->pipeline_cocotb_top__DOT__s_axis_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11615205985028943356ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__m_axis_rd_tdata, __VscopeHash, 302328735854662557ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axis_rd_tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8484847901943171277ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axis_rd_tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11110314395750942464ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axis_rd_tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8082151136330725382ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axis_rd_tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11008835958805013431ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axis_rd_tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14265477746409782053ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_awaddr = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 14993033907864779455ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_awlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12427954469054759814ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_awsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17301525727879961843ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_awburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11214984280728789458ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5356030826950679531ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3649790881214747140ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__m_axi_wdata, __VscopeHash, 16384591163982415863ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_wstrb = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3243943786422313211ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_wlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13645412519392818197ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13009290063238262684ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4780991869311602259ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 4193380150977583224ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1955752707569552631ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3749892733504526662ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_araddr = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 14937353336811453468ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_arlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13253752442419468615ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_arsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12487142728257384933ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_arburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1553587298487479512ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17669580753127341160ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11571127676806175115ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__m_axi_rdata, __VscopeHash, 13779960840716208919ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1389056434035972029ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_rlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18157281658058648530ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3484598618795232918ull);
    vlSelf->pipeline_cocotb_top__DOT__m_axi_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7658320125579866132ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_start_packer_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17834461454039163605ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_done_packer_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13742080135801475904ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_bytes_packer_c = 4288U;
    ;
    vlSelf->pipeline_cocotb_top__DOT__slot_seq_packer_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4985563813496343633ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_valid_good_packer_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1578375596224170985ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_overflow_err_packer_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6033955963789818775ull);
    vlSelf->pipeline_cocotb_top__DOT__slot_bytes_ctrl_c = 4288U;
    ;
    vlSelf->pipeline_cocotb_top__DOT__slot_seq_ctrl_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15665549835571167572ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 498913356724773276ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12157802014047542982ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_vc_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4325739735718225225ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_dt_en_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2166388692238485137ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_vc_i = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11214566491605307031ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_dt_i = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8603655800356777415ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6917905302720927042ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9952391175104319337ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18208725473325416087ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1791377987272778141ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13844220489646637659ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5119222700611597724ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6112095844858638617ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11127152159734145172ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__state_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7271869302973816383ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__state_n = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8489229618755068973ull);
    VL_SCOPED_RAND_RESET_W(353, vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r, __VscopeHash, 18307755613985883111ull);
    VL_SCOPED_RAND_RESET_W(353, vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n, __VscopeHash, 1869073093563242629ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16041302583427714316ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10587128388801082797ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10851839489377828622ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 695838627112399044ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6872733473902787255ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3248424974152797307ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5785654655433598910ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5968092442679774573ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15426901518623594869ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2637535650799469951ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2086198572586937822ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14102827962429627598ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10242456929719070192ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18218644388913931722ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7179631848227593394ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__m_fire_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10181435841491682964ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_bytes_c = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 6967476386366877808ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 5863765574618274566ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__first_vc_c = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12605322550495174428ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__first_dt_c = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 6450931874048051447ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__first_payload_len_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16410482711820819459ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__first_crc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8889568796639043189ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__first_ecc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11949291903633312406ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__first_trunc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8251887616354541914ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__stream_crc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12827545199265236281ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__stream_ecc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11186465231836475612ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__stream_trunc_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16140802084949118959ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7656259180634402608ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_view_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3154156659331869629ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_view_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13060380497404627451ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_view_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15211583307630649385ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_view_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6358220723003957283ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17552797124328685222ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_view_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13142527904423022468ull);
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h503bf3ac__0 = 0;
    vlSelf->pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h5ac0cf88__0 = 0;
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12795296044727878830ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14538393848761639715ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cfg_drop_invalid_pkt_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4967887792168405757ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__pkt_start_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14107679750444019615ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14056980764326500346ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__pkt_bytes_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1522154766285515003ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__pkt_seq_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8356802911355565694ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__pkt_crc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5942798151814810990ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__pkt_ecc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5476694434620363305ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__pkt_trunc_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17251265479700274999ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__pkt_valid_good_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5729315898927562044ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__slot_start_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14200448855739518580ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__slot_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2128334198655090766ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__slot_bytes_o = 4288U;
    ;
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1656521224788698896ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9209243909988950637ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4511953622079228192ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__state_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3134279805395109073ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__state_n = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10710750265632691050ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4267841584706587882ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5017899340107336647ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13717913155191461549ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9577487781814118432ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4046959343693630788ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 181650668865097866ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 75307000227926079ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9578071865576071419ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16151397784970595638ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5786535299398472565ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5248321519588246103ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17243815818066379405ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5123707187220122234ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15853692650604280968ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12570350289845849436ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16873479703933185070ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12470108266176468281ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6496461689474349108ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8364509822929180866ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14211321733273918382ull);
    for (int __Vi0 = 0; __Vi0 < 128; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r[__Vi0], __VscopeHash, 15446119589404891299ull);
    }
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 552701785074145322ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1877588283489682510ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__keep_bytes_c = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 17483592077060130329ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c, __VscopeHash, 3372029759145359004ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__is_slot_last_beat_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7760157650870358956ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11365731195121417060ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__sample_pad_beats_c = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4923462058530595785ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__hdr_word_c, __VscopeHash, 1476148366984122150ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__actual_sample_cnt_c = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 6181184124838408277ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_en_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2472708099969255638ull);
    vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_idx_c = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17708161979708723668ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c, __VscopeHash, 3039883304671947744ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8149659201915918796ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15453792535553255995ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_enable_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6023997410719866583ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_allow_overwrite_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16742142517369690934ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_drop_invalid_slot_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16379000021145661416ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_drop_on_no_space_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7186987902148834972ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 13459114840570568783ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 5596932763353386865ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_start_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13696757268697614406ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_done_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16609128186511528979ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_bytes_i = 4288U;
    ;
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_seq_i = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5776194218606140275ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_valid_good_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2326844578110052513ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_overflow_err_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16343640092689129068ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_commit_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11980198037698551245ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_addr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 4211257244130144343ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11500196126455050383ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 7466144989538933359ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11554432723599420487ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10599424138318216950ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_req_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9853310607777761415ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_consume_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8007659506280994494ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3809980169734619917ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 5890897466180080295ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 243187595609423941ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_o = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13088420626173825727ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8307077242181864887ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_err_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6703455150510303527ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_busy_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10128666315080309585ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_done_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17535877342532398729ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_error_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15642919340074851514ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 8481386381183543857ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 17698822296873448843ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_o = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 13829184580718062557ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8539328193721010057ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8038058736542987946ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_bytes_o = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14303567766144083114ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14008982835957168465ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__almost_full_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11252565067307360189ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__empty_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17124443853503151279ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18261418815492884053ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15509385039122011325ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_o = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15971095163987429358ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2200811904337405536ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15480806863925154594ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14778224102704895194ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16606644806407731675ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17385962026062816819ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17969216715888585455ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_o = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17761310371558158079ull);
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r[__Vi0], __VscopeHash, 31651234388013562ull);
    }
    for (int __Vi0 = 0; __Vi0 < 256; ++__Vi0) {
        vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_keep_r[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 77906374222138439ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r[__Vi0] = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 5471995239570269360ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_bytes_r[__Vi0] = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 6006952448379292315ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_alloc_bytes_r[__Vi0] = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15582983873727092847ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_seq_r[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11211838656264828773ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_valid_good_r[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3859925777340830696ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_overflow_err_r[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18394112369940481214ull);
    }
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9850358644741191722ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14123023221783488759ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4175311154589153097ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9703213578047407493ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 2486734402720938987ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 5640549223756508076ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 8611394686810736468ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 11787332658364072680ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 11183649840668012262ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 6351589063328692125ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8536876960157326405ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12509774672145433956ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 13453726030417137681ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 16684529837559187670ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11704968457781332117ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18144624840406302543ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18330528416822804559ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16950140532556923430ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11045337986158978013ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17553638313378119533ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3530753904903049049ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_n = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16208409865317647740ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13068100646030912716ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_n = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5074330080606673079ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_r = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 2525681420787351880ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_n = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 1898012211035605526ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_r = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 754518659905518206ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_n = VL_SCOPED_RAND_RESET_I(9, __VscopeHash, 11339178768469024761ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2370547527955518358ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 14373514195497795465ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15019079309242549693ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 786337482891275706ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12420184150503596434ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2746826279378135706ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6619257057027180523ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5996731625330846746ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4326489899564123245ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10517513965486472904ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1445437414062389310ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9329423238384728770ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15118312936454363062ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 280893086906931630ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15597586974686715056ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7615405553919938267ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9991900940815399302ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11109929296580831363ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 4263533260034063534ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 906128333046761032ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 17431565504997741543ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 6849401459124730071ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 9051470018244447501ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2733923123776759977ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8024141795072360132ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 4459426732529981948ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10857084813674280162ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10662496892343305288ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_idx_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17103094962539229962ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_idx_n = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9156270771491666432ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 7065137481891445558ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 104206366368925235ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15520010063268646907ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15093440601109556612ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_r = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1793349609943905551ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_n = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2469573076312831877ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11612248844783346191ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_n = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8797851052255122735ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17793069420942979728ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15999206919734629337ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10642315090156874195ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_n = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17968249722922379890ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 9377004909904893343ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 9139754043942243273ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 4092600097013854773ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 4401783992774085295ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_alloc_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1579524085988017876ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_alloc_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 6306529829998894939ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_r = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18445978492358613411ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_n = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 382707301525727809ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_meta_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8787361369558079700ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_meta_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12288774792034565345ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_meta_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4017777405267973898ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_meta_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15515161122126317210ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_seg_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 12454639515761179269ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_seg_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 884869261111371358ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_second_seg_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 2562328054241256938ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_second_seg_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 925454221998667676ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_idx_r = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15674276728867973452ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_idx_n = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9702199972717273733ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_r = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 1658023820967536895ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_n = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 134554708587981255ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 788056917708926206ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 4843424377563481868ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 13571175922051933097ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11436150787377092515ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7492799720758249344ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_n = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15785780034822755787ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_r = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 7523669986427954516ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_n = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15019636278472427381ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8497708481436057913ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_n = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1215059646426317019ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_beat_pending_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12185953663795553821ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_beat_pending_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17785446998520618736ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r, __VscopeHash, 3029502352716067815ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n, __VscopeHash, 5428227843281982243ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5539170902489103614ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_n = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16089596722226106091ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_r = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 18434477390499653171ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_n = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1591672451180781086ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16713120577970433815ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18106577495229511680ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1097506931084189441ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17629740088081853607ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15217145050764533319ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10352112449150550441ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13487272868435940749ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11387874407097620222ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 327739718996366633ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3554707184848603164ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3231949165316336385ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13230266838426110836ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11563861838612759680ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 655069205932526668ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15193744217046152325ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17004104701910365460ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8627395174725137710ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 676293100582513425ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 11212393789757227088ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_ok_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17505762670831198746ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_full_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16917836927168491726ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1466766651265855871ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_invalid_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9851142378916469020ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_can_fit_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6855126631132138180ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_drop_now_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17235825166606798039ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_end_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 17754032088417851236ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__first_seg_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 15527227800095650737ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__second_seg_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 6973301460621456152ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__next_wr_ptr_c = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 4080283218084081942ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__next_wr_wrap_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14784106788928653862ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__s_axis_keep_bytes_c = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 17451131229903801680ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__s_axis_ready_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1858728518270662584ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_fire_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9932028241464370992ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__axi_rready_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16017005798775872100ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_en_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17168409063514608788ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_idx_c = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9544840013943836188ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c, __VscopeHash, 15344319645379494581ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_keep_c = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14508636857240069665ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10156645110601216026ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_idx_c = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10901671284667556703ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_addr_c = VL_SCOPED_RAND_RESET_Q(34, __VscopeHash, 10638653925367134407ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 16979344484128515757ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_alloc_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 1696277939504744539ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_seq_c = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5561059442847430393ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_valid_good_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15089596235579359918ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_overflow_err_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11403747102125938116ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_cur_burst_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 3200296502624429889ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_cur_burst_beats_c = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4739125347404203331ull);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wdata_c, __VscopeHash, 3844963478681814703ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wstrb_c = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14580490697677228370ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_wlast_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15364810266045724152ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_cur_burst_bytes_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 13704390020738872701ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_cur_burst_beats_c = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15764881728200733976ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_effective_bytes_in_c = 4288U;
    ;
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_alloc_bytes_in_c = VL_SCOPED_RAND_RESET_I(17, __VscopeHash, 8007653724880861421ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_commit_pulse_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 370795536212965498ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_done_pulse_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10501309348024862675ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_error_pulse_c = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16002413011009116432ull);
    vlSelf->pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_lane_idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4632468589589540199ull);
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__ring_end_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__10__to_end_bytes = 0;
    vlSelf->__Vfunc_min_u__11__Vfuncout = 0;
    vlSelf->__Vfunc_min_u__11__lhs = 0;
    vlSelf->__Vfunc_min_u__11__rhs = 0;
    vlSelf->__Vfunc_ceil_div_u__12__Vfuncout = 0;
    vlSelf->__Vfunc_ceil_div_u__12__numerator = 0;
    vlSelf->__Vfunc_ceil_div_u__12__denominator = 0;
    vlSelf->__Vfunc_min_u__13__Vfuncout = 0;
    vlSelf->__Vfunc_min_u__13__lhs = 0;
    vlSelf->__Vfunc_min_u__13__rhs = 0;
    vlSelf->__Vfunc_ceil_div_u__14__Vfuncout = 0;
    vlSelf->__Vfunc_ceil_div_u__14__numerator = 0;
    vlSelf->__Vfunc_ceil_div_u__14__denominator = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__15__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__15__ptr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__base_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__ring_size_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__curr_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__advance_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__ring_end_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__16__to_end_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__17__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__17__ptr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__18__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__fifo_ptr_next__18__ptr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__base_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__ring_size_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__curr_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__advance_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__ring_end_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ring_addr_add__19__to_end_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__byte_count = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__keep_mask_from_bytes__20__mask_c = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__base_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__ring_size_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__curr_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__21__ring_end_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__base_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__ring_size_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__curr_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__22__ring_end_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__base_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__ring_size_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__curr_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__23__ring_end_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__base_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__ring_size_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__curr_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__24__ring_end_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__base_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__ring_size_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__curr_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__25__ring_end_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__Vfuncout = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__base_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__ring_size_bytes = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__curr_addr = 0;
    vlSelf->__Vfunc_pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_ring_end__26__ring_end_addr = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__extractor_u__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__extractor_u__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__packer_u__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__clk_i__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rst_ni__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
