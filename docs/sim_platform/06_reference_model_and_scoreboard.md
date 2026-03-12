# 参考模型与 Scoreboard 设计

## 1. 参考模型范围

### 1.1 建模范围

**推荐范围**：**payload → slot 布局 → DDR 地址映射**

- **Payload → Slot 布局**：将原始 payload（RX headers + samples + CQ）转换为固定长度 slot（12352B，64B 对齐）
- **Slot → DDR 地址**：计算 slot 在 ring buffer 中的地址（基于 ring_base_addr、wr_ptr、slot 序号）
- **DDR 写入顺序**：预测 slot 写入 DDR 的顺序与地址
- **Host 读数据**：预测 Host 从 DDR 读取的 slot 数据（基于 rd_ptr、slot 描述符）

**不建模**：
- CSI-2 packet 解析细节（由 Extractor 处理）
- AXI 协议细节（由 cocotbext-axi 处理）
- DDR 物理时序（由 DDR Model 处理）

### 1.2 实现语言

**推荐**：**Python（cocotb）**

- 便于与 cocotb 测试集成
- 易于实现 slot 格式转换、地址计算
- 可复用现有 `awr_payload_model.py`（`tb/cocotb/awr_payload_model.py`）

**参考模型位置**：`tb/cocotb/model/slot_refmodel.py`（或复用/扩展 `awr_payload_model.py`）

## 2. Reference Model 设计

### 2.1 Slot 格式参考模型

**基于现有 `awr_payload_model.py`**，扩展为完整的 reference model：

```python
# tb/cocotb/model/slot_refmodel.py
from typing import List, Tuple
from awr_payload_model import (
    HEADER_BYTES, SAMPLE_AREA_BYTES, CQ_AREA_BYTES,
    SLOT_TOTAL_ALIGNED, pack_rx_header, pack_cq_raw12,
    gen_one_sample, build_expected_slot_bytes
)

class SlotRefModel:
    """Slot 格式参考模型"""
    
    def __init__(self):
        self.slot_seq = 0
    
    def payload_to_slot(self, payload_bytes: bytes, rx_headers: List[Tuple[int, int, int]], 
                       cq_data: int = 0, sample_count: int = 1024) -> bytes:
        """
        将 payload 转换为固定长度 slot
        
        Args:
            payload_bytes: 原始 payload（samples）
            rx_headers: [(channel_id, chirp_profile, chirp_num), ...] (4 个)
            cq_data: CQ 数据（64bit）
            sample_count: Sample 数量（默认 1024）
        
        Returns:
            固定长度 slot bytes (12352B)
        """
        # 1. Pack RX headers (12B)
        header_bytes = b""
        for ch_id, cp, cn in rx_headers:
            header_bytes += pack_rx_header(ch_id, cp, cn)
        
        # 2. Pack samples (12288B，不足补 0)
        sample_bytes = payload_bytes[:SAMPLE_AREA_BYTES]
        if len(sample_bytes) < SAMPLE_AREA_BYTES:
            sample_bytes += b"\x00" * (SAMPLE_AREA_BYTES - len(sample_bytes))
        
        # 3. Pack CQ (9B)
        cq_bytes = pack_cq_raw12(cq_data)
        
        # 4. Padding to 64B alignment
        slot_unaligned = header_bytes + sample_bytes + cq_bytes
        padding_bytes = SLOT_TOTAL_ALIGNED - len(slot_unaligned)
        slot_bytes = slot_unaligned + b"\x00" * padding_bytes
        
        assert len(slot_bytes) == SLOT_TOTAL_ALIGNED, f"Slot size mismatch: {len(slot_bytes)} != {SLOT_TOTAL_ALIGNED}"
        return slot_bytes
    
    def predict_slot_addr(self, ring_base_addr: int, wr_ptr: int, slot_bytes: int) -> int:
        """
        预测 slot 在 DDR 中的地址
        
        Args:
            ring_base_addr: Ring buffer 基址
            wr_ptr: 当前写指针（相对于 ring_base_addr）
            slot_bytes: Slot 字节数（12352）
        
        Returns:
            Slot 的绝对 DDR 地址
        """
        return ring_base_addr + wr_ptr
    
    def predict_next_wr_ptr(self, wr_ptr: int, ring_size_bytes: int, slot_bytes: int) -> int:
        """
        预测下一个写指针（考虑 ring wrap）
        
        Args:
            wr_ptr: 当前写指针
            ring_size_bytes: Ring buffer 大小
            slot_bytes: Slot 字节数
        
        Returns:
            下一个写指针
        """
        next_ptr = wr_ptr + slot_bytes
        if next_ptr >= ring_size_bytes:
            next_ptr = next_ptr % ring_size_bytes  # Wrap around
        return next_ptr
```

