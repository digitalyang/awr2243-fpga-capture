proc latest_ip_vlnv {pattern} {
  set defs [get_ipdefs -all $pattern]
  if {[llength $defs] == 0} {
    error "IP not found for pattern '$pattern'"
  }
  return [lindex [lsort -dictionary $defs] end]
}

proc first_bd_intf_pin {cell patterns} {
  foreach pattern $patterns {
    set pins [get_bd_intf_pins -quiet ${cell}/${pattern}]
    if {[llength $pins] > 0} {
      return [lindex $pins 0]
    }
  }
  error "No BD interface pin found on $cell for patterns: $patterns"
}

proc first_bd_addr_space {patterns} {
  foreach pattern $patterns {
    set spaces [get_bd_addr_spaces -quiet $pattern]
    if {[llength $spaces] > 0} {
      return [lindex $spaces 0]
    }
  }
  error "No BD address space found for patterns: $patterns"
}

proc first_bd_addr_seg {patterns} {
  foreach pattern $patterns {
    set segs [get_bd_addr_segs -quiet $pattern]
    if {[llength $segs] > 0} {
      return [lindex $segs 0]
    }
  }
  error "No BD address segment found for patterns: $patterns"
}

proc safe_connect_pin {src dst_patterns} {
  foreach dst $dst_patterns {
    set pins [get_bd_pins -quiet $dst]
    if {[llength $pins] > 0} {
      connect_bd_net $src [lindex $pins 0]
      return
    }
  }
}

proc connect_to_existing_pins {src dst_patterns} {
  foreach dst $dst_patterns {
    set pins [get_bd_pins -quiet $dst]
    if {[llength $pins] > 0} {
      connect_bd_net $src [lindex $pins 0]
    }
  }
}

proc rename_external_pin {old_name new_name} {
  set candidates [list $old_name "${old_name}_0"]
  if {[string match "ddr4_0_*" $old_name]} {
    set short_name [string range $old_name 7 end]
    lappend candidates $short_name "${short_name}_0"
  }

  foreach candidate $candidates {
    set pin [get_bd_ports -quiet $candidate]
    if {[llength $pin] > 0} {
      if {$candidate ne $new_name} {
        set_property name $new_name $pin
      }
      return
    }
  }
}

proc safe_set_addr_offset {seg_name offset_hex} {
  set seg [get_bd_addr_segs -quiet $seg_name]
  if {[llength $seg] > 0} {
    set_property offset $offset_hex $seg
  }
}

set design_name awr2243_capture_bd

if {[catch {current_project}]} {
  error "Open a Vivado project before sourcing create_awr2243_capture_bd.tcl"
}

set existing_bd_files [get_files -quiet */${design_name}.bd]
if {[llength $existing_bd_files] > 0} {
  remove_files $existing_bd_files
}

create_bd_design $design_name
current_bd_design $design_name

set sys_clk       [create_bd_port -dir I -type clk -freq_hz 100000000 sys_clk]
set sys_rst_n     [create_bd_port -dir I -type rst sys_rst_n]
set video_aclk    [create_bd_port -dir I -type clk -freq_hz 200000000 video_aclk]
set axi_aclk      [create_bd_port -dir I -type clk -freq_hz 250000000 axi_aclk]
set video_aresetn [create_bd_port -dir O -type rst video_aresetn]
set axi_aresetn   [create_bd_port -dir O -type rst axi_aresetn]

set_property CONFIG.POLARITY ACTIVE_LOW [get_bd_ports sys_rst_n]
set_property CONFIG.POLARITY ACTIVE_LOW [get_bd_ports video_aresetn]
set_property CONFIG.POLARITY ACTIVE_LOW [get_bd_ports axi_aresetn]

create_bd_port -dir I pcie_refclk_p
create_bd_port -dir I pcie_refclk_n
create_bd_port -dir I ddr4_refclk_p
create_bd_port -dir I ddr4_refclk_n
create_bd_port -dir I csi_rx_clk_p
create_bd_port -dir I csi_rx_clk_n
create_bd_port -dir I -from 3 -to 0 csi_rx_data_p
create_bd_port -dir I -from 3 -to 0 csi_rx_data_n

