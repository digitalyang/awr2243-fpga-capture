# 每模块 RTL/模型/IP/mock + Vivado IP 目录

## 1. 模块选择表格

| 模块名 | 选择 | 来源/文件位置 | 备注 |
|--------|------|---------------|------|
| **AXIS payload source** | Behavioral mock | cocotbext-axi `AxiStreamSource` | Python 驱动，绑定到 testbench 信号 |
| **CSI RX Subsystem** | Vivado IP（推荐）或 Behavioral mock | Vivado IP Catalog 或 Python mock | 若使用 IP，需导出 RTL；否则用 Python 直接生成 AXIS |
| **AXIS Async FIFO** | 开源模型 | verilog-axis `axis_async_fifo` | `model/verilog-axis/rtl/axis_async_fifo.v` |
| **CSI Packet Extractor** | 真实 RTL | `rtl/core/csi_packet_extractor.sv` | DUT，核心模块 |
| **Fixed Slot Packer** | 真实 RTL | `rtl/core/fixed_slot_packer.sv` | DUT，核心模块 |
| **DDR RingBuffer Controller** | 真实 RTL | `rtl/core/ddr_ringbuffer_controller.sv` | DUT，核心模块 |
| **AXI SmartConnect** | 开源模型（推荐）或 Vivado IP | verilog-axi `axi_crossbar` 或 Vivado IP | `model/verilog-axi/rtl/axi_crossbar.v` |
| **AXI host master** | Behavioral mock | cocotbext-axi `AxiMaster` | Python 驱动，模拟 XDMA host read |
| **DDR Model** | 开源模型（推荐）或 Behavioral mock | LiteDRAM 或 cocotbext-axi `AxiMemory` | LiteDRAM：RTL 模块；cocotbext-axi：纯 Python |
| **Clock/Reset generator** | Behavioral mock | cocotb `Clock` / custom | Python 驱动，在 testbench 中生成时钟/复位 |

## 2. 详细说明

### 2.1 AXIS payload source

**选择**：Behavioral mock（cocotbext-axi）

**实现**：
- **来源**：`cocotbext-axi` Python 库的 `AxiStreamSource` 类
- **位置**：`tb/cocotb/drivers/axis_payload_source.py`（封装）
- **用途**：生成 AWR2243 radar raw payload，模拟 CSI-2 数据流
- **绑定**：通过 cocotb handle 绑定到 testbench 的 AXIS 信号

**安装**：
```bash
pip install cocotbext-axi
```

### 2.2 CSI RX Subsystem

**选择**：Vivado IP（推荐）或 Behavioral mock

**选项 A：Vivado IP**

- **IP 名称**：MIPI CSI-2 RX Subsystem
- **Vivado Catalog 路径**：IP Catalog → Video & Image Processing → MIPI CSI-2 RX Subsystem
- **配置**：
  - CSI-2 Lanes：4（AWR2243 使用 4-lane）
  - Data Type Support：Raw Data（DT=0x2A）
  - AXI4-Stream Data Width：32 或 64 bit
- **导出**：在 Vivado 中生成 IP，导出 RTL 文件到 `rtl/ip/mipi_csi2_rx_subsystem/`（或 `model/vivado_ip/`）
- **约束**：需导出 XDC 约束文件（时钟、复位、引脚）

**选项 B：Behavioral mock**

- **实现**：Python（cocotb），直接生成 AXIS 数据流，跳过 D-PHY 和 CSI-2 协议层
- **位置**：`tb/cocotb/drivers/axis_payload_source.py`（与 payload source 合并）
- **优势**：简化仿真，不依赖 Vivado IP，适合功能验证

**推荐**：Behavioral mock（仿真阶段），Vivado IP（硬件集成阶段）

### 2.3 AXIS Async FIFO

**选择**：开源模型（verilog-axis）

