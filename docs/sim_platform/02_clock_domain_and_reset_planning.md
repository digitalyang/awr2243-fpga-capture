# 时钟域与 Reset 规划

## 1. 时钟域定义

### 1.1 时钟域列表

| 时钟域名称 | 频率 | 周期 | 来源 | 用途 |
|-----------|------|------|------|------|
| `video_aclk` | 200MHz | 5.0ns | Testbench generator (cocotb `Clock`) | CSI RX Subsystem，AXIS payload source 输入侧 |
| `axis_clk` | 250MHz | 4.0ns | Testbench generator (cocotb `Clock`) | CSI Packet Extractor，Fixed Slot Packer，AXIS Async FIFO 输出侧 |
| `axi_clk` | 250MHz | 4.0ns | Testbench generator（与 `axis_clk` 同源或同步） | DDR RingBuffer Controller，AXI SmartConnect，DDR Model |

**注意**：`axis_clk` 与 `axi_clk` 均为 250MHz，在仿真中可共用同一时钟源，或保持同步（同源分频）。实际硬件中若需独立时钟域，可在 testbench 中分别生成。

### 1.2 时钟生成方式

**推荐实现**（在 `tb/top_tb.sv` 或 cocotb `conftest.py` 中）：

```systemverilog
// Option 1: SystemVerilog initial block (in top_tb.sv)
logic video_aclk, axis_clk, axi_clk;

initial begin
    video_aclk = 0;
    forever #2.5ns video_aclk = ~video_aclk;  // 200MHz: period = 5ns
end

initial begin
    axis_clk = 0;
    forever #2.0ns axis_clk = ~axis_clk;      // 250MHz: period = 4ns
end

assign axi_clk = axis_clk;  // 同源，或独立生成
```

```python
# Option 2: cocotb Clock (in cocotb/conftest.py or cocotb/drivers/clk_rst.py)
from cocotb.clock import Clock

@cocotb.test()
async def test_top(dut):
    # 创建时钟对象
    video_aclk = Clock(dut.video_aclk, 5.0, units="ns")  # 200MHz
    axis_clk = Clock(dut.axis_clk, 4.0, units="ns")      # 250MHz
    axi_clk = Clock(dut.axi_clk, 4.0, units="ns")         # 250MHz
    
    # 启动时钟
    cocotb.start_soon(video_aclk.start())
    cocotb.start_soon(axis_clk.start())
    cocotb.start_soon(axi_clk.start())
```

**推荐**：使用 cocotb `Clock`，便于测试中动态控制时钟（暂停、频率切换等）。

## 2. Reset 策略

### 2.1 Reset 类型与极性

| Reset 信号 | 极性 | 类型 | 作用域 | 说明 |
|-----------|------|------|--------|------|
| `sys_rst_n` | 低有效（active-low） | 异步复位，同步释放 | 全局 | 系统级复位，释放时同步到各时钟域 |
| `video_rst_n` | 低有效 | 异步复位，同步释放 | video_aclk 域 | CSI RX Subsystem 专用复位（可选） |
| `axis_rst_n` | 低有效 | 异步复位，同步释放 | axis_clk 域 | Extractor, Packer, AXIS Async FIFO 输出侧 |
| `axi_rst_n` | 低有效 | 异步复位，同步释放 | axi_clk 域 | RingBuffer Controller, SmartConnect, DDR Model |

**复位策略**：
- **全局复位**：`sys_rst_n` 驱动所有模块，释放时分别同步到各时钟域
- **按域复位**（可选）：`video_rst_n`, `axis_rst_n`, `axi_rst_n` 独立控制，便于分域验证

### 2.2 Reset 时序

**复位断言**：异步，立即生效（不依赖时钟）

**复位释放**：同步释放（synchronized deassertion），确保释放边沿对齐到时钟上升沿，避免亚稳态

**复位持续时间**：建议至少 10 个对应时钟周期（例如 axis_rst_n 至少保持 10 × 4ns = 40ns）

**实现示例**（`tb/top_tb.sv`）：

```systemverilog
logic sys_rst_n, axis_rst_n, axi_rst_n;

// 复位生成（异步断言，同步释放）
always_ff @(posedge axis_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        axis_rst_n <= 1'b0;
    end else begin
        axis_rst_n <= 1'b1;  // 同步释放
    end
end

// 类似地处理 axi_rst_n
always_ff @(posedge axi_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        axi_rst_n <= 1'b0;
    end else begin
        axi_rst_n <= 1'b1;
    end
end
```

