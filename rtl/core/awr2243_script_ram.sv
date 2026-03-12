`include "awr2243_script_macros.svh"

module awr2243_script_ram #(
    parameter int unsigned WORD_W = `AWR2243_SCRIPT_WORD_W_DFLT,
    parameter int unsigned DEPTH = `AWR2243_SCRIPT_MEM_DEPTH_DFLT,
    parameter int unsigned SCRIPT_COUNT = `AWR2243_SCRIPT_TABLE_DEPTH_DFLT,
    parameter int unsigned ADDR_W = awr2243_script_pkg::clog2_safe(DEPTH),
    parameter int unsigned SCRIPT_ID_W = awr2243_script_pkg::clog2_safe(SCRIPT_COUNT),
    parameter int unsigned SCRIPT_LEN_W = awr2243_script_pkg::clog2_safe(DEPTH + 1)
) (
    input logic clk_i,
    input logic rst_ni,

    input logic              wr_en_i,
    input logic [ADDR_W-1:0] wr_addr_i,
    input logic [WORD_W-1:0] wr_data_i,

    input logic                    meta_wr_en_i,
    input logic [SCRIPT_ID_W-1:0]  meta_wr_script_id_i,
    input logic [ADDR_W-1:0]       meta_wr_base_addr_i,
    input logic [SCRIPT_LEN_W-1:0] meta_wr_len_i,

    input logic                    rd_en_i,
    input logic [ADDR_W-1:0]       rd_addr_i,
    output logic                   rd_valid_o,
    output logic [WORD_W-1:0]      rd_data_o,

    input logic [SCRIPT_ID_W-1:0]  script_id_i,
    output logic [ADDR_W-1:0]      script_base_addr_o,
    output logic [SCRIPT_LEN_W-1:0] script_len_o
);

  import awr2243_script_pkg::*;

  logic [WORD_W-1:0] word_mem_r [0:DEPTH-1];

  logic [ADDR_W-1:0] base_addr_r [0:SCRIPT_COUNT-1];
  logic [SCRIPT_LEN_W-1:0] script_len_r [0:SCRIPT_COUNT-1];

  logic               rd_valid_r;
  logic [WORD_W-1:0]  rd_data_r;

  integer script_idx;

  initial begin
    if (WORD_W < SCRIPT_WORD_W_DFLT) begin
      $fatal(1, "awr2243_script_ram requires WORD_W >= 64");
    end
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      rd_valid_r <= 1'b0;
      rd_data_r  <= '0;

      for (script_idx = 0; script_idx < SCRIPT_COUNT; script_idx++) begin
        base_addr_r[script_idx]  <= '0;
        script_len_r[script_idx] <= '0;
      end
    end else begin
      rd_valid_r <= rd_en_i;

      if (rd_en_i) begin
        rd_data_r <= word_mem_r[rd_addr_i];
        if (wr_en_i && (wr_addr_i == rd_addr_i)) begin
          rd_data_r <= wr_data_i;
        end
      end

      if (wr_en_i) begin
        word_mem_r[wr_addr_i] <= wr_data_i;
      end

      if (meta_wr_en_i) begin
        base_addr_r[meta_wr_script_id_i]  <= meta_wr_base_addr_i;
        script_len_r[meta_wr_script_id_i] <= meta_wr_len_i;
      end
    end
  end

  always_comb begin
    script_base_addr_o = base_addr_r[script_id_i];
    script_len_o       = script_len_r[script_id_i];
  end

  assign rd_valid_o = rd_valid_r;
  assign rd_data_o  = rd_data_r;

endmodule
