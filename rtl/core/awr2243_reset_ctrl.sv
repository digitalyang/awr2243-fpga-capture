module awr2243_reset_ctrl #(
    parameter int unsigned       CLK_FREQ_HZ   = 100_000_000,
    parameter int unsigned       TIMER_VALUE_W = 32,
    parameter logic        [2:0] SOP_MODE_SPI  = 3'b001
) (
    input  logic                     sys_clk,
    input  logic                     sys_rst_n,
    input  logic                     req_enter_spi_mode_i,
    input  logic                     req_hard_reset_i,
    input  logic                     req_recovery_reset_i,
    input  logic                     fault_active_i,
    input  logic                     auto_recovery_en_i,
    input  logic [              2:0] sop_mode_sel_i,
    input  logic [TIMER_VALUE_W-1:0] reset_hold_us_i,
    input  logic [TIMER_VALUE_W-1:0] post_reset_wait_us_i,
    output logic                     sop0_o,
    output logic                     sop1_o,
    output logic                     sop2_o,
    output logic                     nreset_o,
    output logic                     busy_o,
    output logic                     done_o,
    output logic                     err_o,
    output logic [              2:0] state_o
);

  typedef enum logic [2:0] {
    RST_IDLE,
    RST_DRIVE_SOP,
    RST_ASSERT_NRESET,
    RST_HOLD,
    RST_RELEASE,
    RST_WAIT_BOOT,
    RST_DONE
  } reset_state_e;

  localparam int unsigned REQ_COUNT_W = 2;
  localparam logic [TIMER_VALUE_W-1:0] TIMER_ZERO = '0;
  localparam int unsigned TIMER_CYCLES_PER_US = (CLK_FREQ_HZ + 1_000_000 - 1) / 1_000_000;
  localparam int unsigned TIMER_COUNT_W = TIMER_VALUE_W + ((TIMER_CYCLES_PER_US > 1) ? $clog2(
      TIMER_CYCLES_PER_US
  ) : 0);

  reset_state_e                     state_r;
  reset_state_e                     state_n;
  logic         [              2:0] sop_r;
  logic         [              2:0] sop_n;
  logic         [              2:0] target_sop_r;
  logic         [              2:0] target_sop_n;
  logic                             nreset_r;
  logic                             nreset_n;
  logic                             done_r;
  logic                             done_n;
  logic                             err_r;
  logic                             err_n;
  logic                             fault_active_dly_r;
  logic                             fault_active_dly_n;
  logic                             recovery_pending_r;
  logic                             recovery_pending_n;

  logic                             timer_start_c;
  logic                             timer_busy_c;
  logic                             timer_done_c;
  logic         [TIMER_VALUE_W-1:0] timer_period_value_c;
  /* verilator lint_off UNUSED */
  logic                             timer_expired_unused_c;
  logic         [TIMER_COUNT_W-1:0] timer_count_dbg_unused_c;
  /* verilator lint_on UNUSED */

  logic         [  REQ_COUNT_W-1:0] request_count_c;
  logic                             fault_assert_c;

  assign request_count_c = REQ_COUNT_W'(req_enter_spi_mode_i) +
      REQ_COUNT_W'(req_hard_reset_i) + REQ_COUNT_W'(req_recovery_reset_i);
  assign fault_assert_c = auto_recovery_en_i && fault_active_i && !fault_active_dly_r;

  always_comb begin
    state_n              = state_r;
    sop_n                = sop_r;
    target_sop_n         = target_sop_r;
    nreset_n             = nreset_r;
    done_n               = 1'b0;
    err_n                = 1'b0;
    fault_active_dly_n   = fault_active_i;
    recovery_pending_n   = recovery_pending_r;

    timer_start_c        = 1'b0;
    timer_period_value_c = TIMER_ZERO;

    if (fault_assert_c) begin
      recovery_pending_n = 1'b1;
    end

    if ((state_r != RST_IDLE) && (req_enter_spi_mode_i || req_hard_reset_i || req_recovery_reset_i)) begin
      err_n = 1'b1;
    end

    case (state_r)
      RST_IDLE: begin
        if (request_count_c > REQ_COUNT_W'(1)) begin
          err_n = 1'b1;
        end else if (req_hard_reset_i) begin
          target_sop_n       = sop_mode_sel_i;
          recovery_pending_n = 1'b0;
          state_n            = RST_DRIVE_SOP;
        end else if (req_enter_spi_mode_i) begin
          // Functional SPI mode is encoded as [SOP2 SOP1 SOP0] = [0 0 1].
          target_sop_n       = SOP_MODE_SPI;
          recovery_pending_n = 1'b0;
          state_n            = RST_DRIVE_SOP;
        end else if (req_recovery_reset_i || recovery_pending_r) begin
          target_sop_n       = sop_r;
          recovery_pending_n = 1'b0;
          state_n            = RST_DRIVE_SOP;
        end
      end

      RST_DRIVE_SOP: begin
        sop_n   = target_sop_r;
        state_n = RST_ASSERT_NRESET;
      end

      RST_ASSERT_NRESET: begin
        nreset_n = 1'b0;

        if (!timer_busy_c) begin
          timer_start_c        = 1'b1;
          timer_period_value_c = reset_hold_us_i;
          state_n              = RST_HOLD;
        end
      end

      RST_HOLD: begin
        nreset_n = 1'b0;

        if (timer_done_c) begin
          state_n = RST_RELEASE;
        end
      end

      RST_RELEASE: begin
        nreset_n = 1'b1;

        if (!timer_busy_c) begin
          timer_start_c        = 1'b1;
          timer_period_value_c = post_reset_wait_us_i;
          state_n              = RST_WAIT_BOOT;
        end
      end

      RST_WAIT_BOOT: begin
        nreset_n = 1'b1;

        if (timer_done_c) begin
          state_n = RST_DONE;
        end
      end

      RST_DONE: begin
        nreset_n = 1'b1;
        done_n   = 1'b1;
        state_n  = RST_IDLE;
      end

      default: begin
        state_n = RST_IDLE;
      end
    endcase
  end

  always_ff @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
      state_r            <= RST_IDLE;
      sop_r              <= SOP_MODE_SPI;
      target_sop_r       <= SOP_MODE_SPI;
      nreset_r           <= 1'b0;
      done_r             <= 1'b0;
      err_r              <= 1'b0;
      fault_active_dly_r <= 1'b0;
      recovery_pending_r <= 1'b0;
    end else begin
      state_r            <= state_n;
      sop_r              <= sop_n;
      target_sop_r       <= target_sop_n;
      nreset_r           <= nreset_n;
      done_r             <= done_n;
      err_r              <= err_n;
      fault_active_dly_r <= fault_active_dly_n;
      recovery_pending_r <= recovery_pending_n;
    end
  end

  awr2243_timer #(
      .CLK_FREQ_HZ   (CLK_FREQ_HZ),
      .PERIOD_VALUE_W(TIMER_VALUE_W)
  ) u_reset_timer (
      .clk_i         (sys_clk),
      .rst_ni        (sys_rst_n),
      .start_i       (timer_start_c),
      .clear_i       (1'b0),
      .period_value_i(timer_period_value_c),
      .period_unit_i (1'b1),
      .busy_o        (timer_busy_c),
      .done_o        (timer_done_c),
      .expired_o     (timer_expired_unused_c),
      .count_dbg_o   (timer_count_dbg_unused_c)
  );

  assign sop0_o   = sop_r[0];
  assign sop1_o   = sop_r[1];
  assign sop2_o   = sop_r[2];
  assign nreset_o = nreset_r;
  assign busy_o   = (state_r != RST_IDLE) && (state_r != RST_DONE);
  assign done_o   = done_r;
  assign err_o    = err_r;
  assign state_o  = state_r;

endmodule
