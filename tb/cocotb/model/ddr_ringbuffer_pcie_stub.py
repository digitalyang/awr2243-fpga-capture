from __future__ import annotations

from collections import deque
from dataclasses import dataclass

from cocotbext.pcie.core import Device, MemoryEndpoint

from ddr_ring_csr import (
    COMMIT_PTR_HI_OFFSET,
    COMMIT_PTR_LO_OFFSET,
    COMMITTED_BYTES_OFFSET,
    CTRL_DROP_INVALID_SLOT_MASK,
    CTRL_OFFSET,
    DROP_COUNT_OFFSET,
    FREE_BYTES_OFFSET,
    HEAD_DESC_ADDR_HI_OFFSET,
    HEAD_DESC_ADDR_LO_OFFSET,
    HEAD_DESC_INFO_OFFSET,
    HEAD_DESC_SEQ_OFFSET,
    HEAD_DESC_VALID_MASK,
    LAST_COMMIT_ADDR_HI_OFFSET,
    LAST_COMMIT_ADDR_LO_OFFSET,
    LAST_COMMIT_INFO_OFFSET,
    LAST_COMMIT_SEQ_OFFSET,
    LAST_COMMIT_VALID_MASK,
    OVERFLOW_COUNT_OFFSET,
    RD_PTR_HI_OFFSET,
    RD_PTR_LO_OFFSET,
    READ_CMD_CONSUME_HEAD_MASK,
    READ_CMD_ISSUE_HEAD_READ_MASK,
    READ_CMD_OFFSET,
    RING_BASE_HI_OFFSET,
    RING_BASE_LO_OFFSET,
    RING_SIZE_BYTES_OFFSET,
    SLOT_BYTES_MASK,
    STATUS_EMPTY_MASK,
    STATUS_FULL_MASK,
    STATUS_OFFSET,
    USED_BYTES_OFFSET,
    WRAP_COUNT_OFFSET,
    WR_PTR_HI_OFFSET,
    WR_PTR_LO_OFFSET,
    join_u64,
    pack_slot_info,
    split_u64,
)


@dataclass(frozen=True)
class StubCommittedSlot:
    addr: int
    slot_bytes: int
    seq: int
    valid_good: int
    overflow_err: int
    payload: bytes


