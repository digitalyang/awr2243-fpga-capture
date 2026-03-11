`include "csi_packet_extractor_macros.svh"

// Filters CSI-2 long packets by VC/DT and forwards accepted AXI-Stream beats
// while generating packet-level status sideband for downstream modules.
module csi_packet_extractor #(
    parameter int unsigned AXIS_DATA_W           = `CSI_AXIS_DATA_W_DFLT,
    parameter int unsigned AXIS_USER_W           = `CSI_AXIS_USER_W_DFLT,
    parameter int unsigned VC_W                  = csi_packet_pkg::CSI_VC_W,
    parameter int unsigned DT_W                  = csi_packet_pkg::CSI_DT_W,
    parameter int unsigned PAYLOAD_LEN_W         = csi_packet_pkg::CSI_WORD_COUNT_W,
    parameter int unsigned MAX_PACKET_BYTES      = (1 << csi_packet_pkg::CSI_WORD_COUNT_W) - 1,
    parameter int unsigned PKT_BYTE_CNT_W        = csi_packet_pkg::clog2_safe(MAX_PACKET_BYTES + 1),
    parameter int unsigned PKT_SEQ_W             = `CSI_PKT_SEQ_W_DFLT,
    parameter int unsigned FIFO_DEPTH            = `CSI_FIFO_DEPTH_DFLT,
    parameter int unsigned TUSER_PKT_START_BIT   = csi_packet_pkg::CSI_TUSER_PKT_START_BIT_DFLT,
    parameter int unsigned TUSER_CRC_ERR_BIT     = csi_packet_pkg::CSI_TUSER_CRC_ERR_BIT_DFLT,
    parameter int unsigned TUSER_ECC_ERR_BIT     = csi_packet_pkg::CSI_TUSER_ECC_ERR_BIT_DFLT,
    parameter int unsigned TUSER_TRUNC_ERR_BIT   = csi_packet_pkg::CSI_TUSER_TRUNC_ERR_BIT_DFLT,
    parameter int unsigned TUSER_VC_LSB          = csi_packet_pkg::CSI_TUSER_VC_LSB_DFLT,
    parameter int unsigned TUSER_DT_LSB          = csi_packet_pkg::CSI_TUSER_DT_LSB_DFLT,
    parameter int unsigned TUSER_PAYLOAD_LEN_LSB = csi_packet_pkg::CSI_TUSER_PAYLOAD_LEN_LSB_DFLT
) (
    input  logic                                      clk_i,
    input  logic                                      rst_ni,
    input  logic                                      cfg_vc_en_i,
    input  logic                                      cfg_dt_en_i,
    input  logic                 [          VC_W-1:0] cfg_vc_i,
    input  logic                 [          DT_W-1:0] cfg_dt_i,
    output logic                                      pkt_start_o,
    output logic                                      pkt_done_o,
    output logic                                      pkt_valid_good_o,
    output logic                 [     PKT_SEQ_W-1:0] pkt_seq_o,
    output logic                 [PKT_BYTE_CNT_W-1:0] pkt_bytes_o,
    output logic                                      pkt_crc_err_o,
    output logic                                      pkt_ecc_err_o,
    output logic                                      pkt_trunc_err_o,
           axis_stream_if.slave                       s_axis,
           axis_stream_if.master                      m_axis
);

  import csi_packet_pkg::*;

  localparam int unsigned AXIS_KEEP_W = AXIS_DATA_W / 8;
  localparam int unsigned AXIS_BEAT_BYTES = AXIS_DATA_W / 8;
  localparam int unsigned BEAT_BYTE_CNT_W = clog2_safe(AXIS_BEAT_BYTES + 1);
  localparam int unsigned FIFO_AW = clog2_safe(FIFO_DEPTH);

  typedef enum logic [1:0] {
    ST_IDLE,
    ST_CHECK,
    ST_ACCEPT,
    ST_DROP
  } extractor_state_e;

  typedef struct packed {
    logic [AXIS_DATA_W-1:0] data;
    logic [AXIS_KEEP_W-1:0] keep;
    logic                   last;
    logic [AXIS_USER_W-1:0] user;
  } axis_beat_s;

  extractor_state_e                       state_r;
  extractor_state_e                       state_n;
  axis_beat_s                             first_beat_r;
  axis_beat_s                             first_beat_n;
  logic             [ PKT_BYTE_CNT_W-1:0] pkt_bytes_r;
  logic             [ PKT_BYTE_CNT_W-1:0] pkt_bytes_n;
  logic             [  PAYLOAD_LEN_W-1:0] exp_pkt_bytes_r;
  logic             [  PAYLOAD_LEN_W-1:0] exp_pkt_bytes_n;
  logic             [      PKT_SEQ_W-1:0] pkt_seq_r;
  logic             [      PKT_SEQ_W-1:0] pkt_seq_n;
  logic             [      PKT_SEQ_W-1:0] pkt_seq_ctr_r;
  logic             [      PKT_SEQ_W-1:0] pkt_seq_ctr_n;
  logic                                   pkt_crc_err_r;
  logic                                   pkt_crc_err_n;
  logic                                   pkt_ecc_err_r;
  logic                                   pkt_ecc_err_n;
  logic                                   pkt_trunc_err_r;
  logic                                   pkt_trunc_err_n;

  logic                                   s_fire_c;
  logic                                   m_fire_c;
  logic             [BEAT_BYTE_CNT_W-1:0] first_beat_bytes_c;
  logic             [BEAT_BYTE_CNT_W-1:0] stream_beat_bytes_c;
  logic             [           VC_W-1:0] first_vc_c;
  logic             [           DT_W-1:0] first_dt_c;
  logic             [  PAYLOAD_LEN_W-1:0] first_payload_len_c;
  logic                                   first_crc_err_c;
  logic                                   first_ecc_err_c;
  logic                                   first_trunc_err_c;
  logic                                   stream_crc_err_c;
  logic                                   stream_ecc_err_c;
  logic                                   stream_trunc_err_c;
  logic                                   pkt_match_c;
  logic             [      PKT_SEQ_W-1:0] pkt_seq_view_c;
  logic             [ PKT_BYTE_CNT_W-1:0] pkt_bytes_view_c;
  logic                                   pkt_crc_err_view_c;
  logic                                   pkt_ecc_err_view_c;
  logic                                   pkt_trunc_err_view_c;
  logic                                   pkt_done_view_c;

  function automatic logic [BEAT_BYTE_CNT_W-1:0] count_keep_bytes(
      input logic [AXIS_KEEP_W-1:0] keep);
    logic        [BEAT_BYTE_CNT_W-1:0] sum_c;
    int unsigned                       idx;
    begin
      sum_c = '0;
      for (idx = 0; idx < AXIS_KEEP_W; idx++) begin
        sum_c = sum_c + BEAT_BYTE_CNT_W'(keep[idx]);
      end
      return sum_c;
    end
  endfunction

  assign first_beat_bytes_c = count_keep_bytes(first_beat_r.keep);
  assign stream_beat_bytes_c = count_keep_bytes(s_axis.tkeep);

  assign first_vc_c = first_beat_r.user[TUSER_VC_LSB+:VC_W];
  assign first_dt_c = first_beat_r.user[TUSER_DT_LSB+:DT_W];
  assign first_payload_len_c = first_beat_r.user[TUSER_PAYLOAD_LEN_LSB+:PAYLOAD_LEN_W];

  assign first_crc_err_c = first_beat_r.user[TUSER_CRC_ERR_BIT];
  assign first_ecc_err_c = first_beat_r.user[TUSER_ECC_ERR_BIT];
  assign first_trunc_err_c = first_beat_r.user[TUSER_TRUNC_ERR_BIT];
  assign stream_crc_err_c = s_axis.tuser[TUSER_CRC_ERR_BIT];
  assign stream_ecc_err_c = s_axis.tuser[TUSER_ECC_ERR_BIT];
  assign stream_trunc_err_c = s_axis.tuser[TUSER_TRUNC_ERR_BIT];

  assign pkt_match_c =
        ((!cfg_vc_en_i) || (first_vc_c == cfg_vc_i)) &&
        ((!cfg_dt_en_i) || (first_dt_c == cfg_dt_i));

  assign s_fire_c = s_axis.tvalid && s_axis.tready;
  assign m_fire_c = m_axis.tvalid && m_axis.tready;

  // Main packet FSM:
  // - latch the first beat so VC/DT can be checked before forwarding
  // - stream accepted packets through unchanged
  // - consume rejected packets until tlast to keep the input stream aligned
  always_comb begin
    state_n         = state_r;
    first_beat_n    = first_beat_r;
    pkt_bytes_n     = pkt_bytes_r;
    exp_pkt_bytes_n = exp_pkt_bytes_r;
    pkt_seq_n       = pkt_seq_r;
    pkt_seq_ctr_n   = pkt_seq_ctr_r;
    pkt_crc_err_n   = pkt_crc_err_r;
    pkt_ecc_err_n   = pkt_ecc_err_r;
    pkt_trunc_err_n = pkt_trunc_err_r;

    s_axis.tready   = 1'b0;
    m_axis.tdata    = '0;
    m_axis.tkeep    = '0;
    m_axis.tvalid   = 1'b0;
    m_axis.tlast    = 1'b0;
    m_axis.tuser    = '0;

    case (state_r)
      ST_IDLE: begin
        s_axis.tready = 1'b1;

        if (s_fire_c) begin
          first_beat_n.data = s_axis.tdata;
          first_beat_n.keep = s_axis.tkeep;
          first_beat_n.last = s_axis.tlast;
          first_beat_n.user = s_axis.tuser;
          pkt_bytes_n       = '0;
          exp_pkt_bytes_n   = '0;
          pkt_crc_err_n     = 1'b0;
          pkt_ecc_err_n     = 1'b0;
          pkt_trunc_err_n   = 1'b0;
          state_n           = ST_CHECK;
        end
      end

      ST_CHECK: begin
        if (pkt_match_c) begin
          m_axis.tdata  = first_beat_r.data;
          m_axis.tkeep  = first_beat_r.keep;
          m_axis.tvalid = 1'b1;
          m_axis.tlast  = first_beat_r.last;
          m_axis.tuser  = first_beat_r.user;

          if (m_fire_c) begin
            pkt_seq_n       = pkt_seq_ctr_r;
            pkt_seq_ctr_n   = pkt_seq_ctr_r + PKT_SEQ_W'(1);
            pkt_bytes_n     = PKT_BYTE_CNT_W'(first_beat_bytes_c);
            exp_pkt_bytes_n = first_payload_len_c;
            pkt_crc_err_n   = first_crc_err_c;
            pkt_ecc_err_n   = first_ecc_err_c;
            pkt_trunc_err_n = first_trunc_err_c;

            if (first_beat_r.last) begin
              pkt_trunc_err_n = first_trunc_err_c ||
                                              (PKT_BYTE_CNT_W'(first_beat_bytes_c) != PKT_BYTE_CNT_W'(first_payload_len_c));
              state_n = ST_IDLE;
            end else begin
              pkt_trunc_err_n = first_trunc_err_c ||
                                              (PKT_BYTE_CNT_W'(first_beat_bytes_c) > PKT_BYTE_CNT_W'(first_payload_len_c));
              state_n = ST_ACCEPT;
            end
          end
        end else begin
          if (first_beat_r.last) begin
            state_n = ST_IDLE;
          end else begin
            state_n = ST_DROP;
          end
        end
      end

      ST_ACCEPT: begin
        s_axis.tready = m_axis.tready;
        m_axis.tdata  = s_axis.tdata;
        m_axis.tkeep  = s_axis.tkeep;
        m_axis.tvalid = s_axis.tvalid;
        m_axis.tlast  = s_axis.tlast;
        m_axis.tuser  = s_axis.tuser;

        if (s_fire_c) begin
          pkt_bytes_n = pkt_bytes_r + PKT_BYTE_CNT_W'(stream_beat_bytes_c);
          pkt_crc_err_n = pkt_crc_err_r | stream_crc_err_c;
          pkt_ecc_err_n = pkt_ecc_err_r | stream_ecc_err_c;
          pkt_trunc_err_n = pkt_trunc_err_r |
                                      stream_trunc_err_c |
                                      ((pkt_bytes_r + PKT_BYTE_CNT_W'(stream_beat_bytes_c)) > PKT_BYTE_CNT_W'(exp_pkt_bytes_r));

          if (s_axis.tlast) begin
            pkt_trunc_err_n = pkt_trunc_err_r |
                                          stream_trunc_err_c |
                                          ((pkt_bytes_r + PKT_BYTE_CNT_W'(stream_beat_bytes_c)) != PKT_BYTE_CNT_W'(exp_pkt_bytes_r));
            state_n = ST_IDLE;
          end
        end
      end

      ST_DROP: begin
        s_axis.tready = 1'b1;

        if (s_fire_c && s_axis.tlast) begin
          state_n = ST_IDLE;
        end
      end

      default: begin
        state_n = ST_IDLE;
      end
    endcase
  end

  // Build a "same-cycle" view of packet status so pkt_done/metadata can pulse on
  // the final accepted beat without waiting for the next clock edge.
  always_comb begin
    pkt_seq_view_c       = pkt_seq_r;
    pkt_bytes_view_c     = pkt_bytes_r;
    pkt_crc_err_view_c   = pkt_crc_err_r;
    pkt_ecc_err_view_c   = pkt_ecc_err_r;
    pkt_trunc_err_view_c = pkt_trunc_err_r;
    pkt_done_view_c      = 1'b0;

    if ((state_r == ST_CHECK) && pkt_match_c && m_fire_c) begin
      pkt_seq_view_c       = pkt_seq_ctr_r;
      pkt_bytes_view_c     = PKT_BYTE_CNT_W'(first_beat_bytes_c);
      pkt_crc_err_view_c   = first_crc_err_c;
      pkt_ecc_err_view_c   = first_ecc_err_c;
      pkt_trunc_err_view_c = first_trunc_err_c;

      if (first_beat_r.last) begin
        pkt_trunc_err_view_c = first_trunc_err_c ||
                                       (PKT_BYTE_CNT_W'(first_beat_bytes_c) != PKT_BYTE_CNT_W'(first_payload_len_c));
        pkt_done_view_c = 1'b1;
      end else begin
        pkt_trunc_err_view_c = first_trunc_err_c ||
                                       (PKT_BYTE_CNT_W'(first_beat_bytes_c) > PKT_BYTE_CNT_W'(first_payload_len_c));
      end
    end else if ((state_r == ST_ACCEPT) && s_fire_c) begin
      pkt_seq_view_c = pkt_seq_r;
      pkt_bytes_view_c = pkt_bytes_r + PKT_BYTE_CNT_W'(stream_beat_bytes_c);
      pkt_crc_err_view_c = pkt_crc_err_r | stream_crc_err_c;
      pkt_ecc_err_view_c = pkt_ecc_err_r | stream_ecc_err_c;
      pkt_trunc_err_view_c = pkt_trunc_err_r |
                                   stream_trunc_err_c |
                                   ((pkt_bytes_r + PKT_BYTE_CNT_W'(stream_beat_bytes_c)) > PKT_BYTE_CNT_W'(exp_pkt_bytes_r));

      if (s_axis.tlast) begin
        pkt_trunc_err_view_c = pkt_trunc_err_r |
                                       stream_trunc_err_c |
                                       ((pkt_bytes_r + PKT_BYTE_CNT_W'(stream_beat_bytes_c)) != PKT_BYTE_CNT_W'(exp_pkt_bytes_r));
        pkt_done_view_c = 1'b1;
      end
    end
  end

  assign pkt_start_o = (state_r == ST_CHECK) && pkt_match_c && m_fire_c;
  assign pkt_done_o = pkt_done_view_c;
  assign pkt_seq_o = pkt_seq_view_c;
  assign pkt_bytes_o = pkt_bytes_view_c;
  assign pkt_crc_err_o = pkt_crc_err_view_c;
  assign pkt_ecc_err_o = pkt_ecc_err_view_c;
  assign pkt_trunc_err_o = pkt_trunc_err_view_c;
  assign pkt_valid_good_o = pkt_done_view_c &&
                            !pkt_crc_err_view_c &&
                            !pkt_ecc_err_view_c &&
                            !pkt_trunc_err_view_c;

  // All packet bookkeeping is kept in a single register bank so the metadata
  // seen by pkt_* outputs matches the forwarded packet stream.
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_r         <= ST_IDLE;
      first_beat_r    <= '0;
      pkt_bytes_r     <= '0;
      exp_pkt_bytes_r <= '0;
      pkt_seq_r       <= '0;
      pkt_seq_ctr_r   <= '0;
      pkt_crc_err_r   <= 1'b0;
      pkt_ecc_err_r   <= 1'b0;
      pkt_trunc_err_r <= 1'b0;
    end else begin
      state_r         <= state_n;
      first_beat_r    <= first_beat_n;
      pkt_bytes_r     <= pkt_bytes_n;
      exp_pkt_bytes_r <= exp_pkt_bytes_n;
      pkt_seq_r       <= pkt_seq_n;
      pkt_seq_ctr_r   <= pkt_seq_ctr_n;
      pkt_crc_err_r   <= pkt_crc_err_n;
      pkt_ecc_err_r   <= pkt_ecc_err_n;
      pkt_trunc_err_r <= pkt_trunc_err_n;
    end
  end

  if (1) begin : g_static_checks
    `CSI_STATIC_ASSERT(AXIS_DATA_W > 0, "AXIS_DATA_W must be greater than zero")
    `CSI_STATIC_ASSERT((AXIS_DATA_W % 8) == 0, "AXIS_DATA_W must be byte aligned")
    `CSI_STATIC_ASSERT(AXIS_KEEP_W == (AXIS_DATA_W / 8), "AXIS_KEEP_W must match AXIS_DATA_W / 8")
    `CSI_STATIC_ASSERT($bits(m_axis.tdata) == AXIS_DATA_W,
                       "input/output AXIS data widths must match")
    `CSI_STATIC_ASSERT($bits(m_axis.tkeep) == AXIS_KEEP_W,
                       "input/output AXIS keep widths must match")
    `CSI_STATIC_ASSERT($bits(m_axis.tuser) == AXIS_USER_W,
                       "input/output AXIS user widths must match")
    `CSI_STATIC_ASSERT(FIFO_DEPTH >= 2, "FIFO_DEPTH must be at least 2")
    `CSI_STATIC_ASSERT(MAX_PACKET_BYTES > 0, "MAX_PACKET_BYTES must be greater than zero")
    `CSI_STATIC_ASSERT(TUSER_PKT_START_BIT < AXIS_USER_W, "TUSER_PKT_START_BIT out of range")
    `CSI_STATIC_ASSERT(TUSER_CRC_ERR_BIT < AXIS_USER_W, "TUSER_CRC_ERR_BIT out of range")
    `CSI_STATIC_ASSERT(TUSER_ECC_ERR_BIT < AXIS_USER_W, "TUSER_ECC_ERR_BIT out of range")
    `CSI_STATIC_ASSERT(TUSER_TRUNC_ERR_BIT < AXIS_USER_W, "TUSER_TRUNC_ERR_BIT out of range")
    `CSI_STATIC_ASSERT((TUSER_VC_LSB + VC_W) <= AXIS_USER_W, "TUSER_VC field out of range")
    `CSI_STATIC_ASSERT((TUSER_DT_LSB + DT_W) <= AXIS_USER_W, "TUSER_DT field out of range")
    `CSI_STATIC_ASSERT((TUSER_PAYLOAD_LEN_LSB + PAYLOAD_LEN_W) <= AXIS_USER_W,
                       "TUSER_PAYLOAD_LEN field out of range")
  end

endmodule
