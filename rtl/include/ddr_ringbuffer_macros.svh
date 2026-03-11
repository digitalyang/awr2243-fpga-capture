`ifndef DDR_RINGBUFFER_MACROS_SVH
`define DDR_RINGBUFFER_MACROS_SVH

`define DDR_RING_AXIS_DATA_W_DFLT             256
`define DDR_RING_AXIS_USER_W_DFLT             64
`define DDR_RING_AXI_DATA_W_DFLT              256
`define DDR_RING_AXI_ADDR_W_DFLT              34
`define DDR_RING_RING_SIZE_BYTES_DFLT         65536
`define DDR_RING_SLOT_BUFFER_BYTES_DFLT       8192
`define DDR_RING_SLOT_STRIDE_BYTES_DFLT       4096
`define DDR_RING_FIFO_DEPTH_DFLT              32
`define DDR_RING_MAX_BURST_LEN_DFLT           16
`define DDR_RING_ALIGN_BYTES_DFLT             32
`define DDR_RING_ALMOST_FULL_MARGIN_DFLT      4096
`define DDR_RING_COUNTER_W_DFLT               32
`define DDR_RING_SLOT_SEQ_W_DFLT              16

`define DDR_RING_STATIC_ASSERT(_cond, _msg) \
    initial begin \
        if (!(_cond)) begin \
            $error("%m static assertion failed: %s", _msg); \
            $fatal; \
        end \
    end

`endif
