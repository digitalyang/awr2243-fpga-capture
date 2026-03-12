# 毫米波雷达采集链路仿真平台设计 — 总览

## 项目概述

本文档是「毫米波雷达采集链路完整仿真平台」设计文档的总览与入口。本平台基于 **TI AWR2243** 雷达器件的 MIPI CSI-2 输出，设计了一个端到端的仿真验证环境，覆盖从 CSI-2 packet 提取、固定长度 slot 封装、DDR ring buffer 管理到 Host 读回的完整数据路径。

**技术栈**：
- **RTL**：SystemVerilog（CSI Packet Extractor、Fixed Slot Packer、DDR RingBuffer Controller）
- **仿真平台**：cocotb + Verilator
- **开源模型**：verilog-axis（AXIS Async FIFO）、verilog-axi（AXI SmartConnect）、LiteDRAM（DDR Model）
- **Vivado IP**（可选）：MIPI CSI-2 RX Subsystem、AXI SmartConnect、AXIS Data FIFO

---

## 文档结构

本设计文档共包含 **10 个章节**，按设计流程组织：

| 文档 | 标题 | 主要内容 |
|------|------|----------|
| **[01_system_simulation_architecture.md](01_system_simulation_architecture.md)** | 系统仿真架构设计 | 总体框图、数据路径、时钟域边界、仿真组件、连接关系 |
| **[02_clock_domain_and_reset_planning.md](02_clock_domain_and_reset_planning.md)** | 时钟域与 Reset 规划 | 时钟域定义（200MHz/250MHz）、复位策略、CDC 处理、时钟/复位生成方式 |
| **[03_module_list_and_interfaces.md](03_module_list_and_interfaces.md)** | 模块清单与接口定义 | 所有模块（DUT、模型、IP、mock）的详细接口定义、信号位宽、协议规范 |
| **[04_directory_structure.md](04_directory_structure.md)** | 目录结构 | 推荐工程目录树（rtl/tb/sim/model/cocotb/docs）、命名规范、Git 管理建议 |
| **[05_cocotb_verification_platform.md](05_cocotb_verification_platform.md)** | cocotb 验证平台结构 | cocotb 目录组织、conftest.py、驱动/监控/scoreboard 设计、测试发现与回归 |
| **[06_reference_model_and_scoreboard.md](06_reference_model_and_scoreboard.md)** | 参考模型与 Scoreboard | Slot 参考模型（payload→slot→DDR 地址映射）、Scoreboard 设计、Python 实现 |
| **[07_per_module_choices_and_vivado_ip.md](07_per_module_choices_and_vivado_ip.md)** | 每模块 RTL/模型/IP/mock + Vivado IP | 每个模块的实现选择（RTL/开源模型/Vivado IP/mock）、Vivado IP Catalog 路径、集成步骤 |
| **[08_recommended_test_cases.md](08_recommended_test_cases.md)** | 推荐测试用例 | 测试用例分类（Sanity/功能/错误处理/CDC/性能）、覆盖目标、cocotb 映射、优先级 |
| **[09_top_level_testbench_structure.md](09_top_level_testbench_structure.md)** | 顶层 Testbench 结构 | Testbench 层次、时钟/复位生成、DUT 实例化、开源模型集成、cocotb 绑定、最小骨架代码 |
| **[10_engineering_implementation_steps.md](10_engineering_implementation_steps.md)** | 工程实施步骤 | 有序实施步骤（仓库/依赖/模型集成/RTL/IP/cocotb/TB/首次运行/回归）、命令与文件清单 |

---

## 系统架构概览

### 数据路径

```
AXIS payload source (cocotb)
    │
    │ AXIS (video_aclk = 200MHz)
    ▼
CSI RX Subsystem (Vivado IP 或 Behavioral mock)
    │
    │ AXIS (video_aclk = 200MHz)
    ▼
AXIS Async FIFO (verilog-axis)
    │ [CDC: 200MHz → 250MHz]
    │ AXIS (axis_clk = 250MHz)
    ▼
CSI Packet Extractor (RTL)
    │ AXIS + Sideband
    ▼
Fixed Slot Packer (RTL)
    │ AXIS (固定长度 slot: 12352B)
    ▼
DDR RingBuffer Controller (RTL)
    │ AXI4 Write
    ▼
AXI SmartConnect (verilog-axi 或 Vivado IP)
    ├── RingBuffer Write (Master 0)
    └── Host Read (Master 1)
    │
    ▼
DDR Model (LiteDRAM 或 cocotbext-axi)
```

