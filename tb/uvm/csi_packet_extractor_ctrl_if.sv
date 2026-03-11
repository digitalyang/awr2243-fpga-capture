// UVM control/status interface for driving extractor configuration and sampling
// packet-level outputs from monitors and scoreboards.
interface csi_packet_extractor_ctrl_if #(
    parameter int unsigned VC_W           = 2,
    parameter int unsigned DT_W           = 6,
    parameter int unsigned PKT_SEQ_W      = 16,
    parameter int unsigned PKT_BYTE_CNT_W = 16
) (
    input logic clk
);

  logic                      rst_ni;
  logic                      cfg_vc_en;
  logic                      cfg_dt_en;
  logic [          VC_W-1:0] cfg_vc;
  logic [          DT_W-1:0] cfg_dt;

  logic                      pkt_start;
  logic                      pkt_done;
  logic                      pkt_valid_good;
  logic [     PKT_SEQ_W-1:0] pkt_seq;
  logic [PKT_BYTE_CNT_W-1:0] pkt_bytes;
  logic                      pkt_crc_err;
  logic                      pkt_ecc_err;
  logic                      pkt_trunc_err;

  clocking drv_cb @(posedge clk);
    output cfg_vc_en;
    output cfg_dt_en;
    output cfg_vc;
    output cfg_dt;
  endclocking

  clocking mon_cb @(posedge clk);
    input rst_ni;
    input cfg_vc_en;
    input cfg_dt_en;
    input cfg_vc;
    input cfg_dt;
    input pkt_start;
    input pkt_done;
    input pkt_valid_good;
    input pkt_seq;
    input pkt_bytes;
    input pkt_crc_err;
    input pkt_ecc_err;
    input pkt_trunc_err;
  endclocking

endinterface
