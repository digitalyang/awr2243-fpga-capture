# AWR2243 雷达数据采集 FPGA IP 核组件介绍

本项目提供一套面向 **TI AWR2243 毫米波雷达** 的高速数据采集 FPGA IP 核，采用纯 SystemVerilog 实现，基于 AXI4/AXI4-Stream 标准总线协议，形成完整的 **CSI-2 接收 → 固定槽位封装 → DDR 环形缓冲** 三级流水线。三个核心模块均支持参数化配置、编译期静态断言检查，具备工业级可靠性。

---

## 模块一：CSI Packet Extractor — CSI-2 数据包提取器

**定位**：MIPI CSI-2 协议层与数据处理层之间的桥梁，负责从 CSI-2 RX Subsystem 输出的原始 AXI-Stream 流中筛选并提取有效 long packet payload。

**核心能力**：

- **协议过滤**：支持按 Virtual Channel (VC) 和 Data Type (DT) 双维度可选过滤，不匹配的包在硬件层面直接丢弃（ST_DROP 状态），零延迟释放总线资源
- **完整性校验**：逐 beat 追踪实际接收字节数，与 CSI-2 header 中声明的 word count 做精确比对；同时聚合上游 `tuser` 中携带的 CRC 错误、ECC 错误和截断错误标志
- **包序列号跟踪**：内置自增序列号计数器（默认 16 位），每个通过过滤的有效包自动分配唯一序号，便于下游丢包检测
- **输出信号**：`pkt_start_o`、`pkt_done_o`、`pkt_valid_good_o`（无任何错误的包）、`pkt_bytes_o`、`pkt_crc_err_o`、`pkt_ecc_err_o`、`pkt_trunc_err_o`

**接口规范**：

| 接口 | 类型 | 说明 |
|------|------|------|
| `s_axis` | AXI4-Stream Slave | 来自 CSI-2 RX Subsystem |
| `m_axis` | AXI4-Stream Master | 输出至 Fixed Slot Packer |
| `cfg_vc_en/dt_en/vc/dt` | 配置输入 | VC/DT 过滤使能与目标值 |

**状态机**：IDLE → CHECK → ACCEPT/DROP → IDLE，4 状态精简设计，单周期判定包是否匹配。

**关键参数**：`AXIS_DATA_W`（默认 256 bit）、`MAX_PACKET_BYTES`（最大 65535）、`FIFO_DEPTH`（默认 16）、`PKT_SEQ_W`（序列号位宽）。

---

## 模块二：Fixed Slot Packer — 固定长度槽位封装器

**定位**：将来自 CSI Packet Extractor 的变长 payload 封装为**固定长度的 slot 数据帧**，实现变长到定长的转换，使下游存储和主机读取始终按统一偏移寻址。

**核心能力**：

- **固定 Slot 结构**：每个 slot = Header + Sample 区（默认 1024 sample × 12B = 12288B）+ CQ 区（默认 8B）+ 对齐 Padding，总长默认 12352B（193 × 64B）
- **自描述 Header**：自动构建包含 magic（`0xA110_CA7E`）、版本号、flags（CRC/ECC/截断/有效/溢出五个标志位）、包序列号、实际接收字节数、sample 计数、slot 总长度等元信息的 header
- **先捕获后输出**：采用 capture buffer 架构，先将整个 packet 吸收到片内寄存器阵列，packet 结束后再按 Header → Payload → Sample Pad → CQ Pad → Align Pad 五段有序输出
- **自动补零**：实际 sample 不足 1024 时自动零填充 sample 区剩余空间；CQ 区未启用时自动补零；尾部自动 padding 到 64B 边界
- **无效包丢弃**：支持 `cfg_drop_invalid_pkt_i` 配置，可选择丢弃含错误的包而不产生 slot 输出

**接口规范**：

| 接口 | 类型 | 说明 |
|------|------|------|
| `s_axis` | AXI4-Stream Slave | 来自 CSI Packet Extractor |
| `m_axis` | AXI4-Stream Master | 输出至 DDR Ring Buffer Controller |
| `pkt_*` 侧带 | 输入 | 上游包元信息 |
| `slot_*` 侧带 | 输出 | slot 级元信息（start/done/bytes/seq） |

