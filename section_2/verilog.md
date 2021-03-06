# Verilog

## Inroduction

>> Read [this](https://www.chipverify.com/verilog/verilog-tutorial) page.

## D-Flip-Flop Example
```verilog
// d flip flop
module dff (input d, rstn, clk, output q);
    reg q;
    
    always @ (posedge clk) begin
        if (!rstn)
            q <= 0;
        else
            q <= d;
    end
endmodule

// testbench
module main;
    reg tb_clk;
    reg tb_d;
    reg tb_rstn;
    wire tb_q;
    
    dff dff0(   .clk    (tb_clk),
                .d      (tb_d),
                .rstn   (tb_rstn),
                .q      (tb_q));
    
    initial begin
        tb_rstn     <= 1'b1;
        tb_clk      <= 1'b1;
        tb_d        <= 1'b0;
        $monitor("clk = %0d q = %0d d = %0d", tb_clk, tb_q, tb_d);
    end
endmodule
```
>> taken from [chipverify](https://www.chipverify.com/verilog/verilog-introduction)


## Blinking LED Example

```verilog
module led (i_clk, o_led);
    input wire i_clk;
    output wire o_led;

    reg [12:0] counter;  // changes every 20th cycle
    initial counter = 0;


    always @(posedge i_clk)
        counter <= counter + 1'b1;
    assign o_led = counter[12];
endmodule
```


## UART

* baudrate (bruchteil 12 bit)
* vor ändern der baudrate sicherstellen, dass keine Übertragung im Gange ist

Handshake
* High and RTS = Anfrage
* High an CTS = Sendeerlaubnis
  ![](Screenshot_2020-10-24%20Micro_RS232%20pdf.png)

8 Datenbit, no parity, 1 Stopp Bit

1. transmitting UART (tUART) receives data in parallel from the data bus
2. add start and stop bit to the data frame
3. packet is sent serially; the receiving UART (rUART) samples the data line at the pre-configured baud rate
4. rUART discards start and stop bit 
5. rUART converts serial data back into parallel and transfers it to the data bus

---

Sources:
* [Blogpost: Taking a new look at verilator](https://zipcpu.com/blog/2017/06/21/looking-at-verilator.html)
* [sample implementation](https://github.com/hell03end/verilog-uart)
* [UART Simulator + Implementation](https://github.com/ZipCPU/wbuart32)
* [FPGA design for Software Engineers](https://www.walknsqualk.com/post/014-tiny-fpga-bx/)
* [Verilog: Formal and Beginner Tutorial](https://zipcpu.com/tutorial/)