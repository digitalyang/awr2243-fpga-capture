# 模块清单与接口定义

## 1. 模块清单

### 1.1 仿真专用组件（非 DUT）

| 模块名 | 类型 | 来源 | 角色 | 说明 |
|--------|------|------|------|------|
| **AXIS payload source** | Behavioral mock | cocotbext-axi `AxiStreamSource` | 激励生成 | 生成 AWR2243 radar raw payload，模拟 CSI-2 数据流 |
| **AXIS monitor** | Behavioral mock | cocotbext-axi `AxiStreamMonitor` | 监控 | 监控 Extractor/Packer 输出，用于 scoreboard |
| **AXI host master** | Behavioral mock | cocotbext-axi `AxiMaster` | 激励生成 | 模拟 XDMA host 对 DDR 的 AXI burst read |
| **Clock/Reset generator** | Behavioral mock | cocotb `Clock` / custom | 时钟/复位 | 驱动 video_aclk (200MHz), axis_clk/axi_clk (250MHz) 及复位 |

### 1.2 RTL DUT 模块

| 模块名 | 类型 | 文件位置 | 角色 | 说明 |
|--------|------|----------|------|------|
| **CSI Packet Extractor** | 真实 RTL | `rtl/core/csi_packet_extractor.sv` | DUT | 过滤 CSI-2 long packet，按 VC/DT 过滤，提取 payload，输出侧带信号 |
| **Fixed Slot Packer** | 真实 RTL | `rtl/core/fixed_slot_packer.sv` | DUT | 将 payload 封装为固定长度 slot（12352B：12B header + 12288B sample + 9B CQ + padding） |
| **DDR RingBuffer Controller** | 真实 RTL | `rtl/core/ddr_ringbuffer_controller.sv` | DUT | 管理 ring buffer，AXI 写 DDR，维护描述符 FIFO，支持 Host 读路径 |

### 1.3 开源模型组件

| 模块名 | 类型 | 来源 | 角色 | 说明 |
|--------|------|------|------|------|
| **AXIS Async FIFO** | 开源模型 | verilog-axis `axis_async_fifo` | CDC | 处理 200MHz → 250MHz 跨时钟域，双时钟 FIFO |
| **AXI SmartConnect** | 开源模型 | verilog-axi `axi_crossbar` | Interconnect | 2 master → 1 slave 仲裁（RingBuffer write + Host read） |
| **DDR Model** | 开源模型 | LiteDRAM 或 cocotbext-axi `AxiMemory` | Memory model | AXI slave memory，模拟 DDR4 |

### 1.4 Vivado IP（可选）

| IP 名 | 类型 | Vivado Catalog 路径 | 角色 | 说明 |
|-------|------|-------------------|------|------|
| **MIPI CSI-2 RX Subsystem** | Vivado IP | IP Catalog → Video & Image Processing → MIPI CSI-2 RX Subsystem | CSI-2 接收 | 若使用，需导出 RTL 与约束；否则用 behavioral mock |
| **AXI SmartConnect** | Vivado IP | IP Catalog → AXI Infrastructure → AXI SmartConnect | Interconnect | 替代 verilog-axi `axi_crossbar` |
| **AXIS Data FIFO** | Vivado IP | IP Catalog → AXI Infrastructure → AXI4-Stream Data FIFO | FIFO | 替代 verilog-axis `axis_fifo`（若需要同步 FIFO） |

## 2. 接口定义

### 2.1 AXIS payload source（cocotb）

**接口类型**：AXI4-Stream Master（cocotbext-axi `AxiStreamSource`）

**信号**（Python API，绑定到 testbench 信号）：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `tdata` | Output | 32 或 64 | Payload 数据 |
| `tvalid` | Output | 1 | 数据有效 |
| `tready` | Input | 1 | 下游 ready |
| `tlast` | Output | 1 | Packet 结束 |
| `tkeep` | Output | 4 或 8 | Byte valid |
| `tuser` | Output | 可变 | Packet 元数据（VC, DT, payload_len, errors） |

