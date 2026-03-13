from __future__ import annotations

from dataclasses import dataclass

from awr_payload_model import (
    CQ_BYTES,
    RX_HEADER_BYTES_TOTAL,
    SAMPLE_AREA_BYTES,
    SLOT_TOTAL_ALIGNED,
    SLOT_TOTAL_UNALIGNED,
    build_expected_slot_bytes,
    expected_sample_count,
)


@dataclass(frozen=True)
class SlotRegion:
    name: str
    offset: int
    data: bytes

    @property
    def length(self) -> int:
        return len(self.data)

    @property
    def end_offset(self) -> int:
        return self.offset + self.length


@dataclass(frozen=True)
class RingSpan:
    addr: int
    slot_offset: int
    data: bytes

    @property
    def length(self) -> int:
        return len(self.data)

    @property
    def end_addr(self) -> int:
        return self.addr + self.length


@dataclass(frozen=True)
class HostVisibleSlot:
    seq: int
    slot_bytes: int
    valid_good: int
    overflow_err: int
    ring_base_addr: int
    ring_size_bytes: int
    addr: int
    data: bytes
    spans: tuple[RingSpan, ...]
    regions: tuple[SlotRegion, ...]
    wraps: bool

    def contains_addr(self, addr: int) -> bool:
        ring_addr = self._normalize_addr(addr)
        return any(span.addr <= ring_addr < span.end_addr for span in self.spans)

    def read(self, *, start_addr: int | None = None, byte_count: int | None = None) -> bytes:
        if start_addr is None:
            start_addr = self.addr
        if byte_count is None:
            byte_count = self.slot_bytes
        if byte_count < 0:
            raise ValueError(f"byte_count must be non-negative, got {byte_count}")
        if byte_count == 0:
            return b""

        start_offset = self.slot_offset_for_addr(start_addr)
        end_offset = start_offset + byte_count
        if end_offset > self.slot_bytes:
            raise AssertionError(
                f"Host read exceeds slot bounds: start_offset={start_offset} "
                f"byte_count={byte_count} slot_bytes={self.slot_bytes}"
            )
        return self.data[start_offset:end_offset]

    def slot_offset_for_addr(self, addr: int) -> int:
        ring_addr = self._normalize_addr(addr)
        for span in self.spans:
            if span.addr <= ring_addr < span.end_addr:
                return span.slot_offset + (ring_addr - span.addr)
        raise AssertionError(
            f"Address 0x{ring_addr:x} is outside slot seq={self.seq} spans={self._span_debug()}"
        )

    def _normalize_addr(self, addr: int) -> int:
        if self.ring_size_bytes <= 0:
            raise ValueError(f"ring_size_bytes must be > 0, got {self.ring_size_bytes}")
        offset = (addr - self.ring_base_addr) % self.ring_size_bytes
        return self.ring_base_addr + offset

    def _span_debug(self) -> str:
        return ",".join(
            f"[addr=0x{span.addr:x} len={span.length} slot_ofs={span.slot_offset}]"
            for span in self.spans
        )


@dataclass
class SlotExpectation:
    seq: int
    payload: bytes
    slot_data: bytes
    slot_bytes: int
    valid_good: int
    overflow_err: int
    sample_count: int
    addr: int | None = None
    regions: tuple[SlotRegion, ...] = ()
    host_slot: HostVisibleSlot | None = None

    @property
    def padding_region(self) -> SlotRegion:
        return self.region("padding")

    @property
    def wraps(self) -> bool:
        return bool(self.host_slot and self.host_slot.wraps)

    @property
    def ring_spans(self) -> tuple[RingSpan, ...]:
        if self.host_slot is None:
            return ()
        return self.host_slot.spans

    def region(self, name: str) -> SlotRegion:
        for region in self.regions:
            if region.name == name:
                return region
        raise KeyError(f"Unknown slot region: {name}")


