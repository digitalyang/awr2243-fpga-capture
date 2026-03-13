`include "ddr_ringbuffer_macros.svh"

// Shared constants for the pluggable AXI/DDR subsystem. These defaults preserve
// the current ring-buffer placement while reserving host/DMA windows above it.
package axi_ddr_subsystem_pkg;

  localparam int unsigned AXI_DDR_ADDR_W_DFLT = `DDR_RING_AXI_ADDR_W_DFLT;
  localparam int unsigned AXI_DDR_DATA_W_DFLT = `DDR_RING_AXI_DATA_W_DFLT;

  localparam logic [AXI_DDR_ADDR_W_DFLT-1:0] DDR_RESERVED_BASE_ADDR_DFLT =
      AXI_DDR_ADDR_W_DFLT'('h0000_0000);
  localparam int unsigned DDR_RESERVED_BYTES_DFLT = 'h0000_1000;

  localparam logic [AXI_DDR_ADDR_W_DFLT-1:0] DDR_RING_BASE_ADDR_DFLT =
      AXI_DDR_ADDR_W_DFLT'('h0000_1000);
  localparam int unsigned DDR_RING_SIZE_BYTES_DFLT = `DDR_RING_RING_SIZE_BYTES_DFLT;

  localparam logic [AXI_DDR_ADDR_W_DFLT-1:0] DDR_DMA_DESC_BASE_ADDR_DFLT =
      AXI_DDR_ADDR_W_DFLT'('h0002_0000);
  localparam int unsigned DDR_DMA_DESC_BYTES_DFLT = 'h0001_0000;

  localparam logic [AXI_DDR_ADDR_W_DFLT-1:0] DDR_HOST_SCRATCH_BASE_ADDR_DFLT =
      AXI_DDR_ADDR_W_DFLT'('h0003_0000);
  localparam int unsigned DDR_HOST_SCRATCH_BYTES_DFLT = 'h0001_0000;

  typedef enum logic [1:0] {
    AXI_DDR_MASTER_NONE  = 2'd0,
    AXI_DDR_MASTER_RADAR = 2'd1,
    AXI_DDR_MASTER_HOST  = 2'd2
  } axi_ddr_master_e;

endpackage
