// Minimal AXI-Lite slave stub: always accepts and responds with OK, rdata=0.
// Used as ringbuffer placeholder in BAR0 decode tests.
module axil_slave_stub #(
    parameter int unsigned ADDR_W = 8,
    parameter int unsigned DATA_W = 32
) (
    input  logic                  clk,
    input  logic                  rst_n,
    axi4_lite_if.slave            s_axil
);

  logic pending_b, pending_r;

  assign s_axil.awready = !pending_b && !pending_r;
  assign s_axil.wready  = !pending_b && !pending_r;
  assign s_axil.bvalid  = pending_b;
  assign s_axil.bresp   = 2'b00;
  assign s_axil.arready = !pending_b && !pending_r;
  assign s_axil.rvalid  = pending_r;
  assign s_axil.rdata   = '0;
  assign s_axil.rresp   = 2'b00;

  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      pending_b <= 1'b0;
      pending_r <= 1'b0;
    end else begin
      if (s_axil.awvalid && s_axil.awready && s_axil.wvalid && s_axil.wready)
        pending_b <= 1'b1;
      else if (s_axil.bvalid && s_axil.bready)
        pending_b <= 1'b0;
      if (s_axil.arvalid && s_axil.arready)
        pending_r <= 1'b1;
      else if (s_axil.rvalid && s_axil.rready)
        pending_r <= 1'b0;
    end
  end

endmodule
