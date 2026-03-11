

# 雷达采集系统详细架构设计说明书 v2

## 构建与验证

统一的本地构建与回归入口脚本：

```sh
tools/build_and_verify.sh
```

详细使用说明见：
[BUILD_AND_VERIFY.md](BUILD_AND_VERIFY.md)

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

---

# 2 系统总体架构

```text
AWR2243
   │
   │ MIPI CSI2
   ▼
+------------------+
| MIPI D-PHY       |
+------------------+
   │
   ▼
+----------------------+
| CSI-2 RX Subsystem   |
+----------------------+
   │ AXI4-Stream
   ▼
+----------------------+
| CSI Packet Extractor |
+----------------------+
   │
   ▼
+----------------------+
| Fixed Slot Packer    |
| (1024 Sample)        |
+----------------------+
   │
   ▼
+---------------------------+
| DDR RingBuffer Controller |
+---------------------------+
   │                     │  
   │                     │
   │                     │ AXI4
   │                     │
   │                     │
   │ AXI4                │ 
   │                     ├───────► XDMA PCIe Engine ─────► Host PC
   │                     │
   │                     └───────► CSR / Status Register
   ▼
+----------------------+
| DDR4 MIG Controller  |
+----------------------+

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

## 4.1 slot 总结构

```text
slot
├─ slot_header
├─ raw_payload_fixed
└─ padding
```

---

## 4.2 slot_header 结构

```c
struct slot_header
{
    uint32_t magic;
    uint16_t version;
    uint16_t header_len;

    uint32_t seq;

    uint32_t payload_bytes_rx;
    uint32_t slot_bytes;

