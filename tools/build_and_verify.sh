#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"

PYTHON_BIN=""
LOG_DIR=""
INSTALL_DEPS=0
NO_CLEAN=0
WAVES=0
REQUESTED_TARGETS=()
SELECTED_TARGETS=()
TESTCASES=()

usage() {
  cat <<'EOF'
Usage:
  tools/build_and_verify.sh [options]

Default behavior:
  Runs the "sanity" regression set:
    - csi
    - fixed
    - ddr
    - pipeline

Options:
  --target <name>     Regression target. Repeatable.
  --testcase <name>   Pass a specific testcase through to the selected target.
                      Only valid when exactly one concrete target is selected.
  --python <path>     Python interpreter to use.
  --log-dir <path>    Directory for regression logs.
  --waves             Enable waveform dumping.
  --no-clean          Reuse existing Verilator build directories.
  --install-deps      Install tb/cocotb/requirements.txt into the selected Python env.
  --list-targets      Print available targets and exit.
  -h, --help          Show this help.

Examples:
  tools/build_and_verify.sh
  tools/build_and_verify.sh --target pipeline
  tools/build_and_verify.sh --target ddr --testcase smoke_basic
  tools/build_and_verify.sh --target full --python ./.venv313/bin/python
EOF
}

list_targets() {
  cat <<'EOF'
Available targets:
  csi          Run csi_packet_extractor cocotb regression
  fixed        Run fixed_slot_packer cocotb regression
  ddr          Run ddr_ringbuffer_controller cocotb regression
  pipeline     Run chained pipeline cocotb regression
  awr-payload  Run AWR payload generator tests
  awr-slot     Run AWR slot integration tests
  sanity       Expand to: csi, fixed, ddr, pipeline
  full         Expand to: sanity, awr-payload, awr-slot
EOF
}

die() {
  echo "[build_and_verify] error: $*" >&2
  exit 1
}

have_cmd() {
  command -v "$1" >/dev/null 2>&1
}

append_unique_target() {
  local item="$1"
  local existing

  for existing in "${SELECTED_TARGETS[@]:-}"; do
    if [[ "$existing" == "$item" ]]; then
      return
    fi
  done

  SELECTED_TARGETS+=("$item")
}

expand_target() {
  local target="$1"

  case "$target" in
    csi)
      append_unique_target "csi"
      ;;
    fixed|slot)
      append_unique_target "fixed"
      ;;
    ddr|ring)
      append_unique_target "ddr"
      ;;
    pipeline)
      append_unique_target "pipeline"
      ;;
    awr-payload)
      append_unique_target "awr-payload"
      ;;
    awr-slot)
      append_unique_target "awr-slot"
      ;;
    sanity)
      expand_target "csi"
      expand_target "fixed"
      expand_target "ddr"
      expand_target "pipeline"
      ;;
    full)
      expand_target "sanity"
      expand_target "awr-payload"
      expand_target "awr-slot"
      ;;
    *)
      die "unsupported target: ${target}"
      ;;
  esac
}

resolve_python() {
  local candidate

  if [[ -n "${PYTHON_BIN}" ]]; then
    if [[ -x "${PYTHON_BIN}" ]]; then
      echo "${PYTHON_BIN}"
      return
    fi

    if have_cmd "${PYTHON_BIN}"; then
      command -v "${PYTHON_BIN}"
      return
    fi

    die "python interpreter not found: ${PYTHON_BIN}"
  fi

  for candidate in \
    "${REPO_ROOT}/.venv313/bin/python" \
    "${REPO_ROOT}/.venv/bin/python" \
    python3 \
    python; do
    if [[ -x "${candidate}" ]]; then
      echo "${candidate}"
      return
    fi

    if have_cmd "${candidate}"; then
      command -v "${candidate}"
      return
    fi
  done

  die "no usable python found; pass --python or create .venv313/.venv"
}

