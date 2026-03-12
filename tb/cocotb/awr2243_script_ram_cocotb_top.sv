module awr2243_script_ram_cocotb_top #(
    parameter int unsigned WORD_W       = 64,
    parameter int unsigned DEPTH        = 32,
    parameter int unsigned SCRIPT_COUNT = 8,
    parameter int unsigned ADDR_W       = awr2243_script_pkg::clog2_safe(DEPTH),
    parameter int unsigned SCRIPT_ID_W  = awr2243_script_pkg::clog2_safe(SCRIPT_COUNT),
    parameter int unsigned SCRIPT_LEN_W = awr2243_script_pkg::clog2_safe(DEPTH + 1)
) (
    input logic clk_i,
    input logic rst_ni,

    input logic              wr_en_i,
    input logic [ADDR_W-1:0] wr_addr_i,
    input logic [WORD_W-1:0] wr_data_i,

    input logic                    meta_wr_en_i,
    input logic [ SCRIPT_ID_W-1:0] meta_wr_script_id_i,
    input logic [      ADDR_W-1:0] meta_wr_base_addr_i,
    input logic [SCRIPT_LEN_W-1:0] meta_wr_len_i,

    input  logic              rd_en_i,
    input  logic [ADDR_W-1:0] rd_addr_i,
    output logic              rd_valid_o,
    output logic [WORD_W-1:0] rd_data_o,

    input  logic [ SCRIPT_ID_W-1:0] script_id_i,
    output logic [      ADDR_W-1:0] script_base_addr_o,
    output logic [SCRIPT_LEN_W-1:0] script_len_o
);

  awr2243_script_ram #(
      .WORD_W      (WORD_W),
      .DEPTH       (DEPTH),
      .SCRIPT_COUNT(SCRIPT_COUNT),
      .ADDR_W      (ADDR_W),
      .SCRIPT_ID_W (SCRIPT_ID_W),
      .SCRIPT_LEN_W(SCRIPT_LEN_W)
  ) dut (
      .clk_i              (clk_i),
      .rst_ni             (rst_ni),
      .wr_en_i            (wr_en_i),
      .wr_addr_i          (wr_addr_i),
      .wr_data_i          (wr_data_i),
      .meta_wr_en_i       (meta_wr_en_i),
      .meta_wr_script_id_i(meta_wr_script_id_i),
      .meta_wr_base_addr_i(meta_wr_base_addr_i),
      .meta_wr_len_i      (meta_wr_len_i),
      .rd_en_i            (rd_en_i),
      .rd_addr_i          (rd_addr_i),
      .rd_valid_o         (rd_valid_o),
      .rd_data_o          (rd_data_o),
      .script_id_i        (script_id_i),
      .script_base_addr_o (script_base_addr_o),
      .script_len_o       (script_len_o)
  );

endmodule