**实现**：
- **来源**：verilog-axis 仓库的 `axis_async_fifo` 模块
- **位置**：`model/verilog-axis/rtl/axis_async_fifo.v`
- **集成**：作为 RTL 子模块实例化在 testbench 中
- **配置**：
  - `DEPTH`：512 或更大（覆盖最大 packet 长度）
  - `DATA_WIDTH`：32 或 64（与 CSI RX 输出一致）
  - `KEEP_ENABLE`：1（支持 TLAST/TKEEP）
  - `USER_ENABLE`：1（保留 TUSER）

**获取**：
```bash
git submodule add https://github.com/alexforencich/verilog-axis.git model/verilog-axis
```

### 2.4 CSI Packet Extractor

**选择**：真实 RTL

**实现**：
- **文件**：`rtl/core/csi_packet_extractor.sv`
- **依赖**：`rtl/pkg/csi_packet_pkg.sv`、`rtl/include/csi_packet_extractor_macros.svh`、`rtl/if/axis_stream_if.sv`
- **说明**：DUT 核心模块，无需替换

### 2.5 Fixed Slot Packer

**选择**：真实 RTL

**实现**：
- **文件**：`rtl/core/fixed_slot_packer.sv`
- **依赖**：`rtl/pkg/slot_packer_pkg.sv`、`rtl/include/slot_packer_macros.svh`、`rtl/if/axis_stream_if.sv`
- **说明**：DUT 核心模块，无需替换

### 2.6 DDR RingBuffer Controller

**选择**：真实 RTL

**实现**：
- **文件**：`rtl/core/ddr_ringbuffer_controller.sv`
- **依赖**：`rtl/pkg/ddr_ringbuffer_pkg.sv`、`rtl/include/ddr_ringbuffer_macros.svh`、`rtl/if/axis_stream_if.sv`、`rtl/if/axi4_mm_if.sv`
- **说明**：DUT 核心模块，无需替换

### 2.7 AXI SmartConnect

**选择**：开源模型（推荐）或 Vivado IP

**选项 A：开源模型（verilog-axi）**

- **来源**：verilog-axi 仓库的 `axi_crossbar` 模块
- **位置**：`model/verilog-axi/rtl/axi_crossbar.v`
- **配置**：
  - `S_COUNT`：2（2 个 master：RingBuffer write + Host read）
  - `M_COUNT`：1（1 个 slave：DDR Model）
  - `DATA_WIDTH`：512（AXI 数据位宽）
  - `ADDR_WIDTH`：64（AXI 地址位宽）
- **集成**：作为 RTL 子模块实例化

**获取**：
```bash
git submodule add https://github.com/alexforencich/verilog-axi.git model/verilog-axi
```

**选项 B：Vivado IP**

- **IP 名称**：AXI SmartConnect
- **Vivado Catalog 路径**：IP Catalog → AXI Infrastructure → AXI SmartConnect
- **配置**：
  - Number of Master Interfaces：2
  - Number of Slave Interfaces：1
  - Data Width：512
  - Address Width：64
- **导出**：生成 IP，导出 RTL 到 `rtl/ip/axi_smartconnect/`

**推荐**：开源模型（verilog-axi），便于版本控制和调试

### 2.8 AXI host master

**选择**：Behavioral mock（cocotbext-axi）

**实现**：
- **来源**：`cocotbext-axi` Python 库的 `AxiMaster` 类
- **位置**：`tb/cocotb/drivers/axi_host_master.py`（封装）
- **用途**：模拟 XDMA host 对 DDR 的 AXI burst read
- **绑定**：通过 cocotb handle 绑定到 AXI SmartConnect 的 Master 1 端口

### 2.9 DDR Model

**选择**：开源模型（LiteDRAM 推荐）或 Behavioral mock（cocotbext-axi）

**选项 A：LiteDRAM（推荐）**

- **来源**：LiteDRAM 仓库的 AXI 接口模块
- **位置**：`model/litedram/litedram/cores/axi.py`（Python）或 RTL wrapper
- **配置**：
  - AXI Data Width：512
  - AXI Address Width：64
  - Memory Size：256MB 或更大
- **集成**：实例化 LiteDRAM 的 AXI 接口模块（RTL）或使用 Python 绑定

