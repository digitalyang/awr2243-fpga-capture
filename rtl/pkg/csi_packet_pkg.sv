`include "csi_packet_extractor_macros.svh"

package csi_packet_pkg;

    localparam int unsigned CSI_VC_W         = 2;
    localparam int unsigned CSI_DT_W         = 6;
    localparam int unsigned CSI_WORD_COUNT_W = 16;

    localparam int unsigned CSI_TUSER_PKT_START_BIT_DFLT   = 0;
    localparam int unsigned CSI_TUSER_CRC_ERR_BIT_DFLT     = 1;
    localparam int unsigned CSI_TUSER_ECC_ERR_BIT_DFLT     = 2;
    localparam int unsigned CSI_TUSER_TRUNC_ERR_BIT_DFLT   = 3;
    localparam int unsigned CSI_TUSER_VC_LSB_DFLT          = 8;
    localparam int unsigned CSI_TUSER_DT_LSB_DFLT          = 16;
    localparam int unsigned CSI_TUSER_PAYLOAD_LEN_LSB_DFLT = 24;

    typedef struct packed {
        logic crc_err;
        logic ecc_err;
        logic trunc_err;
    } csi_pkt_err_s;

    function automatic int unsigned clog2_safe(input int unsigned value);
        if (value <= 1) begin
            return 1;
        end

        return $clog2(value);
    endfunction

endpackage
