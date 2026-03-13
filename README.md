

# 雷达采集系统详细架构设计说明书 v2

## 构建与验证

统一的本地构建与回归入口脚本：

```sh
tools/build_and_verify.sh
```

详细使用说明见：
[BUILD_AND_VERIFY.md](BUILD_AND_VERIFY.md)

## Host / PCIe / DMA 仿真扩展约定

当前仓库中 Host 侧回归仍以 cocotb behavioral driver 为主。新增的 `Host -> PCIe -> DMA -> AXI -> DDR -> Radar Data Pipeline` 端到端扩展合同见 [docs/sim_platform/11_pcie_dma_extension_contract.md](docs/sim_platform/11_pcie_dma_extension_contract.md)。

该合同固定第一阶段：

* 继续沿用现有 `AXI_ADDR_W=34`、`AXI_DATA_W=256`
* 保持 `RDL` 导出的 BAR0/CSR 偏移 `0x000-0x08C`
* PCIe RC / endpoint / DMA 先保持 behavioral，避免在各分支并行发散出第二套控制面

# 1 系统设计目标

构建基于 **AWR2243 + FPGA + DDR4 + PCIe XDMA** 的高速雷达数据采集系统，实现：

* AWR2243 雷达配置与启动
* MIPI CSI-2 数据接收
* CSI packet payload 提取
* 固定长度 slot 封装
* DDR4 环形缓冲区存储
* PCIe XDMA 数据读取
* Host 软件解析雷达原始数据

系统设计原则：

* **FPGA 只做数据搬运与封装**
* **Host 负责解析 AWR 原始数据结构**
* **FPGA 不做 AWR payload 内部语义解析**
* **无论实际 Ns 是否小于 1024，统一按 1024 sample 固定槽位存储**
* **CQ 区域始终预留，若无有效 CQ 则填 0**

## 1.1 代码与配置入口（与文档对应）

| 内容           | 位置 |
|----------------|------|
| Slot 工具函数/常量 | `rtl/pkg/slot_packer_pkg.sv` |
| Slot 尺寸/对齐   | `rtl/include/slot_packer_macros.svh` |
| DDR ring 常量/类型 | `rtl/pkg/ddr_ringbuffer_pkg.sv`、`rtl/include/ddr_ringbuffer_macros.svh` |
| CSR 定义        | `rdl/ddr_ringbuffer_controller.rdl` |
| CSR 生成头/示例  | `sw/include/generated/ddr_ringbuffer_controller_csr.h`、`sw/examples/ddr_ringbuffer_controller_csr_example.c` |
| 核心 RTL 模块   | `rtl/core/csi_packet_extractor.sv`、`rtl/core/fixed_slot_packer.sv`、`rtl/core/ddr_ringbuffer_controller.sv`、`rtl/core/ddr_ringbuffer_controller_axil.sv` |

---

# 2 系统总体架构

```text
AXIS payload source
   │
   ▼
CSI RX Subsystem
(video_aclk = 200MHz)
   │
   ▼
AXIS Async FIFO
(200MHz -> 250MHz)
   │
   ▼
CSI Packet Extractor
(axis_clk = 250MHz)
   │
   ▼
Slot Packer
(axis_clk = 250MHz)
   │
   ▼
RingBuffer Controller
(axi_clk = 250MHz)
   │
   ▼
AXI SmartConnect
   ├── AXI host master
   └── DDR model

```

---

# 3 数据处理策略

系统采用 **固定长度 slot 存储策略**。

无论实际配置下：

* `Ns < 1024`
* `Ns = 1024`

都统一存储为固定长度 raw payload 区：

* sample 区按 `1024 sample` 预留
* 不足部分补 0
* CQ 区无论是否启用都保留，未启用时补 0

这样 Host 端始终可以按固定长度读取 slot，不需要变长寻址。

---

# 4 Slot 数据结构

工程中 slot 布局与尺寸由 **`rtl/pkg/slot_packer_pkg.sv`** 与 **`rtl/include/slot_packer_macros.svh`** 定义，`fixed_slot_packer` 按固定长度输出整 slot。

## 4.1 slot 总结构

