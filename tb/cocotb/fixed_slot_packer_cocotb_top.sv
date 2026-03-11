`include "slot_packer_macros.svh"

// Cocotb harness that adapts flat stimulus and monitor signals to AXIS interfaces.
module fixed_slot_packer_cocotb_top #(
    parameter int unsigned AXIS_DATA_W = `SLOT_PKR_AXIS_DATA_W_DFLT,
    parameter int unsigned AXIS_USER_W = `SLOT_PKR_AXIS_USER_W_DFLT,
    parameter int unsigned PKT_SEQ_W = `SLOT_PKR_PKT_SEQ_W_DFLT,
    parameter int unsigned PKT_BYTE_CNT_W = `SLOT_PKR_PKT_BYTE_CNT_W_DFLT,
    parameter int unsigned SAMPLE_SLOT_NUM = `SLOT_PKR_SAMPLE_SLOT_NUM_DFLT,
    parameter int unsigned SAMPLE_UNIT_BYTES = `SLOT_PKR_SAMPLE_UNIT_BYTES_DFLT,
    parameter int unsigned CQ_AREA_BYTES = `SLOT_PKR_CQ_AREA_BYTES_DFLT,
    parameter int unsigned HEADER_BYTES = `SLOT_PKR_HEADER_BYTES_DFLT,
    parameter int unsigned ALIGN_BYTES = `SLOT_PKR_ALIGN_BYTES_DFLT,
    parameter int unsigned SLOT_BYTES_W = slot_packer_pkg::clog2_safe(
        slot_packer_pkg::align_up_u(
            HEADER_BYTES + SAMPLE_SLOT_NUM * SAMPLE_UNIT_BYTES + CQ_AREA_BYTES, ALIGN_BYTES) + 1
    )
) (
    input logic clk_i,
    input logic rst_ni,

    input logic cfg_drop_invalid_pkt_i,

    input logic                      pkt_start_i,
    input logic                      pkt_done_i,
    input logic [PKT_BYTE_CNT_W-1:0] pkt_bytes_i,
    input logic [     PKT_SEQ_W-1:0] pkt_seq_i,
    input logic                      pkt_crc_err_i,
    input logic                      pkt_ecc_err_i,
    input logic                      pkt_trunc_err_i,
    input logic                      pkt_valid_good_i,

    output logic                    slot_start_o,
    output logic                    slot_done_o,
    output logic [SLOT_BYTES_W-1:0] slot_bytes_o,
    output logic [   PKT_SEQ_W-1:0] slot_seq_o,
    output logic                    slot_valid_good_o,
    output logic                    slot_overflow_err_o,

    input  logic [    AXIS_DATA_W-1:0] s_axis_tdata,
    input  logic [(AXIS_DATA_W/8)-1:0] s_axis_tkeep,
    input  logic                       s_axis_tvalid,
    output logic                       s_axis_tready,
    input  logic                       s_axis_tlast,
    input  logic [    AXIS_USER_W-1:0] s_axis_tuser,

    output logic [    AXIS_DATA_W-1:0] m_axis_tdata,
    output logic [(AXIS_DATA_W/8)-1:0] m_axis_tkeep,
    output logic                       m_axis_tvalid,
    input  logic                       m_axis_tready,
    output logic                       m_axis_tlast,
    output logic [    AXIS_USER_W-1:0] m_axis_tuser
);

  axis_stream_if #(
      .DATA_W(AXIS_DATA_W),
      .USER_W(AXIS_USER_W)
  ) s_axis_if ();
  axis_stream_if #(
      .DATA_W(AXIS_DATA_W),
      .USER_W(AXIS_USER_W)
  ) m_axis_if ();

  assign s_axis_if.tdata  = s_axis_tdata;
  assign s_axis_if.tkeep  = s_axis_tkeep;
  assign s_axis_if.tvalid = s_axis_tvalid;
  assign s_axis_if.tlast  = s_axis_tlast;
  assign s_axis_if.tuser  = s_axis_tuser;
  assign s_axis_tready    = s_axis_if.tready;

  assign m_axis_tdata     = m_axis_if.tdata;
  assign m_axis_tkeep     = m_axis_if.tkeep;
  assign m_axis_tvalid    = m_axis_if.tvalid;
  assign m_axis_tlast     = m_axis_if.tlast;
  assign m_axis_tuser     = m_axis_if.tuser;
  assign m_axis_if.tready = m_axis_tready;

  fixed_slot_packer #(
      .AXIS_DATA_W      (AXIS_DATA_W),
      .AXIS_USER_W      (AXIS_USER_W),
      .PKT_SEQ_W        (PKT_SEQ_W),
      .PKT_BYTE_CNT_W   (PKT_BYTE_CNT_W),
      .SAMPLE_SLOT_NUM  (SAMPLE_SLOT_NUM),
      .SAMPLE_UNIT_BYTES(SAMPLE_UNIT_BYTES),
      .CQ_AREA_BYTES    (CQ_AREA_BYTES),
      .HEADER_BYTES     (HEADER_BYTES),
      .ALIGN_BYTES      (ALIGN_BYTES),
      .SLOT_BYTES_W     (SLOT_BYTES_W)
  ) dut (
      .clk_i                 (clk_i),
      .rst_ni                (rst_ni),
      .cfg_drop_invalid_pkt_i(cfg_drop_invalid_pkt_i),
      .pkt_start_i           (pkt_start_i),
      .pkt_done_i            (pkt_done_i),
      .pkt_bytes_i           (pkt_bytes_i),
      .pkt_seq_i             (pkt_seq_i),
      .pkt_crc_err_i         (pkt_crc_err_i),
      .pkt_ecc_err_i         (pkt_ecc_err_i),
      .pkt_trunc_err_i       (pkt_trunc_err_i),
      .pkt_valid_good_i      (pkt_valid_good_i),
      .slot_start_o          (slot_start_o),
      .slot_done_o           (slot_done_o),
      .slot_bytes_o          (slot_bytes_o),
      .slot_seq_o            (slot_seq_o),
      .slot_valid_good_o     (slot_valid_good_o),
      .slot_overflow_err_o   (slot_overflow_err_o),
      .s_axis                (s_axis_if),
      .m_axis                (m_axis_if)
  );

endmodule
