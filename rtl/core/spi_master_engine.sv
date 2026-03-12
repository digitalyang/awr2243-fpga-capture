module spi_master_engine #(
    parameter int unsigned SPI_CLK_DIV     = 4,
    parameter int unsigned CS_SETUP_CYCLES = 1,
    parameter int unsigned CS_HOLD_CYCLES  = 1,
    parameter int unsigned TIMEOUT_CYCLES  = 1024
) (
    input  logic        sys_clk,
    input  logic        sys_rst_n,
    input  logic        cmd_valid_i,
    output logic        cmd_ready_o,
    input  logic        cmd_is_read_i,
    input  logic [15:0] cmd_word_i,
    output logic        rsp_valid_o,
    output logic [15:0] rsp_word_o,
    output logic        busy_o,
    output logic        done_o,
    output logic        timeout_o,
    output logic        spi_sclk_o,
    output logic        spi_cs_n_o,
    output logic        spi_mosi_o,
    input  logic        spi_miso_i
);

  localparam int unsigned WORD_W = 16;
  localparam int unsigned SPI_CLK_DIV_INT = (SPI_CLK_DIV > 0) ? SPI_CLK_DIV : 1;
  localparam int unsigned WAIT_CYCLES_MAX =
      (CS_SETUP_CYCLES > CS_HOLD_CYCLES) ? CS_SETUP_CYCLES : CS_HOLD_CYCLES;
  localparam int unsigned TIMEOUT_CYCLES_INT = (TIMEOUT_CYCLES > 0) ? TIMEOUT_CYCLES : 1;

  function automatic int unsigned clog2_safe(input int unsigned value);
    begin
      if (value <= 1) begin
        return 1;
      end

      return $clog2(value);
    end
  endfunction

  localparam int unsigned BIT_CNT_W = clog2_safe(WORD_W + 1);
  localparam int unsigned CLK_DIV_CNT_W = clog2_safe(SPI_CLK_DIV_INT);
  localparam int unsigned WAIT_CNT_W = clog2_safe(WAIT_CYCLES_MAX + 1);
  localparam int unsigned TIMEOUT_CNT_W = clog2_safe(TIMEOUT_CYCLES_INT + 1);

  typedef enum logic [2:0] {
    ST_IDLE,
    ST_ASSERT_CS,
    ST_SHIFT,
    ST_DEASSERT_CS,
    ST_DONE,
    ST_TIMEOUT
  } spi_state_e;

  spi_state_e                    state_r;
  spi_state_e                    state_n;
  logic                          cmd_is_read_r;
  logic                          cmd_is_read_n;
  logic                          sclk_phase_r;
  logic                          sclk_phase_n;
  logic [WORD_W-1:0]             tx_shift_r;
  logic [WORD_W-1:0]             tx_shift_n;
  logic [WORD_W-1:0]             rx_shift_r;
  logic [WORD_W-1:0]             rx_shift_n;
  logic [WORD_W-1:0]             rsp_word_r;
  logic [WORD_W-1:0]             rsp_word_n;
  logic [BIT_CNT_W-1:0]          bit_cnt_r;
  logic [BIT_CNT_W-1:0]          bit_cnt_n;
  logic [CLK_DIV_CNT_W-1:0]      clk_div_cnt_r;
  logic [CLK_DIV_CNT_W-1:0]      clk_div_cnt_n;
  logic [WAIT_CNT_W-1:0]         wait_cnt_r;
  logic [WAIT_CNT_W-1:0]         wait_cnt_n;
  logic [TIMEOUT_CNT_W-1:0]      timeout_cnt_r;
  logic [TIMEOUT_CNT_W-1:0]      timeout_cnt_n;

  logic                          cmd_fire_c;
  logic                          txn_active_c;
  logic                          timeout_en_c;
  logic                          timeout_expire_c;

  function automatic logic is_active_state(input spi_state_e state);
    begin
      case (state)
        ST_ASSERT_CS,
        ST_SHIFT,
        ST_DEASSERT_CS: return 1'b1;
        default:        return 1'b0;
      endcase
    end
  endfunction

  assign cmd_fire_c = cmd_valid_i && cmd_ready_o;
  assign txn_active_c = is_active_state(state_r);
  assign timeout_en_c = (TIMEOUT_CYCLES != 0);
  assign timeout_expire_c =
      timeout_en_c && (timeout_cnt_r == TIMEOUT_CNT_W'(TIMEOUT_CYCLES_INT - 1));

  assign cmd_ready_o = (state_r == ST_IDLE);
  assign rsp_valid_o = (state_r == ST_DONE) && cmd_is_read_r;
  assign rsp_word_o = rsp_word_r;
  assign busy_o = txn_active_c;
  assign done_o = (state_r == ST_DONE);
  assign timeout_o = (state_r == ST_TIMEOUT);

  assign spi_sclk_o = (state_r == ST_SHIFT) ? sclk_phase_r : 1'b0;
  assign spi_cs_n_o = !((state_r == ST_ASSERT_CS) || (state_r == ST_SHIFT));
  assign spi_mosi_o =
      ((state_r == ST_ASSERT_CS) || (state_r == ST_SHIFT)) ? tx_shift_r[WORD_W-1] : 1'b0;

  // The command word already carries the AWR2243 read/write encoding on MOSI.
  // cmd_is_read_i only tags whether the upper layer expects rsp_valid_o.
  always_comb begin
    state_n       = state_r;
    cmd_is_read_n = cmd_is_read_r;
    sclk_phase_n  = sclk_phase_r;
    tx_shift_n    = tx_shift_r;
    rx_shift_n    = rx_shift_r;
    rsp_word_n    = rsp_word_r;
    bit_cnt_n     = bit_cnt_r;
    clk_div_cnt_n = clk_div_cnt_r;
    wait_cnt_n    = wait_cnt_r;
    timeout_cnt_n = timeout_cnt_r;

    case (state_r)
      ST_IDLE: begin
        sclk_phase_n  = 1'b0;
        bit_cnt_n     = '0;
        clk_div_cnt_n = '0;
        wait_cnt_n    = '0;
        timeout_cnt_n = '0;

        if (cmd_fire_c) begin
          state_n       = ST_ASSERT_CS;
          cmd_is_read_n = cmd_is_read_i;
          tx_shift_n    = cmd_word_i;
          rx_shift_n    = '0;
          bit_cnt_n     = BIT_CNT_W'(WORD_W);
          clk_div_cnt_n = '0;
          wait_cnt_n    = '0;
        end
      end

      ST_ASSERT_CS: begin
        sclk_phase_n  = 1'b0;
        clk_div_cnt_n = '0;

        if (wait_cnt_r == WAIT_CNT_W'(CS_SETUP_CYCLES)) begin
          // SPI mode-0: drive MOSI while SCLK is low, then sample MISO on the first rising edge.
          state_n       = ST_SHIFT;
          sclk_phase_n  = 1'b1;
          clk_div_cnt_n = '0;
          wait_cnt_n    = '0;
          rx_shift_n    = {rx_shift_r[WORD_W-2:0], spi_miso_i};
          bit_cnt_n     = bit_cnt_r - BIT_CNT_W'(1);
        end else begin
          wait_cnt_n = wait_cnt_r + WAIT_CNT_W'(1);
        end
      end

      ST_SHIFT: begin
        wait_cnt_n = '0;

        if (clk_div_cnt_r == CLK_DIV_CNT_W'(SPI_CLK_DIV_INT - 1)) begin
          clk_div_cnt_n = '0;

          if (sclk_phase_r) begin
            sclk_phase_n = 1'b0;

            if (bit_cnt_r != '0) begin
              // Update MOSI on the falling edge so the next bit is stable before the next rise.
              tx_shift_n = {tx_shift_r[WORD_W-2:0], 1'b0};
            end else begin
              state_n      = ST_DEASSERT_CS;
              sclk_phase_n = 1'b0;
              wait_cnt_n   = '0;
              rsp_word_n   = rx_shift_r;
            end
          end else begin
            sclk_phase_n = 1'b1;
            rx_shift_n   = {rx_shift_r[WORD_W-2:0], spi_miso_i};
            bit_cnt_n    = bit_cnt_r - BIT_CNT_W'(1);
          end
        end else begin
          clk_div_cnt_n = clk_div_cnt_r + CLK_DIV_CNT_W'(1);
        end
      end

      ST_DEASSERT_CS: begin
        sclk_phase_n  = 1'b0;
        clk_div_cnt_n = '0;

        if (wait_cnt_r == WAIT_CNT_W'(CS_HOLD_CYCLES)) begin
          state_n    = ST_DONE;
          wait_cnt_n = '0;
          rsp_word_n = rx_shift_r;
        end else begin
          wait_cnt_n = wait_cnt_r + WAIT_CNT_W'(1);
        end
      end

      ST_DONE: begin
        state_n       = ST_IDLE;
        sclk_phase_n  = 1'b0;
        bit_cnt_n     = '0;
        clk_div_cnt_n = '0;
        wait_cnt_n    = '0;
        timeout_cnt_n = '0;
      end

      ST_TIMEOUT: begin
        state_n       = ST_IDLE;
        sclk_phase_n  = 1'b0;
        bit_cnt_n     = '0;
        clk_div_cnt_n = '0;
        wait_cnt_n    = '0;
        timeout_cnt_n = '0;
      end

      default: begin
        state_n       = ST_IDLE;
        sclk_phase_n  = 1'b0;
        bit_cnt_n     = '0;
        clk_div_cnt_n = '0;
        wait_cnt_n    = '0;
        timeout_cnt_n = '0;
      end
    endcase

    if (is_active_state(state_n)) begin
      if (txn_active_c) begin
        timeout_cnt_n = timeout_cnt_r + TIMEOUT_CNT_W'(1);
      end else begin
        timeout_cnt_n = '0;
      end
    end else begin
      timeout_cnt_n = '0;
    end

    if (timeout_expire_c && is_active_state(state_n)) begin
      state_n       = ST_TIMEOUT;
      sclk_phase_n  = 1'b0;
      clk_div_cnt_n = '0;
      wait_cnt_n    = '0;
      timeout_cnt_n = '0;
      rsp_word_n    = rx_shift_n;
    end
  end

  always_ff @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
      state_r       <= ST_IDLE;
      cmd_is_read_r <= 1'b0;
      sclk_phase_r  <= 1'b0;
      tx_shift_r    <= '0;
      rx_shift_r    <= '0;
      rsp_word_r    <= '0;
      bit_cnt_r     <= '0;
      clk_div_cnt_r <= '0;
      wait_cnt_r    <= '0;
      timeout_cnt_r <= '0;
    end else begin
      state_r       <= state_n;
      cmd_is_read_r <= cmd_is_read_n;
      sclk_phase_r  <= sclk_phase_n;
      tx_shift_r    <= tx_shift_n;
      rx_shift_r    <= rx_shift_n;
      rsp_word_r    <= rsp_word_n;
      bit_cnt_r     <= bit_cnt_n;
      clk_div_cnt_r <= clk_div_cnt_n;
      wait_cnt_r    <= wait_cnt_n;
      timeout_cnt_r <= timeout_cnt_n;
    end
  end

endmodule
