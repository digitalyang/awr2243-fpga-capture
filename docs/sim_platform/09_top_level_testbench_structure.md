# 顶层 Testbench 结构

## 1. Testbench 层次结构

### 1.1 顶层模块：top_tb.sv

**位置**：`tb/top_tb.sv`

**职责**：
- 实例化所有模块（DUT、模型、IP）
- 生成时钟/复位
- 连接所有信号
- 提供 cocotb 绑定点（通过 `cocotb.handle`）

**层次结构**：

```
top_tb.sv
├── Clock/Reset Generator (SV initial blocks 或 cocotb-driven)
├── AXIS payload source (cocotb handle binding)
├── CSI RX Subsystem (Vivado IP 或 Behavioral mock)
├── AXIS Async FIFO (verilog-axis)
├── CSI Packet Extractor (RTL DUT)
├── Fixed Slot Packer (RTL DUT)
├── DDR RingBuffer Controller (RTL DUT)
├── AXI SmartConnect (verilog-axi 或 Vivado IP)
├── DDR Model (LiteDRAM 或 cocotbext-axi binding)
└── AXI host master (cocotb handle binding)
```

### 1.2 模块实例化顺序

**推荐顺序**（自顶向下）：
1. Clock/Reset generator
2. 仿真组件（AXIS source、AXI master、DDR model）
3. 开源模型（AXIS Async FIFO、AXI SmartConnect）
4. DUT（Extractor、Packer、RingBuffer Controller）

## 2. 时钟与复位生成

### 2.1 时钟生成方式

**方式 1：SystemVerilog initial 块**（在 `top_tb.sv` 中）

```systemverilog
module top_tb;
    // 时钟信号
    logic video_aclk, axis_clk, axi_clk;
    
    // 时钟生成
    initial begin
        video_aclk = 0;
        forever #2.5ns video_aclk = ~video_aclk;  // 200MHz: period = 5ns
    end
    
    initial begin
        axis_clk = 0;
        forever #2.0ns axis_clk = ~axis_clk;      // 250MHz: period = 4ns
    end
    
    assign axi_clk = axis_clk;  // 同源，或独立生成
endmodule
```

**方式 2：cocotb Clock**（推荐，便于控制）

```systemverilog
module top_tb;
    // 时钟信号（由 cocotb 驱动）
    logic video_aclk, axis_clk, axi_clk;
endmodule
```

```python
# 在 cocotb 测试中
from cocotb.clock import Clock

video_aclk = Clock(dut.video_aclk, 5.0, units="ns")
axis_clk = Clock(dut.axis_clk, 4.0, units="ns")
axi_clk = Clock(dut.axi_clk, 4.0, units="ns")

cocotb.start_soon(video_aclk.start())
cocotb.start_soon(axis_clk.start())
cocotb.start_soon(axi_clk.start())
```

**推荐**：使用 cocotb `Clock`，便于测试中动态控制（暂停、频率切换）。

### 2.2 复位生成

**SystemVerilog 实现**（在 `top_tb.sv` 中）：

```systemverilog
module top_tb;
    logic sys_rst_n, axis_rst_n, axi_rst_n;
    
    // 复位生成（异步断言，同步释放）
    always_ff @(posedge axis_clk or negedge sys_rst_n) begin
        if (!sys_rst_n) begin
            axis_rst_n <= 1'b0;
        end else begin
            axis_rst_n <= 1'b1;  // 同步释放
        end
    end
    
    always_ff @(posedge axi_clk or negedge sys_rst_n) begin
        if (!sys_rst_n) begin
            axi_rst_n <= 1'b0;
        end else begin
            axi_rst_n <= 1'b1;
        end
    end
    
    // 初始复位状态（由 cocotb 或 SV initial 控制）
    initial begin
        sys_rst_n = 0;
        #100ns;
        @(posedge axis_clk);
        @(posedge axis_clk);
        sys_rst_n = 1;
        #50ns;
    end
endmodule
```

**cocotb 驱动**（推荐）：

```python
# 在 cocotb 测试中
async def reset_dut(dut):
    dut.sys_rst_n.value = 0
    await Timer(100, units="ns")
    await RisingEdge(dut.axis_clk)
    await RisingEdge(dut.axis_clk)
    dut.sys_rst_n.value = 1
    await Timer(50, units="ns")
```