target_script() {
  local target="$1"

  case "$target" in
    csi)
      echo "${REPO_ROOT}/tb/cocotb/run_csi_packet_extractor.py"
      ;;
    fixed)
      echo "${REPO_ROOT}/tb/cocotb/run_fixed_slot_packer.py"
      ;;
    ddr)
      echo "${REPO_ROOT}/tb/cocotb/run_ddr_ringbuffer_controller.py"
      ;;
    pipeline)
      echo "${REPO_ROOT}/tb/cocotb/run_pipeline.py"
      ;;
    awr-payload)
      echo "${REPO_ROOT}/tb/cocotb/run_awr_payload.py"
      ;;
    awr-slot)
      echo "${REPO_ROOT}/tb/cocotb/run_awr_slot_integration.py"
      ;;
    *)
      die "no runner script mapped for target: ${target}"
      ;;
  esac
}

while (($# > 0)); do
  case "$1" in
    --target)
      [[ $# -ge 2 ]] || die "--target requires a value"
      REQUESTED_TARGETS+=("$2")
      shift 2
      ;;
    --testcase)
      [[ $# -ge 2 ]] || die "--testcase requires a value"
      TESTCASES+=("$2")
      shift 2
      ;;
    --python)
      [[ $# -ge 2 ]] || die "--python requires a value"
      PYTHON_BIN="$2"
      shift 2
      ;;
    --log-dir)
      [[ $# -ge 2 ]] || die "--log-dir requires a value"
      LOG_DIR="$2"
      shift 2
      ;;
    --waves)
      WAVES=1
      shift
      ;;
    --no-clean)
      NO_CLEAN=1
      shift
      ;;
    --install-deps)
      INSTALL_DEPS=1
      shift
      ;;
    --list-targets)
      list_targets
      exit 0
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    *)
      die "unknown option: $1"
      ;;
  esac
done

if [[ ${#REQUESTED_TARGETS[@]} -eq 0 ]]; then
  REQUESTED_TARGETS=("sanity")
fi

for target in "${REQUESTED_TARGETS[@]}"; do
  expand_target "${target}"
done

if [[ ${#TESTCASES[@]} -gt 0 && ${#SELECTED_TARGETS[@]} -ne 1 ]]; then
  die "--testcase only works when exactly one concrete target is selected"
fi

PYTHON_BIN="$(resolve_python)"

if ! have_cmd verilator; then
  die "verilator is not in PATH"
fi

if [[ -z "${LOG_DIR}" ]]; then
  LOG_DIR="${REPO_ROOT}/sim_build/regression_logs/$(date +%Y%m%d_%H%M%S)_build_verify"
fi

mkdir -p "${LOG_DIR}"

echo "[build_and_verify] repo   : ${REPO_ROOT}"
echo "[build_and_verify] python : ${PYTHON_BIN}"
echo "[build_and_verify] logs   : ${LOG_DIR}"
echo "[build_and_verify] targets: ${SELECTED_TARGETS[*]}"

if [[ ${INSTALL_DEPS} -eq 1 ]]; then
  echo "[build_and_verify] installing cocotb requirements"
  "${PYTHON_BIN}" -m pip install -r "${REPO_ROOT}/tb/cocotb/requirements.txt"
fi

run_target() {
  local target="$1"
  local script
  local logfile
  local cmd=()

  script="$(target_script "${target}")"
  logfile="${LOG_DIR}/${target}.log"

  cmd=("${PYTHON_BIN}" "${script}")

  if [[ ${WAVES} -eq 1 ]]; then
    cmd+=("--waves")
  fi

  if [[ ${NO_CLEAN} -eq 1 ]]; then
    cmd+=("--no-clean")
  fi

  if [[ ${#TESTCASES[@]} -gt 0 ]]; then
    local testcase
    for testcase in "${TESTCASES[@]}"; do
      cmd+=("--testcase" "${testcase}")
    done
  fi

  echo "[build_and_verify] running ${target}"
  if "${cmd[@]}" >"${logfile}" 2>&1; then
    echo "[build_and_verify] PASS ${target}"
    rg -n "TESTS=|FAIL=|PASS=" "${logfile}" | tail -n 5 || true
  else
    echo "[build_and_verify] FAIL ${target}" >&2
    echo "[build_and_verify] tail of ${logfile}:" >&2
    tail -n 80 "${logfile}" >&2 || true
    exit 1
  fi
}

for target in "${SELECTED_TARGETS[@]}"; do
  run_target "${target}"
done

echo "[build_and_verify] completed successfully"
echo "[build_and_verify] detailed logs: ${LOG_DIR}"
