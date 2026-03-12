# cocotb 验证平台结构

## 1. cocotb 目录结构

### 1.1 推荐目录布局

```
tb/cocotb/
├── conftest.py                  # pytest 配置，DUT top，公共 fixtures
├── requirements.txt             # Python 依赖（cocotb, pytest, cocotbext-axi）
├── tests/                       # 测试用例（pytest 自动发现）
│   ├── test_sanity.py          # 基础 sanity 测试
│   ├── test_pipeline.py        # 端到端 pipeline 测试
│   ├── test_ringbuffer.py      # RingBuffer 专项测试
│   └── test_cdc.py             # CDC 专项测试
├── drivers/                     # cocotb 驱动
│   ├── axis_payload_source.py  # AXIS payload source（基于 cocotbext-axi AxiStreamSource）
│   ├── axi_host_master.py      # AXI host master（基于 cocotbext-axi AxiMaster）
│   └── clk_rst.py              # 时钟/复位驱动
├── monitors/                    # cocotb 监控
│   └── axis_monitor.py         # AXIS monitor（基于 cocotbext-axi AxiStreamMonitor）
├── scoreboard/                  # Scoreboard
│   └── slot_scoreboard.py      # Slot 数据比较 scoreboard
├── model/                       # Reference model
│   └── slot_refmodel.py        # Slot 格式参考模型（基于 awr_payload_model.py）
├── utils/                       # 工具函数（可选）
│   └── helpers.py               # 通用工具函数
├── *_cocotb_top.sv             # cocotb 顶层包装（每个测试目标一个）
│   ├── top_cocotb_top.sv       # 完整 pipeline 顶层
│   ├── extractor_cocotb_top.sv # Extractor 单独测试顶层
│   └── packer_cocotb_top.sv    # Packer 单独测试顶层
└── run_*.py                     # 测试运行脚本（兼容 tools/build_and_verify.sh）
    ├── run_pipeline.py
    ├── run_csi_packet_extractor.py
    └── run_fixed_slot_packer.py
```

**注意**：现有仓库已有部分结构（`tb/cocotb/` 下已有 `run_*.py`、`*_cocotb_top.sv`、`test_*.py`），本设计**兼容现有结构**，新增 `drivers/`、`monitors/`、`scoreboard/`、`model/` 目录以组织代码。

## 2. conftest.py 职责

### 2.1 仿真器选择

**推荐**：使用 `cocotb_tools.runner`（cocotb 2.0+），支持 Verilator、Icarus Verilog、Questa 等。

**示例**（在 `run_*.py` 中，而非 `conftest.py`）：

```python
from cocotb_tools.runner import get_runner

runner = get_runner("verilator")  # 或 "icarus", "questa"
```

**conftest.py 职责**：定义公共 fixtures，如 DUT handle、时钟对象、复位函数。

### 2.2 DUT Top 路径

**方式 1**：在 `run_*.py` 中指定（推荐，兼容现有结构）：

```python
TOPLEVEL = "pipeline_cocotb_top"
TEST_MODULE = "pipeline_cocotb"

runner.build(
    sources=build_sources(),
    hdl_toplevel=TOPLEVEL,
    build_dir=build_dir,
    # ...
)

runner.test(
    test_module=TEST_MODULE,
    hdl_toplevel=TOPLEVEL,
    # ...
)
```

**方式 2**：在 `conftest.py` 中定义 fixture（若需要跨测试共享）：

```python
import cocotb
from cocotb.handle import SimHandleBase

@pytest.fixture(scope="module")
def dut():
    """返回 DUT handle"""
    # cocotb 会自动注入，这里只是类型提示
    return cocotb.top
```

### 2.3 时钟/复位驱动

**conftest.py 示例**：

```python
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Timer, RisingEdge

@pytest.fixture(scope="module")
async def clocks(dut):
    """启动所有时钟"""
    video_aclk = Clock(dut.video_aclk, 5.0, units="ns")  # 200MHz
    axis_clk = Clock(dut.axis_clk, 4.0, units="ns")      # 250MHz
    axi_clk = Clock(dut.axi_clk, 4.0, units="ns")       # 250MHz
    
    cocotb.start_soon(video_aclk.start())
    cocotb.start_soon(axis_clk.start())
    cocotb.start_soon(axi_clk.start())
    
    return {"video_aclk": video_aclk, "axis_clk": axis_clk, "axi_clk": axi_clk}

@pytest.fixture(scope="module")
async def reset(dut):
    """复位 DUT"""
    dut.sys_rst_n.value = 0
    await Timer(100, units="ns")
    await RisingEdge(dut.axis_clk)
    await RisingEdge(dut.axis_clk)
    dut.sys_rst_n.value = 1
    await Timer(50, units="ns")
```

