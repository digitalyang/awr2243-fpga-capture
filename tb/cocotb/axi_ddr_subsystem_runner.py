from __future__ import annotations

from pathlib import Path
from typing import Sequence

from cocotb_tools.runner import get_runner


REPO_ROOT = Path(__file__).resolve().parents[2]
TB_DIR = Path(__file__).resolve().parent
TOPLEVEL = "axi_ddr_subsystem_smoke_top"


def build_sources() -> list[Path]:
    return [
        REPO_ROOT / "rtl/pkg/ddr_ringbuffer_pkg.sv",
        REPO_ROOT / "rtl/if/axi4_mm_if.sv",
        REPO_ROOT / "rtl/axi/axi_ddr_subsystem_pkg.sv",
        REPO_ROOT / "rtl/axi/axi_ddr_subsystem.sv",
        REPO_ROOT / "sim/litedram/litedram_axi_wrapper_stub.sv",
        REPO_ROOT / "tb/models/axi_ddr_subsystem_smoke_top.sv",
    ]


def run_regression(
    *,
    build_root_name: str,
    test_modules: Sequence[str],
    testcases: list[str],
    waves: bool,
    clean: bool,
) -> None:
    runner = get_runner("verilator")
    build_root = REPO_ROOT / "sim_build" / build_root_name
    build_dir = build_root / "build"
    test_dir = build_root / "test"
    test_filter = None if not testcases else ".*(" + "|".join(testcases) + ")$"

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
        test_module=list(test_modules),
        hdl_toplevel=TOPLEVEL,
        test_filter=test_filter,
        test_dir=test_dir,
        waves=waves,
        extra_env={
            "PYTHONPATH": str(TB_DIR),
        },
    )
