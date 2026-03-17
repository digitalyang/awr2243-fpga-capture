

# AWR2243 + FPGA 高速雷达数据采集系统

基于 **AWR2243 + FPGA + DDR4 + PCIe XDMA** 的高速毫米波雷达数据采集系统。

## 设计目标

* AWR2243 雷达配置与启动（SPI 脚本化控制）
* MIPI CSI-2 数据接收与 long packet payload 提取
* 固定长度 slot 封装（1024 sample × 12B + CQ + header，64B 对齐）
* DDR4 环形缓冲区存储与指针管理
* PCIe XDMA 数据读取
* Host 软件按固定 slot 解析雷达原始数据

设计原则：**FPGA 只做数据搬运与封装，Host 负责解析 AWR payload 语义；无论实际 Ns 是否小于 1024，统一按固定 slot 存储。**

## 构建与验证

统一入口脚本：

```sh
tools/build_and_verify.sh
```

常用 target：`--target sanity`（默认）、`--target ddr`、`--target awr-bar0`。详见 [BUILD_AND_VERIFY.md](BUILD_AND_VERIFY.md)。

### 仿真（Cocotb + Verilator）

RTL 仿真不依赖 Vivado，使用 Verilator + cocotb：

| 仿真对象 | 脚本 | 说明 |
|----------|------|------|
| CSI Packet Extractor | `python tb/cocotb/run_csi_packet_extractor.py` | 提取器单模块回归 |
| Fixed Slot Packer | `python tb/cocotb/run_fixed_slot_packer.py` | 固定 slot 封装回归 |
| DDR Ring Buffer | `python tb/cocotb/run_ddr_ringbuffer_controller.py` | 环形缓冲区回归 |
| AWR2243 BAR0 + CSR | `tools/build_and_verify.sh --target awr-bar0` | BAR0 译码 + AWR CSR 回归 |
| 全链路 Pipeline | `python tb/cocotb/run_sim_pipeline.py` | extractor + packer + ringbuffer |

全链路仿真中 DDR 双口 RAM 由 `tb/models/xpm_memory_sdpram_stub.sv` 提供纯 RTL 替代，无需 Vivado。

---

## 系统总体架构

```text
AWR2243 Radar
   |  MIPI CSI-2 (4-lane, 2.1Gbps)
   v
CSI RX Subsystem (video_aclk = 200MHz)
   |  AXI-Stream
   v
AXIS Async FIFO (200MHz -> 250MHz)
   |
   v
CSI Packet Extractor --- VC/DT filter, long packet payload extraction
   |  AXI-Stream + sideband
   v
Fixed Slot Packer ------ fixed slot packing (12B hdr + 12288B sample + 9B CQ + 43B pad = 12352B)
   |  AXI-Stream + slot sideband
   v
DDR Ring Buffer Controller -- slot buffer -> AXI-MM burst write DDR -> pointer/descriptor mgmt
   |  AXI-MM (256bit @ 250MHz)         +----------------------------+
   |                                   |   AXI SmartConnect         |
   +-- M0: Ring Buffer Controller ---->|                            |
   |   (AXI-MM write to DDR)           |   arbitration + R/W        |--> S0: MIG --> DDR4
   |                                   |   concurrent (Xilinx IP)   |      (1-2GB ring)
   +-- M1: XDMA ---------------------->|                            |
       (C2H read DDR / BAR0 CSR)       +----------------------------+

Data flow:
  1. Host reads BAR0 CSR HEAD_DESC_ADDR to get head slot DDR address
  2. Host programs XDMA C2H descriptor -> XDMA reads DDR via SmartConnect
  3. Host writes CSR consume_head -> release head slot, ring space reclaimed

Control plane:
  Host --> BAR0 AXI-Lite --> axil_bar0_decode --+-- 0x000-0x08C: Ring Buffer CSR
                                                +-- 0x090+:     AWR2243 Control CSR

AWR2243 Control <-- SPI Master + Script RAM + Config Sequencer
```

### 部署架构说明

* **AXI SmartConnect**（Xilinx IP）负责仲裁，支持多 outstanding、读写并发。仿真中由 `rtl/axi/axi_ddr_subsystem.sv` 行为模型替代
* **DDR 作为环形缓冲区**：数据必须先写入 DDR，Host 再通过 XDMA C2H 从 DDR 读出。DDR ring 分配 1-2GB，可缓冲 ~84,000-170,000 个 slot
* **XDMA C2H**：Host 通过 CSR 获取队首 slot 地址后，直接编程 XDMA C2H 描述符从 DDR 搬运数据，无需 Ring Buffer Controller 参与读回
* Ring Buffer Controller 的 `m_axi` 仅做写入，内置的 AXI 读回路径（`issue_head_read` -> `m_axis_rd`）保留用于调试与扩展

