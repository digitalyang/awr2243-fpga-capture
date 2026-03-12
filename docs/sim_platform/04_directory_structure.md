# 目录结构与用途

## 1. 推荐工程目录树

```
awr2243-fpga-capture/
├── rtl/                          # RTL 源代码
│   ├── core/                    # 核心 RTL 模块
│   │   ├── csi_packet_extractor.sv
│   │   ├── fixed_slot_packer.sv
│   │   └── ddr_ringbuffer_controller.sv
│   ├── pkg/                     # SystemVerilog 包
│   │   ├── csi_packet_pkg.sv
│   │   ├── slot_packer_pkg.sv
│   │   └── ddr_ringbuffer_pkg.sv
│   ├── include/                 # 宏定义
│   │   ├── csi_packet_extractor_macros.svh
│   │   ├── slot_packer_macros.svh
│   │   └── ddr_ringbuffer_macros.svh
│   ├── if/                      # SystemVerilog 接口
│   │   ├── axis_stream_if.sv
│   │   ├── axi4_mm_if.sv
│   │   └── axi4_lite_if.sv
│   └── generated/               # 自动生成文件（CSR 等）
│       └── ddr_ringbuffer_controller_csr.sv
│
├── tb/                          # Testbench
│   ├── top_tb.sv                # 顶层 testbench
│   ├── cocotb/                  # cocotb 测试平台
│   │   ├── conftest.py          # pytest 配置，DUT top，公共 fixtures
│   │   ├── tests/               # 测试用例
│   │   │   ├── test_sanity.py
│   │   │   ├── test_pipeline.py
│   │   │   └── test_ringbuffer.py
│   │   ├── drivers/             # cocotb 驱动
│   │   │   ├── axis_payload_source.py
│   │   │   ├── axi_host_master.py
│   │   │   └── clk_rst.py
│   │   ├── monitors/            # cocotb 监控
│   │   │   └── axis_monitor.py
│   │   ├── scoreboard/          # Scoreboard
│   │   │   └── slot_scoreboard.py
│   │   ├── model/               # Reference model
│   │   │   └── slot_refmodel.py
│   │   ├── *_cocotb_top.sv      # cocotb 顶层包装（每个测试一个）
│   │   └── run_*.py             # 测试运行脚本（兼容现有结构）
│   └── uvm/                     # UVM testbench（可选，现有）
│       └── ...
│
├── sim/                         # 仿真脚本与构建产物
│   ├── Makefile                 # Verilator 编译与运行入口
│   ├── run_sim.sh               # 仿真启动脚本（可选）
│   └── sim_build/               # Verilator 构建目录
│       ├── Vtop_tb              # 编译后的可执行文件
│       └── regression_logs/     # 回归测试日志（由 build_and_verify.sh 生成）
│           └── <timestamp>_build_verify/
│               ├── csi.log
│               ├── fixed.log
│               ├── ddr.log
│               └── pipeline.log
│
├── model/                       # 外部开源模型
│   ├── verilog-axi/             # verilog-axi（git submodule 或 clone）
│   │   ├── rtl/
│   │   │   └── axi_crossbar.v
│   │   └── ...
│   ├── verilog-axis/            # verilog-axis（git submodule 或 clone）
│   │   ├── rtl/
│   │   │   └── axis_async_fifo.v
│   │   └── ...
│   └── litedram/                # LiteDRAM（git submodule 或 clone，可选）
│       └── ...
│
├── cocotb/                      # cocotb 配置与工具（可选，与 tb/cocotb 合并或分离）
│   ├── conftest.py              # 全局 conftest（若与 tb/cocotb/conftest.py 分离）
│   └── utils/                   # 工具函数
│       └── helpers.py
│
├── docs/                        # 文档
│   ├── sim_platform/            # 仿真平台设计文档
│   │   ├── 01_system_simulation_architecture.md
│   │   ├── 02_clock_domain_and_reset_planning.md
│   │   ├── 03_module_list_and_interfaces.md
│   │   ├── 04_directory_structure.md
│   │   ├── 05_cocotb_verification_platform.md
│   │   ├── 06_reference_model_and_scoreboard.md
│   │   ├── 07_per_module_choices_and_vivado_ip.md
│   │   ├── 08_recommended_test_cases.md
│   │   ├── 09_top_level_testbench_structure.md
│   │   └── 10_engineering_implementation_steps.md
│   └── README.md                # 项目总览
│
├── tools/                       # 工具脚本
│   ├── build_and_verify.sh      # 构建与回归入口（现有）
│   └── cursor_parallel/         # Cursor 并行工作流脚本
│       ├── create_worktrees.sh
│       ├── launch_wave.sh
│       └── run_parallel_agents.sh
│
├── .venv/ 或 .venv313/          # Python 虚拟环境（cocotb 依赖）
│
└── CURSOR_PARALLEL_PROMPT.md    # 当前 Wave 的 Parallel Agent prompt（由脚本生成）
```

