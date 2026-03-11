// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"
#include "Vtop_slot_packer_pkg.h"
#include "Vtop_axis_stream_if.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;
    Vtop_axis_stream_if            TOP__fixed_slot_packer_cocotb_top__DOT__m_axis_if;
    Vtop_axis_stream_if            TOP__fixed_slot_packer_cocotb_top__DOT__s_axis_if;
    Vtop_slot_packer_pkg           TOP__slot_packer_pkg;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_TOP;
    VerilatedScope* __Vscopep_fixed_slot_packer_cocotb_top;
    VerilatedScope* __Vscopep_fixed_slot_packer_cocotb_top__dut;
    VerilatedScope* __Vscopep_fixed_slot_packer_cocotb_top__dut__g_static_checks;
    VerilatedScope* __Vscopep_fixed_slot_packer_cocotb_top__m_axis_if;
    VerilatedScope* __Vscopep_fixed_slot_packer_cocotb_top__s_axis_if;
    VerilatedScope* __Vscopep_slot_packer_pkg;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