create_bd_port -dir I -from 7 -to 0 pcie_rxp
create_bd_port -dir I -from 7 -to 0 pcie_rxn
create_bd_port -dir O -from 7 -to 0 pcie_txp
create_bd_port -dir O -from 7 -to 0 pcie_txn
create_bd_port -dir O spi_sclk_o
create_bd_port -dir O spi_cs_n_o
create_bd_port -dir O spi_mosi_o
create_bd_port -dir I spi_miso_i
create_bd_port -dir O sop0_o
create_bd_port -dir O sop1_o
create_bd_port -dir O sop2_o
create_bd_port -dir O nreset_o
create_bd_port -dir I host_irq_i
create_bd_port -dir I nerror_out_i

set util_ds_buf_vlnv    [latest_ip_vlnv "xilinx.com:ip:util_ds_buf:*"]
set proc_sys_reset_vlnv [latest_ip_vlnv "xilinx.com:ip:proc_sys_reset:*"]
set xlconstant_vlnv     [latest_ip_vlnv "xilinx.com:ip:xlconstant:*"]
set util_vec_vlnv       [latest_ip_vlnv "xilinx.com:ip:util_vector_logic:*"]
set xdma_vlnv           [latest_ip_vlnv "xilinx.com:ip:xdma:*"]
set smartconnect_vlnv   [latest_ip_vlnv "xilinx.com:ip:smartconnect:*"]
set axis_fifo_vlnv      [latest_ip_vlnv "xilinx.com:ip:axis_data_fifo:*"]
set axi_cc_vlnv         [latest_ip_vlnv "xilinx.com:ip:axi_clock_converter:*"]
set ddr4_vlnv           [latest_ip_vlnv "xilinx.com:ip:ddr4:*"]
set mipi_vlnv           [latest_ip_vlnv "xilinx.com:ip:mipi_csi2_rx_subsystem:*"]

create_bd_cell -type ip -vlnv $util_ds_buf_vlnv util_ds_buf_pcie_refclk
create_bd_cell -type ip -vlnv $proc_sys_reset_vlnv proc_sys_reset_video
create_bd_cell -type ip -vlnv $proc_sys_reset_vlnv proc_sys_reset_axi
create_bd_cell -type ip -vlnv $proc_sys_reset_vlnv proc_sys_reset_xdma
create_bd_cell -type ip -vlnv $proc_sys_reset_vlnv proc_sys_reset_ddr
create_bd_cell -type ip -vlnv $xlconstant_vlnv xlconstant_one
create_bd_cell -type ip -vlnv $xlconstant_vlnv xlconstant_zero
create_bd_cell -type ip -vlnv $xlconstant_vlnv xlconstant_zero2
create_bd_cell -type ip -vlnv $util_vec_vlnv util_vl_sysrst_inv
create_bd_cell -type ip -vlnv $xdma_vlnv xdma_0
create_bd_cell -type ip -vlnv $smartconnect_vlnv smartconnect_ddr
create_bd_cell -type ip -vlnv $axis_fifo_vlnv axis_async_fifo_0
create_bd_cell -type module -reference csi_rx_axis_pack_ref csi_rx_axis_pack_0
create_bd_cell -type module -reference awr2243_capture_core_ref awr2243_capture_core_0
create_bd_cell -type ip -vlnv $axi_cc_vlnv axil_clock_conv_0
create_bd_cell -type ip -vlnv $axi_cc_vlnv axi_clock_conv_xdma_0
create_bd_cell -type ip -vlnv $axi_cc_vlnv axi_clock_conv_ring_0
create_bd_cell -type ip -vlnv $ddr4_vlnv ddr4_0
create_bd_cell -type ip -vlnv $mipi_vlnv mipi_csi2_rx_subsystem_0

set_property -dict [list CONFIG.C_BUF_TYPE {IBUFDSGTE}] [get_bd_cells util_ds_buf_pcie_refclk]
set_property -dict [list CONFIG.CONST_WIDTH {1} CONFIG.CONST_VAL {1}] [get_bd_cells xlconstant_one]
set_property -dict [list CONFIG.CONST_WIDTH {1} CONFIG.CONST_VAL {0}] [get_bd_cells xlconstant_zero]
set_property -dict [list CONFIG.CONST_WIDTH {2} CONFIG.CONST_VAL {0}] [get_bd_cells xlconstant_zero2]
set_property -dict [list CONFIG.C_OPERATION {not} CONFIG.C_SIZE {1}] [get_bd_cells util_vl_sysrst_inv]