    uint32_t flags;
    uint32_t timestamp;
};
```

---

## 4.3 字段说明

| 字段               | 说明                                    |
| ---------------- | ---------------------------------      
| magic            | slot 标识                               |
| version          | 协议版本                                  |
| header_len       | header 长度                             |
| seq              | slot 序号                               |
| payload_bytes_rx | 实际收到的 CSI long packet payload 字节数 |
| slot_bytes       | slot 总长度                             |
| flags            | 错误/状态标志                           |
| timestamp        | 本地时钟计数                            |

---

# 5 原始 payload 固定区

结构如下：

```text
raw_payload_fixed
│
├─ RX0 header
├─ RX1 header
├─ RX2 header
├─ RX3 header
│
├─ sample[0]
├─ sample[1]
├─ ...
├─ sample[1023]
│
└─ CQ area
```

---

## 5.1 header 区

4 个 RX header：

* `4 × 24bit = 96bit = 12B`

---

## 5.2 sample 区

每个 sample 包含：

* RX0_I
* RX0_Q
* RX1_I
* RX1_Q
* RX2_I
* RX2_Q
* RX3_I
* RX3_Q

每项 12bit，总计：

* `8 × 12bit = 96bit = 12B`

---

## 5.3 sample 区大小

* `1024 × 12B = 12288B`

---

## 5.4 CQ 区

固定预留：

* `8B`

即使 CQ 未启用，也保留并填 0。

---

## 5.5 raw payload 固定区大小

```text
12B + 12288B + 8B = 12308B
```

工程实现建议扩展为：

```text
12312B
```

便于内部字节边界对齐。

---

# 6 Slot 总长度

slot 组成：

* `slot_header = 32B`
* `raw_payload_fixed = 12312B`
* `padding -> 64B 对齐`

最终固定为：

```text
12352B
```

即：

```text
193 × 64B
```

---

# 7 DDR 地址映射

## 7.1 DDR 布局

```text
DDR
│
├─ Control Area
└─ Slot Ring Buffer Area
```

---

## 7.2 Control Area

起始地址：

```text
BASE + 0x0000
```

建议大小：

```text
4KB
```

用于存储：

* ring_write_ptr
* ring_read_ptr
* ring_commit_ptr
* ring_size
* overflow_count
* 状态寄存器

---

## 7.3 Ring Buffer Area

起始地址：

```text
BASE + 0x1000
```

slot 地址计算：

```text
addr = DATA_BASE + slot_id × SLOT_SIZE
```

其中：

* `DATA_BASE = BASE + 0x1000`
* `SLOT_SIZE = 12352B`

---

## 7.4 slot 数量估算

假设可用 DDR 数据区大小为 256MB，则最大 slot 数约为：

```text
256MB / 12352B ≈ 20700 slot
```

---

# 8 模块功能设计

---

# 8.1 SPI Driver

## 功能

用于配置 AWR2243：

* profile 配置
* chirp 配置
* frame 配置
* 启停控制
* 状态读取

## 输入输出

* 系统控制寄存器触发配置
* SPI 四线接口连接 AWR2243

---

# 8.2 CSI Packet Extractor

## 功能

* 接收 CSI-2 RX Subsystem AXI4-Stream 数据
* 识别 short packet / long packet
* 过滤 short packet
* 提取 long packet payload
* 记录 payload 字节数
* 记录 CRC/ECC 错误状态

## 输出

* payload_data
* payload_valid
* payload_last
* payload_bytes
* crc_error
* ecc_error

---

# 8.3 Fixed Slot Packer

## 功能

* 创建固定长度 slot
* 写 slot_header
* 写 raw payload
* 不足 1024 sample 区补 0
* CQ 区固定填充
* 尾部 padding 到 64B 边界

---

# 8.4 DDR Ring Buffer Writer

## 功能

* slot 地址分配
* DDR AXI 写突发控制
* wr_ptr 更新
* commit_ptr 更新
* overflow 检测
* 状态统计

---

# 8.5 XDMA Interface

## 功能

* Host 侧通过 AXI-MM 访问 DDR
* 读取固定 slot 数据
* 读取控制寄存器区状态

---

# 8.6 CSR Register Block

## 功能

* 提供模块控制寄存器
* 提供状态与计数器
* 提供软复位接口
* 提供 ring buffer 运行监控

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

## 10.1 控制量

控制区建议至少包含：

* ring_write_ptr
* ring_commit_ptr
* ring_read_ptr
* ring_size
* overflow_count
* csi_crc_error_count
* slot_seq_counter

---

## 10.2 指针关系

```text
read_ptr ≤ commit_ptr ≤ write_ptr
```

说明：

* `write_ptr`：保留给当前写入的下一 slot
* `commit_ptr`：已经完整写入、可被 Host 读取的最后位置
* `read_ptr`：Host 已消费位置

---

## 10.3 溢出策略

建议 v2 采用：

**丢弃新 slot + overflow_count++**

理由：

* 不破坏已提交数据完整性
* Host 端容易检测
* 调试最清晰

---

# 11 PCIe XDMA 接口

采用：

* **AXI Memory Mapped**

Host 通过 XDMA：

* 读 DDR ring buffer 数据区
* 读控制寄存器区
* 控制 start/stop/reset

---

# 12 寄存器表

## 12.1 控制寄存器

| Offset | 名称      | 说明                   |
| ------ | ------- | -------------------- |
| 0x00   | CONTROL | bit0:start bit1:stop |
| 0x04   | STATUS  | 系统运行状态               |
| 0x08   | RESET   | 软件复位                 |

---

## 12.2 Ring Buffer 寄存器

| Offset | 名称         | 说明            |
| ------ | ---------- | ------------- |
| 0x10   | WR_PTR     | 当前写指针         |
| 0x14   | RD_PTR     | 当前读指针         |
| 0x18   | COMMIT_PTR | 当前提交指针        |
| 0x1C   | RING_SIZE  | ring 总 slot 数 |

---

## 12.3 错误统计寄存器

| Offset | 名称             | 说明           |
| ------ | -------------- | ------------ |
| 0x20   | CSI_CRC_ERR    | CSI CRC 错误计数 |
| 0x24   | CSI_ECC_ERR    | CSI ECC 错误计数 |
| 0x28   | OVERFLOW_COUNT | ring 溢出计数    |
| 0x2C   | SLOT_SEQ       | slot 序号计数    |

---

# 13 状态机设计

## 13.1 Packet Extractor 状态机

```text
IDLE
 │
WAIT_PACKET
 │
READ_PAYLOAD
 │
PACKET_DONE
 │
IDLE
```

---

## 13.2 Fixed Slot Packer 状态机

```text
IDLE
 │
WRITE_HEADER
 │