class SlotRefModel:
    def build_expectation(
        self,
        payload: bytes,
        *,
        seq: int,
        pkt_crc_err: int = 0,
        pkt_ecc_err: int = 0,
        pkt_trunc_err: int = 0,
    ) -> SlotExpectation:
        valid_good = int(not (pkt_crc_err or pkt_ecc_err or pkt_trunc_err))
        overflow_err = int(len(payload) > SLOT_TOTAL_UNALIGNED)
        sample_count = expected_sample_count(payload, pkt_trunc_err=bool(pkt_trunc_err))
        slot_data = build_expected_slot_bytes(payload, pkt_trunc_err=bool(pkt_trunc_err))
        regions = self.build_slot_regions(slot_data)
        return SlotExpectation(
            seq=seq,
            payload=payload,
            slot_data=slot_data,
            slot_bytes=SLOT_TOTAL_ALIGNED,
            valid_good=valid_good,
            overflow_err=overflow_err,
            sample_count=sample_count,
            regions=regions,
        )

    @staticmethod
    def predict_commit_addr(ring_base_addr: int, wr_ptr: int) -> int:
        return ring_base_addr + wr_ptr

    @staticmethod
    def advance_wr_ptr(wr_ptr: int, ring_size_bytes: int, slot_bytes: int) -> int:
        if ring_size_bytes <= 0:
            raise ValueError(f"ring_size_bytes must be > 0, got {ring_size_bytes}")
        return (wr_ptr + slot_bytes) % ring_size_bytes

    @staticmethod
    def build_slot_regions(slot_data: bytes) -> tuple[SlotRegion, ...]:
        return (
            SlotRegion("headers", 0, slot_data[0:RX_HEADER_BYTES_TOTAL]),
            SlotRegion(
                "samples",
                RX_HEADER_BYTES_TOTAL,
                slot_data[RX_HEADER_BYTES_TOTAL : RX_HEADER_BYTES_TOTAL + SAMPLE_AREA_BYTES],
            ),
            SlotRegion(
                "cq",
                RX_HEADER_BYTES_TOTAL + SAMPLE_AREA_BYTES,
                slot_data[
                    RX_HEADER_BYTES_TOTAL
                    + SAMPLE_AREA_BYTES : RX_HEADER_BYTES_TOTAL
                    + SAMPLE_AREA_BYTES
                    + CQ_BYTES
                ],
            ),
            SlotRegion("padding", SLOT_TOTAL_UNALIGNED, slot_data[SLOT_TOTAL_UNALIGNED:]),
        )

    def map_host_slot(
        self,
        expectation: SlotExpectation,
        *,
        ring_base_addr: int,
        ring_size_bytes: int,
        addr: int,
    ) -> HostVisibleSlot:
        spans = self.build_ring_spans(
            ring_base_addr=ring_base_addr,
            ring_size_bytes=ring_size_bytes,
            addr=addr,
            data=expectation.slot_data,
        )
        return HostVisibleSlot(
            seq=expectation.seq,
            slot_bytes=expectation.slot_bytes,
            valid_good=expectation.valid_good,
            overflow_err=expectation.overflow_err,
            ring_base_addr=ring_base_addr,
            ring_size_bytes=ring_size_bytes,
            addr=addr,
            data=expectation.slot_data,
            spans=spans,
            regions=expectation.regions,
            wraps=len(spans) > 1,
        )

    def place_expectation(
        self,
        expectation: SlotExpectation,
        *,
        ring_base_addr: int,
        ring_size_bytes: int,
        wr_ptr: int,
    ) -> SlotExpectation:
        addr = self.predict_commit_addr(ring_base_addr, wr_ptr)
        expectation.addr = addr
        expectation.host_slot = self.map_host_slot(
            expectation,
            ring_base_addr=ring_base_addr,
            ring_size_bytes=ring_size_bytes,
            addr=addr,
        )
        return expectation

    @staticmethod
    def build_ring_spans(
        *,
        ring_base_addr: int,
        ring_size_bytes: int,
        addr: int,
        data: bytes,
    ) -> tuple[RingSpan, ...]:
        if ring_size_bytes <= 0:
            raise ValueError(f"ring_size_bytes must be > 0, got {ring_size_bytes}")
        if len(data) == 0:
            return ()

        ring_end = ring_base_addr + ring_size_bytes
        spans: list[RingSpan] = []
        slot_offset = 0
        cur_addr = ring_base_addr + ((addr - ring_base_addr) % ring_size_bytes)
        remaining = len(data)

        while remaining > 0:
            chunk_len = min(remaining, ring_end - cur_addr)
            spans.append(
                RingSpan(
                    addr=cur_addr,
                    slot_offset=slot_offset,
                    data=data[slot_offset : slot_offset + chunk_len],
                )
            )
            slot_offset += chunk_len
            remaining -= chunk_len
            cur_addr = ring_base_addr

        return tuple(spans)
