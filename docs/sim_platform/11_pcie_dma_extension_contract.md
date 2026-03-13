# Host / PCIe / DMA 端到端扩展架构约定

## 1. 作用域与共享板 claim

- `claim: e2e_arch_spec`
- 本文档是对当前仓库已有 cocotb 平台的增量约定，不替换现有 `tb/cocotb/pipeline_cocotb_top.sv`、`tb/cocotb/platform_env.py`、`rtl/core/ddr_ringbuffer_controller_axil.sv` 的模块级职责。
- 目标是把现有链路扩展为“Host 控制与读回可见”的端到端平台，同时保持雷达数据面 RTL 不变：

```text
Host software / cocotb
    -> PCIe RC model
    -> PCIe endpoint + DMA shim
    -> AXI
    -> DDR
    -> Radar data pipeline
```

## 2. 相对当前平台的最小 delta

| 层次 | 当前仓库基线 | 本次扩展约定 |
|------|--------------|--------------|
| Host 控制 | cocotb 直接驱动 `cfg_*` / `rd_*` | 改为 Host 通过 PCIe BAR0 访问 AXI-Lite CSR |
| Host 数据读回 | `AxiHostMaster` 直接消费读回口或内存模型 | 改为 DMA 通过 AXI-MM 访问 DDR，把 slot 拉回 Host |
| DDR 访问主设备 | 仅 ringbuffer controller 写 DDR | 扩展为 `ring write master + dma master -> 1 x DDR slave` |
| 时钟域 | 仅 `video_aclk -> axis_clk` 为强制 CDC | 第一阶段保持不变，PCIe/DMA 侧不新增独立 CDC |

约束：

- 现有 `m_axis_rd_*` 读回链路保留，用于模块级回归；新的 PCIe 端到端 top 不再把它作为 Host 主路径。
- 第一阶段只要求 **C2H 读回路径** 打通，也就是 Host 依据当前 `HEAD_DESC_*` 描述符把 DDR 中已提交 slot 拉回。H2C 写路径保留为后续扩展点，不在本轮合同内强制实现。

## 3. PCIe RC / Endpoint / DMA 边界

### 3.1 PCIe RC

- 形态：**behavioral cocotb driver/model**
- 责任：
  - 链路拉起与枚举的行为抽象
  - BAR0 MMIO 读写
  - 发起 DMA pull 请求并收集完成数据
- 不做：
  - LTSSM、DLLP、credit、重排等 cycle-accurate PCIe 细节
  - 多 function / 多 BAR 复杂配置

### 3.2 PCIe Endpoint

- 形态：**behavioral endpoint shim**
- 责任：
  - 提供 `pcie_link_up` / `pcie_rst_n` 级别的链路可用语义
  - BAR0 到现有 AXI-Lite CSR wrapper 的地址译码
  - 向 DMA shim 转发 Host 发起的 bulk transfer 请求
- 第一阶段只约定一个稳定 BAR：
  - `BAR0`: 4KB CSR aperture，映射到现有 `ddr_ringbuffer_controller_axil` CSR 空间

### 3.3 DMA

- 形态：**behavioral DMA shim**
- Host 与 DMA 的接口不新增一套独立 CSR map；第一阶段直接复用当前 `HEAD_DESC_*` + `READ_CMD` 流程。
- 约定流程：
  1. Host 通过 BAR0 读取 `HEAD_DESC_ADDR_LO/HI`、`HEAD_DESC_INFO`、`HEAD_DESC_SEQ`
  2. Host 通过 BAR0 写 `READ_CMD.issue_head_read`
  3. DMA shim 对 `HEAD_DESC_INFO.slot_bytes` 指定的字节数发起 AXI-MM 读
  4. Host 收到 slot 后，通过 BAR0 写 `READ_CMD.consume_head`
