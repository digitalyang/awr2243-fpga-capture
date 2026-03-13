`include "csi_packet_extractor_macros.svh"
`include "ddr_ringbuffer_macros.svh"

module top_tb;
  localparam int unsigned AXIS_DATA_W = `CSI_AXIS_DATA_W_DFLT;
  localparam int unsigned AXIS_USER_W = `CSI_AXIS_USER_W_DFLT;
  localparam int unsigned AXI_DATA_W = `DDR_RING_AXI_DATA_W_DFLT;
  localparam int unsigned AXI_ADDR_W = `DDR_RING_AXI_ADDR_W_DFLT;
  localparam int unsigned RD_AXIS_USER_W = `DDR_RING_AXIS_USER_W_DFLT;
  localparam int unsigned VC_W = csi_packet_pkg::CSI_VC_W;
  localparam int unsigned DT_W = csi_packet_pkg::CSI_DT_W;
  localparam int unsigned PKT_SEQ_W = `CSI_PKT_SEQ_W_DFLT;
  localparam int unsigned PKT_BYTE_CNT_W = csi_packet_pkg::clog2_safe(
      (1 << csi_packet_pkg::CSI_WORD_COUNT_W)
  );
  localparam int unsigned CFG_RING_BYTES_W = ddr_ringbuffer_pkg::DDR_RING_BYTES_W_DFLT;
  localparam int unsigned CTRL_SLOT_BYTES_W = ddr_ringbuffer_pkg::DDR_RING_SLOT_BYTES_W_DFLT;
  localparam int unsigned SLOT_SEQ_W = `DDR_RING_SLOT_SEQ_W_DFLT;
  localparam int unsigned COUNTER_W = `DDR_RING_COUNTER_W_DFLT;
  localparam int unsigned CDC_FIFO_DEPTH = 16;
  localparam int unsigned CDC_FIFO_LEVEL_W = $clog2(CDC_FIFO_DEPTH + 1);
  localparam int unsigned TB_CTRL_W = 16;

  logic                         video_aclk;
  logic                         axis_clk;
  logic                         axi_clk;
  logic                         sys_rst_n;
  logic                         video_rst_n;
  logic                         axis_rst_n;
  logic                         axi_rst_n;
  logic                         rst_ni;

  logic                         cfg_vc_en_i;
  logic                         cfg_dt_en_i;
  logic [             VC_W-1:0] cfg_vc_i;
  logic [             DT_W-1:0] cfg_dt_i;
  logic                         cfg_drop_invalid_pkt_i;

  logic                         cfg_enable_i;
  logic                         cfg_allow_overwrite_i;
  logic                         cfg_drop_invalid_slot_i;
  logic                         cfg_drop_on_no_space_i;
  logic [       AXI_ADDR_W-1:0] cfg_ring_base_addr_i;
  logic [ CFG_RING_BYTES_W-1:0] cfg_ring_size_bytes_i;

  logic                         pkt_start_o;
  logic                         pkt_done_o;
  logic                         pkt_valid_good_o;
  logic [        PKT_SEQ_W-1:0] pkt_seq_o;
  logic [   PKT_BYTE_CNT_W-1:0] pkt_bytes_o;
  logic                         pkt_crc_err_o;
  logic                         pkt_ecc_err_o;
  logic                         pkt_trunc_err_o;

  logic                         slot_start_o;
  logic                         slot_done_o;
  logic [CTRL_SLOT_BYTES_W-1:0] slot_bytes_o;
  logic [       SLOT_SEQ_W-1:0] slot_seq_o;
  logic                         slot_valid_good_o;
  logic                         slot_overflow_err_o;

  logic                         wr_slot_commit_o;
  logic [       AXI_ADDR_W-1:0] wr_slot_addr_o;
  logic [       SLOT_SEQ_W-1:0] wr_slot_seq_o;
  logic [CTRL_SLOT_BYTES_W-1:0] wr_slot_bytes_o;
  logic                         wr_slot_valid_good_o;
  logic                         wr_slot_overflow_err_o;

  logic                         rd_slot_req_i;
  logic                         rd_consume_i;
  logic                         rd_slot_valid_o;
  logic [       AXI_ADDR_W-1:0] rd_slot_addr_o;
  logic [CTRL_SLOT_BYTES_W-1:0] rd_slot_bytes_o;
  logic [       SLOT_SEQ_W-1:0] rd_slot_seq_o;
  logic                         rd_slot_valid_good_o;
  logic                         rd_slot_overflow_err_o;
  logic                         rd_busy_o;
  logic                         rd_done_o;
  logic                         rd_error_o;

  logic [       AXI_ADDR_W-1:0] wr_ptr_o;
  logic [       AXI_ADDR_W-1:0] rd_ptr_o;
  logic [       AXI_ADDR_W-1:0] commit_ptr_o;
  logic [ CFG_RING_BYTES_W-1:0] used_bytes_o;
  logic [ CFG_RING_BYTES_W-1:0] free_bytes_o;
  logic [ CFG_RING_BYTES_W-1:0] committed_bytes_o;
  logic                         full_o;
  logic                         almost_full_o;
  logic                         empty_o;
  logic [        COUNTER_W-1:0] wrap_count_o;
  logic [        COUNTER_W-1:0] overflow_count_o;
  logic [        COUNTER_W-1:0] drop_count_o;
  logic                         err_cfg_align_o;
  logic                         err_no_space_o;
  logic                         err_slot_proto_o;
  logic                         err_slot_too_large_o;
  logic                         err_axi_wr_resp_o;
  logic                         err_axi_rd_resp_o;
  logic                         err_illegal_read_o;
  logic [                  3:0] dbg_wr_state_o;
  logic [                  2:0] dbg_rd_state_o;

  logic [      AXIS_DATA_W-1:0] s_axis_tdata;
  logic [  (AXIS_DATA_W/8)-1:0] s_axis_tkeep;
  logic                         s_axis_tvalid;
  logic                         s_axis_tready;
  logic                         s_axis_tlast;
  logic [      AXIS_USER_W-1:0] s_axis_tuser;
  logic                         csi_rx_short_pkt_valid;
  logic                         csi_rx_short_pkt_ready;
  logic [             DT_W-1:0] csi_rx_short_pkt_dt;
  logic [             VC_W-1:0] csi_rx_short_pkt_vc;
  logic [                 15:0] csi_rx_short_pkt_data;
  logic [      AXIS_DATA_W-1:0] csi_rx_axis_tdata;
  logic [  (AXIS_DATA_W/8)-1:0] csi_rx_axis_tkeep;
  logic                         csi_rx_axis_tvalid;
  logic                         csi_rx_axis_tready;
  logic                         csi_rx_axis_tlast;
  logic [      AXIS_USER_W-1:0] csi_rx_axis_tuser;
  logic [        TB_CTRL_W-1:0] csi_rx_startup_latency_cycles;
  logic [        TB_CTRL_W-1:0] csi_rx_interpacket_gap_cycles;
  logic [        TB_CTRL_W-1:0] csi_rx_beat_gap_cycles;
  logic                         csi_rx_busy;
  logic                         csi_rx_gap_active;
  logic [        TB_CTRL_W-1:0] csi_rx_packet_count;
  logic [        TB_CTRL_W-1:0] csi_rx_beat_count;
  logic                         csi_rx_frame_active;
  logic                         csi_rx_line_active;
  logic [        TB_CTRL_W-1:0] csi_rx_short_packet_count;
  logic                         csi_rx_short_packet_error;
  logic [        TB_CTRL_W-1:0] csi_rx_short_packet_error_count;
  logic [        TB_CTRL_W-1:0] csi_rx_frame_count;
  logic [        TB_CTRL_W-1:0] csi_rx_line_count;
  logic [                  3:0] csi_rx_last_short_error_code;
  logic [             DT_W-1:0] csi_rx_last_short_dt;
  logic [             VC_W-1:0] csi_rx_last_short_vc;
  logic [                 15:0] csi_rx_last_short_data;
  logic [      AXIS_DATA_W-1:0] cdc_axis_tdata;
  logic [  (AXIS_DATA_W/8)-1:0] cdc_axis_tkeep;
  logic                         cdc_axis_tvalid;
  logic                         cdc_axis_tready;
  logic                         cdc_axis_tlast;
  logic [      AXIS_USER_W-1:0] cdc_axis_tuser;
  logic [ CDC_FIFO_LEVEL_W-1:0] cdc_fifo_level;
  logic                         cdc_sink_pause;
  logic [      AXIS_DATA_W-1:0] cdc_pipe_tdata;
  logic [  (AXIS_DATA_W/8)-1:0] cdc_pipe_tkeep;
  logic                         cdc_pipe_tvalid;
  logic                         cdc_pipe_tready;
  logic                         cdc_pipe_tlast;
  logic [      AXIS_USER_W-1:0] cdc_pipe_tuser;

  logic [       AXI_DATA_W-1:0] m_axis_rd_tdata;
  logic [   (AXI_DATA_W/8)-1:0] m_axis_rd_tkeep;
  logic                         m_axis_rd_tvalid;
  logic                         m_axis_rd_tready;
  logic                         m_axis_rd_tlast;
  logic [   RD_AXIS_USER_W-1:0] m_axis_rd_tuser;

  logic [       AXI_ADDR_W-1:0] radar_m_axi_awaddr;
  logic [                  7:0] radar_m_axi_awlen;
  logic [                  2:0] radar_m_axi_awsize;
  logic [                  1:0] radar_m_axi_awburst;
  logic                         radar_m_axi_awvalid;
  logic                         radar_m_axi_awready;
  logic [       AXI_DATA_W-1:0] radar_m_axi_wdata;
  logic [   (AXI_DATA_W/8)-1:0] radar_m_axi_wstrb;
  logic                         radar_m_axi_wlast;
  logic                         radar_m_axi_wvalid;
  logic                         radar_m_axi_wready;
  logic [                  1:0] radar_m_axi_bresp;
  logic                         radar_m_axi_bvalid;
  logic                         radar_m_axi_bready;
  logic [       AXI_ADDR_W-1:0] radar_m_axi_araddr;
  logic [                  7:0] radar_m_axi_arlen;
  logic [                  2:0] radar_m_axi_arsize;
  logic [                  1:0] radar_m_axi_arburst;
  logic                         radar_m_axi_arvalid;
  logic                         radar_m_axi_arready;
  logic [       AXI_DATA_W-1:0] radar_m_axi_rdata;
  logic [                  1:0] radar_m_axi_rresp;
  logic                         radar_m_axi_rlast;
  logic                         radar_m_axi_rvalid;
  logic                         radar_m_axi_rready;

  logic [       AXI_ADDR_W-1:0] m_axi_awaddr;
  logic [                  7:0] m_axi_awlen;
  logic [                  2:0] m_axi_awsize;
  logic [                  1:0] m_axi_awburst;
  logic                         m_axi_awvalid;
  logic                         m_axi_awready;
  logic [       AXI_DATA_W-1:0] m_axi_wdata;
  logic [   (AXI_DATA_W/8)-1:0] m_axi_wstrb;
  logic                         m_axi_wlast;
  logic                         m_axi_wvalid;
  logic                         m_axi_wready;
  logic [                  1:0] m_axi_bresp;
  logic                         m_axi_bvalid;
  logic                         m_axi_bready;
  logic [       AXI_ADDR_W-1:0] m_axi_araddr;
  logic [                  7:0] m_axi_arlen;
  logic [                  2:0] m_axi_arsize;
  logic [                  1:0] m_axi_arburst;
  logic                         m_axi_arvalid;
  logic                         m_axi_arready;
  logic [       AXI_DATA_W-1:0] m_axi_rdata;
  logic [                  1:0] m_axi_rresp;
  logic                         m_axi_rlast;
  logic                         m_axi_rvalid;
  logic                         m_axi_rready;

  logic [        COUNTER_W-1:0] radar_bridge_aw_count;
  logic [        COUNTER_W-1:0] radar_bridge_w_beat_count;
  logic [        COUNTER_W-1:0] radar_bridge_w_byte_count;
  logic [        COUNTER_W-1:0] radar_bridge_b_count;
  logic [        COUNTER_W-1:0] radar_bridge_ar_count;
  logic [        COUNTER_W-1:0] radar_bridge_r_beat_count;

  initial begin
    video_aclk                    = 1'b0;
    axis_clk                      = 1'b0;
    axi_clk                       = 1'b0;
    sys_rst_n                     = 1'b0;
    cfg_vc_en_i                   = 1'b0;
    cfg_dt_en_i                   = 1'b0;
    cfg_vc_i                      = '0;
    cfg_dt_i                      = '0;
    cfg_drop_invalid_pkt_i        = 1'b0;
    cfg_enable_i                  = 1'b0;
    cfg_allow_overwrite_i         = 1'b0;
    cfg_drop_invalid_slot_i       = 1'b0;
    cfg_drop_on_no_space_i        = 1'b0;
    cfg_ring_base_addr_i          = '0;
    cfg_ring_size_bytes_i         = '0;
    rd_slot_req_i                 = 1'b0;
    rd_consume_i                  = 1'b0;
    s_axis_tdata                  = '0;
    s_axis_tkeep                  = '0;
    s_axis_tvalid                 = 1'b0;
    s_axis_tlast                  = 1'b0;
    s_axis_tuser                  = '0;
    csi_rx_short_pkt_valid        = 1'b0;
    csi_rx_short_pkt_dt           = '0;
    csi_rx_short_pkt_vc           = '0;
    csi_rx_short_pkt_data         = '0;
    csi_rx_startup_latency_cycles = '0;
    csi_rx_interpacket_gap_cycles = '0;
    csi_rx_beat_gap_cycles        = '0;
    cdc_sink_pause                = 1'b0;
    m_axis_rd_tready              = 1'b1;
    m_axi_awready                 = 1'b0;
    m_axi_wready                  = 1'b0;
    m_axi_bresp                   = '0;
    m_axi_bvalid                  = 1'b0;
    m_axi_arready                 = 1'b0;
    m_axi_rdata                   = '0;
    m_axi_rresp                   = '0;
    m_axi_rlast                   = 1'b0;
    m_axi_rvalid                  = 1'b0;
  end

  always_ff @(posedge video_aclk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
      video_rst_n <= 1'b0;
    end else begin
      video_rst_n <= 1'b1;
    end
  end

  always_ff @(posedge axis_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
      axis_rst_n <= 1'b0;
    end else begin
      axis_rst_n <= 1'b1;
    end
  end

  always_ff @(posedge axi_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
      axi_rst_n <= 1'b0;
    end else begin
      axi_rst_n <= 1'b1;
    end
  end

  assign rst_ni = axis_rst_n & axi_rst_n;

  csi_rx_behavioral_mock #(
      .DATA_WIDTH (AXIS_DATA_W),
      .KEEP_WIDTH (AXIS_DATA_W / 8),
      .USER_WIDTH (AXIS_USER_W),
      .COUNT_WIDTH(TB_CTRL_W)
  ) csi_rx_behavioral_mock_u (
      .clk_i                            (video_aclk),
      .rst_ni                           (video_rst_n),
      .s_axis_tdata                     (s_axis_tdata),
      .s_axis_tkeep                     (s_axis_tkeep),
      .s_axis_tvalid                    (s_axis_tvalid),
      .s_axis_tready                    (s_axis_tready),
      .s_axis_tlast                     (s_axis_tlast),
      .s_axis_tuser                     (s_axis_tuser),
      .m_axis_tdata                     (csi_rx_axis_tdata),
      .m_axis_tkeep                     (csi_rx_axis_tkeep),
      .m_axis_tvalid                    (csi_rx_axis_tvalid),
      .m_axis_tready                    (csi_rx_axis_tready),
      .m_axis_tlast                     (csi_rx_axis_tlast),
      .m_axis_tuser                     (csi_rx_axis_tuser),
      .short_pkt_valid_i                (csi_rx_short_pkt_valid),
      .short_pkt_ready_o                (csi_rx_short_pkt_ready),
      .short_pkt_dt_i                   (csi_rx_short_pkt_dt),
      .short_pkt_vc_i                   (csi_rx_short_pkt_vc),
      .short_pkt_data_i                 (csi_rx_short_pkt_data),
      .cfg_startup_latency_cycles_i     (csi_rx_startup_latency_cycles),
      .cfg_interpacket_gap_cycles_i     (csi_rx_interpacket_gap_cycles),
      .cfg_beat_gap_cycles_i            (csi_rx_beat_gap_cycles),
      .status_busy_o                    (csi_rx_busy),
      .status_gap_active_o              (csi_rx_gap_active),
      .status_packet_count_o            (csi_rx_packet_count),
      .status_beat_count_o              (csi_rx_beat_count),
      .status_frame_active_o            (csi_rx_frame_active),
      .status_line_active_o             (csi_rx_line_active),
      .status_short_packet_count_o      (csi_rx_short_packet_count),
      .status_short_packet_error_o      (csi_rx_short_packet_error),
      .status_short_packet_error_count_o(csi_rx_short_packet_error_count),
      .status_frame_count_o             (csi_rx_frame_count),
      .status_line_count_o              (csi_rx_line_count),
      .status_last_short_error_code_o   (csi_rx_last_short_error_code),
      .status_last_short_dt_o           (csi_rx_last_short_dt),
      .status_last_short_vc_o           (csi_rx_last_short_vc),
      .status_last_short_data_o         (csi_rx_last_short_data)
  );

  axis_async_fifo #(
      .DEPTH      (CDC_FIFO_DEPTH),
      .DATA_WIDTH (AXIS_DATA_W),
      .KEEP_ENABLE(1'b1),
      .KEEP_WIDTH (AXIS_DATA_W / 8),
      .LAST_ENABLE(1'b1),
      .USER_ENABLE(1'b1),
      .USER_WIDTH (AXIS_USER_W)
  ) cdc_axis_async_fifo_u (
      .s_clk        (video_aclk),
      .s_rst        (~video_rst_n),
      .s_axis_tdata (csi_rx_axis_tdata),
      .s_axis_tkeep (csi_rx_axis_tkeep),
      .s_axis_tvalid(csi_rx_axis_tvalid),
      .s_axis_tready(csi_rx_axis_tready),
      .s_axis_tlast (csi_rx_axis_tlast),
      .s_axis_tuser (csi_rx_axis_tuser),
      .m_clk        (axis_clk),
      .m_rst        (~axis_rst_n),
      .m_axis_tdata (cdc_axis_tdata),
      .m_axis_tkeep (cdc_axis_tkeep),
      .m_axis_tvalid(cdc_axis_tvalid),
      .m_axis_tready(cdc_axis_tready),
      .m_axis_tlast (cdc_axis_tlast),
      .m_axis_tuser (cdc_axis_tuser),
      .status_depth (cdc_fifo_level)
  );

  assign cdc_pipe_tdata  = cdc_axis_tdata;
  assign cdc_pipe_tkeep  = cdc_axis_tkeep;
  assign cdc_pipe_tvalid = cdc_axis_tvalid && ~cdc_sink_pause;
  assign cdc_pipe_tlast  = cdc_axis_tlast;
  assign cdc_pipe_tuser  = cdc_axis_tuser;
  assign cdc_axis_tready = cdc_pipe_tready && ~cdc_sink_pause;

  pipeline_cocotb_top pipeline_u (
      .clk_i                  (axis_clk),
      .rst_ni                 (rst_ni),
      .cfg_vc_en_i            (cfg_vc_en_i),
      .cfg_dt_en_i            (cfg_dt_en_i),
      .cfg_vc_i               (cfg_vc_i),
      .cfg_dt_i               (cfg_dt_i),
      .cfg_drop_invalid_pkt_i (cfg_drop_invalid_pkt_i),
      .cfg_enable_i           (cfg_enable_i),
      .cfg_allow_overwrite_i  (cfg_allow_overwrite_i),
      .cfg_drop_invalid_slot_i(cfg_drop_invalid_slot_i),
      .cfg_drop_on_no_space_i (cfg_drop_on_no_space_i),
      .cfg_ring_base_addr_i   (cfg_ring_base_addr_i),
      .cfg_ring_size_bytes_i  (cfg_ring_size_bytes_i),
      .pkt_start_o            (pkt_start_o),
      .pkt_done_o             (pkt_done_o),
      .pkt_valid_good_o       (pkt_valid_good_o),
      .pkt_seq_o              (pkt_seq_o),
      .pkt_bytes_o            (pkt_bytes_o),
      .pkt_crc_err_o          (pkt_crc_err_o),
      .pkt_ecc_err_o          (pkt_ecc_err_o),
      .pkt_trunc_err_o        (pkt_trunc_err_o),
      .slot_start_o           (slot_start_o),
      .slot_done_o            (slot_done_o),
      .slot_bytes_o           (slot_bytes_o),
      .slot_seq_o             (slot_seq_o),
      .slot_valid_good_o      (slot_valid_good_o),
      .slot_overflow_err_o    (slot_overflow_err_o),
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
      .dbg_wr_state_o         (dbg_wr_state_o),
      .dbg_rd_state_o         (dbg_rd_state_o),
      .s_axis_tdata           (cdc_pipe_tdata),
      .s_axis_tkeep           (cdc_pipe_tkeep),
      .s_axis_tvalid          (cdc_pipe_tvalid),
      .s_axis_tready          (cdc_pipe_tready),
      .s_axis_tlast           (cdc_pipe_tlast),
      .s_axis_tuser           (cdc_pipe_tuser),
      .m_axis_rd_tdata        (m_axis_rd_tdata),
      .m_axis_rd_tkeep        (m_axis_rd_tkeep),
      .m_axis_rd_tvalid       (m_axis_rd_tvalid),
      .m_axis_rd_tready       (m_axis_rd_tready),
      .m_axis_rd_tlast        (m_axis_rd_tlast),
      .m_axis_rd_tuser        (m_axis_rd_tuser),
      .m_axi_awaddr           (radar_m_axi_awaddr),
      .m_axi_awlen            (radar_m_axi_awlen),
      .m_axi_awsize           (radar_m_axi_awsize),
      .m_axi_awburst          (radar_m_axi_awburst),
      .m_axi_awvalid          (radar_m_axi_awvalid),
      .m_axi_awready          (radar_m_axi_awready),
      .m_axi_wdata            (radar_m_axi_wdata),
      .m_axi_wstrb            (radar_m_axi_wstrb),
      .m_axi_wlast            (radar_m_axi_wlast),
      .m_axi_wvalid           (radar_m_axi_wvalid),
      .m_axi_wready           (radar_m_axi_wready),
      .m_axi_bresp            (radar_m_axi_bresp),
      .m_axi_bvalid           (radar_m_axi_bvalid),
      .m_axi_bready           (radar_m_axi_bready),
      .m_axi_araddr           (radar_m_axi_araddr),
      .m_axi_arlen            (radar_m_axi_arlen),
      .m_axi_arsize           (radar_m_axi_arsize),
      .m_axi_arburst          (radar_m_axi_arburst),
      .m_axi_arvalid          (radar_m_axi_arvalid),
      .m_axi_arready          (radar_m_axi_arready),
      .m_axi_rdata            (radar_m_axi_rdata),
      .m_axi_rresp            (radar_m_axi_rresp),
      .m_axi_rlast            (radar_m_axi_rlast),
      .m_axi_rvalid           (radar_m_axi_rvalid),
      .m_axi_rready           (radar_m_axi_rready)
  );

  radar_pipeline_ddr_bridge #(
      .AXI_ADDR_W(AXI_ADDR_W),
      .AXI_DATA_W(AXI_DATA_W),
      .COUNTER_W (COUNTER_W)
  ) radar_pipeline_ddr_bridge_u (
      .clk_i                (axis_clk),
      .rst_ni               (rst_ni),
      .s_axi_awaddr         (radar_m_axi_awaddr),
      .s_axi_awlen          (radar_m_axi_awlen),
      .s_axi_awsize         (radar_m_axi_awsize),
      .s_axi_awburst        (radar_m_axi_awburst),
      .s_axi_awvalid        (radar_m_axi_awvalid),
      .s_axi_awready        (radar_m_axi_awready),
      .s_axi_wdata          (radar_m_axi_wdata),
      .s_axi_wstrb          (radar_m_axi_wstrb),
      .s_axi_wlast          (radar_m_axi_wlast),
      .s_axi_wvalid         (radar_m_axi_wvalid),
      .s_axi_wready         (radar_m_axi_wready),
      .s_axi_bresp          (radar_m_axi_bresp),
      .s_axi_bvalid         (radar_m_axi_bvalid),
      .s_axi_bready         (radar_m_axi_bready),
      .s_axi_araddr         (radar_m_axi_araddr),
      .s_axi_arlen          (radar_m_axi_arlen),
      .s_axi_arsize         (radar_m_axi_arsize),
      .s_axi_arburst        (radar_m_axi_arburst),
      .s_axi_arvalid        (radar_m_axi_arvalid),
      .s_axi_arready        (radar_m_axi_arready),
      .s_axi_rdata          (radar_m_axi_rdata),
      .s_axi_rresp          (radar_m_axi_rresp),
      .s_axi_rlast          (radar_m_axi_rlast),
      .s_axi_rvalid         (radar_m_axi_rvalid),
      .s_axi_rready         (radar_m_axi_rready),
      .m_axi_awaddr         (m_axi_awaddr),
      .m_axi_awlen          (m_axi_awlen),
      .m_axi_awsize         (m_axi_awsize),
      .m_axi_awburst        (m_axi_awburst),
      .m_axi_awvalid        (m_axi_awvalid),
      .m_axi_awready        (m_axi_awready),
      .m_axi_wdata          (m_axi_wdata),
      .m_axi_wstrb          (m_axi_wstrb),
      .m_axi_wlast          (m_axi_wlast),
      .m_axi_wvalid         (m_axi_wvalid),
      .m_axi_wready         (m_axi_wready),
      .m_axi_bresp          (m_axi_bresp),
      .m_axi_bvalid         (m_axi_bvalid),
      .m_axi_bready         (m_axi_bready),
      .m_axi_araddr         (m_axi_araddr),
      .m_axi_arlen          (m_axi_arlen),
      .m_axi_arsize         (m_axi_arsize),
      .m_axi_arburst        (m_axi_arburst),
      .m_axi_arvalid        (m_axi_arvalid),
      .m_axi_arready        (m_axi_arready),
      .m_axi_rdata          (m_axi_rdata),
      .m_axi_rresp          (m_axi_rresp),
      .m_axi_rlast          (m_axi_rlast),
      .m_axi_rvalid         (m_axi_rvalid),
      .m_axi_rready         (m_axi_rready),
      .status_aw_count_o    (radar_bridge_aw_count),
      .status_w_beat_count_o(radar_bridge_w_beat_count),
      .status_w_byte_count_o(radar_bridge_w_byte_count),
      .status_b_count_o     (radar_bridge_b_count),
      .status_ar_count_o    (radar_bridge_ar_count),
      .status_r_beat_count_o(radar_bridge_r_beat_count)
  );
endmodule