---

## 项目结构与模块索引

### RTL 模块

| 目录 | 说明 | 详细文档 |
|------|------|----------|
| [`rtl/core/`](rtl/core/) | 核心数据通路与控制模块 | [rtl/core/README.md](rtl/core/README.md) |
| [`rtl/axil/`](rtl/axil/) | BAR0 AXI-Lite 地址译码 | [rtl/axil/README.md](rtl/axil/README.md) |
| [`rtl/axi/`](rtl/axi/) | AXI DDR 子系统（双主仲裁） | [rtl/axi/README.md](rtl/axi/README.md) |
| [`rtl/pcie/`](rtl/pcie/) | PCIe Endpoint + DMA Shell | [rtl/pcie/README.md](rtl/pcie/README.md) |
| [`rtl/if/`](rtl/if/) | 接口定义 (AXI4-Lite, AXI4-MM, AXI-Stream, PCIe RC) | [rtl/if/README.md](rtl/if/README.md) |
| [`rtl/pkg/`](rtl/pkg/) | SystemVerilog Package（类型/常量/工具函数） | [rtl/pkg/README.md](rtl/pkg/README.md) |
| [`rtl/include/`](rtl/include/) | 宏定义头文件（参数默认值） | [rtl/include/README.md](rtl/include/README.md) |
| [`rtl/generated/`](rtl/generated/) | PeakRDL 生成的 CSR RTL | [rtl/generated/README.md](rtl/generated/README.md) |

### 核心模块一览

| 模块 | 文件 | 功能 |
|------|------|------|
| CSI Packet Extractor | `rtl/core/csi_packet_extractor.sv` | 按 VC/DT 过滤 CSI-2 long packet，提取 payload 并输出错误侧带 |
| Fixed Slot Packer | `rtl/core/fixed_slot_packer.sv` | 将变长 packet 封装为固定 12352B slot（header + sample + CQ + padding） |
| DDR Ring Buffer Controller | `rtl/core/ddr_ringbuffer_controller.sv` | 接收 slot 流 -> XPM 缓冲 -> AXI-MM burst 写 DDR -> 环形指针管理 |
| DDR Ring Buffer + AXI-Lite | `rtl/core/ddr_ringbuffer_controller_axil.sv` | Ring buffer + PeakRDL CSR 包装，对外 AXI4-Lite slave |
| AWR2243 Control Top | `rtl/core/awr2243_ctrl_top.sv` | AWR2243 完整控制子系统（CSR + sequencer + SPI + reset + status） |
| SPI Master Engine | `rtl/core/spi_master_engine.sv` | 16bit 全双工 SPI 主机，可配置分频/CS 时序/超时 |
| BAR0 Decode | `rtl/axil/axil_bar0_decode.sv` | PCIe BAR0 地址译码，分发 ring CSR 与 AWR CSR |
| AXI DDR Subsystem | `rtl/axi/axi_ddr_subsystem.sv` | 双主轮询仲裁接入 DDR |
| PCIe Endpoint DMA | `rtl/pcie/pcie_endpoint_dma_shell.sv` | BAR MMIO + 描述符 DMA 引擎 |

### 其他目录

| 目录 | 说明 |
|------|------|
| `rdl/` | PeakRDL 寄存器描述文件（`.rdl`） |
| `sw/` | Host 侧 C 头文件与示例代码 |
| `tb/cocotb/` | Cocotb 验证平台（testbench、driver、monitor、scoreboard） |
| `tb/models/` | 仿真行为模型（XPM stub、CSI mock、async FIFO 等） |
| `tb/uvm/` | UVM 验证环境（可选） |
| `tools/` | 构建/生成/CI 脚本 |
| `docs/` | 设计文档与仿真平台说明 |

---

## Slot 数据结构

Slot 布局与尺寸由 `rtl/pkg/slot_packer_pkg.sv` 与 `rtl/include/slot_packer_macros.svh` 定义。

