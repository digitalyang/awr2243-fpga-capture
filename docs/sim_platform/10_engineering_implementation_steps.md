# 工程实施步骤

## 1. 仓库与依赖准备

### 1.1 克隆/更新主仓库

```bash
# 若已有仓库
cd /path/to/awr2243-fpga-capture
git pull origin main

# 若新克隆
git clone <repo_url> awr2243-fpga-capture
cd awr2243-fpga-capture
```

### 1.2 Python 虚拟环境

```bash
# 创建虚拟环境（Python 3.9-3.13）
/usr/bin/python3 -m venv ~/.venvs/awr2243-cocotb-py39
source ~/.venvs/awr2243-cocotb-py39/bin/activate

# 安装依赖
pip install -r tb/cocotb/requirements.txt
```

**依赖文件**：`tb/cocotb/requirements.txt`

**主要依赖**：
- `cocotb` (>=1.8.0)
- `cocotbext-axi` (>=0.1.0)
- `pytest` (>=7.0.0)
- `verilator` (通过系统包管理器安装)

### 1.3 Verilator 安装

**macOS**：
```bash
brew install verilator
```

**Linux (Ubuntu/Debian)**：
```bash
sudo apt-get install verilator
```

**验证**：
```bash
verilator --version  # 应 >= 5.0
```

## 2. 开源模型集成

### 2.1 verilog-axis（AXIS Async FIFO）

**方式 1：Git Submodule**（推荐）

```bash
# 添加 submodule
git submodule add https://github.com/alexforencich/verilog-axis.git model/verilog-axis
git submodule update --init --recursive

# 或一次性克隆（若已有 submodule）
git submodule update --init --recursive
```

**方式 2：手动克隆**

```bash
mkdir -p model
cd model
git clone https://github.com/alexforencich/verilog-axis.git
cd ..
```

**需要的文件**：
- `model/verilog-axis/rtl/axis_async_fifo.v`

**验证**：
```bash
ls model/verilog-axis/rtl/axis_async_fifo.v
```

### 2.2 verilog-axi（AXI SmartConnect）

**方式 1：Git Submodule**

```bash
git submodule add https://github.com/alexforencich/verilog-axi.git model/verilog-axi
git submodule update --init --recursive
```

**方式 2：手动克隆**

```bash
cd model
git clone https://github.com/alexforencich/verilog-axi.git
cd ..
```

**需要的文件**：
- `model/verilog-axi/rtl/axi_crossbar.v`（或 `axi_interconnect.v`）

**验证**：
```bash
ls model/verilog-axi/rtl/axi_crossbar.v
```

### 2.3 LiteDRAM（可选，DDR Model）

**方式 1：Git Submodule**

```bash
git submodule add https://github.com/enjoy-digital/litedram.git model/litedram
git submodule update --init --recursive
```

**方式 2：使用 cocotbext-axi AxiMemory**（推荐，更简单）

无需额外模型，cocotbext-axi 提供 `AxiMemory` 类。

**验证**（若使用 LiteDRAM）：
```bash
ls model/litedram/litedram/core/init.v
```

### 2.4 更新 .gitignore

**添加**（若未添加）：

```bash
# 在 .gitignore 中添加
model/verilog-axis/
model/verilog-axi/
model/litedram/
```

**或**：保留 submodule 引用，不忽略（推荐）。

## 3. RTL 与 IP 集成

### 3.1 RTL 模块检查

**验证现有 RTL 模块**：

```bash
# CSI Packet Extractor
ls rtl/core/csi_packet_extractor.sv

# Fixed Slot Packer
ls rtl/core/fixed_slot_packer.sv

# DDR RingBuffer Controller
ls rtl/core/ddr_ringbuffer_controller.sv

# Package 文件
ls rtl/pkg/*.sv

# Interface 文件
ls rtl/if/*.sv

# Include 文件
ls rtl/include/*.svh
```

### 3.2 Vivado IP 集成（可选）

**若使用 Vivado IP**：

#### 3.2.1 MIPI CSI-2 RX Subsystem

**步骤**：
1. 打开 Vivado
2. IP Catalog → Video & Image Processing → MIPI CSI-2 RX Subsystem
3. 配置参数（lane count, data width, etc.）
4. Generate Output Products → Generate
5. 导出 RTL：
   ```bash
   # 在 Vivado Tcl Console
   write_verilog -mode synth_stub <ip_dir>/mipi_csi2_rx_subsystem_0_stub.v
   ```
6. 复制到项目：
   ```bash
   cp <vivado_ip_dir>/mipi_csi2_rx_subsystem_0_stub.v rtl/ip/
   cp <vivado_ip_dir>/mipi_csi2_rx_subsystem_0.xdc rtl/ip/
   ```

**或**：使用 behavioral mock（推荐，仿真更快）。

#### 3.2.2 AXI SmartConnect

