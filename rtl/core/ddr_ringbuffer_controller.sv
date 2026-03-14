`include "ddr_ringbuffer_macros.svh"

// XPM-based rewrite:
// 1) slot buffer uses xpm_memory_sdpram instead of inferred RAM
// 2) data+keep merged into one memory word
// 3) added WR_ST_BUF_RD state so AXI W channel consumes registered RAM output
module ddr_ringbuffer_controller #(
    parameter int unsigned CFG_AXI_ADDR_W = `DDR_RING_AXI_ADDR_W_DFLT,
    parameter int unsigned AXIS_DATA_W = `DDR_RING_AXIS_DATA_W_DFLT,
    parameter int unsigned AXIS_USER_W = `DDR_RING_AXIS_USER_W_DFLT,
    parameter int unsigned AXI_DATA_W = `DDR_RING_AXI_DATA_W_DFLT,
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
    parameter int unsigned RD_TUSER_SLOT_FIRST_BIT = 0,
    parameter int unsigned RD_TUSER_SLOT_LAST_BIT = 1,
    parameter int unsigned RD_TUSER_VALID_GOOD_BIT = 2,
    parameter int unsigned RD_TUSER_OVERFLOW_ERR_BIT = 3,
    parameter int unsigned RD_TUSER_SEQ_LSB = 8,
    parameter int unsigned RD_TUSER_BYTES_LSB = 32,
    parameter int unsigned CFG_RING_BYTES_W = ddr_ringbuffer_pkg::clog2_safe(
        RING_SIZE_BYTES_MAX + 1
    ),
    parameter int unsigned SLOT_BYTES_W = ddr_ringbuffer_pkg::clog2_safe(
        ddr_ringbuffer_pkg::max_u(
            RING_SIZE_BYTES_MAX,
            ddr_ringbuffer_pkg::max_u(
                SLOT_BUFFER_BYTES, SLOT_STRIDE_BYTES
            )
        ) + 1
    )
) (
    input  logic                                        clk_i,
    input  logic                                        rst_ni,
    input  logic                                        cfg_enable_i,
    input  logic                                        cfg_allow_overwrite_i,
    input  logic                                        cfg_drop_invalid_slot_i,
    input  logic                                        cfg_drop_on_no_space_i,
    input  logic                 [  CFG_AXI_ADDR_W-1:0] cfg_ring_base_addr_i,
    input  logic                 [CFG_RING_BYTES_W-1:0] cfg_ring_size_bytes_i,
    input  logic                                        slot_start_i,
    input  logic                                        slot_done_i,
    input  logic                 [    SLOT_BYTES_W-1:0] slot_bytes_i,
    input  logic                 [      SLOT_SEQ_W-1:0] slot_seq_i,
    input  logic                                        slot_valid_good_i,
    input  logic                                        slot_overflow_err_i,
    output logic                                        wr_slot_commit_o,
    output logic                 [  CFG_AXI_ADDR_W-1:0] wr_slot_addr_o,
    output logic                 [      SLOT_SEQ_W-1:0] wr_slot_seq_o,
    output logic                 [    SLOT_BYTES_W-1:0] wr_slot_bytes_o,
    output logic                                        wr_slot_valid_good_o,
    output logic                                        wr_slot_overflow_err_o,
    input  logic                                        rd_slot_req_i,
    input  logic                                        rd_consume_i,
    output logic                                        rd_slot_valid_o,
    output logic                 [  CFG_AXI_ADDR_W-1:0] rd_slot_addr_o,
    output logic                 [    SLOT_BYTES_W-1:0] rd_slot_bytes_o,
    output logic                 [      SLOT_SEQ_W-1:0] rd_slot_seq_o,
    output logic                                        rd_slot_valid_good_o,
    output logic                                        rd_slot_overflow_err_o,
    output logic                                        rd_busy_o,
    output logic                                        rd_done_o,
    output logic                                        rd_error_o,
    output logic                 [  CFG_AXI_ADDR_W-1:0] wr_ptr_o,
    output logic                 [  CFG_AXI_ADDR_W-1:0] rd_ptr_o,
    output logic                 [  CFG_AXI_ADDR_W-1:0] commit_ptr_o,
    output logic                 [CFG_RING_BYTES_W-1:0] used_bytes_o,
    output logic                 [CFG_RING_BYTES_W-1:0] free_bytes_o,
    output logic                 [CFG_RING_BYTES_W-1:0] committed_bytes_o,
    output logic                                        full_o,
    output logic                                        almost_full_o,
    output logic                                        empty_o,
    output logic                 [       COUNTER_W-1:0] wrap_count_o,
    output logic                 [       COUNTER_W-1:0] overflow_count_o,
    output logic                 [       COUNTER_W-1:0] drop_count_o,
    output logic                                        err_cfg_align_o,
    output logic                                        err_no_space_o,
    output logic                                        err_slot_proto_o,
    output logic                                        err_slot_too_large_o,
    output logic                                        err_axi_wr_resp_o,
    output logic                                        err_axi_rd_resp_o,
    output logic                                        err_illegal_read_o,
           axis_stream_if.slave                         s_axis_slot,
           axis_stream_if.master                        m_axis_rd,
           axi4_mm_if.master                            m_axi
);

  import ddr_ringbuffer_pkg::*;

  localparam int unsigned AXIS_KEEP_W       = AXIS_DATA_W / 8;
  localparam int unsigned AXIS_BEAT_BYTES   = AXIS_DATA_W / 8;
  localparam int unsigned AXI_ADDR_W        = CFG_AXI_ADDR_W;
  localparam int unsigned AXI_STRB_W        = AXI_DATA_W / 8;
  localparam int unsigned AXI_BEAT_BYTES    = AXI_DATA_W / 8;
  localparam int unsigned RD_AXIS_DATA_W    = AXI_DATA_W;
  localparam int unsigned RD_AXIS_KEEP_W    = RD_AXIS_DATA_W / 8;
  localparam int unsigned RING_BYTES_W      = CFG_RING_BYTES_W;
  localparam int unsigned SLOT_BUF_BEATS    = ceil_div_u(SLOT_BUFFER_BYTES, AXIS_BEAT_BYTES);
  localparam int unsigned SLOT_BUF_IDX_W    = clog2_safe(SLOT_BUF_BEATS);
  localparam int unsigned SLOT_BUF_AW       = clog2_safe(SLOT_BUF_BEATS + 1);
  localparam int unsigned DESC_FIFO_AW      = clog2_safe(DESC_FIFO_DEPTH);
  localparam int unsigned KEEP_CNT_W        = clog2_safe(AXIS_KEEP_W + 1);
  localparam int unsigned MAX_BURST_BYTES   = MAX_BURST_LEN * AXI_BEAT_BYTES;
  localparam int unsigned BURST_LEN_W       = clog2_safe(MAX_BURST_LEN + 1);
  localparam int unsigned AXI_SIZE_C        = clog2_safe(AXI_BEAT_BYTES);
  localparam int unsigned SLOT_BUF_WORD_W   = AXIS_DATA_W + AXIS_KEEP_W;

  typedef enum logic [3:0] {
    WR_ST_IDLE,
    WR_ST_ACCEPT_SLOT,
    WR_ST_CHECK_SPACE,
    WR_ST_MAKE_SPACE,
    WR_ST_AW,
    WR_ST_BUF_RD,
    WR_ST_W,
    WR_ST_WAIT_B,
    WR_ST_COMMIT,
    WR_ST_DROP_SLOT
  } wr_state_e;

  typedef enum logic [2:0] {
    RD_ST_IDLE,
    RD_ST_AR,
    RD_ST_R,
    RD_ST_DONE
  } rd_state_e;

  logic [SLOT_BUF_WORD_W-1:0] slot_buf_rd_word_r;
  logic [AXIS_DATA_W-1:0]     slot_buf_rd_data_r;
  logic [AXIS_KEEP_W-1:0]     slot_buf_rd_keep_r;

  logic [SLOT_BUF_IDX_W-1:0] slot_buf_rd_addr_r;
  logic [SLOT_BUF_IDX_W-1:0] slot_buf_rd_addr_n;
  logic                      slot_buf_rd_pending_r;
  logic                      slot_buf_rd_pending_n;
  logic                      slot_buf_rd_valid_r;

  logic      [AXI_ADDR_W-1:0]   desc_addr_r          [0:DESC_FIFO_DEPTH-1];
  logic      [SLOT_BYTES_W-1:0] desc_bytes_r         [0:DESC_FIFO_DEPTH-1];
  logic      [SLOT_BYTES_W-1:0] desc_alloc_bytes_r   [0:DESC_FIFO_DEPTH-1];
  logic      [SLOT_SEQ_W-1:0]   desc_seq_r           [0:DESC_FIFO_DEPTH-1];
  logic                         desc_valid_good_r    [0:DESC_FIFO_DEPTH-1];
  logic                         desc_overflow_err_r  [0:DESC_FIFO_DEPTH-1];

  wr_state_e                    wr_state_r, wr_state_n;
  rd_state_e                    rd_state_r, rd_state_n;

  logic      [AXI_ADDR_W-1:0]   wr_ptr_r, wr_ptr_n;
  logic      [AXI_ADDR_W-1:0]   rd_ptr_r, rd_ptr_n;
  logic      [AXI_ADDR_W-1:0]   commit_ptr_r, commit_ptr_n;
  logic      [RING_BYTES_W-1:0] used_alloc_bytes_r, used_alloc_bytes_n;
  logic      [RING_BYTES_W-1:0] committed_alloc_bytes_r, committed_alloc_bytes_n;
  logic      [COUNTER_W-1:0]    wrap_count_r, wrap_count_n;
  logic      [COUNTER_W-1:0]    overflow_count_r, overflow_count_n;
  logic      [COUNTER_W-1:0]    drop_count_r, drop_count_n;

  logic      [DESC_FIFO_AW-1:0] desc_head_ptr_r, desc_head_ptr_n;
  logic      [DESC_FIFO_AW-1:0] desc_tail_ptr_r, desc_tail_ptr_n;
  logic      [DESC_FIFO_AW:0]   desc_count_r, desc_count_n;

  logic      [SLOT_BUF_AW-1:0]  cap_beat_count_r, cap_beat_count_n;
  logic      [SLOT_BYTES_W-1:0] cap_actual_bytes_r, cap_actual_bytes_n;
  logic      [SLOT_BYTES_W-1:0] cap_effective_bytes_r, cap_effective_bytes_n;
  logic      [SLOT_BYTES_W-1:0] cap_alloc_bytes_r, cap_alloc_bytes_n;
  logic      [SLOT_SEQ_W-1:0]   cap_slot_seq_r, cap_slot_seq_n;
  logic                         cap_slot_valid_good_r, cap_slot_valid_good_n;
  logic                         cap_slot_overflow_err_r, cap_slot_overflow_err_n;
  logic                         cap_proto_err_r, cap_proto_err_n;
  logic                         cap_too_large_r, cap_too_large_n;
  logic                         cap_size_mismatch_r, cap_size_mismatch_n;
  logic      [AXI_ADDR_W-1:0]   cap_slot_addr_r, cap_slot_addr_n;
  logic      [AXI_ADDR_W-1:0]   cap_next_wr_ptr_r, cap_next_wr_ptr_n;
  logic      [SLOT_BYTES_W-1:0] cap_first_seg_bytes_r, cap_first_seg_bytes_n;
  logic      [SLOT_BYTES_W-1:0] cap_second_seg_bytes_r, cap_second_seg_bytes_n;
  logic                         cap_wrap_r, cap_wrap_n;

  logic      [1:0]              wr_seg_idx_r, wr_seg_idx_n;
  logic      [AXI_ADDR_W-1:0]   wr_seg_addr_r, wr_seg_addr_n;
  logic      [SLOT_BYTES_W-1:0] wr_seg_bytes_rem_r, wr_seg_bytes_rem_n;
  logic      [SLOT_BUF_IDX_W-1:0] wr_buf_beat_idx_r, wr_buf_beat_idx_n;
  logic      [BURST_LEN_W-1:0]  wr_burst_beats_r, wr_burst_beats_n;
  logic      [SLOT_BYTES_W-1:0] wr_burst_bytes_r, wr_burst_bytes_n;
  logic      [BURST_LEN_W-1:0]  wr_burst_beat_sent_r, wr_burst_beat_sent_n;

  logic      [AXI_ADDR_W-1:0]   rd_slot_addr_r, rd_slot_addr_n;
  logic      [SLOT_BYTES_W-1:0] rd_slot_bytes_r, rd_slot_bytes_n;
  logic      [SLOT_BYTES_W-1:0] rd_slot_alloc_bytes_r, rd_slot_alloc_bytes_n;
  logic      [SLOT_SEQ_W-1:0]   rd_slot_seq_r, rd_slot_seq_n;
  logic                         rd_slot_valid_good_meta_r, rd_slot_valid_good_meta_n;
  logic                         rd_slot_overflow_meta_r, rd_slot_overflow_meta_n;
  logic      [SLOT_BYTES_W-1:0] rd_first_seg_bytes_r, rd_first_seg_bytes_n;
  logic      [SLOT_BYTES_W-1:0] rd_second_seg_bytes_r, rd_second_seg_bytes_n;
  logic      [1:0]              rd_seg_idx_r, rd_seg_idx_n;
  logic      [AXI_ADDR_W-1:0]   rd_seg_addr_r, rd_seg_addr_n;
  logic      [SLOT_BYTES_W-1:0] rd_seg_bytes_rem_r, rd_seg_bytes_rem_n;
  logic      [SLOT_BYTES_W-1:0] rd_total_bytes_rem_r, rd_total_bytes_rem_n;
  logic      [BURST_LEN_W-1:0]  rd_burst_beats_r, rd_burst_beats_n;
  logic      [SLOT_BYTES_W-1:0] rd_burst_bytes_r, rd_burst_bytes_n;
  logic      [BURST_LEN_W-1:0]  rd_burst_beats_rcvd_r, rd_burst_beats_rcvd_n;
  logic                         rd_first_beat_pending_r, rd_first_beat_pending_n;

  logic      [RD_AXIS_DATA_W-1:0] rd_axis_data_r, rd_axis_data_n;
  logic      [RD_AXIS_KEEP_W-1:0] rd_axis_keep_r, rd_axis_keep_n;
  logic      [RD_AXIS_USER_W-1:0] rd_axis_user_r, rd_axis_user_n;
  logic                           rd_axis_last_r, rd_axis_last_n;
  logic                           rd_axis_valid_r, rd_axis_valid_n;

  logic                           err_cfg_align_r, err_cfg_align_n;
  logic                           err_no_space_r, err_no_space_n;
  logic                           err_slot_proto_r, err_slot_proto_n;
  logic                           err_slot_too_large_r, err_slot_too_large_n;
  logic                           err_axi_wr_resp_r, err_axi_wr_resp_n;
  logic                           err_axi_rd_resp_r, err_axi_rd_resp_n;
  logic                           err_illegal_read_r, err_illegal_read_n;

  logic      [RING_BYTES_W-1:0] free_bytes_c;
  logic                         cfg_ring_ok_c;
  logic                         desc_fifo_full_c;
  logic                         desc_fifo_empty_c;
  logic                         slot_invalid_c;
  logic                         slot_can_fit_c;
  logic                         slot_drop_now_c;
  logic      [SLOT_BYTES_W-1:0] bytes_to_end_c;
  logic      [SLOT_BYTES_W-1:0] first_seg_bytes_c;
  logic      [SLOT_BYTES_W-1:0] second_seg_bytes_c;
  logic      [AXI_ADDR_W-1:0]   next_wr_ptr_c;
  logic                         next_wr_wrap_c;

  logic      [KEEP_CNT_W-1:0]   s_axis_keep_bytes_c;
  logic                         s_axis_ready_c;
  logic                         rd_axis_fire_c;
  logic                         axi_rready_c;

  logic                         slot_buf_wr_en_c;
  logic      [SLOT_BUF_IDX_W-1:0] slot_buf_wr_idx_c;
  logic      [AXIS_DATA_W-1:0]  slot_buf_wr_data_c;
  logic      [AXIS_KEEP_W-1:0]  slot_buf_wr_keep_c;

  logic                         desc_push_c;
  logic      [DESC_FIFO_AW-1:0] desc_push_idx_c;

  logic      [AXI_ADDR_W-1:0]   desc_head_addr_c;
  logic      [SLOT_BYTES_W-1:0] desc_head_bytes_c;
  logic      [SLOT_BYTES_W-1:0] desc_head_alloc_bytes_c;
  logic      [SLOT_SEQ_W-1:0]   desc_head_seq_c;
  logic                         desc_head_valid_good_c;
  logic                         desc_head_overflow_err_c;

  logic      [SLOT_BYTES_W-1:0] wr_cur_burst_bytes_c;
  logic      [BURST_LEN_W-1:0]  wr_cur_burst_beats_c;
  logic      [AXI_DATA_W-1:0]   wr_wdata_c;
  logic      [AXI_STRB_W-1:0]   wr_wstrb_c;
  logic                         wr_wlast_c;

  logic      [SLOT_BYTES_W-1:0] rd_cur_burst_bytes_c;
  logic      [BURST_LEN_W-1:0]  rd_cur_burst_beats_c;
  logic      [SLOT_BYTES_W-1:0] slot_effective_bytes_in_c;
  logic      [SLOT_BYTES_W-1:0] slot_alloc_bytes_in_c;

  logic                         wr_commit_pulse_c;
  logic                         rd_done_pulse_c;
  logic                         rd_error_pulse_c;

  integer                       wr_lane_idx;

  function automatic logic [KEEP_CNT_W-1:0] count_keep_bytes(input logic [AXIS_KEEP_W-1:0] keep);
    logic [KEEP_CNT_W-1:0] sum_c;
    int unsigned idx;
    begin
      sum_c = '0;
      for (idx = 0; idx < AXIS_KEEP_W; idx++) begin
        sum_c = sum_c + KEEP_CNT_W'(keep[idx]);
      end
      return sum_c;
    end
  endfunction

  function automatic logic [AXI_STRB_W-1:0] keep_mask_from_bytes(
      input logic [SLOT_BYTES_W-1:0] byte_count
  );
    logic [AXI_STRB_W-1:0] mask_c;
    int unsigned idx;
    begin
      mask_c = '0;
      for (idx = 0; idx < AXI_STRB_W; idx++) begin
        if (SLOT_BYTES_W'(idx) < byte_count) begin
          mask_c[idx] = 1'b1;
        end
      end
      return mask_c;
    end
  endfunction

  function automatic logic [DESC_FIFO_AW-1:0] fifo_ptr_next(input logic [DESC_FIFO_AW-1:0] ptr);
    if (ptr == DESC_FIFO_AW'(DESC_FIFO_DEPTH - 1)) begin
      return '0;
    end
    return ptr + DESC_FIFO_AW'(1);
  endfunction

  function automatic logic [SLOT_BYTES_W-1:0] bytes_to_ring_end(
      input logic [AXI_ADDR_W-1:0]   base_addr,
      input logic [RING_BYTES_W-1:0] ring_size_bytes,
      input logic [AXI_ADDR_W-1:0]   curr_addr
  );
    logic [AXI_ADDR_W-1:0] ring_end_addr;
    begin
      ring_end_addr = base_addr + AXI_ADDR_W'(ring_size_bytes);
      return SLOT_BYTES_W'(ring_end_addr - curr_addr);
    end
  endfunction

  function automatic logic [AXI_ADDR_W-1:0] ring_addr_add(
      input logic [AXI_ADDR_W-1:0]   base_addr,
      input logic [RING_BYTES_W-1:0] ring_size_bytes,
      input logic [AXI_ADDR_W-1:0]   curr_addr,
      input logic [SLOT_BYTES_W-1:0] advance_bytes
  );
    logic [AXI_ADDR_W-1:0]   ring_end_addr;
    logic [SLOT_BYTES_W-1:0] to_end_bytes;
    begin
      ring_end_addr = base_addr + AXI_ADDR_W'(ring_size_bytes);
      to_end_bytes  = SLOT_BYTES_W'(ring_end_addr - curr_addr);

      if (advance_bytes < to_end_bytes) begin
        return curr_addr + AXI_ADDR_W'(advance_bytes);
      end else if (advance_bytes == to_end_bytes) begin
        return base_addr;
      end
      return base_addr + AXI_ADDR_W'(advance_bytes - to_end_bytes);
    end
  endfunction

  assign s_axis_keep_bytes_c       = count_keep_bytes(s_axis_slot.tkeep);
  assign slot_effective_bytes_in_c = SLOT_FIXED_EN ? SLOT_BYTES_W'(SLOT_STRIDE_BYTES) : slot_bytes_i;
  assign slot_alloc_bytes_in_c     = SLOT_BYTES_W'(align_up_u(slot_effective_bytes_in_c, ADDR_ALIGN_BYTES));
  assign free_bytes_c              = RING_BYTES_W'(cfg_ring_size_bytes_i - used_alloc_bytes_r);
  assign desc_fifo_full_c          = (desc_count_r == (DESC_FIFO_AW + 1)'(DESC_FIFO_DEPTH));
  assign desc_fifo_empty_c         = (desc_count_r == '0);

  assign desc_head_addr_c          = desc_fifo_empty_c ? '0 : desc_addr_r[desc_head_ptr_r];
  assign desc_head_bytes_c         = desc_fifo_empty_c ? '0 : desc_bytes_r[desc_head_ptr_r];
  assign desc_head_alloc_bytes_c   = desc_fifo_empty_c ? '0 : desc_alloc_bytes_r[desc_head_ptr_r];
  assign desc_head_seq_c           = desc_fifo_empty_c ? '0 : desc_seq_r[desc_head_ptr_r];
  assign desc_head_valid_good_c    = desc_fifo_empty_c ? 1'b0 : desc_valid_good_r[desc_head_ptr_r];
  assign desc_head_overflow_err_c  = desc_fifo_empty_c ? 1'b0 : desc_overflow_err_r[desc_head_ptr_r];

  assign slot_invalid_c = !cap_slot_valid_good_r ||
                          cap_slot_overflow_err_r ||
                          cap_proto_err_r ||
                          cap_too_large_r ||
                          cap_size_mismatch_r;

  assign bytes_to_end_c     = bytes_to_ring_end(cfg_ring_base_addr_i, cfg_ring_size_bytes_i, wr_ptr_r);
  assign first_seg_bytes_c  = (cap_effective_bytes_r <= bytes_to_end_c) ? cap_effective_bytes_r : bytes_to_end_c;
  assign second_seg_bytes_c = cap_effective_bytes_r - first_seg_bytes_c;
  assign next_wr_ptr_c      = ring_addr_add(
      cfg_ring_base_addr_i, cfg_ring_size_bytes_i, wr_ptr_r, cap_alloc_bytes_r
  );
  assign next_wr_wrap_c     = (cap_alloc_bytes_r >= bytes_to_end_c);
  assign slot_can_fit_c     = (cap_alloc_bytes_r <= free_bytes_c) && !desc_fifo_full_c;
  assign slot_drop_now_c    = slot_invalid_c && cfg_drop_invalid_slot_i;

  assign rd_slot_valid_o        = !desc_fifo_empty_c;
  assign rd_slot_addr_o         = desc_head_addr_c;
  assign rd_slot_bytes_o        = desc_head_bytes_c;
  assign rd_slot_seq_o          = desc_head_seq_c;
  assign rd_slot_valid_good_o   = desc_head_valid_good_c;
  assign rd_slot_overflow_err_o = desc_head_overflow_err_c;
  assign rd_busy_o              = (rd_state_r != RD_ST_IDLE) || rd_axis_valid_r;

  assign wr_ptr_o          = wr_ptr_r;
  assign rd_ptr_o          = rd_ptr_r;
  assign commit_ptr_o      = commit_ptr_r;
  assign used_bytes_o      = used_alloc_bytes_r;
  assign free_bytes_o      = free_bytes_c;
  assign committed_bytes_o = committed_alloc_bytes_r;
  assign full_o            = (free_bytes_c == '0) || desc_fifo_full_c;
  assign almost_full_o     = (free_bytes_c <= RING_BYTES_W'(ALMOST_FULL_MARGIN_BYTES)) || desc_fifo_full_c;
  assign empty_o           = (committed_alloc_bytes_r == '0);
  assign wrap_count_o      = wrap_count_r;
  assign overflow_count_o  = overflow_count_r;
  assign drop_count_o      = drop_count_r;

  assign err_cfg_align_o      = err_cfg_align_r;
  assign err_no_space_o       = err_no_space_r;
  assign err_slot_proto_o     = err_slot_proto_r;
  assign err_slot_too_large_o = err_slot_too_large_r;
  assign err_axi_wr_resp_o    = err_axi_wr_resp_r;
  assign err_axi_rd_resp_o    = err_axi_rd_resp_r;
  assign err_illegal_read_o   = err_illegal_read_r;

  assign m_axis_rd.tdata  = rd_axis_data_r;
  assign m_axis_rd.tkeep  = rd_axis_keep_r;
  assign m_axis_rd.tvalid = rd_axis_valid_r;
  assign m_axis_rd.tlast  = rd_axis_last_r;
  assign m_axis_rd.tuser  = rd_axis_user_r;

  assign s_axis_slot.tready = s_axis_ready_c;
  assign rd_axis_fire_c     = rd_axis_valid_r && m_axis_rd.tready;

  assign slot_buf_rd_keep_r = slot_buf_rd_word_r[SLOT_BUF_WORD_W-1 -: AXIS_KEEP_W];
  assign slot_buf_rd_data_r = slot_buf_rd_word_r[AXIS_DATA_W-1:0];

  // XPM SDP RAM for slot capture buffer
  xpm_memory_sdpram #(
      .ADDR_WIDTH_A             (SLOT_BUF_IDX_W),
      .ADDR_WIDTH_B             (SLOT_BUF_IDX_W),
      .AUTO_SLEEP_TIME          (0),
      .BYTE_WRITE_WIDTH_A       (SLOT_BUF_WORD_W),
      .CASCADE_HEIGHT           (0),
      .CLOCKING_MODE            ("common_clock"),
      .ECC_MODE                 ("no_ecc"),
      .MEMORY_INIT_FILE         ("none"),
      .MEMORY_INIT_PARAM        ("0"),
      .MEMORY_OPTIMIZATION      ("true"),
      .MEMORY_PRIMITIVE         ("block"),
      .MEMORY_SIZE              (SLOT_BUF_BEATS * SLOT_BUF_WORD_W),
      .MESSAGE_CONTROL          (0),
      .READ_DATA_WIDTH_B        (SLOT_BUF_WORD_W),
      .READ_LATENCY_B           (1),
      .READ_RESET_VALUE_B       ("0"),
      .RST_MODE_A               ("SYNC"),
      .RST_MODE_B               ("SYNC"),
      .SIM_ASSERT_CHK           (0),
      .USE_EMBEDDED_CONSTRAINT  (0),
      .USE_MEM_INIT             (0),
      .WAKEUP_TIME              ("disable_sleep"),
      .WRITE_DATA_WIDTH_A       (SLOT_BUF_WORD_W),
      .WRITE_MODE_B             ("read_first")
  ) u_slot_buf_mem (
      .sleep          (1'b0),

      .clka           (clk_i),
      .ena            (slot_buf_wr_en_c),
      .wea            (slot_buf_wr_en_c),
      .addra          (slot_buf_wr_idx_c),
      .dina           ({slot_buf_wr_keep_c, slot_buf_wr_data_c}),
      .injectsbiterra (1'b0),
      .injectdbiterra (1'b0),

      .clkb           (clk_i),
      .enb            (slot_buf_rd_pending_r),
      .addrb          (slot_buf_rd_addr_r),
      .rstb           (1'b0),
      .regceb         (1'b1),
      .doutb          (slot_buf_rd_word_r),
      .dbiterrb       (),
      .sbiterrb       ()
  );

  always_comb begin
    logic [AXI_ADDR_W-1:0]   align_mask_addr_c;
    logic [RING_BYTES_W-1:0] align_mask_size_c;

    align_mask_addr_c = AXI_ADDR_W'(ADDR_ALIGN_BYTES - 1);
    align_mask_size_c = RING_BYTES_W'(ADDR_ALIGN_BYTES - 1);

    cfg_ring_ok_c = (cfg_ring_size_bytes_i != '0) &&
                    (cfg_ring_size_bytes_i <= RING_BYTES_W'(RING_SIZE_BYTES_MAX)) &&
                    ((cfg_ring_base_addr_i & align_mask_addr_c) == '0) &&
                    ((cfg_ring_size_bytes_i & align_mask_size_c) == '0);
  end

  always_comb begin
    logic [SLOT_BYTES_W-1:0] beat_valid_bytes_c;
    logic [RD_AXIS_USER_W-1:0] axis_user_c;
    logic last_beat_c;
    logic [SLOT_BYTES_W-1:0] lane_offset_c;
    logic [SLOT_BYTES_W-1:0] slot_byte_index_c;

    wr_state_n                = wr_state_r;
    rd_state_n                = rd_state_r;
    wr_ptr_n                  = wr_ptr_r;
    rd_ptr_n                  = rd_ptr_r;
    commit_ptr_n              = commit_ptr_r;
    used_alloc_bytes_n        = used_alloc_bytes_r;
    committed_alloc_bytes_n   = committed_alloc_bytes_r;
    wrap_count_n              = wrap_count_r;
    overflow_count_n          = overflow_count_r;
    drop_count_n              = drop_count_r;
    desc_head_ptr_n           = desc_head_ptr_r;
    desc_tail_ptr_n           = desc_tail_ptr_r;
    desc_count_n              = desc_count_r;
    cap_beat_count_n          = cap_beat_count_r;
    cap_actual_bytes_n        = cap_actual_bytes_r;
    cap_effective_bytes_n     = cap_effective_bytes_r;
    cap_alloc_bytes_n         = cap_alloc_bytes_r;
    cap_slot_seq_n            = cap_slot_seq_r;
    cap_slot_valid_good_n     = cap_slot_valid_good_r;
    cap_slot_overflow_err_n   = cap_slot_overflow_err_r;
    cap_proto_err_n           = cap_proto_err_r;
    cap_too_large_n           = cap_too_large_r;
    cap_size_mismatch_n       = cap_size_mismatch_r;
    cap_slot_addr_n           = cap_slot_addr_r;
    cap_next_wr_ptr_n         = cap_next_wr_ptr_r;
    cap_first_seg_bytes_n     = cap_first_seg_bytes_r;
    cap_second_seg_bytes_n    = cap_second_seg_bytes_r;
    cap_wrap_n                = cap_wrap_r;
    wr_seg_idx_n              = wr_seg_idx_r;
    wr_seg_addr_n             = wr_seg_addr_r;
    wr_seg_bytes_rem_n        = wr_seg_bytes_rem_r;
    wr_buf_beat_idx_n         = wr_buf_beat_idx_r;
    wr_burst_beats_n          = wr_burst_beats_r;
    wr_burst_bytes_n          = wr_burst_bytes_r;
    wr_burst_beat_sent_n      = wr_burst_beat_sent_r;
    rd_slot_addr_n            = rd_slot_addr_r;
    rd_slot_bytes_n           = rd_slot_bytes_r;
    rd_slot_alloc_bytes_n     = rd_slot_alloc_bytes_r;
    rd_slot_seq_n             = rd_slot_seq_r;
    rd_slot_valid_good_meta_n = rd_slot_valid_good_meta_r;
    rd_slot_overflow_meta_n   = rd_slot_overflow_meta_r;
    rd_first_seg_bytes_n      = rd_first_seg_bytes_r;
    rd_second_seg_bytes_n     = rd_second_seg_bytes_r;
    rd_seg_idx_n              = rd_seg_idx_r;
    rd_seg_addr_n             = rd_seg_addr_r;
    rd_seg_bytes_rem_n        = rd_seg_bytes_rem_r;
    rd_total_bytes_rem_n      = rd_total_bytes_rem_r;
    rd_burst_beats_n          = rd_burst_beats_r;
    rd_burst_bytes_n          = rd_burst_bytes_r;
    rd_burst_beats_rcvd_n     = rd_burst_beats_rcvd_r;
    rd_first_beat_pending_n   = rd_first_beat_pending_r;
    rd_axis_data_n            = rd_axis_data_r;
    rd_axis_keep_n            = rd_axis_keep_r;
    rd_axis_user_n            = rd_axis_user_r;
    rd_axis_last_n            = rd_axis_last_r;
    rd_axis_valid_n           = rd_axis_valid_r;
    err_cfg_align_n           = err_cfg_align_r;
    err_no_space_n            = err_no_space_r;
    err_slot_proto_n          = err_slot_proto_r;
    err_slot_too_large_n      = err_slot_too_large_r;
    err_axi_wr_resp_n         = err_axi_wr_resp_r;
    err_axi_rd_resp_n         = err_axi_rd_resp_r;
    err_illegal_read_n        = err_illegal_read_r;
    slot_buf_rd_addr_n        = slot_buf_rd_addr_r;
    slot_buf_rd_pending_n     = 1'b0;

    s_axis_ready_c            = 1'b0;

    m_axi.awaddr              = '0;
    m_axi.awlen               = '0;
    m_axi.awsize              = 3'(AXI_SIZE_C);
    m_axi.awburst             = AXI_BURST_INCR;
    m_axi.awvalid             = 1'b0;

    m_axi.wdata               = '0;
    m_axi.wstrb               = '0;
    m_axi.wlast               = 1'b0;
    m_axi.wvalid              = 1'b0;
    m_axi.bready              = 1'b0;

    m_axi.araddr              = '0;
    m_axi.arlen               = '0;
    m_axi.arsize              = 3'(AXI_SIZE_C);
    m_axi.arburst             = AXI_BURST_INCR;
    m_axi.arvalid             = 1'b0;
    m_axi.rready              = 1'b0;
    axi_rready_c              = 1'b0;

    slot_buf_wr_en_c          = 1'b0;
    slot_buf_wr_idx_c         = '0;
    slot_buf_wr_data_c        = '0;
    slot_buf_wr_keep_c        = '0;

    desc_push_c               = 1'b0;
    desc_push_idx_c           = desc_tail_ptr_r;

    wr_cur_burst_bytes_c      = SLOT_BYTES_W'(min_u(wr_seg_bytes_rem_r, MAX_BURST_BYTES));
    wr_cur_burst_beats_c      = BURST_LEN_W'(ceil_div_u(wr_cur_burst_bytes_c, AXI_BEAT_BYTES));
    rd_cur_burst_bytes_c      = SLOT_BYTES_W'(min_u(rd_seg_bytes_rem_r, MAX_BURST_BYTES));
    rd_cur_burst_beats_c      = BURST_LEN_W'(ceil_div_u(rd_cur_burst_bytes_c, AXI_BEAT_BYTES));
    beat_valid_bytes_c        = '0;
    axis_user_c               = '0;
    last_beat_c               = 1'b0;

    wr_wdata_c                = '0;
    wr_wstrb_c                = '0;
    wr_wlast_c                = (wr_burst_beat_sent_r == (wr_burst_beats_r - BURST_LEN_W'(1)));

    slot_byte_index_c         = (SLOT_BYTES_W'(wr_buf_beat_idx_r) + SLOT_BYTES_W'(wr_burst_beat_sent_r)) *
                                SLOT_BYTES_W'(AXI_BEAT_BYTES);

    for (wr_lane_idx = 0; wr_lane_idx < AXI_STRB_W; wr_lane_idx++) begin
      lane_offset_c = SLOT_BYTES_W'(wr_lane_idx);
      if ((slot_byte_index_c + lane_offset_c) < cap_effective_bytes_r) begin
        wr_wstrb_c[wr_lane_idx] = 1'b1;
        if (slot_buf_rd_keep_r[wr_lane_idx]) begin
          wr_wdata_c[wr_lane_idx*8 +: 8] = slot_buf_rd_data_r[wr_lane_idx*8 +: 8];
        end
      end
    end

    wr_commit_pulse_c         = 1'b0;
    rd_done_pulse_c           = 1'b0;
    rd_error_pulse_c          = 1'b0;

    if (cfg_enable_i && !cfg_ring_ok_c) begin
      err_cfg_align_n = 1'b1;
    end

    if (rd_axis_fire_c) begin
      rd_axis_valid_n = 1'b0;
      rd_axis_last_n  = 1'b0;
      rd_axis_keep_n  = '0;
      rd_axis_user_n  = '0;
    end

    if (rd_consume_i && rd_slot_req_i) begin
      err_illegal_read_n = 1'b1;
      rd_error_pulse_c   = 1'b1;
    end

    if (rd_consume_i && !rd_slot_req_i) begin
      if (!rd_busy_o && !desc_fifo_empty_c) begin
        desc_head_ptr_n         = fifo_ptr_next(desc_head_ptr_r);
        desc_count_n            = desc_count_n - 1'b1;
        rd_ptr_n                = ring_addr_add(cfg_ring_base_addr_i, cfg_ring_size_bytes_i, rd_ptr_r,
                                                desc_head_alloc_bytes_c);
        used_alloc_bytes_n      = used_alloc_bytes_n - RING_BYTES_W'(desc_head_alloc_bytes_c);
        committed_alloc_bytes_n = committed_alloc_bytes_n - RING_BYTES_W'(desc_head_alloc_bytes_c);
      end else begin
        err_illegal_read_n = 1'b1;
        rd_error_pulse_c   = 1'b1;
      end
    end

    case (wr_state_r)
      WR_ST_IDLE: begin
        if (cfg_enable_i && cfg_ring_ok_c) begin
          s_axis_ready_c = 1'b1;
          if (s_axis_slot.tvalid) begin
            slot_buf_wr_en_c          = (SLOT_BUF_BEATS > 0);
            slot_buf_wr_idx_c         = '0;
            slot_buf_wr_data_c        = s_axis_slot.tdata;
            slot_buf_wr_keep_c        = s_axis_slot.tkeep;
            cap_beat_count_n          = SLOT_BUF_AW'(1);
            cap_actual_bytes_n        = SLOT_BYTES_W'(s_axis_keep_bytes_c);
            cap_effective_bytes_n     = slot_effective_bytes_in_c;
            cap_alloc_bytes_n         = slot_alloc_bytes_in_c;
            cap_slot_seq_n            = slot_seq_i;
            cap_slot_valid_good_n     = slot_valid_good_i;
            cap_slot_overflow_err_n   = slot_overflow_err_i;
            cap_proto_err_n           = !slot_start_i || (slot_done_i && !s_axis_slot.tlast);
            cap_too_large_n           = (slot_effective_bytes_in_c > SLOT_BYTES_W'(SLOT_BUFFER_BYTES));
            cap_size_mismatch_n       = 1'b0;
            cap_slot_addr_n           = '0;
            cap_next_wr_ptr_n         = '0;
            cap_first_seg_bytes_n     = '0;
            cap_second_seg_bytes_n    = '0;
            cap_wrap_n                = 1'b0;

            if (slot_overflow_err_i) begin
              overflow_count_n = overflow_count_n + COUNTER_W'(1);
            end
            if (slot_effective_bytes_in_c > SLOT_BYTES_W'(SLOT_BUFFER_BYTES)) begin
              err_slot_too_large_n = 1'b1;
            end

            if (s_axis_slot.tlast) begin
              if (!slot_done_i || (SLOT_BYTES_W'(s_axis_keep_bytes_c) != slot_effective_bytes_in_c)) begin
                cap_size_mismatch_n = 1'b1;
                err_slot_proto_n    = 1'b1;
              end
              wr_state_n = WR_ST_CHECK_SPACE;
            end else begin
              wr_state_n = WR_ST_ACCEPT_SLOT;
            end
          end
        end
      end

      WR_ST_ACCEPT_SLOT: begin
        if (cfg_enable_i && cfg_ring_ok_c) begin
          s_axis_ready_c = 1'b1;
          if (s_axis_slot.tvalid) begin
            if (cap_beat_count_r < SLOT_BUF_AW'(SLOT_BUF_BEATS)) begin
              slot_buf_wr_en_c   = 1'b1;
              slot_buf_wr_idx_c  = SLOT_BUF_IDX_W'(cap_beat_count_r);
              slot_buf_wr_data_c = s_axis_slot.tdata;
              slot_buf_wr_keep_c = s_axis_slot.tkeep;
              cap_beat_count_n   = cap_beat_count_r + SLOT_BUF_AW'(1);
            end else begin
              cap_too_large_n      = 1'b1;
              err_slot_too_large_n = 1'b1;
            end

            cap_actual_bytes_n = cap_actual_bytes_r + SLOT_BYTES_W'(s_axis_keep_bytes_c);

            if (slot_start_i || (slot_done_i && !s_axis_slot.tlast)) begin
              cap_proto_err_n  = 1'b1;
              err_slot_proto_n = 1'b1;
            end

            if (s_axis_slot.tlast) begin
              if (!slot_done_i ||
                  ((cap_actual_bytes_r + SLOT_BYTES_W'(s_axis_keep_bytes_c)) != cap_effective_bytes_r)) begin
                cap_size_mismatch_n = 1'b1;
                err_slot_proto_n    = 1'b1;
              end
              wr_state_n = WR_ST_CHECK_SPACE;
            end
          end
        end
      end

      WR_ST_CHECK_SPACE: begin
        if (!cfg_ring_ok_c) begin
          err_cfg_align_n = 1'b1;
        end else if ((cap_effective_bytes_r == '0) ||
                      (cap_alloc_bytes_r == '0) ||
                      (cap_alloc_bytes_r > cfg_ring_size_bytes_i) ||
                      cap_too_large_r) begin
          err_slot_too_large_n = 1'b1;
          wr_state_n           = WR_ST_DROP_SLOT;
        end else if (slot_drop_now_c) begin
          wr_state_n = WR_ST_DROP_SLOT;
        end else if (slot_can_fit_c) begin
          cap_slot_addr_n        = wr_ptr_r;
          cap_next_wr_ptr_n      = next_wr_ptr_c;
          cap_first_seg_bytes_n  = first_seg_bytes_c;
          cap_second_seg_bytes_n = second_seg_bytes_c;
          cap_wrap_n             = next_wr_wrap_c;
          wr_ptr_n               = next_wr_ptr_c;
          used_alloc_bytes_n     = used_alloc_bytes_n + RING_BYTES_W'(cap_alloc_bytes_r);
          wrap_count_n           = wrap_count_n + COUNTER_W'(next_wr_wrap_c);
          wr_seg_idx_n           = '0;
          wr_seg_addr_n          = wr_ptr_r;
          wr_seg_bytes_rem_n     = first_seg_bytes_c;
          wr_buf_beat_idx_n      = '0;
          wr_burst_beats_n       = '0;
          wr_burst_bytes_n       = '0;
          wr_burst_beat_sent_n   = '0;

          if (first_seg_bytes_c != '0) begin
            wr_state_n = WR_ST_AW;
          end else begin
            wr_state_n = WR_ST_COMMIT;
          end
        end else begin
          err_no_space_n = 1'b1;
          if (cfg_allow_overwrite_i && !rd_busy_o && !desc_fifo_empty_c) begin
            wr_state_n = WR_ST_MAKE_SPACE;
          end else if (cfg_drop_on_no_space_i) begin
            wr_state_n = WR_ST_DROP_SLOT;
          end
        end
      end

      WR_ST_MAKE_SPACE: begin
        if (!rd_busy_o && !desc_fifo_empty_c && !rd_consume_i) begin
          desc_head_ptr_n         = fifo_ptr_next(desc_head_ptr_r);
          desc_count_n            = desc_count_n - 1'b1;
          rd_ptr_n                = ring_addr_add(cfg_ring_base_addr_i, cfg_ring_size_bytes_i, rd_ptr_r,
                                                  desc_head_alloc_bytes_c);
          used_alloc_bytes_n      = used_alloc_bytes_n - RING_BYTES_W'(desc_head_alloc_bytes_c);
          committed_alloc_bytes_n = committed_alloc_bytes_n - RING_BYTES_W'(desc_head_alloc_bytes_c);
          drop_count_n            = drop_count_n + COUNTER_W'(1);
        end
        wr_state_n = WR_ST_CHECK_SPACE;
      end

      WR_ST_AW: begin
        m_axi.awaddr  = wr_seg_addr_r;
        m_axi.awlen   = 8'(wr_cur_burst_beats_c - BURST_LEN_W'(1));
        m_axi.awvalid = 1'b1;

        if (m_axi.awready) begin
          wr_burst_bytes_n      = wr_cur_burst_bytes_c;
          wr_burst_beats_n      = wr_cur_burst_beats_c;
          wr_burst_beat_sent_n  = '0;
          slot_buf_rd_addr_n    = wr_buf_beat_idx_r;
          slot_buf_rd_pending_n = 1'b1;
          wr_state_n            = WR_ST_BUF_RD;
        end
      end

      WR_ST_BUF_RD: begin
        if (slot_buf_rd_valid_r) begin
          wr_state_n = WR_ST_W;
        end
      end

      WR_ST_W: begin
        m_axi.wdata  = wr_wdata_c;
        m_axi.wstrb  = wr_wstrb_c;
        m_axi.wlast  = wr_wlast_c;
        m_axi.wvalid = 1'b1;

        if (m_axi.wready) begin
          if (wr_wlast_c) begin
            wr_state_n = WR_ST_WAIT_B;
          end else begin
            wr_burst_beat_sent_n  = wr_burst_beat_sent_r + BURST_LEN_W'(1);
            slot_buf_rd_addr_n    = wr_buf_beat_idx_r + SLOT_BUF_IDX_W'(wr_burst_beat_sent_r + BURST_LEN_W'(1));
            slot_buf_rd_pending_n = 1'b1;
            wr_state_n            = WR_ST_BUF_RD;
          end
        end
      end

      WR_ST_WAIT_B: begin
        m_axi.bready = 1'b1;

        if (m_axi.bvalid) begin
          if (m_axi.bresp != AXI_RESP_OKAY) begin
            err_axi_wr_resp_n       = 1'b1;
            wr_ptr_n                = cap_slot_addr_r;
            used_alloc_bytes_n      = used_alloc_bytes_n - RING_BYTES_W'(cap_alloc_bytes_r);
            wrap_count_n            = wrap_count_n - COUNTER_W'(cap_wrap_r);
            drop_count_n            = drop_count_n + COUNTER_W'(1);
            wr_state_n              = WR_ST_IDLE;
            cap_beat_count_n        = '0;
            cap_actual_bytes_n      = '0;
            cap_effective_bytes_n   = '0;
            cap_alloc_bytes_n       = '0;
            cap_slot_seq_n          = '0;
            cap_slot_valid_good_n   = 1'b0;
            cap_slot_overflow_err_n = 1'b0;
            cap_proto_err_n         = 1'b0;
            cap_too_large_n         = 1'b0;
            cap_size_mismatch_n     = 1'b0;
            cap_slot_addr_n         = '0;
            cap_next_wr_ptr_n       = '0;
            cap_first_seg_bytes_n   = '0;
            cap_second_seg_bytes_n  = '0;
            cap_wrap_n              = 1'b0;
          end else if ((wr_seg_bytes_rem_r - wr_burst_bytes_r) != '0) begin
            wr_seg_addr_n      = wr_seg_addr_r + AXI_ADDR_W'(wr_burst_bytes_r);
            wr_seg_bytes_rem_n = wr_seg_bytes_rem_r - wr_burst_bytes_r;
            wr_buf_beat_idx_n  = wr_buf_beat_idx_r + SLOT_BUF_IDX_W'(wr_burst_beats_r);
            wr_state_n         = WR_ST_AW;
          end else if ((wr_seg_idx_r == '0) && (cap_second_seg_bytes_r != '0)) begin
            wr_seg_idx_n       = 2'd1;
            wr_seg_addr_n      = cfg_ring_base_addr_i;
            wr_seg_bytes_rem_n = cap_second_seg_bytes_r;
            wr_buf_beat_idx_n  = wr_buf_beat_idx_r + SLOT_BUF_IDX_W'(wr_burst_beats_r);
            wr_state_n         = WR_ST_AW;
          end else begin
            wr_state_n = WR_ST_COMMIT;
          end
        end
      end

      WR_ST_COMMIT: begin
        commit_ptr_n            = cap_next_wr_ptr_r;
        committed_alloc_bytes_n = committed_alloc_bytes_n + RING_BYTES_W'(cap_alloc_bytes_r);
        desc_push_c             = 1'b1;
        desc_push_idx_c         = desc_tail_ptr_r;
        desc_tail_ptr_n         = fifo_ptr_next(desc_tail_ptr_r);
        desc_count_n            = desc_count_n + 1'b1;
        wr_commit_pulse_c       = 1'b1;
        wr_state_n              = WR_ST_IDLE;
        cap_beat_count_n        = '0;
        cap_actual_bytes_n      = '0;
        cap_effective_bytes_n   = '0;
        cap_alloc_bytes_n       = '0;
        cap_slot_seq_n          = '0;
        cap_slot_valid_good_n   = 1'b0;
        cap_slot_overflow_err_n = 1'b0;
        cap_proto_err_n         = 1'b0;
        cap_too_large_n         = 1'b0;
        cap_size_mismatch_n     = 1'b0;
        cap_slot_addr_n         = '0;
        cap_next_wr_ptr_n       = '0;
        cap_first_seg_bytes_n   = '0;
        cap_second_seg_bytes_n  = '0;
        cap_wrap_n              = 1'b0;
      end

      WR_ST_DROP_SLOT: begin
        drop_count_n            = drop_count_n + COUNTER_W'(1);
        wr_state_n              = WR_ST_IDLE;
        cap_beat_count_n        = '0;
        cap_actual_bytes_n      = '0;
        cap_effective_bytes_n   = '0;
        cap_alloc_bytes_n       = '0;
        cap_slot_seq_n          = '0;
        cap_slot_valid_good_n   = 1'b0;
        cap_slot_overflow_err_n = 1'b0;
        cap_proto_err_n         = 1'b0;
        cap_too_large_n         = 1'b0;
        cap_size_mismatch_n     = 1'b0;
        cap_slot_addr_n         = '0;
        cap_next_wr_ptr_n       = '0;
        cap_first_seg_bytes_n   = '0;
        cap_second_seg_bytes_n  = '0;
        cap_wrap_n              = 1'b0;
      end

      default: begin
        wr_state_n = WR_ST_IDLE;
      end
    endcase

    case (rd_state_r)
      RD_ST_IDLE: begin
        if (rd_slot_req_i && !rd_consume_i) begin
          if (!cfg_enable_i || !cfg_ring_ok_c || desc_fifo_empty_c || rd_axis_valid_r) begin
            err_illegal_read_n = 1'b1;
            rd_error_pulse_c   = 1'b1;
          end else begin
            rd_slot_addr_n            = desc_head_addr_c;
            rd_slot_bytes_n           = desc_head_bytes_c;
            rd_slot_alloc_bytes_n     = desc_head_alloc_bytes_c;
            rd_slot_seq_n             = desc_head_seq_c;
            rd_slot_valid_good_meta_n = desc_head_valid_good_c;
            rd_slot_overflow_meta_n   = desc_head_overflow_err_c;
            rd_first_seg_bytes_n      =
                (desc_head_bytes_c <= bytes_to_ring_end(cfg_ring_base_addr_i, cfg_ring_size_bytes_i,
                                                        desc_head_addr_c)) ? desc_head_bytes_c :
                bytes_to_ring_end(cfg_ring_base_addr_i, cfg_ring_size_bytes_i, desc_head_addr_c);
            rd_second_seg_bytes_n     = desc_head_bytes_c -
                ((desc_head_bytes_c <= bytes_to_ring_end(cfg_ring_base_addr_i, cfg_ring_size_bytes_i,
                                                         desc_head_addr_c)) ? desc_head_bytes_c :
                 bytes_to_ring_end(cfg_ring_base_addr_i, cfg_ring_size_bytes_i, desc_head_addr_c));
            rd_seg_idx_n              = '0;
            rd_seg_addr_n             = desc_head_addr_c;
            rd_seg_bytes_rem_n        =
                (desc_head_bytes_c <= bytes_to_ring_end(cfg_ring_base_addr_i, cfg_ring_size_bytes_i,
                                                        desc_head_addr_c)) ? desc_head_bytes_c :
                bytes_to_ring_end(cfg_ring_base_addr_i, cfg_ring_size_bytes_i, desc_head_addr_c);
            rd_total_bytes_rem_n      = desc_head_bytes_c;
            rd_burst_beats_n          = '0;
            rd_burst_bytes_n          = '0;
            rd_burst_beats_rcvd_n     = '0;
            rd_first_beat_pending_n   = 1'b1;
            rd_state_n                = RD_ST_AR;
          end
        end
      end

      RD_ST_AR: begin
        m_axi.araddr  = rd_seg_addr_r;
        m_axi.arlen   = 8'(rd_cur_burst_beats_c - BURST_LEN_W'(1));
        m_axi.arvalid = 1'b1;

        if (m_axi.arready) begin
          rd_burst_bytes_n      = rd_cur_burst_bytes_c;
          rd_burst_beats_n      = rd_cur_burst_beats_c;
          rd_burst_beats_rcvd_n = '0;
          rd_state_n            = RD_ST_R;
        end
      end

      RD_ST_R: begin
        axi_rready_c = !rd_axis_valid_r || m_axis_rd.tready;
        m_axi.rready = axi_rready_c;

        if (m_axi.rvalid && axi_rready_c) begin
          beat_valid_bytes_c = (rd_total_bytes_rem_r >= SLOT_BYTES_W'(AXI_BEAT_BYTES)) ?
                               SLOT_BYTES_W'(AXI_BEAT_BYTES) : rd_total_bytes_rem_r;
          last_beat_c = (rd_total_bytes_rem_r <= SLOT_BYTES_W'(AXI_BEAT_BYTES));
          axis_user_c = '0;
          axis_user_c[RD_TUSER_VALID_GOOD_BIT]          = rd_slot_valid_good_meta_r;
          axis_user_c[RD_TUSER_OVERFLOW_ERR_BIT]        = rd_slot_overflow_meta_r;
          axis_user_c[RD_TUSER_SLOT_LAST_BIT]           = last_beat_c;
          axis_user_c[RD_TUSER_SEQ_LSB +: SLOT_SEQ_W]   = rd_slot_seq_r;
          axis_user_c[RD_TUSER_BYTES_LSB +: SLOT_BYTES_W] = rd_slot_bytes_r;

          if (rd_first_beat_pending_r) begin
            axis_user_c[RD_TUSER_SLOT_FIRST_BIT] = 1'b1;
          end

          if (m_axi.rresp != AXI_RESP_OKAY) begin
            err_axi_rd_resp_n  = 1'b1;
            err_illegal_read_n = 1'b1;
            rd_error_pulse_c   = 1'b1;
            rd_state_n         = RD_ST_IDLE;
            rd_axis_valid_n    = 1'b0;
          end else begin
            rd_axis_data_n          = m_axi.rdata;
            rd_axis_keep_n          = keep_mask_from_bytes(beat_valid_bytes_c);
            rd_axis_user_n          = axis_user_c;
            rd_axis_last_n          = last_beat_c;
            rd_axis_valid_n         = 1'b1;
            rd_total_bytes_rem_n    = rd_total_bytes_rem_r - beat_valid_bytes_c;
            rd_burst_beats_rcvd_n   = rd_burst_beats_rcvd_r + BURST_LEN_W'(1);
            rd_first_beat_pending_n = 1'b0;

            if (rd_burst_beats_rcvd_r == (rd_burst_beats_r - BURST_LEN_W'(1))) begin
              if ((rd_seg_bytes_rem_r - rd_burst_bytes_r) != '0) begin
                rd_seg_addr_n      = rd_seg_addr_r + AXI_ADDR_W'(rd_burst_bytes_r);
                rd_seg_bytes_rem_n = rd_seg_bytes_rem_r - rd_burst_bytes_r;
                rd_state_n         = RD_ST_AR;
              end else if ((rd_seg_idx_r == '0) && (rd_second_seg_bytes_r != '0)) begin
                rd_seg_idx_n       = 2'd1;
                rd_seg_addr_n      = cfg_ring_base_addr_i;
                rd_seg_bytes_rem_n = rd_second_seg_bytes_r;
                rd_state_n         = RD_ST_AR;
              end else begin
                rd_state_n         = RD_ST_DONE;
              end
            end

            if (m_axi.rlast != (rd_burst_beats_rcvd_r == (rd_burst_beats_r - BURST_LEN_W'(1)))) begin
              err_axi_rd_resp_n = 1'b1;
              rd_error_pulse_c  = 1'b1;
              rd_state_n        = RD_ST_IDLE;
              rd_axis_valid_n   = 1'b0;
              rd_axis_last_n    = 1'b0;
              rd_axis_keep_n    = '0;
              rd_axis_user_n    = '0;
            end
          end
        end
      end

      RD_ST_DONE: begin
        if (rd_axis_fire_c && rd_axis_last_r) begin
          rd_done_pulse_c = 1'b1;
          rd_state_n      = RD_ST_IDLE;
        end else if (!rd_axis_valid_r) begin
          rd_done_pulse_c = 1'b1;
          rd_state_n      = RD_ST_IDLE;
        end
      end

      default: begin
        rd_state_n = RD_ST_IDLE;
      end
    endcase
  end

  assign wr_slot_commit_o       = wr_commit_pulse_c;
  assign wr_slot_addr_o         = cap_slot_addr_r;
  assign wr_slot_seq_o          = cap_slot_seq_r;
  assign wr_slot_bytes_o        = cap_effective_bytes_r;
  assign wr_slot_valid_good_o   = cap_slot_valid_good_r;
  assign wr_slot_overflow_err_o = cap_slot_overflow_err_r;
  assign rd_done_o              = rd_done_pulse_c;
  assign rd_error_o             = rd_error_pulse_c;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      wr_state_r                <= WR_ST_IDLE;
      rd_state_r                <= RD_ST_IDLE;
      wr_ptr_r                  <= '0;
      rd_ptr_r                  <= '0;
      commit_ptr_r              <= '0;
      used_alloc_bytes_r        <= '0;
      committed_alloc_bytes_r   <= '0;
      wrap_count_r              <= '0;
      overflow_count_r          <= '0;
      drop_count_r              <= '0;
      desc_head_ptr_r           <= '0;
      desc_tail_ptr_r           <= '0;
      desc_count_r              <= '0;
      cap_beat_count_r          <= '0;
      cap_actual_bytes_r        <= '0;
      cap_effective_bytes_r     <= '0;
      cap_alloc_bytes_r         <= '0;
      cap_slot_seq_r            <= '0;
      cap_slot_valid_good_r     <= 1'b0;
      cap_slot_overflow_err_r   <= 1'b0;
      cap_proto_err_r           <= 1'b0;
      cap_too_large_r           <= 1'b0;
      cap_size_mismatch_r       <= 1'b0;
      cap_slot_addr_r           <= '0;
      cap_next_wr_ptr_r         <= '0;
      cap_first_seg_bytes_r     <= '0;
      cap_second_seg_bytes_r    <= '0;
      cap_wrap_r                <= 1'b0;
      wr_seg_idx_r              <= '0;
      wr_seg_addr_r             <= '0;
      wr_seg_bytes_rem_r        <= '0;
      wr_buf_beat_idx_r         <= '0;
      wr_burst_beats_r          <= '0;
      wr_burst_bytes_r          <= '0;
      wr_burst_beat_sent_r      <= '0;
      rd_slot_addr_r            <= '0;
      rd_slot_bytes_r           <= '0;
      rd_slot_alloc_bytes_r     <= '0;
      rd_slot_seq_r             <= '0;
      rd_slot_valid_good_meta_r <= 1'b0;
      rd_slot_overflow_meta_r   <= 1'b0;
      rd_first_seg_bytes_r      <= '0;
      rd_second_seg_bytes_r     <= '0;
      rd_seg_idx_r              <= '0;
      rd_seg_addr_r             <= '0;
      rd_seg_bytes_rem_r        <= '0;
      rd_total_bytes_rem_r      <= '0;
      rd_burst_beats_r          <= '0;
      rd_burst_bytes_r          <= '0;
      rd_burst_beats_rcvd_r     <= '0;
      rd_first_beat_pending_r   <= 1'b0;
      rd_axis_data_r            <= '0;
      rd_axis_keep_r            <= '0;
      rd_axis_user_r            <= '0;
      rd_axis_last_r            <= 1'b0;
      rd_axis_valid_r           <= 1'b0;
      err_cfg_align_r           <= 1'b0;
      err_no_space_r            <= 1'b0;
      err_slot_proto_r          <= 1'b0;
      err_slot_too_large_r      <= 1'b0;
      err_axi_wr_resp_r         <= 1'b0;
      err_axi_rd_resp_r         <= 1'b0;
      err_illegal_read_r        <= 1'b0;
      slot_buf_rd_addr_r        <= '0;
      slot_buf_rd_pending_r     <= 1'b0;
      slot_buf_rd_valid_r       <= 1'b0;
    end else if (!cfg_enable_i && (wr_state_r == WR_ST_IDLE) && (rd_state_r == RD_ST_IDLE)) begin
      wr_ptr_r                  <= cfg_ring_base_addr_i;
      rd_ptr_r                  <= cfg_ring_base_addr_i;
      commit_ptr_r              <= cfg_ring_base_addr_i;
      used_alloc_bytes_r        <= '0;
      committed_alloc_bytes_r   <= '0;
      desc_head_ptr_r           <= '0;
      desc_tail_ptr_r           <= '0;
      desc_count_r              <= '0;
      cap_beat_count_r          <= '0;
      cap_actual_bytes_r        <= '0;
      cap_effective_bytes_r     <= '0;
      cap_alloc_bytes_r         <= '0;
      cap_slot_seq_r            <= '0;
      cap_slot_valid_good_r     <= 1'b0;
      cap_slot_overflow_err_r   <= 1'b0;
      cap_proto_err_r           <= 1'b0;
      cap_too_large_r           <= 1'b0;
      cap_size_mismatch_r       <= 1'b0;
      cap_slot_addr_r           <= '0;
      cap_next_wr_ptr_r         <= '0;
      cap_first_seg_bytes_r     <= '0;
      cap_second_seg_bytes_r    <= '0;
      cap_wrap_r                <= 1'b0;
      wr_seg_idx_r              <= '0;
      wr_seg_addr_r             <= '0;
      wr_seg_bytes_rem_r        <= '0;
      wr_buf_beat_idx_r         <= '0;
      wr_burst_beats_r          <= '0;
      wr_burst_bytes_r          <= '0;
      wr_burst_beat_sent_r      <= '0;
      rd_slot_addr_r            <= '0;
      rd_slot_bytes_r           <= '0;
      rd_slot_alloc_bytes_r     <= '0;
      rd_slot_seq_r             <= '0;
      rd_slot_valid_good_meta_r <= 1'b0;
      rd_slot_overflow_meta_r   <= 1'b0;
      rd_first_seg_bytes_r      <= '0;
      rd_second_seg_bytes_r     <= '0;
      rd_seg_idx_r              <= '0;
      rd_seg_addr_r             <= '0;
      rd_seg_bytes_rem_r        <= '0;
      rd_total_bytes_rem_r      <= '0;
      rd_burst_beats_r          <= '0;
      rd_burst_bytes_r          <= '0;
      rd_burst_beats_rcvd_r     <= '0;
      rd_first_beat_pending_r   <= 1'b0;
      rd_axis_data_r            <= '0;
      rd_axis_keep_r            <= '0;
      rd_axis_user_r            <= '0;
      rd_axis_last_r            <= 1'b0;
      rd_axis_valid_r           <= 1'b0;
      wr_state_r                <= WR_ST_IDLE;
      rd_state_r                <= RD_ST_IDLE;
      slot_buf_rd_addr_r        <= '0;
      slot_buf_rd_pending_r     <= 1'b0;
      slot_buf_rd_valid_r       <= 1'b0;
    end else begin
      wr_state_r                <= wr_state_n;
      rd_state_r                <= rd_state_n;
      wr_ptr_r                  <= wr_ptr_n;
      rd_ptr_r                  <= rd_ptr_n;
      commit_ptr_r              <= commit_ptr_n;
      used_alloc_bytes_r        <= used_alloc_bytes_n;
      committed_alloc_bytes_r   <= committed_alloc_bytes_n;
      wrap_count_r              <= wrap_count_n;
      overflow_count_r          <= overflow_count_n;
      drop_count_r              <= drop_count_n;
      desc_head_ptr_r           <= desc_head_ptr_n;
      desc_tail_ptr_r           <= desc_tail_ptr_n;
      desc_count_r              <= desc_count_n;
      cap_beat_count_r          <= cap_beat_count_n;
      cap_actual_bytes_r        <= cap_actual_bytes_n;
      cap_effective_bytes_r     <= cap_effective_bytes_n;
      cap_alloc_bytes_r         <= cap_alloc_bytes_n;
      cap_slot_seq_r            <= cap_slot_seq_n;
      cap_slot_valid_good_r     <= cap_slot_valid_good_n;
      cap_slot_overflow_err_r   <= cap_slot_overflow_err_n;
      cap_proto_err_r           <= cap_proto_err_n;
      cap_too_large_r           <= cap_too_large_n;
      cap_size_mismatch_r       <= cap_size_mismatch_n;
      cap_slot_addr_r           <= cap_slot_addr_n;
      cap_next_wr_ptr_r         <= cap_next_wr_ptr_n;
      cap_first_seg_bytes_r     <= cap_first_seg_bytes_n;
      cap_second_seg_bytes_r    <= cap_second_seg_bytes_n;
      cap_wrap_r                <= cap_wrap_n;
      wr_seg_idx_r              <= wr_seg_idx_n;
      wr_seg_addr_r             <= wr_seg_addr_n;
      wr_seg_bytes_rem_r        <= wr_seg_bytes_rem_n;
      wr_buf_beat_idx_r         <= wr_buf_beat_idx_n;
      wr_burst_beats_r          <= wr_burst_beats_n;
      wr_burst_bytes_r          <= wr_burst_bytes_n;
      wr_burst_beat_sent_r      <= wr_burst_beat_sent_n;
      rd_slot_addr_r            <= rd_slot_addr_n;
      rd_slot_bytes_r           <= rd_slot_bytes_n;
      rd_slot_alloc_bytes_r     <= rd_slot_alloc_bytes_n;
      rd_slot_seq_r             <= rd_slot_seq_n;
      rd_slot_valid_good_meta_r <= rd_slot_valid_good_meta_n;
      rd_slot_overflow_meta_r   <= rd_slot_overflow_meta_n;
      rd_first_seg_bytes_r      <= rd_first_seg_bytes_n;
      rd_second_seg_bytes_r     <= rd_second_seg_bytes_n;
      rd_seg_idx_r              <= rd_seg_idx_n;
      rd_seg_addr_r             <= rd_seg_addr_n;
      rd_seg_bytes_rem_r        <= rd_seg_bytes_rem_n;
      rd_total_bytes_rem_r      <= rd_total_bytes_rem_n;
      rd_burst_beats_r          <= rd_burst_beats_n;
      rd_burst_bytes_r          <= rd_burst_bytes_n;
      rd_burst_beats_rcvd_r     <= rd_burst_beats_rcvd_n;
      rd_first_beat_pending_r   <= rd_first_beat_pending_n;
      rd_axis_data_r            <= rd_axis_data_n;
      rd_axis_keep_r            <= rd_axis_keep_n;
      rd_axis_user_r            <= rd_axis_user_n;
      rd_axis_last_r            <= rd_axis_last_n;
      rd_axis_valid_r           <= rd_axis_valid_n;
      err_cfg_align_r           <= err_cfg_align_n;
      err_no_space_r            <= err_no_space_n;
      err_slot_proto_r          <= err_slot_proto_n;
      err_slot_too_large_r      <= err_slot_too_large_n;
      err_axi_wr_resp_r         <= err_axi_wr_resp_n;
      err_axi_rd_resp_r         <= err_axi_rd_resp_n;
      err_illegal_read_r        <= err_illegal_read_n;
      slot_buf_rd_addr_r        <= slot_buf_rd_addr_n;
      slot_buf_rd_pending_r     <= slot_buf_rd_pending_n;
      slot_buf_rd_valid_r       <= slot_buf_rd_pending_r;

      if (desc_push_c) begin
        desc_addr_r[desc_push_idx_c]         <= cap_slot_addr_r;
        desc_bytes_r[desc_push_idx_c]        <= cap_effective_bytes_r;
        desc_alloc_bytes_r[desc_push_idx_c]  <= cap_alloc_bytes_r;
        desc_seq_r[desc_push_idx_c]          <= cap_slot_seq_r;
        desc_valid_good_r[desc_push_idx_c]   <= cap_slot_valid_good_r;
        desc_overflow_err_r[desc_push_idx_c] <= cap_slot_overflow_err_r;
      end
    end
  end

  if (1) begin : g_static_checks
    `DDR_RING_STATIC_ASSERT(AXIS_DATA_W > 0, "AXIS stream width must be greater than zero")
    `DDR_RING_STATIC_ASSERT((AXIS_DATA_W % 8) == 0, "AXIS stream width must be byte aligned")
    `DDR_RING_STATIC_ASSERT((AXI_DATA_W % 8) == 0, "AXI data width must be byte aligned")
    `DDR_RING_STATIC_ASSERT(CFG_AXI_ADDR_W == AXI_ADDR_W,
                            "CFG_AXI_ADDR_W must match AXI interface address width")
    `DDR_RING_STATIC_ASSERT($bits(s_axis_slot.tdata) == AXIS_DATA_W,
                            "s_axis_slot.tdata width must match AXIS_DATA_W")
    `DDR_RING_STATIC_ASSERT($bits(s_axis_slot.tkeep) == AXIS_KEEP_W,
                            "s_axis_slot.tkeep width must match AXIS_KEEP_W")
    `DDR_RING_STATIC_ASSERT($bits(s_axis_slot.tuser) == AXIS_USER_W,
                            "s_axis_slot.tuser width must match AXIS_USER_W")
    `DDR_RING_STATIC_ASSERT($bits(m_axi.awaddr) == AXI_ADDR_W,
                            "m_axi.awaddr width must match AXI_ADDR_W")
    `DDR_RING_STATIC_ASSERT($bits(m_axi.wdata) == AXI_DATA_W,
                            "m_axi.wdata width must match AXI_DATA_W")
    `DDR_RING_STATIC_ASSERT($bits(m_axi.wstrb) == AXI_STRB_W,
                            "m_axi.wstrb width must match AXI_STRB_W")
    `DDR_RING_STATIC_ASSERT($bits(m_axis_rd.tdata) == RD_AXIS_DATA_W,
                            "m_axis_rd.tdata width must match RD_AXIS_DATA_W")
    `DDR_RING_STATIC_ASSERT($bits(m_axis_rd.tkeep) == RD_AXIS_KEEP_W,
                            "m_axis_rd.tkeep width must match RD_AXIS_KEEP_W")
    `DDR_RING_STATIC_ASSERT($bits(m_axis_rd.tuser) == RD_AXIS_USER_W,
                            "m_axis_rd.tuser width must match RD_AXIS_USER_W")
    `DDR_RING_STATIC_ASSERT(AXIS_DATA_W == AXI_DATA_W,
                            "This revision requires AXIS and AXI write widths to match")
    `DDR_RING_STATIC_ASSERT(RD_AXIS_DATA_W == AXI_DATA_W,
                            "Read AXIS width must match AXI data width")
    `DDR_RING_STATIC_ASSERT(AXIS_KEEP_W == AXI_STRB_W,
                            "AXIS keep width must match AXI strobe width")
    `DDR_RING_STATIC_ASSERT(RD_AXIS_KEEP_W == AXI_STRB_W,
                            "Read AXIS keep width must match AXI strobe width")
    `DDR_RING_STATIC_ASSERT(MAX_BURST_LEN >= 1, "MAX_BURST_LEN must be at least one")
    `DDR_RING_STATIC_ASSERT(MAX_BURST_LEN <= 256, "MAX_BURST_LEN must not exceed AXI4 limit")
    `DDR_RING_STATIC_ASSERT(SLOT_BUFFER_BYTES >= AXI_BEAT_BYTES,
                            "SLOT_BUFFER_BYTES must be at least one AXI beat")
    `DDR_RING_STATIC_ASSERT(DESC_FIFO_DEPTH >= 2, "DESC_FIFO_DEPTH must be at least two")
    `DDR_RING_STATIC_ASSERT(is_pow2_u(AXI_BEAT_BYTES), "AXI beat bytes must be power of two")
    `DDR_RING_STATIC_ASSERT(is_pow2_u(ADDR_ALIGN_BYTES), "ADDR_ALIGN_BYTES must be power of two")
    `DDR_RING_STATIC_ASSERT(ADDR_ALIGN_BYTES >= AXI_BEAT_BYTES,
                            "ADDR_ALIGN_BYTES must be >= AXI beat bytes")
    `DDR_RING_STATIC_ASSERT((ADDR_ALIGN_BYTES % AXI_BEAT_BYTES) == 0,
                            "ADDR_ALIGN_BYTES must be AXI beat aligned")
    `DDR_RING_STATIC_ASSERT((RD_TUSER_SEQ_LSB + SLOT_SEQ_W) <= RD_AXIS_USER_W,
                            "RD TUSER seq field out of range")
    `DDR_RING_STATIC_ASSERT((RD_TUSER_BYTES_LSB + SLOT_BYTES_W) <= RD_AXIS_USER_W,
                            "RD TUSER bytes field out of range")
    `DDR_RING_STATIC_ASSERT(RD_TUSER_SLOT_FIRST_BIT < RD_AXIS_USER_W,
                            "RD_TUSER_SLOT_FIRST_BIT out of range")
    `DDR_RING_STATIC_ASSERT(RD_TUSER_SLOT_LAST_BIT < RD_AXIS_USER_W,
                            "RD_TUSER_SLOT_LAST_BIT out of range")
    `DDR_RING_STATIC_ASSERT(RD_TUSER_VALID_GOOD_BIT < RD_AXIS_USER_W,
                            "RD_TUSER_VALID_GOOD_BIT out of range")
    `DDR_RING_STATIC_ASSERT(RD_TUSER_OVERFLOW_ERR_BIT < RD_AXIS_USER_W,
                            "RD_TUSER_OVERFLOW_ERR_BIT out of range")
  end

endmodule