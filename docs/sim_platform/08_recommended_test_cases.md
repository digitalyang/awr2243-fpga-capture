# 推荐测试用例

## 1. 测试用例分类

### 1.1 Sanity 测试（基础功能）

| 测试用例名 | 目标 | 主要激励 | 主要检查 | 优先级 | cocotb 位置 |
|-----------|------|----------|----------|--------|-------------|
| **test_top_sanity** | 验证完整 pipeline 基本功能 | 发送单个有效 CSI-2 packet | Extractor 过滤、Packer 生成 slot、RingBuffer 写入 DDR、Host 读回数据一致 | P0 (sanity) | `tb/cocotb/tests/test_pipeline.py` |
| **test_extractor_smoke** | 验证 Extractor 基本过滤 | 发送匹配/不匹配 VC/DT 的 packet | 匹配的 packet 通过，不匹配的丢弃 | P0 (sanity) | `tb/cocotb/csi_packet_extractor_cocotb.py::test_smoke_match` |
| **test_packer_smoke** | 验证 Packer 基本封装 | 发送短 payload（<1024 sample） | 生成 12352B slot，不足部分补 0 | P0 (sanity) | `tb/cocotb/fixed_slot_packer_cocotb.py` |
| **test_ringbuffer_smoke** | 验证 RingBuffer 基本写入/读出 | 写入一个 slot，读回 | Slot 地址正确，数据一致 | P0 (sanity) | `tb/cocotb/ddr_ringbuffer_controller_cocotb.py::smoke_basic` |

### 1.2 功能测试（核心场景）

| 测试用例名 | 目标 | 主要激励 | 主要检查 | 优先级 | cocotb 位置 |
|-----------|------|----------|----------|--------|-------------|
| **test_pipeline_awr_frame_roundtrip** | 完整 AWR frame 往返 | 发送 FS/LS/Long/LE/FE packet 序列 | 完整 frame 处理，slot 顺序正确，Host 读回一致 | P1 (full) | `tb/cocotb/pipeline_cocotb.py::pipeline_awr_frame_roundtrip` |
| **test_pipeline_back_to_back_slots** | 背靠背 slot 处理 | 连续发送多个 packet，无间隙 | 每个 packet 生成独立 slot，无丢失 | P1 (full) | `tb/cocotb/tests/test_pipeline.py`（新增） |
| **test_ringbuffer_wraparound** | Ring buffer 回绕 | 写入 slot 直到 ring 满，继续写入触发 wrap | 写指针正确回绕，地址计算正确，无数据覆盖 | P1 (full) | `tb/cocotb/ddr_ringbuffer_controller_cocotb.py::wraparound_basic` |
| **test_axi_burst_lengths** | AXI burst 长度变化 | 不同长度的 AXI write burst | Burst 长度正确，数据完整 | P1 (full) | `tb/cocotb/tests/test_ringbuffer.py`（新增） |
| **test_host_read_burst** | Host burst read | Host 发起不同长度的 AXI read burst | 读数据正确，burst 长度/地址正确 | P1 (full) | `tb/cocotb/tests/test_pipeline.py`（新增） |

### 1.3 错误处理测试

