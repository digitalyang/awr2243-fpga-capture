`include "ddr_ringbuffer_macros.svh"

// BAR + DMA shell that exposes a transaction-level host RC model upstream,
// forwards BAR0 accesses into an AXI-Lite fabric window, and drives a small
// descriptor-programmed AXI write DMA path downstream.
module pcie_endpoint_dma_shell #(
    parameter int unsigned BAR_ADDR_W = pcie_dma_pkg::PCIE_BAR_ADDR_W_DFLT,
    parameter int unsigned BAR_DATA_W = pcie_dma_pkg::PCIE_BAR_DATA_W_DFLT,
    parameter int unsigned BAR_W = pcie_dma_pkg::PCIE_BAR_NUM_W_DFLT,
    parameter int unsigned RC_TAG_W = pcie_dma_pkg::PCIE_RC_TAG_W_DFLT,
    parameter int unsigned AXIL_ADDR_W = pcie_dma_pkg::PCIE_AXIL_ADDR_W_DFLT,
    parameter int unsigned AXIL_DATA_W = pcie_dma_pkg::PCIE_AXIL_DATA_W_DFLT,
    parameter int unsigned AXI_ADDR_W = pcie_dma_pkg::PCIE_DMA_AXI_ADDR_W_DFLT,
    parameter int unsigned AXI_DATA_W = pcie_dma_pkg::PCIE_DMA_AXI_DATA_W_DFLT,
    parameter int unsigned DMA_DESC_ID_W = pcie_dma_pkg::PCIE_DMA_DESC_ID_W_DFLT,
    parameter int unsigned BAR0_INTERNAL_BYTES = pcie_dma_pkg::PCIE_BAR0_INTERNAL_BYTES_DFLT,
    parameter int unsigned BAR0_FORWARD_BASE = pcie_dma_pkg::PCIE_BAR0_FORWARD_BASE_DFLT,
    parameter int unsigned MAX_DMA_BURST_LEN = pcie_dma_pkg::PCIE_DMA_MAX_BURST_LEN_DFLT
) (
    input  logic clk_i,
    input  logic rst_ni,
    pcie_rc_model_if.device host_rc,
    axi4_lite_if.master m_axil_bar0,
    axi4_mm_if.master m_axi_dma,
    output logic irq_o,
    output logic dma_busy_o,
    output logic dma_done_pulse_o,
    output logic [DMA_DESC_ID_W-1:0] dma_done_desc_id_o
);

  localparam int unsigned BAR_STRB_W = BAR_DATA_W / 8;
  localparam int unsigned AXIL_STRB_W = AXIL_DATA_W / 8;
  localparam int unsigned AXI_STRB_W = AXI_DATA_W / 8;
  localparam int unsigned AXI_BEAT_BYTES = AXI_DATA_W / 8;
  localparam int unsigned AXI_BURST_SIZE = pcie_dma_pkg::clog2_safe(AXI_BEAT_BYTES);

  localparam logic [BAR_ADDR_W-1:0] BAR0_INTERNAL_BYTES_C = BAR_ADDR_W'(BAR0_INTERNAL_BYTES);
  localparam logic [BAR_ADDR_W-1:0] BAR0_FORWARD_BASE_C   = BAR_ADDR_W'(BAR0_FORWARD_BASE);
  localparam logic [1:0] AXI_RESP_OKAY = 2'b00;

  typedef enum logic [2:0] {
    MMIO_IDLE,
    MMIO_AXIL_WRITE,
    MMIO_AXIL_WRITE_RESP,
    MMIO_AXIL_READ,
    MMIO_AXIL_READ_RESP
  } mmio_state_e;

  typedef enum logic [1:0] {
    DMA_IDLE,
    DMA_AW,
    DMA_W,
    DMA_B
  } dma_state_e;

  mmio_state_e mmio_state_r;
  dma_state_e  dma_state_r;

  logic control_enable_r;
  logic control_irq_enable_r;
  logic irq_pending_r;
  logic dma_error_r;

  logic [63:0]              shadow_axi_addr_r;
  logic [31:0]              shadow_len_bytes_r;
  logic [31:0]              shadow_pattern_seed_r;
  logic [DMA_DESC_ID_W-1:0] shadow_desc_id_r;
  logic                     shadow_irq_on_done_r;

  logic [AXI_ADDR_W-1:0]    dma_base_addr_r;
  logic [31:0]              dma_total_len_r;
  logic [31:0]              dma_pattern_seed_r;
  logic [DMA_DESC_ID_W-1:0] dma_desc_id_r;
  logic                     dma_irq_on_done_r;
  logic [31:0]              dma_bytes_sent_r;
  logic [7:0]               dma_burst_beats_r;
  logic [31:0]              dma_burst_bytes_r;
  logic [7:0]               dma_beat_index_r;

  logic [DMA_DESC_ID_W-1:0] last_completed_desc_id_r;
  logic [31:0]              last_completed_len_r;
  logic [15:0]              completed_count_r;
  logic                     dma_done_pulse_r;
  logic [DMA_DESC_ID_W-1:0] dma_done_desc_id_r;

  logic                     host_rsp_valid_r;
  logic [BAR_DATA_W-1:0]    host_rsp_data_r;
  logic [1:0]               host_rsp_status_r;
  logic [RC_TAG_W-1:0]      host_rsp_tag_r;

  logic [BAR_ADDR_W-1:0]    mmio_addr_r;
  logic [BAR_DATA_W-1:0]    mmio_wdata_r;
  logic [BAR_STRB_W-1:0]    mmio_wstrb_r;
  logic [RC_TAG_W-1:0]      mmio_tag_r;
  logic [AXIL_ADDR_W-1:0]   mmio_axil_addr_r;
  logic                     mmio_aw_sent_r;
  logic                     mmio_w_sent_r;

  logic host_req_fire;
  logic host_rsp_fire;
  logic axil_aw_fire;
  logic axil_w_fire;
  logic axil_b_fire;
  logic axil_ar_fire;
  logic axil_r_fire;
  logic dma_aw_fire;
  logic dma_w_fire;
  logic dma_b_fire;

  logic status_clear_irq_c;
  logic status_clear_error_c;
  logic doorbell_fire_c;
  logic doorbell_start_ok_c;
  logic doorbell_error_c;

  logic [BAR_DATA_W-1:0] host_req_write_data_masked_c;
  logic                  req_bar0_c;
  logic                  req_status_write_c;
  logic                  req_doorbell_write_c;
  logic                  status_irq_bit_set_c;
  logic                  status_error_bit_set_c;
  logic                  doorbell_bit_set_c;

  function automatic logic [BAR_DATA_W-1:0] apply_bar_strb(
      input logic [BAR_DATA_W-1:0] current_value,
      input logic [BAR_DATA_W-1:0] new_value,
      input logic [BAR_STRB_W-1:0] byte_en
  );
    logic [BAR_DATA_W-1:0] merged_value;
    int unsigned lane;

    merged_value = current_value;
    for (lane = 0; lane < BAR_STRB_W; lane++) begin
      if (byte_en[lane]) begin
        merged_value[lane*8 +: 8] = new_value[lane*8 +: 8];
      end
    end
    return merged_value;
  endfunction

  function automatic logic [BAR_DATA_W-1:0] read_internal_reg(input logic [BAR_ADDR_W-1:0] addr);
    logic [BAR_DATA_W-1:0] value;

    value = '0;
    unique case (addr)
      pcie_dma_pkg::PCIE_DMA_REG_CONTROL: begin
        value[pcie_dma_pkg::PCIE_DMA_CTRL_ENABLE_BIT]     = control_enable_r;
        value[pcie_dma_pkg::PCIE_DMA_CTRL_IRQ_ENABLE_BIT] = control_irq_enable_r;
      end
      pcie_dma_pkg::PCIE_DMA_REG_STATUS: begin
        value[pcie_dma_pkg::PCIE_DMA_STATUS_ENABLE_BIT]       = control_enable_r;
        value[pcie_dma_pkg::PCIE_DMA_STATUS_IRQ_ENABLE_BIT]   = control_irq_enable_r;
        value[pcie_dma_pkg::PCIE_DMA_STATUS_BUSY_BIT]         = (dma_state_r != DMA_IDLE);
        value[pcie_dma_pkg::PCIE_DMA_STATUS_IRQ_PENDING_BIT]  = irq_pending_r;
        value[pcie_dma_pkg::PCIE_DMA_STATUS_ERROR_BIT]        = dma_error_r;
        value[pcie_dma_pkg::PCIE_DMA_STATUS_SHADOW_VALID_BIT] = (shadow_len_bytes_r != 32'd0);
        value[31:16]                                          = completed_count_r;
      end
      pcie_dma_pkg::PCIE_DMA_REG_DESC_ADDR_LO: begin
        value = shadow_axi_addr_r[31:0];
      end
      pcie_dma_pkg::PCIE_DMA_REG_DESC_ADDR_HI: begin
        value = shadow_axi_addr_r[63:32];
      end
      pcie_dma_pkg::PCIE_DMA_REG_DESC_LEN: begin
        value = shadow_len_bytes_r;
      end
      pcie_dma_pkg::PCIE_DMA_REG_DESC_PATTERN: begin
        value = shadow_pattern_seed_r;
      end
      pcie_dma_pkg::PCIE_DMA_REG_DESC_META: begin
        value[DMA_DESC_ID_W-1:0] = shadow_desc_id_r;
        value[pcie_dma_pkg::PCIE_DMA_DESC_META_IRQ_BIT] = shadow_irq_on_done_r;
        value[pcie_dma_pkg::PCIE_DMA_DESC_META_DIR_BIT] = pcie_dma_pkg::PCIE_DMA_DESC_DIR_H2C;
      end
      pcie_dma_pkg::PCIE_DMA_REG_COMPLETION: begin
        value[DMA_DESC_ID_W-1:0] = last_completed_desc_id_r;
        value[15:8]              = 8'd0;
        value[31:16]             = completed_count_r;
      end
      pcie_dma_pkg::PCIE_DMA_REG_COMPLETION_LEN: begin
        value = last_completed_len_r;
      end
      default: begin
        value = '0;
      end
    endcase

    return value;
  endfunction

  function automatic logic [1:0] axi_resp_to_mmio_status(input logic [1:0] axi_resp);
    if (axi_resp == AXI_RESP_OKAY) begin
      return pcie_dma_pkg::PCIE_MMIO_STATUS_SC;
    end
    return pcie_dma_pkg::PCIE_MMIO_STATUS_CA;
  endfunction

  function automatic logic [7:0] calc_burst_beats(input logic [31:0] remaining_bytes);
    int unsigned beats_needed;

    if (remaining_bytes == 32'd0) begin
      return 8'd0;
    end

    beats_needed = (remaining_bytes + AXI_BEAT_BYTES - 1) / AXI_BEAT_BYTES;
    if (beats_needed > MAX_DMA_BURST_LEN) begin
      beats_needed = MAX_DMA_BURST_LEN;
    end

    return 8'(beats_needed);
  endfunction

  function automatic logic [31:0] calc_burst_bytes(input logic [31:0] remaining_bytes);
    logic [7:0] burst_beats;
    burst_beats = calc_burst_beats(remaining_bytes);
    return burst_beats * AXI_BEAT_BYTES;
  endfunction

  function automatic logic [AXI_STRB_W-1:0] make_axi_strb(input logic [31:0] valid_bytes);
    logic [AXI_STRB_W-1:0] strobe;
    int unsigned lane;

    strobe = '0;
    for (lane = 0; lane < AXI_STRB_W; lane++) begin
      if (lane < valid_bytes) begin
        strobe[lane] = 1'b1;
      end
    end
    return strobe;
  endfunction

  function automatic logic [AXI_DATA_W-1:0] make_dma_data(
      input logic [31:0] pattern_seed,
      input logic [31:0] byte_offset
  );
    logic [AXI_DATA_W-1:0] result;
    logic [7:0] seed_byte;
    int unsigned lane;

    result = '0;
    for (lane = 0; lane < AXI_STRB_W; lane++) begin
      seed_byte = pattern_seed[(lane % 4) * 8 +: 8];
      result[lane*8 +: 8] = seed_byte + byte_offset[7:0] + 8'(lane);
    end
    return result;
  endfunction

  assign host_req_fire = host_rc.req_valid && host_rc.req_ready;
  assign host_rsp_fire = host_rsp_valid_r && host_rc.rsp_ready;
  assign axil_aw_fire  = m_axil_bar0.awvalid && m_axil_bar0.awready;
  assign axil_w_fire   = m_axil_bar0.wvalid && m_axil_bar0.wready;
  assign axil_b_fire   = m_axil_bar0.bvalid && m_axil_bar0.bready;
  assign axil_ar_fire  = m_axil_bar0.arvalid && m_axil_bar0.arready;
  assign axil_r_fire   = m_axil_bar0.rvalid && m_axil_bar0.rready;
  assign dma_aw_fire   = m_axi_dma.awvalid && m_axi_dma.awready;
  assign dma_w_fire    = m_axi_dma.wvalid && m_axi_dma.wready;
  assign dma_b_fire    = m_axi_dma.bvalid && m_axi_dma.bready;

  assign host_req_write_data_masked_c =
      apply_bar_strb({BAR_DATA_W{1'b0}}, host_rc.req_data, host_rc.req_strb);

  assign req_bar0_c          = (host_rc.req_bar == {BAR_W{1'b0}});
  assign req_status_write_c  = host_rc.req_write &&
                               (host_rc.req_addr == pcie_dma_pkg::PCIE_DMA_REG_STATUS);
  assign req_doorbell_write_c = host_rc.req_write &&
                                (host_rc.req_addr == pcie_dma_pkg::PCIE_DMA_REG_DOORBELL);

  assign status_irq_bit_set_c =
      host_req_write_data_masked_c[pcie_dma_pkg::PCIE_DMA_STATUS_IRQ_PENDING_BIT];

  assign status_error_bit_set_c =
      host_req_write_data_masked_c[pcie_dma_pkg::PCIE_DMA_STATUS_ERROR_BIT];

  assign doorbell_bit_set_c = host_req_write_data_masked_c[0];

  assign status_clear_irq_c = host_req_fire &&
                              req_bar0_c &&
                              req_status_write_c &&
                              status_irq_bit_set_c;

  assign status_clear_error_c = host_req_fire &&
                                req_bar0_c &&
                                req_status_write_c &&
                                status_error_bit_set_c;

  assign doorbell_fire_c = host_req_fire &&
                           req_bar0_c &&
                           req_doorbell_write_c &&
                           doorbell_bit_set_c;

  assign doorbell_start_ok_c = control_enable_r &&
                               (dma_state_r == DMA_IDLE) &&
                               (shadow_len_bytes_r != 32'd0) &&
                               !((|shadow_axi_addr_r[63:AXI_ADDR_W]));

  assign doorbell_error_c = doorbell_fire_c && !doorbell_start_ok_c;

  assign host_rc.req_ready  = rst_ni && (mmio_state_r == MMIO_IDLE) && !host_rsp_valid_r;
  assign host_rc.rsp_valid  = host_rsp_valid_r;
  assign host_rc.rsp_data   = host_rsp_data_r;
  assign host_rc.rsp_status = host_rsp_status_r;
  assign host_rc.rsp_tag    = host_rsp_tag_r;

  assign irq_o               = irq_pending_r;
  assign dma_busy_o          = (dma_state_r != DMA_IDLE);
  assign dma_done_pulse_o    = dma_done_pulse_r;
  assign dma_done_desc_id_o  = dma_done_desc_id_r;

  always_comb begin
    m_axil_bar0.awaddr  = mmio_axil_addr_r;
    m_axil_bar0.awprot  = '0;
    m_axil_bar0.awvalid = 1'b0;
    m_axil_bar0.wdata   = mmio_wdata_r[AXIL_DATA_W-1:0];
    m_axil_bar0.wstrb   = mmio_wstrb_r[AXIL_STRB_W-1:0];
    m_axil_bar0.wvalid  = 1'b0;
    m_axil_bar0.bready  = 1'b0;
    m_axil_bar0.araddr  = mmio_axil_addr_r;
    m_axil_bar0.arprot  = '0;
    m_axil_bar0.arvalid = 1'b0;
    m_axil_bar0.rready  = 1'b0;

    unique case (mmio_state_r)
      MMIO_AXIL_WRITE: begin
        m_axil_bar0.awvalid = !mmio_aw_sent_r;
        m_axil_bar0.wvalid  = !mmio_w_sent_r;
      end
      MMIO_AXIL_WRITE_RESP: begin
        m_axil_bar0.bready = !host_rsp_valid_r;
      end
      MMIO_AXIL_READ: begin
        m_axil_bar0.arvalid = 1'b1;
      end
      MMIO_AXIL_READ_RESP: begin
        m_axil_bar0.rready = !host_rsp_valid_r;
      end
      default: begin
      end
    endcase
  end

  always_comb begin
    logic [31:0] beat_offset;
    logic [31:0] beat_valid_bytes;

    m_axi_dma.awaddr  = dma_base_addr_r + AXI_ADDR_W'(dma_bytes_sent_r);
    m_axi_dma.awlen   = (dma_burst_beats_r != 8'd0) ? (dma_burst_beats_r - 1'b1) : '0;
    m_axi_dma.awsize  = 3'(AXI_BURST_SIZE);
    m_axi_dma.awburst = 2'b01;
    m_axi_dma.awvalid = 1'b0;

    beat_offset = dma_bytes_sent_r;
    if (beat_offset >= dma_total_len_r) begin
      beat_valid_bytes = 32'd0;
    end else if ((dma_total_len_r - beat_offset) > AXI_BEAT_BYTES) begin
      beat_valid_bytes = AXI_BEAT_BYTES;
    end else begin
      beat_valid_bytes = dma_total_len_r - beat_offset;
    end

    m_axi_dma.wdata   = make_dma_data(dma_pattern_seed_r, beat_offset);
    m_axi_dma.wstrb   = make_axi_strb(beat_valid_bytes);
    m_axi_dma.wlast   = (dma_beat_index_r + 1'b1) >= dma_burst_beats_r;
    m_axi_dma.wvalid  = 1'b0;
    m_axi_dma.bready  = 1'b0;

    m_axi_dma.araddr  = '0;
    m_axi_dma.arlen   = '0;
    m_axi_dma.arsize  = '0;
    m_axi_dma.arburst = '0;
    m_axi_dma.arvalid = 1'b0;
    m_axi_dma.rready  = 1'b1;

    unique case (dma_state_r)
      DMA_AW: begin
        m_axi_dma.awvalid = 1'b1;
      end
      DMA_W: begin
        m_axi_dma.wvalid = 1'b1;
      end
      DMA_B: begin
        m_axi_dma.bready = 1'b1;
      end
      default: begin
      end
    endcase
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    logic [BAR_DATA_W-1:0] write_value;

    if (!rst_ni) begin
      mmio_state_r          <= MMIO_IDLE;
      control_enable_r      <= 1'b0;
      control_irq_enable_r  <= 1'b0;
      shadow_axi_addr_r     <= '0;
      shadow_len_bytes_r    <= '0;
      shadow_pattern_seed_r <= '0;
      shadow_desc_id_r      <= '0;
      shadow_irq_on_done_r  <= 1'b0;
      host_rsp_valid_r      <= 1'b0;
      host_rsp_data_r       <= '0;
      host_rsp_status_r     <= pcie_dma_pkg::PCIE_MMIO_STATUS_SC;
      host_rsp_tag_r        <= '0;
      mmio_addr_r           <= '0;
      mmio_wdata_r          <= '0;
      mmio_wstrb_r          <= '0;
      mmio_tag_r            <= '0;
      mmio_axil_addr_r      <= '0;
      mmio_aw_sent_r        <= 1'b0;
      mmio_w_sent_r         <= 1'b0;
    end else begin
      if (host_rsp_fire) begin
        host_rsp_valid_r <= 1'b0;
      end

      if (host_req_fire) begin
        if (!req_bar0_c) begin
          host_rsp_valid_r  <= 1'b1;
          host_rsp_data_r   <= '0;
          host_rsp_status_r <= pcie_dma_pkg::PCIE_MMIO_STATUS_UR;
          host_rsp_tag_r    <= host_rc.req_tag;
        end else if (host_rc.req_addr < BAR0_INTERNAL_BYTES_C) begin
          if (host_rc.req_write) begin
            unique case (host_rc.req_addr)
              pcie_dma_pkg::PCIE_DMA_REG_CONTROL: begin
                write_value = apply_bar_strb(read_internal_reg(host_rc.req_addr),
                                             host_rc.req_data,
                                             host_rc.req_strb);
                control_enable_r     <= write_value[pcie_dma_pkg::PCIE_DMA_CTRL_ENABLE_BIT];
                control_irq_enable_r <= write_value[pcie_dma_pkg::PCIE_DMA_CTRL_IRQ_ENABLE_BIT];
              end
              pcie_dma_pkg::PCIE_DMA_REG_STATUS: begin
              end
              pcie_dma_pkg::PCIE_DMA_REG_DESC_ADDR_LO: begin
                shadow_axi_addr_r[31:0] <= apply_bar_strb(
                    shadow_axi_addr_r[31:0], host_rc.req_data, host_rc.req_strb);
              end
              pcie_dma_pkg::PCIE_DMA_REG_DESC_ADDR_HI: begin
                shadow_axi_addr_r[63:32] <= apply_bar_strb(
                    shadow_axi_addr_r[63:32], host_rc.req_data, host_rc.req_strb);
              end
              pcie_dma_pkg::PCIE_DMA_REG_DESC_LEN: begin
                shadow_len_bytes_r <= apply_bar_strb(
                    shadow_len_bytes_r, host_rc.req_data, host_rc.req_strb);
              end
              pcie_dma_pkg::PCIE_DMA_REG_DESC_PATTERN: begin
                shadow_pattern_seed_r <= apply_bar_strb(
                    shadow_pattern_seed_r, host_rc.req_data, host_rc.req_strb);
              end
              pcie_dma_pkg::PCIE_DMA_REG_DESC_META: begin
                write_value = apply_bar_strb(read_internal_reg(host_rc.req_addr),
                                             host_rc.req_data,
                                             host_rc.req_strb);
                shadow_desc_id_r     <= write_value[DMA_DESC_ID_W-1:0];
                shadow_irq_on_done_r <= write_value[pcie_dma_pkg::PCIE_DMA_DESC_META_IRQ_BIT];
              end
              pcie_dma_pkg::PCIE_DMA_REG_DOORBELL: begin
              end
              default: begin
              end
            endcase
          end

          host_rsp_valid_r  <= 1'b1;
          host_rsp_data_r   <= host_rc.req_write ? {BAR_DATA_W{1'b0}} :
                                                   read_internal_reg(host_rc.req_addr);
          host_rsp_status_r <= pcie_dma_pkg::PCIE_MMIO_STATUS_SC;
          host_rsp_tag_r    <= host_rc.req_tag;
        end else if (host_rc.req_addr >= BAR0_FORWARD_BASE_C) begin
          mmio_addr_r      <= host_rc.req_addr;
          mmio_wdata_r     <= host_rc.req_data;
          mmio_wstrb_r     <= host_rc.req_strb;
          mmio_tag_r       <= host_rc.req_tag;
          mmio_axil_addr_r <= AXIL_ADDR_W'(host_rc.req_addr - BAR0_FORWARD_BASE_C);
          mmio_aw_sent_r   <= 1'b0;
          mmio_w_sent_r    <= 1'b0;

          if (host_rc.req_write) begin
            mmio_state_r <= MMIO_AXIL_WRITE;
          end else begin
            mmio_state_r <= MMIO_AXIL_READ;
          end
        end else begin
          host_rsp_valid_r  <= 1'b1;
          host_rsp_data_r   <= '0;
          host_rsp_status_r <= pcie_dma_pkg::PCIE_MMIO_STATUS_UR;
          host_rsp_tag_r    <= host_rc.req_tag;
        end
      end

      unique case (mmio_state_r)
        MMIO_AXIL_WRITE: begin
          if (axil_aw_fire) begin
            mmio_aw_sent_r <= 1'b1;
          end
          if (axil_w_fire) begin
            mmio_w_sent_r <= 1'b1;
          end
          if ((mmio_aw_sent_r || axil_aw_fire) &&
              (mmio_w_sent_r  || axil_w_fire)) begin
            mmio_state_r <= MMIO_AXIL_WRITE_RESP;
          end
        end

        MMIO_AXIL_WRITE_RESP: begin
          if (axil_b_fire) begin
            host_rsp_valid_r  <= 1'b1;
            host_rsp_data_r   <= '0;
            host_rsp_status_r <= axi_resp_to_mmio_status(m_axil_bar0.bresp);
            host_rsp_tag_r    <= mmio_tag_r;
            mmio_state_r      <= MMIO_IDLE;
          end
        end

        MMIO_AXIL_READ: begin
          if (axil_ar_fire) begin
            mmio_state_r <= MMIO_AXIL_READ_RESP;
          end
        end

        MMIO_AXIL_READ_RESP: begin
          if (axil_r_fire) begin
            host_rsp_valid_r  <= 1'b1;
            host_rsp_data_r   <= BAR_DATA_W'(m_axil_bar0.rdata);
            host_rsp_status_r <= axi_resp_to_mmio_status(m_axil_bar0.rresp);
            host_rsp_tag_r    <= mmio_tag_r;
            mmio_state_r      <= MMIO_IDLE;
          end
        end

        default: begin
        end
      endcase
    end
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      irq_pending_r <= 1'b0;
      dma_error_r   <= 1'b0;
    end else begin
      if (status_clear_irq_c) begin
        irq_pending_r <= 1'b0;
      end

      if (status_clear_error_c) begin
        dma_error_r <= 1'b0;
      end

      if (doorbell_error_c) begin
        dma_error_r <= 1'b1;
      end

      if (dma_b_fire && (m_axi_dma.bresp != AXI_RESP_OKAY)) begin
        dma_error_r <= 1'b1;
      end

      if (dma_b_fire &&
          (dma_bytes_sent_r >= dma_total_len_r) &&
          control_irq_enable_r &&
          dma_irq_on_done_r) begin
        irq_pending_r <= 1'b1;
      end
    end
  end

  always_ff @(posedge clk_i or negedge rst_ni) begin
    logic [31:0] beat_offset;
    logic [31:0] beat_bytes;
    logic [31:0] bytes_remaining_after_resp;

    if (!rst_ni) begin
      dma_state_r              <= DMA_IDLE;
      dma_base_addr_r          <= '0;
      dma_total_len_r          <= '0;
      dma_pattern_seed_r       <= '0;
      dma_desc_id_r            <= '0;
      dma_irq_on_done_r        <= 1'b0;
      dma_bytes_sent_r         <= '0;
      dma_burst_beats_r        <= '0;
      dma_burst_bytes_r        <= '0;
      dma_beat_index_r         <= '0;
      last_completed_desc_id_r <= '0;
      last_completed_len_r     <= '0;
      completed_count_r        <= '0;
      dma_done_pulse_r         <= 1'b0;
      dma_done_desc_id_r       <= '0;
    end else begin
      dma_done_pulse_r <= 1'b0;

      if (doorbell_fire_c && doorbell_start_ok_c) begin
        dma_base_addr_r       <= shadow_axi_addr_r[AXI_ADDR_W-1:0];
        dma_total_len_r       <= shadow_len_bytes_r;
        dma_pattern_seed_r    <= shadow_pattern_seed_r;
        dma_desc_id_r         <= shadow_desc_id_r;
        dma_irq_on_done_r     <= shadow_irq_on_done_r;
        dma_bytes_sent_r      <= '0;
        dma_burst_beats_r     <= calc_burst_beats(shadow_len_bytes_r);
        dma_burst_bytes_r     <= calc_burst_bytes(shadow_len_bytes_r);
        dma_beat_index_r      <= '0;
        dma_state_r           <= DMA_AW;
      end else begin
        unique case (dma_state_r)
          DMA_AW: begin
            if (dma_aw_fire) begin
              dma_beat_index_r <= '0;
              dma_state_r      <= DMA_W;
            end
          end

          DMA_W: begin
            beat_offset = dma_bytes_sent_r;
            if (beat_offset >= dma_total_len_r) begin
              beat_bytes = 32'd0;
            end else if ((dma_total_len_r - beat_offset) > AXI_BEAT_BYTES) begin
              beat_bytes = AXI_BEAT_BYTES;
            end else begin
              beat_bytes = dma_total_len_r - beat_offset;
            end

            if (dma_w_fire) begin
              dma_bytes_sent_r <= dma_bytes_sent_r + beat_bytes;
              if ((dma_beat_index_r + 1'b1) >= dma_burst_beats_r) begin
                dma_state_r <= DMA_B;
              end else begin
                dma_beat_index_r <= dma_beat_index_r + 1'b1;
              end
            end
          end

          DMA_B: begin
            if (dma_b_fire) begin
              bytes_remaining_after_resp = dma_total_len_r - dma_bytes_sent_r;
              if (dma_bytes_sent_r >= dma_total_len_r) begin
                last_completed_desc_id_r <= dma_desc_id_r;
                last_completed_len_r     <= dma_total_len_r;
                completed_count_r        <= completed_count_r + 1'b1;
                dma_done_pulse_r         <= 1'b1;
                dma_done_desc_id_r       <= dma_desc_id_r;
                dma_state_r              <= DMA_IDLE;
              end else begin
                dma_burst_beats_r <= calc_burst_beats(bytes_remaining_after_resp);
                dma_burst_bytes_r <= calc_burst_bytes(bytes_remaining_after_resp);
                dma_beat_index_r  <= '0;
                dma_state_r       <= DMA_AW;
              end
            end
          end

          default: begin
          end
        endcase
      end
    end
  end

  `DDR_RING_STATIC_ASSERT(BAR_DATA_W == 32,
                          "pcie_endpoint_dma_shell BAR_DATA_W currently expects 32-bit MMIO")
  `DDR_RING_STATIC_ASSERT(BAR_W > 0,
                          "pcie_endpoint_dma_shell BAR_W must be greater than zero")
  `DDR_RING_STATIC_ASSERT(AXIL_DATA_W == 32,
                          "pcie_endpoint_dma_shell AXIL_DATA_W currently expects 32-bit AXI-Lite")
  `DDR_RING_STATIC_ASSERT((AXI_DATA_W > 0) && ((AXI_DATA_W % 8) == 0),
                          "pcie_endpoint_dma_shell AXI_DATA_W must be byte aligned")
  `DDR_RING_STATIC_ASSERT(AXI_ADDR_W < 64,
                          "pcie_endpoint_dma_shell AXI_ADDR_W must be less than 64")
  `DDR_RING_STATIC_ASSERT(MAX_DMA_BURST_LEN > 0,
                          "pcie_endpoint_dma_shell MAX_DMA_BURST_LEN must be greater than zero")

endmodule