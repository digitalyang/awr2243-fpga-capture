`include "ddr_ringbuffer_macros.svh"

// UVM environment, memory model hooks, sequences, and scoreboard for the DDR
// ring-buffer controller.
package ddr_ringbuffer_controller_uvm_pkg;

  import uvm_pkg::*;
  import ddr_ringbuffer_pkg::*;
  `include "uvm_macros.svh"

  localparam int unsigned TB_AXIS_DATA_W = `DDR_RING_AXIS_DATA_W_DFLT;
  localparam int unsigned TB_AXIS_USER_W = `DDR_RING_AXIS_USER_W_DFLT;
  localparam int unsigned TB_AXIS_KEEP_W = TB_AXIS_DATA_W / 8;
  localparam int unsigned TB_AXIS_BEAT_BYTES = TB_AXIS_DATA_W / 8;
  localparam int unsigned TB_AXI_DATA_W = `DDR_RING_AXI_DATA_W_DFLT;
  localparam int unsigned TB_AXI_ADDR_W = `DDR_RING_AXI_ADDR_W_DFLT;
  localparam int unsigned TB_AXI_STRB_W = TB_AXI_DATA_W / 8;
  localparam int unsigned TB_AXI_BEAT_BYTES = TB_AXI_DATA_W / 8;
  localparam int unsigned TB_RD_AXIS_USER_W = `DDR_RING_AXIS_USER_W_DFLT;
  localparam int unsigned TB_RD_AXIS_KEEP_W = TB_AXI_DATA_W / 8;
  localparam int unsigned TB_RING_SIZE_MAX = `DDR_RING_RING_SIZE_BYTES_DFLT;
  localparam int unsigned TB_RING_BYTES_W = clog2_safe(TB_RING_SIZE_MAX + 1);
  localparam int unsigned TB_SLOT_BYTES_W = DDR_RING_SLOT_BYTES_W_DFLT;
  localparam int unsigned TB_SLOT_SEQ_W = `DDR_RING_SLOT_SEQ_W_DFLT;
  localparam int unsigned TB_COUNTER_W = `DDR_RING_COUNTER_W_DFLT;
  localparam int unsigned TB_RD_TUSER_FIRST_BIT = 0;
  localparam int unsigned TB_RD_TUSER_LAST_BIT = 1;
  localparam int unsigned TB_RD_TUSER_VALID_BIT = 2;
  localparam int unsigned TB_RD_TUSER_OVF_BIT = 3;
  localparam int unsigned TB_RD_TUSER_SEQ_LSB = 8;
  localparam int unsigned TB_RD_TUSER_BYTES_LSB = 32;

  `uvm_analysis_imp_decl(_exp)
  `uvm_analysis_imp_decl(_commit)
  `uvm_analysis_imp_decl(_read)

  class ddr_ring_slot_item extends uvm_sequence_item;
    rand bit           [TB_SLOT_SEQ_W-1:0] slot_seq;
    rand bit                               slot_valid_good;
    rand bit                               slot_overflow_err;
    int unsigned                           reported_slot_bytes;
    rand byte unsigned                     payload             [$];

    constraint c_payload_size {payload.size() inside {[1 : (TB_AXI_BEAT_BYTES * 8)]};}

    `uvm_object_utils_begin(ddr_ring_slot_item)
      `uvm_field_int(slot_seq, UVM_DEFAULT)
      `uvm_field_int(slot_valid_good, UVM_DEFAULT)
      `uvm_field_int(slot_overflow_err, UVM_DEFAULT)
      `uvm_field_int(reported_slot_bytes, UVM_DEFAULT)
      `uvm_field_queue_int(payload, UVM_DEFAULT)
    `uvm_object_utils_end

    function new(string name = "ddr_ring_slot_item");
      super.new(name);
      slot_valid_good     = 1'b1;
      slot_overflow_err   = 1'b0;
      reported_slot_bytes = 0;
    endfunction

    function int unsigned slot_bytes();
      return payload.size();
    endfunction

    function ddr_ring_slot_item dup(string name = "dup_slot");
      ddr_ring_slot_item copy_item;
      copy_item = ddr_ring_slot_item::type_id::create(name);
      copy_item.copy(this);
      return copy_item;
    endfunction

    function string convert2string();
      return $sformatf(
          "seq=%0d bytes=%0d valid=%0b overflow=%0b",
          slot_seq,
          payload.size(),
          slot_valid_good,
          slot_overflow_err
      );
    endfunction
  endclass

  class ddr_ring_commit_item extends uvm_object;
    bit          [TB_AXI_ADDR_W-1:0] slot_addr;
    bit          [TB_SLOT_SEQ_W-1:0] slot_seq;
    int unsigned                     slot_bytes;
    bit                              slot_valid_good;
    bit                              slot_overflow_err;

    `uvm_object_utils_begin(ddr_ring_commit_item)
      `uvm_field_int(slot_addr, UVM_DEFAULT)
      `uvm_field_int(slot_seq, UVM_DEFAULT)
      `uvm_field_int(slot_bytes, UVM_DEFAULT)
      `uvm_field_int(slot_valid_good, UVM_DEFAULT)
      `uvm_field_int(slot_overflow_err, UVM_DEFAULT)
    `uvm_object_utils_end

    function new(string name = "ddr_ring_commit_item");
      super.new(name);
    endfunction
  endclass

  class ddr_ringbuffer_env_cfg extends uvm_object;
    virtual axis_stream_if #(TB_AXIS_DATA_W, TB_AXIS_USER_W) src_vif;
    virtual axis_stream_if #(TB_AXI_DATA_W, TB_RD_AXIS_USER_W) rd_vif;
    virtual axi4_mm_if #(TB_AXI_ADDR_W, TB_AXI_DATA_W) axi_vif;
    virtual ddr_ringbuffer_ctrl_if #(
            TB_AXI_ADDR_W,
            TB_RING_BYTES_W,
            TB_SLOT_BYTES_W,
            TB_SLOT_SEQ_W,
            TB_COUNTER_W
        ) ctrl_vif;

    bit [TB_AXI_ADDR_W-1:0] cfg_ring_base_addr;
    bit [TB_RING_BYTES_W-1:0] cfg_ring_size_bytes;
    bit cfg_enable;
    bit cfg_allow_overwrite;
    bit cfg_drop_invalid_slot;
    bit cfg_drop_on_no_space;

    `uvm_object_utils_begin(ddr_ringbuffer_env_cfg)
      `uvm_field_int(cfg_ring_base_addr, UVM_DEFAULT)
      `uvm_field_int(cfg_ring_size_bytes, UVM_DEFAULT)
      `uvm_field_int(cfg_enable, UVM_DEFAULT)
      `uvm_field_int(cfg_allow_overwrite, UVM_DEFAULT)
      `uvm_field_int(cfg_drop_invalid_slot, UVM_DEFAULT)
      `uvm_field_int(cfg_drop_on_no_space, UVM_DEFAULT)
    `uvm_object_utils_end

    function new(string name = "ddr_ringbuffer_env_cfg");
      super.new(name);
    endfunction
  endclass

  class ddr_ring_source_sequencer extends uvm_sequencer #(ddr_ring_slot_item);
    `uvm_component_utils(ddr_ring_source_sequencer)

    function new(string name = "ddr_ring_source_sequencer", uvm_component parent = null);
      super.new(name, parent);
    endfunction
  endclass

  class ddr_ring_source_driver extends uvm_driver #(ddr_ring_slot_item);
    `uvm_component_utils(ddr_ring_source_driver)

    ddr_ringbuffer_env_cfg                  cfg;
    uvm_analysis_port #(ddr_ring_slot_item) exp_ap;

    function new(string name = "ddr_ring_source_driver", uvm_component parent = null);
      super.new(name, parent);
      exp_ap = new("exp_ap", this);
    endfunction

    function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      if (!uvm_config_db#(ddr_ringbuffer_env_cfg)::get(this, "", "env_cfg", cfg)) begin
        `uvm_fatal(get_type_name(), "env_cfg is not set for ddr_ring_source_driver")
      end
    endfunction

    task reset_signals();
      cfg.src_vif.tdata              <= '0;
      cfg.src_vif.tkeep              <= '0;
      cfg.src_vif.tvalid             <= 1'b0;
      cfg.src_vif.tlast              <= 1'b0;
      cfg.src_vif.tuser              <= '0;
      cfg.ctrl_vif.slot_start        <= 1'b0;
      cfg.ctrl_vif.slot_done         <= 1'b0;
      cfg.ctrl_vif.slot_bytes        <= '0;
      cfg.ctrl_vif.slot_seq          <= '0;
      cfg.ctrl_vif.slot_valid_good   <= 1'b0;
      cfg.ctrl_vif.slot_overflow_err <= 1'b0;
    endtask

    task run_phase(uvm_phase phase);
      ddr_ring_slot_item req_item;

      reset_signals();
      wait (cfg.ctrl_vif.rst_ni === 1'b1);

      forever begin
        seq_item_port.get_next_item(req_item);
        req_item.reported_slot_bytes = req_item.slot_bytes();
        exp_ap.write(req_item.dup("exp_slot"));
        drive_slot(req_item);
        seq_item_port.item_done();
      end
    endtask

    task drive_slot(ddr_ring_slot_item item);
      int unsigned                      beat_count;
      int unsigned                      beat_idx;
      int unsigned                      lane_idx;
      int unsigned                      byte_idx;
      logic        [TB_AXIS_DATA_W-1:0] beat_data_c;
      logic        [TB_AXIS_KEEP_W-1:0] beat_keep_c;

      beat_count = ceil_div_u(item.payload.size(), TB_AXIS_BEAT_BYTES);

      for (beat_idx = 0; beat_idx < beat_count; beat_idx++) begin
        beat_data_c = '0;
        beat_keep_c = '0;

        for (lane_idx = 0; lane_idx < TB_AXIS_BEAT_BYTES; lane_idx++) begin
          byte_idx = (beat_idx * TB_AXIS_BEAT_BYTES) + lane_idx;
          if (byte_idx < item.payload.size()) begin
            beat_data_c[(lane_idx*8)+:8] = item.payload[byte_idx];
            beat_keep_c[lane_idx]        = 1'b1;
          end
        end

        cfg.src_vif.tdata              <= beat_data_c;
        cfg.src_vif.tkeep              <= beat_keep_c;
        cfg.src_vif.tvalid             <= 1'b1;
        cfg.src_vif.tlast              <= (beat_idx == (beat_count - 1));
        cfg.src_vif.tuser              <= '0;
        cfg.ctrl_vif.slot_start        <= (beat_idx == 0);
        cfg.ctrl_vif.slot_done         <= (beat_idx == (beat_count - 1));
        cfg.ctrl_vif.slot_bytes        <= TB_SLOT_BYTES_W'(item.slot_bytes());
        cfg.ctrl_vif.slot_seq          <= item.slot_seq;
        cfg.ctrl_vif.slot_valid_good   <= item.slot_valid_good;
        cfg.ctrl_vif.slot_overflow_err <= item.slot_overflow_err;

        do begin
          @(posedge cfg.ctrl_vif.clk);
        end while (!(cfg.src_vif.tvalid && cfg.src_vif.tready));
      end

      reset_signals();
      @(posedge cfg.ctrl_vif.clk);
    endtask
  endclass

  class ddr_ring_source_agent extends uvm_agent;
    `uvm_component_utils(ddr_ring_source_agent)

    ddr_ring_source_sequencer seqr;
    ddr_ring_source_driver    drv;

    function new(string name = "ddr_ring_source_agent", uvm_component parent = null);
      super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      seqr = ddr_ring_source_sequencer::type_id::create("seqr", this);
      drv  = ddr_ring_source_driver::type_id::create("drv", this);
    endfunction

    function void connect_phase(uvm_phase phase);
      super.connect_phase(phase);
      drv.seq_item_port.connect(seqr.seq_item_export);
    endfunction
  endclass

  class ddr_ring_read_monitor extends uvm_component;
    `uvm_component_utils(ddr_ring_read_monitor)

    ddr_ringbuffer_env_cfg                  cfg;
    uvm_analysis_port #(ddr_ring_slot_item) read_ap;

    function new(string name = "ddr_ring_read_monitor", uvm_component parent = null);
      super.new(name, parent);
      read_ap = new("read_ap", this);
    endfunction

    function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      if (!uvm_config_db#(ddr_ringbuffer_env_cfg)::get(this, "", "env_cfg", cfg)) begin
        `uvm_fatal(get_type_name(), "env_cfg is not set for ddr_ring_read_monitor")
      end
    endfunction

    task run_phase(uvm_phase phase);
      ddr_ring_slot_item slot_item;
      int unsigned       lane_idx;

      slot_item = null;
      wait (cfg.ctrl_vif.rst_ni === 1'b1);

      forever begin
        @(posedge cfg.ctrl_vif.clk);

        if (cfg.rd_vif.tvalid && cfg.rd_vif.tready) begin
          if (slot_item == null) begin
            slot_item = ddr_ring_slot_item::type_id::create("read_slot");
            slot_item.slot_seq = cfg.rd_vif.tuser[TB_RD_TUSER_SEQ_LSB+:TB_SLOT_SEQ_W];
            slot_item.slot_valid_good = cfg.rd_vif.tuser[TB_RD_TUSER_VALID_BIT];
            slot_item.slot_overflow_err = cfg.rd_vif.tuser[TB_RD_TUSER_OVF_BIT];
            slot_item.reported_slot_bytes =
                            cfg.rd_vif.tuser[TB_RD_TUSER_BYTES_LSB +: TB_SLOT_BYTES_W];
          end

          for (lane_idx = 0; lane_idx < TB_AXI_BEAT_BYTES; lane_idx++) begin
            if (cfg.rd_vif.tkeep[lane_idx]) begin
              slot_item.payload.push_back(byte'(cfg.rd_vif.tdata[(lane_idx*8)+:8]));
            end
          end

          if (cfg.rd_vif.tlast) begin
            read_ap.write(slot_item);
            slot_item = null;
          end
        end
      end
    endtask
  endclass

  class ddr_ring_ctrl_monitor extends uvm_component;
    `uvm_component_utils(ddr_ring_ctrl_monitor)

    ddr_ringbuffer_env_cfg                    cfg;
    uvm_analysis_port #(ddr_ring_commit_item) commit_ap;

    function new(string name = "ddr_ring_ctrl_monitor", uvm_component parent = null);
      super.new(name, parent);
      commit_ap = new("commit_ap", this);
    endfunction

    function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      if (!uvm_config_db#(ddr_ringbuffer_env_cfg)::get(this, "", "env_cfg", cfg)) begin
        `uvm_fatal(get_type_name(), "env_cfg is not set for ddr_ring_ctrl_monitor")
      end
    endfunction

    task run_phase(uvm_phase phase);
      ddr_ring_commit_item commit_item;

      wait (cfg.ctrl_vif.rst_ni === 1'b1);

      forever begin
        @(cfg.ctrl_vif.mon_cb);

        if (cfg.ctrl_vif.mon_cb.wr_slot_commit) begin
          commit_item                   = ddr_ring_commit_item::type_id::create("commit_item");
          commit_item.slot_addr         = cfg.ctrl_vif.mon_cb.wr_slot_addr;
          commit_item.slot_seq          = cfg.ctrl_vif.mon_cb.wr_slot_seq;
          commit_item.slot_bytes        = cfg.ctrl_vif.mon_cb.wr_slot_bytes;
          commit_item.slot_valid_good   = cfg.ctrl_vif.mon_cb.wr_slot_valid_good;
          commit_item.slot_overflow_err = cfg.ctrl_vif.mon_cb.wr_slot_overflow_err;
          commit_ap.write(commit_item);
        end
      end
    endtask
  endclass

  class ddr_ring_axi_mem_model extends uvm_component;
    `uvm_component_utils(ddr_ring_axi_mem_model)

    ddr_ringbuffer_env_cfg cfg;
    byte unsigned          mem[longint unsigned];

    function new(string name = "ddr_ring_axi_mem_model", uvm_component parent = null);
      super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      if (!uvm_config_db#(ddr_ringbuffer_env_cfg)::get(this, "", "env_cfg", cfg)) begin
        `uvm_fatal(get_type_name(), "env_cfg is not set for ddr_ring_axi_mem_model")
      end
    endfunction

    task reset_outputs();
      cfg.axi_vif.awready <= 1'b0;
      cfg.axi_vif.wready  <= 1'b0;
      cfg.axi_vif.bresp   <= AXI_RESP_OKAY;
      cfg.axi_vif.bvalid  <= 1'b0;
      cfg.axi_vif.arready <= 1'b0;
      cfg.axi_vif.rdata   <= '0;
      cfg.axi_vif.rresp   <= AXI_RESP_OKAY;
      cfg.axi_vif.rlast   <= 1'b0;
      cfg.axi_vif.rvalid  <= 1'b0;
    endtask

    function void write_mem_word(input longint unsigned addr, input logic [TB_AXI_DATA_W-1:0] data,
                                 input logic [TB_AXI_STRB_W-1:0] strb);
      for (int unsigned lane_idx = 0; lane_idx < TB_AXI_STRB_W; lane_idx++) begin
        if (strb[lane_idx]) begin
          mem[addr+lane_idx] = byte'(data[(lane_idx*8)+:8]);
        end
      end
    endfunction

    function logic [TB_AXI_DATA_W-1:0] read_mem_word(input longint unsigned addr);
      logic [TB_AXI_DATA_W-1:0] data_c;
      begin
        data_c = '0;
        for (int unsigned lane_idx = 0; lane_idx < TB_AXI_STRB_W; lane_idx++) begin
          if (mem.exists(addr + lane_idx)) begin
            data_c[(lane_idx*8)+:8] = mem[addr+lane_idx];
          end
        end
        return data_c;
      end
    endfunction

    function void read_ring_bytes(input bit [TB_AXI_ADDR_W-1:0] ring_base_addr,
                                  input bit [TB_RING_BYTES_W-1:0] ring_size_bytes,
                                  input bit [TB_AXI_ADDR_W-1:0] start_addr,
                                  input int unsigned byte_count, ref byte unsigned data_q[$]);
      longint unsigned addr_u;
      longint unsigned base_u;
      longint unsigned end_u;
      begin
        data_q.delete();
        base_u = ring_base_addr;
        end_u  = ring_base_addr + ring_size_bytes;
        addr_u = start_addr;

        for (int unsigned idx = 0; idx < byte_count; idx++) begin
          if (addr_u >= end_u) begin
            addr_u = base_u;
          end

          if (mem.exists(addr_u)) begin
            data_q.push_back(mem[addr_u]);
          end else begin
            data_q.push_back(8'h00);
          end

          addr_u++;
        end
      end
    endfunction

    task run_phase(uvm_phase phase);
      bit              wr_active;
      bit              rd_active;
      longint unsigned wr_addr_cur;
      longint unsigned rd_addr_cur;
      int unsigned     wr_beats_rem;
      int unsigned     rd_beats_rem;
      int unsigned     wr_step_bytes;
      int unsigned     rd_step_bytes;

      wr_active     = 1'b0;
      rd_active     = 1'b0;
      wr_addr_cur   = '0;
      rd_addr_cur   = '0;
      wr_beats_rem  = 0;
      rd_beats_rem  = 0;
      wr_step_bytes = TB_AXI_BEAT_BYTES;
      rd_step_bytes = TB_AXI_BEAT_BYTES;

      reset_outputs();

      forever begin
        @(posedge cfg.ctrl_vif.clk);

        if (!cfg.ctrl_vif.rst_ni) begin
          wr_active    = 1'b0;
          rd_active    = 1'b0;
          wr_beats_rem = 0;
          rd_beats_rem = 0;
          reset_outputs();
        end else begin
          cfg.axi_vif.awready <= (!wr_active) && (!cfg.axi_vif.bvalid);
          cfg.axi_vif.wready  <= wr_active;
          cfg.axi_vif.arready <= (!rd_active) && (!cfg.axi_vif.rvalid);

          if (cfg.axi_vif.awvalid && cfg.axi_vif.awready) begin
            wr_active     = 1'b1;
            wr_addr_cur   = cfg.axi_vif.awaddr;
            wr_beats_rem  = cfg.axi_vif.awlen + 1;
            wr_step_bytes = (1 << cfg.axi_vif.awsize);
          end

          if (cfg.axi_vif.wvalid && cfg.axi_vif.wready) begin
            write_mem_word(wr_addr_cur, cfg.axi_vif.wdata, cfg.axi_vif.wstrb);
            wr_addr_cur = wr_addr_cur + wr_step_bytes;

            if (wr_beats_rem != 0) begin
              wr_beats_rem--;
            end

            if (cfg.axi_vif.wlast || (wr_beats_rem <= 1)) begin
              wr_active = 1'b0;
              cfg.axi_vif.wready <= 1'b0;
              cfg.axi_vif.bresp  <= AXI_RESP_OKAY;
              cfg.axi_vif.bvalid <= 1'b1;
            end
          end

          if (cfg.axi_vif.bvalid && cfg.axi_vif.bready) begin
            cfg.axi_vif.bvalid <= 1'b0;
          end

          if (cfg.axi_vif.arvalid && cfg.axi_vif.arready) begin
            rd_active     = 1'b1;
            rd_addr_cur   = cfg.axi_vif.araddr;
            rd_beats_rem  = cfg.axi_vif.arlen + 1;
            rd_step_bytes = (1 << cfg.axi_vif.arsize);
          end

          if (cfg.axi_vif.rvalid && cfg.axi_vif.rready) begin
            cfg.axi_vif.rvalid <= 1'b0;
            cfg.axi_vif.rlast  <= 1'b0;
          end

          if (((!cfg.axi_vif.rvalid) || (cfg.axi_vif.rvalid && cfg.axi_vif.rready)) && rd_active) begin
            cfg.axi_vif.rdata  <= read_mem_word(rd_addr_cur);
            cfg.axi_vif.rresp  <= AXI_RESP_OKAY;
            cfg.axi_vif.rlast  <= (rd_beats_rem == 1);
            cfg.axi_vif.rvalid <= 1'b1;
            rd_addr_cur = rd_addr_cur + rd_step_bytes;

            if (rd_beats_rem != 0) begin
              rd_beats_rem--;
            end

            if (rd_beats_rem <= 1) begin
              rd_active = 1'b0;
            end
          end
        end
      end
    endtask
  endclass

  class ddr_ring_scoreboard extends uvm_component;
    `uvm_component_utils(ddr_ring_scoreboard)

    ddr_ringbuffer_env_cfg                                               cfg;
    ddr_ring_axi_mem_model                                               mem_model;
    uvm_analysis_imp_exp #(ddr_ring_slot_item, ddr_ring_scoreboard)      exp_imp;
    uvm_analysis_imp_commit #(ddr_ring_commit_item, ddr_ring_scoreboard) commit_imp;
    uvm_analysis_imp_read #(ddr_ring_slot_item, ddr_ring_scoreboard)     read_imp;

    ddr_ring_slot_item                                                   exp_commit_q[$];
    ddr_ring_slot_item                                                   exp_read_q  [$];
    int unsigned                                                         error_count;

    function new(string name = "ddr_ring_scoreboard", uvm_component parent = null);
      super.new(name, parent);
      exp_imp     = new("exp_imp", this);
      commit_imp  = new("commit_imp", this);
      read_imp    = new("read_imp", this);
      error_count = 0;
    endfunction

    function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      if (!uvm_config_db#(ddr_ringbuffer_env_cfg)::get(this, "", "env_cfg", cfg)) begin
        `uvm_fatal(get_type_name(), "env_cfg is not set for ddr_ring_scoreboard")
      end
    endfunction

    function void push_error(string msg);
      error_count++;
      `uvm_error(get_type_name(), msg)
    endfunction

    function void compare_slot_meta(input string prefix, input ddr_ring_slot_item exp_item,
                                    input bit [TB_SLOT_SEQ_W-1:0] act_seq,
                                    input int unsigned act_bytes, input bit act_valid,
                                    input bit act_overflow);
      if (exp_item.slot_seq != act_seq) begin
        push_error($sformatf("%s seq mismatch exp=%0d act=%0d", prefix, exp_item.slot_seq, act_seq
                   ));
      end
      if (exp_item.slot_bytes() != act_bytes) begin
        push_error($sformatf(
                   "%s bytes mismatch exp=%0d act=%0d", prefix, exp_item.slot_bytes(), act_bytes));
      end
      if (exp_item.slot_valid_good != act_valid) begin
        push_error(
            $sformatf(
            "%s valid_good mismatch exp=%0b act=%0b", prefix, exp_item.slot_valid_good, act_valid));
      end
      if (exp_item.slot_overflow_err != act_overflow) begin
        push_error(
            $sformatf(
            "%s overflow mismatch exp=%0b act=%0b", prefix, exp_item.slot_overflow_err, act_overflow
            ));
      end
    endfunction

    function void compare_payload(input string prefix, input byte unsigned exp_payload[$],
                                  input byte unsigned act_payload[$]);
      if (exp_payload.size() != act_payload.size()) begin
        push_error($sformatf(
                   "%s payload size mismatch exp=%0d act=%0d",
                   prefix,
                   exp_payload.size(),
                   act_payload.size()
                   ));
        return;
      end

      foreach (exp_payload[idx]) begin
        if (exp_payload[idx] != act_payload[idx]) begin
          push_error($sformatf(
                     "%s payload mismatch at byte %0d exp=0x%0h act=0x%0h",
                     prefix,
                     idx,
                     exp_payload[idx],
                     act_payload[idx]
                     ));
          break;
        end
      end
    endfunction

    function void write_exp(ddr_ring_slot_item item);
      exp_commit_q.push_back(item.dup("exp_commit_slot"));
      `uvm_info(get_type_name(), $sformatf("Expect store: %s", item.convert2string()), UVM_MEDIUM)
    endfunction

    function void write_commit(ddr_ring_commit_item item);
      ddr_ring_slot_item exp_item;
      byte unsigned      mem_bytes[$];
      begin
        if (exp_commit_q.size() == 0) begin
          push_error($sformatf(
                     "Unexpected commit, seq=%0d addr=0x%0h", item.slot_seq, item.slot_addr));
          return;
        end

        exp_item = exp_commit_q.pop_front();
        compare_slot_meta("commit", exp_item, item.slot_seq, item.slot_bytes, item.slot_valid_good,
                          item.slot_overflow_err);

        if (mem_model == null) begin
          push_error("mem_model is null in scoreboard");
        end else begin
          mem_model.read_ring_bytes(cfg.cfg_ring_base_addr, cfg.cfg_ring_size_bytes, item.slot_addr,
                                    exp_item.slot_bytes(), mem_bytes);
          compare_payload("commit_mem", exp_item.payload, mem_bytes);
        end

        exp_read_q.push_back(exp_item);
      end
    endfunction

    function void write_read(ddr_ring_slot_item item);
      ddr_ring_slot_item exp_item;
      begin
        if (exp_read_q.size() == 0) begin
          push_error($sformatf(
                     "Unexpected read slot, seq=%0d bytes=%0d", item.slot_seq, item.slot_bytes()));
          return;
        end

        exp_item = exp_read_q.pop_front();
        compare_slot_meta("read", exp_item, item.slot_seq, item.reported_slot_bytes,
                          item.slot_valid_good, item.slot_overflow_err);
        compare_payload("read_payload", exp_item.payload, item.payload);
      end
    endfunction

    function bit is_idle();
      return (exp_commit_q.size() == 0) && (exp_read_q.size() == 0);
    endfunction

    function void report_phase(uvm_phase phase);
      super.report_phase(phase);
      if (!is_idle()) begin
        push_error($sformatf(
                   "Scoreboard still busy: exp_commit_q=%0d exp_read_q=%0d",
                   exp_commit_q.size(),
                   exp_read_q.size()
                   ));
      end
      if (error_count == 0) begin
        `uvm_info(get_type_name(), "Scoreboard completed without mismatch", UVM_LOW)
      end
    endfunction
  endclass

  class ddr_ring_env extends uvm_env;
    `uvm_component_utils(ddr_ring_env)

    ddr_ring_source_agent  src_agent;
    ddr_ring_read_monitor  rd_mon;
    ddr_ring_ctrl_monitor  ctrl_mon;
    ddr_ring_axi_mem_model mem_model;
    ddr_ring_scoreboard    scb;

    function new(string name = "ddr_ring_env", uvm_component parent = null);
      super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      src_agent = ddr_ring_source_agent::type_id::create("src_agent", this);
      rd_mon    = ddr_ring_read_monitor::type_id::create("rd_mon", this);
      ctrl_mon  = ddr_ring_ctrl_monitor::type_id::create("ctrl_mon", this);
      mem_model = ddr_ring_axi_mem_model::type_id::create("mem_model", this);
      scb       = ddr_ring_scoreboard::type_id::create("scb", this);
    endfunction

    function void connect_phase(uvm_phase phase);
      super.connect_phase(phase);
      src_agent.drv.exp_ap.connect(scb.exp_imp);
      ctrl_mon.commit_ap.connect(scb.commit_imp);
      rd_mon.read_ap.connect(scb.read_imp);
      scb.mem_model = mem_model;
    endfunction
  endclass

  class ddr_ring_program_sequence extends uvm_sequence #(ddr_ring_slot_item);
    `uvm_object_utils(ddr_ring_program_sequence)

    ddr_ring_slot_item items[$];

    function new(string name = "ddr_ring_program_sequence");
      super.new(name);
    endfunction

    virtual task body();
      ddr_ring_slot_item seq_item;
      foreach (items[idx]) begin
        seq_item = items[idx].dup($sformatf("slot_%0d", idx));
        start_item(seq_item);
        finish_item(seq_item);
      end
    endtask
  endclass

  class ddr_ring_base_sequence extends uvm_sequence #(ddr_ring_slot_item);
    `uvm_object_utils(ddr_ring_base_sequence)

    function new(string name = "ddr_ring_base_sequence");
      super.new(name);
    endfunction

    virtual task send_slot(input int unsigned byte_count, input bit [TB_SLOT_SEQ_W-1:0] slot_seq,
                           input byte unsigned seed, input bit slot_valid_good = 1'b1,
                           input bit slot_overflow_err = 1'b0);
      ddr_ring_slot_item item;

      item = ddr_ring_slot_item::type_id::create("item");
      start_item(item);
      item.slot_seq          = slot_seq;
      item.slot_valid_good   = slot_valid_good;
      item.slot_overflow_err = slot_overflow_err;
      item.payload.delete();
      for (int unsigned idx = 0; idx < byte_count; idx++) begin
        item.payload.push_back(byte'((seed + idx) & 8'hff));
      end
      finish_item(item);
    endtask
  endclass

  class ddr_ring_smoke_sequence extends ddr_ring_base_sequence;
    `uvm_object_utils(ddr_ring_smoke_sequence)

    function new(string name = "ddr_ring_smoke_sequence");
      super.new(name);
    endfunction

    task body();
      send_slot(48, 16'h10, 8'h21);
      send_slot(80, 16'h11, 8'h61);
    endtask
  endclass

  class ddr_ring_wrap_phase1_sequence extends ddr_ring_base_sequence;
    `uvm_object_utils(ddr_ring_wrap_phase1_sequence)

    function new(string name = "ddr_ring_wrap_phase1_sequence");
      super.new(name);
    endfunction

    task body();
      send_slot(96, 16'h20, 8'h10);
    endtask
  endclass

  class ddr_ring_wrap_phase2_sequence extends ddr_ring_base_sequence;
    `uvm_object_utils(ddr_ring_wrap_phase2_sequence)

    function new(string name = "ddr_ring_wrap_phase2_sequence");
      super.new(name);
    endfunction

    task body();
      send_slot(80, 16'h21, 8'h90);
    endtask
  endclass

  class ddr_ring_base_test extends uvm_test;
    `uvm_component_utils(ddr_ring_base_test)

    ddr_ring_env           m_env;
    ddr_ringbuffer_env_cfg m_cfg;

    function new(string name = "ddr_ring_base_test", uvm_component parent = null);
      super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
      super.build_phase(phase);

      m_cfg = ddr_ringbuffer_env_cfg::type_id::create("m_cfg");
      if (!uvm_config_db#(virtual axis_stream_if #(TB_AXIS_DATA_W, TB_AXIS_USER_W))::get(
              this, "", "src_vif", m_cfg.src_vif
          )) begin
        `uvm_fatal(get_type_name(), "src_vif not found")
      end
      if (!uvm_config_db#(virtual axis_stream_if #(TB_AXI_DATA_W, TB_RD_AXIS_USER_W))::get(
              this, "", "rd_vif", m_cfg.rd_vif
          )) begin
        `uvm_fatal(get_type_name(), "rd_vif not found")
      end
      if (!uvm_config_db#(virtual axi4_mm_if #(TB_AXI_ADDR_W, TB_AXI_DATA_W))::get(
              this, "", "axi_vif", m_cfg.axi_vif
          )) begin
        `uvm_fatal(get_type_name(), "axi_vif not found")
      end
      if (!uvm_config_db#(virtual ddr_ringbuffer_ctrl_if #(
                    TB_AXI_ADDR_W,
                    TB_RING_BYTES_W,
                    TB_SLOT_BYTES_W,
                    TB_SLOT_SEQ_W,
                    TB_COUNTER_W
                ))::get(
              this, "", "ctrl_vif", m_cfg.ctrl_vif
          )) begin
        `uvm_fatal(get_type_name(), "ctrl_vif not found")
      end

      m_cfg.cfg_enable            = 1'b1;
      m_cfg.cfg_allow_overwrite   = 1'b0;
      m_cfg.cfg_drop_invalid_slot = 1'b1;
      m_cfg.cfg_drop_on_no_space  = 1'b0;
      m_cfg.cfg_ring_base_addr    = TB_AXI_ADDR_W'(34'h0000_1000);
      m_cfg.cfg_ring_size_bytes   = TB_RING_BYTES_W'(256);

      uvm_config_db#(ddr_ringbuffer_env_cfg)::set(this, "*", "env_cfg", m_cfg);
      m_env = ddr_ring_env::type_id::create("m_env", this);
    endfunction

    virtual task clear_drive_pulses();
      m_cfg.ctrl_vif.drv_cb.rd_slot_req <= 1'b0;
      m_cfg.ctrl_vif.drv_cb.rd_consume  <= 1'b0;
    endtask

    virtual task apply_cfg();
      m_cfg.ctrl_vif.drv_cb.cfg_enable            <= m_cfg.cfg_enable;
      m_cfg.ctrl_vif.drv_cb.cfg_allow_overwrite   <= m_cfg.cfg_allow_overwrite;
      m_cfg.ctrl_vif.drv_cb.cfg_drop_invalid_slot <= m_cfg.cfg_drop_invalid_slot;
      m_cfg.ctrl_vif.drv_cb.cfg_drop_on_no_space  <= m_cfg.cfg_drop_on_no_space;
      m_cfg.ctrl_vif.drv_cb.cfg_ring_base_addr    <= m_cfg.cfg_ring_base_addr;
      m_cfg.ctrl_vif.drv_cb.cfg_ring_size_bytes   <= m_cfg.cfg_ring_size_bytes;
      clear_drive_pulses();
      @(m_cfg.ctrl_vif.drv_cb);
    endtask

    virtual task issue_read_request();
      m_cfg.ctrl_vif.drv_cb.rd_slot_req <= 1'b1;
      @(m_cfg.ctrl_vif.drv_cb);
      m_cfg.ctrl_vif.drv_cb.rd_slot_req <= 1'b0;
    endtask

    virtual task issue_consume();
      m_cfg.ctrl_vif.drv_cb.rd_consume <= 1'b1;
      @(m_cfg.ctrl_vif.drv_cb);
      m_cfg.ctrl_vif.drv_cb.rd_consume <= 1'b0;
    endtask

    virtual task drain_one_slot();
      wait (m_cfg.ctrl_vif.rd_slot_valid === 1'b1);
      issue_read_request();
      do begin
        @(m_cfg.ctrl_vif.mon_cb);
      end while (!(m_cfg.ctrl_vif.mon_cb.rd_done || m_cfg.ctrl_vif.mon_cb.rd_error));

      if (m_cfg.ctrl_vif.mon_cb.rd_error) begin
        `uvm_fatal(get_type_name(), "Read side reported rd_error")
      end

      issue_consume();
      @(m_cfg.ctrl_vif.mon_cb);
    endtask

    virtual task drain_slots(input int unsigned slot_count);
      for (int unsigned idx = 0; idx < slot_count; idx++) begin
        drain_one_slot();
      end
    endtask

    virtual task run_test_sequence();
      ddr_ring_smoke_sequence seq;
      seq = ddr_ring_smoke_sequence::type_id::create("seq");
      seq.start(m_env.src_agent.seqr);
      drain_slots(2);
    endtask

    task run_phase(uvm_phase phase);
      phase.raise_objection(this);
      wait (m_cfg.ctrl_vif.rst_ni === 1'b1);
      apply_cfg();
      run_test_sequence();
      repeat (32) @(m_cfg.ctrl_vif.mon_cb);
      if (!m_env.scb.is_idle()) begin
        `uvm_error(get_type_name(), "Scoreboard is not idle before test ends")
      end
      phase.drop_objection(this);
    endtask
  endclass

  class ddr_ring_smoke_test extends ddr_ring_base_test;
    `uvm_component_utils(ddr_ring_smoke_test)

    function new(string name = "ddr_ring_smoke_test", uvm_component parent = null);
      super.new(name, parent);
    endfunction
  endclass

  class ddr_ring_wrap_test extends ddr_ring_base_test;
    `uvm_component_utils(ddr_ring_wrap_test)

    function new(string name = "ddr_ring_wrap_test", uvm_component parent = null);
      super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
      super.build_phase(phase);
      m_cfg.cfg_ring_size_bytes = TB_RING_BYTES_W'(160);
    endfunction

    virtual task run_test_sequence();
      ddr_ring_wrap_phase1_sequence seq1;
      ddr_ring_wrap_phase2_sequence seq2;

      seq1 = ddr_ring_wrap_phase1_sequence::type_id::create("seq1");
      seq1.start(m_env.src_agent.seqr);
      drain_slots(1);

      seq2 = ddr_ring_wrap_phase2_sequence::type_id::create("seq2");
      seq2.start(m_env.src_agent.seqr);
      drain_slots(1);

      if (m_cfg.ctrl_vif.wrap_count == '0) begin
        `uvm_error(get_type_name(), "Expected wrap_count to increment in wrap test")
      end
    endtask
  endclass

endpackage
