# Device-level clock skeleton for the production top
# awr2243_capture_top_with_bd.

create_clock -period 10.000 -name sys_clk_100m     [get_ports sys_clk]
create_clock -period 5.000  -name video_aclk_200m  [get_ports video_aclk]
create_clock -period 4.000  -name axi_clk_250m     [get_ports axi_aclk]

set_clock_groups -asynchronous \
  -group [get_clocks sys_clk_100m] \
  -group [get_clocks video_aclk_200m] \
  -group [get_clocks axi_clk_250m]

# Fill these with real package pins / IOSTANDARDs for your board when
# closing the physical design.
# set_property PACKAGE_PIN <PIN> [get_ports sys_clk]
# set_property IOSTANDARD LVCMOS18 [get_ports sys_rst_n]

