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

默认会跑 3 个 testcase：

- `pipeline_smoke_basic`
- `pipeline_invalid_slot_roundtrip`
- `pipeline_controller_drops_invalid`

这个回归覆盖：

- CSI packet 过滤后进入 slot packer
- slot 固定长度封装与 header/zero padding 校验
- slot 写入 DDR ringbuffer 并读回
- invalid packet 侧带错误在整条链路上的传递
- controller 按配置丢弃 invalid slot
