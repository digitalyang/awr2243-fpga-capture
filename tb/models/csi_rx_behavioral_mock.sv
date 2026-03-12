module csi_rx_behavioral_mock #(
    parameter int unsigned DATA_WIDTH       = 256,
    parameter int unsigned KEEP_WIDTH       = (DATA_WIDTH / 8),
    parameter int unsigned USER_WIDTH       = 64,
    parameter int unsigned COUNT_WIDTH      = 16,
    parameter int unsigned VC_WIDTH         = 2,
    parameter int unsigned DT_WIDTH         = 6,
    parameter int unsigned SHORT_DATA_WIDTH = 16
) (
    input logic clk_i,
    input logic rst_ni,

    input  logic [DATA_WIDTH-1:0] s_axis_tdata,
    input  logic [KEEP_WIDTH-1:0] s_axis_tkeep,
    input  logic                  s_axis_tvalid,
    output logic                  s_axis_tready,
    input  logic                  s_axis_tlast,
    input  logic [USER_WIDTH-1:0] s_axis_tuser,

    output logic [DATA_WIDTH-1:0] m_axis_tdata,
    output logic [KEEP_WIDTH-1:0] m_axis_tkeep,
    output logic                  m_axis_tvalid,
    input  logic                  m_axis_tready,
    output logic                  m_axis_tlast,
    output logic [USER_WIDTH-1:0] m_axis_tuser,

    input  logic                        short_pkt_valid_i,
    output logic                        short_pkt_ready_o,
    input  logic [        DT_WIDTH-1:0] short_pkt_dt_i,
    input  logic [        VC_WIDTH-1:0] short_pkt_vc_i,
    input  logic [SHORT_DATA_WIDTH-1:0] short_pkt_data_i,

    input logic [COUNT_WIDTH-1:0] cfg_startup_latency_cycles_i,
    input logic [COUNT_WIDTH-1:0] cfg_interpacket_gap_cycles_i,
    input logic [COUNT_WIDTH-1:0] cfg_beat_gap_cycles_i,

    output logic                        status_busy_o,
    output logic                        status_gap_active_o,
    output logic [     COUNT_WIDTH-1:0] status_packet_count_o,
    output logic [     COUNT_WIDTH-1:0] status_beat_count_o,
    output logic                        status_frame_active_o,
    output logic                        status_line_active_o,
    output logic [     COUNT_WIDTH-1:0] status_short_packet_count_o,
    output logic                        status_short_packet_error_o,
    output logic [     COUNT_WIDTH-1:0] status_short_packet_error_count_o,
    output logic [     COUNT_WIDTH-1:0] status_frame_count_o,
    output logic [     COUNT_WIDTH-1:0] status_line_count_o,
    output logic [                 3:0] status_last_short_error_code_o,
    output logic [        DT_WIDTH-1:0] status_last_short_dt_o,
    output logic [        VC_WIDTH-1:0] status_last_short_vc_o,
    output logic [SHORT_DATA_WIDTH-1:0] status_last_short_data_o
);
  localparam logic [DT_WIDTH-1:0] DT_FS = DT_WIDTH'(6'h00);
  localparam logic [DT_WIDTH-1:0] DT_FE = DT_WIDTH'(6'h01);
  localparam logic [DT_WIDTH-1:0] DT_LS = DT_WIDTH'(6'h02);
  localparam logic [DT_WIDTH-1:0] DT_LE = DT_WIDTH'(6'h03);
  localparam logic [3:0] SP_ERR_NONE = 4'd0;
  localparam logic [3:0] SP_ERR_FS_WHILE_ACTIVE = 4'd1;
  localparam logic [3:0] SP_ERR_FE_WITHOUT_FS = 4'd2;
  localparam logic [3:0] SP_ERR_FE_BEFORE_LE = 4'd3;
  localparam logic [3:0] SP_ERR_LS_WITHOUT_FS = 4'd4;
  localparam logic [3:0] SP_ERR_NESTED_LS = 4'd5;
  localparam logic [3:0] SP_ERR_LE_WITHOUT_LS = 4'd6;

  logic                        startup_armed_reg;
  logic                        startup_pending_reg;
  logic                        in_packet_reg;
  logic                        frame_active_reg;
  logic                        line_active_reg;
  logic                        short_packet_error_reg;
  logic [     COUNT_WIDTH-1:0] startup_delay_reg;
  logic [     COUNT_WIDTH-1:0] interpacket_gap_reg;
  logic [     COUNT_WIDTH-1:0] beat_gap_reg;
  logic [     COUNT_WIDTH-1:0] packet_count_reg;
  logic [     COUNT_WIDTH-1:0] beat_count_reg;
  logic [     COUNT_WIDTH-1:0] short_packet_count_reg;
  logic [     COUNT_WIDTH-1:0] short_packet_error_count_reg;
  logic [     COUNT_WIDTH-1:0] frame_count_reg;
  logic [     COUNT_WIDTH-1:0] line_count_reg;
  logic [                 3:0] last_short_error_code_reg;
  logic [        DT_WIDTH-1:0] last_short_dt_reg;
  logic [        VC_WIDTH-1:0] last_short_vc_reg;
  logic [SHORT_DATA_WIDTH-1:0] last_short_data_reg;
  logic                        startup_hold_c;
  logic                        forward_enable_c;
  logic                        transfer_c;
  logic                        short_pkt_accept_c;
  logic                        short_pkt_error_c;
  logic [                 3:0] short_pkt_error_code_c;

  assign startup_hold_c = startup_pending_reg
      || (startup_armed_reg && s_axis_tvalid && (cfg_startup_latency_cycles_i != '0));
  assign forward_enable_c = rst_ni
      && !startup_hold_c
      && (interpacket_gap_reg == '0)
      && (beat_gap_reg == '0);
  assign transfer_c = forward_enable_c && s_axis_tvalid && m_axis_tready;

  assign s_axis_tready = forward_enable_c && m_axis_tready;
  assign m_axis_tdata = s_axis_tdata;
  assign m_axis_tkeep = s_axis_tkeep;
  assign m_axis_tvalid = forward_enable_c && s_axis_tvalid;
  assign m_axis_tlast = s_axis_tlast;
  assign m_axis_tuser = s_axis_tuser;
  assign short_pkt_ready_o = rst_ni;
  assign short_pkt_accept_c = short_pkt_valid_i && short_pkt_ready_o;

  assign status_busy_o = startup_hold_c || in_packet_reg || s_axis_tvalid;
  assign status_gap_active_o = startup_hold_c
      || (interpacket_gap_reg != '0)
      || (beat_gap_reg != '0);
  assign status_packet_count_o = packet_count_reg;
  assign status_beat_count_o = beat_count_reg;
  assign status_frame_active_o = frame_active_reg;
  assign status_line_active_o = line_active_reg;
  assign status_short_packet_count_o = short_packet_count_reg;
  assign status_short_packet_error_o = short_packet_error_reg;
  assign status_short_packet_error_count_o = short_packet_error_count_reg;
  assign status_frame_count_o = frame_count_reg;
  assign status_line_count_o = line_count_reg;
  assign status_last_short_error_code_o = last_short_error_code_reg;
  assign status_last_short_dt_o = last_short_dt_reg;
  assign status_last_short_vc_o = last_short_vc_reg;
  assign status_last_short_data_o = last_short_data_reg;

  always_comb begin
    short_pkt_error_c      = 1'b0;
    short_pkt_error_code_c = SP_ERR_NONE;

    unique case (short_pkt_dt_i)
      DT_FS: begin
        if (frame_active_reg || line_active_reg) begin
          short_pkt_error_c      = 1'b1;
          short_pkt_error_code_c = SP_ERR_FS_WHILE_ACTIVE;
        end
      end
      DT_FE: begin
        if (!frame_active_reg) begin
          short_pkt_error_c      = 1'b1;
          short_pkt_error_code_c = SP_ERR_FE_WITHOUT_FS;
        end else if (line_active_reg) begin
          short_pkt_error_c      = 1'b1;
          short_pkt_error_code_c = SP_ERR_FE_BEFORE_LE;
        end
      end
      DT_LS: begin
        if (!frame_active_reg) begin
          short_pkt_error_c      = 1'b1;
          short_pkt_error_code_c = SP_ERR_LS_WITHOUT_FS;
        end else if (line_active_reg) begin
          short_pkt_error_c      = 1'b1;
          short_pkt_error_code_c = SP_ERR_NESTED_LS;
        end
      end
      DT_LE: begin
        if (!line_active_reg) begin
          short_pkt_error_c      = 1'b1;
          short_pkt_error_code_c = SP_ERR_LE_WITHOUT_LS;
        end
      end
      default: begin
      end
    endcase
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      startup_armed_reg            <= 1'b1;
      startup_pending_reg          <= 1'b0;
      in_packet_reg                <= 1'b0;
      frame_active_reg             <= 1'b0;
      line_active_reg              <= 1'b0;
      short_packet_error_reg       <= 1'b0;
      startup_delay_reg            <= '0;
      interpacket_gap_reg          <= '0;
      beat_gap_reg                 <= '0;
      packet_count_reg             <= '0;
      beat_count_reg               <= '0;
      short_packet_count_reg       <= '0;
      short_packet_error_count_reg <= '0;
      frame_count_reg              <= '0;
      line_count_reg               <= '0;
      last_short_error_code_reg    <= SP_ERR_NONE;
      last_short_dt_reg            <= '0;
      last_short_vc_reg            <= '0;
      last_short_data_reg          <= '0;
    end else begin
      if (startup_armed_reg && s_axis_tvalid) begin
        startup_armed_reg <= 1'b0;
        if (cfg_startup_latency_cycles_i != '0) begin
          startup_pending_reg <= 1'b1;
          startup_delay_reg   <= cfg_startup_latency_cycles_i;
        end
      end else if (startup_pending_reg) begin
        if (startup_delay_reg > COUNT_WIDTH'(1)) begin
          startup_delay_reg <= startup_delay_reg - COUNT_WIDTH'(1);
        end else begin
          startup_delay_reg   <= '0;
          startup_pending_reg <= 1'b0;
        end
      end

      if (interpacket_gap_reg != '0) begin
        interpacket_gap_reg <= interpacket_gap_reg - COUNT_WIDTH'(1);
      end

      if (beat_gap_reg != '0) begin
        beat_gap_reg <= beat_gap_reg - COUNT_WIDTH'(1);
      end

      if (transfer_c) begin
        beat_count_reg <= beat_count_reg + COUNT_WIDTH'(1);
        in_packet_reg  <= !s_axis_tlast;

        if (s_axis_tlast) begin
          packet_count_reg    <= packet_count_reg + COUNT_WIDTH'(1);
          interpacket_gap_reg <= cfg_interpacket_gap_cycles_i;
          beat_gap_reg        <= '0;
        end else begin
          beat_gap_reg <= cfg_beat_gap_cycles_i;
        end
      end

      if (short_pkt_accept_c) begin
        short_packet_count_reg <= short_packet_count_reg + COUNT_WIDTH'(1);
        last_short_dt_reg      <= short_pkt_dt_i;
        last_short_vc_reg      <= short_pkt_vc_i;
        last_short_data_reg    <= short_pkt_data_i;

        if (short_pkt_error_c) begin
          short_packet_error_reg       <= 1'b1;
          short_packet_error_count_reg <= short_packet_error_count_reg + COUNT_WIDTH'(1);
          last_short_error_code_reg    <= short_pkt_error_code_c;
        end

        // Explicit policy: count every accepted short packet, but separately
        // flag and count order violations while still applying deterministic
        // recovery to frame/line state.
        unique case (short_pkt_dt_i)
          DT_FS: begin
            frame_active_reg <= 1'b1;
            line_active_reg  <= 1'b0;
            frame_count_reg  <= frame_count_reg + COUNT_WIDTH'(1);
          end
          DT_FE: begin
            frame_active_reg <= 1'b0;
            line_active_reg  <= 1'b0;
          end
          DT_LS: begin
            if (frame_active_reg && !line_active_reg) begin
              line_active_reg <= 1'b1;
              line_count_reg  <= line_count_reg + COUNT_WIDTH'(1);
            end
          end
          DT_LE: begin
            line_active_reg <= 1'b0;
          end
          default: begin
          end
        endcase
      end
    end
  end
endmodule
