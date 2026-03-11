`include "slot_packer_macros.svh"

module fixed_slot_packer #(
    parameter int unsigned AXIS_DATA_W       = `SLOT_PKR_AXIS_DATA_W_DFLT,
    parameter int unsigned AXIS_USER_W       = `SLOT_PKR_AXIS_USER_W_DFLT,
    parameter int unsigned PKT_SEQ_W         = `SLOT_PKR_PKT_SEQ_W_DFLT,
    parameter int unsigned PKT_BYTE_CNT_W    = `SLOT_PKR_PKT_BYTE_CNT_W_DFLT,
    parameter int unsigned SAMPLE_SLOT_NUM   = `SLOT_PKR_SAMPLE_SLOT_NUM_DFLT,
    parameter int unsigned SAMPLE_UNIT_BYTES = `SLOT_PKR_SAMPLE_UNIT_BYTES_DFLT,
    parameter int unsigned CQ_AREA_BYTES     = `SLOT_PKR_CQ_AREA_BYTES_DFLT,
    parameter int unsigned HEADER_BYTES      = `SLOT_PKR_HEADER_BYTES_DFLT,
    parameter int unsigned ALIGN_BYTES       = `SLOT_PKR_ALIGN_BYTES_DFLT,
    parameter logic [31:0] SLOT_HDR_MAGIC    = slot_packer_pkg::SLOT_HDR_MAGIC_VAL_DFLT,
    parameter logic [7:0]  SLOT_HDR_VERSION  = slot_packer_pkg::SLOT_HDR_VERSION_VAL_DFLT,
    parameter int unsigned SLOT_BYTES_W      = slot_packer_pkg::clog2_safe(
                                                   slot_packer_pkg::align_up_u(
                                                       HEADER_BYTES +
                                                       SAMPLE_SLOT_NUM * SAMPLE_UNIT_BYTES +
                                                       CQ_AREA_BYTES,
                                                       ALIGN_BYTES
                                                   ) + 1
                                               )
) (
    input  logic                           clk_i,
    input  logic                           rst_ni,

    // ── configuration ──────────────────────────────────────────
    input  logic                           cfg_drop_invalid_pkt_i,

    // ── upstream packet sideband (from CSI Packet Extractor) ──
    input  logic                           pkt_start_i,
    input  logic                           pkt_done_i,
    input  logic [PKT_BYTE_CNT_W-1:0]     pkt_bytes_i,
    input  logic [PKT_SEQ_W-1:0]          pkt_seq_i,
    input  logic                           pkt_crc_err_i,
    input  logic                           pkt_ecc_err_i,
    input  logic                           pkt_trunc_err_i,
    input  logic                           pkt_valid_good_i,

    // ── downstream slot sideband (to DDR RingBuffer) ──────────
    output logic                           slot_start_o,
    output logic                           slot_done_o,
    output logic [SLOT_BYTES_W-1:0]        slot_bytes_o,
    output logic [PKT_SEQ_W-1:0]          slot_seq_o,
    output logic                           slot_valid_good_o,
    output logic                           slot_overflow_err_o,

    // ── AXI-Stream interfaces ─────────────────────────────────
    axis_stream_if.slave                   s_axis,
    axis_stream_if.master                  m_axis
);

    import slot_packer_pkg::*;

    // ================================================================
    //  Localparam derivations
    // ================================================================
    localparam int unsigned AXIS_KEEP_W     = AXIS_DATA_W / 8;
    localparam int unsigned AXIS_BEAT_BYTES = AXIS_DATA_W / 8;
    localparam int unsigned BEAT_BYTE_CNT_W = clog2_safe(AXIS_BEAT_BYTES + 1);

    localparam int unsigned SAMPLE_UNIT_BITS  = SAMPLE_UNIT_BYTES * 8;
    localparam int unsigned SAMPLE_AREA_BYTES = SAMPLE_SLOT_NUM * SAMPLE_UNIT_BYTES;
    localparam int unsigned SAMPLE_CNT_W      = clog2_safe(SAMPLE_SLOT_NUM + 1);

    localparam int unsigned HEADER_BITS = HEADER_BYTES * 8;

    localparam int unsigned SLOT_TOTAL_UNALIGNED = HEADER_BYTES +
                                                   SAMPLE_AREA_BYTES +
                                                   CQ_AREA_BYTES;
    localparam int unsigned SLOT_TOTAL_ALIGNED   = align_up_u(SLOT_TOTAL_UNALIGNED,
                                                              ALIGN_BYTES);
    localparam int unsigned PAD_BYTES            = SLOT_TOTAL_ALIGNED -
                                                   SLOT_TOTAL_UNALIGNED;

    localparam int unsigned HEADER_BEATS      = HEADER_BYTES      / AXIS_BEAT_BYTES;
    localparam int unsigned SAMPLE_AREA_BEATS = SAMPLE_AREA_BYTES / AXIS_BEAT_BYTES;
    localparam int unsigned CQ_AREA_BEATS     = CQ_AREA_BYTES     / AXIS_BEAT_BYTES;
    localparam int unsigned PAD_BEATS         = PAD_BYTES          / AXIS_BEAT_BYTES;
    localparam int unsigned SLOT_TOTAL_BEATS  = SLOT_TOTAL_ALIGNED / AXIS_BEAT_BYTES;

    localparam int unsigned CAP_BUF_BEATS = SAMPLE_AREA_BEATS;
    localparam int unsigned BEAT_CNT_W    = clog2_safe(max_u(SLOT_TOTAL_BEATS, 1) + 1);

    // Header field bit positions (byte offset * 8)
    localparam int unsigned HDR_MAGIC_BIT_LSB       = SLOT_HDR_MAGIC_BYTE_OFS       * 8;
    localparam int unsigned HDR_VERSION_BIT_LSB     = SLOT_HDR_VERSION_BYTE_OFS     * 8;
    localparam int unsigned HDR_FLAGS_BIT_LSB       = SLOT_HDR_FLAGS_BYTE_OFS       * 8;
    localparam int unsigned HDR_PKT_SEQ_BIT_LSB     = SLOT_HDR_PKT_SEQ_BYTE_OFS    * 8;
    localparam int unsigned HDR_PKT_BYTES_BIT_LSB   = SLOT_HDR_PKT_BYTES_BYTE_OFS  * 8;
    localparam int unsigned HDR_SAMPLE_CNT_BIT_LSB  = SLOT_HDR_SAMPLE_CNT_BYTE_OFS * 8;
    localparam int unsigned HDR_SLOT_BYTES_BIT_LSB  = SLOT_HDR_SLOT_BYTES_BYTE_OFS * 8;
    localparam int unsigned HDR_SAMPLE_AREA_BIT_LSB = SLOT_HDR_SAMPLE_AREA_BYTE_OFS * 8;
    localparam int unsigned HDR_CQ_AREA_BIT_LSB     = SLOT_HDR_CQ_AREA_BYTE_OFS    * 8;

    localparam int unsigned HDR_PKT_SEQ_FIELD_BITS    = SLOT_HDR_PKT_SEQ_BYTES    * 8;
    localparam int unsigned HDR_PKT_BYTES_FIELD_BITS  = SLOT_HDR_PKT_BYTES_BYTES  * 8;
    localparam int unsigned HDR_SAMPLE_CNT_FIELD_BITS = SLOT_HDR_SAMPLE_CNT_BYTES * 8;

    // ================================================================
    //  Type declarations
    // ================================================================
    typedef enum logic [2:0] {
        ST_IDLE,
        ST_CAPTURE,
        ST_HEADER,
        ST_PAYLOAD,
        ST_SAMPLE_PAD,
        ST_CQ_PAD,
        ST_ALIGN_PAD
    } packer_state_e;

    // ================================================================
    //  Register declarations
    // ================================================================
    packer_state_e              state_r;
    packer_state_e              state_n;

    logic [BEAT_CNT_W-1:0]      out_beat_cnt_r;
    logic [BEAT_CNT_W-1:0]      out_beat_cnt_n;
    logic [BEAT_CNT_W-1:0]      total_out_beat_cnt_r;
    logic [BEAT_CNT_W-1:0]      total_out_beat_cnt_n;

    logic [BEAT_CNT_W-1:0]      cap_beat_cnt_r;
    logic [BEAT_CNT_W-1:0]      cap_beat_cnt_n;

    logic [PKT_SEQ_W-1:0]      cap_pkt_seq_r;
    logic [PKT_SEQ_W-1:0]      cap_pkt_seq_n;
    logic [PKT_BYTE_CNT_W-1:0] cap_pkt_bytes_r;
    logic [PKT_BYTE_CNT_W-1:0] cap_pkt_bytes_n;

    logic                       cap_pkt_crc_err_r;
    logic                       cap_pkt_crc_err_n;
    logic                       cap_pkt_ecc_err_r;
    logic                       cap_pkt_ecc_err_n;
    logic                       cap_pkt_trunc_err_r;
    logic                       cap_pkt_trunc_err_n;
    logic                       cap_pkt_valid_good_r;
    logic                       cap_pkt_valid_good_n;
    logic                       cap_overflow_r;
    logic                       cap_overflow_n;

    // Capture buffer (register array)
    logic [AXIS_DATA_W-1:0]     cap_buf_data_r [0:CAP_BUF_BEATS-1];

    // ================================================================
    //  Combinational wires
    // ================================================================
    logic                        s_fire_c;
    logic                        m_fire_c;
    logic [BEAT_BYTE_CNT_W-1:0]  keep_bytes_c;
    logic [AXIS_DATA_W-1:0]      masked_data_c;
    logic                        is_slot_last_beat_c;
    logic                        should_drop_c;

    logic [BEAT_CNT_W-1:0]       sample_pad_beats_c;
    logic [HEADER_BITS-1:0]      hdr_word_c;
    logic [SAMPLE_CNT_W-1:0]     actual_sample_cnt_c;

    logic                        cap_buf_wr_en_c;
    logic [BEAT_CNT_W-1:0]       cap_buf_wr_idx_c;
    logic [AXIS_DATA_W-1:0]      cap_buf_wr_data_c;

    // ================================================================
    //  Functions
    // ================================================================
    function automatic logic [BEAT_BYTE_CNT_W-1:0] count_keep_bytes(
        input logic [AXIS_KEEP_W-1:0] keep
    );
        logic [BEAT_BYTE_CNT_W-1:0] sum_c;
        int unsigned                idx;
        begin
            sum_c = '0;
            for (idx = 0; idx < AXIS_KEEP_W; idx++) begin
                sum_c = sum_c + BEAT_BYTE_CNT_W'(keep[idx]);
            end
            return sum_c;
        end
    endfunction

    function automatic logic [AXIS_DATA_W-1:0] mask_data_with_keep(
        input logic [AXIS_DATA_W-1:0] data,
        input logic [AXIS_KEEP_W-1:0] keep
    );
        logic [AXIS_DATA_W-1:0] result;
        int unsigned            idx;
        begin
            result = '0;
            for (idx = 0; idx < AXIS_KEEP_W; idx++) begin
                if (keep[idx]) begin
                    result[idx*8 +: 8] = data[idx*8 +: 8];
                end
            end
            return result;
        end
    endfunction

    // ================================================================
    //  Continuous assignments
    // ================================================================
    assign s_fire_c    = s_axis.tvalid && s_axis.tready;
    assign m_fire_c    = m_axis.tvalid && m_axis.tready;
    assign keep_bytes_c = count_keep_bytes(s_axis.tkeep);
    assign masked_data_c = mask_data_with_keep(s_axis.tdata, s_axis.tkeep);

    assign is_slot_last_beat_c = (total_out_beat_cnt_r ==
                                  BEAT_CNT_W'(SLOT_TOTAL_BEATS - 1));

    assign sample_pad_beats_c = BEAT_CNT_W'(SAMPLE_AREA_BEATS) - cap_beat_cnt_r;

    assign should_drop_c = !pkt_valid_good_i && cfg_drop_invalid_pkt_i;

    // Actual sample count placed in sample area (capped at SAMPLE_SLOT_NUM)
    assign actual_sample_cnt_c =
        (cap_pkt_bytes_r >= PKT_BYTE_CNT_W'(SAMPLE_AREA_BYTES))
            ? SAMPLE_CNT_W'(SAMPLE_SLOT_NUM)
            : SAMPLE_CNT_W'(cap_pkt_bytes_r / SAMPLE_UNIT_BYTES);

    // ────────────────────────────────────────────────────────────
    //  Combinational header word construction
    //  Built from captured registers; stable during output phase.
    // ────────────────────────────────────────────────────────────
    always_comb begin
        hdr_word_c = '0;

        hdr_word_c[HDR_MAGIC_BIT_LSB       +: 32] = SLOT_HDR_MAGIC;
        hdr_word_c[HDR_VERSION_BIT_LSB      +: 8]  = SLOT_HDR_VERSION;

        hdr_word_c[HDR_FLAGS_BIT_LSB + SLOT_HDR_FLAG_CRC_ERR_BIT]   = cap_pkt_crc_err_r;
        hdr_word_c[HDR_FLAGS_BIT_LSB + SLOT_HDR_FLAG_ECC_ERR_BIT]   = cap_pkt_ecc_err_r;
        hdr_word_c[HDR_FLAGS_BIT_LSB + SLOT_HDR_FLAG_TRUNC_ERR_BIT] = cap_pkt_trunc_err_r;
        hdr_word_c[HDR_FLAGS_BIT_LSB + SLOT_HDR_FLAG_VALID_GOOD_BIT] = cap_pkt_valid_good_r;
        hdr_word_c[HDR_FLAGS_BIT_LSB + SLOT_HDR_FLAG_OVERFLOW_BIT]   = cap_overflow_r;

        hdr_word_c[HDR_PKT_SEQ_BIT_LSB    +: HDR_PKT_SEQ_FIELD_BITS]    =
            HDR_PKT_SEQ_FIELD_BITS'(cap_pkt_seq_r);
        hdr_word_c[HDR_PKT_BYTES_BIT_LSB  +: HDR_PKT_BYTES_FIELD_BITS]  =
            HDR_PKT_BYTES_FIELD_BITS'(cap_pkt_bytes_r);
        hdr_word_c[HDR_SAMPLE_CNT_BIT_LSB +: HDR_SAMPLE_CNT_FIELD_BITS] =
            HDR_SAMPLE_CNT_FIELD_BITS'(actual_sample_cnt_c);

        hdr_word_c[HDR_SLOT_BYTES_BIT_LSB  +: 32] = 32'(SLOT_TOTAL_ALIGNED);
        hdr_word_c[HDR_SAMPLE_AREA_BIT_LSB +: 32] = 32'(SAMPLE_AREA_BYTES);
        hdr_word_c[HDR_CQ_AREA_BIT_LSB     +: 16] = 16'(CQ_AREA_BYTES);
    end

    // ────────────────────────────────────────────────────────────
    //  Slot-level sideband outputs
    // ────────────────────────────────────────────────────────────
    assign slot_start_o        = m_axis.tvalid && (total_out_beat_cnt_r == '0);
    assign slot_done_o         = m_axis.tvalid && is_slot_last_beat_c;
    assign slot_bytes_o        = SLOT_BYTES_W'(SLOT_TOTAL_ALIGNED);
    assign slot_seq_o          = cap_pkt_seq_r;
    assign slot_valid_good_o   = cap_pkt_valid_good_r;
    assign slot_overflow_err_o = cap_overflow_r;

    // ================================================================
    //  Main combinational block (FSM + datapath)
    // ================================================================
    always_comb begin
        // ── defaults (hold) ────────────────────────────────────
        state_n               = state_r;
        out_beat_cnt_n        = out_beat_cnt_r;
        total_out_beat_cnt_n  = total_out_beat_cnt_r;
        cap_beat_cnt_n        = cap_beat_cnt_r;
        cap_pkt_seq_n         = cap_pkt_seq_r;
        cap_pkt_bytes_n       = cap_pkt_bytes_r;
        cap_pkt_crc_err_n     = cap_pkt_crc_err_r;
        cap_pkt_ecc_err_n     = cap_pkt_ecc_err_r;
        cap_pkt_trunc_err_n   = cap_pkt_trunc_err_r;
        cap_pkt_valid_good_n  = cap_pkt_valid_good_r;
        cap_overflow_n        = cap_overflow_r;

        // ── input side defaults ────────────────────────────────
        s_axis.tready = 1'b0;

        // ── output side defaults ───────────────────────────────
        m_axis.tdata  = '0;
        m_axis.tkeep  = '0;
        m_axis.tvalid = 1'b0;
        m_axis.tlast  = 1'b0;
        m_axis.tuser  = '0;

        // ── buffer write defaults ──────────────────────────────
        cap_buf_wr_en_c   = 1'b0;
        cap_buf_wr_idx_c  = '0;
        cap_buf_wr_data_c = '0;

        case (state_r)
            // ────────────────────────────────────────────────────
            //  ST_IDLE: wait for first beat of a new packet
            // ────────────────────────────────────────────────────
            ST_IDLE: begin
                s_axis.tready = 1'b1;

                if (s_fire_c) begin
                    cap_buf_wr_en_c   = 1'b1;
                    cap_buf_wr_idx_c  = '0;
                    cap_buf_wr_data_c = masked_data_c;

                    cap_beat_cnt_n    = BEAT_CNT_W'(1);
                    cap_pkt_seq_n     = pkt_seq_i;
                    cap_overflow_n    = 1'b0;

                    if (pkt_done_i) begin
                        // Single-beat packet: latch final metadata
                        cap_pkt_bytes_n       = pkt_bytes_i;
                        cap_pkt_crc_err_n     = pkt_crc_err_i;
                        cap_pkt_ecc_err_n     = pkt_ecc_err_i;
                        cap_pkt_trunc_err_n   = pkt_trunc_err_i;
                        cap_pkt_valid_good_n  = pkt_valid_good_i;

                        if (pkt_bytes_i > PKT_BYTE_CNT_W'(SAMPLE_AREA_BYTES)) begin
                            cap_overflow_n = 1'b1;
                        end

                        if (should_drop_c) begin
                            state_n        = ST_IDLE;
                            cap_beat_cnt_n = '0;
                        end else begin
                            state_n              = ST_HEADER;
                            out_beat_cnt_n       = '0;
                            total_out_beat_cnt_n = '0;
                        end
                    end else begin
                        state_n = ST_CAPTURE;
                    end
                end
            end

            // ────────────────────────────────────────────────────
            //  ST_CAPTURE: absorb remaining beats of the packet
            // ────────────────────────────────────────────────────
            ST_CAPTURE: begin
                s_axis.tready = 1'b1;

                if (s_fire_c) begin
                    if (cap_beat_cnt_r < BEAT_CNT_W'(CAP_BUF_BEATS)) begin
                        cap_buf_wr_en_c   = 1'b1;
                        cap_buf_wr_idx_c  = cap_beat_cnt_r;
                        cap_buf_wr_data_c = masked_data_c;
                        cap_beat_cnt_n    = cap_beat_cnt_r + BEAT_CNT_W'(1);
                    end else begin
                        cap_overflow_n = 1'b1;
                    end

                    if (pkt_done_i) begin
                        cap_pkt_bytes_n       = pkt_bytes_i;
                        cap_pkt_crc_err_n     = pkt_crc_err_i;
                        cap_pkt_ecc_err_n     = pkt_ecc_err_i;
                        cap_pkt_trunc_err_n   = pkt_trunc_err_i;
                        cap_pkt_valid_good_n  = pkt_valid_good_i;

                        if (pkt_bytes_i > PKT_BYTE_CNT_W'(SAMPLE_AREA_BYTES)) begin
                            cap_overflow_n = 1'b1;
                        end

                        if (should_drop_c) begin
                            state_n        = ST_IDLE;
                            cap_beat_cnt_n = '0;
                        end else begin
                            state_n              = ST_HEADER;
                            out_beat_cnt_n       = '0;
                            total_out_beat_cnt_n = '0;
                        end
                    end
                end
            end

            // ────────────────────────────────────────────────────
            //  ST_HEADER: output header beats
            // ────────────────────────────────────────────────────
            ST_HEADER: begin
                m_axis.tdata  = hdr_word_c[out_beat_cnt_r * AXIS_DATA_W +: AXIS_DATA_W];
                m_axis.tkeep  = {AXIS_KEEP_W{1'b1}};
                m_axis.tvalid = 1'b1;
                m_axis.tlast  = is_slot_last_beat_c;

                if (m_fire_c) begin
                    out_beat_cnt_n       = out_beat_cnt_r + BEAT_CNT_W'(1);
                    total_out_beat_cnt_n = total_out_beat_cnt_r + BEAT_CNT_W'(1);

                    if (out_beat_cnt_r == BEAT_CNT_W'(HEADER_BEATS - 1)) begin
                        out_beat_cnt_n = '0;
                        if (cap_beat_cnt_r > '0) begin
                            state_n = ST_PAYLOAD;
                        end else if (SAMPLE_AREA_BEATS > 0) begin
                            state_n = ST_SAMPLE_PAD;
                        end else if (CQ_AREA_BEATS > 0) begin
                            state_n = ST_CQ_PAD;
                        end else if (PAD_BEATS > 0) begin
                            state_n = ST_ALIGN_PAD;
                        end else begin
                            state_n        = ST_IDLE;
                            cap_beat_cnt_n = '0;
                        end
                    end
                end
            end

            // ────────────────────────────────────────────────────
            //  ST_PAYLOAD: output captured sample data from buffer
            // ────────────────────────────────────────────────────
            ST_PAYLOAD: begin
                m_axis.tdata  = cap_buf_data_r[out_beat_cnt_r];
                m_axis.tkeep  = {AXIS_KEEP_W{1'b1}};
                m_axis.tvalid = 1'b1;
                m_axis.tlast  = is_slot_last_beat_c;

                if (m_fire_c) begin
                    out_beat_cnt_n       = out_beat_cnt_r + BEAT_CNT_W'(1);
                    total_out_beat_cnt_n = total_out_beat_cnt_r + BEAT_CNT_W'(1);

                    if (out_beat_cnt_r == cap_beat_cnt_r - BEAT_CNT_W'(1)) begin
                        out_beat_cnt_n = '0;
                        if (cap_beat_cnt_r < BEAT_CNT_W'(SAMPLE_AREA_BEATS)) begin
                            state_n = ST_SAMPLE_PAD;
                        end else if (CQ_AREA_BEATS > 0) begin
                            state_n = ST_CQ_PAD;
                        end else if (PAD_BEATS > 0) begin
                            state_n = ST_ALIGN_PAD;
                        end else begin
                            state_n        = ST_IDLE;
                            cap_beat_cnt_n = '0;
                        end
                    end
                end
            end

            // ────────────────────────────────────────────────────
            //  ST_SAMPLE_PAD: zero-fill remaining sample area
            // ────────────────────────────────────────────────────
            ST_SAMPLE_PAD: begin
                m_axis.tdata  = '0;
                m_axis.tkeep  = {AXIS_KEEP_W{1'b1}};
                m_axis.tvalid = 1'b1;
                m_axis.tlast  = is_slot_last_beat_c;

                if (m_fire_c) begin
                    out_beat_cnt_n       = out_beat_cnt_r + BEAT_CNT_W'(1);
                    total_out_beat_cnt_n = total_out_beat_cnt_r + BEAT_CNT_W'(1);

                    if (out_beat_cnt_r == sample_pad_beats_c - BEAT_CNT_W'(1)) begin
                        out_beat_cnt_n = '0;
                        if (CQ_AREA_BEATS > 0) begin
                            state_n = ST_CQ_PAD;
                        end else if (PAD_BEATS > 0) begin
                            state_n = ST_ALIGN_PAD;
                        end else begin
                            state_n        = ST_IDLE;
                            cap_beat_cnt_n = '0;
                        end
                    end
                end
            end

            // ────────────────────────────────────────────────────
            //  ST_CQ_PAD: zero-fill CQ area
            // ────────────────────────────────────────────────────
            ST_CQ_PAD: begin
                m_axis.tdata  = '0;
                m_axis.tkeep  = {AXIS_KEEP_W{1'b1}};
                m_axis.tvalid = 1'b1;
                m_axis.tlast  = is_slot_last_beat_c;

                if (m_fire_c) begin
                    out_beat_cnt_n       = out_beat_cnt_r + BEAT_CNT_W'(1);
                    total_out_beat_cnt_n = total_out_beat_cnt_r + BEAT_CNT_W'(1);

                    if (out_beat_cnt_r == BEAT_CNT_W'(CQ_AREA_BEATS - 1)) begin
                        out_beat_cnt_n = '0;
                        if (PAD_BEATS > 0) begin
                            state_n = ST_ALIGN_PAD;
                        end else begin
                            state_n        = ST_IDLE;
                            cap_beat_cnt_n = '0;
                        end
                    end
                end
            end

            // ────────────────────────────────────────────────────
            //  ST_ALIGN_PAD: zero-fill to 64B alignment
            // ────────────────────────────────────────────────────
            ST_ALIGN_PAD: begin
                m_axis.tdata  = '0;
                m_axis.tkeep  = {AXIS_KEEP_W{1'b1}};
                m_axis.tvalid = 1'b1;
                m_axis.tlast  = is_slot_last_beat_c;

                if (m_fire_c) begin
                    out_beat_cnt_n       = out_beat_cnt_r + BEAT_CNT_W'(1);
                    total_out_beat_cnt_n = total_out_beat_cnt_r + BEAT_CNT_W'(1);

                    if (out_beat_cnt_r == BEAT_CNT_W'(PAD_BEATS - 1)) begin
                        state_n        = ST_IDLE;
                        cap_beat_cnt_n = '0;
                    end
                end
            end

            default: begin
                state_n = ST_IDLE;
            end
        endcase
    end

    // ================================================================
    //  Register update (single always_ff for all control + buffer)
    // ================================================================
    always_ff @(posedge clk_i or negedge rst_ni) begin
        if (!rst_ni) begin
            state_r               <= ST_IDLE;
            out_beat_cnt_r        <= '0;
            total_out_beat_cnt_r  <= '0;
            cap_beat_cnt_r        <= '0;
            cap_pkt_seq_r         <= '0;
            cap_pkt_bytes_r       <= '0;
            cap_pkt_crc_err_r     <= 1'b0;
            cap_pkt_ecc_err_r     <= 1'b0;
            cap_pkt_trunc_err_r   <= 1'b0;
            cap_pkt_valid_good_r  <= 1'b0;
            cap_overflow_r        <= 1'b0;
        end else begin
            state_r               <= state_n;
            out_beat_cnt_r        <= out_beat_cnt_n;
            total_out_beat_cnt_r  <= total_out_beat_cnt_n;
            cap_beat_cnt_r        <= cap_beat_cnt_n;
            cap_pkt_seq_r         <= cap_pkt_seq_n;
            cap_pkt_bytes_r       <= cap_pkt_bytes_n;
            cap_pkt_crc_err_r     <= cap_pkt_crc_err_n;
            cap_pkt_ecc_err_r     <= cap_pkt_ecc_err_n;
            cap_pkt_trunc_err_r   <= cap_pkt_trunc_err_n;
            cap_pkt_valid_good_r  <= cap_pkt_valid_good_n;
            cap_overflow_r        <= cap_overflow_n;

            if (cap_buf_wr_en_c) begin
                cap_buf_data_r[cap_buf_wr_idx_c] <= cap_buf_wr_data_c;
            end
        end
    end

    // ================================================================
    //  Static assertions
    // ================================================================
    if (1) begin : g_static_checks
        `SLOT_PKR_STATIC_ASSERT(AXIS_DATA_W > 0,
            "AXIS_DATA_W must be greater than zero")
        `SLOT_PKR_STATIC_ASSERT((AXIS_DATA_W % 8) == 0,
            "AXIS_DATA_W must be byte aligned")
        `SLOT_PKR_STATIC_ASSERT(is_pow2_u(AXIS_BEAT_BYTES),
            "AXIS_BEAT_BYTES must be a power of two")

        `SLOT_PKR_STATIC_ASSERT(HEADER_BYTES > 0,
            "HEADER_BYTES must be greater than zero")
        `SLOT_PKR_STATIC_ASSERT((HEADER_BYTES % AXIS_BEAT_BYTES) == 0,
            "HEADER_BYTES must be a multiple of AXIS_BEAT_BYTES")

        `SLOT_PKR_STATIC_ASSERT(SAMPLE_SLOT_NUM > 0,
            "SAMPLE_SLOT_NUM must be greater than zero")
        `SLOT_PKR_STATIC_ASSERT(SAMPLE_UNIT_BYTES > 0,
            "SAMPLE_UNIT_BYTES must be greater than zero")
        `SLOT_PKR_STATIC_ASSERT((SAMPLE_AREA_BYTES % AXIS_BEAT_BYTES) == 0,
            "SAMPLE_AREA_BYTES must be a multiple of AXIS_BEAT_BYTES")

        `SLOT_PKR_STATIC_ASSERT((CQ_AREA_BYTES % AXIS_BEAT_BYTES) == 0,
            "CQ_AREA_BYTES must be a multiple of AXIS_BEAT_BYTES")

        `SLOT_PKR_STATIC_ASSERT(is_pow2_u(ALIGN_BYTES),
            "ALIGN_BYTES must be a power of two")
        `SLOT_PKR_STATIC_ASSERT(ALIGN_BYTES >= AXIS_BEAT_BYTES,
            "ALIGN_BYTES must be >= AXIS_BEAT_BYTES")
        `SLOT_PKR_STATIC_ASSERT((ALIGN_BYTES % AXIS_BEAT_BYTES) == 0,
            "ALIGN_BYTES must be a multiple of AXIS_BEAT_BYTES")

        `SLOT_PKR_STATIC_ASSERT(SLOT_TOTAL_BEATS > 0,
            "SLOT_TOTAL_BEATS must be greater than zero")
        `SLOT_PKR_STATIC_ASSERT(SLOT_TOTAL_ALIGNED <= (1 << SLOT_BYTES_W),
            "SLOT_BYTES_W too narrow for SLOT_TOTAL_ALIGNED")

        `SLOT_PKR_STATIC_ASSERT(HEADER_BITS <= (HEADER_BEATS * AXIS_DATA_W),
            "HEADER_BITS mismatch with HEADER_BEATS * AXIS_DATA_W")

        `SLOT_PKR_STATIC_ASSERT($bits(m_axis.tdata) == AXIS_DATA_W,
            "Input and output AXIS data widths must match")
        `SLOT_PKR_STATIC_ASSERT($bits(m_axis.tkeep) == AXIS_KEEP_W,
            "Input and output AXIS keep widths must match")
    end

endmodule