**获取**：
```bash
git submodule add https://github.com/enjoy-digital/litedram.git model/litedram
```

**选项 B：cocotbext-axi AxiMemory（纯 Python）**

- **来源**：`cocotbext-axi` Python 库的 `AxiMemory` 类
- **位置**：在 testbench 中通过 Python 绑定
- **优势**：纯 Python，无需 RTL 模块，易于调试
- **劣势**：性能可能不如 RTL 模型

**推荐**：LiteDRAM（RTL 模型，更接近真实 DDR）或 cocotbext-axi（纯 Python，简化调试）

### 2.10 Clock/Reset generator

**选择**：Behavioral mock（cocotb）

**实现**：
- **来源**：cocotb `Clock` 类 + 自定义复位函数
- **位置**：`tb/cocotb/drivers/clk_rst.py` 或 `conftest.py`
- **时钟**：video_aclk (200MHz), axis_clk/axi_clk (250MHz)
- **复位**：异步断言，同步释放

## 3. Vivado IP Catalog 获取方式

### 3.1 MIPI CSI-2 RX Subsystem

**步骤**：
1. 打开 Vivado
2. IP Catalog（左侧面板）
3. 导航：**Video & Image Processing** → **MIPI CSI-2 RX Subsystem**
4. 双击打开配置界面
5. 配置参数：
   - CSI-2 Lanes：4
   - Data Type Support：Raw Data (DT=0x2A)
   - AXI4-Stream Data Width：32 或 64
   - Clock Domain：video_aclk (200MHz)
6. 生成 IP，导出到项目

**文件位置**（生成后）：
- RTL：`<project_dir>/<ip_name>/<ip_name>.srcs/sources_1/ip/<ip_name>/<ip_name>.v`
- 约束：`<project_dir>/<ip_name>/<ip_name>.srcs/constrs_1/new/<ip_name>.xdc`

**集成到仿真**：
- 将 RTL 文件添加到 `sim/Makefile` 或 `tb/cocotb/run_*.py` 的 `build_sources()`
- 将约束文件中的时钟/复位定义转换为 testbench 中的时钟生成

### 3.2 AXI SmartConnect

**步骤**：
1. IP Catalog → **AXI Infrastructure** → **AXI SmartConnect**
2. 配置：
   - Number of Master Interfaces：2
   - Number of Slave Interfaces：1
   - Data Width：512
   - Address Width：64
   - Clock Domain：axi_clk (250MHz)
3. 生成 IP，导出 RTL

**注意**：若使用开源模型（verilog-axi），可跳过此 IP。

### 3.3 AXIS Data FIFO（可选）

**步骤**：
1. IP Catalog → **AXI Infrastructure** → **AXI4-Stream Data FIFO**
2. 配置：
   - FIFO Depth：512 或更大
   - TDATA Width：32 或 64
   - TUSER Width：按需
3. 生成 IP

**注意**：若使用 verilog-axis `axis_fifo`，可跳过此 IP。

## 4. 开源模型分配

### 4.1 cocotbext-axi

**分配**：
- **AXIS payload source**：`AxiStreamSource` → 生成 CSI-2 数据流
- **AXIS monitor**：`AxiStreamMonitor` → 监控 Extractor/Packer 输出
- **AXI host master**：`AxiMaster` → 模拟 Host 读 DDR
- **DDR Model（可选）**：`AxiMemory` → 纯 Python DDR 模型

**安装**：
```bash
pip install cocotbext-axi
```

### 4.2 verilog-axi

**分配**：
- **AXI SmartConnect**：`axi_crossbar` → 2 master → 1 slave 仲裁

**获取**：
```bash
git submodule add https://github.com/alexforencich/verilog-axi.git model/verilog-axi
```

**文件列表**（需添加到编译）：
- `model/verilog-axi/rtl/axi_crossbar.v`
- `model/verilog-axi/rtl/axi_arbiter.v`（依赖）
- `model/verilog-axi/rtl/axi_*.v`（其他依赖）

