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

void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__1\n"); );
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

void Vtop___024root___ico_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.__VdfgRegularize_hebeb780c_0_0;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__m_fire_c 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.__VdfgRegularize_hebeb780c_0_0;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c 
        = ((IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tready) 
           & (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tvalid));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_idx_c = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_en_c = 0U;
    VL_ASSIGN_W(256, vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r;
    if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r) 
                  >> 1U)))) {
        if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__m_fire_c) {
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_n 
                        = (0x0000ffffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_r)));
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_r;
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_payload_len_c;
                }
            }
        } else if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c) {
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_n = 0U;
        }
    }
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_start_o 
        = ((1U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)) 
           & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__m_fire_c) 
              & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c)));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r;
    if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
        if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
            if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c) 
                 & (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tlast))) {
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n = 0U;
            }
        } else if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c) {
            if (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tlast) {
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n = 0U;
            }
        }
        if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)))) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_n 
                    = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_r) 
                       | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_crc_err_c));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_n 
                    = (0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                                      + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c)));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_n 
                    = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_r) 
                       | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_ecc_err_c));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
                    = (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r) 
                        | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_trunc_err_c)) 
                       | ((0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c))) 
                          > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r)));
                if (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tlast) {
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
                        = (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r) 
                            | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_trunc_err_c)) 
                           | ((0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                                              + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c))) 
                              != (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r)));
                }
            }
        }
    } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
        if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__m_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_crc_err_c;
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_bytes_c;
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_ecc_err_c;
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_trunc_err_c;
                if ((1U & vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U])) {
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n = 0U;
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h503bf3ac__0;
                } else {
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n = 2U;
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h5ac0cf88__0;
                }
            }
        } else {
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n 
                = ((1U & vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U])
                    ? 0U : 3U);
        }
    } else if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c) {
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n = 1U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_n = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_n = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_n = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n = 0U;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_view_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_view_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_view_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_view_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_view_c = 0U;
    if ((((1U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)) 
          & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c)) 
         & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__m_fire_c))) {
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_r;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_bytes_c;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_crc_err_c;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_ecc_err_c;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_trunc_err_c;
        if ((1U & vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U])) {
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
                = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h503bf3ac__0;
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_view_c = 1U;
        } else {
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
                = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h5ac0cf88__0;
        }
    } else if (((2U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)) 
                & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c))) {
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_r;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_view_c 
            = (0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                              + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c)));
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_view_c 
            = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_r) 
               | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_crc_err_c));
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_view_c 
            = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_r) 
               | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_ecc_err_c));
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
            = (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r) 
                | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_trunc_err_c)) 
               | ((0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                                  + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c))) 
                  > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r)));
        if (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tlast) {
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
                = (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r) 
                    | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_trunc_err_c)) 
                   | ((0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                                      + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c))) 
                      != (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r)));
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_view_c = 1U;
        }
    }
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_start_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_start_o;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_view_c;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_view_c;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_view_c;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_view_c;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_valid_good_o 
        = ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_view_c)) 
           & ((~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_view_c) 
                  | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c))) 
              & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_view_c)));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_view_c;
    vlSelfRef.pkt_start_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_start_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_start_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_start_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_seq_o = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_crc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_ecc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_trunc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_valid_good_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_done_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_o;
    vlSelfRef.pkt_seq_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_seq_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_seq_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_seq_o;
    vlSelfRef.pkt_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_bytes_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_bytes_o;
    vlSelfRef.pkt_crc_err_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_crc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_crc_err_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_crc_err_o;
    vlSelfRef.pkt_ecc_err_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_ecc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_ecc_err_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_ecc_err_o;
    vlSelfRef.pkt_trunc_err_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_trunc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_trunc_err_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_trunc_err_o;
    vlSelfRef.pkt_valid_good_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_valid_good_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_valid_good_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_valid_good_o;
    vlSelfRef.pkt_done_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_done_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_done_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c 
        = ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_valid_good_i)) 
           & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cfg_drop_invalid_pkt_i));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_r;
    if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                    if ((0x80U > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_idx_c 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_en_c = 1U;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[0U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[0U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[1U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[1U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[2U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[2U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[3U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[3U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[4U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[4U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[5U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[5U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[6U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[6U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[7U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[7U];
                    }
                    if ((0x80U <= (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n = 1U;
                    }
                    if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_bytes_i;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_crc_err_i;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_ecc_err_i;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_trunc_err_i;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_valid_good_i;
                        if ((0x1000U < (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_bytes_i))) {
                            vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n = 1U;
                        }
                    }
                }
            } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_idx_c = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_en_c = 1U;
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[0U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[0U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[1U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[1U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[2U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[2U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[3U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[3U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[4U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[4U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[5U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[5U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[6U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[6U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[7U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[7U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n = 0U;
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_bytes_i;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_crc_err_i;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_ecc_err_i;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_trunc_err_i;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_valid_good_i;
                    if ((0x1000U < (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_bytes_i))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n = 1U;
                    }
                }
            }
            if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r)))) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_seq_i;
                }
            }
        }
    }
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r;
    if ((4U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r)))) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r)));
                    if ((0xffU == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n = 0U;
                    }
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r)));
                }
            }
            if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n = 0U;
            } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
                if ((0xffU == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r)));
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r)));
                if ((3U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n = 0U;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n = 0U;
                }
            }
        } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
            vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
                = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r)));
            vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
                = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r)));
            if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r) 
                 == (0x000000ffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__sample_pad_beats_c) 
                                    - (IData)(1U))))) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n = 5U;
            }
        }
    } else {
        if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r)));
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r)));
                    if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r) 
                         == (0x000000ffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r) 
                                            - (IData)(1U))))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n 
                            = ((0x80U > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r))
                                ? 4U : 5U);
                    }
                }
            } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r)));
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r)));
                if ((1U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n 
                        = ((0U < (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r))
                            ? 3U : 4U);
                }
            }
        } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                    if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c)))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                    }
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n 
                        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c)
                            ? 0U : 2U);
                }
            }
        } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c)))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n = 0U;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                }
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n 
                    = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c)
                        ? 0U : 2U);
            } else {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n = 1U;
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                    if ((0x80U > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n 
                            = (0x000000ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r)));
                    }
                    if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                        if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c) {
                            vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n = 0U;
                        }
                    }
                }
            } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n = 1U;
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                    if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n = 0U;
                    }
                }
            }
        }
    }
}

