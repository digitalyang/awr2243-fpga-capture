`include "awr2243_script_macros.svh"

package awr2243_script_pkg;

  localparam int unsigned SCRIPT_WORD_W_DFLT = `AWR2243_SCRIPT_WORD_W_DFLT;
  localparam int unsigned SCRIPT_OPCODE_W_DFLT = `AWR2243_SCRIPT_OPCODE_W_DFLT;
  localparam int unsigned SCRIPT_FLAGS_W_DFLT = `AWR2243_SCRIPT_FLAGS_W_DFLT;
  localparam int unsigned SCRIPT_STEP_ID_W_DFLT = `AWR2243_SCRIPT_STEP_ID_W_DFLT;
  localparam int unsigned SCRIPT_ERR_CODE_W_DFLT = `AWR2243_SCRIPT_ERR_CODE_W_DFLT;

  localparam int unsigned SCRIPT_OPCODE_MSB = 63;
  localparam int unsigned SCRIPT_OPCODE_LSB = 56;
  localparam int unsigned SCRIPT_FLAGS_MSB = 55;
  localparam int unsigned SCRIPT_FLAGS_LSB = 48;
  localparam int unsigned SCRIPT_STEP_MSB = 47;
  localparam int unsigned SCRIPT_STEP_LSB = 32;
  localparam int unsigned SCRIPT_IMM_A_MSB = 31;
  localparam int unsigned SCRIPT_IMM_A_LSB = 16;
  localparam int unsigned SCRIPT_IMM_B_MSB = 15;
  localparam int unsigned SCRIPT_IMM_B_LSB = 0;

  localparam int unsigned SPI_RD_FLAG_COMPARE_BIT = 0;

  typedef enum logic [SCRIPT_OPCODE_W_DFLT-1:0] {
    AWR_CMD_NOP         = 8'h00,
    AWR_CMD_SPI_WR      = 8'h01,
    AWR_CMD_SPI_RD      = 8'h02,
    AWR_CMD_DELAY_US    = 8'h03,
    AWR_CMD_WAIT_IRQ    = 8'h04,
    AWR_CMD_CHECK_FAULT = 8'h05,
    AWR_CMD_END         = 8'h06,
    AWR_CMD_FAIL        = 8'h07,
    AWR_CMD_JUMP        = 8'h08
  } awr2243_cmd_opcode_e;

  typedef enum logic [`AWR2243_SCRIPT_TIMER_UNIT_W_DFLT-1:0] {
    AWR_TIMER_UNIT_CYCLES = 2'd0,
    AWR_TIMER_UNIT_US     = 2'd1
  } awr2243_timer_unit_e;

  typedef enum logic [SCRIPT_ERR_CODE_W_DFLT-1:0] {
    AWR_CMD_ERR_NONE           = 8'h00,
    AWR_CMD_ERR_INVALID_OPCODE = 8'h01,
    AWR_CMD_ERR_SPI_TIMEOUT    = 8'h02,
    AWR_CMD_ERR_SPI_MISMATCH   = 8'h03,
    AWR_CMD_ERR_WAIT_IRQ_TO    = 8'h04,
    AWR_CMD_ERR_FAULT_ACTIVE   = 8'h05,
    AWR_CMD_ERR_FAIL_OPCODE    = 8'h06
  } awr2243_cmd_err_e;

  function automatic int unsigned clog2_safe(input int unsigned value);
    if (value <= 1) begin
      return 1;
    end

    return $clog2(value);
  endfunction

  function automatic logic [7:0] cmd_opcode(input logic [63:0] word);
    return word[SCRIPT_OPCODE_MSB:SCRIPT_OPCODE_LSB];
  endfunction

  function automatic logic [7:0] cmd_flags(input logic [63:0] word);
    return word[SCRIPT_FLAGS_MSB:SCRIPT_FLAGS_LSB];
  endfunction

  function automatic logic [15:0] cmd_step_id(input logic [63:0] word);
    return word[SCRIPT_STEP_MSB:SCRIPT_STEP_LSB];
  endfunction

  function automatic logic [15:0] cmd_imm_a(input logic [63:0] word);
    return word[SCRIPT_IMM_A_MSB:SCRIPT_IMM_A_LSB];
  endfunction

  function automatic logic [15:0] cmd_imm_b(input logic [63:0] word);
    return word[SCRIPT_IMM_B_MSB:SCRIPT_IMM_B_LSB];
  endfunction

  function automatic logic [31:0] cmd_imm32(input logic [63:0] word);
    return {cmd_imm_a(word), cmd_imm_b(word)};
  endfunction

  function automatic bit opcode_is_supported(input logic [7:0] opcode);
    case (opcode)
      AWR_CMD_NOP,
      AWR_CMD_SPI_WR,
      AWR_CMD_SPI_RD,
      AWR_CMD_DELAY_US,
      AWR_CMD_WAIT_IRQ,
      AWR_CMD_CHECK_FAULT,
      AWR_CMD_END,
      AWR_CMD_FAIL,
      AWR_CMD_JUMP: begin
        return 1'b1;
      end
      default: begin
        return 1'b0;
      end
    endcase
  endfunction

endpackage
