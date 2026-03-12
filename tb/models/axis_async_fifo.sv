module axis_async_fifo #(
    parameter int unsigned DEPTH = 16,
    parameter int unsigned DATA_WIDTH = 256,
    parameter bit KEEP_ENABLE = 1'b1,
    parameter int unsigned KEEP_WIDTH = (DATA_WIDTH / 8),
    parameter bit LAST_ENABLE = 1'b1,
    parameter bit USER_ENABLE = 1'b1,
    parameter int unsigned USER_WIDTH = 64
) (
    input  logic                    s_clk,
    input  logic                    s_rst,
    input  logic [DATA_WIDTH-1:0]   s_axis_tdata,
    input  logic [KEEP_WIDTH-1:0]   s_axis_tkeep,
    input  logic                    s_axis_tvalid,
    output logic                    s_axis_tready,
    input  logic                    s_axis_tlast,
    input  logic [USER_WIDTH-1:0]   s_axis_tuser,

    input  logic                    m_clk,
    input  logic                    m_rst,
    output logic [DATA_WIDTH-1:0]   m_axis_tdata,
    output logic [KEEP_WIDTH-1:0]   m_axis_tkeep,
    output logic                    m_axis_tvalid,
    input  logic                    m_axis_tready,
    output logic                    m_axis_tlast,
    output logic [USER_WIDTH-1:0]   m_axis_tuser,

    output logic [$clog2(DEPTH+1)-1:0] status_depth
);
  localparam int unsigned ADDR_W = (DEPTH <= 2) ? 1 : $clog2(DEPTH);
  localparam int unsigned PTR_W = ADDR_W + 1;

  logic [DATA_WIDTH-1:0] mem_data[0:DEPTH-1];
  logic [KEEP_WIDTH-1:0] mem_keep[0:DEPTH-1];
  logic                  mem_last[0:DEPTH-1];
  logic [USER_WIDTH-1:0] mem_user[0:DEPTH-1];

  logic [PTR_W-1:0] wr_ptr_bin_reg;
  logic [PTR_W-1:0] wr_ptr_gray_reg;
  logic [PTR_W-1:0] rd_ptr_bin_reg;
  logic [PTR_W-1:0] rd_ptr_gray_reg;

  logic [PTR_W-1:0] wr_ptr_gray_sync1_reg;
  logic [PTR_W-1:0] wr_ptr_gray_sync2_reg;
  logic [PTR_W-1:0] rd_ptr_gray_sync1_reg;
  logic [PTR_W-1:0] rd_ptr_gray_sync2_reg;

  logic [PTR_W-1:0] wr_ptr_bin_next;
  logic [PTR_W-1:0] wr_ptr_bin_inc;
  logic [PTR_W-1:0] wr_ptr_gray_next;
  logic [PTR_W-1:0] rd_ptr_bin_next;
  logic [PTR_W-1:0] rd_ptr_gray_next;
  logic [PTR_W-1:0] wr_ptr_bin_sync;
  logic             wr_write_en;
  logic             rd_read_en;
  logic             full_c;
  logic             empty_c;

  function automatic [PTR_W-1:0] bin2gray(input [PTR_W-1:0] value);
    return (value >> 1) ^ value;
  endfunction

  function automatic [PTR_W-1:0] gray2bin(input [PTR_W-1:0] value);
    int idx;
    begin
      gray2bin[PTR_W-1] = value[PTR_W-1];
      for (idx = PTR_W-2; idx >= 0; idx--) begin
        gray2bin[idx] = gray2bin[idx+1] ^ value[idx];
      end
    end
  endfunction

  initial begin
    if (DEPTH < 4) begin
      $error("%m DEPTH must be >= 4");
      $fatal;
    end

    if ((DEPTH & (DEPTH - 1)) != 0) begin
      $error("%m DEPTH must be a power of 2");
      $fatal;
    end
  end

  assign wr_ptr_bin_inc = wr_ptr_bin_reg + {{(PTR_W-1){1'b0}}, 1'b1};
  assign full_c = (bin2gray(wr_ptr_bin_inc) == {~rd_ptr_gray_sync2_reg[PTR_W-1:PTR_W-2], rd_ptr_gray_sync2_reg[PTR_W-3:0]});
  assign s_axis_tready = ~full_c;
  assign wr_write_en = s_axis_tvalid && ~full_c;
  assign wr_ptr_bin_next = wr_ptr_bin_reg + {{(PTR_W-1){1'b0}}, wr_write_en};
  assign wr_ptr_gray_next = bin2gray(wr_ptr_bin_next);
  assign rd_read_en = m_axis_tvalid && m_axis_tready;
  assign rd_ptr_bin_next = rd_ptr_bin_reg + {{(PTR_W-1){1'b0}}, rd_read_en};
  assign rd_ptr_gray_next = bin2gray(rd_ptr_bin_next);
  assign empty_c = (wr_ptr_gray_sync2_reg == rd_ptr_gray_reg);
  assign m_axis_tvalid = ~empty_c;

  assign wr_ptr_bin_sync = gray2bin(wr_ptr_gray_sync2_reg);
  assign status_depth = wr_ptr_bin_sync[$clog2(DEPTH+1)-1:0] - rd_ptr_bin_reg[$clog2(DEPTH+1)-1:0];

  always_comb begin
    if (empty_c) begin
      m_axis_tdata = '0;
      m_axis_tkeep = KEEP_ENABLE ? '0 : '1;
      m_axis_tlast = 1'b0;
      m_axis_tuser = '0;
    end else begin
      m_axis_tdata = mem_data[rd_ptr_bin_reg[ADDR_W-1:0]];
      m_axis_tkeep = KEEP_ENABLE ? mem_keep[rd_ptr_bin_reg[ADDR_W-1:0]] : '1;
      m_axis_tlast = LAST_ENABLE ? mem_last[rd_ptr_bin_reg[ADDR_W-1:0]] : 1'b1;
      m_axis_tuser = USER_ENABLE ? mem_user[rd_ptr_bin_reg[ADDR_W-1:0]] : '0;
    end
  end

  always_ff @(posedge s_clk) begin
    if (s_rst) begin
      wr_ptr_bin_reg <= '0;
      wr_ptr_gray_reg <= '0;
      rd_ptr_gray_sync1_reg <= '0;
      rd_ptr_gray_sync2_reg <= '0;
    end else begin
      rd_ptr_gray_sync1_reg <= rd_ptr_gray_reg;
      rd_ptr_gray_sync2_reg <= rd_ptr_gray_sync1_reg;

      if (wr_write_en) begin
        mem_data[wr_ptr_bin_reg[ADDR_W-1:0]] <= s_axis_tdata;
        mem_keep[wr_ptr_bin_reg[ADDR_W-1:0]] <= s_axis_tkeep;
        mem_last[wr_ptr_bin_reg[ADDR_W-1:0]] <= s_axis_tlast;
        mem_user[wr_ptr_bin_reg[ADDR_W-1:0]] <= s_axis_tuser;
        wr_ptr_bin_reg <= wr_ptr_bin_next;
        wr_ptr_gray_reg <= wr_ptr_gray_next;
      end
    end
  end

  always_ff @(posedge m_clk) begin
    if (m_rst) begin
      rd_ptr_bin_reg <= '0;
      rd_ptr_gray_reg <= '0;
      wr_ptr_gray_sync1_reg <= '0;
      wr_ptr_gray_sync2_reg <= '0;
    end else begin
      wr_ptr_gray_sync1_reg <= wr_ptr_gray_reg;
      wr_ptr_gray_sync2_reg <= wr_ptr_gray_sync1_reg;

      if (rd_read_en) begin
        rd_ptr_bin_reg <= rd_ptr_bin_next;
        rd_ptr_gray_reg <= rd_ptr_gray_next;
      end
    end
  end
endmodule
