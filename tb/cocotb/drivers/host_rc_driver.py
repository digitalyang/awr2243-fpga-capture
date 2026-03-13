from __future__ import annotations

from dataclasses import dataclass
from typing import Any

from cocotb.triggers import Timer

from ddr_ring_csr import (
    COMMITTED_BYTES_OFFSET,
    CTRL_OFFSET,
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
    READ_CMD_CONSUME_HEAD_MASK,
    READ_CMD_ISSUE_HEAD_READ_MASK,
    READ_CMD_OFFSET,
    RING_BASE_HI_OFFSET,
    RING_BASE_LO_OFFSET,
    RING_SIZE_BYTES_OFFSET,
    STATUS_EMPTY_MASK,
    STATUS_OFFSET,
    RingControlConfig,
    join_u64,
    pack_ctrl,
    split_u64,
    unpack_slot_info,
    USED_BYTES_OFFSET,
)


class HostRcDependencyError(RuntimeError):
    pass


@dataclass(frozen=True)
class HostBarConfig:
    csr_bar: int = 0
    dma_bar: int = 2


@dataclass(frozen=True)
class HostStatus:
    raw: int
    empty: int
    committed_bytes: int
    used_bytes: int
    free_bytes: int


@dataclass(frozen=True)
class HostSlotDescriptor:
    addr: int
    slot_bytes: int
    seq: int
    valid_good: int
    overflow_err: int


@dataclass(frozen=True)
class HostLastCommit:
    addr: int
    slot_bytes: int
    seq: int
    valid_good: int
    overflow_err: int
    valid: int


@dataclass(frozen=True)
class HostSlotRead:
    descriptor: HostSlotDescriptor
    payload: bytes


def _load_pcie_core():
    try:
        from cocotbext.pcie.core import RootComplex
        from cocotbext.pcie.core.utils import PcieId
    except ModuleNotFoundError as exc:
        raise HostRcDependencyError(
            "cocotbext-pcie is required for host_rc_driver; install tb/cocotb/requirements.txt"
        ) from exc

    return RootComplex, PcieId


def _iter_pci_devices(bus) -> list[Any]:
    devices = list(getattr(bus, "devices", []))
    for child in getattr(bus, "children", []):
        devices.extend(_iter_pci_devices(child))
    return devices


class HostRootComplexModel:
    def __init__(self, rc=None):
        if rc is None:
            RootComplex, _ = _load_pcie_core()
            rc = RootComplex()
        self.rc = rc

    def make_port(self):
        return self.rc.make_port()

    async def enumerate(self, *, timeout: int = 1000, timeout_unit: str = "ns") -> None:
        await self.rc.enumerate(timeout=timeout, timeout_unit=timeout_unit)

    def find_devices(
        self,
        *,
        vendor_id: int | None = None,
        device_id: int | None = None,
        pcie_id: tuple[int, int, int] | None = None,
    ) -> list[Any]:
        _, PcieId = _load_pcie_core()
        devices = _iter_pci_devices(self.rc.host_bridge.bus)
        matches = []
        expected_id = PcieId(*pcie_id) if pcie_id is not None else None

        for device in devices:
            if vendor_id is not None and device.vendor_id != vendor_id:
                continue
            if device_id is not None and device.device_id != device_id:
                continue
            if expected_id is not None and device.pcie_id != expected_id:
                continue
            matches.append(device)

        return matches

    async def claim_host_rc_driver(
        self,
        *,
        vendor_id: int | None = None,
        device_id: int | None = None,
        pcie_id: tuple[int, int, int] | None = None,
        bar_config: HostBarConfig | None = None,
        timeout: int = 1000,
        timeout_unit: str = "ns",
    ) -> "HostRcDriver":
        await self.enumerate(timeout=timeout, timeout_unit=timeout_unit)
        matches = self.find_devices(vendor_id=vendor_id, device_id=device_id, pcie_id=pcie_id)

        if not matches:
            raise LookupError("No PCIe function matched the requested host_rc_driver claim")
        if len(matches) != 1:
            raise LookupError(f"host_rc_driver claim is ambiguous: matched {len(matches)} functions")

        return HostRcDriver(matches[0], bar_config=bar_config)


