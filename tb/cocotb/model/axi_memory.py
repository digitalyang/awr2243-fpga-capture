from __future__ import annotations

from dataclasses import dataclass
from types import SimpleNamespace

try:
    from cocotb.triggers import FallingEdge, RisingEdge
except ModuleNotFoundError:  # pragma: no cover - exercised only in unit-test environments without cocotb
    FallingEdge = None
    RisingEdge = None


def int_to_bytes(value: int, byte_count: int) -> bytes:
    return int(value).to_bytes(byte_count, byteorder="little", signed=False)


def bytes_to_int(data: bytes) -> int:
    return int.from_bytes(data, byteorder="little", signed=False)


@dataclass(frozen=True)
class AxiBackpressureProfile:
    aw_ready_delay: int = 0
    w_ready_delay: int = 0
    b_valid_delay: int = 0
    ar_ready_delay: int = 0
    r_valid_delay: int = 0


@dataclass
class AxiBurstRecord:
    addr: int
    beats: int
    size_bytes: int
    start_cycle: int
    observed_beats: int = 0
    end_cycle: int | None = None

    @property
    def byte_count(self) -> int:
        return self.beats * self.size_bytes


class AxiMemoryModel:
    def __init__(
        self,
        dut=None,
        *,
        prefix: str = "m_axi",
        clock_name: str = "axis_clk",
        reset_name: str = "rst_ni",
        beat_bytes: int | None = None,
    ):
        self.dut = dut
        self.clock = getattr(dut, clock_name) if dut is not None else None
        self.reset = getattr(dut, reset_name) if dut is not None else None
        if dut is not None:
            self.bus = SimpleNamespace(
                awaddr=getattr(dut, f"{prefix}_awaddr"),
                awlen=getattr(dut, f"{prefix}_awlen"),
                awsize=getattr(dut, f"{prefix}_awsize"),
                awvalid=getattr(dut, f"{prefix}_awvalid"),
                awready=getattr(dut, f"{prefix}_awready"),
                wdata=getattr(dut, f"{prefix}_wdata"),
                wstrb=getattr(dut, f"{prefix}_wstrb"),
                wlast=getattr(dut, f"{prefix}_wlast"),
                wvalid=getattr(dut, f"{prefix}_wvalid"),
                wready=getattr(dut, f"{prefix}_wready"),
                bresp=getattr(dut, f"{prefix}_bresp"),
                bvalid=getattr(dut, f"{prefix}_bvalid"),
                bready=getattr(dut, f"{prefix}_bready"),
                araddr=getattr(dut, f"{prefix}_araddr"),
                arlen=getattr(dut, f"{prefix}_arlen"),
                arsize=getattr(dut, f"{prefix}_arsize"),
                arvalid=getattr(dut, f"{prefix}_arvalid"),
                arready=getattr(dut, f"{prefix}_arready"),
                rdata=getattr(dut, f"{prefix}_rdata"),
                rresp=getattr(dut, f"{prefix}_rresp"),
                rlast=getattr(dut, f"{prefix}_rlast"),
                rvalid=getattr(dut, f"{prefix}_rvalid"),
                rready=getattr(dut, f"{prefix}_rready"),
            )
            self.beat_bytes = len(self.bus.wdata) // 8
        else:
            self.bus = None
            self.beat_bytes = 32 if beat_bytes is None else beat_bytes
        self.mem: dict[int, int] = {}
        self.backpressure = AxiBackpressureProfile()
        self.write_bursts: list[AxiBurstRecord] = []
        self.read_bursts: list[AxiBurstRecord] = []
        self._stall_counters = self._new_stall_counters()
        self.reset_bus()

    def _new_stall_counters(self) -> dict[str, int]:
        return {
            "aw_ready_cycles": 0,
            "w_ready_cycles": 0,
            "b_valid_cycles": 0,
            "ar_ready_cycles": 0,
            "r_valid_cycles": 0,
        }

    def clear_activity(self) -> None:
        self.write_bursts.clear()
        self.read_bursts.clear()
        self._stall_counters = self._new_stall_counters()

    def stall_counters(self) -> dict[str, int]:
        return dict(self._stall_counters)

    def set_backpressure(
        self,
        *,
        aw_ready_delay: int = 0,
        w_ready_delay: int = 0,
        b_valid_delay: int = 0,
        ar_ready_delay: int = 0,
        r_valid_delay: int = 0,
    ) -> None:
        profile = AxiBackpressureProfile(
            aw_ready_delay=aw_ready_delay,
            w_ready_delay=w_ready_delay,
            b_valid_delay=b_valid_delay,
            ar_ready_delay=ar_ready_delay,
            r_valid_delay=r_valid_delay,
        )
        if any(value < 0 for value in profile.__dict__.values()):
            raise ValueError(f"AXI backpressure delays must be non-negative: {profile}")

        self.backpressure = profile
        if (not self._wr_active) and (not self._bvalid) and (not self._b_pending):
            self._aw_wait = self.backpressure.aw_ready_delay
        if (not self._rd_active) and (not self._rvalid):
            self._ar_wait = self.backpressure.ar_ready_delay

    def reset_backpressure(self) -> None:
        self.set_backpressure()

    @property
    def cycle(self) -> int:
        return self._cycle

    def reset_bus(self) -> None:
        self._cycle = 0
        self._wr_active = False
        self._rd_active = False
        self._wr_addr = 0
        self._rd_addr = 0
        self._wr_beats_rem = 0
        self._rd_beats_rem = 0
        self._wr_step_bytes = self.beat_bytes
        self._rd_step_bytes = self.beat_bytes
        self._aw_wait = self.backpressure.aw_ready_delay
        self._w_wait = 0
        self._b_wait = 0
        self._b_pending = False
        self._ar_wait = self.backpressure.ar_ready_delay
        self._r_wait = 0
        self._active_write_burst: AxiBurstRecord | None = None
        self._active_read_burst: AxiBurstRecord | None = None
        self._bvalid = 0
        self._bresp = 0
        self._rvalid = 0
        self._rdata = 0
        self._rresp = 0
        self._rlast = 0

    def drive_outputs(self) -> None:
        if self.bus is None:
            raise RuntimeError("drive_outputs requires a DUT-backed AxiMemoryModel")
        self.bus.awready.value = int((not self._wr_active) and (not self._bvalid) and (not self._b_pending) and (self._aw_wait == 0))
        self.bus.wready.value = int(self._wr_active and (self._w_wait == 0))
        self.bus.bresp.value = self._bresp
        self.bus.bvalid.value = self._bvalid
        self.bus.arready.value = int((not self._rd_active) and (not self._rvalid) and (self._ar_wait == 0))
        self.bus.rdata.value = self._rdata
        self.bus.rresp.value = self._rresp
        self.bus.rlast.value = self._rlast
        self.bus.rvalid.value = self._rvalid

    def write_mem_word(self, addr: int, data: int, strb: int) -> None:
        raw = int_to_bytes(data, self.beat_bytes)
        for lane in range(self.beat_bytes):
            if (strb >> lane) & 0x1:
                self.mem[addr + lane] = raw[lane]

    def write_bytes(self, start_addr: int, data: bytes) -> None:
        for offset, value in enumerate(data):
            self.mem[start_addr + offset] = value

    def write_ring_bytes(self, *, ring_base: int, ring_size: int, start_addr: int, data: bytes) -> None:
        addr = self.normalize_ring_addr(ring_base=ring_base, ring_size=ring_size, addr=start_addr)
        for value in data:
            self.mem[addr] = value
            addr += 1
            if addr >= ring_base + ring_size:
                addr = ring_base

    def read_mem_word(self, addr: int) -> int:
        raw = bytes(self.mem.get(addr + lane, 0) for lane in range(self.beat_bytes))
        return bytes_to_int(raw)

    def read_bytes(self, start_addr: int, byte_count: int) -> bytes:
        return bytes(self.mem.get(start_addr + offset, 0) for offset in range(byte_count))

    @staticmethod
    def normalize_ring_addr(*, ring_base: int, ring_size: int, addr: int) -> int:
        if ring_size <= 0:
            raise ValueError(f"ring_size must be > 0, got {ring_size}")
        return ring_base + ((addr - ring_base) % ring_size)

    def read_ring_bytes(self, ring_base: int, ring_size: int, start_addr: int, byte_count: int) -> bytes:
        payload = []
        addr = self.normalize_ring_addr(ring_base=ring_base, ring_size=ring_size, addr=start_addr)
        ring_end = ring_base + ring_size
        for _ in range(byte_count):
            if addr >= ring_end:
                addr = ring_base
            payload.append(self.mem.get(addr, 0))
            addr += 1
        return bytes(payload)

    def _record_aw_handshake(self) -> None:
        self._wr_active = True
        self._wr_addr = int(self.bus.awaddr.value)
        self._wr_beats_rem = int(self.bus.awlen.value) + 1
        self._wr_step_bytes = 1 << int(self.bus.awsize.value)
        self._w_wait = self.backpressure.w_ready_delay
        self._active_write_burst = AxiBurstRecord(
            addr=self._wr_addr,
            beats=self._wr_beats_rem,
            size_bytes=self._wr_step_bytes,
            start_cycle=self._cycle,
        )
        self.write_bursts.append(self._active_write_burst)

    def _record_ar_handshake(self) -> None:
        self._rd_active = True
        self._rd_addr = int(self.bus.araddr.value)
        self._rd_beats_rem = int(self.bus.arlen.value) + 1
        self._rd_step_bytes = 1 << int(self.bus.arsize.value)
        self._r_wait = self.backpressure.r_valid_delay
        self._active_read_burst = AxiBurstRecord(
            addr=self._rd_addr,
            beats=self._rd_beats_rem,
            size_bytes=self._rd_step_bytes,
            start_cycle=self._cycle,
        )
        self.read_bursts.append(self._active_read_burst)

    async def run(self) -> None:
        if FallingEdge is None or RisingEdge is None:
            raise ModuleNotFoundError("cocotb is required to run the live AXI memory model")
        if self.bus is None or self.clock is None or self.reset is None:
            raise RuntimeError("run() requires a DUT-backed AxiMemoryModel")
        self.reset_bus()
        while True:
            await FallingEdge(self.clock)
            if int(self.reset.value) == 0:
                self.reset_bus()
            self.drive_outputs()

            await RisingEdge(self.clock)
            if int(self.reset.value) == 0:
                self.reset_bus()
                continue

            self._cycle += 1

            if self._bvalid and int(self.bus.bready.value):
                self._bvalid = 0
                if not self._wr_active:
                    self._aw_wait = self.backpressure.aw_ready_delay

            if self._b_pending:
                if self._b_wait > 0:
                    self._b_wait -= 1
                    self._stall_counters["b_valid_cycles"] += 1
                else:
                    self._b_pending = False
                    self._bresp = 0
                    self._bvalid = 1

            aw_available = (not self._wr_active) and (not self._bvalid) and (not self._b_pending)
            if aw_available and int(self.bus.awvalid.value):
                if self._aw_wait > 0:
                    self._aw_wait -= 1
                    self._stall_counters["aw_ready_cycles"] += 1
                elif int(self.bus.awready.value):
                    self._record_aw_handshake()

            if self._wr_active and int(self.bus.wvalid.value):
                if self._w_wait > 0:
                    self._w_wait -= 1
                    self._stall_counters["w_ready_cycles"] += 1
                elif int(self.bus.wready.value):
                    self.write_mem_word(
                        self._wr_addr,
                        int(self.bus.wdata.value),
                        int(self.bus.wstrb.value),
                    )
                    if self._active_write_burst is not None:
                        self._active_write_burst.observed_beats += 1
                    self._wr_addr += self._wr_step_bytes
                    if self._wr_beats_rem > 0:
                        self._wr_beats_rem -= 1
                    if int(self.bus.wlast.value) or self._wr_beats_rem == 0:
                        if self._active_write_burst is not None:
                            self._active_write_burst.end_cycle = self._cycle
                        self._active_write_burst = None
                        self._wr_active = False
                        self._bresp = 0
                        if self.backpressure.b_valid_delay > 0:
                            self._b_pending = True
                            self._b_wait = self.backpressure.b_valid_delay
                        else:
                            self._bvalid = 1
                    else:
                        self._w_wait = self.backpressure.w_ready_delay

            if self._rvalid and int(self.bus.rready.value):
                if self._active_read_burst is not None:
                    self._active_read_burst.observed_beats += 1
                    if int(self.bus.rlast.value):
                        self._active_read_burst.end_cycle = self._cycle
                        self._active_read_burst = None
                        self._ar_wait = self.backpressure.ar_ready_delay
                    elif self._rd_active:
                        self._r_wait = self.backpressure.r_valid_delay
                self._rvalid = 0
                self._rlast = 0

            ar_available = (not self._rd_active) and (not self._rvalid)
            if ar_available and int(self.bus.arvalid.value):
                if self._ar_wait > 0:
                    self._ar_wait -= 1
                    self._stall_counters["ar_ready_cycles"] += 1
                elif int(self.bus.arready.value):
                    self._record_ar_handshake()

            if (not self._rvalid) and self._rd_active:
                if self._r_wait > 0:
                    self._r_wait -= 1
                    self._stall_counters["r_valid_cycles"] += 1
                else:
                    self._rdata = self.read_mem_word(self._rd_addr)
                    self._rresp = 0
                    self._rlast = int(self._rd_beats_rem == 1)
                    self._rvalid = 1
                    self._rd_addr += self._rd_step_bytes
                    if self._rd_beats_rem > 0:
                        self._rd_beats_rem -= 1
                    if self._rd_beats_rem == 0:
                        self._rd_active = False
