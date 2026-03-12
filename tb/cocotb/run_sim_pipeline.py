from __future__ import annotations

import argparse
import sys

from sim_platform_runner import run_regression


TEST_MODULES = ["tests.test_pipeline"]
TESTCASES = [
    "test_top_sanity",
    "test_pipeline_back_to_back_slots",
    "test_pipeline_invalid_slot_roundtrip",
    "test_pipeline_controller_drops_invalid",
    "test_pipeline_awr_frame_roundtrip",
    "test_pipeline_short_packet_missing_ls",
    "test_pipeline_short_packet_early_fe",
    "test_pipeline_short_packet_orphan_control_packets",
    "test_pipeline_short_packet_cross_frame_recovery",
]


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run Verilator+cocotb regression for simulation-platform pipeline tests")
    parser.add_argument("--testcase", action="append", choices=TESTCASES, help="Specific cocotb testcase to run.")
    parser.add_argument("--waves", action="store_true", help="Enable waveform dump")
    parser.add_argument("--no-clean", action="store_true", help="Reuse existing build directory")
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    run_regression(
        build_root_name="sim_platform_pipeline",
        test_modules=TEST_MODULES,
        testcases=args.testcase or TESTCASES,
        waves=args.waves,
        clean=not args.no_clean,
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