void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__m_axis_rd_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__s_axis_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axi4_mm_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__m_axi_if__0(Vtop_axi4_mm_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__pkt_axis_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__slot_axis_if__0(Vtop_axis_stream_if* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__m_axis_rd_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if));
        Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__s_axis_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if));
        Vtop_axi4_mm_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__m_axi_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axi_if));
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__pkt_axis_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if));
        Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__slot_axis_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if));
        Vtop___024root___ico_sequent__TOP__2(vlSelf);
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
                                                    (((((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rst_ni)) 
                                                        & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rst_ni__0)) 
                                                       << 5U) 
                                                      | (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__clk_i) 
                                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__clk_i__0))) 
                                                         << 4U)) 
                                                     | (((((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni)) 
                                                           & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni__0)) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__clk_i) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__packer_u__DOT__clk_i__0))) 
                                                            << 2U)) 
                                                        | ((((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__rst_ni)) 
                                                             & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__extractor_u__DOT__rst_ni__0)) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__clk_i) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__pipeline_cocotb_top__DOT__extractor_u__DOT__clk_i__0))))))));
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
    VlWide<8>/*255:0*/ __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0;
    VL_ZERO_W(256, __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0);
    CData/*6:0*/ __VdlyDim0__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0;
    __VdlyDim0__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0 = 0;
    CData/*0:0*/ __VdlySet__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0;
    __VdlySet__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0 = 0;
    IData/*31:0*/ __VExpandSel_WordIdx_1;
    IData/*31:0*/ __VExpandSel_LoShift_1;
    CData/*0:0*/ __VExpandSel_Aligned_1;
    IData/*31:0*/ __VExpandSel_HiShift_1;
    IData/*31:0*/ __VExpandSel_HiMask_1;
    // Body
    __VdlySet__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0 = 0U;
    if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni) {
        if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_en_c) {
            __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[0U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[0U];
            __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[1U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[1U];
            __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[2U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[2U];
            __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[3U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[3U];
            __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[4U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[4U];
            __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[5U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[5U];
            __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[6U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[6U];
            __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[7U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[7U];
            __VdlyDim0__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0 
                = (0x0000007fU & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_idx_c));
            __VdlySet__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0 = 1U;
        }
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r 
            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n;
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r 
            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n;
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_r 
            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_n;
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_r 
            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_n;
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r 
            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n;
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r 
            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n;
    } else {
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r = 0U;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_r 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni) 
           && (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_n));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_r 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni) 
           && (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_n));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_r 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni) 
           && (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_n));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_r 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni) 
           && (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_n));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_r 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__rst_ni) 
           && (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n));
    if (__VdlySet__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0) {
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0][0U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[0U];
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0][1U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[1U];
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0][2U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[2U];
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0][3U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[3U];
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0][4U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[4U];
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0][5U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[5U];
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0][6U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[6U];
        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0][7U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_data_r__v0[7U];
    }
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__sample_pad_beats_c 
        = (0x000000ffU & ((IData)(0x80U) - (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r)));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_overflow_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__actual_sample_cnt_c 
        = ((0x1000U <= (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_r))
            ? 0x00000400U : (0x000007ffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_r) 
                                            >> 2U)));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__is_slot_last_beat_c 
        = (0x85U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r));
    vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tkeep = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tready = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r) 
                      >> 1U)))) {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tready = 1U;
        }
    }
    vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tvalid = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_valid_good_packer_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_valid_good_o;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_packer_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_seq_o;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_overflow_err_packer_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_overflow_err_o;
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
    vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tlast = 0U;
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
    vlSelfRef.pipeline_cocotb_top__DOT__slot_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_valid_good_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_valid_good_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_valid_good_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_ctrl_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_overflow_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_overflow_err_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_overflow_err_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_overflow_err_packer_c;
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
    vlSelfRef.pipeline_cocotb_top__DOT__slot_start_packer_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_start_o;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_done_packer_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__slot_done_o;
    vlSelfRef.slot_valid_good_o = vlSelfRef.pipeline_cocotb_top__DOT__slot_valid_good_o;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_ctrl_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_seq_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_ctrl_c;
    vlSelfRef.slot_overflow_err_o = vlSelfRef.pipeline_cocotb_top__DOT__slot_overflow_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_start_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_start_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_start_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_start_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__slot_done_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_done_packer_c;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_done_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__slot_done_packer_c;
    vlSelfRef.slot_seq_o = vlSelfRef.pipeline_cocotb_top__DOT__slot_seq_o;
    vlSelfRef.slot_start_o = vlSelfRef.pipeline_cocotb_top__DOT__slot_start_o;
    vlSelfRef.slot_done_o = vlSelfRef.pipeline_cocotb_top__DOT__slot_done_o;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
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
    IData/*16:0*/ __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r;
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r = 0;
    IData/*16:0*/ __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r;
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r = 0;
    SData/*15:0*/ __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r;
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r = 0;
    CData/*0:0*/ __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r;
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r = 0;
    CData/*0:0*/ __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r;
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r = 0;
    QData/*33:0*/ __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r;
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r = 0;
    VlWide<8>/*255:0*/ __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0;
    VL_ZERO_W(256, __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0);
    CData/*7:0*/ __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0;
    __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0 = 0;
    CData/*0:0*/ __VdlySet__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0;
    __VdlySet__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0 = 0;
    IData/*31:0*/ __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_keep_r__v0;
    __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_keep_r__v0 = 0;
    CData/*7:0*/ __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_keep_r__v0;
    __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_keep_r__v0 = 0;
    QData/*33:0*/ __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0;
    __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0 = 0;
    CData/*4:0*/ __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0;
    __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0 = 0;
    CData/*0:0*/ __VdlySet__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0;
    __VdlySet__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0 = 0;
    IData/*16:0*/ __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_bytes_r__v0;
    __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_bytes_r__v0 = 0;
    CData/*4:0*/ __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_bytes_r__v0;
    __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_bytes_r__v0 = 0;
    IData/*16:0*/ __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_alloc_bytes_r__v0;
    __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_alloc_bytes_r__v0 = 0;
    CData/*4:0*/ __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_alloc_bytes_r__v0;
    __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_alloc_bytes_r__v0 = 0;
    SData/*15:0*/ __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_seq_r__v0;
    __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_seq_r__v0 = 0;
    CData/*4:0*/ __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_seq_r__v0;
    __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_seq_r__v0 = 0;
    CData/*0:0*/ __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_valid_good_r__v0;
    __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_valid_good_r__v0 = 0;
    CData/*4:0*/ __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_valid_good_r__v0;
    __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_valid_good_r__v0 = 0;
    CData/*0:0*/ __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_overflow_err_r__v0;
    __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_overflow_err_r__v0 = 0;
    CData/*4:0*/ __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_overflow_err_r__v0;
    __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_overflow_err_r__v0 = 0;
    // Body
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r;
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r;
    __VdlySet__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0 = 0U;
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r;
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r;
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r;
    __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r;
    __VdlySet__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0 = 0U;
    if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rst_ni) {
        if ((((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_enable_i)) 
              & (0U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r))) 
             & (0U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r)))) {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_r = 0U;
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r = 0U;
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r = 0U;
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r = 0U;
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r = 0U;
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_r = 0U;
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r = 0ULL;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_r = 0ULL;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_idx_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_r = 0ULL;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_r = 0ULL;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_alloc_bytes_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_meta_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_meta_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_seg_bytes_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_second_seg_bytes_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_idx_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_r = 0ULL;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_beat_pending_r = 0U;
            VL_ASSIGN_W(256, vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r, Vtop__ConstPool__CONST_h9e67c271_0);
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_r = 0ULL;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r = 0U;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r = 0U;
        } else {
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_idx_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_idx_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_alloc_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_alloc_bytes_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_meta_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_meta_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_meta_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_meta_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_seg_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_seg_bytes_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_second_seg_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_second_seg_bytes_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_idx_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_idx_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_beat_pending_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_beat_pending_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[0U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[0U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[1U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[1U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[2U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[2U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[3U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[3U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[4U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[4U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[5U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[5U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[6U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[6U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r[7U] 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_n[7U];
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_n;
            vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_n;
            if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_en_c) {
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[0U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[0U];
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[1U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[1U];
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[2U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[2U];
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[3U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[3U];
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[4U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[4U];
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[5U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[5U];
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[6U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[6U];
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[7U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_data_c[7U];
                __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_idx_c;
                __VdlySet__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0 = 1U;
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_keep_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_keep_c;
                __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_keep_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_wr_idx_c;
            }
            if (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_c) {
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r;
                __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_idx_c;
                __VdlySet__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0 = 1U;
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_bytes_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r;
                __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_bytes_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_idx_c;
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_alloc_bytes_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r;
                __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_alloc_bytes_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_idx_c;
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_seq_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r;
                __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_seq_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_idx_c;
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_valid_good_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r;
                __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_valid_good_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_idx_c;
                __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_overflow_err_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r;
                __VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_overflow_err_r__v0 
                    = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_push_idx_c;
            }
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_n;
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_n;
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_n;
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_n;
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_n;
            __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r 
                = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_n;
        }
    } else {
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r = 0ULL;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_r = 0ULL;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_r = 0ULL;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wrap_count_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__overflow_count_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__drop_count_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_head_ptr_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_tail_ptr_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_beat_count_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_actual_bytes_r = 0U;
        __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r = 0U;
        __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r = 0U;
        __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r = 0U;
        __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r = 0U;
        __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_r = 0U;
        __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r = 0ULL;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_next_wr_ptr_r = 0ULL;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_first_seg_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_second_seg_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_wrap_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_idx_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_addr_r = 0ULL;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_seg_bytes_rem_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_buf_beat_idx_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beats_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_burst_beat_sent_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_addr_r = 0ULL;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_alloc_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_seq_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_valid_good_meta_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_slot_overflow_meta_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_seg_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_second_seg_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_idx_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_addr_r = 0ULL;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_seg_bytes_rem_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_total_bytes_rem_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_burst_beats_rcvd_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_first_beat_pending_r = 0U;
        VL_ASSIGN_W(256, vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_data_r, Vtop__ConstPool__CONST_h9e67c271_0);
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_keep_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_user_r = 0ULL;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_last_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_cfg_align_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_no_space_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_proto_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_slot_too_large_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_wr_resp_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_axi_rd_resp_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__err_illegal_read_r = 0U;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r 
        = __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r 
        = __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r;
    if (__VdlySet__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0) {
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0][0U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[0U];
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0][1U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[1U];
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0][2U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[2U];
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0][3U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[3U];
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0][4U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[4U];
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0][5U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[5U];
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0][6U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[6U];
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0][7U] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_data_r__v0[7U];
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_keep_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_keep_r__v0] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_buf_keep_r__v0;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r 
        = __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r 
        = __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r 
        = __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r 
        = __Vdly__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r;
    if (__VdlySet__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0) {
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_alloc_bytes_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_alloc_bytes_r__v0] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_alloc_bytes_r__v0;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_addr_r__v0;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_bytes_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_bytes_r__v0] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_bytes_r__v0;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_seq_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_seq_r__v0] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_seq_r__v0;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_valid_good_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_valid_good_r__v0] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_valid_good_r__v0;
        vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_overflow_err_r[__VdlyDim0__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_overflow_err_r__v0] 
            = __VdlyVal__pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_overflow_err_r__v0;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__dbg_wr_state_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_state_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_addr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_addr_r;
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
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__empty_o 
        = (0U == vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_alloc_bytes_r);
    vlSelfRef.pipeline_cocotb_top__DOT__dbg_rd_state_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_overflow_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_invalid_c 
        = (1U & ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_valid_good_r)) 
                 | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_proto_err_r) 
                    | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_slot_overflow_err_r) 
                       | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_size_mismatch_r) 
                          | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_too_large_r))))));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_c 
        = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i 
                          - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_alloc_bytes_r));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_fire_c 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r) 
           & (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tready));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_busy_o 
        = ((0U != (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_state_r)) 
           | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_axis_valid_r));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r;
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
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_end_c 
        = (0x0001ffffU & (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_base_addr_i) 
                           + vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_ring_size_bytes_i) 
                          - (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_r)));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_full_c 
        = (0x20U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_r));
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_fifo_empty_c 
        = (0U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__desc_count_r));
    vlSelfRef.dbg_wr_state_o = vlSelfRef.pipeline_cocotb_top__DOT__dbg_wr_state_o;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_ptr_o = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_ptr_o;
    vlSelfRef.pipeline_cocotb_top__DOT__commit_ptr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__commit_ptr_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_seq_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_addr_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_addr_o;
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
    vlSelfRef.pipeline_cocotb_top__DOT__committed_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__committed_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__empty_o = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__empty_o;
    vlSelfRef.dbg_rd_state_o = vlSelfRef.pipeline_cocotb_top__DOT__dbg_rd_state_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_valid_good_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_overflow_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_overflow_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_drop_now_c 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cfg_drop_invalid_slot_i) 
           & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__slot_invalid_c));
    vlSelfRef.pipeline_cocotb_top__DOT__used_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__used_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_c;
    vlSelfRef.pipeline_cocotb_top__DOT__rd_busy_o = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__rd_busy_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_slot_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__wr_ptr_o = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__wr_ptr_o;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__next_wr_wrap_c 
        = (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_alloc_bytes_r 
           >= vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_end_c);
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__first_seg_bytes_c 
        = ((vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r 
            <= vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_end_c)
            ? vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r
            : vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__bytes_to_end_c);
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
    vlSelfRef.rd_ptr_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_ptr_o;
    vlSelfRef.commit_ptr_o = vlSelfRef.pipeline_cocotb_top__DOT__commit_ptr_o;
    vlSelfRef.wr_slot_seq_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_seq_o;
    vlSelfRef.wr_slot_addr_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_addr_o;
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
    vlSelfRef.committed_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__committed_bytes_o;
    vlSelfRef.empty_o = vlSelfRef.pipeline_cocotb_top__DOT__empty_o;
    vlSelfRef.wr_slot_valid_good_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_valid_good_o;
    vlSelfRef.wr_slot_overflow_err_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_overflow_err_o;
    vlSelfRef.used_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__used_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__free_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__free_bytes_o;
    vlSelfRef.rd_busy_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_busy_o;
    vlSelfRef.wr_slot_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_slot_bytes_o;
    vlSelfRef.wr_ptr_o = vlSelfRef.pipeline_cocotb_top__DOT__wr_ptr_o;
    vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__second_seg_bytes_c 
        = (0x0001ffffU & (vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__cap_effective_bytes_r 
                          - vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__first_seg_bytes_c));
    vlSelfRef.pipeline_cocotb_top__DOT__full_o = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__full_o;
    vlSelfRef.pipeline_cocotb_top__DOT__almost_full_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__ringbuffer_u__DOT__almost_full_o;
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
    vlSelfRef.free_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__free_bytes_o;
    vlSelfRef.full_o = vlSelfRef.pipeline_cocotb_top__DOT__full_o;
    vlSelfRef.almost_full_o = vlSelfRef.pipeline_cocotb_top__DOT__almost_full_o;
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
    vlSelfRef.rd_slot_addr_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_addr_o;
    vlSelfRef.rd_slot_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_bytes_o;
    vlSelfRef.rd_slot_seq_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_seq_o;
    vlSelfRef.rd_slot_valid_good_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_valid_good_o;
    vlSelfRef.rd_slot_overflow_err_o = vlSelfRef.pipeline_cocotb_top__DOT__rd_slot_overflow_err_o;
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
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
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tuser 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tuser;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tlast 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tlast;
    vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tvalid 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if.tvalid;
    vlSelfRef.m_axis_rd_tdata[0U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[0U];
    vlSelfRef.m_axis_rd_tdata[1U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[1U];
    vlSelfRef.m_axis_rd_tdata[2U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[2U];
    vlSelfRef.m_axis_rd_tdata[3U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[3U];
    vlSelfRef.m_axis_rd_tdata[4U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[4U];
    vlSelfRef.m_axis_rd_tdata[5U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[5U];
    vlSelfRef.m_axis_rd_tdata[6U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[6U];
    vlSelfRef.m_axis_rd_tdata[7U] = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tdata[7U];
    vlSelfRef.m_axis_rd_tkeep = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tkeep;
    vlSelfRef.m_axis_rd_tuser = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tuser;
    vlSelfRef.m_axis_rd_tlast = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tlast;
    vlSelfRef.m_axis_rd_tvalid = vlSelfRef.pipeline_cocotb_top__DOT__m_axis_rd_tvalid;
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
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
    if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__rst_ni) {
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_r 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_n;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_r 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_n;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_n;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_n;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[0U];
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[1U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[1U];
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[2U];
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[3U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[3U];
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[4U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[4U];
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[5U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[5U];
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[6U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[6U];
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[7U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[7U];
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[8U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[8U];
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[9U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[9U];
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[10U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[10U];
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[11U] 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_n[11U];
    } else {
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[1U] = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U] = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[3U] = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[4U] = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[5U] = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[6U] = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[7U] = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[8U] = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[9U] = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[10U] = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[11U] = 0U;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_r 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__rst_ni) 
           && (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_n));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_r 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__rst_ni) 
           && (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_n));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__rst_ni) 
           && (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_crc_err_c 
        = (1U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
                 >> 1U));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_ecc_err_c 
        = (1U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
                 >> 2U));
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
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_trunc_err_c 
        = (1U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
                 >> 3U));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_vc_c 
        = (3U & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
                 >> 8U));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_dt_c 
        = (0x0000003fU & (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U] 
                          >> 0x00000010U));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h503bf3ac__0 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_trunc_err_c) 
           | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_bytes_c) 
              != (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_payload_len_c)));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h5ac0cf88__0 
        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_trunc_err_c) 
           | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_bytes_c) 
              > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_payload_len_c)));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c 
        = (1U & (((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_vc_en_i)) 
                  | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_vc_i) 
                     == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_vc_c))) 
                 & ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_dt_en_i)) 
                    | ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__cfg_dt_i) 
                       == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_dt_c)))));
    vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tlast = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tuser = 0ULL;
    VL_ASSIGN_W(256, vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tdata, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tkeep = 0U;
    vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tvalid = 0U;
    if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
        if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)))) {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tlast 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tlast;
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tuser 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tuser;
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
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tvalid 
                = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tvalid;
        }
    } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
        if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c) {
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tlast 
                = (1U & vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U]);
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tuser 
                = (((QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[1U])) 
                    << 0x00000020U) | (QData)((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[0U])));
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
            vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tvalid = 1U;
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
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c 
        = ((IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tready) 
           & (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if.tvalid));
}

