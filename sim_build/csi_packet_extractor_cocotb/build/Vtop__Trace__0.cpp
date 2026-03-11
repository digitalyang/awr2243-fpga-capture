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
    bufp->chgBit(oldp+2,(vlSelfRef.cfg_vc_en_i));
    bufp->chgBit(oldp+3,(vlSelfRef.cfg_dt_en_i));
    bufp->chgCData(oldp+4,(vlSelfRef.cfg_vc_i),2);
    bufp->chgCData(oldp+5,(vlSelfRef.cfg_dt_i),6);
    bufp->chgBit(oldp+6,(vlSelfRef.pkt_start_o));
    bufp->chgBit(oldp+7,(vlSelfRef.pkt_done_o));
    bufp->chgBit(oldp+8,(vlSelfRef.pkt_valid_good_o));
    bufp->chgSData(oldp+9,(vlSelfRef.pkt_seq_o),16);
    bufp->chgSData(oldp+10,(vlSelfRef.pkt_bytes_o),16);
    bufp->chgBit(oldp+11,(vlSelfRef.pkt_crc_err_o));
    bufp->chgBit(oldp+12,(vlSelfRef.pkt_ecc_err_o));
    bufp->chgBit(oldp+13,(vlSelfRef.pkt_trunc_err_o));
    bufp->chgWData(oldp+14,(vlSelfRef.s_axis_tdata),256);
    bufp->chgIData(oldp+22,(vlSelfRef.s_axis_tkeep),32);
    bufp->chgBit(oldp+23,(vlSelfRef.s_axis_tvalid));
    bufp->chgBit(oldp+24,(vlSelfRef.s_axis_tready));
    bufp->chgBit(oldp+25,(vlSelfRef.s_axis_tlast));
    bufp->chgQData(oldp+26,(vlSelfRef.s_axis_tuser),64);
    bufp->chgWData(oldp+28,(vlSelfRef.m_axis_tdata),256);
    bufp->chgIData(oldp+36,(vlSelfRef.m_axis_tkeep),32);
    bufp->chgBit(oldp+37,(vlSelfRef.m_axis_tvalid));
    bufp->chgBit(oldp+38,(vlSelfRef.m_axis_tready));
    bufp->chgBit(oldp+39,(vlSelfRef.m_axis_tlast));
    bufp->chgQData(oldp+40,(vlSelfRef.m_axis_tuser),64);
    bufp->chgBit(oldp+42,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__clk_i));
    bufp->chgBit(oldp+43,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__rst_ni));
    bufp->chgBit(oldp+44,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_vc_en_i));
    bufp->chgBit(oldp+45,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_dt_en_i));
    bufp->chgCData(oldp+46,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_vc_i),2);
    bufp->chgCData(oldp+47,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_dt_i),6);
    bufp->chgBit(oldp+48,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_start_o));
    bufp->chgBit(oldp+49,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_done_o));
    bufp->chgBit(oldp+50,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_valid_good_o));
    bufp->chgSData(oldp+51,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_seq_o),16);
    bufp->chgSData(oldp+52,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_bytes_o),16);
    bufp->chgBit(oldp+53,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_crc_err_o));
    bufp->chgBit(oldp+54,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_ecc_err_o));
    bufp->chgBit(oldp+55,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_trunc_err_o));
    bufp->chgWData(oldp+56,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata),256);
    bufp->chgIData(oldp+64,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tkeep),32);
    bufp->chgBit(oldp+65,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tvalid));
    bufp->chgBit(oldp+66,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tready));
    bufp->chgBit(oldp+67,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tlast));
    bufp->chgQData(oldp+68,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tuser),64);
    bufp->chgWData(oldp+70,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata),256);
    bufp->chgIData(oldp+78,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tkeep),32);
    bufp->chgBit(oldp+79,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tvalid));
    bufp->chgBit(oldp+80,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tready));
    bufp->chgBit(oldp+81,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tlast));
    bufp->chgQData(oldp+82,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tuser),64);
    bufp->chgBit(oldp+84,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i));
    bufp->chgBit(oldp+85,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni));
    bufp->chgBit(oldp+86,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_en_i));
    bufp->chgBit(oldp+87,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_en_i));
    bufp->chgCData(oldp+88,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_i),2);
    bufp->chgCData(oldp+89,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_i),6);
    bufp->chgBit(oldp+90,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_start_o));
    bufp->chgBit(oldp+91,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_o));
    bufp->chgBit(oldp+92,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_valid_good_o));
    bufp->chgSData(oldp+93,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_o),16);
    bufp->chgSData(oldp+94,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_o),16);
    bufp->chgBit(oldp+95,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_o));
    bufp->chgBit(oldp+96,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_o));
    bufp->chgBit(oldp+97,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_o));
    bufp->chgCData(oldp+98,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r),2);
    bufp->chgCData(oldp+99,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n),2);
    bufp->chgWData(oldp+100,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r),353);
    bufp->chgWData(oldp+112,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n),353);
    bufp->chgSData(oldp+124,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r),16);
    bufp->chgSData(oldp+125,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n),16);
    bufp->chgSData(oldp+126,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r),16);
    bufp->chgSData(oldp+127,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n),16);
    bufp->chgSData(oldp+128,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r),16);
    bufp->chgSData(oldp+129,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_n),16);
    bufp->chgSData(oldp+130,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r),16);
    bufp->chgSData(oldp+131,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_n),16);
    bufp->chgBit(oldp+132,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r));
    bufp->chgBit(oldp+133,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n));
    bufp->chgBit(oldp+134,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r));
    bufp->chgBit(oldp+135,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n));
    bufp->chgBit(oldp+136,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r));
    bufp->chgBit(oldp+137,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n));
    bufp->chgBit(oldp+138,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c));
    bufp->chgBit(oldp+139,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c));
    bufp->chgCData(oldp+140,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c),6);
    bufp->chgCData(oldp+141,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c),6);
    bufp->chgCData(oldp+142,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_vc_c),2);
    bufp->chgCData(oldp+143,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_dt_c),6);
    bufp->chgSData(oldp+144,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c),16);
    bufp->chgBit(oldp+145,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_crc_err_c));
    bufp->chgBit(oldp+146,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_ecc_err_c));
    bufp->chgBit(oldp+147,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c));
    bufp->chgBit(oldp+148,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_crc_err_c));
    bufp->chgBit(oldp+149,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_ecc_err_c));
    bufp->chgBit(oldp+150,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c));
    bufp->chgBit(oldp+151,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c));
    bufp->chgSData(oldp+152,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c),16);
    bufp->chgSData(oldp+153,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c),16);
    bufp->chgBit(oldp+154,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c));
    bufp->chgBit(oldp+155,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c));
    bufp->chgBit(oldp+156,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c));
    bufp->chgBit(oldp+157,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c));
    bufp->chgWData(oldp+158,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata),256);
    bufp->chgIData(oldp+166,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep),32);
    bufp->chgBit(oldp+167,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tvalid));
    bufp->chgBit(oldp+168,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready));
    bufp->chgBit(oldp+169,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast));
    bufp->chgQData(oldp+170,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser),64);
    bufp->chgWData(oldp+172,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata),256);
    bufp->chgIData(oldp+180,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep),32);
    bufp->chgBit(oldp+181,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid));
    bufp->chgBit(oldp+182,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tready));
    bufp->chgBit(oldp+183,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast));
    bufp->chgQData(oldp+184,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser),64);
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
