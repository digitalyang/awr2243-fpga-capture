# Macro Include Files

本目录包含各模块的参数默认值宏定义头文件，通过 `` `include `` 引入。

## 文件列表

| 文件 | 关联模块 | 说明 |
|------|----------|------|
| `csi_packet_extractor_macros.svh` | CSI Packet Extractor | AXIS 位宽、FIFO 深度、序号位宽等默认值 |
| `slot_packer_macros.svh` | Fixed Slot Packer | sample 数/字节、CQ 大小、对齐粒度、header 大小等 |
| `ddr_ringbuffer_macros.svh` | DDR Ring Buffer Controller | AXI 位宽、buffer/stride 大小、FIFO 深度、burst 长度等 |
| `awr2243_script_macros.svh` | AWR2243 控制子系统 | 脚本 word 位宽、RAM 深度、script 表深度、opcode 位宽等 |

## 设计约定

* 所有宏名以模块前缀开头（如 `CSI_`、`SLOT_PKR_`、`DDR_RING_`、`AWR2243_SCRIPT_`）
* 宏名以 `_DFLT` 结尾表示默认值
* 修改这些宏可在编译时改变模块的参数化配置
* Slot 布局修改示例：改 `SLOT_PKR_SAMPLE_SLOT_NUM_DFLT`、`SLOT_PKR_SAMPLE_UNIT_BYTES_DFLT` 即可改变 slot 大小

## 关键默认值

| 宏 | 默认值 | 说明 |
|----|--------|------|
| `SLOT_PKR_SAMPLE_SLOT_NUM_DFLT` | 1024 | sample 槽位数 |
| `SLOT_PKR_SAMPLE_UNIT_BYTES_DFLT` | 12 | 每 sample 字节 |
| `SLOT_PKR_CQ_AREA_BYTES_DFLT` | 9 | CQ 区字节 |
| `SLOT_PKR_HEADER_BYTES_DFLT` | 12 | header 字节 |
| `SLOT_PKR_ALIGN_BYTES_DFLT` | 64 | 对齐粒度 |
| `DDR_RING_AXI_ADDR_W_DFLT` | 34 | AXI 地址位宽 |
| `DDR_RING_AXI_DATA_W_DFLT` | 256 | AXI 数据位宽 |
| `DDR_RING_SLOT_BUFFER_BYTES_DFLT` | 12352 | Slot buffer 大小 |
| `DDR_RING_SLOT_STRIDE_BYTES_DFLT` | 12352 | DDR slot 步进 |
| `DDR_RING_RING_SIZE_BYTES_DFLT` | 65536 | Ring 默认容量 |