**步骤**：
1. IP Catalog → AXI Infrastructure → AXI SmartConnect
2. 配置：2 masters, 1 slave, 512-bit data width, 64-bit address width
3. Generate → Export RTL
4. 复制到项目：
   ```bash
   cp <vivado_ip_dir>/axi_smartconnect_0_stub.v rtl/ip/
   ```

**或**：使用 verilog-axi `axi_crossbar`（推荐，开源）。

#### 3.2.3 AXIS Data FIFO（若需要同步 FIFO）

**步骤**：
1. IP Catalog → AXI Infrastructure → AXI4-Stream Data FIFO
2. 配置：Async/Async, depth, data width
3. Generate → Export RTL
4. 复制到项目：
   ```bash
   cp <vivado_ip_dir>/axis_data_fifo_0_stub.v rtl/ip/
   ```

**或**：使用 verilog-axis `axis_fifo`（推荐，开源）。

### 3.3 目录结构创建

**创建目录**（若不存在）：

```bash
mkdir -p rtl/ip
mkdir -p tb/cocotb/tests
mkdir -p tb/cocotb/drivers
mkdir -p tb/cocotb/monitors
mkdir -p tb/cocotb/scoreboard
mkdir -p tb/cocotb/model
mkdir -p sim_build
mkdir -p docs/sim_platform
```

## 4. cocotb 平台搭建

### 4.1 目录结构

**创建 cocotb 目录结构**：

```bash
cd tb/cocotb
mkdir -p tests drivers monitors scoreboard model
```

**文件组织**：
- `tests/`：测试用例（`test_*.py`）
- `drivers/`：驱动（`axis_payload_source.py`, `axi_host_master.py`）
- `monitors/`：监控（`axis_monitor.py`）
- `scoreboard/`：Scoreboard（`slot_scoreboard.py`）
- `model/`：参考模型（`slot_refmodel.py`, `ddr_write_model.py`）

### 4.2 conftest.py

**创建** `tb/cocotb/conftest.py`：

```python
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Timer

@cocotb.test()
async def setup_clocks(dut):
    """设置时钟"""
    video_aclk = Clock(dut.video_aclk, 5.0, units="ns")
    axis_clk = Clock(dut.axis_clk, 4.0, units="ns")
    axi_clk = Clock(dut.axi_clk, 4.0, units="ns")
    
    cocotb.start_soon(video_aclk.start())
    cocotb.start_soon(axis_clk.start())
    cocotb.start_soon(axi_clk.start())
    
    await Timer(100, units="ns")
```

### 4.3 驱动与监控（Wave 1 设计）

**参考** `docs/sim_platform/05_cocotb_verification_platform.md`：

**创建驱动**：
- `tb/cocotb/drivers/axis_payload_source.py`：AXIS source 封装
- `tb/cocotb/drivers/axi_host_master.py`：AXI host master 封装

**创建监控**：
- `tb/cocotb/monitors/axis_monitor.py`：AXIS monitor 封装

**创建 Scoreboard**：
- `tb/cocotb/scoreboard/slot_scoreboard.py`：Slot 数据比较

**创建参考模型**：
- `tb/cocotb/model/slot_refmodel.py`：Slot 参考模型
- `tb/cocotb/model/ddr_write_model.py`：DDR 写入参考模型

### 4.4 测试用例（Wave 2 设计）

**参考** `docs/sim_platform/08_recommended_test_cases.md`：

**创建测试文件**：
- `tb/cocotb/tests/test_pipeline.py`：Pipeline 测试
- `tb/cocotb/tests/test_ringbuffer.py`：RingBuffer 测试
- `tb/cocotb/tests/test_cdc.py`：CDC 测试
- `tb/cocotb/tests/test_packer.py`：Packer 测试

**示例**（`test_pipeline.py`）：

```python
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

@cocotb.test()
async def test_top_sanity(dut):
    """Sanity 测试"""
    # 设置时钟
    video_aclk = Clock(dut.video_aclk, 5.0, units="ns")
    axis_clk = Clock(dut.axis_clk, 4.0, units="ns")
    axi_clk = Clock(dut.axi_clk, 4.0, units="ns")
    
    cocotb.start_soon(video_aclk.start())
    cocotb.start_soon(axis_clk.start())
    cocotb.start_soon(axi_clk.start())
    
    # 复位
    dut.sys_rst_n.value = 0
    await Timer(100, units="ns")
    await RisingEdge(dut.axis_clk)
    await RisingEdge(dut.axis_clk)
    dut.sys_rst_n.value = 1
    await Timer(50, units="ns")
    
    # 配置
    dut.cfg_vc_en.value = 1
    dut.cfg_dt_en.value = 1
    dut.cfg_vc.value = 1
    dut.cfg_dt.value = 0x2A
    
    # 发送 packet
    # ... (使用 axis_payload_source)
    
    # 检查
    # ... (使用 scoreboard)
```

