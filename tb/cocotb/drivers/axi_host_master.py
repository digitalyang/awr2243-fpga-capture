from __future__ import annotations

from dataclasses import dataclass

from cocotb.triggers import RisingEdge


RD_TUSER_FIRST_BIT = 0
RD_TUSER_VALID_BIT = 2
RD_TUSER_OVF_BIT = 3
RD_TUSER_SEQ_LSB = 8
RD_TUSER_BYTES_LSB = 32


def int_to_bytes(value: int, byte_count: int) -> bytes:
    return int(value).to_bytes(byte_count, byteorder="little", signed=False)


@dataclass
class ReadbackSlot:
    seq: int
    slot_bytes: int
    valid_good: int
    overflow_err: int
    payload: bytes


class AxiHostMaster:
    def __init__(self, dut):
        self.dut = dut
        self.clock = dut.axis_clk
        self.beat_bytes = len(dut.m_axis_rd_tdata) // 8

    async def wait_slot_available(self, timeout_cycles: int = 1500) -> None:
        for _ in range(timeout_cycles):
            await RisingEdge(self.clock)
            if int(self.dut.rd_slot_valid_o.value):
                return
        raise TimeoutError("Timed out waiting for rd_slot_valid_o")

    async def request_slot(self) -> None:
        await self.wait_slot_available()
        self.dut.rd_slot_req_i.value = 1
        await RisingEdge(self.clock)
        self.dut.rd_slot_req_i.value = 0

    async def read_next_slot(self, timeout_cycles: int = 1500) -> ReadbackSlot:
        payload = bytearray()
        meta = None
        self.dut.m_axis_rd_tready.value = 1

        await self.request_slot()

        for _ in range(timeout_cycles):
            await RisingEdge(self.clock)
            if int(self.dut.m_axis_rd_tvalid.value) and int(self.dut.m_axis_rd_tready.value):
                if meta is None:
                    tuser = int(self.dut.m_axis_rd_tuser.value)
                    meta = ReadbackSlot(
                        seq=(tuser >> RD_TUSER_SEQ_LSB) & ((1 << len(self.dut.rd_slot_seq_o)) - 1),
                        slot_bytes=(tuser >> RD_TUSER_BYTES_LSB) & ((1 << len(self.dut.rd_slot_bytes_o)) - 1),
                        valid_good=(tuser >> RD_TUSER_VALID_BIT) & 0x1,
                        overflow_err=(tuser >> RD_TUSER_OVF_BIT) & 0x1,
                        payload=b"",
                    )
                    assert ((tuser >> RD_TUSER_FIRST_BIT) & 0x1) == 1, "Missing readback first marker"

                beat_data = int_to_bytes(int(self.dut.m_axis_rd_tdata.value), self.beat_bytes)
                beat_keep = int(self.dut.m_axis_rd_tkeep.value)
                for lane in range(self.beat_bytes):
                    if (beat_keep >> lane) & 0x1:
                        payload.append(beat_data[lane])

                if int(self.dut.m_axis_rd_tlast.value):
                    assert meta is not None
                    meta.payload = bytes(payload)
                    return meta

        raise TimeoutError("Timed out collecting m_axis_rd slot payload")

    async def consume_slot(self) -> None:
        self.dut.rd_consume_i.value = 1
        await RisingEdge(self.clock)
        self.dut.rd_consume_i.value = 0
        await RisingEdge(self.clock)

    async def read_and_consume(self, timeout_cycles: int = 1500) -> ReadbackSlot:
        slot = await self.read_next_slot(timeout_cycles=timeout_cycles)
        await self.consume_slot()
        return slot
