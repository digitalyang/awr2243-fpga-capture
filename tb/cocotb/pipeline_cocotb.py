from __future__ import annotations

import struct
from dataclasses import dataclass
from typing import Dict, List

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles, FallingEdge, RisingEdge

from test_csi2_awr_packets import (
    DT_AWR_RAW as CSI2_DT_AWR_RAW,
    DT_FE as CSI2_DT_FE,
    DT_FS as CSI2_DT_FS,
    DT_LE as CSI2_DT_LE,
    DT_LS as CSI2_DT_LS,
    build_awr_frame_packets,
    csi2_calc_crc16 as csi2_packet_crc16,
    csi2_calc_ecc as csi2_packet_ecc,
)


AXIS_DATA_W = 256
AXIS_USER_W = 64
AXIS_BEAT_BYTES = AXIS_DATA_W // 8
AXI_DATA_W = 256
AXI_BEAT_BYTES = AXI_DATA_W // 8

VC_W = 2
DT_W = 6
PAYLOAD_LEN_W = 16

TUSER_PKT_START_BIT = 0
TUSER_CRC_ERR_BIT = 1
TUSER_ECC_ERR_BIT = 2
TUSER_TRUNC_ERR_BIT = 3
TUSER_VC_LSB = 8
TUSER_DT_LSB = 16
TUSER_PAYLOAD_LEN_LSB = 24

RD_TUSER_FIRST_BIT = 0
RD_TUSER_LAST_BIT = 1
RD_TUSER_VALID_BIT = 2
RD_TUSER_OVF_BIT = 3
RD_TUSER_SEQ_LSB = 8
RD_TUSER_BYTES_LSB = 32

