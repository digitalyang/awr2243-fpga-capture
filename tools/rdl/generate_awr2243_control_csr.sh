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
    "${repo_root}/rdl/awr2243_control.rdl" \
    -t awr2243_control_csr \
    --cpuif axi4-lite-flat \
    --module-name awr2243_control_csr \
    --package-name awr2243_control_csr_pkg \
    --default-reset arst_n \
    --hwif-report \
    -o "${repo_root}/rtl/generated"

peakrdl c-header \
    "${repo_root}/rdl/awr2243_control.rdl" \
    -t awr2243_control_csr \
    -o "${repo_root}/sw/include/generated/awr2243_control_csr.h"

peakrdl uvm \
    "${repo_root}/rdl/awr2243_control.rdl" \
    -t awr2243_control_csr \
    -o "${repo_root}/tb/uvm/ral/awr2243_control_csr_ral_pkg.sv"

echo "Generated:"
echo "  rtl/generated/awr2243_control_csr_pkg.sv"
echo "  rtl/generated/awr2243_control_csr.sv"
echo "  rtl/generated/awr2243_control_csr_hwif.rpt"
echo "  sw/include/generated/awr2243_control_csr.h"
echo "  tb/uvm/ral/awr2243_control_csr_ral_pkg.sv"
