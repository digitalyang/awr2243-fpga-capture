// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_H_
#define VERILATED_VTOP_H_  // guard

#include "verilated.h"
#include "svdpi.h"

class Vtop__Syms;
class Vtop___024root;
class VerilatedFstC;
class Vtop_axi4_mm_if;
class Vtop_axis_stream_if;
class Vtop_ddr_ringbuffer_pkg;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtop VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtop__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = true;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk_i,0,0);
    VL_IN8(&rst_ni,0,0);
    VL_IN8(&cfg_enable_i,0,0);
    VL_IN8(&cfg_allow_overwrite_i,0,0);
    VL_IN8(&cfg_drop_invalid_slot_i,0,0);
    VL_IN8(&cfg_drop_on_no_space_i,0,0);
    VL_IN8(&slot_start_i,0,0);
    VL_IN8(&slot_done_i,0,0);
    VL_IN8(&slot_valid_good_i,0,0);
    VL_IN8(&slot_overflow_err_i,0,0);
    VL_OUT8(&wr_slot_commit_o,0,0);
    VL_OUT8(&wr_slot_valid_good_o,0,0);
    VL_OUT8(&wr_slot_overflow_err_o,0,0);
    VL_IN8(&rd_slot_req_i,0,0);
    VL_IN8(&rd_consume_i,0,0);
    VL_OUT8(&rd_slot_valid_o,0,0);
    VL_OUT8(&rd_slot_valid_good_o,0,0);
    VL_OUT8(&rd_slot_overflow_err_o,0,0);
    VL_OUT8(&rd_busy_o,0,0);
    VL_OUT8(&rd_done_o,0,0);
    VL_OUT8(&rd_error_o,0,0);
    VL_OUT8(&full_o,0,0);
    VL_OUT8(&almost_full_o,0,0);
    VL_OUT8(&empty_o,0,0);
    VL_OUT8(&err_cfg_align_o,0,0);
    VL_OUT8(&err_no_space_o,0,0);
    VL_OUT8(&err_slot_proto_o,0,0);
    VL_OUT8(&err_slot_too_large_o,0,0);
    VL_OUT8(&err_axi_wr_resp_o,0,0);
    VL_OUT8(&err_axi_rd_resp_o,0,0);
    VL_OUT8(&err_illegal_read_o,0,0);
    VL_OUT8(&dbg_wr_state_o,3,0);
    VL_OUT8(&dbg_rd_state_o,2,0);
    VL_OUT8(&dbg_wr_burst_beats_o,7,0);
    VL_OUT8(&dbg_wr_burst_sent_o,7,0);
    VL_IN8(&s_axis_slot_tvalid,0,0);
    VL_OUT8(&s_axis_slot_tready,0,0);
    VL_IN8(&s_axis_slot_tlast,0,0);
    VL_OUT8(&m_axis_rd_tvalid,0,0);
    VL_IN8(&m_axis_rd_tready,0,0);
    VL_OUT8(&m_axis_rd_tlast,0,0);
    VL_OUT8(&m_axi_awlen,7,0);
    VL_OUT8(&m_axi_awsize,2,0);
    VL_OUT8(&m_axi_awburst,1,0);
    VL_OUT8(&m_axi_awvalid,0,0);
    VL_IN8(&m_axi_awready,0,0);
    VL_OUT8(&m_axi_wlast,0,0);
    VL_OUT8(&m_axi_wvalid,0,0);
    VL_IN8(&m_axi_wready,0,0);
    VL_IN8(&m_axi_bresp,1,0);
    VL_IN8(&m_axi_bvalid,0,0);
    VL_OUT8(&m_axi_bready,0,0);
    VL_OUT8(&m_axi_arlen,7,0);
    VL_OUT8(&m_axi_arsize,2,0);
    VL_OUT8(&m_axi_arburst,1,0);
    VL_OUT8(&m_axi_arvalid,0,0);
    VL_IN8(&m_axi_arready,0,0);
    VL_IN8(&m_axi_rresp,1,0);
    VL_IN8(&m_axi_rlast,0,0);
    VL_IN8(&m_axi_rvalid,0,0);
    VL_OUT8(&m_axi_rready,0,0);
    VL_IN16(&slot_seq_i,15,0);
    VL_OUT16(&wr_slot_seq_o,15,0);
    VL_OUT16(&rd_slot_seq_o,15,0);
    VL_IN(&cfg_ring_size_bytes_i,16,0);
    VL_IN(&slot_bytes_i,16,0);
    VL_OUT(&wr_slot_bytes_o,16,0);
    VL_OUT(&rd_slot_bytes_o,16,0);
    VL_OUT(&used_bytes_o,16,0);
    VL_OUT(&free_bytes_o,16,0);
    VL_OUT(&committed_bytes_o,16,0);
    VL_OUT(&wrap_count_o,31,0);
    VL_OUT(&overflow_count_o,31,0);
    VL_OUT(&drop_count_o,31,0);
    VL_INW(&s_axis_slot_tdata,255,0,8);
    VL_IN(&s_axis_slot_tkeep,31,0);
    VL_OUTW(&m_axis_rd_tdata,255,0,8);
    VL_OUT(&m_axis_rd_tkeep,31,0);
    VL_OUTW(&m_axi_wdata,255,0,8);
    VL_OUT(&m_axi_wstrb,31,0);
    VL_INW(&m_axi_rdata,255,0,8);
    VL_IN64(&cfg_ring_base_addr_i,33,0);
    VL_OUT64(&wr_slot_addr_o,33,0);
    VL_OUT64(&rd_slot_addr_o,33,0);
    VL_OUT64(&wr_ptr_o,33,0);
    VL_OUT64(&rd_ptr_o,33,0);
    VL_OUT64(&commit_ptr_o,33,0);
    VL_IN64(&s_axis_slot_tuser,63,0);
    VL_OUT64(&m_axis_rd_tuser,63,0);
    VL_OUT64(&m_axi_awaddr,33,0);
    VL_OUT64(&m_axi_araddr,33,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vtop_ddr_ringbuffer_pkg* const __PVT__ddr_ringbuffer_pkg;
    Vtop_axis_stream_if* const __PVT__ddr_ringbuffer_controller_cocotb_top__DOT__s_axis_slot_if;
    Vtop_axis_stream_if* const __PVT__ddr_ringbuffer_controller_cocotb_top__DOT__m_axis_rd_if;
    Vtop_axi4_mm_if* const __PVT__ddr_ringbuffer_controller_cocotb_top__DOT__m_axi_if;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtop___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtop(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtop();
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