### 时钟域

| 时钟域 | 频率 | 用途 |
|--------|------|------|
| `video_aclk` | 200MHz | CSI RX Subsystem、AXIS payload source 输入侧 |
| `axis_clk` | 250MHz | CSI Packet Extractor、Fixed Slot Packer、AXIS Async FIFO 输出侧 |
| `axi_clk` | 250MHz | DDR RingBuffer Controller、AXI SmartConnect、DDR Model |

**CDC 边界**：AXIS Async FIFO（200MHz → 250MHz）

### 核心模块

| 模块 | 类型 | 文件位置 | 说明 |
|------|------|----------|------|
| **CSI Packet Extractor** | RTL DUT | `rtl/core/csi_packet_extractor.sv` | 过滤 CSI-2 long packet（VC/DT），提取 payload，输出侧带信号 |
| **Fixed Slot Packer** | RTL DUT | `rtl/core/fixed_slot_packer.sv` | 将 payload 封装为固定长度 slot（12352B：12B header + 12288B sample + 9B CQ + padding） |
| **DDR RingBuffer Controller** | RTL DUT | `rtl/core/ddr_ringbuffer_controller.sv` | 管理 ring buffer，AXI 写 DDR，维护描述符 FIFO，支持 Host 读路径 |
| **AXIS Async FIFO** | 开源模型 | `model/verilog-axis/rtl/axis_async_fifo.v` | CDC：200MHz → 250MHz |
| **AXI SmartConnect** | 开源模型 | `model/verilog-axi/rtl/axi_crossbar.v` | 2 masters → 1 slave 仲裁 |
| **DDR Model** | 开源模型 | LiteDRAM 或 cocotbext-axi `AxiMemory` | AXI slave memory |

---

## 模块实现选择

### 推荐配置（仿真阶段）

| 模块 | 选择 | 来源 | 备注 |
|------|------|------|------|
| AXIS payload source | Behavioral mock | cocotbext-axi `AxiStreamSource` | Python 驱动 |
| CSI RX Subsystem | Behavioral mock | Python（与 payload source 合并） | 简化仿真，跳过 D-PHY/CSI-2 协议层 |
| AXIS Async FIFO | 开源模型 | verilog-axis | Git submodule |
| CSI Packet Extractor | RTL | `rtl/core/csi_packet_extractor.sv` | DUT |
| Fixed Slot Packer | RTL | `rtl/core/fixed_slot_packer.sv` | DUT |
| DDR RingBuffer Controller | RTL | `rtl/core/ddr_ringbuffer_controller.sv` | DUT |
| AXI SmartConnect | 开源模型 | verilog-axi | Git submodule |
| AXI host master | Behavioral mock | cocotbext-axi `AxiMaster` | Python 驱动 |
| DDR Model | Behavioral mock | cocotbext-axi `AxiMemory` | Python 驱动（推荐）或 LiteDRAM RTL |

### 硬件集成阶段（可选）

- **CSI RX Subsystem**：使用 Vivado IP（MIPI CSI-2 RX Subsystem）
- **AXI SmartConnect**：使用 Vivado IP（AXI SmartConnect）
- **AXIS Data FIFO**：使用 Vivado IP（若需要同步 FIFO）

详细说明见 **[07_per_module_choices_and_vivado_ip.md](07_per_module_choices_and_vivado_ip.md)**。

---

## 目录结构

### 推荐工程目录树

```
awr2243-fpga-capture/
├── rtl/                          # RTL 源代码
│   ├── core/                    # 核心 RTL 模块
│   ├── pkg/                     # SystemVerilog 包
│   ├── include/                 # 宏定义
│   ├── if/                      # SystemVerilog 接口
│   └── ip/                      # Vivado IP（可选）
│
├── tb/                          # Testbench
│   ├── top_tb.sv                # 顶层 testbench
│   └── cocotb/                  # cocotb 测试平台
│       ├── conftest.py          # pytest 配置
│       ├── tests/               # 测试用例
│       ├── drivers/             # cocotb 驱动
│       ├── monitors/            # cocotb 监控
│       ├── scoreboard/          # Scoreboard
│       ├── model/               # Reference model
│       └── run_*.py             # 测试运行脚本
│
├── model/                       # 开源模型（Git submodules）
│   ├── verilog-axis/            # AXIS Async FIFO
│   ├── verilog-axi/             # AXI SmartConnect
│   └── litedram/                # DDR Model（可选）
│
├── sim_build/                   # 仿真构建产物
│   └── <test_name>_cocotb/      # Verilator 输出
│
└── docs/sim_platform/           # 本文档集
    ├── 00_README.md             # 本文件（总览）
    ├── 01_system_simulation_architecture.md
    ├── 02_clock_domain_and_reset_planning.md
    ├── 03_module_list_and_interfaces.md
    ├── 04_directory_structure.md
    ├── 05_cocotb_verification_platform.md
    ├── 06_reference_model_and_scoreboard.md
    ├── 07_per_module_choices_and_vivado_ip.md
    ├── 08_recommended_test_cases.md
    ├── 09_top_level_testbench_structure.md
    └── 10_engineering_implementation_steps.md
```

