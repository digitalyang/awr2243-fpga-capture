from __future__ import annotations

from dataclasses import dataclass

from cocotb.triggers import RisingEdge


def int_to_bytes(value: int, byte_count: int) -> bytes:
    return int(value).to_bytes(byte_count, byteorder="little", signed=False)


@dataclass
class AxisFrame:
    data: bytes
    beat_count: int
    first_tuser: int
    last_tuser: int


class AxisStreamMonitor:
    def __init__(self, clock, tdata, tkeep, tvalid, tready, tlast, tuser):
        self.clock = clock
        self.tdata = tdata
        self.tkeep = tkeep
        self.tvalid = tvalid
        self.tready = tready
        self.tlast = tlast
        self.tuser = tuser
        self.beat_bytes = len(tdata) // 8

    async def capture_frame(self, timeout_cycles: int = 1500) -> AxisFrame:
        payload = bytearray()
        beat_count = 0
        first_tuser = None
        last_tuser = 0

        for _ in range(timeout_cycles):
            await RisingEdge(self.clock)
            if int(self.tvalid.value) and int(self.tready.value):
                beat_count += 1
                beat_data = int_to_bytes(int(self.tdata.value), self.beat_bytes)
                beat_keep = int(self.tkeep.value)
                tuser_value = int(self.tuser.value)

                if first_tuser is None:
                    first_tuser = tuser_value
                last_tuser = tuser_value

                for lane in range(self.beat_bytes):
                    if (beat_keep >> lane) & 0x1:
                        payload.append(beat_data[lane])

                if int(self.tlast.value):
                    return AxisFrame(
                        data=bytes(payload),
                        beat_count=beat_count,
                        first_tuser=0 if first_tuser is None else first_tuser,
                        last_tuser=last_tuser,
                    )

        raise TimeoutError("Timed out while waiting for a complete AXIS frame")
