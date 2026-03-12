`timescale 1ns / 1ps

module awr2243_cfg_sequencer #(
    parameter int unsigned                   SCRIPT_ID_W               = 8,
    parameter int unsigned                   ERR_CODE_W                = 16,
    parameter int unsigned                   STEP_ID_W                 = 16,
    parameter int unsigned                   OPCODE_W                  = 16,
    parameter int unsigned                   TIMEOUT_W                 = 32,
    parameter logic        [SCRIPT_ID_W-1:0] NULL_SCRIPT_ID            = {SCRIPT_ID_W{1'b1}},
    parameter logic        [ ERR_CODE_W-1:0] ERR_NONE                  = '0,
    parameter logic        [ ERR_CODE_W-1:0] ERR_INVALID_REQ           = 16'h0001,
    parameter logic        [ ERR_CODE_W-1:0] ERR_NOT_INITIALIZED       = 16'h0002,
    parameter logic        [ ERR_CODE_W-1:0] ERR_ALREADY_RUNNING       = 16'h0003,
    parameter logic        [ ERR_CODE_W-1:0] ERR_NOT_RUNNING           = 16'h0004,
    parameter logic        [ ERR_CODE_W-1:0] ERR_RESET_TIMEOUT         = 16'h0005,
    parameter logic        [ ERR_CODE_W-1:0] ERR_RESET_FAILED          = 16'h0006,
    parameter logic        [ ERR_CODE_W-1:0] ERR_SCRIPT_TIMEOUT        = 16'h0007,
    parameter logic        [ ERR_CODE_W-1:0] ERR_START_WAIT_TIMEOUT    = 16'h0008,
    parameter logic        [ ERR_CODE_W-1:0] ERR_FAULT_ACTIVE          = 16'h0009,
    parameter logic        [ ERR_CODE_W-1:0] ERR_INIT_WHILE_RUNNING    = 16'h000a,
    parameter logic        [ ERR_CODE_W-1:0] ERR_CMD_FAILURE_BASE      = 16'h0100,
    parameter logic        [  TIMEOUT_W-1:0] RESET_TIMEOUT_CYCLES      = 32'd100000,
    parameter logic        [  TIMEOUT_W-1:0] SCRIPT_TIMEOUT_CYCLES     = 32'd1000000,
    parameter logic        [  TIMEOUT_W-1:0] START_WAIT_TIMEOUT_CYCLES = 32'd1000000,
    parameter bit                            REQUIRE_START_IRQ         = 1'b1,
    parameter bit                            SKIP_NULL_SCRIPT_EN       = 1'b1
) (
    input  logic                   clk_i,
    input  logic                   rst_ni,
    input  logic                   start_init_i,
    input  logic                   start_sensor_i,
    input  logic                   stop_sensor_i,
    input  logic                   hard_reset_i,
    input  logic                   clear_error_i,
    input  logic [SCRIPT_ID_W-1:0] init_script_id_i,
    input  logic [SCRIPT_ID_W-1:0] rf_script_id_i,
    input  logic [SCRIPT_ID_W-1:0] profile_script_id_i,
    input  logic [SCRIPT_ID_W-1:0] frame_script_id_i,
    input  logic [SCRIPT_ID_W-1:0] monitor_script_id_i,
    input  logic [SCRIPT_ID_W-1:0] start_script_id_i,
    input  logic [SCRIPT_ID_W-1:0] stop_script_id_i,
    output logic                   req_enter_spi_mode_o,
    output logic                   req_hard_reset_o,
    output logic                   req_recovery_reset_o,
    output logic                   script_start_o,
    output logic [SCRIPT_ID_W-1:0] script_id_o,
    input  logic                   reset_done_i,
    input  logic                   reset_err_i,
    input  logic                   script_done_i,
    input  logic                   cmd_done_i,
    input  logic                   cmd_error_i,
    input  logic [ ERR_CODE_W-1:0] cmd_err_code_i,
    input  logic [  STEP_ID_W-1:0] cmd_step_id_i,
    input  logic [   OPCODE_W-1:0] cmd_last_opcode_i,
    input  logic                   host_irq_sticky_i,
    input  logic                   fault_active_i,
    input  logic                   fault_sticky_i,
    output logic                   busy_o,
    output logic                   done_o,
    output logic [ ERR_CODE_W-1:0] err_code_o,
    output logic [            3:0] state_o,
    output logic [SCRIPT_ID_W-1:0] active_script_o,
    output logic [  STEP_ID_W-1:0] step_id_o,
    output logic [   OPCODE_W-1:0] last_opcode_o
);

  typedef enum logic [3:0] {
    S_IDLE            = 4'd0,
    S_ENTER_SPI_MODE  = 4'd1,
    S_HW_RESET        = 4'd2,
    S_RUN_INIT_SCRIPT = 4'd3,
    S_RUN_RF_SCRIPT   = 4'd4,
    S_RUN_PROFILE     = 4'd5,
    S_RUN_FRAME       = 4'd6,
    S_RUN_MONITOR     = 4'd7,
    S_RUN_START       = 4'd8,
    S_RUN_WAIT_RUN    = 4'd9,
    S_RUN_STOP        = 4'd10,
    S_RECOVERY_RESET  = 4'd11,
    S_DONE            = 4'd12,
    S_ERROR           = 4'd13
  } sequencer_state_e;

  sequencer_state_e                   state_r;
  sequencer_state_e                   state_n;
  logic                               action_issued_r;
  logic                               action_issued_n;
  logic                               init_complete_r;
  logic                               init_complete_n;
  logic                               sensor_running_r;
  logic                               sensor_running_n;
  logic             [  TIMEOUT_W-1:0] timeout_count_r;
  logic             [  TIMEOUT_W-1:0] timeout_count_n;
  logic             [ ERR_CODE_W-1:0] err_code_r;
  logic             [ ERR_CODE_W-1:0] err_code_n;
  logic             [SCRIPT_ID_W-1:0] active_script_r;
  logic             [SCRIPT_ID_W-1:0] active_script_n;
  logic             [  STEP_ID_W-1:0] step_id_r;
  logic             [  STEP_ID_W-1:0] step_id_n;
  logic             [   OPCODE_W-1:0] last_opcode_r;
  logic             [   OPCODE_W-1:0] last_opcode_n;

  logic             [            2:0] request_count_c;
  logic                               fault_detect_c;
  logic                               track_timeout_c;
  logic                               timeout_hit_c;
  logic             [  TIMEOUT_W-1:0] timeout_limit_c;
  logic                               script_state_c;

  function automatic logic script_id_is_null(input logic [SCRIPT_ID_W-1:0] script_id);
    begin
      script_id_is_null = SKIP_NULL_SCRIPT_EN && (script_id == NULL_SCRIPT_ID);
    end
  endfunction

  function automatic logic [ERR_CODE_W-1:0] map_cmd_error(
      input logic [ERR_CODE_W-1:0] cmd_err_code);
    begin
      if (cmd_err_code == '0) begin
        map_cmd_error = ERR_CMD_FAILURE_BASE;
      end else begin
        map_cmd_error = ERR_CMD_FAILURE_BASE | cmd_err_code;
      end
    end
  endfunction

  function automatic logic is_script_state(input sequencer_state_e state);
    begin
      case (state)
        S_RUN_INIT_SCRIPT,
        S_RUN_RF_SCRIPT,
        S_RUN_PROFILE,
        S_RUN_FRAME,
        S_RUN_MONITOR,
        S_RUN_START,
        S_RUN_STOP: begin
          is_script_state = 1'b1;
        end
        default: begin
          is_script_state = 1'b0;
        end
      endcase
    end
  endfunction

  function automatic logic [TIMEOUT_W-1:0] timeout_limit_for_state(input sequencer_state_e state);
    begin
      case (state)
        S_ENTER_SPI_MODE, S_HW_RESET, S_RECOVERY_RESET: begin
          timeout_limit_for_state = RESET_TIMEOUT_CYCLES;
        end
        S_RUN_INIT_SCRIPT,
        S_RUN_RF_SCRIPT,
        S_RUN_PROFILE,
        S_RUN_FRAME,
        S_RUN_MONITOR,
        S_RUN_START,
        S_RUN_STOP: begin
          timeout_limit_for_state = SCRIPT_TIMEOUT_CYCLES;
        end
        S_RUN_WAIT_RUN: begin
          timeout_limit_for_state = START_WAIT_TIMEOUT_CYCLES;
        end
        default: begin
          timeout_limit_for_state = '0;
        end
      endcase
    end
  endfunction

  assign request_count_c = {2'b00, start_init_i} +
      {2'b00, start_sensor_i} + {2'b00, stop_sensor_i} + {2'b00, hard_reset_i};
  assign fault_detect_c = fault_active_i || fault_sticky_i;
  assign script_state_c = is_script_state(state_r);
  assign timeout_limit_c = timeout_limit_for_state(state_r);
  assign track_timeout_c = (((state_r == S_ENTER_SPI_MODE) ||
      (state_r == S_HW_RESET) || (state_r == S_RECOVERY_RESET) || script_state_c) &&
      action_issued_r && (timeout_limit_c != '0)) ||
      ((state_r == S_RUN_WAIT_RUN) && REQUIRE_START_IRQ && (timeout_limit_c != '0));
  assign timeout_hit_c = track_timeout_c && (timeout_count_r >= (timeout_limit_c - TIMEOUT_W'(1)));

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_r          <= S_IDLE;
      action_issued_r  <= 1'b0;
      init_complete_r  <= 1'b0;
      sensor_running_r <= 1'b0;
      timeout_count_r  <= '0;
      err_code_r       <= ERR_NONE;
      active_script_r  <= '0;
      step_id_r        <= '0;
      last_opcode_r    <= '0;
    end else begin
      state_r          <= state_n;
      action_issued_r  <= action_issued_n;
      init_complete_r  <= init_complete_n;
      sensor_running_r <= sensor_running_n;
      timeout_count_r  <= timeout_count_n;
      err_code_r       <= err_code_n;
      active_script_r  <= active_script_n;
      step_id_r        <= step_id_n;
      last_opcode_r    <= last_opcode_n;
    end
  end

  always_comb begin
    state_n          = state_r;
    action_issued_n  = action_issued_r;
    init_complete_n  = init_complete_r;
    sensor_running_n = sensor_running_r;
    timeout_count_n  = timeout_count_r;
    err_code_n       = err_code_r;
    active_script_n  = active_script_r;
    step_id_n        = step_id_r;
    last_opcode_n    = last_opcode_r;

    if ((cmd_done_i || cmd_error_i) && busy_o) begin
      step_id_n     = cmd_step_id_i;
      last_opcode_n = cmd_last_opcode_i;
    end

    if (clear_error_i && !busy_o) begin
      err_code_n      = ERR_NONE;
      step_id_n       = '0;
      last_opcode_n   = '0;
      active_script_n = '0;
      if (state_r == S_ERROR) begin
        state_n = S_IDLE;
      end
    end

    case (state_r)
      S_IDLE: begin
        action_issued_n = 1'b0;
        timeout_count_n = '0;
        active_script_n = '0;

        if (request_count_c > 3'd1) begin
          err_code_n = ERR_INVALID_REQ;
          state_n    = S_ERROR;
        end else if (hard_reset_i) begin
          err_code_n       = ERR_NONE;
          step_id_n        = '0;
          last_opcode_n    = '0;
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          state_n          = S_HW_RESET;
        end else if (start_init_i) begin
          if (sensor_running_r) begin
            err_code_n = ERR_INIT_WHILE_RUNNING;
            state_n    = S_ERROR;
          end else begin
            err_code_n      = ERR_NONE;
            step_id_n       = '0;
            last_opcode_n   = '0;
            init_complete_n = 1'b0;
            state_n         = S_ENTER_SPI_MODE;
          end
        end else if (start_sensor_i) begin
          if (fault_detect_c) begin
            err_code_n       = ERR_FAULT_ACTIVE;
            init_complete_n  = 1'b0;
            sensor_running_n = 1'b0;
            state_n          = S_RECOVERY_RESET;
          end else if (!init_complete_r) begin
            err_code_n = ERR_NOT_INITIALIZED;
            state_n    = S_ERROR;
          end else if (sensor_running_r) begin
            err_code_n = ERR_ALREADY_RUNNING;
            state_n    = S_ERROR;
          end else begin
            err_code_n      = ERR_NONE;
            step_id_n       = '0;
            last_opcode_n   = '0;
            active_script_n = start_script_id_i;
            state_n         = S_RUN_START;
          end
        end else if (stop_sensor_i) begin
          if (fault_detect_c) begin
            err_code_n       = ERR_FAULT_ACTIVE;
            init_complete_n  = 1'b0;
            sensor_running_n = 1'b0;
            state_n          = S_RECOVERY_RESET;
          end else if (!sensor_running_r) begin
            err_code_n = ERR_NOT_RUNNING;
            state_n    = S_ERROR;
          end else begin
            err_code_n      = ERR_NONE;
            step_id_n       = '0;
            last_opcode_n   = '0;
            active_script_n = stop_script_id_i;
            state_n         = S_RUN_STOP;
          end
        end
      end

      S_ENTER_SPI_MODE: begin
        if (!action_issued_r) begin
          action_issued_n = 1'b1;
        end else if (reset_err_i) begin
          err_code_n = ERR_RESET_FAILED;
          state_n    = S_ERROR;
        end else if (reset_done_i) begin
          active_script_n = init_script_id_i;
          state_n         = S_RUN_INIT_SCRIPT;
        end else if (timeout_hit_c) begin
          err_code_n = ERR_RESET_TIMEOUT;
          state_n    = S_ERROR;
        end
      end

      S_HW_RESET: begin
        if (!action_issued_r) begin
          action_issued_n = 1'b1;
        end else if (reset_err_i) begin
          err_code_n = ERR_RESET_FAILED;
          state_n    = S_ERROR;
        end else if (reset_done_i) begin
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          active_script_n  = '0;
          state_n          = S_DONE;
        end else if (timeout_hit_c) begin
          err_code_n = ERR_RESET_TIMEOUT;
          state_n    = S_ERROR;
        end
      end

      S_RUN_INIT_SCRIPT: begin
        if (script_id_is_null(active_script_r)) begin
          active_script_n = rf_script_id_i;
          state_n         = S_RUN_RF_SCRIPT;
        end else if (fault_detect_c) begin
          err_code_n       = ERR_FAULT_ACTIVE;
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          state_n          = S_RECOVERY_RESET;
        end else if (!action_issued_r) begin
          action_issued_n = 1'b1;
        end else if (cmd_error_i) begin
          err_code_n = map_cmd_error(cmd_err_code_i);
          state_n    = S_ERROR;
        end else if (script_done_i) begin
          active_script_n = rf_script_id_i;
          state_n         = S_RUN_RF_SCRIPT;
        end else if (timeout_hit_c) begin
          err_code_n = ERR_SCRIPT_TIMEOUT;
          state_n    = S_ERROR;
        end
      end

      S_RUN_RF_SCRIPT: begin
        if (script_id_is_null(active_script_r)) begin
          active_script_n = profile_script_id_i;
          state_n         = S_RUN_PROFILE;
        end else if (fault_detect_c) begin
          err_code_n       = ERR_FAULT_ACTIVE;
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          state_n          = S_RECOVERY_RESET;
        end else if (!action_issued_r) begin
          action_issued_n = 1'b1;
        end else if (cmd_error_i) begin
          err_code_n = map_cmd_error(cmd_err_code_i);
          state_n    = S_ERROR;
        end else if (script_done_i) begin
          active_script_n = profile_script_id_i;
          state_n         = S_RUN_PROFILE;
        end else if (timeout_hit_c) begin
          err_code_n = ERR_SCRIPT_TIMEOUT;
          state_n    = S_ERROR;
        end
      end

      S_RUN_PROFILE: begin
        if (script_id_is_null(active_script_r)) begin
          active_script_n = frame_script_id_i;
          state_n         = S_RUN_FRAME;
        end else if (fault_detect_c) begin
          err_code_n       = ERR_FAULT_ACTIVE;
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          state_n          = S_RECOVERY_RESET;
        end else if (!action_issued_r) begin
          action_issued_n = 1'b1;
        end else if (cmd_error_i) begin
          err_code_n = map_cmd_error(cmd_err_code_i);
          state_n    = S_ERROR;
        end else if (script_done_i) begin
          active_script_n = frame_script_id_i;
          state_n         = S_RUN_FRAME;
        end else if (timeout_hit_c) begin
          err_code_n = ERR_SCRIPT_TIMEOUT;
          state_n    = S_ERROR;
        end
      end

      S_RUN_FRAME: begin
        if (script_id_is_null(active_script_r)) begin
          active_script_n = monitor_script_id_i;
          state_n         = S_RUN_MONITOR;
        end else if (fault_detect_c) begin
          err_code_n       = ERR_FAULT_ACTIVE;
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          state_n          = S_RECOVERY_RESET;
        end else if (!action_issued_r) begin
          action_issued_n = 1'b1;
        end else if (cmd_error_i) begin
          err_code_n = map_cmd_error(cmd_err_code_i);
          state_n    = S_ERROR;
        end else if (script_done_i) begin
          active_script_n = monitor_script_id_i;
          state_n         = S_RUN_MONITOR;
        end else if (timeout_hit_c) begin
          err_code_n = ERR_SCRIPT_TIMEOUT;
          state_n    = S_ERROR;
        end
      end

      S_RUN_MONITOR: begin
        if (script_id_is_null(active_script_r)) begin
          init_complete_n = 1'b1;
          active_script_n = '0;
          state_n         = S_DONE;
        end else if (fault_detect_c) begin
          err_code_n       = ERR_FAULT_ACTIVE;
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          state_n          = S_RECOVERY_RESET;
        end else if (!action_issued_r) begin
          action_issued_n = 1'b1;
        end else if (cmd_error_i) begin
          err_code_n = map_cmd_error(cmd_err_code_i);
          state_n    = S_ERROR;
        end else if (script_done_i) begin
          init_complete_n = 1'b1;
          active_script_n = '0;
          state_n         = S_DONE;
        end else if (timeout_hit_c) begin
          err_code_n = ERR_SCRIPT_TIMEOUT;
          state_n    = S_ERROR;
        end
      end

      S_RUN_START: begin
        if (script_id_is_null(active_script_r)) begin
          state_n = S_RUN_WAIT_RUN;
        end else if (fault_detect_c) begin
          err_code_n       = ERR_FAULT_ACTIVE;
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          state_n          = S_RECOVERY_RESET;
        end else if (!action_issued_r) begin
          action_issued_n = 1'b1;
        end else if (cmd_error_i) begin
          err_code_n = map_cmd_error(cmd_err_code_i);
          state_n    = S_ERROR;
        end else if (script_done_i) begin
          if (REQUIRE_START_IRQ) begin
            state_n = S_RUN_WAIT_RUN;
          end else begin
            sensor_running_n = 1'b1;
            active_script_n  = '0;
            state_n          = S_DONE;
          end
        end else if (timeout_hit_c) begin
          err_code_n = ERR_SCRIPT_TIMEOUT;
          state_n    = S_ERROR;
        end
      end

      S_RUN_WAIT_RUN: begin
        if (fault_detect_c) begin
          err_code_n       = ERR_FAULT_ACTIVE;
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          state_n          = S_RECOVERY_RESET;
        end else if (!REQUIRE_START_IRQ || host_irq_sticky_i) begin
          sensor_running_n = 1'b1;
          active_script_n  = '0;
          state_n          = S_DONE;
        end else if (timeout_hit_c) begin
          err_code_n = ERR_START_WAIT_TIMEOUT;
          state_n    = S_ERROR;
        end
      end

      S_RUN_STOP: begin
        if (script_id_is_null(active_script_r)) begin
          sensor_running_n = 1'b0;
          active_script_n  = '0;
          state_n          = S_DONE;
        end else if (fault_detect_c) begin
          err_code_n       = ERR_FAULT_ACTIVE;
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          state_n          = S_RECOVERY_RESET;
        end else if (!action_issued_r) begin
          action_issued_n = 1'b1;
        end else if (cmd_error_i) begin
          err_code_n = map_cmd_error(cmd_err_code_i);
          state_n    = S_ERROR;
        end else if (script_done_i) begin
          sensor_running_n = 1'b0;
          active_script_n  = '0;
          state_n          = S_DONE;
        end else if (timeout_hit_c) begin
          err_code_n = ERR_SCRIPT_TIMEOUT;
          state_n    = S_ERROR;
        end
      end

      S_RECOVERY_RESET: begin
        if (!action_issued_r) begin
          action_issued_n = 1'b1;
        end else if (reset_err_i) begin
          err_code_n = ERR_RESET_FAILED;
          state_n    = S_ERROR;
        end else if (reset_done_i) begin
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          state_n          = S_ERROR;
        end else if (timeout_hit_c) begin
          err_code_n = ERR_RESET_TIMEOUT;
          state_n    = S_ERROR;
        end
      end

      S_DONE: begin
        active_script_n = '0;
        state_n         = S_IDLE;
      end

      S_ERROR: begin
        action_issued_n = 1'b0;
        timeout_count_n = '0;

        if (request_count_c > 3'd1) begin
          err_code_n = ERR_INVALID_REQ;
        end else if (hard_reset_i) begin
          err_code_n       = ERR_NONE;
          step_id_n        = '0;
          last_opcode_n    = '0;
          init_complete_n  = 1'b0;
          sensor_running_n = 1'b0;
          active_script_n  = '0;
          state_n          = S_HW_RESET;
        end else if (start_init_i) begin
          err_code_n      = ERR_NONE;
          step_id_n       = '0;
          last_opcode_n   = '0;
          init_complete_n = 1'b0;
          active_script_n = '0;
          state_n         = S_ENTER_SPI_MODE;
        end
      end

      default: begin
        state_n = S_IDLE;
      end
    endcase

    if (state_n != state_r) begin
      action_issued_n = 1'b0;
      timeout_count_n = '0;
    end else if (track_timeout_c && !timeout_hit_c) begin
      timeout_count_n = timeout_count_r + TIMEOUT_W'(1);
    end
  end

  always_comb begin
    req_enter_spi_mode_o = (state_r == S_ENTER_SPI_MODE) && !action_issued_r;
    req_hard_reset_o = (state_r == S_HW_RESET) && !action_issued_r;
    req_recovery_reset_o = (state_r == S_RECOVERY_RESET) && !action_issued_r;
    script_start_o = script_state_c && !action_issued_r && !script_id_is_null(active_script_r);
    script_id_o = active_script_r;
    busy_o = (state_r != S_IDLE) && (state_r != S_DONE) && (state_r != S_ERROR);
    done_o = (state_r == S_DONE);
    err_code_o = err_code_r;
    state_o = state_r;
    active_script_o = active_script_r;
    step_id_o = step_id_r;
    last_opcode_o = last_opcode_r;
  end

endmodule
