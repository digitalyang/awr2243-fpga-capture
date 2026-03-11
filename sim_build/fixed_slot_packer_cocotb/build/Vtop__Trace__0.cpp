// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.clk_i));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_ni));
    bufp->chgBit(oldp+2,(vlSelfRef.cfg_drop_invalid_pkt_i));
    bufp->chgBit(oldp+3,(vlSelfRef.pkt_start_i));
    bufp->chgBit(oldp+4,(vlSelfRef.pkt_done_i));
    bufp->chgSData(oldp+5,(vlSelfRef.pkt_bytes_i),16);
    bufp->chgSData(oldp+6,(vlSelfRef.pkt_seq_i),16);
    bufp->chgBit(oldp+7,(vlSelfRef.pkt_crc_err_i));
    bufp->chgBit(oldp+8,(vlSelfRef.pkt_ecc_err_i));
    bufp->chgBit(oldp+9,(vlSelfRef.pkt_trunc_err_i));
    bufp->chgBit(oldp+10,(vlSelfRef.pkt_valid_good_i));
    bufp->chgBit(oldp+11,(vlSelfRef.slot_start_o));
    bufp->chgBit(oldp+12,(vlSelfRef.slot_done_o));
    bufp->chgSData(oldp+13,(vlSelfRef.slot_seq_o),16);
    bufp->chgBit(oldp+14,(vlSelfRef.slot_valid_good_o));
    bufp->chgBit(oldp+15,(vlSelfRef.slot_overflow_err_o));
    bufp->chgWData(oldp+16,(vlSelfRef.s_axis_tdata),256);
    bufp->chgIData(oldp+24,(vlSelfRef.s_axis_tkeep),32);
    bufp->chgBit(oldp+25,(vlSelfRef.s_axis_tvalid));
    bufp->chgBit(oldp+26,(vlSelfRef.s_axis_tready));
    bufp->chgBit(oldp+27,(vlSelfRef.s_axis_tlast));
    bufp->chgQData(oldp+28,(vlSelfRef.s_axis_tuser),64);
    bufp->chgWData(oldp+30,(vlSelfRef.m_axis_tdata),256);
    bufp->chgIData(oldp+38,(vlSelfRef.m_axis_tkeep),32);
    bufp->chgBit(oldp+39,(vlSelfRef.m_axis_tvalid));
    bufp->chgBit(oldp+40,(vlSelfRef.m_axis_tready));
    bufp->chgBit(oldp+41,(vlSelfRef.m_axis_tlast));
    bufp->chgQData(oldp+42,(vlSelfRef.m_axis_tuser),64);
    bufp->chgBit(oldp+44,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__clk_i));
    bufp->chgBit(oldp+45,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__rst_ni));
    bufp->chgBit(oldp+46,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__cfg_drop_invalid_pkt_i));
    bufp->chgBit(oldp+47,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_start_i));
    bufp->chgBit(oldp+48,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_done_i));
    bufp->chgSData(oldp+49,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_bytes_i),16);
    bufp->chgSData(oldp+50,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_seq_i),16);
    bufp->chgBit(oldp+51,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_crc_err_i));
    bufp->chgBit(oldp+52,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_ecc_err_i));
    bufp->chgBit(oldp+53,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_trunc_err_i));
    bufp->chgBit(oldp+54,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_valid_good_i));
    bufp->chgBit(oldp+55,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_start_o));
    bufp->chgBit(oldp+56,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_done_o));
    bufp->chgSData(oldp+57,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_seq_o),16);
    bufp->chgBit(oldp+58,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_valid_good_o));
    bufp->chgBit(oldp+59,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_overflow_err_o));
    bufp->chgWData(oldp+60,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tdata),256);
    bufp->chgIData(oldp+68,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tkeep),32);
    bufp->chgBit(oldp+69,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tvalid));
    bufp->chgBit(oldp+70,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tready));
    bufp->chgBit(oldp+71,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tlast));
    bufp->chgQData(oldp+72,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tuser),64);
    bufp->chgWData(oldp+74,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata),256);
    bufp->chgIData(oldp+82,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tkeep),32);
    bufp->chgBit(oldp+83,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tvalid));
    bufp->chgBit(oldp+84,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tready));
    bufp->chgBit(oldp+85,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tlast));
    bufp->chgQData(oldp+86,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tuser),64);
    bufp->chgBit(oldp+88,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i));
    bufp->chgBit(oldp+89,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni));
    bufp->chgBit(oldp+90,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cfg_drop_invalid_pkt_i));
    bufp->chgBit(oldp+91,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_start_i));
    bufp->chgBit(oldp+92,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i));
    bufp->chgSData(oldp+93,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i),16);
    bufp->chgSData(oldp+94,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_seq_i),16);
    bufp->chgBit(oldp+95,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_crc_err_i));
    bufp->chgBit(oldp+96,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_ecc_err_i));
    bufp->chgBit(oldp+97,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_trunc_err_i));
    bufp->chgBit(oldp+98,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_valid_good_i));
    bufp->chgBit(oldp+99,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_start_o));
    bufp->chgBit(oldp+100,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_done_o));
    bufp->chgSData(oldp+101,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_seq_o),16);
    bufp->chgBit(oldp+102,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_valid_good_o));
    bufp->chgBit(oldp+103,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_overflow_err_o));
    bufp->chgCData(oldp+104,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r),3);
    bufp->chgCData(oldp+105,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n),3);
    bufp->chgCData(oldp+106,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r),8);
    bufp->chgCData(oldp+107,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n),8);
    bufp->chgCData(oldp+108,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r),8);
    bufp->chgCData(oldp+109,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n),8);
    bufp->chgCData(oldp+110,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r),8);
    bufp->chgCData(oldp+111,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n),8);
    bufp->chgSData(oldp+112,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r),16);
    bufp->chgSData(oldp+113,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_n),16);
    bufp->chgSData(oldp+114,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r),16);
    bufp->chgSData(oldp+115,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n),16);
    bufp->chgBit(oldp+116,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r));
    bufp->chgBit(oldp+117,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n));
    bufp->chgBit(oldp+118,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r));
    bufp->chgBit(oldp+119,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n));
    bufp->chgBit(oldp+120,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r));
    bufp->chgBit(oldp+121,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n));
    bufp->chgBit(oldp+122,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r));
    bufp->chgBit(oldp+123,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n));
    bufp->chgBit(oldp+124,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r));
    bufp->chgBit(oldp+125,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n));
    bufp->chgBit(oldp+126,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c));
    bufp->chgBit(oldp+127,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c));
    bufp->chgCData(oldp+128,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__keep_bytes_c),6);
    bufp->chgWData(oldp+129,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c),256);
    bufp->chgBit(oldp+137,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c));
    bufp->chgBit(oldp+138,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c));
    bufp->chgCData(oldp+139,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__sample_pad_beats_c),8);
    bufp->chgWData(oldp+140,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c),512);
    bufp->chgSData(oldp+156,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__actual_sample_cnt_c),11);
    bufp->chgBit(oldp+157,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c));
    bufp->chgCData(oldp+158,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c),8);
    bufp->chgWData(oldp+159,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c),256);
    bufp->chgWData(oldp+167,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tdata),256);
    bufp->chgIData(oldp+175,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep),32);
    bufp->chgBit(oldp+176,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tvalid));
    bufp->chgBit(oldp+177,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tready));
    bufp->chgBit(oldp+178,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tlast));
    bufp->chgQData(oldp+179,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tuser),64);
    bufp->chgWData(oldp+181,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata),256);
    bufp->chgIData(oldp+189,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep),32);
    bufp->chgBit(oldp+190,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid));
    bufp->chgBit(oldp+191,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tready));
    bufp->chgBit(oldp+192,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast));
    bufp->chgQData(oldp+193,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tuser),64);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