```text
slot (单块连续输出，64B 对齐)
├─ rx_headers (4 × 24bit = 12B)
├─ sample_area (1024 × 12B = 12288B)
├─ CQ_area (6 × 12bit = 9B, 原始 64bit CQ 按 raw12 对齐)
└─ padding (至 ALIGN_BYTES 边界)
```

默认宏下：`HEADER_BYTES=12`，`SAMPLE_SLOT_NUM=1024`，`SAMPLE_UNIT_BYTES=12`，`CQ_AREA_BYTES=9`，`ALIGN_BYTES=64`。

---

## 4.2 RX Header 布局（与代码一致）

每个 RX header 为 **24bit = 两个 12bit word**，按 raw12 little-endian 紧凑打包：

| 12bit word | 位段 | 说明 |
|------------|------|------|
| word0      | [11:6] | `NULL`，固定 0 |
| word0      | [5:2]  | `chirp_profile`（4bit） |
| word0      | [1:0]  | `channel_id`（2bit） |
| word1      | [11:0] | `chirp_num`（12bit） |

4 个 RX header 连续排布，总计 **12B**。当前实现不再插入额外的 synthetic slot header。

---

## 4.3 sample 区与 CQ 区

* **sample 区**：`SAMPLE_SLOT_NUM × SAMPLE_UNIT_BYTES`。默认 1024×12B = 12288B，不足部分由 packer 填 0。
* **CQ 区**：固定 `CQ_AREA_BYTES`。默认 `9B = 6×12bit`，用于承载原始 64bit CQ 数据并按 raw12 边界补齐。

---

## 4.4 Slot 总长度（代码计算）

在 `fixed_slot_packer.sv` 中：

```text
SLOT_TOTAL_UNALIGNED = HEADER_BYTES + SAMPLE_AREA_BYTES + CQ_AREA_BYTES
SLOT_TOTAL_ALIGNED   = align_up_u(SLOT_TOTAL_UNALIGNED, ALIGN_BYTES)
slot_bytes_o         = SLOT_TOTAL_ALIGNED
```

默认：12 + 12288 + 9 = 12309B，向上按 64B 对齐后为 **12352B**，padding **43B**。修改 `slot_packer_macros.svh` 中 `SAMPLE_UNIT_BYTES`、`CQ_AREA_BYTES`、`HEADER_BYTES` 等可改变 slot 布局与长度。

---

# 7 DDR 与 Ring Buffer 地址

Ring 在 DDR 上为连续区间，由软件通过 CSR 配置，不区分独立 “Control Area” 与 “Data Area” 两段：基址与长度由 **RING_BASE_LO/HI**、**RING_SIZE_BYTES** 给出，指针与占用由控制器内部维护并通过 CSR 只读寄存器暴露。

## 7.1 地址与参数（与 RTL 一致）

* **Ring 基址**：`ring_base_addr`（64bit，由 RING_BASE_LO / RING_BASE_HI 配置）
* **Ring 长度**：`ring_size_bytes`（RING_SIZE_BYTES，需满足控制器对齐要求，见 `ddr_ringbuffer_macros.svh` 中 `DDR_RING_ALIGN_BYTES_DFLT` 等）
* **Slot 步进**：由上游 `fixed_slot_packer` 的 `slot_bytes_o` 决定；控制器侧可选固定 stride（`SLOT_STRIDE_BYTES`）或按每 slot 实际字节数写入

默认宏（`ddr_ringbuffer_macros.svh`）：`DDR_RING_SLOT_BUFFER_BYTES_DFLT=12352`，`DDR_RING_SLOT_STRIDE_BYTES_DFLT=12352`，`DDR_RING_RING_SIZE_BYTES_DFLT=65536`。默认配置下，控制器缓冲与固定 stride 已与新的 slot 长度匹配。

## 7.2 slot 数量估算

例如 ring_size_bytes = 256MB、单 slot = 12352B 时，约可存 `256MB / 12352B ≈ 21735` 个 slot（实际受对齐与控制器约束）。

---

# 8 模块功能与代码位置

---

## 8.1 CSI Packet Extractor

