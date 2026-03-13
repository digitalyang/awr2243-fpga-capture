`include "ddr_ringbuffer_macros.svh"

// Two-master, single-slave AXI subsystem boundary for the radar E2E platform.
//
// The port list is intentionally aligned with the shape needed by a future
// verilog-axi axi_crossbar instance. Until that dependency is vendored into
// this repo, a behavioral round-robin arbiter keeps burst visibility explicit
// for verification and preserves a clean handoff point for agent-pipeline and
// agent-host.
module axi_ddr_subsystem #(
    parameter int unsigned AXI_ADDR_W = axi_ddr_subsystem_pkg::AXI_DDR_ADDR_W_DFLT,
    parameter int unsigned AXI_DATA_W = axi_ddr_subsystem_pkg::AXI_DDR_DATA_W_DFLT,
    parameter bit USE_EXTERNAL_VERILOG_AXI = 1'b0
) (
    input logic clk_i,
    input logic rst_ni,

    output logic [1:0] wr_owner_o,
    output logic       wr_owner_valid_o,
    output logic [1:0] rd_owner_o,
    output logic       rd_owner_valid_o,

    axi4_mm_if.slave  s_axi_radar,
    axi4_mm_if.slave  s_axi_host,
    axi4_mm_if.master m_axi_ddr
);

  import axi_ddr_subsystem_pkg::*;
  import ddr_ringbuffer_pkg::*;

  logic            wr_active_r;
  logic            wr_active_n;
  axi_ddr_master_e wr_owner_r;
  axi_ddr_master_e wr_owner_n;
  axi_ddr_master_e wr_last_grant_r;
  axi_ddr_master_e wr_last_grant_n;
  axi_ddr_master_e wr_pick_c;

  logic            rd_active_r;
  logic            rd_active_n;
  axi_ddr_master_e rd_owner_r;
  axi_ddr_master_e rd_owner_n;
  axi_ddr_master_e rd_last_grant_r;
  axi_ddr_master_e rd_last_grant_n;
  axi_ddr_master_e rd_pick_c;

  function automatic axi_ddr_master_e pick_owner(
      input axi_ddr_master_e last_grant,
      input logic radar_req,
      input logic host_req
  );
    if (radar_req && !host_req) begin
      return AXI_DDR_MASTER_RADAR;
    end

    if (!radar_req && host_req) begin
      return AXI_DDR_MASTER_HOST;
    end

    if (radar_req && host_req) begin
      if (last_grant == AXI_DDR_MASTER_RADAR) begin
        return AXI_DDR_MASTER_HOST;
      end

      return AXI_DDR_MASTER_RADAR;
    end

    return AXI_DDR_MASTER_NONE;
  endfunction

  always_comb begin
    wr_owner_n      = wr_owner_r;
    wr_active_n     = wr_active_r;
    wr_last_grant_n = wr_last_grant_r;
    rd_owner_n      = rd_owner_r;
    rd_active_n     = rd_active_r;
    rd_last_grant_n = rd_last_grant_r;

    wr_pick_c       = pick_owner(wr_last_grant_r, s_axi_radar.awvalid, s_axi_host.awvalid);
    rd_pick_c       = pick_owner(rd_last_grant_r, s_axi_radar.arvalid, s_axi_host.arvalid);

    s_axi_radar.awready = 1'b0;
    s_axi_radar.wready  = 1'b0;
    s_axi_radar.bresp   = AXI_RESP_OKAY;
    s_axi_radar.bvalid  = 1'b0;
    s_axi_radar.arready = 1'b0;
    s_axi_radar.rdata   = '0;
    s_axi_radar.rresp   = AXI_RESP_OKAY;
    s_axi_radar.rlast   = 1'b0;
    s_axi_radar.rvalid  = 1'b0;

    s_axi_host.awready  = 1'b0;
    s_axi_host.wready   = 1'b0;
    s_axi_host.bresp    = AXI_RESP_OKAY;
    s_axi_host.bvalid   = 1'b0;
    s_axi_host.arready  = 1'b0;
    s_axi_host.rdata    = '0;
    s_axi_host.rresp    = AXI_RESP_OKAY;
    s_axi_host.rlast    = 1'b0;
    s_axi_host.rvalid   = 1'b0;

    m_axi_ddr.awaddr    = '0;
    m_axi_ddr.awlen     = '0;
    m_axi_ddr.awsize    = '0;
    m_axi_ddr.awburst   = '0;
    m_axi_ddr.awvalid   = 1'b0;
    m_axi_ddr.wdata     = '0;
    m_axi_ddr.wstrb     = '0;
    m_axi_ddr.wlast     = 1'b0;
    m_axi_ddr.wvalid    = 1'b0;
    m_axi_ddr.bready    = 1'b0;
    m_axi_ddr.araddr    = '0;
    m_axi_ddr.arlen     = '0;
    m_axi_ddr.arsize    = '0;
    m_axi_ddr.arburst   = '0;
    m_axi_ddr.arvalid   = 1'b0;
    m_axi_ddr.rready    = 1'b0;

    if (wr_active_r) begin
      case (wr_owner_r)
        AXI_DDR_MASTER_RADAR: begin
          m_axi_ddr.wdata    = s_axi_radar.wdata;
          m_axi_ddr.wstrb    = s_axi_radar.wstrb;
          m_axi_ddr.wlast    = s_axi_radar.wlast;
          m_axi_ddr.wvalid   = s_axi_radar.wvalid;
          m_axi_ddr.bready   = s_axi_radar.bready;
          s_axi_radar.wready = m_axi_ddr.wready;
          s_axi_radar.bresp  = m_axi_ddr.bresp;
          s_axi_radar.bvalid = m_axi_ddr.bvalid;

          if (m_axi_ddr.bvalid && s_axi_radar.bready) begin
            wr_active_n = 1'b0;
            wr_owner_n  = AXI_DDR_MASTER_NONE;
          end
        end

        AXI_DDR_MASTER_HOST: begin
          m_axi_ddr.wdata   = s_axi_host.wdata;
          m_axi_ddr.wstrb   = s_axi_host.wstrb;
          m_axi_ddr.wlast   = s_axi_host.wlast;
          m_axi_ddr.wvalid  = s_axi_host.wvalid;
          m_axi_ddr.bready  = s_axi_host.bready;
          s_axi_host.wready = m_axi_ddr.wready;
          s_axi_host.bresp  = m_axi_ddr.bresp;
          s_axi_host.bvalid = m_axi_ddr.bvalid;

          if (m_axi_ddr.bvalid && s_axi_host.bready) begin
            wr_active_n = 1'b0;
            wr_owner_n  = AXI_DDR_MASTER_NONE;
          end
        end

        default: begin
          wr_active_n = 1'b0;
          wr_owner_n  = AXI_DDR_MASTER_NONE;
        end
      endcase
    end else begin
      case (wr_pick_c)
        AXI_DDR_MASTER_RADAR: begin
          m_axi_ddr.awaddr     = s_axi_radar.awaddr;
          m_axi_ddr.awlen      = s_axi_radar.awlen;
          m_axi_ddr.awsize     = s_axi_radar.awsize;
          m_axi_ddr.awburst    = s_axi_radar.awburst;
          m_axi_ddr.awvalid    = s_axi_radar.awvalid;
          s_axi_radar.awready  = m_axi_ddr.awready;

          if (s_axi_radar.awvalid && m_axi_ddr.awready) begin
            wr_active_n     = 1'b1;
            wr_owner_n      = AXI_DDR_MASTER_RADAR;
            wr_last_grant_n = AXI_DDR_MASTER_RADAR;
          end
        end

        AXI_DDR_MASTER_HOST: begin
          m_axi_ddr.awaddr    = s_axi_host.awaddr;
          m_axi_ddr.awlen     = s_axi_host.awlen;
          m_axi_ddr.awsize    = s_axi_host.awsize;
          m_axi_ddr.awburst   = s_axi_host.awburst;
          m_axi_ddr.awvalid   = s_axi_host.awvalid;
          s_axi_host.awready  = m_axi_ddr.awready;

          if (s_axi_host.awvalid && m_axi_ddr.awready) begin
            wr_active_n     = 1'b1;
            wr_owner_n      = AXI_DDR_MASTER_HOST;
            wr_last_grant_n = AXI_DDR_MASTER_HOST;
          end
        end

        default: begin
          wr_owner_n  = AXI_DDR_MASTER_NONE;
          wr_active_n = 1'b0;
        end
      endcase
    end

    if (rd_active_r) begin
      case (rd_owner_r)
        AXI_DDR_MASTER_RADAR: begin
          m_axi_ddr.rready    = s_axi_radar.rready;
          s_axi_radar.rdata   = m_axi_ddr.rdata;
          s_axi_radar.rresp   = m_axi_ddr.rresp;
          s_axi_radar.rlast   = m_axi_ddr.rlast;
          s_axi_radar.rvalid  = m_axi_ddr.rvalid;

          if (m_axi_ddr.rvalid && s_axi_radar.rready && m_axi_ddr.rlast) begin
            rd_active_n = 1'b0;
            rd_owner_n  = AXI_DDR_MASTER_NONE;
          end
        end

        AXI_DDR_MASTER_HOST: begin
          m_axi_ddr.rready   = s_axi_host.rready;
          s_axi_host.rdata   = m_axi_ddr.rdata;
          s_axi_host.rresp   = m_axi_ddr.rresp;
          s_axi_host.rlast   = m_axi_ddr.rlast;
          s_axi_host.rvalid  = m_axi_ddr.rvalid;

          if (m_axi_ddr.rvalid && s_axi_host.rready && m_axi_ddr.rlast) begin
            rd_active_n = 1'b0;
            rd_owner_n  = AXI_DDR_MASTER_NONE;
          end
        end

        default: begin
          rd_active_n = 1'b0;
          rd_owner_n  = AXI_DDR_MASTER_NONE;
        end
      endcase
    end else begin
      case (rd_pick_c)
        AXI_DDR_MASTER_RADAR: begin
          m_axi_ddr.araddr     = s_axi_radar.araddr;
          m_axi_ddr.arlen      = s_axi_radar.arlen;
          m_axi_ddr.arsize     = s_axi_radar.arsize;
          m_axi_ddr.arburst    = s_axi_radar.arburst;
          m_axi_ddr.arvalid    = s_axi_radar.arvalid;
          s_axi_radar.arready  = m_axi_ddr.arready;

          if (s_axi_radar.arvalid && m_axi_ddr.arready) begin
            rd_active_n     = 1'b1;
            rd_owner_n      = AXI_DDR_MASTER_RADAR;
            rd_last_grant_n = AXI_DDR_MASTER_RADAR;
          end
        end

        AXI_DDR_MASTER_HOST: begin
          m_axi_ddr.araddr    = s_axi_host.araddr;
          m_axi_ddr.arlen     = s_axi_host.arlen;
          m_axi_ddr.arsize    = s_axi_host.arsize;
          m_axi_ddr.arburst   = s_axi_host.arburst;
          m_axi_ddr.arvalid   = s_axi_host.arvalid;
          s_axi_host.arready  = m_axi_ddr.arready;

          if (s_axi_host.arvalid && m_axi_ddr.arready) begin
            rd_active_n     = 1'b1;
            rd_owner_n      = AXI_DDR_MASTER_HOST;
            rd_last_grant_n = AXI_DDR_MASTER_HOST;
          end
        end

        default: begin
          rd_owner_n  = AXI_DDR_MASTER_NONE;
          rd_active_n = 1'b0;
        end
      endcase
    end
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      wr_active_r     <= 1'b0;
      wr_owner_r      <= AXI_DDR_MASTER_NONE;
      wr_last_grant_r <= AXI_DDR_MASTER_HOST;
      rd_active_r     <= 1'b0;
      rd_owner_r      <= AXI_DDR_MASTER_NONE;
      rd_last_grant_r <= AXI_DDR_MASTER_HOST;
    end else begin
      wr_active_r     <= wr_active_n;
      wr_owner_r      <= wr_owner_n;
      wr_last_grant_r <= wr_last_grant_n;
      rd_active_r     <= rd_active_n;
      rd_owner_r      <= rd_owner_n;
      rd_last_grant_r <= rd_last_grant_n;
    end
  end

  assign wr_owner_o       = wr_active_r ? wr_owner_r : wr_pick_c;
  assign wr_owner_valid_o = wr_active_r || (wr_pick_c != AXI_DDR_MASTER_NONE);
  assign rd_owner_o       = rd_active_r ? rd_owner_r : rd_pick_c;
  assign rd_owner_valid_o = rd_active_r || (rd_pick_c != AXI_DDR_MASTER_NONE);

  `DDR_RING_STATIC_ASSERT(AXI_ADDR_W > 0, "AXI_ADDR_W must be greater than zero")
  `DDR_RING_STATIC_ASSERT((AXI_DATA_W > 0) && ((AXI_DATA_W % 8) == 0),
                          "AXI_DATA_W must be byte aligned")

endmodule
