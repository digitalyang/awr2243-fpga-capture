# Build And Verify

## Purpose

This repository now provides a single entry-point script for Verilator + cocotb
build and regression runs:

```sh
tools/build_and_verify.sh
```

The script wraps the existing module-level and pipeline regression runners under
`tb/cocotb/run_*.py`, checks the local environment, and stores per-target logs
under `sim_build/regression_logs/`.

## Prerequisites

- `Verilator 5.x`
- Python 3.9 to 3.13
- `cocotb` and `pytest`

The script automatically prefers these Python interpreters in order:

1. `./.venv313/bin/python`
2. `./.venv/bin/python`
3. `python3`
4. `python`

To install cocotb dependencies into the selected Python environment:

```sh
tools/build_and_verify.sh --install-deps --target csi
```

## Default Run

Running the script with no arguments launches the `sanity` regression set:

- `csi`
- `fixed`
- `ddr`
- `pipeline`

```sh
tools/build_and_verify.sh
```

This is the recommended command for a normal pre-push verification pass.

## Available Targets

```text
csi          csi_packet_extractor standalone regression
fixed        fixed_slot_packer standalone regression
ddr          ddr_ringbuffer_controller standalone regression
pipeline     end-to-end 3-module pipeline regression
script-ram   awr2243_script_ram regression
cmd-fetch    awr2243_cmd_fetch regression
cmd-decode   awr2243_cmd_decode regression
awr-script   expands to: script-ram, cmd-fetch, cmd-decode
awr-payload  AWR payload generator tests
awr-slot     AWR payload -> fixed slot integration tests
sanity       expands to: csi, fixed, ddr, pipeline
full         expands to: sanity, awr-payload, awr-slot
```

List them from the script:

```sh
tools/build_and_verify.sh --list-targets
```

## Common Examples

Run the default sanity suite:

```sh
tools/build_and_verify.sh
```

Run only the DDR ringbuffer controller regression:

```sh
tools/build_and_verify.sh --target ddr
```

Run the pipeline regression and dump waveforms:

```sh
tools/build_and_verify.sh --target pipeline --waves
```

Run the AWR2243 script-side control regressions:

```sh
tools/build_and_verify.sh --target awr-script
```

Reuse an existing Verilator build directory:

```sh
tools/build_and_verify.sh --target pipeline --no-clean
```

Use a specific Python interpreter:

```sh
tools/build_and_verify.sh --target sanity --python ./.venv313/bin/python
```

Run one testcase from one concrete target:

```sh
tools/build_and_verify.sh --target ddr --testcase smoke_basic
tools/build_and_verify.sh --target pipeline --testcase pipeline_smoke_basic
```

`--testcase` is intentionally limited to a single concrete target. Do not mix it
with grouped targets like `sanity` or `full`.

## Logs

Each run creates a timestamped log directory under:

```text
sim_build/regression_logs/<timestamp>_build_verify/
```

Each target writes a separate log file:

```text
csi.log
fixed.log
ddr.log
pipeline.log
script-ram.log
cmd-fetch.log
cmd-decode.log
awr-payload.log
awr-slot.log
```

The wrapper prints a short PASS/FAIL summary to the terminal and keeps the full
build/simulation output in those log files.

## Notes

- The wrapper reuses the existing cocotb runner scripts instead of replacing them.
- The script is intended for local build/regression use; it does not modify RTL.
- If a regression fails, the script stops on the first failing target and prints
  the tail of the failing log.
