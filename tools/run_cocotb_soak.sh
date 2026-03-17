#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"

MODE="overnight"
COUNT=""
BASE_SEED=""
PYTHON_BIN=""
LOG_DIR=""
REUSE_BUILD=1
CLEAN_FIRST=0
WAVES=0

usage() {
  cat <<'EOF'
Usage:
  tools/run_cocotb_soak.sh [mode] [options]

Modes:
  overnight     Alias for sim-platform with default count=100 and base-seed=10000
  sim-platform  Repeat tb/cocotb/run_sim_platform.py
  fixed         Repeat tb/cocotb/run_fixed_slot_packer.py
  csi           Repeat tb/cocotb/run_csi_packet_extractor.py
  unit          Repeat fixed, then csi
  all           Repeat fixed, csi, then sim-platform

Options:
  --count <n>        Iteration count for each selected mode
  --base-seed <n>    Base seed for the first selected mode
  --python <path>    Python interpreter to use
  --log-dir <path>   Output directory for per-iteration logs
  --waves            Enable waveform dumping
  --clean            Clean build directories on every iteration
  --clean-first      Clean only the first iteration, then reuse builds
  --list-modes       Print available modes and exit
  -h, --help         Show this help

Examples:
  tools/run_cocotb_soak.sh
  tools/run_cocotb_soak.sh sim-platform --count 1000
  tools/run_cocotb_soak.sh unit --count 200 --base-seed 50000
  tools/run_cocotb_soak.sh fixed --count 500 --clean-first
EOF
}

list_modes() {
  cat <<'EOF'
Available modes:
  overnight
  sim-platform
  fixed
  csi
  unit
  all
EOF
}

die() {
  echo "[run_cocotb_soak] error: $*" >&2
  exit 1
}

have_cmd() {
  command -v "$1" >/dev/null 2>&1
}

python_supported() {
  local python_bin="$1"

  "${python_bin}" -c '
import sys
major, minor = sys.version_info[:2]
raise SystemExit(0 if (major, minor) >= (3, 9) and (major, minor) < (3, 14) else 1)
' >/dev/null 2>&1
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
      if python_supported "${candidate}"; then
        echo "${candidate}"
        return
      fi
    elif have_cmd "${candidate}"; then
      candidate="$(command -v "${candidate}")"
      if python_supported "${candidate}"; then
        echo "${candidate}"
        return
      fi
    fi
  done

  die "no supported Python interpreter found"
}

summary_line() {
  local logfile="$1"

  if have_cmd rg; then
    rg -n "TESTS=.*PASS=.*FAIL=.*SKIP=.*" "${logfile}" | tail -n 1 || true
  else
    grep -nE "TESTS=.*PASS=.*FAIL=.*SKIP=.*" "${logfile}" | tail -n 1 || true
  fi
}

default_count_for_mode() {
  case "$1" in
    overnight|sim-platform|fixed|csi|unit|all)
      echo "100"
      ;;
    *)
      die "unsupported mode: $1"
      ;;
  esac
}

default_seed_for_mode() {
  case "$1" in
    overnight|sim-platform)
      echo "10000"
      ;;
    fixed)
      echo "20000"
      ;;
    csi)
      echo "30000"
      ;;
    unit)
      echo "40000"
      ;;
    all)
      echo "50000"
      ;;
    *)
      die "unsupported mode: $1"
      ;;
  esac
}

runner_for_mode() {
  case "$1" in
    overnight|sim-platform)
      echo "tb/cocotb/run_sim_platform.py"
      ;;
    fixed)
      echo "tb/cocotb/run_fixed_slot_packer.py"
      ;;
    csi)
      echo "tb/cocotb/run_csi_packet_extractor.py"
      ;;
    *)
      die "runner requested for composite mode: $1"
      ;;
  esac
}

label_for_mode() {
  case "$1" in
    overnight|sim-platform)
      echo "sim_platform_full"
      ;;
    fixed)
      echo "fixed_slot_packer"
      ;;
    csi)
      echo "csi_packet_extractor"
      ;;
    *)
      die "label requested for composite mode: $1"
      ;;
  esac
}

