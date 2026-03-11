// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_axis_stream_if;
class Vtop_csi_packet_pkg;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:
    // CELLS
    Vtop_csi_packet_pkg* __PVT__csi_packet_pkg;
    Vtop_axis_stream_if* __PVT__csi_packet_extractor_cocotb_top__DOT__s_axis_if;
    Vtop_axis_stream_if* __PVT__csi_packet_extractor_cocotb_top__DOT__m_axis_if;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk_i,0,0);
        VL_IN8(rst_ni,0,0);
        VL_IN8(cfg_vc_en_i,0,0);
        VL_IN8(cfg_dt_en_i,0,0);
        VL_IN8(cfg_vc_i,1,0);
        VL_IN8(cfg_dt_i,5,0);
        VL_OUT8(pkt_start_o,0,0);
        VL_OUT8(pkt_done_o,0,0);
        VL_OUT8(pkt_valid_good_o,0,0);
        VL_OUT8(pkt_crc_err_o,0,0);
        VL_OUT8(pkt_ecc_err_o,0,0);
        VL_OUT8(pkt_trunc_err_o,0,0);
        VL_IN8(s_axis_tvalid,0,0);
        VL_OUT8(s_axis_tready,0,0);
        VL_IN8(s_axis_tlast,0,0);
        VL_OUT8(m_axis_tvalid,0,0);
        VL_IN8(m_axis_tready,0,0);
        VL_OUT8(m_axis_tlast,0,0);
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__clk_i;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__rst_ni;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__cfg_vc_en_i;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__cfg_dt_en_i;
        CData/*1:0*/ csi_packet_extractor_cocotb_top__DOT__cfg_vc_i;
        CData/*5:0*/ csi_packet_extractor_cocotb_top__DOT__cfg_dt_i;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__pkt_start_o;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__pkt_done_o;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__pkt_valid_good_o;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__pkt_crc_err_o;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__pkt_ecc_err_o;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__pkt_trunc_err_o;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__s_axis_tvalid;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__s_axis_tready;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__s_axis_tlast;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__m_axis_tvalid;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__m_axis_tready;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__m_axis_tlast;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_en_i;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_en_i;
        CData/*1:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_vc_i;
        CData/*5:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__cfg_dt_i;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_start_o;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_o;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_valid_good_o;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_o;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_o;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_o;
        CData/*1:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_r;
        CData/*1:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__state_n;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_r;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_n;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_r;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_n;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_r;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_n;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__s_fire_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__m_fire_c;
        CData/*5:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_bytes_c;
        CData/*5:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_beat_bytes_c;
        CData/*1:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_vc_c;
        CData/*5:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_dt_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_crc_err_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_ecc_err_c;
    };
    struct {
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_trunc_err_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_crc_err_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_ecc_err_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__stream_trunc_err_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_match_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_crc_err_view_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_ecc_err_view_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_trunc_err_view_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_done_view_c;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h503bf3ac__0;
        CData/*0:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT____VdfgExtracted_h5ac0cf88__0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__csi_packet_extractor_cocotb_top__DOT__dut__DOT__clk_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__csi_packet_extractor_cocotb_top__DOT__dut__DOT__rst_ni__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        VL_OUT16(pkt_seq_o,15,0);
        VL_OUT16(pkt_bytes_o,15,0);
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__pkt_seq_o;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__pkt_bytes_o;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_o;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_o;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_r;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_n;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_r;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__exp_pkt_bytes_n;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_r;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_n;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_r;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_ctr_n;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_payload_len_c;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_seq_view_c;
        SData/*15:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__pkt_bytes_view_c;
        VL_INW(s_axis_tdata,255,0,8);
        VL_IN(s_axis_tkeep,31,0);
        VL_OUTW(m_axis_tdata,255,0,8);
        VL_OUT(m_axis_tkeep,31,0);
        VlWide<8>/*255:0*/ csi_packet_extractor_cocotb_top__DOT__s_axis_tdata;
        IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__s_axis_tkeep;
        VlWide<8>/*255:0*/ csi_packet_extractor_cocotb_top__DOT__m_axis_tdata;
        IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__m_axis_tkeep;
        IData/*31:0*/ __VactIterCount;
        VL_IN64(s_axis_tuser,63,0);
        VL_OUT64(m_axis_tuser,63,0);
        QData/*63:0*/ csi_packet_extractor_cocotb_top__DOT__s_axis_tuser;
        QData/*63:0*/ csi_packet_extractor_cocotb_top__DOT__m_axis_tuser;
        VlWide<12>/*352:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_r;
        VlWide<12>/*352:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__first_beat_n;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__AXIS_DATA_W = 0x00000100U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__AXIS_USER_W = 0x00000040U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__VC_W = 2U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__DT_W = 6U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__PAYLOAD_LEN_W = 0x00000010U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__MAX_PACKET_BYTES = 0x0000ffffU;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__PKT_BYTE_CNT_W = 0x00000010U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__PKT_SEQ_W = 0x00000010U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_DATA_W = 0x00000100U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_USER_W = 0x00000040U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__VC_W = 2U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__DT_W = 6U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__PAYLOAD_LEN_W = 0x00000010U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__MAX_PACKET_BYTES = 0x0000ffffU;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__PKT_BYTE_CNT_W = 0x00000010U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__PKT_SEQ_W = 0x00000010U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__FIFO_DEPTH = 0x00000010U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_PKT_START_BIT = 0U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_CRC_ERR_BIT = 1U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_ECC_ERR_BIT = 2U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_TRUNC_ERR_BIT = 3U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_VC_LSB = 8U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_DT_LSB = 0x00000010U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__TUSER_PAYLOAD_LEN_LSB = 0x00000018U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_KEEP_W = 0x00000020U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__AXIS_BEAT_BYTES = 0x00000020U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__BEAT_BYTE_CNT_W = 6U;
    static constexpr IData/*31:0*/ csi_packet_extractor_cocotb_top__DOT__dut__DOT__FIFO_AW = 4U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