**cocotb 复位驱动**（`cocotb/drivers/clk_rst.py`）：

```python
async def reset_dut(dut, duration_ns=100):
    """异步断言，同步释放复位"""
    dut.sys_rst_n.value = 0
    await Timer(duration_ns, units="ns")
    # 等待时钟边沿后释放
    await RisingEdge(dut.axis_clk)
    await RisingEdge(dut.axis_clk)
    dut.sys_rst_n.value = 1
    await Timer(10, units="ns")  # 稳定时间
```

## 3. CDC（跨时钟域）处理

### 3.1 CDC 边界

**唯一 CDC 边界**：**200MHz → 250MHz**

- **位置**：CSI RX Subsystem（200MHz）→ AXIS Async FIFO → CSI Packet Extractor（250MHz）
- **处理方式**：使用 **verilog-axis `axis_async_fifo`** 模块，内置双时钟 FIFO 与握手逻辑

### 3.2 AXIS Async FIFO 配置

| 参数 | 值 | 说明 |
|------|-----|------|
| `DEPTH` | 512 或更大 | FIFO 深度，需覆盖 CSI packet 最大长度 |
| `DATA_WIDTH` | 32 或 64 | 与 CSI RX Subsystem AXIS 数据位宽一致 |
| `KEEP_ENABLE` | 1 | 支持 TLAST/TKEEP |
| `ID_ENABLE` | 0 | 通常不需要 TID |
| `DEST_ENABLE` | 0 | 通常不需要 TDEST |
| `USER_ENABLE` | 1 | 保留 TUSER（可能包含 packet 元数据） |

**实例化示例**（在 testbench 中）：

```systemverilog
axis_async_fifo #(
    .DEPTH(512),
    .DATA_WIDTH(32),
    .KEEP_ENABLE(1),
    .USER_ENABLE(1)
) u_axis_async_fifo (
    .s_clk(video_aclk),
    .s_rst(~video_rst_n),
    .s_axis_tdata(csi_rx_axis_tdata),
    .s_axis_tvalid(csi_rx_axis_tvalid),
    .s_axis_tready(csi_rx_axis_tready),
    .s_axis_tlast(csi_rx_axis_tlast),
    .s_axis_tkeep(csi_rx_axis_tkeep),
    .s_axis_tuser(csi_rx_axis_tuser),
    
    .m_clk(axis_clk),
    .m_rst(~axis_rst_n),
    .m_axis_tdata(extractor_axis_tdata),
    .m_axis_tvalid(extractor_axis_tvalid),
    .m_axis_tready(extractor_axis_tready),
    .m_axis_tlast(extractor_axis_tlast),
    .m_axis_tkeep(extractor_axis_tkeep),
    .m_axis_tuser(extractor_axis_tuser)
);
```

### 3.3 其他时钟域

- **250MHz 域内**：Extractor → Packer → RingBuffer Controller → SmartConnect → DDR Model，均为同步连接，无 CDC
- **AXI SmartConnect**：若使用 verilog-axi `axi_crossbar`，内部处理多 master 时钟域同步（若需要）

## 4. Testbench 时钟/复位驱动

### 4.1 顶层 Testbench 结构

```systemverilog
module top_tb;
    // 时钟信号
    logic video_aclk, axis_clk, axi_clk;
    
    // 复位信号
    logic sys_rst_n, axis_rst_n, axi_rst_n;
    
    // 时钟生成（由 cocotb 或 SV initial 驱动）
    // ... (见上文)
    
    // 复位生成（异步断言，同步释放）
    // ... (见上文)
    
    // DUT 实例化
    // ...
endmodule
```

### 4.2 cocotb 集成

**conftest.py**：

```python
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import Timer

@cocotb.test()
async def test_top(dut):
    # 创建时钟
    video_aclk = Clock(dut.video_aclk, 5.0, units="ns")
    axis_clk = Clock(dut.axis_clk, 4.0, units="ns")
    axi_clk = Clock(dut.axi_clk, 4.0, units="ns")
    
    # 启动时钟
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
    
    # 开始测试
    # ...
```

## 5. 时钟/复位验证要点

1. **时钟频率**：验证 video_aclk = 200MHz，axis_clk/axi_clk = 250MHz（通过周期测量）
2. **复位释放**：验证复位释放边沿对齐到时钟上升沿
3. **CDC 功能**：验证 AXIS Async FIFO 正确传递数据，无丢失或重复
4. **复位后状态**：验证所有模块复位后进入 IDLE/初始状态
5. **时钟门控**（若需要）：验证时钟暂停/恢复不影响数据完整性
