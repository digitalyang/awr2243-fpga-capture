# AXI DDR Subsystem

本目录包含 DDR 侧的 AXI 互连子系统，提供双主仲裁接入 DDR 的功能。

## 模块列表

| 模块 | 文件 | 说明 |
|------|------|------|
| `axi_ddr_subsystem` | `axi_ddr_subsystem.sv` | 双主轮询仲裁互连 |
| `axi_ddr_subsystem_pkg` | `axi_ddr_subsystem_pkg.sv` | 地址映射默认值与主端口编码 |

---

## axi_ddr_subsystem

### 功能

两主一从的 AXI 互连边界，连接雷达数据通路（写）和 Host DMA（读/写）到 DDR 控制器：

```text
s_axi_radar (Ring Buffer write) --+
                                  +--> m_axi_ddr (DDR Memory Controller)
s_axi_host  (Host DMA R/W)     --+
```

### 工作原理

* **写通道与读通道独立仲裁**：Host 读可以与 radar 写并行
* **轮询仲裁**：当两个主端口同时请求时，交替授权（round-robin），避免饥饿
* **单在途 burst**：每个通道当前支持一个在途 burst（未来可替换为 verilog-axi axi_crossbar）
* **仅 INCR burst**：当前仅假设递增突发模式
* 输出 `wr_owner_o` / `rd_owner_o` 可观测信号用于验证

### 参数

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `AXI_ADDR_W` | 34 | AXI 地址位宽 |
| `AXI_DATA_W` | 256 | AXI 数据位宽 |
| `USE_EXTERNAL_VERILOG_AXI` | 0 | 是否使用外部 verilog-axi IP（预留） |

### 地址映射默认值

| 地址范围 | 用途 |
|----------|------|
| `0x0000_0000 - 0x0000_0FFF` | 保留 / training / guard page |
| `0x0000_1000 - 0x0001_0FFF` | DDR ring 默认窗口（与 cocotb 平台 `RING_BASE_ADDR=0x1000` 对齐） |
| `0x0002_0000 - 0x0002_FFFF` | Host/DMA 描述符窗口 |
| `0x0003_0000 - 0x0003_FFFF` | Host scratch / refmodel staging |

Ring base/size 通过 CSR 可配置，以上为仿真默认约定。

### LiteDRAM 计划

`sim/litedram/litedram_axi_wrapper_stub.sv` 是可替换的 DDR 适配边界。当前直通到 cocotb 内存模型，未来导入 LiteDRAM 时替换内部实现，保持 `s_axi` 和 `ddr_init_done_o` 接口不变。
