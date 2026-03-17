# Cocotb 测试说明

这个目录放的是本工程的 `cocotb` 测试平台、顶层仿真封装、Python runner 和具体测试用例。

如果只是想跑测试，优先用仓库根目录下的脚本入口：

- `tools/build_and_verify.sh`
- `tools/run_cocotb_soak.sh`
- `tools/generate_perf_dataset.py`
- `tools/run_perf_dataset.sh`

这些脚本已经把常用参数和日志目录约定好了，日常使用不需要直接手敲所有 `cocotb` 参数。

## 目录结构

- `tb/cocotb/run_*.py`
  - 各模块的 cocotb runner，负责组织 Verilator 编译源、顶层模块、test module 和参数。
- `tb/cocotb/tests/`
  - 集成类测试用例，主要是 pipeline / platform 级验证。
- `tb/cocotb/*_cocotb.py`
  - 单模块 cocotb driver / monitor / testcase。
- `tb/cocotb/*_top.sv`
  - 仿真顶层封装。

## 环境准备

建议在仓库根目录执行，优先使用项目虚拟环境：

```bash
cd /Users/hb39209/Desktop/awr2243-fpga-capture
./.venv313/bin/python --version
verilator --version
```

如果没有 `.venv313`，需要先准备 Python 依赖和 Verilator 环境。下面的脚本默认会优先尝试：

- `./.venv313/bin/python`
- `./.venv/bin/python`
- `python3`
- `python`

## 常用测试入口

### 1. 回归入口

脚本：

- [build_and_verify.sh](/Users/hb39209/Desktop/awr2243-fpga-capture/tools/build_and_verify.sh)

用途：

- 跑工程常用回归集合。
- 适合做一次性基线检查。

示例：

```bash
cd /Users/hb39209/Desktop/awr2243-fpga-capture
tools/build_and_verify.sh
```

结果怎么看：

- 终端最后会有每组测试的 `PASS/FAIL` 汇总。
- 详细日志在 `sim_build/regression_logs/<时间戳>_build_verify/`。

重点看：

- `csi.log`
- `fixed.log`
- `ddr.log`
- `pipeline.log`
- `sim-platform.log`

### 2. 单模块 runner

这些脚本在 `tb/cocotb/` 下，适合单独定位问题。

常用 runner：

- [run_csi_packet_extractor.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/run_csi_packet_extractor.py)
- [run_fixed_slot_packer.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/run_fixed_slot_packer.py)
- [run_ddr_ringbuffer_controller.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/run_ddr_ringbuffer_controller.py)
- [run_sim_pipeline.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/run_sim_pipeline.py)
- [run_sim_platform.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/run_sim_platform.py)

示例：

```bash
cd /Users/hb39209/Desktop/awr2243-fpga-capture
./.venv313/bin/python tb/cocotb/run_fixed_slot_packer.py
./.venv313/bin/python tb/cocotb/run_csi_packet_extractor.py
./.venv313/bin/python tb/cocotb/run_sim_platform.py
```

只跑某个 testcase：

```bash
./.venv313/bin/python tb/cocotb/run_fixed_slot_packer.py --testcase test_drop_invalid
./.venv313/bin/python tb/cocotb/run_sim_pipeline.py --testcase test_top_sanity
```

常用参数：

- `--testcase <name>`: 只跑指定用例
- `--waves`: 保留波形
- `--no-clean`: 不清理 `sim_build`，适合重复压力跑

结果怎么看：

- 终端会直接打印 cocotb summary，例如 `TESTS=10 PASS=10 FAIL=0 SKIP=0`。
- 如果失败，先看终端最后一段 traceback。
- 需要更详细信息时，保留完整 stdout 到日志文件。

### 3. 压力测试入口

脚本：

- [run_cocotb_soak.sh](/Users/hb39209/Desktop/awr2243-fpga-capture/tools/run_cocotb_soak.sh)

用途：

- 多 seed、多轮次重复跑 cocotb。
- 用来观察随机扰动下是否有不稳定失败。

默认行为：

- 默认模式是 `sim-platform`
- 默认次数是 `100`
- 日志会写到 `sim_build/stress_logs/<时间戳>_<mode>/`

示例：

```bash
cd /Users/hb39209/Desktop/awr2243-fpga-capture
tools/run_cocotb_soak.sh
tools/run_cocotb_soak.sh sim-platform --count 1000
tools/run_cocotb_soak.sh fixed --count 500
tools/run_cocotb_soak.sh csi --count 500
tools/run_cocotb_soak.sh unit --count 200
tools/run_cocotb_soak.sh all --count 100
```

帮助：

```bash
tools/run_cocotb_soak.sh --help
```

结果怎么看：

- 每轮都会打印当前 `iter` 和 `seed`。
- 如果失败，脚本会立即停下，并打印失败的日志路径。
- 完成后看：
  - `sim_build/stress_logs/<时间戳>_<mode>/summary.txt`
  - 同目录下每轮的 `*.log`

### 4. 性能数据生成

脚本：

- [generate_perf_dataset.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tools/generate_perf_dataset.py)

用途：

- 生成大体量、可重复的测试数据，用于连续读写和吞吐测试。

支持格式：

- `slot`
- `payload`
- `csi`

示例：

