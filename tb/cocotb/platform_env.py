from __future__ import annotations

from dataclasses import dataclass

import cocotb
from cocotb.triggers import RisingEdge

from drivers.axi_host_master import AxiHostMaster
from drivers.axis_payload_source import AxisPayloadSource
from drivers.clk_rst import ClockBundle, reset_platform, start_platform_clocks
from model.axi_memory import AxiMemoryModel
from scoreboard.slot_scoreboard import SlotScoreboard
from test_csi2_awr_packets import csi2_calc_crc16, csi2_calc_ecc


FILTER_VC = 0x1
FILTER_DT = 0x2A
RING_BASE_ADDR = 0x1000
RING_SIZE_BYTES = 0x4000


@dataclass(frozen=True)
class PlatformConfig:
    vc: int = FILTER_VC
    dt: int = FILTER_DT
    drop_invalid_pkt: int = 0
    allow_overwrite: int = 0
    drop_invalid_slot: int = 0
    drop_on_no_space: int = 0
    ring_base_addr: int = RING_BASE_ADDR
    ring_size_bytes: int = RING_SIZE_BYTES


@dataclass(frozen=True)
class CommitInfo:
    seq: int
    slot_bytes: int
    valid_good: int
    overflow_err: int
    addr: int


@dataclass(frozen=True)
class RawCsi2Packet:
    raw: bytes
    vc: int
    dt: int
    is_long: bool
    short_data: int = 0
    word_count: int = 0
    payload: bytes = b""
    header_ecc: int = 0
    header_ecc_ok: bool = True
    crc16: int = 0
    crc_ok: bool = True
    trunc_err: int = 0


def parse_raw_csi2_packet(packet: bytes) -> RawCsi2Packet:
    if len(packet) < 4:
        raise ValueError(f"CSI-2 packet too short: {len(packet)} bytes")

    data_id = packet[0]
    dt = data_id & 0x3F
    vc = (data_id >> 6) & 0x3
    header_ecc = packet[3]
    header_ecc_ok = header_ecc == csi2_calc_ecc(packet[:3])

    if len(packet) == 4:
        return RawCsi2Packet(
            raw=packet,
            vc=vc,
            dt=dt,
            is_long=False,
            short_data=packet[1] | (packet[2] << 8),
            header_ecc=header_ecc,
            header_ecc_ok=header_ecc_ok,
        )

    word_count = packet[1] | (packet[2] << 8)
    payload_end = min(len(packet), 4 + word_count)
    payload = packet[4:payload_end]
    trunc_err = int(len(packet) != (4 + word_count + 2))

    crc16 = 0
    crc_ok = False
    if len(packet) >= (4 + word_count + 2):
        crc16 = int.from_bytes(packet[4 + word_count : 4 + word_count + 2], byteorder="little", signed=False)
        crc_ok = (len(payload) == word_count) and (crc16 == csi2_calc_crc16(payload))

    return RawCsi2Packet(
        raw=packet,
        vc=vc,
        dt=dt,
        is_long=True,
        word_count=word_count,
        payload=payload,
        header_ecc=header_ecc,
        header_ecc_ok=header_ecc_ok,
        crc16=crc16,
        crc_ok=crc_ok,
        trunc_err=trunc_err,
    )


