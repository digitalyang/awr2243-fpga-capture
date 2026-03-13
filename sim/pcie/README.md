# PCIe Endpoint DMA Shell

This directory tracks the additive PCIe endpoint wrapper introduced for the radar PCIe/DDR end-to-end platform.

## Dependency boundary

- Expected external dependency: `alexforencich/verilog-pcie`
- Integration hook: `rtl/pcie/pcie_endpoint_dma_vpcie_adapter.sv`
- Current smoke mode: `DIRECT_RC_MODEL=1`, which bypasses the missing vendored core and exposes a transaction-level host RC model directly to cocotb

## Upstream host RC model

The smoke harness uses a clean MMIO transaction interface instead of raw PCIe TLP streams:

- Request: `host_rc_req_valid`, `host_rc_req_ready`, `host_rc_req_write`, `host_rc_req_bar[2:0]`, `host_rc_req_addr[15:0]`, `host_rc_req_data[31:0]`, `host_rc_req_strb[3:0]`, `host_rc_req_tag[7:0]`
- Response: `host_rc_rsp_valid`, `host_rc_rsp_ready`, `host_rc_rsp_data[31:0]`, `host_rc_rsp_status[1:0]`, `host_rc_rsp_tag[7:0]`
- Status encoding: `00=successful completion`, `01=unsupported request`, `10=completer abort`

This is the interface `agent-host` should target until the real `verilog-pcie` CQ/CC/RQ/RC path is vendored.

## BAR0 map

- `0x0000`: `CONTROL`
  - bit 0: endpoint DMA enable
  - bit 1: interrupt enable
- `0x0004`: `STATUS`
  - bit 0: enable mirror
  - bit 1: interrupt-enable mirror
  - bit 8: DMA busy
  - bit 9: interrupt pending, write-one-to-clear
  - bit 10: sticky DMA/config error, write-one-to-clear
  - bit 11: descriptor shadow valid (`DESC_LEN != 0`)
  - bits 31:16: completion count
- `0x0010`: `DESC_ADDR_LO`
- `0x0014`: `DESC_ADDR_HI`
- `0x0018`: `DESC_LEN`
- `0x001C`: `DESC_PATTERN`
- `0x0020`: `DESC_META`
  - bits 7:0: descriptor ID
  - bit 16: interrupt on completion
  - bit 17: direction marker, fixed to host-to-card write in the current shell
- `0x0024`: `DOORBELL`
  - bit 0: launch the shadow descriptor
- `0x0028`: `COMPLETION`
  - bits 7:0: last completed descriptor ID
  - bits 31:16: completion count
- `0x002C`: `COMPLETION_LEN`
  - last completed descriptor byte count

Addresses `0x0100` through `0x0FFF` are reserved. BAR0 accesses at `0x1000+` are forwarded to `m_axil_bar0`.

## Downstream interfaces

- `m_axil_bar0`
  - AXI4-Lite master
  - 16-bit address, 32-bit data
  - BAR0 offset presented as `addr - 16'h1000`
- `m_axi_dma`
  - AXI4 memory-mapped master
  - 34-bit address, 256-bit data, INCR bursts
  - current shell implements host-to-card writes only
  - max burst length defaults to `16` beats, aligned with the existing DDR ring defaults

## Smoke entry point

- cocotb runner: `tb/cocotb/run_pcie_endpoint_dma.py`
- file list: `sim/pcie/pcie_endpoint_dma_smoke.f`

Example:

```bash
python3 tb/cocotb/run_pcie_endpoint_dma.py
```
