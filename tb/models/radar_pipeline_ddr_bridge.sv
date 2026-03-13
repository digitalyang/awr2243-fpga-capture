`include "ddr_ringbuffer_macros.svh"

// Simulation bridge that presents the radar ringbuffer AXI master as a
// pluggable subsystem boundary while preserving the current flat DDR-facing
// bus used by the cocotb memory model.
module radar_pipeline_ddr_bridge #(
    parameter int unsigned AXI_ADDR_W = `DDR_RING_AXI_ADDR_W_DFLT,
    parameter int unsigned AXI_DATA_W = `DDR_RING_AXI_DATA_W_DFLT,
    parameter int unsigned COUNTER_W  = `DDR_RING_COUNTER_W_DFLT
) (
    input  logic                  clk_i,
    input  logic                  rst_ni,

    input  logic [AXI_ADDR_W-1:0] s_axi_awaddr,
    input  logic [           7:0] s_axi_awlen,
    input  logic [           2:0] s_axi_awsize,
    input  logic [           1:0] s_axi_awburst,
    input  logic                  s_axi_awvalid,
    output logic                  s_axi_awready,
    input  logic [AXI_DATA_W-1:0] s_axi_wdata,
    input  logic [(AXI_DATA_W/8)-1:0] s_axi_wstrb,
    input  logic                  s_axi_wlast,
    input  logic                  s_axi_wvalid,
    output logic                  s_axi_wready,
    output logic [           1:0] s_axi_bresp,
    output logic                  s_axi_bvalid,
    input  logic                  s_axi_bready,
    input  logic [AXI_ADDR_W-1:0] s_axi_araddr,
    input  logic [           7:0] s_axi_arlen,
    input  logic [           2:0] s_axi_arsize,
    input  logic [           1:0] s_axi_arburst,
    input  logic                  s_axi_arvalid,
    output logic                  s_axi_arready,
    output logic [AXI_DATA_W-1:0] s_axi_rdata,
    output logic [           1:0] s_axi_rresp,
    output logic                  s_axi_rlast,
    output logic                  s_axi_rvalid,
    input  logic                  s_axi_rready,

    output logic [AXI_ADDR_W-1:0] m_axi_awaddr,
    output logic [           7:0] m_axi_awlen,
    output logic [           2:0] m_axi_awsize,
    output logic [           1:0] m_axi_awburst,
    output logic                  m_axi_awvalid,
    input  logic                  m_axi_awready,
    output logic [AXI_DATA_W-1:0] m_axi_wdata,
    output logic [(AXI_DATA_W/8)-1:0] m_axi_wstrb,
    output logic                  m_axi_wlast,
    output logic                  m_axi_wvalid,
    input  logic                  m_axi_wready,
    input  logic [           1:0] m_axi_bresp,
    input  logic                  m_axi_bvalid,
    output logic                  m_axi_bready,
    output logic [AXI_ADDR_W-1:0] m_axi_araddr,
    output logic [           7:0] m_axi_arlen,
    output logic [           2:0] m_axi_arsize,
    output logic [           1:0] m_axi_arburst,
    output logic                  m_axi_arvalid,
    input  logic                  m_axi_arready,
    input  logic [AXI_DATA_W-1:0] m_axi_rdata,
    input  logic [           1:0] m_axi_rresp,
    input  logic                  m_axi_rlast,
    input  logic                  m_axi_rvalid,
    output logic                  m_axi_rready,

    output logic [ COUNTER_W-1:0] status_aw_count_o,
    output logic [ COUNTER_W-1:0] status_w_beat_count_o,
    output logic [ COUNTER_W-1:0] status_w_byte_count_o,
    output logic [ COUNTER_W-1:0] status_b_count_o,
    output logic [ COUNTER_W-1:0] status_ar_count_o,
    output logic [ COUNTER_W-1:0] status_r_beat_count_o
);

  localparam int unsigned AXI_STRB_W = AXI_DATA_W / 8;

  logic aw_fire_c;
  logic w_fire_c;
  logic b_fire_c;
  logic ar_fire_c;
  logic r_fire_c;

  function automatic logic [COUNTER_W-1:0] count_strb_ones(
      input logic [AXI_STRB_W-1:0] strb
  );
    logic [COUNTER_W-1:0] count_c;
    int unsigned          idx;
    begin
      count_c = '0;
      for (idx = 0; idx < AXI_STRB_W; idx++) begin
        count_c = count_c + COUNTER_W'(strb[idx]);
      end
      return count_c;
    end
  endfunction

  assign m_axi_awaddr  = s_axi_awaddr;
  assign m_axi_awlen   = s_axi_awlen;
  assign m_axi_awsize  = s_axi_awsize;
  assign m_axi_awburst = s_axi_awburst;
  assign m_axi_awvalid = s_axi_awvalid;
  assign s_axi_awready = m_axi_awready;

  assign m_axi_wdata   = s_axi_wdata;
  assign m_axi_wstrb   = s_axi_wstrb;
  assign m_axi_wlast   = s_axi_wlast;
  assign m_axi_wvalid  = s_axi_wvalid;
  assign s_axi_wready  = m_axi_wready;

  assign s_axi_bresp   = m_axi_bresp;
  assign s_axi_bvalid  = m_axi_bvalid;
  assign m_axi_bready  = s_axi_bready;

  assign m_axi_araddr  = s_axi_araddr;
  assign m_axi_arlen   = s_axi_arlen;
  assign m_axi_arsize  = s_axi_arsize;
  assign m_axi_arburst = s_axi_arburst;
  assign m_axi_arvalid = s_axi_arvalid;
  assign s_axi_arready = m_axi_arready;

  assign s_axi_rdata   = m_axi_rdata;
  assign s_axi_rresp   = m_axi_rresp;
  assign s_axi_rlast   = m_axi_rlast;
  assign s_axi_rvalid  = m_axi_rvalid;
  assign m_axi_rready  = s_axi_rready;

  assign aw_fire_c = s_axi_awvalid && s_axi_awready;
  assign w_fire_c  = s_axi_wvalid && s_axi_wready;
  assign b_fire_c  = s_axi_bvalid && s_axi_bready;
  assign ar_fire_c = s_axi_arvalid && s_axi_arready;
  assign r_fire_c  = s_axi_rvalid && s_axi_rready;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      status_aw_count_o     <= '0;
      status_w_beat_count_o <= '0;
      status_w_byte_count_o <= '0;
      status_b_count_o      <= '0;
      status_ar_count_o     <= '0;
      status_r_beat_count_o <= '0;
    end else begin
      if (aw_fire_c) begin
        status_aw_count_o <= status_aw_count_o + COUNTER_W'(1);
      end
      if (w_fire_c) begin
        status_w_beat_count_o <= status_w_beat_count_o + COUNTER_W'(1);
        status_w_byte_count_o <= status_w_byte_count_o + count_strb_ones(s_axi_wstrb);
      end
      if (b_fire_c) begin
        status_b_count_o <= status_b_count_o + COUNTER_W'(1);
      end
      if (ar_fire_c) begin
        status_ar_count_o <= status_ar_count_o + COUNTER_W'(1);
      end
      if (r_fire_c) begin
        status_r_beat_count_o <= status_r_beat_count_o + COUNTER_W'(1);
      end
    end
  end

endmodule