set_property -dict [list \
  CONFIG.pl_link_cap_max_link_width {X8} \
  CONFIG.pl_link_cap_max_link_speed {8.0_GT/s} \
  CONFIG.axi_data_width {256_bit} \
  CONFIG.axilite_master_en {true} \
  CONFIG.axilite_master_scale {Kilobytes} \
  CONFIG.axilite_master_size {64} \
  CONFIG.en_axi_master_if {true} \
  CONFIG.en_axi_slave_if {false} \
  CONFIG.xdma_en {true} \
  CONFIG.xdma_axi_intf_mm {AXI_Memory_Mapped} \
] [get_bd_cells xdma_0]

set_property -dict [list CONFIG.NUM_SI {2} CONFIG.NUM_MI {1}] [get_bd_cells smartconnect_ddr]

set_property -dict [list \
  CONFIG.IS_ACLK_ASYNC {1} \
  CONFIG.TDATA_NUM_BYTES {8} \
  CONFIG.TUSER_WIDTH {96} \
  CONFIG.TDEST_WIDTH {10} \
  CONFIG.HAS_TKEEP {1} \
  CONFIG.HAS_TLAST {1} \
  CONFIG.FIFO_DEPTH {512} \
] [get_bd_cells axis_async_fifo_0]

set_property -dict [list \
  CONFIG.S_DATA_W {64} \
  CONFIG.M_DATA_W {256} \
  CONFIG.S_TUSER_W {96} \
  CONFIG.M_TUSER_W {64} \
  CONFIG.S_TDEST_W {10} \
  CONFIG.S_ERR_BIT {1} \
  CONFIG.S_VC_TDEST_LSB {0} \
  CONFIG.S_DT_TDEST_LSB {2} \
  CONFIG.S_PAYLOAD_LEN_LSB {48} \
] [get_bd_cells csi_rx_axis_pack_0]

set_property -dict [list \
  CONFIG.AXIS_DATA_W {256} \
  CONFIG.AXIS_USER_W {64} \
  CONFIG.AXIL_ADDR_W {32} \
  CONFIG.AXIL_DATA_W {32} \
  CONFIG.AXI_ADDR_W {34} \
  CONFIG.AXI_DATA_W {256} \
] [get_bd_cells awr2243_capture_core_0]

set_property -dict [list \
  CONFIG.PROTOCOL {AXI4LITE} \
  CONFIG.ADDR_WIDTH {32} \
  CONFIG.DATA_WIDTH {32} \
] [get_bd_cells axil_clock_conv_0]

set_property -dict [list \
  CONFIG.PROTOCOL {AXI4} \
  CONFIG.ADDR_WIDTH {64} \
  CONFIG.DATA_WIDTH {256} \
  CONFIG.ID_WIDTH {4} \
] [get_bd_cells axi_clock_conv_xdma_0]

set_property -dict [list \
  CONFIG.PROTOCOL {AXI4} \
  CONFIG.ADDR_WIDTH {34} \
  CONFIG.DATA_WIDTH {256} \
] [get_bd_cells axi_clock_conv_ring_0]

set_property -dict [list \
  CONFIG.C0.DDR4_DataWidth {64} \
  CONFIG.C0.DDR4_InputClockPeriod {10000} \
] [get_bd_cells ddr4_0]

set_property -dict [list \
  CONFIG.SupportLevel {1} \
  CONFIG.CMN_NUM_LANES {4} \
  CONFIG.C_DPHY_LANES {4} \
  CONFIG.AXIS_TDATA_WIDTH {64} \
  CONFIG.AXIS_TDEST_WIDTH {10} \
  CONFIG.CSI_CONTROLLER_REG_IF {false} \
  CONFIG.CMN_INC_VFB {false} \
  CONFIG.C_HS_LINE_RATE {2100} \
  CONFIG.DPY_LINE_RATE {2100} \
] [get_bd_cells mipi_csi2_rx_subsystem_0]