## 3. DUT 实例化

### 3.1 CSI Packet Extractor

```systemverilog
csi_packet_extractor #(
    .AXIS_DATA_W(32),
    .AXIS_USER_W(64),
    // ... 其他参数
) extractor_u (
    .clk_i(axis_clk),
    .rst_ni(axis_rst_n),
    .cfg_vc_en_i(cfg_vc_en),
    .cfg_dt_en_i(cfg_dt_en),
    .cfg_vc_i(cfg_vc),
    .cfg_dt_i(cfg_dt),
    .pkt_start_o(pkt_start),
    .pkt_done_o(pkt_done),
    .pkt_valid_good_o(pkt_valid_good),
    .pkt_seq_o(pkt_seq),
    .pkt_bytes_o(pkt_bytes),
    .pkt_crc_err_o(pkt_crc_err),
    .pkt_ecc_err_o(pkt_ecc_err),
    .pkt_trunc_err_o(pkt_trunc_err),
    .s_axis(extractor_s_axis_if),
    .m_axis(extractor_m_axis_if)
);
```

### 3.2 Fixed Slot Packer

```systemverilog
fixed_slot_packer #(
    .AXIS_DATA_W(32),
    .AXIS_USER_W(64),
    // ... 其他参数
) packer_u (
    .clk_i(axis_clk),
    .rst_ni(axis_rst_n),
    .cfg_drop_invalid_pkt_i(cfg_drop_invalid_pkt),
    .pkt_start_i(pkt_start),
    .pkt_done_i(pkt_done),
    .pkt_bytes_i(pkt_bytes),
    .pkt_seq_i(pkt_seq),
    .pkt_crc_err_i(pkt_crc_err),
    .pkt_ecc_err_i(pkt_ecc_err),
    .pkt_trunc_err_i(pkt_trunc_err),
    .pkt_valid_good_i(pkt_valid_good),
    .slot_start_o(slot_start),
    .slot_done_o(slot_done),
    .slot_bytes_o(slot_bytes),
    .slot_seq_o(slot_seq),
    .slot_valid_good_o(slot_valid_good),
    .slot_overflow_err_o(slot_overflow_err),
    .s_axis(extractor_m_axis_if),
    .m_axis(packer_m_axis_if)
);
```

### 3.3 DDR RingBuffer Controller

```systemverilog
ddr_ringbuffer_controller #(
    .CFG_AXI_ADDR_W(34),
    .AXIS_DATA_W(32),
    .AXI_DATA_W(256),
    // ... 其他参数
) ringbuffer_u (
    .clk_i(axi_clk),
    .rst_ni(axi_rst_n),
    .cfg_enable_i(cfg_enable),
    .cfg_allow_overwrite_i(cfg_allow_overwrite),
    .cfg_drop_invalid_slot_i(cfg_drop_invalid_slot),
    .cfg_drop_on_no_space_i(cfg_drop_on_no_space),
    .cfg_ring_base_addr_i(cfg_ring_base_addr),
    .cfg_ring_size_bytes_i(cfg_ring_size_bytes),
    .slot_start_i(slot_start),
    .slot_done_i(slot_done),
    .slot_bytes_i(slot_bytes),
    .slot_seq_i(slot_seq),
    .slot_valid_good_i(slot_valid_good),
    .slot_overflow_err_i(slot_overflow_err),
    .wr_slot_commit_o(wr_slot_commit),
    .wr_slot_addr_o(wr_slot_addr),
    .wr_slot_seq_o(wr_slot_seq),
    .wr_slot_bytes_o(wr_slot_bytes),
    .wr_slot_valid_good_o(wr_slot_valid_good),
    .wr_slot_overflow_err_o(wr_slot_overflow_err),
    .rd_slot_req_i(rd_slot_req),
    .rd_consume_i(rd_consume),
    .rd_slot_valid_o(rd_slot_valid),
    .rd_slot_addr_o(rd_slot_addr),
    .rd_slot_bytes_o(rd_slot_bytes),
    .rd_slot_seq_o(rd_slot_seq),
    .rd_slot_valid_good_o(rd_slot_valid_good),
    .rd_slot_overflow_err_o(rd_slot_overflow_err),
    .rd_busy_o(rd_busy),
    .rd_done_o(rd_done),
    .rd_error_o(rd_error),
    // ... 状态信号
    .s_axis_slot(packer_m_axis_if),
    .m_axis_rd(ringbuffer_rd_axis_if),
    .m_axi(ringbuffer_axi_if)
);
```

