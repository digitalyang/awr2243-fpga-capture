// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations

#include "verilated_fst_c.h"


void Vtop___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"ST_IDLE", "ST_CHECK", "ST_ACCEPT", "ST_DROP"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11"};
        tracep->declDTypeEnum(1, "csi_packet_extractor.extractor_state_e", 4, 2, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"ST_IDLE", "ST_CAPTURE", "ST_HEADER", "ST_PAYLOAD", 
                                "ST_SAMPLE_PAD", "ST_CQ_PAD", 
                                "ST_ALIGN_PAD"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110"};
        tracep->declDTypeEnum(2, "fixed_slot_packer.packer_state_e", 7, 3, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"WR_ST_IDLE", "WR_ST_ACCEPT_SLOT", "WR_ST_CHECK_SPACE", 
                                "WR_ST_MAKE_SPACE", 
                                "WR_ST_AW", "WR_ST_W", 
                                "WR_ST_WAIT_B", "WR_ST_COMMIT", 
                                "WR_ST_DROP_SLOT"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "111", "1000"};
        tracep->declDTypeEnum(3, "ddr_ringbuffer_controller.wr_state_e", 9, 4, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"RD_ST_IDLE", "RD_ST_AR", "RD_ST_R", "RD_ST_DONE"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11"};
        tracep->declDTypeEnum(4, "ddr_ringbuffer_controller.rd_state_e", 4, 3, __VenumItemNames, __VenumItemValues);
    }
}

void Vtop___024root__trace_decl_types(VerilatedFst* tracep) {
    Vtop___024root__traceDeclTypesSub0(tracep);
}