```bash
cd /Users/hb39209/Desktop/awr2243-fpga-capture
python3 tools/generate_perf_dataset.py --size 400MiB --format slot --output sim_build/perf_data/perf_slot_400MiB.bin
python3 tools/generate_perf_dataset.py --size 400MiB --format csi --output sim_build/perf_data/perf_csi_400MiB.bin
```

结果怎么看：

- 数据文件在 `sim_build/perf_data/`
- 同名 `.json` 是元数据

例如：

- `sim_build/perf_data/perf_slot_400MiB.bin`
- `sim_build/perf_data/perf_slot_400MiB.bin.json`

元数据里重点看：

- `size_bytes`
- `slot_count`
- `slot_bytes`
- `format`
- `seed`

### 5. 性能测试入口

脚本：

- [run_perf_dataset.sh](/Users/hb39209/Desktop/awr2243-fpga-capture/tools/run_perf_dataset.sh)

用途：

- 用生成好的 dataset 驱动 `ddr_ringbuffer_controller` 的连续写入和读回 bench。
- 当前对应的 cocotb testcase 是 `perf_dataset_roundtrip`，定义在 [ddr_ringbuffer_controller_cocotb.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/ddr_ringbuffer_controller_cocotb.py)。

默认行为：

- 默认 dataset 是 `sim_build/perf_data/perf_slot_400MiB.bin`
- 默认只跑前 `256` 个 slot
- 日志输出到 `sim_build/perf_logs/<时间戳>/perf_dataset_roundtrip.log`

示例：

```bash
cd /Users/hb39209/Desktop/awr2243-fpga-capture
tools/run_perf_dataset.sh
tools/run_perf_dataset.sh --all-slots
tools/run_perf_dataset.sh --max-slots 1024
tools/run_perf_dataset.sh --dataset sim_build/perf_data/perf_slot_400MiB.bin --max-slots 256
```

帮助：

```bash
tools/run_perf_dataset.sh --help
```

结果怎么看：

- 终端和日志里会打印关键统计值。
- 优先看这些字段：
  - `slots`
  - `slot_bytes`
  - `total_bytes`
  - `total_elapsed_ns`
  - `total_mib_s`
  - `write_mib_s`
  - `read_mib_s`

如果失败：

- 脚本会返回非零退出码。
- 先看 `perf_dataset_roundtrip.log` 最后的 traceback。

## 推荐使用方式

### 做功能基线

```bash
tools/build_and_verify.sh
```

或者直接跑平台集成：

```bash
./.venv313/bin/python tb/cocotb/run_sim_platform.py
```

### 定位模块问题

先单跑模块，再回到集成：

```bash
./.venv313/bin/python tb/cocotb/run_fixed_slot_packer.py
./.venv313/bin/python tb/cocotb/run_csi_packet_extractor.py
./.venv313/bin/python tb/cocotb/run_ddr_ringbuffer_controller.py
./.venv313/bin/python tb/cocotb/run_sim_pipeline.py
```

### 做稳定性验证

```bash
tools/run_cocotb_soak.sh sim-platform --count 100
```

### 做连续读写性能验证

```bash
python3 tools/generate_perf_dataset.py --size 400MiB --format slot --output sim_build/perf_data/perf_slot_400MiB.bin
tools/run_perf_dataset.sh --all-slots
```

## 结果判读建议

### 功能测试

看到这类 summary 可以认为这轮通过：

```text
TESTS=19 PASS=19 FAIL=0 SKIP=0
```

如果失败：

1. 先看失败的是哪个 testcase。
2. 再看报错是协议超时、payload mismatch 还是顶层编译失败。
3. 最后再决定是看波形，还是直接看对应 cocotb testcase 代码。

### 压力测试

压力测试脚本最重要的是两点：

- 是否中途退出
- `summary.txt` 是否显示全部迭代完成

只要某一轮失败，脚本会立即停住，并把失败日志路径打印出来。

### 性能测试

性能测试更关注吞吐和稳定性：

- `total_mib_s`: 总体吞吐
- `write_mib_s`: 写通道吞吐
- `read_mib_s`: 读通道吞吐

如果缩小 `--max-slots` 后吞吐明显变化，一般说明统计窗口太短，不够稳定。

## 相关文件

入口脚本：

- [build_and_verify.sh](/Users/hb39209/Desktop/awr2243-fpga-capture/tools/build_and_verify.sh)
- [run_cocotb_soak.sh](/Users/hb39209/Desktop/awr2243-fpga-capture/tools/run_cocotb_soak.sh)
- [generate_perf_dataset.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tools/generate_perf_dataset.py)
- [run_perf_dataset.sh](/Users/hb39209/Desktop/awr2243-fpga-capture/tools/run_perf_dataset.sh)

主要 runner：

- [run_csi_packet_extractor.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/run_csi_packet_extractor.py)
- [run_fixed_slot_packer.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/run_fixed_slot_packer.py)
- [run_ddr_ringbuffer_controller.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/run_ddr_ringbuffer_controller.py)
- [run_sim_pipeline.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/run_sim_pipeline.py)
- [run_sim_platform.py](/Users/hb39209/Desktop/awr2243-fpga-capture/tb/cocotb/run_sim_platform.py)

主要日志目录：

- `sim_build/regression_logs/`
- `sim_build/stress_logs/`
- `sim_build/perf_data/`
- `sim_build/perf_logs/`