## 4. 开源模型实例化

### 4.1 AXIS Async FIFO（verilog-axis）

```systemverilog
axis_async_fifo #(
    .DEPTH(512),
    .DATA_WIDTH(32),
    .KEEP_ENABLE(1),
    .USER_ENABLE(1)
) axis_async_fifo_u (
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
    .m_axis_tdata(extractor_s_axis_tdata),
    .m_axis_tvalid(extractor_s_axis_tvalid),
    .m_axis_tready(extractor_s_axis_tready),
    .m_axis_tlast(extractor_s_axis_tlast),
    .m_axis_tkeep(extractor_s_axis_tkeep),
    .m_axis_tuser(extractor_s_axis_tuser)
);
```

### 4.2 AXI SmartConnect（verilog-axi）

```systemverilog
axi_crossbar #(
    .S_COUNT(2),      // 2 masters
    .M_COUNT(1),      // 1 slave
    .DATA_WIDTH(512),
    .ADDR_WIDTH(64),
    .STRB_WIDTH(64),
    .ID_WIDTH(8)
) axi_smartconnect_u (
    .clk(axi_clk),
    .rst(~axi_rst_n),
    
    // Master 0: RingBuffer write
    .s_axi_awaddr({ringbuffer_axi_awaddr, 64'b0}),
    .s_axi_awlen({ringbuffer_axi_awlen, 8'b0}),
    .s_axi_awsize({ringbuffer_axi_awsize, 3'b0}),
    .s_axi_awburst({ringbuffer_axi_awburst, 2'b0}),
    .s_axi_awvalid({ringbuffer_axi_awvalid, 1'b0}),
    .s_axi_awready({ringbuffer_axi_awready, 1'b0}),
    .s_axi_wdata({ringbuffer_axi_wdata, 512'b0}),
    .s_axi_wstrb({ringbuffer_axi_wstrb, 64'b0}),
    .s_axi_wlast({ringbuffer_axi_wlast, 1'b0}),
    .s_axi_wvalid({ringbuffer_axi_wvalid, 1'b0}),
    .s_axi_wready({ringbuffer_axi_wready, 1'b0}),
    .s_axi_bresp({ringbuffer_axi_bresp, 2'b0}),
    .s_axi_bvalid({ringbuffer_axi_bvalid, 1'b0}),
    .s_axi_bready({ringbuffer_axi_bready, 1'b0}),
    
    // Master 1: Host read（cocotb 绑定）
    .s_axi_araddr({64'b0, host_axi_araddr}),
    .s_axi_arlen({8'b0, host_axi_arlen}),
    // ... 类似连接
    
    // Slave: DDR Model
    .m_axi_awaddr(ddr_axi_awaddr),
    .m_axi_awlen(ddr_axi_awlen),
    // ... 完整 AXI 信号
);
```

**注意**：verilog-axi `axi_crossbar` 的信号命名可能与上述不同，需参考实际模块接口。

## 5. cocotb 绑定

### 5.1 AXIS payload source

**SystemVerilog**（在 `top_tb.sv` 中）：

```systemverilog
// AXIS 信号（绑定到 cocotb）
logic [31:0] axis_source_tdata;
logic [3:0] axis_source_tkeep;
logic axis_source_tvalid;
logic axis_source_tready;
logic axis_source_tlast;
logic [63:0] axis_source_tuser;

// 连接到 CSI RX 或直接到 Async FIFO
assign csi_rx_axis_tdata = axis_source_tdata;
assign csi_rx_axis_tvalid = axis_source_tvalid;
assign axis_source_tready = csi_rx_axis_tready;
assign csi_rx_axis_tlast = axis_source_tlast;
assign csi_rx_axis_tkeep = axis_source_tkeep;
assign csi_rx_axis_tuser = axis_source_tuser;
```

