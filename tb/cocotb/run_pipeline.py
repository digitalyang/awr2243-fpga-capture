from __future__ import annotations

import argparse
import sys
from pathlib import Path

from cocotb_tools.runner import get_runner


REPO_ROOT = Path(__file__).resolve().parents[2]
TB_DIR = Path(__file__).resolve().parent
BUILD_ROOT = REPO_ROOT / "sim_build" / "pipeline_cocotb"
TOPLEVEL = "pipeline_cocotb_top"
TEST_MODULE = "pipeline_cocotb"


def build_sources():
    return [
        REPO_ROOT / "rtl/pkg/csi_packet_pkg.sv",
        REPO_ROOT / "rtl/pkg/slot_packer_pkg.sv",
        REPO_ROOT / "rtl/pkg/ddr_ringbuffer_pkg.sv",
        REPO_ROOT / "rtl/if/axis_stream_if.sv",
        REPO_ROOT / "rtl/if/axi4_mm_if.sv",
        REPO_ROOT / "rtl/core/csi_packet_extractor.sv",
        REPO_ROOT / "rtl/core/fixed_slot_packer.sv",
        REPO_ROOT / "rtl/core/ddr_ringbuffer_controller.sv",
        TB_DIR / "pipeline_cocotb_top.sv",
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
    parser = argparse.ArgumentParser(description="Run Verilator+cocotb regression for the chained pipeline")
    parser.add_argument(
        "--testcase",
        action="append",
        choices=[
            "pipeline_smoke_basic",
            "pipeline_invalid_slot_roundtrip",
            "pipeline_controller_drops_invalid",
        ],
        help="Specific cocotb testcase to run. Defaults to the full pipeline regression.",
    )
    parser.add_argument("--waves", action="store_true", help="Enable waveform dump")
    parser.add_argument("--no-clean", action="store_true", help="Reuse existing build directory")
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    testcases = args.testcase if args.testcase else [
        "pipeline_smoke_basic",
        "pipeline_invalid_slot_roundtrip",
        "pipeline_controller_drops_invalid",
    ]
    run_regression(testcases=testcases, waves=args.waves, clean=not args.no_clean)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
