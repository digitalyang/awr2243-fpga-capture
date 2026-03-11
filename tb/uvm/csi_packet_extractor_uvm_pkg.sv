`include "csi_packet_extractor_macros.svh"

package csi_packet_extractor_uvm_pkg;

    import uvm_pkg::*;
    import csi_packet_pkg::*;
    `include "uvm_macros.svh"

    localparam int unsigned TB_AXIS_DATA_W     = `CSI_AXIS_DATA_W_DFLT;
    localparam int unsigned TB_AXIS_USER_W     = `CSI_AXIS_USER_W_DFLT;
    localparam int unsigned TB_AXIS_KEEP_W     = TB_AXIS_DATA_W / 8;
    localparam int unsigned TB_AXIS_BEAT_BYTES = TB_AXIS_DATA_W / 8;
    localparam int unsigned TB_VC_W            = CSI_VC_W;
    localparam int unsigned TB_DT_W            = CSI_DT_W;
    localparam int unsigned TB_PAYLOAD_LEN_W   = CSI_WORD_COUNT_W;
    localparam int unsigned TB_PKT_SEQ_W       = `CSI_PKT_SEQ_W_DFLT;
    localparam int unsigned TB_PKT_BYTE_CNT_W  = clog2_safe((1 << CSI_WORD_COUNT_W));

    typedef enum int unsigned {
        META_KIND_START,
        META_KIND_DONE
    } csi_meta_kind_e;

    `uvm_analysis_imp_decl(_exp)
    `uvm_analysis_imp_decl(_act)
    `uvm_analysis_imp_decl(_meta)

    function automatic logic [TB_AXIS_USER_W-1:0] build_tuser(
        input logic [TB_VC_W-1:0]          vc,
        input logic [TB_DT_W-1:0]          dt,
        input logic [TB_PAYLOAD_LEN_W-1:0] payload_len,
        input logic                        crc_err,
        input logic                        ecc_err,
        input logic                        trunc_err,
        input logic                        pkt_start
    );
        logic [TB_AXIS_USER_W-1:0] user_c;
        begin
            user_c = '0;
            user_c[CSI_TUSER_PKT_START_BIT_DFLT] = pkt_start;
            user_c[CSI_TUSER_CRC_ERR_BIT_DFLT]   = crc_err;
            user_c[CSI_TUSER_ECC_ERR_BIT_DFLT]   = ecc_err;
            user_c[CSI_TUSER_TRUNC_ERR_BIT_DFLT] = trunc_err;
            user_c[CSI_TUSER_VC_LSB_DFLT +: TB_VC_W] = vc;
            user_c[CSI_TUSER_DT_LSB_DFLT +: TB_DT_W] = dt;
            user_c[CSI_TUSER_PAYLOAD_LEN_LSB_DFLT +: TB_PAYLOAD_LEN_W] = payload_len;
            return user_c;
        end
    endfunction

    class csi_axis_packet_item extends uvm_sequence_item;
        rand bit [TB_VC_W-1:0] vc;
        rand bit [TB_DT_W-1:0] dt;
        rand int unsigned      declared_payload_nbytes;
        rand byte unsigned     payload[$];
        rand bit               crc_err_first;
        rand bit               ecc_err_first;
        rand bit               trunc_err_first;
        rand bit               crc_err_last;
        rand bit               ecc_err_last;
        rand bit               trunc_err_last;

        constraint c_payload_size {
            payload.size() inside {[1 : (TB_AXIS_BEAT_BYTES * 8)]};
            declared_payload_nbytes inside {[1 : (TB_AXIS_BEAT_BYTES * 8)]};
        }

        `uvm_object_utils_begin(csi_axis_packet_item)
            `uvm_field_int(vc, UVM_DEFAULT)
            `uvm_field_int(dt, UVM_DEFAULT)
            `uvm_field_int(declared_payload_nbytes, UVM_DEFAULT)
            `uvm_field_queue_int(payload, UVM_DEFAULT)
            `uvm_field_int(crc_err_first, UVM_DEFAULT)
            `uvm_field_int(ecc_err_first, UVM_DEFAULT)
            `uvm_field_int(trunc_err_first, UVM_DEFAULT)
            `uvm_field_int(crc_err_last, UVM_DEFAULT)
            `uvm_field_int(ecc_err_last, UVM_DEFAULT)
            `uvm_field_int(trunc_err_last, UVM_DEFAULT)
        `uvm_object_utils_end

        function new(string name = "csi_axis_packet_item");
            super.new(name);
        endfunction

        function void post_randomize();
            foreach (payload[idx]) begin
                payload[idx] = byte'(idx);
            end
        endfunction

        function int unsigned actual_nbytes();
            return payload.size();
        endfunction

        function string convert2string();
            return $sformatf(
                "vc=0x%0h dt=0x%0h declared=%0d actual=%0d err_first=%0b%0b%0b err_last=%0b%0b%0b",
                vc,
                dt,
                declared_payload_nbytes,
                payload.size(),
                crc_err_first,
                ecc_err_first,
                trunc_err_first,
                crc_err_last,
                ecc_err_last,
                trunc_err_last
            );
        endfunction
    endclass

    class csi_expected_packet extends uvm_object;
        bit [TB_PKT_SEQ_W-1:0]      pkt_seq;
        int unsigned                pkt_bytes;
        bit                         pkt_valid_good;
        bit                         pkt_crc_err;
        bit                         pkt_ecc_err;
        bit                         pkt_trunc_err;
        byte unsigned               payload[$];

        `uvm_object_utils_begin(csi_expected_packet)
            `uvm_field_int(pkt_seq, UVM_DEFAULT)
            `uvm_field_int(pkt_bytes, UVM_DEFAULT)
            `uvm_field_int(pkt_valid_good, UVM_DEFAULT)
            `uvm_field_int(pkt_crc_err, UVM_DEFAULT)
            `uvm_field_int(pkt_ecc_err, UVM_DEFAULT)
            `uvm_field_int(pkt_trunc_err, UVM_DEFAULT)
            `uvm_field_queue_int(payload, UVM_DEFAULT)
        `uvm_object_utils_end

        function new(string name = "csi_expected_packet");
            super.new(name);
        endfunction
    endclass

    class csi_pkt_meta_item extends uvm_sequence_item;
        csi_meta_kind_e             kind;
        bit [TB_PKT_SEQ_W-1:0]      pkt_seq;
        int unsigned                pkt_bytes;
        bit                         pkt_valid_good;
        bit                         pkt_crc_err;
        bit                         pkt_ecc_err;
        bit                         pkt_trunc_err;

        `uvm_object_utils_begin(csi_pkt_meta_item)
            `uvm_field_enum(csi_meta_kind_e, kind, UVM_DEFAULT)
            `uvm_field_int(pkt_seq, UVM_DEFAULT)
            `uvm_field_int(pkt_bytes, UVM_DEFAULT)
            `uvm_field_int(pkt_valid_good, UVM_DEFAULT)
            `uvm_field_int(pkt_crc_err, UVM_DEFAULT)
            `uvm_field_int(pkt_ecc_err, UVM_DEFAULT)
            `uvm_field_int(pkt_trunc_err, UVM_DEFAULT)
        `uvm_object_utils_end

        function new(string name = "csi_pkt_meta_item");
            super.new(name);
        endfunction
    endclass

    class csi_extractor_env_cfg extends uvm_object;
        virtual axis_stream_if #(TB_AXIS_DATA_W, TB_AXIS_USER_W) src_vif;
        virtual axis_stream_if #(TB_AXIS_DATA_W, TB_AXIS_USER_W) dst_vif;
        virtual csi_packet_extractor_ctrl_if #(
            TB_VC_W,
            TB_DT_W,
            TB_PKT_SEQ_W,
            TB_PKT_BYTE_CNT_W
        ) ctrl_vif;

        bit [TB_VC_W-1:0] cfg_vc;
        bit [TB_DT_W-1:0] cfg_dt;
        bit               cfg_vc_en;
        bit               cfg_dt_en;

        `uvm_object_utils_begin(csi_extractor_env_cfg)
            `uvm_field_int(cfg_vc, UVM_DEFAULT)
            `uvm_field_int(cfg_dt, UVM_DEFAULT)
            `uvm_field_int(cfg_vc_en, UVM_DEFAULT)
            `uvm_field_int(cfg_dt_en, UVM_DEFAULT)
        `uvm_object_utils_end

        function new(string name = "csi_extractor_env_cfg");
            super.new(name);
        endfunction
    endclass

    class csi_source_sequencer extends uvm_sequencer #(csi_axis_packet_item);
        `uvm_component_utils(csi_source_sequencer)

        function new(string name = "csi_source_sequencer", uvm_component parent = null);
            super.new(name, parent);
        endfunction
    endclass

    class csi_source_driver extends uvm_driver #(csi_axis_packet_item);
        `uvm_component_utils(csi_source_driver)

        csi_extractor_env_cfg cfg;
        uvm_analysis_port #(csi_axis_packet_item) exp_ap;

        function new(string name = "csi_source_driver", uvm_component parent = null);
            super.new(name, parent);
            exp_ap = new("exp_ap", this);
        endfunction

        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(csi_extractor_env_cfg)::get(this, "", "env_cfg", cfg)) begin
                `uvm_fatal(get_type_name(), "env_cfg is not set for csi_source_driver")
            end
        endfunction

        task reset_signals();
            cfg.src_vif.tdata  <= '0;
            cfg.src_vif.tkeep  <= '0;
            cfg.src_vif.tvalid <= 1'b0;
            cfg.src_vif.tlast  <= 1'b0;
            cfg.src_vif.tuser  <= '0;
        endtask

        task run_phase(uvm_phase phase);
            csi_axis_packet_item req_item;

            reset_signals();
            wait (cfg.ctrl_vif.rst_ni === 1'b1);

            forever begin
                seq_item_port.get_next_item(req_item);
                exp_ap.write(req_item);
                drive_packet(req_item);
                seq_item_port.item_done();
            end
        endtask

        task drive_packet(csi_axis_packet_item item);
            int unsigned beat_idx;
            int unsigned beat_count;
            int unsigned lane_idx;
            int unsigned byte_offset;
            logic [TB_AXIS_DATA_W-1:0] beat_data_c;
            logic [TB_AXIS_KEEP_W-1:0] beat_keep_c;
            logic [TB_AXIS_USER_W-1:0] beat_user_c;

            beat_count = (item.payload.size() + TB_AXIS_BEAT_BYTES - 1) / TB_AXIS_BEAT_BYTES;

            for (beat_idx = 0; beat_idx < beat_count; beat_idx++) begin
                beat_data_c = '0;
                beat_keep_c = '0;

                for (lane_idx = 0; lane_idx < TB_AXIS_BEAT_BYTES; lane_idx++) begin
                    byte_offset = (beat_idx * TB_AXIS_BEAT_BYTES) + lane_idx;
                    if (byte_offset < item.payload.size()) begin
                        beat_data_c[(lane_idx * 8) +: 8] = item.payload[byte_offset];
                        beat_keep_c[lane_idx] = 1'b1;
                    end
                end

                beat_user_c = build_tuser(
                    item.vc,
                    item.dt,
                    TB_PAYLOAD_LEN_W'(item.declared_payload_nbytes),
                    ((beat_idx == 0) ? item.crc_err_first   : 1'b0) | ((beat_idx == (beat_count - 1)) ? item.crc_err_last   : 1'b0),
                    ((beat_idx == 0) ? item.ecc_err_first   : 1'b0) | ((beat_idx == (beat_count - 1)) ? item.ecc_err_last   : 1'b0),
                    ((beat_idx == 0) ? item.trunc_err_first : 1'b0) | ((beat_idx == (beat_count - 1)) ? item.trunc_err_last : 1'b0),
                    (beat_idx == 0)
                );

                cfg.src_vif.tdata  <= beat_data_c;
                cfg.src_vif.tkeep  <= beat_keep_c;
                cfg.src_vif.tvalid <= 1'b1;
                cfg.src_vif.tlast  <= (beat_idx == (beat_count - 1));
                cfg.src_vif.tuser  <= beat_user_c;

                do begin
                    @(posedge cfg.ctrl_vif.clk);
                end while (!(cfg.src_vif.tvalid && cfg.src_vif.tready));
            end

            reset_signals();
            @(posedge cfg.ctrl_vif.clk);
        endtask
    endclass

    class csi_source_agent extends uvm_agent;
        `uvm_component_utils(csi_source_agent)

        csi_source_sequencer seqr;
        csi_source_driver    drv;

        function new(string name = "csi_source_agent", uvm_component parent = null);
            super.new(name, parent);
        endfunction

        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            seqr = csi_source_sequencer::type_id::create("seqr", this);
            drv  = csi_source_driver::type_id::create("drv", this);
        endfunction

        function void connect_phase(uvm_phase phase);
            super.connect_phase(phase);
            drv.seq_item_port.connect(seqr.seq_item_export);
        endfunction
    endclass

    class csi_output_monitor extends uvm_component;
        `uvm_component_utils(csi_output_monitor)

        csi_extractor_env_cfg                  cfg;
        uvm_analysis_port #(csi_axis_packet_item) act_ap;

        function new(string name = "csi_output_monitor", uvm_component parent = null);
            super.new(name, parent);
            act_ap = new("act_ap", this);
        endfunction

        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(csi_extractor_env_cfg)::get(this, "", "env_cfg", cfg)) begin
                `uvm_fatal(get_type_name(), "env_cfg is not set for csi_output_monitor")
            end
        endfunction

        task run_phase(uvm_phase phase);
            csi_axis_packet_item pkt_item;
            int unsigned         lane_idx;

            pkt_item = null;
            wait (cfg.ctrl_vif.rst_ni === 1'b1);

            forever begin
                @(posedge cfg.ctrl_vif.clk);

                if (cfg.dst_vif.tvalid && cfg.dst_vif.tready) begin
                    if (pkt_item == null) begin
                        pkt_item = csi_axis_packet_item::type_id::create("pkt_item");
                        pkt_item.vc = cfg.dst_vif.tuser[CSI_TUSER_VC_LSB_DFLT +: TB_VC_W];
                        pkt_item.dt = cfg.dst_vif.tuser[CSI_TUSER_DT_LSB_DFLT +: TB_DT_W];
                        pkt_item.declared_payload_nbytes =
                            cfg.dst_vif.tuser[CSI_TUSER_PAYLOAD_LEN_LSB_DFLT +: TB_PAYLOAD_LEN_W];
                    end

                    for (lane_idx = 0; lane_idx < TB_AXIS_BEAT_BYTES; lane_idx++) begin
                        if (cfg.dst_vif.tkeep[lane_idx]) begin
                            pkt_item.payload.push_back(byte'(cfg.dst_vif.tdata[(lane_idx * 8) +: 8]));
                        end
                    end

                    if (cfg.dst_vif.tlast) begin
                        act_ap.write(pkt_item);
                        pkt_item = null;
                    end
                end
            end
        endtask
    endclass

    class csi_ctrl_monitor extends uvm_component;
        `uvm_component_utils(csi_ctrl_monitor)

        csi_extractor_env_cfg              cfg;
        uvm_analysis_port #(csi_pkt_meta_item) meta_ap;

        function new(string name = "csi_ctrl_monitor", uvm_component parent = null);
            super.new(name, parent);
            meta_ap = new("meta_ap", this);
        endfunction

        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(csi_extractor_env_cfg)::get(this, "", "env_cfg", cfg)) begin
                `uvm_fatal(get_type_name(), "env_cfg is not set for csi_ctrl_monitor")
            end
        endfunction

        task run_phase(uvm_phase phase);
            csi_pkt_meta_item meta_item;

            wait (cfg.ctrl_vif.rst_ni === 1'b1);

            forever begin
                @(cfg.ctrl_vif.mon_cb);

                if (cfg.ctrl_vif.mon_cb.pkt_start) begin
                    meta_item = csi_pkt_meta_item::type_id::create("meta_start");
                    meta_item.kind           = META_KIND_START;
                    meta_item.pkt_seq        = cfg.ctrl_vif.mon_cb.pkt_seq;
                    meta_item.pkt_bytes      = cfg.ctrl_vif.mon_cb.pkt_bytes;
                    meta_item.pkt_valid_good = cfg.ctrl_vif.mon_cb.pkt_valid_good;
                    meta_item.pkt_crc_err    = cfg.ctrl_vif.mon_cb.pkt_crc_err;
                    meta_item.pkt_ecc_err    = cfg.ctrl_vif.mon_cb.pkt_ecc_err;
                    meta_item.pkt_trunc_err  = cfg.ctrl_vif.mon_cb.pkt_trunc_err;
                    meta_ap.write(meta_item);
                end

                if (cfg.ctrl_vif.mon_cb.pkt_done) begin
                    meta_item = csi_pkt_meta_item::type_id::create("meta_done");
                    meta_item.kind           = META_KIND_DONE;
                    meta_item.pkt_seq        = cfg.ctrl_vif.mon_cb.pkt_seq;
                    meta_item.pkt_bytes      = cfg.ctrl_vif.mon_cb.pkt_bytes;
                    meta_item.pkt_valid_good = cfg.ctrl_vif.mon_cb.pkt_valid_good;
                    meta_item.pkt_crc_err    = cfg.ctrl_vif.mon_cb.pkt_crc_err;
                    meta_item.pkt_ecc_err    = cfg.ctrl_vif.mon_cb.pkt_ecc_err;
                    meta_item.pkt_trunc_err  = cfg.ctrl_vif.mon_cb.pkt_trunc_err;
                    meta_ap.write(meta_item);
                end
            end
        endtask
    endclass

    class csi_scoreboard extends uvm_component;
        `uvm_component_utils(csi_scoreboard)

        csi_extractor_env_cfg cfg;
        uvm_analysis_imp_exp  #(csi_axis_packet_item, csi_scoreboard) exp_imp;
        uvm_analysis_imp_act  #(csi_axis_packet_item, csi_scoreboard) act_imp;
        uvm_analysis_imp_meta #(csi_pkt_meta_item,   csi_scoreboard) meta_imp;

        csi_expected_packet exp_data_q[$];
        csi_expected_packet exp_meta_q[$];
        bit [TB_PKT_SEQ_W-1:0] exp_start_q[$];
        int unsigned next_exp_seq;
        int unsigned error_count;

        function new(string name = "csi_scoreboard", uvm_component parent = null);
            super.new(name, parent);
            exp_imp  = new("exp_imp", this);
            act_imp  = new("act_imp", this);
            meta_imp = new("meta_imp", this);
            next_exp_seq = '0;
            error_count  = 0;
        endfunction

        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(csi_extractor_env_cfg)::get(this, "", "env_cfg", cfg)) begin
                `uvm_fatal(get_type_name(), "env_cfg is not set for csi_scoreboard")
            end
        endfunction

        function bit packet_matches(csi_axis_packet_item item);
            bit vc_hit;
            bit dt_hit;
            begin
                vc_hit = (!cfg.cfg_vc_en) || (item.vc == cfg.cfg_vc);
                dt_hit = (!cfg.cfg_dt_en) || (item.dt == cfg.cfg_dt);
                return vc_hit && dt_hit;
            end
        endfunction

        function csi_expected_packet build_expected(csi_axis_packet_item item);
            csi_expected_packet exp_item;
            begin
                exp_item = csi_expected_packet::type_id::create("exp_item");
                exp_item.pkt_seq        = next_exp_seq[TB_PKT_SEQ_W-1:0];
                exp_item.pkt_bytes      = item.payload.size();
                exp_item.pkt_crc_err    = item.crc_err_first | item.crc_err_last;
                exp_item.pkt_ecc_err    = item.ecc_err_first | item.ecc_err_last;
                exp_item.pkt_trunc_err  = item.trunc_err_first |
                                          item.trunc_err_last  |
                                          (item.declared_payload_nbytes != item.payload.size());
                exp_item.pkt_valid_good = !(exp_item.pkt_crc_err || exp_item.pkt_ecc_err || exp_item.pkt_trunc_err);
                foreach (item.payload[idx]) begin
                    exp_item.payload.push_back(item.payload[idx]);
                end
                next_exp_seq++;
                return exp_item;
            end
        endfunction

        function void push_error(string msg);
            error_count++;
            `uvm_error(get_type_name(), msg)
        endfunction

        function void write_exp(csi_axis_packet_item item);
            csi_expected_packet exp_item;
            csi_expected_packet meta_item;
            begin
                if (packet_matches(item)) begin
                    exp_item = build_expected(item);
                    meta_item = csi_expected_packet::type_id::create("meta_item");
                    meta_item.copy(exp_item);
                    exp_start_q.push_back(exp_item.pkt_seq);
                    exp_data_q.push_back(exp_item);
                    exp_meta_q.push_back(meta_item);
                    `uvm_info(get_type_name(), $sformatf("Expect accept: %s", item.convert2string()), UVM_MEDIUM)
                end else begin
                    `uvm_info(get_type_name(), $sformatf("Expect drop: %s", item.convert2string()), UVM_MEDIUM)
                end
            end
        endfunction

        function void write_act(csi_axis_packet_item item);
            csi_expected_packet exp_item;
            begin
                if (exp_data_q.size() == 0) begin
                    push_error($sformatf("Unexpected output packet, actual bytes=%0d", item.payload.size()));
                    return;
                end

                exp_item = exp_data_q.pop_front();
                if (item.payload.size() != exp_item.payload.size()) begin
                    push_error($sformatf("Payload byte count mismatch, exp=%0d act=%0d",
                                         exp_item.payload.size(), item.payload.size()));
                end

                foreach (exp_item.payload[idx]) begin
                    if ((idx >= item.payload.size()) || (item.payload[idx] != exp_item.payload[idx])) begin
                        push_error($sformatf("Payload mismatch at byte %0d, exp=0x%0h",
                                             idx,
                                             exp_item.payload[idx]));
                        break;
                    end
                end
            end
        endfunction

        function void write_meta(csi_pkt_meta_item item);
            csi_expected_packet exp_item;
            bit [TB_PKT_SEQ_W-1:0] exp_seq;
            begin
                case (item.kind)
                    META_KIND_START: begin
                        if (exp_start_q.size() == 0) begin
                            push_error($sformatf("Unexpected pkt_start, seq=%0d", item.pkt_seq));
                            return;
                        end

                        exp_seq = exp_start_q.pop_front();
                        if (item.pkt_seq != exp_seq) begin
                            push_error($sformatf("pkt_start seq mismatch, exp=%0d act=%0d",
                                                 exp_seq, item.pkt_seq));
                        end
                    end

                    META_KIND_DONE: begin
                        if (exp_meta_q.size() == 0) begin
                            push_error($sformatf("Unexpected pkt_done, seq=%0d", item.pkt_seq));
                            return;
                        end

                        exp_item = exp_meta_q.pop_front();
                        if (item.pkt_seq != exp_item.pkt_seq) begin
                            push_error($sformatf("pkt_done seq mismatch, exp=%0d act=%0d",
                                                 exp_item.pkt_seq, item.pkt_seq));
                        end
                        if (item.pkt_bytes != exp_item.pkt_bytes) begin
                            push_error($sformatf("pkt_done bytes mismatch, exp=%0d act=%0d",
                                                 exp_item.pkt_bytes, item.pkt_bytes));
                        end
                        if (item.pkt_crc_err != exp_item.pkt_crc_err) begin
                            push_error($sformatf("pkt_done crc_err mismatch, exp=%0b act=%0b",
                                                 exp_item.pkt_crc_err, item.pkt_crc_err));
                        end
                        if (item.pkt_ecc_err != exp_item.pkt_ecc_err) begin
                            push_error($sformatf("pkt_done ecc_err mismatch, exp=%0b act=%0b",
                                                 exp_item.pkt_ecc_err, item.pkt_ecc_err));
                        end
                        if (item.pkt_trunc_err != exp_item.pkt_trunc_err) begin
                            push_error($sformatf("pkt_done trunc_err mismatch, exp=%0b act=%0b",
                                                 exp_item.pkt_trunc_err, item.pkt_trunc_err));
                        end
                        if (item.pkt_valid_good != exp_item.pkt_valid_good) begin
                            push_error($sformatf("pkt_done valid_good mismatch, exp=%0b act=%0b",
                                                 exp_item.pkt_valid_good, item.pkt_valid_good));
                        end
                    end

                    default: begin
                        push_error("Unknown meta kind");
                    end
                endcase
            end
        endfunction

        function bit is_idle();
            return (exp_start_q.size() == 0) &&
                   (exp_data_q.size()  == 0) &&
                   (exp_meta_q.size()  == 0);
        endfunction

        function void report_phase(uvm_phase phase);
            super.report_phase(phase);
            if (!is_idle()) begin
                push_error($sformatf("Scoreboard still has pending expectations: start=%0d data=%0d meta=%0d",
                                     exp_start_q.size(),
                                     exp_data_q.size(),
                                     exp_meta_q.size()));
            end
            if (error_count == 0) begin
                `uvm_info(get_type_name(), "Scoreboard completed without mismatch", UVM_LOW)
            end
        endfunction
    endclass

    class csi_env extends uvm_env;
        `uvm_component_utils(csi_env)

        csi_source_agent   src_agent;
        csi_output_monitor out_mon;
        csi_ctrl_monitor   ctrl_mon;
        csi_scoreboard     scb;

        function new(string name = "csi_env", uvm_component parent = null);
            super.new(name, parent);
        endfunction

        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            src_agent = csi_source_agent::type_id::create("src_agent", this);
            out_mon   = csi_output_monitor::type_id::create("out_mon", this);
            ctrl_mon  = csi_ctrl_monitor::type_id::create("ctrl_mon", this);
            scb       = csi_scoreboard::type_id::create("scb", this);
        endfunction

        function void connect_phase(uvm_phase phase);
            super.connect_phase(phase);
            src_agent.drv.exp_ap.connect(scb.exp_imp);
            out_mon.act_ap.connect(scb.act_imp);
            ctrl_mon.meta_ap.connect(scb.meta_imp);
        endfunction
    endclass

    class csi_base_sequence extends uvm_sequence #(csi_axis_packet_item);
        `uvm_object_utils(csi_base_sequence)

        function new(string name = "csi_base_sequence");
            super.new(name);
        endfunction

        virtual task send_pkt(
            input bit [TB_VC_W-1:0] vc,
            input bit [TB_DT_W-1:0] dt,
            input int unsigned actual_nbytes,
            input int unsigned declared_nbytes,
            input bit crc_err_first = 1'b0,
            input bit ecc_err_first = 1'b0,
            input bit trunc_err_first = 1'b0,
            input bit crc_err_last = 1'b0,
            input bit ecc_err_last = 1'b0,
            input bit trunc_err_last = 1'b0
        );
            csi_axis_packet_item item;

            item = csi_axis_packet_item::type_id::create("item");
            start_item(item);
            item.vc                      = vc;
            item.dt                      = dt;
            item.declared_payload_nbytes = declared_nbytes;
            item.payload.delete();
            for (int unsigned idx = 0; idx < actual_nbytes; idx++) begin
                item.payload.push_back(byte'(((idx * 13) + actual_nbytes) & 8'hff));
            end
            item.crc_err_first   = crc_err_first;
            item.ecc_err_first   = ecc_err_first;
            item.trunc_err_first = trunc_err_first;
            item.crc_err_last    = crc_err_last;
            item.ecc_err_last    = ecc_err_last;
            item.trunc_err_last  = trunc_err_last;
            finish_item(item);
        endtask
    endclass

    class csi_smoke_sequence extends csi_base_sequence;
        `uvm_object_utils(csi_smoke_sequence)

        function new(string name = "csi_smoke_sequence");
            super.new(name);
        endfunction

        task body();
            send_pkt(2'h1, 6'h2a, 24, 24);
        endtask
    endclass

    class csi_mixed_filter_sequence extends csi_base_sequence;
        `uvm_object_utils(csi_mixed_filter_sequence)

        function new(string name = "csi_mixed_filter_sequence");
            super.new(name);
        endfunction

        task body();
            send_pkt(2'h1, 6'h2a, 40, 40);
            send_pkt(2'h2, 6'h2a, 20, 20);
            send_pkt(2'h1, 6'h15, 12, 12);
            send_pkt(2'h1, 6'h2a, 70, 70);
        endtask
    endclass

    class csi_error_latch_sequence extends csi_base_sequence;
        `uvm_object_utils(csi_error_latch_sequence)

        function new(string name = "csi_error_latch_sequence");
            super.new(name);
        endfunction

        task body();
            send_pkt(2'h1, 6'h2a, 80, 80, 1'b1, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0);
        endtask
    endclass

    class csi_truncation_sequence extends csi_base_sequence;
        `uvm_object_utils(csi_truncation_sequence)

        function new(string name = "csi_truncation_sequence");
            super.new(name);
        endfunction

        task body();
            send_pkt(2'h1, 6'h2a, 20, 24);
            send_pkt(2'h1, 6'h2a, 48, 32, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1);
        endtask
    endclass

    class csi_base_test extends uvm_test;
        `uvm_component_utils(csi_base_test)

        csi_env               m_env;
        csi_extractor_env_cfg m_cfg;

        function new(string name = "csi_base_test", uvm_component parent = null);
            super.new(name, parent);
        endfunction

        function void build_phase(uvm_phase phase);
            super.build_phase(phase);

            m_cfg = csi_extractor_env_cfg::type_id::create("m_cfg");
            if (!uvm_config_db#(virtual axis_stream_if #(TB_AXIS_DATA_W, TB_AXIS_USER_W))::get(this, "", "src_vif", m_cfg.src_vif)) begin
                `uvm_fatal(get_type_name(), "src_vif not found")
            end
            if (!uvm_config_db#(virtual axis_stream_if #(TB_AXIS_DATA_W, TB_AXIS_USER_W))::get(this, "", "dst_vif", m_cfg.dst_vif)) begin
                `uvm_fatal(get_type_name(), "dst_vif not found")
            end
            if (!uvm_config_db#(virtual csi_packet_extractor_ctrl_if #(
                    TB_VC_W,
                    TB_DT_W,
                    TB_PKT_SEQ_W,
                    TB_PKT_BYTE_CNT_W
                ))::get(this, "", "ctrl_vif", m_cfg.ctrl_vif)) begin
                `uvm_fatal(get_type_name(), "ctrl_vif not found")
            end

            m_cfg.cfg_vc_en = 1'b1;
            m_cfg.cfg_dt_en = 1'b1;
            m_cfg.cfg_vc    = 2'h1;
            m_cfg.cfg_dt    = 6'h2a;

            uvm_config_db#(csi_extractor_env_cfg)::set(this, "*", "env_cfg", m_cfg);
            m_env = csi_env::type_id::create("m_env", this);
        endfunction

        virtual task apply_cfg();
            m_cfg.ctrl_vif.drv_cb.cfg_vc_en <= m_cfg.cfg_vc_en;
            m_cfg.ctrl_vif.drv_cb.cfg_dt_en <= m_cfg.cfg_dt_en;
            m_cfg.ctrl_vif.drv_cb.cfg_vc    <= m_cfg.cfg_vc;
            m_cfg.ctrl_vif.drv_cb.cfg_dt    <= m_cfg.cfg_dt;
            @(m_cfg.ctrl_vif.drv_cb);
        endtask

        virtual task run_test_sequence();
            csi_smoke_sequence seq;
            seq = csi_smoke_sequence::type_id::create("seq");
            seq.start(m_env.src_agent.seqr);
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

    class csi_smoke_test extends csi_base_test;
        `uvm_component_utils(csi_smoke_test)

        function new(string name = "csi_smoke_test", uvm_component parent = null);
            super.new(name, parent);
        endfunction
    endclass

    class csi_mixed_filter_test extends csi_base_test;
        `uvm_component_utils(csi_mixed_filter_test)

        function new(string name = "csi_mixed_filter_test", uvm_component parent = null);
            super.new(name, parent);
        endfunction

        virtual task run_test_sequence();
            csi_mixed_filter_sequence seq;
            seq = csi_mixed_filter_sequence::type_id::create("seq");
            seq.start(m_env.src_agent.seqr);
        endtask
    endclass

    class csi_error_latch_test extends csi_base_test;
        `uvm_component_utils(csi_error_latch_test)

        function new(string name = "csi_error_latch_test", uvm_component parent = null);
            super.new(name, parent);
        endfunction

        virtual task run_test_sequence();
            csi_error_latch_sequence seq;
            seq = csi_error_latch_sequence::type_id::create("seq");
            seq.start(m_env.src_agent.seqr);
        endtask
    endclass

    class csi_truncation_test extends csi_base_test;
        `uvm_component_utils(csi_truncation_test)

        function new(string name = "csi_truncation_test", uvm_component parent = null);
            super.new(name, parent);
        endfunction

        virtual task run_test_sequence();
            csi_truncation_sequence seq;
            seq = csi_truncation_sequence::type_id::create("seq");
            seq.start(m_env.src_agent.seqr);
        endtask
    endclass

endpackage