safe_connect_pin [get_bd_ports pcie_refclk_p] [list util_ds_buf_pcie_refclk/IBUF_DS_P util_ds_buf_pcie_refclk/CLK_IN_D_P]
safe_connect_pin [get_bd_ports pcie_refclk_n] [list util_ds_buf_pcie_refclk/IBUF_DS_N util_ds_buf_pcie_refclk/CLK_IN_D_N]

connect_bd_net [get_bd_ports sys_rst_n] [get_bd_pins util_vl_sysrst_inv/Op1]
connect_bd_net [get_bd_pins util_vl_sysrst_inv/Res] [get_bd_pins proc_sys_reset_video/ext_reset_in]
connect_bd_net [get_bd_pins util_vl_sysrst_inv/Res] [get_bd_pins proc_sys_reset_axi/ext_reset_in]
connect_bd_net [get_bd_pins util_vl_sysrst_inv/Res] [get_bd_pins proc_sys_reset_xdma/ext_reset_in]
connect_bd_net [get_bd_pins util_vl_sysrst_inv/Res] [get_bd_pins proc_sys_reset_ddr/ext_reset_in]

connect_to_existing_pins [get_bd_pins xlconstant_one/dout] [list \
  proc_sys_reset_video/aux_reset_in \
  proc_sys_reset_axi/aux_reset_in \
  proc_sys_reset_xdma/aux_reset_in \
  proc_sys_reset_ddr/aux_reset_in \
]

connect_to_existing_pins [get_bd_pins xlconstant_zero/dout] [list \
  proc_sys_reset_video/mb_debug_sys_rst \
  proc_sys_reset_axi/mb_debug_sys_rst \
  proc_sys_reset_xdma/mb_debug_sys_rst \
  proc_sys_reset_ddr/mb_debug_sys_rst \
]

connect_bd_net [get_bd_ports video_aclk] [get_bd_pins proc_sys_reset_video/slowest_sync_clk]
connect_bd_net [get_bd_ports axi_aclk]   [get_bd_pins proc_sys_reset_axi/slowest_sync_clk]
connect_bd_net [get_bd_pins xdma_0/axi_aclk] [get_bd_pins proc_sys_reset_xdma/slowest_sync_clk]
connect_bd_net [get_bd_pins ddr4_0/c0_ddr4_ui_clk] [get_bd_pins proc_sys_reset_ddr/slowest_sync_clk]

connect_bd_net [get_bd_pins xlconstant_one/dout] [get_bd_pins proc_sys_reset_video/dcm_locked]
connect_bd_net [get_bd_pins xlconstant_one/dout] [get_bd_pins proc_sys_reset_axi/dcm_locked]
connect_bd_net [get_bd_pins xdma_0/user_lnk_up] [get_bd_pins proc_sys_reset_xdma/dcm_locked]
connect_bd_net [get_bd_pins ddr4_0/c0_init_calib_complete] [get_bd_pins proc_sys_reset_ddr/dcm_locked]

connect_bd_net [get_bd_pins proc_sys_reset_video/peripheral_aresetn] [get_bd_ports video_aresetn]
connect_bd_net [get_bd_pins proc_sys_reset_axi/peripheral_aresetn]   [get_bd_ports axi_aresetn]

safe_connect_pin [get_bd_pins util_ds_buf_pcie_refclk/IBUF_OUT] [list xdma_0/sys_clk_gt xdma_0/gt_refclk]
safe_connect_pin [get_bd_pins util_ds_buf_pcie_refclk/IBUF_DS_ODIV2] [list xdma_0/sys_clk xdma_0/sys_clk_odiv2]
safe_connect_pin [get_bd_ports sys_rst_n] [list xdma_0/sys_rst_n]

connect_bd_net [get_bd_pins xdma_0/axi_aclk] [get_bd_pins axil_clock_conv_0/s_axi_aclk]
connect_bd_net [get_bd_pins proc_sys_reset_xdma/peripheral_aresetn] [get_bd_pins axil_clock_conv_0/s_axi_aresetn]
connect_bd_net [get_bd_ports axi_aclk] [get_bd_pins axil_clock_conv_0/m_axi_aclk]
connect_bd_net [get_bd_pins proc_sys_reset_axi/peripheral_aresetn] [get_bd_pins axil_clock_conv_0/m_axi_aresetn]