COPY_PAYLOAD
 │
ZERO_FILL
 │
PAD_ALIGN
 │
SLOT_DONE
 │
IDLE
```

---

## 13.3 DDR Writer 状态机

```text
IDLE
 │
ALLOC_SLOT
 │
AXI_WRITE
 │
WAIT_BRESP
 │
COMMIT
 │
IDLE
```

---

## 13.4 SPI Driver 状态机

```text
IDLE
 │
CFG_PROFILE
 │
CFG_CHIRP
 │
CFG_FRAME
 │
START_SENSOR
 │
RUNNING
```

---

# 14 上位机解析流程

Host 每次读取固定长度 slot：

1. 读取 `slot_header`
2. 获取 `payload_bytes_rx`
3. 读取固定长度 raw payload 区
4. 按 AWR 原始结构解析：

   * 4 路 header
   * sample 区
   * CQ 区
5. 根据实际配置判断真实 Ns
6. 忽略尾部填零区域

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
* 1024 sample 固定区补零正确
* CQ 区补零正确
* slot 长度固定为 12352B

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
| 固定 slot 大小        | 12352B   |

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

当前仓库已经把 `rdl/ddr_ringbuffer_controller.rdl` 接成一套可重复生成的 CSR 流程：

* `rtl/generated/ddr_ringbuffer_controller_csr_pkg.sv`
* `rtl/generated/ddr_ringbuffer_controller_csr.sv`
* `sw/include/generated/ddr_ringbuffer_controller_csr.h`
* `tb/uvm/ral/ddr_ringbuffer_controller_csr_ral_pkg.sv`

## 17.1 重新生成

首次安装本地依赖：

```bash
./tools/rdl/install_peakrdl_deps.sh
```

重新生成所有 CSR 产物：

```bash
./tools/rdl/generate_ddr_ringbuffer_controller_csr.sh
```

本地依赖默认安装到 `tools/rdl/.deps/`，不会污染系统 Python 环境。

## 17.2 RTL 侧使用

新增了 [ddr_ringbuffer_controller_axil.sv](/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/core/ddr_ringbuffer_controller_axil.sv) 作为包装层：

* 外部暴露 `AXI4-Lite slave` CSR 口
* 内部实例化 `PeakRDL` 生成的 CSR regblock
* 将 `CTRL/RING_BASE/RING_SIZE/READ_CMD` 映射到 `ddr_ringbuffer_controller`
* 将状态、指针、计数、最近提交槽信息、头描述符信息回填到 CSR 只读寄存器

当前这版 RDL 的软件可见位宽约束是：

* 地址字段最大 `64bit`
* ring size / occupancy / counter 最大 `32bit`
* slot byte count 最大 `24bit`

如果后续 RTL 参数改得更大，需要同步更新 `rdl/ddr_ringbuffer_controller.rdl`，否则 wrapper 里的静态检查会报错。

可直接使用文件列表 [ddr_ringbuffer_controller_axil.f](/Users/hb39209/Desktop/awr2243-fpga-capture/rtl/ddr_ringbuffer_controller_axil.f) 编译这套带 CSR 的版本。

## 17.3 Host 软件侧使用

生成的 C 头文件在 [ddr_ringbuffer_controller_csr.h](/Users/hb39209/Desktop/awr2243-fpga-capture/sw/include/generated/ddr_ringbuffer_controller_csr.h)。
示例代码见 [ddr_ringbuffer_controller_csr_example.c](/Users/hb39209/Desktop/awr2243-fpga-capture/sw/examples/ddr_ringbuffer_controller_csr_example.c)。

典型用法是把 `BAR0 + CSR offset` 转成寄存器结构体指针：

```c
volatile ddr_ringbuffer_controller_csr_t *csr =
    (volatile ddr_ringbuffer_controller_csr_t *)((volatile uint8_t *)bar0 + csr_offset);
```

之后可直接：

* 写 `CTRL/RING_BASE_LO/RING_BASE_HI/RING_SIZE_BYTES` 完成初始化
* 写 `READ_CMD` 触发 `issue_head_read` 或 `consume_head`
* 读 `STATUS/USED_BYTES/FREE_BYTES/HEAD_DESC_*` 轮询当前状态