## 2. 各目录用途说明

### 2.1 `rtl/`

**用途**：存放项目 RTL 源代码。

**内容**：
- **`rtl/core/`**：核心 RTL 模块（DUT），如 `csi_packet_extractor.sv`、`fixed_slot_packer.sv`、`ddr_ringbuffer_controller.sv`
- **`rtl/pkg/`**：SystemVerilog 包（package），定义类型、常量、函数
- **`rtl/include/`**：宏定义头文件（`.svh`），如 `slot_packer_macros.svh`
- **`rtl/if/`**：SystemVerilog 接口定义，如 `axis_stream_if.sv`、`axi4_mm_if.sv`
- **`rtl/generated/`**：自动生成文件（如 PeakRDL 生成的 CSR），不应手动修改

**命名约定**：
- 模块文件：`<module_name>.sv`
- 包文件：`<package_name>_pkg.sv`
- 宏文件：`<module_name>_macros.svh`
- 接口文件：`<interface_name>_if.sv`

### 2.2 `tb/`

**用途**：存放 testbench 代码（SystemVerilog 与 cocotb）。

**内容**：
- **`tb/top_tb.sv`**：顶层 testbench，实例化 DUT、时钟/复位生成、连接所有模块
- **`tb/cocotb/`**：cocotb 测试平台
  - **`conftest.py`**：pytest 配置，DUT top 路径，公共 fixtures（时钟、复位、DUT handle）
  - **`tests/`**：测试用例（`test_*.py`），使用 pytest 发现
  - **`drivers/`**：cocotb 驱动（AXIS source、AXI master、时钟/复位）
  - **`monitors/`**：cocotb 监控（AXIS monitor）
  - **`scoreboard/`**：Scoreboard 实现
  - **`model/`**：Reference model（Python）
  - **`*_cocotb_top.sv`**：cocotb 顶层包装，每个测试一个（若需要独立顶层）
  - **`run_*.py`**：测试运行脚本（兼容现有 `tools/build_and_verify.sh` 调用）
- **`tb/uvm/`**：UVM testbench（可选，现有结构保留）

**命名约定**：
- Testbench：`<dut_name>_tb.sv` 或 `top_tb.sv`
- cocotb 测试：`test_<feature>.py`
- cocotb 驱动：`<protocol>_driver.py` 或 `<component>_driver.py`
- cocotb 监控：`<protocol>_monitor.py`
- cocotb 顶层：`<test_name>_cocotb_top.sv`

### 2.3 `sim/`

**用途**：仿真脚本与构建产物。

**内容**：
- **`sim/Makefile`**：Verilator 编译与运行入口，定义编译选项、文件列表、运行目标
- **`sim/run_sim.sh`**：仿真启动脚本（可选，封装 Makefile 调用）
- **`sim/sim_build/`**：Verilator 构建目录
  - **`Vtop_tb`**：编译后的可执行文件
  - **`regression_logs/`**：回归测试日志（由 `tools/build_and_verify.sh` 生成）

**命名约定**：
- Makefile 目标：`build`（编译）、`run`（运行）、`clean`（清理）
- 日志文件：`<target>.log`（如 `csi.log`、`pipeline.log`）

### 2.4 `model/`

**用途**：存放外部开源模型（git submodule 或手动 clone）。

