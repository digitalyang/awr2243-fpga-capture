`include "ddr_ringbuffer_macros.svh"

// LiteDRAM-compatible integration stub. The current E2E platform still binds a
// cocotb/Python AXI memory model behind this wrapper, but agent-pipeline and
// agent-host can already target this boundary instead of wiring directly to a
// behavioral RAM.
module litedram_axi_wrapper_stub #(
    parameter int unsigned AXI_ADDR_W = axi_ddr_subsystem_pkg::AXI_DDR_ADDR_W_DFLT,
    parameter int unsigned AXI_DATA_W = axi_ddr_subsystem_pkg::AXI_DDR_DATA_W_DFLT,
    parameter int unsigned INIT_CYCLES = 8
) (
    input logic clk_i,
    input logic rst_ni,

    output logic ddr_init_done_o,

    axi4_mm_if.slave  s_axi,
    axi4_mm_if.master m_axi_model
);

  localparam int unsigned INIT_CNT_W = (INIT_CYCLES <= 1) ? 1 : $clog2(INIT_CYCLES + 1);

  logic [INIT_CNT_W-1:0] init_count_r;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      init_count_r <= '0;
    end else if (!ddr_init_done_o) begin
      init_count_r <= init_count_r + INIT_CNT_W'(1);
    end
  end

  assign ddr_init_done_o = (init_count_r >= INIT_CNT_W'(INIT_CYCLES));

  always_comb begin
    s_axi.awready    = 1'b0;
    s_axi.wready     = 1'b0;
    s_axi.bresp      = ddr_ringbuffer_pkg::AXI_RESP_OKAY;
    s_axi.bvalid     = 1'b0;
    s_axi.arready    = 1'b0;
    s_axi.rdata      = '0;
    s_axi.rresp      = ddr_ringbuffer_pkg::AXI_RESP_OKAY;
    s_axi.rlast      = 1'b0;
    s_axi.rvalid     = 1'b0;

    m_axi_model.awaddr  = '0;
    m_axi_model.awlen   = '0;
    m_axi_model.awsize  = '0;
    m_axi_model.awburst = '0;
    m_axi_model.awvalid = 1'b0;
    m_axi_model.wdata   = '0;
    m_axi_model.wstrb   = '0;
    m_axi_model.wlast   = 1'b0;
    m_axi_model.wvalid  = 1'b0;
    m_axi_model.bready  = 1'b0;
    m_axi_model.araddr  = '0;
    m_axi_model.arlen   = '0;
    m_axi_model.arsize  = '0;
    m_axi_model.arburst = '0;
    m_axi_model.arvalid = 1'b0;
    m_axi_model.rready  = 1'b0;

    if (ddr_init_done_o) begin
      m_axi_model.awaddr  = s_axi.awaddr;
      m_axi_model.awlen   = s_axi.awlen;
      m_axi_model.awsize  = s_axi.awsize;
      m_axi_model.awburst = s_axi.awburst;
      m_axi_model.awvalid = s_axi.awvalid;
      s_axi.awready       = m_axi_model.awready;

      m_axi_model.wdata   = s_axi.wdata;
      m_axi_model.wstrb   = s_axi.wstrb;
      m_axi_model.wlast   = s_axi.wlast;
      m_axi_model.wvalid  = s_axi.wvalid;
      s_axi.wready        = m_axi_model.wready;

      s_axi.bresp         = m_axi_model.bresp;
      s_axi.bvalid        = m_axi_model.bvalid;
      m_axi_model.bready  = s_axi.bready;

      m_axi_model.araddr  = s_axi.araddr;
      m_axi_model.arlen   = s_axi.arlen;
      m_axi_model.arsize  = s_axi.arsize;
      m_axi_model.arburst = s_axi.arburst;
      m_axi_model.arvalid = s_axi.arvalid;
      s_axi.arready       = m_axi_model.arready;

      s_axi.rdata         = m_axi_model.rdata;
      s_axi.rresp         = m_axi_model.rresp;
      s_axi.rlast         = m_axi_model.rlast;
      s_axi.rvalid        = m_axi_model.rvalid;
      m_axi_model.rready  = s_axi.rready;
    end
  end

  `DDR_RING_STATIC_ASSERT(AXI_ADDR_W > 0, "AXI_ADDR_W must be greater than zero")
  `DDR_RING_STATIC_ASSERT((AXI_DATA_W > 0) && ((AXI_DATA_W % 8) == 0),
                          "AXI_DATA_W must be byte aligned")

endmodule