| 测试用例名 | 目标 | 主要激励 | 主要检查 | 优先级 | cocotb 位置 |
|-----------|------|----------|----------|--------|-------------|
| **test_pipeline_invalid_slot_roundtrip** | Invalid slot 处理 | 发送带 CRC/ECC/trunc 错误的 packet | Invalid slot 标记正确，侧带传递正确 | P1 (full) | `tb/cocotb/pipeline_cocotb.py::pipeline_invalid_slot_roundtrip` |
| **test_pipeline_controller_drops_invalid** | Controller 丢弃 invalid | 配置 `drop_invalid_slot=1`，发送 invalid packet | Invalid slot 被丢弃，不写入 DDR | P1 (full) | `tb/cocotb/pipeline_cocotb.py::pipeline_controller_drops_invalid` |
| **test_extractor_error_latch** | Extractor 错误锁存 | 发送带错误的 packet | CRC/ECC/trunc 错误正确锁存到侧带 | P1 (full) | `tb/cocotb/csi_packet_extractor_cocotb.py::test_error_latch` |
| **test_packer_overflow** | Packer 溢出处理 | 发送 >1024 sample 的 payload | `slot_overflow_err_o` 置位，slot 仍生成但标记 overflow | P1 (full) | `tb/cocotb/tests/test_packer.py`（新增） |
| **test_ringbuffer_full_drop** | Ring 满时丢弃 | 写入 slot 直到 ring 满，继续写入 | 按配置丢弃或覆盖，`drop_count`/`overflow_count` 正确 | P1 (full) | `tb/cocotb/tests/test_ringbuffer.py`（新增） |

### 1.4 CDC 与时序测试

| 测试用例名 | 目标 | 主要激励 | 主要检查 | 优先级 | cocotb 位置 |
|-----------|------|----------|----------|--------|-------------|
| **test_cdc_async_fifo** | CDC Async FIFO 功能 | 在 200MHz 域发送数据，250MHz 域接收 | 数据无丢失/重复，FIFO 满/空处理正确 | P1 (full) | `tb/cocotb/tests/test_cdc.py`（新增） |
| **test_cdc_timing** | CDC 时序验证 | 不同时钟相位关系下的数据传输 | 无亚稳态，数据完整性 | P2 (full) | `tb/cocotb/tests/test_cdc.py`（新增） |
| **test_backpressure** | 背压处理 | 下游 ready 拉低，验证上游 backpressure | 数据不丢失，ready 握手正确 | P1 (full) | `tb/cocotb/csi_packet_extractor_cocotb.py::test_backpressure` |

### 1.5 性能与压力测试

| 测试用例名 | 目标 | 主要激励 | 主要检查 | 优先级 | cocotb 位置 |
|-----------|------|----------|----------|--------|-------------|
| **test_pipeline_continuous_stream** | 连续流处理 | 长时间连续发送 packet | 无数据丢失，性能稳定 | P2 (full) | `tb/cocotb/tests/test_pipeline.py`（新增） |
| **test_ringbuffer_stress** | Ring buffer 压力 | 高频率写入/读出，接近 ring 容量 | 无溢出（若配置允许覆盖），性能稳定 | P2 (full) | `tb/cocotb/tests/test_ringbuffer.py`（新增） |
| **test_axi_concurrent** | AXI 并发访问 | RingBuffer write 与 Host read 同时进行 | SmartConnect 仲裁正确，无数据冲突 | P2 (full) | `tb/cocotb/tests/test_pipeline.py`（新增） |

## 2. 覆盖目标

### 2.1 Payload 提取覆盖

- ✅ **VC/DT 过滤**：匹配/不匹配的 packet 正确处理
- ✅ **Packet 解析**：Long packet payload 正确提取
- ✅ **错误检测**：CRC/ECC/trunc 错误正确检测并传递
- ✅ **侧带信号**：pkt_start、pkt_done、pkt_bytes、pkt_seq 正确

### 2.2 Slot 封装覆盖

- ✅ **固定长度**：所有 slot 均为 12352B（64B 对齐）
- ✅ **Header 保留**：RX headers（12B）正确保留
- ✅ **Sample 填充**：不足 1024 sample 时补 0，超过时标记 overflow
- ✅ **CQ 区域**：CQ 数据正确打包（9B raw12）
- ✅ **Padding**：尾部 padding 至 64B 对齐

### 2.3 CDC 覆盖

- ✅ **200MHz → 250MHz**：AXIS Async FIFO 正确传递数据
- ✅ **FIFO 满/空**：FIFO 满时 backpressure，空时等待
- ✅ **数据完整性**：跨时钟域数据无丢失/重复
- ✅ **时序**：不同时钟相位关系下正常工作

