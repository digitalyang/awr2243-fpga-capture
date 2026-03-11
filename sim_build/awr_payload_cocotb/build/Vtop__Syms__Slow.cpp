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
    Verilated::stackCheck(830);
    // Setup sub module instances
    TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.ctor(this, "fixed_slot_packer_cocotb_top.m_axis_if");
    TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.ctor(this, "fixed_slot_packer_cocotb_top.s_axis_if");
    TOP__slot_packer_pkg.ctor(this, "slot_packer_pkg");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__fixed_slot_packer_cocotb_top__DOT__m_axis_if = &TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if;
    TOP.__PVT__fixed_slot_packer_cocotb_top__DOT__s_axis_if = &TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if;
    TOP.__PVT__slot_packer_pkg = &TOP__slot_packer_pkg;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.__Vconfigure(true);
    TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.__Vconfigure(false);
    TOP__slot_packer_pkg.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_fixed_slot_packer_cocotb_top = new VerilatedScope{this, "fixed_slot_packer_cocotb_top", "fixed_slot_packer_cocotb_top", "fixed_slot_packer_cocotb_top", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_fixed_slot_packer_cocotb_top__dut = new VerilatedScope{this, "fixed_slot_packer_cocotb_top.dut", "dut", "fixed_slot_packer", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_fixed_slot_packer_cocotb_top__dut__g_static_checks = new VerilatedScope{this, "fixed_slot_packer_cocotb_top.dut.g_static_checks", "g_static_checks", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if = new VerilatedScope{this, "fixed_slot_packer_cocotb_top.m_axis_if", "m_axis_if", "axis_stream_if", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if = new VerilatedScope{this, "fixed_slot_packer_cocotb_top.s_axis_if", "s_axis_if", "axis_stream_if", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_slot_packer_pkg = new VerilatedScope{this, "slot_packer_pkg", "slot_packer_pkg", "slot_packer_pkg", -9, VerilatedScope::SCOPE_PACKAGE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_fixed_slot_packer_cocotb_top);
    __Vhier.add(0, __Vscopep_slot_packer_pkg);
    __Vhier.add(__Vscopep_fixed_slot_packer_cocotb_top, __Vscopep_fixed_slot_packer_cocotb_top__dut);
    __Vhier.add(__Vscopep_fixed_slot_packer_cocotb_top, __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if);
    __Vhier.add(__Vscopep_fixed_slot_packer_cocotb_top, __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("cfg_drop_invalid_pkt_i", &(TOP.cfg_drop_invalid_pkt_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("clk_i", &(TOP.clk_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("m_axis_tdata", &(TOP.m_axis_tdata), false, VLVT_WDATA, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,255,0);
    __Vscopep_TOP->varInsert("m_axis_tkeep", &(TOP.m_axis_tkeep), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("m_axis_tlast", &(TOP.m_axis_tlast), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("m_axis_tready", &(TOP.m_axis_tready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("m_axis_tuser", &(TOP.m_axis_tuser), false, VLVT_UINT64, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("m_axis_tvalid", &(TOP.m_axis_tvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("pkt_bytes_i", &(TOP.pkt_bytes_i), false, VLVT_UINT16, VLVD_IN|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("pkt_crc_err_i", &(TOP.pkt_crc_err_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("pkt_done_i", &(TOP.pkt_done_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("pkt_ecc_err_i", &(TOP.pkt_ecc_err_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("pkt_seq_i", &(TOP.pkt_seq_i), false, VLVT_UINT16, VLVD_IN|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("pkt_start_i", &(TOP.pkt_start_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("pkt_trunc_err_i", &(TOP.pkt_trunc_err_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("pkt_valid_good_i", &(TOP.pkt_valid_good_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rst_ni", &(TOP.rst_ni), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("s_axis_tdata", &(TOP.s_axis_tdata), false, VLVT_WDATA, VLVD_IN|VLVF_PUB_RW, 0, 1 ,255,0);
    __Vscopep_TOP->varInsert("s_axis_tkeep", &(TOP.s_axis_tkeep), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("s_axis_tlast", &(TOP.s_axis_tlast), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("s_axis_tready", &(TOP.s_axis_tready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("s_axis_tuser", &(TOP.s_axis_tuser), false, VLVT_UINT64, VLVD_IN|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("s_axis_tvalid", &(TOP.s_axis_tvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("slot_bytes_o", &(TOP.slot_bytes_o), false, VLVT_UINT16, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,12,0);
    __Vscopep_TOP->varInsert("slot_done_o", &(TOP.slot_done_o), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("slot_overflow_err_o", &(TOP.slot_overflow_err_o), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("slot_seq_o", &(TOP.slot_seq_o), false, VLVT_UINT16, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("slot_start_o", &(TOP.slot_start_o), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("slot_valid_good_o", &(TOP.slot_valid_good_o), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("ALIGN_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__ALIGN_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("AXIS_DATA_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__AXIS_DATA_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("AXIS_USER_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__AXIS_USER_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("CQ_AREA_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__CQ_AREA_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("HEADER_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__HEADER_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("PKT_BYTE_CNT_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__PKT_BYTE_CNT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("PKT_SEQ_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__PKT_SEQ_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("SAMPLE_SLOT_NUM", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__SAMPLE_SLOT_NUM))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("SAMPLE_UNIT_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__SAMPLE_UNIT_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("SLOT_BYTES_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__SLOT_BYTES_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("cfg_drop_invalid_pkt_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__cfg_drop_invalid_pkt_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("clk_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__clk_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("m_axis_tdata", &(TOP.fixed_slot_packer_cocotb_top__DOT__m_axis_tdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,255,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("m_axis_tkeep", &(TOP.fixed_slot_packer_cocotb_top__DOT__m_axis_tkeep), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("m_axis_tlast", &(TOP.fixed_slot_packer_cocotb_top__DOT__m_axis_tlast), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("m_axis_tready", &(TOP.fixed_slot_packer_cocotb_top__DOT__m_axis_tready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("m_axis_tuser", &(TOP.fixed_slot_packer_cocotb_top__DOT__m_axis_tuser), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("m_axis_tvalid", &(TOP.fixed_slot_packer_cocotb_top__DOT__m_axis_tvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("pkt_bytes_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__pkt_bytes_i), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("pkt_crc_err_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__pkt_crc_err_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("pkt_done_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__pkt_done_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("pkt_ecc_err_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__pkt_ecc_err_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("pkt_seq_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__pkt_seq_i), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("pkt_start_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__pkt_start_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("pkt_trunc_err_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__pkt_trunc_err_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("pkt_valid_good_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__pkt_valid_good_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("rst_ni", &(TOP.fixed_slot_packer_cocotb_top__DOT__rst_ni), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("s_axis_tdata", &(TOP.fixed_slot_packer_cocotb_top__DOT__s_axis_tdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,255,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("s_axis_tkeep", &(TOP.fixed_slot_packer_cocotb_top__DOT__s_axis_tkeep), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("s_axis_tlast", &(TOP.fixed_slot_packer_cocotb_top__DOT__s_axis_tlast), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("s_axis_tready", &(TOP.fixed_slot_packer_cocotb_top__DOT__s_axis_tready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("s_axis_tuser", &(TOP.fixed_slot_packer_cocotb_top__DOT__s_axis_tuser), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("s_axis_tvalid", &(TOP.fixed_slot_packer_cocotb_top__DOT__s_axis_tvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("slot_bytes_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__slot_bytes_o), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,12,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("slot_done_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__slot_done_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("slot_overflow_err_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__slot_overflow_err_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("slot_seq_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__slot_seq_o), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("slot_start_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__slot_start_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top->varInsert("slot_valid_good_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__slot_valid_good_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("ALIGN_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__ALIGN_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("AXIS_BEAT_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_BEAT_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("AXIS_DATA_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_DATA_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("AXIS_KEEP_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_KEEP_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("AXIS_USER_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_USER_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("BEAT_BYTE_CNT_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__BEAT_BYTE_CNT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("BEAT_CNT_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__BEAT_CNT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("CAP_BUF_BEATS", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__CAP_BUF_BEATS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("CQ_AREA_BEATS", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__CQ_AREA_BEATS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("CQ_AREA_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__CQ_AREA_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_CQ_AREA_BIT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_CQ_AREA_BIT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_FLAGS_BIT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_FLAGS_BIT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_MAGIC_BIT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_MAGIC_BIT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_PKT_BYTES_BIT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_BYTES_BIT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_PKT_BYTES_FIELD_BITS", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_BYTES_FIELD_BITS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_PKT_SEQ_BIT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_SEQ_BIT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_PKT_SEQ_FIELD_BITS", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_SEQ_FIELD_BITS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_SAMPLE_AREA_BIT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SAMPLE_AREA_BIT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_SAMPLE_CNT_BIT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SAMPLE_CNT_BIT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_SAMPLE_CNT_FIELD_BITS", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SAMPLE_CNT_FIELD_BITS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_SLOT_BYTES_BIT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SLOT_BYTES_BIT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HDR_VERSION_BIT_LSB", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_VERSION_BIT_LSB))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HEADER_BEATS", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HEADER_BEATS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HEADER_BITS", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HEADER_BITS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("HEADER_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__HEADER_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("PAD_BEATS", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__PAD_BEATS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("PAD_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__PAD_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("PKT_BYTE_CNT_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__PKT_BYTE_CNT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("PKT_SEQ_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__PKT_SEQ_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SAMPLE_AREA_BEATS", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_AREA_BEATS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SAMPLE_AREA_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_AREA_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SAMPLE_CNT_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_CNT_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SAMPLE_SLOT_NUM", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_SLOT_NUM))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SAMPLE_UNIT_BITS", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_UNIT_BITS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SAMPLE_UNIT_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_UNIT_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SLOT_BYTES_W", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_BYTES_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SLOT_HDR_MAGIC", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_HDR_MAGIC))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SLOT_HDR_VERSION", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_HDR_VERSION))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SLOT_TOTAL_ALIGNED", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_TOTAL_ALIGNED))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SLOT_TOTAL_BEATS", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_TOTAL_BEATS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("SLOT_TOTAL_UNALIGNED", const_cast<void*>(static_cast<const void*>(&(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_TOTAL_UNALIGNED))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("actual_sample_cnt_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__actual_sample_cnt_c), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,10,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_beat_cnt_n", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_beat_cnt_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_buf_data_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,127 ,255,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_buf_wr_data_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,255,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_buf_wr_en_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_buf_wr_idx_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_overflow_n", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_overflow_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_bytes_n", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_bytes_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_crc_err_n", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_crc_err_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_ecc_err_n", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_ecc_err_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_seq_n", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_n), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_seq_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_trunc_err_n", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_trunc_err_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_valid_good_n", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cap_pkt_valid_good_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("cfg_drop_invalid_pkt_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__cfg_drop_invalid_pkt_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("clk_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("hdr_word_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,511,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("is_slot_last_beat_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("keep_bytes_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__keep_bytes_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,5,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("m_fire_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("masked_data_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,255,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("out_beat_cnt_n", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("out_beat_cnt_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("pkt_bytes_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("pkt_crc_err_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_crc_err_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("pkt_done_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("pkt_ecc_err_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_ecc_err_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("pkt_seq_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_seq_i), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("pkt_start_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_start_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("pkt_trunc_err_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_trunc_err_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("pkt_valid_good_i", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_valid_good_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("rst_ni", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("s_fire_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("sample_pad_beats_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__sample_pad_beats_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,7,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("should_drop_c", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("slot_bytes_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_bytes_o), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,12,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("slot_done_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_done_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("slot_overflow_err_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_overflow_err_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("slot_seq_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_seq_o), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,15,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("slot_start_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_start_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("slot_valid_good_o", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_valid_good_o), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("state_n", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("state_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("total_out_beat_cnt_n", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_fixed_slot_packer_cocotb_top__dut->varInsert("total_out_beat_cnt_r", &(TOP.fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if->varInsert("DATA_W", const_cast<void*>(static_cast<const void*>(&(TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.DATA_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if->varInsert("KEEP_W", const_cast<void*>(static_cast<const void*>(&(TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.KEEP_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if->varInsert("USER_W", const_cast<void*>(static_cast<const void*>(&(TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.USER_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if->varInsert("tdata", &(TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,255,0);
    __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if->varInsert("tkeep", &(TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tkeep), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if->varInsert("tlast", &(TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tlast), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if->varInsert("tready", &(TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if->varInsert("tuser", &(TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tuser), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if->varInsert("tvalid", &(TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.tvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if->varInsert("DATA_W", const_cast<void*>(static_cast<const void*>(&(TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.DATA_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if->varInsert("KEEP_W", const_cast<void*>(static_cast<const void*>(&(TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.KEEP_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if->varInsert("USER_W", const_cast<void*>(static_cast<const void*>(&(TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.USER_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if->varInsert("tdata", &(TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,255,0);
    __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if->varInsert("tkeep", &(TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tkeep), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if->varInsert("tlast", &(TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tlast), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if->varInsert("tready", &(TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if->varInsert("tuser", &(TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tuser), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if->varInsert("tvalid", &(TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.tvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_CQ_AREA_BYTE_OFS", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_CQ_AREA_BYTE_OFS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_CQ_AREA_SIZE", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_CQ_AREA_SIZE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_FLAGS_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_FLAGS_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_FLAGS_BYTE_OFS", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_FLAGS_BYTE_OFS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_FLAG_CRC_ERR_BIT", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_FLAG_CRC_ERR_BIT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_FLAG_ECC_ERR_BIT", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_FLAG_ECC_ERR_BIT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_FLAG_OVERFLOW_BIT", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_FLAG_OVERFLOW_BIT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_FLAG_TRUNC_ERR_BIT", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_FLAG_TRUNC_ERR_BIT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_FLAG_VALID_GOOD_BIT", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_FLAG_VALID_GOOD_BIT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_MAGIC_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_MAGIC_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_MAGIC_BYTE_OFS", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_MAGIC_BYTE_OFS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_MAGIC_VAL_DFLT", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_MAGIC_VAL_DFLT))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_PKT_BYTES_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_PKT_BYTES_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_PKT_BYTES_BYTE_OFS", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_PKT_BYTES_BYTE_OFS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_PKT_SEQ_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_PKT_SEQ_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_PKT_SEQ_BYTE_OFS", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_PKT_SEQ_BYTE_OFS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_RSVD0_BYTE_OFS", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_RSVD0_BYTE_OFS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_RSVD1_BYTE_OFS", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_RSVD1_BYTE_OFS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_SAMPLE_AREA_BYTE_OFS", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_SAMPLE_AREA_BYTE_OFS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_SAMPLE_AREA_SIZE", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_SAMPLE_AREA_SIZE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_SAMPLE_CNT_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_SAMPLE_CNT_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_SAMPLE_CNT_BYTE_OFS", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_SAMPLE_CNT_BYTE_OFS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_SLOT_BYTES_BYTE_OFS", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_SLOT_BYTES_BYTE_OFS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_SLOT_BYTES_SIZE", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_SLOT_BYTES_SIZE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_VERSION_BYTES", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_VERSION_BYTES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_VERSION_BYTE_OFS", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_VERSION_BYTE_OFS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY, 0, 1 ,31,0);
    __Vscopep_slot_packer_pkg->varInsert("SLOT_HDR_VERSION_VAL_DFLT", const_cast<void*>(static_cast<const void*>(&(TOP__slot_packer_pkg.SLOT_HDR_VERSION_VAL_DFLT))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_fixed_slot_packer_cocotb_top);
    __Vhier.remove(0, __Vscopep_slot_packer_pkg);
    __Vhier.remove(__Vscopep_fixed_slot_packer_cocotb_top, __Vscopep_fixed_slot_packer_cocotb_top__dut);
    __Vhier.remove(__Vscopep_fixed_slot_packer_cocotb_top, __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if);
    __Vhier.remove(__Vscopep_fixed_slot_packer_cocotb_top, __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_fixed_slot_packer_cocotb_top, __Vscopep_fixed_slot_packer_cocotb_top = nullptr);
    VL_DO_CLEAR(delete __Vscopep_fixed_slot_packer_cocotb_top__dut, __Vscopep_fixed_slot_packer_cocotb_top__dut = nullptr);
    VL_DO_CLEAR(delete __Vscopep_fixed_slot_packer_cocotb_top__dut__g_static_checks, __Vscopep_fixed_slot_packer_cocotb_top__dut__g_static_checks = nullptr);
    VL_DO_CLEAR(delete __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if, __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if = nullptr);
    VL_DO_CLEAR(delete __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if, __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if = nullptr);
    VL_DO_CLEAR(delete __Vscopep_slot_packer_pkg, __Vscopep_slot_packer_pkg = nullptr);
    // Tear down sub module instances
    TOP__slot_packer_pkg.dtor();
    TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if.dtor();
    TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if.dtor();
}