**状态机**：IDLE → CAPTURE → HEADER → PAYLOAD → SAMPLE_PAD → CQ_PAD → ALIGN_PAD → IDLE，7 状态全覆盖。

**关键参数**：`SAMPLE_SLOT_NUM`（默认 1024）、`SAMPLE_UNIT_BYTES`（默认 12）、`CQ_AREA_BYTES`（默认 8）、`HEADER_BYTES`（默认 32）、`ALIGN_BYTES`（默认 64）。

---

## 模块三：DDR Ring Buffer Controller — DDR 环形缓冲控制器

**定位**：整个采集链路的核心存储管理引擎，负责将封装好的 slot 通过 AXI4 Memory-Mapped 接口写入 DDR4 环形缓冲区，并提供 Host 侧读回通道与全面的状态监控。

**核心能力**：

- **完整的环形缓冲管理**：维护 `wr_ptr` / `rd_ptr` / `commit_ptr` 三指针体系，支持地址回绕（含跨边界 wrap 的两段式 AXI 突发写入）
- **描述符 FIFO**：内置可配置深度的 slot 描述符队列（默认 16 深），记录每个已提交 slot 的地址、字节数、序列号、有效性等完整元信息
- **灵活的溢出策略**：
  - `cfg_drop_on_no_space_i`：空间不足时丢弃新 slot
  - `cfg_allow_overwrite_i`：允许覆写最旧 slot（自动弹出 FIFO 头部释放空间）
  - `cfg_drop_invalid_slot_i`：含错误的 slot 直接丢弃不写入 DDR
- **AXI4 突发引擎**：写路径支持可配置最大突发长度（默认 256 beat），自动分段处理环形边界回绕；读路径同样支持多段突发读取，通过 `m_axis_rd` AXI-Stream 输出读回数据
- **全面的错误检测**：配置对齐错误、空间不足、slot 协议违反、slot 过大、AXI 写/读响应错误、非法读取，共 7 类独立错误标志
- **统计计数器**：wrap 次数、溢出次数、丢弃次数，均为可配置位宽（默认 32 位）

**接口规范**：

| 接口 | 类型 | 说明 |
|------|------|------|
| `s_axis_slot` | AXI4-Stream Slave | 来自 Fixed Slot Packer |
| `m_axi` | AXI4 MM Master | 连接 DDR4 MIG |
| `m_axis_rd` | AXI4-Stream Master | Host 读回数据通道（连接 XDMA） |
| `rd_slot_req/consume` | 读控制 | Host 发起读请求 / 消费确认 |
| `cfg_ring_base/size` | 配置 | 环形缓冲区 DDR 基地址与大小 |

**写状态机**：IDLE → ACCEPT_SLOT → CHECK_SPACE → [MAKE_SPACE] → AW → W → WAIT_B → COMMIT / DROP_SLOT，9 状态完整覆盖正常/异常路径。

**读状态机**：IDLE → AR → R → DONE，4 状态精简高效。

**关键参数**：`CFG_AXI_ADDR_W`（默认 40 bit，支持 1TB 寻址）、`AXI_DATA_W`（默认 256 bit）、`RING_SIZE_BYTES_MAX`（默认 256MB）、`MAX_BURST_LEN`（默认 256）、`DESC_FIFO_DEPTH`（默认 16）、`ALMOST_FULL_MARGIN_BYTES`（近满水位线）。

---

## 三模块协同数据流

```
AWR2243 → MIPI CSI-2 RX → [CSI Packet Extractor] → [Fixed Slot Packer] → [DDR Ring Buffer Controller] → DDR4
                                                                                          ↓
                                                                              XDMA ← m_axis_rd ← AXI4 Read
                                                                                          ↓
                                                                                       Host PC
```

**设计亮点**：

- 三模块均通过标准 AXI4-Stream 接口级联，可独立替换或复用
- FPGA 只做数据搬运与封装，不解析 AWR payload 语义，保持架构简洁
- Host 端按固定 12352B 偏移读取 slot，无需变长寻址
- 配套 PeakRDL 生成的 CSR 寄存器块 + AXI4-Lite 包装层，支持运行时监控与控制
- 配套 cocotb + Verilator 和 UVM 两套验证环境，覆盖单模块和全链路集成测试
