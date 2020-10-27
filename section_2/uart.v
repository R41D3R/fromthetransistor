module uart (input in, clk, answer, rx, ensend, enrec output out, ask, tx, busy, send, rec, errsend);
    reg baudrate = 10;  // change later
    reg [8:0] buffer;
    reg confirmed = 1'b0;
    reg counter = 0;

    // input
    reg ensend;
    reg enrec;
    reg answer;
              
    reg rx;
    wire [8:0] in;
         

    // output
    reg ask;  
    reg busy = 1'b0;    
    reg send = 1'b0;    // sending?
    reg rec = 1'b0;     // receiving?
    reg tx;             // send data
    wire [8:0] out; 
    reg errsend = 1'b0;


    always @(posedge clk) begin
        if (!busy)
            if (ensend)
                busy <= 1'b1;
                send <= 1'b1;
                ask <= 1'b1;
                buffer <= in;
            if (answer)
                busy <= 1'b1;
                rec <= 1'b1;
                ask <= 1'b1;
        else
            if (send)
                // if sending and should do something -> error
                if (!confirmed)
                    if (answer)
                        confirmed <= 1'b1;
                        tx <= 1'b1;
                    else
                        // if no answer after x cycles -> ask again or idle -> error
                else
                    if (counter < 8)
                        tx <= buffer[counter];
                    else
                        tx <= 1'b1;
                        send <= 1'b0;
                        busy <= 1'b0;
                        confirmed <= 1'b0;
                        counter <= 0;
            if (rec)
                // if receiving and should do something -> error
                // check if enough cycles
                if (counter == 0)
                    counter <= counter + 1;
                else if (counter < 8)
                    buffer[counter - 1] <= rx;
                    else
                        busy <= 1'b0;
                        rec <= 1'b0;
                        counter <= 0;
                        out <= buffer;

            // if enough empty cycles and no received message endinge -> raise error or discard message

    end
endmodule