## 5. Testbench 集成

### 5.1 创建 top_tb.sv

**参考** `docs/sim_platform/09_top_level_testbench_structure.md`：

**创建** `tb/top_tb.sv`：

```bash
# 复制模板或创建新文件
touch tb/top_tb.sv
```

**内容**：参考 `09_top_level_testbench_structure.md` 第 7 节“最小 SystemVerilog 骨架”。

### 5.2 创建 top_cocotb_top.sv（可选）

**创建** `tb/cocotb/top_cocotb_top.sv`：

```bash
touch tb/cocotb/top_cocotb_top.sv
```

**内容**：参考 `09_top_level_testbench_structure.md` 第 7.2 节。

### 5.3 更新运行脚本

**创建** `tb/cocotb/run_top.py`：

```python
from pathlib import Path
import sys

REPO_ROOT = Path(__file__).resolve().parents[2]
TB_DIR = Path(__file__).resolve().parent

sys.path.insert(0, str(TB_DIR))

from cocotb_tools.runner import get_runner

def build_sources():
    return [
        # RTL
        REPO_ROOT / "rtl/core/csi_packet_extractor.sv",
        REPO_ROOT / "rtl/core/fixed_slot_packer.sv",
        REPO_ROOT / "rtl/core/ddr_ringbuffer_controller.sv",
        REPO_ROOT / "rtl/pkg/*.sv",
        REPO_ROOT / "rtl/include/*.svh",
        REPO_ROOT / "rtl/if/*.sv",
        
        # 开源模型
        REPO_ROOT / "model/verilog-axis/rtl/axis_async_fifo.v",
        REPO_ROOT / "model/verilog-axi/rtl/axi_crossbar.v",
        
        # Testbench
        TB_DIR / "top_cocotb_top.sv",  # 或 top_tb.sv
    ]

def run_regression(testcases=None, waves=False, clean=True):
    runner = get_runner("verilator")
    
    build_dir = REPO_ROOT / "sim_build" / "top_cocotb"
    
    runner.build(
        sources=build_sources(),
        includes=[REPO_ROOT / "rtl/include"],
        hdl_toplevel="top_cocotb_top",
        build_dir=build_dir,
        clean=clean,
        always=True,
        waves=waves,
        timescale=("1ns", "1ps"),
        build_args=[
            "-Wall",
            "-Wno-fatal",
            "-Wno-DECLFILENAME",
            "-Wno-UNUSEDSIGNAL",
            "-Wno-UNDRIVEN",
            "--trace-fst",
        ],
    )
    
    test_dir = TB_DIR / "tests"
    
    runner.test(
        test_module="test_pipeline",  # 或 "top_cocotb"
        hdl_toplevel="top_cocotb_top",
        test_filter=testcases[0] if testcases else None,
        test_dir=test_dir,
        waves=waves,
        extra_env={
            "PYTHONPATH": str(TB_DIR),
        },
    )

if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument("--testcase", action="append", help="Test case name")
    parser.add_argument("--waves", action="store_true", help="Enable waves")
    parser.add_argument("--no-clean", action="store_true", help="Don't clean build")
    args = parser.parse_args()
    
    run_regression(
        testcases=args.testcase,
        waves=args.waves,
        clean=not args.no_clean,
    )
```

**使可执行**：

```bash
chmod +x tb/cocotb/run_top.py
```

## 6. 首次运行

### 6.1 编译检查

**运行编译**（不运行测试）：

```bash
cd tb/cocotb
python run_top.py --testcase test_top_sanity --no-clean
# 仅编译，不运行（若脚本支持）
```

**或手动编译**：

```bash
cd sim_build/top_cocotb
make
```

**检查错误**：
- RTL 语法错误
- 接口不匹配
- 缺少文件

### 6.2 运行 Sanity 测试

**运行单个测试**：

```bash
cd tb/cocotb
python run_top.py --testcase test_top_sanity
```

**预期输出**：
- 编译成功
- 测试运行
- 通过或失败（若失败，检查波形）

### 6.3 调试

**若失败**：

1. **查看波形**：
   ```bash
   python run_top.py --testcase test_top_sanity --waves
   # 打开波形文件（sim_build/top_cocotb/*.fst）
   ```

2. **检查日志**：
   ```bash
   tail -f sim_build/top_cocotb/sim.log
   ```

3. **检查 cocotb 输出**：
   ```bash
   # 查看测试输出
   python run_top.py --testcase test_top_sanity 2>&1 | tee test.log
   ```

## 7. 回归测试

### 7.1 Sanity 回归

**运行 Sanity 测试**：

```bash
cd tb/cocotb
python run_top.py --testcase test_top_sanity
python run_top.py --testcase test_extractor_smoke
python run_top.py --testcase test_packer_smoke
python run_top.py --testcase test_ringbuffer_smoke
```

