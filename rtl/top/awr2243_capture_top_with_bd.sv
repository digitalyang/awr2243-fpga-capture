`timescale 1ns / 1ps

module awr2243_capture_top_with_bd (
    input  logic sys_clk,
    input  logic sys_rst_n,
    input  logic video_aclk,
    input  logic axi_aclk,

    input  logic       pcie_refclk_p,
    input  logic       pcie_refclk_n,
    input  logic       ddr4_refclk_p,
    input  logic       ddr4_refclk_n,
    input  logic       csi_rx_clk_p,
    input  logic       csi_rx_clk_n,
    input  logic [3:0] csi_rx_data_p,
    input  logic [3:0] csi_rx_data_n,

    input  logic [7:0] pcie_rxp,
    input  logic [7:0] pcie_rxn,
    output logic [7:0] pcie_txp,
    output logic [7:0] pcie_txn,

    inout  wire  [63:0] ddr4_dq,
    inout  wire  [7:0]  ddr4_dqs_c,
    inout  wire  [7:0]  ddr4_dqs_t,
    output logic [16:0] ddr4_adr,
    output logic [1:0]  ddr4_ba,
    output logic [1:0]  ddr4_bg,
    output logic        ddr4_ck_c,
    output logic        ddr4_ck_t,
    output logic        ddr4_cke,
    output logic        ddr4_cs_n,
    output logic        ddr4_act_n,
    output logic        ddr4_odt,
    output logic        ddr4_reset_n,
    inout  wire  [7:0]  ddr4_dm_n,

    output logic spi_sclk_o,
    output logic spi_cs_n_o,
    output logic spi_mosi_o,
    input  logic spi_miso_i,
    output logic sop0_o,
    output logic sop1_o,
    output logic sop2_o,
    output logic nreset_o,
    input  logic host_irq_i,
    input  logic nerror_out_i
);

  logic video_aresetn_unused;
  logic axi_aresetn_unused;

  awr2243_capture_bd_wrapper u_bd (
      .sys_clk       (sys_clk),
      .sys_rst_n     (sys_rst_n),
      .video_aclk    (video_aclk),
      .axi_aclk      (axi_aclk),
      .video_aresetn (video_aresetn_unused),
      .axi_aresetn   (axi_aresetn_unused),

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

endmodule
