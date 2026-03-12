# 系统仿真架构设计

## 1. 仿真平台总体框图

```
┌─────────────────────────────────────────────────────────────────┐
│                        Simulation Platform                        │
├─────────────────────────────────────────────────────────────────┤
│                                                                   │
│  ┌──────────────────┐                                           │
│  │ cocotb Testbench │                                           │
│  │  - conftest.py   │                                           │
│  │  - test_*.py     │                                           │
│  └────────┬─────────┘                                           │
│           │                                                      │
│           │ Python API (cocotbext-axi)                           │
│           │                                                      │
│  ┌────────▼──────────────────────────────────────────────────┐ │
│  │              Top Testbench (top_tb.sv)                    │ │
│  │                                                             │ │
│  │  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐   │ │
│  │  │ Clock/Reset  │  │ AXIS Source  │  │ AXI Host     │   │ │
│  │  │ Generator    │  │ (cocotb)     │  │ Master       │   │ │
│  │  │              │  │              │  │ (cocotb)     │   │ │
│  │  └──────┬───────┘  └──────┬───────┘  └──────┬───────┘   │ │
│  │         │                  │                  │            │ │
│  │         │ video_aclk       │ AXIS             │ AXI4       │ │
│  │         │ 200MHz           │                  │            │ │
│  │         │                  │                  │            │ │
│  │  ┌──────▼──────────────────▼──────────────────▼──────┐   │ │
│  │  │         DUT: Radar Capture Pipeline                │   │ │
│  │  │                                                      │   │ │
│  │  │  ┌──────────────┐                                   │   │ │
│  │  │  │ CSI RX       │  (Vivado IP or Behavioral)      │   │ │
│  │  │  │ Subsystem    │                                   │   │ │
│  │  │  └──────┬───────┘                                   │   │ │
│  │  │         │ AXIS (200MHz)                             │   │ │
│  │  │  ┌──────▼───────┐                                   │   │ │
│  │  │  │ AXIS Async   │  (verilog-axis)                   │   │ │
│  │  │  │ FIFO         │  CDC: 200MHz -> 250MHz            │   │ │
│  │  │  └──────┬───────┘                                   │   │ │
│  │  │         │ AXIS (250MHz)                             │   │ │
│  │  │  ┌──────▼──────────────┐                           │   │ │
│  │  │  │ CSI Packet          │  (RTL: csi_packet_        │   │ │
│  │  │  │ Extractor           │       extractor.sv)        │   │ │
│  │  │  └──────┬───────────────┘                           │   │ │
│  │  │         │ AXIS (250MHz)                             │   │ │
│  │  │  ┌──────▼──────────────┐                           │   │ │
│  │  │  │ Fixed Slot Packer   │  (RTL: fixed_slot_        │   │ │
│  │  │  │                     │       packer.sv)           │   │ │
│  │  │  └──────┬──────────────┘                           │   │ │
│  │  │         │ AXIS (250MHz)                             │   │ │
│  │  │  ┌──────▼──────────────────────┐                    │   │ │
│  │  │  │ DDR RingBuffer Controller   │  (RTL: ddr_       │   │ │
│  │  │  │                             │       ringbuffer_  │   │ │
│  │  │  │                             │       controller)  │   │ │
│  │  │  └──────┬──────────────────────┘                    │   │ │
│  │  │         │ AXI4 Write (250MHz)                       │   │ │
│  │  │  ┌──────▼──────────────────────┐                    │   │ │
│  │  │  │ AXI SmartConnect            │  (verilog-axi or   │   │ │
│  │  │  │ 2 Masters -> 1 Slave       │   Vivado IP)        │   │ │
│  │  │  │  - RingBuffer Write         │                    │   │ │
│  │  │  │  - Host Read                │                    │   │ │
│  │  │  └──────┬──────────────────────┘                    │   │ │
│  │  │         │ AXI4 (250MHz)                             │   │ │
│  │  │  ┌──────▼──────────────┐                           │   │ │
│  │  │  │ DDR Model           │  (LiteDRAM or cocotbext-  │   │ │
│  │  │  │ AXI Slave Memory    │   axi AXI memory)         │   │ │
│  │  │  └─────────────────────┘                           │   │ │
│  │  │                                                      │   │ │
│  │  └──────────────────────────────────────────────────────┘   │ │
│  │                                                             │ │
│  └─────────────────────────────────────────────────────────────┘ │
│                                                                   │
└─────────────────────────────────────────────────────────────────┘
```

