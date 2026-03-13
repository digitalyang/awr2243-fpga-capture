`include "ddr_ringbuffer_macros.svh"

// Shared constants and register-map definitions for the PCIe endpoint DMA shell.
package pcie_dma_pkg;

    function automatic int unsigned clog2_safe(input int unsigned value);
        if (value <= 1) begin
            return 1;
        end

        return $clog2(value);
    endfunction

    localparam int unsigned PCIE_BAR_ADDR_W_DFLT        = 16;
    localparam int unsigned PCIE_BAR_DATA_W_DFLT        = 32;
    localparam int unsigned PCIE_BAR_NUM_W_DFLT         = 3;
    localparam int unsigned PCIE_RC_TAG_W_DFLT          = 8;
    localparam int unsigned PCIE_AXIL_ADDR_W_DFLT       = 16;
    localparam int unsigned PCIE_AXIL_DATA_W_DFLT       = 32;
    localparam int unsigned PCIE_DMA_DESC_ID_W_DFLT     = 8;
    localparam int unsigned PCIE_DMA_AXI_ADDR_W_DFLT    = `DDR_RING_AXI_ADDR_W_DFLT;
    localparam int unsigned PCIE_DMA_AXI_DATA_W_DFLT    = `DDR_RING_AXI_DATA_W_DFLT;
    localparam int unsigned PCIE_BAR0_INTERNAL_BYTES_DFLT = 32'h0000_0100;
    localparam int unsigned PCIE_BAR0_FORWARD_BASE_DFLT   = 32'h0000_1000;
    localparam int unsigned PCIE_DMA_MAX_BURST_LEN_DFLT   = `DDR_RING_MAX_BURST_LEN_DFLT;

    typedef enum logic [1:0] {
        PCIE_MMIO_STATUS_SC = 2'b00,
        PCIE_MMIO_STATUS_UR = 2'b01,
        PCIE_MMIO_STATUS_CA = 2'b10
    } pcie_mmio_status_e;

    typedef struct packed {
        logic [63:0]                               axi_addr;
        logic [31:0]                               len_bytes;
        logic [31:0]                               pattern_seed;
        logic [PCIE_DMA_DESC_ID_W_DFLT-1:0]        desc_id;
        logic                                      irq_on_done;
    } pcie_dma_desc_s;

    localparam logic [PCIE_BAR_ADDR_W_DFLT-1:0] PCIE_DMA_REG_CONTROL        = 16'h0000;
    localparam logic [PCIE_BAR_ADDR_W_DFLT-1:0] PCIE_DMA_REG_STATUS         = 16'h0004;
    localparam logic [PCIE_BAR_ADDR_W_DFLT-1:0] PCIE_DMA_REG_DESC_ADDR_LO   = 16'h0010;
    localparam logic [PCIE_BAR_ADDR_W_DFLT-1:0] PCIE_DMA_REG_DESC_ADDR_HI   = 16'h0014;
    localparam logic [PCIE_BAR_ADDR_W_DFLT-1:0] PCIE_DMA_REG_DESC_LEN       = 16'h0018;
    localparam logic [PCIE_BAR_ADDR_W_DFLT-1:0] PCIE_DMA_REG_DESC_PATTERN   = 16'h001c;
    localparam logic [PCIE_BAR_ADDR_W_DFLT-1:0] PCIE_DMA_REG_DESC_META      = 16'h0020;
    localparam logic [PCIE_BAR_ADDR_W_DFLT-1:0] PCIE_DMA_REG_DOORBELL       = 16'h0024;
    localparam logic [PCIE_BAR_ADDR_W_DFLT-1:0] PCIE_DMA_REG_COMPLETION     = 16'h0028;
    localparam logic [PCIE_BAR_ADDR_W_DFLT-1:0] PCIE_DMA_REG_COMPLETION_LEN = 16'h002c;

    localparam int unsigned PCIE_DMA_CTRL_ENABLE_BIT     = 0;
    localparam int unsigned PCIE_DMA_CTRL_IRQ_ENABLE_BIT = 1;

    localparam int unsigned PCIE_DMA_STATUS_ENABLE_BIT      = 0;
    localparam int unsigned PCIE_DMA_STATUS_IRQ_ENABLE_BIT  = 1;
    localparam int unsigned PCIE_DMA_STATUS_BUSY_BIT        = 8;
    localparam int unsigned PCIE_DMA_STATUS_IRQ_PENDING_BIT = 9;
    localparam int unsigned PCIE_DMA_STATUS_ERROR_BIT       = 10;
    localparam int unsigned PCIE_DMA_STATUS_SHADOW_VALID_BIT = 11;

    localparam int unsigned PCIE_DMA_DESC_META_IRQ_BIT = 16;
    localparam int unsigned PCIE_DMA_DESC_META_DIR_BIT = 17;
    localparam logic        PCIE_DMA_DESC_DIR_H2C      = 1'b1;

endpackage