**RTL**：`rtl/core/csi_packet_extractor.sv`；宏：`rtl/include/csi_packet_extractor_macros.svh`；类型与常量：`rtl/pkg/csi_packet_pkg.sv`。

* 接收 CSI-2 RX Subsystem 的 AXI4-Stream
* 按 VC/DT 过滤，识别并转发 long packet payload
* 侧带输出：pkt_start, pkt_done, pkt_bytes, pkt_seq, pkt_crc_err, pkt_ecc_err, pkt_trunc_err, pkt_valid_good

---

## 8.2 Fixed Slot Packer

**RTL**：`rtl/core/fixed_slot_packer.sv`；宏：`rtl/include/slot_packer_macros.svh`；工具函数：`rtl/pkg/slot_packer_pkg.sv`。

* 接收上游 packet 流与侧带，生成固定长度 slot 流
* 保留原始 12B RX header，不再生成额外 slot header
* sample 区固定按 1024×12B 展开，不足补 0
* CQ 区固定 9B，按 raw12 格式承载原始 64bit CQ 数据
* 尾部 padding 至 64B 对齐
* 输出：AXIS 数据 + slot_start, slot_done, slot_bytes_o, slot_seq_o, slot_valid_good_o, slot_overflow_err_o

---

## 8.3 DDR Ring Buffer Controller

**RTL**：`rtl/core/ddr_ringbuffer_controller.sv`；宏与类型：`rtl/include/ddr_ringbuffer_macros.svh`、`rtl/pkg/ddr_ringbuffer_pkg.sv`。

* 上游 AXIS slot 流写入内部 buffer，按 ring 基址/长度做地址分配
* AXI-MM 写突发写入 DDR，维护 wr_ptr / commit_ptr，提交 slot 描述符
* 支持 Host 通过 READ_CMD（issue_head_read / consume_head）读取队首描述符并消费
* 溢出/丢弃策略由 CTRL（allow_overwrite, drop_invalid_slot, drop_on_no_space）控制

---

## 8.4 DDR Ring Buffer Controller + AXI-Lite CSR 包装

**RTL**：`rtl/core/ddr_ringbuffer_controller_axil.sv`；文件列表：`rtl/ddr_ringbuffer_controller_axil.f`。

* 对外 AXI4-Lite slave CSR 口
* 内部实例化 PeakRDL 生成的 CSR regblock 与 `ddr_ringbuffer_controller`
* 将 CTRL/RING_BASE/RING_SIZE/READ_CMD 等映射到控制器，状态/指针/计数/LAST_COMMIT_*/HEAD_DESC_* 回填到只读寄存器

---

## 8.5 XDMA / Host 侧

* Host 通过 PCIe XDMA 以 AXI-MM 访问 DDR（读 slot 数据）及 AXI-Lite 访问 CSR（BAR0 + CSR 偏移）
* 使用 `sw/include/generated/ddr_ringbuffer_controller_csr.h` 与 `sw/examples/ddr_ringbuffer_controller_csr_example.c` 进行配置与读队首/消费

---

## 8.6 SPI Driver（AWR2243）

当前仓库未包含 SPI 驱动 RTL；若需配置 AWR2243 profile/chirp/frame，需在系统侧另行实现并接入。

---

# 9 时钟域分析

这一部分整合你原本的时钟规划，并补充跨时钟域设计要求。

---

## 9.1 系统时钟规划

## 系统基准时钟

* `sys_clk = 100MHz`

## 高速总线时钟

* `PCIe = 100MHz`
* `AXI = 250MHz`
* `CSI2 = 200MHz`

## 低速控制时钟

* `SPI = 50MHz`

---

## 9.2 各时钟域划分

建议按功能划分为以下时钟域：

### 1）sys_clk 域（100MHz）

用于：

* 顶层控制逻辑
* CSR 寄存器块
* 软复位控制
* 简单状态机控制

### 2）pcie_clk 域（100MHz）

用于：

* XDMA 用户侧接口
* PCIe 配置与中断逻辑
* Host 访问控制

### 3）csi_rx_clk 域（200MHz）

用于：

