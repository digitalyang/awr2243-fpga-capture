from __future__ import annotations

import argparse
import sys

from sim_platform_runner import run_regression


TEST_MODULES = ["tests.test_ringbuffer"]
TESTCASES = [
    "test_ringbuffer_commit_addr_progression",
    "test_ringbuffer_wraparound",
]


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run Verilator+cocotb regression for simulation-platform ringbuffer tests")
    parser.add_argument("--testcase", action="append", choices=TESTCASES, help="Specific cocotb testcase to run.")
    parser.add_argument("--waves", action="store_true", help="Enable waveform dump")
    parser.add_argument("--no-clean", action="store_true", help="Reuse existing build directory")
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    run_regression(
        build_root_name="sim_platform_ringbuffer",
        test_modules=TEST_MODULES,
        testcases=args.testcase or TESTCASES,
        waves=args.waves,
        clean=not args.no_clean,
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
