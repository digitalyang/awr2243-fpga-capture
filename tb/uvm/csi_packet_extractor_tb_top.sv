`include "csi_packet_extractor_macros.svh"
`timescale 1ns / 1ps

// UVM top-level testbench wrapper for the standalone csi_packet_extractor DUT.
module csi_packet_extractor_tb_top;

  import uvm_pkg::*;
  import csi_packet_pkg::*;
  import csi_packet_extractor_uvm_pkg::*;

  localparam int unsigned AXIS_DATA_W = TB_AXIS_DATA_W;
  localparam int unsigned AXIS_USER_W = TB_AXIS_USER_W;
  localparam int unsigned PKT_BYTE_CNT_W = TB_PKT_BYTE_CNT_W;
  localparam int unsigned PKT_SEQ_W = TB_PKT_SEQ_W;
  localparam int unsigned VC_W = TB_VC_W;
  localparam int unsigned DT_W = TB_DT_W;

  logic clk;

  axis_stream_if #(
      .DATA_W(AXIS_DATA_W),
      .USER_W(AXIS_USER_W)
  ) s_axis_if ();

  axis_stream_if #(
      .DATA_W(AXIS_DATA_W),
      .USER_W(AXIS_USER_W)
  ) m_axis_if ();

  csi_packet_extractor_ctrl_if #(
      .VC_W          (VC_W),
      .DT_W          (DT_W),
      .PKT_SEQ_W     (PKT_SEQ_W),
      .PKT_BYTE_CNT_W(PKT_BYTE_CNT_W)
  ) ctrl_if (
      .clk(clk)
  );

  assign m_axis_if.tready = 1'b1;

  always #5 clk = ~clk;

  initial begin
    clk               = 1'b0;
    ctrl_if.rst_ni    = 1'b0;
    ctrl_if.cfg_vc_en = 1'b0;
    ctrl_if.cfg_dt_en = 1'b0;
    ctrl_if.cfg_vc    = '0;
    ctrl_if.cfg_dt    = '0;

    repeat (8) @(posedge clk);
    ctrl_if.rst_ni = 1'b1;
  end

  csi_packet_extractor #(
      .AXIS_DATA_W     (AXIS_DATA_W),
      .AXIS_USER_W     (AXIS_USER_W),
      .VC_W            (VC_W),
      .DT_W            (DT_W),
      .PAYLOAD_LEN_W   (CSI_WORD_COUNT_W),
      .MAX_PACKET_BYTES((1 << CSI_WORD_COUNT_W) - 1),
      .PKT_BYTE_CNT_W  (PKT_BYTE_CNT_W),
      .PKT_SEQ_W       (PKT_SEQ_W),
      .FIFO_DEPTH      (`CSI_FIFO_DEPTH_DFLT)
  ) dut (
      .clk_i           (clk),
      .rst_ni          (ctrl_if.rst_ni),
      .cfg_vc_en_i     (ctrl_if.cfg_vc_en),
      .cfg_dt_en_i     (ctrl_if.cfg_dt_en),
      .cfg_vc_i        (ctrl_if.cfg_vc),
      .cfg_dt_i        (ctrl_if.cfg_dt),
      .pkt_start_o     (ctrl_if.pkt_start),
      .pkt_done_o      (ctrl_if.pkt_done),
      .pkt_valid_good_o(ctrl_if.pkt_valid_good),
      .pkt_seq_o       (ctrl_if.pkt_seq),
      .pkt_bytes_o     (ctrl_if.pkt_bytes),
      .pkt_crc_err_o   (ctrl_if.pkt_crc_err),
      .pkt_ecc_err_o   (ctrl_if.pkt_ecc_err),
      .pkt_trunc_err_o (ctrl_if.pkt_trunc_err),
      .s_axis          (s_axis_if),
      .m_axis          (m_axis_if)
  );

  initial begin
    uvm_config_db#(virtual axis_stream_if #(AXIS_DATA_W, AXIS_USER_W))::set(null, "*", "src_vif",
                                                                            s_axis_if);
    uvm_config_db#(virtual axis_stream_if #(AXIS_DATA_W, AXIS_USER_W))::set(null, "*", "dst_vif",
                                                                            m_axis_if);
    uvm_config_db#(virtual csi_packet_extractor_ctrl_if #(
            VC_W,
            DT_W,
            PKT_SEQ_W,
            PKT_BYTE_CNT_W
        ))::set(
        null, "*", "ctrl_vif", ctrl_if);

    run_test();
  end

endmodule