### 2.4 Ring Buffer 覆盖

- ✅ **地址分配**：Slot 地址基于 ring_base_addr + wr_ptr
- ✅ **Ring wrap**：写指针回绕时地址计算正确
- ✅ **描述符提交**：Slot 提交后描述符对外可见
- ✅ **FIFO 管理**：描述符 FIFO 满/空处理
- ✅ **溢出处理**：Ring 满时的 drop/overwrite 策略

### 2.5 DDR 写入覆盖

- ✅ **AXI write burst**：不同 burst 长度（1-256 beats）
- ✅ **地址对齐**：64B 对齐地址
- ✅ **数据完整性**：写入 DDR 的数据与 slot 数据一致
- ✅ **响应处理**：AXI write 响应（OKAY/EXOKAY/SLVERR/DECERR）

### 2.6 Host burst read 覆盖

- ✅ **AXI read burst**：不同 burst 长度
- ✅ **地址正确性**：基于描述符的地址正确
- ✅ **数据一致性**：读回数据与写入数据一致
- ✅ **并发访问**：与 RingBuffer write 并发时的仲裁

## 3. 测试用例详细说明

### 3.1 test_top_sanity（Sanity）

**目标**：验证完整 pipeline 从 payload 输入到 Host 读回的基本功能。

**激励**：
1. 复位 DUT
2. 配置 Extractor（VC=1, DT=0x2A）
3. 配置 Packer（drop_invalid_pkt=0）
4. 配置 RingBuffer（ring_base=0x1000, ring_size=0x4000, enable=1）
5. 发送单个有效 CSI-2 packet（payload 100B）
6. 等待 slot 提交
7. Host 读回 slot

**检查**：
- Extractor 输出 pkt_valid_good=1
- Packer 输出 slot_bytes=12352, slot_valid_good=1
- RingBuffer 提交 slot，地址正确
- DDR 写入数据与 slot 数据一致
- Host 读回数据与写入数据一致

**cocotb 实现**：`tb/cocotb/tests/test_pipeline.py::test_top_sanity`

### 3.2 test_pipeline_back_to_back_slots（功能）

**目标**：验证背靠背 slot 处理，无数据丢失。

**激励**：
1. 连续发送 10 个 packet，无间隙
2. 每个 packet 生成一个 slot

**检查**：
- 10 个 slot 全部提交，序号连续（0-9）
- 每个 slot 地址正确（递增）
- Host 读回 10 个 slot，数据一致

**cocotb 实现**：`tb/cocotb/tests/test_pipeline.py::test_pipeline_back_to_back_slots`

### 3.3 test_ringbuffer_wraparound（功能）

**目标**：验证 ring buffer 写指针回绕。

**激励**：
1. 配置 ring_size=0x4000（16KB，约 1 个 slot）
2. 写入第一个 slot（12352B，触发 wrap）
3. 写入第二个 slot（覆盖或丢弃，取决于配置）

**检查**：
- 第一个 slot 地址 = ring_base + 0
- 第二个 slot 地址 = ring_base + (12352 % 0x4000) 或 ring_base + 0（若覆盖）
- wrap_count 递增
- 数据完整性

**cocotb 实现**：`tb/cocotb/ddr_ringbuffer_controller_cocotb.py::wraparound_basic`

### 3.4 test_axi_burst_lengths（功能）

**目标**：验证不同 AXI burst 长度的处理。

**激励**：
1. 发送不同长度的 slot（触发不同 burst 长度）
2. 或配置 RingBuffer 使用不同 MAX_BURST_LEN

**检查**：
- Burst 长度正确（AWLEN）
- Burst size 正确（AWSIZE，64B = 6）
- 数据完整

**cocotb 实现**：`tb/cocotb/tests/test_ringbuffer.py::test_axi_burst_lengths`

### 3.5 test_cdc_async_fifo（CDC）

**目标**：验证 CDC Async FIFO 功能。