**cocotb 使用示例**：

```python
from cocotbext.axi import AxiStreamSource

axis_source = AxiStreamSource(dut.s_axis_csi, dut.video_aclk, dut.video_rst_n)
await axis_source.write(data_bytes, tuser=user_value)
```

### 2.2 CSI Packet Extractor

**接口类型**：AXI4-Stream Slave + Master，带侧带信号

**时钟域**：`axis_clk` (250MHz)

**AXIS Slave**（`axis_stream_if.slave s_axis`）：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `s_axis_tdata` | Input | `AXIS_DATA_W` (默认 32) | CSI packet payload |
| `s_axis_tvalid` | Input | 1 | 数据有效 |
| `s_axis_tready` | Output | 1 | Ready |
| `s_axis_tlast` | Input | 1 | Packet 结束 |
| `s_axis_tkeep` | Input | `AXIS_DATA_W/8` | Byte valid |
| `s_axis_tuser` | Input | `AXIS_USER_W` | VC, DT, payload_len, CRC/ECC/trunc errors |

**AXIS Master**（`axis_stream_if.master m_axis`）：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `m_axis_tdata` | Output | `AXIS_DATA_W` | 过滤后的 payload |
| `m_axis_tvalid` | Output | 1 | 数据有效 |
| `m_axis_tready` | Input | 1 | 下游 ready |
| `m_axis_tlast` | Output | 1 | Packet 结束 |
| `m_axis_tkeep` | Output | `AXIS_DATA_W/8` | Byte valid |
| `m_axis_tuser` | Output | `AXIS_USER_W` | 保留或清空 |

**侧带信号**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `pkt_start_o` | Output | 1 | Packet 开始 |
| `pkt_done_o` | Output | 1 | Packet 完成 |
| `pkt_valid_good_o` | Output | 1 | Packet 有效且无错误 |
| `pkt_seq_o` | Output | `PKT_SEQ_W` | Packet 序号 |
| `pkt_bytes_o` | Output | `PKT_BYTE_CNT_W` | Packet 字节数 |
| `pkt_crc_err_o` | Output | 1 | CRC 错误 |
| `pkt_ecc_err_o` | Output | 1 | ECC 错误 |
| `pkt_trunc_err_o` | Output | 1 | 截断错误 |

**配置信号**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `cfg_vc_en_i` | Input | 1 | VC 过滤使能 |
| `cfg_dt_en_i` | Input | 1 | DT 过滤使能 |
| `cfg_vc_i` | Input | `VC_W` (2) | 目标 VC |
| `cfg_dt_i` | Input | `DT_W` (6) | 目标 DT |

### 2.3 Fixed Slot Packer

**接口类型**：AXI4-Stream Slave + Master，带侧带信号

**时钟域**：`axis_clk` (250MHz)

**AXIS Slave**（`axis_stream_if.slave s_axis`）：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `s_axis_tdata` | Input | `AXIS_DATA_W` (默认 32) | 上游 payload |
| `s_axis_tvalid` | Input | 1 | 数据有效 |
| `s_axis_tready` | Output | 1 | Ready |
| `s_axis_tlast` | Input | 1 | Packet 结束 |
| `s_axis_tkeep` | Input | `AXIS_DATA_W/8` | Byte valid |
| `s_axis_tuser` | Input | `AXIS_USER_W` | 保留 |

**AXIS Master**（`axis_stream_if.master m_axis`）：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `m_axis_tdata` | Output | `AXIS_DATA_W` | Slot 数据（固定 12352B） |
| `m_axis_tvalid` | Output | 1 | 数据有效 |
| `m_axis_tready` | Input | 1 | 下游 ready |
| `m_axis_tlast` | Output | 1 | Slot 结束 |
| `m_axis_tkeep` | Output | `AXIS_DATA_W/8` | Byte valid |
| `m_axis_tuser` | Output | `AXIS_USER_W` | 保留 |