**或**：在 `drivers/clk_rst.py` 中定义函数：

```python
async def reset_dut(dut, duration_ns=100):
    """复位 DUT"""
    dut.sys_rst_n.value = 0
    await Timer(duration_ns, units="ns")
    await RisingEdge(dut.axis_clk)
    await RisingEdge(dut.axis_clk)
    dut.sys_rst_n.value = 1
    await Timer(50, units="ns")
```

### 2.4 参数化

**conftest.py** 可定义参数化 fixtures（如不同数据位宽、FIFO 深度）：

```python
@pytest.fixture(params=[32, 64, 256])
def axis_data_width(request):
    """参数化 AXIS 数据位宽"""
    return request.param
```

## 3. cocotbext-axi 用法

### 3.1 AXIS payload source

**位置**：`tb/cocotb/drivers/axis_payload_source.py`

**实现**：

```python
from cocotbext.axi import AxiStreamSource

class AxisPayloadSource:
    def __init__(self, dut_axis_handle, clock, reset=None):
        self.source = AxiStreamSource(
            dut_axis_handle,
            clock,
            reset
        )
    
    async def send_packet(self, payload_bytes, tuser=0):
        """发送一个 CSI-2 packet"""
        await self.source.write(payload_bytes, tuser=tuser)
    
    async def send_awr_frame(self, packets):
        """发送完整的 AWR frame（FS/LS/Long packets）"""
        for packet in packets:
            await self.send_packet(packet.raw, tuser=packet.tuser)
```

**使用示例**（在测试中）：

```python
from drivers.axis_payload_source import AxisPayloadSource

source = AxisPayloadSource(dut.s_axis, dut.video_aclk, dut.video_rst_n)
await source.send_awr_frame(awr_packets)
```

### 3.2 AXIS monitor

**位置**：`tb/cocotb/monitors/axis_monitor.py`

**实现**：

```python
from cocotbext.axi import AxiStreamMonitor

class AxisMonitor:
    def __init__(self, dut_axis_handle, clock, reset=None):
        self.monitor = AxiStreamMonitor(
            dut_axis_handle,
            clock,
            reset
        )
        self.received_data = []
    
    async def capture(self):
        """持续捕获 AXIS 数据"""
        while True:
            data = await self.monitor.read()
            self.received_data.append(data)
```

**使用示例**：

```python
from monitors.axis_monitor import AxisMonitor

monitor = AxisMonitor(dut.m_axis, dut.axis_clk, dut.axis_rst_n)
cocotb.start_soon(monitor.capture())
# ... 运行测试 ...
# 检查 monitor.received_data
```

### 3.3 AXI host master

**位置**：`tb/cocotb/drivers/axi_host_master.py`

**实现**：

```python
from cocotbext.axi import AxiMaster

class AxiHostMaster:
    def __init__(self, dut_axi_handle, clock, reset=None):
        self.master = AxiMaster(
            dut_axi_handle,
            clock,
            reset
        )
    
    async def read_slot(self, addr, length):
        """从 DDR 读取 slot 数据"""
        return await self.master.read(addr, length)
    
    async def burst_read(self, addr, burst_len, burst_size=6):  # 6 = 64 bytes
        """AXI burst read"""
        return await self.master.read(addr, burst_len * burst_size)
```

**使用示例**：

```python
from drivers.axi_host_master import AxiHostMaster

host = AxiHostMaster(dut.s01_axi, dut.axi_clk, dut.axi_rst_n)
slot_data = await host.read_slot(slot_addr, slot_bytes)
```

### 3.4 AXI memory（DDR Model）

**若使用 cocotbext-axi `AxiMemory`**（纯 Python，无需 RTL）：

```python
from cocotbext.axi import AxiMemory

# 在 testbench 中绑定到 DDR Model 的 AXI 接口
ddr_memory = AxiMemory(dut.m00_axi, dut.axi_clk, dut.axi_rst_n, size=256*1024*1024)  # 256MB
```

**若使用 LiteDRAM**：需实例化 RTL 模块，cocotb 仅监控/驱动信号。

## 4. 测试发现与回归入口

### 4.1 pytest 测试发现

**pytest 自动发现规则**：
- 文件名：`test_*.py` 或 `*_test.py`
- 函数名：`test_*`
- 类名：`Test*`（类内方法需 `test_*`）

**示例**（`tb/cocotb/tests/test_pipeline.py`）：

```python
import cocotb
from cocotb.triggers import Timer

@cocotb.test()
async def test_pipeline_smoke_basic(dut):
    """基础 pipeline smoke 测试"""
    # 复位
    await reset_dut(dut)
    # 发送数据
    # 检查结果
    pass

@cocotb.test()
async def test_pipeline_invalid_slot_roundtrip(dut):
    """无效 slot 往返测试"""
    pass
```

