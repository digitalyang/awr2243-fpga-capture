`include "ddr_ringbuffer_macros.svh"

/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNDRIVEN */
interface axi4_lite_if #(
    parameter int unsigned ADDR_W = 8,
    parameter int unsigned DATA_W = 32
);

    localparam int unsigned STRB_W = DATA_W / 8;

    logic [ADDR_W-1:0] awaddr;
    logic [2:0]        awprot;
    logic              awvalid;
    logic              awready;

    logic [DATA_W-1:0] wdata;
    logic [STRB_W-1:0] wstrb;
    logic              wvalid;
    logic              wready;

    logic [1:0]        bresp;
    logic              bvalid;
    logic              bready;

    logic [ADDR_W-1:0] araddr;
    logic [2:0]        arprot;
    logic              arvalid;
    logic              arready;

    logic [DATA_W-1:0] rdata;
    logic [1:0]        rresp;
    logic              rvalid;
    logic              rready;

    `DDR_RING_STATIC_ASSERT((DATA_W > 0) && ((DATA_W % 8) == 0), "axi4_lite_if DATA_W must be byte aligned")
    `DDR_RING_STATIC_ASSERT(ADDR_W > 0, "axi4_lite_if ADDR_W must be greater than zero")

    modport master (
        output awaddr,
        output awprot,
        output awvalid,
        input  awready,

        output wdata,
        output wstrb,
        output wvalid,
        input  wready,

        input  bresp,
        input  bvalid,
        output bready,

        output araddr,
        output arprot,
        output arvalid,
        input  arready,

        input  rdata,
        input  rresp,
        input  rvalid,
        output rready
    );

    modport slave (
        input  awaddr,
        input  awprot,
        input  awvalid,
        output awready,

        input  wdata,
        input  wstrb,
        input  wvalid,
        output wready,

        output bresp,
        output bvalid,
        input  bready,

        input  araddr,
        input  arprot,
        input  arvalid,
        output arready,

        output rdata,
        output rresp,
        output rvalid,
        input  rready
    );

    modport monitor (
        input awaddr,
        input awprot,
        input awvalid,
        input awready,

        input wdata,
        input wstrb,
        input wvalid,
        input wready,

        input bresp,
        input bvalid,
        input bready,

        input araddr,
        input arprot,
        input arvalid,
        input arready,

        input rdata,
        input rresp,
        input rvalid,
        input rready
    );

endinterface
/* verilator lint_on UNDRIVEN */
/* verilator lint_on UNUSEDSIGNAL */