class DdrRingbufferPcieStubEndpoint(MemoryEndpoint):
    def __init__(
        self,
        *,
        vendor_id: int = 0xBEEF,
        device_id: int = 0x2243,
        dma_size_bytes: int = 0x20_0000,
        csr_size_bytes: int = 0x1000,
    ):
        super().__init__()

        self.vendor_id = vendor_id
        self.device_id = device_id
        self.subsystem_vendor_id = vendor_id
        self.subsystem_id = device_id

        self.csr_bar = 0
        self.dma_bar = 2
        self.csr_size_bytes = csr_size_bytes
        self.dma_size_bytes = dma_size_bytes

        self.ctrl_value = CTRL_DROP_INVALID_SLOT_MASK
        self.ring_base_addr = 0x1000
        self.ring_size_bytes = 0x4000
        self.wrap_count = 0
        self.overflow_count = 0
        self.drop_count = 0
        self.wr_ptr_offset = 0
        self.rd_ptr_offset = 0

        self._csr_space = bytearray(csr_size_bytes)
        self._dma_space = bytearray(dma_size_bytes)
        self._pending_slots: deque[StubCommittedSlot] = deque()
        self._last_commit: StubCommittedSlot | None = None
        self._issue_head_read_count = 0

        self._write_reg(CTRL_OFFSET, self.ctrl_value)
        self._write_reg(RING_BASE_LO_OFFSET, self.ring_base_addr & 0xFFFF_FFFF)
        self._write_reg(RING_BASE_HI_OFFSET, (self.ring_base_addr >> 32) & 0xFFFF_FFFF)
        self._write_reg(RING_SIZE_BYTES_OFFSET, self.ring_size_bytes)

        self.add_mem_region(csr_size_bytes, read=self._read_csr, write=self._write_csr)
        self.add_mem_region(0x1000)
        self.add_mem_region(dma_size_bytes, read=self._read_dma, write=self._write_dma)

    def make_device(self, *, max_link_speed: int = 3, max_link_width: int = 8):
        device = Device(self)
        device.upstream_port.max_link_speed = max_link_speed
        device.upstream_port.max_link_width = max_link_width
        return device

    def push_slot(
        self,
        payload: bytes,
        *,
        seq: int,
        valid_good: int = 1,
        overflow_err: int = 0,
        addr: int | None = None,
    ) -> StubCommittedSlot:
        if self.ring_size_bytes <= 0:
            raise ValueError("Stub ring is not configured")

        if addr is None:
            addr = self.ring_base_addr + self.wr_ptr_offset

        slot = StubCommittedSlot(
            addr=addr,
            slot_bytes=len(payload),
            seq=seq,
            valid_good=int(valid_good),
            overflow_err=int(overflow_err),
            payload=bytes(payload),
        )
        self._write_ring_bytes(slot.addr, slot.payload)
        if not self._pending_slots:
            self.rd_ptr_offset = slot.addr - self.ring_base_addr
        self._pending_slots.append(slot)
        self._last_commit = slot
        self.wr_ptr_offset = self._advance_wr_ptr(self.wr_ptr_offset, slot.slot_bytes)
        self._refresh_dynamic_csrs()
        return slot

    async def _read_csr(self, addr: int, length: int) -> bytes:
        self._refresh_dynamic_csrs()
        return bytes(self._csr_space[addr : addr + length])

    async def _write_csr(self, addr: int, data: bytes) -> None:
        end = addr + len(data)
        self._csr_space[addr:end] = data

        if addr <= CTRL_OFFSET < end:
            self.ctrl_value = self._read_reg(CTRL_OFFSET)
        if (
            addr <= RING_BASE_LO_OFFSET < end
            or addr <= RING_BASE_HI_OFFSET < end
        ):
            self.ring_base_addr = join_u64(
                self._read_reg(RING_BASE_LO_OFFSET),
                self._read_reg(RING_BASE_HI_OFFSET),
            )
        if addr <= RING_SIZE_BYTES_OFFSET < end:
            self.ring_size_bytes = self._read_reg(RING_SIZE_BYTES_OFFSET)
        if addr <= READ_CMD_OFFSET < end:
            self._apply_read_cmd(self._read_reg(READ_CMD_OFFSET))
            self._write_reg(READ_CMD_OFFSET, 0)

        self._refresh_dynamic_csrs()

    async def _read_dma(self, addr: int, length: int) -> bytes:
        return bytes(self._dma_space[addr : addr + length])

    async def _write_dma(self, addr: int, data: bytes) -> None:
        end = addr + len(data)
        self._dma_space[addr:end] = data

    def _apply_read_cmd(self, value: int) -> None:
        if value & READ_CMD_ISSUE_HEAD_READ_MASK:
            self._issue_head_read_count += 1

        if value & READ_CMD_CONSUME_HEAD_MASK and self._pending_slots:
            self._pending_slots.popleft()
            if self._pending_slots:
                self.rd_ptr_offset = self._pending_slots[0].addr - self.ring_base_addr
            else:
                self.rd_ptr_offset = self.wr_ptr_offset

    def _advance_wr_ptr(self, wr_ptr_offset: int, slot_bytes: int) -> int:
        next_offset = wr_ptr_offset + slot_bytes
        if self.ring_size_bytes > 0 and next_offset >= self.ring_size_bytes:
            self.wrap_count += next_offset // self.ring_size_bytes
            next_offset %= self.ring_size_bytes
        return next_offset

    def _write_ring_bytes(self, addr: int, payload: bytes) -> None:
        ring_base = self.ring_base_addr
        ring_end = ring_base + self.ring_size_bytes
        cursor = addr

        for byte in payload:
            if cursor >= ring_end:
                cursor = ring_base
            self._dma_space[cursor] = byte
            cursor += 1

    def _pending_bytes(self) -> int:
        return sum(slot.slot_bytes for slot in self._pending_slots)

    def _write_reg(self, offset: int, value: int) -> None:
        self._csr_space[offset : offset + 4] = int(value & 0xFFFF_FFFF).to_bytes(4, byteorder="little")

    def _read_reg(self, offset: int) -> int:
        return int.from_bytes(self._csr_space[offset : offset + 4], byteorder="little", signed=False)

    def _refresh_dynamic_csrs(self) -> None:
        ring_base_lo, ring_base_hi = split_u64(self.ring_base_addr)
        wr_ptr_lo, wr_ptr_hi = split_u64(self.ring_base_addr + self.wr_ptr_offset)
        rd_ptr_lo, rd_ptr_hi = split_u64(self.ring_base_addr + self.rd_ptr_offset)
        commit_ptr_lo, commit_ptr_hi = wr_ptr_lo, wr_ptr_hi
        pending_bytes = self._pending_bytes()
        free_bytes = max(self.ring_size_bytes - pending_bytes, 0)
        status = 0

        if pending_bytes == 0:
            status |= STATUS_EMPTY_MASK
        if self.ring_size_bytes > 0 and pending_bytes >= self.ring_size_bytes:
            status |= STATUS_FULL_MASK

        self._write_reg(CTRL_OFFSET, self.ctrl_value)
        self._write_reg(STATUS_OFFSET, status)
        self._write_reg(RING_BASE_LO_OFFSET, ring_base_lo)
        self._write_reg(RING_BASE_HI_OFFSET, ring_base_hi)
        self._write_reg(RING_SIZE_BYTES_OFFSET, self.ring_size_bytes)
        self._write_reg(USED_BYTES_OFFSET, pending_bytes)
        self._write_reg(FREE_BYTES_OFFSET, free_bytes)
        self._write_reg(COMMITTED_BYTES_OFFSET, pending_bytes)
        self._write_reg(WR_PTR_LO_OFFSET, wr_ptr_lo)
        self._write_reg(WR_PTR_HI_OFFSET, wr_ptr_hi)
        self._write_reg(RD_PTR_LO_OFFSET, rd_ptr_lo)
        self._write_reg(RD_PTR_HI_OFFSET, rd_ptr_hi)
        self._write_reg(COMMIT_PTR_LO_OFFSET, commit_ptr_lo)
        self._write_reg(COMMIT_PTR_HI_OFFSET, commit_ptr_hi)
        self._write_reg(WRAP_COUNT_OFFSET, self.wrap_count)
        self._write_reg(OVERFLOW_COUNT_OFFSET, self.overflow_count)
        self._write_reg(DROP_COUNT_OFFSET, self.drop_count)

        if self._last_commit is None:
            self._write_reg(LAST_COMMIT_ADDR_LO_OFFSET, 0)
            self._write_reg(LAST_COMMIT_ADDR_HI_OFFSET, 0)
            self._write_reg(
                LAST_COMMIT_INFO_OFFSET,
                pack_slot_info(0, valid_good=0, overflow_err=0, valid=0, valid_mask=LAST_COMMIT_VALID_MASK),
            )
            self._write_reg(LAST_COMMIT_SEQ_OFFSET, 0)
        else:
            last_addr_lo, last_addr_hi = split_u64(self._last_commit.addr)
            self._write_reg(LAST_COMMIT_ADDR_LO_OFFSET, last_addr_lo)
            self._write_reg(LAST_COMMIT_ADDR_HI_OFFSET, last_addr_hi)
            self._write_reg(
                LAST_COMMIT_INFO_OFFSET,
                pack_slot_info(
                    self._last_commit.slot_bytes & SLOT_BYTES_MASK,
                    valid_good=self._last_commit.valid_good,
                    overflow_err=self._last_commit.overflow_err,
                    valid=1,
                    valid_mask=LAST_COMMIT_VALID_MASK,
                ),
            )
            self._write_reg(LAST_COMMIT_SEQ_OFFSET, self._last_commit.seq)

        if not self._pending_slots:
            self._write_reg(HEAD_DESC_ADDR_LO_OFFSET, 0)
            self._write_reg(HEAD_DESC_ADDR_HI_OFFSET, 0)
            self._write_reg(
                HEAD_DESC_INFO_OFFSET,
                pack_slot_info(0, valid_good=0, overflow_err=0, valid=0, valid_mask=HEAD_DESC_VALID_MASK),
            )
            self._write_reg(HEAD_DESC_SEQ_OFFSET, 0)
            return

        head = self._pending_slots[0]
        head_addr_lo, head_addr_hi = split_u64(head.addr)
        self._write_reg(HEAD_DESC_ADDR_LO_OFFSET, head_addr_lo)
        self._write_reg(HEAD_DESC_ADDR_HI_OFFSET, head_addr_hi)
        self._write_reg(
            HEAD_DESC_INFO_OFFSET,
            pack_slot_info(
                head.slot_bytes & SLOT_BYTES_MASK,
                valid_good=head.valid_good,
                overflow_err=head.overflow_err,
                valid=1,
                valid_mask=HEAD_DESC_VALID_MASK,
            ),
        )
        self._write_reg(HEAD_DESC_SEQ_OFFSET, head.seq)
