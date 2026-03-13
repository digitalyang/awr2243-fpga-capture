from __future__ import annotations

import argparse
import sys
from pathlib import Path

from cocotb_tools.runner import get_runner


REPO_ROOT = Path(__file__).resolve().parents[2]
TB_DIR = Path(__file__).resolve().parent
BUILD_ROOT = REPO_ROOT / "sim_build" / "pcie_endpoint_dma_cocotb"
TOPLEVEL = "pcie_endpoint_dma_cocotb_top"
TEST_MODULE = "pcie_endpoint_dma_cocotb"


def build_sources():
    return [
        REPO_ROOT / "rtl/pkg/ddr_ringbuffer_pkg.sv",
        REPO_ROOT / "rtl/pkg/pcie_dma_pkg.sv",
        REPO_ROOT / "rtl/if/axi4_lite_if.sv",
        REPO_ROOT / "rtl/if/axi4_mm_if.sv",
        REPO_ROOT / "rtl/if/pcie_rc_model_if.sv",
        REPO_ROOT / "rtl/pcie/pcie_endpoint_dma_shell.sv",
        REPO_ROOT / "rtl/pcie/pcie_endpoint_dma_vpcie_adapter.sv",
        REPO_ROOT / "rtl/pcie/pcie_endpoint_dma_integration.sv",
        TB_DIR / "pcie_endpoint_dma_cocotb_top.sv",
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
            "-Wno-DECLFILENAME",
            "-Wno-UNUSEDPARAM",
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
    parser = argparse.ArgumentParser(description="Run Verilator+cocotb regression for the PCIe endpoint DMA shell")
    parser.add_argument(
        "--testcase",
        action="append",
        choices=["smoke_mmio_forward_and_dma_write"],
        help="Specific cocotb testcase to run. Defaults to the smoke regression.",
    )
    parser.add_argument("--waves", action="store_true", help="Enable waveform dump")
    parser.add_argument("--no-clean", action="store_true", help="Reuse existing build directory")
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    testcases = args.testcase if args.testcase else ["smoke_mmio_forward_and_dma_write"]
    run_regression(testcases=testcases, waves=args.waves, clean=not args.no_clean)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