```text
slot (64B aligned, default 12352B)
+-- rx_headers    4 x 24bit = 12B     word0[5:2]=chirp_profile, word0[1:0]=channel_id, word1[11:0]=chirp_num
+-- sample_area   1024 x 12B = 12288B  zero-padded if Ns < 1024
+-- CQ_area       6 x 12bit = 9B       raw 64bit CQ in raw12 alignment
+-- padding       43B                   to 64B boundary
```

Slot 总长度计算：`align_up(12 + 12288 + 9, 64) = 12352B`。修改 `slot_packer_macros.svh` 中宏可改变布局。

---

## DDR Ring Buffer 管理

### 指针关系

```text
rd_ptr <= commit_ptr <= wr_ptr
```

* **wr_ptr**：下一 slot 写入起始地址
* **commit_ptr**：已完整写入、可被 Host 读取的提交边界
* **rd_ptr**：Host 已消费边界（consume_head 推进）

### CSR 控制（RDL 定义）

通过 `rdl/ddr_ringbuffer_controller.rdl` 定义，BAR0 偏移 **0x000–0x08C**：

| 分类 | 寄存器 |
|------|--------|
| 配置 | CTRL（enable, allow_overwrite, drop_invalid_slot, drop_on_no_space）、RING_BASE_LO/HI、RING_SIZE_BYTES |
| 指针 | WR_PTR、RD_PTR、COMMIT_PTR（各 64bit，LO/HI） |
| 占用 | USED_BYTES、FREE_BYTES、COMMITTED_BYTES |
| 计数 | WRAP_COUNT、OVERFLOW_COUNT、DROP_COUNT |
| 描述符 | HEAD_DESC_*（队首）、LAST_COMMIT_*（最近提交） |
| 命令 | READ_CMD（issue_head_read / consume_head） |

### 消费逻辑（Host 与 Ring Buffer Controller 的协调）

Ring Buffer Controller（M0）和 XDMA（M1）在 SmartConnect 上是两个独立的 AXI master，彼此没有直接信号连接。Controller **无法感知 XDMA 是否已经从 DDR 读走了某个 slot 的数据**。因此，ring 空间的回收完全依赖 Host 软件通过 CSR 显式通知：

```text
Ring Buffer Controller                    Host Software
        |                                       |
  [write slot to DDR]                           |
  [commit -> push desc FIFO]                    |
  [HEAD_DESC CSR updated]                       |
        |                              [read HEAD_DESC_ADDR from CSR]
        |                              [program XDMA C2H descriptor]
        |                              [XDMA reads DDR via SmartConnect]
        |                              [wait C2H done]
        |                              [write READ_CMD.consume_head = 1]
        |                                       |
  [receive consume_head pulse]  <--- AXI-Lite --|
  [pop desc FIFO head]                          |
  [advance rd_ptr]                              |
  [free ring space]                             |
        |                              [next slot...]
```

关键点：

* **rd_ptr 仍然必要**：它标记了 Host 已确认消费的边界。只有 `consume_head` 推进 `rd_ptr` 后，对应的 ring 空间才被释放，Controller 才能写入新 slot
* **Controller 不感知 XDMA 读取**：XDMA 通过 SmartConnect 直接读 DDR，Controller 无从得知。消费确认完全靠 Host 写 `consume_head`
* **Host 软件是协调者**：Host 负责保证 "先让 XDMA 读完数据，再写 `consume_head`"。如果 Host 提前 consume 了还没读完的 slot，XDMA 可能读到被新数据覆盖的内容
* **单步 consume**：每次 `consume_head` 只释放 FIFO 队首一个 slot。批量消费需要连续写多次

### 溢出策略

由 CTRL 位域控制：`drop_on_no_space`（无空间时丢弃）、`allow_overwrite`（覆盖未读）、`drop_invalid_slot`（丢弃无效 slot）。

---

## AWR2243 控制子系统

BAR0 偏移 **0x090+** 经 `axil_bar0_decode` 译码后接入 `awr2243_ctrl_top`。

子系统内部包含：

| 子模块 | 功能 |
|--------|------|
| `awr2243_cfg_sequencer` | 多阶段配置状态机（init -> rf -> profile -> frame -> monitor -> start/stop） |
| `awr2243_cmd_fetch` | PC 驱动的脚本指令提取 |
| `awr2243_cmd_decode` | 指令解码与 SPI/delay/GPIO 操作执行 |
| `awr2243_script_ram` | 脚本存储 + 元数据表（base_addr / len per script） |
| `awr2243_reset_ctrl` | nRESET / SOP 引脚时序控制 |
| `awr2243_status_mon` | HOST_IRQ / nERROR 状态监控与计数 |
| `awr2243_timer` | 通用延时/超时计时器 |
| `spi_master_engine` | 16bit SPI 主机 |

