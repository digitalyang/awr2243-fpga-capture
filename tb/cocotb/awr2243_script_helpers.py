from __future__ import annotations

OP_NOP = 0x00
OP_SPI_WR = 0x01
OP_SPI_RD = 0x02
OP_DELAY_US = 0x03
OP_WAIT_IRQ = 0x04
OP_CHECK_FAULT = 0x05
OP_END = 0x06
OP_FAIL = 0x07
OP_JUMP = 0x08

SPI_RD_FLAG_COMPARE_BIT = 0
ERR_INVALID_OPCODE = 0x01
ERR_SPI_TIMEOUT = 0x02
ERR_SPI_MISMATCH = 0x03
ERR_WAIT_IRQ_TIMEOUT = 0x04
ERR_FAULT_ACTIVE = 0x05
ERR_FAIL_OPCODE = 0x06


def encode_cmd(
    opcode: int,
    *,
    flags: int = 0,
    step_id: int = 0,
    imm_a: int = 0,
    imm_b: int = 0,
) -> int:
    return (
        ((opcode & 0xFF) << 56)
        | ((flags & 0xFF) << 48)
        | ((step_id & 0xFFFF) << 32)
        | ((imm_a & 0xFFFF) << 16)
        | (imm_b & 0xFFFF)
    )
