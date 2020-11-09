module led (i_clk, o_led);
    input wire i_clk;
    output wire o_led;

    reg [12:0] counter;  // changes every 20th cycle
    initial counter = 0;


    always @(posedge i_clk)
        counter <= counter + 1'b1;
    assign o_led = counter[12];
endmodule