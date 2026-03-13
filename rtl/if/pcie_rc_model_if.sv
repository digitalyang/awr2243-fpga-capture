`include "ddr_ringbuffer_macros.svh"

/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNDRIVEN */
// Transaction-level host RC model interface used by the PCIe endpoint smoke harness.
interface pcie_rc_model_if #(
    parameter int unsigned ADDR_W = pcie_dma_pkg::PCIE_BAR_ADDR_W_DFLT,
    parameter int unsigned DATA_W = pcie_dma_pkg::PCIE_BAR_DATA_W_DFLT,
    parameter int unsigned BAR_W  = pcie_dma_pkg::PCIE_BAR_NUM_W_DFLT,
    parameter int unsigned TAG_W  = pcie_dma_pkg::PCIE_RC_TAG_W_DFLT
);

  localparam int unsigned STRB_W = DATA_W / 8;

  logic              req_valid;
  logic              req_ready;
  logic              req_write;
  logic [BAR_W-1:0]  req_bar;
  logic [ADDR_W-1:0] req_addr;
  logic [DATA_W-1:0] req_data;
  logic [STRB_W-1:0] req_strb;
  logic [TAG_W-1:0]  req_tag;

  logic              rsp_valid;
  logic              rsp_ready;
  logic [DATA_W-1:0] rsp_data;
  logic [       1:0] rsp_status;
  logic [TAG_W-1:0]  rsp_tag;

  `DDR_RING_STATIC_ASSERT((DATA_W > 0) && ((DATA_W % 8) == 0),
                          "pcie_rc_model_if DATA_W must be byte aligned")
  `DDR_RING_STATIC_ASSERT(ADDR_W > 0, "pcie_rc_model_if ADDR_W must be greater than zero")
  `DDR_RING_STATIC_ASSERT(TAG_W > 0, "pcie_rc_model_if TAG_W must be greater than zero")

  modport host(
      output req_valid,
      input req_ready,
      output req_write,
      output req_bar,
      output req_addr,
      output req_data,
      output req_strb,
      output req_tag,

      input rsp_valid,
      output rsp_ready,
      input rsp_data,
      input rsp_status,
      input rsp_tag
  );

  modport device(
      input req_valid,
      output req_ready,
      input req_write,
      input req_bar,
      input req_addr,
      input req_data,
      input req_strb,
      input req_tag,

      output rsp_valid,
      input rsp_ready,
      output rsp_data,
      output rsp_status,
      output rsp_tag
  );

  modport monitor(
      input req_valid,
      input req_ready,
      input req_write,
      input req_bar,
      input req_addr,
      input req_data,
      input req_strb,
      input req_tag,

      input rsp_valid,
      input rsp_ready,
      input rsp_data,
      input rsp_status,
      input rsp_tag
  );

endinterface
/* verilator lint_on UNDRIVEN */
/* verilator lint_on UNUSEDSIGNAL */
