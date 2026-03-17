# SystemVerilog Packages

本目录包含各模块共享的类型定义、常量和工具函数。

## Package 列表

| Package | 文件 | 关联模块 |
|---------|------|----------|
| `csi_packet_pkg` | `csi_packet_pkg.sv` | CSI Packet Extractor |
| `slot_packer_pkg` | `slot_packer_pkg.sv` | Fixed Slot Packer |
| `ddr_ringbuffer_pkg` | `ddr_ringbuffer_pkg.sv` | DDR Ring Buffer Controller |
| `awr2243_script_pkg` | `awr2243_script_pkg.sv` | AWR2243 控制子系统 |
| `pcie_dma_pkg` | `pcie_dma_pkg.sv` | PCIe Endpoint DMA |

---

## csi_packet_pkg

CSI-2 协议相关定义：
* VC/DT 位宽（`CSI_VC_W=2`, `CSI_DT_W=6`）
* tuser 中各字段的位偏移（pkt_start、crc_err、ecc_err、trunc_err、vc、dt、payload_len）
* `clog2_safe()` 工具函数

## slot_packer_pkg

Slot 封装相关工具：
* `align_up_u(value, align)`：向上对齐
* `clog2_safe(value)`：安全 clog2（value<=1 返回 1）
* Slot 总长度计算逻辑的复用

## ddr_ringbuffer_pkg

DDR 环形缓冲区类型与工具：
* `clog2_safe()`、`max_u()` 工具函数
* Ring buffer 地址/占用/计数的位宽推导

## awr2243_script_pkg

AWR2243 脚本系统定义：
* Opcode 编码（SPI_WRITE、SPI_READ、DELAY、GPIO_SET 等）
* 错误码定义
* Script RAM 地址/长度位宽
* `clog2_safe()` 工具函数

## pcie_dma_pkg

PCIe DMA 参数默认值：
* BAR 地址/数据位宽
* AXI-Lite / AXI-MM 位宽
* DMA 描述符 ID 位宽
* BAR0 内部空间/转发基址