**上游侧带输入**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `pkt_start_i` | Input | 1 | Packet 开始 |
| `pkt_done_i` | Input | 1 | Packet 完成 |
| `pkt_bytes_i` | Input | `PKT_BYTE_CNT_W` | Packet 字节数 |
| `pkt_seq_i` | Input | `PKT_SEQ_W` | Packet 序号 |
| `pkt_crc_err_i` | Input | 1 | CRC 错误 |
| `pkt_ecc_err_i` | Input | 1 | ECC 错误 |
| `pkt_trunc_err_i` | Input | 1 | 截断错误 |
| `pkt_valid_good_i` | Input | 1 | Packet 有效且无错误 |

**下游侧带输出**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `slot_start_o` | Output | 1 | Slot 开始 |
| `slot_done_o` | Output | 1 | Slot 完成 |
| `slot_bytes_o` | Output | `SLOT_BYTES_W` | Slot 字节数（固定 12352） |
| `slot_seq_o` | Output | `PKT_SEQ_W` | Slot 序号（继承自 packet） |
| `slot_valid_good_o` | Output | 1 | Slot 有效且无错误 |
| `slot_overflow_err_o` | Output | 1 | Slot 溢出错误（payload > 1024 sample） |

**配置信号**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `cfg_drop_invalid_pkt_i` | Input | 1 | 丢弃无效 packet |

### 2.4 DDR RingBuffer Controller

**接口类型**：AXI4-Stream Slave（写） + Master（读），AXI4 Master（写 DDR），控制信号

**时钟域**：`axi_clk` (250MHz)

**AXIS Slave（写 slot）**（`axis_stream_if.slave s_axis_slot`）：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `s_axis_slot_tdata` | Input | `AXIS_DATA_W` (默认 32) | Slot 数据 |
| `s_axis_slot_tvalid` | Input | 1 | 数据有效 |
| `s_axis_slot_tready` | Output | 1 | Ready |
| `s_axis_slot_tlast` | Input | 1 | Slot 结束 |
| `s_axis_slot_tkeep` | Input | `AXIS_DATA_W/8` | Byte valid |
| `s_axis_slot_tuser` | Input | `AXIS_USER_W` | 保留 |

**AXIS Master（读 slot）**（`axis_stream_if.master m_axis_rd`）：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `m_axis_rd_tdata` | Output | `AXIS_DATA_W` | 读出的 slot 数据 |
| `m_axis_rd_tvalid` | Output | 1 | 数据有效 |
| `m_axis_rd_tready` | Input | 1 | 下游 ready |
| `m_axis_rd_tlast` | Output | 1 | Slot 结束 |
| `m_axis_rd_tkeep` | Output | `AXIS_DATA_W/8` | Byte valid |
| `m_axis_rd_tuser` | Output | `RD_AXIS_USER_W` | slot_start, slot_last, valid_good, overflow_err, seq, bytes |

**AXI4 Master（写 DDR）**（`axi4_mm_if.master m_axi`）：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `m_axi_awaddr` | Output | `CFG_AXI_ADDR_W` (34) | 写地址 |
| `m_axi_awlen` | Output | 8 | Burst 长度 |
| `m_axi_awsize` | Output | 3 | Burst size |
| `m_axi_awburst` | Output | 2 | Burst type |
| `m_axi_awvalid` | Output | 1 | 地址有效 |
| `m_axi_awready` | Input | 1 | 地址 ready |
| `m_axi_wdata` | Output | `AXI_DATA_W` (256) | 写数据 |
| `m_axi_wstrb` | Output | `AXI_DATA_W/8` | Write strobe |
| `m_axi_wlast` | Output | 1 | 最后一个 beat |
| `m_axi_wvalid` | Output | 1 | 数据有效 |
| `m_axi_wready` | Input | 1 | 数据 ready |
| `m_axi_bresp` | Input | 2 | 写响应 |
| `m_axi_bvalid` | Input | 1 | 响应有效 |
| `m_axi_bready` | Output | 1 | 响应 ready |

