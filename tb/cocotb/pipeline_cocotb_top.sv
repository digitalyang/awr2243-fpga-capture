`include "csi_packet_extractor_macros.svh"
`include "slot_packer_macros.svh"
`include "ddr_ringbuffer_macros.svh"

// End-to-end cocotb harness that chains extractor, slot packer, and DDR ring
// controller into a single top-level pipeline.
module pipeline_cocotb_top #(
    parameter int unsigned AXIS_DATA_W = `CSI_AXIS_DATA_W_DFLT,
    parameter int unsigned AXIS_USER_W = `CSI_AXIS_USER_W_DFLT,
    parameter int unsigned VC_W = csi_packet_pkg::CSI_VC_W,
    parameter int unsigned DT_W = csi_packet_pkg::CSI_DT_W,
    parameter int unsigned PAYLOAD_LEN_W = csi_packet_pkg::CSI_WORD_COUNT_W,
    parameter int unsigned MAX_PACKET_BYTES = (1 << csi_packet_pkg::CSI_WORD_COUNT_W) - 1,
    parameter int unsigned PKT_BYTE_CNT_W = csi_packet_pkg::clog2_safe(MAX_PACKET_BYTES + 1),
    parameter int unsigned PKT_SEQ_W = `CSI_PKT_SEQ_W_DFLT,
    parameter int unsigned SAMPLE_SLOT_NUM = `SLOT_PKR_SAMPLE_SLOT_NUM_DFLT,
    parameter int unsigned SAMPLE_UNIT_BYTES = `SLOT_PKR_SAMPLE_UNIT_BYTES_DFLT,
    parameter int unsigned CQ_AREA_BYTES = `SLOT_PKR_CQ_AREA_BYTES_DFLT,
    parameter int unsigned HEADER_BYTES = `SLOT_PKR_HEADER_BYTES_DFLT,
    parameter int unsigned SLOT_ALIGN_BYTES = `SLOT_PKR_ALIGN_BYTES_DFLT,
    parameter int unsigned AXI_DATA_W = `DDR_RING_AXI_DATA_W_DFLT,
    parameter int unsigned AXI_ADDR_W = `DDR_RING_AXI_ADDR_W_DFLT,
    parameter int unsigned RD_AXIS_USER_W = `DDR_RING_AXIS_USER_W_DFLT,
    parameter bit SLOT_FIXED_EN = 1'b0,
    parameter int unsigned SLOT_STRIDE_BYTES = `DDR_RING_SLOT_STRIDE_BYTES_DFLT,
    parameter int unsigned SLOT_BUFFER_BYTES = `DDR_RING_SLOT_BUFFER_BYTES_DFLT,
    parameter int unsigned DESC_FIFO_DEPTH = `DDR_RING_FIFO_DEPTH_DFLT,
    parameter int unsigned MAX_BURST_LEN = `DDR_RING_MAX_BURST_LEN_DFLT,
    parameter int unsigned ADDR_ALIGN_BYTES = `DDR_RING_ALIGN_BYTES_DFLT,
    parameter int unsigned RING_SIZE_BYTES_MAX = `DDR_RING_RING_SIZE_BYTES_DFLT,
    parameter int unsigned ALMOST_FULL_MARGIN_BYTES = `DDR_RING_ALMOST_FULL_MARGIN_DFLT,
    parameter int unsigned SLOT_SEQ_W = `DDR_RING_SLOT_SEQ_W_DFLT,
    parameter int unsigned COUNTER_W = `DDR_RING_COUNTER_W_DFLT,
    parameter int unsigned PACKER_SLOT_BYTES_W = slot_packer_pkg::clog2_safe(
        slot_packer_pkg::align_up_u(
            HEADER_BYTES + SAMPLE_SLOT_NUM * SAMPLE_UNIT_BYTES + CQ_AREA_BYTES,
            SLOT_ALIGN_BYTES) + 1
    ),
    parameter int unsigned CFG_RING_BYTES_W = ddr_ringbuffer_pkg::clog2_safe(
        RING_SIZE_BYTES_MAX + 1
    ),
    parameter int unsigned CTRL_SLOT_BYTES_W = ddr_ringbuffer_pkg::clog2_safe(
        ddr_ringbuffer_pkg::max_u(
            RING_SIZE_BYTES_MAX,
            ddr_ringbuffer_pkg::max_u(
                SLOT_BUFFER_BYTES, SLOT_STRIDE_BYTES)) + 1
    )
) (
    input logic clk_i,
    input logic rst_ni,

    input logic            cfg_vc_en_i,
    input logic            cfg_dt_en_i,
    input logic [VC_W-1:0] cfg_vc_i,
    input logic [DT_W-1:0] cfg_dt_i,
    input logic            cfg_drop_invalid_pkt_i,

    input logic                        cfg_enable_i,
    input logic                        cfg_allow_overwrite_i,
    input logic                        cfg_drop_invalid_slot_i,
    input logic                        cfg_drop_on_no_space_i,
    input logic [      AXI_ADDR_W-1:0] cfg_ring_base_addr_i,
    input logic [CFG_RING_BYTES_W-1:0] cfg_ring_size_bytes_i,

    output logic                      pkt_start_o,
    output logic                      pkt_done_o,
    output logic                      pkt_valid_good_o,
    output logic [     PKT_SEQ_W-1:0] pkt_seq_o,
    output logic [PKT_BYTE_CNT_W-1:0] pkt_bytes_o,
    output logic                      pkt_crc_err_o,
    output logic                      pkt_ecc_err_o,
    output logic                      pkt_trunc_err_o,

    output logic                         slot_start_o,
    output logic                         slot_done_o,
    output logic [CTRL_SLOT_BYTES_W-1:0] slot_bytes_o,
    output logic [       SLOT_SEQ_W-1:0] slot_seq_o,
    output logic                         slot_valid_good_o,
    output logic                         slot_overflow_err_o,

    output logic                         wr_slot_commit_o,
    output logic [       AXI_ADDR_W-1:0] wr_slot_addr_o,
    output logic [       SLOT_SEQ_W-1:0] wr_slot_seq_o,
    output logic [CTRL_SLOT_BYTES_W-1:0] wr_slot_bytes_o,
    output logic                         wr_slot_valid_good_o,
    output logic                         wr_slot_overflow_err_o,

    input  logic                         rd_slot_req_i,
    input  logic                         rd_consume_i,
    output logic                         rd_slot_valid_o,
    output logic [       AXI_ADDR_W-1:0] rd_slot_addr_o,
    output logic [CTRL_SLOT_BYTES_W-1:0] rd_slot_bytes_o,
    output logic [       SLOT_SEQ_W-1:0] rd_slot_seq_o,
    output logic                         rd_slot_valid_good_o,
    output logic                         rd_slot_overflow_err_o,
    output logic                         rd_busy_o,
    output logic                         rd_done_o,
    output logic                         rd_error_o,

    output logic [      AXI_ADDR_W-1:0] wr_ptr_o,
    output logic [      AXI_ADDR_W-1:0] rd_ptr_o,
    output logic [      AXI_ADDR_W-1:0] commit_ptr_o,
    output logic [CFG_RING_BYTES_W-1:0] used_bytes_o,
    output logic [CFG_RING_BYTES_W-1:0] free_bytes_o,
    output logic [CFG_RING_BYTES_W-1:0] committed_bytes_o,
    output logic                        full_o,
    output logic                        almost_full_o,
    output logic                        empty_o,
    output logic [       COUNTER_W-1:0] wrap_count_o,
    output logic [       COUNTER_W-1:0] overflow_count_o,
    output logic [       COUNTER_W-1:0] drop_count_o,
    output logic                        err_cfg_align_o,
    output logic                        err_no_space_o,
    output logic                        err_slot_proto_o,
    output logic                        err_slot_too_large_o,
    output logic                        err_axi_wr_resp_o,
    output logic                        err_axi_rd_resp_o,
    output logic                        err_illegal_read_o,
    output logic [                 3:0] dbg_wr_state_o,
    output logic [                 2:0] dbg_rd_state_o,

    input  logic [    AXIS_DATA_W-1:0] s_axis_tdata,
    input  logic [(AXIS_DATA_W/8)-1:0] s_axis_tkeep,
    input  logic                       s_axis_tvalid,
    output logic                       s_axis_tready,
    input  logic                       s_axis_tlast,
    input  logic [    AXIS_USER_W-1:0] s_axis_tuser,

    output logic [    AXI_DATA_W-1:0] m_axis_rd_tdata,
    output logic [(AXI_DATA_W/8)-1:0] m_axis_rd_tkeep,
    output logic                      m_axis_rd_tvalid,
    input  logic                      m_axis_rd_tready,
    output logic                      m_axis_rd_tlast,
    output logic [RD_AXIS_USER_W-1:0] m_axis_rd_tuser,

    output logic [    AXI_ADDR_W-1:0] m_axi_awaddr,
    output logic [               7:0] m_axi_awlen,
    output logic [               2:0] m_axi_awsize,
    output logic [               1:0] m_axi_awburst,
    output logic                      m_axi_awvalid,
    input  logic                      m_axi_awready,
    output logic [    AXI_DATA_W-1:0] m_axi_wdata,
    output logic [(AXI_DATA_W/8)-1:0] m_axi_wstrb,
    output logic                      m_axi_wlast,
    output logic                      m_axi_wvalid,
    input  logic                      m_axi_wready,
    input  logic [               1:0] m_axi_bresp,
    input  logic                      m_axi_bvalid,
    output logic                      m_axi_bready,
    output logic [    AXI_ADDR_W-1:0] m_axi_araddr,
    output logic [               7:0] m_axi_arlen,
    output logic [               2:0] m_axi_arsize,
    output logic [               1:0] m_axi_arburst,
    output logic                      m_axi_arvalid,
    input  logic                      m_axi_arready,
    input  logic [    AXI_DATA_W-1:0] m_axi_rdata,
    input  logic [               1:0] m_axi_rresp,
    input  logic                      m_axi_rlast,
    input  logic                      m_axi_rvalid,
    output logic                      m_axi_rready
);

  axis_stream_if #(
      .DATA_W(AXIS_DATA_W),
      .USER_W(AXIS_USER_W)
  ) s_axis_if ();

  axis_stream_if #(
      .DATA_W(AXIS_DATA_W),
      .USER_W(AXIS_USER_W)
  ) pkt_axis_if ();

  axis_stream_if #(
      .DATA_W(AXIS_DATA_W),
      .USER_W(AXIS_USER_W)
  ) slot_axis_if ();

  axis_stream_if #(
      .DATA_W(AXI_DATA_W),
      .USER_W(RD_AXIS_USER_W)
  ) m_axis_rd_if ();

  axi4_mm_if #(
      .ADDR_W(AXI_ADDR_W),
      .DATA_W(AXI_DATA_W)
  ) m_axi_if ();

  logic                           slot_start_packer_c;
  logic                           slot_done_packer_c;
  logic [PACKER_SLOT_BYTES_W-1:0] slot_bytes_packer_c;
  logic [          PKT_SEQ_W-1:0] slot_seq_packer_c;
  logic                           slot_valid_good_packer_c;
  logic                           slot_overflow_err_packer_c;
  logic [  CTRL_SLOT_BYTES_W-1:0] slot_bytes_ctrl_c;
  logic [         SLOT_SEQ_W-1:0] slot_seq_ctrl_c;

  assign s_axis_if.tdata     = s_axis_tdata;
  assign s_axis_if.tkeep     = s_axis_tkeep;
  assign s_axis_if.tvalid    = s_axis_tvalid;
  assign s_axis_if.tlast     = s_axis_tlast;
  assign s_axis_if.tuser     = s_axis_tuser;
  assign s_axis_tready       = s_axis_if.tready;

  assign m_axis_rd_tdata     = m_axis_rd_if.tdata;
  assign m_axis_rd_tkeep     = m_axis_rd_if.tkeep;
  assign m_axis_rd_tvalid    = m_axis_rd_if.tvalid;
  assign m_axis_rd_tlast     = m_axis_rd_if.tlast;
  assign m_axis_rd_tuser     = m_axis_rd_if.tuser;
  assign m_axis_rd_if.tready = m_axis_rd_tready;

  assign m_axi_awaddr        = m_axi_if.awaddr;
  assign m_axi_awlen         = m_axi_if.awlen;
  assign m_axi_awsize        = m_axi_if.awsize;
  assign m_axi_awburst       = m_axi_if.awburst;
  assign m_axi_awvalid       = m_axi_if.awvalid;
  assign m_axi_if.awready    = m_axi_awready;
  assign m_axi_wdata         = m_axi_if.wdata;
  assign m_axi_wstrb         = m_axi_if.wstrb;
  assign m_axi_wlast         = m_axi_if.wlast;
  assign m_axi_wvalid        = m_axi_if.wvalid;
  assign m_axi_if.wready     = m_axi_wready;
  assign m_axi_if.bresp      = m_axi_bresp;
  assign m_axi_if.bvalid     = m_axi_bvalid;
  assign m_axi_bready        = m_axi_if.bready;
  assign m_axi_araddr        = m_axi_if.araddr;
  assign m_axi_arlen         = m_axi_if.arlen;
  assign m_axi_arsize        = m_axi_if.arsize;
  assign m_axi_arburst       = m_axi_if.arburst;
  assign m_axi_arvalid       = m_axi_if.arvalid;
  assign m_axi_if.arready    = m_axi_arready;
  assign m_axi_if.rdata      = m_axi_rdata;
  assign m_axi_if.rresp      = m_axi_rresp;
  assign m_axi_if.rlast      = m_axi_rlast;
  assign m_axi_if.rvalid     = m_axi_rvalid;
  assign m_axi_rready        = m_axi_if.rready;

  assign slot_bytes_ctrl_c   = CTRL_SLOT_BYTES_W'(slot_bytes_packer_c);
  assign slot_seq_ctrl_c     = SLOT_SEQ_W'(slot_seq_packer_c);

  assign slot_start_o        = slot_start_packer_c;
  assign slot_done_o         = slot_done_packer_c;
  assign slot_bytes_o        = slot_bytes_ctrl_c;
  assign slot_seq_o          = slot_seq_ctrl_c;
  assign slot_valid_good_o   = slot_valid_good_packer_c;
  assign slot_overflow_err_o = slot_overflow_err_packer_c;

  csi_packet_extractor #(
      .AXIS_DATA_W     (AXIS_DATA_W),
      .AXIS_USER_W     (AXIS_USER_W),
      .VC_W            (VC_W),
      .DT_W            (DT_W),
      .PAYLOAD_LEN_W   (PAYLOAD_LEN_W),
      .MAX_PACKET_BYTES(MAX_PACKET_BYTES),
      .PKT_BYTE_CNT_W  (PKT_BYTE_CNT_W),
      .PKT_SEQ_W       (PKT_SEQ_W)
  ) extractor_u (
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
      .m_axis          (pkt_axis_if)
  );

  fixed_slot_packer #(
      .AXIS_DATA_W      (AXIS_DATA_W),
      .AXIS_USER_W      (AXIS_USER_W),
      .PKT_SEQ_W        (PKT_SEQ_W),
      .PKT_BYTE_CNT_W   (PKT_BYTE_CNT_W),
      .SAMPLE_SLOT_NUM  (SAMPLE_SLOT_NUM),
      .SAMPLE_UNIT_BYTES(SAMPLE_UNIT_BYTES),
      .CQ_AREA_BYTES    (CQ_AREA_BYTES),
      .HEADER_BYTES     (HEADER_BYTES),
      .ALIGN_BYTES      (SLOT_ALIGN_BYTES),
      .SLOT_BYTES_W     (PACKER_SLOT_BYTES_W)
  ) packer_u (
      .clk_i                 (clk_i),
      .rst_ni                (rst_ni),
      .cfg_drop_invalid_pkt_i(cfg_drop_invalid_pkt_i),
      .pkt_start_i           (pkt_start_o),
      .pkt_done_i            (pkt_done_o),
      .pkt_bytes_i           (pkt_bytes_o),
      .pkt_seq_i             (pkt_seq_o),
      .pkt_crc_err_i         (pkt_crc_err_o),
      .pkt_ecc_err_i         (pkt_ecc_err_o),
      .pkt_trunc_err_i       (pkt_trunc_err_o),
      .pkt_valid_good_i      (pkt_valid_good_o),
      .slot_start_o          (slot_start_packer_c),
      .slot_done_o           (slot_done_packer_c),
      .slot_bytes_o          (slot_bytes_packer_c),
      .slot_seq_o            (slot_seq_packer_c),
      .slot_valid_good_o     (slot_valid_good_packer_c),
      .slot_overflow_err_o   (slot_overflow_err_packer_c),
      .s_axis                (pkt_axis_if),
      .m_axis                (slot_axis_if)
  );

  ddr_ringbuffer_controller #(
      .CFG_AXI_ADDR_W          (AXI_ADDR_W),
      .AXIS_DATA_W             (AXIS_DATA_W),
      .AXIS_USER_W             (AXIS_USER_W),
      .AXI_DATA_W              (AXI_DATA_W),
      .RD_AXIS_USER_W          (RD_AXIS_USER_W),
      .SLOT_FIXED_EN           (SLOT_FIXED_EN),
      .SLOT_STRIDE_BYTES       (SLOT_STRIDE_BYTES),
      .SLOT_BUFFER_BYTES       (SLOT_BUFFER_BYTES),
      .DESC_FIFO_DEPTH         (DESC_FIFO_DEPTH),
      .MAX_BURST_LEN           (MAX_BURST_LEN),
      .ADDR_ALIGN_BYTES        (ADDR_ALIGN_BYTES),
      .RING_SIZE_BYTES_MAX     (RING_SIZE_BYTES_MAX),
      .ALMOST_FULL_MARGIN_BYTES(ALMOST_FULL_MARGIN_BYTES),
      .SLOT_SEQ_W              (SLOT_SEQ_W),
      .COUNTER_W               (COUNTER_W),
      .CFG_RING_BYTES_W        (CFG_RING_BYTES_W),
      .SLOT_BYTES_W            (CTRL_SLOT_BYTES_W)
  ) ringbuffer_u (
      .clk_i                  (clk_i),
      .rst_ni                 (rst_ni),
      .cfg_enable_i           (cfg_enable_i),
      .cfg_allow_overwrite_i  (cfg_allow_overwrite_i),
      .cfg_drop_invalid_slot_i(cfg_drop_invalid_slot_i),
      .cfg_drop_on_no_space_i (cfg_drop_on_no_space_i),
      .cfg_ring_base_addr_i   (cfg_ring_base_addr_i),
      .cfg_ring_size_bytes_i  (cfg_ring_size_bytes_i),
      .slot_start_i           (slot_start_packer_c),
      .slot_done_i            (slot_done_packer_c),
      .slot_bytes_i           (slot_bytes_ctrl_c),
      .slot_seq_i             (slot_seq_ctrl_c),
      .slot_valid_good_i      (slot_valid_good_packer_c),
      .slot_overflow_err_i    (slot_overflow_err_packer_c),
      .wr_slot_commit_o       (wr_slot_commit_o),
      .wr_slot_addr_o         (wr_slot_addr_o),
      .wr_slot_seq_o          (wr_slot_seq_o),
      .wr_slot_bytes_o        (wr_slot_bytes_o),
      .wr_slot_valid_good_o   (wr_slot_valid_good_o),
      .wr_slot_overflow_err_o (wr_slot_overflow_err_o),
      .rd_slot_req_i          (rd_slot_req_i),
      .rd_consume_i           (rd_consume_i),
      .rd_slot_valid_o        (rd_slot_valid_o),
      .rd_slot_addr_o         (rd_slot_addr_o),
      .rd_slot_bytes_o        (rd_slot_bytes_o),
      .rd_slot_seq_o          (rd_slot_seq_o),
      .rd_slot_valid_good_o   (rd_slot_valid_good_o),
      .rd_slot_overflow_err_o (rd_slot_overflow_err_o),
      .rd_busy_o              (rd_busy_o),
      .rd_done_o              (rd_done_o),
      .rd_error_o             (rd_error_o),
      .wr_ptr_o               (wr_ptr_o),
      .rd_ptr_o               (rd_ptr_o),
      .commit_ptr_o           (commit_ptr_o),
      .used_bytes_o           (used_bytes_o),
      .free_bytes_o           (free_bytes_o),
      .committed_bytes_o      (committed_bytes_o),
      .full_o                 (full_o),
      .almost_full_o          (almost_full_o),
      .empty_o                (empty_o),
      .wrap_count_o           (wrap_count_o),
      .overflow_count_o       (overflow_count_o),
      .drop_count_o           (drop_count_o),
      .err_cfg_align_o        (err_cfg_align_o),
      .err_no_space_o         (err_no_space_o),
      .err_slot_proto_o       (err_slot_proto_o),
      .err_slot_too_large_o   (err_slot_too_large_o),
      .err_axi_wr_resp_o      (err_axi_wr_resp_o),
      .err_axi_rd_resp_o      (err_axi_rd_resp_o),
      .err_illegal_read_o     (err_illegal_read_o),
      .s_axis_slot            (slot_axis_if),
      .m_axis_rd              (m_axis_rd_if),
      .m_axi                  (m_axi_if)
  );

  assign dbg_wr_state_o = ringbuffer_u.wr_state_r;
  assign dbg_rd_state_o = ringbuffer_u.rd_state_r;

endmodule
