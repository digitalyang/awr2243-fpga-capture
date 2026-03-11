interface ddr_ringbuffer_ctrl_if #(
    parameter int unsigned ADDR_W       = 34,
    parameter int unsigned RING_BYTES_W = 17,
    parameter int unsigned SLOT_BYTES_W = 17,
    parameter int unsigned SLOT_SEQ_W   = 16,
    parameter int unsigned COUNTER_W    = 32
) (
    input logic clk
);

    logic rst_ni;

    logic                   cfg_enable;
    logic                   cfg_allow_overwrite;
    logic                   cfg_drop_invalid_slot;
    logic                   cfg_drop_on_no_space;
    logic [ADDR_W-1:0]      cfg_ring_base_addr;
    logic [RING_BYTES_W-1:0] cfg_ring_size_bytes;

    logic                   slot_start;
    logic                   slot_done;
    logic [SLOT_BYTES_W-1:0] slot_bytes;
    logic [SLOT_SEQ_W-1:0]  slot_seq;
    logic                   slot_valid_good;
    logic                   slot_overflow_err;

    logic                   rd_slot_req;
    logic                   rd_consume;

    logic                   wr_slot_commit;
    logic [ADDR_W-1:0]      wr_slot_addr;
    logic [SLOT_SEQ_W-1:0]  wr_slot_seq;
    logic [SLOT_BYTES_W-1:0] wr_slot_bytes;
    logic                   wr_slot_valid_good;
    logic                   wr_slot_overflow_err;

    logic                   rd_slot_valid;
    logic [ADDR_W-1:0]      rd_slot_addr;
    logic [SLOT_BYTES_W-1:0] rd_slot_bytes;
    logic [SLOT_SEQ_W-1:0]  rd_slot_seq;
    logic                   rd_slot_valid_good;
    logic                   rd_slot_overflow_err;
    logic                   rd_busy;
    logic                   rd_done;
    logic                   rd_error;

    logic [ADDR_W-1:0]      wr_ptr;
    logic [ADDR_W-1:0]      rd_ptr;
    logic [ADDR_W-1:0]      commit_ptr;
    logic [RING_BYTES_W-1:0] used_bytes;
    logic [RING_BYTES_W-1:0] free_bytes;
    logic [RING_BYTES_W-1:0] committed_bytes;
    logic                   full;
    logic                   almost_full;
    logic                   empty;
    logic [COUNTER_W-1:0]   wrap_count;
    logic [COUNTER_W-1:0]   overflow_count;
    logic [COUNTER_W-1:0]   drop_count;

    logic                   err_cfg_align;
    logic                   err_no_space;
    logic                   err_slot_proto;
    logic                   err_slot_too_large;
    logic                   err_axi_wr_resp;
    logic                   err_axi_rd_resp;
    logic                   err_illegal_read;

    clocking drv_cb @(posedge clk);
        output cfg_enable;
        output cfg_allow_overwrite;
        output cfg_drop_invalid_slot;
        output cfg_drop_on_no_space;
        output cfg_ring_base_addr;
        output cfg_ring_size_bytes;
        output rd_slot_req;
        output rd_consume;
    endclocking

    clocking mon_cb @(posedge clk);
        input rst_ni;
        input cfg_enable;
        input cfg_allow_overwrite;
        input cfg_drop_invalid_slot;
        input cfg_drop_on_no_space;
        input cfg_ring_base_addr;
        input cfg_ring_size_bytes;
        input slot_start;
        input slot_done;
        input slot_bytes;
        input slot_seq;
        input slot_valid_good;
        input slot_overflow_err;
        input rd_slot_req;
        input rd_consume;
        input wr_slot_commit;
        input wr_slot_addr;
        input wr_slot_seq;
        input wr_slot_bytes;
        input wr_slot_valid_good;
        input wr_slot_overflow_err;
        input rd_slot_valid;
        input rd_slot_addr;
        input rd_slot_bytes;
        input rd_slot_seq;
        input rd_slot_valid_good;
        input rd_slot_overflow_err;
        input rd_busy;
        input rd_done;
        input rd_error;
        input wr_ptr;
        input rd_ptr;
        input commit_ptr;
        input used_bytes;
        input free_bytes;
        input committed_bytes;
        input full;
        input almost_full;
        input empty;
        input wrap_count;
        input overflow_count;
        input drop_count;
        input err_cfg_align;
        input err_no_space;
        input err_slot_proto;
        input err_slot_too_large;
        input err_axi_wr_resp;
        input err_axi_rd_resp;
        input err_illegal_read;
    endclocking

endinterface
