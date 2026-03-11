// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__slot_packer_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+0,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"cfg_drop_invalid_pkt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"pkt_start_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"pkt_done_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"pkt_bytes_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+6,0,"pkt_seq_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+7,0,"pkt_crc_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+8,0,"pkt_ecc_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"pkt_trunc_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"pkt_valid_good_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"slot_start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"slot_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+195,0,"slot_bytes_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+13,0,"slot_seq_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+14,0,"slot_valid_good_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"slot_overflow_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+16,0,"s_axis_tdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+24,0,"s_axis_tkeep",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+25,0,"s_axis_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"s_axis_tready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"s_axis_tlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+28,0,"s_axis_tuser",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declArray(c+30,0,"m_axis_tdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+38,0,"m_axis_tkeep",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+39,0,"m_axis_tvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"m_axis_tready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"m_axis_tlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+42,0,"m_axis_tuser",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->pushPrefix("fixed_slot_packer_cocotb_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+196,0,"AXIS_DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"AXIS_USER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+198,0,"PKT_SEQ_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+198,0,"PKT_BYTE_CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+199,0,"SAMPLE_SLOT_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+200,0,"SAMPLE_UNIT_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+201,0,"CQ_AREA_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"HEADER_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"ALIGN_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+202,0,"SLOT_BYTES_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"cfg_drop_invalid_pkt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"pkt_start_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"pkt_done_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"pkt_bytes_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+50,0,"pkt_seq_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+51,0,"pkt_crc_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"pkt_ecc_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"pkt_trunc_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"pkt_valid_good_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"slot_start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"slot_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+195,0,"slot_bytes_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+57,0,"slot_seq_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+58,0,"slot_valid_good_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+59,0,"slot_overflow_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+60,0,"s_axis_tdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+68,0,"s_axis_tkeep",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+69,0,"s_axis_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"s_axis_tready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"s_axis_tlast",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+72,0,"s_axis_tuser",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declArray(c+74,0,"m_axis_tdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+82,0,"m_axis_tkeep",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+83,0,"m_axis_tvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"m_axis_tready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"m_axis_tlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+86,0,"m_axis_tuser",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+196,0,"AXIS_DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"AXIS_USER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+198,0,"PKT_SEQ_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+198,0,"PKT_BYTE_CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+199,0,"SAMPLE_SLOT_NUM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+200,0,"SAMPLE_UNIT_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+201,0,"CQ_AREA_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"HEADER_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"ALIGN_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+203,0,"SLOT_HDR_MAGIC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"SLOT_HDR_VERSION",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+202,0,"SLOT_BYTES_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+88,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"cfg_drop_invalid_pkt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"pkt_start_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+92,0,"pkt_done_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+93,0,"pkt_bytes_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+94,0,"pkt_seq_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+95,0,"pkt_crc_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"pkt_ecc_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"pkt_trunc_err_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"pkt_valid_good_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"slot_start_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"slot_done_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+195,0,"slot_bytes_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 12,0);
    tracep->declBus(c+101,0,"slot_seq_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+102,0,"slot_valid_good_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"slot_overflow_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+205,0,"AXIS_KEEP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+205,0,"AXIS_BEAT_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+206,0,"BEAT_BYTE_CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+205,0,"SAMPLE_UNIT_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+207,0,"SAMPLE_AREA_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+208,0,"SAMPLE_CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+209,0,"HEADER_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+210,0,"SLOT_TOTAL_UNALIGNED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+210,0,"SLOT_TOTAL_ALIGNED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+211,0,"PAD_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+212,0,"HEADER_BEATS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+201,0,"SAMPLE_AREA_BEATS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+200,0,"CQ_AREA_BEATS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+211,0,"PAD_BEATS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+213,0,"SLOT_TOTAL_BEATS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+201,0,"CAP_BUF_BEATS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+214,0,"BEAT_CNT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+211,0,"HDR_MAGIC_BIT_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+205,0,"HDR_VERSION_BIT_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+215,0,"HDR_FLAGS_BIT_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"HDR_PKT_SEQ_BIT_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+216,0,"HDR_PKT_BYTES_BIT_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+217,0,"HDR_SAMPLE_CNT_BIT_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+201,0,"HDR_SLOT_BYTES_BIT_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+218,0,"HDR_SAMPLE_AREA_BIT_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+219,0,"HDR_CQ_AREA_BIT_LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+198,0,"HDR_PKT_SEQ_FIELD_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+198,0,"HDR_PKT_BYTES_FIELD_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+198,0,"HDR_SAMPLE_CNT_FIELD_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+104,0,"state_r",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+105,0,"state_n",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+106,0,"out_beat_cnt_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+107,0,"out_beat_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+108,0,"total_out_beat_cnt_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+109,0,"total_out_beat_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+110,0,"cap_beat_cnt_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+111,0,"cap_beat_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+112,0,"cap_pkt_seq_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+113,0,"cap_pkt_seq_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+114,0,"cap_pkt_bytes_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+115,0,"cap_pkt_bytes_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+116,0,"cap_pkt_crc_err_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"cap_pkt_crc_err_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+118,0,"cap_pkt_ecc_err_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"cap_pkt_ecc_err_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"cap_pkt_trunc_err_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"cap_pkt_trunc_err_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"cap_pkt_valid_good_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"cap_pkt_valid_good_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"cap_overflow_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"cap_overflow_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"s_fire_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+127,0,"m_fire_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+128,0,"keep_bytes_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declArray(c+129,0,"masked_data_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBit(c+137,0,"is_slot_last_beat_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+138,0,"should_drop_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+139,0,"sample_pad_beats_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+140,0,"hdr_word_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBus(c+156,0,"actual_sample_cnt_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 10,0);
    tracep->declBit(c+157,0,"cap_buf_wr_en_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+158,0,"cap_buf_wr_idx_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+159,0,"cap_buf_wr_data_c",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->pushPrefix("m_axis", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("s_axis", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("m_axis_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("s_axis_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vtop___024root__trace_init_sub__TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("slot_packer_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__slot_packer_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__slot_packer_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__slot_packer_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+211,0,"SLOT_HDR_MAGIC_BYTE_OFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+200,0,"SLOT_HDR_MAGIC_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+200,0,"SLOT_HDR_VERSION_BYTE_OFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+220,0,"SLOT_HDR_VERSION_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+221,0,"SLOT_HDR_FLAGS_BYTE_OFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+220,0,"SLOT_HDR_FLAGS_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+206,0,"SLOT_HDR_RSVD0_BYTE_OFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+214,0,"SLOT_HDR_PKT_SEQ_BYTE_OFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+212,0,"SLOT_HDR_PKT_SEQ_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+222,0,"SLOT_HDR_PKT_BYTES_BYTE_OFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+212,0,"SLOT_HDR_PKT_BYTES_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+223,0,"SLOT_HDR_SAMPLE_CNT_BYTE_OFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+212,0,"SLOT_HDR_SAMPLE_CNT_BYTES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+224,0,"SLOT_HDR_RSVD1_BYTE_OFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+198,0,"SLOT_HDR_SLOT_BYTES_BYTE_OFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+200,0,"SLOT_HDR_SLOT_BYTES_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+225,0,"SLOT_HDR_SAMPLE_AREA_BYTE_OFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+200,0,"SLOT_HDR_SAMPLE_AREA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+226,0,"SLOT_HDR_CQ_AREA_BYTE_OFS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+212,0,"SLOT_HDR_CQ_AREA_SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+211,0,"SLOT_HDR_FLAG_CRC_ERR_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+220,0,"SLOT_HDR_FLAG_ECC_ERR_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+212,0,"SLOT_HDR_FLAG_TRUNC_ERR_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+227,0,"SLOT_HDR_FLAG_VALID_GOOD_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+200,0,"SLOT_HDR_FLAG_OVERFLOW_BIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+203,0,"SLOT_HDR_MAGIC_VAL_DFLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"SLOT_HDR_VERSION_VAL_DFLT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+196,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"USER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+205,0,"KEEP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declArray(c+167,0,"tdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+175,0,"tkeep",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+176,0,"tvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+177,0,"tready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+178,0,"tlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+179,0,"tuser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+196,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+197,0,"USER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+205,0,"KEEP_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declArray(c+181,0,"tdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 255,0);
    tracep->declBus(c+189,0,"tkeep",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+190,0,"tvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"tready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"tlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+193,0,"tuser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
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
    bufp->fullSData(oldp+195,(0x10c0U),13);
    bufp->fullIData(oldp+196,(0x00000100U),32);
    bufp->fullIData(oldp+197,(0x00000040U),32);
    bufp->fullIData(oldp+198,(0x00000010U),32);
    bufp->fullIData(oldp+199,(0x00000400U),32);
    bufp->fullIData(oldp+200,(4U),32);
    bufp->fullIData(oldp+201,(0x00000080U),32);
    bufp->fullIData(oldp+202,(0x0000000dU),32);
    bufp->fullIData(oldp+203,(0xaa551024U),32);
    bufp->fullCData(oldp+204,(1U),8);
    bufp->fullIData(oldp+205,(0x00000020U),32);
    bufp->fullIData(oldp+206,(6U),32);
    bufp->fullIData(oldp+207,(0x00001000U),32);
    bufp->fullIData(oldp+208,(0x0000000bU),32);
    bufp->fullIData(oldp+209,(0x00000200U),32);
    bufp->fullIData(oldp+210,(0x000010c0U),32);
    bufp->fullIData(oldp+211,(0U),32);
    bufp->fullIData(oldp+212,(2U),32);
    bufp->fullIData(oldp+213,(0x00000086U),32);
    bufp->fullIData(oldp+214,(8U),32);
    bufp->fullIData(oldp+215,(0x00000028U),32);
    bufp->fullIData(oldp+216,(0x00000050U),32);
    bufp->fullIData(oldp+217,(0x00000060U),32);
    bufp->fullIData(oldp+218,(0x000000a0U),32);
    bufp->fullIData(oldp+219,(0x000000c0U),32);
    bufp->fullIData(oldp+220,(1U),32);
    bufp->fullIData(oldp+221,(5U),32);
    bufp->fullIData(oldp+222,(0x0000000aU),32);
    bufp->fullIData(oldp+223,(0x0000000cU),32);
    bufp->fullIData(oldp+224,(0x0000000eU),32);
    bufp->fullIData(oldp+225,(0x00000014U),32);
    bufp->fullIData(oldp+226,(0x00000018U),32);
    bufp->fullIData(oldp+227,(3U),32);
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
    bufp->fullBit(oldp+2,(vlSelfRef.cfg_drop_invalid_pkt_i));
    bufp->fullBit(oldp+3,(vlSelfRef.pkt_start_i));
    bufp->fullBit(oldp+4,(vlSelfRef.pkt_done_i));
    bufp->fullSData(oldp+5,(vlSelfRef.pkt_bytes_i),16);
    bufp->fullSData(oldp+6,(vlSelfRef.pkt_seq_i),16);
    bufp->fullBit(oldp+7,(vlSelfRef.pkt_crc_err_i));
    bufp->fullBit(oldp+8,(vlSelfRef.pkt_ecc_err_i));
    bufp->fullBit(oldp+9,(vlSelfRef.pkt_trunc_err_i));
    bufp->fullBit(oldp+10,(vlSelfRef.pkt_valid_good_i));
    bufp->fullBit(oldp+11,(vlSelfRef.slot_start_o));
    bufp->fullBit(oldp+12,(vlSelfRef.slot_done_o));
    bufp->fullSData(oldp+13,(vlSelfRef.slot_seq_o),16);
    bufp->fullBit(oldp+14,(vlSelfRef.slot_valid_good_o));
    bufp->fullBit(oldp+15,(vlSelfRef.slot_overflow_err_o));
    bufp->fullWData(oldp+16,(vlSelfRef.s_axis_tdata),256);
    bufp->fullIData(oldp+24,(vlSelfRef.s_axis_tkeep),32);
    bufp->fullBit(oldp+25,(vlSelfRef.s_axis_tvalid));
    bufp->fullBit(oldp+26,(vlSelfRef.s_axis_tready));
    bufp->fullBit(oldp+27,(vlSelfRef.s_axis_tlast));
    bufp->fullQData(oldp+28,(vlSelfRef.s_axis_tuser),64);
    bufp->fullWData(oldp+30,(vlSelfRef.m_axis_tdata),256);
    bufp->fullIData(oldp+38,(vlSelfRef.m_axis_tkeep),32);
    bufp->fullBit(oldp+39,(vlSelfRef.m_axis_tvalid));
    bufp->fullBit(oldp+40,(vlSelfRef.m_axis_tready));
    bufp->fullBit(oldp+41,(vlSelfRef.m_axis_tlast));
    bufp->fullQData(oldp+42,(vlSelfRef.m_axis_tuser),64);
    bufp->fullBit(oldp+44,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__clk_i));
    bufp->fullBit(oldp+45,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__rst_ni));
    bufp->fullBit(oldp+46,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__cfg_drop_invalid_pkt_i));
    bufp->fullBit(oldp+47,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_start_i));
    bufp->fullBit(oldp+48,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_done_i));
    bufp->fullSData(oldp+49,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_bytes_i),16);
    bufp->fullSData(oldp+50,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_seq_i),16);
    bufp->fullBit(oldp+51,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_crc_err_i));
    bufp->fullBit(oldp+52,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_ecc_err_i));
    bufp->fullBit(oldp+53,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_trunc_err_i));
    bufp->fullBit(oldp+54,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__pkt_valid_good_i));
    bufp->fullBit(oldp+55,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_start_o));
    bufp->fullBit(oldp+56,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_done_o));
    bufp->fullSData(oldp+57,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_seq_o),16);
    bufp->fullBit(oldp+58,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_valid_good_o));
    bufp->fullBit(oldp+59,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__slot_overflow_err_o));
    bufp->fullWData(oldp+60,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tdata),256);
    bufp->fullIData(oldp+68,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tkeep),32);
    bufp->fullBit(oldp+69,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tvalid));
    bufp->fullBit(oldp+70,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tready));
    bufp->fullBit(oldp+71,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tlast));
    bufp->fullQData(oldp+72,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__s_axis_tuser),64);
    bufp->fullWData(oldp+74,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata),256);
    bufp->fullIData(oldp+82,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tkeep),32);
    bufp->fullBit(oldp+83,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tvalid));
    bufp->fullBit(oldp+84,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tready));
    bufp->fullBit(oldp+85,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tlast));
    bufp->fullQData(oldp+86,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__m_axis_tuser),64);
    bufp->fullBit(oldp+88,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i));
    bufp->fullBit(oldp+89,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni));
    bufp->fullBit(oldp+90,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cfg_drop_invalid_pkt_i));
    bufp->fullBit(oldp+91,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_start_i));
    bufp->fullBit(oldp+92,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i));
    bufp->fullSData(oldp+93,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i),16);
    bufp->fullSData(oldp+94,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_seq_i),16);
    bufp->fullBit(oldp+95,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_crc_err_i));
    bufp->fullBit(oldp+96,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_ecc_err_i));
    bufp->fullBit(oldp+97,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_trunc_err_i));
    bufp->fullBit(oldp+98,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_valid_good_i));
    bufp->fullBit(oldp+99,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_start_o));
    bufp->fullBit(oldp+100,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_done_o));
    bufp->fullSData(oldp+101,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_seq_o),16);
    bufp->fullBit(oldp+102,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_valid_good_o));
    bufp->fullBit(oldp+103,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_overflow_err_o));
    bufp->fullCData(oldp+104,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r),3);
    bufp->fullCData(oldp+105,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n),3);
    bufp->fullCData(oldp+106,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r),8);
    bufp->fullCData(oldp+107,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n),8);
    bufp->fullCData(oldp+108,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r),8);
    bufp->fullCData(oldp+109,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n),8);
    bufp->fullCData(oldp+110,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r),8);
    bufp->fullCData(oldp+111,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n),8);
    bufp->fullSData(oldp+112,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r),16);
    bufp->fullSData(oldp+113,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_n),16);
    bufp->fullSData(oldp+114,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r),16);
    bufp->fullSData(oldp+115,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n),16);
    bufp->fullBit(oldp+116,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r));
    bufp->fullBit(oldp+117,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n));
    bufp->fullBit(oldp+118,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r));
    bufp->fullBit(oldp+119,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n));
    bufp->fullBit(oldp+120,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r));
    bufp->fullBit(oldp+121,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n));
    bufp->fullBit(oldp+122,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r));
    bufp->fullBit(oldp+123,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n));
    bufp->fullBit(oldp+124,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r));
    bufp->fullBit(oldp+125,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n));
    bufp->fullBit(oldp+126,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c));
    bufp->fullBit(oldp+127,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c));
    bufp->fullCData(oldp+128,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__keep_bytes_c),6);
    bufp->fullWData(oldp+129,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c),256);
    bufp->fullBit(oldp+137,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c));
    bufp->fullBit(oldp+138,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c));
    bufp->fullCData(oldp+139,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__sample_pad_beats_c),8);
    bufp->fullWData(oldp+140,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c),512);
    bufp->fullSData(oldp+156,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__actual_sample_cnt_c),11);
    bufp->fullBit(oldp+157,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c));
    bufp->fullCData(oldp+158,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c),8);
    bufp->fullWData(oldp+159,(vlSelfRef.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c),256);
    bufp->fullWData(oldp+167,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tdata),256);
    bufp->fullIData(oldp+175,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep),32);
    bufp->fullBit(oldp+176,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tvalid));
    bufp->fullBit(oldp+177,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tready));
    bufp->fullBit(oldp+178,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tlast));
    bufp->fullQData(oldp+179,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tuser),64);
    bufp->fullWData(oldp+181,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata),256);
    bufp->fullIData(oldp+189,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep),32);
    bufp->fullBit(oldp+190,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid));
    bufp->fullBit(oldp+191,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tready));
    bufp->fullBit(oldp+192,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast));
    bufp->fullQData(oldp+193,(vlSymsp->TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tuser),64);
}
