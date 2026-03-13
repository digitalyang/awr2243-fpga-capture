from __future__ import annotations

from dataclasses import dataclass
from types import SimpleNamespace

from cocotb.triggers import FallingEdge, RisingEdge

from model.axi_memory import AxiMemoryModel, int_to_bytes


def bytes_to_int(data: bytes) -> int:
    return int.from_bytes(data, byteorder="little", signed=False)


@dataclass(frozen=True)
class AxiBurstRecord:
    addr: int
    beats: int
    beat_bytes: int


class InstrumentedAxiMemoryModel(AxiMemoryModel):
    def __init__(self, dut, *, prefix: str, clock_name: str = "clk_i", reset_name: str = "rst_ni"):
        super().__init__(dut, prefix=prefix, clock_name=clock_name, reset_name=reset_name)
        self.write_bursts: list[AxiBurstRecord] = []
        self.read_bursts: list[AxiBurstRecord] = []

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
                self.write_bursts.append(
                    AxiBurstRecord(
                        addr=self._wr_addr,
                        beats=self._wr_beats_rem,
                        beat_bytes=self._wr_step_bytes,
                    )
                )

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
                self.read_bursts.append(
                    AxiBurstRecord(
                        addr=self._rd_addr,
                        beats=self._rd_beats_rem,
                        beat_bytes=self._rd_step_bytes,
                    )
                )

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


class AxiMasterBurstDriver:
    def __init__(self, dut, *, prefix: str, clock_name: str = "clk_i"):
        self.dut = dut
        self.clock = getattr(dut, clock_name)
        self.bus = SimpleNamespace(
            awaddr=getattr(dut, f"{prefix}_awaddr"),
            awlen=getattr(dut, f"{prefix}_awlen"),
            awsize=getattr(dut, f"{prefix}_awsize"),
            awburst=getattr(dut, f"{prefix}_awburst"),
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
            arburst=getattr(dut, f"{prefix}_arburst"),
            arvalid=getattr(dut, f"{prefix}_arvalid"),
            arready=getattr(dut, f"{prefix}_arready"),
            rdata=getattr(dut, f"{prefix}_rdata"),
            rresp=getattr(dut, f"{prefix}_rresp"),
            rlast=getattr(dut, f"{prefix}_rlast"),
            rvalid=getattr(dut, f"{prefix}_rvalid"),
            rready=getattr(dut, f"{prefix}_rready"),
        )
        self.beat_bytes = len(self.bus.wdata) // 8
        self.drive_idle()

    def drive_idle(self) -> None:
        self.bus.awaddr.value = 0
        self.bus.awlen.value = 0
        self.bus.awsize.value = 0
        self.bus.awburst.value = 0
        self.bus.awvalid.value = 0
        self.bus.wdata.value = 0
        self.bus.wstrb.value = 0
        self.bus.wlast.value = 0
        self.bus.wvalid.value = 0
        self.bus.bready.value = 0
        self.bus.araddr.value = 0
        self.bus.arlen.value = 0
        self.bus.arsize.value = 0
        self.bus.arburst.value = 0
        self.bus.arvalid.value = 0
        self.bus.rready.value = 0

    async def write_burst(self, addr: int, words: list[int], *, strbs: list[int] | None = None) -> int:
        if not words:
            raise ValueError("write_burst requires at least one data word")

        full_strb = (1 << self.beat_bytes) - 1
        use_strbs = strbs or [full_strb] * len(words)

        self.bus.awaddr.value = addr
        self.bus.awlen.value = len(words) - 1
        self.bus.awsize.value = (self.beat_bytes.bit_length() - 1)
        self.bus.awburst.value = 1
        self.bus.awvalid.value = 1

        while True:
            await RisingEdge(self.clock)
            if int(self.bus.awvalid.value) and int(self.bus.awready.value):
                break

        self.bus.awvalid.value = 0

        for index, word in enumerate(words):
            self.bus.wdata.value = word
            self.bus.wstrb.value = use_strbs[index]
            self.bus.wlast.value = int(index == (len(words) - 1))
            self.bus.wvalid.value = 1

            while True:
                await RisingEdge(self.clock)
                if int(self.bus.wvalid.value) and int(self.bus.wready.value):
                    break

        self.bus.wvalid.value = 0
        self.bus.wlast.value = 0
        self.bus.bready.value = 1

        while True:
            await RisingEdge(self.clock)
            if int(self.bus.bvalid.value) and int(self.bus.bready.value):
                resp = int(self.bus.bresp.value)
                break

        self.bus.bready.value = 0
        return resp

    async def read_burst(self, addr: int, beats: int) -> list[int]:
        if beats <= 0:
            raise ValueError("read_burst requires beats > 0")

        self.bus.araddr.value = addr
        self.bus.arlen.value = beats - 1
        self.bus.arsize.value = (self.beat_bytes.bit_length() - 1)
        self.bus.arburst.value = 1
        self.bus.arvalid.value = 1

        while True:
            await RisingEdge(self.clock)
            if int(self.bus.arvalid.value) and int(self.bus.arready.value):
                break

        self.bus.arvalid.value = 0
        self.bus.rready.value = 1

        words: list[int] = []
        while True:
            await RisingEdge(self.clock)
            if int(self.bus.rvalid.value) and int(self.bus.rready.value):
                words.append(int(self.bus.rdata.value))
                if int(self.bus.rlast.value):
                    break

        self.bus.rready.value = 0
        return words

    async def write_bytes(self, addr: int, payload: bytes) -> int:
        words: list[int] = []
        strbs: list[int] = []
        for offset in range(0, len(payload), self.beat_bytes):
            chunk = payload[offset : offset + self.beat_bytes]
            words.append(bytes_to_int(chunk.ljust(self.beat_bytes, b"\x00")))
            strbs.append((1 << len(chunk)) - 1)
        return await self.write_burst(addr, words, strbs=strbs)

    async def read_bytes(self, addr: int, size_bytes: int) -> bytes:
        words = await self.read_burst(addr, (size_bytes + self.beat_bytes - 1) // self.beat_bytes)
        raw = bytearray()
        for word in words:
            raw.extend(int_to_bytes(word, self.beat_bytes))
        return bytes(raw[:size_bytes])
