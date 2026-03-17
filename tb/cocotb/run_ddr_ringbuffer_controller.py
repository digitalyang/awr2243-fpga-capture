from __future__ import annotations

import argparse
import sys
from pathlib import Path

from cocotb_tools.runner import get_runner


REPO_ROOT = Path(__file__).resolve().parents[2]
TB_DIR = Path(__file__).resolve().parent
BUILD_ROOT = REPO_ROOT / "sim_build" / "ddr_ringbuffer_controller_cocotb"
TOPLEVEL = "ddr_ringbuffer_controller_cocotb_top"
TEST_MODULE = "ddr_ringbuffer_controller_cocotb"


def build_sources():
    return [
        REPO_ROOT / "rtl/pkg/ddr_ringbuffer_pkg.sv",
        REPO_ROOT / "rtl/if/axis_stream_if.sv",
        REPO_ROOT / "rtl/if/axi4_mm_if.sv",
        REPO_ROOT / "tb/models/xpm_memory_sdpram_stub.sv",
        REPO_ROOT / "rtl/core/ddr_ringbuffer_controller.sv",
        TB_DIR / "ddr_ringbuffer_controller_cocotb_top.sv",
    ]


def run_regression(testcases: list[str], waves: bool, clean: bool) -> None:
    runner = get_runner("verilator")
    build_dir = BUILD_ROOT / "build"
    test_dir = BUILD_ROOT / "test"
    test_filter = ".*(" + "|".join(testcases) + ")$"

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
            "-Wno-fatal",
            "-Wno-DECLFILENAME",
            "-Wno-UNUSEDSIGNAL",
            "-Wno-UNDRIVEN",
            "-Wno-UNUSEDPARAM",
            "-Wno-EOFNEWLINE",
            "-Wno-PINCONNECTEMPTY",
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
    parser = argparse.ArgumentParser(description="Run Verilator+cocotb regression for ddr_ringbuffer_controller")
    parser.add_argument(
        "--testcase",
        action="append",
        choices=["smoke_basic", "wraparound_basic", "perf_dataset_roundtrip"],
        help="Specific cocotb testcase to run. Defaults to full smoke regression.",
    )
    parser.add_argument("--waves", action="store_true", help="Enable waveform dump")
    parser.add_argument("--no-clean", action="store_true", help="Reuse existing build directory")
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    testcases = args.testcase if args.testcase else ["smoke_basic", "wraparound_basic"]
    run_regression(testcases=testcases, waves=args.waves, clean=not args.no_clean)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
