`include "awr2243_script_macros.svh"

module awr2243_cmd_decode #(
    parameter int unsigned WORD_W = `AWR2243_SCRIPT_WORD_W_DFLT,
    parameter int unsigned PC_W = awr2243_script_pkg::clog2_safe(`AWR2243_SCRIPT_MEM_DEPTH_DFLT),
    parameter int unsigned STEP_ID_W = `AWR2243_SCRIPT_STEP_ID_W_DFLT,
    parameter int unsigned ERR_CODE_W = `AWR2243_SCRIPT_ERR_CODE_W_DFLT,
    parameter int unsigned TIMER_VALUE_W = `AWR2243_SCRIPT_TIMER_VALUE_W_DFLT,
    parameter int unsigned TIMER_UNIT_W = `AWR2243_SCRIPT_TIMER_UNIT_W_DFLT
) (
    input  logic clk_i,
    input  logic rst_ni,

    input  logic              cmd_valid_i,
    input  logic [WORD_W-1:0] cmd_word_i,
    input  logic [PC_W-1:0]   pc_i,

    output logic              fetch_advance_o,
    output logic              fetch_hold_o,
    output logic              jump_en_o,
    output logic [PC_W-1:0]   jump_addr_o,

    output logic                  cmd_done_o,
    output logic                  cmd_error_o,
    output logic [ERR_CODE_W-1:0] error_code_o,
    output logic [STEP_ID_W-1:0]  step_id_o,
    output logic [7:0]            last_opcode_o,
    output logic                  busy_o,
    output logic [3:0]            state_o,

    output logic        spi_cmd_valid_o,
    input  logic        spi_cmd_ready_i,
    output logic        spi_cmd_is_read_o,
    output logic [15:0] spi_cmd_word_o,
    input  logic        spi_rsp_valid_i,
    input  logic [15:0] spi_rsp_word_i,
    input  logic        spi_busy_i,
    input  logic        spi_done_i,
    input  logic        spi_timeout_i,

    output logic                     timer_start_o,
    output logic                     timer_clear_o,
    output logic [TIMER_VALUE_W-1:0] timer_period_value_o,
    output logic [TIMER_UNIT_W-1:0]  timer_period_unit_o,
    input  logic                     timer_busy_i,
    input  logic                     timer_done_i,
    input  logic                     timer_expired_i,

    output logic clr_irq_sticky_o,
    output logic clr_fault_sticky_o,
    input  logic host_irq_rise_i,
    input  logic host_irq_sticky_i,
    input  logic fault_active_i,
    input  logic fault_sticky_i
);

  import awr2243_script_pkg::*;

  typedef enum logic [3:0] {
    D_IDLE,
    D_PULSE_DONE,
    D_PULSE_JUMP,
    D_PULSE_ERROR,
    D_PULSE_ERROR_ADV,
    D_ERROR_HOLD,
    D_SPI_REQ,
    D_SPI_WAIT,
    D_DELAY_ARM,
    D_DELAY_WAIT,
    D_WAIT_IRQ_ARM,
    D_WAIT_IRQ
  } decode_state_e;

  decode_state_e state_r, state_n;

  logic [WORD_W-1:0]        cmd_word_r, cmd_word_n;
  logic [7:0]               opcode_r, opcode_n;
  logic [7:0]               flags_r, flags_n;
  logic [STEP_ID_W-1:0]     step_id_r, step_id_n;
  logic [15:0]              imm_a_r, imm_a_n;
  logic [15:0]              imm_b_r, imm_b_n;
  logic [TIMER_VALUE_W-1:0] timer_value_r, timer_value_n;
  logic [PC_W-1:0]          cmd_pc_r, cmd_pc_n;
  logic [15:0]              spi_rsp_word_r, spi_rsp_word_n;
  logic [ERR_CODE_W-1:0]    error_code_r, error_code_n;

  logic [63:0]              accept_word_c;
  logic [15:0]              spi_rsp_cmp_c;
  logic [15:0]              imm_b_cmd_c;
  logic [31:0]              imm32_cmd_c;
  logic [ERR_CODE_W-1:0]    fail_err_code_c;

  initial begin
    if (WORD_W < SCRIPT_WORD_W_DFLT) begin
      $fatal(1, "awr2243_cmd_decode requires WORD_W >= 64");
    end
  end

  assign accept_word_c   = cmd_word_i[63:0];
  assign spi_rsp_cmp_c   = spi_rsp_valid_i ? spi_rsp_word_i : spi_rsp_word_r;
  assign imm_b_cmd_c     = cmd_imm_b(accept_word_c);
  assign imm32_cmd_c     = cmd_imm32(accept_word_c);
  assign fail_err_code_c = imm_b_cmd_c[ERR_CODE_W-1:0];

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_r        <= D_IDLE;
      cmd_word_r     <= '0;
      opcode_r       <= AWR_CMD_NOP;
      flags_r        <= '0;
      step_id_r      <= '0;
      imm_a_r        <= '0;
      imm_b_r        <= '0;
      timer_value_r  <= '0;
      cmd_pc_r       <= '0;
      spi_rsp_word_r <= '0;
      error_code_r   <= AWR_CMD_ERR_NONE;
    end else begin
      state_r        <= state_n;
      cmd_word_r     <= cmd_word_n;
      opcode_r       <= opcode_n;
      flags_r        <= flags_n;
      step_id_r      <= step_id_n;
      imm_a_r        <= imm_a_n;
      imm_b_r        <= imm_b_n;
      timer_value_r  <= timer_value_n;
      cmd_pc_r       <= cmd_pc_n;
      spi_rsp_word_r <= spi_rsp_word_n;
      error_code_r   <= error_code_n;
    end
  end

  always_comb begin
    state_n        = state_r;
    cmd_word_n     = cmd_word_r;
    opcode_n       = opcode_r;
    flags_n        = flags_r;
    step_id_n      = step_id_r;
    imm_a_n        = imm_a_r;
    imm_b_n        = imm_b_r;
    timer_value_n  = timer_value_r;
    cmd_pc_n       = cmd_pc_r;
    spi_rsp_word_n = spi_rsp_word_r;
    error_code_n   = error_code_r;

    case (state_r)
      D_IDLE: begin
        if (cmd_valid_i) begin
          cmd_word_n    = cmd_word_i;
          opcode_n      = cmd_opcode(accept_word_c);
          flags_n       = cmd_flags(accept_word_c);
          step_id_n     = STEP_ID_W'(cmd_step_id(accept_word_c));
          imm_a_n       = cmd_imm_a(accept_word_c);
          imm_b_n       = imm_b_cmd_c;
          timer_value_n = TIMER_VALUE_W'(imm32_cmd_c);
          cmd_pc_n      = pc_i;

          case (cmd_opcode(accept_word_c))
            AWR_CMD_NOP,
            AWR_CMD_END: begin
              state_n = D_PULSE_DONE;
            end

            AWR_CMD_JUMP: begin
              state_n = D_PULSE_JUMP;
            end

            AWR_CMD_FAIL: begin
              error_code_n = (fail_err_code_c != {ERR_CODE_W{1'b0}}) ?
                             fail_err_code_c : AWR_CMD_ERR_FAIL_OPCODE;
              state_n = D_PULSE_ERROR_ADV;
            end

            AWR_CMD_CHECK_FAULT: begin
              if (fault_active_i || fault_sticky_i) begin
                error_code_n = AWR_CMD_ERR_FAULT_ACTIVE;
                state_n      = D_PULSE_ERROR;
              end else begin
                state_n = D_PULSE_DONE;
              end
            end

            AWR_CMD_SPI_WR,
            AWR_CMD_SPI_RD: begin
              spi_rsp_word_n = 16'd0;
              state_n        = D_SPI_REQ;
            end

            AWR_CMD_DELAY_US: begin
              if (imm32_cmd_c == 32'd0) begin
                state_n = D_PULSE_DONE;
              end else begin
                state_n = D_DELAY_ARM;
              end
            end

            AWR_CMD_WAIT_IRQ: begin
              state_n = D_WAIT_IRQ_ARM;
            end

            default: begin
              error_code_n = AWR_CMD_ERR_INVALID_OPCODE;
              state_n      = D_PULSE_ERROR;
            end
          endcase
        end
      end

      D_PULSE_DONE: begin
        state_n = D_IDLE;
      end

      D_PULSE_JUMP: begin
        state_n = D_IDLE;
      end

      D_PULSE_ERROR: begin
        state_n = D_ERROR_HOLD;
      end

      D_PULSE_ERROR_ADV: begin
        state_n = D_IDLE;
      end

      D_ERROR_HOLD: begin
        if (!cmd_valid_i) begin
          state_n = D_IDLE;
        end
      end

      D_SPI_REQ: begin
        if (spi_cmd_ready_i) begin
          state_n = D_SPI_WAIT;
        end
      end

      D_SPI_WAIT: begin
        if (spi_rsp_valid_i) begin
          spi_rsp_word_n = spi_rsp_word_i;
        end

        if (spi_timeout_i) begin
          error_code_n = AWR_CMD_ERR_SPI_TIMEOUT;
          state_n      = D_PULSE_ERROR;
        end else if (spi_done_i) begin
          if ((opcode_r == AWR_CMD_SPI_RD) &&
              flags_r[SPI_RD_FLAG_COMPARE_BIT] &&
              (spi_rsp_cmp_c != imm_a_r)) begin
            error_code_n = AWR_CMD_ERR_SPI_MISMATCH;
            state_n      = D_PULSE_ERROR;
          end else begin
            state_n = D_PULSE_DONE;
          end
        end
      end

      D_DELAY_ARM: begin
        if (!timer_busy_i) begin
          state_n = D_DELAY_WAIT;
        end
      end

      D_DELAY_WAIT: begin
        if (timer_done_i || timer_expired_i) begin
          state_n = D_PULSE_DONE;
        end
      end

      D_WAIT_IRQ_ARM: begin
        if (host_irq_rise_i) begin
          state_n = D_PULSE_DONE;
        end else if (timer_value_r == {TIMER_VALUE_W{1'b0}}) begin
          state_n = D_WAIT_IRQ;
        end else if (!timer_busy_i) begin
          state_n = D_WAIT_IRQ;
        end
      end

      D_WAIT_IRQ: begin
        if (host_irq_rise_i || host_irq_sticky_i) begin
          state_n = D_PULSE_DONE;
        end else if ((timer_value_r != {TIMER_VALUE_W{1'b0}}) &&
                     (timer_done_i || timer_expired_i)) begin
          error_code_n = AWR_CMD_ERR_WAIT_IRQ_TO;
          state_n      = D_PULSE_ERROR;
        end
      end

      default: begin
        state_n = D_IDLE;
      end
    endcase
  end

  always_comb begin
    fetch_advance_o      = 1'b0;
    fetch_hold_o         = 1'b0;
    jump_en_o            = 1'b0;
    jump_addr_o          = PC_W'(imm_b_r[PC_W-1:0]);
    cmd_done_o           = 1'b0;
    cmd_error_o          = 1'b0;
    spi_cmd_valid_o      = 1'b0;
    spi_cmd_is_read_o    = 1'b0;
    spi_cmd_word_o       = imm_b_r;
    timer_start_o        = 1'b0;
    timer_clear_o        = 1'b0;
    timer_period_value_o = timer_value_r;
    timer_period_unit_o  = AWR_TIMER_UNIT_US;
    clr_irq_sticky_o     = 1'b0;
    clr_fault_sticky_o   = 1'b0;

    case (state_r)
      D_PULSE_DONE: begin
        fetch_advance_o = 1'b1;
        cmd_done_o      = 1'b1;
      end

      D_PULSE_JUMP: begin
        jump_en_o  = 1'b1;
        cmd_done_o = 1'b1;
      end

      D_PULSE_ERROR: begin
        cmd_error_o = 1'b1;
      end

      D_PULSE_ERROR_ADV: begin
        fetch_advance_o = 1'b1;
        cmd_error_o     = 1'b1;
      end

      D_SPI_REQ: begin
        fetch_hold_o      = 1'b1;
        spi_cmd_valid_o   = 1'b1;
        spi_cmd_is_read_o = (opcode_r == AWR_CMD_SPI_RD);
      end

      D_SPI_WAIT: begin
        fetch_hold_o = 1'b1;
      end

      D_DELAY_ARM: begin
        fetch_hold_o = 1'b1;
        if (!timer_busy_i) begin
          timer_start_o = 1'b1;
        end
      end

      D_DELAY_WAIT: begin
        fetch_hold_o = 1'b1;
        if (timer_done_i || timer_expired_i) begin
          timer_clear_o = 1'b1;
        end
      end

      D_WAIT_IRQ_ARM: begin
        fetch_hold_o     = 1'b1;
        clr_irq_sticky_o = 1'b1;
        if ((timer_value_r != {TIMER_VALUE_W{1'b0}}) &&
            !timer_busy_i &&
            !host_irq_rise_i) begin
          timer_start_o = 1'b1;
        end
      end

      D_WAIT_IRQ: begin
        fetch_hold_o = 1'b1;
        if ((host_irq_rise_i || host_irq_sticky_i) ||
            ((timer_value_r != {TIMER_VALUE_W{1'b0}}) &&
             (timer_done_i || timer_expired_i))) begin
          timer_clear_o = (timer_value_r != {TIMER_VALUE_W{1'b0}});
        end
      end

      default: begin
      end
    endcase
  end

  assign error_code_o  = error_code_r;
  assign step_id_o     = step_id_r;
  assign last_opcode_o = opcode_r;
  assign busy_o        = (state_r != D_IDLE) && (state_r != D_ERROR_HOLD);
  assign state_o       = state_r;

endmodule
