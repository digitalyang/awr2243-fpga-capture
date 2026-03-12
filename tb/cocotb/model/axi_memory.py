from __future__ import annotations

from types import SimpleNamespace

from cocotb.triggers import FallingEdge, RisingEdge


def int_to_bytes(value: int, byte_count: int) -> bytes:
    return int(value).to_bytes(byte_count, byteorder="little", signed=False)


def bytes_to_int(data: bytes) -> int:
    return int.from_bytes(data, byteorder="little", signed=False)


class AxiMemoryModel:
    def __init__(self, dut, *, prefix: str = "m_axi", clock_name: str = "axis_clk", reset_name: str = "rst_ni"):
        self.dut = dut
        self.clock = getattr(dut, clock_name)
        self.reset = getattr(dut, reset_name)
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
        self.mem: dict[int, int] = {}
        self.reset_bus()

    def reset_bus(self) -> None:
        self._wr_active = False
        self._rd_active = False
        self._wr_addr = 0
        self._rd_addr = 0
        self._wr_beats_rem = 0
        self._rd_beats_rem = 0
        self._wr_step_bytes = self.beat_bytes
        self._rd_step_bytes = self.beat_bytes
        self._bvalid = 0
        self._bresp = 0
        self._rvalid = 0
        self._rdata = 0
        self._rresp = 0
        self._rlast = 0

    def drive_outputs(self) -> None:
        self.bus.awready.value = int((not self._wr_active) and (not self._bvalid))
        self.bus.wready.value = int(self._wr_active)
        self.bus.bresp.value = self._bresp
        self.bus.bvalid.value = self._bvalid
        self.bus.arready.value = int((not self._rd_active) and (not self._rvalid))
        self.bus.rdata.value = self._rdata
        self.bus.rresp.value = self._rresp
        self.bus.rlast.value = self._rlast
        self.bus.rvalid.value = self._rvalid

    def write_mem_word(self, addr: int, data: int, strb: int) -> None:
        raw = int_to_bytes(data, self.beat_bytes)
        for lane in range(self.beat_bytes):
            if (strb >> lane) & 0x1:
                self.mem[addr + lane] = raw[lane]

    def read_mem_word(self, addr: int) -> int:
        raw = bytes(self.mem.get(addr + lane, 0) for lane in range(self.beat_bytes))
        return bytes_to_int(raw)

    def read_ring_bytes(self, ring_base: int, ring_size: int, start_addr: int, byte_count: int) -> bytes:
        payload = []
        addr = start_addr
        ring_end = ring_base + ring_size
        for _ in range(byte_count):
            if addr >= ring_end:
                addr = ring_base
            payload.append(self.mem.get(addr, 0))
            addr += 1
        return bytes(payload)

    async def run(self) -> None:
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

            if self._bvalid and int(self.bus.bready.value):
                self._bvalid = 0

            if int(self.bus.awvalid.value) and int(self.bus.awready.value):
                self._wr_active = True
                self._wr_addr = int(self.bus.awaddr.value)
                self._wr_beats_rem = int(self.bus.awlen.value) + 1
                self._wr_step_bytes = 1 << int(self.bus.awsize.value)

            if int(self.bus.wvalid.value) and int(self.bus.wready.value):
                self.write_mem_word(
                    self._wr_addr,
                    int(self.bus.wdata.value),
                    int(self.bus.wstrb.value),
                )
                self._wr_addr += self._wr_step_bytes
                if self._wr_beats_rem > 0:
                    self._wr_beats_rem -= 1
                if int(self.bus.wlast.value) or self._wr_beats_rem == 0:
                    self._wr_active = False
                    self._bresp = 0
                    self._bvalid = 1

            if self._rvalid and int(self.bus.rready.value):
                self._rvalid = 0
                self._rlast = 0

            if int(self.bus.arvalid.value) and int(self.bus.arready.value):
                self._rd_active = True
                self._rd_addr = int(self.bus.araddr.value)
                self._rd_beats_rem = int(self.bus.arlen.value) + 1
                self._rd_step_bytes = 1 << int(self.bus.arsize.value)

            if (not self._rvalid) and self._rd_active:
                self._rdata = self.read_mem_word(self._rd_addr)
                self._rresp = 0
                self._rlast = int(self._rd_beats_rem == 1)
                self._rvalid = 1
                self._rd_addr += self._rd_step_bytes
                if self._rd_beats_rem > 0:
                    self._rd_beats_rem -= 1
                if self._rd_beats_rem == 0:
                    self._rd_active = False
