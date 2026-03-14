`include "slot_packer_macros.svh"

// Vivado-friendly rewrite:
// - Writes the FINAL fixed slot image directly into beat-wide RAM
// - Avoids random byte reads from a large packet buffer
// - Separates memory write/read from async-reset control logic
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
            HEADER_BYTES + SAMPLE_SLOT_NUM * SAMPLE_UNIT_BYTES + CQ_AREA_BYTES, ALIGN_BYTES
        ) + 1
    )
) (
    input  logic clk_i,
    input  logic rst_ni,

    input  logic                      cfg_drop_invalid_pkt_i,

    input  logic                      pkt_start_i,
    input  logic                      pkt_done_i,
    input  logic [PKT_BYTE_CNT_W-1:0] pkt_bytes_i,
    input  logic [PKT_SEQ_W-1:0]      pkt_seq_i,
    input  logic                      pkt_crc_err_i,
    input  logic                      pkt_ecc_err_i,
    input  logic                      pkt_trunc_err_i,
    input  logic                      pkt_valid_good_i,

    output logic                      slot_start_o,
    output logic                      slot_done_o,
    output logic [SLOT_BYTES_W-1:0]   slot_bytes_o,
    output logic [PKT_SEQ_W-1:0]      slot_seq_o,
    output logic                      slot_valid_good_o,
    output logic                      slot_overflow_err_o,

    axis_stream_if.slave  s_axis,
    axis_stream_if.master m_axis
);

  import slot_packer_pkg::*;

  localparam int unsigned AXIS_KEEP_W       = AXIS_DATA_W / 8;
  localparam int unsigned AXIS_BEAT_BYTES   = AXIS_DATA_W / 8;
  localparam int unsigned SAMPLE_AREA_BYTES = SAMPLE_SLOT_NUM * SAMPLE_UNIT_BYTES;
  localparam int unsigned SLOT_TOTAL_RAW    = HEADER_BYTES + SAMPLE_AREA_BYTES + CQ_AREA_BYTES;
  localparam int unsigned SLOT_TOTAL_ALIGN  = align_up_u(SLOT_TOTAL_RAW, ALIGN_BYTES);
  localparam int unsigned SLOT_TOTAL_BEATS  = SLOT_TOTAL_ALIGN / AXIS_BEAT_BYTES;

  localparam int unsigned MEM_BEAT_W        = clog2_safe(SLOT_TOTAL_BEATS);
  localparam int unsigned CQ_CNT_W          = clog2_safe(CQ_AREA_BYTES + 1);

  localparam int unsigned CQ_START_BYTE     = HEADER_BYTES + SAMPLE_AREA_BYTES;
  localparam int unsigned CQ_START_BEAT     = CQ_START_BYTE / AXIS_BEAT_BYTES;

  typedef enum logic [3:0] {
    ST_IDLE,
    ST_CAPTURE,
    ST_CAP_FLUSH,
    ST_ZERO_MID,
    ST_CQ_WRITE,
    ST_CQ_FLUSH,
    ST_ZERO_TAIL,
    ST_OUT_READ,
    ST_OUT_SEND
  } packer_state_e;

  // --------------------------------------------------------------------------
  // Control/state registers
  // --------------------------------------------------------------------------
  packer_state_e state_r, state_n;

  logic [PKT_SEQ_W-1:0]      cap_pkt_seq_r,        cap_pkt_seq_n;
  logic [PKT_BYTE_CNT_W-1:0] cap_pkt_bytes_r,      cap_pkt_bytes_n;
  logic                      cap_pkt_crc_err_r,    cap_pkt_crc_err_n;
  logic                      cap_pkt_ecc_err_r,    cap_pkt_ecc_err_n;
  logic                      cap_pkt_trunc_err_r,  cap_pkt_trunc_err_n;
  logic                      cap_pkt_valid_good_r, cap_pkt_valid_good_n;
  logic                      cap_overflow_r,       cap_overflow_n;

  logic [31:0]               wr_abs_pos_r,         wr_abs_pos_n;
  logic [MEM_BEAT_W-1:0]     zero_fill_idx_r,      zero_fill_idx_n;
  logic [MEM_BEAT_W-1:0]     out_idx_r,            out_idx_n;

  logic                      wr_shadow_valid_r,    wr_shadow_valid_n;
  logic [MEM_BEAT_W-1:0]     wr_shadow_idx_r,      wr_shadow_idx_n;
  logic [AXIS_DATA_W-1:0]    wr_shadow_data_r,     wr_shadow_data_n;

  logic [CQ_CNT_W-1:0]       tail_count_r,         tail_count_n;
  logic [CQ_CNT_W-1:0]       cq_count_r,           cq_count_n;

  logic [7:0]                tail_buf_r [0:CQ_AREA_BYTES-1];
  logic [7:0]                tail_buf_n [0:CQ_AREA_BYTES-1];
  logic [7:0]                cq_buf_r   [0:CQ_AREA_BYTES-1];
  logic [7:0]                cq_buf_n   [0:CQ_AREA_BYTES-1];

  // --------------------------------------------------------------------------
  // Final slot RAM (beat-wide)
  // --------------------------------------------------------------------------
  (* ram_style = "block" *) logic [AXIS_DATA_W-1:0] slot_mem_r [0:SLOT_TOTAL_BEATS-1];

  logic                   mem_wr_en_c;
  logic [MEM_BEAT_W-1:0]  mem_wr_addr_c;
  logic [AXIS_DATA_W-1:0] mem_wr_data_c;

  logic                   mem_rd_en_c;
  logic [MEM_BEAT_W-1:0]  mem_rd_addr_c;
  logic [AXIS_DATA_W-1:0] mem_rd_data_r;

  // --------------------------------------------------------------------------
  // Combinational helpers
  // --------------------------------------------------------------------------
  logic s_fire_c;
  logic m_fire_c;
  logic should_drop_c;
  logic is_last_out_beat_c;

  integer i;

  function automatic int unsigned ceil_div_int(input int unsigned a, input int unsigned b);
    begin
      ceil_div_int = (a + b - 1) / b;
    end
  endfunction

  task automatic append_byte_to_shadow(
      input  logic [7:0] in_byte,
      inout  logic                   shadow_valid,
      inout  logic [MEM_BEAT_W-1:0]  shadow_idx,
      inout  logic [AXIS_DATA_W-1:0] shadow_data,
      inout  logic [31:0]            abs_pos,
      inout  logic                   wr_en,
      inout  logic [MEM_BEAT_W-1:0]  wr_addr,
      inout  logic [AXIS_DATA_W-1:0] wr_data
  );
    int unsigned beat_idx;
    int unsigned lane_idx;
    logic [AXIS_DATA_W-1:0] tmp_data;
    begin
      beat_idx = abs_pos / AXIS_BEAT_BYTES;
      lane_idx = abs_pos % AXIS_BEAT_BYTES;

      if (!shadow_valid) begin
        shadow_valid = 1'b1;
        shadow_idx   = MEM_BEAT_W'(beat_idx);
        shadow_data  = '0;
      end

      if (shadow_idx != MEM_BEAT_W'(beat_idx)) begin
        wr_en        = 1'b1;
        wr_addr      = shadow_idx;
        wr_data      = shadow_data;
        shadow_idx   = MEM_BEAT_W'(beat_idx);
        shadow_data  = '0;
        shadow_valid = 1'b1;
      end

      tmp_data = shadow_data;
      tmp_data[lane_idx*8 +: 8] = in_byte;
      shadow_data = tmp_data;

      if (lane_idx == (AXIS_BEAT_BYTES-1)) begin
        wr_en        = 1'b1;
        wr_addr      = MEM_BEAT_W'(beat_idx);
        wr_data      = tmp_data;
        shadow_valid = 1'b0;
        shadow_data  = '0;
      end

      abs_pos = abs_pos + 1;
    end
  endtask

  task automatic flush_shadow(
      inout  logic                   shadow_valid,
      input  logic [MEM_BEAT_W-1:0]  shadow_idx,
      input  logic [AXIS_DATA_W-1:0] shadow_data,
      inout  logic                   wr_en,
      inout  logic [MEM_BEAT_W-1:0]  wr_addr,
      inout  logic [AXIS_DATA_W-1:0] wr_data
  );
    begin
      if (shadow_valid) begin
        wr_en        = 1'b1;
        wr_addr      = shadow_idx;
        wr_data      = shadow_data;
        shadow_valid = 1'b0;
      end
    end
  endtask

  assign s_fire_c           = s_axis.tvalid && s_axis.tready;
  assign m_fire_c           = m_axis.tvalid && m_axis.tready;
  assign should_drop_c      = !pkt_valid_good_i && cfg_drop_invalid_pkt_i;
  assign is_last_out_beat_c = (out_idx_r == MEM_BEAT_W'(SLOT_TOTAL_BEATS-1));

  assign slot_start_o        = (state_r == ST_OUT_SEND) && m_axis.tvalid && (out_idx_r == '0);
  assign slot_done_o         = (state_r == ST_OUT_SEND) && m_axis.tvalid && is_last_out_beat_c;
  assign slot_bytes_o        = SLOT_BYTES_W'(SLOT_TOTAL_ALIGN);
  assign slot_seq_o          = cap_pkt_seq_r;
  assign slot_valid_good_o   = cap_pkt_valid_good_r;
  assign slot_overflow_err_o = cap_overflow_r;

  // --------------------------------------------------------------------------
  // AXIS output
  // --------------------------------------------------------------------------
  always_comb begin
    s_axis.tready = 1'b0;

    m_axis.tdata  = '0;
    m_axis.tkeep  = '0;
    m_axis.tvalid = 1'b0;
    m_axis.tlast  = 1'b0;
    m_axis.tuser  = '0;

    if (state_r == ST_CAPTURE) begin
      s_axis.tready = 1'b1;
    end

    if (state_r == ST_OUT_SEND) begin
      m_axis.tdata  = mem_rd_data_r;
      m_axis.tkeep  = {AXIS_KEEP_W{1'b1}};
      m_axis.tvalid = 1'b1;
      m_axis.tlast  = is_last_out_beat_c;
    end
  end

  // --------------------------------------------------------------------------
  // Main combinational next-state logic
  // --------------------------------------------------------------------------
  always_comb begin
    logic                      sh_valid;
    logic [MEM_BEAT_W-1:0]     sh_idx;
    logic [AXIS_DATA_W-1:0]    sh_data;
    logic [31:0]               abs_pos;
    logic [CQ_CNT_W-1:0]       tail_cnt;
    logic [CQ_CNT_W-1:0]       cq_cnt;

    logic [7:0]                tail_tmp [0:CQ_AREA_BYTES-1];
    logic [7:0]                cq_tmp   [0:CQ_AREA_BYTES-1];

    logic [7:0]                cur_byte;
    int unsigned               lane;
    int unsigned               valid_before_lane;
    int unsigned               pkt_byte_pos_before_this_byte;

    state_n              = state_r;

    cap_pkt_seq_n        = cap_pkt_seq_r;
    cap_pkt_bytes_n      = cap_pkt_bytes_r;
    cap_pkt_crc_err_n    = cap_pkt_crc_err_r;
    cap_pkt_ecc_err_n    = cap_pkt_ecc_err_r;
    cap_pkt_trunc_err_n  = cap_pkt_trunc_err_r;
    cap_pkt_valid_good_n = cap_pkt_valid_good_r;
    cap_overflow_n       = cap_overflow_r;

    wr_abs_pos_n         = wr_abs_pos_r;
    zero_fill_idx_n      = zero_fill_idx_r;
    out_idx_n            = out_idx_r;

    wr_shadow_valid_n    = wr_shadow_valid_r;
    wr_shadow_idx_n      = wr_shadow_idx_r;
    wr_shadow_data_n     = wr_shadow_data_r;

    tail_count_n         = tail_count_r;
    cq_count_n           = cq_count_r;

    for (i = 0; i < CQ_AREA_BYTES; i++) begin
      tail_buf_n[i] = tail_buf_r[i];
      cq_buf_n[i]   = cq_buf_r[i];
      tail_tmp[i]   = tail_buf_r[i];
      cq_tmp[i]     = cq_buf_r[i];
    end

    mem_wr_en_c    = 1'b0;
    mem_wr_addr_c  = '0;
    mem_wr_data_c  = '0;

    mem_rd_en_c    = 1'b0;
    mem_rd_addr_c  = '0;

    sh_valid = wr_shadow_valid_r;
    sh_idx   = wr_shadow_idx_r;
    sh_data  = wr_shadow_data_r;
    abs_pos  = wr_abs_pos_r;
    tail_cnt = tail_count_r;
    cq_cnt   = cq_count_r;

    case (state_r)
      ST_IDLE: begin
        if (pkt_start_i && s_axis.tvalid) begin
          cap_pkt_seq_n        = pkt_seq_i;
          cap_pkt_bytes_n      = '0;
          cap_pkt_crc_err_n    = 1'b0;
          cap_pkt_ecc_err_n    = 1'b0;
          cap_pkt_trunc_err_n  = 1'b0;
          cap_pkt_valid_good_n = 1'b0;
          cap_overflow_n       = 1'b0;

          wr_abs_pos_n         = 32'd0;
          zero_fill_idx_n      = '0;
          out_idx_n            = '0;

          wr_shadow_valid_n    = 1'b0;
          wr_shadow_idx_n      = '0;
          wr_shadow_data_n     = '0;

          tail_count_n         = '0;
          cq_count_n           = '0;
          for (i = 0; i < CQ_AREA_BYTES; i++) begin
            tail_buf_n[i] = 8'h00;
            cq_buf_n[i]   = 8'h00;
          end

          state_n = ST_CAPTURE;
        end
      end

      ST_CAPTURE: begin
        if (s_fire_c) begin
          valid_before_lane = 0;

          for (lane = 0; lane < AXIS_KEEP_W; lane++) begin
            if (s_axis.tkeep[lane]) begin
              cur_byte = s_axis.tdata[lane*8 +: 8];

              pkt_byte_pos_before_this_byte = cap_pkt_bytes_r + valid_before_lane;

              if (pkt_byte_pos_before_this_byte < HEADER_BYTES) begin
                append_byte_to_shadow(
                    cur_byte, sh_valid, sh_idx, sh_data, abs_pos,
                    mem_wr_en_c, mem_wr_addr_c, mem_wr_data_c
                );
              end else begin
                if (tail_cnt < CQ_AREA_BYTES) begin
                  tail_tmp[tail_cnt] = cur_byte;
                  tail_cnt = tail_cnt + 1'b1;
                end else begin
                  append_byte_to_shadow(
                      tail_tmp[0], sh_valid, sh_idx, sh_data, abs_pos,
                      mem_wr_en_c, mem_wr_addr_c, mem_wr_data_c
                  );
                  for (i = 0; i < CQ_AREA_BYTES-1; i++) begin
                    tail_tmp[i] = tail_tmp[i+1];
                  end
                  tail_tmp[CQ_AREA_BYTES-1] = cur_byte;
                end
              end

              valid_before_lane = valid_before_lane + 1;
            end
          end

          cap_pkt_bytes_n = cap_pkt_bytes_r + PKT_BYTE_CNT_W'(valid_before_lane);

          if (pkt_done_i) begin
            cap_pkt_bytes_n      = pkt_bytes_i;
            cap_pkt_crc_err_n    = pkt_crc_err_i;
            cap_pkt_ecc_err_n    = pkt_ecc_err_i;
            cap_pkt_trunc_err_n  = pkt_trunc_err_i;
            cap_pkt_valid_good_n = pkt_valid_good_i;

            if (pkt_bytes_i > PKT_BYTE_CNT_W'(SLOT_TOTAL_RAW)) begin
              cap_overflow_n = 1'b1;
            end

            if (should_drop_c) begin
              state_n = ST_IDLE;
            end else begin
              if (pkt_trunc_err_i) begin
                for (i = 0; i < CQ_AREA_BYTES; i++) begin
                  if (i < tail_cnt) begin
                    append_byte_to_shadow(
                        tail_tmp[i], sh_valid, sh_idx, sh_data, abs_pos,
                        mem_wr_en_c, mem_wr_addr_c, mem_wr_data_c
                    );
                  end
                end
                cq_cnt = '0;
                for (i = 0; i < CQ_AREA_BYTES; i++) begin
                  cq_tmp[i] = 8'h00;
                end
              end else begin
                cq_cnt = tail_cnt;
                for (i = 0; i < CQ_AREA_BYTES; i++) begin
                  if (i < tail_cnt) begin
                    cq_tmp[i] = tail_tmp[i];
                  end else begin
                    cq_tmp[i] = 8'h00;
                  end
                end
              end

              state_n = ST_CAP_FLUSH;
            end
          end
        end

        wr_shadow_valid_n = sh_valid;
        wr_shadow_idx_n   = sh_idx;
        wr_shadow_data_n  = sh_data;
        wr_abs_pos_n      = abs_pos;
        tail_count_n      = tail_cnt;
        cq_count_n        = cq_cnt;
        for (i = 0; i < CQ_AREA_BYTES; i++) begin
          tail_buf_n[i] = tail_tmp[i];
          cq_buf_n[i]   = cq_tmp[i];
        end
      end

      ST_CAP_FLUSH: begin
        sh_valid = wr_shadow_valid_r;
        flush_shadow(
            sh_valid, wr_shadow_idx_r, wr_shadow_data_r,
            mem_wr_en_c, mem_wr_addr_c, mem_wr_data_c
        );
        wr_shadow_valid_n = 1'b0;
        wr_shadow_data_n  = '0;

        zero_fill_idx_n = MEM_BEAT_W'(ceil_div_int(wr_abs_pos_r, AXIS_BEAT_BYTES));
        state_n         = ST_ZERO_MID;
      end

      ST_ZERO_MID: begin
        if (zero_fill_idx_r < MEM_BEAT_W'(CQ_START_BEAT)) begin
          mem_wr_en_c     = 1'b1;
          mem_wr_addr_c   = zero_fill_idx_r;
          mem_wr_data_c   = '0;
          zero_fill_idx_n = zero_fill_idx_r + 1'b1;
        end else begin
          wr_shadow_valid_n = 1'b1;
          wr_shadow_idx_n   = MEM_BEAT_W'(CQ_START_BEAT);
          wr_shadow_data_n  = '0;
          wr_abs_pos_n      = CQ_START_BYTE;
          state_n           = ST_CQ_WRITE;
        end
      end

      ST_CQ_WRITE: begin
        sh_valid = 1'b1;
        sh_idx   = MEM_BEAT_W'(CQ_START_BEAT);
        sh_data  = '0;
        abs_pos  = CQ_START_BYTE;

        for (i = 0; i < CQ_AREA_BYTES; i++) begin
          if (i < cq_count_r) begin
            append_byte_to_shadow(
                cq_buf_r[i], sh_valid, sh_idx, sh_data, abs_pos,
                mem_wr_en_c, mem_wr_addr_c, mem_wr_data_c
            );
          end
        end

        wr_shadow_valid_n = sh_valid;
        wr_shadow_idx_n   = sh_idx;
        wr_shadow_data_n  = sh_data;
        wr_abs_pos_n      = abs_pos;
        state_n           = ST_CQ_FLUSH;
      end

      ST_CQ_FLUSH: begin
        sh_valid = wr_shadow_valid_r;
        flush_shadow(
            sh_valid, wr_shadow_idx_r, wr_shadow_data_r,
            mem_wr_en_c, mem_wr_addr_c, mem_wr_data_c
        );
        wr_shadow_valid_n = 1'b0;
        wr_shadow_data_n  = '0;

        zero_fill_idx_n = MEM_BEAT_W'(ceil_div_int(wr_abs_pos_r, AXIS_BEAT_BYTES));
        state_n         = ST_ZERO_TAIL;
      end

      ST_ZERO_TAIL: begin
        if (zero_fill_idx_r < MEM_BEAT_W'(SLOT_TOTAL_BEATS)) begin
          mem_wr_en_c     = 1'b1;
          mem_wr_addr_c   = zero_fill_idx_r;
          mem_wr_data_c   = '0;
          zero_fill_idx_n = zero_fill_idx_r + 1'b1;
        end else begin
          out_idx_n = '0;
          state_n   = ST_OUT_READ;
        end
      end

      ST_OUT_READ: begin
        mem_rd_en_c   = 1'b1;
        mem_rd_addr_c = out_idx_r;
        state_n       = ST_OUT_SEND;
      end

      ST_OUT_SEND: begin
        if (m_fire_c) begin
          if (is_last_out_beat_c) begin
            state_n   = ST_IDLE;
            out_idx_n = '0;
          end else begin
            out_idx_n = out_idx_r + 1'b1;
            state_n   = ST_OUT_READ;
          end
        end
      end

      default: begin
        state_n = ST_IDLE;
      end
    endcase
  end

  // --------------------------------------------------------------------------
  // Control/state registers with async reset
  // --------------------------------------------------------------------------
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_r              <= ST_IDLE;

      cap_pkt_seq_r        <= '0;
      cap_pkt_bytes_r      <= '0;
      cap_pkt_crc_err_r    <= 1'b0;
      cap_pkt_ecc_err_r    <= 1'b0;
      cap_pkt_trunc_err_r  <= 1'b0;
      cap_pkt_valid_good_r <= 1'b0;
      cap_overflow_r       <= 1'b0;

      wr_abs_pos_r         <= '0;
      zero_fill_idx_r      <= '0;
      out_idx_r            <= '0;

      wr_shadow_valid_r    <= 1'b0;
      wr_shadow_idx_r      <= '0;
      wr_shadow_data_r     <= '0;

      tail_count_r         <= '0;
      cq_count_r           <= '0;

      for (i = 0; i < CQ_AREA_BYTES; i++) begin
        tail_buf_r[i] <= 8'h00;
        cq_buf_r[i]   <= 8'h00;
      end
    end else begin
      state_r              <= state_n;

      cap_pkt_seq_r        <= cap_pkt_seq_n;
      cap_pkt_bytes_r      <= cap_pkt_bytes_n;
      cap_pkt_crc_err_r    <= cap_pkt_crc_err_n;
      cap_pkt_ecc_err_r    <= cap_pkt_ecc_err_n;
      cap_pkt_trunc_err_r  <= cap_pkt_trunc_err_n;
      cap_pkt_valid_good_r <= cap_pkt_valid_good_n;
      cap_overflow_r       <= cap_overflow_n;

      wr_abs_pos_r         <= wr_abs_pos_n;
      zero_fill_idx_r      <= zero_fill_idx_n;
      out_idx_r            <= out_idx_n;

      wr_shadow_valid_r    <= wr_shadow_valid_n;
      wr_shadow_idx_r      <= wr_shadow_idx_n;
      wr_shadow_data_r     <= wr_shadow_data_n;

      tail_count_r         <= tail_count_n;
      cq_count_r           <= cq_count_n;

      for (i = 0; i < CQ_AREA_BYTES; i++) begin
        tail_buf_r[i] <= tail_buf_n[i];
        cq_buf_r[i]   <= cq_buf_n[i];
      end
    end
  end

  // --------------------------------------------------------------------------
  // RAM write/read ports WITHOUT reset
  // --------------------------------------------------------------------------
  always_ff @(posedge clk_i) begin
    if (mem_wr_en_c) begin
      slot_mem_r[mem_wr_addr_c] <= mem_wr_data_c;
    end
    if (mem_rd_en_c) begin
      mem_rd_data_r <= slot_mem_r[mem_rd_addr_c];
    end
  end

  // --------------------------------------------------------------------------
  // Static assertions
  // --------------------------------------------------------------------------
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
    `SLOT_PKR_STATIC_ASSERT((SLOT_TOTAL_ALIGN % AXIS_BEAT_BYTES) == 0,
                            "Aligned slot size must be a multiple of AXIS_BEAT_BYTES")
    `SLOT_PKR_STATIC_ASSERT(SLOT_TOTAL_BEATS > 0, "SLOT_TOTAL_BEATS must be > 0")

    `SLOT_PKR_STATIC_ASSERT($bits(m_axis.tdata) == AXIS_DATA_W,
                            "Input and output AXIS data widths must match")
    `SLOT_PKR_STATIC_ASSERT($bits(m_axis.tkeep) == AXIS_KEEP_W,
                            "Input and output AXIS keep widths must match")
  end

endmodule