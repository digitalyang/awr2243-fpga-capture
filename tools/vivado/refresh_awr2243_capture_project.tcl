proc repo_root_from_script {} {
  set script_dir [file normalize [file dirname [info script]]]
  return [file normalize [file join $script_dir .. ..]]
}

proc ensure_file_in_fileset {fileset path} {
  set normalized [file normalize $path]
  set existing [get_files -quiet $normalized]
  if {[llength $existing] == 0} {
    add_files -fileset $fileset -norecurse $normalized
  }
}

proc refresh_file_in_fileset {fileset path} {
  set normalized [file normalize $path]
  set existing [get_files -quiet $normalized]
  if {[llength $existing] > 0} {
    remove_files $existing
  }
  add_files -fileset $fileset -norecurse $normalized
}

proc remove_file_from_project {path} {
  set normalized [file normalize $path]
  set existing [get_files -quiet $normalized]
  if {[llength $existing] > 0} {
    remove_files $existing
  }
}

proc remove_pattern_from_project {pattern} {
  set existing [get_files -all -quiet $pattern]
  if {[llength $existing] > 0} {
    remove_files $existing
  }
}

proc delete_run_if_present {run_name} {
  set run_obj [get_runs -quiet $run_name]
  if {[llength $run_obj] > 0} {
    catch {delete_runs $run_obj}
  }
}

proc delete_fileset_if_present {fileset_name} {
  set fs_obj [get_filesets -quiet $fileset_name]
  if {[llength $fs_obj] > 0} {
    catch {delete_fileset $fs_obj}
  }
}

proc append_glob_files {var_name pattern} {
  upvar 1 $var_name results
  foreach path [lsort -dictionary [glob -nocomplain $pattern]] {
    if {[file isfile $path]} {
      lappend results [file normalize $path]
    }
  }
}

proc repo_source_files {repo_root} {
  set results {}
  foreach pattern {
    rtl/include/*.svh
    rtl/pkg/*.sv
    rtl/axi/*_pkg.sv
    rtl/generated/*_pkg.sv
    rtl/if/*.sv
    rtl/generated/*.sv
    rtl/axi/*.sv
    rtl/axil/*.sv
    rtl/core/*.sv
    rtl/pcie/*.sv
    rtl/top/csi_rx_axis_pack_ref.v
    rtl/top/awr2243_capture_top_exec.sv
    rtl/top/awr2243_capture_core_ref.sv
    rtl/top/awr2243_capture_core_ref.v
    rtl/top/awr2243_capture_top_with_bd.sv
  } {
    append_glob_files results [file join $repo_root $pattern]
  }
  return [lsort -unique $results]
}

set repo_root [repo_root_from_script]
if {[info exists ::awr2243_project_name]} {
  set project_name $::awr2243_project_name
} else {
  set project_name awr2243_fpga_capture
}
if {[info exists ::awr2243_project_dir]} {
  set project_dir [file normalize $::awr2243_project_dir]
} else {
  set project_dir [file join $repo_root vivado_project vivado_ku5p]
}
set project_xpr [file join $project_dir ${project_name}.xpr]

if {[llength [get_projects -quiet]] > 0} {
  close_project
}
if {[file exists $project_xpr]} {
  open_project $project_xpr
} elseif {[file exists $project_dir]} {
  create_project $project_name $project_dir -part xcku5p-ffvb676-2-e -force
} else {
  create_project $project_name $project_dir -part xcku5p-ffvb676-2-e
}

set sources_1 [get_filesets sources_1]
set constrs_1 [get_filesets constrs_1]
set utils_1   [get_filesets utils_1]

foreach stale {
  C:/Users/admin/Downloads/awr2243_capture_top_exec.sv
  C:/Users/admin/Downloads/awr2243_capture_top_with_bd.sv
  rtl/top/csi_rx_axis_shim_ref.v
  rtl/top/csi_rx_axis_tdest_shim_ref.v
  rtl/top/csi_rx_axis_shim.sv
} {
  if {[file pathtype $stale] eq "absolute"} {
    set stale_path $stale
  } else {
    set stale_path [file join $repo_root $stale]
  }
  remove_file_from_project $stale_path
}

foreach legacy_ip {
  awr2243_capture_bd_axis_dwidth_converter_0_0
  awr2243_capture_bd_csi_rx_axis_collapse_0_0
  awr2243_capture_bd_csi_rx_axis_shim_0_0
} {
  delete_run_if_present ${legacy_ip}_synth_1
  delete_run_if_present ${legacy_ip}_impl_1
  delete_fileset_if_present $legacy_ip
  remove_pattern_from_project */${legacy_ip}/*
}

set stale_incr_dcp [file join $project_dir awr2243_fpga_capture.srcs utils_1 imports synth_1 awr2243_capture_top_exec.dcp]
set stale_incr_files [get_files -quiet $stale_incr_dcp]
if {[llength $stale_incr_files] > 0} {
  remove_files -fileset $utils_1 $stale_incr_files
}
if {[file exists $stale_incr_dcp]} {
  file delete -force $stale_incr_dcp
}

foreach src [repo_source_files $repo_root] {
  refresh_file_in_fileset $sources_1 $src
}

ensure_file_in_fileset $constrs_1 [file join $repo_root constraints awr2243_project_stub.xdc]

update_compile_order -fileset sources_1

source [file join $repo_root tools vivado create_awr2243_capture_bd.tcl]

set bd_file [get_files -quiet */awr2243_capture_bd.bd]
generate_target all $bd_file

set wrapper_file [make_wrapper -files $bd_file -top]
if {[llength $wrapper_file] > 0} {
  ensure_file_in_fileset $sources_1 [lindex $wrapper_file 0]
}

set_property top awr2243_capture_top_with_bd $sources_1
set_property top awr2243_capture_top_with_bd [get_filesets sim_1]
set_property verilog_dir [file join $repo_root rtl include] $sources_1

update_compile_order -fileset sources_1
if {![info exists ::awr2243_keep_project_open] || !$::awr2243_keep_project_open} {
  close_project
}
