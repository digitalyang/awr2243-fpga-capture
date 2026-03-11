#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "${script_dir}/../.." && pwd)"
deps_dir="${script_dir}/.deps"

if [[ -d "${deps_dir}" ]]; then
    export PYTHONPATH="${deps_dir}${PYTHONPATH:+:${PYTHONPATH}}"
fi

if ! command -v peakrdl >/dev/null 2>&1; then
    echo "peakrdl command not found. Install PeakRDL first." >&2
    exit 1
fi

plugins="$(peakrdl --plugins)"
for plugin in regblock c-header uvm; do
    if [[ "${plugins}" != *"${plugin}"* ]]; then
        echo "Missing PeakRDL plugin '${plugin}'." >&2
        echo "Run: ${script_dir}/install_peakrdl_deps.sh" >&2
        exit 1
    fi
done

mkdir -p \
    "${repo_root}/rtl/generated" \
    "${repo_root}/sw/include/generated" \
    "${repo_root}/tb/uvm/ral"

peakrdl regblock \
    "${repo_root}/rdl/ddr_ringbuffer_controller.rdl" \
    -t ddr_ringbuffer_controller_csr \
    --cpuif axi4-lite-flat \
    --module-name ddr_ringbuffer_controller_csr \
    --package-name ddr_ringbuffer_controller_csr_pkg \
    --default-reset arst_n \
    --hwif-report \
    -o "${repo_root}/rtl/generated"

peakrdl c-header \
    "${repo_root}/rdl/ddr_ringbuffer_controller.rdl" \
    -t ddr_ringbuffer_controller_csr \
    -o "${repo_root}/sw/include/generated/ddr_ringbuffer_controller_csr.h"

peakrdl uvm \
    "${repo_root}/rdl/ddr_ringbuffer_controller.rdl" \
    -t ddr_ringbuffer_controller_csr \
    -o "${repo_root}/tb/uvm/ral/ddr_ringbuffer_controller_csr_ral_pkg.sv"

echo "Generated:"
echo "  rtl/generated/ddr_ringbuffer_controller_csr_pkg.sv"
echo "  rtl/generated/ddr_ringbuffer_controller_csr.sv"
echo "  rtl/generated/ddr_ringbuffer_controller_csr_hwif.rpt"
echo "  sw/include/generated/ddr_ringbuffer_controller_csr.h"
echo "  tb/uvm/ral/ddr_ringbuffer_controller_csr_ral_pkg.sv"