详细说明见 **[04_directory_structure.md](04_directory_structure.md)**。

---

## 快速开始

### 1. 环境准备

```bash
# Python 虚拟环境
/usr/bin/python3 -m venv ~/.venvs/awr2243-cocotb-py39
source ~/.venvs/awr2243-cocotb-py39/bin/activate
pip install -r tb/cocotb/requirements.txt

# Verilator
brew install verilator  # macOS
# 或
sudo apt-get install verilator  # Linux
```

### 2. 开源模型集成

```bash
# Git submodules
git submodule add https://github.com/alexforencich/verilog-axis.git model/verilog-axis
git submodule add https://github.com/alexforencich/verilog-axi.git model/verilog-axi
git submodule update --init --recursive
```

### 3. 运行 Sanity 测试

```bash
cd tb/cocotb
python run_top.py --testcase test_top_sanity
```

### 4. 运行 Full 回归

```bash
pytest tests/ -v
```

**详细步骤**见 **[10_engineering_implementation_steps.md](10_engineering_implementation_steps.md)**。

---

## 测试用例概览

### Sanity 测试（P0）

- `test_top_sanity`：完整 pipeline 基本功能
- `test_extractor_smoke`：Extractor 基本过滤
- `test_packer_smoke`：Packer 基本封装
- `test_ringbuffer_smoke`：RingBuffer 基本写入/读出

### 功能测试（P1）

- `test_pipeline_awr_frame_roundtrip`：完整 AWR frame 往返
- `test_pipeline_back_to_back_slots`：背靠背 slot 处理
- `test_ringbuffer_wraparound`：Ring buffer 回绕
- `test_axi_burst_lengths`：AXI burst 长度变化
- `test_host_read_burst`：Host burst read

### 错误处理测试（P1）

- `test_pipeline_invalid_slot_roundtrip`：Invalid slot 处理
- `test_pipeline_controller_drops_invalid`：Controller 丢弃 invalid
- `test_extractor_error_latch`：Extractor 错误锁存
- `test_packer_overflow`：Packer 溢出处理
- `test_ringbuffer_full_drop`：Ring 满时丢弃

### CDC 与时序测试（P1-P2）

- `test_cdc_async_fifo`：CDC Async FIFO 功能
- `test_cdc_timing`：CDC 时序验证
- `test_backpressure`：背压处理

### 性能与压力测试（P2）

- `test_pipeline_continuous_stream`：连续流处理
- `test_ringbuffer_stress`：Ring buffer 压力
- `test_axi_concurrent`：AXI 并发访问

**详细说明**见 **[08_recommended_test_cases.md](08_recommended_test_cases.md)**。

---

## 关键设计决策

### 1. Slot 设计

- **固定长度**：12352B（64B 对齐）
- **布局**：12B RX headers + 12288B samples（1024 sample × 12B） + 9B CQ + padding
- **对齐**：64B 对齐，便于 AXI burst 写入

### 2. CDC 处理

- **位置**：AXIS Async FIFO（200MHz → 250MHz）
- **实现**：verilog-axis `axis_async_fifo`
- **策略**：异步 FIFO，双时钟域，FIFO 满/空处理

### 3. DDR Ring Buffer

- **管理**：RingBuffer Controller 维护写指针、描述符 FIFO
- **写入**：AXI4 write burst（最大 256 beats，512-bit data width）
- **读出**：Host AXI master 基于描述符读回
- **回绕**：写指针回绕时地址计算正确

### 4. 验证策略

