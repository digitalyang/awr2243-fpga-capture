`ifndef CSI_PACKET_EXTRACTOR_MACROS_SVH
`define CSI_PACKET_EXTRACTOR_MACROS_SVH

`define CSI_AXIS_DATA_W_DFLT 256
`define CSI_AXIS_USER_W_DFLT 64
`define CSI_FIFO_DEPTH_DFLT  16
`define CSI_PKT_SEQ_W_DFLT   16

`define CSI_STATIC_ASSERT(_cond, _msg) \
    initial begin \
        if (!(_cond)) begin \
            $error("%m static assertion failed: %s", _msg); \
            $fatal; \
        end \
    end

`endif
