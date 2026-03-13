`include "awr2243_script_macros.svh"

module awr2243_ctrl_top #(
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
    input  logic                       sys_clk,
    input  logic                       sys_rst_n,
    axi4_lite_if.slave                 s_axil,
    output logic                       spi_sclk_o,
    output logic                       spi_cs_n_o,
    output logic                       spi_mosi_o,
    input  logic                       spi_miso_i,
    output logic                       sop0_o,
    output logic                       sop1_o,
    output logic                       sop2_o,
    output logic                       nreset_o,
    input  logic                       host_irq_i,
    input  logic                       nerror_out_i,
    output logic                       ctrl_busy_o,
    output logic                       ctrl_done_o,
    output logic [CTRL_ERR_CODE_W-1:0] ctrl_err_code_o,
    output logic [                3:0] ctrl_state_o
);

  localparam logic WARM_RESET_TIED_LOW = 1'b0;

  import awr2243_control_csr_pkg::*;
  awr2243_control_csr__in_t  hwif_in;
  awr2243_control_csr__out_t hwif_out;

  logic                       csr_start_init;
  logic                       csr_start_sensor;
  logic                       csr_stop_sensor;
  logic                       csr_hard_reset;
  logic                       csr_clear_error;
  logic [    SCRIPT_ID_W-1:0] csr_init_script_id;
  logic [    SCRIPT_ID_W-1:0] csr_rf_script_id;
  logic [    SCRIPT_ID_W-1:0] csr_profile_script_id;
  logic [    SCRIPT_ID_W-1:0] csr_frame_script_id;
  logic [    SCRIPT_ID_W-1:0] csr_monitor_script_id;
  logic [    SCRIPT_ID_W-1:0] csr_start_script_id;
  logic [    SCRIPT_ID_W-1:0] csr_stop_script_id;

  logic                       seq_req_enter_spi_mode;
  logic                       seq_req_hard_reset;
  logic                       seq_req_recovery_reset;
  logic                       seq_script_start;
  logic [    SCRIPT_ID_W-1:0] seq_script_id;
  logic                       seq_busy;
  logic                       seq_done;
  logic [CTRL_ERR_CODE_W-1:0] seq_err_code;
  logic [                3:0] seq_state;
  logic [      STEP_ID_W-1:0] seq_step_id;
  logic [       OPCODE_W-1:0] seq_last_opcode;

  logic                       status_host_irq_rise;
  logic                       status_host_irq_sticky;
  logic                       status_fault_active;
  logic                       status_fault_sticky;
  logic [ STATUS_COUNT_W-1:0] status_irq_count;
  logic [ STATUS_COUNT_W-1:0] status_fault_count;
  logic                       status_clr_irq_sticky;
  logic                       status_clr_fault_sticky;
  logic                       status_clr_warm_reset_sticky;
  logic                       status_clear_any;

  logic                       reset_done;
  logic                       reset_err;

  logic                       ram_rd_en;
  logic [  SCRIPT_ADDR_W-1:0] ram_rd_addr;
  logic                       ram_rd_valid;
  logic [  SCRIPT_WORD_W-1:0] ram_rd_data;
  logic [    SCRIPT_ID_W-1:0] ram_script_id;
  logic [  SCRIPT_ADDR_W-1:0] ram_script_base;
  logic [   SCRIPT_LEN_W-1:0] ram_script_len;

  logic                       fetch_cmd_valid;
  logic [  SCRIPT_WORD_W-1:0] fetch_cmd_word;
  logic [  SCRIPT_ADDR_W-1:0] fetch_pc;
  logic                       fetch_script_done;

  logic                       decode_fetch_advance;
  logic                       decode_fetch_hold;
  logic                       decode_jump_en;
  logic [  SCRIPT_ADDR_W-1:0] decode_jump_addr;
  logic                       decode_cmd_done;
  logic                       decode_cmd_error;
  logic [ CMD_ERR_CODE_W-1:0] decode_err_code;
  logic [CTRL_ERR_CODE_W-1:0] seq_cmd_err_code;
  logic [      STEP_ID_W-1:0] decode_step_id;
  logic [       OPCODE_W-1:0] decode_last_opcode;
  logic                       decode_spi_cmd_valid;
  logic                       decode_spi_cmd_ready;
  logic                       decode_spi_cmd_is_read;
  logic [               15:0] decode_spi_cmd_word;
  logic                       decode_timer_start;
  logic                       decode_timer_clear;
  logic [  TIMER_VALUE_W-1:0] decode_timer_period_value;
  logic [   TIMER_UNIT_W-1:0] decode_timer_period_unit;
  logic                       decode_clr_irq_sticky;
  logic                       decode_clr_fault_sticky;

  logic                       spi_rsp_valid;
  logic [               15:0] spi_rsp_word;
  logic                       spi_busy;
  logic                       spi_done;
  logic                       spi_timeout;

  logic                       cmd_timer_busy;
  logic                       cmd_timer_done;
  logic                       cmd_timer_expired;

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

  // Control pulses and script IDs from RDL-generated CSR (hwif_out)
  assign csr_start_init   = hwif_out.CONTROL.start_init.value;
  assign csr_start_sensor = hwif_out.CONTROL.start_sensor.value;
  assign csr_stop_sensor  = hwif_out.CONTROL.stop_sensor.value;
  assign csr_hard_reset   = hwif_out.CONTROL.hard_reset.value;
  assign csr_clear_error  = hwif_out.CONTROL.clear_error.value;
  assign csr_init_script_id    = hwif_out.INIT_SCRIPT_ID.init_script_id.value[SCRIPT_ID_W-1:0];
  assign csr_rf_script_id      = hwif_out.RF_SCRIPT_ID.rf_script_id.value[SCRIPT_ID_W-1:0];
  assign csr_profile_script_id = hwif_out.PROFILE_SCRIPT_ID.profile_script_id.value[SCRIPT_ID_W-1:0];
  assign csr_frame_script_id   = hwif_out.FRAME_SCRIPT_ID.frame_script_id.value[SCRIPT_ID_W-1:0];
  assign csr_monitor_script_id = hwif_out.MONITOR_SCRIPT_ID.monitor_script_id.value[SCRIPT_ID_W-1:0];
  assign csr_start_script_id   = hwif_out.START_SCRIPT_ID.start_script_id.value[SCRIPT_ID_W-1:0];
  assign csr_stop_script_id    = hwif_out.STOP_SCRIPT_ID.stop_script_id.value[SCRIPT_ID_W-1:0];

  assign status_ack_pulse_c   = csr_start_init || csr_start_sensor || csr_stop_sensor || csr_hard_reset;
  assign sticky_clear_pulse_c = csr_clear_error || csr_hard_reset;
  assign status_clear_any = csr_clear_error || csr_hard_reset || csr_start_init;
  assign status_clr_irq_sticky = decode_clr_irq_sticky || status_clear_any || csr_start_sensor;
  assign status_clr_fault_sticky = decode_clr_fault_sticky || status_clear_any;
  assign status_clr_warm_reset_sticky = status_clear_any;

  // Sticky/snapshot state (was inside csr_reg_block; now drives hwif_in)
  logic                   done_sticky_r;
  logic                   err_sticky_r;
  logic                   irq_seen_sticky_r;
  logic                   fault_seen_sticky_r;
  logic [CTRL_ERR_CODE_W-1:0] err_code_sticky_r;
  logic [  STEP_ID_W-1:0] step_id_snapshot_r;
  logic [   OPCODE_W-1:0] last_opcode_snapshot_r;
  logic [ STATUS_COUNT_W-1:0] irq_count_seen_r;
  logic [ STATUS_COUNT_W-1:0] fault_count_seen_r;
  logic                   done_event_c;
  logic                   irq_event_c;
  logic                   fault_event_c;
  logic                   err_event_c;
  logic                   snapshot_update_c;

  assign done_event_c = seq_done && !(status_ack_pulse_c || sticky_clear_pulse_c);
  assign irq_event_c  = !sticky_clear_pulse_c && (status_irq_count != irq_count_seen_r);
  assign fault_event_c = !sticky_clear_pulse_c && (status_fault_count != fault_count_seen_r);
  assign err_event_c  = (seq_err_code != '0);
  assign snapshot_update_c = done_event_c || err_event_c;

  always_ff @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
      err_code_sticky_r   <= '0;
      step_id_snapshot_r  <= '0;
      last_opcode_snapshot_r <= '0;
      irq_count_seen_r    <= '0;
      fault_count_seen_r  <= '0;
      done_sticky_r       <= 1'b0;
      err_sticky_r        <= 1'b0;
      irq_seen_sticky_r   <= 1'b0;
      fault_seen_sticky_r <= 1'b0;
    end else begin
      if (status_ack_pulse_c || sticky_clear_pulse_c) begin
        done_sticky_r          <= 1'b0;
        step_id_snapshot_r     <= '0;
        last_opcode_snapshot_r <= '0;
      end
      if (sticky_clear_pulse_c) begin
        err_code_sticky_r   <= '0;
        err_sticky_r        <= 1'b0;
        irq_seen_sticky_r   <= 1'b0;
        fault_seen_sticky_r <= 1'b0;
        irq_count_seen_r    <= status_irq_count;
        fault_count_seen_r  <= status_fault_count;
      end
      if (done_event_c)
        done_sticky_r <= 1'b1;
      if (snapshot_update_c) begin
        step_id_snapshot_r     <= seq_step_id;
        last_opcode_snapshot_r <= seq_last_opcode;
      end
      if (err_event_c) begin
        err_code_sticky_r <= seq_err_code;
        err_sticky_r      <= 1'b1;
      end
      if (irq_event_c) begin
        irq_count_seen_r  <= status_irq_count;
        irq_seen_sticky_r <= 1'b1;
      end
      if (fault_event_c) begin
        fault_count_seen_r  <= status_fault_count;
        fault_seen_sticky_r <= 1'b1;
      end
    end
  end

  // hwif_in: drive readback values for status/error/step/opcode/counts
  // (No global '0 for hwif_in: Verilator cannot assign struct from integer.)
  always_comb begin
    hwif_in.STATUS.busy.next            = seq_busy;
    hwif_in.STATUS.done.next           = seq_done;
    hwif_in.STATUS.done_sticky.next     = done_sticky_r;
    hwif_in.STATUS.err_sticky.next      = err_sticky_r;
    hwif_in.STATUS.irq_seen_sticky.next = irq_seen_sticky_r;
    hwif_in.STATUS.fault_seen_sticky.next = fault_seen_sticky_r;
    hwif_in.ERR_CODE_LIVE.err_code_live.next   = seq_err_code;
    hwif_in.ERR_CODE_STICKY.err_code_sticky.next = err_code_sticky_r;
    hwif_in.STEP_ID_LIVE.step_id_live.next     = seq_step_id;
    hwif_in.STEP_ID_SNAPSHOT.step_id_snapshot.next = step_id_snapshot_r;
    hwif_in.LAST_OPCODE_LIVE.last_opcode_live.next = seq_last_opcode;
    hwif_in.LAST_OPCODE_SNAP.last_opcode_snap.next = last_opcode_snapshot_r;
    hwif_in.IRQ_COUNT.irq_count.next   = status_irq_count;
    hwif_in.FAULT_COUNT.fault_count.next = status_fault_count;
    // RDL hw=rw registers: drive .next from .value so non-SW cycles do not overwrite
    hwif_in.INIT_SCRIPT_ID.init_script_id.next    = hwif_out.INIT_SCRIPT_ID.init_script_id.value;
    hwif_in.RF_SCRIPT_ID.rf_script_id.next        = hwif_out.RF_SCRIPT_ID.rf_script_id.value;
    hwif_in.PROFILE_SCRIPT_ID.profile_script_id.next = hwif_out.PROFILE_SCRIPT_ID.profile_script_id.value;
    hwif_in.FRAME_SCRIPT_ID.frame_script_id.next  = hwif_out.FRAME_SCRIPT_ID.frame_script_id.value;
    hwif_in.MONITOR_SCRIPT_ID.monitor_script_id.next = hwif_out.MONITOR_SCRIPT_ID.monitor_script_id.value;
    hwif_in.START_SCRIPT_ID.start_script_id.next = hwif_out.START_SCRIPT_ID.start_script_id.value;
    hwif_in.STOP_SCRIPT_ID.stop_script_id.next    = hwif_out.STOP_SCRIPT_ID.stop_script_id.value;
    hwif_in.SCRATCH.scratch.next                  = hwif_out.SCRATCH.scratch.value;
  end

  awr2243_control_csr u_csr (
      .clk           (sys_clk),
      .arst_n        (sys_rst_n),
      .s_axil_awready(s_axil.awready),
      .s_axil_awvalid(s_axil.awvalid),
      .s_axil_awaddr (s_axil.awaddr[6:0]),
      .s_axil_awprot (s_axil.awprot),
      .s_axil_wready (s_axil.wready),
      .s_axil_wvalid (s_axil.wvalid),
      .s_axil_wdata  (s_axil.wdata),
      .s_axil_wstrb  (s_axil.wstrb),
      .s_axil_bready (s_axil.bready),
      .s_axil_bvalid (s_axil.bvalid),
      .s_axil_bresp  (s_axil.bresp),
      .s_axil_arready(s_axil.arready),
      .s_axil_arvalid(s_axil.arvalid),
      .s_axil_araddr (s_axil.araddr[6:0]),
      .s_axil_arprot (s_axil.arprot),
      .s_axil_rready (s_axil.rready),
      .s_axil_rvalid (s_axil.rvalid),
      .s_axil_rdata  (s_axil.rdata),
      .s_axil_rresp  (s_axil.rresp),
      .hwif_in       (hwif_in),
      .hwif_out      (hwif_out)
  );

  // awr2243_cmd_decode emits a 2-bit timer unit, but the shared timer only consumes
  // the established cycle/us LSB encoding today.
  assign seq_cmd_err_code = CTRL_ERR_CODE_W'(decode_err_code);

  awr2243_cfg_sequencer #(
      .SCRIPT_ID_W   (SCRIPT_ID_W),
      .ERR_CODE_W    (CTRL_ERR_CODE_W),
      .STEP_ID_W     (STEP_ID_W),
      .OPCODE_W      (OPCODE_W),
      .TIMEOUT_W     (TIMER_VALUE_W),
      .NULL_SCRIPT_ID({SCRIPT_ID_W{1'b1}})
  ) u_cfg_sequencer (
      .clk_i               (sys_clk),
      .rst_ni              (sys_rst_n),
      .start_init_i        (csr_start_init),
      .start_sensor_i      (csr_start_sensor),
      .stop_sensor_i       (csr_stop_sensor),
      .hard_reset_i        (csr_hard_reset),
      .clear_error_i       (csr_clear_error),
      .init_script_id_i    (csr_init_script_id),
      .rf_script_id_i      (csr_rf_script_id),
      .profile_script_id_i (csr_profile_script_id),
      .frame_script_id_i   (csr_frame_script_id),
      .monitor_script_id_i (csr_monitor_script_id),
      .start_script_id_i   (csr_start_script_id),
      .stop_script_id_i    (csr_stop_script_id),
      .req_enter_spi_mode_o(seq_req_enter_spi_mode),
      .req_hard_reset_o    (seq_req_hard_reset),
      .req_recovery_reset_o(seq_req_recovery_reset),
      .script_start_o      (seq_script_start),
      .script_id_o         (seq_script_id),
      .reset_done_i        (reset_done),
      .reset_err_i         (reset_err),
      .script_done_i       (fetch_script_done),
      .cmd_done_i          (decode_cmd_done),
      .cmd_error_i         (decode_cmd_error),
      .cmd_err_code_i      (seq_cmd_err_code),
      .cmd_step_id_i       (decode_step_id),
      .cmd_last_opcode_i   (decode_last_opcode),
      .host_irq_sticky_i   (status_host_irq_sticky),
      .fault_active_i      (status_fault_active),
      .fault_sticky_i      (status_fault_sticky),
      .busy_o              (seq_busy),
      .done_o              (seq_done),
      .err_code_o          (seq_err_code),
      .state_o             (seq_state),
      .active_script_o     (),
      .step_id_o           (seq_step_id),
      .last_opcode_o       (seq_last_opcode)
  );

  awr2243_status_mon #(
      .COUNT_W(STATUS_COUNT_W)
  ) u_status_mon (
      .sys_clk                (sys_clk),
      .sys_rst_n              (sys_rst_n),
      .host_irq_i             (host_irq_i),
      .nerror_out_i           (nerror_out_i),
      .warm_reset_i           (WARM_RESET_TIED_LOW),
      .arm_i                  (STATUS_ARM),
      .clr_irq_sticky_i       (status_clr_irq_sticky),
      .clr_fault_sticky_i     (status_clr_fault_sticky),
      .clr_warm_reset_sticky_i(status_clr_warm_reset_sticky),
      .host_irq_rise_o        (status_host_irq_rise),
      .host_irq_sticky_o      (status_host_irq_sticky),
      .fault_active_o         (status_fault_active),
      .fault_sticky_o         (status_fault_sticky),
      .warm_reset_rise_o      (),
      .warm_reset_sticky_o    (),
      .irq_count_o            (status_irq_count),
      .fault_count_o          (status_fault_count),
      .warm_reset_count_o     (),
      .host_irq_sync_o        (),
      .nerror_out_sync_o      (),
      .warm_reset_sync_o      ()
  );

  awr2243_reset_ctrl #(
      .CLK_FREQ_HZ  (CLK_FREQ_HZ),
      .TIMER_VALUE_W(TIMER_VALUE_W),
      .SOP_MODE_SPI (DEFAULT_SOP_MODE)
  ) u_reset_ctrl (
      .sys_clk             (sys_clk),
      .sys_rst_n           (sys_rst_n),
      .req_enter_spi_mode_i(seq_req_enter_spi_mode),
      .req_hard_reset_i    (seq_req_hard_reset),
      .req_recovery_reset_i(seq_req_recovery_reset),
      .fault_active_i      (status_fault_active),
      .auto_recovery_en_i  (AUTO_RECOVERY_EN),
      .sop_mode_sel_i      (DEFAULT_SOP_MODE),
      .reset_hold_us_i     (RESET_HOLD_US),
      .post_reset_wait_us_i(POST_RESET_WAIT_US),
      .sop0_o              (sop0_o),
      .sop1_o              (sop1_o),
      .sop2_o              (sop2_o),
      .nreset_o            (nreset_o),
      .busy_o              (),
      .done_o              (reset_done),
      .err_o               (reset_err),
      .state_o             ()
  );

  awr2243_script_ram #(
      .WORD_W      (SCRIPT_WORD_W),
      .DEPTH       (SCRIPT_DEPTH),
      .SCRIPT_COUNT(SCRIPT_COUNT),
      .ADDR_W      (SCRIPT_ADDR_W),
      .SCRIPT_ID_W (SCRIPT_ID_W),
      .SCRIPT_LEN_W(SCRIPT_LEN_W)
  ) u_script_ram (
      .clk_i              (sys_clk),
      .rst_ni             (sys_rst_n),
      .wr_en_i            (1'b0),
      .wr_addr_i          ('0),
      .wr_data_i          ('0),
      .meta_wr_en_i       (1'b0),
      .meta_wr_script_id_i('0),
      .meta_wr_base_addr_i('0),
      .meta_wr_len_i      ('0),
      .rd_en_i            (ram_rd_en),
      .rd_addr_i          (ram_rd_addr),
      .rd_valid_o         (ram_rd_valid),
      .rd_data_o          (ram_rd_data),
      .script_id_i        (ram_script_id),
      .script_base_addr_o (ram_script_base),
      .script_len_o       (ram_script_len)
  );

  awr2243_cmd_fetch #(
      .WORD_W      (SCRIPT_WORD_W),
      .DEPTH       (SCRIPT_DEPTH),
      .SCRIPT_COUNT(SCRIPT_COUNT),
      .ADDR_W      (SCRIPT_ADDR_W),
      .SCRIPT_ID_W (SCRIPT_ID_W),
      .SCRIPT_LEN_W(SCRIPT_LEN_W)
  ) u_cmd_fetch (
      .clk_i            (sys_clk),
      .rst_ni           (sys_rst_n),
      .start_i          (seq_script_start),
      .script_id_i      (seq_script_id),
      .advance_i        (decode_fetch_advance),
      .hold_i           (decode_fetch_hold),
      .jump_en_i        (decode_jump_en),
      .jump_addr_i      (decode_jump_addr),
      .ram_rd_en_o      (ram_rd_en),
      .ram_rd_addr_o    (ram_rd_addr),
      .ram_rd_valid_i   (ram_rd_valid),
      .ram_rd_data_i    (ram_rd_data),
      .ram_script_id_o  (ram_script_id),
      .ram_script_base_i(ram_script_base),
      .ram_script_len_i (ram_script_len),
      .cmd_valid_o      (fetch_cmd_valid),
      .cmd_word_o       (fetch_cmd_word),
      .pc_o             (fetch_pc),
      .script_done_o    (fetch_script_done),
      .busy_o           (),
      .state_o          ()
  );

  awr2243_cmd_decode #(
      .WORD_W       (SCRIPT_WORD_W),
      .PC_W         (SCRIPT_ADDR_W),
      .STEP_ID_W    (STEP_ID_W),
      .ERR_CODE_W   (CMD_ERR_CODE_W),
      .TIMER_VALUE_W(TIMER_VALUE_W),
      .TIMER_UNIT_W (TIMER_UNIT_W)
  ) u_cmd_decode (
      .clk_i               (sys_clk),
      .rst_ni              (sys_rst_n),
      .cmd_valid_i         (fetch_cmd_valid),
      .cmd_word_i          (fetch_cmd_word),
      .pc_i                (fetch_pc),
      .fetch_advance_o     (decode_fetch_advance),
      .fetch_hold_o        (decode_fetch_hold),
      .jump_en_o           (decode_jump_en),
      .jump_addr_o         (decode_jump_addr),
      .cmd_done_o          (decode_cmd_done),
      .cmd_error_o         (decode_cmd_error),
      .error_code_o        (decode_err_code),
      .step_id_o           (decode_step_id),
      .last_opcode_o       (decode_last_opcode),
      .busy_o              (),
      .state_o             (),
      .spi_cmd_valid_o     (decode_spi_cmd_valid),
      .spi_cmd_ready_i     (decode_spi_cmd_ready),
      .spi_cmd_is_read_o   (decode_spi_cmd_is_read),
      .spi_cmd_word_o      (decode_spi_cmd_word),
      .spi_rsp_valid_i     (spi_rsp_valid),
      .spi_rsp_word_i      (spi_rsp_word),
      .spi_busy_i          (spi_busy),
      .spi_done_i          (spi_done),
      .spi_timeout_i       (spi_timeout),
      .timer_start_o       (decode_timer_start),
      .timer_clear_o       (decode_timer_clear),
      .timer_period_value_o(decode_timer_period_value),
      .timer_period_unit_o (decode_timer_period_unit),
      .timer_busy_i        (cmd_timer_busy),
      .timer_done_i        (cmd_timer_done),
      .timer_expired_i     (cmd_timer_expired),
      .clr_irq_sticky_o    (decode_clr_irq_sticky),
      .clr_fault_sticky_o  (decode_clr_fault_sticky),
      .host_irq_rise_i     (status_host_irq_rise),
      .host_irq_sticky_i   (status_host_irq_sticky),
      .fault_active_i      (status_fault_active),
      .fault_sticky_i      (status_fault_sticky)
  );

  awr2243_timer #(
      .CLK_FREQ_HZ   (CLK_FREQ_HZ),
      .PERIOD_VALUE_W(TIMER_VALUE_W)
  ) u_cmd_timer (
      .clk_i         (sys_clk),
      .rst_ni        (sys_rst_n),
      .start_i       (decode_timer_start),
      .clear_i       (decode_timer_clear),
      .period_value_i(decode_timer_period_value),
      .period_unit_i (decode_timer_period_unit[0]),
      .busy_o        (cmd_timer_busy),
      .done_o        (cmd_timer_done),
      .expired_o     (cmd_timer_expired),
      .count_dbg_o   ()
  );

  spi_master_engine #(
      .SPI_CLK_DIV    (SPI_CLK_DIV),
      .CS_SETUP_CYCLES(SPI_CS_SETUP_CYCLES),
      .CS_HOLD_CYCLES (SPI_CS_HOLD_CYCLES),
      .TIMEOUT_CYCLES (SPI_TIMEOUT_CYCLES)
  ) u_spi_master (
      .sys_clk      (sys_clk),
      .sys_rst_n    (sys_rst_n),
      .cmd_valid_i  (decode_spi_cmd_valid),
      .cmd_ready_o  (decode_spi_cmd_ready),
      .cmd_is_read_i(decode_spi_cmd_is_read),
      .cmd_word_i   (decode_spi_cmd_word),
      .rsp_valid_o  (spi_rsp_valid),
      .rsp_word_o   (spi_rsp_word),
      .busy_o       (spi_busy),
      .done_o       (spi_done),
      .timeout_o    (spi_timeout),
      .spi_sclk_o   (spi_sclk_o),
      .spi_cs_n_o   (spi_cs_n_o),
      .spi_mosi_o   (spi_mosi_o),
      .spi_miso_i   (spi_miso_i)
  );

  assign ctrl_busy_o     = seq_busy;
  assign ctrl_done_o     = seq_done;
  assign ctrl_err_code_o = seq_err_code;
  assign ctrl_state_o    = seq_state;

endmodule
