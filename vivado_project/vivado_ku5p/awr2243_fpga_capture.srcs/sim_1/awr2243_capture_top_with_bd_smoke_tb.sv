`timescale 1ns / 1ps

module awr2243_capture_top_with_bd_smoke_tb;

  localparam time SYS_CLK_HALF_PERIOD_NS   = 5ns;
  localparam time VIDEO_CLK_HALF_PERIOD_NS = 2.5ns;
  localparam time AXI_CLK_HALF_PERIOD_NS   = 2ns;
  localparam time REFCLK_HALF_PERIOD_NS    = 5ns;
  localparam time RESET_HOLD_TIME          = 1us;
  localparam time SIM_RUN_TIME             = 10us;

  logic sys_clk        = 1'b0;
  logic sys_rst_n      = 1'b0;
  logic video_aclk     = 1'b0;
  logic axi_aclk       = 1'b0;

  logic       pcie_refclk_p = 1'b0;
  logic       pcie_refclk_n = 1'b1;
  logic       ddr4_refclk_p = 1'b0;
  logic       ddr4_refclk_n = 1'b1;
  logic       csi_rx_clk_p  = 1'b0;
  logic       csi_rx_clk_n  = 1'b1;
  logic [3:0] csi_rx_data_p = 4'h0;
  logic [3:0] csi_rx_data_n = 4'hf;

  logic [7:0] pcie_rxp = 8'h00;
  logic [7:0] pcie_rxn = 8'hff;
  logic [7:0] pcie_txp;
  logic [7:0] pcie_txn;

  tri [63:0] ddr4_dq;
  tri [7:0]  ddr4_dqs_c;
  tri [7:0]  ddr4_dqs_t;
  logic [16:0] ddr4_adr;
  logic [1:0]  ddr4_ba;
  logic [1:0]  ddr4_bg;
  logic        ddr4_ck_c;
  logic        ddr4_ck_t;
  logic        ddr4_cke;
  logic        ddr4_cs_n;
  logic        ddr4_act_n;
  logic        ddr4_odt;
  logic        ddr4_reset_n;
  tri [7:0]    ddr4_dm_n;

  logic spi_sclk_o;
  logic spi_cs_n_o;
  logic spi_mosi_o;
  logic spi_miso_i   = 1'b0;
  logic sop0_o;
  logic sop1_o;
  logic sop2_o;
  logic nreset_o;
  logic host_irq_i   = 1'b0;
  logic nerror_out_i = 1'b1;

  int unsigned sys_clk_edges   = 0;
  int unsigned video_clk_edges = 0;
  int unsigned axi_clk_edges   = 0;

  awr2243_capture_top_with_bd dut (
      .sys_clk       (sys_clk),
      .sys_rst_n     (sys_rst_n),
      .video_aclk    (video_aclk),
      .axi_aclk      (axi_aclk),
      .pcie_refclk_p (pcie_refclk_p),
      .pcie_refclk_n (pcie_refclk_n),
      .ddr4_refclk_p (ddr4_refclk_p),
      .ddr4_refclk_n (ddr4_refclk_n),
      .csi_rx_clk_p  (csi_rx_clk_p),
      .csi_rx_clk_n  (csi_rx_clk_n),
      .csi_rx_data_p (csi_rx_data_p),
      .csi_rx_data_n (csi_rx_data_n),
      .pcie_rxp      (pcie_rxp),
      .pcie_rxn      (pcie_rxn),
      .pcie_txp      (pcie_txp),
      .pcie_txn      (pcie_txn),
      .ddr4_dq       (ddr4_dq),
      .ddr4_dqs_c    (ddr4_dqs_c),
      .ddr4_dqs_t    (ddr4_dqs_t),
      .ddr4_adr      (ddr4_adr),
      .ddr4_ba       (ddr4_ba),
      .ddr4_bg       (ddr4_bg),
      .ddr4_ck_c     (ddr4_ck_c),
      .ddr4_ck_t     (ddr4_ck_t),
      .ddr4_cke      (ddr4_cke),
      .ddr4_cs_n     (ddr4_cs_n),
      .ddr4_act_n    (ddr4_act_n),
      .ddr4_odt      (ddr4_odt),
      .ddr4_reset_n  (ddr4_reset_n),
      .ddr4_dm_n     (ddr4_dm_n),
      .spi_sclk_o    (spi_sclk_o),
      .spi_cs_n_o    (spi_cs_n_o),
      .spi_mosi_o    (spi_mosi_o),
      .spi_miso_i    (spi_miso_i),
      .sop0_o        (sop0_o),
      .sop1_o        (sop1_o),
      .sop2_o        (sop2_o),
      .nreset_o      (nreset_o),
      .host_irq_i    (host_irq_i),
      .nerror_out_i  (nerror_out_i)
  );

  always #(SYS_CLK_HALF_PERIOD_NS) sys_clk = ~sys_clk;
  always #(VIDEO_CLK_HALF_PERIOD_NS) video_aclk = ~video_aclk;
  always #(AXI_CLK_HALF_PERIOD_NS) axi_aclk = ~axi_aclk;

  always @(posedge sys_clk) begin
    sys_clk_edges <= sys_clk_edges + 1;
  end

  always @(posedge video_aclk) begin
    video_clk_edges <= video_clk_edges + 1;
  end

  always @(posedge axi_aclk) begin
    axi_clk_edges <= axi_clk_edges + 1;
  end

  always #(REFCLK_HALF_PERIOD_NS) begin
    pcie_refclk_p = ~pcie_refclk_p;
    pcie_refclk_n = ~pcie_refclk_n;
    ddr4_refclk_p = ~ddr4_refclk_p;
    ddr4_refclk_n = ~ddr4_refclk_n;
  end

  initial begin
    sys_rst_n = 1'b0;
    #(RESET_HOLD_TIME);
    sys_rst_n = 1'b1;
  end

  initial begin
    #(SIM_RUN_TIME);

    $display(
        "Smoke status @ %0t: sys_rst_n=%b util_rst=%b video_aresetn=%b video_periph_aresetn=%b axi_aresetn=%b axi_periph_aresetn=%b sys_clk_edges=%0d video_clk_edges=%0d axi_clk_edges=%0d",
        $time,
        sys_rst_n,
        dut.u_bd.awr2243_capture_bd_i.util_vl_sysrst_inv_Res,
        dut.video_aresetn_unused,
        dut.u_bd.awr2243_capture_bd_i.proc_sys_reset_video_peripheral_aresetn,
        dut.axi_aresetn_unused,
        dut.u_bd.awr2243_capture_bd_i.proc_sys_reset_axi_peripheral_aresetn,
        sys_clk_edges,
        video_clk_edges,
        axi_clk_edges
    );

    if (dut.video_aresetn_unused !== 1'b1) begin
      $fatal(1, "video_aresetn_unused did not release within %0t", SIM_RUN_TIME);
    end

    if (dut.axi_aresetn_unused !== 1'b1) begin
      $fatal(1, "axi_aresetn_unused did not release within %0t", SIM_RUN_TIME);
    end

    $display("BD smoke simulation passed at %0t", $time);
    $finish;
  end

endmodule
