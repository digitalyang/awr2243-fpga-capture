`include "csi_packet_extractor_macros.svh"

/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNDRIVEN */
// Shared AXI-Stream interface bundle for packet, slot, and replay datapaths.
interface axis_stream_if #(
    parameter int unsigned DATA_W = `CSI_AXIS_DATA_W_DFLT,
    parameter int unsigned USER_W = `CSI_AXIS_USER_W_DFLT
);

  localparam int unsigned KEEP_W = DATA_W / 8;

  logic [DATA_W-1:0] tdata;
  logic [KEEP_W-1:0] tkeep;
  logic              tvalid;
  logic              tready;
  logic              tlast;
  logic [USER_W-1:0] tuser;

  `CSI_STATIC_ASSERT((DATA_W > 0) && ((DATA_W % 8) == 0),
                     "axis_stream_if DATA_W must be byte aligned")
  `CSI_STATIC_ASSERT(USER_W > 0, "axis_stream_if USER_W must be greater than zero")

  modport master(
      output tdata,
      output tkeep,
      output tvalid,
      input tready,
      output tlast,
      output tuser
  );

  modport slave(input tdata, input tkeep, input tvalid, output tready, input tlast, input tuser);

  modport monitor(input tdata, input tkeep, input tvalid, input tready, input tlast, input tuser);

endinterface
/* verilator lint_on UNDRIVEN */
/* verilator lint_on UNUSEDSIGNAL */