* D-PHY / CSI-2 RX Subsystem 输出域
* CSI Packet Extractor

### 4）axi_clk 域（250MHz）

用于：

* Fixed Slot Packer
* DDR Ring Buffer Writer
* AXI Interconnect / SmartConnect
* MIG 用户接口相关逻辑

### 5）spi_clk 域（50MHz）

用于：

* AWR2243 SPI 配置状态机

---

## 9.3 推荐模块与时钟域对应关系

| 模块                     | 时钟域        |
| ---------------------- | ---------- |
| SPI Driver             | spi_clk    |
| CSR Register Block     | sys_clk    |
| XDMA Interface         | pcie_clk   |
| CSI-2 RX Subsystem     | csi_rx_clk |
| CSI Packet Extractor   | csi_rx_clk |
| Fixed Slot Packer      | axi_clk    |
| DDR Ring Buffer Writer | axi_clk    |
| MIG User Interface     | axi_clk    |

---

## 9.4 跨时钟域路径分析

系统主要存在以下 CDC 路径：

### 路径 1：sys_clk -> spi_clk

用于：

* 配置启动命令
* 状态触发信号

建议方式：

* 单 bit 控制信号：双触发器同步
* 多 bit 配置命令：握手或小型异步 FIFO

---

### 路径 2：sys_clk -> pcie_clk

用于：

* 控制寄存器与 XDMA 用户逻辑交互
* 软复位信号分发

建议方式：

* 控制信号：双触发器同步
* 状态返回：寄存器镜像或握手同步

---

### 路径 3：csi_rx_clk -> axi_clk

这是**最关键的跨时钟域路径**。

用于：

* CSI packet payload 从 CSI RX 域传入 slot 打包域

建议方式：

* **AXIS Data FIFO / Async FIFO**
* 保持 packet 边界信息
* 保持 `tlast`、payload_bytes、error flags 一并跨域

这是全链路里最重要的 CDC 点。

---

### 路径 4：axi_clk -> pcie_clk

用于：

* ring buffer 状态同步到 XDMA/Host 可见域
* wr_ptr / commit_ptr / overflow_count 状态可见化

建议方式：

* 小宽度状态量：跨域同步寄存器
* 多 bit 指针：Gray Code 或握手同步
* 大吞吐数据：不直接跨域，统一通过 DDR 共享

---

### 路径 5：axi_clk -> sys_clk

用于：

* 全局状态监控
* 调试计数器汇总

建议方式：

* 低速状态同步
* 不建议频繁大总线跨域

---

## 9.5 时钟域隔离原则

### 原则 1

**高速数据流只经过 FIFO 跨域，不直接裸连状态机。**

### 原则 2

**控制路径和数据路径分离。**

* 数据走 AXIS FIFO / DDR
* 控制走同步寄存器/握手

### 原则 3

**ring buffer 数据本体不做跨域搬运。**

数据统一写入 DDR 后，由不同域通过：

* DDR 地址
* 指针
* 状态寄存器

间接共享。

---

## 9.6 复位域分析

建议不要只使用一个统一复位，而是分域管理。

推荐复位划分如下：

| 复位名      | 作用域          |
| -------- | ------------ |
| rst_sys  | sys_clk 域    |
| rst_pcie | pcie_clk 域   |
| rst_csi  | csi_rx_clk 域 |
| rst_axi  | axi_clk 域    |
| rst_spi  | spi_clk 域    |

---

## 9.7 复位释放顺序建议

建议上电后按以下顺序释放：

### Step 1

释放 `rst_sys`

### Step 2

等待时钟稳定后释放 `rst_pcie`

### Step 3

等待 DDR 初始化完成后释放 `rst_axi`

### Step 4

等待 CSI 子系统 ready 后释放 `rst_csi`

### Step 5

最后释放 `rst_spi`，开始配置雷达

这样可以避免：

* 雷达先出流，但后端未准备好
* DDR 未 ready 就写数据
* XDMA 未 ready 就暴露状态

---

## 9.8 时钟域设计建议

### 对于 `csi_rx_clk -> axi_clk`

建议使用：

* `AXIS Data FIFO`
* `AXIS Register Slice`

