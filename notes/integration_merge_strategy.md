# integration merge strategy

Prepared in `agent-integrator` on `2026-03-12`.

## Current board state

- `integration_final` is blocked by:
  - `awr2243_cfg_sequencer`
  - `awr2243_ctrl_top`
- All completed upstream tasks currently live as uncommitted worktree changes, not branch commits.
- Known overlapping edits already exist in:
  - `tools/build_and_verify.sh`
  - `BUILD_AND_VERIFY.md`

## Observed worktree outputs

- `agent-spi`
  - `rtl/core/spi_master_engine.sv`
- `agent-core`
  - `rtl/core/awr2243_timer.sv`
- `agent-csr`
  - `rtl/core/csr_reg_block.sv`
- `agent-gpio`
  - `rtl/core/awr2243_status_mon.sv`
  - `rtl/core/awr2243_reset_ctrl.sv`
  - `tb/cocotb/run_awr2243_status_mon.py`
  - `tb/cocotb/run_awr2243_reset_ctrl.py`
  - matching cocotb tops and tests
- `agent-script`
  - `rtl/core/awr2243_script_ram.sv`
  - `rtl/core/awr2243_cmd_fetch.sv`
  - `rtl/core/awr2243_cmd_decode.sv`
  - `rtl/include/awr2243_script_macros.svh`
  - `rtl/pkg/awr2243_script_pkg.sv`
  - `tb/cocotb/run_awr2243_script_ram.py`
  - `tb/cocotb/run_awr2243_cmd_fetch.py`
  - `tb/cocotb/run_awr2243_cmd_decode.py`
  - matching cocotb tops and tests
  - `tools/build_and_verify.sh`
  - `BUILD_AND_VERIFY.md`
- `agent-sequencer`
  - not ready yet; only prep notes and helper script are present
- `agent-top`
  - not ready yet; only prep notes are present

## Merge order once ready

1. Re-run `state.json`, `status`, and `integration-check` from the main repo.
2. Claim `integration_final` with the main repo `tools/codex_swarm.py`.
3. Copy completed module outputs from sibling worktrees into this worktree in dependency order:
   - `agent-spi`
   - `agent-core`
   - `agent-csr`
   - `agent-gpio`
   - `agent-script`
   - `agent-sequencer`
   - `agent-top`
4. Resolve tracked-file overlaps manually before staging:
   - keep the Python 3.9-3.13 interpreter filter
   - keep the `rg`/`grep` fallback
   - keep the `awr-script` targets and docs
5. Run focused control-path verification before repo-level regression.
6. Run repo-level regression from the integrator worktree.
7. Record the exact merge result and verification commands with `note` and then `complete`.

## Verification plan

- Focused control-path checks:
  - `python3 tb/cocotb/run_awr2243_status_mon.py`
  - `python3 tb/cocotb/run_awr2243_reset_ctrl.py`
  - `python3 tb/cocotb/run_awr2243_script_ram.py`
  - `python3 tb/cocotb/run_awr2243_cmd_fetch.py`
  - `python3 tb/cocotb/run_awr2243_cmd_decode.py`
  - add sequencer/top regressions once those agents publish them
- Aggregated wrapper checks after merge:
  - `tools/build_and_verify.sh --target awr-script`
  - `tools/build_and_verify.sh --target sanity`

## Open integration risks

- `awr2243_cfg_sequencer` and `awr2243_ctrl_top` have not produced RTL yet.
- Because upstream work is uncommitted, final integration is file-level copy/merge work, not a pure `git merge`.
- The plan file does not yet include control-path wrapper targets in `integration_final.verify_commands`, so final signoff should log the richer command set explicitly in swarm notes.
