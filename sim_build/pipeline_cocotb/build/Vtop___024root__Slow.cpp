// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr CData/*7:0*/ Vtop___024root::pipeline_cocotb_top__DOT__SLOT_HDR_VERSION;
constexpr CData/*0:0*/ Vtop___024root::pipeline_cocotb_top__DOT__SLOT_FIXED_EN;
constexpr CData/*7:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SLOT_HDR_VERSION;
constexpr CData/*0:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__SLOT_FIXED_EN;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__VC_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__DT_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__PAYLOAD_LEN_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__MAX_PACKET_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__PKT_BYTE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__PKT_SEQ_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__SAMPLE_SLOT_NUM;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__SAMPLE_UNIT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__CQ_AREA_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__HEADER_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__SLOT_ALIGN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__SLOT_HDR_MAGIC;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__AXI_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__AXI_ADDR_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__RD_AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__SLOT_STRIDE_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__SLOT_BUFFER_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__DESC_FIFO_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__MAX_BURST_LEN;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ADDR_ALIGN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__RING_SIZE_BYTES_MAX;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ALMOST_FULL_MARGIN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__SLOT_SEQ_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__COUNTER_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__PACKER_SLOT_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__CFG_RING_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__CTRL_SLOT_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__VC_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__DT_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__PAYLOAD_LEN_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__MAX_PACKET_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__PKT_BYTE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__PKT_SEQ_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__FIFO_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__TUSER_PKT_START_BIT;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__TUSER_CRC_ERR_BIT;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__TUSER_ECC_ERR_BIT;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__TUSER_TRUNC_ERR_BIT;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__TUSER_VC_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__TUSER_DT_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__TUSER_PAYLOAD_LEN_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__AXIS_KEEP_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__AXIS_BEAT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__BEAT_BYTE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__extractor_u__DOT__FIFO_AW;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__PKT_SEQ_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__PKT_BYTE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SAMPLE_SLOT_NUM;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SAMPLE_UNIT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__CQ_AREA_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HEADER_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__ALIGN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SLOT_HDR_MAGIC;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SLOT_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__AXIS_KEEP_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__AXIS_BEAT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__BEAT_BYTE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SAMPLE_UNIT_BITS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SAMPLE_AREA_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SAMPLE_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HEADER_BITS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SLOT_TOTAL_UNALIGNED;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SLOT_TOTAL_ALIGNED;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__PAD_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HEADER_BEATS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SAMPLE_AREA_BEATS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__CQ_AREA_BEATS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__PAD_BEATS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__SLOT_TOTAL_BEATS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__CAP_BUF_BEATS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__BEAT_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_MAGIC_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_VERSION_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_FLAGS_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_PKT_SEQ_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_PKT_BYTES_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_SAMPLE_CNT_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_SLOT_BYTES_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_SAMPLE_AREA_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_CQ_AREA_BIT_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_PKT_SEQ_FIELD_BITS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_PKT_BYTES_FIELD_BITS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__packer_u__DOT__HDR_SAMPLE_CNT_FIELD_BITS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__CFG_AXI_ADDR_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__AXI_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__RD_AXIS_USER_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__SLOT_STRIDE_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__SLOT_BUFFER_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__DESC_FIFO_DEPTH;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__MAX_BURST_LEN;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ADDR_ALIGN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__RING_SIZE_BYTES_MAX;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__ALMOST_FULL_MARGIN_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__SLOT_SEQ_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__COUNTER_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__RD_TUSER_SLOT_FIRST_BIT;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__RD_TUSER_SLOT_LAST_BIT;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__RD_TUSER_VALID_GOOD_BIT;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__RD_TUSER_OVERFLOW_ERR_BIT;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__RD_TUSER_SEQ_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__RD_TUSER_BYTES_LSB;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__CFG_RING_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__SLOT_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__AXIS_KEEP_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__AXIS_BEAT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__AXI_ADDR_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__AXI_STRB_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__AXI_BEAT_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__RD_AXIS_DATA_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__RD_AXIS_KEEP_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__RING_BYTES_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__SLOT_BUF_BEATS;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__SLOT_BUF_IDX_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__SLOT_BUF_AW;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__DESC_FIFO_AW;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__KEEP_CNT_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__MAX_BURST_BYTES;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__BURST_LEN_W;
constexpr IData/*31:0*/ Vtop___024root::pipeline_cocotb_top__DOT__ringbuffer_u__DOT__AXI_SIZE_C;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
