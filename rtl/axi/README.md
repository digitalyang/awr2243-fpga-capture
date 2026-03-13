# AXI DDR Subsystem

This directory adds a pluggable AXI/DDR boundary for the radar E2E platform without disturbing the current `ddr_ringbuffer_controller -> axi_memory.py` flow.

## Modules

- `axi_ddr_subsystem.sv`
  - Two AXI master ingress ports: `s_axi_radar` and `s_axi_host`
  - One DDR-facing AXI egress port: `m_axi_ddr`
  - Current implementation is a round-robin behavioral substitute for a future `verilog-axi` `axi_crossbar`
- `axi_ddr_subsystem_pkg.sv`
  - Shared address-map defaults and master-owner encodings used by RTL and smoke tests

## Address Map Defaults

- `0x0000_0000 - 0x0000_0FFF`
  - reserved / training / guard page
- `0x0000_1000 - 0x0001_0FFF`
  - default DDR ring window
  - matches the current cocotb platform default `RING_BASE_ADDR = 0x1000` and `RING_SIZE_BYTES = 0x10000`
- `0x0002_0000 - 0x0002_FFFF`
  - host/DMA descriptor window
- `0x0003_0000 - 0x0003_FFFF`
  - host scratch / refmodel staging window

The ring base/size remain software-configurable through the existing CSR path. The defaults above are the shared contract for the E2E subsystem and smoke tests, not a hard decode in the ringbuffer controller.

## Arbitration Assumptions

- The substitute interconnect preserves full AXI burst visibility on the DDR-facing port.
- Write and read paths arbitrate independently, so a host read can overlap a radar write.
- Each path supports one in-flight burst at a time through the current substitute layer.
- Only `INCR` bursts are assumed.
- No AXI ID interleaving or out-of-order completion is modeled in this revision.

## LiteDRAM Plan

- `sim/litedram/litedram_axi_wrapper_stub.sv` is the swappable DDR adapter boundary.
- Today it forwards the AXI bus into the cocotb-visible memory model after a short `ddr_init_done_o` delay.
- When LiteDRAM is imported, replace the stub internals while keeping:
  - `s_axi` as the interconnect-facing port
  - `m_axi_model` or an equivalent backing-memory hook for verification
  - `ddr_init_done_o` as the readiness gate consumed by higher layers
