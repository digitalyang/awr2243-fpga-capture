// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop_axis_stream_if___eval_initial__TOP__pipeline_cocotb_top__DOT__slot_axis_if(Vtop_axis_stream_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axis_stream_if___eval_initial__TOP__pipeline_cocotb_top__DOT__slot_axis_if\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tuser = 0ULL;
}

VL_ATTR_COLD void Vtop_axis_stream_if___ctor_var_reset(Vtop_axis_stream_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axis_stream_if___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    VL_SCOPED_RAND_RESET_W(256, vlSelf->tdata, __VscopeHash, 17793882294932938261ull);
    vlSelf->tkeep = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15675116905018685246ull);
    vlSelf->tvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11580290079671979871ull);
    vlSelf->tready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6606742779220347250ull);
    vlSelf->tlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9634498217090403279ull);
    vlSelf->tuser = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16187945839469799350ull);
    vlSelf->__VdfgRegularize_hebeb780c_0_0 = 0;
}
