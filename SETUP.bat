@echo off
setlocal

set VIVADO_BAT=D:\fpga\Vivado/2022.2\bin\vivado.bat
set REPO_ROOT=E:/fpga/xilinxfpga/awr2243-fpga-capture
set TCL_SCRIPT=C:/Users/admin/Downloads/build_awr2243_full_project.tcl

if not exist "%VIVADO_BAT%" (
    echo ERROR: Vivado not found: %VIVADO_BAT%
    exit /b 1
)

if not exist "%TCL_SCRIPT%" (
    echo ERROR: Tcl script not found: %TCL_SCRIPT%
    exit /b 1
)

set AWR2243_REPO_ROOT=%REPO_ROOT%

call "%VIVADO_BAT%" -mode gui -source "%TCL_SCRIPT%"