// BAR0 AXI-Lite address decoder: one slave, two masters.
// addr < AWR_BASE -> m_axil_ring; addr >= AWR_BASE -> m_axil_awr (addr - AWR_BASE).
// One transaction in flight at a time (one write or one read).
`include "ddr_ringbuffer_macros.svh"

module axil_bar0_decode #(
    parameter int unsigned ADDR_W     = 16,
    parameter int unsigned DATA_W     = 32,
    parameter logic [ADDR_W-1:0] AWR_BASE = 16'h0090
) (
    input  logic          clk,
    input  logic          rst_n,
    axi4_lite_if.slave   s_axil,
    axi4_lite_if.master  m_axil_ring,
    axi4_lite_if.master  m_axil_awr
);

  logic sel_awr_r;
  logic waiting_for_b_r;
  logic waiting_for_r_r;

  wire in_flight = waiting_for_b_r | waiting_for_r_r;
  wire sel_awr_eff = in_flight ? sel_awr_r : (s_axil.arvalid ? (s_axil.araddr >= AWR_BASE) : (s_axil.awaddr >= AWR_BASE));
  wire sel_ring_eff = ~sel_awr_eff;

  wire [ADDR_W-1:0] awr_awaddr_local = s_axil.awaddr - AWR_BASE;
  wire [ADDR_W-1:0] awr_araddr_local = s_axil.araddr - AWR_BASE;

  // ---- Write channel (AW/W/B) ----
  wire aw_fire = s_axil.awvalid & s_axil.awready;
  wire w_fire  = s_axil.wvalid & s_axil.wready;
  wire b_fire  = s_axil.bvalid & s_axil.bready;

  assign s_axil.awready = ~waiting_for_b_r & (sel_ring_eff ? m_axil_ring.awready : m_axil_awr.awready);
  assign s_axil.wready  = ~waiting_for_b_r & (sel_ring_eff ? m_axil_ring.wready : m_axil_awr.wready);

  assign m_axil_ring.awvalid = sel_ring_eff & s_axil.awvalid & ~waiting_for_b_r;
  assign m_axil_ring.awaddr  = s_axil.awaddr[7:0];
  assign m_axil_ring.awprot  = s_axil.awprot;
  assign m_axil_ring.wvalid  = sel_ring_eff & s_axil.wvalid & ~waiting_for_b_r;
  assign m_axil_ring.wdata   = s_axil.wdata;
  assign m_axil_ring.wstrb   = s_axil.wstrb;
  assign m_axil_ring.bready  = sel_ring_eff & s_axil.bready;

  assign m_axil_awr.awvalid = sel_awr_eff & s_axil.awvalid & ~waiting_for_b_r;
  assign m_axil_awr.awaddr  = awr_awaddr_local[7:0];
  assign m_axil_awr.awprot  = s_axil.awprot;
  assign m_axil_awr.wvalid  = sel_awr_eff & s_axil.wvalid & ~waiting_for_b_r;
  assign m_axil_awr.wdata   = s_axil.wdata;
  assign m_axil_awr.wstrb   = s_axil.wstrb;
  assign m_axil_awr.bready  = sel_awr_eff & s_axil.bready;

  assign s_axil.bvalid = sel_ring_eff ? m_axil_ring.bvalid : m_axil_awr.bvalid;
  assign s_axil.bresp  = sel_ring_eff ? m_axil_ring.bresp : m_axil_awr.bresp;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      waiting_for_b_r <= 1'b0;
      waiting_for_r_r <= 1'b0;
      sel_awr_r       <= 1'b0;
    end else begin
      if (aw_fire && w_fire) begin
        waiting_for_b_r <= 1'b1;
        sel_awr_r       <= (s_axil.awaddr >= AWR_BASE);
      end else if (b_fire)
        waiting_for_b_r <= 1'b0;

      if (ar_fire) begin
        waiting_for_r_r <= 1'b1;
        sel_awr_r       <= (s_axil.araddr >= AWR_BASE);
      end else if (r_fire)
        waiting_for_r_r <= 1'b0;
    end
  end

  // ---- Read channel (AR/R) ----
  wire ar_fire = s_axil.arvalid & s_axil.arready;
  wire r_fire  = s_axil.rvalid & s_axil.rready;

  assign s_axil.arready = ~waiting_for_r_r & (sel_ring_eff ? m_axil_ring.arready : m_axil_awr.arready);

  assign m_axil_ring.arvalid = sel_ring_eff & s_axil.arvalid & ~waiting_for_r_r;
  assign m_axil_ring.araddr  = s_axil.araddr[7:0];
  assign m_axil_ring.arprot  = s_axil.arprot;
  assign m_axil_ring.rready  = sel_ring_eff & s_axil.rready;

  assign m_axil_awr.arvalid = sel_awr_eff & s_axil.arvalid & ~waiting_for_r_r;
  assign m_axil_awr.araddr  = awr_araddr_local[7:0];
  assign m_axil_awr.arprot  = s_axil.arprot;
  assign m_axil_awr.rready  = sel_awr_eff & s_axil.rready;

  assign s_axil.rvalid = sel_ring_eff ? m_axil_ring.rvalid : m_axil_awr.rvalid;
  assign s_axil.rdata  = sel_ring_eff ? m_axil_ring.rdata : m_axil_awr.rdata;
  assign s_axil.rresp  = sel_ring_eff ? m_axil_ring.rresp : m_axil_awr.rresp;

endmodule
