# Slot 布局：README / RTL / Cocotb 对照

## 1. 常量与公式

| 项目 | README (§4) | RTL (slot_packer_macros.svh + fixed_slot_packer.sv) | Cocotb (awr_payload_model.py) |
|------|-------------|------------------------------------------------------|-------------------------------|
| 每 RX header | 24bit = 3B | HEADER_BYTES/4 = 3B（未单列，总 12B） | RX_HEADER_BYTES_EACH = 3 |
| RX headers 总长 | 4×24bit = 12B | HEADER_BYTES = 12 | RX_HEADER_BYTES_TOTAL = 12 |
| Sample 区 | 1024×12B = 12288B | SAMPLE_SLOT_NUM×SAMPLE_UNIT_BYTES = 1024×12 | SAMPLE_AREA_BYTES = 1024×12 |
| CQ 区 | 6×12bit = 9B | CQ_AREA_BYTES = 9 | CQ_WORD_COUNT=6, CQ_BYTES=9 |
| 对齐 | 64B | ALIGN_BYTES = 64 | ALIGN_BYTES = 64 |
| 未对齐总长 | 12+12288+9 = 12309 | SLOT_TOTAL_RAW = HEADER + SAMPLE_AREA + CQ | SLOT_TOTAL_UNALIGNED = 12309 |
| 对齐后总长 | 12352B | SLOT_TOTAL_ALIGN = align_up(12309,64) | SLOT_TOTAL_ALIGNED = 12352 |
| Padding | 43B | 12352−12309 | SLOT_PADDING_BYTES = 43 |

**结论**：三处使用的常量和计算公式一致。

---

## 2. Slot 区段顺序

| 顺序 | README (§4.1) | RTL | Cocotb build_expected_slot_bytes |
|------|----------------|-----|----------------------------------|
| 1 | rx_headers | 0 .. HEADER_BYTES-1 (append 写) | header |
| 2 | sample_area | HEADER_BYTES .. CQ_START_BYTE-1 | sample |
| 3 | CQ_area | CQ_START_BYTE .. CQ_START_BYTE+CQ_AREA_BYTES-1 | cq |
| 4 | padding | 至 SLOT_TOTAL_ALIGN | b"\x00"*SLOT_PADDING_BYTES |

RTL 中 `CQ_START_BYTE = HEADER_BYTES + SAMPLE_AREA_BYTES`（= 12300），CQ 写在 `ST_CQ_WRITE` 阶段。  
**结论**：区段顺序一致：header → sample → CQ → padding。

---

## 3. 可能的不一致点（Vivado 适配后重点查）

### 3.1 字节在 beat 内的位置（AXI-Stream 约定）

- **RTL 写入**：`tmp_data[lane_idx*8 +: 8] = in_byte`，即 lane 0 = [7:0]，lane 1 = [15:8]，…（小端，首字节在 LSB）。
- **Cocotb 采集**：`int_to_bytes_le(int(dut.m_axis_tdata.value), 32)`，即把 256 位按整数小端转 32 字节，首字节为 LSB。
- 若 Vivado 或综合后 `m_axis_tdata` 的位序/字节序与上述约定不一致（例如某处按大端或不同 lane 顺序），会出现“布局看起来对但逐字节比较失败”。

**建议**：在仿真里对第一个失败用例打印 `expected_slot` 与 `cap.data` 首次不同的下标和该 beat 的 hex；确认是“同一 beat 内字节序”还是“整 beat 错位”。

### 3.2 RTL 中 slot 的拼接方式（与 README 一致）

RTL 实际行为如下（`fixed_slot_packer.sv`）：

1. **Header（0..11）**  
   - `pkt_byte_pos_before_this_byte < HEADER_BYTES` 时，直接 `append_byte_to_shadow(cur_byte, ...)`，按顺序写入 `abs_pos` 0→11。  
   - 结果：slot[0:12] = payload[0:12]。

