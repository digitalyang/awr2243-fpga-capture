// Stub for Xilinx xpm_memory_sdpram for Verilator/simulation (no XPM dependency).
// Same port/parameter names as XPM so ddr_ringbuffer_controller instantiates without change.
module xpm_memory_sdpram #(
    parameter int ADDR_WIDTH_A             = 6,
    parameter int ADDR_WIDTH_B             = 6,
    parameter int AUTO_SLEEP_TIME         = 0,
    parameter int BYTE_WRITE_WIDTH_A       = 288,
    parameter int CASCADE_HEIGHT           = 0,
    parameter string CLOCKING_MODE         = "common_clock",
    parameter string ECC_MODE              = "no_ecc",
    parameter string MEMORY_INIT_FILE      = "none",
    parameter string MEMORY_INIT_PARAM     = "0",
    parameter string MEMORY_OPTIMIZATION    = "true",
    parameter string MEMORY_PRIMITIVE      = "block",
    parameter int MEMORY_SIZE              = 1728,
    parameter int MESSAGE_CONTROL          = 0,
    parameter int READ_DATA_WIDTH_B       = 288,
    parameter int READ_LATENCY_B          = 1,
    parameter string READ_RESET_VALUE_B    = "0",
    parameter string RST_MODE_A            = "SYNC",
    parameter string RST_MODE_B            = "SYNC",
    parameter int SIM_ASSERT_CHK           = 0,
    parameter int USE_EMBEDDED_CONSTRAINT = 0,
    parameter int USE_MEM_INIT             = 0,
    parameter string WAKEUP_TIME           = "disable_sleep",
    parameter int WRITE_DATA_WIDTH_A      = 288,
    parameter string WRITE_MODE_B          = "read_first"
) (
    input  logic                        sleep,
    input  logic                        clka,
    input  logic                        ena,
    input  logic                        wea,
    input  logic [ADDR_WIDTH_A-1:0]    addra,
    input  logic [WRITE_DATA_WIDTH_A-1:0] dina,
    input  logic                        injectsbiterra,
    input  logic                        injectdbiterra,
    input  logic                        clkb,
    input  logic                        enb,
    input  logic [ADDR_WIDTH_B-1:0]    addrb,
    input  logic                        rstb,
    input  logic                        regceb,
    output logic [READ_DATA_WIDTH_B-1:0] doutb,
    output logic                        dbiterrb,
    output logic                        sbiterrb
);
  localparam int DEPTH = 1 << (ADDR_WIDTH_A > ADDR_WIDTH_B ? ADDR_WIDTH_A : ADDR_WIDTH_B);
  logic [READ_DATA_WIDTH_B-1:0] mem [0:DEPTH-1];
  logic [READ_DATA_WIDTH_B-1:0] doutb_r;

  always_ff @(posedge clka) begin
    if (ena && wea)
      mem[addra] <= dina;
  end

  always_ff @(posedge clkb) begin
    if (rstb)
      doutb_r <= '0;
    else if (enb && regceb)
      doutb_r <= mem[addrb];
  end

  assign doutb = (READ_LATENCY_B >= 1) ? doutb_r : mem[addrb];
  assign dbiterrb = 1'b0;
  assign sbiterrb = 1'b0;
endmodule
