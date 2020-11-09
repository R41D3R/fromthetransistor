module uart (i_data, i_clk,
             o_data, o_error);
    reg baudrate = 10;  // change later
    reg [8:0] buffer;   // buffer sending or incoming data
    input wire mode; // 0 - sending, 1 - receiving
    reg [2:0] state = 0;
    // 00 (idle) -> 01 (asked) -> 10 (confirmed -> sending)
    // 00 (idle) -> 11 (accepted -> receiving)
    reg [4:0] bitcounter = 1;

    reg [10:0] counter = 0; // after X baudrate sample 
    reg startbit = 1'b0;
    reg stopbit = 1'b0;

    input wire i_mode;
    input wire i_clk;
    input wire [8:0] i_data;
    input wire i_rx;
    input wire i_cts;
    input wire i_send;

    output wire [8:0] o_data;
    output wire o_tx;
    output wire o_rts;
    output wire [3:0] o_error;



    always @(posedge i_clk) begin
        counter <= counter + 1'b1;
        if (counter == 0)
            if (bitcounter >= 9)
                bitcounter <= 1'b0;
                state <= 1'b0;
            else
                bitcounter <= bitcounter + 1'b1;
        if (!mode) // sending
            if (state == 0 and i_send)
                o_rts <= 1'b1;
                buffer <= i_data;
                state <= state + 1'b1;
            if (state == 1 and i_cts)
                state <= state + 1'b1;
            if (state == 2)
                if (bitcounter == 0)
                    o_tx <= 1'b1;
                if (0 > bitcounter and bitcounter <= 8)
                    o_tx <= buffer[bitcounter - 1]
                if (bitcounter > 8)
                    o_tx <= 1'b1;
        
        else // receiving


    end 
endmodule
