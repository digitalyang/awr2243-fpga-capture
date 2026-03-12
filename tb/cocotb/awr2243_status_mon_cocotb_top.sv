module awr2243_status_mon_cocotb_top;

  logic sys_clk;
  logic sys_rst_n;
  logic host_irq_i;
  logic nerror_out_i;
  logic warm_reset_i;
  logic arm_i;
  logic clr_irq_sticky_i;
  logic clr_fault_sticky_i;
  logic clr_warm_reset_sticky_i;

  logic        host_irq_rise_o;
  logic        host_irq_sticky_o;
  logic        fault_active_o;
  logic        fault_sticky_o;
  logic        warm_reset_rise_o;
  logic        warm_reset_sticky_o;
  logic [31:0] irq_count_o;
  logic [31:0] fault_count_o;
  logic [31:0] warm_reset_count_o;
  logic        host_irq_sync_o;
  logic        nerror_out_sync_o;
  logic        warm_reset_sync_o;

  awr2243_status_mon u_dut (
      .sys_clk(sys_clk),
      .sys_rst_n(sys_rst_n),
      .host_irq_i(host_irq_i),
      .nerror_out_i(nerror_out_i),
      .warm_reset_i(warm_reset_i),
      .arm_i(arm_i),
      .clr_irq_sticky_i(clr_irq_sticky_i),
      .clr_fault_sticky_i(clr_fault_sticky_i),
      .clr_warm_reset_sticky_i(clr_warm_reset_sticky_i),
      .host_irq_rise_o(host_irq_rise_o),
      .host_irq_sticky_o(host_irq_sticky_o),
      .fault_active_o(fault_active_o),
      .fault_sticky_o(fault_sticky_o),
      .warm_reset_rise_o(warm_reset_rise_o),
      .warm_reset_sticky_o(warm_reset_sticky_o),
      .irq_count_o(irq_count_o),
      .fault_count_o(fault_count_o),
      .warm_reset_count_o(warm_reset_count_o),
      .host_irq_sync_o(host_irq_sync_o),
      .nerror_out_sync_o(nerror_out_sync_o),
      .warm_reset_sync_o(warm_reset_sync_o)
  );

endmodule
