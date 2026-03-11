// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop__Syms(contextp(), _vcname__, this)}
    , clk_i{vlSymsp->TOP.clk_i}
    , rst_ni{vlSymsp->TOP.rst_ni}
    , cfg_vc_en_i{vlSymsp->TOP.cfg_vc_en_i}
    , cfg_dt_en_i{vlSymsp->TOP.cfg_dt_en_i}
    , cfg_vc_i{vlSymsp->TOP.cfg_vc_i}
    , cfg_dt_i{vlSymsp->TOP.cfg_dt_i}
    , cfg_drop_invalid_pkt_i{vlSymsp->TOP.cfg_drop_invalid_pkt_i}
    , cfg_enable_i{vlSymsp->TOP.cfg_enable_i}
    , cfg_allow_overwrite_i{vlSymsp->TOP.cfg_allow_overwrite_i}
    , cfg_drop_invalid_slot_i{vlSymsp->TOP.cfg_drop_invalid_slot_i}
    , cfg_drop_on_no_space_i{vlSymsp->TOP.cfg_drop_on_no_space_i}
    , pkt_start_o{vlSymsp->TOP.pkt_start_o}
    , pkt_done_o{vlSymsp->TOP.pkt_done_o}
    , pkt_valid_good_o{vlSymsp->TOP.pkt_valid_good_o}
    , pkt_crc_err_o{vlSymsp->TOP.pkt_crc_err_o}
    , pkt_ecc_err_o{vlSymsp->TOP.pkt_ecc_err_o}
    , pkt_trunc_err_o{vlSymsp->TOP.pkt_trunc_err_o}
    , slot_start_o{vlSymsp->TOP.slot_start_o}
    , slot_done_o{vlSymsp->TOP.slot_done_o}
    , slot_valid_good_o{vlSymsp->TOP.slot_valid_good_o}
    , slot_overflow_err_o{vlSymsp->TOP.slot_overflow_err_o}
    , wr_slot_commit_o{vlSymsp->TOP.wr_slot_commit_o}
    , wr_slot_valid_good_o{vlSymsp->TOP.wr_slot_valid_good_o}
    , wr_slot_overflow_err_o{vlSymsp->TOP.wr_slot_overflow_err_o}
    , rd_slot_req_i{vlSymsp->TOP.rd_slot_req_i}
    , rd_consume_i{vlSymsp->TOP.rd_consume_i}
    , rd_slot_valid_o{vlSymsp->TOP.rd_slot_valid_o}
    , rd_slot_valid_good_o{vlSymsp->TOP.rd_slot_valid_good_o}
    , rd_slot_overflow_err_o{vlSymsp->TOP.rd_slot_overflow_err_o}
    , rd_busy_o{vlSymsp->TOP.rd_busy_o}
    , rd_done_o{vlSymsp->TOP.rd_done_o}
    , rd_error_o{vlSymsp->TOP.rd_error_o}
    , full_o{vlSymsp->TOP.full_o}
    , almost_full_o{vlSymsp->TOP.almost_full_o}
    , empty_o{vlSymsp->TOP.empty_o}
    , err_cfg_align_o{vlSymsp->TOP.err_cfg_align_o}
    , err_no_space_o{vlSymsp->TOP.err_no_space_o}
    , err_slot_proto_o{vlSymsp->TOP.err_slot_proto_o}
    , err_slot_too_large_o{vlSymsp->TOP.err_slot_too_large_o}
    , err_axi_wr_resp_o{vlSymsp->TOP.err_axi_wr_resp_o}
    , err_axi_rd_resp_o{vlSymsp->TOP.err_axi_rd_resp_o}
    , err_illegal_read_o{vlSymsp->TOP.err_illegal_read_o}
    , dbg_wr_state_o{vlSymsp->TOP.dbg_wr_state_o}
    , dbg_rd_state_o{vlSymsp->TOP.dbg_rd_state_o}
    , s_axis_tvalid{vlSymsp->TOP.s_axis_tvalid}
    , s_axis_tready{vlSymsp->TOP.s_axis_tready}
    , s_axis_tlast{vlSymsp->TOP.s_axis_tlast}
    , m_axis_rd_tvalid{vlSymsp->TOP.m_axis_rd_tvalid}
    , m_axis_rd_tready{vlSymsp->TOP.m_axis_rd_tready}
    , m_axis_rd_tlast{vlSymsp->TOP.m_axis_rd_tlast}
    , m_axi_awlen{vlSymsp->TOP.m_axi_awlen}
    , m_axi_awsize{vlSymsp->TOP.m_axi_awsize}
    , m_axi_awburst{vlSymsp->TOP.m_axi_awburst}
    , m_axi_awvalid{vlSymsp->TOP.m_axi_awvalid}
    , m_axi_awready{vlSymsp->TOP.m_axi_awready}
    , m_axi_wlast{vlSymsp->TOP.m_axi_wlast}
    , m_axi_wvalid{vlSymsp->TOP.m_axi_wvalid}
    , m_axi_wready{vlSymsp->TOP.m_axi_wready}
    , m_axi_bresp{vlSymsp->TOP.m_axi_bresp}
    , m_axi_bvalid{vlSymsp->TOP.m_axi_bvalid}
    , m_axi_bready{vlSymsp->TOP.m_axi_bready}
    , m_axi_arlen{vlSymsp->TOP.m_axi_arlen}
    , m_axi_arsize{vlSymsp->TOP.m_axi_arsize}
    , m_axi_arburst{vlSymsp->TOP.m_axi_arburst}
    , m_axi_arvalid{vlSymsp->TOP.m_axi_arvalid}
    , m_axi_arready{vlSymsp->TOP.m_axi_arready}
    , m_axi_rresp{vlSymsp->TOP.m_axi_rresp}
    , m_axi_rlast{vlSymsp->TOP.m_axi_rlast}
    , m_axi_rvalid{vlSymsp->TOP.m_axi_rvalid}
    , m_axi_rready{vlSymsp->TOP.m_axi_rready}
    , pkt_seq_o{vlSymsp->TOP.pkt_seq_o}
    , pkt_bytes_o{vlSymsp->TOP.pkt_bytes_o}
    , slot_seq_o{vlSymsp->TOP.slot_seq_o}
    , wr_slot_seq_o{vlSymsp->TOP.wr_slot_seq_o}
    , rd_slot_seq_o{vlSymsp->TOP.rd_slot_seq_o}
    , cfg_ring_size_bytes_i{vlSymsp->TOP.cfg_ring_size_bytes_i}
    , slot_bytes_o{vlSymsp->TOP.slot_bytes_o}
    , wr_slot_bytes_o{vlSymsp->TOP.wr_slot_bytes_o}
    , rd_slot_bytes_o{vlSymsp->TOP.rd_slot_bytes_o}
    , used_bytes_o{vlSymsp->TOP.used_bytes_o}
    , free_bytes_o{vlSymsp->TOP.free_bytes_o}
    , committed_bytes_o{vlSymsp->TOP.committed_bytes_o}
    , wrap_count_o{vlSymsp->TOP.wrap_count_o}
    , overflow_count_o{vlSymsp->TOP.overflow_count_o}
    , drop_count_o{vlSymsp->TOP.drop_count_o}
    , s_axis_tdata{vlSymsp->TOP.s_axis_tdata}
    , s_axis_tkeep{vlSymsp->TOP.s_axis_tkeep}
    , m_axis_rd_tdata{vlSymsp->TOP.m_axis_rd_tdata}
    , m_axis_rd_tkeep{vlSymsp->TOP.m_axis_rd_tkeep}
    , m_axi_wdata{vlSymsp->TOP.m_axi_wdata}
    , m_axi_wstrb{vlSymsp->TOP.m_axi_wstrb}
    , m_axi_rdata{vlSymsp->TOP.m_axi_rdata}
    , cfg_ring_base_addr_i{vlSymsp->TOP.cfg_ring_base_addr_i}
    , wr_slot_addr_o{vlSymsp->TOP.wr_slot_addr_o}
    , rd_slot_addr_o{vlSymsp->TOP.rd_slot_addr_o}
    , wr_ptr_o{vlSymsp->TOP.wr_ptr_o}
    , rd_ptr_o{vlSymsp->TOP.rd_ptr_o}
    , commit_ptr_o{vlSymsp->TOP.commit_ptr_o}
    , s_axis_tuser{vlSymsp->TOP.s_axis_tuser}
    , m_axis_rd_tuser{vlSymsp->TOP.m_axis_rd_tuser}
    , m_axi_awaddr{vlSymsp->TOP.m_axi_awaddr}
    , m_axi_araddr{vlSymsp->TOP.m_axi_araddr}
    , __PVT__csi_packet_pkg{vlSymsp->TOP.__PVT__csi_packet_pkg}
    , __PVT__slot_packer_pkg{vlSymsp->TOP.__PVT__slot_packer_pkg}
    , __PVT__ddr_ringbuffer_pkg{vlSymsp->TOP.__PVT__ddr_ringbuffer_pkg}
    , __PVT__pipeline_cocotb_top__DOT__s_axis_if{vlSymsp->TOP.__PVT__pipeline_cocotb_top__DOT__s_axis_if}
    , __PVT__pipeline_cocotb_top__DOT__pkt_axis_if{vlSymsp->TOP.__PVT__pipeline_cocotb_top__DOT__pkt_axis_if}
    , __PVT__pipeline_cocotb_top__DOT__slot_axis_if{vlSymsp->TOP.__PVT__pipeline_cocotb_top__DOT__slot_axis_if}
    , __PVT__pipeline_cocotb_top__DOT__m_axis_rd_if{vlSymsp->TOP.__PVT__pipeline_cocotb_top__DOT__m_axis_rd_if}
    , __PVT__pipeline_cocotb_top__DOT__m_axi_if{vlSymsp->TOP.__PVT__pipeline_cocotb_top__DOT__m_axi_if}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vtop::Vtop(const char* _vcname__)
    : Vtop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop::~Vtop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_static(Vtop___024root* vlSelf);
void Vtop___024root___eval_initial(Vtop___024root* vlSelf);
void Vtop___024root___eval_settle(Vtop___024root* vlSelf);
void Vtop___024root___eval(Vtop___024root* vlSelf);

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop___024root___eval_static(&(vlSymsp->TOP));
        Vtop___024root___eval_initial(&(vlSymsp->TOP));
        Vtop___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtop::eventsPending() { return false; }

uint64_t Vtop::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop___024root___eval_final(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop::final() {
    Vtop___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop::hierName() const { return vlSymsp->name(); }
const char* Vtop::modelName() const { return "Vtop"; }
unsigned Vtop::threads() const { return 1; }
void Vtop::prepareClone() const { contextp()->prepareClone(); }
void Vtop::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vtop::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vtop___024root__trace_decl_types(VerilatedFst* tracep);

void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_decl_types(tracep);
    Vtop___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vtop::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtop::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 1083);
    Vtop___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
