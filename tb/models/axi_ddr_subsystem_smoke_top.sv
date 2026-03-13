`include "ddr_ringbuffer_macros.svh"

module axi_ddr_subsystem_smoke_top #(
    parameter int unsigned AXI_ADDR_W = axi_ddr_subsystem_pkg::AXI_DDR_ADDR_W_DFLT,
    parameter int unsigned AXI_DATA_W = axi_ddr_subsystem_pkg::AXI_DDR_DATA_W_DFLT
) (
    input logic clk_i,
    input logic rst_ni,

    output logic [1:0] wr_owner_o,
    output logic       wr_owner_valid_o,
    output logic [1:0] rd_owner_o,
    output logic       rd_owner_valid_o,
    output logic       ddr_init_done_o,

    input  logic [AXI_ADDR_W-1:0] radar_axi_awaddr,
    input  logic [7:0]            radar_axi_awlen,
    input  logic [2:0]            radar_axi_awsize,
    input  logic [1:0]            radar_axi_awburst,
    input  logic                  radar_axi_awvalid,
    output logic                  radar_axi_awready,
    input  logic [AXI_DATA_W-1:0] radar_axi_wdata,
    input  logic [(AXI_DATA_W/8)-1:0] radar_axi_wstrb,
    input  logic                      radar_axi_wlast,
    input  logic                      radar_axi_wvalid,
    output logic                      radar_axi_wready,
    output logic [1:0]                radar_axi_bresp,
    output logic                      radar_axi_bvalid,
    input  logic                      radar_axi_bready,
    input  logic [AXI_ADDR_W-1:0]     radar_axi_araddr,
    input  logic [7:0]                radar_axi_arlen,
    input  logic [2:0]                radar_axi_arsize,
    input  logic [1:0]                radar_axi_arburst,
    input  logic                      radar_axi_arvalid,
    output logic                      radar_axi_arready,
    output logic [AXI_DATA_W-1:0]     radar_axi_rdata,
    output logic [1:0]                radar_axi_rresp,
    output logic                      radar_axi_rlast,
    output logic                      radar_axi_rvalid,
    input  logic                      radar_axi_rready,

    input  logic [AXI_ADDR_W-1:0] host_axi_awaddr,
    input  logic [7:0]            host_axi_awlen,
    input  logic [2:0]            host_axi_awsize,
    input  logic [1:0]            host_axi_awburst,
    input  logic                  host_axi_awvalid,
    output logic                  host_axi_awready,
    input  logic [AXI_DATA_W-1:0] host_axi_wdata,
    input  logic [(AXI_DATA_W/8)-1:0] host_axi_wstrb,
    input  logic                      host_axi_wlast,
    input  logic                      host_axi_wvalid,
    output logic                      host_axi_wready,
    output logic [1:0]                host_axi_bresp,
    output logic                      host_axi_bvalid,
    input  logic                      host_axi_bready,
    input  logic [AXI_ADDR_W-1:0]     host_axi_araddr,
    input  logic [7:0]                host_axi_arlen,
    input  logic [2:0]                host_axi_arsize,
    input  logic [1:0]                host_axi_arburst,
    input  logic                      host_axi_arvalid,
    output logic                      host_axi_arready,
    output logic [AXI_DATA_W-1:0]     host_axi_rdata,
    output logic [1:0]                host_axi_rresp,
    output logic                      host_axi_rlast,
    output logic                      host_axi_rvalid,
    input  logic                      host_axi_rready,

    output logic [AXI_ADDR_W-1:0]     ddr_axi_awaddr,
    output logic [7:0]                ddr_axi_awlen,
    output logic [2:0]                ddr_axi_awsize,
    output logic [1:0]                ddr_axi_awburst,
    output logic                      ddr_axi_awvalid,
    input  logic                      ddr_axi_awready,
    output logic [AXI_DATA_W-1:0]     ddr_axi_wdata,
    output logic [(AXI_DATA_W/8)-1:0] ddr_axi_wstrb,
    output logic                      ddr_axi_wlast,
    output logic                      ddr_axi_wvalid,
    input  logic                      ddr_axi_wready,
    input  logic [1:0]                ddr_axi_bresp,
    input  logic                      ddr_axi_bvalid,
    output logic                      ddr_axi_bready,
    output logic [AXI_ADDR_W-1:0]     ddr_axi_araddr,
    output logic [7:0]                ddr_axi_arlen,
    output logic [2:0]                ddr_axi_arsize,
    output logic [1:0]                ddr_axi_arburst,
    output logic                      ddr_axi_arvalid,
    input  logic                      ddr_axi_arready,
    input  logic [AXI_DATA_W-1:0]     ddr_axi_rdata,
    input  logic [1:0]                ddr_axi_rresp,
    input  logic                      ddr_axi_rlast,
    input  logic                      ddr_axi_rvalid,
    output logic                      ddr_axi_rready
);

  axi4_mm_if #(
      .ADDR_W(AXI_ADDR_W),
      .DATA_W(AXI_DATA_W)
  ) radar_axi_if ();

  axi4_mm_if #(
      .ADDR_W(AXI_ADDR_W),
      .DATA_W(AXI_DATA_W)
  ) host_axi_if ();

  axi4_mm_if #(
      .ADDR_W(AXI_ADDR_W),
      .DATA_W(AXI_DATA_W)
  ) ddr_frontend_axi_if ();

  axi4_mm_if #(
      .ADDR_W(AXI_ADDR_W),
      .DATA_W(AXI_DATA_W)
  ) ddr_backend_axi_if ();

  assign radar_axi_if.awaddr  = radar_axi_awaddr;
  assign radar_axi_if.awlen   = radar_axi_awlen;
  assign radar_axi_if.awsize  = radar_axi_awsize;
  assign radar_axi_if.awburst = radar_axi_awburst;
  assign radar_axi_if.awvalid = radar_axi_awvalid;
  assign radar_axi_awready    = radar_axi_if.awready;
  assign radar_axi_if.wdata   = radar_axi_wdata;
  assign radar_axi_if.wstrb   = radar_axi_wstrb;
  assign radar_axi_if.wlast   = radar_axi_wlast;
  assign radar_axi_if.wvalid  = radar_axi_wvalid;
  assign radar_axi_wready     = radar_axi_if.wready;
  assign radar_axi_bresp      = radar_axi_if.bresp;
  assign radar_axi_bvalid     = radar_axi_if.bvalid;
  assign radar_axi_if.bready  = radar_axi_bready;
  assign radar_axi_if.araddr  = radar_axi_araddr;
  assign radar_axi_if.arlen   = radar_axi_arlen;
  assign radar_axi_if.arsize  = radar_axi_arsize;
  assign radar_axi_if.arburst = radar_axi_arburst;
  assign radar_axi_if.arvalid = radar_axi_arvalid;
  assign radar_axi_arready    = radar_axi_if.arready;
  assign radar_axi_rdata      = radar_axi_if.rdata;
  assign radar_axi_rresp      = radar_axi_if.rresp;
  assign radar_axi_rlast      = radar_axi_if.rlast;
  assign radar_axi_rvalid     = radar_axi_if.rvalid;
  assign radar_axi_if.rready  = radar_axi_rready;

  assign host_axi_if.awaddr   = host_axi_awaddr;
  assign host_axi_if.awlen    = host_axi_awlen;
  assign host_axi_if.awsize   = host_axi_awsize;
  assign host_axi_if.awburst  = host_axi_awburst;
  assign host_axi_if.awvalid  = host_axi_awvalid;
  assign host_axi_awready     = host_axi_if.awready;
  assign host_axi_if.wdata    = host_axi_wdata;
  assign host_axi_if.wstrb    = host_axi_wstrb;
  assign host_axi_if.wlast    = host_axi_wlast;
  assign host_axi_if.wvalid   = host_axi_wvalid;
  assign host_axi_wready      = host_axi_if.wready;
  assign host_axi_bresp       = host_axi_if.bresp;
  assign host_axi_bvalid      = host_axi_if.bvalid;
  assign host_axi_if.bready   = host_axi_bready;
  assign host_axi_if.araddr   = host_axi_araddr;
  assign host_axi_if.arlen    = host_axi_arlen;
  assign host_axi_if.arsize   = host_axi_arsize;
  assign host_axi_if.arburst  = host_axi_arburst;
  assign host_axi_if.arvalid  = host_axi_arvalid;
  assign host_axi_arready     = host_axi_if.arready;
  assign host_axi_rdata       = host_axi_if.rdata;
  assign host_axi_rresp       = host_axi_if.rresp;
  assign host_axi_rlast       = host_axi_if.rlast;
  assign host_axi_rvalid      = host_axi_if.rvalid;
  assign host_axi_if.rready   = host_axi_rready;

  assign ddr_axi_awaddr       = ddr_backend_axi_if.awaddr;
  assign ddr_axi_awlen        = ddr_backend_axi_if.awlen;
  assign ddr_axi_awsize       = ddr_backend_axi_if.awsize;
  assign ddr_axi_awburst      = ddr_backend_axi_if.awburst;
  assign ddr_axi_awvalid      = ddr_backend_axi_if.awvalid;
  assign ddr_backend_axi_if.awready = ddr_axi_awready;
  assign ddr_axi_wdata        = ddr_backend_axi_if.wdata;
  assign ddr_axi_wstrb        = ddr_backend_axi_if.wstrb;
  assign ddr_axi_wlast        = ddr_backend_axi_if.wlast;
  assign ddr_axi_wvalid       = ddr_backend_axi_if.wvalid;
  assign ddr_backend_axi_if.wready = ddr_axi_wready;
  assign ddr_backend_axi_if.bresp = ddr_axi_bresp;
  assign ddr_backend_axi_if.bvalid = ddr_axi_bvalid;
  assign ddr_axi_bready       = ddr_backend_axi_if.bready;
  assign ddr_axi_araddr       = ddr_backend_axi_if.araddr;
  assign ddr_axi_arlen        = ddr_backend_axi_if.arlen;
  assign ddr_axi_arsize       = ddr_backend_axi_if.arsize;
  assign ddr_axi_arburst      = ddr_backend_axi_if.arburst;
  assign ddr_axi_arvalid      = ddr_backend_axi_if.arvalid;
  assign ddr_backend_axi_if.arready = ddr_axi_arready;
  assign ddr_backend_axi_if.rdata = ddr_axi_rdata;
  assign ddr_backend_axi_if.rresp = ddr_axi_rresp;
  assign ddr_backend_axi_if.rlast = ddr_axi_rlast;
  assign ddr_backend_axi_if.rvalid = ddr_axi_rvalid;
  assign ddr_axi_rready       = ddr_backend_axi_if.rready;

  axi_ddr_subsystem #(
      .AXI_ADDR_W(AXI_ADDR_W),
      .AXI_DATA_W(AXI_DATA_W)
  ) dut (
      .clk_i          (clk_i),
      .rst_ni         (rst_ni),
      .wr_owner_o     (wr_owner_o),
      .wr_owner_valid_o(wr_owner_valid_o),
      .rd_owner_o     (rd_owner_o),
      .rd_owner_valid_o(rd_owner_valid_o),
      .s_axi_radar    (radar_axi_if),
      .s_axi_host     (host_axi_if),
      .m_axi_ddr      (ddr_frontend_axi_if)
  );

  litedram_axi_wrapper_stub #(
      .AXI_ADDR_W (AXI_ADDR_W),
      .AXI_DATA_W (AXI_DATA_W)
  ) litedram_stub_u (
      .clk_i         (clk_i),
      .rst_ni        (rst_ni),
      .ddr_init_done_o(ddr_init_done_o),
      .s_axi         (ddr_frontend_axi_if),
      .m_axi_model   (ddr_backend_axi_if)
  );

endmodule