run_loop() {
  local mode_name="$1"
  local count="$2"
  local base_seed="$3"
  local runner_rel
  local label
  local iter seed log_file summary
  local -a cmd

  runner_rel="$(runner_for_mode "${mode_name}")"
  label="$(label_for_mode "${mode_name}")"

  echo "[run_cocotb_soak] mode=${mode_name} count=${count} base_seed=${base_seed}" | tee -a "${SUMMARY_FILE}"

  for ((iter=1; iter<=count; iter++)); do
    seed=$((base_seed + iter))
    log_file="${LOG_DIR}/${label}_iter$(printf '%03d' "${iter}")_seed${seed}.log"

    cmd=("${PYTHON_PATH}" "${REPO_ROOT}/${runner_rel}")
    if (( WAVES )); then
      cmd+=("--waves")
    fi
    if (( REUSE_BUILD )); then
      if (( !CLEAN_FIRST || iter != 1 )); then
        cmd+=("--no-clean")
      fi
    fi

    echo "[$(date +%H:%M:%S)] ${label} iter ${iter}/${count} seed=${seed}" | tee -a "${SUMMARY_FILE}"

    if ! COCOTB_RANDOM_SEED="${seed}" "${cmd[@]}" >"${log_file}" 2>&1; then
      echo "[run_cocotb_soak] FAILED mode=${mode_name} iter=${iter} seed=${seed} log=${log_file}" | tee -a "${SUMMARY_FILE}"
      tail -n 120 "${log_file}" | tee -a "${SUMMARY_FILE}"
      exit 1
    fi

    summary="$(summary_line "${log_file}")"
    if [[ -n "${summary}" ]]; then
      echo "${summary}" | tee -a "${SUMMARY_FILE}"
    fi
  done
}

parse_args() {
  while (($# > 0)); do
    case "$1" in
      overnight|sim-platform|fixed|csi|unit|all)
        MODE="$1"
        shift
        ;;
      --count)
        [[ $# -ge 2 ]] || die "--count requires a value"
        COUNT="$2"
        shift 2
        ;;
      --base-seed)
        [[ $# -ge 2 ]] || die "--base-seed requires a value"
        BASE_SEED="$2"
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
      --clean)
        REUSE_BUILD=0
        CLEAN_FIRST=0
        shift
        ;;
      --clean-first)
        REUSE_BUILD=1
        CLEAN_FIRST=1
        shift
        ;;
      --list-modes)
        list_modes
        exit 0
        ;;
      -h|--help)
        usage
        exit 0
        ;;
      *)
        die "unsupported argument: $1"
        ;;
    esac
  done
}

parse_args "$@"

if [[ -z "${COUNT}" ]]; then
  COUNT="$(default_count_for_mode "${MODE}")"
fi
if [[ -z "${BASE_SEED}" ]]; then
  BASE_SEED="$(default_seed_for_mode "${MODE}")"
fi

[[ "${COUNT}" =~ ^[0-9]+$ ]] || die "--count must be a non-negative integer"
[[ "${BASE_SEED}" =~ ^[0-9]+$ ]] || die "--base-seed must be a non-negative integer"
(( COUNT > 0 )) || die "--count must be greater than zero"

PYTHON_PATH="$(resolve_python)"

if [[ -z "${LOG_DIR}" ]]; then
  TS="$(date +%Y%m%d_%H%M%S)"
  LOG_DIR="${REPO_ROOT}/sim_build/stress_logs/${TS}_${MODE}"
fi
mkdir -p "${LOG_DIR}"
SUMMARY_FILE="${LOG_DIR}/summary.txt"

echo "[run_cocotb_soak] repo_root=${REPO_ROOT}" | tee "${SUMMARY_FILE}"
echo "[run_cocotb_soak] python=${PYTHON_PATH}" | tee -a "${SUMMARY_FILE}"
echo "[run_cocotb_soak] log_dir=${LOG_DIR}" | tee -a "${SUMMARY_FILE}"
echo "[run_cocotb_soak] reuse_build=${REUSE_BUILD} clean_first=${CLEAN_FIRST} waves=${WAVES}" | tee -a "${SUMMARY_FILE}"

SECONDS=0

case "${MODE}" in
  overnight|sim-platform)
    run_loop "sim-platform" "${COUNT}" "${BASE_SEED}"
    ;;
  fixed)
    run_loop "fixed" "${COUNT}" "${BASE_SEED}"
    ;;
  csi)
    run_loop "csi" "${COUNT}" "${BASE_SEED}"
    ;;
  unit)
    run_loop "fixed" "${COUNT}" "${BASE_SEED}"
    run_loop "csi" "${COUNT}" "$((BASE_SEED + 100000))"
    ;;
  all)
    run_loop "fixed" "${COUNT}" "${BASE_SEED}"
    run_loop "csi" "${COUNT}" "$((BASE_SEED + 100000))"
    run_loop "sim-platform" "${COUNT}" "$((BASE_SEED + 200000))"
    ;;
  *)
    die "unsupported mode: ${MODE}"
    ;;
esac

echo "[run_cocotb_soak] DONE elapsed=${SECONDS}s log_dir=${LOG_DIR}" | tee -a "${SUMMARY_FILE}"
