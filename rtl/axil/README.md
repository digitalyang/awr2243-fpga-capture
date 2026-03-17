# AXI-Lite BAR0 Address Decoder

## 模块

**文件**：`axil_bar0_decode.sv`

## 功能

PCIe BAR0 空间的 AXI-Lite 地址译码器，将单一上游 slave 端口拆分为两个下游 master 端口：

```text
Host (PCIe XDMA)
      │
      ▼
┌─────────────────────┐
│  axil_bar0_decode    │
│                     │
│  addr < 0x090 ──────┼──► m_axil_ring  (DDR Ringbuffer CSR, 0x000–0x08C)
│  addr ≥ 0x090 ──────┼──► m_axil_awr   (AWR2243 Control CSR, 地址偏移减去 0x090)
└─────────────────────┘
```

## 工作原理

* **地址译码**：根据 `AWR_BASE`（默认 0x0090）判断目标：小于 AWR_BASE 路由到 ringbuffer CSR，大于等于则路由到 AWR2243 CSR（地址自动减去偏移量）
* **串行事务**：同一时刻仅支持一个在途事务（一次写或一次读），通过 `waiting_for_b_r` / `waiting_for_r_r` 状态跟踪
* **完整 AXI-Lite 协议**：支持 AW/W/B（写通道）和 AR/R（读通道），响应直接从选中的下游端口透传

## 参数

| 参数 | 默认值 | 说明 |
|------|--------|------|
| `ADDR_W` | 16 | 地址位宽 |
| `DATA_W` | 32 | 数据位宽 |
| `AWR_BASE` | 16'h0090 | AWR2243 CSR 起始地址 |

## BAR0 地址映射

| 偏移范围 | 目标 | CSR 空间大小 |
|----------|------|-------------|
| 0x000 – 0x08C | DDR Ringbuffer Controller CSR | 0x90 (144B) |
| 0x090 + | AWR2243 Control CSR | 由 RDL 定义 |