### 4.2 回归入口

**方式 1**：使用 `run_*.py`（兼容现有 `tools/build_and_verify.sh`）：

```python
# tb/cocotb/run_pipeline.py
def run_regression(testcases: list[str], waves: bool, clean: bool):
    runner = get_runner("verilator")
    runner.build(...)
    runner.test(
        test_module="pipeline_cocotb",
        test_filter=".*(" + "|".join(testcases) + ")$",
        ...
    )
```

**方式 2**：直接使用 pytest（若需要更灵活的过滤）：

```bash
cd tb/cocotb
pytest tests/test_pipeline.py::test_pipeline_smoke_basic -v
```

**方式 3**：通过 `tools/build_and_verify.sh`（现有入口）：

```bash
tools/build_and_verify.sh --target pipeline
tools/build_and_verify.sh --target pipeline --testcase pipeline_smoke_basic
```

### 4.3 测试过滤

**pytest marker**（可选）：

```python
import pytest

@pytest.mark.sanity
@cocotb.test()
async def test_pipeline_smoke_basic(dut):
    pass

@pytest.mark.full
@cocotb.test()
async def test_pipeline_stress(dut):
    pass
```

**运行**：

```bash
pytest -m sanity  # 只跑 sanity 标记的测试
pytest -m "not full"  # 排除 full 标记的测试
```

## 5. 最小骨架示例

### 5.1 conftest.py（可选，若需要公共 fixtures）

```python
# tb/cocotb/conftest.py
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Timer, RisingEdge

@pytest.fixture(scope="module")
async def clocks(dut):
    """启动所有时钟"""
    video_aclk = Clock(dut.video_aclk, 5.0, units="ns")
    axis_clk = Clock(dut.axis_clk, 4.0, units="ns")
    axi_clk = Clock(dut.axi_clk, 4.0, units="ns")
    
    cocotb.start_soon(video_aclk.start())
    cocotb.start_soon(axis_clk.start())
    cocotb.start_soon(axi_clk.start())
    
    return {"video_aclk": video_aclk, "axis_clk": axis_clk, "axi_clk": axi_clk}

@pytest.fixture(scope="module")
async def reset(dut):
    """复位 DUT"""
    dut.sys_rst_n.value = 0
    await Timer(100, units="ns")
    await RisingEdge(dut.axis_clk)
    await RisingEdge(dut.axis_clk)
    dut.sys_rst_n.value = 1
    await Timer(50, units="ns")
```

### 5.2 tests/test_sanity.py（最小测试示例）

```python
# tb/cocotb/tests/test_sanity.py
import cocotb
from cocotb.triggers import Timer
from drivers.clk_rst import reset_dut
from drivers.axis_payload_source import AxisPayloadSource

@cocotb.test()
async def test_top_sanity(dut):
    """顶层 sanity 测试"""
    # 复位
    await reset_dut(dut)
    
    # 创建驱动
    source = AxisPayloadSource(dut.s_axis, dut.video_aclk, dut.video_rst_n)
    
    # 发送一个简单 packet
    await source.send_packet(b"\x00" * 100)
    
    # 等待处理
    await Timer(1000, units="ns")
    
    # 检查状态（示例）
    assert dut.pkt_done_o.value == 1
```

## 6. 与现有结构的兼容

**现有结构**（`tb/cocotb/`）：
- `run_*.py`：测试运行脚本（保留）
- `*_cocotb_top.sv`：cocotb 顶层（保留）
- `*_cocotb.py`：测试代码（保留，可迁移到 `tests/` 或保留）

**新增结构**：
- `drivers/`：驱动封装（新增）
- `monitors/`：监控封装（新增）
- `scoreboard/`：Scoreboard（新增）
- `model/`：Reference model（新增，可复用现有 `awr_payload_model.py`）
- `tests/`：测试用例（新增，或与现有 `*_cocotb.py` 合并）
- `conftest.py`：公共 fixtures（新增，可选）

**迁移建议**：
- 现有 `*_cocotb.py` 可保留，或逐步迁移到 `tests/test_*.py`
- 现有 `awr_payload_model.py` 可移动到 `model/slot_refmodel.py` 或保留并引用
- `run_*.py` 保持不变，继续作为回归入口

## 7. 依赖管理

**requirements.txt**（`tb/cocotb/requirements.txt`）：

```
cocotb>=2.0,<2.1
pytest>=8.0,<9.0
cocotbext-axi>=0.1.0
```

**安装**：

```bash
python3 -m venv .venv
source .venv/bin/activate  # 或 .venv\Scripts\activate (Windows)
pip install -r tb/cocotb/requirements.txt
```

**或使用现有虚拟环境**（如 `.venv313/`）：

```bash
.venv313/bin/pip install cocotbext-axi
```
