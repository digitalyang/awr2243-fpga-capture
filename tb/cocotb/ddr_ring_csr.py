from __future__ import annotations

from dataclasses import dataclass


CTRL_OFFSET = 0x00
STATUS_OFFSET = 0x04
RING_BASE_LO_OFFSET = 0x08
RING_BASE_HI_OFFSET = 0x0C
RING_SIZE_BYTES_OFFSET = 0x10
READ_CMD_OFFSET = 0x14

USED_BYTES_OFFSET = 0x20
FREE_BYTES_OFFSET = 0x24
COMMITTED_BYTES_OFFSET = 0x28
WR_PTR_LO_OFFSET = 0x30
WR_PTR_HI_OFFSET = 0x34
RD_PTR_LO_OFFSET = 0x38
RD_PTR_HI_OFFSET = 0x3C
COMMIT_PTR_LO_OFFSET = 0x40
COMMIT_PTR_HI_OFFSET = 0x44
WRAP_COUNT_OFFSET = 0x48
OVERFLOW_COUNT_OFFSET = 0x4C
DROP_COUNT_OFFSET = 0x50

LAST_COMMIT_ADDR_LO_OFFSET = 0x60
LAST_COMMIT_ADDR_HI_OFFSET = 0x64
LAST_COMMIT_INFO_OFFSET = 0x68
LAST_COMMIT_SEQ_OFFSET = 0x6C
HEAD_DESC_ADDR_LO_OFFSET = 0x80
HEAD_DESC_ADDR_HI_OFFSET = 0x84
HEAD_DESC_INFO_OFFSET = 0x88
HEAD_DESC_SEQ_OFFSET = 0x8C

CSR_SPACE_BYTES = 0x90

CTRL_ENABLE_MASK = 0x1
CTRL_ALLOW_OVERWRITE_MASK = 0x2
CTRL_DROP_INVALID_SLOT_MASK = 0x4
CTRL_DROP_ON_NO_SPACE_MASK = 0x8

STATUS_FULL_MASK = 0x1
STATUS_ALMOST_FULL_MASK = 0x2
STATUS_EMPTY_MASK = 0x4
STATUS_RD_BUSY_MASK = 0x8
STATUS_ERR_CFG_ALIGN_MASK = 0x100
STATUS_ERR_NO_SPACE_MASK = 0x200
STATUS_ERR_SLOT_PROTO_MASK = 0x400
STATUS_ERR_SLOT_TOO_LARGE_MASK = 0x800
STATUS_ERR_AXI_WR_RESP_MASK = 0x1000
STATUS_ERR_AXI_RD_RESP_MASK = 0x2000
STATUS_ERR_ILLEGAL_READ_MASK = 0x4000

READ_CMD_ISSUE_HEAD_READ_MASK = 0x1
READ_CMD_CONSUME_HEAD_MASK = 0x2

SLOT_BYTES_MASK = 0x00FF_FFFF
SLOT_VALID_GOOD_MASK = 0x0100_0000
SLOT_OVERFLOW_ERR_MASK = 0x0200_0000
HEAD_DESC_VALID_MASK = 0x8000_0000
LAST_COMMIT_VALID_MASK = 0x8000_0000


@dataclass(frozen=True)
class RingControlConfig:
    ring_base_addr: int
    ring_size_bytes: int
    enable: int = 1
    allow_overwrite: int = 0
    drop_invalid_slot: int = 1
    drop_on_no_space: int = 0


@dataclass(frozen=True)
class SlotInfoFields:
    slot_bytes: int
    valid_good: int
    overflow_err: int
    valid: int


def split_u64(value: int) -> tuple[int, int]:
    value = int(value) & 0xFFFF_FFFF_FFFF_FFFF
    return value & 0xFFFF_FFFF, (value >> 32) & 0xFFFF_FFFF


def join_u64(lo: int, hi: int) -> int:
    return (int(hi) << 32) | int(lo)


def pack_ctrl(config: RingControlConfig) -> int:
    value = 0
    if config.enable:
        value |= CTRL_ENABLE_MASK
    if config.allow_overwrite:
        value |= CTRL_ALLOW_OVERWRITE_MASK
    if config.drop_invalid_slot:
        value |= CTRL_DROP_INVALID_SLOT_MASK
    if config.drop_on_no_space:
        value |= CTRL_DROP_ON_NO_SPACE_MASK
    return value


def pack_slot_info(
    slot_bytes: int,
    *,
    valid_good: int,
    overflow_err: int,
    valid: int,
    valid_mask: int,
) -> int:
    value = int(slot_bytes) & SLOT_BYTES_MASK
    if valid_good:
        value |= SLOT_VALID_GOOD_MASK
    if overflow_err:
        value |= SLOT_OVERFLOW_ERR_MASK
    if valid:
        value |= valid_mask
    return value


def unpack_slot_info(value: int, *, valid_mask: int) -> SlotInfoFields:
    value = int(value)
    return SlotInfoFields(
        slot_bytes=value & SLOT_BYTES_MASK,
        valid_good=int(bool(value & SLOT_VALID_GOOD_MASK)),
        overflow_err=int(bool(value & SLOT_OVERFLOW_ERR_MASK)),
        valid=int(bool(value & valid_mask)),
    )