**侧带输入（写 slot）**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `slot_start_i` | Input | 1 | Slot 开始 |
| `slot_done_i` | Input | 1 | Slot 完成 |
| `slot_bytes_i` | Input | `SLOT_BYTES_W` | Slot 字节数 |
| `slot_seq_i` | Input | `SLOT_SEQ_W` | Slot 序号 |
| `slot_valid_good_i` | Input | 1 | Slot 有效且无错误 |
| `slot_overflow_err_i` | Input | 1 | Slot 溢出错误 |

**侧带输出（写 slot）**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `wr_slot_commit_o` | Output | 1 | Slot 提交（写入 DDR 完成） |
| `wr_slot_addr_o` | Output | `CFG_AXI_ADDR_W` | Slot 在 DDR 中的地址 |
| `wr_slot_seq_o` | Output | `SLOT_SEQ_W` | Slot 序号 |
| `wr_slot_bytes_o` | Output | `SLOT_BYTES_W` | Slot 字节数 |
| `wr_slot_valid_good_o` | Output | 1 | Slot 有效且无错误 |
| `wr_slot_overflow_err_o` | Output | 1 | Slot 溢出错误 |

**读控制信号**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `rd_slot_req_i` | Input | 1 | 读请求（读队首 slot） |
| `rd_consume_i` | Input | 1 | 消费队首 slot（释放描述符） |
| `rd_slot_valid_o` | Output | 1 | 读 slot 有效 |
| `rd_slot_addr_o` | Output | `CFG_AXI_ADDR_W` | 读 slot 地址 |
| `rd_slot_bytes_o` | Output | `SLOT_BYTES_W` | 读 slot 字节数 |
| `rd_slot_seq_o` | Output | `SLOT_SEQ_W` | 读 slot 序号 |
| `rd_slot_valid_good_o` | Output | 1 | 读 slot 有效且无错误 |
| `rd_slot_overflow_err_o` | Output | 1 | 读 slot 溢出错误 |
| `rd_busy_o` | Output | 1 | 读忙 |
| `rd_done_o` | Output | 1 | 读完成 |
| `rd_error_o` | Output | 1 | 读错误 |

**配置信号**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `cfg_enable_i` | Input | 1 | 使能 |
| `cfg_allow_overwrite_i` | Input | 1 | 允许覆盖 |
| `cfg_drop_invalid_slot_i` | Input | 1 | 丢弃无效 slot |
| `cfg_drop_on_no_space_i` | Input | 1 | 无空间时丢弃 |
| `cfg_ring_base_addr_i` | Input | `CFG_AXI_ADDR_W` | Ring buffer 基址 |
| `cfg_ring_size_bytes_i` | Input | `CFG_RING_BYTES_W` | Ring buffer 大小 |

**状态信号**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `wr_ptr_o` | Output | `CFG_AXI_ADDR_W` | 写指针 |
| `rd_ptr_o` | Output | `CFG_AXI_ADDR_W` | 读指针 |
| `commit_ptr_o` | Output | `CFG_AXI_ADDR_W` | 提交指针 |
| `used_bytes_o` | Output | `CFG_RING_BYTES_W` | 已用字节数 |
| `free_bytes_o` | Output | `CFG_RING_BYTES_W` | 空闲字节数 |
| `committed_bytes_o` | Output | `CFG_RING_BYTES_W` | 已提交字节数 |
| `full_o` | Output | 1 | Ring 满 |
| `almost_full_o` | Output | 1 | Ring 几乎满 |
| `empty_o` | Output | 1 | Ring 空 |
| `wrap_count_o` | Output | `COUNTER_W` | 写指针回绕次数 |
| `overflow_count_o` | Output | `COUNTER_W` | 溢出计数 |
| `drop_count_o` | Output | `COUNTER_W` | 丢弃计数 |

### 2.5 AXI SmartConnect（verilog-axi）

**接口类型**：AXI4 Interconnect（2 Masters → 1 Slave）

**时钟域**：`axi_clk` (250MHz)

**Master 0（RingBuffer Write）**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `s00_axi_*` | Input/Output | 按 AXI4 标准 | RingBuffer Controller AXI write |