### 对于 `axi_clk -> pcie_clk`

建议：

* ring status 单独寄存器镜像
* wr_ptr / commit_ptr 使用同步逻辑导出只读快照

### 对于 `sys_clk` 控制

建议：

* 全局 CSR 在 sys_clk 域
* 每个子模块做本地同步控制

---

# 10 DDR Ring Buffer 管理

## 10.1 控制与状态（与 RDL/CSR 一致）

通过 **`rdl/ddr_ringbuffer_controller.rdl`** 定义的 CSR 暴露：

* **配置**：CTRL（enable, allow_overwrite, drop_invalid_slot, drop_on_no_space）、RING_BASE_LO/HI、RING_SIZE_BYTES
* **指针**：WR_PTR、RD_PTR、COMMIT_PTR（各 64bit，LO/HI）
* **占用**：USED_BYTES、FREE_BYTES、COMMITTED_BYTES
* **计数**：WRAP_COUNT、OVERFLOW_COUNT、DROP_COUNT
* **队首/最近提交**：HEAD_DESC_*、LAST_COMMIT_*（地址、slot_bytes、valid_good、overflow_err、slot_seq）

CSI CRC/ECC 等由各 slot 的 header flags 携带，不在此做全局计数。

## 10.2 指针关系

```text
rd_ptr ≤ commit_ptr ≤ wr_ptr
```

* **wr_ptr**：下一 slot 写入起始地址
* **commit_ptr**：已完整写入、可被 Host 读取的提交边界
* **rd_ptr**：Host 已消费边界（consume_head 推进）

## 10.3 溢出与丢弃策略

由 CTRL 控制：

* **drop_on_no_space**：无空间时是否立即丢弃 slot（否则可能背压）
* **allow_overwrite**：是否允许覆盖未读 slot
* **drop_invalid_slot**：是否丢弃无效 slot

OVERFLOW_COUNT 统计带 overflow 标记的 slot；DROP_COUNT 统计所有被丢弃的 slot（含 overwrite 驱逐）。不覆盖已提交数据，保证 Host 可见数据一致。

---

# 11 PCIe XDMA 接口

采用：

* **AXI Memory Mapped**

Host 通过 XDMA：

* 读 DDR ring buffer 数据区
* 读控制寄存器区
* 控制 start/stop/reset

---

# 12 寄存器表（与 RDL/生成代码一致）

寄存器由 **`rdl/ddr_ringbuffer_controller.rdl`** 定义，生成 RTL 与 C 头文件。Host 侧以 **`sw/include/generated/ddr_ringbuffer_controller_csr.h`** 和结构体 `ddr_ringbuffer_controller_csr_t`（总大小 0x90）为准。以下偏移与 RDL 一致。

## 12.1 控制与配置

| Offset | 名称             | 说明 |
| ------ | ---------------- | ---- |
| 0x000  | CTRL             | enable, allow_overwrite, drop_invalid_slot, drop_on_no_space |
| 0x004  | STATUS           | full, almost_full, empty, rd_busy, err_cfg_align, err_no_space, err_slot_proto, err_slot_too_large, err_axi_wr_resp, err_axi_rd_resp, err_illegal_read |
| 0x008  | RING_BASE_LO     | Ring 基址 [31:0] |
| 0x00C  | RING_BASE_HI     | Ring 基址 [63:32] |
| 0x010  | RING_SIZE_BYTES  | Ring 长度（字节） |
| 0x014  | READ_CMD         | issue_head_read（脉冲）, consume_head（脉冲） |

## 12.2 占用与指针

| Offset | 名称             | 说明 |
| ------ | ---------------- | ---- |
| 0x020  | USED_BYTES       | 已占用字节（含未提交） |
| 0x024  | FREE_BYTES       | 剩余可用字节 |
| 0x028  | COMMITTED_BYTES  | 已提交未消费字节 |
| 0x030  | WR_PTR_LO / HI   | 写指针 |
| 0x038  | RD_PTR_LO / HI   | 读（消费）指针 |
| 0x040  | COMMIT_PTR_LO/HI | 提交指针 |

