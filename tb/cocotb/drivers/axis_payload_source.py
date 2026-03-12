from __future__ import annotations

from dataclasses import dataclass

from cocotb.triggers import RisingEdge


TUSER_PKT_START_BIT = 0
TUSER_CRC_ERR_BIT = 1
TUSER_ECC_ERR_BIT = 2
TUSER_TRUNC_ERR_BIT = 3
TUSER_VC_LSB = 8
TUSER_DT_LSB = 16
TUSER_PAYLOAD_LEN_LSB = 24


def keep_mask(valid_bytes: int, beat_bytes: int) -> int:
    if valid_bytes <= 0:
        return 0
    if valid_bytes >= beat_bytes:
        return (1 << beat_bytes) - 1
    return (1 << valid_bytes) - 1


def bytes_to_int(data: bytes) -> int:
    return int.from_bytes(data, byteorder="little", signed=False)


def build_tuser(
    vc: int,
    dt: int,
    declared_payload_len: int,
    *,
    pkt_start: int = 0,
    crc_err: int = 0,
    ecc_err: int = 0,
    trunc_err: int = 0,
) -> int:
    user = 0
    user |= (int(pkt_start) & 0x1) << TUSER_PKT_START_BIT
    user |= (int(crc_err) & 0x1) << TUSER_CRC_ERR_BIT
    user |= (int(ecc_err) & 0x1) << TUSER_ECC_ERR_BIT
    user |= (int(trunc_err) & 0x1) << TUSER_TRUNC_ERR_BIT
    user |= (vc & 0x3) << TUSER_VC_LSB
    user |= (dt & 0x3F) << TUSER_DT_LSB
    user |= (declared_payload_len & 0xFFFF) << TUSER_PAYLOAD_LEN_LSB
    return user


@dataclass(frozen=True)
class AxisPacket:
    payload: bytes
    vc: int
    dt: int
    declared_payload_len: int
    crc_err_first: int = 0
    ecc_err_first: int = 0
    trunc_err_first: int = 0
    crc_err_last: int = 0
    ecc_err_last: int = 0
    trunc_err_last: int = 0


class AxisPayloadSource:
    def __init__(self, dut):
        self.dut = dut
        self.clock = dut.video_aclk
        self.beat_bytes = len(dut.s_axis_tdata) // 8

    def drive_idle(self) -> None:
        self.dut.s_axis_tdata.value = 0
        self.dut.s_axis_tkeep.value = 0
        self.dut.s_axis_tvalid.value = 0
        self.dut.s_axis_tlast.value = 0
        self.dut.s_axis_tuser.value = 0

    async def send(self, packet: AxisPacket) -> None:
        beat_count = max(1, (len(packet.payload) + self.beat_bytes - 1) // self.beat_bytes)

        for beat_idx in range(beat_count):
            beat = packet.payload[beat_idx * self.beat_bytes : (beat_idx + 1) * self.beat_bytes]
            is_first = beat_idx == 0
            is_last = beat_idx == beat_count - 1

            self.dut.s_axis_tdata.value = bytes_to_int(beat.ljust(self.beat_bytes, b"\x00"))
            self.dut.s_axis_tkeep.value = keep_mask(len(beat), self.beat_bytes)
            self.dut.s_axis_tvalid.value = 1
            self.dut.s_axis_tlast.value = int(is_last)
            self.dut.s_axis_tuser.value = build_tuser(
                packet.vc,
                packet.dt,
                packet.declared_payload_len,
                pkt_start=int(is_first),
                crc_err=((packet.crc_err_first if is_first else 0) | (packet.crc_err_last if is_last else 0)),
                ecc_err=((packet.ecc_err_first if is_first else 0) | (packet.ecc_err_last if is_last else 0)),
                trunc_err=((packet.trunc_err_first if is_first else 0) | (packet.trunc_err_last if is_last else 0)),
            )

            while True:
                await RisingEdge(self.clock)
                if int(self.dut.s_axis_tvalid.value) and int(self.dut.s_axis_tready.value):
                    break

        self.drive_idle()
        await RisingEdge(self.clock)

    async def send_payload(
        self,
        payload: bytes,
        *,
        vc: int,
        dt: int,
        declared_payload_len: int | None = None,
        crc_err_first: int = 0,
        ecc_err_first: int = 0,
        trunc_err_first: int = 0,
        crc_err_last: int = 0,
        ecc_err_last: int = 0,
        trunc_err_last: int = 0,
    ) -> None:
        await self.send(
            AxisPacket(
                payload=payload,
                vc=vc,
                dt=dt,
                declared_payload_len=len(payload) if declared_payload_len is None else declared_payload_len,
                crc_err_first=crc_err_first,
                ecc_err_first=ecc_err_first,
                trunc_err_first=trunc_err_first,
                crc_err_last=crc_err_last,
                ecc_err_last=ecc_err_last,
                trunc_err_last=trunc_err_last,
            )
        )
