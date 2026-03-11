#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "generated/ddr_ringbuffer_controller_csr.h"

static inline volatile ddr_ringbuffer_controller_csr_t *ddr_ringbuffer_controller_regs(
    volatile void *bar0,
    size_t csr_offset
) {
    return (volatile ddr_ringbuffer_controller_csr_t *)((volatile uint8_t *)bar0 + csr_offset);
}

void ddr_ringbuffer_controller_configure(
    volatile void *bar0,
    size_t csr_offset,
    uint64_t ring_base_addr,
    uint32_t ring_size_bytes,
    bool allow_overwrite,
    bool drop_invalid_slot,
    bool drop_on_no_space
) {
    volatile ddr_ringbuffer_controller_csr_t *csr;
    uint32_t ctrl;

    csr = ddr_ringbuffer_controller_regs(bar0, csr_offset);

    csr->CTRL = 0;
    csr->RING_BASE_LO = (uint32_t)ring_base_addr;
    csr->RING_BASE_HI = (uint32_t)(ring_base_addr >> 32);
    csr->RING_SIZE_BYTES = ring_size_bytes;

    ctrl = DDR_RINGBUFFER_CONTROLLER_CSR__CTRL__ENABLE_bm;
    if (allow_overwrite) {
        ctrl |= DDR_RINGBUFFER_CONTROLLER_CSR__CTRL__ALLOW_OVERWRITE_bm;
    }
    if (drop_invalid_slot) {
        ctrl |= DDR_RINGBUFFER_CONTROLLER_CSR__CTRL__DROP_INVALID_SLOT_bm;
    }
    if (drop_on_no_space) {
        ctrl |= DDR_RINGBUFFER_CONTROLLER_CSR__CTRL__DROP_ON_NO_SPACE_bm;
    }

    csr->CTRL = ctrl;
}

void ddr_ringbuffer_controller_issue_head_read(volatile void *bar0, size_t csr_offset) {
    ddr_ringbuffer_controller_regs(bar0, csr_offset)->READ_CMD =
        DDR_RINGBUFFER_CONTROLLER_CSR__READ_CMD__ISSUE_HEAD_READ_bm;
}

void ddr_ringbuffer_controller_consume_head(volatile void *bar0, size_t csr_offset) {
    ddr_ringbuffer_controller_regs(bar0, csr_offset)->READ_CMD =
        DDR_RINGBUFFER_CONTROLLER_CSR__READ_CMD__CONSUME_HEAD_bm;
}

bool ddr_ringbuffer_controller_head_desc_valid(volatile void *bar0, size_t csr_offset) {
    return (ddr_ringbuffer_controller_regs(bar0, csr_offset)->HEAD_DESC_INFO &
            DDR_RINGBUFFER_CONTROLLER_CSR__HEAD_DESC_INFO__DESC_VALID_bm) != 0u;
}
