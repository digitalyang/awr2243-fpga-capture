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
  localparam int unsigned BEAT_BYTE_CNT_W   = clog2_safe(AXIS_BEAT_BYTES + 1);

  localparam int unsigned CQ_START_BYTE     = HEADER_BYTES + SAMPLE_AREA_BYTES;
  localparam int unsigned CQ_START_BEAT     = CQ_START_BYTE / AXIS_BEAT_BYTES;
  localparam int unsigned CQ_LANE_OFFSET    = CQ_START_BYTE % AXIS_BEAT_BYTES;

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

  logic [AXIS_DATA_W-1:0]    current_beat_r,       current_beat_n;
  logic [BEAT_BYTE_CNT_W-1:0] bytes_in_beat_r,     bytes_in_beat_n;

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

  function automatic logic [BEAT_BYTE_CNT_W-1:0] count_keep_bytes(input logic [AXIS_KEEP_W-1:0] keep);
    logic [BEAT_BYTE_CNT_W-1:0] sum;
    int unsigned idx;
    begin
      sum = '0;
      for (idx = 0; idx < AXIS_KEEP_W; idx++)
        sum = sum + BEAT_BYTE_CNT_W'(keep[idx]);
      count_keep_bytes = sum;
    end
  endfunction

  function automatic logic [31:0] sample_end_byte_for_pkt(
      input logic [PKT_BYTE_CNT_W-1:0] pkt_bytes,
      input logic                      pkt_trunc_err
  );
    logic [31:0] pkt_bytes_u32;
    begin
      pkt_bytes_u32 = 32'(pkt_bytes);
      sample_end_byte_for_pkt = 32'(HEADER_BYTES);

      if (pkt_trunc_err) begin
        if (pkt_bytes_u32 >= 32'(HEADER_BYTES)) begin
          if ((pkt_bytes_u32 - 32'(HEADER_BYTES)) < 32'(SAMPLE_AREA_BYTES))
            sample_end_byte_for_pkt = pkt_bytes_u32;
          else
            sample_end_byte_for_pkt = 32'(HEADER_BYTES) + 32'(SAMPLE_AREA_BYTES);
        end
      end else if (pkt_bytes_u32 >= 32'(HEADER_BYTES + CQ_AREA_BYTES)) begin
        if ((pkt_bytes_u32 - 32'(HEADER_BYTES + CQ_AREA_BYTES)) < 32'(SAMPLE_AREA_BYTES))
          sample_end_byte_for_pkt = pkt_bytes_u32 - 32'(CQ_AREA_BYTES);
        else
          sample_end_byte_for_pkt = 32'(HEADER_BYTES) + 32'(SAMPLE_AREA_BYTES);
      end
    end
  endfunction

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
    int unsigned               carried_cnt;

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
    carried_cnt = 0;

    current_beat_n  = current_beat_r;
    bytes_in_beat_n = bytes_in_beat_r;

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

          current_beat_n      = '0;
          bytes_in_beat_n     = BEAT_BYTE_CNT_W'(0);

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
          logic [31:0] pkt_sample_end_byte;

          pkt_sample_end_byte = sample_end_byte_for_pkt(pkt_bytes_i, pkt_trunc_err_i);
          valid_before_lane = 0;

          // Fast path: beat-aligned and full beat, write s_axis.tdata directly to RAM.
          // On last beat (pkt_done_i), zero-fill from effective payload end to match slot layout (sample_len = remainder - CQ).
          if ((wr_abs_pos_r % AXIS_BEAT_BYTES) == 0 &&
              (s_axis.tkeep == {AXIS_KEEP_W{1'b1}}) &&
              (wr_abs_pos_r + AXIS_BEAT_BYTES <= CQ_START_BYTE) &&
              ((32'(cap_pkt_bytes_r) + 32'(AXIS_BEAT_BYTES)) <= pkt_sample_end_byte)) begin
            mem_wr_en_c   = 1'b1;
            mem_wr_addr_c = MEM_BEAT_W'(wr_abs_pos_r / AXIS_BEAT_BYTES);
            mem_wr_data_c = s_axis.tdata;
            valid_before_lane = AXIS_BEAT_BYTES;
            if (pkt_done_i && !pkt_trunc_err_i &&
                (32'(pkt_bytes_i) >= 32'(HEADER_BYTES + CQ_AREA_BYTES))) begin
              logic [31:0] eff_end;
              int unsigned z_start;
              // eff_end = HEADER + min(pkt_bytes - HEADER - CQ, SAMPLE_AREA) = slot payload end (matches Python sample_len)
              if ((32'(pkt_bytes_i) - 32'(HEADER_BYTES + CQ_AREA_BYTES)) < 32'(SAMPLE_AREA_BYTES))
                eff_end = 32'(pkt_bytes_i) - 32'(CQ_AREA_BYTES);
              else
                eff_end = 32'(HEADER_BYTES) + 32'(SAMPLE_AREA_BYTES);
              z_start = (eff_end > wr_abs_pos_r) ? int'(eff_end - wr_abs_pos_r) : 0;
              for (i = 0; i < AXIS_BEAT_BYTES; i++) begin
                if (i >= z_start)
                  mem_wr_data_c[i*8 +: 8] = 8'h00;
              end
            end
            wr_abs_pos_n  = wr_abs_pos_r + 32'(AXIS_BEAT_BYTES);
            for (i = 0; i < CQ_AREA_BYTES; i++) begin
              tail_tmp[i] = s_axis.tdata[(AXIS_BEAT_BYTES - CQ_AREA_BYTES + i) * 8 +: 8];
            end
            tail_cnt = CQ_CNT_W'(CQ_AREA_BYTES);
            sh_valid = wr_shadow_valid_r;
            sh_idx   = wr_shadow_idx_r;
            sh_data  = wr_shadow_data_r;
            abs_pos  = wr_abs_pos_r + 32'(AXIS_BEAT_BYTES);
            current_beat_n  = current_beat_r;
            bytes_in_beat_n = bytes_in_beat_r;
          end else begin
            // Slow path: merge into current_beat, sliding window for sample/CQ boundary
            begin
              logic [AXIS_DATA_W-1:0] merged_beat;
              int unsigned            slot_off;
              logic [7:0]             byte_out;
              logic [31:0]            sample_end_byte;
              int unsigned            slot_pos;
              int unsigned            break_lane;
              int unsigned            valid_bytes_cur;
              int unsigned            sample_bytes_this_beat;
              logic                   bypass_full_beat;
              logic                   zero_fill_done;

              break_lane = AXIS_KEEP_W;
              carried_cnt = 0;
              sample_end_byte = pkt_sample_end_byte;

              // Bypass: beat-aligned, empty buffer, entire beat in sample region → use s_axis.tdata as-is (no reorder).
              bypass_full_beat = (bytes_in_beat_r == 0) &&
                ((wr_abs_pos_r % AXIS_BEAT_BYTES) == 0) &&
                (wr_abs_pos_r + AXIS_BEAT_BYTES <= CQ_START_BYTE) &&
                ((32'(cap_pkt_bytes_r) + 32'(AXIS_BEAT_BYTES)) <= sample_end_byte) &&
                (s_axis.tkeep == {AXIS_KEEP_W{1'b1}});

              merged_beat = current_beat_r;
              slot_off    = 32'(bytes_in_beat_r);
              valid_bytes_cur = int'(count_keep_bytes(s_axis.tkeep));

              if ((bytes_in_beat_r == BEAT_BYTE_CNT_W'(0)) &&
                  (tail_cnt == CQ_CNT_W'(CQ_AREA_BYTES)) &&
                  (32'(cap_pkt_bytes_r) < 32'(SLOT_TOTAL_RAW)) &&
                  (sample_end_byte <= (32'(cap_pkt_bytes_r) + 32'(valid_bytes_cur))) &&
                  !pkt_trunc_err_i) begin
                if (32'(pkt_bytes_i) >= 32'(HEADER_BYTES + CQ_AREA_BYTES)) begin
                  if ((32'(pkt_bytes_i) - 32'(HEADER_BYTES + CQ_AREA_BYTES)) < 32'(SAMPLE_AREA_BYTES))
                    sample_end_byte = 32'(pkt_bytes_i) - 32'(CQ_AREA_BYTES);
                  else
                    sample_end_byte = 32'(HEADER_BYTES) + 32'(SAMPLE_AREA_BYTES);
                end else begin
                  sample_end_byte = 32'(HEADER_BYTES);
                end

                if (sample_end_byte > 32'(cap_pkt_bytes_r))
                  sample_bytes_this_beat = int'(sample_end_byte - 32'(cap_pkt_bytes_r));
                else
                  sample_bytes_this_beat = 0;

                if (sample_bytes_this_beat > valid_bytes_cur)
                  sample_bytes_this_beat = valid_bytes_cur;

                merged_beat = '0;
                if (MEM_BEAT_W'(wr_abs_pos_r / AXIS_BEAT_BYTES) == MEM_BEAT_W'(CQ_START_BEAT)) begin
                  slot_off = sample_bytes_this_beat;
                end else begin
                  slot_off   = 32'(AXIS_BEAT_BYTES);
                  break_lane = AXIS_KEEP_W;
                end
                valid_before_lane = valid_bytes_cur;

                for (i = 0; i < AXIS_KEEP_W; i++) begin
                  if (i < sample_bytes_this_beat)
                    merged_beat[i*8 +: 8] = s_axis.tdata[i*8 +: 8];
                end

                if ((valid_bytes_cur - sample_bytes_this_beat) >= CQ_AREA_BYTES)
                  tail_cnt = CQ_CNT_W'(CQ_AREA_BYTES);
                else
                  tail_cnt = CQ_CNT_W'(valid_bytes_cur - sample_bytes_this_beat);

                for (i = 0; i < CQ_AREA_BYTES; i++) begin
                  if ((i < (valid_bytes_cur - sample_bytes_this_beat)) &&
                      ((sample_bytes_this_beat + i) < AXIS_KEEP_W))
                    tail_tmp[i] = s_axis.tdata[(sample_bytes_this_beat + i) * 8 +: 8];
                  else
                    tail_tmp[i] = 8'h00;
                end
              end else begin
                if (bypass_full_beat) begin
                  merged_beat = s_axis.tdata;
                  slot_off    = 32'(AXIS_BEAT_BYTES);
                  break_lane  = AXIS_KEEP_W;
                  valid_before_lane = valid_before_lane + AXIS_BEAT_BYTES;
                  for (i = 0; i < CQ_AREA_BYTES; i++)
                    tail_tmp[i] = s_axis.tdata[(AXIS_BEAT_BYTES - CQ_AREA_BYTES + i) * 8 +: 8];
                  tail_cnt = CQ_CNT_W'(CQ_AREA_BYTES);
                end else begin
                  for (lane = 0; lane < AXIS_KEEP_W; lane++) begin
                    if (break_lane >= AXIS_KEEP_W) begin
                      if (slot_off >= 32'(AXIS_BEAT_BYTES)) begin
                        break_lane = lane;
                      end else if (s_axis.tkeep[lane]) begin
                        cur_byte = s_axis.tdata[lane*8 +: 8];
                        pkt_byte_pos_before_this_byte = cap_pkt_bytes_r + valid_before_lane;

                        if (pkt_byte_pos_before_this_byte < SLOT_TOTAL_RAW) begin
                          if (pkt_byte_pos_before_this_byte < HEADER_BYTES) begin
                            byte_out = cur_byte;
                            if ((wr_abs_pos_r + 32'(slot_off) - 32'(bytes_in_beat_r)) < CQ_START_BYTE) begin
                              merged_beat[slot_off*8 +: 8] = byte_out;
                              slot_off = slot_off + 1;
                            end
                          end else begin
                            if (tail_cnt < CQ_AREA_BYTES) begin
                              tail_tmp[tail_cnt] = cur_byte;
                              tail_cnt = tail_cnt + 1'b1;
                            end else begin
                              byte_out = tail_tmp[0];
                              if ((wr_abs_pos_r + 32'(slot_off) - 32'(bytes_in_beat_r)) < CQ_START_BYTE) begin
                                merged_beat[slot_off*8 +: 8] = byte_out;
                                slot_off = slot_off + 1;
                              end
                              for (i = 0; i < CQ_AREA_BYTES-1; i++)
                                tail_tmp[i] = tail_tmp[i+1];
                              tail_tmp[CQ_AREA_BYTES-1] = cur_byte;
                            end
                          end
                        end
                        valid_before_lane = valid_before_lane + 1;
                      end
                    end
                  end
                end

                // Carry over: run remaining input bytes through the sliding window; output (pops) go to current_beat_n.
                // Use a local copy of the window so we don't conflict with shared tail_tmp indexing.
                if (slot_off >= 32'(AXIS_BEAT_BYTES) && break_lane < AXIS_KEEP_W) begin
                  logic [7:0] rem_bytes [0:AXIS_BEAT_BYTES-1];
                  logic [7:0] win [0:CQ_AREA_BYTES-1];
                  int unsigned rem_cnt;
                  int unsigned k;
                  int unsigned write_idx;
                  rem_cnt = 0;
                  for (k = 0; k < AXIS_BEAT_BYTES; k++)
                    rem_bytes[k] = 8'h00;
                  for (lane = 0; lane < AXIS_KEEP_W; lane++) begin
                    if ((lane >= break_lane) &&
                        s_axis.tkeep[lane] && rem_cnt < AXIS_BEAT_BYTES &&
                        (32'(cap_pkt_bytes_r) + 32'(valid_before_lane) + 32'(rem_cnt) < 32'(SLOT_TOTAL_RAW))) begin
                      rem_bytes[rem_cnt] = s_axis.tdata[lane*8 +: 8];
                      rem_cnt = rem_cnt + 1;
                    end
                  end
                  for (i = 0; i < CQ_AREA_BYTES; i++)
                    win[i] = tail_tmp[i];
                  write_idx = 0;
                  // Fast path: 9 in window and 23 remaining => output = win[0:9] then rem_bytes[0:14] = payload[32:55]
                  if (rem_cnt == 23 && tail_cnt >= CQ_AREA_BYTES) begin
                    for (k = 0; k < 9; k++)
                      current_beat_n[k*8 +: 8] = win[k];
                    for (k = 0; k < 14; k++)
                      current_beat_n[(9+k)*8 +: 8] = rem_bytes[k];
                    for (i = 0; i < CQ_AREA_BYTES-1; i++)
                      tail_tmp[i] = rem_bytes[14 + i];
                    tail_tmp[CQ_AREA_BYTES-1] = rem_bytes[22];
                    write_idx = 23;
                  end else begin
                    for (k = 0; k < AXIS_BEAT_BYTES; k++) begin
                      if (k < rem_cnt) begin
                        if (tail_cnt < CQ_AREA_BYTES) begin
                          win[tail_cnt] = rem_bytes[k];
                          tail_cnt = tail_cnt + 1'b1;
                        end else begin
                          if (write_idx < AXIS_BEAT_BYTES) begin
                            current_beat_n[write_idx*8 +: 8] = win[0];
                            write_idx = write_idx + 1;
                          end
                          for (i = 0; i < CQ_AREA_BYTES-1; i++)
                            win[i] = win[i+1];
                          win[CQ_AREA_BYTES-1] = rem_bytes[k];
                        end
                      end
                    end
                    for (i = 0; i < CQ_AREA_BYTES; i++)
                      tail_tmp[i] = win[i];
                  end
                  if (write_idx > AXIS_BEAT_BYTES)
                    bytes_in_beat_n = BEAT_BYTE_CNT_W'(AXIS_BEAT_BYTES);
                  else
                    bytes_in_beat_n = BEAT_BYTE_CNT_W'(write_idx);
                  carried_cnt = rem_cnt;
                end
              end

              // Zero-fill from end of sample to CQ when packet ends this beat
              if (pkt_done_i) begin
                zero_fill_done = 1'b0;
                for (i = 0; i < AXIS_BEAT_BYTES; i++) begin
                  if (!zero_fill_done) begin
                    if (slot_off >= 32'(AXIS_BEAT_BYTES)) begin
                      zero_fill_done = 1'b1;
                    end else begin
                      slot_pos = wr_abs_pos_r + 32'(slot_off) - 32'(bytes_in_beat_r);
                      if (slot_pos >= CQ_START_BYTE) begin
                        zero_fill_done = 1'b1;
                      end else if (slot_pos >= sample_end_byte) begin
                        merged_beat[slot_off*8 +: 8] = 8'h00;
                        slot_off = slot_off + 1;
                      end else begin
                        zero_fill_done = 1'b1;
                      end
                    end
                  end
                end
              end

              if (slot_off >= AXIS_BEAT_BYTES) begin
                mem_wr_en_c   = 1'b1;
                mem_wr_addr_c = MEM_BEAT_W'(wr_abs_pos_r / AXIS_BEAT_BYTES);
                mem_wr_data_c = merged_beat;
                // Last beat zero-fill from effective payload end (sample_len = remainder - CQ) when pkt_done_i
                if (pkt_done_i && (break_lane >= AXIS_KEEP_W) &&
                    (32'(pkt_bytes_i) >= 32'(HEADER_BYTES + CQ_AREA_BYTES))) begin
                  logic [31:0] eff_end_s;
                  int unsigned z_start_s;
                  if ((32'(pkt_bytes_i) - 32'(HEADER_BYTES + CQ_AREA_BYTES)) < 32'(SAMPLE_AREA_BYTES))
                    eff_end_s = 32'(pkt_bytes_i) - 32'(CQ_AREA_BYTES);
                  else
                    eff_end_s = 32'(HEADER_BYTES) + 32'(SAMPLE_AREA_BYTES);
                  z_start_s = (eff_end_s > wr_abs_pos_r) ? int'(eff_end_s - wr_abs_pos_r) : 0;
                  for (i = 0; i < AXIS_BEAT_BYTES; i++) begin
                    if (i >= z_start_s)
                      mem_wr_data_c[i*8 +: 8] = 8'h00;
                  end
                end
                wr_abs_pos_n  = wr_abs_pos_r + 32'(AXIS_BEAT_BYTES);
                abs_pos       = wr_abs_pos_r + 32'(AXIS_BEAT_BYTES);
                if (break_lane >= AXIS_KEEP_W) begin
                  current_beat_n  = '0;
                  if (slot_off > AXIS_BEAT_BYTES)
                    bytes_in_beat_n = BEAT_BYTE_CNT_W'(slot_off - AXIS_BEAT_BYTES);
                  else
                    bytes_in_beat_n = BEAT_BYTE_CNT_W'(0);
                end
                // else: current_beat_n and bytes_in_beat_n already set by carry-over above
              end else begin
                wr_abs_pos_n     = wr_abs_pos_r + 32'(slot_off - 32'(bytes_in_beat_r));
                abs_pos          = wr_abs_pos_r + 32'(slot_off - 32'(bytes_in_beat_r));
                current_beat_n   = merged_beat;
                bytes_in_beat_n  = BEAT_BYTE_CNT_W'(slot_off);
              end
              sh_valid = wr_shadow_valid_r;
              sh_idx   = wr_shadow_idx_r;
              sh_data  = wr_shadow_data_r;
            end
          end

          cap_pkt_bytes_n = cap_pkt_bytes_r + PKT_BYTE_CNT_W'(valid_before_lane) + PKT_BYTE_CNT_W'(carried_cnt);

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
                cq_cnt = '0;
                for (i = 0; i < CQ_AREA_BYTES; i++) begin
                  cq_tmp[i] = 8'h00;
                end
                // On truncation, tail_tmp bytes belong to the sample region. Only
                // append/flush when there is an unwritten partial beat buffer; if
                // the last beat was already committed directly, keep that write.
                if (bytes_in_beat_n != BEAT_BYTE_CNT_W'(0)) begin
                  logic [AXIS_DATA_W-1:0] fin_beat;
                  int unsigned            so;
                  so = 32'(bytes_in_beat_n);
                  fin_beat = current_beat_n;
                  for (i = 0; i < CQ_AREA_BYTES; i++) begin
                    if ((i < tail_cnt) && (so < AXIS_BEAT_BYTES)) begin
                      fin_beat[so*8 +: 8] = tail_tmp[i];
                      so = so + 1;
                    end
                  end
                  if (so > 0) begin
                    mem_wr_en_c   = 1'b1;
                    mem_wr_addr_c = MEM_BEAT_W'(wr_abs_pos_r / AXIS_BEAT_BYTES);
                    mem_wr_data_c = fin_beat;
                    wr_abs_pos_n  = wr_abs_pos_r + 32'(so);
                    wr_shadow_valid_n = 1'b0;
                    wr_shadow_data_n  = '0;
                    current_beat_n  = '0;
                    bytes_in_beat_n = BEAT_BYTE_CNT_W'(0);
                  end
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
        if (!s_fire_c) begin
          current_beat_n  = current_beat_r;
          bytes_in_beat_n = bytes_in_beat_r;
        end
        if (state_n == ST_CAP_FLUSH && bytes_in_beat_n != BEAT_BYTE_CNT_W'(0)) begin
          wr_shadow_valid_n = 1'b1;
          // Partial beat holds bytes for slot [wr_abs_pos_n, wr_abs_pos_n+bytes_in_beat_n), so write to beat wr_abs_pos_n/32
          wr_shadow_idx_n   = MEM_BEAT_W'(wr_abs_pos_n / AXIS_BEAT_BYTES);
          wr_shadow_data_n  = current_beat_n;
          for (i = 0; i < AXIS_BEAT_BYTES; i++)
            if (i >= bytes_in_beat_n) wr_shadow_data_n[i*8 +: 8] = 8'h00;
        end
      end

      ST_CAP_FLUSH: begin
        if (wr_shadow_valid_r && (wr_shadow_idx_r == MEM_BEAT_W'(CQ_START_BEAT))) begin
          wr_shadow_valid_n = 1'b1;
          wr_shadow_idx_n   = wr_shadow_idx_r;
          wr_shadow_data_n  = wr_shadow_data_r;
        end else begin
          if (wr_shadow_valid_r) begin
            mem_wr_en_c   = 1'b1;
            mem_wr_addr_c = wr_shadow_idx_r;
            mem_wr_data_c = wr_shadow_data_r;
          end
          wr_shadow_valid_n = 1'b0;
          wr_shadow_data_n  = '0;
        end

        // Start zero-fill after last written beat: if we wrote a partial to wr_shadow_idx_r, zero from next beat;
        // else we wrote only full beats, so zero from wr_abs_pos_r/32.
        if (wr_shadow_valid_r)
          zero_fill_idx_n = wr_shadow_idx_r + 1'b1;
        else
          zero_fill_idx_n = MEM_BEAT_W'(wr_abs_pos_r / AXIS_BEAT_BYTES);
        state_n          = ST_ZERO_MID;
      end

      ST_ZERO_MID: begin
        if (zero_fill_idx_r < MEM_BEAT_W'(CQ_START_BEAT)) begin
          mem_wr_en_c     = 1'b1;
          mem_wr_addr_c   = zero_fill_idx_r;
          mem_wr_data_c   = '0;
          zero_fill_idx_n = zero_fill_idx_r + 1'b1;
        end else begin
          if (!(wr_shadow_valid_r && (wr_shadow_idx_r == MEM_BEAT_W'(CQ_START_BEAT)))) begin
            wr_shadow_valid_n = 1'b1;
            wr_shadow_idx_n   = MEM_BEAT_W'(CQ_START_BEAT);
            wr_shadow_data_n  = '0;
          end
          wr_abs_pos_n      = CQ_START_BYTE;
          state_n           = ST_CQ_WRITE;
        end
      end

      ST_CQ_WRITE: begin
        begin
          logic [AXIS_DATA_W-1:0] cq_beat;
          cq_beat = (wr_shadow_valid_r && (wr_shadow_idx_r == MEM_BEAT_W'(CQ_START_BEAT)))
              ? wr_shadow_data_r
              : '0;
          for (i = 0; i < CQ_AREA_BYTES; i++)
            if ((i < cq_count_r) && ((CQ_LANE_OFFSET + i) < AXIS_BEAT_BYTES))
              cq_beat[(CQ_LANE_OFFSET + i) * 8 +: 8] = cq_buf_r[i];
          mem_wr_en_c   = 1'b1;
          mem_wr_addr_c = MEM_BEAT_W'(CQ_START_BEAT);
          mem_wr_data_c = cq_beat;
        end
        wr_shadow_valid_n = 1'b0;
        wr_shadow_data_n  = '0;
        wr_abs_pos_n      = CQ_START_BYTE + 32'(CQ_AREA_BYTES);
        state_n           = ST_CQ_FLUSH;
      end

      ST_CQ_FLUSH: begin
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

      current_beat_r      <= '0;
      bytes_in_beat_r     <= '0;

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

      current_beat_r      <= current_beat_n;
      bytes_in_beat_r     <= bytes_in_beat_n;

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