- **平台**：cocotb + Verilator（开源，快速）
- **参考模型**：Python 实现（payload → slot → DDR 地址映射）
- **Scoreboard**：自动比较 DUT 输出与参考模型
- **测试发现**：pytest 自动发现 `test_*.py`

---

## 文档使用指南

### 按角色阅读

**系统架构师**：
1. [01_system_simulation_architecture.md](01_system_simulation_architecture.md) — 总体架构
2. [02_clock_domain_and_reset_planning.md](02_clock_domain_and_reset_planning.md) — 时钟/复位规划
3. [03_module_list_and_interfaces.md](03_module_list_and_interfaces.md) — 模块接口

**RTL 工程师**：
1. [03_module_list_and_interfaces.md](03_module_list_and_interfaces.md) — 接口定义
2. [07_per_module_choices_and_vivado_ip.md](07_per_module_choices_and_vivado_ip.md) — 模块选择
3. [09_top_level_testbench_structure.md](09_top_level_testbench_structure.md) — Testbench 结构

**验证工程师**：
1. [05_cocotb_verification_platform.md](05_cocotb_verification_platform.md) — cocotb 平台
2. [06_reference_model_and_scoreboard.md](06_reference_model_and_scoreboard.md) — 参考模型
3. [08_recommended_test_cases.md](08_recommended_test_cases.md) — 测试用例
4. [09_top_level_testbench_structure.md](09_top_level_testbench_structure.md) — Testbench 结构

**项目管理者**：
1. [10_engineering_implementation_steps.md](10_engineering_implementation_steps.md) — 实施步骤
2. [04_directory_structure.md](04_directory_structure.md) — 目录结构

### 按流程阅读

**设计阶段**：
1. [01_system_simulation_architecture.md](01_system_simulation_architecture.md)
2. [02_clock_domain_and_reset_planning.md](02_clock_domain_and_reset_planning.md)
3. [03_module_list_and_interfaces.md](03_module_list_and_interfaces.md)
4. [07_per_module_choices_and_vivado_ip.md](07_per_module_choices_and_vivado_ip.md)

**实现阶段**：
1. [04_directory_structure.md](04_directory_structure.md)
2. [05_cocotb_verification_platform.md](05_cocotb_verification_platform.md)
3. [06_reference_model_and_scoreboard.md](06_reference_model_and_scoreboard.md)
4. [09_top_level_testbench_structure.md](09_top_level_testbench_structure.md)

**验证阶段**：
1. [08_recommended_test_cases.md](08_recommended_test_cases.md)
2. [10_engineering_implementation_steps.md](10_engineering_implementation_steps.md)

---

## 一致性检查

本文档集已通过一致性检查，确保：

- ✅ **时钟命名**：`video_aclk` (200MHz), `axis_clk` (250MHz), `axi_clk` (250MHz) — 所有文档一致
- ✅ **模块命名**：CSI Packet Extractor, Fixed Slot Packer, DDR RingBuffer Controller — 所有文档一致
- ✅ **文件路径**：`rtl/core/`, `tb/cocotb/`, `model/` — 所有文档一致
- ✅ **接口信号**：AXIS/AXI 信号命名与位宽 — 所有文档一致
- ✅ **Slot 规格**：12352B（64B 对齐）— 所有文档一致

---

## 相关资源

### 开源项目

- **verilog-axis**：https://github.com/alexforencich/verilog-axis
- **verilog-axi**：https://github.com/alexforencich/verilog-axi
- **LiteDRAM**：https://github.com/enjoy-digital/litedram
- **cocotb**：https://github.com/cocotb/cocotb
- **cocotbext-axi**：https://github.com/alexforencich/cocotbext-axi

### Vivado IP Catalog

- **MIPI CSI-2 RX Subsystem**：IP Catalog → Video & Image Processing → MIPI CSI-2 RX Subsystem
- **AXI SmartConnect**：IP Catalog → AXI Infrastructure → AXI SmartConnect
- **AXIS Data FIFO**：IP Catalog → AXI Infrastructure → AXI4-Stream Data FIFO

---

## 更新日志

- **2026-03-12**：初始版本，完成 10 个设计文档
  - Wave 0：系统架构、时钟/复位、模块清单、目录结构
  - Wave 1：cocotb 平台、参考模型、模块选择
  - Wave 2：测试用例、Testbench 结构、实施步骤
  - Wave 3：最终整合与总览

---

## 联系方式

如有问题或建议，请参考各章节文档或联系项目维护者。
