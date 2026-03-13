from __future__ import annotations

from collections import deque

from model.slot_refmodel import HostVisibleSlot, SlotExpectation, SlotRefModel


class SlotScoreboard:
    def __init__(self, *, ring_base_addr: int, ring_size_bytes: int):
        self.ring_base_addr = ring_base_addr
        self.ring_size_bytes = ring_size_bytes
        self.refmodel = SlotRefModel()
        self.pending_commits: deque[SlotExpectation] = deque()
        self.pending_reads: deque[SlotExpectation] = deque()
        self.errors: list[str] = []
        self.matches = 0
        self._wr_ptr = 0

    def push_expectation(
        self,
        payload: bytes,
        *,
        seq: int,
        pkt_crc_err: int = 0,
        pkt_ecc_err: int = 0,
        pkt_trunc_err: int = 0,
    ) -> SlotExpectation:
        expectation = self.refmodel.build_expectation(
            payload,
            seq=seq,
            pkt_crc_err=pkt_crc_err,
            pkt_ecc_err=pkt_ecc_err,
            pkt_trunc_err=pkt_trunc_err,
        )
        self.refmodel.place_expectation(
            expectation,
            ring_base_addr=self.ring_base_addr,
            ring_size_bytes=self.ring_size_bytes,
            wr_ptr=self._wr_ptr,
        )
        self._wr_ptr = self.refmodel.advance_wr_ptr(self._wr_ptr, self.ring_size_bytes, expectation.slot_bytes)
        self.pending_commits.append(expectation)
        return expectation

    def check_commit(
        self,
        *,
        seq: int,
        slot_bytes: int,
        valid_good: int,
        overflow_err: int,
        addr: int,
    ) -> SlotExpectation:
        if not self.pending_commits:
            raise AssertionError("No queued expectation for commit")

        exp = self.pending_commits.popleft()
        assert seq == exp.seq, f"Commit seq mismatch: exp={exp.seq} act={seq}"
        assert slot_bytes == exp.slot_bytes, f"Commit slot_bytes mismatch: exp={exp.slot_bytes} act={slot_bytes}"
        assert valid_good == exp.valid_good, f"Commit valid_good mismatch: exp={exp.valid_good} act={valid_good}"
        assert overflow_err == exp.overflow_err, (
            f"Commit overflow mismatch: exp={exp.overflow_err} act={overflow_err}"
        )
        assert addr == exp.addr, f"Commit addr mismatch: exp=0x{exp.addr:x} act=0x{addr:x}"
        self.pending_reads.append(exp)
        self.matches += 1
        return exp

    def check_memory(self, memory_model, expectation: SlotExpectation) -> None:
        host_slot = self.host_slot_for(expectation)
        stored = memory_model.read_ring_bytes(
            ring_base=self.ring_base_addr,
            ring_size=self.ring_size_bytes,
            start_addr=host_slot.addr,
            byte_count=host_slot.slot_bytes,
        )
        assert stored == host_slot.data, (
            f"Stored slot mismatch for seq={expectation.seq} spans={self._span_debug(host_slot)}"
        )
        self.matches += 1

    def check_host_dma_read(
        self,
        *,
        addr: int,
        data: bytes,
        expectation: SlotExpectation | None = None,
        seq: int | None = None,
    ) -> SlotExpectation:
        exp = expectation if expectation is not None else self.last_committed_expectation()
        host_slot = self.host_slot_for(exp)
        if seq is not None:
            assert seq == exp.seq, f"Host/DMA seq mismatch: exp={exp.seq} act={seq}"
        expected = host_slot.read(start_addr=addr, byte_count=len(data))
        assert data == expected, (
            f"Host/DMA read mismatch for seq={exp.seq} addr=0x{addr:x} bytes={len(data)} "
            f"spans={self._span_debug(host_slot)}"
        )
        self.matches += 1
        return exp

    def check_readback(self, read_slot) -> SlotExpectation:
        if not self.pending_reads:
            raise AssertionError("No queued expectation for readback")

        exp = self.pending_reads.popleft()
        host_slot = self.host_slot_for(exp)
        assert read_slot.seq == exp.seq, f"Readback seq mismatch: exp={exp.seq} act={read_slot.seq}"
        assert read_slot.slot_bytes == exp.slot_bytes, (
            f"Readback slot_bytes mismatch: exp={exp.slot_bytes} act={read_slot.slot_bytes}"
        )
        assert read_slot.valid_good == exp.valid_good, (
            f"Readback valid_good mismatch: exp={exp.valid_good} act={read_slot.valid_good}"
        )
        assert read_slot.overflow_err == exp.overflow_err, (
            f"Readback overflow mismatch: exp={exp.overflow_err} act={read_slot.overflow_err}"
        )
        assert read_slot.payload == host_slot.data, f"Readback payload mismatch for seq={exp.seq}"
        self.matches += 1
        return exp

    def last_committed_expectation(self) -> SlotExpectation:
        if not self.pending_reads:
            raise AssertionError("No committed expectation is pending for readback")
        return self.pending_reads[-1]

    def host_slot_for(self, expectation: SlotExpectation) -> HostVisibleSlot:
        if expectation.host_slot is None:
            raise AssertionError(f"Expectation seq={expectation.seq} does not have host-slot mapping")
        return expectation.host_slot

    @staticmethod
    def _span_debug(host_slot: HostVisibleSlot) -> str:
        return ",".join(
            f"[addr=0x{span.addr:x} len={span.length} slot_ofs={span.slot_offset}]"
            for span in host_slot.spans
        )

    def summary(self) -> dict[str, int]:
        return {
            "matches": self.matches,
            "pending_commits": len(self.pending_commits),
            "pending_reads": len(self.pending_reads),
        }
