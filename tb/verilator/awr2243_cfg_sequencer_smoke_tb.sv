`timescale 1ns / 1ps

module awr2243_cfg_sequencer_smoke_tb;

  localparam logic [3:0] S_IDLE = 4'd0;
  localparam logic [3:0] S_ERROR = 4'd13;
  localparam logic [15:0] ERR_FAULT_ACTIVE = 16'h0009;
  localparam logic [15:0] ERR_NOT_INITIALIZED = 16'h0002;
  localparam logic [15:0] ERR_CMD_FAILURE_BASE = 16'h0100;

  logic        clk_i;
  logic        rst_ni;
  logic        start_init_i;
  logic        start_sensor_i;
  logic        stop_sensor_i;
  logic        hard_reset_i;
  logic        clear_error_i;
  logic [ 7:0] init_script_id_i;
  logic [ 7:0] rf_script_id_i;
  logic [ 7:0] profile_script_id_i;
  logic [ 7:0] frame_script_id_i;
  logic [ 7:0] monitor_script_id_i;
  logic [ 7:0] start_script_id_i;
  logic [ 7:0] stop_script_id_i;
  logic        req_enter_spi_mode_o;
  logic        req_hard_reset_o;
  logic        req_recovery_reset_o;
  logic        script_start_o;
  logic [ 7:0] script_id_o;
  logic        reset_done_i;
  logic        reset_err_i;
  logic        script_done_i;
  logic        cmd_done_i;
  logic        cmd_error_i;
  logic [15:0] cmd_err_code_i;
  logic [15:0] cmd_step_id_i;
  logic [15:0] cmd_last_opcode_i;
  logic        host_irq_sticky_i;
  logic        fault_active_i;
  logic        fault_sticky_i;
  logic        busy_o;
  logic        done_o;
  logic [15:0] err_code_o;
  logic [ 3:0] state_o;
  logic [ 7:0] active_script_o;
  logic [15:0] step_id_o;
  logic [15:0] last_opcode_o;

  awr2243_cfg_sequencer #(
      .RESET_TIMEOUT_CYCLES     (32'd16),
      .SCRIPT_TIMEOUT_CYCLES    (32'd32),
      .START_WAIT_TIMEOUT_CYCLES(32'd16)
  ) dut (
      .clk_i               (clk_i),
      .rst_ni              (rst_ni),
      .start_init_i        (start_init_i),
      .start_sensor_i      (start_sensor_i),
      .stop_sensor_i       (stop_sensor_i),
      .hard_reset_i        (hard_reset_i),
      .clear_error_i       (clear_error_i),
      .init_script_id_i    (init_script_id_i),
      .rf_script_id_i      (rf_script_id_i),
      .profile_script_id_i (profile_script_id_i),
      .frame_script_id_i   (frame_script_id_i),
      .monitor_script_id_i (monitor_script_id_i),
      .start_script_id_i   (start_script_id_i),
      .stop_script_id_i    (stop_script_id_i),
      .req_enter_spi_mode_o(req_enter_spi_mode_o),
      .req_hard_reset_o    (req_hard_reset_o),
      .req_recovery_reset_o(req_recovery_reset_o),
      .script_start_o      (script_start_o),
      .script_id_o         (script_id_o),
      .reset_done_i        (reset_done_i),
      .reset_err_i         (reset_err_i),
      .script_done_i       (script_done_i),
      .cmd_done_i          (cmd_done_i),
      .cmd_error_i         (cmd_error_i),
      .cmd_err_code_i      (cmd_err_code_i),
      .cmd_step_id_i       (cmd_step_id_i),
      .cmd_last_opcode_i   (cmd_last_opcode_i),
      .host_irq_sticky_i   (host_irq_sticky_i),
      .fault_active_i      (fault_active_i),
      .fault_sticky_i      (fault_sticky_i),
      .busy_o              (busy_o),
      .done_o              (done_o),
      .err_code_o          (err_code_o),
      .state_o             (state_o),
      .active_script_o     (active_script_o),
      .step_id_o           (step_id_o),
      .last_opcode_o       (last_opcode_o)
  );

  always #5 clk_i = ~clk_i;

  task automatic tick();
    begin
      @(posedge clk_i);
      #1;
    end
  endtask

  task automatic pulse(ref logic signal);
    begin
      signal = 1'b1;
      tick();
      signal = 1'b0;
    end
  endtask

  task automatic wait_high(ref logic signal, input int unsigned max_cycles, input string label);
    int unsigned idx;
    begin
      if (signal === 1'b1) begin
        return;
      end

      for (idx = 0; idx < max_cycles; idx++) begin
        tick();
        if (signal === 1'b1) begin
          return;
        end
      end

      $fatal(1, "Timeout waiting for %s", label);
    end
  endtask

  task automatic wait_state(input logic [3:0] expected_state, input int unsigned max_cycles,
                            input string label);
    int unsigned idx;
    begin
      for (idx = 0; idx < max_cycles; idx++) begin
        tick();
        if (state_o == expected_state) begin
          return;
        end
      end

      $fatal(1, "Timeout waiting for state %s", label);
    end
  endtask

  task automatic expect_eq16(input logic [15:0] actual, input logic [15:0] expected,
                             input string label);
    begin
      if (actual !== expected) begin
        $fatal(1, "%s mismatch: got 0x%04h expected 0x%04h", label, actual, expected);
      end
    end
  endtask

  task automatic expect_eq8(input logic [7:0] actual, input logic [7:0] expected,
                            input string label);
    begin
      if (actual !== expected) begin
        $fatal(1, "%s mismatch: got 0x%02h expected 0x%02h", label, actual, expected);
      end
    end
  endtask

  task automatic apply_reset();
    begin
      start_init_i        = 1'b0;
      start_sensor_i      = 1'b0;
      stop_sensor_i       = 1'b0;
      hard_reset_i        = 1'b0;
      clear_error_i       = 1'b0;
      reset_done_i        = 1'b0;
      reset_err_i         = 1'b0;
      script_done_i       = 1'b0;
      cmd_done_i          = 1'b0;
      cmd_error_i         = 1'b0;
      cmd_err_code_i      = '0;
      cmd_step_id_i       = '0;
      cmd_last_opcode_i   = '0;
      host_irq_sticky_i   = 1'b0;
      fault_active_i      = 1'b0;
      fault_sticky_i      = 1'b0;

      init_script_id_i    = 8'h10;
      rf_script_id_i      = 8'h11;
      profile_script_id_i = 8'h12;
      frame_script_id_i   = 8'h13;
      monitor_script_id_i = 8'h14;
      start_script_id_i   = 8'h20;
      stop_script_id_i    = 8'h21;

      rst_ni              = 1'b0;
      repeat (5) begin
        tick();
      end
      rst_ni = 1'b1;
      tick();
      wait_state(S_IDLE, 4, "idle after reset");
      expect_eq16(err_code_o, 16'h0000, "err_code_o");
    end
  endtask

  task automatic complete_reset_stage(ref logic request_signal, input string label);
    begin
      wait_high(request_signal, 16, label);
      tick();
      pulse(reset_done_i);
    end
  endtask

  task automatic finish_script(input logic [7:0] expected_script_id, input logic [15:0] step_id,
                               input logic [15:0] opcode);
    begin
      wait_high(script_start_o, 16, "script_start_o");
      expect_eq8(script_id_o, expected_script_id, "script_id_o");
      tick();
      cmd_step_id_i     = step_id;
      cmd_last_opcode_i = opcode;
      pulse(cmd_done_i);
      pulse(script_done_i);
    end
  endtask

  task automatic test_init_start_stop_happy_path();
    begin
      $display("[tb] test_init_start_stop_happy_path");
      apply_reset();

      pulse(start_init_i);
      complete_reset_stage(req_enter_spi_mode_o, "req_enter_spi_mode_o");

      finish_script(8'h10, 16'h0010, 16'h0031);
      finish_script(8'h11, 16'h0011, 16'h0032);
      finish_script(8'h12, 16'h0012, 16'h0033);
      finish_script(8'h13, 16'h0013, 16'h0034);
      finish_script(8'h14, 16'h0014, 16'h0035);

      wait_high(done_o, 16, "done_o after init");
      expect_eq16(err_code_o, 16'h0000, "err_code_o after init");
      expect_eq16(step_id_o, 16'h0014, "step_id_o after init");
      expect_eq16(last_opcode_o, 16'h0035, "last_opcode_o after init");
      wait_state(S_IDLE, 4, "idle after init");

      pulse(start_sensor_i);
      wait_high(script_start_o, 16, "start script");
      expect_eq8(script_id_o, 8'h20, "start script_id_o");
      tick();
      pulse(script_done_i);
      host_irq_sticky_i = 1'b1;
      wait_high(done_o, 16, "done_o after sensor start");
      host_irq_sticky_i = 1'b0;
      wait_state(S_IDLE, 4, "idle after sensor start");

      pulse(stop_sensor_i);
      wait_high(script_start_o, 16, "stop script");
      expect_eq8(script_id_o, 8'h21, "stop script_id_o");
      tick();
      pulse(script_done_i);
      wait_high(done_o, 16, "done_o after sensor stop");
      expect_eq16(err_code_o, 16'h0000, "err_code_o after sensor stop");
      wait_state(S_IDLE, 4, "idle after sensor stop");
    end
  endtask

  task automatic test_cmd_error_latches_and_clear_rearms();
    begin
      $display("[tb] test_cmd_error_latches_and_clear_rearms");
      apply_reset();

      pulse(start_init_i);
      complete_reset_stage(req_enter_spi_mode_o, "req_enter_spi_mode_o");
      wait_high(script_start_o, 16, "init script start");
      expect_eq8(script_id_o, 8'h10, "init script id");

      tick();
      cmd_err_code_i    = 16'h0023;
      cmd_step_id_i     = 16'h0077;
      cmd_last_opcode_i = 16'h0055;
      pulse(cmd_error_i);

      wait_state(S_ERROR, 8, "error after cmd_error_i");
      expect_eq16(err_code_o, ERR_CMD_FAILURE_BASE | 16'h0023, "err_code_o cmd error");
      expect_eq16(step_id_o, 16'h0077, "step_id_o cmd error");
      expect_eq16(last_opcode_o, 16'h0055, "last_opcode_o cmd error");
      expect_eq8(active_script_o, 8'h10, "active_script_o cmd error");

      pulse(clear_error_i);
      wait_state(S_IDLE, 8, "idle after clear_error_i");
      expect_eq16(err_code_o, 16'h0000, "err_code_o after clear");

      pulse(hard_reset_i);
      complete_reset_stage(req_hard_reset_o, "req_hard_reset_o");
      wait_high(done_o, 16, "done_o after hard reset");
      wait_state(S_IDLE, 4, "idle after hard reset");
    end
  endtask

  task automatic test_fault_forces_recovery_reset();
    begin
      $display("[tb] test_fault_forces_recovery_reset");
      apply_reset();

      pulse(start_init_i);
      complete_reset_stage(req_enter_spi_mode_o, "req_enter_spi_mode_o");

      wait_high(script_start_o, 16, "init script start before fault");
      expect_eq8(script_id_o, 8'h10, "init script id before fault");
      tick();
      pulse(script_done_i);

      wait_high(script_start_o, 16, "rf script start before fault");
      expect_eq8(script_id_o, 8'h11, "rf script id before fault");
      fault_active_i = 1'b1;

      wait_high(req_recovery_reset_o, 16, "req_recovery_reset_o");
      tick();
      pulse(reset_done_i);
      wait_state(S_ERROR, 8, "error after recovery reset");
      expect_eq16(err_code_o, ERR_FAULT_ACTIVE, "err_code_o fault");
      expect_eq8(active_script_o, 8'h11, "active_script_o fault");

      fault_active_i = 1'b0;
      pulse(clear_error_i);
      wait_state(S_IDLE, 8, "idle after fault clear");

      pulse(start_sensor_i);
      wait_state(S_ERROR, 8, "error after start without init");
      expect_eq16(err_code_o, ERR_NOT_INITIALIZED, "err_code_o not initialized");
    end
  endtask

  initial begin
    clk_i = 1'b0;

    test_init_start_stop_happy_path();
    test_cmd_error_latches_and_clear_rearms();
    test_fault_forces_recovery_reset();

    $display("[tb] awr2243_cfg_sequencer smoke tests passed");
    $finish;
  end

endmodule
