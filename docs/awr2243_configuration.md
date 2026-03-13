# AWR2243 控制寄存器与 BAR0 配置说明

## 1. 权威来源

- **RTL 寄存器定义**：`rdl/awr2243_control.rdl`
- **Host 侧偏移与位定义**：`sw/include/generated/awr2243_control_csr.h`（由 PeakRDL-cheader 从 RDL 生成）
- 寄存器语义与 `rtl/core/awr2243_ctrl_top.sv` 中通过 hwif 连接的逻辑一致。

## 2. BAR0 地址映射

与 [docs/sim_platform/11_pcie_dma_extension_contract.md](sim_platform/11_pcie_dma_extension_contract.md) 一致：

| BAR0 地址范围       | 用途                         |
|---------------------|------------------------------|
| `0x000`–`0x08C`     | DDR ringbuffer CSR           |
| `0x090` 及以后      | AWR2243 控制 CSR             |

- AWR2243 窗口基址：**0x090**。访问时使用 BAR0 地址 `0x090 + 偏移`。
- 偏移与 RDL addrmap 一致，为 0-based 字节偏移（见下表）。Host 侧建议使用 `awr2243_control_csr.h` 中的结构体或宏。

## 3. AWR2243 CSR 寄存器表（0x090 窗口内偏移）

| 偏移 | 寄存器名           | 访问 | 说明 |
|------|--------------------|------|------|
| 0x00 | VERSION            | RO   | 固定 0x4353_0100 ("CS" v1.0) |
| 0x04 | CONTROL            | WO*  | singlepulse：start_init, start_sensor, stop_sensor, hard_reset, clear_error |
| 0x08 | STATUS             | RO   | busy, done, done_sticky, err_sticky, irq_seen_sticky, fault_seen_sticky |
| 0x0C | ERR_CODE_LIVE      | RO   | 当前错误码（16 位） |
| 0x10 | ERR_CODE_STICKY    | RO   | 锁存错误码 |
| 0x14 | STEP_ID_LIVE       | RO   | 当前步 ID |
| 0x18 | STEP_ID_SNAPSHOT   | RO   | 在 done/err 时锁存的步 ID |
| 0x1C | LAST_OPCODE_LIVE   | RO   | 当前最后 opcode |
| 0x20 | LAST_OPCODE_SNAP   | RO   | 锁存的最后 opcode |
| 0x24 | IRQ_COUNT          | RO   | Host IRQ 计数 |
| 0x28 | FAULT_COUNT        | RO   | 故障计数 |
| 0x2C | INIT_SCRIPT_ID     | R/W  | 初始化脚本 ID |
| 0x30 | RF_SCRIPT_ID       | R/W  | RF 脚本 ID |
| 0x34 | PROFILE_SCRIPT_ID  | R/W  | Profile 脚本 ID |
| 0x38 | FRAME_SCRIPT_ID    | R/W  | Frame 脚本 ID |
| 0x3C | MONITOR_SCRIPT_ID  | R/W  | Monitor 脚本 ID |
| 0x40 | START_SCRIPT_ID    | R/W  | Start 脚本 ID |
| 0x44 | STOP_SCRIPT_ID     | R/W  | Stop 脚本 ID |
| 0x48 | SCRATCH            | R/W  | 32 位 scratch |

\* CONTROL 为 singlepulse：软件写 1 产生脉冲，硬件读回为 0。

头文件中的位掩码与位位置：使用 `AWR2243_CONTROL_CSR__CONTROL__START_INIT_bm`、`AWR2243_CONTROL_CSR__STATUS__BUSY_bm` 等宏，见 `awr2243_control_csr.h`。

## 4. 配置流程简述

1. **上电/复位后**  
   - 读 `STATUS`、`ERR_CODE_*` 确认无残留错误；必要时写 CONTROL 的 `clear_error` 或 `hard_reset`（singlepulse）。

2. **配置脚本 ID**  
   - 按需写 `INIT_SCRIPT_ID`、`RF_SCRIPT_ID`、`PROFILE_SCRIPT_ID`、`FRAME_SCRIPT_ID`、`MONITOR_SCRIPT_ID`、`START_SCRIPT_ID`、`STOP_SCRIPT_ID`（偏移 0x2C–0x44）。

3. **启动**  
   - 写 CONTROL：`start_init` 启动初始化脚本；完成后可写 `start_sensor` 启动传感器。

4. **轮询与调试**  
   - 读 `STATUS`（busy/done/done_sticky/err_sticky 等）。  
   - 读 `ERR_CODE_LIVE` / `ERR_CODE_STICKY`、`STEP_ID_LIVE` / `STEP_ID_SNAPSHOT`、`LAST_OPCODE_LIVE` / `LAST_OPCODE_SNAP`。  
   - 读 `IRQ_COUNT`、`FAULT_COUNT` 用于统计与调试。

5. **停止**  
   - 写 CONTROL：`stop_sensor`（singlepulse）。

## 5. 与项目其他文档的关系

- **FPGA IP 核**：见 [FPGA IP 核组件介绍.md](../FPGA%20IP%20核组件介绍.md)（若存在）中对 AWR2243 控制与 BAR0 的说明。
- **PCIe/DMA/BAR0**：见 [docs/sim_platform/11_pcie_dma_extension_contract.md](sim_platform/11_pcie_dma_extension_contract.md)。  
- RTL 中 BAR0 译码由 `rtl/axil/axil_bar0_decode.sv` 实现；`addr < 0x90` 接 ringbuffer CSR，`addr >= 0x90` 接 AWR2243 控制块（地址为 `addr - 0x90`，低 8 位）。
