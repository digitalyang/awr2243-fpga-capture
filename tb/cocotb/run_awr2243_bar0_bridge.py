"""Build and run BAR0 decode + AWR2243 CSR cocotb regression (csr_rd_wr, addr_decode)."""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

from cocotb_tools.runner import get_runner


REPO_ROOT = Path(__file__).resolve().parents[2]
TB_DIR = Path(__file__).resolve().parent
BUILD_ROOT = REPO_ROOT / "sim_build" / "awr2243_bar0_cocotb"
TOPLEVEL = "awr2243_bar0_cocotb_top"
TEST_MODULE = "tests.test_awr2243_bar0_bridge"

ALL_TESTS = [
    "test_csr_rd_wr",
    "test_addr_decode",
]


def build_sources():
    return [
        REPO_ROOT / "rtl/pkg/awr2243_script_pkg.sv",
        REPO_ROOT / "rtl/if/axi4_lite_if.sv",
        REPO_ROOT / "rtl/generated/awr2243_control_csr_pkg.sv",
        REPO_ROOT / "rtl/generated/awr2243_control_csr.sv",
        REPO_ROOT / "rtl/axil/axil_bar0_decode.sv",
        REPO_ROOT / "rtl/core/awr2243_script_ram.sv",
        REPO_ROOT / "rtl/core/awr2243_cmd_decode.sv",
        REPO_ROOT / "rtl/core/awr2243_cmd_fetch.sv",
        REPO_ROOT / "rtl/core/awr2243_cfg_sequencer.sv",
        REPO_ROOT / "rtl/core/awr2243_status_mon.sv",
        REPO_ROOT / "rtl/core/awr2243_reset_ctrl.sv",
        REPO_ROOT / "rtl/core/awr2243_timer.sv",
        REPO_ROOT / "rtl/core/spi_master_engine.sv",
        REPO_ROOT / "rtl/core/awr2243_ctrl_top.sv",
        REPO_ROOT / "tb/models/axil_slave_stub.sv",
        TB_DIR / "awr2243_bar0_cocotb_top.sv",
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
            "-Wno-BLKLOOPINIT",  # PeakRDL-generated loop over compound array
            "-Wno-MULTIDRIVEN",  # PeakRDL singlepulse field_combo
            "-Wno-PINCONNECTEMPTY",
            "-Wno-IMPLICIT",
            "-Wno-EOFNEWLINE",
            "--trace-fst",
        ],
    )

    runner.test(
        test_module=TEST_MODULE,
        hdl_toplevel=TOPLEVEL,
        test_filter=".*(" + "|".join(testcases) + ")$" if testcases else None,
        test_dir=test_dir,
        waves=waves,
        extra_env={"PYTHONPATH": str(TB_DIR)},
    )


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Run Verilator+cocotb regression for BAR0 decode + AWR2243 CSR"
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
