from __future__ import annotations

import argparse
import importlib
import sys
from pathlib import Path

from cocotb_tools.runner import get_runner


REPO_ROOT = Path(__file__).resolve().parents[2]
TB_DIR = Path(__file__).resolve().parent
BUILD_ROOT = REPO_ROOT / "sim_build" / "pcie_host_smoke"
TOPLEVEL = "pcie_host_smoke_top"
TEST_MODULE = "tests.test_pcie_host_smoke"
TESTCASES = [
    "test_pcie_host_bringup_smoke",
    "test_pcie_host_waits_for_concurrent_slot_and_wraps_readback",
]


def check_dependencies() -> None:
    try:
        importlib.import_module("cocotbext.pcie.core")
    except ModuleNotFoundError as exc:
        raise SystemExit(
            "Missing dependency: cocotbext-pcie. Install tb/cocotb/requirements.txt "
            "or run tools/build_and_verify.sh --install-deps."
        ) from exc


def build_sources() -> list[Path]:
    return [
        TB_DIR / "pcie_host_smoke_top.sv",
    ]


def run_regression(testcases: list[str], waves: bool, clean: bool) -> None:
    runner = get_runner("verilator")
    build_dir = BUILD_ROOT / "build"
    test_dir = BUILD_ROOT / "test"
    test_filter = None if not testcases else ".*(" + "|".join(testcases) + ")$"

    runner.build(
        sources=build_sources(),
        hdl_toplevel=TOPLEVEL,
        build_dir=build_dir,
        clean=clean,
        always=True,
        waves=waves,
        timescale=("1ns", "1ps"),
        build_args=[
            "-Wall",
            "-Wno-fatal",
            "--trace-fst",
        ],
    )

    runner.test(
        test_module=TEST_MODULE,
        hdl_toplevel=TOPLEVEL,
        test_filter=test_filter,
        test_dir=test_dir,
        waves=waves,
        extra_env={
            "PYTHONPATH": str(TB_DIR),
        },
    )


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the cocotbext-pcie host smoke tests")
    parser.add_argument(
        "--testcase",
        action="append",
        choices=TESTCASES,
        help="Specific cocotb testcase to run. Defaults to the full PCIe host smoke regression.",
    )
    parser.add_argument("--waves", action="store_true", help="Enable waveform dump")
    parser.add_argument("--no-clean", action="store_true", help="Reuse existing build directory")
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    check_dependencies()
    run_regression(testcases=args.testcase or TESTCASES, waves=args.waves, clean=not args.no_clean)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