## 2. 数据路径与时钟域边界

### 2.1 数据路径

```
AXIS payload source (cocotb)
    │
    │ AXIS (video_aclk = 200MHz)
    ▼
CSI RX Subsystem (Vivado IP or Behavioral)
    │
    │ AXIS (video_aclk = 200MHz)
    ▼
AXIS Async FIFO (verilog-axis)
    │ [CDC Boundary: 200MHz -> 250MHz]
    │ AXIS (axis_clk = 250MHz)
    ▼
CSI Packet Extractor (RTL: csi_packet_extractor.sv)
    │
    │ AXIS (axis_clk = 250MHz)
    │ Sideband: pkt_start, pkt_done, pkt_bytes, pkt_seq, pkt_*_err
    ▼
Fixed Slot Packer (RTL: fixed_slot_packer.sv)
    │
    │ AXIS (axis_clk = 250MHz)
    │ Sideband: slot_start, slot_done, slot_bytes, slot_seq, slot_valid_good
    ▼
DDR RingBuffer Controller (RTL: ddr_ringbuffer_controller.sv)
    │
    │ AXI4 Write (axi_clk = 250MHz)
    ▼
AXI SmartConnect (verilog-axi or Vivado IP)
    │
    │ AXI4 (axi_clk = 250MHz)
    ├───► RingBuffer Write (Master 0)
    └───► Host Read (Master 1, cocotb AXI master)
    │
    │ AXI4 (axi_clk = 250MHz)
    ▼
DDR Model (LiteDRAM or cocotbext-axi AXI memory)
```

### 2.2 时钟域划分

| 时钟域 | 频率 | 来源 | 用途 |
|--------|------|------|------|
| `video_aclk` | 200MHz | Testbench generator | CSI RX Subsystem, AXIS payload source |
| `axis_clk` | 250MHz | Testbench generator | CSI Packet Extractor, Fixed Slot Packer, AXIS Async FIFO 输出侧 |
| `axi_clk` | 250MHz | Testbench generator (与 axis_clk 同源或同步) | DDR RingBuffer Controller, AXI SmartConnect, DDR Model |

**CDC 边界**：
- **200MHz → 250MHz**：AXIS Async FIFO（verilog-axis 的 `axis_async_fifo`）处理跨时钟域
- 其他模块均在 250MHz 域内，无额外 CDC

## 3. 仿真专用组件

### 3.1 cocotb 驱动/监控组件

| 组件 | 来源 | 用途 | 位置 |
|------|------|------|------|
| **AXIS payload source** | cocotbext-axi `AxiStreamSource` | 生成 AWR2243 radar raw payload，模拟 CSI-2 数据流 | `cocotb/drivers/axis_payload_source.py` |
| **AXIS monitor** | cocotbext-axi `AxiStreamMonitor` | 监控 Extractor/Packer 输出，用于 scoreboard | `cocotb/monitors/axis_monitor.py` |
| **AXI host master** | cocotbext-axi `AxiMaster` | 模拟 XDMA host 对 DDR 的 burst read | `cocotb/drivers/axi_host_master.py` |
| **Clock/Reset driver** | cocotb `Clock` / custom | 驱动 video_aclk, axis_clk, axi_clk 及复位 | `cocotb/drivers/clk_rst.py` |

### 3.2 RTL 模块（DUT）

| 模块 | 类型 | 文件位置 | 说明 |
|------|------|----------|------|
| **CSI Packet Extractor** | 真实 RTL | `rtl/core/csi_packet_extractor.sv` | 过滤 CSI-2 long packet，提取 payload |
| **Fixed Slot Packer** | 真实 RTL | `rtl/core/fixed_slot_packer.sv` | 将 payload 封装为固定长度 slot（12352B） |
| **DDR RingBuffer Controller** | 真实 RTL | `rtl/core/ddr_ringbuffer_controller.sv` | 管理 ring buffer，AXI 写 DDR，维护描述符 |

### 3.3 开源模型组件