void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tready = 0U;
    if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
        vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tready 
            = ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)) 
               || (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.tready));
    } else if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)))) {
        vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tready = 1U;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tready 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tready;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c 
        = ((IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tready) 
           & (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tvalid));
    vlSelfRef.s_axis_tready = vlSelfRef.pipeline_cocotb_top__DOT__s_axis_tready;
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
}

void Vtop___024root___nba_comb__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.__VdfgRegularize_hebeb780c_0_0;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__m_fire_c 
        = vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if.__VdfgRegularize_hebeb780c_0_0;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_idx_c = 0U;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_en_c = 0U;
    VL_ASSIGN_W(256, vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c, Vtop__ConstPool__CONST_h9e67c271_0);
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r;
    if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r) 
                  >> 1U)))) {
        if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__m_fire_c) {
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_n 
                        = (0x0000ffffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_r)));
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_r;
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_payload_len_c;
                }
            }
        } else if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c) {
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_n = 0U;
        }
    }
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_start_o 
        = ((1U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)) 
           & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__m_fire_c) 
              & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c)));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r;
    if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
        if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
            if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c) 
                 & (IData)(vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tlast))) {
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n = 0U;
            }
        } else if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c) {
            if (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tlast) {
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n = 0U;
            }
        }
        if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)))) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_n 
                    = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_r) 
                       | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_crc_err_c));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_n 
                    = (0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                                      + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c)));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_n 
                    = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_r) 
                       | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_ecc_err_c));
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
                    = (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r) 
                        | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_trunc_err_c)) 
                       | ((0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c))) 
                          > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r)));
                if (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tlast) {
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
                        = (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r) 
                            | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_trunc_err_c)) 
                           | ((0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                                              + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c))) 
                              != (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r)));
                }
            }
        }
    } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r))) {
        if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__m_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_crc_err_c;
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_bytes_c;
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_ecc_err_c;
                vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
                    = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_trunc_err_c;
                if ((1U & vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U])) {
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n = 0U;
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h503bf3ac__0;
                } else {
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n = 2U;
                    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h5ac0cf88__0;
                }
            }
        } else {
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n 
                = ((1U & vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U])
                    ? 0U : 3U);
        }
    } else if (vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c) {
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_n = 1U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_n = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_n = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_n = 0U;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_n = 0U;
    }
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_view_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_view_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_view_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_view_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_view_c = 0U;
    if ((((1U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)) 
          & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_match_c)) 
         & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__m_fire_c))) {
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_ctr_r;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_bytes_c;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_crc_err_c;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_ecc_err_c;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_trunc_err_c;
        if ((1U & vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__first_beat_r[2U])) {
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
                = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h503bf3ac__0;
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_view_c = 1U;
        } else {
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
                = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT____VdfgExtracted_h5ac0cf88__0;
        }
    } else if (((2U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__state_r)) 
                & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__s_fire_c))) {
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_view_c 
            = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_r;
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_view_c 
            = (0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                              + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c)));
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_view_c 
            = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_r) 
               | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_crc_err_c));
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_view_c 
            = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_r) 
               | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_ecc_err_c));
        vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
            = (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r) 
                | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_trunc_err_c)) 
               | ((0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                                  + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c))) 
                  > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r)));
        if (vlSymsp->TOP__pipeline_cocotb_top__DOT__s_axis_if.tlast) {
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c 
                = (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_r) 
                    | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_trunc_err_c)) 
                   | ((0x0000ffffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_r) 
                                      + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__stream_beat_bytes_c))) 
                      != (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__exp_pkt_bytes_r)));
            vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_view_c = 1U;
        }
    }
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_start_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_start_o;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_view_c;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_view_c;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_view_c;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_view_c;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c;
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_valid_good_o 
        = ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_view_c)) 
           & ((~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_view_c) 
                  | (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_view_c))) 
              & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_view_c)));
    vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_view_c;
    vlSelfRef.pkt_start_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_start_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_start_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_start_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_seq_o = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_seq_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_bytes_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_crc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_crc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_ecc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_ecc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_trunc_err_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_trunc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_valid_good_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_valid_good_o;
    vlSelfRef.pipeline_cocotb_top__DOT__pkt_done_o 
        = vlSelfRef.pipeline_cocotb_top__DOT__extractor_u__DOT__pkt_done_o;
    vlSelfRef.pkt_seq_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_seq_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_seq_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_seq_o;
    vlSelfRef.pkt_bytes_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_bytes_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_bytes_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_bytes_o;
    vlSelfRef.pkt_crc_err_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_crc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_crc_err_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_crc_err_o;
    vlSelfRef.pkt_ecc_err_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_ecc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_ecc_err_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_ecc_err_o;
    vlSelfRef.pkt_trunc_err_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_trunc_err_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_trunc_err_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_trunc_err_o;
    vlSelfRef.pkt_valid_good_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_valid_good_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_valid_good_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_valid_good_o;
    vlSelfRef.pkt_done_o = vlSelfRef.pipeline_cocotb_top__DOT__pkt_done_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i 
        = vlSelfRef.pipeline_cocotb_top__DOT__pkt_done_o;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c 
        = ((~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_valid_good_i)) 
           & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cfg_drop_invalid_pkt_i));
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_r;
    if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                    if ((0x80U > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_idx_c 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_en_c = 1U;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[0U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[0U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[1U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[1U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[2U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[2U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[3U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[3U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[4U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[4U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[5U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[5U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[6U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[6U];
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[7U] 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[7U];
                    }
                    if ((0x80U <= (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n = 1U;
                    }
                    if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_bytes_i;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_crc_err_i;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_ecc_err_i;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_trunc_err_i;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_n 
                            = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_valid_good_i;
                        if ((0x1000U < (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_bytes_i))) {
                            vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n = 1U;
                        }
                    }
                }
            } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_idx_c = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_en_c = 1U;
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[0U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[0U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[1U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[1U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[2U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[2U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[3U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[3U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[4U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[4U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[5U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[5U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[6U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[6U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_buf_wr_data_c[7U] 
                    = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__masked_data_c[7U];
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n = 0U;
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_bytes_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_bytes_i;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_crc_err_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_crc_err_i;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_ecc_err_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_ecc_err_i;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_trunc_err_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_trunc_err_i;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_valid_good_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_valid_good_i;
                    if ((0x1000U < (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_bytes_i))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_overflow_n = 1U;
                    }
                }
            }
            if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r)))) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_pkt_seq_n 
                        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_seq_i;
                }
            }
        }
    }
}

void Vtop___024root___nba_comb__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r;
    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n 
        = vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r;
    if ((4U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
        if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r)))) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r)));
                    if ((0xffU == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n = 0U;
                    }
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r)));
                }
            }
            if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n = 0U;
            } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
                if ((0xffU == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r)));
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r)));
                if ((3U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n = 0U;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n = 0U;
                }
            }
        } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
            vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
                = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r)));
            vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
                = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r)));
            if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r) 
                 == (0x000000ffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__sample_pad_beats_c) 
                                    - (IData)(1U))))) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n = 5U;
            }
        }
    } else {
        if ((2U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r)));
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r)));
                    if (((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r) 
                         == (0x000000ffU & ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r) 
                                            - (IData)(1U))))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n 
                            = ((0x80U > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r))
                                ? 4U : 5U);
                    }
                }
            } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__m_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_r)));
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n 
                    = (0x000000ffU & ((IData)(1U) + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r)));
                if ((1U == (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_r))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n 
                        = ((0U < (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r))
                            ? 3U : 4U);
                }
            }
        } else if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                    if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c)))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n = 0U;
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                    }
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n 
                        = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c)
                            ? 0U : 2U);
                }
            }
        } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
            if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                if ((1U & (~ (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c)))) {
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__total_out_beat_cnt_n = 0U;
                    vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__out_beat_cnt_n = 0U;
                }
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n 
                    = ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c)
                        ? 0U : 2U);
            } else {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_n = 1U;
            }
        }
        if ((1U & (~ ((IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r) 
                      >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__state_r))) {
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                    if ((0x80U > (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r))) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n 
                            = (0x000000ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_r)));
                    }
                    if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                        if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c) {
                            vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n = 0U;
                        }
                    }
                }
            } else if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__s_fire_c) {
                vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n = 1U;
                if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__pkt_done_i) {
                    if (vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__should_drop_c) {
                        vlSelfRef.pipeline_cocotb_top__DOT__packer_u__DOT__cap_beat_cnt_n = 0U;
                    }
                }
            }
        }
    }
}