**或使用 pytest**：

```bash
cd tb/cocotb
pytest tests/test_pipeline.py::test_top_sanity -v
pytest tests/test_pipeline.py::test_extractor_smoke -v
pytest tests/test_packer.py::test_packer_smoke -v
pytest tests/test_ringbuffer.py::test_ringbuffer_smoke -v
```

### 7.2 Full 回归

**运行所有测试**：

```bash
cd tb/cocotb
pytest tests/ -v
```

**或使用脚本**：

```bash
cd tb/cocotb
python run_top.py  # 运行所有测试（若脚本支持）
```

### 7.3 专项回归

**Extractor 专项**：

```bash
pytest tests/test_extractor.py -v
```

**Packer 专项**：

```bash
pytest tests/test_packer.py -v
```

**RingBuffer 专项**：

```bash
pytest tests/test_ringbuffer.py -v
```

**Pipeline 专项**：

```bash
pytest tests/test_pipeline.py -v
```

**CDC 专项**：

```bash
pytest tests/test_cdc.py -v
```

### 7.4 持续集成（可选）

**创建 CI 脚本**（`.github/workflows/sim.yml` 或 `tools/ci_sim.sh`）：

```bash
#!/bin/bash
set -e

source ~/.venvs/awr2243-cocotb-py39/bin/activate

cd tb/cocotb
pytest tests/ -v --tb=short
```

## 8. 文档与交付

### 8.1 文档整理

**检查文档完整性**：

```bash
ls docs/sim_platform/
# 应包含：
# 01_system_simulation_architecture.md
# 02_clock_domain_and_reset_planning.md
# 03_module_list_and_interfaces.md
# 04_directory_structure.md
# 05_cocotb_verification_platform.md
# 06_reference_model_and_scoreboard.md
# 07_per_module_choices_and_vivado_ip.md
# 08_recommended_test_cases.md
# 09_top_level_testbench_structure.md
# 10_engineering_implementation_steps.md
```

### 8.2 README 更新

**更新** `tb/cocotb/README.md`：

```markdown
# Radar Capture Link Simulation Platform

## 快速开始

1. 安装依赖：
   ```bash
   /usr/bin/python3 -m venv ~/.venvs/awr2243-cocotb-py39
   source ~/.venvs/awr2243-cocotb-py39/bin/activate
   pip install -r requirements.txt
   ```

2. 运行 Sanity 测试：
   ```bash
   python run_top.py --testcase test_top_sanity
   ```

3. 运行 Full 回归：
   ```bash
   pytest tests/ -v
   ```

## 文档

详细设计文档见 `docs/sim_platform/`。
```

### 8.3 交付清单

**检查清单**：

- [ ] 所有 RTL 模块存在
- [ ] 所有开源模型集成（submodule 或手动）
- [ ] cocotb 平台搭建完成
- [ ] Testbench 创建完成（`top_tb.sv`）
- [ ] 测试用例实现（至少 Sanity）
- [ ] 参考模型与 Scoreboard 实现
- [ ] 运行脚本创建（`run_top.py`）
- [ ] Sanity 测试通过
- [ ] 文档完整（10 个文档）

## 9. 常见问题

### 9.1 Verilator 编译错误

**问题**：`undefined reference to 'vpi_get_vlog_info'`

**解决**：
```bash
# 检查 Verilator 版本
verilator --version

# 若版本过低，升级
brew upgrade verilator  # macOS
sudo apt-get upgrade verilator  # Linux
```

### 9.2 cocotb 导入错误

**问题**：`ModuleNotFoundError: No module named 'cocotb'`

**解决**：
```bash
# 激活虚拟环境
source ~/.venvs/awr2243-cocotb-py39/bin/activate

# 重新安装
pip install -r tb/cocotb/requirements.txt
```

### 9.3 接口不匹配

**问题**：`Port width mismatch`

**解决**：
1. 检查 `top_tb.sv` 中的信号位宽
2. 检查 RTL 模块参数
3. 检查 `axis_stream_if` / `axi4_mm_if` 定义

### 9.4 时钟域错误

**问题**：CDC 时序错误

**解决**：
1. 检查时钟生成（`video_aclk` 200MHz, `axis_clk`/`axi_clk` 250MHz）
2. 检查复位同步释放
3. 检查 Async FIFO 实例化

## 10. 下一步

**完成 Wave 2 后**：

1. **Wave 3（集成与最终验证）**：
   - 运行所有测试用例
   - 修复发现的问题
   - 文档最终整理

2. **实际硬件验证**（可选）：
   - 综合到 FPGA
   - 时序约束
   - 硬件测试

3. **性能优化**（可选）：
   - 吞吐量分析
   - 延迟分析
   - 资源使用分析
