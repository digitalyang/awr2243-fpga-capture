param(
    [string]$VivadoBat = 'D:\fpga\Vivado\2022.2\bin\vivado.bat'
)

$ErrorActionPreference = 'Stop'

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$repoRoot = (Resolve-Path (Join-Path $scriptDir '..\..')).Path
$setupTcl = Join-Path $scriptDir 'setup_awr2243_bd_smoke_sim.tcl'
$vivadoRoot = Split-Path -Parent (Split-Path -Parent $VivadoBat)
$settingsBat = Join-Path $vivadoRoot 'settings64.bat'
$runDir = Join-Path $repoRoot 'vivado_project\vivado_ku5p\awr2243_fpga_capture.sim\sim_1\behav\xsim'
$xsimIni = Join-Path $runDir 'xsim.ini'
$ipRoot = Join-Path $repoRoot 'vivado_project\vivado_ku5p\awr2243_fpga_capture.gen\sources_1\bd\awr2243_capture_bd\ip'

if (-not (Test-Path $VivadoBat)) {
    throw "Vivado batch launcher not found: $VivadoBat"
}

if (-not (Test-Path $settingsBat)) {
    throw "Vivado settings script not found: $settingsBat"
}

Write-Host "Preparing AWR2243 BD smoke simulation artifacts..."
& $VivadoBat -mode batch -source $setupTcl
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

if (-not (Test-Path $xsimIni)) {
    throw "XSIM init file not found: $xsimIni"
}

if (-not (Select-String -Path $xsimIni -Pattern '^xil_defaultlib=' -Quiet)) {
    Add-Content -Path $xsimIni -Value 'xil_defaultlib=xsim.dir/xil_defaultlib'
}

$ddrMapDirs = Get-ChildItem -Path $ipRoot -Directory |
    Where-Object { $_.Name -like 'awr2243_capture_bd_ddr4_0_0*' } |
    ForEach-Object { Join-Path $_.FullName 'ip_1\rtl\map' } |
    Where-Object { Test-Path $_ } |
    Sort-Object -Unique

if (-not $ddrMapDirs) {
    throw "No DDR4 map include directories were found under $ipRoot"
}

$ddrIncludeArgs = ($ddrMapDirs | ForEach-Object { '-i "' + $_ + '"' }) -join ' '

$cmd = @"
call "$settingsBat" && cd /d "$runDir" && xvlog --initfile xsim.ini --incr --relax -L uvm -L axi_vip_v1_1_13 -L smartconnect_v1_0 -L xdma_v4_1_20 -L mipi_dphy_v4_3_5 -L xilinx_vip $ddrIncludeArgs -prj awr2243_capture_top_with_bd_smoke_tb_vlog.prj -log xvlog.log && xvhdl --initfile xsim.ini --incr --relax -prj awr2243_capture_top_with_bd_smoke_tb_vhdl.prj -log xvhdl.log && xelab --initfile xsim.ini --incr --debug typical --relax --mt 2 -L xil_defaultlib -L lib_cdc_v1_0_2 -L proc_sys_reset_v5_0_13 -L xlconstant_v1_1_7 -L util_vector_logic_v2_0_2 -L gtwizard_ultrascale_v1_7_14 -L blk_mem_gen_v8_4_5 -L xdma_v4_1_20 -L smartconnect_v1_0 -L axi_infrastructure_v1_1_0 -L axi_register_slice_v2_1_27 -L axi_vip_v1_1_13 -L axis_infrastructure_v1_1_0 -L axis_data_fifo_v2_0_9 -L fifo_generator_v13_2_7 -L axi_clock_converter_v2_1_26 -L microblaze_v11_0_10 -L lmb_v10_v3_0_12 -L lmb_bram_if_cntlr_v4_0_21 -L iomodule_v3_1_8 -L mipi_csi2_rx_ctrl_v1_0_8 -L high_speed_selectio_wiz_v3_6_4 -L mipi_dphy_v4_3_5 -L uvm -L xilinx_vip -L unisims_ver -L unimacro_ver -L secureip -L xpm --snapshot awr2243_capture_top_with_bd_smoke_tb_behav xil_defaultlib.awr2243_capture_top_with_bd_smoke_tb xil_defaultlib.glbl -log xelab.log && xsim awr2243_capture_top_with_bd_smoke_tb_behav -key {Behavioral:sim_1:Functional:awr2243_capture_top_with_bd_smoke_tb} -tclbatch awr2243_capture_top_with_bd_smoke_tb.tcl -protoinst "protoinst_files/bd_f41a.protoinst" -protoinst "protoinst_files/bd_5fe6.protoinst" -protoinst "protoinst_files/bd_fbe3.protoinst" -protoinst "protoinst_files/awr2243_capture_bd.protoinst" -log xsim_run.log
"@

Write-Host "Running XSIM smoke test..."
cmd /c $cmd

$xsimLog = Join-Path $runDir 'xsim_run.log'
if (-not (Test-Path $xsimLog)) {
    throw "XSIM run log not found: $xsimLog"
}

if (-not (Select-String -Path $xsimLog -Pattern 'BD smoke simulation passed' -Quiet)) {
    throw "Smoke simulation completed without the expected PASS marker. See $xsimLog"
}

Write-Host "AWR2243 BD smoke simulation passed."