**Master 1（Host Read）**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `s01_axi_*` | Input/Output | 按 AXI4 标准 | cocotb AXI host master |

**Slave（DDR Model）**：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `m00_axi_*` | Input/Output | 按 AXI4 标准 | DDR Model AXI slave |

### 2.6 DDR Model

**接口类型**：AXI4 Slave Memory

**时钟域**：`axi_clk` (250MHz)

**AXI4 Slave**（标准 AXI4 信号）：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `s_axi_*` | Input/Output | 按 AXI4 标准 | AXI4 slave memory 接口 |

**若使用 LiteDRAM**：需实例化 LiteDRAM 的 AXI 接口模块。

**若使用 cocotbext-axi**：通过 Python `AxiMemory` 绑定到 testbench 信号。

### 2.7 AXI Host Master（cocotb）

**接口类型**：AXI4 Master（cocotbext-axi `AxiMaster`）

**信号**（Python API，绑定到 testbench 信号）：

| 信号名 | 方向 | 位宽 | 说明 |
|--------|------|------|------|
| `awaddr`, `awlen`, `awsize`, `awburst`, `awvalid`, `awready` | Input/Output | 按 AXI4 标准 | 写地址通道 |
| `wdata`, `wstrb`, `wlast`, `wvalid`, `wready` | Input/Output | 按 AXI4 标准 | 写数据通道 |
| `bresp`, `bvalid`, `bready` | Input/Output | 按 AXI4 标准 | 写响应通道 |
| `araddr`, `arlen`, `arsize`, `arburst`, `arvalid`, `arready` | Input/Output | 按 AXI4 标准 | 读地址通道 |
| `rdata`, `rresp`, `rlast`, `rvalid`, `rready` | Input/Output | 按 AXI4 标准 | 读数据通道 |

**cocotb 使用示例**：

```python
from cocotbext.axi import AxiMaster

axi_master = AxiMaster(dut.s01_axi, dut.axi_clk, dut.axi_rst_n)
await axi_master.read(addr, length)  # Burst read
```

## 3. SystemVerilog Interface 定义

### 3.1 axis_stream_if

**位置**：`rtl/if/axis_stream_if.sv`

**定义**：

```systemverilog
interface axis_stream_if #(
    parameter int unsigned DATA_WIDTH = 32,
    parameter int unsigned USER_WIDTH = 1
) (
    input logic aclk,
    input logic aresetn
);
    logic [DATA_WIDTH-1:0] tdata;
    logic [DATA_WIDTH/8-1:0] tkeep;
    logic tlast;
    logic [USER_WIDTH-1:0] tuser;
    logic tvalid;
    logic tready;

    modport master (
        output tdata, tkeep, tlast, tuser, tvalid,
        input tready
    );

    modport slave (
        input tdata, tkeep, tlast, tuser, tvalid,
        output tready
    );
endinterface
```

### 3.2 axi4_mm_if

**位置**：`rtl/if/axi4_mm_if.sv`

**定义**：标准 AXI4 Master/Slave modport，包含 AW, W, B, AR, R 通道。

## 4. 接口连接关系

```
AXIS payload source (cocotb)
    │ AXIS
    ▼
CSI RX Subsystem (Vivado IP or Behavioral)
    │ AXIS (200MHz)
    ▼
AXIS Async FIFO (verilog-axis)
    │ AXIS (250MHz)
    ▼
CSI Packet Extractor (RTL)
    │ AXIS (250MHz) + sideband
    ▼
Fixed Slot Packer (RTL)
    │ AXIS (250MHz) + sideband
    ▼
DDR RingBuffer Controller (RTL)
    │ AXI4 Write (250MHz)
    ▼
AXI SmartConnect (verilog-axi)
    ├─── Master 0: RingBuffer Write
    └─── Master 1: Host Read (cocotb)
    │ AXI4 (250MHz)
    ▼
DDR Model (LiteDRAM or cocotbext-axi)
```
