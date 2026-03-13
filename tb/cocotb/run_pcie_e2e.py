from __future__ import annotations

import argparse
import sys

from sim_platform_runner import run_regression


TEST_MODULES = [
    "tests.test_pipeline",
    "tests.test_ringbuffer",
    "tests.test_cdc",
    "tests.test_e2e_regression",
]
TESTCASES = [
    "test_top_sanity",
    "test_pipeline_back_to_back_slots",
    "test_ringbuffer_wraparound",
    "test_cdc_timing_skewed_clocks_and_mock_gaps",
    "test_cdc_fifo_fill_and_backpressure",
    "test_e2e_host_burst_read",
    "test_e2e_host_read_while_write",
    "test_e2e_payload_truncation",
    "test_e2e_axi_backpressure",
    "test_e2e_overflow_condition",
]


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the end-to-end radar DDR regression matrix")
    parser.add_argument("--testcase", action="append", choices=TESTCASES, help="Specific cocotb testcase to run.")
    parser.add_argument("--waves", action="store_true", help="Enable waveform dump")
    parser.add_argument("--no-clean", action="store_true", help="Reuse existing build directory")
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    run_regression(
        build_root_name="pcie_e2e_regression",
        test_modules=TEST_MODULES,
        testcases=args.testcase or TESTCASES,
        waves=args.waves,
        clean=not args.no_clean,
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
