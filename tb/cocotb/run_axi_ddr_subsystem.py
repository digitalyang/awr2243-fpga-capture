from __future__ import annotations

import argparse
import sys

from axi_ddr_subsystem_runner import run_regression


TEST_MODULES = ["axi_ddr_subsystem_cocotb"]
TESTCASES = ["test_axi_ddr_subsystem_burst_smoke"]


def parse_args(argv: list[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run the AXI/DDR subsystem burst smoke regression")
    parser.add_argument("--testcase", action="append", choices=TESTCASES, help="Specific cocotb testcase to run.")
    parser.add_argument("--waves", action="store_true", help="Enable waveform dump")
    parser.add_argument("--no-clean", action="store_true", help="Reuse existing build directory")
    return parser.parse_args(argv)


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    run_regression(
        build_root_name="axi_ddr_subsystem",
        test_modules=TEST_MODULES,
        testcases=args.testcase or TESTCASES,
        waves=args.waves,
        clean=not args.no_clean,
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
