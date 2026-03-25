proc repo_root_from_script {} {
  set script_dir [file normalize [file dirname [info script]]]
  return [file normalize [file join $script_dir .. ..]]
}

set repo_root [repo_root_from_script]
set ::awr2243_keep_project_open 1

source [file join $repo_root tools vivado refresh_awr2243_capture_project.tcl]

set bd_file [get_files -quiet */awr2243_capture_bd.bd]
if {[llength $bd_file] == 0} {
  error "AWR2243 block design not found in project."
}

open_bd_design [lindex $bd_file 0]
validate_bd_design
generate_target all $bd_file
export_ip_user_files -of_objects $bd_file -no_script -sync -force

set sim_1 [get_filesets sim_1]
set_property top awr2243_capture_top_with_bd_smoke_tb $sim_1
set_property xsim.simulate.runtime 10us $sim_1

update_compile_order -fileset sources_1
update_compile_order -fileset sim_1

launch_simulation -simset sim_1 -mode behavioral -scripts_only

close_project
