from __future__ import annotations

from pathlib import Path
from typing import Sequence

from cocotb_tools.runner import get_runner


REPO_ROOT = Path(__file__).resolve().parents[2]
TB_DIR = Path(__file__).resolve().parent
TOPLEVEL = "top_tb"


def build_sources() -> list[Path]:
    return [
        REPO_ROOT / "rtl/pkg/csi_packet_pkg.sv",
        REPO_ROOT / "rtl/pkg/slot_packer_pkg.sv",
        REPO_ROOT / "rtl/pkg/ddr_ringbuffer_pkg.sv",
        REPO_ROOT / "rtl/if/axis_stream_if.sv",
        REPO_ROOT / "rtl/if/axi4_mm_if.sv",
        REPO_ROOT / "rtl/core/csi_packet_extractor.sv",
        REPO_ROOT / "rtl/core/fixed_slot_packer.sv",
        REPO_ROOT / "rtl/core/ddr_ringbuffer_controller.sv",
        REPO_ROOT / "tb/models/csi_rx_behavioral_mock.sv",
        REPO_ROOT / "tb/models/axis_async_fifo.sv",
        TB_DIR / "pipeline_cocotb_top.sv",
        REPO_ROOT / "tb/top_tb.sv",
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