**激励**：
1. 在 200MHz 域（video_aclk）发送 packet
2. 在 250MHz 域（axis_clk）接收

**检查**：
- 数据无丢失/重复
- FIFO 满时 backpressure（s_axis_tready=0）
- FIFO 空时等待（m_axis_tvalid=0）
- 跨时钟域数据完整性

**cocotb 实现**：`tb/cocotb/tests/test_cdc.py::test_cdc_async_fifo`

### 3.6 test_pipeline_awr_frame_roundtrip（功能）

**目标**：验证完整 AWR frame（FS/LS/Long/LE/FE）处理。

**激励**：
1. 发送 AWR frame：FS → Long packets → LS → LE → FE
2. 每个 Long packet 生成一个 slot

**检查**：
- Frame 边界正确识别
- Slot 顺序正确
- Host 读回完整 frame

**cocotb 实现**：`tb/cocotb/pipeline_cocotb.py::pipeline_awr_frame_roundtrip`

### 3.7 test_pipeline_controller_drops_invalid（错误处理）

**目标**：验证 Controller 丢弃 invalid slot。

**激励**：
1. 配置 `drop_invalid_slot=1`
2. 发送 invalid packet（CRC/ECC/trunc 错误）
3. Packer 生成 invalid slot

**检查**：
- Invalid slot 不写入 DDR
- drop_count 递增
- 下一个 valid slot 正常处理

**cocotb 实现**：`tb/cocotb/pipeline_cocotb.py::pipeline_controller_drops_invalid`

### 3.8 test_host_read_burst（功能）

**目标**：验证 Host AXI burst read。

**激励**：
1. 写入多个 slot 到 DDR
2. Host 发起不同长度的 AXI read burst（1-256 beats）

**检查**：
- Burst 长度正确（ARLEN）
- 读数据正确
- Burst 地址递增正确

**cocotb 实现**：`tb/cocotb/tests/test_pipeline.py::test_host_read_burst`

## 4. 测试用例与 cocotb 文件映射

### 4.1 现有测试用例（保留）

| 测试用例 | cocotb 文件 | 函数名 |
|---------|------------|--------|
| Extractor smoke | `tb/cocotb/csi_packet_extractor_cocotb.py` | `test_smoke_match` |
| Extractor backpressure | `tb/cocotb/csi_packet_extractor_cocotb.py` | `test_backpressure` |
| Extractor error latch | `tb/cocotb/csi_packet_extractor_cocotb.py` | `test_error_latch` |
| Packer payload | `tb/cocotb/test_awr_payload.py` | `test_payload_ns_*` |
| RingBuffer smoke | `tb/cocotb/ddr_ringbuffer_controller_cocotb.py` | `smoke_basic` |
| RingBuffer wraparound | `tb/cocotb/ddr_ringbuffer_controller_cocotb.py` | `wraparound_basic` |
| Pipeline smoke | `tb/cocotb/pipeline_cocotb.py` | `pipeline_smoke_basic` |
| Pipeline invalid roundtrip | `tb/cocotb/pipeline_cocotb.py` | `pipeline_invalid_slot_roundtrip` |
| Pipeline drop invalid | `tb/cocotb/pipeline_cocotb.py` | `pipeline_controller_drops_invalid` |
| Pipeline AWR frame | `tb/cocotb/pipeline_cocotb.py` | `pipeline_awr_frame_roundtrip` |
| Pipeline CRC error | `tb/cocotb/pipeline_cocotb.py` | `pipeline_awr_frame_crc_error` |

### 4.2 新增测试用例（建议实现）

