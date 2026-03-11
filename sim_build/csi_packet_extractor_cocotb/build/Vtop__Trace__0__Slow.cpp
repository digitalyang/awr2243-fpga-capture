// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__csi_packet_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+0,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"cfg_vc_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"cfg_dt_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"cfg_vc_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+5,0,"cfg_dt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+6,0,"pkt_start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+7,0,"pkt_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"pkt_valid_good_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"pkt_seq_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+10,0,"pkt_bytes_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+11,0,"pkt_crc_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"pkt_ecc_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"pkt_trunc_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+14,0,"s_axis_tdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+22,0,"s_axis_tkeep",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+23,0,"s_axis_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"s_axis_tready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"s_axis_tlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+26,0,"s_axis_tuser",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declArray(c+28,0,"m_axis_tdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+36,0,"m_axis_tkeep",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+37,0,"m_axis_tvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"m_axis_tready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"m_axis_tlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+40,0,"m_axis_tuser",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->pushPrefix("csi_packet_extractor_cocotb_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+186,0,"AXIS_DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+187,0,"AXIS_USER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+188,0,"VC_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+189,0,"DT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+190,0,"PAYLOAD_LEN_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+191,0,"MAX_PACKET_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+190,0,"PKT_BYTE_CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+190,0,"PKT_SEQ_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+42,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"cfg_vc_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"cfg_dt_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"cfg_vc_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+47,0,"cfg_dt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+48,0,"pkt_start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"pkt_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"pkt_valid_good_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"pkt_seq_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+52,0,"pkt_bytes_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+53,0,"pkt_crc_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"pkt_ecc_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"pkt_trunc_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+56,0,"s_axis_tdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+64,0,"s_axis_tkeep",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+65,0,"s_axis_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"s_axis_tready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"s_axis_tlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+68,0,"s_axis_tuser",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declArray(c+70,0,"m_axis_tdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+78,0,"m_axis_tkeep",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+79,0,"m_axis_tvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"m_axis_tready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+81,0,"m_axis_tlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+82,0,"m_axis_tuser",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+186,0,"AXIS_DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+187,0,"AXIS_USER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+188,0,"VC_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+189,0,"DT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+190,0,"PAYLOAD_LEN_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+191,0,"MAX_PACKET_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+190,0,"PKT_BYTE_CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+190,0,"PKT_SEQ_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+190,0,"FIFO_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+192,0,"TUSER_PKT_START_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+193,0,"TUSER_CRC_ERR_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+188,0,"TUSER_ECC_ERR_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+194,0,"TUSER_TRUNC_ERR_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+195,0,"TUSER_VC_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+190,0,"TUSER_DT_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+196,0,"TUSER_PAYLOAD_LEN_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+84,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"cfg_vc_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"cfg_dt_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+88,0,"cfg_vc_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+89,0,"cfg_dt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+90,0,"pkt_start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"pkt_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"pkt_valid_good_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"pkt_seq_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+94,0,"pkt_bytes_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+95,0,"pkt_crc_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"pkt_ecc_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"pkt_trunc_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+197,0,"AXIS_KEEP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"AXIS_BEAT_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+189,0,"BEAT_BYTE_CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+198,0,"FIFO_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+98,0,"state_r",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+99,0,"state_n",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+100,0,"first_beat_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 352,0);
    tracep->declArray(c+112,0,"first_beat_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 352,0);
    tracep->declBus(c+124,0,"pkt_bytes_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+125,0,"pkt_bytes_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+126,0,"exp_pkt_bytes_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+127,0,"exp_pkt_bytes_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+128,0,"pkt_seq_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+129,0,"pkt_seq_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+130,0,"pkt_seq_ctr_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+131,0,"pkt_seq_ctr_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+132,0,"pkt_crc_err_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+133,0,"pkt_crc_err_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"pkt_ecc_err_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"pkt_ecc_err_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"pkt_trunc_err_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+137,0,"pkt_trunc_err_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"s_fire_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+139,0,"m_fire_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+140,0,"first_beat_bytes_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+141,0,"stream_beat_bytes_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+142,0,"first_vc_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+143,0,"first_dt_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+144,0,"first_payload_len_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+145,0,"first_crc_err_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+146,0,"first_ecc_err_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+147,0,"first_trunc_err_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+148,0,"stream_crc_err_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+149,0,"stream_ecc_err_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+150,0,"stream_trunc_err_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+151,0,"pkt_match_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+152,0,"pkt_seq_view_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+153,0,"pkt_bytes_view_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+154,0,"pkt_crc_err_view_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+155,0,"pkt_ecc_err_view_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"pkt_trunc_err_view_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"pkt_done_view_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("m_axis", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("s_axis", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("m_axis_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("s_axis_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("csi_packet_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__csi_packet_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__csi_packet_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__csi_packet_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+188,0,"CSI_VC_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+189,0,"CSI_DT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+190,0,"CSI_WORD_COUNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+192,0,"CSI_TUSER_PKT_START_BIT_DFLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+193,0,"CSI_TUSER_CRC_ERR_BIT_DFLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+188,0,"CSI_TUSER_ECC_ERR_BIT_DFLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+194,0,"CSI_TUSER_TRUNC_ERR_BIT_DFLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+195,0,"CSI_TUSER_VC_LSB_DFLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+190,0,"CSI_TUSER_DT_LSB_DFLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+196,0,"CSI_TUSER_PAYLOAD_LEN_LSB_DFLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+186,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+187,0,"USER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"KEEP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declArray(c+158,0,"tdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+166,0,"tkeep",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+167,0,"tvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+168,0,"tready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+169,0,"tlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+170,0,"tuser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+186,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+187,0,"USER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"KEEP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declArray(c+172,0,"tdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+180,0,"tkeep",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+181,0,"tvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+182,0,"tready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+183,0,"tlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+184,0,"tuser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+186,(0x00000100U),32);
    bufp->fullIData(oldp+187,(0x00000040U),32);
    bufp->fullIData(oldp+188,(2U),32);
    bufp->fullIData(oldp+189,(6U),32);
    bufp->fullIData(oldp+190,(0x00000010U),32);
    bufp->fullIData(oldp+191,(0x0000ffffU),32);
    bufp->fullIData(oldp+192,(0U),32);
    bufp->fullIData(oldp+193,(1U),32);
    bufp->fullIData(oldp+194,(3U),32);
    bufp->fullIData(oldp+195,(8U),32);
    bufp->fullIData(oldp+196,(0x00000018U),32);
    bufp->fullIData(oldp+197,(0x00000020U),32);
    bufp->fullIData(oldp+198,(4U),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.clk_i));
    bufp->fullBit(oldp+1,(vlSelfRef.rst_ni));
    bufp->fullBit(oldp+2,(vlSelfRef.cfg_vc_en_i));
    bufp->fullBit(oldp+3,(vlSelfRef.cfg_dt_en_i));
    bufp->fullCData(oldp+4,(vlSelfRef.cfg_vc_i),2);
    bufp->fullCData(oldp+5,(vlSelfRef.cfg_dt_i),6);
    bufp->fullBit(oldp+6,(vlSelfRef.pkt_start_o));
    bufp->fullBit(oldp+7,(vlSelfRef.pkt_done_o));
    bufp->fullBit(oldp+8,(vlSelfRef.pkt_valid_good_o));
    bufp->fullSData(oldp+9,(vlSelfRef.pkt_seq_o),16);
    bufp->fullSData(oldp+10,(vlSelfRef.pkt_bytes_o),16);
    bufp->fullBit(oldp+11,(vlSelfRef.pkt_crc_err_o));
    bufp->fullBit(oldp+12,(vlSelfRef.pkt_ecc_err_o));
    bufp->fullBit(oldp+13,(vlSelfRef.pkt_trunc_err_o));
    bufp->fullWData(oldp+14,(vlSelfRef.s_axis_tdata),256);
    bufp->fullIData(oldp+22,(vlSelfRef.s_axis_tkeep),32);
    bufp->fullBit(oldp+23,(vlSelfRef.s_axis_tvalid));
    bufp->fullBit(oldp+24,(vlSelfRef.s_axis_tready));
    bufp->fullBit(oldp+25,(vlSelfRef.s_axis_tlast));
    bufp->fullQData(oldp+26,(vlSelfRef.s_axis_tuser),64);
    bufp->fullWData(oldp+28,(vlSelfRef.m_axis_tdata),256);
    bufp->fullIData(oldp+36,(vlSelfRef.m_axis_tkeep),32);
    bufp->fullBit(oldp+37,(vlSelfRef.m_axis_tvalid));
    bufp->fullBit(oldp+38,(vlSelfRef.m_axis_tready));
    bufp->fullBit(oldp+39,(vlSelfRef.m_axis_tlast));
    bufp->fullQData(oldp+40,(vlSelfRef.m_axis_tuser),64);
    bufp->fullBit(oldp+42,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__clk_i));
    bufp->fullBit(oldp+43,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__rst_ni));
    bufp->fullBit(oldp+44,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_vc_en_i));
    bufp->fullBit(oldp+45,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_dt_en_i));
    bufp->fullCData(oldp+46,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_vc_i),2);
    bufp->fullCData(oldp+47,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__cfg_dt_i),6);
    bufp->fullBit(oldp+48,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_start_o));
    bufp->fullBit(oldp+49,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_done_o));
    bufp->fullBit(oldp+50,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_valid_good_o));
    bufp->fullSData(oldp+51,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_seq_o),16);
    bufp->fullSData(oldp+52,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_bytes_o),16);
    bufp->fullBit(oldp+53,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_crc_err_o));
    bufp->fullBit(oldp+54,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_ecc_err_o));
    bufp->fullBit(oldp+55,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__pkt_trunc_err_o));
    bufp->fullWData(oldp+56,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata),256);
    bufp->fullIData(oldp+64,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tkeep),32);
    bufp->fullBit(oldp+65,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tvalid));
    bufp->fullBit(oldp+66,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tready));
    bufp->fullBit(oldp+67,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tlast));
    bufp->fullQData(oldp+68,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__s_axis_tuser),64);
    bufp->fullWData(oldp+70,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata),256);
    bufp->fullIData(oldp+78,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tkeep),32);
    bufp->fullBit(oldp+79,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tvalid));
    bufp->fullBit(oldp+80,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tready));
    bufp->fullBit(oldp+81,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tlast));
    bufp->fullQData(oldp+82,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__m_axis_tuser),64);
    bufp->fullBit(oldp+84,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i));
    bufp->fullBit(oldp+85,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni));
    bufp->fullBit(oldp+86,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_en_i));
    bufp->fullBit(oldp+87,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_en_i));
    bufp->fullCData(oldp+88,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_i),2);
    bufp->fullCData(oldp+89,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_i),6);
    bufp->fullBit(oldp+90,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_start_o));
    bufp->fullBit(oldp+91,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_o));
    bufp->fullBit(oldp+92,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_valid_good_o));
    bufp->fullSData(oldp+93,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_o),16);
    bufp->fullSData(oldp+94,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_o),16);
    bufp->fullBit(oldp+95,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_o));
    bufp->fullBit(oldp+96,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_o));
    bufp->fullBit(oldp+97,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_o));
    bufp->fullCData(oldp+98,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r),2);
    bufp->fullCData(oldp+99,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n),2);
    bufp->fullWData(oldp+100,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r),353);
    bufp->fullWData(oldp+112,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n),353);
    bufp->fullSData(oldp+124,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r),16);
    bufp->fullSData(oldp+125,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n),16);
    bufp->fullSData(oldp+126,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r),16);
    bufp->fullSData(oldp+127,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n),16);
    bufp->fullSData(oldp+128,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r),16);
    bufp->fullSData(oldp+129,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_n),16);
    bufp->fullSData(oldp+130,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r),16);
    bufp->fullSData(oldp+131,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_n),16);
    bufp->fullBit(oldp+132,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r));
    bufp->fullBit(oldp+133,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n));
    bufp->fullBit(oldp+134,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r));
    bufp->fullBit(oldp+135,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n));
    bufp->fullBit(oldp+136,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r));
    bufp->fullBit(oldp+137,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n));
    bufp->fullBit(oldp+138,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c));
    bufp->fullBit(oldp+139,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c));
    bufp->fullCData(oldp+140,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c),6);
    bufp->fullCData(oldp+141,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c),6);
    bufp->fullCData(oldp+142,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_vc_c),2);
    bufp->fullCData(oldp+143,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_dt_c),6);
    bufp->fullSData(oldp+144,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c),16);
    bufp->fullBit(oldp+145,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_crc_err_c));
    bufp->fullBit(oldp+146,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_ecc_err_c));
    bufp->fullBit(oldp+147,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c));
    bufp->fullBit(oldp+148,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_crc_err_c));
    bufp->fullBit(oldp+149,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_ecc_err_c));
    bufp->fullBit(oldp+150,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c));
    bufp->fullBit(oldp+151,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c));
    bufp->fullSData(oldp+152,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c),16);
    bufp->fullSData(oldp+153,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c),16);
    bufp->fullBit(oldp+154,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c));
    bufp->fullBit(oldp+155,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c));
    bufp->fullBit(oldp+156,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c));
    bufp->fullBit(oldp+157,(vlSelfRef.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c));
    bufp->fullWData(oldp+158,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata),256);
    bufp->fullIData(oldp+166,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep),32);
    bufp->fullBit(oldp+167,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tvalid));
    bufp->fullBit(oldp+168,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready));
    bufp->fullBit(oldp+169,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast));
    bufp->fullQData(oldp+170,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser),64);
    bufp->fullWData(oldp+172,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata),256);
    bufp->fullIData(oldp+180,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep),32);
    bufp->fullBit(oldp+181,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid));
    bufp->fullBit(oldp+182,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tready));
    bufp->fullBit(oldp+183,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast));
    bufp->fullQData(oldp+184,(vlSymsp->TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser),64);
}
