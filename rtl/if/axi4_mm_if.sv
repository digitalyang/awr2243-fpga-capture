`include "ddr_ringbuffer_macros.svh"

/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNDRIVEN */
// AXI4 memory-mapped interface bundle for the DDR write/read datapath.
interface axi4_mm_if #(
    parameter int unsigned ADDR_W = `DDR_RING_AXI_ADDR_W_DFLT,
    parameter int unsigned DATA_W = `DDR_RING_AXI_DATA_W_DFLT
);

  localparam int unsigned STRB_W = DATA_W / 8;

  logic [ADDR_W-1:0] awaddr;
  logic [       7:0] awlen;
  logic [       2:0] awsize;
  logic [       1:0] awburst;
  logic              awvalid;
  logic              awready;

  logic [DATA_W-1:0] wdata;
  logic [STRB_W-1:0] wstrb;
  logic              wlast;
  logic              wvalid;
  logic              wready;

  logic [       1:0] bresp;
  logic              bvalid;
  logic              bready;

  logic [ADDR_W-1:0] araddr;
  logic [       7:0] arlen;
  logic [       2:0] arsize;
  logic [       1:0] arburst;
  logic              arvalid;
  logic              arready;

  logic [DATA_W-1:0] rdata;
  logic [       1:0] rresp;
  logic              rlast;
  logic              rvalid;
  logic              rready;

  `DDR_RING_STATIC_ASSERT((DATA_W > 0) && ((DATA_W % 8) == 0),
                          "axi4_mm_if DATA_W must be byte aligned")
  `DDR_RING_STATIC_ASSERT(ADDR_W > 0, "axi4_mm_if ADDR_W must be greater than zero")

  modport master(
      output awaddr,
      output awlen,
      output awsize,
      output awburst,
      output awvalid,
      input awready,

      output wdata,
      output wstrb,
      output wlast,
      output wvalid,
      input wready,

      input bresp,
      input bvalid,
      output bready,

      output araddr,
      output arlen,
      output arsize,
      output arburst,
      output arvalid,
      input arready,

      input rdata,
      input rresp,
      input rlast,
      input rvalid,
      output rready
  );

  modport slave(
      input awaddr,
      input awlen,
      input awsize,
      input awburst,
      input awvalid,
      output awready,

      input wdata,
      input wstrb,
      input wlast,
      input wvalid,
      output wready,

      output bresp,
      output bvalid,
      input bready,

      input araddr,
      input arlen,
      input arsize,
      input arburst,
      input arvalid,
      output arready,

      output rdata,
      output rresp,
      output rlast,
      output rvalid,
      input rready
  );

  modport monitor(
      input awaddr,
      input awlen,
      input awsize,
      input awburst,
      input awvalid,
      input awready,

      input wdata,
      input wstrb,
      input wlast,
      input wvalid,
      input wready,

      input bresp,
      input bvalid,
      input bready,

      input araddr,
      input arlen,
      input arsize,
      input arburst,
      input arvalid,
      input arready,

      input rdata,
      input rresp,
      input rlast,
      input rvalid,
      input rready
  );

endinterface
/* verilator lint_on UNDRIVEN */
/* verilator lint_on UNUSEDSIGNAL */
