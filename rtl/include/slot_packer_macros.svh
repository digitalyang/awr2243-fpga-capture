`ifndef SLOT_PACKER_MACROS_SVH
`define SLOT_PACKER_MACROS_SVH

`define SLOT_PKR_AXIS_DATA_W_DFLT          256
`define SLOT_PKR_AXIS_USER_W_DFLT          64

`define SLOT_PKR_PKT_SEQ_W_DFLT           16
`define SLOT_PKR_PKT_BYTE_CNT_W_DFLT      16

`define SLOT_PKR_SAMPLE_SLOT_NUM_DFLT      1024
`define SLOT_PKR_SAMPLE_UNIT_BYTES_DFLT    4
`define SLOT_PKR_CQ_AREA_BYTES_DFLT        128
`define SLOT_PKR_HEADER_BYTES_DFLT         64
`define SLOT_PKR_ALIGN_BYTES_DFLT          64

`define SLOT_PKR_STATIC_ASSERT(_cond, _msg) \
    initial begin \
        if (!(_cond)) begin \
            $error("%m static assertion failed: %s", _msg); \
            $fatal; \
        end \
    end

`endif