SAMPLE_SLOT_NUM = 1024
SAMPLE_UNIT_BYTES = 4
SAMPLE_AREA_BYTES = SAMPLE_SLOT_NUM * SAMPLE_UNIT_BYTES
CQ_AREA_BYTES = 128
HEADER_BYTES = 64
ALIGN_BYTES = 64
SLOT_TOTAL_UNALIGNED = HEADER_BYTES + SAMPLE_AREA_BYTES + CQ_AREA_BYTES
SLOT_TOTAL_ALIGNED = ((SLOT_TOTAL_UNALIGNED + ALIGN_BYTES - 1) // ALIGN_BYTES) * ALIGN_BYTES

HDR_MAGIC_OFS = 0
HDR_VERSION_OFS = 4
HDR_FLAGS_OFS = 5
HDR_PKT_SEQ_OFS = 8
HDR_PKT_BYTES_OFS = 10
HDR_SAMPLE_CNT_OFS = 12
HDR_SLOT_BYTES_OFS = 16
HDR_SAMPLE_AREA_OFS = 20
HDR_CQ_AREA_OFS = 24

FLAG_CRC_ERR_BIT = 0
FLAG_ECC_ERR_BIT = 1
FLAG_TRUNC_ERR_BIT = 2
FLAG_VALID_GOOD_BIT = 3
FLAG_OVERFLOW_BIT = 4

SLOT_MAGIC = 0xAA551024
SLOT_VERSION = 0x01

RING_BASE_ADDR = 0x1000
RING_SIZE_BYTES = 0x4000
FILTER_VC = 0x1
FILTER_DT = 0x2A


def signal_width(sig) -> int:
    return len(sig)


def int_to_bytes(value: int, byte_count: int) -> bytes:
    return int(value).to_bytes(byte_count, byteorder="little", signed=False)


def bytes_to_int(data: bytes) -> int:
    return int.from_bytes(data, byteorder="little", signed=False)


def keep_mask(valid_bytes: int, beat_bytes: int) -> int:
    if valid_bytes <= 0:
        return 0
    if valid_bytes >= beat_bytes:
        return (1 << beat_bytes) - 1
    return (1 << valid_bytes) - 1


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
    user |= (vc & ((1 << VC_W) - 1)) << TUSER_VC_LSB
    user |= (dt & ((1 << DT_W) - 1)) << TUSER_DT_LSB
    user |= (declared_payload_len & ((1 << PAYLOAD_LEN_W) - 1)) << TUSER_PAYLOAD_LEN_LSB
    return user


def gen_payload(length: int, seed: int = 0) -> bytes:
    return bytes(((seed + idx * 17 + length) & 0xFF) for idx in range(length))


@dataclass
class PacketSpec:
    vc: int
    dt: int
    payload: bytes
    declared_payload_len: int
    crc_err_first: int = 0
    ecc_err_first: int = 0
    trunc_err_first: int = 0
    crc_err_last: int = 0
    ecc_err_last: int = 0
    trunc_err_last: int = 0


@dataclass
class SlotResult:
    seq: int
    slot_bytes: int
    valid_good: int
    overflow_err: int
    addr: int = 0
    payload: bytes = b""


@dataclass
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


class AxiMemoryModel:
    def __init__(self, dut):
        self.dut = dut
        self.mem: Dict[int, int] = {}
        self._wr_active = False
        self._rd_active = False
        self._wr_addr = 0
        self._rd_addr = 0
        self._wr_beats_rem = 0
        self._rd_beats_rem = 0
        self._wr_step_bytes = AXI_BEAT_BYTES
        self._rd_step_bytes = AXI_BEAT_BYTES
        self._bvalid = 0
        self._bresp = 0
        self._rvalid = 0
        self._rdata = 0
        self._rresp = 0
        self._rlast = 0

    def reset_bus(self) -> None:
        self._wr_active = False
        self._rd_active = False
        self._wr_beats_rem = 0
        self._rd_beats_rem = 0
        self._wr_addr = 0
        self._rd_addr = 0
        self._bvalid = 0
        self._bresp = 0
        self._rvalid = 0
        self._rdata = 0
        self._rresp = 0
        self._rlast = 0

    def drive_outputs(self) -> None:
        awready = int((not self._wr_active) and (not self._bvalid))
        wready = int(self._wr_active)
        arready = int((not self._rd_active) and (not self._rvalid))

        self.dut.m_axi_awready.value = awready
        self.dut.m_axi_wready.value = wready
        self.dut.m_axi_bresp.value = self._bresp
        self.dut.m_axi_bvalid.value = self._bvalid
        self.dut.m_axi_arready.value = arready
        self.dut.m_axi_rdata.value = self._rdata
        self.dut.m_axi_rresp.value = self._rresp
        self.dut.m_axi_rlast.value = self._rlast
        self.dut.m_axi_rvalid.value = self._rvalid

    def write_mem_word(self, addr: int, data: int, strb: int) -> None:
        raw = int_to_bytes(data, AXI_BEAT_BYTES)
        for lane in range(AXI_BEAT_BYTES):
            if (strb >> lane) & 0x1:
                self.mem[addr + lane] = raw[lane]

    def read_mem_word(self, addr: int) -> int:
        raw = bytes(self.mem.get(addr + lane, 0) for lane in range(AXI_BEAT_BYTES))
        return bytes_to_int(raw)

    def read_ring_bytes(self, ring_base: int, ring_size: int, start_addr: int, byte_count: int) -> bytes:
        data: List[int] = []
        addr = start_addr
        ring_end = ring_base + ring_size
        for _ in range(byte_count):
            if addr >= ring_end:
                addr = ring_base
            data.append(self.mem.get(addr, 0))
            addr += 1
        return bytes(data)

    async def run(self) -> None:
        self.reset_bus()
        while True:
            await FallingEdge(self.dut.clk_i)
            if int(self.dut.rst_ni.value) == 0:
                self.reset_bus()
            self.drive_outputs()

            await RisingEdge(self.dut.clk_i)
            if int(self.dut.rst_ni.value) == 0:
                self.reset_bus()
                continue

            awready = int((not self._wr_active) and (not self._bvalid))
            wready = int(self._wr_active)
            arready = int((not self._rd_active) and (not self._rvalid))

            if self._bvalid and int(self.dut.m_axi_bready.value):
                self._bvalid = 0

            if int(self.dut.m_axi_awvalid.value) and awready:
                self._wr_active = True
                self._wr_addr = int(self.dut.m_axi_awaddr.value)
                self._wr_beats_rem = int(self.dut.m_axi_awlen.value) + 1
                self._wr_step_bytes = 1 << int(self.dut.m_axi_awsize.value)

            if int(self.dut.m_axi_wvalid.value) and wready:
                self.write_mem_word(
                    self._wr_addr,
                    int(self.dut.m_axi_wdata.value),
                    int(self.dut.m_axi_wstrb.value),
                )
                self._wr_addr += self._wr_step_bytes
                if self._wr_beats_rem > 0:
                    self._wr_beats_rem -= 1
                if int(self.dut.m_axi_wlast.value) or self._wr_beats_rem == 0:
                    self._wr_active = False
                    self._bresp = 0
                    self._bvalid = 1

            if self._rvalid and int(self.dut.m_axi_rready.value):
                self._rvalid = 0
                self._rlast = 0

            if int(self.dut.m_axi_arvalid.value) and arready:
                self._rd_active = True
                self._rd_addr = int(self.dut.m_axi_araddr.value)
                self._rd_beats_rem = int(self.dut.m_axi_arlen.value) + 1
                self._rd_step_bytes = 1 << int(self.dut.m_axi_arsize.value)

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


async def apply_reset(dut) -> None:
    cocotb.start_soon(Clock(dut.clk_i, 10, unit="ns").start())

    dut.rst_ni.value = 0
    dut.cfg_vc_en_i.value = 0
    dut.cfg_dt_en_i.value = 0
    dut.cfg_vc_i.value = 0
    dut.cfg_dt_i.value = 0
    dut.cfg_drop_invalid_pkt_i.value = 0
    dut.cfg_enable_i.value = 0
    dut.cfg_allow_overwrite_i.value = 0
    dut.cfg_drop_invalid_slot_i.value = 0
    dut.cfg_drop_on_no_space_i.value = 0
    dut.cfg_ring_base_addr_i.value = 0
    dut.cfg_ring_size_bytes_i.value = 0
    dut.rd_slot_req_i.value = 0
    dut.rd_consume_i.value = 0

    dut.s_axis_tdata.value = 0
    dut.s_axis_tkeep.value = 0
    dut.s_axis_tvalid.value = 0
    dut.s_axis_tlast.value = 0
    dut.s_axis_tuser.value = 0

    dut.m_axis_rd_tready.value = 1

    dut.m_axi_awready.value = 0
    dut.m_axi_wready.value = 0
    dut.m_axi_bresp.value = 0
    dut.m_axi_bvalid.value = 0
    dut.m_axi_arready.value = 0
    dut.m_axi_rdata.value = 0
    dut.m_axi_rresp.value = 0
    dut.m_axi_rlast.value = 0
    dut.m_axi_rvalid.value = 0

    await ClockCycles(dut.clk_i, 8)
    dut.rst_ni.value = 1
    await ClockCycles(dut.clk_i, 2)


async def configure_pipeline(
    dut,
    *,
    vc: int = FILTER_VC,
    dt: int = FILTER_DT,
    drop_invalid_pkt: int = 0,
    allow_overwrite: int = 0,
    drop_invalid_slot: int = 0,
    drop_on_no_space: int = 0,
    ring_base_addr: int = RING_BASE_ADDR,
    ring_size_bytes: int = RING_SIZE_BYTES,
) -> None:
    dut.cfg_vc_en_i.value = 1
    dut.cfg_dt_en_i.value = 1
    dut.cfg_vc_i.value = vc
    dut.cfg_dt_i.value = dt
    dut.cfg_drop_invalid_pkt_i.value = drop_invalid_pkt

    dut.cfg_enable_i.value = 0
    dut.cfg_allow_overwrite_i.value = allow_overwrite
    dut.cfg_drop_invalid_slot_i.value = drop_invalid_slot
    dut.cfg_drop_on_no_space_i.value = drop_on_no_space
    dut.cfg_ring_base_addr_i.value = ring_base_addr
    dut.cfg_ring_size_bytes_i.value = ring_size_bytes
    await ClockCycles(dut.clk_i, 2)
    dut.cfg_enable_i.value = 1
    await ClockCycles(dut.clk_i, 2)


async def drive_packet(dut, pkt: PacketSpec) -> None:
    beat_count = max(1, (len(pkt.payload) + AXIS_BEAT_BYTES - 1) // AXIS_BEAT_BYTES)

    for beat_idx in range(beat_count):
        beat = pkt.payload[beat_idx * AXIS_BEAT_BYTES : (beat_idx + 1) * AXIS_BEAT_BYTES]
        is_first = beat_idx == 0
        is_last = beat_idx == beat_count - 1

        dut.s_axis_tdata.value = bytes_to_int(beat.ljust(AXIS_BEAT_BYTES, b"\x00"))
        dut.s_axis_tkeep.value = keep_mask(len(beat), AXIS_BEAT_BYTES)
        dut.s_axis_tvalid.value = 1
        dut.s_axis_tlast.value = int(is_last)
        dut.s_axis_tuser.value = build_tuser(
            pkt.vc,
            pkt.dt,
            pkt.declared_payload_len,
            pkt_start=int(is_first),
            crc_err=((pkt.crc_err_first if is_first else 0) | (pkt.crc_err_last if is_last else 0)),
            ecc_err=((pkt.ecc_err_first if is_first else 0) | (pkt.ecc_err_last if is_last else 0)),
            trunc_err=((pkt.trunc_err_first if is_first else 0) | (pkt.trunc_err_last if is_last else 0)),
        )

        while True:
            await RisingEdge(dut.clk_i)
            if int(dut.s_axis_tvalid.value) and int(dut.s_axis_tready.value):
                break

    dut.s_axis_tdata.value = 0
    dut.s_axis_tkeep.value = 0
    dut.s_axis_tvalid.value = 0
    dut.s_axis_tlast.value = 0
    dut.s_axis_tuser.value = 0
    await RisingEdge(dut.clk_i)


async def expect_no_commit(dut, cycles: int = 200) -> None:
    for _ in range(cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.wr_slot_commit_o.value):
            raise AssertionError("Unexpected wr_slot_commit_o while no slot should be committed")


async def wait_commit(dut, timeout_cycles: int = 1500) -> SlotResult:
    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.wr_slot_commit_o.value):
            return SlotResult(
                seq=int(dut.wr_slot_seq_o.value),
                slot_bytes=int(dut.wr_slot_bytes_o.value),
                valid_good=int(dut.wr_slot_valid_good_o.value),
                overflow_err=int(dut.wr_slot_overflow_err_o.value),
                addr=int(dut.wr_slot_addr_o.value),
            )

    raise TimeoutError(
        "Timed out waiting for wr_slot_commit_o "
        f"(dbg_wr_state={int(dut.dbg_wr_state_o.value)} used_bytes={int(dut.used_bytes_o.value)} "
        f"drop_count={int(dut.drop_count_o.value)} err_slot_proto={int(dut.err_slot_proto_o.value)} "
        f"err_slot_too_large={int(dut.err_slot_too_large_o.value)} err_no_space={int(dut.err_no_space_o.value)})"
    )


async def request_read(dut) -> None:
    while int(dut.rd_slot_valid_o.value) == 0:
        await RisingEdge(dut.clk_i)

    dut.rd_slot_req_i.value = 1
    await RisingEdge(dut.clk_i)
    dut.rd_slot_req_i.value = 0


async def collect_read_slot(dut, timeout_cycles: int = 1500) -> SlotResult:
    payload = bytearray()
    meta = None

    for _ in range(timeout_cycles):
        await RisingEdge(dut.clk_i)
        if int(dut.m_axis_rd_tvalid.value) and int(dut.m_axis_rd_tready.value):
            if meta is None:
                tuser = int(dut.m_axis_rd_tuser.value)
                meta = SlotResult(
                    seq=(tuser >> RD_TUSER_SEQ_LSB) & ((1 << signal_width(dut.rd_slot_seq_o)) - 1),
                    slot_bytes=(tuser >> RD_TUSER_BYTES_LSB) & ((1 << signal_width(dut.rd_slot_bytes_o)) - 1),
                    valid_good=(tuser >> RD_TUSER_VALID_BIT) & 0x1,
                    overflow_err=(tuser >> RD_TUSER_OVF_BIT) & 0x1,
                )
                assert ((tuser >> RD_TUSER_FIRST_BIT) & 0x1) == 1, "Missing slot_first marker"

            beat_data = int_to_bytes(int(dut.m_axis_rd_tdata.value), AXI_BEAT_BYTES)
            beat_keep = int(dut.m_axis_rd_tkeep.value)
            for lane in range(AXI_BEAT_BYTES):
                if (beat_keep >> lane) & 0x1:
                    payload.append(beat_data[lane])

            if int(dut.m_axis_rd_tlast.value):
                assert meta is not None
                meta.payload = bytes(payload)
                return meta

    raise TimeoutError("Timed out collecting slot from m_axis_rd")


async def consume_slot(dut) -> None:
    dut.rd_consume_i.value = 1
    await RisingEdge(dut.clk_i)
    dut.rd_consume_i.value = 0
    await RisingEdge(dut.clk_i)


def verify_slot_layout(
    slot_data: bytes,
    *,
    payload: bytes,
    pkt_seq: int,
    pkt_crc_err: int,
    pkt_ecc_err: int,
    pkt_trunc_err: int,
) -> None:
    valid_good = int(not (pkt_crc_err or pkt_ecc_err or pkt_trunc_err))
    overflow = int(len(payload) > SAMPLE_AREA_BYTES)
    eff_bytes = min(len(payload), SAMPLE_AREA_BYTES)
    exp_sample_cnt = eff_bytes // SAMPLE_UNIT_BYTES

    assert len(slot_data) == SLOT_TOTAL_ALIGNED, (
        f"Slot size mismatch: exp={SLOT_TOTAL_ALIGNED} act={len(slot_data)}"
    )

    act_magic = struct.unpack_from("<I", slot_data, HDR_MAGIC_OFS)[0]
    assert act_magic == SLOT_MAGIC, f"Header magic mismatch: 0x{act_magic:08x}"

    act_ver = slot_data[HDR_VERSION_OFS]
    assert act_ver == SLOT_VERSION, f"Header version mismatch: exp={SLOT_VERSION} act={act_ver}"

    act_flags = slot_data[HDR_FLAGS_OFS]
    assert ((act_flags >> FLAG_CRC_ERR_BIT) & 1) == pkt_crc_err, "crc_err flag mismatch"
    assert ((act_flags >> FLAG_ECC_ERR_BIT) & 1) == pkt_ecc_err, "ecc_err flag mismatch"
    assert ((act_flags >> FLAG_TRUNC_ERR_BIT) & 1) == pkt_trunc_err, "trunc_err flag mismatch"
    assert ((act_flags >> FLAG_VALID_GOOD_BIT) & 1) == valid_good, "valid_good flag mismatch"
    assert ((act_flags >> FLAG_OVERFLOW_BIT) & 1) == overflow, "overflow flag mismatch"

    act_seq = struct.unpack_from("<H", slot_data, HDR_PKT_SEQ_OFS)[0]
    assert act_seq == (pkt_seq & 0xFFFF), f"pkt_seq mismatch: exp={pkt_seq & 0xFFFF} act={act_seq}"

    act_pkt_bytes = struct.unpack_from("<H", slot_data, HDR_PKT_BYTES_OFS)[0]
    assert act_pkt_bytes == (len(payload) & 0xFFFF), (
        f"pkt_bytes mismatch: exp={len(payload) & 0xFFFF} act={act_pkt_bytes}"
    )

    act_sample_cnt = struct.unpack_from("<H", slot_data, HDR_SAMPLE_CNT_OFS)[0]
    assert act_sample_cnt == exp_sample_cnt, (
        f"sample_cnt mismatch: exp={exp_sample_cnt} act={act_sample_cnt}"
    )

    act_slot_bytes = struct.unpack_from("<I", slot_data, HDR_SLOT_BYTES_OFS)[0]
    assert act_slot_bytes == SLOT_TOTAL_ALIGNED, (
        f"slot_bytes mismatch: exp={SLOT_TOTAL_ALIGNED} act={act_slot_bytes}"
    )

    act_sample_area = struct.unpack_from("<I", slot_data, HDR_SAMPLE_AREA_OFS)[0]
    assert act_sample_area == SAMPLE_AREA_BYTES, (
        f"sample_area mismatch: exp={SAMPLE_AREA_BYTES} act={act_sample_area}"
    )

    act_cq_area = struct.unpack_from("<H", slot_data, HDR_CQ_AREA_OFS)[0]
    assert act_cq_area == CQ_AREA_BYTES, f"cq_area mismatch: exp={CQ_AREA_BYTES} act={act_cq_area}"

    sample_ofs = HEADER_BYTES
    for idx in range(eff_bytes):
        assert slot_data[sample_ofs + idx] == payload[idx], (
            f"Payload mismatch at byte {idx}: exp=0x{payload[idx]:02x} act=0x{slot_data[sample_ofs + idx]:02x}"
        )

    for idx in range(eff_bytes, SAMPLE_AREA_BYTES):
        assert slot_data[sample_ofs + idx] == 0, (
            f"Sample zero pad mismatch at offset {sample_ofs + idx}: act=0x{slot_data[sample_ofs + idx]:02x}"
        )

    cq_ofs = HEADER_BYTES + SAMPLE_AREA_BYTES
    for idx in range(CQ_AREA_BYTES):
        assert slot_data[cq_ofs + idx] == 0, (
            f"CQ zero pad mismatch at offset {cq_ofs + idx}: act=0x{slot_data[cq_ofs + idx]:02x}"
        )


@cocotb.test()
async def pipeline_smoke_basic(dut):
    mem_model = AxiMemoryModel(dut)
    cocotb.start_soon(mem_model.run())

    await apply_reset(dut)
    await configure_pipeline(dut, drop_invalid_pkt=0, drop_invalid_slot=1)

    dropped_pkt = PacketSpec(
        vc=FILTER_VC ^ 0x1,
        dt=FILTER_DT,
        payload=gen_payload(53, seed=0x11),
        declared_payload_len=53,
    )
    await drive_packet(dut, dropped_pkt)
    await expect_no_commit(dut, cycles=120)
    assert int(dut.used_bytes_o.value) == 0, "Filtered packet should not allocate ring space"

    good_pkt = PacketSpec(
        vc=FILTER_VC,
        dt=FILTER_DT,
        payload=gen_payload(77, seed=0x40),
        declared_payload_len=77,
    )
    await drive_packet(dut, good_pkt)

    commit = await wait_commit(dut)
    assert commit.seq == 0, f"Unexpected committed seq: {commit.seq}"
    assert commit.slot_bytes == SLOT_TOTAL_ALIGNED, (
        f"Committed slot_bytes mismatch: exp={SLOT_TOTAL_ALIGNED} act={commit.slot_bytes}"
    )
    assert commit.valid_good == 1, "Valid packet should commit as valid_good"
    assert commit.overflow_err == 0, "Unexpected overflow on short payload"

    stored = mem_model.read_ring_bytes(
        ring_base=int(dut.cfg_ring_base_addr_i.value),
        ring_size=int(dut.cfg_ring_size_bytes_i.value),
        start_addr=commit.addr,
        byte_count=commit.slot_bytes,
    )
    verify_slot_layout(
        stored,
        payload=good_pkt.payload,
        pkt_seq=0,
        pkt_crc_err=0,
        pkt_ecc_err=0,
        pkt_trunc_err=0,
    )

    await request_read(dut)
    readback = await collect_read_slot(dut)
    assert readback.seq == 0
    assert readback.slot_bytes == SLOT_TOTAL_ALIGNED
    assert readback.valid_good == 1
    assert readback.overflow_err == 0
    assert readback.payload == stored, "Readback slot bytes mismatch"
    await consume_slot(dut)

    assert int(dut.err_axi_wr_resp_o.value) == 0
    assert int(dut.err_axi_rd_resp_o.value) == 0
    assert int(dut.err_illegal_read_o.value) == 0


@cocotb.test()
async def pipeline_invalid_slot_roundtrip(dut):
    mem_model = AxiMemoryModel(dut)
    cocotb.start_soon(mem_model.run())

    await apply_reset(dut)
    await configure_pipeline(dut, drop_invalid_pkt=0, drop_invalid_slot=0)

    bad_pkt = PacketSpec(
        vc=FILTER_VC,
        dt=FILTER_DT,
        payload=gen_payload(93, seed=0x70),
        declared_payload_len=100,
        crc_err_last=1,
    )
    await drive_packet(dut, bad_pkt)

    commit = await wait_commit(dut)
    assert commit.seq == 0
    assert commit.slot_bytes == SLOT_TOTAL_ALIGNED
    assert commit.valid_good == 0, "Invalid packet must propagate valid_good=0"
    assert commit.overflow_err == 0

    stored = mem_model.read_ring_bytes(
        ring_base=int(dut.cfg_ring_base_addr_i.value),
        ring_size=int(dut.cfg_ring_size_bytes_i.value),
        start_addr=commit.addr,
        byte_count=commit.slot_bytes,
    )
    verify_slot_layout(
        stored,
        payload=bad_pkt.payload,
        pkt_seq=0,
        pkt_crc_err=1,
        pkt_ecc_err=0,
        pkt_trunc_err=1,
    )

    await request_read(dut)
    readback = await collect_read_slot(dut)
    assert readback.seq == 0
    assert readback.slot_bytes == SLOT_TOTAL_ALIGNED
    assert readback.valid_good == 0
    assert readback.overflow_err == 0
    assert readback.payload == stored
    await consume_slot(dut)


@cocotb.test()
async def pipeline_controller_drops_invalid(dut):
    mem_model = AxiMemoryModel(dut)
    cocotb.start_soon(mem_model.run())

    await apply_reset(dut)
    await configure_pipeline(dut, drop_invalid_pkt=0, drop_invalid_slot=1)

    bad_pkt = PacketSpec(
        vc=FILTER_VC,
        dt=FILTER_DT,
        payload=gen_payload(65, seed=0x22),
        declared_payload_len=70,
        trunc_err_last=1,
    )
    await drive_packet(dut, bad_pkt)

    await expect_no_commit(dut, cycles=200)
    assert int(dut.drop_count_o.value) == 1, "Controller should count one dropped slot"
    assert int(dut.used_bytes_o.value) == 0, "Dropped invalid slot must not consume ring space"
    assert int(dut.rd_slot_valid_o.value) == 0, "Dropped invalid slot must not become readable"
