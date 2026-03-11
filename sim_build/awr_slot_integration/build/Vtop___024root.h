// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_axis_stream_if;
class Vtop_slot_packer_pkg;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:
    // CELLS
    Vtop_slot_packer_pkg* __PVT__slot_packer_pkg;
    Vtop_axis_stream_if* __PVT__fixed_slot_packer_cocotb_top__DOT__s_axis_if;
    Vtop_axis_stream_if* __PVT__fixed_slot_packer_cocotb_top__DOT__m_axis_if;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk_i,0,0);
        VL_IN8(rst_ni,0,0);
        VL_IN8(cfg_drop_invalid_pkt_i,0,0);
        VL_IN8(pkt_start_i,0,0);
        VL_IN8(pkt_done_i,0,0);
        VL_IN8(pkt_crc_err_i,0,0);
        VL_IN8(pkt_ecc_err_i,0,0);
        VL_IN8(pkt_trunc_err_i,0,0);
        VL_IN8(pkt_valid_good_i,0,0);
        VL_OUT8(slot_start_o,0,0);
        VL_OUT8(slot_done_o,0,0);
        VL_OUT8(slot_valid_good_o,0,0);
        VL_OUT8(slot_overflow_err_o,0,0);
        VL_IN8(s_axis_tvalid,0,0);
        VL_OUT8(s_axis_tready,0,0);
        VL_IN8(s_axis_tlast,0,0);
        VL_OUT8(m_axis_tvalid,0,0);
        VL_IN8(m_axis_tready,0,0);
        VL_OUT8(m_axis_tlast,0,0);
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__clk_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__rst_ni;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__cfg_drop_invalid_pkt_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__pkt_start_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__pkt_done_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__pkt_crc_err_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__pkt_ecc_err_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__pkt_trunc_err_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__pkt_valid_good_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__slot_start_o;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__slot_done_o;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__slot_valid_good_o;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__slot_overflow_err_o;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__s_axis_tvalid;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__s_axis_tready;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__s_axis_tlast;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__m_axis_tvalid;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__m_axis_tready;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__m_axis_tlast;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cfg_drop_invalid_pkt_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_start_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_done_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_crc_err_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_ecc_err_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_trunc_err_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_valid_good_i;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_start_o;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_done_o;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_valid_good_o;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_overflow_err_o;
        CData/*2:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_r;
        CData/*2:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__state_n;
        CData/*7:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_r;
        CData/*7:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__out_beat_cnt_n;
        CData/*7:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_r;
        CData/*7:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__total_out_beat_cnt_n;
        CData/*7:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_r;
        CData/*7:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_beat_cnt_n;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_r;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_crc_err_n;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_r;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_ecc_err_n;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_r;
    };
    struct {
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_trunc_err_n;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_r;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_valid_good_n;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_r;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_overflow_n;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__s_fire_c;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__m_fire_c;
        CData/*5:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__keep_bytes_c;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__is_slot_last_beat_c;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__should_drop_c;
        CData/*7:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__sample_pad_beats_c;
        CData/*0:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_en_c;
        CData/*7:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_idx_c;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fixed_slot_packer_cocotb_top__DOT__dut__DOT__clk_i__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__fixed_slot_packer_cocotb_top__DOT__dut__DOT__rst_ni__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        VL_IN16(pkt_bytes_i,15,0);
        VL_IN16(pkt_seq_i,15,0);
        VL_OUT16(slot_bytes_o,12,0);
        VL_OUT16(slot_seq_o,15,0);
        SData/*15:0*/ fixed_slot_packer_cocotb_top__DOT__pkt_bytes_i;
        SData/*15:0*/ fixed_slot_packer_cocotb_top__DOT__pkt_seq_i;
        SData/*12:0*/ fixed_slot_packer_cocotb_top__DOT__slot_bytes_o;
        SData/*15:0*/ fixed_slot_packer_cocotb_top__DOT__slot_seq_o;
        SData/*15:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_bytes_i;
        SData/*15:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__pkt_seq_i;
        SData/*12:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_bytes_o;
        SData/*15:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__slot_seq_o;
        SData/*15:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_r;
        SData/*15:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_seq_n;
        SData/*15:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_r;
        SData/*15:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_pkt_bytes_n;
        SData/*10:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__actual_sample_cnt_c;
        VL_INW(s_axis_tdata,255,0,8);
        VL_IN(s_axis_tkeep,31,0);
        VL_OUTW(m_axis_tdata,255,0,8);
        VL_OUT(m_axis_tkeep,31,0);
        VlWide<8>/*255:0*/ fixed_slot_packer_cocotb_top__DOT__s_axis_tdata;
        IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__s_axis_tkeep;
        VlWide<8>/*255:0*/ fixed_slot_packer_cocotb_top__DOT__m_axis_tdata;
        IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__m_axis_tkeep;
        VlWide<8>/*255:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__masked_data_c;
        VlWide<16>/*511:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__hdr_word_c;
        VlWide<8>/*255:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_wr_data_c;
        IData/*31:0*/ __VactIterCount;
        VL_IN64(s_axis_tuser,63,0);
        VL_OUT64(m_axis_tuser,63,0);
        QData/*63:0*/ fixed_slot_packer_cocotb_top__DOT__s_axis_tuser;
        QData/*63:0*/ fixed_slot_packer_cocotb_top__DOT__m_axis_tuser;
        VlUnpacked<VlWide<8>/*255:0*/, 128> fixed_slot_packer_cocotb_top__DOT__dut__DOT__cap_buf_data_r;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*7:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_HDR_VERSION = 1U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__AXIS_DATA_W = 0x00000100U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__AXIS_USER_W = 0x00000040U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__PKT_SEQ_W = 0x00000010U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__PKT_BYTE_CNT_W = 0x00000010U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__SAMPLE_SLOT_NUM = 0x00000400U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__SAMPLE_UNIT_BYTES = 4U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__CQ_AREA_BYTES = 0x00000080U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__HEADER_BYTES = 0x00000040U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__ALIGN_BYTES = 0x00000040U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__SLOT_BYTES_W = 0x0000000dU;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_DATA_W = 0x00000100U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_USER_W = 0x00000040U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__PKT_SEQ_W = 0x00000010U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__PKT_BYTE_CNT_W = 0x00000010U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_SLOT_NUM = 0x00000400U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_UNIT_BYTES = 4U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__CQ_AREA_BYTES = 0x00000080U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HEADER_BYTES = 0x00000040U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__ALIGN_BYTES = 0x00000040U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_HDR_MAGIC = 0xaa551024U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_BYTES_W = 0x0000000dU;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_KEEP_W = 0x00000020U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__AXIS_BEAT_BYTES = 0x00000020U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__BEAT_BYTE_CNT_W = 6U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_UNIT_BITS = 0x00000020U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_AREA_BYTES = 0x00001000U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_CNT_W = 0x0000000bU;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HEADER_BITS = 0x00000200U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_TOTAL_UNALIGNED = 0x000010c0U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_TOTAL_ALIGNED = 0x000010c0U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__PAD_BYTES = 0U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HEADER_BEATS = 2U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SAMPLE_AREA_BEATS = 0x00000080U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__CQ_AREA_BEATS = 4U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__PAD_BEATS = 0U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__SLOT_TOTAL_BEATS = 0x00000086U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__CAP_BUF_BEATS = 0x00000080U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__BEAT_CNT_W = 8U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_MAGIC_BIT_LSB = 0U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_VERSION_BIT_LSB = 0x00000020U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_FLAGS_BIT_LSB = 0x00000028U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_SEQ_BIT_LSB = 0x00000040U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_BYTES_BIT_LSB = 0x00000050U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SAMPLE_CNT_BIT_LSB = 0x00000060U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SLOT_BYTES_BIT_LSB = 0x00000080U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SAMPLE_AREA_BIT_LSB = 0x000000a0U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_CQ_AREA_BIT_LSB = 0x000000c0U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_SEQ_FIELD_BITS = 0x00000010U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_PKT_BYTES_FIELD_BITS = 0x00000010U;
    static constexpr IData/*31:0*/ fixed_slot_packer_cocotb_top__DOT__dut__DOT__HDR_SAMPLE_CNT_FIELD_BITS = 0x00000010U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
