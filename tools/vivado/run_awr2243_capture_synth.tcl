proc repo_root_from_script {} {
  set script_dir [file normalize [file dirname [info script]]]
  return [file normalize [file join $script_dir .. ..]]
}

proc bd_child_ip_xcis {design_name} {
  set pattern "*${design_name}.bd"
  return [lsort [get_files -all -filter "FILE_TYPE == IP && PARENT_COMPOSITE_FILE =~ \"$pattern\""]]
}

proc ensure_bd_ip_runs {design_name} {
  set runs {}
  foreach xci [bd_child_ip_xcis $design_name] {
    set run_name "[file rootname [file tail $xci]]_synth_1"
    if {[llength [get_runs -quiet $run_name]] == 0} {
      if {[catch {create_ip_run $xci} create_err]} {
        puts "INFO: skipping IP run for $xci ($create_err)"
        continue
      }
    }
    if {[llength [get_runs -quiet $run_name]] > 0} {
      lappend runs $run_name
    }
  }
  return [lsort -unique $runs]
}

proc launch_and_wait_runs {runs jobs} {
  if {[llength $runs] == 0} {
    return
  }
  launch_runs $runs -jobs $jobs
  foreach run_name $runs {
    wait_on_run $run_name
  }
}

set repo_root [repo_root_from_script]
set ::awr2243_keep_project_open 1
source [file join $repo_root tools vivado refresh_awr2243_capture_project.tcl]
unset ::awr2243_keep_project_open

set design_name awr2243_capture_bd
set run_jobs 2

set ip_runs [ensure_bd_ip_runs $design_name]
puts "INFO: BD child IP synthesis runs: [llength $ip_runs]"
foreach run_name $ip_runs {
  puts "INFO:   $run_name"
}
launch_and_wait_runs $ip_runs $run_jobs

reset_run synth_1
launch_runs synth_1 -jobs $run_jobs
wait_on_run synth_1

puts "INFO: synth_1 status   = [get_property STATUS [get_runs synth_1]]"
puts "INFO: synth_1 progress = [get_property PROGRESS [get_runs synth_1]]"

close_project
