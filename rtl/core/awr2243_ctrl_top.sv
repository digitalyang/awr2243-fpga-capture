`include "awr2243_script_macros.svh"

module awr2243_ctrl_top #(
    parameter int unsigned CSR_ADDR_W = 8,
    parameter int unsigned CSR_DATA_W = 32,
    parameter int unsigned CLK_FREQ_HZ = 100_000_000,
    parameter int unsigned SCRIPT_WORD_W = `AWR2243_SCRIPT_WORD_W_DFLT,
    parameter int unsigned SCRIPT_DEPTH = `AWR2243_SCRIPT_MEM_DEPTH_DFLT,
    parameter int unsigned SCRIPT_COUNT = `AWR2243_SCRIPT_TABLE_DEPTH_DFLT,
    parameter int unsigned SCRIPT_ID_W = awr2243_script_pkg::clog2_safe(SCRIPT_COUNT),
    parameter int unsigned SCRIPT_ADDR_W = awr2243_script_pkg::clog2_safe(SCRIPT_DEPTH),
    parameter int unsigned SCRIPT_LEN_W = awr2243_script_pkg::clog2_safe(SCRIPT_DEPTH + 1),
    parameter int unsigned STEP_ID_W = `AWR2243_SCRIPT_STEP_ID_W_DFLT,
    parameter int unsigned CMD_ERR_CODE_W = `AWR2243_SCRIPT_ERR_CODE_W_DFLT,
    parameter int unsigned CTRL_ERR_CODE_W = 16,
    parameter int unsigned OPCODE_W = `AWR2243_SCRIPT_OPCODE_W_DFLT,
    parameter int unsigned STATUS_COUNT_W = 32,
    parameter int unsigned TIMER_VALUE_W = `AWR2243_SCRIPT_TIMER_VALUE_W_DFLT,
    parameter int unsigned TIMER_UNIT_W = `AWR2243_SCRIPT_TIMER_UNIT_W_DFLT,
    parameter logic [2:0] DEFAULT_SOP_MODE = 3'b001,
    parameter logic [TIMER_VALUE_W-1:0] RESET_HOLD_US = TIMER_VALUE_W'(10),
    parameter logic [TIMER_VALUE_W-1:0] POST_RESET_WAIT_US = TIMER_VALUE_W'(1000),
    parameter bit AUTO_RECOVERY_EN = 1'b1,
    parameter bit STATUS_ARM = 1'b1,
    parameter int unsigned SPI_CLK_DIV = 4,
    parameter int unsigned SPI_CS_SETUP_CYCLES = 1,
    parameter int unsigned SPI_CS_HOLD_CYCLES = 1,
    parameter int unsigned SPI_TIMEOUT_CYCLES = 1024
) (
    input  logic                        sys_clk,
    input  logic                        sys_rst_n,
    input  logic                        csr_wr_en_i,
    input  logic                        csr_rd_en_i,
    input  logic [CSR_ADDR_W-1:0]       csr_addr_i,
    input  logic [CSR_DATA_W-1:0]       csr_wdata_i,
    output logic [CSR_DATA_W-1:0]       csr_rdata_o,
    output logic                        spi_sclk_o,
    output logic                        spi_cs_n_o,
    output logic                        spi_mosi_o,
    input  logic                        spi_miso_i,
    output logic                        sop0_o,
    output logic                        sop1_o,
    output logic                        sop2_o,
    output logic                        nreset_o,
    input  logic                        host_irq_i,
    input  logic                        nerror_out_i,
    output logic                        ctrl_busy_o,
    output logic                        ctrl_done_o,
    output logic [CTRL_ERR_CODE_W-1:0]  ctrl_err_code_o,
    output logic [3:0]                  ctrl_state_o
);

  localparam logic WARM_RESET_TIED_LOW = 1'b0;

  logic                        csr_start_init;
  logic                        csr_start_sensor;
  logic                        csr_stop_sensor;
  logic                        csr_hard_reset;
  logic                        csr_clear_error;
  logic [SCRIPT_ID_W-1:0]      csr_init_script_id;
  logic [SCRIPT_ID_W-1:0]      csr_rf_script_id;
  logic [SCRIPT_ID_W-1:0]      csr_profile_script_id;
  logic [SCRIPT_ID_W-1:0]      csr_frame_script_id;
  logic [SCRIPT_ID_W-1:0]      csr_monitor_script_id;
  logic [SCRIPT_ID_W-1:0]      csr_start_script_id;
  logic [SCRIPT_ID_W-1:0]      csr_stop_script_id;

  logic                        seq_req_enter_spi_mode;
  logic                        seq_req_hard_reset;
  logic                        seq_req_recovery_reset;
  logic                        seq_script_start;
  logic [SCRIPT_ID_W-1:0]      seq_script_id;
  logic                        seq_busy;
  logic                        seq_done;
  logic [CTRL_ERR_CODE_W-1:0]  seq_err_code;
  logic [3:0]                  seq_state;
  logic [STEP_ID_W-1:0]        seq_step_id;
  logic [OPCODE_W-1:0]         seq_last_opcode;

  logic                        status_host_irq_rise;
  logic                        status_host_irq_sticky;
  logic                        status_fault_active;
  logic                        status_fault_sticky;
  logic [STATUS_COUNT_W-1:0]   status_irq_count;
  logic [STATUS_COUNT_W-1:0]   status_fault_count;
  logic                        status_clr_irq_sticky;
  logic                        status_clr_fault_sticky;
  logic                        status_clr_warm_reset_sticky;
  logic                        status_clear_any;

  logic                        reset_done;
  logic                        reset_err;

  logic                        ram_rd_en;
  logic [SCRIPT_ADDR_W-1:0]    ram_rd_addr;
  logic                        ram_rd_valid;
  logic [SCRIPT_WORD_W-1:0]    ram_rd_data;
  logic [SCRIPT_ID_W-1:0]      ram_script_id;
  logic [SCRIPT_ADDR_W-1:0]    ram_script_base;
  logic [SCRIPT_LEN_W-1:0]     ram_script_len;

  logic                        fetch_cmd_valid;
  logic [SCRIPT_WORD_W-1:0]    fetch_cmd_word;
  logic [SCRIPT_ADDR_W-1:0]    fetch_pc;
  logic                        fetch_script_done;

  logic                        decode_fetch_advance;
  logic                        decode_fetch_hold;
  logic                        decode_jump_en;
  logic [SCRIPT_ADDR_W-1:0]    decode_jump_addr;
  logic                        decode_cmd_done;
  logic                        decode_cmd_error;
  logic [CMD_ERR_CODE_W-1:0]   decode_err_code;
  logic [CTRL_ERR_CODE_W-1:0]  seq_cmd_err_code;
  logic [STEP_ID_W-1:0]        decode_step_id;
  logic [OPCODE_W-1:0]         decode_last_opcode;
  logic                        decode_spi_cmd_valid;
  logic                        decode_spi_cmd_ready;
  logic                        decode_spi_cmd_is_read;
  logic [15:0]                 decode_spi_cmd_word;
  logic                        decode_timer_start;
  logic                        decode_timer_clear;
  logic [TIMER_VALUE_W-1:0]    decode_timer_period_value;
  logic [TIMER_UNIT_W-1:0]     decode_timer_period_unit;
  logic                        decode_clr_irq_sticky;
  logic                        decode_clr_fault_sticky;

  logic                        spi_rsp_valid;
  logic [15:0]                 spi_rsp_word;
  logic                        spi_busy;
  logic                        spi_done;
  logic                        spi_timeout;

  logic                        cmd_timer_busy;
  logic                        cmd_timer_done;
  logic                        cmd_timer_expired;

  initial begin
    if (CTRL_ERR_CODE_W < CMD_ERR_CODE_W) begin
      $error("%m CTRL_ERR_CODE_W must be >= CMD_ERR_CODE_W");
      $fatal;
    end

    if (OPCODE_W < 8) begin
      $error("%m OPCODE_W must be at least 8 bits");
      $fatal;
    end
  end

  assign status_clear_any = csr_clear_error || csr_hard_reset || csr_start_init;
  assign status_clr_irq_sticky =
      decode_clr_irq_sticky || status_clear_any || csr_start_sensor;
  assign status_clr_fault_sticky = decode_clr_fault_sticky || status_clear_any;
  assign status_clr_warm_reset_sticky = status_clear_any;

  // awr2243_cmd_decode emits a 2-bit timer unit, but the shared timer only consumes
  // the established cycle/us LSB encoding today.
  assign seq_cmd_err_code = CTRL_ERR_CODE_W'(decode_err_code);

  csr_reg_block #(
      .CSR_ADDR_W(CSR_ADDR_W),
      .CSR_DATA_W(CSR_DATA_W),
      .SCRIPT_ID_W(SCRIPT_ID_W),
      .ERR_CODE_W(CTRL_ERR_CODE_W),
      .STEP_ID_W(STEP_ID_W),
      .OPCODE_W(OPCODE_W),
      .COUNT_W(STATUS_COUNT_W)
  ) u_csr_reg_block (
      .sys_clk(sys_clk),
      .sys_rst_n(sys_rst_n),
      .csr_wr_en_i(csr_wr_en_i),
      .csr_rd_en_i(csr_rd_en_i),
      .csr_addr_i(csr_addr_i),
      .csr_wdata_i(csr_wdata_i),
      .csr_rdata_o(csr_rdata_o),
      .start_init_o(csr_start_init),
      .start_sensor_o(csr_start_sensor),
      .stop_sensor_o(csr_stop_sensor),
      .hard_reset_o(csr_hard_reset),
      .clear_error_o(csr_clear_error),
      .init_script_id_o(csr_init_script_id),
      .rf_script_id_o(csr_rf_script_id),
      .profile_script_id_o(csr_profile_script_id),
      .frame_script_id_o(csr_frame_script_id),
      .monitor_script_id_o(csr_monitor_script_id),
      .start_script_id_o(csr_start_script_id),
      .stop_script_id_o(csr_stop_script_id),
      .busy_i(seq_busy),
      .done_i(seq_done),
      .err_code_i(seq_err_code),
      .step_id_i(seq_step_id),
      .last_opcode_i(seq_last_opcode),
      .irq_count_i(status_irq_count),
      .fault_count_i(status_fault_count)
  );

  awr2243_cfg_sequencer #(
      .SCRIPT_ID_W(SCRIPT_ID_W),
      .ERR_CODE_W(CTRL_ERR_CODE_W),
      .STEP_ID_W(STEP_ID_W),
      .OPCODE_W(OPCODE_W),
      .TIMEOUT_W(TIMER_VALUE_W),
      .NULL_SCRIPT_ID({SCRIPT_ID_W{1'b1}})
  ) u_cfg_sequencer (
      .clk_i(sys_clk),
      .rst_ni(sys_rst_n),
      .start_init_i(csr_start_init),
      .start_sensor_i(csr_start_sensor),
      .stop_sensor_i(csr_stop_sensor),
      .hard_reset_i(csr_hard_reset),
      .clear_error_i(csr_clear_error),
      .init_script_id_i(csr_init_script_id),
      .rf_script_id_i(csr_rf_script_id),
      .profile_script_id_i(csr_profile_script_id),
      .frame_script_id_i(csr_frame_script_id),
      .monitor_script_id_i(csr_monitor_script_id),
      .start_script_id_i(csr_start_script_id),
      .stop_script_id_i(csr_stop_script_id),
      .req_enter_spi_mode_o(seq_req_enter_spi_mode),
      .req_hard_reset_o(seq_req_hard_reset),
      .req_recovery_reset_o(seq_req_recovery_reset),
      .script_start_o(seq_script_start),
      .script_id_o(seq_script_id),
      .reset_done_i(reset_done),
      .reset_err_i(reset_err),
      .script_done_i(fetch_script_done),
      .cmd_done_i(decode_cmd_done),
      .cmd_error_i(decode_cmd_error),
      .cmd_err_code_i(seq_cmd_err_code),
      .cmd_step_id_i(decode_step_id),
      .cmd_last_opcode_i(decode_last_opcode),
      .host_irq_sticky_i(status_host_irq_sticky),
      .fault_active_i(status_fault_active),
      .fault_sticky_i(status_fault_sticky),
      .busy_o(seq_busy),
      .done_o(seq_done),
      .err_code_o(seq_err_code),
      .state_o(seq_state),
      .active_script_o(),
      .step_id_o(seq_step_id),
      .last_opcode_o(seq_last_opcode)
  );

  awr2243_status_mon #(
      .COUNT_W(STATUS_COUNT_W)
  ) u_status_mon (
      .sys_clk(sys_clk),
      .sys_rst_n(sys_rst_n),
      .host_irq_i(host_irq_i),
      .nerror_out_i(nerror_out_i),
      .warm_reset_i(WARM_RESET_TIED_LOW),
      .arm_i(STATUS_ARM),
      .clr_irq_sticky_i(status_clr_irq_sticky),
      .clr_fault_sticky_i(status_clr_fault_sticky),
      .clr_warm_reset_sticky_i(status_clr_warm_reset_sticky),
      .host_irq_rise_o(status_host_irq_rise),
      .host_irq_sticky_o(status_host_irq_sticky),
      .fault_active_o(status_fault_active),
      .fault_sticky_o(status_fault_sticky),
      .warm_reset_rise_o(),
      .warm_reset_sticky_o(),
      .irq_count_o(status_irq_count),
      .fault_count_o(status_fault_count),
      .warm_reset_count_o(),
      .host_irq_sync_o(),
      .nerror_out_sync_o(),
      .warm_reset_sync_o()
  );

  awr2243_reset_ctrl #(
      .CLK_FREQ_HZ(CLK_FREQ_HZ),
      .TIMER_VALUE_W(TIMER_VALUE_W),
      .SOP_MODE_SPI(DEFAULT_SOP_MODE)
  ) u_reset_ctrl (
      .sys_clk(sys_clk),
      .sys_rst_n(sys_rst_n),
      .req_enter_spi_mode_i(seq_req_enter_spi_mode),
      .req_hard_reset_i(seq_req_hard_reset),
      .req_recovery_reset_i(seq_req_recovery_reset),
      .fault_active_i(status_fault_active),
      .auto_recovery_en_i(AUTO_RECOVERY_EN),
      .sop_mode_sel_i(DEFAULT_SOP_MODE),
      .reset_hold_us_i(RESET_HOLD_US),
      .post_reset_wait_us_i(POST_RESET_WAIT_US),
      .sop0_o(sop0_o),
      .sop1_o(sop1_o),
      .sop2_o(sop2_o),
      .nreset_o(nreset_o),
      .busy_o(),
      .done_o(reset_done),
      .err_o(reset_err),
      .state_o()
  );

  awr2243_script_ram #(
      .WORD_W(SCRIPT_WORD_W),
      .DEPTH(SCRIPT_DEPTH),
      .SCRIPT_COUNT(SCRIPT_COUNT),
      .ADDR_W(SCRIPT_ADDR_W),
      .SCRIPT_ID_W(SCRIPT_ID_W),
      .SCRIPT_LEN_W(SCRIPT_LEN_W)
  ) u_script_ram (
      .clk_i(sys_clk),
      .rst_ni(sys_rst_n),
      .wr_en_i(1'b0),
      .wr_addr_i('0),
      .wr_data_i('0),
      .meta_wr_en_i(1'b0),
      .meta_wr_script_id_i('0),
      .meta_wr_base_addr_i('0),
      .meta_wr_len_i('0),
      .rd_en_i(ram_rd_en),
      .rd_addr_i(ram_rd_addr),
      .rd_valid_o(ram_rd_valid),
      .rd_data_o(ram_rd_data),
      .script_id_i(ram_script_id),
      .script_base_addr_o(ram_script_base),
      .script_len_o(ram_script_len)
  );

  awr2243_cmd_fetch #(
      .WORD_W(SCRIPT_WORD_W),
      .DEPTH(SCRIPT_DEPTH),
      .SCRIPT_COUNT(SCRIPT_COUNT),
      .ADDR_W(SCRIPT_ADDR_W),
      .SCRIPT_ID_W(SCRIPT_ID_W),
      .SCRIPT_LEN_W(SCRIPT_LEN_W)
  ) u_cmd_fetch (
      .clk_i(sys_clk),
      .rst_ni(sys_rst_n),
      .start_i(seq_script_start),
      .script_id_i(seq_script_id),
      .advance_i(decode_fetch_advance),
      .hold_i(decode_fetch_hold),
      .jump_en_i(decode_jump_en),
      .jump_addr_i(decode_jump_addr),
      .ram_rd_en_o(ram_rd_en),
      .ram_rd_addr_o(ram_rd_addr),
      .ram_rd_valid_i(ram_rd_valid),
      .ram_rd_data_i(ram_rd_data),
      .ram_script_id_o(ram_script_id),
      .ram_script_base_i(ram_script_base),
      .ram_script_len_i(ram_script_len),
      .cmd_valid_o(fetch_cmd_valid),
      .cmd_word_o(fetch_cmd_word),
      .pc_o(fetch_pc),
      .script_done_o(fetch_script_done),
      .busy_o(),
      .state_o()
  );

  awr2243_cmd_decode #(
      .WORD_W(SCRIPT_WORD_W),
      .PC_W(SCRIPT_ADDR_W),
      .STEP_ID_W(STEP_ID_W),
      .ERR_CODE_W(CMD_ERR_CODE_W),
      .TIMER_VALUE_W(TIMER_VALUE_W),
      .TIMER_UNIT_W(TIMER_UNIT_W)
  ) u_cmd_decode (
      .clk_i(sys_clk),
      .rst_ni(sys_rst_n),
      .cmd_valid_i(fetch_cmd_valid),
      .cmd_word_i(fetch_cmd_word),
      .pc_i(fetch_pc),
      .fetch_advance_o(decode_fetch_advance),
      .fetch_hold_o(decode_fetch_hold),
      .jump_en_o(decode_jump_en),
      .jump_addr_o(decode_jump_addr),
      .cmd_done_o(decode_cmd_done),
      .cmd_error_o(decode_cmd_error),
      .error_code_o(decode_err_code),
      .step_id_o(decode_step_id),
      .last_opcode_o(decode_last_opcode),
      .busy_o(),
      .state_o(),
      .spi_cmd_valid_o(decode_spi_cmd_valid),
      .spi_cmd_ready_i(decode_spi_cmd_ready),
      .spi_cmd_is_read_o(decode_spi_cmd_is_read),
      .spi_cmd_word_o(decode_spi_cmd_word),
      .spi_rsp_valid_i(spi_rsp_valid),
      .spi_rsp_word_i(spi_rsp_word),
      .spi_busy_i(spi_busy),
      .spi_done_i(spi_done),
      .spi_timeout_i(spi_timeout),
      .timer_start_o(decode_timer_start),
      .timer_clear_o(decode_timer_clear),
      .timer_period_value_o(decode_timer_period_value),
      .timer_period_unit_o(decode_timer_period_unit),
      .timer_busy_i(cmd_timer_busy),
      .timer_done_i(cmd_timer_done),
      .timer_expired_i(cmd_timer_expired),
      .clr_irq_sticky_o(decode_clr_irq_sticky),
      .clr_fault_sticky_o(decode_clr_fault_sticky),
      .host_irq_rise_i(status_host_irq_rise),
      .host_irq_sticky_i(status_host_irq_sticky),
      .fault_active_i(status_fault_active),
      .fault_sticky_i(status_fault_sticky)
  );

  awr2243_timer #(
      .CLK_FREQ_HZ(CLK_FREQ_HZ),
      .PERIOD_VALUE_W(TIMER_VALUE_W)
  ) u_cmd_timer (
      .clk_i(sys_clk),
      .rst_ni(sys_rst_n),
      .start_i(decode_timer_start),
      .clear_i(decode_timer_clear),
      .period_value_i(decode_timer_period_value),
      .period_unit_i(decode_timer_period_unit[0]),
      .busy_o(cmd_timer_busy),
      .done_o(cmd_timer_done),
      .expired_o(cmd_timer_expired),
      .count_dbg_o()
  );

  spi_master_engine #(
      .SPI_CLK_DIV(SPI_CLK_DIV),
      .CS_SETUP_CYCLES(SPI_CS_SETUP_CYCLES),
      .CS_HOLD_CYCLES(SPI_CS_HOLD_CYCLES),
      .TIMEOUT_CYCLES(SPI_TIMEOUT_CYCLES)
  ) u_spi_master (
      .sys_clk(sys_clk),
      .sys_rst_n(sys_rst_n),
      .cmd_valid_i(decode_spi_cmd_valid),
      .cmd_ready_o(decode_spi_cmd_ready),
      .cmd_is_read_i(decode_spi_cmd_is_read),
      .cmd_word_i(decode_spi_cmd_word),
      .rsp_valid_o(spi_rsp_valid),
      .rsp_word_o(spi_rsp_word),
      .busy_o(spi_busy),
      .done_o(spi_done),
      .timeout_o(spi_timeout),
      .spi_sclk_o(spi_sclk_o),
      .spi_cs_n_o(spi_cs_n_o),
      .spi_mosi_o(spi_mosi_o),
      .spi_miso_i(spi_miso_i)
  );

  assign ctrl_busy_o = seq_busy;
  assign ctrl_done_o = seq_done;
  assign ctrl_err_code_o = seq_err_code;
  assign ctrl_state_o = seq_state;

endmodule
