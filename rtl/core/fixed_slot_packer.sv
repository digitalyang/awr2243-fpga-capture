`include "slot_packer_macros.svh"

// Captures one AWR payload, then replays it as a fixed-size slot:
//   12B RX headers + 1024*12B sample area + 9B CQ tail + 64B alignment padding.
// Missing samples are zero-filled and the legacy synthetic slot header is removed.
module fixed_slot_packer #(
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

    // Drop packets already marked invalid by the CSI packet extractor.
    input logic cfg_drop_invalid_pkt_i,

    // Upstream packet sideband.
    input logic                      pkt_start_i,
    input logic                      pkt_done_i,
    input logic [PKT_BYTE_CNT_W-1:0] pkt_bytes_i,
    input logic [     PKT_SEQ_W-1:0] pkt_seq_i,
    input logic                      pkt_crc_err_i,
    input logic                      pkt_ecc_err_i,
    input logic                      pkt_trunc_err_i,
    input logic                      pkt_valid_good_i,

    // Downstream slot sideband.
    output logic                    slot_start_o,
    output logic                    slot_done_o,
    output logic [SLOT_BYTES_W-1:0] slot_bytes_o,
    output logic [   PKT_SEQ_W-1:0] slot_seq_o,
    output logic                    slot_valid_good_o,
    output logic                    slot_overflow_err_o,

    axis_stream_if.slave  s_axis,
    axis_stream_if.master m_axis
);

  import slot_packer_pkg::*;

  // ================================================================
  //  Layout constants
  // ================================================================
  localparam int unsigned AXIS_KEEP_W = AXIS_DATA_W / 8;
  localparam int unsigned AXIS_BEAT_BYTES = AXIS_DATA_W / 8;
  localparam int unsigned BEAT_BYTE_CNT_W = clog2_safe(AXIS_BEAT_BYTES + 1);
  localparam int unsigned CAP_IDX_W = clog2_safe(ceil_div_u(
      HEADER_BYTES + SAMPLE_SLOT_NUM * SAMPLE_UNIT_BYTES + CQ_AREA_BYTES,
      AXIS_BEAT_BYTES));

  localparam int unsigned SAMPLE_AREA_BYTES = SAMPLE_SLOT_NUM * SAMPLE_UNIT_BYTES;
  localparam int unsigned SAMPLE_CNT_W = clog2_safe(SAMPLE_SLOT_NUM + 1);

  localparam int unsigned SLOT_TOTAL_UNALIGNED = HEADER_BYTES + SAMPLE_AREA_BYTES + CQ_AREA_BYTES;
  localparam int unsigned SLOT_TOTAL_ALIGNED = align_up_u(SLOT_TOTAL_UNALIGNED, ALIGN_BYTES);
  localparam int unsigned SLOT_TOTAL_BEATS = SLOT_TOTAL_ALIGNED / AXIS_BEAT_BYTES;

  localparam int unsigned CAP_BUF_BYTES = SLOT_TOTAL_UNALIGNED;
  localparam int unsigned CAP_BUF_BEATS = ceil_div_u(CAP_BUF_BYTES, AXIS_BEAT_BYTES);
  localparam int unsigned BEAT_CNT_W = clog2_safe(max_u(SLOT_TOTAL_BEATS, CAP_BUF_BEATS) + 1);

  // ================================================================
  //  Type declarations
  // ================================================================
  typedef enum logic [1:0] {
    ST_IDLE,
    ST_CAPTURE,
    ST_OUTPUT
  } packer_state_e;

  // ================================================================
  //  Registers
  // ================================================================
  packer_state_e                       state_r;
  packer_state_e                       state_n;

  logic          [     BEAT_CNT_W-1:0] out_beat_cnt_r;
  logic          [     BEAT_CNT_W-1:0] out_beat_cnt_n;
  logic          [     BEAT_CNT_W-1:0] cap_beat_cnt_r;
  logic          [     BEAT_CNT_W-1:0] cap_beat_cnt_n;

  logic          [      PKT_SEQ_W-1:0] cap_pkt_seq_r;
  logic          [      PKT_SEQ_W-1:0] cap_pkt_seq_n;
  logic          [ PKT_BYTE_CNT_W-1:0] cap_pkt_bytes_r;
  logic          [ PKT_BYTE_CNT_W-1:0] cap_pkt_bytes_n;

  logic                                cap_pkt_crc_err_r;
  logic                                cap_pkt_crc_err_n;
  logic                                cap_pkt_ecc_err_r;
  logic                                cap_pkt_ecc_err_n;
  logic                                cap_pkt_trunc_err_r;
  logic                                cap_pkt_trunc_err_n;
  logic                                cap_pkt_valid_good_r;
  logic                                cap_pkt_valid_good_n;
  logic                                cap_overflow_r;
  logic                                cap_overflow_n;

  // Register array that holds the original packet bytes until the full slot is replayed.
  logic          [    AXIS_DATA_W-1:0] cap_buf_data_r [0:CAP_BUF_BEATS-1];

  // ================================================================
  //  Combinational wires
  // ================================================================
  logic                                s_fire_c;
  logic                                m_fire_c;
  logic          [BEAT_BYTE_CNT_W-1:0] keep_bytes_c;
  logic          [    AXIS_DATA_W-1:0] masked_data_c;
  logic                                should_drop_c;
  logic                                is_slot_last_beat_c;

  logic          [ PKT_BYTE_CNT_W-1:0] cap_payload_bytes_capped_c;
  logic          [ PKT_BYTE_CNT_W-1:0] hdr_valid_bytes_c;
  logic          [ PKT_BYTE_CNT_W-1:0] sample_input_bytes_c;
  logic          [ PKT_BYTE_CNT_W-1:0] cq_input_ofs_c;
  logic          [ PKT_BYTE_CNT_W-1:0] cq_input_bytes_c;
  logic          [   SAMPLE_CNT_W-1:0] actual_sample_cnt_c;

  logic                                cap_buf_wr_en_c;
  logic          [      CAP_IDX_W-1:0] cap_buf_wr_idx_c;
  logic          [    AXIS_DATA_W-1:0] cap_buf_wr_data_c;

  logic          [    AXIS_DATA_W-1:0] out_data_c;

  // ================================================================
  //  Functions
  // ================================================================
  function automatic logic [BEAT_BYTE_CNT_W-1:0] count_keep_bytes(
      input logic [AXIS_KEEP_W-1:0] keep);
    logic        [BEAT_BYTE_CNT_W-1:0] sum_c;
    int unsigned                       idx;
    begin
      sum_c = '0;
      for (idx = 0; idx < AXIS_KEEP_W; idx++) begin
        sum_c = sum_c + BEAT_BYTE_CNT_W'(keep[idx]);
      end
      return sum_c;
    end
  endfunction

  function automatic logic [AXIS_DATA_W-1:0] mask_data_with_keep(
      input logic [AXIS_DATA_W-1:0] data,
      input logic [AXIS_KEEP_W-1:0] keep);
    logic        [AXIS_DATA_W-1:0] result;
    int unsigned                   idx;
    begin
      result = '0;
      for (idx = 0; idx < AXIS_KEEP_W; idx++) begin
        if (keep[idx]) begin
          result[idx*8+:8] = data[idx*8+:8];
        end
      end
      return result;
    end
  endfunction

  function automatic logic [7:0] capture_byte_at(input int unsigned byte_idx);
    int unsigned beat_idx;
    int unsigned lane_idx;
    begin
      capture_byte_at = '0;

      if (byte_idx < CAP_BUF_BYTES) begin
        beat_idx = byte_idx / AXIS_BEAT_BYTES;
        lane_idx = byte_idx % AXIS_BEAT_BYTES;
        capture_byte_at = cap_buf_data_r[beat_idx][lane_idx*8+:8];
      end
    end
  endfunction

  function automatic logic [7:0] slot_byte_at(input int unsigned byte_idx);
    int unsigned sample_byte_idx;
    int unsigned cq_byte_idx;
    int unsigned cq_input_idx;
    begin
      slot_byte_at = '0;
      cq_input_idx = 0;

      if (byte_idx < HEADER_BYTES) begin
        if (byte_idx < hdr_valid_bytes_c) begin
          slot_byte_at = capture_byte_at(byte_idx);
        end
      end else if (byte_idx < (HEADER_BYTES + SAMPLE_AREA_BYTES)) begin
        sample_byte_idx = byte_idx - HEADER_BYTES;
        if (sample_byte_idx < sample_input_bytes_c) begin
          slot_byte_at = capture_byte_at(HEADER_BYTES + sample_byte_idx);
        end
      end else if (byte_idx < SLOT_TOTAL_UNALIGNED) begin
        cq_byte_idx = byte_idx - HEADER_BYTES - SAMPLE_AREA_BYTES;
        if (cq_byte_idx < cq_input_bytes_c) begin
          cq_input_idx = int'(cq_input_ofs_c) + cq_byte_idx;
          slot_byte_at = capture_byte_at(cq_input_idx);
        end
      end
    end
  endfunction

  // ================================================================
  //  Continuous assignments
  // ================================================================
  assign s_fire_c = s_axis.tvalid && s_axis.tready;
  assign m_fire_c = m_axis.tvalid && m_axis.tready;

  assign keep_bytes_c = count_keep_bytes(s_axis.tkeep);
  assign masked_data_c = mask_data_with_keep(s_axis.tdata, s_axis.tkeep);

  assign should_drop_c = !pkt_valid_good_i && cfg_drop_invalid_pkt_i;
  assign is_slot_last_beat_c = (out_beat_cnt_r == BEAT_CNT_W'(SLOT_TOTAL_BEATS - 1));

  assign cap_payload_bytes_capped_c =
      (cap_pkt_bytes_r >= PKT_BYTE_CNT_W'(CAP_BUF_BYTES))
          ? PKT_BYTE_CNT_W'(CAP_BUF_BYTES)
          : cap_pkt_bytes_r;

  assign hdr_valid_bytes_c =
      (cap_payload_bytes_capped_c >= PKT_BYTE_CNT_W'(HEADER_BYTES))
          ? PKT_BYTE_CNT_W'(HEADER_BYTES)
          : cap_payload_bytes_capped_c;

  assign actual_sample_cnt_c = SAMPLE_CNT_W'(sample_input_bytes_c / SAMPLE_UNIT_BYTES);

  assign slot_start_o        = m_axis.tvalid && (out_beat_cnt_r == '0);
  assign slot_done_o         = m_axis.tvalid && is_slot_last_beat_c;
  assign slot_bytes_o        = SLOT_BYTES_W'(SLOT_TOTAL_ALIGNED);
  assign slot_seq_o          = cap_pkt_seq_r;
  assign slot_valid_good_o   = cap_pkt_valid_good_r;
  assign slot_overflow_err_o = cap_overflow_r;

  // ================================================================
  //  Decode the captured payload into raw header / sample / CQ regions.
  //  Valid packets carry CQ immediately after the actual sample payload.
  //  Truncated packets are assumed to end somewhere inside the sample area.
  // ================================================================
  always_comb begin
    logic [PKT_BYTE_CNT_W-1:0] data_after_hdr_c;
    logic [PKT_BYTE_CNT_W-1:0] sample_candidate_c;
    logic [PKT_BYTE_CNT_W-1:0] cq_candidate_c;

    data_after_hdr_c    = '0;
    sample_candidate_c  = '0;
    cq_candidate_c      = '0;

    sample_input_bytes_c = '0;
    cq_input_ofs_c       = PKT_BYTE_CNT_W'(HEADER_BYTES);
    cq_input_bytes_c     = '0;

    if (cap_payload_bytes_capped_c > PKT_BYTE_CNT_W'(HEADER_BYTES)) begin
      data_after_hdr_c = cap_payload_bytes_capped_c - PKT_BYTE_CNT_W'(HEADER_BYTES);

      if (cap_pkt_trunc_err_r) begin
        sample_input_bytes_c =
            (data_after_hdr_c >= PKT_BYTE_CNT_W'(SAMPLE_AREA_BYTES))
                ? PKT_BYTE_CNT_W'(SAMPLE_AREA_BYTES)
                : data_after_hdr_c;

        cq_input_ofs_c = PKT_BYTE_CNT_W'(HEADER_BYTES + SAMPLE_AREA_BYTES);
        if (cap_payload_bytes_capped_c > PKT_BYTE_CNT_W'(HEADER_BYTES + SAMPLE_AREA_BYTES)) begin
          cq_candidate_c = cap_payload_bytes_capped_c - PKT_BYTE_CNT_W'(HEADER_BYTES + SAMPLE_AREA_BYTES);
          cq_input_bytes_c =
              (cq_candidate_c >= PKT_BYTE_CNT_W'(CQ_AREA_BYTES))
                  ? PKT_BYTE_CNT_W'(CQ_AREA_BYTES)
                  : cq_candidate_c;
        end
      end else begin
        if (data_after_hdr_c <= PKT_BYTE_CNT_W'(CQ_AREA_BYTES)) begin
          cq_input_bytes_c = data_after_hdr_c;
        end else begin
          sample_candidate_c = data_after_hdr_c - PKT_BYTE_CNT_W'(CQ_AREA_BYTES);
          sample_input_bytes_c =
              (sample_candidate_c >= PKT_BYTE_CNT_W'(SAMPLE_AREA_BYTES))
                  ? PKT_BYTE_CNT_W'(SAMPLE_AREA_BYTES)
                  : sample_candidate_c;

          cq_input_ofs_c = PKT_BYTE_CNT_W'(HEADER_BYTES) + sample_input_bytes_c;
          cq_candidate_c = cap_payload_bytes_capped_c - cq_input_ofs_c;
          cq_input_bytes_c =
              (cq_candidate_c >= PKT_BYTE_CNT_W'(CQ_AREA_BYTES))
                  ? PKT_BYTE_CNT_W'(CQ_AREA_BYTES)
                  : cq_candidate_c;
        end
      end
    end
  end

  // Assemble the current output beat from the captured packet bytes and zero padding.
  always_comb begin
    int unsigned byte_idx;
    int unsigned lane_idx;

    out_data_c = '0;
    byte_idx   = int'(out_beat_cnt_r) * AXIS_BEAT_BYTES;

    for (lane_idx = 0; lane_idx < AXIS_BEAT_BYTES; lane_idx++) begin
      out_data_c[lane_idx*8+:8] = slot_byte_at(byte_idx + lane_idx);
    end
  end

  // ================================================================
  //  Main combinational FSM
  // ================================================================
  always_comb begin
    state_n              = state_r;
    out_beat_cnt_n       = out_beat_cnt_r;
    cap_beat_cnt_n       = cap_beat_cnt_r;
    cap_pkt_seq_n        = cap_pkt_seq_r;
    cap_pkt_bytes_n      = cap_pkt_bytes_r;
    cap_pkt_crc_err_n    = cap_pkt_crc_err_r;
    cap_pkt_ecc_err_n    = cap_pkt_ecc_err_r;
    cap_pkt_trunc_err_n  = cap_pkt_trunc_err_r;
    cap_pkt_valid_good_n = cap_pkt_valid_good_r;
    cap_overflow_n       = cap_overflow_r;

    s_axis.tready        = 1'b0;

    m_axis.tdata         = '0;
    m_axis.tkeep         = '0;
    m_axis.tvalid        = 1'b0;
    m_axis.tlast         = 1'b0;
    m_axis.tuser         = '0;

    cap_buf_wr_en_c      = 1'b0;
    cap_buf_wr_idx_c     = '0;
    cap_buf_wr_data_c    = '0;

    case (state_r)
      ST_IDLE: begin
        s_axis.tready = 1'b1;

        if (s_fire_c) begin
          cap_buf_wr_en_c   = 1'b1;
          cap_buf_wr_idx_c  = '0;
          cap_buf_wr_data_c = masked_data_c;

          cap_beat_cnt_n       = BEAT_CNT_W'(1);
          cap_pkt_seq_n        = pkt_seq_i;
          cap_pkt_bytes_n      = '0;
          cap_pkt_crc_err_n    = 1'b0;
          cap_pkt_ecc_err_n    = 1'b0;
          cap_pkt_trunc_err_n  = 1'b0;
          cap_pkt_valid_good_n = 1'b0;
          cap_overflow_n       = 1'b0;

          if (pkt_done_i) begin
            cap_pkt_bytes_n      = pkt_bytes_i;
            cap_pkt_crc_err_n    = pkt_crc_err_i;
            cap_pkt_ecc_err_n    = pkt_ecc_err_i;
            cap_pkt_trunc_err_n  = pkt_trunc_err_i;
            cap_pkt_valid_good_n = pkt_valid_good_i;
            cap_overflow_n       = (pkt_bytes_i > PKT_BYTE_CNT_W'(CAP_BUF_BYTES));

            if (should_drop_c) begin
              state_n        = ST_IDLE;
              cap_beat_cnt_n = '0;
            end else begin
              state_n        = ST_OUTPUT;
              out_beat_cnt_n = '0;
            end
          end else begin
            state_n = ST_CAPTURE;
          end
        end
      end

      ST_CAPTURE: begin
        s_axis.tready = 1'b1;

        if (s_fire_c) begin
          if (cap_beat_cnt_r < BEAT_CNT_W'(CAP_BUF_BEATS)) begin
            cap_buf_wr_en_c   = 1'b1;
            cap_buf_wr_idx_c  = CAP_IDX_W'(cap_beat_cnt_r);
            cap_buf_wr_data_c = masked_data_c;
            cap_beat_cnt_n    = cap_beat_cnt_r + BEAT_CNT_W'(1);
          end else begin
            cap_overflow_n = 1'b1;
          end

          if (pkt_done_i) begin
            cap_pkt_bytes_n      = pkt_bytes_i;
            cap_pkt_crc_err_n    = pkt_crc_err_i;
            cap_pkt_ecc_err_n    = pkt_ecc_err_i;
            cap_pkt_trunc_err_n  = pkt_trunc_err_i;
            cap_pkt_valid_good_n = pkt_valid_good_i;

            if (pkt_bytes_i > PKT_BYTE_CNT_W'(CAP_BUF_BYTES)) begin
              cap_overflow_n = 1'b1;
            end

            if (should_drop_c) begin
              state_n        = ST_IDLE;
              cap_beat_cnt_n = '0;
            end else begin
              state_n        = ST_OUTPUT;
              out_beat_cnt_n = '0;
            end
          end
        end
      end

      ST_OUTPUT: begin
        m_axis.tdata  = out_data_c;
        m_axis.tkeep  = {AXIS_KEEP_W{1'b1}};
        m_axis.tvalid = 1'b1;
        m_axis.tlast  = is_slot_last_beat_c;

        if (m_fire_c) begin
          if (is_slot_last_beat_c) begin
            state_n        = ST_IDLE;
            out_beat_cnt_n = '0;
            cap_beat_cnt_n = '0;
          end else begin
            out_beat_cnt_n = out_beat_cnt_r + BEAT_CNT_W'(1);
          end
        end
      end

      default: begin
        state_n = ST_IDLE;
      end
    endcase
  end

  // ================================================================
  //  Register update
  // ================================================================
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_r              <= ST_IDLE;
      out_beat_cnt_r       <= '0;
      cap_beat_cnt_r       <= '0;
      cap_pkt_seq_r        <= '0;
      cap_pkt_bytes_r      <= '0;
      cap_pkt_crc_err_r    <= 1'b0;
      cap_pkt_ecc_err_r    <= 1'b0;
      cap_pkt_trunc_err_r  <= 1'b0;
      cap_pkt_valid_good_r <= 1'b0;
      cap_overflow_r       <= 1'b0;
    end else begin
      state_r              <= state_n;
      out_beat_cnt_r       <= out_beat_cnt_n;
      cap_beat_cnt_r       <= cap_beat_cnt_n;
      cap_pkt_seq_r        <= cap_pkt_seq_n;
      cap_pkt_bytes_r      <= cap_pkt_bytes_n;
      cap_pkt_crc_err_r    <= cap_pkt_crc_err_n;
      cap_pkt_ecc_err_r    <= cap_pkt_ecc_err_n;
      cap_pkt_trunc_err_r  <= cap_pkt_trunc_err_n;
      cap_pkt_valid_good_r <= cap_pkt_valid_good_n;
      cap_overflow_r       <= cap_overflow_n;

      if (cap_buf_wr_en_c) begin
        cap_buf_data_r[cap_buf_wr_idx_c] <= cap_buf_wr_data_c;
      end
    end
  end

  // ================================================================
  //  Static assertions
  // ================================================================
  if (1) begin : g_static_checks
    `SLOT_PKR_STATIC_ASSERT(AXIS_DATA_W > 0, "AXIS_DATA_W must be greater than zero")
    `SLOT_PKR_STATIC_ASSERT((AXIS_DATA_W % 8) == 0, "AXIS_DATA_W must be byte aligned")
    `SLOT_PKR_STATIC_ASSERT(is_pow2_u(AXIS_BEAT_BYTES), "AXIS_BEAT_BYTES must be a power of two")

    `SLOT_PKR_STATIC_ASSERT(HEADER_BYTES > 0, "HEADER_BYTES must be greater than zero")
    `SLOT_PKR_STATIC_ASSERT(SAMPLE_SLOT_NUM > 0, "SAMPLE_SLOT_NUM must be greater than zero")
    `SLOT_PKR_STATIC_ASSERT(SAMPLE_UNIT_BYTES > 0, "SAMPLE_UNIT_BYTES must be greater than zero")
    `SLOT_PKR_STATIC_ASSERT(CQ_AREA_BYTES > 0, "CQ_AREA_BYTES must be greater than zero")

    `SLOT_PKR_STATIC_ASSERT(is_pow2_u(ALIGN_BYTES), "ALIGN_BYTES must be a power of two")
    `SLOT_PKR_STATIC_ASSERT(ALIGN_BYTES >= AXIS_BEAT_BYTES,
                            "ALIGN_BYTES must be >= AXIS_BEAT_BYTES")
    `SLOT_PKR_STATIC_ASSERT((ALIGN_BYTES % AXIS_BEAT_BYTES) == 0,
                            "ALIGN_BYTES must be a multiple of AXIS_BEAT_BYTES")
    `SLOT_PKR_STATIC_ASSERT((SLOT_TOTAL_ALIGNED % AXIS_BEAT_BYTES) == 0,
                            "Aligned slot size must be a multiple of AXIS_BEAT_BYTES")

    `SLOT_PKR_STATIC_ASSERT(SLOT_TOTAL_BEATS > 0, "SLOT_TOTAL_BEATS must be greater than zero")
    `SLOT_PKR_STATIC_ASSERT(SLOT_TOTAL_ALIGNED <= (1 << SLOT_BYTES_W),
                            "SLOT_BYTES_W too narrow for SLOT_TOTAL_ALIGNED")

    `SLOT_PKR_STATIC_ASSERT($bits(m_axis.tdata) == AXIS_DATA_W,
                            "Input and output AXIS data widths must match")
    `SLOT_PKR_STATIC_ASSERT($bits(m_axis.tkeep) == AXIS_KEEP_W,
                            "Input and output AXIS keep widths must match")
  end

endmodule
