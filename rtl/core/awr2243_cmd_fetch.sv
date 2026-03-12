`include "awr2243_script_macros.svh"

module awr2243_cmd_fetch #(
    parameter int unsigned WORD_W       = `AWR2243_SCRIPT_WORD_W_DFLT,
    parameter int unsigned DEPTH        = `AWR2243_SCRIPT_MEM_DEPTH_DFLT,
    parameter int unsigned SCRIPT_COUNT = `AWR2243_SCRIPT_TABLE_DEPTH_DFLT,
    parameter int unsigned ADDR_W       = awr2243_script_pkg::clog2_safe(DEPTH),
    parameter int unsigned SCRIPT_ID_W  = awr2243_script_pkg::clog2_safe(SCRIPT_COUNT),
    parameter int unsigned SCRIPT_LEN_W = awr2243_script_pkg::clog2_safe(DEPTH + 1)
) (
    input logic clk_i,
    input logic rst_ni,

    input logic                   start_i,
    input logic [SCRIPT_ID_W-1:0] script_id_i,
    input logic                   advance_i,
    input logic                   hold_i,
    input logic                   jump_en_i,
    input logic [     ADDR_W-1:0] jump_addr_i,

    output logic                    ram_rd_en_o,
    output logic [      ADDR_W-1:0] ram_rd_addr_o,
    input  logic                    ram_rd_valid_i,
    input  logic [      WORD_W-1:0] ram_rd_data_i,
    output logic [ SCRIPT_ID_W-1:0] ram_script_id_o,
    input  logic [      ADDR_W-1:0] ram_script_base_i,
    input  logic [SCRIPT_LEN_W-1:0] ram_script_len_i,

    output logic              cmd_valid_o,
    output logic [WORD_W-1:0] cmd_word_o,
    output logic [ADDR_W-1:0] pc_o,
    output logic              script_done_o,
    output logic              busy_o,
    output logic [       2:0] state_o
);

  import awr2243_script_pkg::*;

  typedef enum logic [2:0] {
    F_IDLE,
    F_LOOKUP,
    F_READ,
    F_WAIT_CONSUME,
    F_DONE
  } fetch_state_e;

  fetch_state_e                    state_r;
  fetch_state_e                    state_n;
  logic         [ SCRIPT_ID_W-1:0] active_script_id_r;
  logic         [ SCRIPT_ID_W-1:0] active_script_id_n;
  logic         [      ADDR_W-1:0] script_base_r;
  logic         [      ADDR_W-1:0] script_base_n;
  logic         [SCRIPT_LEN_W-1:0] script_len_r;
  logic         [SCRIPT_LEN_W-1:0] script_len_n;
  logic         [      ADDR_W-1:0] pc_r;
  logic         [      ADDR_W-1:0] pc_n;
  logic         [      WORD_W-1:0] cmd_word_r;
  logic         [      WORD_W-1:0] cmd_word_n;
  logic                            rd_pending_r;
  logic                            rd_pending_n;

  initial begin
    if (WORD_W < SCRIPT_WORD_W_DFLT) begin
      $fatal(1, "awr2243_cmd_fetch requires WORD_W >= 64");
    end
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_r            <= F_IDLE;
      active_script_id_r <= '0;
      script_base_r      <= '0;
      script_len_r       <= '0;
      pc_r               <= '0;
      cmd_word_r         <= '0;
      rd_pending_r       <= 1'b0;
    end else begin
      state_r            <= state_n;
      active_script_id_r <= active_script_id_n;
      script_base_r      <= script_base_n;
      script_len_r       <= script_len_n;
      pc_r               <= pc_n;
      cmd_word_r         <= cmd_word_n;
      rd_pending_r       <= rd_pending_n;
    end
  end

  always_comb begin
    state_n            = state_r;
    active_script_id_n = active_script_id_r;
    script_base_n      = script_base_r;
    script_len_n       = script_len_r;
    pc_n               = pc_r;
    cmd_word_n         = cmd_word_r;
    rd_pending_n       = rd_pending_r;

    if (start_i) begin
      state_n            = F_LOOKUP;
      active_script_id_n = script_id_i;
      script_base_n      = '0;
      script_len_n       = '0;
      pc_n               = '0;
      cmd_word_n         = '0;
      rd_pending_n       = 1'b0;
    end else begin
      case (state_r)
        F_IDLE: begin
          rd_pending_n = 1'b0;
        end

        F_LOOKUP: begin
          script_base_n = ram_script_base_i;
          script_len_n  = ram_script_len_i;
          pc_n          = '0;
          rd_pending_n  = 1'b0;

          if (ram_script_len_i == '0) begin
            state_n = F_DONE;
          end else begin
            state_n = F_READ;
          end
        end

        F_READ: begin
          if (!rd_pending_r) begin
            rd_pending_n = 1'b1;
          end else if (ram_rd_valid_i) begin
            cmd_word_n   = ram_rd_data_i;
            rd_pending_n = 1'b0;
            state_n      = F_WAIT_CONSUME;
          end
        end

        F_WAIT_CONSUME: begin
          if (jump_en_i) begin
            rd_pending_n = 1'b0;
            if (jump_addr_i < script_len_r) begin
              pc_n    = jump_addr_i;
              state_n = F_READ;
            end else begin
              state_n = F_DONE;
            end
          end else if (advance_i) begin
            rd_pending_n = 1'b0;
            if ((pc_r + ADDR_W'(1)) >= script_len_r) begin
              state_n = F_DONE;
            end else begin
              pc_n    = pc_r + ADDR_W'(1);
              state_n = F_READ;
            end
          end else if (hold_i) begin
            state_n = F_WAIT_CONSUME;
          end
        end

        F_DONE: begin
          state_n = F_IDLE;
        end

        default: begin
          state_n = F_IDLE;
        end
      endcase
    end
  end

  always_comb begin
    ram_rd_en_o     = (state_r == F_READ) && !rd_pending_r;
    ram_rd_addr_o   = script_base_r + pc_r;
    ram_script_id_o = active_script_id_r;
    cmd_valid_o     = (state_r == F_WAIT_CONSUME);
    cmd_word_o      = cmd_word_r;
    pc_o            = pc_r;
    script_done_o   = (state_r == F_DONE);
    busy_o          = (state_r != F_IDLE) && (state_r != F_DONE);
    state_o         = state_r;
  end

endmodule
