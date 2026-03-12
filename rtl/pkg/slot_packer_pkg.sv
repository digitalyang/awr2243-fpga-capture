`include "slot_packer_macros.svh"

// Utility helpers shared by the fixed slot packer and its cocotb harnesses.
package slot_packer_pkg;

  function automatic int unsigned clog2_safe(input int unsigned value);
    if (value <= 1) begin
      return 1;
    end

    return $clog2(value);
  endfunction

  function automatic int unsigned ceil_div_u(input int unsigned numerator,
                                             input int unsigned denominator);
    if (denominator == 0) begin
      return 0;
    end

    return (numerator + denominator - 1) / denominator;
  endfunction

  function automatic int unsigned align_up_u(input int unsigned value,
                                             input int unsigned align_bytes);
    if (align_bytes <= 1) begin
      return value;
    end

    return ceil_div_u(value, align_bytes) * align_bytes;
  endfunction

  function automatic int unsigned max_u(input int unsigned lhs, input int unsigned rhs);
    if (lhs > rhs) begin
      return lhs;
    end

    return rhs;
  endfunction

  function automatic int unsigned min_u(input int unsigned lhs, input int unsigned rhs);
    if (lhs < rhs) begin
      return lhs;
    end

    return rhs;
  endfunction

  function automatic bit is_pow2_u(input int unsigned value);
    if (value == 0) begin
      return 1'b0;
    end

    return (value & (value - 1)) == 0;
  endfunction

endpackage