## 12.3 计数与最近提交 / 队首描述符

| Offset | 名称                 | 说明 |
| ------ | -------------------- | ---- |
| 0x048  | WRAP_COUNT           | 写指针回绕次数 |
| 0x04C  | OVERFLOW_COUNT       | 带 overflow 的 slot 计数 |
| 0x050  | DROP_COUNT           | 丢弃 slot 计数（含 overwrite） |
| 0x060  | LAST_COMMIT_ADDR_LO/HI | 最近一次提交的 slot 地址 |
| 0x068  | LAST_COMMIT_INFO     | slot_bytes[23:0], valid_good, overflow_err, commit_valid |
| 0x06C  | LAST_COMMIT_SEQ      | 最近提交 slot 序号 |
| 0x080  | HEAD_DESC_ADDR_LO/HI | 当前队首（最老未读）slot 地址 |
| 0x088  | HEAD_DESC_INFO       | slot_bytes[23:0], valid_good, overflow_err, desc_valid |
| 0x08C  | HEAD_DESC_SEQ        | 队首 slot 序号 |

---

# 13 状态机设计（与 RTL 对应）

## 13.1 CSI Packet Extractor（`rtl/core/csi_packet_extractor.sv`）

```text
ST_IDLE
   │
   ▼
ST_CHECK ──► ST_ACCEPT（转发） 或 ST_DROP（丢弃）
   │
   └──────────────► ...
```

按 VC/DT 过滤，对接受的 long packet 输出 payload 并产生 pkt_start / pkt_done / pkt_bytes / pkt_*_err 等侧带。

---

## 13.2 Fixed Slot Packer（`rtl/core/fixed_slot_packer.sv`）

```text
ST_IDLE
   │
   ▼
ST_CAPTURE   （从上游捕获原始 payload）
   │
   ▼
ST_OUTPUT    （按 12B header + 12288B sample + 9B CQ + padding 重放）
   │
   ▼
slot_done → IDLE
```

---

## 13.3 DDR Ring Buffer Controller（`rtl/core/ddr_ringbuffer_controller.sv`）

内部包含：接收上游 AXIS slot 流、按 ring 基址/长度分配、AXI 写突发、提交指针与描述符 FIFO、以及 Host 侧 issue_head_read / consume_head 触发的读路径。具体状态与写/读段逻辑见该模块源码。

---

## 13.4 SPI Driver 状态机

本仓库当前 RTL 未包含 AWR2243 SPI 驱动实现；若后续添加，可在此补充与代码一致的状态机描述。

---

# 14 上位机解析流程

Host 侧按「队首描述符 + 固定长度 slot」读取：

1. 通过 CSR 读 **HEAD_DESC_ADDR_LO/HI**、**HEAD_DESC_INFO**、**HEAD_DESC_SEQ** 得到当前队首 slot 的 DDR 地址、字节数（slot_bytes）、valid_good、overflow_err。
2. 可选：写 **READ_CMD.issue_head_read** 触发控制器侧预读/锁定队首。
3. 通过 XDMA AXI-MM 从该地址读取 **HEAD_DESC_INFO.slot_bytes** 字节（即本 slot 总长，默认 12352B）。
4. 解析 slot：前 12B 为 4 个 RX header，其后为 12288B sample 固定区、9B CQ 区与 43B padding。
5. 实际有效 sample 数由 Host 根据业务配置或 payload 上下文推导；尾部补零与 CQ padding 可直接忽略。
6. 消费完成后写 **READ_CMD.consume_head** 释放队首，再读下一 slot。

---

# 15 联调步骤

## Step 1：PCIe/XDMA 独立打通

* Host 访问 FPGA BRAM/寄存器
* 验证 BAR
* 验证 C2H/MM 路径

## Step 2：DDR 通路打通

* FPGA 写测试 slot 到 DDR
* Host 读回并校验

## Step 3：时钟/复位验证

* 检查各域时钟稳定
* 检查 reset release 顺序
* 检查 CDC FIFO 工作

## Step 4：CSI 接收验证

* lane lock
* packet 统计
* short/long packet 分离
* CRC/ECC 检查