| 测试用例 | cocotb 文件 | 函数名 |
|---------|------------|--------|
| Top sanity | `tb/cocotb/tests/test_pipeline.py` | `test_top_sanity` |
| Back-to-back slots | `tb/cocotb/tests/test_pipeline.py` | `test_pipeline_back_to_back_slots` |
| AXI burst lengths | `tb/cocotb/tests/test_ringbuffer.py` | `test_axi_burst_lengths` |
| Host read burst | `tb/cocotb/tests/test_pipeline.py` | `test_host_read_burst` |
| CDC async FIFO | `tb/cocotb/tests/test_cdc.py` | `test_cdc_async_fifo` |
| CDC timing | `tb/cocotb/tests/test_cdc.py` | `test_cdc_timing` |
| Packer overflow | `tb/cocotb/tests/test_packer.py` | `test_packer_overflow` |
| RingBuffer full drop | `tb/cocotb/tests/test_ringbuffer.py` | `test_ringbuffer_full_drop` |
| Continuous stream | `tb/cocotb/tests/test_pipeline.py` | `test_pipeline_continuous_stream` |
| RingBuffer stress | `tb/cocotb/tests/test_ringbuffer.py` | `test_ringbuffer_stress` |
| AXI concurrent | `tb/cocotb/tests/test_pipeline.py` | `test_axi_concurrent` |

## 5. 优先级与回归分组

### 5.1 Sanity 回归（快速验证）

**测试用例**：
- `test_top_sanity`
- `test_extractor_smoke`
- `test_packer_smoke`
- `test_ringbuffer_smoke`

**运行命令**：
```bash
tools/build_and_verify.sh --target sanity
# 或
pytest tb/cocotb/tests/test_pipeline.py::test_top_sanity -v
```

### 5.2 Full 回归（完整验证）

**测试用例**：所有 P0 + P1 + P2 测试用例

**运行命令**：
```bash
tools/build_and_verify.sh --target full
# 或
pytest tb/cocotb/tests/ -v
```

### 5.3 专项回归

**Extractor 专项**：
```bash
tools/build_and_verify.sh --target csi
```

**Packer 专项**：
```bash
tools/build_and_verify.sh --target fixed
```

**RingBuffer 专项**：
```bash
tools/build_and_verify.sh --target ddr
```

**Pipeline 专项**：
```bash
tools/build_and_verify.sh --target pipeline
```

## 6. 测试用例实现建议

### 6.1 使用 Scoreboard

**所有测试用例**应使用 Scoreboard 进行数据比较：

```python
from scoreboard.slot_scoreboard import SlotScoreboard
from model.slot_refmodel import SlotRefModel

scoreboard = SlotScoreboard()
ref_model = SlotRefModel()

# 预测 slot
expected_slot = ref_model.payload_to_slot(payload, rx_headers)

# 检查
scoreboard.check_packer_slot(dut_slot, expected_slot, slot_seq)
```

### 6.2 使用现有驱动/监控

**复用现有代码**：
- `awr_payload_model.py`：Payload 生成
- `test_csi2_awr_packets.py`：CSI-2 packet 构建
- `pipeline_cocotb.py`：Pipeline 测试辅助函数

**新增驱动**（Wave 1 设计）：
- `drivers/axis_payload_source.py`：AXIS source 封装
- `drivers/axi_host_master.py`：AXI host master 封装
- `monitors/axis_monitor.py`：AXIS monitor 封装

### 6.3 测试参数化

**使用 pytest 参数化**（可选）：

```python
import pytest

@pytest.mark.parametrize("payload_size", [100, 500, 1000, 12288])
@cocotb.test()
async def test_packer_various_sizes(dut, payload_size):
    """测试不同 payload 大小的 slot 封装"""
    pass
```

## 7. 覆盖率目标

**功能覆盖率**：
- Extractor：VC/DT 过滤、错误检测 → 100%
- Packer：不同 payload 大小、overflow → 100%
- RingBuffer：Ring wrap、drop/overwrite → 100%
- CDC：FIFO 满/空、不同时钟相位 → 100%

**代码覆盖率**（可选，使用 Verilator coverage）：
- 行覆盖率：>90%
- 分支覆盖率：>85%
- 状态机覆盖率：100%