**cocotb**（在测试中）：

```python
from cocotbext.axi import AxiStreamSource

axis_source = AxiStreamSource(
    dut.axis_source,  # 绑定到 top_tb 的 axis_source_* 信号
    dut.video_aclk,
    dut.video_rst_n
)
```

### 5.2 AXI host master

**SystemVerilog**：

```systemverilog
// AXI 信号（绑定到 cocotb）
logic [63:0] host_axi_araddr;
logic [7:0] host_axi_arlen;
logic [2:0] host_axi_arsize;
logic [1:0] host_axi_arburst;
logic host_axi_arvalid;
logic host_axi_arready;
logic [511:0] host_axi_rdata;
logic [1:0] host_axi_rresp;
logic host_axi_rlast;
logic host_axi_rvalid;
logic host_axi_rready;
```

**cocotb**：

```python
from cocotbext.axi import AxiMaster

host_master = AxiMaster(
    dut.host_axi,  # 绑定到 top_tb 的 host_axi_* 信号
    dut.axi_clk,
    dut.axi_rst_n
)
```

### 5.3 DDR Model（若使用 cocotbext-axi AxiMemory）

**SystemVerilog**：

```systemverilog
// AXI 信号（绑定到 cocotb）
logic [63:0] ddr_axi_awaddr;
logic [7:0] ddr_axi_awlen;
// ... 完整 AXI 信号
```

**cocotb**：

```python
from cocotbext.axi import AxiMemory

ddr_memory = AxiMemory(
    dut.ddr_axi,
    dut.axi_clk,
    dut.axi_rst_n,
    size=256*1024*1024  # 256MB
)
```

## 6. 文件放置

### 6.1 Testbench 文件

| 文件 | 位置 | 说明 |
|------|------|------|
| **top_tb.sv** | `tb/top_tb.sv` | 顶层 testbench（完整 pipeline） |
| **extractor_tb.sv** | `tb/extractor_tb.sv` | Extractor 单独测试（可选） |
| **packer_tb.sv** | `tb/packer_tb.sv` | Packer 单独测试（可选） |
| **ringbuffer_tb.sv** | `tb/ringbuffer_tb.sv` | RingBuffer 单独测试（可选） |

### 6.2 cocotb 顶层包装

| 文件 | 位置 | 说明 |
|------|------|------|
| **top_cocotb_top.sv** | `tb/cocotb/top_cocotb_top.sv` | cocotb 顶层包装（完整 pipeline） |
| **pipeline_cocotb_top.sv** | `tb/cocotb/pipeline_cocotb_top.sv` | 现有 pipeline 顶层（保留） |

**注意**：`*_cocotb_top.sv` 通常是对应 `top_tb.sv` 的简化版本，仅暴露 cocotb 需要的信号。

### 6.3 与仿真脚本的配合

**Verilator 编译**（`sim/Makefile` 或 `tb/cocotb/run_*.py`）：

```python
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
        TB_DIR / "top_tb.sv",  # 或 top_cocotb_top.sv
    ]
```

## 7. 最小 SystemVerilog 骨架

### 7.1 top_tb.sv（骨架）

```systemverilog
`timescale 1ns / 1ps

