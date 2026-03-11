`include "ddr_ringbuffer_macros.svh"

package ddr_ringbuffer_pkg;

    localparam logic [1:0] AXI_RESP_OKAY   = 2'b00;
    localparam logic [1:0] AXI_BURST_INCR  = 2'b01;

    function automatic int unsigned clog2_safe(input int unsigned value);
        if (value <= 1) begin
            return 1;
        end

        return $clog2(value);
    endfunction

    function automatic int unsigned min_u(
        input int unsigned lhs,
        input int unsigned rhs
    );
        if (lhs < rhs) begin
            return lhs;
        end

        return rhs;
    endfunction

    function automatic int unsigned max_u(
        input int unsigned lhs,
        input int unsigned rhs
    );
        if (lhs > rhs) begin
            return lhs;
        end

        return rhs;
    endfunction

    function automatic int unsigned ceil_div_u(
        input int unsigned numerator,
        input int unsigned denominator
    );
        if (denominator == 0) begin
            return 0;
        end

        return (numerator + denominator - 1) / denominator;
    endfunction

    function automatic int unsigned align_up_u(
        input int unsigned value,
        input int unsigned align_bytes
    );
        if (align_bytes <= 1) begin
            return value;
        end

        return ceil_div_u(value, align_bytes) * align_bytes;
    endfunction

    function automatic bit is_pow2_u(input int unsigned value);
        if (value == 0) begin
            return 1'b0;
        end

        return (value & (value - 1)) == 0;
    endfunction

    // Default-width packed types for metadata transport, scoreboarding, and CSR/verification views.
    localparam int unsigned DDR_RING_ADDR_W_DFLT = `DDR_RING_AXI_ADDR_W_DFLT;
    localparam int unsigned DDR_RING_BYTES_W_DFLT = clog2_safe(`DDR_RING_RING_SIZE_BYTES_DFLT + 1);
    localparam int unsigned DDR_RING_SLOT_BYTES_W_DFLT = clog2_safe(
        max_u(
            `DDR_RING_RING_SIZE_BYTES_DFLT,
            max_u(
                `DDR_RING_SLOT_BUFFER_BYTES_DFLT,
                `DDR_RING_SLOT_STRIDE_BYTES_DFLT
            )
        ) + 1
    );
    localparam int unsigned DDR_RING_SLOT_SEQ_W_DFLT = `DDR_RING_SLOT_SEQ_W_DFLT;
    localparam int unsigned DDR_RING_COUNTER_W_DFLT  = `DDR_RING_COUNTER_W_DFLT;

    typedef enum logic [1:0] {
        DDR_RING_DROP_NONE        = 2'd0,
        DDR_RING_DROP_INVALID     = 2'd1,
        DDR_RING_DROP_NO_SPACE    = 2'd2,
        DDR_RING_DROP_OVERWRITE   = 2'd3
    } ddr_ring_drop_reason_e;

    typedef struct packed {
        logic                                      enable;
        logic                                      allow_overwrite;
        logic                                      drop_invalid_slot;
        logic                                      drop_on_no_space;
        logic [DDR_RING_ADDR_W_DFLT-1:0]          ring_base_addr;
        logic [DDR_RING_BYTES_W_DFLT-1:0]         ring_size_bytes;
    } ddr_ring_cfg_s;

    typedef struct packed {
        logic                                      slot_start;
        logic                                      slot_done;
        logic                                      slot_valid_good;
        logic                                      slot_overflow_err;
        logic [DDR_RING_SLOT_BYTES_W_DFLT-1:0]    slot_bytes;
        logic [DDR_RING_SLOT_SEQ_W_DFLT-1:0]      slot_seq;
    } ddr_ring_slot_meta_s;

    typedef struct packed {
        logic [DDR_RING_ADDR_W_DFLT-1:0]          slot_addr;
        logic [DDR_RING_SLOT_BYTES_W_DFLT-1:0]    slot_bytes;
        logic [DDR_RING_SLOT_BYTES_W_DFLT-1:0]    alloc_bytes;
        logic [DDR_RING_SLOT_SEQ_W_DFLT-1:0]      slot_seq;
        logic                                      valid_good;
        logic                                      overflow_err;
    } ddr_ring_slot_desc_s;

    typedef struct packed {
        logic                                      commit_valid;
        logic [DDR_RING_ADDR_W_DFLT-1:0]          slot_addr;
        logic [DDR_RING_SLOT_BYTES_W_DFLT-1:0]    slot_bytes;
        logic [DDR_RING_SLOT_SEQ_W_DFLT-1:0]      slot_seq;
        logic                                      valid_good;
        logic                                      overflow_err;
    } ddr_ring_commit_info_s;

    typedef struct packed {
        logic [DDR_RING_ADDR_W_DFLT-1:0]          wr_ptr;
        logic [DDR_RING_ADDR_W_DFLT-1:0]          rd_ptr;
        logic [DDR_RING_ADDR_W_DFLT-1:0]          commit_ptr;
        logic [DDR_RING_BYTES_W_DFLT-1:0]         used_bytes;
        logic [DDR_RING_BYTES_W_DFLT-1:0]         free_bytes;
        logic [DDR_RING_BYTES_W_DFLT-1:0]         committed_bytes;
        logic [DDR_RING_COUNTER_W_DFLT-1:0]       wrap_count;
        logic [DDR_RING_COUNTER_W_DFLT-1:0]       overflow_count;
        logic [DDR_RING_COUNTER_W_DFLT-1:0]       drop_count;
        logic                                      full;
        logic                                      almost_full;
        logic                                      empty;
        logic                                      err_cfg_align;
        logic                                      err_no_space;
        logic                                      err_slot_proto;
        logic                                      err_slot_too_large;
        logic                                      err_axi_wr_resp;
        logic                                      err_axi_rd_resp;
        logic                                      err_illegal_read;
    } ddr_ring_status_s;

endpackage
