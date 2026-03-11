// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(250);
    // Setup sub module instances
    TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.ctor(this, "csi_packet_extractor_cocotb_top.m_axis_if");
    TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.ctor(this, "csi_packet_extractor_cocotb_top.s_axis_if");
    TOP__csi_packet_pkg.ctor(this, "csi_packet_pkg");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__csi_packet_extractor_cocotb_top__DOT__m_axis_if = &TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if;
    TOP.__PVT__csi_packet_extractor_cocotb_top__DOT__s_axis_if = &TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if;
    TOP.__PVT__csi_packet_pkg = &TOP__csi_packet_pkg;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.__Vconfigure(true);
    TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.__Vconfigure(false);
    TOP__csi_packet_pkg.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_csi_packet_extractor_cocotb_top = new VerilatedScope{this, "csi_packet_extractor_cocotb_top", "csi_packet_extractor_cocotb_top", "csi_packet_extractor_cocotb_top", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_csi_packet_extractor_cocotb_top__dut = new VerilatedScope{this, "csi_packet_extractor_cocotb_top.dut", "dut", "csi_packet_extractor", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if = new VerilatedScope{this, "csi_packet_extractor_cocotb_top.m_axis_if", "m_axis_if", "axis_stream_if", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if = new VerilatedScope{this, "csi_packet_extractor_cocotb_top.s_axis_if", "s_axis_if", "axis_stream_if", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_csi_packet_pkg = new VerilatedScope{this, "csi_packet_pkg", "csi_packet_pkg", "csi_packet_pkg", -9, VerilatedScope::SCOPE_PACKAGE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_csi_packet_extractor_cocotb_top);
    __Vhier.add(0, __Vscopep_csi_packet_pkg);
    __Vhier.add(__Vscopep_csi_packet_extractor_cocotb_top, __Vscopep_csi_packet_extractor_cocotb_top__dut);
    __Vhier.add(__Vscopep_csi_packet_extractor_cocotb_top, __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if);
    __Vhier.add(__Vscopep_csi_packet_extractor_cocotb_top, __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("cfg_dt_en_i", &(TOP.cfg_dt_en_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("cfg_dt_i", &(TOP.cfg_dt_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,5,0);
    __Vscopep_TOP->varInsert("cfg_vc_en_i", &(TOP.cfg_vc_en_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("cfg_vc_i", &(TOP.cfg_vc_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("clk_i", &(TOP.clk_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("m_axis_tdata", &(TOP.m_axis_tdata), false, VLVT_WDATA, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,255,0);
    __Vscopep_TOP->varInsert("m_axis_tkeep", &(TOP.m_axis_tkeep), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("m_axis_tlast", &(TOP.m_axis_tlast), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("m_axis_tready", &(TOP.m_axis_tready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("m_axis_tuser", &(TOP.m_axis_tuser), false, VLVT_UINT64, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("m_axis_tvalid", &(TOP.m_axis_tvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("pkt_bytes_o", &(TOP.pkt_bytes_o), false, VLVT_UINT16, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("pkt_crc_err_o", &(TOP.pkt_crc_err_o), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("pkt_done_o", &(TOP.pkt_done_o), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("pkt_ecc_err_o", &(TOP.pkt_ecc_err_o), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("pkt_seq_o", &(TOP.pkt_seq_o), false, VLVT_UINT16, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("pkt_start_o", &(TOP.pkt_start_o), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("pkt_trunc_err_o", &(TOP.pkt_trunc_err_o), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("pkt_valid_good_o", &(TOP.pkt_valid_good_o), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rst_ni", &(TOP.rst_ni), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("s_axis_tdata", &(TOP.s_axis_tdata), false, VLVT_WDATA, VLVD_IN|VLVF_PUB_RW, 0, 1 ,255,0);
    __Vscopep_TOP->varInsert("s_axis_tkeep", &(TOP.s_axis_tkeep), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("s_axis_tlast", &(TOP.s_axis_tlast), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("s_axis_tready", &(TOP.s_axis_tready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("s_axis_tuser", &(TOP.s_axis_tuser), false, VLVT_UINT64, VLVD_IN|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("s_axis_tvalid", &(TOP.s_axis_tvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("AXIS_DATA_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__AXIS_DATA_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("AXIS_USER_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__AXIS_USER_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("DT_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__DT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("MAX_PACKET_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__MAX_PACKET_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("PAYLOAD_LEN_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__PAYLOAD_LEN_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("PKT_BYTE_CNT_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__PKT_BYTE_CNT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("PKT_SEQ_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__PKT_SEQ_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("VC_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__VC_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("cfg_dt_en_i", &(TOP.csi_packet_extractor_cocotb_top__DOT__cfg_dt_en_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("cfg_dt_i", &(TOP.csi_packet_extractor_cocotb_top__DOT__cfg_dt_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,5,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("cfg_vc_en_i", &(TOP.csi_packet_extractor_cocotb_top__DOT__cfg_vc_en_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("cfg_vc_i", &(TOP.csi_packet_extractor_cocotb_top__DOT__cfg_vc_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("clk_i", &(TOP.csi_packet_extractor_cocotb_top__DOT__clk_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("m_axis_tdata", &(TOP.csi_packet_extractor_cocotb_top__DOT__m_axis_tdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,255,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("m_axis_tkeep", &(TOP.csi_packet_extractor_cocotb_top__DOT__m_axis_tkeep), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("m_axis_tlast", &(TOP.csi_packet_extractor_cocotb_top__DOT__m_axis_tlast), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("m_axis_tready", &(TOP.csi_packet_extractor_cocotb_top__DOT__m_axis_tready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("m_axis_tuser", &(TOP.csi_packet_extractor_cocotb_top__DOT__m_axis_tuser), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("m_axis_tvalid", &(TOP.csi_packet_extractor_cocotb_top__DOT__m_axis_tvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("pkt_bytes_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__pkt_bytes_o), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("pkt_crc_err_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__pkt_crc_err_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("pkt_done_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__pkt_done_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("pkt_ecc_err_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__pkt_ecc_err_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("pkt_seq_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__pkt_seq_o), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("pkt_start_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__pkt_start_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("pkt_trunc_err_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__pkt_trunc_err_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("pkt_valid_good_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__pkt_valid_good_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("rst_ni", &(TOP.csi_packet_extractor_cocotb_top__DOT__rst_ni), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("s_axis_tdata", &(TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,255,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("s_axis_tkeep", &(TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tkeep), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("s_axis_tlast", &(TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tlast), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("s_axis_tready", &(TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("s_axis_tuser", &(TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tuser), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_csi_packet_extractor_cocotb_top->varInsert("s_axis_tvalid", &(TOP.csi_packet_extractor_cocotb_top__DOT__s_axis_tvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("AXIS_BEAT_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_BEAT_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("AXIS_DATA_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_DATA_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("AXIS_KEEP_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_KEEP_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("AXIS_USER_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_USER_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("BEAT_BYTE_CNT_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__BEAT_BYTE_CNT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("DT_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__DT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("FIFO_AW", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__FIFO_AW))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("FIFO_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__FIFO_DEPTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("MAX_PACKET_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__MAX_PACKET_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("PAYLOAD_LEN_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__PAYLOAD_LEN_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("PKT_BYTE_CNT_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__PKT_BYTE_CNT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("PKT_SEQ_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__PKT_SEQ_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("TUSER_CRC_ERR_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_CRC_ERR_BIT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("TUSER_DT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_DT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("TUSER_ECC_ERR_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_ECC_ERR_BIT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("TUSER_PAYLOAD_LEN_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_PAYLOAD_LEN_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("TUSER_PKT_START_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_PKT_START_BIT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("TUSER_TRUNC_ERR_BIT", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_TRUNC_ERR_BIT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("TUSER_VC_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_VC_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("VC_W", const_cast<void*>(static_cast<const void*>(&(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__VC_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("cfg_dt_en_i", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_en_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("cfg_dt_i", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,5,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("cfg_vc_en_i", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_en_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("cfg_vc_i", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("clk_i", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("exp_pkt_bytes_n", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("exp_pkt_bytes_r", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("first_beat_bytes_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,5,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("first_beat_n", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,352,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("first_beat_r", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,352,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("first_crc_err_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_crc_err_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("first_dt_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_dt_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,5,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("first_ecc_err_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_ecc_err_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("first_payload_len_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("first_trunc_err_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("first_vc_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_vc_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("m_fire_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_bytes_n", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_bytes_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_o), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_bytes_r", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_bytes_view_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_crc_err_n", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_crc_err_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_crc_err_r", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_crc_err_view_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_done_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_done_view_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_ecc_err_n", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_ecc_err_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_ecc_err_r", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_ecc_err_view_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_match_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_seq_ctr_n", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_n), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_seq_ctr_r", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_seq_n", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_n), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_seq_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_o), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_seq_r", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_seq_view_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_start_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_start_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_trunc_err_n", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_trunc_err_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_trunc_err_r", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_trunc_err_view_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("pkt_valid_good_o", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_valid_good_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("rst_ni", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("s_fire_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("state_n", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("state_r", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("stream_beat_bytes_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,5,0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("stream_crc_err_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_crc_err_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("stream_ecc_err_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_ecc_err_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__dut->varInsert("stream_trunc_err_c", &(TOP.csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if->varInsert("DATA_W", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.DATA_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if->varInsert("KEEP_W", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.KEEP_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if->varInsert("USER_W", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.USER_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if->varInsert("tdata", &(TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,255,0);
    __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if->varInsert("tkeep", &(TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tkeep), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if->varInsert("tlast", &(TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tlast), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if->varInsert("tready", &(TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if->varInsert("tuser", &(TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tuser), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if->varInsert("tvalid", &(TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.tvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if->varInsert("DATA_W", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.DATA_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if->varInsert("KEEP_W", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.KEEP_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if->varInsert("USER_W", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.USER_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if->varInsert("tdata", &(TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,255,0);
    __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if->varInsert("tkeep", &(TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tkeep), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if->varInsert("tlast", &(TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tlast), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if->varInsert("tready", &(TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if->varInsert("tuser", &(TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tuser), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if->varInsert("tvalid", &(TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.tvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csi_packet_pkg->varInsert("CSI_DT_W", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_pkg.CSI_DT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_pkg->varInsert("CSI_TUSER_CRC_ERR_BIT_DFLT", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_pkg.CSI_TUSER_CRC_ERR_BIT_DFLT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_pkg->varInsert("CSI_TUSER_DT_LSB_DFLT", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_pkg.CSI_TUSER_DT_LSB_DFLT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_pkg->varInsert("CSI_TUSER_ECC_ERR_BIT_DFLT", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_pkg.CSI_TUSER_ECC_ERR_BIT_DFLT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_pkg->varInsert("CSI_TUSER_PAYLOAD_LEN_LSB_DFLT", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_pkg.CSI_TUSER_PAYLOAD_LEN_LSB_DFLT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_pkg->varInsert("CSI_TUSER_PKT_START_BIT_DFLT", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_pkg.CSI_TUSER_PKT_START_BIT_DFLT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_pkg->varInsert("CSI_TUSER_TRUNC_ERR_BIT_DFLT", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_pkg.CSI_TUSER_TRUNC_ERR_BIT_DFLT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_pkg->varInsert("CSI_TUSER_VC_LSB_DFLT", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_pkg.CSI_TUSER_VC_LSB_DFLT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_pkg->varInsert("CSI_VC_W", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_pkg.CSI_VC_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_csi_packet_pkg->varInsert("CSI_WORD_COUNT_W", const_cast<void*>(static_cast<const void*>(&(TOP__csi_packet_pkg.CSI_WORD_COUNT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_csi_packet_extractor_cocotb_top);
    __Vhier.remove(0, __Vscopep_csi_packet_pkg);
    __Vhier.remove(__Vscopep_csi_packet_extractor_cocotb_top, __Vscopep_csi_packet_extractor_cocotb_top__dut);
    __Vhier.remove(__Vscopep_csi_packet_extractor_cocotb_top, __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if);
    __Vhier.remove(__Vscopep_csi_packet_extractor_cocotb_top, __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_csi_packet_extractor_cocotb_top, __Vscopep_csi_packet_extractor_cocotb_top = nullptr);
    VL_DO_CLEAR(delete __Vscopep_csi_packet_extractor_cocotb_top__dut, __Vscopep_csi_packet_extractor_cocotb_top__dut = nullptr);
    VL_DO_CLEAR(delete __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if, __Vscopep_csi_packet_extractor_cocotb_top__m_axis_if = nullptr);
    VL_DO_CLEAR(delete __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if, __Vscopep_csi_packet_extractor_cocotb_top__s_axis_if = nullptr);
    VL_DO_CLEAR(delete __Vscopep_csi_packet_pkg, __Vscopep_csi_packet_pkg = nullptr);
    // Tear down sub module instances
    TOP__csi_packet_pkg.dtor();
    TOP__csi_packet_extractor_cocotb_top__DOT__s_axis_if.dtor();
    TOP__csi_packet_extractor_cocotb_top__DOT__m_axis_if.dtor();
}
