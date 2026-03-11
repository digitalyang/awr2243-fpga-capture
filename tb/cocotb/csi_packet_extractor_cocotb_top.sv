`include "csi_packet_extractor_macros.svh"

// Cocotb harness that flattens interface signals around csi_packet_extractor.
module csi_packet_extractor_cocotb_top #(
    parameter int unsigned AXIS_DATA_W      = `CSI_AXIS_DATA_W_DFLT,
    parameter int unsigned AXIS_USER_W      = `CSI_AXIS_USER_W_DFLT,
    parameter int unsigned VC_W             = csi_packet_pkg::CSI_VC_W,
    parameter int unsigned DT_W             = csi_packet_pkg::CSI_DT_W,
    parameter int unsigned PAYLOAD_LEN_W    = csi_packet_pkg::CSI_WORD_COUNT_W,
    parameter int unsigned MAX_PACKET_BYTES = (1 << csi_packet_pkg::CSI_WORD_COUNT_W) - 1,
    parameter int unsigned PKT_BYTE_CNT_W   = csi_packet_pkg::clog2_safe(MAX_PACKET_BYTES + 1),
    parameter int unsigned PKT_SEQ_W        = `CSI_PKT_SEQ_W_DFLT
) (
    input logic clk_i,
    input logic rst_ni,

    input logic            cfg_vc_en_i,
    input logic            cfg_dt_en_i,
    input logic [VC_W-1:0] cfg_vc_i,
    input logic [DT_W-1:0] cfg_dt_i,

    output logic                      pkt_start_o,
    output logic                      pkt_done_o,
    output logic                      pkt_valid_good_o,
    output logic [     PKT_SEQ_W-1:0] pkt_seq_o,
    output logic [PKT_BYTE_CNT_W-1:0] pkt_bytes_o,
    output logic                      pkt_crc_err_o,
    output logic                      pkt_ecc_err_o,
    output logic                      pkt_trunc_err_o,

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

  csi_packet_extractor #(
      .AXIS_DATA_W     (AXIS_DATA_W),
      .AXIS_USER_W     (AXIS_USER_W),
      .VC_W            (VC_W),
      .DT_W            (DT_W),
      .PAYLOAD_LEN_W   (PAYLOAD_LEN_W),
      .MAX_PACKET_BYTES(MAX_PACKET_BYTES),
      .PKT_BYTE_CNT_W  (PKT_BYTE_CNT_W),
      .PKT_SEQ_W       (PKT_SEQ_W)
  ) dut (
      .clk_i           (clk_i),
      .rst_ni          (rst_ni),
      .cfg_vc_en_i     (cfg_vc_en_i),
      .cfg_dt_en_i     (cfg_dt_en_i),
      .cfg_vc_i        (cfg_vc_i),
      .cfg_dt_i        (cfg_dt_i),
      .pkt_start_o     (pkt_start_o),
      .pkt_done_o      (pkt_done_o),
      .pkt_valid_good_o(pkt_valid_good_o),
      .pkt_seq_o       (pkt_seq_o),
      .pkt_bytes_o     (pkt_bytes_o),
      .pkt_crc_err_o   (pkt_crc_err_o),
      .pkt_ecc_err_o   (pkt_ecc_err_o),
      .pkt_trunc_err_o (pkt_trunc_err_o),
      .s_axis          (s_axis_if),
      .m_axis          (m_axis_if)
  );

endmodule