- DMA 到 AXI 的边界固定复用现有 `axi4_mm_if`：
  - `ADDR_W = 34`
  - `DATA_W = 256`
  - burst type = `INCR`
  - `MAX_BURST_LEN = 16`
  - 地址和长度按 32B beat 对齐处理

## 4. AXI 地址图与 DDR 布局

### 4.1 BAR0 / AXI-Lite CSR 空间

BAR0 对应现有 `rdl/ddr_ringbuffer_controller.rdl` 生成的 CSR，当前有效偏移如下：

| 偏移 | 寄存器 | 说明 |
|------|--------|------|
| `0x000` | `CTRL` | `enable` / `allow_overwrite` / `drop_invalid_slot` / `drop_on_no_space` |
| `0x004` | `STATUS` | `full` / `almost_full` / `empty` / `rd_busy` / 错误状态 |
| `0x008-0x010` | `RING_BASE_*`, `RING_SIZE_BYTES` | DDR ring 配置 |
| `0x014` | `READ_CMD` | `issue_head_read` / `consume_head` |
| `0x020-0x050` | `USED_BYTES` 等 | 占用、指针、计数器 |
| `0x060-0x06C` | `LAST_COMMIT_*` | 最近提交 slot |
| `0x080-0x08C` | `HEAD_DESC_*` | 队首未消费 slot |

约定：

- `0x000-0x08C` 按当前 RDL 保持不变。
- `0x090-0xFFF` 第一阶段保留，不在 PCIe/DMA 分支各自发明新的 BAR0 扩展寄存器。

### 4.2 DDR / AXI-MM 空间

DDR 空间不切分独立“控制区 + 数据区”，仍沿用当前 ring buffer 设计：

- `ring_base_addr`：由 `RING_BASE_LO/HI` 配置
- `ring_size_bytes`：由 `RING_SIZE_BYTES` 配置
- `slot_bytes`：沿用当前 `fixed_slot_packer` 输出，默认 `12352B`
- `slot_stride_bytes`：沿用当前宏默认值 `12352B`
- `DDR_RING_ALIGN_BYTES_DFLT = 32`

与当前 cocotb 环境保持一致的默认回归布局：

| DDR 区间 | 用途 |
|---------|------|
| `0x0000_0000 - 0x0000_0FFF` | guard / 保留，不放 ring |
| `0x0000_1000 - 0x0000_4FFF` | 默认回归 ring window (`RING_BASE_ADDR=0x1000`, `RING_SIZE_BYTES=0x4000`) |
| `0x0000_5000` 以上 | 保留给更大 ring 或后续 DMA scratch；第一阶段不依赖 |

约定：

- 不引入额外 DDR descriptor table。Host/DMA 侧以 `HEAD_DESC_*` 为唯一稳定描述符来源。
- 所有新加 AXI 主设备必须遵守当前 32B 对齐规则，不得改变 `ddr_ringbuffer_macros.svh` 既有宽度。

## 5. 时钟 / Reset 合同

### 5.1 时钟

| 逻辑时钟 | 第一阶段映射 | 说明 |
|---------|--------------|------|
| `video_aclk` | 200MHz | 保持现有 CSI RX mock 域 |
| `axis_clk` | 250MHz | 保持现有 extractor / packer 域 |
| `axi_clk` | 250MHz | 保持现有 ringbuffer / DDR 域 |
| `pcie_user_clk` | `axi_clk` 同源同频 | 第一阶段不额外引入 PCIe CDC |
| `dma_clk` | `axi_clk` 同源同频 | DMA shim 与 DDR 同域 |

### 5.2 Reset 与链路拉起

- `sys_rst_n` 仍是总复位输入。
- `video_rst_n`、`axis_rst_n`、`axi_rst_n` 仍按当前 `tb/top_tb.sv` 的“异步断言、同步释放”方式生成。
- 若 PCIe/DMA top 增加 `pcie_rst_n`、`dma_rst_n`，第一阶段均直接从 `axi_rst_n` 派生。
- `pcie_link_up` 必须满足：
  - `axi_rst_n == 1`
  - DDR model 已完成初始化
  - 至少等待 4 个 `axi_clk` 周期后再置位

