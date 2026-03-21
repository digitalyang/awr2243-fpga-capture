`timescale 1ns / 1ps

module csi_rx_axis_pack_ref #(
    parameter integer S_DATA_W = 64,
    parameter integer M_DATA_W = 256,
    parameter integer S_TUSER_W = 96,
    parameter integer M_TUSER_W = 64,
    parameter integer S_TDEST_W = 10,
    parameter integer VC_W = 2,
    parameter integer DT_W = 6,
    parameter integer PAYLOAD_LEN_W = 16,
    parameter integer S_ERR_BIT = 1,
    parameter integer S_VC_TDEST_LSB = 0,
    parameter integer S_DT_TDEST_LSB = 2,
    parameter integer S_PAYLOAD_LEN_LSB = 48
) (
    input  wire                     aclk,
    input  wire                     aresetn,
    input  wire [S_DATA_W-1:0]      s_axis_tdata,
    input  wire [S_DATA_W/8-1:0]    s_axis_tkeep,
    input  wire                     s_axis_tvalid,
    output reg                      s_axis_tready,
    input  wire                     s_axis_tlast,
    input  wire [S_TUSER_W-1:0]     s_axis_tuser,
    input  wire [S_TDEST_W-1:0]     s_axis_tdest,
    output reg  [M_DATA_W-1:0]      m_axis_tdata,
    output reg  [M_DATA_W/8-1:0]    m_axis_tkeep,
    output reg                      m_axis_tvalid,
    input  wire                     m_axis_tready,
    output reg                      m_axis_tlast,
    output reg  [M_TUSER_W-1:0]     m_axis_tuser
);

  localparam integer S_KEEP_W = S_DATA_W / 8;
  localparam integer M_KEEP_W = M_DATA_W / 8;
  localparam integer LANE_RATIO = M_DATA_W / S_DATA_W;
  localparam integer CNT_W = 3;

  localparam integer M_PKT_START_BIT   = 0;
  localparam integer M_CRC_ERR_BIT     = 1;
  localparam integer M_ECC_ERR_BIT     = 2;
  localparam integer M_TRUNC_ERR_BIT   = 3;
  localparam integer M_VC_LSB          = 8;
  localparam integer M_DT_LSB          = 16;
  localparam integer M_PAYLOAD_LEN_LSB = 24;

  reg  [M_DATA_W-1:0]  acc_data_r, acc_data_n;
  reg  [M_KEEP_W-1:0]  acc_keep_r, acc_keep_n;
  reg  [M_TUSER_W-1:0] acc_user_r, acc_user_n;
  reg  [CNT_W-1:0]     acc_count_r, acc_count_n;
  reg                  acc_valid_r, acc_valid_n;

  reg  [M_DATA_W-1:0]  out_data_r, out_data_n;
  reg  [M_KEEP_W-1:0]  out_keep_r, out_keep_n;
  reg  [M_TUSER_W-1:0] out_user_r, out_user_n;
  reg                  out_last_r, out_last_n;
  reg                  out_valid_r, out_valid_n;

  reg  [M_TUSER_W-1:0] pkt_meta_r, pkt_meta_n;
  reg                  in_packet_r, in_packet_n;

  reg  [M_TUSER_W-1:0] beat_meta_base_c;
  reg  [M_TUSER_W-1:0] next_user_c;
  reg  [M_DATA_W-1:0]  next_data_c;
  reg  [M_KEEP_W-1:0]  next_keep_c;
  reg  [CNT_W-1:0]     next_count_c;
  reg                  chunk_complete_c;
  integer              lane_idx_c;
  integer              data_lsb_c;
  integer              keep_lsb_c;

  wire s_err_c;

  assign s_err_c = s_axis_tuser[S_ERR_BIT];

  always @* begin
    beat_meta_base_c = {M_TUSER_W{1'b0}};
    beat_meta_base_c[M_VC_LSB +: VC_W] = s_axis_tdest[S_VC_TDEST_LSB +: VC_W];
    beat_meta_base_c[M_DT_LSB +: DT_W] = s_axis_tdest[S_DT_TDEST_LSB +: DT_W];
    beat_meta_base_c[M_PAYLOAD_LEN_LSB +: PAYLOAD_LEN_W] =
        s_axis_tuser[S_PAYLOAD_LEN_LSB +: PAYLOAD_LEN_W];
  end

  always @* begin
    acc_data_n   = acc_data_r;
    acc_keep_n   = acc_keep_r;
    acc_user_n   = acc_user_r;
    acc_count_n  = acc_count_r;
    acc_valid_n  = acc_valid_r;

    out_data_n   = out_data_r;
    out_keep_n   = out_keep_r;
    out_user_n   = out_user_r;
    out_last_n   = out_last_r;
    out_valid_n  = out_valid_r;

    pkt_meta_n   = pkt_meta_r;
    in_packet_n  = in_packet_r;

    m_axis_tdata  = out_data_r;
    m_axis_tkeep  = out_keep_r;
    m_axis_tuser  = out_user_r;
    m_axis_tlast  = out_last_r;
    m_axis_tvalid = out_valid_r;
    s_axis_tready = ~out_valid_r;

    next_data_c      = acc_data_r;
    next_keep_c      = acc_keep_r;
    next_user_c      = acc_user_r;
    next_count_c     = acc_count_r;
    chunk_complete_c = 1'b0;
    lane_idx_c       = acc_valid_r ? acc_count_r : 0;
    data_lsb_c       = lane_idx_c * S_DATA_W;
    keep_lsb_c       = lane_idx_c * S_KEEP_W;

    if (out_valid_r) begin
      if (m_axis_tready) begin
        out_valid_n = 1'b0;
      end
    end else if (s_axis_tvalid) begin
      next_data_c[data_lsb_c +: S_DATA_W] = s_axis_tdata;
      next_keep_c[keep_lsb_c +: S_KEEP_W] = s_axis_tkeep;

      if (!acc_valid_r) begin
        if (!in_packet_r) begin
          next_user_c = beat_meta_base_c;
          next_user_c[M_PKT_START_BIT] = 1'b1;
        end else begin
          next_user_c = pkt_meta_r;
        end
      end

      next_user_c[M_CRC_ERR_BIT]   = next_user_c[M_CRC_ERR_BIT]   | s_err_c;
      next_user_c[M_ECC_ERR_BIT]   = next_user_c[M_ECC_ERR_BIT]   | s_err_c;
      next_user_c[M_TRUNC_ERR_BIT] = next_user_c[M_TRUNC_ERR_BIT] | s_err_c;

      next_count_c = lane_idx_c + 1;
      chunk_complete_c = s_axis_tlast || (next_count_c == LANE_RATIO);

      if (!in_packet_r) begin
        pkt_meta_n = beat_meta_base_c;
      end
      in_packet_n = ~s_axis_tlast;

      if (chunk_complete_c) begin
        m_axis_tdata  = next_data_c;
        m_axis_tkeep  = next_keep_c;
        m_axis_tuser  = next_user_c;
        m_axis_tlast  = s_axis_tlast;
        m_axis_tvalid = 1'b1;

        acc_data_n   = {M_DATA_W{1'b0}};
        acc_keep_n   = {M_KEEP_W{1'b0}};
        acc_user_n   = {M_TUSER_W{1'b0}};
        acc_count_n  = {CNT_W{1'b0}};
        acc_valid_n  = 1'b0;

        if (!m_axis_tready) begin
          out_data_n  = next_data_c;
          out_keep_n  = next_keep_c;
          out_user_n  = next_user_c;
          out_last_n  = s_axis_tlast;
          out_valid_n = 1'b1;
        end
      end else begin
        acc_data_n   = next_data_c;
        acc_keep_n   = next_keep_c;
        acc_user_n   = next_user_c;
        acc_count_n  = next_count_c;
        acc_valid_n  = 1'b1;
      end
    end
  end

  always @(posedge aclk or negedge aresetn) begin
    if (!aresetn) begin
      acc_data_r  <= {M_DATA_W{1'b0}};
      acc_keep_r  <= {M_KEEP_W{1'b0}};
      acc_user_r  <= {M_TUSER_W{1'b0}};
      acc_count_r <= {CNT_W{1'b0}};
      acc_valid_r <= 1'b0;

      out_data_r  <= {M_DATA_W{1'b0}};
      out_keep_r  <= {M_KEEP_W{1'b0}};
      out_user_r  <= {M_TUSER_W{1'b0}};
      out_last_r  <= 1'b0;
      out_valid_r <= 1'b0;

      pkt_meta_r  <= {M_TUSER_W{1'b0}};
      in_packet_r <= 1'b0;
    end else begin
      acc_data_r  <= acc_data_n;
      acc_keep_r  <= acc_keep_n;
      acc_user_r  <= acc_user_n;
      acc_count_r <= acc_count_n;
      acc_valid_r <= acc_valid_n;

      out_data_r  <= out_data_n;
      out_keep_r  <= out_keep_n;
      out_user_r  <= out_user_n;
      out_last_r  <= out_last_n;
      out_valid_r <= out_valid_n;

      pkt_meta_r  <= pkt_meta_n;
      in_packet_r <= in_packet_n;
    end
  end

endmodule