class SimulationPlatformEnv:
    def __init__(self, dut, config: PlatformConfig | None = None):
        self.dut = dut
        self.config = config or PlatformConfig()
        self.clocks = ClockBundle()
        self.source = AxisPayloadSource(dut)
        self.host = AxiHostMaster(dut)
        self.memory = AxiMemoryModel(dut)
        self.scoreboard = SlotScoreboard(
            ring_base_addr=self.config.ring_base_addr,
            ring_size_bytes=self.config.ring_size_bytes,
        )

    async def start(self, *, clocks: ClockBundle | None = None) -> None:
        if clocks is not None:
            self.clocks = clocks
        start_platform_clocks(self.dut, self.clocks)
        self.source.drive_idle()
        self.dut.csi_rx_short_pkt_valid.value = 0
        self.dut.csi_rx_short_pkt_dt.value = 0
        self.dut.csi_rx_short_pkt_vc.value = 0
        self.dut.csi_rx_short_pkt_data.value = 0
        self.dut.m_axis_rd_tready.value = 1
        self.dut.rd_slot_req_i.value = 0
        self.dut.rd_consume_i.value = 0
        self.dut.sys_rst_n.value = 0
        self.dut.csi_rx_startup_latency_cycles.value = 0
        self.dut.csi_rx_interpacket_gap_cycles.value = 0
        self.dut.csi_rx_beat_gap_cycles.value = 0
        self.dut.cdc_sink_pause.value = 0
        self.dut.m_axi_awready.value = 0
        self.dut.m_axi_wready.value = 0
        self.dut.m_axi_bresp.value = 0
        self.dut.m_axi_bvalid.value = 0
        self.dut.m_axi_arready.value = 0
        self.dut.m_axi_rdata.value = 0
        self.dut.m_axi_rresp.value = 0
        self.dut.m_axi_rlast.value = 0
        self.dut.m_axi_rvalid.value = 0
        self.dut._mem_model = self.memory
        cocotb.start_soon(self.memory.run())

    async def reset(self) -> None:
        await reset_platform(self.dut)

    async def configure(self, config: PlatformConfig | None = None) -> None:
        if config is not None:
            self.config = config
            self.scoreboard = SlotScoreboard(
                ring_base_addr=self.config.ring_base_addr,
                ring_size_bytes=self.config.ring_size_bytes,
            )

        self.dut.cfg_vc_en_i.value = 1
        self.dut.cfg_dt_en_i.value = 1
        self.dut.cfg_vc_i.value = self.config.vc
        self.dut.cfg_dt_i.value = self.config.dt
        self.dut.cfg_drop_invalid_pkt_i.value = self.config.drop_invalid_pkt
        self.dut.cfg_enable_i.value = 0
        self.dut.cfg_allow_overwrite_i.value = self.config.allow_overwrite
        self.dut.cfg_drop_invalid_slot_i.value = self.config.drop_invalid_slot
        self.dut.cfg_drop_on_no_space_i.value = self.config.drop_on_no_space
        self.dut.cfg_ring_base_addr_i.value = self.config.ring_base_addr
        self.dut.cfg_ring_size_bytes_i.value = self.config.ring_size_bytes
        await RisingEdge(self.dut.axis_clk)
        await RisingEdge(self.dut.axis_clk)
        self.dut.cfg_enable_i.value = 1
        await RisingEdge(self.dut.axis_clk)
        await RisingEdge(self.dut.axis_clk)

    async def configure_csi_rx_mock(
        self,
        *,
        startup_cycles: int = 0,
        interpacket_gap_cycles: int = 0,
        beat_gap_cycles: int = 0,
    ) -> None:
        self.dut.csi_rx_startup_latency_cycles.value = startup_cycles
        self.dut.csi_rx_interpacket_gap_cycles.value = interpacket_gap_cycles
        self.dut.csi_rx_beat_gap_cycles.value = beat_gap_cycles
        await RisingEdge(self.dut.video_aclk)
        await RisingEdge(self.dut.video_aclk)

    async def set_cdc_sink_pause(self, enable: int) -> None:
        self.dut.cdc_sink_pause.value = int(enable)
        await RisingEdge(self.dut.axis_clk)

    async def inject_short_packet(
        self,
        *,
        dt: int,
        short_data: int = 0,
        vc: int | None = None,
    ) -> None:
        self.dut.csi_rx_short_pkt_dt.value = dt
        self.dut.csi_rx_short_pkt_vc.value = self.config.vc if vc is None else vc
        self.dut.csi_rx_short_pkt_data.value = short_data
        self.dut.csi_rx_short_pkt_valid.value = 1

        while True:
            await RisingEdge(self.dut.video_aclk)
            if int(self.dut.csi_rx_short_pkt_valid.value) and int(self.dut.csi_rx_short_pkt_ready.value):
                break

        self.dut.csi_rx_short_pkt_valid.value = 0
        await RisingEdge(self.dut.video_aclk)

    async def send_packet(
        self,
        payload: bytes,
        *,
        seq: int,
        vc: int | None = None,
        dt: int | None = None,
        declared_payload_len: int | None = None,
        pkt_crc_err: int = 0,
        pkt_ecc_err: int = 0,
        pkt_trunc_err: int = 0,
    ) -> None:
        self.scoreboard.push_expectation(
            payload,
            seq=seq,
            pkt_crc_err=pkt_crc_err,
            pkt_ecc_err=pkt_ecc_err,
            pkt_trunc_err=pkt_trunc_err,
        )
        await self.source.send_payload(
            payload,
            vc=self.config.vc if vc is None else vc,
            dt=self.config.dt if dt is None else dt,
            declared_payload_len=len(payload) if declared_payload_len is None else declared_payload_len,
            ecc_err_first=pkt_ecc_err,
            crc_err_last=pkt_crc_err,
            trunc_err_last=pkt_trunc_err,
        )

    async def send_raw_csi2_packet(self, raw_packet: bytes, *, seq: int) -> RawCsi2Packet:
        info = parse_raw_csi2_packet(raw_packet)
        if info.is_long:
            await self.send_packet(
                info.payload,
                seq=seq,
                vc=info.vc,
                dt=info.dt,
                declared_payload_len=info.word_count,
                pkt_crc_err=int(not info.crc_ok),
                pkt_ecc_err=int(not info.header_ecc_ok),
                pkt_trunc_err=info.trunc_err,
            )
        else:
            if info.header_ecc_ok:
                await self.inject_short_packet(dt=info.dt, short_data=info.short_data, vc=info.vc)
            else:
                await RisingEdge(self.dut.video_aclk)
        return info

    async def wait_for_commit(self, timeout_cycles: int = 1500) -> CommitInfo:
        for _ in range(timeout_cycles):
            await RisingEdge(self.dut.axis_clk)
            if int(self.dut.wr_slot_commit_o.value):
                commit = CommitInfo(
                    seq=int(self.dut.wr_slot_seq_o.value),
                    slot_bytes=int(self.dut.wr_slot_bytes_o.value),
                    valid_good=int(self.dut.wr_slot_valid_good_o.value),
                    overflow_err=int(self.dut.wr_slot_overflow_err_o.value),
                    addr=int(self.dut.wr_slot_addr_o.value),
                )
                self.scoreboard.check_commit(**commit.__dict__)
                return commit

        raise TimeoutError(
            "Timed out waiting for wr_slot_commit_o "
            f"(dbg_wr_state={int(self.dut.dbg_wr_state_o.value)} used_bytes={int(self.dut.used_bytes_o.value)})"
        )

    async def expect_no_commit(self, cycles: int = 200) -> None:
        for _ in range(cycles):
            await RisingEdge(self.dut.axis_clk)
            if int(self.dut.wr_slot_commit_o.value):
                raise AssertionError("Unexpected wr_slot_commit_o")

    async def verify_memory_for_last_commit(self) -> None:
        if not self.scoreboard.pending_reads:
            raise AssertionError("No committed slot available for memory verification")
        self.scoreboard.check_memory(self.memory, self.scoreboard.pending_reads[-1])

    async def readback_next_slot(self, timeout_cycles: int = 1500):
        readback = await self.host.read_and_consume(timeout_cycles=timeout_cycles)
        self.scoreboard.check_readback(readback)
        return readback

    async def wait_for_cdc_idle(self, timeout_cycles: int = 512) -> None:
        for _ in range(timeout_cycles):
            await RisingEdge(self.dut.axis_clk)
            if (
                int(self.dut.cdc_fifo_level.value) == 0
                and int(self.dut.cdc_axis_tvalid.value) == 0
                and int(self.dut.csi_rx_axis_tvalid.value) == 0
                and int(self.dut.csi_rx_gap_active.value) == 0
                and int(self.dut.csi_rx_short_pkt_valid.value) == 0
            ):
                return
        raise TimeoutError("Timed out waiting for CDC FIFO to drain")
