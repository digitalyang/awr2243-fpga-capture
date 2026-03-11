`include "slot_packer_macros.svh"

package slot_packer_pkg;

    // ────────────────────────────────────────────────────────────
    //  Slot header field byte offsets (little-endian layout)
    // ────────────────────────────────────────────────────────────
    localparam int unsigned SLOT_HDR_MAGIC_BYTE_OFS        = 0;   // 4 bytes
    localparam int unsigned SLOT_HDR_MAGIC_BYTES           = 4;
    localparam int unsigned SLOT_HDR_VERSION_BYTE_OFS      = 4;   // 1 byte
    localparam int unsigned SLOT_HDR_VERSION_BYTES         = 1;
    localparam int unsigned SLOT_HDR_FLAGS_BYTE_OFS        = 5;   // 1 byte
    localparam int unsigned SLOT_HDR_FLAGS_BYTES           = 1;
    localparam int unsigned SLOT_HDR_RSVD0_BYTE_OFS       = 6;   // 2 bytes reserved
    localparam int unsigned SLOT_HDR_PKT_SEQ_BYTE_OFS     = 8;   // 2 bytes
    localparam int unsigned SLOT_HDR_PKT_SEQ_BYTES        = 2;
    localparam int unsigned SLOT_HDR_PKT_BYTES_BYTE_OFS   = 10;  // 2 bytes
    localparam int unsigned SLOT_HDR_PKT_BYTES_BYTES      = 2;
    localparam int unsigned SLOT_HDR_SAMPLE_CNT_BYTE_OFS  = 12;  // 2 bytes
    localparam int unsigned SLOT_HDR_SAMPLE_CNT_BYTES     = 2;
    localparam int unsigned SLOT_HDR_RSVD1_BYTE_OFS       = 14;  // 2 bytes reserved
    localparam int unsigned SLOT_HDR_SLOT_BYTES_BYTE_OFS  = 16;  // 4 bytes
    localparam int unsigned SLOT_HDR_SLOT_BYTES_SIZE      = 4;
    localparam int unsigned SLOT_HDR_SAMPLE_AREA_BYTE_OFS = 20;  // 4 bytes
    localparam int unsigned SLOT_HDR_SAMPLE_AREA_SIZE     = 4;
    localparam int unsigned SLOT_HDR_CQ_AREA_BYTE_OFS     = 24;  // 2 bytes
    localparam int unsigned SLOT_HDR_CQ_AREA_SIZE         = 2;
    // bytes 26-63: reserved (zero-filled)

    // ────────────────────────────────────────────────────────────
    //  Header flags bit positions within the 8-bit flags byte
    // ────────────────────────────────────────────────────────────
    localparam int unsigned SLOT_HDR_FLAG_CRC_ERR_BIT     = 0;
    localparam int unsigned SLOT_HDR_FLAG_ECC_ERR_BIT     = 1;
    localparam int unsigned SLOT_HDR_FLAG_TRUNC_ERR_BIT   = 2;
    localparam int unsigned SLOT_HDR_FLAG_VALID_GOOD_BIT  = 3;
    localparam int unsigned SLOT_HDR_FLAG_OVERFLOW_BIT    = 4;

    // ────────────────────────────────────────────────────────────
    //  Default magic / version values
    // ────────────────────────────────────────────────────────────
    localparam logic [31:0] SLOT_HDR_MAGIC_VAL_DFLT   = 32'hAA55_1024;
    localparam logic [7:0]  SLOT_HDR_VERSION_VAL_DFLT = 8'h01;

    // ────────────────────────────────────────────────────────────
    //  Utility functions (synthesis-safe)
    // ────────────────────────────────────────────────────────────
    function automatic int unsigned clog2_safe(input int unsigned value);
        if (value <= 1) begin
            return 1;
        end

        return $clog2(value);
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

    function automatic int unsigned max_u(
        input int unsigned lhs,
        input int unsigned rhs
    );
        if (lhs > rhs) begin
            return lhs;
        end

        return rhs;
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

    function automatic bit is_pow2_u(input int unsigned value);
        if (value == 0) begin
            return 1'b0;
        end

        return (value & (value - 1)) == 0;
    endfunction

endpackage
