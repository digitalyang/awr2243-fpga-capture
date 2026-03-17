#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"

PYTHON_BIN=""
DATASET=""
SLOT_BYTES=""
LOG_DIR=""
MAX_SLOTS="256"
VERIFY_EVERY="32"
RING_SIZE_BYTES="65536"
TIMEOUT_CYCLES="4000"
NO_CLEAN=1
WAVES=0
ALL_SLOTS=0

usage() {
  cat <<'EOF'
Usage:
  tools/run_perf_dataset.sh [options]

Default behavior:
  Runs the DDR ringbuffer continuous write+read perf test on:
    sim_build/perf_data/perf_slot_400MiB.bin
  with:
    --max-slots 256
    --verify-every 32

Options:
  --dataset <path>          Slot dataset to read. Default: sim_build/perf_data/perf_slot_400MiB.bin
  --slot-bytes <n>          Slot size in bytes. Default: read from dataset .json metadata, else 12352
  --max-slots <n>           Limit the number of slots to process. Use 0 for the whole file. Default: 256
  --all-slots               Equivalent to --max-slots 0
  --verify-every <n>        DDR image verification cadence. 0 disables spot checks. Default: 32
  --ring-size <n>           Ring size in bytes. Default: 65536
  --timeout-cycles <n>      Timeout for commit/read collection. Default: 4000
  --python <path>           Python interpreter to use
  --log-dir <path>          Directory for the run log. Default: sim_build/perf_logs/<timestamp>
  --clean                   Rebuild Verilator output from scratch
  --waves                   Enable waveform dump
  -h, --help                Show this help

Examples:
  tools/run_perf_dataset.sh
  tools/run_perf_dataset.sh --all-slots
  tools/run_perf_dataset.sh --dataset sim_build/perf_data/perf_slot_400MiB.bin --max-slots 1024
EOF
}