class HostRcDriver:
    def __init__(
        self,
        device,
        *,
        bar_config: HostBarConfig | None = None,
        default_burst_bytes: int = 256,
    ):
        self.device = device
        self.bar_config = bar_config or HostBarConfig()
        self.default_burst_bytes = default_burst_bytes
        self._read_busy = False

    @property
    def csr_window(self):
        window = self.device.bar_window[self.bar_config.csr_bar]
        if window is None:
            raise ValueError(f"CSR BAR{self.bar_config.csr_bar} is not enumerated")
        return window

    @property
    def dma_window(self):
        window = self.device.bar_window[self.bar_config.dma_bar]
        if window is None:
            raise ValueError(f"DMA BAR{self.bar_config.dma_bar} is not enumerated")
        return window

    async def read_csr_dword(self, offset: int) -> int:
        return int(await self.csr_window.read_dword(offset, byteorder="little"))

    async def write_csr_dword(self, offset: int, value: int) -> None:
        await self.csr_window.write_dword(offset, int(value) & 0xFFFF_FFFF, byteorder="little")

    async def program_ring(
        self,
        *,
        ring_base_addr: int,
        ring_size_bytes: int,
        enable: int = 1,
        allow_overwrite: int = 0,
        drop_invalid_slot: int = 1,
        drop_on_no_space: int = 0,
    ) -> RingControlConfig:
        config = RingControlConfig(
            ring_base_addr=ring_base_addr,
            ring_size_bytes=ring_size_bytes,
            enable=enable,
            allow_overwrite=allow_overwrite,
            drop_invalid_slot=drop_invalid_slot,
            drop_on_no_space=drop_on_no_space,
        )
        ring_base_lo, ring_base_hi = split_u64(config.ring_base_addr)

        await self.write_csr_dword(CTRL_OFFSET, 0)
        await self.write_csr_dword(RING_BASE_LO_OFFSET, ring_base_lo)
        await self.write_csr_dword(RING_BASE_HI_OFFSET, ring_base_hi)
        await self.write_csr_dword(RING_SIZE_BYTES_OFFSET, config.ring_size_bytes)
        await self.write_csr_dword(CTRL_OFFSET, pack_ctrl(config))

        return config

    async def read_ring_config(self) -> RingControlConfig:
        ctrl = await self.read_csr_dword(CTRL_OFFSET)
        ring_base_lo = await self.read_csr_dword(RING_BASE_LO_OFFSET)
        ring_base_hi = await self.read_csr_dword(RING_BASE_HI_OFFSET)
        ring_size_bytes = await self.read_csr_dword(RING_SIZE_BYTES_OFFSET)

        return RingControlConfig(
            ring_base_addr=join_u64(ring_base_lo, ring_base_hi),
            ring_size_bytes=ring_size_bytes,
            enable=int(bool(ctrl & 0x1)),
            allow_overwrite=int(bool(ctrl & 0x2)),
            drop_invalid_slot=int(bool(ctrl & 0x4)),
            drop_on_no_space=int(bool(ctrl & 0x8)),
        )

    async def read_status(self) -> HostStatus:
        raw = await self.read_csr_dword(STATUS_OFFSET)
        used_bytes = await self.read_csr_dword(USED_BYTES_OFFSET)
        free_bytes = await self.read_csr_dword(FREE_BYTES_OFFSET)
        committed_bytes = await self.read_csr_dword(COMMITTED_BYTES_OFFSET)
        return HostStatus(
            raw=raw,
            empty=int(bool(raw & STATUS_EMPTY_MASK)),
            committed_bytes=committed_bytes,
            used_bytes=used_bytes,
            free_bytes=free_bytes,
        )

    async def issue_head_read(self) -> None:
        await self.write_csr_dword(READ_CMD_OFFSET, READ_CMD_ISSUE_HEAD_READ_MASK)

    async def consume_head(self) -> None:
        await self.write_csr_dword(READ_CMD_OFFSET, READ_CMD_CONSUME_HEAD_MASK)

    async def read_head_descriptor(self, *, issue_read: bool = False) -> HostSlotDescriptor | None:
        if issue_read:
            await self.issue_head_read()

        info = unpack_slot_info(
            await self.read_csr_dword(HEAD_DESC_INFO_OFFSET),
            valid_mask=HEAD_DESC_VALID_MASK,
        )
        if not info.valid:
            return None

        addr = join_u64(
            await self.read_csr_dword(HEAD_DESC_ADDR_LO_OFFSET),
            await self.read_csr_dword(HEAD_DESC_ADDR_HI_OFFSET),
        )
        seq = await self.read_csr_dword(HEAD_DESC_SEQ_OFFSET)

        return HostSlotDescriptor(
            addr=addr,
            slot_bytes=info.slot_bytes,
            seq=seq,
            valid_good=info.valid_good,
            overflow_err=info.overflow_err,
        )

    async def wait_for_head_descriptor(
        self,
        *,
        timeout_ns: int = 20_000,
        poll_interval_ns: int = 100,
        issue_read: bool = True,
    ) -> HostSlotDescriptor:
        remaining = timeout_ns

        while True:
            descriptor = await self.read_head_descriptor(issue_read=issue_read)
            if descriptor is not None:
                return descriptor

            if remaining <= 0:
                raise TimeoutError("Timed out waiting for a valid HEAD_DESC slot")

            await Timer(poll_interval_ns, unit="ns")
            remaining -= poll_interval_ns

    async def read_last_commit(self) -> HostLastCommit:
        info = unpack_slot_info(
            await self.read_csr_dword(LAST_COMMIT_INFO_OFFSET),
            valid_mask=LAST_COMMIT_VALID_MASK,
        )
        addr = join_u64(
            await self.read_csr_dword(LAST_COMMIT_ADDR_LO_OFFSET),
            await self.read_csr_dword(LAST_COMMIT_ADDR_HI_OFFSET),
        )
        seq = await self.read_csr_dword(LAST_COMMIT_SEQ_OFFSET)
        return HostLastCommit(
            addr=addr,
            slot_bytes=info.slot_bytes,
            seq=seq,
            valid_good=info.valid_good,
            overflow_err=info.overflow_err,
            valid=info.valid,
        )

    async def burst_read(self, addr: int, length: int, *, burst_bytes: int | None = None) -> bytes:
        if length <= 0:
            return b""

        burst_bytes = self.default_burst_bytes if burst_bytes is None else int(burst_bytes)
        payload = bytearray()
        offset = 0

        while offset < length:
            chunk = min(burst_bytes, length - offset)
            payload.extend(await self.dma_window.read(addr + offset, chunk))
            offset += chunk

        return bytes(payload)

    async def read_slot_data(
        self,
        descriptor: HostSlotDescriptor,
        *,
        burst_bytes: int | None = None,
    ) -> HostSlotRead:
        ring = await self.read_ring_config()
        payload = bytearray()
        ring_base = ring.ring_base_addr
        ring_size = ring.ring_size_bytes
        addr = descriptor.addr
        remaining = descriptor.slot_bytes
        burst_bytes = self.default_burst_bytes if burst_bytes is None else int(burst_bytes)
        ring_end = ring_base + ring_size

        if ring_size <= 0:
            raise ValueError("Ring size is zero; program the ring before reading slot data")

        while remaining > 0:
            if addr < ring_base or addr >= ring_end:
                raise ValueError(
                    f"Slot address 0x{addr:x} is outside the programmed ring [0x{ring_base:x}, 0x{ring_end:x})"
                )

            contiguous = min(remaining, ring_end - addr)
            payload.extend(await self.burst_read(addr, contiguous, burst_bytes=burst_bytes))
            remaining -= contiguous
            addr = ring_base if remaining else addr + contiguous

        return HostSlotRead(descriptor=descriptor, payload=bytes(payload))

    async def request_slot_read(
        self,
        *,
        timeout_ns: int = 20_000,
        poll_interval_ns: int = 100,
        burst_bytes: int | None = None,
        consume: bool = True,
    ) -> HostSlotRead:
        while self._read_busy:
            await Timer(10, unit="ns")

        self._read_busy = True
        try:
            descriptor = await self.wait_for_head_descriptor(
                timeout_ns=timeout_ns,
                poll_interval_ns=poll_interval_ns,
                issue_read=True,
            )
            slot = await self.read_slot_data(descriptor, burst_bytes=burst_bytes)
            if consume:
                await self.consume_head()
            return slot
        finally:
            self._read_busy = False