connect_bd_net [get_bd_pins xdma_0/axi_aclk] [get_bd_pins axi_clock_conv_xdma_0/s_axi_aclk]
connect_bd_net [get_bd_pins proc_sys_reset_xdma/peripheral_aresetn] [get_bd_pins axi_clock_conv_xdma_0/s_axi_aresetn]
connect_bd_net [get_bd_pins ddr4_0/c0_ddr4_ui_clk] [get_bd_pins axi_clock_conv_xdma_0/m_axi_aclk]
connect_bd_net [get_bd_pins proc_sys_reset_ddr/peripheral_aresetn] [get_bd_pins axi_clock_conv_xdma_0/m_axi_aresetn]

connect_bd_net [get_bd_ports axi_aclk] [get_bd_pins axi_clock_conv_ring_0/s_axi_aclk]
connect_bd_net [get_bd_pins proc_sys_reset_axi/peripheral_aresetn] [get_bd_pins axi_clock_conv_ring_0/s_axi_aresetn]
connect_bd_net [get_bd_pins ddr4_0/c0_ddr4_ui_clk] [get_bd_pins axi_clock_conv_ring_0/m_axi_aclk]
connect_bd_net [get_bd_pins proc_sys_reset_ddr/peripheral_aresetn] [get_bd_pins axi_clock_conv_ring_0/m_axi_aresetn]

connect_bd_net [get_bd_pins ddr4_0/c0_ddr4_ui_clk] [get_bd_pins smartconnect_ddr/aclk]
connect_bd_net [get_bd_pins proc_sys_reset_ddr/peripheral_aresetn] [get_bd_pins smartconnect_ddr/aresetn]

safe_connect_pin [get_bd_ports ddr4_refclk_p] [list ddr4_0/c0_sys_clk_p]
safe_connect_pin [get_bd_ports ddr4_refclk_n] [list ddr4_0/c0_sys_clk_n]
safe_connect_pin [get_bd_pins util_vl_sysrst_inv/Res] [list ddr4_0/sys_rst ddr4_0/c0_sys_rst]

safe_connect_pin [get_bd_ports csi_rx_clk_p]  [list mipi_csi2_rx_subsystem_0/mipi_phy_if_clk_p]
safe_connect_pin [get_bd_ports csi_rx_clk_n]  [list mipi_csi2_rx_subsystem_0/mipi_phy_if_clk_n]
safe_connect_pin [get_bd_ports csi_rx_data_p] [list mipi_csi2_rx_subsystem_0/mipi_phy_if_data_p]
safe_connect_pin [get_bd_ports csi_rx_data_n] [list mipi_csi2_rx_subsystem_0/mipi_phy_if_data_n]
safe_connect_pin [get_bd_ports video_aclk] [list mipi_csi2_rx_subsystem_0/video_aclk]
safe_connect_pin [get_bd_ports video_aclk] [list mipi_csi2_rx_subsystem_0/dphy_clk_200M]
safe_connect_pin [get_bd_pins proc_sys_reset_video/peripheral_aresetn] [list mipi_csi2_rx_subsystem_0/video_aresetn]
safe_connect_pin [get_bd_pins xlconstant_one/dout] [list mipi_csi2_rx_subsystem_0/ctrl_core_en]
safe_connect_pin [get_bd_pins xlconstant_zero2/dout] [list mipi_csi2_rx_subsystem_0/active_lanes]

safe_connect_pin [get_bd_ports pcie_rxp] [list xdma_0/pci_exp_rxp]
safe_connect_pin [get_bd_ports pcie_rxn] [list xdma_0/pci_exp_rxn]
safe_connect_pin [get_bd_ports pcie_txp] [list xdma_0/pci_exp_txp]
safe_connect_pin [get_bd_ports pcie_txn] [list xdma_0/pci_exp_txn]

safe_connect_pin [get_bd_ports video_aclk] [list axis_async_fifo_0/s_axis_aclk]
safe_connect_pin [get_bd_ports axi_aclk]   [list axis_async_fifo_0/m_axis_aclk]
safe_connect_pin [get_bd_pins proc_sys_reset_video/peripheral_aresetn] [list axis_async_fifo_0/s_axis_aresetn]
safe_connect_pin [get_bd_pins proc_sys_reset_axi/peripheral_aresetn]   [list axis_async_fifo_0/m_axis_aresetn]

