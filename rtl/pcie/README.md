# PCIe Endpoint + DMA Modules

本目录包含 PCIe 端点侧的 BAR 访问、DMA 引擎以及与 verilog-pcie 的适配层。

## 模块总览

| 模块 | 文件 | 功能 |
|------|------|------|
| PCIe Endpoint DMA Shell | `pcie_endpoint_dma_shell.sv` | BAR MMIO 桥接 + 描述符 DMA 写引擎 |
| PCIe Endpoint DMA Integration | `pcie_endpoint_dma_integration.sv` | 顶层集成包装（adapter + shell） |
| PCIe vPCIe Adapter | `pcie_endpoint_dma_vpcie_adapter.sv` | verilog-pcie 依赖隔离适配层 |

---

## PCIe Endpoint DMA Shell

**文件**：`pcie_endpoint_dma_shell.sv`
**Package**：`../pkg/pcie_dma_pkg.sv`

### 功能

该模块是 PCIe endpoint 的核心逻辑，包含两个独立子系统：

**1. BAR0 MMIO 桥接**

将 Host RC（Root Complex）的 BAR0 读写事务转换为 AXI-Lite 事务：

```text
Host RC BAR0 Write → MMIO_AXIL_WRITE → MMIO_AXIL_WRITE_RESP → MMIO_IDLE
Host RC BAR0 Read  → MMIO_AXIL_READ  → MMIO_AXIL_READ_RESP  → MMIO_IDLE
```

* BAR0 内部空间（< `BAR0_INTERNAL_BYTES`）直接处理
* BAR0 转发空间（≥ `BAR0_FORWARD_BASE`）转发到 `m_axil_bar0`

**2. 描述符 DMA 写引擎**

Host 通过 BAR0 寄存器编程 DMA 描述符（源地址、目标地址、长度、ID），DMA 引擎自动生成 AXI-MM 写 burst：

```text
DMA_IDLE → DMA_ACTIVE → DMA_WAIT_RESP → DMA_IDLE (dma_done_pulse)
```

* 支持多 beat burst，最大长度 `MAX_DMA_BURST_LEN`
* 完成后输出 `dma_done_pulse_o` 和 `dma_done_desc_id_o`

### 接口

| 端口 | 类型 | 说明 |
|------|------|------|
| `host_rc` | `pcie_rc_model_if.device` | Host RC 事务级接口 |
| `m_axil_bar0` | `axi4_lite_if.master` | BAR0 AXI-Lite 输出 |
| `m_axi_dma` | `axi4_mm_if.master` | DMA AXI-MM 输出 |
| `irq_o` | output | 中断输出 |

---

## PCIe Endpoint DMA Integration

**文件**：`pcie_endpoint_dma_integration.sv`

顶层集成包装，串联 `pcie_endpoint_dma_vpcie_adapter` 和 `pcie_endpoint_dma_shell`：

```text
host_rc (外部) → vpcie_adapter → shell_rc_if (内部) → pcie_endpoint_dma_shell
```

`DIRECT_RC_MODEL` 参数控制是否直通 RC model 接口（默认 1，即直连不经过 verilog-pcie IP）。

---

## PCIe vPCIe Adapter

**文件**：`pcie_endpoint_dma_vpcie_adapter.sv`

将外部 `pcie_rc_model_if` 适配到内部 shell 所需的 RC 接口格式。当 `DIRECT_RC_MODEL=1` 时为直通连线；未来接入 verilog-pcie IP 时在此做协议转换。

---

## 参数（pcie_dma_pkg 默认值）

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `BAR_ADDR_W` | 32 | BAR 地址位宽 |
| `BAR_DATA_W` | 32 | BAR 数据位宽 |
| `AXIL_ADDR_W` | 16 | AXI-Lite 地址位宽 |
| `AXI_ADDR_W` | 34 | DMA AXI 地址位宽 |
| `AXI_DATA_W` | 256 | DMA AXI 数据位宽 |
| `BAR0_INTERNAL_BYTES` | 256 | BAR0 内部寄存器空间 |
| `BAR0_FORWARD_BASE` | 0 | BAR0 转发起始地址 |
| `MAX_DMA_BURST_LEN` | 16 | 最大 DMA burst 长度 |
