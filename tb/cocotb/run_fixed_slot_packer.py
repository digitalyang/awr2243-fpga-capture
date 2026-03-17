from __future__ import annotations

import argparse
import sys
from pathlib import Path

from cocotb_tools.runner import get_runner


REPO_ROOT = Path(__file__).resolve().parents[2]
TB_DIR = Path(__file__).resolve().parent
BUILD_ROOT = REPO_ROOT / "sim_build" / "fixed_slot_packer_cocotb"
TOPLEVEL = "fixed_slot_packer_cocotb_top"
TEST_MODULE = "fixed_slot_packer_cocotb"

ALL_TESTS = [
    "test_smoke",
    "test_short_pkt",
    "test_single_beat",
    "test_cq_crosses_before_last_beat",
    "test_full_slot",
    "test_overflow",
    "test_mark_invalid",
    "test_drop_invalid",
    "test_multi_pkt",
    "test_backpressure",
]


def build_sources():
    return [
        REPO_ROOT / "rtl/pkg/slot_packer_pkg.sv",
        REPO_ROOT / "rtl/if/axis_stream_if.sv",
        REPO_ROOT / "rtl/core/fixed_slot_packer.sv",
        TB_DIR / "fixed_slot_packer_cocotb_top.sv",
    ]


def run_regression(testcases: list[str], waves: bool, clean: bool) -> None:
    runner = get_runner("verilator")
    build_dir = BUILD_ROOT / "build"
    test_dir = BUILD_ROOT / "test"

    runner.build(
        sources=build_sources(),
        includes=[REPO_ROOT / "rtl/include"],
        hdl_toplevel=TOPLEVEL,
        build_dir=build_dir,
        clean=clean,
        always=True,
        waves=waves,
        timescale=("1ns", "1ps"),
        build_args=[
            "-Wall",
            "-Wno-DECLFILENAME",
            "-Wno-UNUSEDSIGNAL",
            "-Wno-UNDRIVEN",
            "-Wno-UNUSEDPARAM",
            "-Wno-WIDTHTRUNC",
            "-Wno-WIDTHEXPAND",
            "-Wno-MULTIDRIVEN",
            "-Wno-LATCH",
            "-Wno-EOFNEWLINE",
            "--trace-fst",
        ],
    )

    runner.test(
        test_module=TEST_MODULE,
        hdl_toplevel=TOPLEVEL,
        testcase=testcases,
        test_dir=test_dir,
        waves=waves,
        extra_env={
            "PYTHONPATH": str(TB_DIR),
        },
    )


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run Verilator+cocotb regression for fixed_slot_packer"
    )
    parser.add_argument(
        "--testcase",
        action="append",
        choices=ALL_TESTS,
        help="Specific testcase to run (repeatable). Defaults to all.",
    )
    parser.add_argument("--waves", action="store_true", help="Enable waveform dump")
    parser.add_argument("--no-clean", action="store_true", help="Reuse existing build")
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    testcases = args.testcase if args.testcase else ALL_TESTS
    run_regression(testcases=testcases, waves=args.waves, clean=not args.no_clean)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
