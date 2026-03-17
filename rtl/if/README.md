# Interface Definitions

本目录包含项目中使用的 SystemVerilog interface 定义，统一了各模块之间的互连协议。

## 接口列表

| 接口 | 文件 | 说明 |
|------|------|------|
| `axis_stream_if` | `axis_stream_if.sv` | AXI4-Stream 接口，用于模块间流式数据传输 |
| `axi4_lite_if` | `axi4_lite_if.sv` | AXI4-Lite 接口，用于 CSR 寄存器访问 |
| `axi4_mm_if` | `axi4_mm_if.sv` | AXI4 Memory-Mapped 接口，用于 DDR 读写 |
| `pcie_rc_model_if` | `pcie_rc_model_if.sv` | PCIe Root Complex 事务级模型接口 |

---

## axis_stream_if

AXI4-Stream 标准接口，参数化数据位宽：
* `tdata`、`tkeep`、`tlast`、`tvalid`、`tready`、`tuser`
* `slave` 和 `master` modport
* 用于：CSI RX -> Extractor -> Packer -> Ring Buffer 全链路

## axi4_lite_if

AXI4-Lite 寄存器访问接口：
* 5 通道：AW、W、B、AR、R
* `slave` 和 `master` modport
* 用于：BAR0 译码、CSR regblock、AWR2243 控制

## axi4_mm_if

完整 AXI4 Memory-Mapped 接口：
* 支持 burst（awlen/arlen）、size、id
* `slave` 和 `master` modport
* 用于：DDR Ring Buffer 写入、DMA 传输、AXI DDR 子系统

## pcie_rc_model_if

PCIe Root Complex 事务级接口：
* BAR 读写事务（addr、data、bar、tag）
* DMA 描述符编程
* `host` 和 `device` modport
* 用于：cocotb 仿真中 Host 行为建模
