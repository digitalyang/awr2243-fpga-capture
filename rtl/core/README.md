# RTL Core Modules

本目录包含雷达数据采集系统的核心数据通路与控制模块。

---

## 模块总览

| 模块 | 文件 | 功能 |
|------|------|------|
| [CSI Packet Extractor](#csi-packet-extractor) | `csi_packet_extractor.sv` | CSI-2 long packet 过滤与 payload 提取 |
| [Fixed Slot Packer](#fixed-slot-packer) | `fixed_slot_packer.sv` | 变长 packet -> 固定长度 slot 封装 |
| [DDR Ring Buffer Controller](#ddr-ring-buffer-controller) | `ddr_ringbuffer_controller.sv` | slot -> XPM 缓冲 -> AXI-MM DDR 写入 + 环形指针管理 |
| [DDR Ring Buffer + AXI-Lite](#ddr-ring-buffer-controller-axil) | `ddr_ringbuffer_controller_axil.sv` | Ring buffer + PeakRDL CSR 包装 |
| [AWR2243 Control Top](#awr2243-control-top) | `awr2243_ctrl_top.sv` | AWR2243 完整控制子系统 |
| [AWR2243 Config Sequencer](#awr2243-config-sequencer) | `awr2243_cfg_sequencer.sv` | 多阶段初始化/配置/启停状态机 |
| [AWR2243 Command Fetch](#awr2243-command-fetch) | `awr2243_cmd_fetch.sv` | PC 驱动的脚本指令提取 |
| [AWR2243 Command Decode](#awr2243-command-decode) | `awr2243_cmd_decode.sv` | 指令解码与 SPI/delay/GPIO 操作 |
| [AWR2243 Script RAM](#awr2243-script-ram) | `awr2243_script_ram.sv` | 脚本存储 + 元数据表 |
| [AWR2243 Reset Control](#awr2243-reset-control) | `awr2243_reset_ctrl.sv` | nRESET / SOP 引脚时序控制 |
| [AWR2243 Status Monitor](#awr2243-status-monitor) | `awr2243_status_mon.sv` | HOST_IRQ / nERROR 状态监控 |
| [AWR2243 Timer](#awr2243-timer) | `awr2243_timer.sv` | 通用延时/超时计时器 |
| [SPI Master Engine](#spi-master-engine) | `spi_master_engine.sv` | 16bit 全双工 SPI 主机 |
| CSR Register Block | `csr_reg_block.sv` | 通用 CSR 寄存器块 |

---

## CSI Packet Extractor

**文件**：`csi_packet_extractor.sv`
**宏**：`../include/csi_packet_extractor_macros.svh`
**Package**：`../pkg/csi_packet_pkg.sv`

### 功能

接收 CSI-2 RX Subsystem 输出的 AXI-Stream 流，按 Virtual Channel (VC) 和 Data Type (DT) 过滤，识别 long packet 并转发其 payload。同时产生 packet 级侧带信号供下游使用。

### 状态机

```text
ST_IDLE --> ST_CHECK --+-- ST_ACCEPT (VC/DT match -> forward payload beats)
                       +-- ST_DROP   (mismatch -> discard until tlast)
```

### 接口

| 端口方向 | 信号 | 说明 |
|----------|------|------|
| input | `s_axis` (AXI-Stream slave) | CSI-2 RX 输出的原始 packet 流 |
| input | `cfg_vc_en_i`, `cfg_vc_i` | VC 过滤使能与目标 VC |
| input | `cfg_dt_en_i`, `cfg_dt_i` | DT 过滤使能与目标 DT |
| output | `m_axis` (AXI-Stream master) | 过滤后的 payload 流 |
| output | `pkt_start_o`, `pkt_done_o` | packet 边界脉冲 |
| output | `pkt_bytes_o` | 已接收 payload 字节数 |
| output | `pkt_seq_o` | packet 序号（自增） |
| output | `pkt_valid_good_o` | packet 有效且无错误 |
| output | `pkt_crc_err_o/ecc_err_o/trunc_err_o` | 错误标志 |

### 工作原理

1. **IDLE**：等待 `s_axis.tvalid` 且 `tuser` 中 `pkt_start` 位置位
2. **CHECK**：锁存首 beat 的 `tuser`，解析 VC、DT、payload length；与配置比较
3. **ACCEPT**：VC/DT 匹配，内部 FIFO 缓冲后按 `m_axis` 输出，tkeep 跟踪有效字节；tlast 到达时输出 `pkt_done_o` 与累计字节数
4. **DROP**：不匹配，消耗 s_axis 至 tlast 但不输出

内部使用 `FIFO_DEPTH` 深度的同步 FIFO 解耦上下游背压。payload 字节数通过逐 beat 累加 tkeep popcount 得到。

### 参数

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `AXIS_DATA_W` | 256 | AXI-Stream 数据位宽 |
| `FIFO_DEPTH` | 16 | 内部 FIFO 深度 |
| `PKT_SEQ_W` | 16 | packet 序号位宽 |

---

## Fixed Slot Packer

**文件**：`fixed_slot_packer.sv`
**宏**：`../include/slot_packer_macros.svh`
**Package**：`../pkg/slot_packer_pkg.sv`

### 功能

将上游 CSI Packet Extractor 输出的变长 packet 流封装为固定长度 slot，使 Host 端可以按固定偏移读取，无需变长寻址。

### Slot 布局（默认 12352B）

```text
+----------------------------------+  offset 0
| RX Headers (4 x 24bit = 12B)    |
+----------------------------------+  offset 12
| Sample Area (1024 x 12B)        |
| = 12288B, zero-padded           |
+----------------------------------+  offset 12300
| CQ Area (6 x 12bit = 9B)        |
+----------------------------------+  offset 12309
| Padding (43B zeros)              |
+----------------------------------+  offset 12352 (64B aligned)
```

### 状态机

```text
ST_IDLE
  |
  v
ST_CAPTURE ---- capture upstream payload, write to beat-wide RAM
  |
  v
ST_CAP_FLUSH -- flush last partial beat
  |
  v
ST_ZERO_MID --- zero-fill remaining sample area
  |
  v
ST_CQ_WRITE --- write CQ data
  |
  v
ST_CQ_FLUSH --- flush CQ tail
  |
  v
ST_ZERO_TAIL -- zero-pad to alignment boundary
  |
  v
ST_OUT_READ --- read beat from RAM
  |
  v
ST_OUT_SEND --- output via m_axis
  |
  v
ST_IDLE (slot_done)
```

### 工作原理

1. **捕获阶段**：接收上游 AXI-Stream beats，直接写入 beat-wide 内部 RAM（避免大 packet buffer 随机字节读取）。前 12B 保留为原始 RX header
2. **补零阶段**：sample 区不足 1024 samples 时补零；CQ 区按 raw12 格式写入后补零
3. **对齐阶段**：tail padding 补零至 `ALIGN_BYTES`（默认 64B）边界
4. **输出阶段**：从 RAM 顺序读出每个 beat，通过 `m_axis` 输出，最后一 beat 置 `tlast`

输出侧带：`slot_start_o`、`slot_done_o`、`slot_bytes_o`（= 12352）、`slot_seq_o`、`slot_valid_good_o`、`slot_overflow_err_o`。

### 参数

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `AXIS_DATA_W` | 256 | 数据位宽 |
| `SAMPLE_SLOT_NUM` | 1024 | sample 槽位数 |
| `SAMPLE_UNIT_BYTES` | 12 | 每 sample 字节数 |
| `CQ_AREA_BYTES` | 9 | CQ 区字节数 |
| `HEADER_BYTES` | 12 | header 字节数 |
| `ALIGN_BYTES` | 64 | 对齐粒度 |

---

## DDR Ring Buffer Controller

**文件**：`ddr_ringbuffer_controller.sv`
**宏**：`../include/ddr_ringbuffer_macros.svh`
**Package**：`../pkg/ddr_ringbuffer_pkg.sv`

### 功能

接收上游 slot 流，缓冲至内部 XPM 双口 RAM，然后以 AXI-MM burst 写入 DDR。维护环形缓冲区的写/提交/读指针，管理描述符 FIFO，支持 Host 通过读命令获取队首描述符并消费。

### 架构

```text
Upstream Slot Stream (AXI-Stream)
        |
        v
   +----------------+
   |  Slot Buffer   |  XPM SDPRAM (data+keep merged)
   |  (beat-wide)   |
   +-------+--------+
           | AXI-MM Write Burst
           v
   +----------------+
   |  AXI Master    |  address alloc + burst gen
   |  Write Path    |         +--------------------------+
   +-------+--------+         |   AXI SmartConnect       |
           |                  |                          |
           +-- M0 ----------->|   Xilinx IP              |--> MIG --> DDR4
           |                  |   R/W concurrent arb     |      (1-2GB ring)
           |  M1: XDMA C2H -->|                          |
           |                  +--------------------------+
           v
   Descriptor FIFO --> HEAD_DESC CSR (combinational, always readable)
                   --> consume_head  (singlepulse, release head)
```

### 部署数据流（XDMA C2H MM 模式）

1. **写入**：Ring Buffer Controller 通过 SmartConnect M0 将 slot 写入 DDR
2. **Host 查询**：读 CSR `HEAD_DESC_ADDR/INFO` 获取队首 slot 的 DDR 地址和大小（组合逻辑直出，无需 `issue_head_read`）
3. **Host 搬运**：编程 XDMA C2H 描述符，XDMA 通过 SmartConnect M1 直接从 DDR 读数据搬到 Host 内存
4. **Host 释放**：写 CSR `consume_head` -> 描述符 FIFO 推进 -> `rd_ptr` 前移 -> ring 空间回收

内置的 AXI 读回路径（`issue_head_read` -> `m_axis_rd`）保留用于调试和验证，生产环境中不在关键路径上。

### 指针管理

```text
Ring Base ----------------------------------------- Ring Base + Ring Size
  |                                                    |
  +-- rd_ptr ---- commit_ptr ---- wr_ptr --------------+
  |   (consumed   (committed,     (next write          |
  |    boundary)   host-readable)  position)           |
  +------------------- wrap around --------------------+
```

* **写入流程**：slot_start -> 接收 beats 到 buffer -> slot_done -> 计算 DDR 地址 -> AXI burst -> commit -> 推入描述符 FIFO
* **读取流程（C2H MM）**：Host 读 HEAD_DESC CSR -> 编程 XDMA C2H -> XDMA 直读 DDR -> 写 consume_head -> rd_ptr 推进

### 溢出策略

| CTRL 位 | 作用 |
|---------|------|
| `cfg_enable` | 全局使能 |
| `cfg_allow_overwrite` | 允许覆盖未读 slot |
| `cfg_drop_invalid_slot` | 丢弃无效 slot |
| `cfg_drop_on_no_space` | 无空间时丢弃（否则背压） |

### 参数

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `CFG_AXI_ADDR_W` | 34 | AXI 地址位宽 |
| `AXIS_DATA_W` | 256 | 上游数据位宽 |
| `AXI_DATA_W` | 256 | DDR 侧数据位宽 |
| `SLOT_BUFFER_BYTES` | 12352 | 内部 slot buffer 大小 |
| `SLOT_STRIDE_BYTES` | 12352 | DDR 中 slot 步进 |
| `DESC_FIFO_DEPTH` | 8 | 描述符 FIFO 深度 |
| `MAX_BURST_LEN` | 16 | 最大 AXI burst 长度 |
| `RING_SIZE_BYTES_MAX` | 65536 | Ring 最大容量（CSR 支持 32bit，最大 4GB） |

### 推荐部署配置

| 配置项 | 推荐值 | 说明 |
|--------|--------|------|
| Ring 大小 | 1-2GB | 可缓冲 4-8 秒数据（~84,000-170,000 个 slot） |
| `allow_overwrite` | 0 | 不覆盖未读 slot，Host 读取速度远超写入 |
| `drop_on_no_space` | 1 | ring 满时丢弃新 slot 而非背压上游 |
| `drop_invalid_slot` | 1 | 丢弃无效 slot |

---

## DDR Ring Buffer Controller AXI-Lite

**文件**：`ddr_ringbuffer_controller_axil.sv`
**文件列表**：`../ddr_ringbuffer_controller_axil.f`

### 功能

在 `ddr_ringbuffer_controller` 外包装 PeakRDL 生成的 CSR regblock，对外提供 AXI4-Lite slave 接口。

* CTRL / RING_BASE / RING_SIZE / READ_CMD 映射到控制器输入
* STATUS / 指针 / 计数 / LAST_COMMIT_* / HEAD_DESC_* 回填到只读寄存器
* 总 CSR 空间 0x90 字节

---

## AWR2243 Control Top

**文件**：`awr2243_ctrl_top.sv`
**RDL**：`../../rdl/awr2243_control.rdl`
**配置说明**：[docs/awr2243_configuration.md](../../docs/awr2243_configuration.md)

### 功能

AWR2243 毫米波雷达的完整控制子系统，对外提供 AXI4-Lite slave CSR 接口和物理引脚（SPI、nRESET、SOP、HOST_IRQ、nERROR）。

### 内部架构

```text
AXI4-Lite Slave (CSR)
        |
        v
+----------------------------------------------+
|              awr2243_ctrl_top                |
|                                              |
|  +---------------+    +--------------------+ |
|  |  PeakRDL CSR  |--> | cfg_sequencer      | |
|  |  regblock     |    | (init/start/stop   | |
|  +---------------+    |  state machine)    | |
|                       +---------+----------+ |
|                                 |            |
|                       +---------v----------+ |
|                       | cmd_fetch          | |
|                       | (PC + script RAM)  | |
|                       +---------+----------+ |
|                                 |            |
|                       +---------v----------+ |
|                       | cmd_decode         | |  --> SPI SCLK/CS/MOSI
|                       | (SPI/delay/GPIO)   | |  <-- SPI MISO
|                       +--------------------+ |
|                                              |
|  +---------------+   +--------------------+  |
|  | reset_ctrl    |-->| nRESET, SOP[2:0]   |  |
|  +---------------+   +--------------------+  |
|                                              |
|  +---------------+   +--------------------+  |
|  | status_mon    |<--| HOST_IRQ, nERROR   |  |
|  +---------------+   +--------------------+  |
|                                              |
|  +---------------+                           |
|  | timer         |  delay / timeout          |
|  +---------------+                           |
|                                              |
|  +---------------+                           |
|  | spi_master    |  16bit SPI engine         |
|  +---------------+                           |
+----------------------------------------------+
```

### AWR2243 配置流程

1. Host 写 CONTROL.start_init -> sequencer 进入 INIT 阶段
2. 依次执行 init_script -> rf_script -> profile_script -> frame_script -> monitor_script
3. Host 写 CONTROL.start_sensor -> 执行 start_script -> 雷达开始出数据
4. Host 写 CONTROL.stop_sensor -> 执行 stop_script -> 雷达停止
5. 错误恢复：CONTROL.hard_reset 或 clear_error

---

## AWR2243 Config Sequencer

**文件**：`awr2243_cfg_sequencer.sv`

多阶段初始化配置状态机，编排 AWR2243 从硬复位到数据采集的完整流程：

```text
SEQ_IDLE -> SEQ_RESET -> SEQ_ENTER_SPI -> SEQ_INIT -> SEQ_RF ->
SEQ_PROFILE -> SEQ_FRAME -> SEQ_MONITOR -> SEQ_WAIT_START_IRQ ->
SEQ_START -> SEQ_RUNNING -> SEQ_STOP -> SEQ_DONE / SEQ_ERROR
```

支持 NULL script 跳过、超时检测、错误自动恢复（`AUTO_RECOVERY_EN`）。

---

## AWR2243 Command Fetch

**文件**：`awr2243_cmd_fetch.sv`

PC（Program Counter）驱动的指令提取单元：
* 根据 script_id 查找 `script_ram` 中的 base_addr 和 len
* 逐地址读取脚本指令，支持 advance / hold / jump
* 输出 `cmd_valid_o` + `cmd_word_o` + `pc_o` 供下游 decode 消费
* 到达脚本末尾时输出 `script_done_o`

---

## AWR2243 Command Decode

**文件**：`awr2243_cmd_decode.sv`

脚本指令解码与执行单元，支持的操作码（opcode）包括：
* **SPI_WRITE**：16bit SPI 写操作
* **SPI_READ**：16bit SPI 读操作
* **DELAY**：延时（支持 cycle / μs 两种单位）
* **GPIO_SET/CLR**：引脚控制
* **WAIT_IRQ**：等待 HOST_IRQ
* **JUMP**：脚本跳转
* **NOP / END**：空操作 / 脚本结束

输出 step_id、last_opcode、error_code 供上层监控。

---

## AWR2243 Script RAM

**文件**：`awr2243_script_ram.sv`

双功能存储：
* **指令存储**：深度 `DEPTH`（默认 1024），字宽 `WORD_W`（默认 32bit）的同步 RAM
* **元数据表**：每个 script_id 对应 (base_addr, len)，用于 cmd_fetch 定位脚本

支持运行时通过 CSR 写入脚本内容和元数据。

---

## AWR2243 Reset Control

**文件**：`awr2243_reset_ctrl.sv`

管理 AWR2243 的硬复位序列：

```text
RST_IDLE -> RST_DRIVE_SOP -> RST_ASSERT_NRESET -> RST_HOLD ->
RST_WAIT_RELEASE -> RST_POST_WAIT -> RST_DONE
```

* 先驱动 SOP[2:0] 选择启动模式（SPI mode = 3'b001）
* 拉低 nRESET 持续 `RESET_HOLD_US`
* 释放后等待 `POST_RESET_WAIT_US`
* 支持 fault 自动恢复触发的 recovery reset

---

## AWR2243 Status Monitor

**文件**：`awr2243_status_mon.sv`

监控 AWR2243 的外部状态引脚：
* **HOST_IRQ**：上升沿检测 + sticky 锁存 + 计数
* **nERROR**：活跃态检测 + sticky + fault 计数
* **WARM_RESET**：上升沿 + sticky + 计数
* 所有输入经过可配置深度的毛刺滤波（`IRQ_FILTER_CYCLES` 等）
* 支持 arm/clear 控制

---

## AWR2243 Timer

**文件**：`awr2243_timer.sv`

通用延时/超时计时器：
* `period_unit_i = 0`：按原始时钟周期计数
* `period_unit_i = 1`：按微秒计数（内部乘以 `CYCLES_PER_US`）
* start / clear / busy / done / expired 接口
* 被 cmd_decode 和 reset_ctrl 共用

---

## SPI Master Engine

**文件**：`spi_master_engine.sv`

16bit 全双工 SPI 主机，CPOL=0 / CPHA=0：

```text
ST_IDLE -> ST_ASSERT_CS -> ST_SHIFT (16 bits) -> ST_DEASSERT_CS -> ST_DONE
                                                       +-- ST_TIMEOUT
```

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `SPI_CLK_DIV` | 4 | 时钟分频系数 |
| `CS_SETUP_CYCLES` | 1 | CS 建立时间 |
| `CS_HOLD_CYCLES` | 1 | CS 保持时间 |
| `TIMEOUT_CYCLES` | 1024 | 超时周期 |

cmd_valid/cmd_ready 握手接口，支持读/写指示（`cmd_is_read_i`），读响应通过 `rsp_valid_o` + `rsp_word_o` 返回。