### 2.2 DDR 写入顺序模型

```python
class DDRWriteModel:
    """DDR 写入顺序参考模型"""
    
    def __init__(self, ring_base_addr: int, ring_size_bytes: int):
        self.ring_base_addr = ring_base_addr
        self.ring_size_bytes = ring_size_bytes
        self.wr_ptr = 0
        self.committed_slots = []  # [(addr, slot_bytes, seq, valid_good), ...]
    
    def commit_slot(self, slot_bytes: int, slot_seq: int, valid_good: bool = True):
        """提交一个 slot，记录地址与描述符"""
        slot_addr = self.ring_base_addr + self.wr_ptr
        self.committed_slots.append((slot_addr, slot_bytes, slot_seq, valid_good))
        self.wr_ptr = (self.wr_ptr + slot_bytes) % self.ring_size_bytes
    
    def get_head_slot(self) -> Tuple[int, int, int, bool]:
        """获取队首 slot（最老未读）"""
        if not self.committed_slots:
            return None
        return self.committed_slots[0]
    
    def consume_head(self):
        """消费队首 slot"""
        if self.committed_slots:
            self.committed_slots.pop(0)
```

### 2.3 Host 读数据模型

```python
class HostReadModel:
    """Host 读数据参考模型"""
    
    def __init__(self, ddr_model: dict):  # ddr_model: {addr: bytes}
        self.ddr_model = ddr_model
    
    def read_slot(self, slot_addr: int, slot_bytes: int) -> bytes:
        """
        从 DDR model 读取 slot 数据
        
        Args:
            slot_addr: Slot 地址
            slot_bytes: Slot 字节数
        
        Returns:
            Slot 数据 bytes
        """
        slot_data = b""
        for offset in range(0, slot_bytes, 64):  # 假设 64B 对齐
            addr = slot_addr + offset
            if addr in self.ddr_model:
                chunk = self.ddr_model[addr:addr+64]
                slot_data += chunk[:min(64, slot_bytes - offset)]
            else:
                slot_data += b"\x00" * min(64, slot_bytes - offset)
        return slot_data[:slot_bytes]
```

## 3. Scoreboard 设计

### 3.1 比较内容

| 比较点 | DUT 输出 | 参考模型输出 | 比较时机 |
|--------|----------|--------------|----------|
| **Extractor 输出 AXIS** | `m_axis` 数据流 | 参考模型：过滤后的 payload | 每个 packet 完成时 |
| **Packer 输出 slot** | `m_axis` slot 数据 + sideband | 参考模型：`payload_to_slot()` | 每个 slot 完成时（`slot_done_o`） |
| **DDR 写入地址** | `wr_slot_addr_o` | 参考模型：`predict_slot_addr()` | Slot 提交时（`wr_slot_commit_o`） |
| **DDR 写入数据** | DDR Model 内容（通过 AXI write） | 参考模型：`payload_to_slot()` | Slot 提交后 |
| **Host 读数据** | AXI host master 读回的数据 | 参考模型：`read_slot()` | Host 读完成时 |

### 3.2 Scoreboard 实现

**位置**：`tb/cocotb/scoreboard/slot_scoreboard.py`

