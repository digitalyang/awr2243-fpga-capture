`include "ddr_ringbuffer_macros.svh"
`timescale 1ns/1ps

module ddr_ringbuffer_controller_tb_top;

    import uvm_pkg::*;
    import ddr_ringbuffer_pkg::*;
    import ddr_ringbuffer_controller_uvm_pkg::*;

    localparam int unsigned AXIS_DATA_W   = TB_AXIS_DATA_W;
    localparam int unsigned AXIS_USER_W   = TB_AXIS_USER_W;
    localparam int unsigned AXI_DATA_W    = TB_AXI_DATA_W;
    localparam int unsigned AXI_ADDR_W    = TB_AXI_ADDR_W;
    localparam int unsigned RD_AXIS_USER_W = TB_RD_AXIS_USER_W;
    localparam int unsigned RING_BYTES_W  = TB_RING_BYTES_W;
    localparam int unsigned SLOT_BYTES_W  = TB_SLOT_BYTES_W;
    localparam int unsigned SLOT_SEQ_W    = TB_SLOT_SEQ_W;
    localparam int unsigned COUNTER_W     = TB_COUNTER_W;

    logic clk;

    axis_stream_if #(
        .DATA_W(AXIS_DATA_W),
        .USER_W(AXIS_USER_W)
    ) s_axis_if ();

    axis_stream_if #(
        .DATA_W(AXI_DATA_W),
        .USER_W(RD_AXIS_USER_W)
    ) m_axis_rd_if ();

    axi4_mm_if #(
        .ADDR_W(AXI_ADDR_W),
        .DATA_W(AXI_DATA_W)
    ) axi_if ();

    ddr_ringbuffer_ctrl_if #(
        .ADDR_W(AXI_ADDR_W),
        .RING_BYTES_W(RING_BYTES_W),
        .SLOT_BYTES_W(SLOT_BYTES_W),
        .SLOT_SEQ_W(SLOT_SEQ_W),
        .COUNTER_W(COUNTER_W)
    ) ctrl_if (
        .clk(clk)
    );

    assign m_axis_rd_if.tready = 1'b1;

    always #5 clk = ~clk;

    initial begin
        clk = 1'b0;

        ctrl_if.rst_ni               = 1'b0;
        ctrl_if.cfg_enable           = 1'b0;
        ctrl_if.cfg_allow_overwrite  = 1'b0;
        ctrl_if.cfg_drop_invalid_slot = 1'b1;
        ctrl_if.cfg_drop_on_no_space = 1'b0;
        ctrl_if.cfg_ring_base_addr   = '0;
        ctrl_if.cfg_ring_size_bytes  = '0;
        ctrl_if.slot_start           = 1'b0;
        ctrl_if.slot_done            = 1'b0;
        ctrl_if.slot_bytes           = '0;
        ctrl_if.slot_seq             = '0;
        ctrl_if.slot_valid_good      = 1'b0;
        ctrl_if.slot_overflow_err    = 1'b0;
        ctrl_if.rd_slot_req          = 1'b0;
        ctrl_if.rd_consume           = 1'b0;

        repeat (8) @(posedge clk);
        ctrl_if.rst_ni = 1'b1;
    end

    ddr_ringbuffer_controller #(
        .CFG_AXI_ADDR_W(AXI_ADDR_W),
        .AXIS_DATA_W(AXIS_DATA_W),
        .AXIS_USER_W(AXIS_USER_W),
        .AXI_DATA_W(AXI_DATA_W),
        .RD_AXIS_USER_W(RD_AXIS_USER_W),
        .SLOT_FIXED_EN(1'b0),
        .SLOT_BUFFER_BYTES(512),
        .DESC_FIFO_DEPTH(8),
        .MAX_BURST_LEN(8),
        .RING_SIZE_BYTES_MAX(TB_RING_SIZE_MAX),
        .SLOT_SEQ_W(SLOT_SEQ_W),
        .COUNTER_W(COUNTER_W),
        .CFG_RING_BYTES_W(RING_BYTES_W),
        .SLOT_BYTES_W(SLOT_BYTES_W)
    ) dut (
        .clk_i(clk),
        .rst_ni(ctrl_if.rst_ni),
        .cfg_enable_i(ctrl_if.cfg_enable),
        .cfg_allow_overwrite_i(ctrl_if.cfg_allow_overwrite),
        .cfg_drop_invalid_slot_i(ctrl_if.cfg_drop_invalid_slot),
        .cfg_drop_on_no_space_i(ctrl_if.cfg_drop_on_no_space),
        .cfg_ring_base_addr_i(ctrl_if.cfg_ring_base_addr),
        .cfg_ring_size_bytes_i(ctrl_if.cfg_ring_size_bytes),
        .slot_start_i(ctrl_if.slot_start),
        .slot_done_i(ctrl_if.slot_done),
        .slot_bytes_i(ctrl_if.slot_bytes),
        .slot_seq_i(ctrl_if.slot_seq),
        .slot_valid_good_i(ctrl_if.slot_valid_good),
        .slot_overflow_err_i(ctrl_if.slot_overflow_err),
        .wr_slot_commit_o(ctrl_if.wr_slot_commit),
        .wr_slot_addr_o(ctrl_if.wr_slot_addr),
        .wr_slot_seq_o(ctrl_if.wr_slot_seq),
        .wr_slot_bytes_o(ctrl_if.wr_slot_bytes),
        .wr_slot_valid_good_o(ctrl_if.wr_slot_valid_good),
        .wr_slot_overflow_err_o(ctrl_if.wr_slot_overflow_err),
        .rd_slot_req_i(ctrl_if.rd_slot_req),
        .rd_consume_i(ctrl_if.rd_consume),
        .rd_slot_valid_o(ctrl_if.rd_slot_valid),
        .rd_slot_addr_o(ctrl_if.rd_slot_addr),
        .rd_slot_bytes_o(ctrl_if.rd_slot_bytes),
        .rd_slot_seq_o(ctrl_if.rd_slot_seq),
        .rd_slot_valid_good_o(ctrl_if.rd_slot_valid_good),
        .rd_slot_overflow_err_o(ctrl_if.rd_slot_overflow_err),
        .rd_busy_o(ctrl_if.rd_busy),
        .rd_done_o(ctrl_if.rd_done),
        .rd_error_o(ctrl_if.rd_error),
        .wr_ptr_o(ctrl_if.wr_ptr),
        .rd_ptr_o(ctrl_if.rd_ptr),
        .commit_ptr_o(ctrl_if.commit_ptr),
        .used_bytes_o(ctrl_if.used_bytes),
        .free_bytes_o(ctrl_if.free_bytes),
        .committed_bytes_o(ctrl_if.committed_bytes),
        .full_o(ctrl_if.full),
        .almost_full_o(ctrl_if.almost_full),
        .empty_o(ctrl_if.empty),
        .wrap_count_o(ctrl_if.wrap_count),
        .overflow_count_o(ctrl_if.overflow_count),
        .drop_count_o(ctrl_if.drop_count),
        .err_cfg_align_o(ctrl_if.err_cfg_align),
        .err_no_space_o(ctrl_if.err_no_space),
        .err_slot_proto_o(ctrl_if.err_slot_proto),
        .err_slot_too_large_o(ctrl_if.err_slot_too_large),
        .err_axi_wr_resp_o(ctrl_if.err_axi_wr_resp),
        .err_axi_rd_resp_o(ctrl_if.err_axi_rd_resp),
        .err_illegal_read_o(ctrl_if.err_illegal_read),
        .s_axis_slot(s_axis_if),
        .m_axis_rd(m_axis_rd_if),
        .m_axi(axi_if)
    );

    initial begin
        uvm_config_db#(virtual axis_stream_if #(AXIS_DATA_W, AXIS_USER_W))::set(null, "*", "src_vif", s_axis_if);
        uvm_config_db#(virtual axis_stream_if #(AXI_DATA_W, RD_AXIS_USER_W))::set(null, "*", "rd_vif", m_axis_rd_if);
        uvm_config_db#(virtual axi4_mm_if #(AXI_ADDR_W, AXI_DATA_W))::set(null, "*", "axi_vif", axi_if);
        uvm_config_db#(virtual ddr_ringbuffer_ctrl_if #(
            AXI_ADDR_W,
            RING_BYTES_W,
            SLOT_BYTES_W,
            SLOT_SEQ_W,
            COUNTER_W
        ))::set(null, "*", "ctrl_vif", ctrl_if);

        run_test();
    end

endmodule
