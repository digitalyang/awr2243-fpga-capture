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

默认回归会跑两个 testcase：

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