**内容**：
- **`model/verilog-axi/`**：verilog-axi 仓库（AXI crossbar/interconnect）
- **`model/verilog-axis/`**：verilog-axis 仓库（AXIS FIFO、async FIFO）
- **`model/litedram/`**：LiteDRAM 仓库（DDR behavioral model，可选）

**集成方式**：
- **Git submodule**（推荐）：`git submodule add <url> model/verilog-axi`
- **手动 clone**：`git clone <url> model/verilog-axi`
- **符号链接**：若模型在其他位置，可创建符号链接

**文件列表**：
- 在 `sim/Makefile` 或 `tb/cocotb/*.f` 中引用 `model/verilog-axi/rtl/*.v`、`model/verilog-axis/rtl/*.v`

### 2.5 `cocotb/`

**用途**：cocotb 全局配置与工具（可选，若与 `tb/cocotb/` 分离）。

**内容**：
- **`cocotb/conftest.py`**：全局 conftest（若与 `tb/cocotb/conftest.py` 分离）
- **`cocotb/utils/`**：工具函数（如 helpers、common utilities）

**注意**：若 `tb/cocotb/conftest.py` 已足够，可省略此目录，所有 cocotb 代码放在 `tb/cocotb/`。

### 2.6 `docs/`

**用途**：项目文档。

**内容**：
- **`docs/sim_platform/`**：仿真平台设计文档（Wave 0-3 交付物）
- **`docs/README.md`**：项目总览（现有）

**命名约定**：
- 设计文档：`<序号>_<topic>.md`（如 `01_system_simulation_architecture.md`）
- 总览：`README.md` 或 `00_README.md`

### 2.7 `tools/`

**用途**：工具脚本。

**内容**：
- **`tools/build_and_verify.sh`**：构建与回归入口（现有）
- **`tools/cursor_parallel/`**：Cursor 并行工作流脚本

### 2.8 其他

- **`.venv/` 或 `.venv313/`**：Python 虚拟环境，安装 cocotb、cocotbext-axi、pytest
- **`CURSOR_PARALLEL_PROMPT.md`**：当前 Wave 的 Parallel Agent prompt（由 `tools/cursor_parallel/run_parallel_agents.sh` 生成）

## 3. 文件列表（Filelist）组织

### 3.1 Verilator 编译文件列表

**推荐位置**：`sim/top_tb.f` 或 `sim/Makefile` 内联

**内容**：
```
# RTL
rtl/core/csi_packet_extractor.sv
rtl/core/fixed_slot_packer.sv
rtl/core/ddr_ringbuffer_controller.sv
rtl/pkg/*.sv
rtl/include/*.svh
rtl/if/*.sv

# Models
model/verilog-axi/rtl/axi_crossbar.v
model/verilog-axis/rtl/axis_async_fifo.v

# Testbench
tb/top_tb.sv
```

### 3.2 cocotb 文件列表

**推荐位置**：`tb/cocotb/top_tb.f` 或 `tb/cocotb/Makefile`

**内容**：与 Verilator 相同，但需包含 cocotb 顶层（`tb/cocotb/*_cocotb_top.sv`）。

## 4. 与现有仓库结构的兼容

本目录结构**兼容现有仓库**：

- **保留**：`rtl/`、`tb/cocotb/`、`tb/uvm/`、`tools/build_and_verify.sh` 等现有结构
- **新增**：`docs/sim_platform/`、`model/`（若不存在）、`sim/`（若不存在）
- **可选合并**：`cocotb/` 可与 `tb/cocotb/` 合并

## 5. Git 管理建议

**应提交**：
- `rtl/`、`tb/`、`docs/`、`tools/`、`sim/Makefile`（不含构建产物）

**应忽略**（`.gitignore`）：
- `sim/sim_build/`（构建产物）
- `.venv/`、`.venv313/`（Python 虚拟环境）
- `model/verilog-axi/`、`model/verilog-axis/`、`model/litedram/`（若为 git submodule，submodule 本身需提交，但内容由 submodule 管理）

**Git submodule 管理**：
```bash
git submodule add https://github.com/alexforencich/verilog-axi.git model/verilog-axi
git submodule add https://github.com/alexforencich/verilog-axis.git model/verilog-axis
git submodule add https://github.com/enjoy-digital/litedram.git model/litedram  # 可选
```
