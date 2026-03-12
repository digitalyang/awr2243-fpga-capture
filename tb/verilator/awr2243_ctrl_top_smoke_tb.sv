`timescale 1ns / 1ps

module awr2243_ctrl_top_smoke_tb;

  import awr2243_script_pkg::*;

  localparam logic [7:0] ADDR_CONTROL = 8'h04;
  localparam logic [7:0] ADDR_STATUS = 8'h08;
  localparam logic [7:0] ADDR_ERR_CODE_LIVE = 8'h0c;
  localparam logic [7:0] ADDR_IRQ_COUNT = 8'h24;

  localparam logic [31:0] CTRL_START_INIT = 32'h0000_0001;
  localparam logic [31:0] CTRL_START_SENSOR = 32'h0000_0002;
  localparam logic [31:0] CTRL_STOP_SENSOR = 32'h0000_0004;
  localparam logic [31:0] CTRL_HARD_RESET = 32'h0000_0008;
  localparam logic [31:0] CTRL_CLEAR_ERROR = 32'h0000_0010;

  localparam logic [15:0] ERR_NOT_INITIALIZED = 16'h0002;

  logic        sys_clk;
  logic        sys_rst_n;
  logic        csr_wr_en_i;
  logic        csr_rd_en_i;
  logic [ 7:0] csr_addr_i;
  logic [31:0] csr_wdata_i;
  logic [31:0] csr_rdata_o;
  logic        spi_sclk_o;
  logic        spi_cs_n_o;
  logic        spi_mosi_o;
  logic        spi_miso_i;
  logic        sop0_o;
  logic        sop1_o;
  logic        sop2_o;
  logic        nreset_o;
  logic        host_irq_i;
  logic        nerror_out_i;
  logic        ctrl_busy_o;
  logic        ctrl_done_o;
  logic [15:0] ctrl_err_code_o;
  logic [ 3:0] ctrl_state_o;

  logic [31:0] csr_read_data;
  bit          saw_spi_cs_low;
  bit          saw_cmd_timer_busy;
  bit          done_seen;
  int          cycles;

  function automatic logic [63:0] make_cmd(input logic [7:0] opcode, input logic [7:0] flags,
                                           input logic [15:0] step_id, input logic [15:0] imm_a,
                                           input logic [15:0] imm_b);
    begin
      make_cmd = {opcode, flags, step_id, imm_a, imm_b};
    end
  endfunction

  task automatic csr_write(input logic [7:0] addr, input logic [31:0] data);
    begin
      @(negedge sys_clk);
      csr_addr_i  = addr;
      csr_wdata_i = data;
      csr_wr_en_i = 1'b1;
      csr_rd_en_i = 1'b0;

      @(negedge sys_clk);
      csr_wr_en_i = 1'b0;
      csr_addr_i  = '0;
      csr_wdata_i = '0;
    end
  endtask

  task automatic csr_read(input logic [7:0] addr, output logic [31:0] data);
    begin
      @(negedge sys_clk);
      csr_addr_i  = addr;
      csr_rd_en_i = 1'b1;
      csr_wr_en_i = 1'b0;

      @(negedge sys_clk);
      data        = csr_rdata_o;
      csr_rd_en_i = 1'b0;
      csr_addr_i  = '0;
    end
  endtask

  awr2243_ctrl_top #(
      .CLK_FREQ_HZ        (1_000_000),
      .RESET_HOLD_US      (32'd1),
      .POST_RESET_WAIT_US (32'd2),
      .SPI_CLK_DIV        (1),
      .SPI_CS_SETUP_CYCLES(1),
      .SPI_CS_HOLD_CYCLES (1),
      .SPI_TIMEOUT_CYCLES (128)
  ) dut (
      .sys_clk        (sys_clk),
      .sys_rst_n      (sys_rst_n),
      .csr_wr_en_i    (csr_wr_en_i),
      .csr_rd_en_i    (csr_rd_en_i),
      .csr_addr_i     (csr_addr_i),
      .csr_wdata_i    (csr_wdata_i),
      .csr_rdata_o    (csr_rdata_o),
      .spi_sclk_o     (spi_sclk_o),
      .spi_cs_n_o     (spi_cs_n_o),
      .spi_mosi_o     (spi_mosi_o),
      .spi_miso_i     (spi_miso_i),
      .sop0_o         (sop0_o),
      .sop1_o         (sop1_o),
      .sop2_o         (sop2_o),
      .nreset_o       (nreset_o),
      .host_irq_i     (host_irq_i),
      .nerror_out_i   (nerror_out_i),
      .ctrl_busy_o    (ctrl_busy_o),
      .ctrl_done_o    (ctrl_done_o),
      .ctrl_err_code_o(ctrl_err_code_o),
      .ctrl_state_o   (ctrl_state_o)
  );

  initial begin
    sys_clk = 1'b0;
    forever #5 sys_clk = ~sys_clk;
  end

  initial begin
    sys_rst_n          = 1'b0;
    csr_wr_en_i        = 1'b0;
    csr_rd_en_i        = 1'b0;
    csr_addr_i         = '0;
    csr_wdata_i        = '0;
    spi_miso_i         = 1'b0;
    host_irq_i         = 1'b0;
    nerror_out_i       = 1'b1;
    saw_spi_cs_low     = 1'b0;
    saw_cmd_timer_busy = 1'b0;

    repeat (4) @(negedge sys_clk);
    sys_rst_n = 1'b1;
    @(negedge sys_clk);

    dut.u_script_ram.word_mem_r[0] =
        make_cmd(AWR_CMD_DELAY_US, 8'h00, 16'h0001, 16'h0000, 16'h0001);
    dut.u_script_ram.word_mem_r[1] = make_cmd(AWR_CMD_SPI_WR, 8'h00, 16'h0002, 16'h0000, 16'ha55a);
    dut.u_script_ram.word_mem_r[2] = make_cmd(AWR_CMD_END, 8'h00, 16'h0003, 16'h0000, 16'h0000);
    dut.u_script_ram.base_addr_r[0] = '0;
    dut.u_script_ram.script_len_r[0] = 3;

    if ({sop2_o, sop1_o, sop0_o} !== 3'b001) begin
      $fatal(1, "reset controller SOP defaults are not functional SPI mode");
    end

    csr_write(ADDR_CONTROL, CTRL_START_SENSOR);
    repeat (2) @(negedge sys_clk);
    if (ctrl_err_code_o !== ERR_NOT_INITIALIZED) begin
      $fatal(1, "start_sensor before init did not raise ERR_NOT_INITIALIZED");
    end

    csr_read(ADDR_ERR_CODE_LIVE, csr_read_data);
    if (csr_read_data[15:0] !== ERR_NOT_INITIALIZED) begin
      $fatal(1, "CSR err-code readback mismatch before init");
    end

    csr_write(ADDR_CONTROL, CTRL_CLEAR_ERROR);
    repeat (2) @(negedge sys_clk);
    if (ctrl_err_code_o !== 16'h0000) begin
      $fatal(1, "clear_error did not return sequencer to idle");
    end

    csr_write(ADDR_CONTROL, CTRL_START_INIT);
    for (cycles = 0; cycles < 120; cycles++) begin
      @(negedge sys_clk);
      if (!spi_cs_n_o) begin
        saw_spi_cs_low = 1'b1;
      end
      if (dut.u_cmd_timer.busy_o) begin
        saw_cmd_timer_busy = 1'b1;
      end
      if (ctrl_done_o) begin
        break;
      end
    end
    if (!ctrl_done_o) begin
      $display(
          "init timeout: seq_state=%0d err=%0h reset_state=%0d fetch_state=%0d decode_state=%0d active_script=%0d fetch_done=%0b cmd_done=%0b cmd_err=%0b timer_busy=%0b timer_done=%0b spi_busy=%0b spi_done=%0b",
          dut.u_cfg_sequencer.state_o, ctrl_err_code_o, dut.u_reset_ctrl.state_o,
          dut.u_cmd_fetch.state_o, dut.u_cmd_decode.state_o, dut.u_cfg_sequencer.active_script_o,
          dut.fetch_script_done, dut.decode_cmd_done, dut.decode_cmd_error, dut.u_cmd_timer.busy_o,
          dut.u_cmd_timer.done_o, dut.u_spi_master.busy_o, dut.u_spi_master.done_o);
      $fatal(1, "init flow timed out");
    end
    if (ctrl_err_code_o !== 16'h0000) begin
      $fatal(1, "init flow completed with an unexpected error");
    end
    if (!saw_spi_cs_low) begin
      $fatal(1, "init script never exercised the SPI master");
    end
    if (!saw_cmd_timer_busy) begin
      $fatal(1, "init script never exercised the shared command timer");
    end
    if (nreset_o !== 1'b1) begin
      $fatal(1, "device reset was not released after init");
    end

    csr_read(ADDR_STATUS, csr_read_data);
    if (!csr_read_data[8]) begin
      $fatal(1, "CSR done sticky bit was not captured after init");
    end

    csr_write(ADDR_CONTROL, CTRL_START_SENSOR);
    done_seen = 1'b0;
    for (cycles = 0; cycles < 80; cycles++) begin
      @(negedge sys_clk);
      if (cycles == 8) begin
        host_irq_i = 1'b1;
      end
      if (cycles == 12) begin
        host_irq_i = 1'b0;
      end
      if (ctrl_done_o) begin
        done_seen = 1'b1;
        break;
      end
    end
    host_irq_i = 1'b0;
    if (!done_seen) begin
      $display("start timeout: seq_state=%0d err=%0h host_irq_sticky=%0b irq_count=%0d",
               dut.u_cfg_sequencer.state_o, ctrl_err_code_o, dut.u_status_mon.host_irq_sticky_o,
               dut.u_status_mon.irq_count_o);
      $fatal(1, "start flow timed out waiting for host IRQ");
    end
    if (ctrl_err_code_o !== 16'h0000) begin
      $fatal(1, "start flow completed with an unexpected error");
    end

    csr_read(ADDR_IRQ_COUNT, csr_read_data);
    if (csr_read_data != 32'd1) begin
      $fatal(1, "IRQ counter did not increment after start handshake");
    end

    csr_write(ADDR_CONTROL, CTRL_STOP_SENSOR);
    for (cycles = 0; cycles < 80; cycles++) begin
      @(negedge sys_clk);
      if (ctrl_done_o) begin
        break;
      end
    end
    if (!ctrl_done_o) begin
      $display("stop timeout: seq_state=%0d err=%0h", dut.u_cfg_sequencer.state_o, ctrl_err_code_o);
      $fatal(1, "stop flow timed out");
    end

    csr_write(ADDR_CONTROL, CTRL_HARD_RESET);
    for (cycles = 0; cycles < 40; cycles++) begin
      @(negedge sys_clk);
      if (!nreset_o) begin
        break;
      end
    end
    if (nreset_o !== 1'b0) begin
      $fatal(1, "hard reset never asserted nreset_o low");
    end

    for (cycles = 0; cycles < 80; cycles++) begin
      @(negedge sys_clk);
      if (ctrl_done_o) begin
        break;
      end
    end
    if (!ctrl_done_o) begin
      $display("hard reset timeout: seq_state=%0d err=%0h reset_state=%0d nreset=%0b",
               dut.u_cfg_sequencer.state_o, ctrl_err_code_o, dut.u_reset_ctrl.state_o, nreset_o);
      $fatal(1, "hard reset flow timed out");
    end
    if (nreset_o !== 1'b1) begin
      $fatal(1, "hard reset flow did not release nreset_o");
    end

    $display("awr2243_ctrl_top smoke test passed");
    $finish;
  end

  initial begin
    #5000;
    $fatal(1, "global timeout");
  end

endmodule