connect_bd_net [get_bd_ports axi_aclk] [get_bd_pins csi_rx_axis_pack_0/aclk]
connect_bd_net [get_bd_pins proc_sys_reset_axi/peripheral_aresetn] [get_bd_pins csi_rx_axis_pack_0/aresetn]
connect_bd_net [get_bd_ports axi_aclk] [get_bd_pins awr2243_capture_core_0/axi_clk]
connect_bd_net [get_bd_pins proc_sys_reset_axi/peripheral_aresetn] [get_bd_pins awr2243_capture_core_0/axi_rst_n]

connect_bd_intf_net [first_bd_intf_pin mipi_csi2_rx_subsystem_0 [list video_out]] [first_bd_intf_pin axis_async_fifo_0 [list S_AXIS]]

foreach sig {tdata tkeep tvalid tready tlast tuser tdest} {
  connect_bd_net [get_bd_pins axis_async_fifo_0/m_axis_$sig] [get_bd_pins csi_rx_axis_pack_0/s_axis_$sig]
}
set pack_m_axis      [first_bd_intf_pin csi_rx_axis_pack_0 [list m_axis]]
set core_s_axis      [first_bd_intf_pin awr2243_capture_core_0 [list s_axis_csi]]
set axil_conv_m_axi  [first_bd_intf_pin axil_clock_conv_0 [list M_AXI]]
set core_s_axil      [first_bd_intf_pin awr2243_capture_core_0 [list s_axil_bar0]]
set core_m_axi       [first_bd_intf_pin awr2243_capture_core_0 [list m_axi]]
set ring_conv_s_axi  [first_bd_intf_pin axi_clock_conv_ring_0 [list S_AXI]]

connect_bd_intf_net $pack_m_axis     $core_s_axis
connect_bd_intf_net $axil_conv_m_axi $core_s_axil
connect_bd_intf_net $core_m_axi      $ring_conv_s_axi

foreach pair [list \
  [list $pack_m_axis     $core_s_axis] \
  [list $axil_conv_m_axi $core_s_axil] \
  [list $ring_conv_s_axi $core_m_axi] \
] {
  set src_intf [lindex $pair 0]
  set dst_intf [lindex $pair 1]
  set freq_hz [get_property CONFIG.FREQ_HZ $src_intf]
  if {$freq_hz ne ""} {
    set_property CONFIG.FREQ_HZ $freq_hz $dst_intf
  }
  set clk_domain [get_property CONFIG.CLK_DOMAIN $src_intf]
  if {$clk_domain ne ""} {
    set_property CONFIG.CLK_DOMAIN $clk_domain $dst_intf
  }
}
set_property CONFIG.FREQ_HZ 250000000 $core_s_axis
set_property CONFIG.FREQ_HZ 250000000 $core_s_axil
set_property CONFIG.FREQ_HZ 250000000 $core_m_axi

connect_bd_intf_net [first_bd_intf_pin xdma_0 [list M_AXI_LITE]] [first_bd_intf_pin axil_clock_conv_0 [list S_AXI]]
connect_bd_intf_net [first_bd_intf_pin xdma_0 [list M_AXI]]      [first_bd_intf_pin axi_clock_conv_xdma_0 [list S_AXI]]
connect_bd_intf_net [first_bd_intf_pin axi_clock_conv_xdma_0 [list M_AXI]] [first_bd_intf_pin smartconnect_ddr [list S00_AXI]]
connect_bd_intf_net [first_bd_intf_pin axi_clock_conv_ring_0 [list M_AXI]] [first_bd_intf_pin smartconnect_ddr [list S01_AXI]]
connect_bd_intf_net [first_bd_intf_pin smartconnect_ddr [list M00_AXI]]    [first_bd_intf_pin ddr4_0 [list C0_DDR4_S_AXI]]

