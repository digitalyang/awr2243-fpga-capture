# Generated CSR Files

本目录包含由 PeakRDL 从 RDL 寄存器描述文件自动生成的 SystemVerilog CSR 模块。

**请勿手动修改此目录下的文件，应修改 `rdl/` 下的源 RDL 文件后重新生成。**

## 文件列表

| 文件 | 源 RDL | 说明 |
|------|--------|------|
| `ddr_ringbuffer_controller_csr_pkg.sv` | `rdl/ddr_ringbuffer_controller.rdl` | Ring buffer CSR 类型定义（hwif_in/out） |
| `ddr_ringbuffer_controller_csr.sv` | 同上 | Ring buffer CSR regblock 模块 |
| `ddr_ringbuffer_controller_csr_hwif.rpt` | 同上 | 硬件接口映射报告 |
| `awr2243_control_csr_pkg.sv` | `rdl/awr2243_control.rdl` | AWR2243 CSR 类型定义 |
| `awr2243_control_csr.sv` | 同上 | AWR2243 CSR regblock 模块 |
| `awr2243_control_csr_hwif.rpt` | 同上 | 硬件接口映射报告 |

## 生成方式

```sh
# 首次安装 PeakRDL 依赖
./tools/rdl/install_peakrdl_deps.sh

# 生成 DDR Ringbuffer CSR
./tools/rdl/generate_ddr_ringbuffer_controller_csr.sh

# 生成 AWR2243 Control CSR
./tools/rdl/generate_awr2243_control_csr.sh
```

## 生成产物分布

| 产物类型 | 位置 |
|----------|------|
| RTL (pkg + regblock) | `rtl/generated/` |
| C 头文件 | `sw/include/generated/` |
| UVM RAL | `tb/uvm/ral/` |

## RTL 侧使用

* `ddr_ringbuffer_controller_axil.sv` 实例化 `ddr_ringbuffer_controller_csr` regblock，将 hwif_in/out 连接到控制器信号
* `awr2243_ctrl_top.sv` 实例化 `awr2243_control_csr` regblock，将 hwif_in/out 连接到 sequencer/status 信号
