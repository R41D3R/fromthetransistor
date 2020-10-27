module led (input clk, output state);
    reg state;
    // add timer and counter for more flexablilty


    always @(posedge clk) begin
        state <= clk;
    end
endmodule