### 4.3 verilog-axis

**分配**：
- **AXIS Async FIFO**：`axis_async_fifo` → CDC (200MHz → 250MHz)

**获取**：
```bash
git submodule add https://github.com/alexforencich/verilog-axis.git model/verilog-axis
```

**文件列表**（需添加到编译）：
- `model/verilog-axis/rtl/axis_async_fifo.v`
- `model/verilog-axis/rtl/axis_fifo*.v`（依赖）

### 4.4 LiteDRAM

**分配**：
- **DDR Model**：LiteDRAM AXI 接口 → DDR behavioral model

**获取**：
```bash
git submodule add https://github.com/enjoy-digital/litedram.git model/litedram
```

**集成**：
- 使用 LiteDRAM 的 AXI 接口 wrapper（RTL）
- 或使用 LiteDRAM 的 Python 绑定（若支持）

### 4.5 cocotb

**分配**：
- **测试框架**：cocotb → Verilator/其他仿真器集成
- **时钟/复位**：cocotb `Clock` → 时钟生成

**安装**：
```bash
pip install cocotb
```

## 5. 文件列表组织

### 5.1 Verilator 编译文件列表

**位置**：`sim/Makefile` 或 `tb/cocotb/run_*.py` 的 `build_sources()`

**示例**（`tb/cocotb/run_pipeline.py`）：

```python
def build_sources():
    return [
        # RTL DUT
        REPO_ROOT / "rtl/core/csi_packet_extractor.sv",
        REPO_ROOT / "rtl/core/fixed_slot_packer.sv",
        REPO_ROOT / "rtl/core/ddr_ringbuffer_controller.sv",
        REPO_ROOT / "rtl/pkg/*.sv",
        REPO_ROOT / "rtl/include/*.svh",
        REPO_ROOT / "rtl/if/*.sv",
        
        # 开源模型
        REPO_ROOT / "model/verilog-axis/rtl/axis_async_fifo.v",
        REPO_ROOT / "model/verilog-axi/rtl/axi_crossbar.v",
        # LiteDRAM（若使用 RTL）
        # REPO_ROOT / "model/litedram/...",
        
        # Vivado IP（若使用）
        # REPO_ROOT / "rtl/ip/mipi_csi2_rx_subsystem/...",
        # REPO_ROOT / "rtl/ip/axi_smartconnect/...",
        
        # Testbench
        TB_DIR / "top_tb.sv",  # 或 pipeline_cocotb_top.sv
    ]
```

### 5.2 依赖管理

**Git submodules**（推荐）：

```bash
# 初始化 submodules
git submodule update --init --recursive

# 更新 submodules
git submodule update --remote
```

**.gitmodules**（示例）：

```ini
[submodule "model/verilog-axi"]
    path = model/verilog-axi
    url = https://github.com/alexforencich/verilog-axi.git
[submodule "model/verilog-axis"]
    path = model/verilog-axis
    url = https://github.com/alexforencich/verilog-axis.git
[submodule "model/litedram"]
    path = model/litedram
    url = https://github.com/enjoy-digital/litedram.git
```

## 6. 总结

**RTL DUT**：3 个核心模块（Extractor、Packer、RingBuffer Controller）使用真实 RTL。

**开源模型**：
- verilog-axis：AXIS Async FIFO
- verilog-axi：AXI SmartConnect
- LiteDRAM：DDR Model（可选）

**Behavioral mock（Python）**：
- cocotbext-axi：AXIS payload source、AXIS monitor、AXI host master、DDR Model（可选）
- cocotb：Clock/Reset generator

**Vivado IP（可选）**：
- MIPI CSI-2 RX Subsystem：CSI-2 接收（可用 behavioral mock 替代）
- AXI SmartConnect：可用 verilog-axi 替代
- AXIS Data FIFO：可用 verilog-axis 替代

**推荐配置**（最小依赖）：
- RTL DUT + verilog-axis + verilog-axi + cocotbext-axi + cocotb
- 不使用 Vivado IP（用 behavioral mock 和开源模型）