CSR 定义：`rdl/awr2243_control.rdl`。配置流程详见 [docs/awr2243_configuration.md](docs/awr2243_configuration.md)。

---

## 时钟域规划

| 时钟域 | 频率 | 覆盖模块 |
|--------|------|----------|
| sys_clk | 100MHz | 顶层控制、CSR 寄存器块、软复位 |
| pcie_clk | 100MHz | XDMA 用户接口、PCIe 配置与中断 |
| csi_rx_clk | 200MHz | D-PHY / CSI-2 RX、CSI Packet Extractor |
| axi_clk | 250MHz | Slot Packer、DDR Ring Buffer、AXI Interconnect、MIG |
| spi_clk | 50MHz | AWR2243 SPI 控制 |

关键 CDC 路径：`csi_rx_clk -> axi_clk` 通过 AXIS Async FIFO 跨域，保持 packet 边界与 tlast。

---

## CSR 生成

| CSR | RDL 源 | 生成脚本 |
|-----|--------|----------|
| DDR Ringbuffer | `rdl/ddr_ringbuffer_controller.rdl` | `tools/rdl/generate_ddr_ringbuffer_controller_csr.sh` |
| AWR2243 Control | `rdl/awr2243_control.rdl` | `tools/rdl/generate_awr2243_control_csr.sh` |

产物：`rtl/generated/` 下 RTL、`sw/include/generated/` 下 C 头文件、`tb/uvm/ral/` 下 RAL。首次安装依赖：`tools/rdl/install_peakrdl_deps.sh`。

---

## Host 侧数据读取流程（XDMA C2H MM 模式）

```text
+-------------------------------------------------------------------+
| Host Software                                                     |
|                                                                   |
|  1. read HEAD_DESC_INFO.desc_valid  --> check slot available      |
|  2. read HEAD_DESC_ADDR_LO/HI      --> get slot DDR address       |
|  3. read HEAD_DESC_INFO.slot_bytes  --> get slot size (12352B)    |
|  4. program XDMA C2H descriptor                                   |
|     src = HEAD_DESC_ADDR, len = slot_bytes, dst = host_buf        |
|  5. start XDMA C2H transfer        --> XDMA reads DDR directly    |
|  6. wait for C2H completion                                       |
|  7. parse slot: 12B header -> 12288B sample -> 9B CQ -> padding   |
|  8. write READ_CMD.consume_head     --> release head, reclaim ring|
|  9. goto step 1                                                   |
+-------------------------------------------------------------------+
```

* HEAD_DESC 是描述符 FIFO 队首的**组合逻辑直出**，读 CSR 即可获取，无需触发 `issue_head_read`
* XDMA 通过 SmartConnect 直读 DDR，不经过 Ring Buffer Controller 的读回路径
* `consume_head` 为 singlepulse 寄存器，写 `READ_CMD = 0x2` 即可

Host 头文件：`sw/include/generated/ddr_ringbuffer_controller_csr.h`，示例：`sw/examples/ddr_ringbuffer_controller_csr_example.c`。

---

## 性能指标与带宽分析

| 环节 | 带宽 | 说明 |
|------|------|------|
| 雷达输入 | 2.1Gbps (260MB/s) | 4RX × 22.5Msps × 24bit |
| AXI 内部带宽 | 64Gbps | 256bit @ 250MHz |
| DDR4 理论带宽 | 76.8Gbps | 2400MT/s × 32bit |
| DDR4 实际持续读写 | ~30-46Gbps | 效率 40-60% |
| PCIe Gen3 ×8 | ~56Gbps (7GB/s) | 8GT/s × 128b/130b × 8lane |
| 默认 slot 大小 | 12352B | 可配置 |

| DDR Ring 指标 | 1GB ring | 2GB ring |
|--------------|----------|----------|
| 可存 slot 数 | ~84,800 | ~169,600 |
| 不读取可缓冲时间 | ~4 秒 | ~8 秒 |

系统写入速率 260MB/s，Host 读取能力 ~5-6 GB/s（PCIe Gen3 ×8 持续），**读取速度是写入速度的 20 倍以上**。DDR ring 在正常运行下占用率极低。

