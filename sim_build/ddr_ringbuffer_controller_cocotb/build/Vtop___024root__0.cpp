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
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__clk_i 
        = vlSelfRef.clk_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rst_ni 
        = vlSelfRef.rst_ni;
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
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__clk_i 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__clk_i;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rst_ni 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rst_ni;
    vlSelfRef.dbg_rd_state_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_rd_state_o;
    vlSelfRef.dbg_wr_state_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_state_o;
    vlSelfRef.dbg_wr_burst_beats_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_beats_o;
    vlSelfRef.dbg_wr_burst_sent_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_sent_o;
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

void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__1\n"); );
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

void Vtop___024root___ico_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tready 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tready;
    vlSelfRef.s_axis_slot_tready = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tready;
}

void Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if__0(Vtop_axis_stream_if* vlSelf);
void Vtop_axi4_mm_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if__0(Vtop_axi4_mm_if* vlSelf);
void Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if__1(Vtop_axis_stream_if* vlSelf);

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if__0((&vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if));
        Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if__0((&vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if));
        Vtop_axi4_mm_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if__0((&vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if));
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
        Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if__1((&vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if));
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
                                                    ((((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rst_ni)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rst_ni__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__clk_i) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__clk_i__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__clk_i__0 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__clk_i;
    vlSelfRef.__Vtrigprevexpr___TOP__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rst_ni__0 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rst_ni;
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
    QData/*33:0*/ __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__base_addr;
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__base_addr = 0;
    IData/*16:0*/ __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__ring_size_bytes;
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__ring_size_bytes = 0;
    QData/*33:0*/ __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__curr_addr;
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__curr_addr = 0;
    IData/*16:0*/ __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__advance_bytes;
    __Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__4__advance_bytes = 0;
    IData/*16:0*/ __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r;
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r = 0;
    IData/*16:0*/ __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r;
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r = 0;
    SData/*15:0*/ __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r;
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r = 0;
    CData/*0:0*/ __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r;
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r = 0;
    CData/*0:0*/ __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r;
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r = 0;
    QData/*33:0*/ __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r;
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r = 0;
    VlWide<8>/*255:0*/ __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0;
    VL_ZERO_W(256, __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0);
    CData/*3:0*/ __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0;
    __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0 = 0;
    CData/*0:0*/ __VdlySet__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0;
    __VdlySet__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0 = 0;
    IData/*31:0*/ __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_keep_r__v0;
    __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_keep_r__v0 = 0;
    CData/*3:0*/ __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_keep_r__v0;
    __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_keep_r__v0 = 0;
    QData/*33:0*/ __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0;
    __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0 = 0;
    CData/*2:0*/ __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0;
    __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0 = 0;
    CData/*0:0*/ __VdlySet__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0;
    __VdlySet__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0 = 0;
    IData/*16:0*/ __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_bytes_r__v0;
    __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_bytes_r__v0 = 0;
    CData/*2:0*/ __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_bytes_r__v0;
    __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_bytes_r__v0 = 0;
    IData/*16:0*/ __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_alloc_bytes_r__v0;
    __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_alloc_bytes_r__v0 = 0;
    CData/*2:0*/ __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_alloc_bytes_r__v0;
    __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_alloc_bytes_r__v0 = 0;
    SData/*15:0*/ __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_seq_r__v0;
    __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_seq_r__v0 = 0;
    CData/*2:0*/ __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_seq_r__v0;
    __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_seq_r__v0 = 0;
    CData/*0:0*/ __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_valid_good_r__v0;
    __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_valid_good_r__v0 = 0;
    CData/*2:0*/ __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_valid_good_r__v0;
    __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_valid_good_r__v0 = 0;
    CData/*0:0*/ __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_overflow_err_r__v0;
    __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_overflow_err_r__v0 = 0;
    CData/*2:0*/ __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_overflow_err_r__v0;
    __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_overflow_err_r__v0 = 0;
    // Body
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r;
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r;
    __VdlySet__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0 = 0U;
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r;
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r;
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r;
    __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r;
    __VdlySet__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0 = 0U;
    if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rst_ni) {
        if ((((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_enable_i)) 
              & (0U == (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r))) 
             & (0U == (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r)))) {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_r = 0U;
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r = 0U;
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r = 0U;
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r = 0U;
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r = 0U;
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_r = 0U;
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r = 0ULL;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_r = 0ULL;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_idx_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_r = 0ULL;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_r = 0ULL;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_alloc_bytes_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_meta_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_meta_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_seg_bytes_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_second_seg_bytes_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_idx_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_r = 0ULL;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_beat_pending_r = 0U;
            VL_ASSIGN_W(256, vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r, Vtop__ConstPool__CONST_h9e67c271_0);
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_keep_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_user_r = 0ULL;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r = 0U;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r = 0U;
        } else {
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_idx_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_idx_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_alloc_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_alloc_bytes_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_meta_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_meta_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_meta_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_meta_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_seg_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_seg_bytes_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_second_seg_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_second_seg_bytes_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_idx_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_idx_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_beat_pending_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_beat_pending_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[0U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[0U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[1U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[1U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[2U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[2U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[3U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[3U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[4U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[4U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[5U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[5U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[6U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[6U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r[7U] 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_n[7U];
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_keep_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_keep_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_user_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_user_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_n;
            vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_n;
            if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_en_c) {
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[0U] 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[0U];
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[1U] 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[1U];
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[2U] 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[2U];
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[3U] 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[3U];
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[4U] 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[4U];
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[5U] 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[5U];
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[6U] 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[6U];
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[7U] 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_data_c[7U];
                __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_idx_c;
                __VdlySet__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0 = 1U;
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_keep_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_keep_c;
                __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_keep_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_wr_idx_c;
            }
            if (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_c) {
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r;
                __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_idx_c;
                __VdlySet__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0 = 1U;
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_bytes_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r;
                __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_bytes_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_idx_c;
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_alloc_bytes_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r;
                __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_alloc_bytes_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_idx_c;
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_seq_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r;
                __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_seq_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_idx_c;
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_valid_good_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r;
                __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_valid_good_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_idx_c;
                __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_overflow_err_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r;
                __VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_overflow_err_r__v0 
                    = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_push_idx_c;
            }
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_n;
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_n;
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_n;
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_n;
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_n;
            __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r 
                = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_n;
        }
    } else {
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r = 0ULL;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_r = 0ULL;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_r = 0ULL;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wrap_count_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__overflow_count_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__drop_count_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_head_ptr_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_tail_ptr_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_beat_count_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_actual_bytes_r = 0U;
        __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r = 0U;
        __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r = 0U;
        __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r = 0U;
        __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r = 0U;
        __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_r = 0U;
        __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r = 0ULL;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_next_wr_ptr_r = 0ULL;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_first_seg_bytes_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_second_seg_bytes_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_wrap_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_idx_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_addr_r = 0ULL;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_seg_bytes_rem_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_buf_beat_idx_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_bytes_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_addr_r = 0ULL;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_bytes_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_alloc_bytes_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_seq_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_valid_good_meta_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_slot_overflow_meta_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_seg_bytes_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_second_seg_bytes_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_idx_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_addr_r = 0ULL;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_seg_bytes_rem_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_total_bytes_rem_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_bytes_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_burst_beats_rcvd_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_first_beat_pending_r = 0U;
        VL_ASSIGN_W(256, vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_data_r, Vtop__ConstPool__CONST_h9e67c271_0);
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_keep_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_user_r = 0ULL;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_last_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_cfg_align_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_no_space_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_proto_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_slot_too_large_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_wr_resp_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_axi_rd_resp_r = 0U;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__err_illegal_read_r = 0U;
    }
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r 
        = __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r 
        = __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r;
    if (__VdlySet__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0) {
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0][0U] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[0U];
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0][1U] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[1U];
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0][2U] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[2U];
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0][3U] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[3U];
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0][4U] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[4U];
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0][5U] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[5U];
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0][6U] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[6U];
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0][7U] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_data_r__v0[7U];
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_keep_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_keep_r__v0] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_buf_keep_r__v0;
    }
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r 
        = __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r 
        = __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r 
        = __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r 
        = __Vdly__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r;
    if (__VdlySet__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0) {
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_alloc_bytes_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_alloc_bytes_r__v0] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_alloc_bytes_r__v0;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_addr_r__v0;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_bytes_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_bytes_r__v0] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_bytes_r__v0;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_seq_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_seq_r__v0] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_seq_r__v0;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_valid_good_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_valid_good_r__v0] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_valid_good_r__v0;
        vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_overflow_err_r[__VdlyDim0__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_overflow_err_r__v0] 
            = __VdlyVal__ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_overflow_err_r__v0;
    }
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_beats_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beats_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_sent_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_burst_beat_sent_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_state_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_state_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_seq_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_seq_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_addr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_addr_r;
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
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__empty_o 
        = (0U == vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_alloc_bytes_r);
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_rd_state_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_valid_good_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_overflow_err_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_invalid_c 
        = (1U & ((~ (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_valid_good_r)) 
                 | ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_proto_err_r) 
                    | ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_slot_overflow_err_r) 
                       | ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_size_mismatch_r) 
                          | (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_too_large_r))))));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_c 
        = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i 
                          - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_alloc_bytes_r));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_fire_c 
        = ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r) 
           & (IData)(vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tready));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_busy_o 
        = ((0U != (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_state_r)) 
           | (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_axis_valid_r));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r;
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
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_end_c 
        = (0x0001ffffU & (((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_base_addr_i) 
                           + vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_ring_size_bytes_i) 
                          - (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_r)));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_full_c 
        = (8U == (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_r));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_fifo_empty_c 
        = (0U == (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__desc_count_r));
    vlSelfRef.dbg_wr_burst_beats_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_beats_o;
    vlSelfRef.dbg_wr_burst_sent_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_burst_sent_o;
    vlSelfRef.dbg_wr_state_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_wr_state_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_ptr_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__commit_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__commit_ptr_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_seq_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_seq_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_addr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_addr_o;
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
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__committed_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__committed_bytes_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__empty_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__empty_o;
    vlSelfRef.dbg_rd_state_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dbg_rd_state_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_valid_good_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_valid_good_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_overflow_err_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_overflow_err_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_drop_now_c 
        = ((IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cfg_drop_invalid_slot_i) 
           & (IData)(vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__slot_invalid_c));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__used_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__used_bytes_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_c;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_busy_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__rd_busy_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_slot_bytes_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_ptr_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__wr_ptr_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__next_wr_wrap_c 
        = (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_alloc_bytes_r 
           >= vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_end_c);
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__first_seg_bytes_c 
        = ((vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r 
            <= vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_end_c)
            ? vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r
            : vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__bytes_to_end_c);
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
    vlSelfRef.rd_ptr_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_ptr_o;
    vlSelfRef.commit_ptr_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__commit_ptr_o;
    vlSelfRef.wr_slot_seq_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_seq_o;
    vlSelfRef.wr_slot_addr_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_addr_o;
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
    vlSelfRef.committed_bytes_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__committed_bytes_o;
    vlSelfRef.empty_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__empty_o;
    vlSelfRef.wr_slot_valid_good_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_valid_good_o;
    vlSelfRef.wr_slot_overflow_err_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_overflow_err_o;
    vlSelfRef.used_bytes_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__used_bytes_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__free_bytes_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__free_bytes_o;
    vlSelfRef.rd_busy_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_busy_o;
    vlSelfRef.wr_slot_bytes_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_slot_bytes_o;
    vlSelfRef.wr_ptr_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__wr_ptr_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__second_seg_bytes_c 
        = (0x0001ffffU & (vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__cap_effective_bytes_r 
                          - vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__first_seg_bytes_c));
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__full_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__full_o;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__almost_full_o 
        = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__almost_full_o;
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
    vlSelfRef.free_bytes_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__free_bytes_o;
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
                        goto __Vlabel1;
                    }
                    vlSelfRef.__Vfunc_min_u__5__Vfuncout 
                        = vlSelfRef.__Vfunc_min_u__5__rhs;
                    __Vlabel1: ;
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
                        goto __Vlabel2;
                    }
                    vlSelfRef.__Vfunc_ceil_div_u__6__Vfuncout 
                        = VL_DIV_III(32, ((vlSelfRef.__Vfunc_ceil_div_u__6__numerator 
                                           + vlSelfRef.__Vfunc_ceil_div_u__6__denominator) 
                                          - (IData)(1U)), vlSelfRef.__Vfunc_ceil_div_u__6__denominator);
                    __Vlabel2: ;
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
                        goto __Vlabel3;
                    }
                    vlSelfRef.__Vfunc_min_u__7__Vfuncout 
                        = vlSelfRef.__Vfunc_min_u__7__rhs;
                    __Vlabel3: ;
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
                        goto __Vlabel4;
                    }
                    vlSelfRef.__Vfunc_ceil_div_u__8__Vfuncout 
                        = VL_DIV_III(32, ((vlSelfRef.__Vfunc_ceil_div_u__8__numerator 
                                           + vlSelfRef.__Vfunc_ceil_div_u__8__denominator) 
                                          - (IData)(1U)), vlSelfRef.__Vfunc_ceil_div_u__8__denominator);
                    __Vlabel4: ;
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
                    goto __Vlabel5;
                }
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__9__Vfuncout 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__9__ptr)));
                __Vlabel5: ;
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
                    goto __Vlabel6;
                } else if ((vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__advance_bytes 
                            == vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__to_end_bytes)) {
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__Vfuncout 
                        = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__base_addr;
                    goto __Vlabel6;
                }
                vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__Vfuncout 
                    = (0x00000003ffffffffULL & (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__base_addr 
                                                + ((QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__advance_bytes)) 
                                                   - (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__10__to_end_bytes)))));
                __Vlabel6: ;
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
                        goto __Vlabel7;
                    }
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__11__Vfuncout 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__11__ptr)));
                    __Vlabel7: ;
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
                        goto __Vlabel8;
                    }
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__12__Vfuncout 
                        = (7U & ((IData)(1U) + (IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__fifo_ptr_next__12__ptr)));
                    __Vlabel8: ;
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
                        goto __Vlabel9;
                    } else if ((vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__advance_bytes 
                                == vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__to_end_bytes)) {
                        vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__Vfuncout 
                            = vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__base_addr;
                        goto __Vlabel9;
                    }
                    vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__Vfuncout 
                        = (0x00000003ffffffffULL & 
                           (vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__base_addr 
                            + ((QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__advance_bytes)) 
                               - (QData)((IData)(vlSelfRef.__Vfunc_ddr_ringbuffer_controller_cocotb_top__DOT__dut__DOT__ring_addr_add__13__to_end_bytes)))));
                    __Vlabel9: ;
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
    vlSelfRef.full_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__full_o;
    vlSelfRef.almost_full_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__almost_full_o;
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
    vlSelfRef.rd_slot_addr_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_addr_o;
    vlSelfRef.rd_slot_bytes_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_bytes_o;
    vlSelfRef.rd_slot_seq_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_seq_o;
    vlSelfRef.rd_slot_valid_good_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_valid_good_o;
    vlSelfRef.rd_slot_overflow_err_o = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__rd_slot_overflow_err_o;
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

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
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
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tuser 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tuser;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tlast 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tlast;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tvalid 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if.tvalid;
    vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tready 
        = vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if.tready;
    vlSelfRef.m_axis_rd_tdata[0U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[0U];
    vlSelfRef.m_axis_rd_tdata[1U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[1U];
    vlSelfRef.m_axis_rd_tdata[2U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[2U];
    vlSelfRef.m_axis_rd_tdata[3U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[3U];
    vlSelfRef.m_axis_rd_tdata[4U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[4U];
    vlSelfRef.m_axis_rd_tdata[5U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[5U];
    vlSelfRef.m_axis_rd_tdata[6U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[6U];
    vlSelfRef.m_axis_rd_tdata[7U] = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tdata[7U];
    vlSelfRef.m_axis_rd_tkeep = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tkeep;
    vlSelfRef.m_axis_rd_tuser = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tuser;
    vlSelfRef.m_axis_rd_tlast = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tlast;
    vlSelfRef.m_axis_rd_tvalid = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_tvalid;
    vlSelfRef.s_axis_slot_tready = vlSelfRef.ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_tready;
}

void Vtop_axis_stream_if___nba_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if__0(Vtop_axis_stream_if* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        Vtop_axis_stream_if___nba_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if__0((&vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if));
        Vtop_axis_stream_if___ico_sequent__TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if__1((&vlSymsp->TOP__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if));
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
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
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/ddr_ringbuffer_controller_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 100 tries");
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
            VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/ddr_ringbuffer_controller_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/ddr_ringbuffer_controller_cocotb_top.sv", 3, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.slot_start_i & 0xfeU)))) {
        Verilated::overWidthError("slot_start_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.slot_done_i & 0xfeU)))) {
        Verilated::overWidthError("slot_done_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.slot_bytes_i & 0xfffe0000U)))) {
        Verilated::overWidthError("slot_bytes_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.slot_valid_good_i & 0xfeU)))) {
        Verilated::overWidthError("slot_valid_good_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.slot_overflow_err_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("slot_overflow_err_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rd_slot_req_i & 0xfeU)))) {
        Verilated::overWidthError("rd_slot_req_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.rd_consume_i & 0xfeU)))) {
        Verilated::overWidthError("rd_consume_i");
    }
    if (VL_UNLIKELY(((vlSelfRef.s_axis_slot_tvalid 
                      & 0xfeU)))) {
        Verilated::overWidthError("s_axis_slot_tvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.s_axis_slot_tlast & 0xfeU)))) {
        Verilated::overWidthError("s_axis_slot_tlast");
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
