# Verilator + cocotb Regression

本目录提供 `ddr_ringbuffer_controller` 的开源 smoke regression。

## 依赖

- `Verilator 5.x`
- Python 3.9 到 3.13
- `cocotb` / `pytest`

建议使用独立虚拟环境：

```sh
/usr/bin/python3 -m venv ~/.venvs/awr2243-cocotb-py39
~/.venvs/awr2243-cocotb-py39/bin/python -m pip install -r tb/cocotb/requirements.txt
```

## 运行

`ddr_ringbuffer_controller` 的默认回归会跑两个 testcase：

- `smoke_basic`
- `wraparound_basic`

```sh
~/.venvs/awr2243-cocotb-py39/bin/python tb/cocotb/run_ddr_ringbuffer_controller.py
```

只跑单个 testcase：

```sh
~/.venvs/awr2243-cocotb-py39/bin/python tb/cocotb/run_ddr_ringbuffer_controller.py --testcase smoke_basic
```

打开波形：

```sh
~/.venvs/awr2243-cocotb-py39/bin/python tb/cocotb/run_ddr_ringbuffer_controller.py --waves
```

## 覆盖范围

- slot 写入 DDR
- commit 后 descriptor 对外可见
- 读回 AXIS payload 与元数据校验
- ring wrap-around 基本路径
- AXI4-MM 写/读 burst 基本握手

## 三模块串联回归

仓库中的 3 个核心模块也可以直接串起来做端到端仿真：

- `csi_packet_extractor`
- `fixed_slot_packer`
- `ddr_ringbuffer_controller`

运行命令：

```sh
~/.venvs/awr2243-cocotb-py39/bin/python tb/cocotb/run_pipeline.py
```

默认会跑 5 个 testcase：

- `pipeline_smoke_basic`
- `pipeline_invalid_slot_roundtrip`
- `pipeline_controller_drops_invalid`
- `pipeline_awr_frame_roundtrip`
- `pipeline_awr_frame_crc_error`

这个回归覆盖：

- CSI packet 过滤后进入 slot packer
- slot 固定长度封装与 header/zero padding 校验
- slot 写入 DDR ringbuffer 并读回
- invalid packet 侧带错误在整条链路上的传递
- controller 按配置丢弃 invalid slot
- 基于 AWR2243 风格 `FS/LS/Long/LE/FE` 原始 CSI-2 packet 序列的链路验证
- raw long packet 的 header ECC / payload CRC 错误映射到 extractor sideband

## PCIe host smoke

目录下还提供了一个基于 `cocotbext-pcie` 的 host-side smoke bring-up：

- `drivers/host_rc_driver.py`：root complex / BAR / slot DMA helper
- `model/ddr_ringbuffer_pcie_stub.py`：BAR0 CSR + BAR2 DDR 的 endpoint stub
- `run_pcie_host_smoke.py`：最小 smoke runner

运行命令：

```sh
~/.venvs/awr2243-cocotb-py39/bin/python tb/cocotb/run_pcie_host_smoke.py
```

当前假设：

- endpoint RTL 侧尚未接好时，使用 Python stub 验证 host API
- BAR0 用于 CSR 访问，BAR2 用于 slot readback DMA 读
- `READ_CMD.issue_head_read` 先按 pulse/no-op 建模，等 endpoint ready 后再替换为真实时序