2. **Header 之后的所有字节（≥12）—— 9 字节滑动窗口**  
   - 用 `tail_tmp[0..8]` 做 9 字节滑动窗口，`tail_cnt` 为当前窗口内字节数。  
   - **当 `tail_cnt < CQ_AREA_BYTES`（9）**：只把当前字节放进 `tail_tmp[tail_cnt]`，不写内存。即 payload 的字节 12..20 先只进窗口。  
   - **当 `tail_cnt == 9`**：每来一新字节就 (1) 把**窗口里最旧的一字节** `tail_tmp[0]` 用 `append_byte_to_shadow` 写到当前 `abs_pos`，(2) 窗口左移：`tail_tmp[i]=tail_tmp[i+1]`，(3) 新字节进 `tail_tmp[8]`。  
   - 因此：先写出的 9 字节是 payload[12..20]，再写 payload[21]，[22]，… 顺序不变。  
   - 结果：slot[12 : 12+(N-12-9)] = payload[12 : N-9]，其中 N = 本包有效字节数；即 **sample 区（及若 payload 更长则多出的部分）按 payload 顺序写入**。

3. **pkt_done 时**  
   - 窗口里剩下的 9 字节 = payload 的**最后 9 字节**（即 CQ 区内容）。  
   - 非截断：`cq_buf_n = tail_tmp`，进入 `ST_CAP_FLUSH` → `ST_ZERO_MID` → **ST_CQ_WRITE**。  
   - **ST_CQ_WRITE**：用 `append_byte_to_shadow(cq_buf_r[i], ...)` 把 `cq_buf_r[0..8]` 写到 `abs_pos = CQ_START_BYTE`（12300）起。  
   - 结果：slot[12300:12309] = payload 最后 9 字节 = CQ。

4. **Zero / Padding**  
   - **ST_ZERO_MID**：从 `ceil(wr_abs_pos_r/AXIS_BEAT_BYTES)` 起把整 beat 填 0，直到 `CQ_START_BEAT`（不包含）。  
   - **ST_CQ_FLUSH** 后再 **ST_ZERO_TAIL**：从当前 beat 起把到 `SLOT_TOTAL_BEATS` 的 beat 都写 0，形成 padding。

**结论**：RTL 拼接顺序与 README 一致：**header（直写）→ sample（滑动窗口顺序写出）→ CQ（pkt_done 后从窗口存到 cq_buf，再在 ST_CQ_WRITE 写到 CQ_START_BYTE）→ zero/padding**。与 Cocotb 的「header | sample | cq | padding」一致。

若 Vivado 适配时改动了 `ST_CAPTURE` 里 `tail_tmp`/`append_byte_to_shadow` 的调用条件、或 `CQ_START_BYTE`/`CQ_START_BEAT` 的计算，可能只影响某些 payload 长度（例如正好 12309 或带截断时）。

**建议**：对 12309 字节的 payload，在 RTL 里临时打 log（或波形）确认：写出的前 12 字节 = payload[0:12]，12300..12308 = payload[12300:12309]，中间 12288 字节 = payload[12:12300]。

### 3.3 README 与代码的命名差异（仅文档）

- README 写的是 `SLOT_TOTAL_UNALIGNED` / `SLOT_TOTAL_ALIGNED`（§4.4）。
- RTL 里是 `SLOT_TOTAL_RAW` / `SLOT_TOTAL_ALIGN`，含义相同。

如需与 README 完全一致，可在 RTL 注释或文档中注明对应关系，避免误解。

---

## 4. 小结

- **布局与常数**：README、RTL（宏 + fixed_slot_packer）、awr_payload_model 三者一致（12+12288+9，对齐 64，12352B，header→sample→CQ→padding）。
- **cocotb 失败**（slot payload layout mismatch）更可能来自：
  1. **beat 内字节序/位序** 与 cocotb 的 `int_to_bytes_le` 假设不一致（Vivado/网表/仿真器差异），或  
  2. **Vivado 适配** 中改动了 capture/zero-fill/CQ 写入的细节。

建议下一步：在 `verify_slot` 里一旦 `d != expected_slot`，打印 `next(i for i in range(len(d)) if d[i] != expected_slot[i])` 和该 beat 的索引，便于判断是“同一 beat 内错位”还是“整段错位”。
