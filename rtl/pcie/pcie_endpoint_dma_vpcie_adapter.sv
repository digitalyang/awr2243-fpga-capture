// Integration boundary for alexforencich/verilog-pcie. The open-source core is
// not vendored in this repo yet, so the smoke configuration uses DIRECT_RC_MODEL
// to pass a transaction-level host RC model straight into the endpoint shell.
module pcie_endpoint_dma_vpcie_adapter #(
    parameter bit DIRECT_RC_MODEL = 1'b1
) (
    input logic clk_i,
    input logic rst_ni,
    pcie_rc_model_if.device host_rc,
    pcie_rc_model_if.host shell_rc
);

  if (DIRECT_RC_MODEL) begin : gen_direct_rc_model
    assign shell_rc.req_valid = host_rc.req_valid;
    assign shell_rc.req_write = host_rc.req_write;
    assign shell_rc.req_bar   = host_rc.req_bar;
    assign shell_rc.req_addr  = host_rc.req_addr;
    assign shell_rc.req_data  = host_rc.req_data;
    assign shell_rc.req_strb  = host_rc.req_strb;
    assign shell_rc.req_tag   = host_rc.req_tag;
    assign host_rc.req_ready  = shell_rc.req_ready;

    assign host_rc.rsp_valid  = shell_rc.rsp_valid;
    assign host_rc.rsp_data   = shell_rc.rsp_data;
    assign host_rc.rsp_status = shell_rc.rsp_status;
    assign host_rc.rsp_tag    = shell_rc.rsp_tag;
    assign shell_rc.rsp_ready = host_rc.rsp_ready;
  end else begin : gen_vpcie_placeholder
    assign shell_rc.req_valid = 1'b0;
    assign shell_rc.req_write = 1'b0;
    assign shell_rc.req_bar   = '0;
    assign shell_rc.req_addr  = '0;
    assign shell_rc.req_data  = '0;
    assign shell_rc.req_strb  = '0;
    assign shell_rc.req_tag   = '0;
    assign shell_rc.rsp_ready = 1'b0;

    assign host_rc.req_ready  = 1'b0;
    assign host_rc.rsp_valid  = 1'b0;
    assign host_rc.rsp_data   = '0;
    assign host_rc.rsp_status = pcie_dma_pkg::PCIE_MMIO_STATUS_UR;
    assign host_rc.rsp_tag    = '0;

    // Keep CDC tools aware that the boundary lives in the PCIe clock domain.
    logic unused_clk;
    logic unused_rst_n;
    assign unused_clk   = clk_i;
    assign unused_rst_n = rst_ni;
  end

endmodule
