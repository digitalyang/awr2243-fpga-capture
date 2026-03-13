// Endpoint-facing top-level wrapper that keeps the verilog-pcie dependency
// isolated behind a small adapter and exposes clean BAR/AXI-facing interfaces.
module pcie_endpoint_dma_integration #(
    parameter bit DIRECT_RC_MODEL = 1'b1,
    parameter int unsigned BAR_ADDR_W = pcie_dma_pkg::PCIE_BAR_ADDR_W_DFLT,
    parameter int unsigned BAR_DATA_W = pcie_dma_pkg::PCIE_BAR_DATA_W_DFLT,
    parameter int unsigned BAR_W = pcie_dma_pkg::PCIE_BAR_NUM_W_DFLT,
    parameter int unsigned RC_TAG_W = pcie_dma_pkg::PCIE_RC_TAG_W_DFLT,
    parameter int unsigned AXIL_ADDR_W = pcie_dma_pkg::PCIE_AXIL_ADDR_W_DFLT,
    parameter int unsigned AXIL_DATA_W = pcie_dma_pkg::PCIE_AXIL_DATA_W_DFLT,
    parameter int unsigned AXI_ADDR_W = pcie_dma_pkg::PCIE_DMA_AXI_ADDR_W_DFLT,
    parameter int unsigned AXI_DATA_W = pcie_dma_pkg::PCIE_DMA_AXI_DATA_W_DFLT,
    parameter int unsigned DMA_DESC_ID_W = pcie_dma_pkg::PCIE_DMA_DESC_ID_W_DFLT,
    parameter int unsigned BAR0_INTERNAL_BYTES = pcie_dma_pkg::PCIE_BAR0_INTERNAL_BYTES_DFLT,
    parameter int unsigned BAR0_FORWARD_BASE = pcie_dma_pkg::PCIE_BAR0_FORWARD_BASE_DFLT,
    parameter int unsigned MAX_DMA_BURST_LEN = pcie_dma_pkg::PCIE_DMA_MAX_BURST_LEN_DFLT
) (
    input  logic clk_i,
    input  logic rst_ni,
    pcie_rc_model_if.device host_rc,
    axi4_lite_if.master m_axil_bar0,
    axi4_mm_if.master m_axi_dma,
    output logic irq_o,
    output logic dma_busy_o,
    output logic dma_done_pulse_o,
    output logic [DMA_DESC_ID_W-1:0] dma_done_desc_id_o
);

  pcie_rc_model_if #(
      .ADDR_W(BAR_ADDR_W),
      .DATA_W(BAR_DATA_W),
      .BAR_W (BAR_W),
      .TAG_W (RC_TAG_W)
  ) shell_rc_if ();

  pcie_endpoint_dma_vpcie_adapter #(
      .DIRECT_RC_MODEL(DIRECT_RC_MODEL)
  ) adapter_u (
      .clk_i   (clk_i),
      .rst_ni  (rst_ni),
      .host_rc (host_rc),
      .shell_rc(shell_rc_if)
  );

  pcie_endpoint_dma_shell #(
      .BAR_ADDR_W         (BAR_ADDR_W),
      .BAR_DATA_W         (BAR_DATA_W),
      .BAR_W              (BAR_W),
      .RC_TAG_W           (RC_TAG_W),
      .AXIL_ADDR_W        (AXIL_ADDR_W),
      .AXIL_DATA_W        (AXIL_DATA_W),
      .AXI_ADDR_W         (AXI_ADDR_W),
      .AXI_DATA_W         (AXI_DATA_W),
      .DMA_DESC_ID_W      (DMA_DESC_ID_W),
      .BAR0_INTERNAL_BYTES(BAR0_INTERNAL_BYTES),
      .BAR0_FORWARD_BASE  (BAR0_FORWARD_BASE),
      .MAX_DMA_BURST_LEN  (MAX_DMA_BURST_LEN)
  ) shell_u (
      .clk_i             (clk_i),
      .rst_ni            (rst_ni),
      .host_rc           (shell_rc_if),
      .m_axil_bar0       (m_axil_bar0),
      .m_axi_dma         (m_axi_dma),
      .irq_o             (irq_o),
      .dma_busy_o        (dma_busy_o),
      .dma_done_pulse_o  (dma_done_pulse_o),
      .dma_done_desc_id_o(dma_done_desc_id_o)
  );

endmodule