```python
# tb/cocotb/scoreboard/slot_scoreboard.py
from typing import List, Optional
from model.slot_refmodel import SlotRefModel, DDRWriteModel, HostReadModel

class SlotScoreboard:
    """Slot 数据比较 Scoreboard"""
    
    def __init__(self):
        self.ref_model = SlotRefModel()
        self.ddr_write_model = None
        self.host_read_model = None
        self.errors = []
        self.matches = 0
    
    def configure_ring(self, ring_base_addr: int, ring_size_bytes: int):
        """配置 ring buffer 参数"""
        self.ddr_write_model = DDRWriteModel(ring_base_addr, ring_size_bytes)
    
    def configure_ddr(self, ddr_model: dict):
        """配置 DDR model（用于 Host 读预测）"""
        self.host_read_model = HostReadModel(ddr_model)
    
    def check_extractor_output(self, dut_payload: bytes, expected_payload: bytes, pkt_seq: int):
        """检查 Extractor 输出"""
        if dut_payload != expected_payload:
            self.errors.append(f"Extractor pkt_seq={pkt_seq}: payload mismatch")
            return False
        self.matches += 1
        return True
    
    def check_packer_slot(self, dut_slot: bytes, expected_slot: bytes, slot_seq: int):
        """检查 Packer 输出 slot"""
        if dut_slot != expected_slot:
            self.errors.append(f"Packer slot_seq={slot_seq}: slot data mismatch")
            # 可选：详细比较 header/sample/CQ 区域
            return False
        self.matches += 1
        return True
    
    def check_ddr_write_addr(self, dut_addr: int, expected_addr: int, slot_seq: int):
        """检查 DDR 写入地址"""
        if dut_addr != expected_addr:
            self.errors.append(f"Slot seq={slot_seq}: DDR addr mismatch: dut={hex(dut_addr)} vs ref={hex(expected_addr)}")
            return False
        return True
    
    def check_host_read(self, dut_data: bytes, slot_addr: int, slot_bytes: int):
        """检查 Host 读数据"""
        expected_data = self.host_read_model.read_slot(slot_addr, slot_bytes)
        if dut_data != expected_data:
            self.errors.append(f"Host read addr={hex(slot_addr)}: data mismatch")
            return False
        self.matches += 1
        return True
    
    def get_summary(self) -> dict:
        """获取 Scoreboard 摘要"""
        return {
            "matches": self.matches,
            "errors": len(self.errors),
            "error_list": self.errors
        }
```

### 3.3 Scoreboard 集成到测试

**使用示例**（在测试中）：

```python
import cocotb
from scoreboard.slot_scoreboard import SlotScoreboard
from model.slot_refmodel import SlotRefModel

@cocotb.test()
async def test_pipeline_with_scoreboard(dut):
    """使用 Scoreboard 的 pipeline 测试"""
    # 初始化 Scoreboard
    scoreboard = SlotScoreboard()
    scoreboard.configure_ring(ring_base_addr=0x1000, ring_size_bytes=0x4000)
    
    ref_model = SlotRefModel()
    
    # 发送 payload
    payload_bytes = b"..."  # 实际 payload
    rx_headers = [(0, 0, 0), (1, 0, 0), (2, 0, 0), (3, 0, 0)]
    expected_slot = ref_model.payload_to_slot(payload_bytes, rx_headers)
    
    # 等待 slot 完成
    await RisingEdge(dut.slot_done_o)
    
    # 检查 Packer 输出（通过 monitor 捕获）
    dut_slot = monitor.get_last_slot()
    scoreboard.check_packer_slot(dut_slot, expected_slot, slot_seq=0)
    
    # 检查 DDR 写入地址
    expected_addr = ref_model.predict_slot_addr(0x1000, 0, 12352)
    scoreboard.check_ddr_write_addr(int(dut.wr_slot_addr_o.value), expected_addr, slot_seq=0)
    
    # Host 读回检查
    host_data = await host.read_slot(slot_addr, slot_bytes)
    scoreboard.check_host_read(host_data, slot_addr, slot_bytes)
    
    # 最终检查
    summary = scoreboard.get_summary()
    assert summary["errors"] == 0, f"Scoreboard errors: {summary['error_list']}"
```

## 4. 在仓库中的位置

### 4.1 目录结构

```
tb/cocotb/
├── model/                       # Reference model
│   └── slot_refmodel.py        # Slot 格式、DDR 地址、写入顺序模型
│                                # （可复用/扩展现有 awr_payload_model.py）
├── scoreboard/                  # Scoreboard
│   └── slot_scoreboard.py      # Slot 数据比较 Scoreboard
└── tests/
    └── test_pipeline.py        # 测试用例（使用 scoreboard）
```

