from __future__ import annotations

from dataclasses import dataclass

from cocotb.triggers import RisingEdge


@dataclass(frozen=True)
class RcCompletion:
    tag: int
    status: int
    data: int


class PcieHostRcMaster:
    def __init__(self, dut, prefix: str = "host_rc"):
        self.dut = dut
        self.clock = dut.clk_i
        self.req_valid = getattr(dut, f"{prefix}_req_valid")
        self.req_ready = getattr(dut, f"{prefix}_req_ready")
        self.req_write = getattr(dut, f"{prefix}_req_write")
        self.req_bar = getattr(dut, f"{prefix}_req_bar")
        self.req_addr = getattr(dut, f"{prefix}_req_addr")
        self.req_data = getattr(dut, f"{prefix}_req_data")
        self.req_strb = getattr(dut, f"{prefix}_req_strb")
        self.req_tag = getattr(dut, f"{prefix}_req_tag")
        self.rsp_valid = getattr(dut, f"{prefix}_rsp_valid")
        self.rsp_ready = getattr(dut, f"{prefix}_rsp_ready")
        self.rsp_data = getattr(dut, f"{prefix}_rsp_data")
        self.rsp_status = getattr(dut, f"{prefix}_rsp_status")
        self.rsp_tag = getattr(dut, f"{prefix}_rsp_tag")
        self.tag_mask = (1 << len(self.req_tag)) - 1
        self.next_tag = 0

    def drive_idle(self) -> None:
        self.req_valid.value = 0
        self.req_write.value = 0
        self.req_bar.value = 0
        self.req_addr.value = 0
        self.req_data.value = 0
        self.req_strb.value = 0
        self.req_tag.value = 0
        self.rsp_ready.value = 0

    async def _issue(
        self,
        *,
        write: bool,
        bar: int,
        addr: int,
        data: int = 0,
        strb: int = 0xF,
        tag: int | None = None,
    ) -> RcCompletion:
        if tag is None:
            tag = self.next_tag & self.tag_mask
            self.next_tag += 1

        self.req_write.value = int(write)
        self.req_bar.value = bar
        self.req_addr.value = addr
        self.req_data.value = data
        self.req_strb.value = strb
        self.req_tag.value = tag
        self.req_valid.value = 1

        while True:
            await RisingEdge(self.clock)
            if int(self.req_valid.value) and int(self.req_ready.value):
                break

        self.req_valid.value = 0
        self.rsp_ready.value = 1

        while True:
            await RisingEdge(self.clock)
            if int(self.rsp_valid.value):
                completion = RcCompletion(
                    tag=int(self.rsp_tag.value),
                    status=int(self.rsp_status.value),
                    data=int(self.rsp_data.value),
                )
                self.rsp_ready.value = 0
                return completion

    async def write32(self, addr: int, data: int, *, bar: int = 0, strb: int = 0xF) -> RcCompletion:
        return await self._issue(write=True, bar=bar, addr=addr, data=data, strb=strb)

    async def read32(self, addr: int, *, bar: int = 0) -> RcCompletion:
        return await self._issue(write=False, bar=bar, addr=addr, data=0, strb=0)