| 组件 | 来源 | 用途 | 集成方式 |
|------|------|------|----------|
| **AXIS Async FIFO** | verilog-axis `axis_async_fifo` | CDC：200MHz → 250MHz | 作为 RTL 子模块实例化，或通过 `model/verilog-axis/` 路径引用 |
| **AXI SmartConnect** | verilog-axi `axi_crossbar` | 2 master → 1 slave 仲裁 | 作为 RTL 子模块实例化，或通过 `model/verilog-axi/` 路径引用 |
| **DDR Model** | LiteDRAM 或 cocotbext-axi `AxiMemory` | AXI slave memory，模拟 DDR | LiteDRAM：作为 RTL 模块；cocotbext-axi：纯 Python，通过 cocotb 绑定 |

### 3.4 Vivado IP（可选）

| IP | Vivado Catalog 路径 | 用途 | 替代方案 |
|----|---------------------|------|----------|
| **MIPI CSI-2 RX Subsystem** | IP Catalog → Video & Image Processing → MIPI CSI-2 RX Subsystem | CSI-2 接收 | Behavioral mock（仅仿真 payload，不仿真 D-PHY） |
| **AXI SmartConnect** | IP Catalog → AXI Infrastructure → AXI SmartConnect | AXI interconnect | verilog-axi `axi_crossbar` |
| **AXIS Data FIFO** | IP Catalog → AXI Infrastructure → AXI4-Stream Data FIFO | AXIS FIFO | verilog-axis `axis_fifo` |

## 4. 连接关系

### 4.1 cocotb → Testbench

- **Clock/Reset**：cocotb `Clock` 对象驱动 `top_tb.sv` 中的时钟信号
- **AXIS Source**：cocotbext-axi `AxiStreamSource` 通过 `cocotb.handle` 绑定到 testbench 的 AXIS 信号
- **AXI Master**：cocotbext-axi `AxiMaster` 绑定到 AXI SmartConnect 的 Master 1 端口

### 4.2 Testbench → DUT

- **CSI RX**：若使用 Vivado IP，通过 AXI4-Stream 连接到 Extractor；若使用 behavioral mock，直接输出 AXIS 到 Extractor
- **AXIS Async FIFO**：输入侧接 CSI RX（200MHz），输出侧接 Extractor（250MHz）
- **Pipeline**：Extractor → Packer → RingBuffer Controller，均为 AXIS（250MHz）
- **AXI SmartConnect**：Master 0 = RingBuffer Controller AXI write，Master 1 = Host AXI read（cocotb）

### 4.3 DUT → DDR Model

- **AXI4**：SmartConnect Slave 端口连接到 DDR Model（LiteDRAM 或 cocotbext-axi AXI memory）

## 5. 仿真平台层次

```
top_tb.sv (SystemVerilog)
├── Clock/Reset Generator (SV initial blocks or cocotb-driven)
├── AXIS payload source (cocotb handle binding)
├── CSI RX Subsystem (Vivado IP or behavioral)
├── AXIS Async FIFO (verilog-axis)
├── CSI Packet Extractor (RTL DUT)
├── Fixed Slot Packer (RTL DUT)
├── DDR RingBuffer Controller (RTL DUT)
├── AXI SmartConnect (verilog-axi or Vivado IP)
├── DDR Model (LiteDRAM or cocotbext-axi)
└── AXI host master (cocotb handle binding)

cocotb/
├── conftest.py (simulator selection, DUT top, common fixtures)
├── tests/
│   └── test_*.py (test cases)
├── drivers/
│   ├── axis_payload_source.py
│   ├── axi_host_master.py
│   └── clk_rst.py
├── monitors/
│   └── axis_monitor.py
└── scoreboard/
    └── slot_scoreboard.py
```

## 6. 验证重点覆盖

1. **Payload 提取**：CSI Packet Extractor 正确识别并转发 long packet payload
2. **Slot 封装**：Fixed Slot Packer 生成 12352B 固定长度 slot（header + sample + CQ + padding）
3. **CDC**：AXIS Async FIFO 正确处理 200MHz → 250MHz 跨时钟域
4. **Ring Buffer**：DDR RingBuffer Controller 正确管理 ring，分配地址，提交描述符
5. **DDR 写入**：AXI write burst 正确写入 DDR Model
6. **Host burst read**：AXI host master 通过 SmartConnect 正确读取 DDR 中的 slot 数据
