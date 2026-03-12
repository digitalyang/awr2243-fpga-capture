// Shared delay/timeout primitive for AWR2243 control-path state machines.
// `period_unit_i == 1'b0` selects raw clock cycles.
// `period_unit_i == 1'b1` selects microseconds scaled by CYCLES_PER_US.
module awr2243_timer #(
    parameter int unsigned CLK_FREQ_HZ    = 100_000_000,
    parameter int unsigned PERIOD_VALUE_W = 32,
    parameter int unsigned CYCLES_PER_US  = ((CLK_FREQ_HZ + 1_000_000 - 1) / 1_000_000),
    parameter int unsigned COUNT_W        = PERIOD_VALUE_W + ((CYCLES_PER_US > 1) ? $clog2(CYCLES_PER_US) : 0)
) (
    input  logic                      clk_i,
    input  logic                      rst_ni,
    input  logic                      start_i,
    input  logic                      clear_i,
    input  logic [PERIOD_VALUE_W-1:0] period_value_i,
    input  logic                      period_unit_i,
    output logic                      busy_o,
    output logic                      done_o,
    output logic                      expired_o,
    output logic [       COUNT_W-1:0] count_dbg_o
);

  typedef enum logic {
    TMR_IDLE,
    TMR_RUN
  } timer_state_e;

  typedef enum logic {
    TMR_UNIT_CYCLE,
    TMR_UNIT_US
  } timer_unit_e;

  localparam int unsigned MIN_COUNT_W = PERIOD_VALUE_W + ((CYCLES_PER_US > 1) ? $clog2(CYCLES_PER_US) : 0);
  localparam logic [COUNT_W-1:0] COUNT_ONE = COUNT_W'(1);

  timer_state_e            state_r;
  timer_state_e            state_n;
  logic [COUNT_W-1:0]      count_r;
  logic [COUNT_W-1:0]      count_n;
  logic                    done_r;
  logic                    done_n;
  logic                    expired_r;
  logic                    expired_n;
  timer_unit_e             period_unit_c;
  logic [COUNT_W-1:0]      requested_cycles_c;

  function automatic logic [COUNT_W-1:0] calc_requested_cycles(
      input logic [PERIOD_VALUE_W-1:0] period_value,
      input timer_unit_e               period_unit
  );
    logic [COUNT_W-1:0] period_value_ext_c;
    logic [COUNT_W-1:0] scaled_value_c;
    begin
      period_value_ext_c = COUNT_W'(period_value);
      scaled_value_c     = period_value_ext_c;

      if (period_unit == TMR_UNIT_US) begin
        scaled_value_c = period_value_ext_c * COUNT_W'(CYCLES_PER_US);
      end

      return scaled_value_c;
    end
  endfunction

  assign period_unit_c      = timer_unit_e'(period_unit_i);
  assign requested_cycles_c = calc_requested_cycles(period_value_i, period_unit_c);

  assign busy_o      = (state_r == TMR_RUN);
  assign done_o      = done_r;
  assign expired_o   = expired_r;
  assign count_dbg_o = count_r;

  always_comb begin
    state_n   = state_r;
    count_n   = count_r;
    done_n    = 1'b0;
    expired_n = 1'b0;

    case (state_r)
      TMR_IDLE: begin
        count_n = '0;

        if (start_i) begin
          if (requested_cycles_c == '0) begin
            done_n    = 1'b1;
            expired_n = 1'b1;
          end else begin
            // The timer accepts a new request only from IDLE; callers gate with busy_o.
            state_n = TMR_RUN;
            count_n = requested_cycles_c;
          end
        end
      end

      TMR_RUN: begin
        if (clear_i) begin
          state_n = TMR_IDLE;
          count_n = '0;
        end else if (count_r == COUNT_ONE) begin
          state_n   = TMR_IDLE;
          count_n   = '0;
          done_n    = 1'b1;
          expired_n = 1'b1;
        end else begin
          count_n = count_r - COUNT_ONE;
        end
      end

      default: begin
        state_n = TMR_IDLE;
        count_n = '0;
      end
    endcase
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_r   <= TMR_IDLE;
      count_r   <= '0;
      done_r    <= 1'b0;
      expired_r <= 1'b0;
    end else begin
      state_r   <= state_n;
      count_r   <= count_n;
      done_r    <= done_n;
      expired_r <= expired_n;
    end
  end

  initial begin
    if (CLK_FREQ_HZ == 0) begin
      $error("%m CLK_FREQ_HZ must be non-zero");
      $fatal;
    end

    if (PERIOD_VALUE_W == 0) begin
      $error("%m PERIOD_VALUE_W must be at least 1");
      $fatal;
    end

    if (CYCLES_PER_US == 0) begin
      $error("%m CYCLES_PER_US must be at least 1");
      $fatal;
    end

    if (COUNT_W < MIN_COUNT_W) begin
      $error("%m COUNT_W must cover the largest scaled cycle count");
      $fatal;
    end
  end

endmodule
