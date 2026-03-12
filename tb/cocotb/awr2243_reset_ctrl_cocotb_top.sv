module awr2243_reset_ctrl_cocotb_top;

  logic        sys_clk;
  logic        sys_rst_n;
  logic        req_enter_spi_mode_i;
  logic        req_hard_reset_i;
  logic        req_recovery_reset_i;
  logic        fault_active_i;
  logic        auto_recovery_en_i;
  logic [ 2:0] sop_mode_sel_i;
  logic [31:0] reset_hold_us_i;
  logic [31:0] post_reset_wait_us_i;

  logic        sop0_o;
  logic        sop1_o;
  logic        sop2_o;
  logic        nreset_o;
  logic        busy_o;
  logic        done_o;
  logic        err_o;
  logic [ 2:0] state_o;

  awr2243_reset_ctrl #(
      .CLK_FREQ_HZ(1_000_000)
  ) u_dut (
      .sys_clk             (sys_clk),
      .sys_rst_n           (sys_rst_n),
      .req_enter_spi_mode_i(req_enter_spi_mode_i),
      .req_hard_reset_i    (req_hard_reset_i),
      .req_recovery_reset_i(req_recovery_reset_i),
      .fault_active_i      (fault_active_i),
      .auto_recovery_en_i  (auto_recovery_en_i),
      .sop_mode_sel_i      (sop_mode_sel_i),
      .reset_hold_us_i     (reset_hold_us_i),
      .post_reset_wait_us_i(post_reset_wait_us_i),
      .sop0_o              (sop0_o),
      .sop1_o              (sop1_o),
      .sop2_o              (sop2_o),
      .nreset_o            (nreset_o),
      .busy_o              (busy_o),
      .done_o              (done_o),
      .err_o               (err_o),
      .state_o             (state_o)
  );

endmodule
