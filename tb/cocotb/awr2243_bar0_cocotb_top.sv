`include "ddr_ringbuffer_macros.svh"

// Cocotb harness: BAR0 decode + ringbuffer stub + awr2243_ctrl_top.
// Host (cocotb) drives s_axil as AXI-Lite master; addr 0x000-0x08C -> ring stub, 0x090+ -> AWR CSR.
module awr2243_bar0_cocotb_top (
    input  logic        clk_i,
    input  logic        rst_ni,

    // Host AXI-Lite (master driven by cocotb); 16-bit addr for BAR0 decode
    input  logic [15:0] s_axil_awaddr,
    input  logic [ 2:0] s_axil_awprot,
    input  logic        s_axil_awvalid,
    output logic        s_axil_awready,
    input  logic [31:0] s_axil_wdata,
    input  logic [ 3:0] s_axil_wstrb,
    input  logic        s_axil_wvalid,
    output logic        s_axil_wready,
    output logic [ 1:0] s_axil_bresp,
    output logic        s_axil_bvalid,
    input  logic        s_axil_bready,
    input  logic [15:0] s_axil_araddr,
    input  logic [ 2:0] s_axil_arprot,
    input  logic        s_axil_arvalid,
    output logic        s_axil_arready,
    output logic [31:0] s_axil_rdata,
    output logic [ 1:0] s_axil_rresp,
    output logic        s_axil_rvalid,
    input  logic        s_axil_rready
);

  localparam int unsigned ADDR_W = 16;
  localparam int unsigned DATA_W = 32;

  axi4_lite_if #(.ADDR_W(ADDR_W), .DATA_W(DATA_W)) s_axil_host ();
  axi4_lite_if #(.ADDR_W(8), .DATA_W(DATA_W))      m_axil_ring ();
  axi4_lite_if #(.ADDR_W(8), .DATA_W(DATA_W))      m_axil_awr  ();

  assign s_axil_host.awaddr  = s_axil_awaddr;
  assign s_axil_host.awprot  = s_axil_awprot;
  assign s_axil_host.awvalid = s_axil_awvalid;
  assign s_axil_awready     = s_axil_host.awready;
  assign s_axil_host.wdata   = s_axil_wdata;
  assign s_axil_host.wstrb   = s_axil_wstrb;
  assign s_axil_host.wvalid  = s_axil_wvalid;
  assign s_axil_wready      = s_axil_host.wready;
  assign s_axil_bresp       = s_axil_host.bresp;
  assign s_axil_bvalid      = s_axil_host.bvalid;
  assign s_axil_host.bready  = s_axil_bready;
  assign s_axil_host.araddr  = s_axil_araddr;
  assign s_axil_host.arprot  = s_axil_arprot;
  assign s_axil_host.arvalid = s_axil_arvalid;
  assign s_axil_arready     = s_axil_host.arready;
  assign s_axil_rdata       = s_axil_host.rdata;
  assign s_axil_rresp       = s_axil_host.rresp;
  assign s_axil_rvalid      = s_axil_host.rvalid;
  assign s_axil_host.rready  = s_axil_rready;

  axil_bar0_decode #(
      .ADDR_W   (ADDR_W),
      .DATA_W   (DATA_W),
      .AWR_BASE (16'h0090)
  ) u_decode (
      .clk         (clk_i),
      .rst_n       (rst_ni),
      .s_axil      (s_axil_host),
      .m_axil_ring (m_axil_ring),
      .m_axil_awr  (m_axil_awr)
  );

  axil_slave_stub #(
      .ADDR_W(8),
      .DATA_W(DATA_W)
  ) u_ring_stub (
      .clk    (clk_i),
      .rst_n  (rst_ni),
      .s_axil (m_axil_ring)
  );

  awr2243_ctrl_top u_awr (
      .sys_clk       (clk_i),
      .sys_rst_n     (rst_ni),
      .s_axil        (m_axil_awr),
      .spi_sclk_o    (),
      .spi_cs_n_o    (),
      .spi_mosi_o    (),
      .spi_miso_i    (1'b0),
      .sop0_o        (),
      .sop1_o        (),
      .sop2_o        (),
      .nreset_o       (),
      .host_irq_i    (1'b0),
      .nerror_out_i  (1'b1),
      .ctrl_busy_o   (),
      .ctrl_done_o   (),
      .ctrl_err_code_o(),
      .ctrl_state_o  ()
  );

endmodule