set core_reg_seg [first_bd_addr_seg [list \
  awr2243_capture_core_0/s_axil_bar0/reg0 \
  /awr2243_capture_core_0/s_axil_bar0/reg0 \
]]
set ddr_addr_seg [first_bd_addr_seg [list \
  ddr4_0/C0_DDR4_MEMORY_MAP/C0_DDR4_ADDRESS_BLOCK \
  /ddr4_0/C0_DDR4_MEMORY_MAP/C0_DDR4_ADDRESS_BLOCK \
]]
set xdma_axil_space [first_bd_addr_space [list xdma_0/M_AXI_LITE /xdma_0/M_AXI_LITE]]
set xdma_axi_space  [first_bd_addr_space [list xdma_0/M_AXI /xdma_0/M_AXI]]
set core_axi_space  [first_bd_addr_space [list awr2243_capture_core_0/m_axi /awr2243_capture_core_0/m_axi]]

assign_bd_address -target_address_space $xdma_axil_space $core_reg_seg
assign_bd_address -target_address_space $xdma_axi_space  $ddr_addr_seg
assign_bd_address -target_address_space $core_axi_space  $ddr_addr_seg

safe_set_addr_offset xdma_0/M_AXI_LITE/SEG_awr2243_capture_core_0_reg0 0x00000000
safe_set_addr_offset /xdma_0/M_AXI_LITE/SEG_awr2243_capture_core_0_reg0 0x00000000
safe_set_addr_offset xdma_0/M_AXI/SEG_ddr4_0_C0_DDR4_ADDRESS_BLOCK 0x00000000
safe_set_addr_offset /xdma_0/M_AXI/SEG_ddr4_0_C0_DDR4_ADDRESS_BLOCK 0x00000000
safe_set_addr_offset awr2243_capture_core_0/m_axi/SEG_ddr4_0_C0_DDR4_ADDRESS_BLOCK 0x00000000
safe_set_addr_offset /awr2243_capture_core_0/m_axi/SEG_ddr4_0_C0_DDR4_ADDRESS_BLOCK 0x00000000

array set ddr_pin_map {
  c0_ddr4_adr      ddr4_adr
  c0_ddr4_ba       ddr4_ba
  c0_ddr4_bg       ddr4_bg
  c0_ddr4_cke      ddr4_cke
  c0_ddr4_odt      ddr4_odt
  c0_ddr4_cs_n     ddr4_cs_n
  c0_ddr4_ck_t     ddr4_ck_t
  c0_ddr4_ck_c     ddr4_ck_c
  c0_ddr4_reset_n  ddr4_reset_n
  c0_ddr4_act_n    ddr4_act_n
  c0_ddr4_dm_dbi_n ddr4_dm_n
  c0_ddr4_dq       ddr4_dq
  c0_ddr4_dqs_t    ddr4_dqs_t
  c0_ddr4_dqs_c    ddr4_dqs_c
}

foreach src_pin [array names ddr_pin_map] {
  if {[llength [get_bd_pins -quiet ddr4_0/$src_pin]] > 0} {
    make_bd_pins_external [get_bd_pins ddr4_0/$src_pin]
    rename_external_pin $src_pin $ddr_pin_map($src_pin)
  }
}

connect_bd_net [get_bd_pins awr2243_capture_core_0/spi_sclk_o] [get_bd_ports spi_sclk_o]
connect_bd_net [get_bd_pins awr2243_capture_core_0/spi_cs_n_o] [get_bd_ports spi_cs_n_o]
connect_bd_net [get_bd_pins awr2243_capture_core_0/spi_mosi_o] [get_bd_ports spi_mosi_o]
connect_bd_net [get_bd_ports spi_miso_i] [get_bd_pins awr2243_capture_core_0/spi_miso_i]
connect_bd_net [get_bd_pins awr2243_capture_core_0/sop0_o] [get_bd_ports sop0_o]
connect_bd_net [get_bd_pins awr2243_capture_core_0/sop1_o] [get_bd_ports sop1_o]
connect_bd_net [get_bd_pins awr2243_capture_core_0/sop2_o] [get_bd_ports sop2_o]
connect_bd_net [get_bd_pins awr2243_capture_core_0/nreset_o] [get_bd_ports nreset_o]
connect_bd_net [get_bd_ports host_irq_i] [get_bd_pins awr2243_capture_core_0/host_irq_i]
connect_bd_net [get_bd_ports nerror_out_i] [get_bd_pins awr2243_capture_core_0/nerror_out_i]

validate_bd_design
save_bd_design