唯一强制异步 CDC 仍是：

- `video_aclk (200MHz) -> axis_clk (250MHz)`，继续由现有 `axis_async_fifo` 承担

## 6. Behavioral 与开源 IP / 现有 RTL 的划分

| 部分 | 约定实现方式 | 备注 |
|------|--------------|------|
| PCIe RC | behavioral | cocotb driver / BFM 即可 |
| PCIe endpoint BAR / DMA shim | behavioral | 第一阶段不引入真实 PCIe TLP RTL |
| Radar pipeline (`csi_packet_extractor` / `fixed_slot_packer` / `ddr_ringbuffer_controller`) | 保持现有 RTL | 不改职责，不并行再造 |
| AXIS CDC FIFO | 保持现有 `tb/models/axis_async_fifo.sv` | 继续作为唯一硬性 CDC 模块 |
| DMA + ring -> DDR 仲裁 | 推荐薄封装开源 AXI interconnect，或极简本地仲裁 | 若包装开源模块，位宽必须保持 256-bit / 34-bit |
| DDR model | 默认 behavioral `AxiMemoryModel` | LiteDRAM 仍可作为可选替代，不是第一阶段强制项 |

推荐原则：

- **PCIe 行为建模优先，先把系统 contract 定死，再决定是否换成开源 PCIe RTL。**
- **AXI 与 DDR 保持现有宽度与对齐，不为 PCIe 分支改宏。**

## 7. 推荐新增文件与目录

以下为建议新增项，命名保持与现有 `tb/cocotb/` 结构一致：

- `tb/cocotb/pcie_e2e_cocotb_top.sv`
- `tb/cocotb/pcie_e2e_cocotb.py`
- `tb/cocotb/run_pcie_e2e.py`
- `tb/cocotb/drivers/pcie_rc_driver.py`
- `tb/cocotb/model/pcie_endpoint_dma_model.py`
- `tb/cocotb/tests/test_pcie_e2e.py`

可选新增项：

- `tb/models/axi_mm_2to1_arb.sv`，如果不直接包装现成 AXI interconnect

不建议在第一阶段新增：

- 新的 `rtl/core/pcie_*.sv` 真 RTL 目录
- 新的 DDR descriptor table RTL
- 与现有 RDL 平行的第二套 DMA CSR 文档

## 8. Handoff Notes

- `handoff[pcie]`: 只实现 transaction-level RC/endpoint/DMA 即可；不要在第一阶段引入新的 BAR0 寄存器图，也不要改 `READ_CMD` / `HEAD_DESC_*` 语义。
- `handoff[axi-ddr]`: 固定使用 `axi4_mm_if` 现有宽度，`ADDR_W=34`、`DATA_W=256`、`MAX_BURST_LEN=16`、`ALIGN_BYTES=32`；DMA 与 ring writer 的仲裁只做 2-to-1。
- `handoff[host]`: Host 读回流程以 `HEAD_DESC_* -> READ_CMD.issue_head_read -> DMA pull -> READ_CMD.consume_head` 为准，不直接假设 DDR 中存在额外 descriptor table。
- `handoff[integrator/tests]`: 第一阶段把 `pcie_user_clk`、`dma_clk` 绑到 `axi_clk`；保留 `m_axis_rd_*` 回归用于模块级验证，不把它删掉。

## 9. Status

- `--verify-status passed`
- 架构增量总结：在不改变现有雷达 pipeline RTL、AXI 宽度、CSR 偏移和 DDR ring 语义的前提下，引入 behavioral PCIe RC / endpoint / DMA shim，把 Host 控制与 DDR 读回统一收敛到 BAR0 + AXI-MM 两条稳定边界。
