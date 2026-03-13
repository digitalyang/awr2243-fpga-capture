module pcie_endpoint_dma_cocotb_top (
    input  logic                                               clk_i,
    input  logic                                               rst_ni,

    input  logic                                               host_rc_req_valid,
    output logic                                               host_rc_req_ready,
    input  logic                                               host_rc_req_write,
    input  logic [pcie_dma_pkg::PCIE_BAR_NUM_W_DFLT-1:0]      host_rc_req_bar,
    input  logic [pcie_dma_pkg::PCIE_BAR_ADDR_W_DFLT-1:0]     host_rc_req_addr,
    input  logic [pcie_dma_pkg::PCIE_BAR_DATA_W_DFLT-1:0]     host_rc_req_data,
    input  logic [(pcie_dma_pkg::PCIE_BAR_DATA_W_DFLT/8)-1:0] host_rc_req_strb,
    input  logic [pcie_dma_pkg::PCIE_RC_TAG_W_DFLT-1:0]       host_rc_req_tag,

    output logic                                               host_rc_rsp_valid,
    input  logic                                               host_rc_rsp_ready,
    output logic [pcie_dma_pkg::PCIE_BAR_DATA_W_DFLT-1:0]     host_rc_rsp_data,
    output logic [1:0]                                         host_rc_rsp_status,
    output logic [pcie_dma_pkg::PCIE_RC_TAG_W_DFLT-1:0]       host_rc_rsp_tag,

    output logic                                               irq_o,
    output logic                                               dma_busy_o,
    output logic                                               dma_done_pulse_o,
    output logic [pcie_dma_pkg::PCIE_DMA_DESC_ID_W_DFLT-1:0]  dma_done_desc_id_o,

    output logic [pcie_dma_pkg::PCIE_AXIL_ADDR_W_DFLT-1:0]    m_axil_awaddr,
    output logic [2:0]                                         m_axil_awprot,
    output logic                                               m_axil_awvalid,
    input  logic                                               m_axil_awready,
    output logic [pcie_dma_pkg::PCIE_AXIL_DATA_W_DFLT-1:0]    m_axil_wdata,
    output logic [(pcie_dma_pkg::PCIE_AXIL_DATA_W_DFLT/8)-1:0] m_axil_wstrb,
    output logic                                               m_axil_wvalid,
    input  logic                                               m_axil_wready,
    input  logic [1:0]                                         m_axil_bresp,
    input  logic                                               m_axil_bvalid,
    output logic                                               m_axil_bready,
    output logic [pcie_dma_pkg::PCIE_AXIL_ADDR_W_DFLT-1:0]    m_axil_araddr,
    output logic [2:0]                                         m_axil_arprot,
    output logic                                               m_axil_arvalid,
    input  logic                                               m_axil_arready,
    input  logic [pcie_dma_pkg::PCIE_AXIL_DATA_W_DFLT-1:0]    m_axil_rdata,
    input  logic [1:0]                                         m_axil_rresp,
    input  logic                                               m_axil_rvalid,
    output logic                                               m_axil_rready,

    output logic [pcie_dma_pkg::PCIE_DMA_AXI_ADDR_W_DFLT-1:0]  m_axi_awaddr,
    output logic [7:0]                                          m_axi_awlen,
    output logic [2:0]                                          m_axi_awsize,
    output logic [1:0]                                          m_axi_awburst,
    output logic                                                m_axi_awvalid,
    input  logic                                                m_axi_awready,
    output logic [pcie_dma_pkg::PCIE_DMA_AXI_DATA_W_DFLT-1:0]  m_axi_wdata,
    output logic [(pcie_dma_pkg::PCIE_DMA_AXI_DATA_W_DFLT/8)-1:0] m_axi_wstrb,
    output logic                                                m_axi_wlast,
    output logic                                                m_axi_wvalid,
    input  logic                                                m_axi_wready,
    input  logic [1:0]                                          m_axi_bresp,
    input  logic                                                m_axi_bvalid,
    output logic                                                m_axi_bready,
    output logic [pcie_dma_pkg::PCIE_DMA_AXI_ADDR_W_DFLT-1:0]  m_axi_araddr,
    output logic [7:0]                                          m_axi_arlen,
    output logic [2:0]                                          m_axi_arsize,
    output logic [1:0]                                          m_axi_arburst,
    output logic                                                m_axi_arvalid,
    input  logic                                                m_axi_arready,
    input  logic [pcie_dma_pkg::PCIE_DMA_AXI_DATA_W_DFLT-1:0]  m_axi_rdata,
    input  logic [1:0]                                          m_axi_rresp,
    input  logic                                                m_axi_rlast,
    input  logic                                                m_axi_rvalid,
    output logic                                                m_axi_rready
);

  pcie_rc_model_if host_rc_if ();
  axi4_lite_if #(
      .ADDR_W(pcie_dma_pkg::PCIE_AXIL_ADDR_W_DFLT),
      .DATA_W(pcie_dma_pkg::PCIE_AXIL_DATA_W_DFLT)
  ) m_axil_if ();
  axi4_mm_if #(
      .ADDR_W(pcie_dma_pkg::PCIE_DMA_AXI_ADDR_W_DFLT),
      .DATA_W(pcie_dma_pkg::PCIE_DMA_AXI_DATA_W_DFLT)
  ) m_axi_if ();

  assign host_rc_if.req_valid = host_rc_req_valid;
  assign host_rc_req_ready    = host_rc_if.req_ready;
  assign host_rc_if.req_write = host_rc_req_write;
  assign host_rc_if.req_bar   = host_rc_req_bar;
  assign host_rc_if.req_addr  = host_rc_req_addr;
  assign host_rc_if.req_data  = host_rc_req_data;
  assign host_rc_if.req_strb  = host_rc_req_strb;
  assign host_rc_if.req_tag   = host_rc_req_tag;
  assign host_rc_rsp_valid    = host_rc_if.rsp_valid;
  assign host_rc_if.rsp_ready = host_rc_rsp_ready;
  assign host_rc_rsp_data     = host_rc_if.rsp_data;
  assign host_rc_rsp_status   = host_rc_if.rsp_status;
  assign host_rc_rsp_tag      = host_rc_if.rsp_tag;

  assign m_axil_awaddr        = m_axil_if.awaddr;
  assign m_axil_awprot        = m_axil_if.awprot;
  assign m_axil_awvalid       = m_axil_if.awvalid;
  assign m_axil_if.awready    = m_axil_awready;
  assign m_axil_wdata         = m_axil_if.wdata;
  assign m_axil_wstrb         = m_axil_if.wstrb;
  assign m_axil_wvalid        = m_axil_if.wvalid;
  assign m_axil_if.wready     = m_axil_wready;
  assign m_axil_if.bresp      = m_axil_bresp;
  assign m_axil_if.bvalid     = m_axil_bvalid;
  assign m_axil_bready        = m_axil_if.bready;
  assign m_axil_araddr        = m_axil_if.araddr;
  assign m_axil_arprot        = m_axil_if.arprot;
  assign m_axil_arvalid       = m_axil_if.arvalid;
  assign m_axil_if.arready    = m_axil_arready;
  assign m_axil_if.rdata      = m_axil_rdata;
  assign m_axil_if.rresp      = m_axil_rresp;
  assign m_axil_if.rvalid     = m_axil_rvalid;
  assign m_axil_rready        = m_axil_if.rready;

  assign m_axi_awaddr         = m_axi_if.awaddr;
  assign m_axi_awlen          = m_axi_if.awlen;
  assign m_axi_awsize         = m_axi_if.awsize;
  assign m_axi_awburst        = m_axi_if.awburst;
  assign m_axi_awvalid        = m_axi_if.awvalid;
  assign m_axi_if.awready     = m_axi_awready;
  assign m_axi_wdata          = m_axi_if.wdata;
  assign m_axi_wstrb          = m_axi_if.wstrb;
  assign m_axi_wlast          = m_axi_if.wlast;
  assign m_axi_wvalid         = m_axi_if.wvalid;
  assign m_axi_if.wready      = m_axi_wready;
  assign m_axi_if.bresp       = m_axi_bresp;
  assign m_axi_if.bvalid      = m_axi_bvalid;
  assign m_axi_bready         = m_axi_if.bready;
  assign m_axi_araddr         = m_axi_if.araddr;
  assign m_axi_arlen          = m_axi_if.arlen;
  assign m_axi_arsize         = m_axi_if.arsize;
  assign m_axi_arburst        = m_axi_if.arburst;
  assign m_axi_arvalid        = m_axi_if.arvalid;
  assign m_axi_if.arready     = m_axi_arready;
  assign m_axi_if.rdata       = m_axi_rdata;
  assign m_axi_if.rresp       = m_axi_rresp;
  assign m_axi_if.rlast       = m_axi_rlast;
  assign m_axi_if.rvalid      = m_axi_rvalid;
  assign m_axi_rready         = m_axi_if.rready;

  pcie_endpoint_dma_integration #(
      .DIRECT_RC_MODEL(1'b1)
  ) dut (
      .clk_i             (clk_i),
      .rst_ni            (rst_ni),
      .host_rc           (host_rc_if),
      .m_axil_bar0       (m_axil_if),
      .m_axi_dma         (m_axi_if),
      .irq_o             (irq_o),
      .dma_busy_o        (dma_busy_o),
      .dma_done_pulse_o  (dma_done_pulse_o),
      .dma_done_desc_id_o(dma_done_desc_id_o)
  );

endmodule