### 4.2 与现有代码的关系

**现有代码**：
- `tb/cocotb/awr_payload_model.py`：已有 slot 格式函数（`build_expected_slot_bytes` 等）

**建议**：
- **复用**：`slot_refmodel.py` 可直接 import `awr_payload_model`，扩展为完整 reference model
- **或迁移**：将 `awr_payload_model.py` 移动到 `model/` 目录，重命名为 `slot_refmodel.py`

## 5. 类/函数草图

### 5.1 SlotRefModel（完整）

```python
class SlotRefModel:
    """Slot 格式参考模型"""
    
    def payload_to_slot(self, payload_bytes, rx_headers, cq_data=0, sample_count=1024) -> bytes:
        """Payload → Slot (12352B)"""
        pass
    
    def predict_slot_addr(self, ring_base_addr, wr_ptr, slot_bytes) -> int:
        """预测 slot DDR 地址"""
        pass
    
    def predict_next_wr_ptr(self, wr_ptr, ring_size_bytes, slot_bytes) -> int:
        """预测下一个写指针（考虑 wrap）"""
        pass
```

### 5.2 DDRWriteModel

```python
class DDRWriteModel:
    """DDR 写入顺序模型"""
    
    def __init__(self, ring_base_addr, ring_size_bytes):
        pass
    
    def commit_slot(self, slot_bytes, slot_seq, valid_good=True):
        """提交 slot，记录地址"""
        pass
    
    def get_head_slot(self) -> Tuple[int, int, int, bool]:
        """获取队首 slot"""
        pass
    
    def consume_head(self):
        """消费队首 slot"""
        pass
```

### 5.3 HostReadModel

```python
class HostReadModel:
    """Host 读数据模型"""
    
    def __init__(self, ddr_model: dict):
        pass
    
    def read_slot(self, slot_addr, slot_bytes) -> bytes:
        """从 DDR model 读 slot"""
        pass
```

### 5.4 SlotScoreboard

```python
class SlotScoreboard:
    """Slot Scoreboard"""
    
    def configure_ring(self, ring_base_addr, ring_size_bytes):
        """配置 ring buffer"""
        pass
    
    def configure_ddr(self, ddr_model):
        """配置 DDR model"""
        pass
    
    def check_extractor_output(self, dut_payload, expected_payload, pkt_seq):
        """检查 Extractor 输出"""
        pass
    
    def check_packer_slot(self, dut_slot, expected_slot, slot_seq):
        """检查 Packer slot"""
        pass
    
    def check_ddr_write_addr(self, dut_addr, expected_addr, slot_seq):
        """检查 DDR 写入地址"""
        pass
    
    def check_host_read(self, dut_data, slot_addr, slot_bytes):
        """检查 Host 读数据"""
        pass
    
    def get_summary(self) -> dict:
        """获取摘要"""
        pass
```

## 6. 测试对接

### 6.1 测试中使用 Scoreboard

**步骤**：
1. 创建 Scoreboard 实例
2. 配置 ring buffer 和 DDR model
3. 运行测试，在关键点调用 Scoreboard 检查函数
4. 测试结束时检查 Scoreboard 摘要

**示例**（见上文 3.3 节）。

### 6.2 与 cocotb monitor 集成

**Monitor 捕获数据** → **Scoreboard 比较**：

```python
# Monitor 捕获 slot 数据
monitor = AxisMonitor(dut.m_axis, dut.axis_clk)
cocotb.start_soon(monitor.capture())

# Scoreboard 比较
scoreboard = SlotScoreboard()
# ... 运行测试 ...
dut_slot = monitor.get_last_slot()
scoreboard.check_packer_slot(dut_slot, expected_slot, slot_seq)
```

## 7. 验证覆盖

**Scoreboard 覆盖**：
1. **数据完整性**：Payload → Slot → DDR → Host 读，数据无丢失/损坏
2. **地址正确性**：DDR 写入地址符合 ring buffer 规则
3. **顺序正确性**：Slot 写入/读出的顺序符合 FIFO 语义
4. **错误处理**：Invalid slot 的正确丢弃/标记
