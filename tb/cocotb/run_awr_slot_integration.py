from __future__ import annotations

import argparse
import sys
from pathlib import Path

from cocotb_tools.runner import get_runner

REPO_ROOT = Path(__file__).resolve().parents[2]
TB_DIR = Path(__file__).resolve().parent
BUILD_ROOT = REPO_ROOT / "sim_build" / "awr_slot_integration"
TOPLEVEL = "fixed_slot_packer_cocotb_top"
TEST_MODULE = "test_awr_slot_integration"

ALL_TESTS = [
    "test_awr_ramp_ns64",
    "test_awr_const_ns1",
    "test_awr_ramp_ns256",
    "test_awr_exact_fit",
    "test_awr_overflow",
    "test_awr_channel_tag_integrity",
    "test_awr_multi_chirp_sequence",
    "test_awr_backpressure",
    "test_awr_ramp_iq_spot_check",
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
            "--trace-fst",
        ],
    )

    runner.test(
        test_module=TEST_MODULE,
        hdl_toplevel=TOPLEVEL,
        testcase=testcases,
        test_dir=test_dir,
        waves=waves,
        extra_env={"PYTHONPATH": str(TB_DIR)},
    )


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="AWR2243 → fixed_slot_packer integration tests"
    )
    parser.add_argument(
        "--testcase", action="append", choices=ALL_TESTS,
        help="Specific testcase (repeatable). Defaults to all.",
    )
    parser.add_argument("--waves", action="store_true")
    parser.add_argument("--no-clean", action="store_true")
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    testcases = args.testcase if args.testcase else ALL_TESTS
    run_regression(testcases=testcases, waves=args.waves, clean=not args.no_clean)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
