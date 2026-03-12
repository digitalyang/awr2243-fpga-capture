module awr2243_cmd_fetch_cocotb_top #(
    parameter int unsigned WORD_W = 64,
    parameter int unsigned DEPTH = 32,
    parameter int unsigned SCRIPT_COUNT = 8,
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

    input logic                   start_i,
    input logic [SCRIPT_ID_W-1:0] script_id_i,
    input logic                   advance_i,
    input logic                   hold_i,
    input logic                   jump_en_i,
    input logic [ADDR_W-1:0]      jump_addr_i,

    output logic              cmd_valid_o,
    output logic [WORD_W-1:0] cmd_word_o,
    output logic [ADDR_W-1:0] pc_o,
    output logic              script_done_o,
    output logic              busy_o,
    output logic [2:0]        state_o
);

  logic                   ram_rd_en_w;
  logic [ADDR_W-1:0]      ram_rd_addr_w;
  logic                   ram_rd_valid_w;
  logic [WORD_W-1:0]      ram_rd_data_w;
  logic [SCRIPT_ID_W-1:0] ram_script_id_w;
  logic [ADDR_W-1:0]      ram_script_base_w;
  logic [SCRIPT_LEN_W-1:0] ram_script_len_w;

  awr2243_script_ram #(
      .WORD_W(WORD_W),
      .DEPTH(DEPTH),
      .SCRIPT_COUNT(SCRIPT_COUNT),
      .ADDR_W(ADDR_W),
      .SCRIPT_ID_W(SCRIPT_ID_W),
      .SCRIPT_LEN_W(SCRIPT_LEN_W)
  ) script_ram (
      .clk_i            (clk_i),
      .rst_ni           (rst_ni),
      .wr_en_i          (wr_en_i),
      .wr_addr_i        (wr_addr_i),
      .wr_data_i        (wr_data_i),
      .meta_wr_en_i     (meta_wr_en_i),
      .meta_wr_script_id_i(meta_wr_script_id_i),
      .meta_wr_base_addr_i(meta_wr_base_addr_i),
      .meta_wr_len_i    (meta_wr_len_i),
      .rd_en_i          (ram_rd_en_w),
      .rd_addr_i        (ram_rd_addr_w),
      .rd_valid_o       (ram_rd_valid_w),
      .rd_data_o        (ram_rd_data_w),
      .script_id_i      (ram_script_id_w),
      .script_base_addr_o(ram_script_base_w),
      .script_len_o     (ram_script_len_w)
  );

  awr2243_cmd_fetch #(
      .WORD_W(WORD_W),
      .DEPTH(DEPTH),
      .SCRIPT_COUNT(SCRIPT_COUNT),
      .ADDR_W(ADDR_W),
      .SCRIPT_ID_W(SCRIPT_ID_W),
      .SCRIPT_LEN_W(SCRIPT_LEN_W)
  ) dut (
      .clk_i            (clk_i),
      .rst_ni           (rst_ni),
      .start_i          (start_i),
      .script_id_i      (script_id_i),
      .advance_i        (advance_i),
      .hold_i           (hold_i),
      .jump_en_i        (jump_en_i),
      .jump_addr_i      (jump_addr_i),
      .ram_rd_en_o      (ram_rd_en_w),
      .ram_rd_addr_o    (ram_rd_addr_w),
      .ram_rd_valid_i   (ram_rd_valid_w),
      .ram_rd_data_i    (ram_rd_data_w),
      .ram_script_id_o  (ram_script_id_w),
      .ram_script_base_i(ram_script_base_w),
      .ram_script_len_i (ram_script_len_w),
      .cmd_valid_o      (cmd_valid_o),
      .cmd_word_o       (cmd_word_o),
      .pc_o             (pc_o),
      .script_done_o    (script_done_o),
      .busy_o           (busy_o),
      .state_o          (state_o)
  );

endmodule