die() {
  echo "[run_perf_dataset] error: $*" >&2
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

parse_args() {
  while (($# > 0)); do
    case "$1" in
      --dataset)
        [[ $# -ge 2 ]] || die "--dataset requires a value"
        DATASET="$2"
        shift 2
        ;;
      --slot-bytes)
        [[ $# -ge 2 ]] || die "--slot-bytes requires a value"
        SLOT_BYTES="$2"
        shift 2
        ;;
      --max-slots)
        [[ $# -ge 2 ]] || die "--max-slots requires a value"
        MAX_SLOTS="$2"
        shift 2
        ;;
      --all-slots)
        ALL_SLOTS=1
        shift
        ;;
      --verify-every)
        [[ $# -ge 2 ]] || die "--verify-every requires a value"
        VERIFY_EVERY="$2"
        shift 2
        ;;
      --ring-size)
        [[ $# -ge 2 ]] || die "--ring-size requires a value"
        RING_SIZE_BYTES="$2"
        shift 2
        ;;
      --timeout-cycles)
        [[ $# -ge 2 ]] || die "--timeout-cycles requires a value"
        TIMEOUT_CYCLES="$2"
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
      --clean)
        NO_CLEAN=0
        shift
        ;;
      --waves)
        WAVES=1
        shift
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

PYTHON_PATH="$(resolve_python)"

if [[ -z "${DATASET}" ]]; then
  DATASET="${REPO_ROOT}/sim_build/perf_data/perf_slot_400MiB.bin"
fi

[[ -f "${DATASET}" ]] || die "dataset not found: ${DATASET}"

if (( ALL_SLOTS )); then
  MAX_SLOTS="0"
fi

[[ "${MAX_SLOTS}" =~ ^[0-9]+$ ]] || die "--max-slots must be a non-negative integer"
[[ "${VERIFY_EVERY}" =~ ^[0-9]+$ ]] || die "--verify-every must be a non-negative integer"
[[ "${RING_SIZE_BYTES}" =~ ^[0-9]+$ ]] || die "--ring-size must be a non-negative integer"
[[ "${TIMEOUT_CYCLES}" =~ ^[0-9]+$ ]] || die "--timeout-cycles must be a non-negative integer"

if [[ -z "${SLOT_BYTES}" ]]; then
  META_JSON="${DATASET}.json"
  if [[ -f "${META_JSON}" ]]; then
    SLOT_BYTES="$("${PYTHON_PATH}" - <<'PY' "${META_JSON}"
import json, sys
from pathlib import Path
meta = json.loads(Path(sys.argv[1]).read_text())
slot_bytes = meta.get("slot_bytes")
print(slot_bytes if slot_bytes else "")
PY
)"
  fi
fi

if [[ -z "${SLOT_BYTES}" ]]; then
  SLOT_BYTES="12352"
fi

[[ "${SLOT_BYTES}" =~ ^[0-9]+$ ]] || die "--slot-bytes must be a non-negative integer"
(( SLOT_BYTES > 0 )) || die "--slot-bytes must be greater than zero"

DATASET_SIZE="$("${PYTHON_PATH}" - <<'PY' "${DATASET}"
from pathlib import Path
import sys
print(Path(sys.argv[1]).stat().st_size)
PY
)"
TOTAL_SLOTS_IN_FILE=$((DATASET_SIZE / SLOT_BYTES))

if [[ -z "${LOG_DIR}" ]]; then
  TS="$(date +%Y%m%d_%H%M%S)"
  LOG_DIR="${REPO_ROOT}/sim_build/perf_logs/${TS}"
fi
mkdir -p "${LOG_DIR}"
LOG_FILE="${LOG_DIR}/perf_dataset_roundtrip.log"

if [[ "${MAX_SLOTS}" == "0" ]]; then
  SELECTED_SLOTS="${TOTAL_SLOTS_IN_FILE}"
else
  if (( MAX_SLOTS > TOTAL_SLOTS_IN_FILE )); then
    SELECTED_SLOTS="${TOTAL_SLOTS_IN_FILE}"
  else
    SELECTED_SLOTS="${MAX_SLOTS}"
  fi
fi

{
  echo "[run_perf_dataset] repo_root=${REPO_ROOT}"
  echo "[run_perf_dataset] python=${PYTHON_PATH}"
  echo "[run_perf_dataset] dataset=${DATASET}"
  echo "[run_perf_dataset] dataset_size=${DATASET_SIZE}"
  echo "[run_perf_dataset] slot_bytes=${SLOT_BYTES}"
  echo "[run_perf_dataset] total_slots_in_file=${TOTAL_SLOTS_IN_FILE}"
  echo "[run_perf_dataset] selected_slots=${SELECTED_SLOTS}"
  echo "[run_perf_dataset] verify_every=${VERIFY_EVERY}"
  echo "[run_perf_dataset] ring_size_bytes=${RING_SIZE_BYTES}"
  echo "[run_perf_dataset] timeout_cycles=${TIMEOUT_CYCLES}"
  echo "[run_perf_dataset] log_file=${LOG_FILE}"
} | tee "${LOG_FILE}"

CMD=("${PYTHON_PATH}" "${REPO_ROOT}/tb/cocotb/run_ddr_ringbuffer_controller.py" "--testcase" "perf_dataset_roundtrip")
if (( NO_CLEAN )); then
  CMD+=("--no-clean")
fi
if (( WAVES )); then
  CMD+=("--waves")
fi

PERF_DATASET="${DATASET}" \
PERF_SLOT_BYTES="${SLOT_BYTES}" \
PERF_MAX_SLOTS="${MAX_SLOTS}" \
PERF_VERIFY_EVERY="${VERIFY_EVERY}" \
PERF_RING_SIZE_BYTES="${RING_SIZE_BYTES}" \
PERF_TIMEOUT_CYCLES="${TIMEOUT_CYCLES}" \
"${CMD[@]}" 2>&1 | tee -a "${LOG_FILE}"

echo "[run_perf_dataset] done" | tee -a "${LOG_FILE}"
