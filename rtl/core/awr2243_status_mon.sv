module awr2243_status_mon #(
    parameter int unsigned COUNT_W = 32,
    parameter int unsigned IRQ_FILTER_CYCLES = 1,
    parameter int unsigned NERROR_FILTER_CYCLES = 1,
    parameter int unsigned WARM_RESET_FILTER_CYCLES = 1
) (
    input  logic                    sys_clk,
    input  logic                    sys_rst_n,
    input  logic                    host_irq_i,
    input  logic                    nerror_out_i,
    input  logic                    warm_reset_i,
    input  logic                    arm_i,
    input  logic                    clr_irq_sticky_i,
    input  logic                    clr_fault_sticky_i,
    input  logic                    clr_warm_reset_sticky_i,
    output logic                    host_irq_rise_o,
    output logic                    host_irq_sticky_o,
    output logic                    fault_active_o,
    output logic                    fault_sticky_o,
    output logic                    warm_reset_rise_o,
    output logic                    warm_reset_sticky_o,
    output logic [      COUNT_W-1:0] irq_count_o,
    output logic [      COUNT_W-1:0] fault_count_o,
    output logic [      COUNT_W-1:0] warm_reset_count_o,
    output logic                    host_irq_sync_o,
    output logic                    nerror_out_sync_o,
    output logic                    warm_reset_sync_o
);

  localparam int unsigned IRQ_FILTER_LEN = (IRQ_FILTER_CYCLES < 1) ? 1 : IRQ_FILTER_CYCLES;
  localparam int unsigned NERROR_FILTER_LEN =
      (NERROR_FILTER_CYCLES < 1) ? 1 : NERROR_FILTER_CYCLES;
  localparam int unsigned WARM_RESET_FILTER_LEN =
      (WARM_RESET_FILTER_CYCLES < 1) ? 1 : WARM_RESET_FILTER_CYCLES;

  localparam int unsigned IRQ_FILTER_CNT_W = (IRQ_FILTER_LEN <= 1) ? 1 : $clog2(IRQ_FILTER_LEN);
  localparam int unsigned NERROR_FILTER_CNT_W =
      (NERROR_FILTER_LEN <= 1) ? 1 : $clog2(NERROR_FILTER_LEN);
  localparam int unsigned WARM_RESET_FILTER_CNT_W =
      (WARM_RESET_FILTER_LEN <= 1) ? 1 : $clog2(WARM_RESET_FILTER_LEN);

  function automatic logic [COUNT_W-1:0] sat_inc(input logic [COUNT_W-1:0] value);
    begin
      if (&value) begin
        sat_inc = value;
      end else begin
        sat_inc = value + COUNT_W'(1);
      end
    end
  endfunction

  logic host_irq_sync_ff1_r;
  logic host_irq_sync_ff2_r;
  logic nerror_sync_ff1_r;
  logic nerror_sync_ff2_r;
  logic warm_reset_sync_ff1_r;
  logic warm_reset_sync_ff2_r;

  logic host_irq_level_r;
  logic host_irq_level_n;
  logic nerror_level_r;
  logic nerror_level_n;
  logic warm_reset_level_r;
  logic warm_reset_level_n;

  logic [IRQ_FILTER_CNT_W-1:0] irq_filter_cnt_r;
  logic [IRQ_FILTER_CNT_W-1:0] irq_filter_cnt_n;
  logic [NERROR_FILTER_CNT_W-1:0] nerror_filter_cnt_r;
  logic [NERROR_FILTER_CNT_W-1:0] nerror_filter_cnt_n;
  logic [WARM_RESET_FILTER_CNT_W-1:0] warm_reset_filter_cnt_r;
  logic [WARM_RESET_FILTER_CNT_W-1:0] warm_reset_filter_cnt_n;

  logic host_irq_sticky_r;
  logic host_irq_sticky_n;
  logic fault_sticky_r;
  logic fault_sticky_n;
  logic warm_reset_sticky_r;
  logic warm_reset_sticky_n;

  logic [COUNT_W-1:0] irq_count_r;
  logic [COUNT_W-1:0] irq_count_n;
  logic [COUNT_W-1:0] fault_count_r;
  logic [COUNT_W-1:0] fault_count_n;
  logic [COUNT_W-1:0] warm_reset_count_r;
  logic [COUNT_W-1:0] warm_reset_count_n;

  logic host_irq_rise_r;
  logic host_irq_rise_n;
  logic warm_reset_rise_r;
  logic warm_reset_rise_n;

  logic host_irq_rise_c;
  logic fault_assert_c;
  logic warm_reset_rise_c;

  always_comb begin
    host_irq_level_n = host_irq_level_r;
    nerror_level_n = nerror_level_r;
    warm_reset_level_n = warm_reset_level_r;

    irq_filter_cnt_n = irq_filter_cnt_r;
    nerror_filter_cnt_n = nerror_filter_cnt_r;
    warm_reset_filter_cnt_n = warm_reset_filter_cnt_r;

    host_irq_sticky_n = host_irq_sticky_r;
    fault_sticky_n = fault_sticky_r;
    warm_reset_sticky_n = warm_reset_sticky_r;

    irq_count_n = irq_count_r;
    fault_count_n = fault_count_r;
    warm_reset_count_n = warm_reset_count_r;

    host_irq_rise_n = 1'b0;
    warm_reset_rise_n = 1'b0;

    if (host_irq_sync_ff2_r == host_irq_level_r) begin
      irq_filter_cnt_n = '0;
    end else if (irq_filter_cnt_r == IRQ_FILTER_CNT_W'(IRQ_FILTER_LEN - 1)) begin
      host_irq_level_n = host_irq_sync_ff2_r;
      irq_filter_cnt_n = '0;
    end else begin
      irq_filter_cnt_n = irq_filter_cnt_r + IRQ_FILTER_CNT_W'(1);
    end

    if (nerror_sync_ff2_r == nerror_level_r) begin
      nerror_filter_cnt_n = '0;
    end else if (nerror_filter_cnt_r == NERROR_FILTER_CNT_W'(NERROR_FILTER_LEN - 1)) begin
      nerror_level_n = nerror_sync_ff2_r;
      nerror_filter_cnt_n = '0;
    end else begin
      nerror_filter_cnt_n = nerror_filter_cnt_r + NERROR_FILTER_CNT_W'(1);
    end

    if (warm_reset_sync_ff2_r == warm_reset_level_r) begin
      warm_reset_filter_cnt_n = '0;
    end else if (warm_reset_filter_cnt_r == WARM_RESET_FILTER_CNT_W'(WARM_RESET_FILTER_LEN - 1)) begin
      warm_reset_level_n = warm_reset_sync_ff2_r;
      warm_reset_filter_cnt_n = '0;
    end else begin
      warm_reset_filter_cnt_n = warm_reset_filter_cnt_r + WARM_RESET_FILTER_CNT_W'(1);
    end

    host_irq_rise_c = arm_i && host_irq_level_n && !host_irq_level_r;
    fault_assert_c = arm_i && !nerror_level_n && nerror_level_r;
    warm_reset_rise_c = arm_i && warm_reset_level_n && !warm_reset_level_r;

    host_irq_rise_n = host_irq_rise_c;
    warm_reset_rise_n = warm_reset_rise_c;

    if (clr_irq_sticky_i) begin
      host_irq_sticky_n = 1'b0;
    end
    if (clr_fault_sticky_i) begin
      fault_sticky_n = 1'b0;
    end
    if (clr_warm_reset_sticky_i) begin
      warm_reset_sticky_n = 1'b0;
    end

    if (host_irq_rise_c) begin
      host_irq_sticky_n = 1'b1;
      irq_count_n = sat_inc(irq_count_r);
    end

    // NERROR_OUT is active-low; the sticky bit records each new low-going assertion.
    if (fault_assert_c) begin
      fault_sticky_n = 1'b1;
      fault_count_n = sat_inc(fault_count_r);
    end

    if (warm_reset_rise_c) begin
      warm_reset_sticky_n = 1'b1;
      warm_reset_count_n = sat_inc(warm_reset_count_r);
    end
  end

  always_ff @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
      host_irq_sync_ff1_r <= 1'b0;
      host_irq_sync_ff2_r <= 1'b0;
      nerror_sync_ff1_r <= 1'b1;
      nerror_sync_ff2_r <= 1'b1;
      warm_reset_sync_ff1_r <= 1'b0;
      warm_reset_sync_ff2_r <= 1'b0;

      host_irq_level_r <= 1'b0;
      nerror_level_r <= 1'b1;
      warm_reset_level_r <= 1'b0;

      irq_filter_cnt_r <= '0;
      nerror_filter_cnt_r <= '0;
      warm_reset_filter_cnt_r <= '0;

      host_irq_sticky_r <= 1'b0;
      fault_sticky_r <= 1'b0;
      warm_reset_sticky_r <= 1'b0;

      irq_count_r <= '0;
      fault_count_r <= '0;
      warm_reset_count_r <= '0;

      host_irq_rise_r <= 1'b0;
      warm_reset_rise_r <= 1'b0;
    end else begin
      host_irq_sync_ff1_r <= host_irq_i;
      host_irq_sync_ff2_r <= host_irq_sync_ff1_r;
      nerror_sync_ff1_r <= nerror_out_i;
      nerror_sync_ff2_r <= nerror_sync_ff1_r;
      warm_reset_sync_ff1_r <= warm_reset_i;
      warm_reset_sync_ff2_r <= warm_reset_sync_ff1_r;

      host_irq_level_r <= host_irq_level_n;
      nerror_level_r <= nerror_level_n;
      warm_reset_level_r <= warm_reset_level_n;

      irq_filter_cnt_r <= irq_filter_cnt_n;
      nerror_filter_cnt_r <= nerror_filter_cnt_n;
      warm_reset_filter_cnt_r <= warm_reset_filter_cnt_n;

      host_irq_sticky_r <= host_irq_sticky_n;
      fault_sticky_r <= fault_sticky_n;
      warm_reset_sticky_r <= warm_reset_sticky_n;

      irq_count_r <= irq_count_n;
      fault_count_r <= fault_count_n;
      warm_reset_count_r <= warm_reset_count_n;

      host_irq_rise_r <= host_irq_rise_n;
      warm_reset_rise_r <= warm_reset_rise_n;
    end
  end

  assign host_irq_rise_o = host_irq_rise_r;
  assign host_irq_sticky_o = host_irq_sticky_r;
  assign fault_active_o = !nerror_level_r;
  assign fault_sticky_o = fault_sticky_r;
  assign warm_reset_rise_o = warm_reset_rise_r;
  assign warm_reset_sticky_o = warm_reset_sticky_r;
  assign irq_count_o = irq_count_r;
  assign fault_count_o = fault_count_r;
  assign warm_reset_count_o = warm_reset_count_r;
  assign host_irq_sync_o = host_irq_level_r;
  assign nerror_out_sync_o = nerror_level_r;
  assign warm_reset_sync_o = warm_reset_level_r;

endmodule