module top_tb;
    // 时钟信号
    logic video_aclk, axis_clk, axi_clk;
    
    // 复位信号
    logic sys_rst_n, axis_rst_n, axi_rst_n;
    
    // 时钟生成（由 cocotb 或 SV initial 驱动）
    // ... (见上文 2.1 节)
    
    // 复位生成（由 cocotb 或 SV initial 驱动）
    // ... (见上文 2.2 节)
    
    // AXIS 接口（用于 cocotb 绑定）
    axis_stream_if #(.DATA_W(32), .USER_W(64)) axis_source_if (.aclk(video_aclk), .aresetn(video_rst_n));
    axis_stream_if #(.DATA_W(32), .USER_W(64)) extractor_s_axis_if (.aclk(axis_clk), .aresetn(axis_rst_n));
    axis_stream_if #(.DATA_W(32), .USER_W(64)) extractor_m_axis_if (.aclk(axis_clk), .aresetn(axis_rst_n));
    axis_stream_if #(.DATA_W(32), .USER_W(64)) packer_m_axis_if (.aclk(axis_clk), .aresetn(axis_rst_n));
    axis_stream_if #(.DATA_W(512), .USER_W(32)) ringbuffer_rd_axis_if (.aclk(axi_clk), .aresetn(axi_rst_n));
    
    // AXI 接口
    axi4_mm_if #(.ADDR_W(64), .DATA_W(512)) ringbuffer_axi_if (.aclk(axi_clk), .aresetn(axi_rst_n));
    axi4_mm_if #(.ADDR_W(64), .DATA_W(512)) host_axi_if (.aclk(axi_clk), .aresetn(axi_rst_n));
    axi4_mm_if #(.ADDR_W(64), .DATA_W(512)) ddr_axi_if (.aclk(axi_clk), .aresetn(axi_rst_n));
    
    // 配置信号
    logic cfg_vc_en, cfg_dt_en;
    logic [1:0] cfg_vc;
    logic [5:0] cfg_dt;
    logic cfg_drop_invalid_pkt;
    logic cfg_enable, cfg_allow_overwrite, cfg_drop_invalid_slot, cfg_drop_on_no_space;
    logic [63:0] cfg_ring_base_addr;
    logic [31:0] cfg_ring_size_bytes;
    
    // 侧带信号
    logic pkt_start, pkt_done, pkt_valid_good;
    logic [15:0] pkt_seq, pkt_bytes;
    logic pkt_crc_err, pkt_ecc_err, pkt_trunc_err;
    logic slot_start, slot_done, slot_valid_good, slot_overflow_err;
    logic [15:0] slot_seq;
    logic [15:0] slot_bytes;
    logic wr_slot_commit;
    logic [63:0] wr_slot_addr;
    logic [15:0] wr_slot_seq, wr_slot_bytes;
    logic wr_slot_valid_good, wr_slot_overflow_err;
    logic rd_slot_req, rd_consume;
    logic rd_slot_valid, rd_busy, rd_done, rd_error;
    logic [63:0] rd_slot_addr;
    logic [15:0] rd_slot_bytes, rd_slot_seq;
    logic rd_slot_valid_good, rd_slot_overflow_err;
    
    // AXIS Async FIFO 实例化
    axis_async_fifo #(
        .DEPTH(512),
        .DATA_WIDTH(32),
        .KEEP_ENABLE(1),
        .USER_ENABLE(1)
    ) axis_async_fifo_u (
        .s_clk(video_aclk),
        .s_rst(~video_rst_n),
        .s_axis_tdata(axis_source_if.tdata),
        .s_axis_tvalid(axis_source_if.tvalid),
        .s_axis_tready(axis_source_if.tready),
        .s_axis_tlast(axis_source_if.tlast),
        .s_axis_tkeep(axis_source_if.tkeep),
        .s_axis_tuser(axis_source_if.tuser),
        
        .m_clk(axis_clk),
        .m_rst(~axis_rst_n),
        .m_axis_tdata(extractor_s_axis_if.tdata),
        .m_axis_tvalid(extractor_s_axis_if.tvalid),
        .m_axis_tready(extractor_s_axis_if.tready),
        .m_axis_tlast(extractor_s_axis_if.tlast),
        .m_axis_tkeep(extractor_s_axis_if.tkeep),
        .m_axis_tuser(extractor_s_axis_if.tuser)
    );
    
    // CSI Packet Extractor 实例化
    csi_packet_extractor #(
        .AXIS_DATA_W(32),
        .AXIS_USER_W(64)
    ) extractor_u (
        .clk_i(axis_clk),
        .rst_ni(axis_rst_n),
        .cfg_vc_en_i(cfg_vc_en),
        .cfg_dt_en_i(cfg_dt_en),
        .cfg_vc_i(cfg_vc),
        .cfg_dt_i(cfg_dt),
        .pkt_start_o(pkt_start),
        .pkt_done_o(pkt_done),
        .pkt_valid_good_o(pkt_valid_good),
        .pkt_seq_o(pkt_seq),
        .pkt_bytes_o(pkt_bytes),
        .pkt_crc_err_o(pkt_crc_err),
        .pkt_ecc_err_o(pkt_ecc_err),
        .pkt_trunc_err_o(pkt_trunc_err),
        .s_axis(extractor_s_axis_if),
        .m_axis(extractor_m_axis_if)
    );
    
    // Fixed Slot Packer 实例化
    fixed_slot_packer #(
        .AXIS_DATA_W(32),
        .AXIS_USER_W(64)
    ) packer_u (
        .clk_i(axis_clk),
        .rst_ni(axis_rst_n),
        .cfg_drop_invalid_pkt_i(cfg_drop_invalid_pkt),
        .pkt_start_i(pkt_start),
        .pkt_done_i(pkt_done),
        .pkt_bytes_i(pkt_bytes),
        .pkt_seq_i(pkt_seq),
        .pkt_crc_err_i(pkt_crc_err),
        .pkt_ecc_err_i(pkt_ecc_err),
        .pkt_trunc_err_i(pkt_trunc_err),
        .pkt_valid_good_i(pkt_valid_good),
        .slot_start_o(slot_start),
        .slot_done_o(slot_done),
        .slot_bytes_o(slot_bytes),
        .slot_seq_o(slot_seq),
        .slot_valid_good_o(slot_valid_good),
        .slot_overflow_err_o(slot_overflow_err),
        .s_axis(extractor_m_axis_if),
        .m_axis(packer_m_axis_if)
    );
    
    // DDR RingBuffer Controller 实例化
    ddr_ringbuffer_controller #(
        .CFG_AXI_ADDR_W(34),
        .AXIS_DATA_W(32),
        .AXI_DATA_W(256)
    ) ringbuffer_u (
        .clk_i(axi_clk),
        .rst_ni(axi_rst_n),
        .cfg_enable_i(cfg_enable),
        .cfg_allow_overwrite_i(cfg_allow_overwrite),
        .cfg_drop_invalid_slot_i(cfg_drop_invalid_slot),
        .cfg_drop_on_no_space_i(cfg_drop_on_no_space),
        .cfg_ring_base_addr_i(cfg_ring_base_addr),
        .cfg_ring_size_bytes_i(cfg_ring_size_bytes),
        .slot_start_i(slot_start),
        .slot_done_i(slot_done),
        .slot_bytes_i(slot_bytes),
        .slot_seq_i(slot_seq),
        .slot_valid_good_i(slot_valid_good),
        .slot_overflow_err_i(slot_overflow_err),
        .wr_slot_commit_o(wr_slot_commit),
        .wr_slot_addr_o(wr_slot_addr),
        .wr_slot_seq_o(wr_slot_seq),
        .wr_slot_bytes_o(wr_slot_bytes),
        .wr_slot_valid_good_o(wr_slot_valid_good),
        .wr_slot_overflow_err_o(wr_slot_overflow_err),
        .rd_slot_req_i(rd_slot_req),
        .rd_consume_i(rd_consume),
        .rd_slot_valid_o(rd_slot_valid),
        .rd_slot_addr_o(rd_slot_addr),
        .rd_slot_bytes_o(rd_slot_bytes),
        .rd_slot_seq_o(rd_slot_seq),
        .rd_slot_valid_good_o(rd_slot_valid_good),
        .rd_slot_overflow_err_o(rd_slot_overflow_err),
        .rd_busy_o(rd_busy),
        .rd_done_o(rd_done),
        .rd_error_o(rd_error),
        .s_axis_slot(packer_m_axis_if),
        .m_axis_rd(ringbuffer_rd_axis_if),
        .m_axi(ringbuffer_axi_if)
    );
    
    // AXI SmartConnect 实例化（verilog-axi）
    axi_crossbar #(
        .S_COUNT(2),
        .M_COUNT(1),
        .DATA_WIDTH(512),
        .ADDR_WIDTH(64)
    ) axi_smartconnect_u (
        .clk(axi_clk),
        .rst(~axi_rst_n),
        // Master 0: RingBuffer
        .s_axi_awaddr({ringbuffer_axi_if.awaddr, 64'b0}),
        // ... 完整连接
        // Master 1: Host（cocotb）
        .s_axi_araddr({64'b0, host_axi_if.araddr}),
        // ... 完整连接
        // Slave: DDR
        .m_axi_awaddr(ddr_axi_if.awaddr),
        // ... 完整连接
    );
    
    // DDR Model（若使用 LiteDRAM RTL，需实例化；若使用 cocotbext-axi，仅需信号）
    // ... DDR Model 实例化或信号声明
    
endmodule
```

### 7.2 top_cocotb_top.sv（cocotb 包装）

**简化版本**，仅暴露 cocotb 需要的信号：

```systemverilog
`timescale 1ns / 1ps

// cocotb 顶层包装：实例化 top_tb，仅暴露 cocotb 需要的信号
module top_cocotb_top;
    // 时钟/复位（cocotb 驱动）
    logic video_aclk, axis_clk, axi_clk;
    logic sys_rst_n;
    
    // AXIS source（cocotb 绑定）
    logic [31:0] axis_source_tdata;
    logic [3:0] axis_source_tkeep;
    logic axis_source_tvalid;
    logic axis_source_tready;
    logic axis_source_tlast;
    logic [63:0] axis_source_tuser;
    
    // AXI host master（cocotb 绑定）
    logic [63:0] host_axi_araddr;
    logic [7:0] host_axi_arlen;
    logic [2:0] host_axi_arsize;
    logic [1:0] host_axi_arburst;
    logic host_axi_arvalid;
    logic host_axi_arready;
    logic [511:0] host_axi_rdata;
    logic [1:0] host_axi_rresp;
    logic host_axi_rlast;
    logic host_axi_rvalid;
    logic host_axi_rready;
    
    // DDR AXI（cocotb 绑定，若使用 cocotbext-axi AxiMemory）
    logic [63:0] ddr_axi_awaddr;
    // ... 完整 AXI 信号
    
    // 实例化 top_tb（内部模块）
    top_tb u_top_tb (
        .video_aclk(video_aclk),
        .axis_clk(axis_clk),
        .axi_clk(axi_clk),
        .sys_rst_n(sys_rst_n),
        .axis_source_tdata(axis_source_tdata),
        .axis_source_tvalid(axis_source_tvalid),
        .axis_source_tready(axis_source_tready),
        .axis_source_tlast(axis_source_tlast),
        .axis_source_tkeep(axis_source_tkeep),
        .axis_source_tuser(axis_source_tuser),
        .host_axi_araddr(host_axi_araddr),
        // ... 完整信号连接
    );
endmodule
```

**或**：直接在 `top_tb.sv` 中暴露信号，无需单独包装。

## 8. 与仿真脚本的配合

### 8.1 Verilator 编译选项

**在 `tb/cocotb/run_*.py` 中**：

```python
runner.build(
    sources=build_sources(),
    includes=[REPO_ROOT / "rtl/include"],
    hdl_toplevel="top_cocotb_top",  # 或 "top_tb"
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
        "--trace-fst",  # 波形
    ],
)
```

### 8.2 cocotb 测试运行

```python
runner.test(
    test_module="test_pipeline",  # 或 "top_cocotb"
    hdl_toplevel="top_cocotb_top",
    test_filter="test_top_sanity",
    test_dir=test_dir,
    waves=waves,
    extra_env={
        "PYTHONPATH": str(TB_DIR),
    },
)
```

## 9. 与现有结构的兼容

**现有结构**：
- `tb/cocotb/pipeline_cocotb_top.sv`：现有 pipeline 顶层（保留）
- `tb/cocotb/run_pipeline.py`：现有运行脚本（保留）

**新增结构**：
- `tb/top_tb.sv`：完整顶层 testbench（新增）
- `tb/cocotb/top_cocotb_top.sv`：cocotb 包装（新增，可选）

**建议**：
- 保留现有 `pipeline_cocotb_top.sv` 和 `run_pipeline.py`
- 新增 `top_tb.sv` 作为更通用的顶层（包含 CSI RX、Async FIFO、SmartConnect、DDR Model）
- 两者可共存，`pipeline_cocotb_top.sv` 用于快速回归，`top_tb.sv` 用于完整平台验证
