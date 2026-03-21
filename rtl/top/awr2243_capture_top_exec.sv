`timescale 1ns / 1ps

module awr2243_capture_top_exec #(
    parameter int unsigned AXIS_DATA_W = 256,
    parameter int unsigned AXIS_USER_W = 64,
    parameter int unsigned AXIL_ADDR_W = 32,
    parameter int unsigned AXIL_DATA_W = 32,
    parameter int unsigned AXI_ADDR_W  = 34,
    parameter int unsigned AXI_DATA_W  = 256,
    parameter bit          CFG_VC_EN_DEFAULT = 1'b0,
    parameter bit          CFG_DT_EN_DEFAULT = 1'b0,
    parameter logic [1:0]  CFG_VC_DEFAULT    = 2'b00,
    parameter logic [5:0]  CFG_DT_DEFAULT    = 6'h00,
    parameter bit          CFG_DROP_INVALID_PKT_DEFAULT = 1'b0,
    parameter logic [AXIL_ADDR_W-1:0] AWR_BASE_ADDR = AXIL_ADDR_W'(16'h0090)
) (
    input  logic sys_clk,
    input  logic sys_rst_n,
    input  logic axi_clk,
    input  logic axi_rst_n,

    input  logic [AXIS_DATA_W-1:0]   s_axis_csi_tdata,
    input  logic [AXIS_DATA_W/8-1:0] s_axis_csi_tkeep,
    input  logic                     s_axis_csi_tvalid,
    output logic                     s_axis_csi_tready,
    input  logic                     s_axis_csi_tlast,
    input  logic [AXIS_USER_W-1:0]   s_axis_csi_tuser,

    input  logic [AXIL_ADDR_W-1:0]   s_axil_bar0_awaddr,
    input  logic [2:0]               s_axil_bar0_awprot,
    input  logic                     s_axil_bar0_awvalid,
    output logic                     s_axil_bar0_awready,
    input  logic [AXIL_DATA_W-1:0]   s_axil_bar0_wdata,
    input  logic [AXIL_DATA_W/8-1:0] s_axil_bar0_wstrb,
    input  logic                     s_axil_bar0_wvalid,
    output logic                     s_axil_bar0_wready,
    output logic [1:0]               s_axil_bar0_bresp,
    output logic                     s_axil_bar0_bvalid,
    input  logic                     s_axil_bar0_bready,
    input  logic [AXIL_ADDR_W-1:0]   s_axil_bar0_araddr,
    input  logic [2:0]               s_axil_bar0_arprot,
    input  logic                     s_axil_bar0_arvalid,
    output logic                     s_axil_bar0_arready,
    output logic [AXIL_DATA_W-1:0]   s_axil_bar0_rdata,
    output logic [1:0]               s_axil_bar0_rresp,
    output logic                     s_axil_bar0_rvalid,
    input  logic                     s_axil_bar0_rready,

    output logic [AXI_ADDR_W-1:0]    m_axi_awaddr,
    output logic [7:0]               m_axi_awlen,
    output logic [2:0]               m_axi_awsize,
    output logic [1:0]               m_axi_awburst,
    output logic                     m_axi_awvalid,
    input  logic                     m_axi_awready,
    output logic [AXI_DATA_W-1:0]    m_axi_wdata,
    output logic [AXI_DATA_W/8-1:0]  m_axi_wstrb,
    output logic                     m_axi_wlast,
    output logic                     m_axi_wvalid,
    input  logic                     m_axi_wready,
    input  logic [1:0]               m_axi_bresp,
    input  logic                     m_axi_bvalid,
    output logic                     m_axi_bready,
    output logic [AXI_ADDR_W-1:0]    m_axi_araddr,
    output logic [7:0]               m_axi_arlen,
    output logic [2:0]               m_axi_arsize,
    output logic [1:0]               m_axi_arburst,
    output logic                     m_axi_arvalid,
    input  logic                     m_axi_arready,
    input  logic [AXI_DATA_W-1:0]    m_axi_rdata,
    input  logic [1:0]               m_axi_rresp,
    input  logic                     m_axi_rlast,
    input  logic                     m_axi_rvalid,
    output logic                     m_axi_rready,

    output logic [AXIS_DATA_W-1:0]   m_axis_rd_tdata,
    output logic [AXIS_DATA_W/8-1:0] m_axis_rd_tkeep,
    output logic                     m_axis_rd_tvalid,
    input  logic                     m_axis_rd_tready,
    output logic                     m_axis_rd_tlast,
    output logic [AXIS_USER_W-1:0]   m_axis_rd_tuser,

    output logic spi_sclk_o,
    output logic spi_cs_n_o,
    output logic spi_mosi_o,
    input  logic spi_miso_i,
    output logic sop0_o,
    output logic sop1_o,
    output logic sop2_o,
    output logic nreset_o,
    input  logic host_irq_i,
    input  logic nerror_out_i,

    output logic                  pkt_start_o,
    output logic                  pkt_done_o,
    output logic                  pkt_valid_good_o,
    output logic [15:0]           pkt_seq_o,
    output logic [15:0]           pkt_bytes_o,
    output logic                  pkt_crc_err_o,
    output logic                  pkt_ecc_err_o,
    output logic                  pkt_trunc_err_o,
    output logic                  slot_start_o,
    output logic                  slot_done_o,
    output logic [23:0]           slot_bytes_o,
    output logic [15:0]           slot_seq_o,
    output logic                  slot_valid_good_o,
    output logic                  slot_overflow_err_o,
    output logic                  wr_slot_commit_o,
    output logic [AXI_ADDR_W-1:0] wr_slot_addr_o,
    output logic [15:0]           wr_slot_seq_o,
    output logic [23:0]           wr_slot_bytes_o,
    output logic                  wr_slot_valid_good_o,
    output logic                  wr_slot_overflow_err_o,
    output logic                  rd_slot_valid_o,
    output logic [AXI_ADDR_W-1:0] rd_slot_addr_o,
    output logic [23:0]           rd_slot_bytes_o,
    output logic [15:0]           rd_slot_seq_o,
    output logic                  rd_slot_valid_good_o,
    output logic                  rd_slot_overflow_err_o,
    output logic                  rd_busy_o,
    output logic                  rd_done_o,
    output logic                  rd_error_o,
    output logic [AXI_ADDR_W-1:0] wr_ptr_o,
    output logic [AXI_ADDR_W-1:0] rd_ptr_o,
    output logic [AXI_ADDR_W-1:0] commit_ptr_o,
    output logic [31:0]           used_bytes_o,
    output logic [31:0]           free_bytes_o,
    output logic [31:0]           committed_bytes_o,
    output logic                  full_o,
    output logic                  almost_full_o,
    output logic                  empty_o,
    output logic [31:0]           wrap_count_o,
    output logic [31:0]           overflow_count_o,
    output logic [31:0]           drop_count_o,
    output logic                  err_cfg_align_o,
    output logic                  err_no_space_o,
    output logic                  err_slot_proto_o,
    output logic                  err_slot_too_large_o,
    output logic                  err_axi_wr_resp_o,
    output logic                  err_axi_rd_resp_o,
    output logic                  err_illegal_read_o,
    output logic                  ctrl_busy_o,
    output logic                  ctrl_done_o,
    output logic [15:0]           ctrl_err_code_o,
    output logic [3:0]            ctrl_state_o
);

  logic       cfg_vc_en_i;
  logic       cfg_dt_en_i;
  logic [1:0] cfg_vc_i;
  logic [5:0] cfg_dt_i;
  logic       cfg_drop_invalid_pkt_i;

  localparam int unsigned SLOT_PACKER_BYTES_W = slot_packer_pkg::clog2_safe(
      slot_packer_pkg::align_up_u(12 + 1024 * 12 + 9, 64) + 1
  );
  localparam int unsigned DDR_SLOT_BYTES_W = ddr_ringbuffer_pkg::DDR_RING_SLOT_BYTES_W_DFLT;
  localparam int unsigned DDR_RING_BYTES_W = ddr_ringbuffer_pkg::DDR_RING_BYTES_W_DFLT;

  logic [SLOT_PACKER_BYTES_W-1:0] slot_bytes_packer_w;
  logic [DDR_SLOT_BYTES_W-1:0]    slot_bytes_ring_w;
  logic [DDR_SLOT_BYTES_W-1:0]    wr_slot_bytes_ring_w;
  logic [DDR_SLOT_BYTES_W-1:0]    rd_slot_bytes_ring_w;
  logic [DDR_RING_BYTES_W-1:0]    used_bytes_ring_w;
  logic [DDR_RING_BYTES_W-1:0]    free_bytes_ring_w;
  logic [DDR_RING_BYTES_W-1:0]    committed_bytes_ring_w;

  assign cfg_vc_en_i            = CFG_VC_EN_DEFAULT;
  assign cfg_dt_en_i            = CFG_DT_EN_DEFAULT;
  assign cfg_vc_i               = CFG_VC_DEFAULT;
  assign cfg_dt_i               = CFG_DT_DEFAULT;
  assign cfg_drop_invalid_pkt_i = CFG_DROP_INVALID_PKT_DEFAULT;

  assign slot_bytes_ring_w = DDR_SLOT_BYTES_W'(slot_bytes_packer_w);
  assign slot_bytes_o      = 24'(slot_bytes_packer_w);
  assign wr_slot_bytes_o   = 24'(wr_slot_bytes_ring_w);
  assign rd_slot_bytes_o   = 24'(rd_slot_bytes_ring_w);
  assign used_bytes_o      = 32'(used_bytes_ring_w);
  assign free_bytes_o      = 32'(free_bytes_ring_w);
  assign committed_bytes_o = 32'(committed_bytes_ring_w);

  axis_stream_if #(
      .DATA_W(AXIS_DATA_W),
      .USER_W(AXIS_USER_W)
  ) axis_csi_if();

  axis_stream_if #(
      .DATA_W(AXIS_DATA_W),
      .USER_W(AXIS_USER_W)
  ) axis_pkt_if();

  axis_stream_if #(
      .DATA_W(AXIS_DATA_W),
      .USER_W(AXIS_USER_W)
  ) axis_slot_if();

  axis_stream_if #(
      .DATA_W(AXIS_DATA_W),
      .USER_W(AXIS_USER_W)
  ) axis_rd_if();

  axi4_lite_if #(
      .ADDR_W(AXIL_ADDR_W),
      .DATA_W(AXIL_DATA_W)
  ) axil_bar0_if();

  axi4_lite_if #(
      .ADDR_W(AXIL_ADDR_W),
      .DATA_W(AXIL_DATA_W)
  ) axil_ring_if();

  axi4_lite_if #(
      .ADDR_W(AXIL_ADDR_W),
      .DATA_W(AXIL_DATA_W)
  ) axil_awr_if();

  axi4_mm_if #(
      .ADDR_W(AXI_ADDR_W),
      .DATA_W(AXI_DATA_W)
  ) axi_ddr_if();

  assign axil_bar0_if.awaddr  = s_axil_bar0_awaddr;
  assign axil_bar0_if.awprot  = s_axil_bar0_awprot;
  assign axil_bar0_if.awvalid = s_axil_bar0_awvalid;
  assign s_axil_bar0_awready  = axil_bar0_if.awready;
  assign axil_bar0_if.wdata   = s_axil_bar0_wdata;
  assign axil_bar0_if.wstrb   = s_axil_bar0_wstrb;
  assign axil_bar0_if.wvalid  = s_axil_bar0_wvalid;
  assign s_axil_bar0_wready   = axil_bar0_if.wready;
  assign s_axil_bar0_bresp    = axil_bar0_if.bresp;
  assign s_axil_bar0_bvalid   = axil_bar0_if.bvalid;
  assign axil_bar0_if.bready  = s_axil_bar0_bready;
  assign axil_bar0_if.araddr  = s_axil_bar0_araddr;
  assign axil_bar0_if.arprot  = s_axil_bar0_arprot;
  assign axil_bar0_if.arvalid = s_axil_bar0_arvalid;
  assign s_axil_bar0_arready  = axil_bar0_if.arready;
  assign s_axil_bar0_rdata    = axil_bar0_if.rdata;
  assign s_axil_bar0_rresp    = axil_bar0_if.rresp;
  assign s_axil_bar0_rvalid   = axil_bar0_if.rvalid;
  assign axil_bar0_if.rready  = s_axil_bar0_rready;

  assign axis_csi_if.tdata  = s_axis_csi_tdata;
  assign axis_csi_if.tkeep  = s_axis_csi_tkeep;
  assign axis_csi_if.tvalid = s_axis_csi_tvalid;
  assign axis_csi_if.tlast  = s_axis_csi_tlast;
  assign axis_csi_if.tuser  = s_axis_csi_tuser;
  assign s_axis_csi_tready  = axis_csi_if.tready;

  assign m_axi_awaddr       = axi_ddr_if.awaddr;
  assign m_axi_awlen        = axi_ddr_if.awlen;
  assign m_axi_awsize       = axi_ddr_if.awsize;
  assign m_axi_awburst      = axi_ddr_if.awburst;
  assign m_axi_awvalid      = axi_ddr_if.awvalid;
  assign axi_ddr_if.awready = m_axi_awready;
  assign m_axi_wdata        = axi_ddr_if.wdata;
  assign m_axi_wstrb        = axi_ddr_if.wstrb;
  assign m_axi_wlast        = axi_ddr_if.wlast;
  assign m_axi_wvalid       = axi_ddr_if.wvalid;
  assign axi_ddr_if.wready  = m_axi_wready;
  assign axi_ddr_if.bresp   = m_axi_bresp;
  assign axi_ddr_if.bvalid  = m_axi_bvalid;
  assign m_axi_bready       = axi_ddr_if.bready;
  assign m_axi_araddr       = axi_ddr_if.araddr;
  assign m_axi_arlen        = axi_ddr_if.arlen;
  assign m_axi_arsize       = axi_ddr_if.arsize;
  assign m_axi_arburst      = axi_ddr_if.arburst;
  assign m_axi_arvalid      = axi_ddr_if.arvalid;
  assign axi_ddr_if.arready = m_axi_arready;
  assign axi_ddr_if.rdata   = m_axi_rdata;
  assign axi_ddr_if.rresp   = m_axi_rresp;
  assign axi_ddr_if.rlast   = m_axi_rlast;
  assign axi_ddr_if.rvalid  = m_axi_rvalid;
  assign m_axi_rready       = axi_ddr_if.rready;

  assign m_axis_rd_tdata    = axis_rd_if.tdata;
  assign m_axis_rd_tkeep    = axis_rd_if.tkeep;
  assign m_axis_rd_tvalid   = axis_rd_if.tvalid;
  assign m_axis_rd_tlast    = axis_rd_if.tlast;
  assign m_axis_rd_tuser    = axis_rd_if.tuser;
  assign axis_rd_if.tready  = m_axis_rd_tready;

  axil_bar0_decode #(
      .ADDR_W  (AXIL_ADDR_W),
      .DATA_W  (AXIL_DATA_W),
      .AWR_BASE(AWR_BASE_ADDR)
  ) u_axil_bar0_decode (
      .clk         (axi_clk),
      .rst_n       (axi_rst_n),
      .s_axil      (axil_bar0_if),
      .m_axil_ring (axil_ring_if),
      .m_axil_awr  (axil_awr_if)
  );

  csi_packet_extractor #(
      .AXIS_DATA_W(AXIS_DATA_W),
      .AXIS_USER_W(AXIS_USER_W)
  ) u_csi_packet_extractor (
      .clk_i            (axi_clk),
      .rst_ni           (axi_rst_n),
      .cfg_vc_en_i      (cfg_vc_en_i),
      .cfg_dt_en_i      (cfg_dt_en_i),
      .cfg_vc_i         (cfg_vc_i),
      .cfg_dt_i         (cfg_dt_i),
      .pkt_start_o      (pkt_start_o),
      .pkt_done_o       (pkt_done_o),
      .pkt_valid_good_o (pkt_valid_good_o),
      .pkt_seq_o        (pkt_seq_o),
      .pkt_bytes_o      (pkt_bytes_o),
      .pkt_crc_err_o    (pkt_crc_err_o),
      .pkt_ecc_err_o    (pkt_ecc_err_o),
      .pkt_trunc_err_o  (pkt_trunc_err_o),
      .s_axis           (axis_csi_if),
      .m_axis           (axis_pkt_if)
  );

  fixed_slot_packer #(
      .AXIS_DATA_W(AXIS_DATA_W),
      .AXIS_USER_W(AXIS_USER_W)
  ) u_fixed_slot_packer (
      .clk_i                 (axi_clk),
      .rst_ni                (axi_rst_n),
      .cfg_drop_invalid_pkt_i(cfg_drop_invalid_pkt_i),
      .pkt_start_i           (pkt_start_o),
      .pkt_done_i            (pkt_done_o),
      .pkt_bytes_i           (pkt_bytes_o),
      .pkt_seq_i             (pkt_seq_o),
      .pkt_crc_err_i         (pkt_crc_err_o),
      .pkt_ecc_err_i         (pkt_ecc_err_o),
      .pkt_trunc_err_i       (pkt_trunc_err_o),
      .pkt_valid_good_i      (pkt_valid_good_o),
      .slot_start_o          (slot_start_o),
      .slot_done_o           (slot_done_o),
      .slot_bytes_o          (slot_bytes_packer_w),
      .slot_seq_o            (slot_seq_o),
      .slot_valid_good_o     (slot_valid_good_o),
      .slot_overflow_err_o   (slot_overflow_err_o),
      .s_axis                (axis_pkt_if),
      .m_axis                (axis_slot_if)
  );

  ddr_ringbuffer_controller_axil #(
      .CFG_AXI_ADDR_W(AXI_ADDR_W),
      .AXIS_DATA_W   (AXIS_DATA_W),
      .AXIS_USER_W   (AXIS_USER_W),
      .AXI_DATA_W    (AXI_DATA_W),
      .RD_AXIS_USER_W(AXIS_USER_W)
  ) u_ddr_ringbuffer_controller_axil (
      .clk_i                 (axi_clk),
      .rst_ni                (axi_rst_n),
      .slot_start_i          (slot_start_o),
      .slot_done_i           (slot_done_o),
      .slot_bytes_i          (slot_bytes_ring_w),
      .slot_seq_i            (slot_seq_o),
      .slot_valid_good_i     (slot_valid_good_o),
      .slot_overflow_err_i   (slot_overflow_err_o),
      .wr_slot_commit_o      (wr_slot_commit_o),
      .wr_slot_addr_o        (wr_slot_addr_o),
      .wr_slot_seq_o         (wr_slot_seq_o),
      .wr_slot_bytes_o       (wr_slot_bytes_ring_w),
      .wr_slot_valid_good_o  (wr_slot_valid_good_o),
      .wr_slot_overflow_err_o(wr_slot_overflow_err_o),
      .rd_slot_valid_o       (rd_slot_valid_o),
      .rd_slot_addr_o        (rd_slot_addr_o),
      .rd_slot_bytes_o       (rd_slot_bytes_ring_w),
      .rd_slot_seq_o         (rd_slot_seq_o),
      .rd_slot_valid_good_o  (rd_slot_valid_good_o),
      .rd_slot_overflow_err_o(rd_slot_overflow_err_o),
      .rd_busy_o             (rd_busy_o),
      .rd_done_o             (rd_done_o),
      .rd_error_o            (rd_error_o),
      .wr_ptr_o              (wr_ptr_o),
      .rd_ptr_o              (rd_ptr_o),
      .commit_ptr_o          (commit_ptr_o),
      .used_bytes_o          (used_bytes_ring_w),
      .free_bytes_o          (free_bytes_ring_w),
      .committed_bytes_o     (committed_bytes_ring_w),
      .full_o                (full_o),
      .almost_full_o         (almost_full_o),
      .empty_o               (empty_o),
      .wrap_count_o          (wrap_count_o),
      .overflow_count_o      (overflow_count_o),
      .drop_count_o          (drop_count_o),
      .err_cfg_align_o       (err_cfg_align_o),
      .err_no_space_o        (err_no_space_o),
      .err_slot_proto_o      (err_slot_proto_o),
      .err_slot_too_large_o  (err_slot_too_large_o),
      .err_axi_wr_resp_o     (err_axi_wr_resp_o),
      .err_axi_rd_resp_o     (err_axi_rd_resp_o),
      .err_illegal_read_o    (err_illegal_read_o),
      .s_axis_slot           (axis_slot_if),
      .m_axis_rd             (axis_rd_if),
      .m_axi                 (axi_ddr_if),
      .s_axil                (axil_ring_if)
  );

  awr2243_ctrl_top u_awr2243_ctrl_top (
      .sys_clk        (axi_clk),
      .sys_rst_n      (axi_rst_n),
      .s_axil         (axil_awr_if),
      .spi_sclk_o     (spi_sclk_o),
      .spi_cs_n_o     (spi_cs_n_o),
      .spi_mosi_o     (spi_mosi_o),
      .spi_miso_i     (spi_miso_i),
      .sop0_o         (sop0_o),
      .sop1_o         (sop1_o),
      .sop2_o         (sop2_o),
      .nreset_o       (nreset_o),
      .host_irq_i     (host_irq_i),
      .nerror_out_i   (nerror_out_i),
      .ctrl_busy_o    (ctrl_busy_o),
      .ctrl_done_o    (ctrl_done_o),
      .ctrl_err_code_o(ctrl_err_code_o),
      .ctrl_state_o   (ctrl_state_o)
  );

endmodule