void Vtop_axis_stream_if___nba_sequent__TOP__pipeline_cocotb_top__DOT__m_axis_rd_if__0(Vtop_axis_stream_if* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0x000000000000000cULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x0000000000000030ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
        Vtop_axis_stream_if___nba_sequent__TOP__pipeline_cocotb_top__DOT__m_axis_rd_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__m_axis_rd_if));
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x000000000000003cULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__slot_axis_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__slot_axis_if));
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__2(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__pipeline_cocotb_top__DOT__pkt_axis_if__0((&vlSymsp->TOP__pipeline_cocotb_top__DOT__pkt_axis_if));
        Vtop___024root___nba_comb__TOP__3(vlSelf);
    }
    if ((0x000000000000003fULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__4(vlSelf);
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
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/pipeline_cocotb_top.sv", 5, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 100 tries");
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
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/pipeline_cocotb_top.sv", 5, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/pipeline_cocotb_top.sv", 5, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.cfg_drop_invalid_pkt_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("cfg_drop_invalid_pkt_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.cfg_enable_i & 0xfeU)))) {
        Verilated::overWidthError("cfg_enable_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.cfg_allow_overwrite_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("cfg_allow_overwrite_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.cfg_drop_invalid_slot_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("cfg_drop_invalid_slot_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.cfg_drop_on_no_space_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("cfg_drop_on_no_space_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.cfg_ring_base_addr_i 
                      & 0ULL)))) {
        Verilated::overWidthError("cfg_ring_base_addr_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.cfg_ring_size_bytes_i 
                      & 0xfffe0000U)))) {
        Verilated::overWidthError("cfg_ring_size_bytes_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rd_slot_req_i & 0xfeU)))) {
        Verilated::overWidthError("rd_slot_req_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rd_consume_i & 0xfeU)))) {
        Verilated::overWidthError("rd_consume_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.s_axis_tvalid & 0xfeU)))) {
        Verilated::overWidthError("s_axis_tvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.s_axis_tlast & 0xfeU)))) {
        Verilated::overWidthError("s_axis_tlast");
    }
    if (VL_UNLIKELY(((vlSelfRef.m_axis_rd_tready & 0xfeU)))) {
        Verilated::overWidthError("m_axis_rd_tready");
    }
    if (VL_UNLIKELY(((vlSelfRef.m_axi_awready & 0xfeU)))) {
        Verilated::overWidthError("m_axi_awready");
    }
    if (VL_UNLIKELY(((vlSelfRef.m_axi_wready & 0xfeU)))) {
        Verilated::overWidthError("m_axi_wready");
    }
    if (VL_UNLIKELY(((vlSelfRef.m_axi_bresp & 0xfcU)))) {
        Verilated::overWidthError("m_axi_bresp");
    }
    if (VL_UNLIKELY(((vlSelfRef.m_axi_bvalid & 0xfeU)))) {
        Verilated::overWidthError("m_axi_bvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.m_axi_arready & 0xfeU)))) {
        Verilated::overWidthError("m_axi_arready");
    }
    if (VL_UNLIKELY(((vlSelfRef.m_axi_rresp & 0xfcU)))) {
        Verilated::overWidthError("m_axi_rresp");
    }
    if (VL_UNLIKELY(((vlSelfRef.m_axi_rlast & 0xfeU)))) {
        Verilated::overWidthError("m_axi_rlast");
    }
    if (VL_UNLIKELY(((vlSelfRef.m_axi_rvalid & 0xfeU)))) {
        Verilated::overWidthError("m_axi_rvalid");
    }
}
#endif  // VL_DEBUG
