// Local CSR register block for the AWR2243 configuration control path.
module csr_reg_block #(
    parameter int unsigned                   CSR_ADDR_W             = 8,
    parameter int unsigned                   CSR_DATA_W             = 32,
    parameter int unsigned                   SCRIPT_ID_W            = 8,
    parameter int unsigned                   ERR_CODE_W             = 16,
    parameter int unsigned                   STEP_ID_W              = 8,
    parameter int unsigned                   OPCODE_W               = 16,
    parameter int unsigned                   COUNT_W                = 16,
    parameter logic        [SCRIPT_ID_W-1:0] INIT_SCRIPT_ID_DFLT    = 'd0,
    parameter logic        [SCRIPT_ID_W-1:0] RF_SCRIPT_ID_DFLT      = 'd1,
    parameter logic        [SCRIPT_ID_W-1:0] PROFILE_SCRIPT_ID_DFLT = 'd2,
    parameter logic        [SCRIPT_ID_W-1:0] FRAME_SCRIPT_ID_DFLT   = 'd3,
    parameter logic        [SCRIPT_ID_W-1:0] MONITOR_SCRIPT_ID_DFLT = 'd4,
    parameter logic        [SCRIPT_ID_W-1:0] START_SCRIPT_ID_DFLT   = 'd5,
    parameter logic        [SCRIPT_ID_W-1:0] STOP_SCRIPT_ID_DFLT    = 'd6
) (
    input  logic                   sys_clk,
    input  logic                   sys_rst_n,
    input  logic                   csr_wr_en_i,
    input  logic                   csr_rd_en_i,
    input  logic [ CSR_ADDR_W-1:0] csr_addr_i,
    input  logic [ CSR_DATA_W-1:0] csr_wdata_i,
    output logic [ CSR_DATA_W-1:0] csr_rdata_o,
    output logic                   start_init_o,
    output logic                   start_sensor_o,
    output logic                   stop_sensor_o,
    output logic                   hard_reset_o,
    output logic                   clear_error_o,
    output logic [SCRIPT_ID_W-1:0] init_script_id_o,
    output logic [SCRIPT_ID_W-1:0] rf_script_id_o,
    output logic [SCRIPT_ID_W-1:0] profile_script_id_o,
    output logic [SCRIPT_ID_W-1:0] frame_script_id_o,
    output logic [SCRIPT_ID_W-1:0] monitor_script_id_o,
    output logic [SCRIPT_ID_W-1:0] start_script_id_o,
    output logic [SCRIPT_ID_W-1:0] stop_script_id_o,
    input  logic                   busy_i,
    input  logic                   done_i,
    input  logic [ ERR_CODE_W-1:0] err_code_i,
    input  logic [  STEP_ID_W-1:0] step_id_i,
    input  logic [   OPCODE_W-1:0] last_opcode_i,
    input  logic [    COUNT_W-1:0] irq_count_i,
    input  logic [    COUNT_W-1:0] fault_count_i
);

  localparam logic [CSR_ADDR_W-1:0] ADDR_VERSION = 'h00;
  localparam logic [CSR_ADDR_W-1:0] ADDR_CONTROL = 'h04;
  localparam logic [CSR_ADDR_W-1:0] ADDR_STATUS = 'h08;
  localparam logic [CSR_ADDR_W-1:0] ADDR_ERR_CODE_LIVE = 'h0c;
  localparam logic [CSR_ADDR_W-1:0] ADDR_ERR_CODE_STICKY = 'h10;
  localparam logic [CSR_ADDR_W-1:0] ADDR_STEP_ID_LIVE = 'h14;
  localparam logic [CSR_ADDR_W-1:0] ADDR_STEP_ID_SNAPSHOT = 'h18;
  localparam logic [CSR_ADDR_W-1:0] ADDR_LAST_OPCODE_LIVE = 'h1c;
  localparam logic [CSR_ADDR_W-1:0] ADDR_LAST_OPCODE_SNAP = 'h20;
  localparam logic [CSR_ADDR_W-1:0] ADDR_IRQ_COUNT = 'h24;
  localparam logic [CSR_ADDR_W-1:0] ADDR_FAULT_COUNT = 'h28;
  localparam logic [CSR_ADDR_W-1:0] ADDR_INIT_SCRIPT_ID = 'h2c;
  localparam logic [CSR_ADDR_W-1:0] ADDR_RF_SCRIPT_ID = 'h30;
  localparam logic [CSR_ADDR_W-1:0] ADDR_PROFILE_SCRIPT_ID = 'h34;
  localparam logic [CSR_ADDR_W-1:0] ADDR_FRAME_SCRIPT_ID = 'h38;
  localparam logic [CSR_ADDR_W-1:0] ADDR_MONITOR_SCRIPT_ID = 'h3c;
  localparam logic [CSR_ADDR_W-1:0] ADDR_START_SCRIPT_ID = 'h40;
  localparam logic [CSR_ADDR_W-1:0] ADDR_STOP_SCRIPT_ID = 'h44;
  localparam logic [CSR_ADDR_W-1:0] ADDR_SCRATCH = 'h48;

  localparam int unsigned CTRL_START_INIT_BIT = 0;
  localparam int unsigned CTRL_START_SENSOR_BIT = 1;
  localparam int unsigned CTRL_STOP_SENSOR_BIT = 2;
  localparam int unsigned CTRL_HARD_RESET_BIT = 3;
  localparam int unsigned CTRL_CLEAR_ERROR_BIT = 4;

  logic [SCRIPT_ID_W-1:0] init_script_id_r;
  logic [SCRIPT_ID_W-1:0] rf_script_id_r;
  logic [SCRIPT_ID_W-1:0] profile_script_id_r;
  logic [SCRIPT_ID_W-1:0] frame_script_id_r;
  logic [SCRIPT_ID_W-1:0] monitor_script_id_r;
  logic [SCRIPT_ID_W-1:0] start_script_id_r;
  logic [SCRIPT_ID_W-1:0] stop_script_id_r;
  logic [ CSR_DATA_W-1:0] scratch_r;

  logic [ ERR_CODE_W-1:0] err_code_sticky_r;
  logic [  STEP_ID_W-1:0] step_id_snapshot_r;
  logic [   OPCODE_W-1:0] last_opcode_snapshot_r;
  logic [    COUNT_W-1:0] irq_count_seen_r;
  logic [    COUNT_W-1:0] fault_count_seen_r;
  logic                   done_sticky_r;
  logic                   err_sticky_r;
  logic                   irq_seen_sticky_r;
  logic                   fault_seen_sticky_r;

  logic                   control_wr_hit;
  logic                   start_init_pulse_c;
  logic                   start_sensor_pulse_c;
  logic                   stop_sensor_pulse_c;
  logic                   hard_reset_pulse_c;
  logic                   clear_error_pulse_c;
  logic                   status_ack_pulse_c;
  logic                   sticky_clear_pulse_c;
  logic                   done_event_c;
  logic                   irq_event_c;
  logic                   fault_event_c;
  logic                   err_event_c;
  logic                   snapshot_update_c;

  assign control_wr_hit = csr_wr_en_i && (csr_addr_i == ADDR_CONTROL);
  assign start_init_pulse_c = control_wr_hit && csr_wdata_i[CTRL_START_INIT_BIT];
  assign start_sensor_pulse_c = control_wr_hit && csr_wdata_i[CTRL_START_SENSOR_BIT];
  assign stop_sensor_pulse_c = control_wr_hit && csr_wdata_i[CTRL_STOP_SENSOR_BIT];
  assign hard_reset_pulse_c = control_wr_hit && csr_wdata_i[CTRL_HARD_RESET_BIT];
  assign clear_error_pulse_c = control_wr_hit && csr_wdata_i[CTRL_CLEAR_ERROR_BIT];

  assign status_ack_pulse_c   = start_init_pulse_c
                              || start_sensor_pulse_c
                              || stop_sensor_pulse_c
                              || hard_reset_pulse_c;
  assign sticky_clear_pulse_c = clear_error_pulse_c || hard_reset_pulse_c;
  assign done_event_c = done_i && !(status_ack_pulse_c || sticky_clear_pulse_c);
  assign irq_event_c = !sticky_clear_pulse_c && (irq_count_i != irq_count_seen_r);
  assign fault_event_c = !sticky_clear_pulse_c && (fault_count_i != fault_count_seen_r);
  assign err_event_c = (err_code_i != '0);
  assign snapshot_update_c = done_event_c || err_event_c;

  always_ff @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
      start_init_o   <= 1'b0;
      start_sensor_o <= 1'b0;
      stop_sensor_o  <= 1'b0;
      hard_reset_o   <= 1'b0;
      clear_error_o  <= 1'b0;
    end else begin
      start_init_o   <= start_init_pulse_c;
      start_sensor_o <= start_sensor_pulse_c;
      stop_sensor_o  <= stop_sensor_pulse_c;
      hard_reset_o   <= hard_reset_pulse_c;
      clear_error_o  <= clear_error_pulse_c;
    end
  end

  always_ff @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
      init_script_id_r    <= INIT_SCRIPT_ID_DFLT;
      rf_script_id_r      <= RF_SCRIPT_ID_DFLT;
      profile_script_id_r <= PROFILE_SCRIPT_ID_DFLT;
      frame_script_id_r   <= FRAME_SCRIPT_ID_DFLT;
      monitor_script_id_r <= MONITOR_SCRIPT_ID_DFLT;
      start_script_id_r   <= START_SCRIPT_ID_DFLT;
      stop_script_id_r    <= STOP_SCRIPT_ID_DFLT;
      scratch_r           <= '0;
    end else if (csr_wr_en_i) begin
      case (csr_addr_i)
        ADDR_INIT_SCRIPT_ID: begin
          init_script_id_r <= csr_wdata_i[SCRIPT_ID_W-1:0];
        end
        ADDR_RF_SCRIPT_ID: begin
          rf_script_id_r <= csr_wdata_i[SCRIPT_ID_W-1:0];
        end
        ADDR_PROFILE_SCRIPT_ID: begin
          profile_script_id_r <= csr_wdata_i[SCRIPT_ID_W-1:0];
        end
        ADDR_FRAME_SCRIPT_ID: begin
          frame_script_id_r <= csr_wdata_i[SCRIPT_ID_W-1:0];
        end
        ADDR_MONITOR_SCRIPT_ID: begin
          monitor_script_id_r <= csr_wdata_i[SCRIPT_ID_W-1:0];
        end
        ADDR_START_SCRIPT_ID: begin
          start_script_id_r <= csr_wdata_i[SCRIPT_ID_W-1:0];
        end
        ADDR_STOP_SCRIPT_ID: begin
          stop_script_id_r <= csr_wdata_i[SCRIPT_ID_W-1:0];
        end
        ADDR_SCRATCH: begin
          scratch_r <= csr_wdata_i;
        end
        default: begin
        end
      endcase
    end
  end

  always_ff @(posedge sys_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
      err_code_sticky_r      <= '0;
      step_id_snapshot_r     <= '0;
      last_opcode_snapshot_r <= '0;
      irq_count_seen_r       <= '0;
      fault_count_seen_r     <= '0;
      done_sticky_r          <= 1'b0;
      err_sticky_r           <= 1'b0;
      irq_seen_sticky_r      <= 1'b0;
      fault_seen_sticky_r    <= 1'b0;
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
        irq_count_seen_r    <= irq_count_i;
        fault_count_seen_r  <= fault_count_i;
      end

      if (done_event_c) begin
        done_sticky_r <= 1'b1;
      end

      if (snapshot_update_c) begin
        step_id_snapshot_r     <= step_id_i;
        last_opcode_snapshot_r <= last_opcode_i;
      end

      if (err_event_c) begin
        err_code_sticky_r <= err_code_i;
        err_sticky_r      <= 1'b1;
      end

      if (irq_event_c) begin
        irq_count_seen_r  <= irq_count_i;
        irq_seen_sticky_r <= 1'b1;
      end

      if (fault_event_c) begin
        fault_count_seen_r  <= fault_count_i;
        fault_seen_sticky_r <= 1'b1;
      end
    end
  end

  assign init_script_id_o    = init_script_id_r;
  assign rf_script_id_o      = rf_script_id_r;
  assign profile_script_id_o = profile_script_id_r;
  assign frame_script_id_o   = frame_script_id_r;
  assign monitor_script_id_o = monitor_script_id_r;
  assign start_script_id_o   = start_script_id_r;
  assign stop_script_id_o    = stop_script_id_r;

  always_comb begin
    csr_rdata_o = '0;

    if (csr_rd_en_i) begin
      case (csr_addr_i)
        ADDR_VERSION: begin
          csr_rdata_o = {16'h4353, 8'd1, 8'd0};
        end
        ADDR_CONTROL: begin
          csr_rdata_o[CTRL_START_INIT_BIT]   = 1'b0;
          csr_rdata_o[CTRL_START_SENSOR_BIT] = 1'b0;
          csr_rdata_o[CTRL_STOP_SENSOR_BIT]  = 1'b0;
          csr_rdata_o[CTRL_HARD_RESET_BIT]   = 1'b0;
          csr_rdata_o[CTRL_CLEAR_ERROR_BIT]  = 1'b0;
        end
        ADDR_STATUS: begin
          csr_rdata_o[0]  = busy_i;
          csr_rdata_o[1]  = done_i;
          csr_rdata_o[8]  = done_sticky_r;
          csr_rdata_o[9]  = err_sticky_r;
          csr_rdata_o[10] = irq_seen_sticky_r;
          csr_rdata_o[11] = fault_seen_sticky_r;
        end
        ADDR_ERR_CODE_LIVE: begin
          csr_rdata_o[ERR_CODE_W-1:0] = err_code_i;
        end
        ADDR_ERR_CODE_STICKY: begin
          csr_rdata_o[ERR_CODE_W-1:0] = err_code_sticky_r;
        end
        ADDR_STEP_ID_LIVE: begin
          csr_rdata_o[STEP_ID_W-1:0] = step_id_i;
        end
        ADDR_STEP_ID_SNAPSHOT: begin
          csr_rdata_o[STEP_ID_W-1:0] = step_id_snapshot_r;
        end
        ADDR_LAST_OPCODE_LIVE: begin
          csr_rdata_o[OPCODE_W-1:0] = last_opcode_i;
        end
        ADDR_LAST_OPCODE_SNAP: begin
          csr_rdata_o[OPCODE_W-1:0] = last_opcode_snapshot_r;
        end
        ADDR_IRQ_COUNT: begin
          csr_rdata_o[COUNT_W-1:0] = irq_count_i;
        end
        ADDR_FAULT_COUNT: begin
          csr_rdata_o[COUNT_W-1:0] = fault_count_i;
        end
        ADDR_INIT_SCRIPT_ID: begin
          csr_rdata_o[SCRIPT_ID_W-1:0] = init_script_id_r;
        end
        ADDR_RF_SCRIPT_ID: begin
          csr_rdata_o[SCRIPT_ID_W-1:0] = rf_script_id_r;
        end
        ADDR_PROFILE_SCRIPT_ID: begin
          csr_rdata_o[SCRIPT_ID_W-1:0] = profile_script_id_r;
        end
        ADDR_FRAME_SCRIPT_ID: begin
          csr_rdata_o[SCRIPT_ID_W-1:0] = frame_script_id_r;
        end
        ADDR_MONITOR_SCRIPT_ID: begin
          csr_rdata_o[SCRIPT_ID_W-1:0] = monitor_script_id_r;
        end
        ADDR_START_SCRIPT_ID: begin
          csr_rdata_o[SCRIPT_ID_W-1:0] = start_script_id_r;
        end
        ADDR_STOP_SCRIPT_ID: begin
          csr_rdata_o[SCRIPT_ID_W-1:0] = stop_script_id_r;
        end
        ADDR_SCRATCH: begin
          csr_rdata_o = scratch_r;
        end
        default: begin
        end
      endcase
    end
  end

endmodule
