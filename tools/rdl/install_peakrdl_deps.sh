#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
deps_dir="${script_dir}/.deps"

python3 -m pip install --target "${deps_dir}" -r "${script_dir}/requirements.txt"

echo "Installed PeakRDL dependencies into ${deps_dir}"