## Step 5：固定 slot 封装验证

* payload 拷贝正确
* 1024×SAMPLE_UNIT_BYTES 固定区补零正确
* CQ 区 raw12 对齐与补零正确
* slot 长度与 `slot_packer_macros.svh` 一致（默认 12352B）

## Step 6：全链路验证

* Radar -> CSI -> FPGA -> DDR -> XDMA -> Host
* Host 正确读取 slot
* Host 正确解析 AWR 原始结构

## Step 7：压力测试

* 长时间运行
* overflow 行为验证
* Host 读取不及时场景验证

---

# 16 性能指标

| 指标                | 目标       |
| ----------------- | -------- |
| 最大雷达输入速率          | 2.1Gbps  |
| AXI 内部带宽          | 64Gbps   |
| DDR 理论带宽          | 76.8Gbps |
| PCIe Gen3 x8 理论带宽 | 63Gbps   |
| 默认 slot 大小（slot_packer 宏） | 12352B（可配置） |

# 传输速率分析： 
CSI2: awr2243最大传输速率：4 x 22.5Msps x (12x2)bit = 2160 Mbps (2.1Gbps) 
AXI: 256 bit @ 250 MHz = 64Gbps 
DDR4: 2400MT/s x 32bit = 76.8 Gbps 
PCIe Gen3 x 8: 8GT/s x 128b/130b x 8lane = 63Gbps 
雷电4: 理论40Gbps 实际是22Gbps(另外的是给视频的，暂时用不了)

系统设计上内部链路带宽充足，实际瓶颈主要取决于：

* Host 接口有效吞吐
* XDMA 实际持续读带宽
* 上位机存储与解析能力

---

# 17 CSR 生成与接入

当前仓库将 **`rdl/ddr_ringbuffer_controller.rdl`** 接成可重复生成的 CSR 流程，产物包括：

* `rtl/generated/ddr_ringbuffer_controller_csr_pkg.sv`
* `rtl/generated/ddr_ringbuffer_controller_csr.sv`
* `sw/include/generated/ddr_ringbuffer_controller_csr.h`
* `tb/uvm/ral/ddr_ringbuffer_controller_csr_ral_pkg.sv`

## 17.1 重新生成

安装本地依赖（首次）：

```bash
./tools/rdl/install_peakrdl_deps.sh
```

生成所有 CSR 产物：

```bash
./tools/rdl/generate_ddr_ringbuffer_controller_csr.sh
```

依赖安装在 `tools/rdl/.deps/`。

## 17.2 RTL 侧使用

**`rtl/core/ddr_ringbuffer_controller_axil.sv`** 为带 CSR 的包装层：

* 对外 AXI4-Lite slave CSR 口
* 内部实例化 PeakRDL 生成的 CSR regblock 与 `ddr_ringbuffer_controller`
* CTRL/RING_BASE/RING_SIZE/READ_CMD 写入控制器；状态、指针、计数、LAST_COMMIT_*、HEAD_DESC_* 回填只读寄存器

RDL 约束：地址 64bit，ring size/occupancy/counter 32bit，slot byte count 24bit。若 RTL 参数更大，需同步改 `rdl/ddr_ringbuffer_controller.rdl`，否则 axil 包装内静态检查会报错。

编译带 CSR 的版本可使用 **`rtl/ddr_ringbuffer_controller_axil.f`**。

## 17.3 Host 软件侧使用

* 头文件：**`sw/include/generated/ddr_ringbuffer_controller_csr.h`**
* 示例：**`sw/examples/ddr_ringbuffer_controller_csr_example.c`**

将 BAR0 + CSR 偏移映射为结构体指针后访问：

```c
volatile ddr_ringbuffer_controller_csr_t *csr =
    (volatile ddr_ringbuffer_controller_csr_t *)((volatile uint8_t *)bar0 + csr_offset);
```

示例中提供：`ddr_ringbuffer_controller_configure()`、`ddr_ringbuffer_controller_issue_head_read()`、`ddr_ringbuffer_controller_consume_head()`、`ddr_ringbuffer_controller_head_desc_valid()` 等，与 RDL 寄存器定义一致。
