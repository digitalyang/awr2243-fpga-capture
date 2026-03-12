from __future__ import annotations

import argparse
import sys
from pathlib import Path

from cocotb_tools.runner import get_runner


REPO_ROOT = Path(__file__).resolve().parents[2]
TB_DIR = Path(__file__).resolve().parent
BUILD_ROOT = REPO_ROOT / "sim_build" / "awr2243_cmd_decode_cocotb"
TOPLEVEL = "awr2243_cmd_decode_cocotb_top"
TEST_MODULE = "awr2243_cmd_decode_cocotb"

ALL_TESTS = [
    "test_spi_write_and_end",
    "test_delay_and_wait_irq",
    "test_error_paths",
]


def build_sources():
    return [
        REPO_ROOT / "rtl/pkg/awr2243_script_pkg.sv",
        REPO_ROOT / "rtl/core/awr2243_cmd_decode.sv",
        TB_DIR / "awr2243_cmd_decode_cocotb_top.sv",
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
            "-Wno-UNUSEDPARAM",
            "-Wno-WIDTHTRUNC",
            "-Wno-WIDTHEXPAND",
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
        description="Run Verilator+cocotb regression for awr2243_cmd_decode"
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
