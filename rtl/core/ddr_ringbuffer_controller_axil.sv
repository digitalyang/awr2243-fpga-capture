`include "ddr_ringbuffer_macros.svh"

// Wraps ddr_ringbuffer_controller with an AXI-Lite CSR block so software can
// configure the ring and observe status through generated registers.
module ddr_ringbuffer_controller_axil #(
    parameter int unsigned CFG_AXI_ADDR_W = `DDR_RING_AXI_ADDR_W_DFLT,
    parameter int unsigned AXIS_DATA_W = `DDR_RING_AXIS_DATA_W_DFLT,
    parameter int unsigned AXIS_USER_W = `DDR_RING_AXIS_USER_W_DFLT,
    parameter int unsigned AXI_DATA_W = `DDR_RING_AXI_DATA_W_DFLT,
    parameter int unsigned RD_AXIS_USER_W = `DDR_RING_AXIS_USER_W_DFLT,
    parameter bit SLOT_FIXED_EN = 1'b0,
    parameter int unsigned SLOT_STRIDE_BYTES = `DDR_RING_SLOT_STRIDE_BYTES_DFLT,
    parameter int unsigned SLOT_BUFFER_BYTES = `DDR_RING_SLOT_BUFFER_BYTES_DFLT,
    parameter int unsigned DESC_FIFO_DEPTH = `DDR_RING_FIFO_DEPTH_DFLT,
    parameter int unsigned MAX_BURST_LEN = `DDR_RING_MAX_BURST_LEN_DFLT,
    parameter int unsigned ADDR_ALIGN_BYTES = `DDR_RING_ALIGN_BYTES_DFLT,
    parameter int unsigned RING_SIZE_BYTES_MAX = `DDR_RING_RING_SIZE_BYTES_DFLT,
    parameter int unsigned ALMOST_FULL_MARGIN_BYTES = `DDR_RING_ALMOST_FULL_MARGIN_DFLT,
    parameter int unsigned SLOT_SEQ_W = `DDR_RING_SLOT_SEQ_W_DFLT,
    parameter int unsigned COUNTER_W = `DDR_RING_COUNTER_W_DFLT,
    parameter int unsigned RD_TUSER_SLOT_FIRST_BIT = 0,
    parameter int unsigned RD_TUSER_SLOT_LAST_BIT = 1,
    parameter int unsigned RD_TUSER_VALID_GOOD_BIT = 2,
    parameter int unsigned RD_TUSER_OVERFLOW_ERR_BIT = 3,
    parameter int unsigned RD_TUSER_SEQ_LSB = 8,
    parameter int unsigned RD_TUSER_BYTES_LSB = 32,
    parameter int unsigned CFG_RING_BYTES_W = ddr_ringbuffer_pkg::clog2_safe(
        RING_SIZE_BYTES_MAX + 1
    ),
    parameter int unsigned SLOT_BYTES_W = ddr_ringbuffer_pkg::clog2_safe(
        ddr_ringbuffer_pkg::max_u(
            RING_SIZE_BYTES_MAX,
            ddr_ringbuffer_pkg::max_u(
                SLOT_BUFFER_BYTES, SLOT_STRIDE_BYTES)) + 1
    )
) (
    input  logic                                        clk_i,
    input  logic                                        rst_ni,
    input  logic                                        slot_start_i,
    input  logic                 [    SLOT_BYTES_W-1:0] slot_bytes_i,
    input  logic                                        slot_done_i,
    input  logic                 [      SLOT_SEQ_W-1:0] slot_seq_i,
    input  logic                                        slot_valid_good_i,
    input  logic                                        slot_overflow_err_i,
    output logic                                        wr_slot_commit_o,
    output logic                 [  CFG_AXI_ADDR_W-1:0] wr_slot_addr_o,
    output logic                 [      SLOT_SEQ_W-1:0] wr_slot_seq_o,
    output logic                 [    SLOT_BYTES_W-1:0] wr_slot_bytes_o,
    output logic                                        wr_slot_valid_good_o,
    output logic                                        wr_slot_overflow_err_o,
    output logic                                        rd_slot_valid_o,
    output logic                 [  CFG_AXI_ADDR_W-1:0] rd_slot_addr_o,
    output logic                 [    SLOT_BYTES_W-1:0] rd_slot_bytes_o,
    output logic                 [      SLOT_SEQ_W-1:0] rd_slot_seq_o,
    output logic                                        rd_slot_valid_good_o,
    output logic                                        rd_slot_overflow_err_o,
    output logic                                        rd_busy_o,
    output logic                                        rd_done_o,
    output logic                                        rd_error_o,
    output logic                 [  CFG_AXI_ADDR_W-1:0] wr_ptr_o,
    output logic                 [  CFG_AXI_ADDR_W-1:0] rd_ptr_o,
    output logic                 [  CFG_AXI_ADDR_W-1:0] commit_ptr_o,
    output logic                 [CFG_RING_BYTES_W-1:0] used_bytes_o,
    output logic                 [CFG_RING_BYTES_W-1:0] free_bytes_o,
    output logic                 [CFG_RING_BYTES_W-1:0] committed_bytes_o,
    output logic                                        full_o,
    output logic                                        almost_full_o,
    output logic                                        empty_o,
    output logic                 [       COUNTER_W-1:0] wrap_count_o,
    output logic                 [       COUNTER_W-1:0] overflow_count_o,
    output logic                 [       COUNTER_W-1:0] drop_count_o,
    output logic                                        err_cfg_align_o,
    output logic                                        err_no_space_o,
    output logic                                        err_slot_proto_o,
    output logic                                        err_slot_too_large_o,
    output logic                                        err_axi_wr_resp_o,
    output logic                                        err_axi_rd_resp_o,
    output logic                                        err_illegal_read_o,
           axis_stream_if.slave                         s_axis_slot,
           axis_stream_if.master                        m_axis_rd,
           axi4_mm_if.master                            m_axi,
           axi4_lite_if.slave                           s_axil
);

  import ddr_ringbuffer_pkg::*;
  import ddr_ringbuffer_controller_csr_pkg::*;

  localparam int unsigned CSR_DATA_W = DDR_RINGBUFFER_CONTROLLER_CSR_DATA_WIDTH;
  localparam int unsigned CSR_ADDR_W = DDR_RINGBUFFER_CONTROLLER_CSR_MIN_ADDR_WIDTH;

  ddr_ringbuffer_controller_csr__in_t  csr_hwif_in;
  ddr_ringbuffer_controller_csr__out_t csr_hwif_out;

  logic                                [  CFG_AXI_ADDR_W-1:0] cfg_ring_base_addr_c;
  logic                                [CFG_RING_BYTES_W-1:0] cfg_ring_size_bytes_c;
  logic                                                       cfg_enable_c;
  logic                                                       cfg_allow_overwrite_c;
  logic                                                       cfg_drop_invalid_slot_c;
  logic                                                       cfg_drop_on_no_space_c;
  logic                                                       rd_slot_req_c;
  logic                                                       rd_consume_c;

  logic                                                       last_commit_valid_r;
  logic                                [  CFG_AXI_ADDR_W-1:0] last_commit_addr_r;
  logic                                [    SLOT_BYTES_W-1:0] last_commit_bytes_r;
  logic                                [      SLOT_SEQ_W-1:0] last_commit_seq_r;
  logic                                                       last_commit_valid_good_r;
  logic                                                       last_commit_overflow_err_r;

  logic                                [                63:0] wr_ptr_u64_c;
  logic                                [                63:0] rd_ptr_u64_c;
  logic                                [                63:0] commit_ptr_u64_c;
  logic                                [                63:0] last_commit_addr_u64_c;
  logic                                [                63:0] head_desc_addr_u64_c;

  function automatic logic [63:0] addr_to_u64(input logic [CFG_AXI_ADDR_W-1:0] addr);
    logic [63:0] tmp;
    begin
      tmp                     = '0;
      tmp[CFG_AXI_ADDR_W-1:0] = addr;
      return tmp;
    end
  endfunction

  `DDR_RING_STATIC_ASSERT(CFG_AXI_ADDR_W <= 64, "CSR RDL only exposes up to 64-bit addresses")
  `DDR_RING_STATIC_ASSERT(CFG_RING_BYTES_W <= 32,
                          "CSR RDL exposes ring size and occupancy counters as 32-bit values")
  `DDR_RING_STATIC_ASSERT(SLOT_BYTES_W <= 24, "CSR RDL exposes slot byte counts as 24-bit values")
  `DDR_RING_STATIC_ASSERT(SLOT_SEQ_W <= 32, "CSR RDL exposes slot sequence values as 32-bit values")
  `DDR_RING_STATIC_ASSERT(COUNTER_W <= 32,
                          "CSR RDL exposes wrap/overflow/drop counters as 32-bit values")
  `DDR_RING_STATIC_ASSERT($bits(s_axil.wdata) == CSR_DATA_W,
                          "AXI-Lite data width must match generated CSR block")
  `DDR_RING_STATIC_ASSERT($bits(s_axil.awaddr) >= CSR_ADDR_W,
                          "AXI-Lite address width must cover the generated CSR space")

  assign cfg_enable_c            = csr_hwif_out.CTRL.enable.value;
  assign cfg_allow_overwrite_c   = csr_hwif_out.CTRL.allow_overwrite.value;
  assign cfg_drop_invalid_slot_c = csr_hwif_out.CTRL.drop_invalid_slot.value;
  assign cfg_drop_on_no_space_c  = csr_hwif_out.CTRL.drop_on_no_space.value;

  assign cfg_ring_base_addr_c = CFG_AXI_ADDR_W'({
    csr_hwif_out.RING_BASE_HI.ring_base_hi.value,
    csr_hwif_out.RING_BASE_LO.ring_base_lo.value
  });

  assign cfg_ring_size_bytes_c =
      csr_hwif_out.RING_SIZE_BYTES.ring_size_bytes.value[CFG_RING_BYTES_W-1:0];

  assign rd_slot_req_c = csr_hwif_out.READ_CMD.issue_head_read.value;
  assign rd_consume_c  = csr_hwif_out.READ_CMD.consume_head.value;

  assign wr_ptr_u64_c          = addr_to_u64(wr_ptr_o);
  assign rd_ptr_u64_c          = addr_to_u64(rd_ptr_o);
  assign commit_ptr_u64_c      = addr_to_u64(commit_ptr_o);
  assign last_commit_addr_u64_c = addr_to_u64(last_commit_addr_r);
  assign head_desc_addr_u64_c   = addr_to_u64(rd_slot_addr_o);

  // Capture the most recent committed slot so software can inspect the latest
  // write result without walking the descriptor FIFO.
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      last_commit_valid_r        <= 1'b0;
      last_commit_addr_r         <= '0;
      last_commit_bytes_r        <= '0;
      last_commit_seq_r          <= '0;
      last_commit_valid_good_r   <= 1'b0;
      last_commit_overflow_err_r <= 1'b0;
    end else if (wr_slot_commit_o) begin
      last_commit_valid_r        <= 1'b1;
      last_commit_addr_r         <= wr_slot_addr_o;
      last_commit_bytes_r        <= wr_slot_bytes_o;
      last_commit_seq_r          <= wr_slot_seq_o;
      last_commit_valid_good_r   <= wr_slot_valid_good_o;
      last_commit_overflow_err_r <= wr_slot_overflow_err_o;
    end
  end

  // Mirror internal state into the autogenerated CSR regblock and feed writable
  // fields back through .next so register values persist after software writes.
  always_comb begin
    csr_hwif_in = '{default:'0};

    // Loop SW-visible RW fields back into the regblock so software writes persist.
    csr_hwif_in.CTRL.enable.next                = csr_hwif_out.CTRL.enable.value;
    csr_hwif_in.CTRL.allow_overwrite.next       = csr_hwif_out.CTRL.allow_overwrite.value;
    csr_hwif_in.CTRL.drop_invalid_slot.next     = csr_hwif_out.CTRL.drop_invalid_slot.value;
    csr_hwif_in.CTRL.drop_on_no_space.next      = csr_hwif_out.CTRL.drop_on_no_space.value;

    csr_hwif_in.RING_BASE_LO.ring_base_lo.next  = csr_hwif_out.RING_BASE_LO.ring_base_lo.value;
    csr_hwif_in.RING_BASE_HI.ring_base_hi.next  = csr_hwif_out.RING_BASE_HI.ring_base_hi.value;
    csr_hwif_in.RING_SIZE_BYTES.ring_size_bytes.next =
        csr_hwif_out.RING_SIZE_BYTES.ring_size_bytes.value;

    csr_hwif_in.STATUS.full.next                = full_o;
    csr_hwif_in.STATUS.almost_full.next         = almost_full_o;
    csr_hwif_in.STATUS.empty.next               = empty_o;
    csr_hwif_in.STATUS.rd_busy.next             = rd_busy_o;
    csr_hwif_in.STATUS.err_cfg_align.next       = err_cfg_align_o;
    csr_hwif_in.STATUS.err_no_space.next        = err_no_space_o;
    csr_hwif_in.STATUS.err_slot_proto.next      = err_slot_proto_o;
    csr_hwif_in.STATUS.err_slot_too_large.next  = err_slot_too_large_o;
    csr_hwif_in.STATUS.err_axi_wr_resp.next     = err_axi_wr_resp_o;
    csr_hwif_in.STATUS.err_axi_rd_resp.next     = err_axi_rd_resp_o;
    csr_hwif_in.STATUS.err_illegal_read.next    = err_illegal_read_o;

    csr_hwif_in.USED_BYTES.used_bytes.next         = 32'(used_bytes_o);
    csr_hwif_in.FREE_BYTES.free_bytes.next         = 32'(free_bytes_o);
    csr_hwif_in.COMMITTED_BYTES.committed_bytes.next = 32'(committed_bytes_o);

    csr_hwif_in.WR_PTR_LO.wr_ptr_lo.next        = wr_ptr_u64_c[31:0];
    csr_hwif_in.WR_PTR_HI.wr_ptr_hi.next        = wr_ptr_u64_c[63:32];
    csr_hwif_in.RD_PTR_LO.rd_ptr_lo.next        = rd_ptr_u64_c[31:0];
    csr_hwif_in.RD_PTR_HI.rd_ptr_hi.next        = rd_ptr_u64_c[63:32];
    csr_hwif_in.COMMIT_PTR_LO.commit_ptr_lo.next = commit_ptr_u64_c[31:0];
    csr_hwif_in.COMMIT_PTR_HI.commit_ptr_hi.next = commit_ptr_u64_c[63:32];

    csr_hwif_in.WRAP_COUNT.wrap_count.next         = wrap_count_o;
    csr_hwif_in.OVERFLOW_COUNT.overflow_count.next = overflow_count_o;
    csr_hwif_in.DROP_COUNT.drop_count.next         = drop_count_o;

    csr_hwif_in.LAST_COMMIT_ADDR_LO.slot_addr_lo.next = last_commit_addr_u64_c[31:0];
    csr_hwif_in.LAST_COMMIT_ADDR_HI.slot_addr_hi.next = last_commit_addr_u64_c[63:32];
    csr_hwif_in.LAST_COMMIT_INFO.slot_bytes.next      = 24'(last_commit_bytes_r);
    csr_hwif_in.LAST_COMMIT_INFO.valid_good.next      = last_commit_valid_good_r;
    csr_hwif_in.LAST_COMMIT_INFO.overflow_err.next    = last_commit_overflow_err_r;
    csr_hwif_in.LAST_COMMIT_INFO.commit_valid.next    = last_commit_valid_r;
    csr_hwif_in.LAST_COMMIT_SEQ.slot_seq.next         = 32'(last_commit_seq_r);

    csr_hwif_in.HEAD_DESC_ADDR_LO.slot_addr_lo.next = head_desc_addr_u64_c[31:0];
    csr_hwif_in.HEAD_DESC_ADDR_HI.slot_addr_hi.next = head_desc_addr_u64_c[63:32];
    csr_hwif_in.HEAD_DESC_INFO.slot_bytes.next      = 24'(rd_slot_bytes_o);
    csr_hwif_in.HEAD_DESC_INFO.valid_good.next      = rd_slot_valid_good_o;
    csr_hwif_in.HEAD_DESC_INFO.overflow_err.next    = rd_slot_overflow_err_o;
    csr_hwif_in.HEAD_DESC_INFO.desc_valid.next      = rd_slot_valid_o;
    csr_hwif_in.HEAD_DESC_SEQ.slot_seq.next         = 32'(rd_slot_seq_o);
  end

  ddr_ringbuffer_controller_csr u_csr (
      .clk            (clk_i),
      .arst_n         (rst_ni),
      .s_axil_awready (s_axil.awready),
      .s_axil_awvalid (s_axil.awvalid),
      .s_axil_awaddr  (s_axil.awaddr[CSR_ADDR_W-1:0]),
      .s_axil_awprot  (s_axil.awprot),
      .s_axil_wready  (s_axil.wready),
      .s_axil_wvalid  (s_axil.wvalid),
      .s_axil_wdata   (s_axil.wdata),
      .s_axil_wstrb   (s_axil.wstrb),
      .s_axil_bready  (s_axil.bready),
      .s_axil_bvalid  (s_axil.bvalid),
      .s_axil_bresp   (s_axil.bresp),
      .s_axil_arready (s_axil.arready),
      .s_axil_arvalid (s_axil.arvalid),
      .s_axil_araddr  (s_axil.araddr[CSR_ADDR_W-1:0]),
      .s_axil_arprot  (s_axil.arprot),
      .s_axil_rready  (s_axil.rready),
      .s_axil_rvalid  (s_axil.rvalid),
      .s_axil_rdata   (s_axil.rdata),
      .s_axil_rresp   (s_axil.rresp),
      .hwif_in        (csr_hwif_in),
      .hwif_out       (csr_hwif_out)
  );

  ddr_ringbuffer_controller #(
      .CFG_AXI_ADDR_W            (CFG_AXI_ADDR_W),
      .AXIS_DATA_W               (AXIS_DATA_W),
      .AXIS_USER_W               (AXIS_USER_W),
      .AXI_DATA_W                (AXI_DATA_W),
      .RD_AXIS_USER_W            (RD_AXIS_USER_W),
      .SLOT_FIXED_EN             (SLOT_FIXED_EN),
      .SLOT_STRIDE_BYTES         (SLOT_STRIDE_BYTES),
      .SLOT_BUFFER_BYTES         (SLOT_BUFFER_BYTES),
      .DESC_FIFO_DEPTH           (DESC_FIFO_DEPTH),
      .MAX_BURST_LEN             (MAX_BURST_LEN),
      .ADDR_ALIGN_BYTES          (ADDR_ALIGN_BYTES),
      .RING_SIZE_BYTES_MAX       (RING_SIZE_BYTES_MAX),
      .ALMOST_FULL_MARGIN_BYTES  (ALMOST_FULL_MARGIN_BYTES),
      .SLOT_SEQ_W                (SLOT_SEQ_W),
      .COUNTER_W                 (COUNTER_W),
      .RD_TUSER_SLOT_FIRST_BIT   (RD_TUSER_SLOT_FIRST_BIT),
      .RD_TUSER_SLOT_LAST_BIT    (RD_TUSER_SLOT_LAST_BIT),
      .RD_TUSER_VALID_GOOD_BIT   (RD_TUSER_VALID_GOOD_BIT),
      .RD_TUSER_OVERFLOW_ERR_BIT (RD_TUSER_OVERFLOW_ERR_BIT),
      .RD_TUSER_SEQ_LSB          (RD_TUSER_SEQ_LSB),
      .RD_TUSER_BYTES_LSB        (RD_TUSER_BYTES_LSB),
      .CFG_RING_BYTES_W          (CFG_RING_BYTES_W),
      .SLOT_BYTES_W              (SLOT_BYTES_W)
  ) u_ddr_ringbuffer_controller (
      .clk_i                   (clk_i),
      .rst_ni                  (rst_ni),
      .cfg_enable_i            (cfg_enable_c),
      .cfg_allow_overwrite_i   (cfg_allow_overwrite_c),
      .cfg_drop_invalid_slot_i (cfg_drop_invalid_slot_c),
      .cfg_drop_on_no_space_i  (cfg_drop_on_no_space_c),
      .cfg_ring_base_addr_i    (cfg_ring_base_addr_c),
      .cfg_ring_size_bytes_i   (cfg_ring_size_bytes_c),
      .slot_start_i            (slot_start_i),
      .slot_done_i             (slot_done_i),
      .slot_bytes_i            (slot_bytes_i),
      .slot_seq_i              (slot_seq_i),
      .slot_valid_good_i       (slot_valid_good_i),
      .slot_overflow_err_i     (slot_overflow_err_i),
      .wr_slot_commit_o        (wr_slot_commit_o),
      .wr_slot_addr_o          (wr_slot_addr_o),
      .wr_slot_seq_o           (wr_slot_seq_o),
      .wr_slot_bytes_o         (wr_slot_bytes_o),
      .wr_slot_valid_good_o    (wr_slot_valid_good_o),
      .wr_slot_overflow_err_o  (wr_slot_overflow_err_o),
      .rd_slot_req_i           (rd_slot_req_c),
      .rd_consume_i            (rd_consume_c),
      .rd_slot_valid_o         (rd_slot_valid_o),
      .rd_slot_addr_o          (rd_slot_addr_o),
      .rd_slot_bytes_o         (rd_slot_bytes_o),
      .rd_slot_seq_o           (rd_slot_seq_o),
      .rd_slot_valid_good_o    (rd_slot_valid_good_o),
      .rd_slot_overflow_err_o  (rd_slot_overflow_err_o),
      .rd_busy_o               (rd_busy_o),
      .rd_done_o               (rd_done_o),
      .rd_error_o              (rd_error_o),
      .wr_ptr_o                (wr_ptr_o),
      .rd_ptr_o                (rd_ptr_o),
      .commit_ptr_o            (commit_ptr_o),
      .used_bytes_o            (used_bytes_o),
      .free_bytes_o            (free_bytes_o),
      .committed_bytes_o       (committed_bytes_o),
      .full_o                  (full_o),
      .almost_full_o           (almost_full_o),
      .empty_o                 (empty_o),
      .wrap_count_o            (wrap_count_o),
      .overflow_count_o        (overflow_count_o),
      .drop_count_o            (drop_count_o),
      .err_cfg_align_o         (err_cfg_align_o),
      .err_no_space_o          (err_no_space_o),
      .err_slot_proto_o        (err_slot_proto_o),
      .err_slot_too_large_o    (err_slot_too_large_o),
      .err_axi_wr_resp_o       (err_axi_wr_resp_o),
      .err_axi_rd_resp_o       (err_axi_rd_resp_o),
      .err_illegal_read_o      (err_illegal_read_o),
      .s_axis_slot             (s_axis_slot),
      .m_axis_rd               (m_axis_rd),
      .m_axi                   (m_axi)
  );

endmodule