推荐配置：`allow_overwrite=0`（不覆盖未读 slot）、`drop_on_no_space=1`（ring 满时丢弃新 slot 而非背压上游）。

---

## 架构亮点

### 1. 固定 Slot 策略

无论实际 Ns 是否小于 1024，统一按固定 12352B slot 存储。Host 按固定偏移读取，无需解析变长头部。DDR 地址管理极简——slot stride 固定，指针推进即加常数。相比 TI DCA1000EVM 的变长 packet 方案，消除了 Host 侧解析开销和丢包时的半包残留风险。

### 2. 三级指针 Ring Buffer（rd_ptr / commit_ptr / wr_ptr）

引入 `commit_ptr` 保证数据一致性：AXI burst 全部完成后才提交，Host 不会看到半写的 slot。不需要 Host 侧做 fence 或 barrier。描述符 FIFO 队首组合逻辑直出，Host 随时可读。

### 3. DDR 先存后取 + XDMA C2H 直读

DDR 作为大容量环形缓冲区（1-2GB），完全解耦雷达写入速率与 Host 读取节奏。XDMA C2H 直接从 DDR 读数据，不经过 Ring Buffer Controller 的读回路径，写入和读取走 SmartConnect 的独立 AXI 通道，互不阻塞。

### 4. AWR2243 脚本化控制

AWR2243 的配置流程（SPI 写寄存器、延时等待、GPIO 控制、IRQ 等待）抽象为脚本指令集，由 FPGA 内部 sequencer 执行。减少 Host 实时介入，配置时序精度从 Host CPU 的毫秒级提升到 FPGA 的微秒级。支持错误自动恢复。

### 5. 完整可观测性

CSR 暴露三类计数器（wrap/overflow/drop）、细粒度错误标志（cfg_align/no_space/slot_proto/axi_wr_resp 等）、队首与最近提交描述符快照。运行时可通过 BAR0 实时监控系统状态。

---

## 改进方向

### 短期优化

1. **Slot Packer cut-through 模式**：当前 Packer 先将整个 slot 写入内部 BRAM 再读出（store-and-forward），延迟约 2×slot_beats。可改为边收边发，header/sample 区直通，仅在尾部补零和 CQ 追加时使用缓冲
2. **AXI 写 outstanding 提升**：当前 Ring Buffer Controller 单 slot 在途，每次 burst 串行 AW->W->B。可增加 outstanding 到 2-4，AW 提前发出，W 数据流水跟上
3. **增大 MAX_BURST_LEN**：当前默认 16，一个 12352B slot 需 25 次 burst。增大到 64 或 256 可减少 AW/B 握手开销

### 中期扩展

4. **运行时可配置 sample 数**：当前固定 1024 sample。对 Ns=128 场景，slot 从 12352B 缩至 ~1600B，DDR 带宽利用率从 ~12% 提升到 ~95%。可通过 CSR 运行时配置实际 Ns
5. **Async FIFO 背压监控**：CSI RX -> Packer 之间的 Async FIFO 缺少 overflow 计数器。增加 FIFO 水位和溢出事件统计，供 Host 监控链路健康度

### 长期演进

6. **多雷达级联**：扩展到 4 片 AWR2243 级联（4x2.1Gbps = 8.4Gbps），需要多路 CSI RX -> 多路 Extractor -> 合并/独立 Packer、DDR ring 分区或多 ring
7. **XDMA C2H Streaming 模式**：当前使用 C2H MM 模式（Host 编程描述符）。未来可探索 C2H Streaming 模式，Ring Buffer Controller 读回 DDR 数据后通过 `m_axis_rd` 直推 XDMA C2H 流式通道，进一步降低 Host CPU 开销

---

## 联调步骤

1. **PCIe/XDMA 打通** — BAR0 读写验证、XDMA C2H MM 路径验证
2. **DDR 通路打通** — Ring Buffer Controller 写测试 slot 到 DDR -> XDMA C2H 读回校验
3. **时钟/复位验证** — 各域时钟稳定、reset release 顺序、CDC FIFO
4. **CSI 接收验证** — lane lock、packet 统计、CRC/ECC
5. **Slot 封装验证** — payload 正确、补零正确、slot 长度一致
6. **全链路验证** — Radar -> CSI -> FPGA -> DDR -> XDMA C2H -> Host
7. **压力测试** — 长时间运行、drop_count 监控、Host 读取不及时场景验证
