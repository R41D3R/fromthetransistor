# Section 1: Intro: Cheating our way past the transistor -- 0.5 weeks

## So about those transistors -- Course overview. 

### Describe how FPGAs are buildable using transistors, and that ICs are just collections of transistors in a nice reliable package. Understand the LUTs and stuff. Talk briefly about the theory of transistors, but all projects must build on each other so we can’t build one.

* highly configurable logic and data paths
* modern FPGAs have a wide variety of components, at their heart is a large array of replicated programmable LUTs, [flipflops](https://de.wikipedia.org/wiki/Flipflop) and programmable wires

>>![](https://www.rapidwright.io/docs/_images/logic_array.png)

>>![](https://www.rapidwright.io/docs/_images/logic_array_closeup.png)

#### LUTs

* has single bit output that is calculated besed on the input signal values and the configuration table (or memory)
![](https://www.rapidwright.io/docs/_images/luts.png)
>> left: truth table / right: logical hehavior

* can implement any N bit logic operation (where N is the number of inputs)
    * X1 XOR X0: 

| I2 | I1 | I0 | Out |
|----|----|----|-----|
| 0  | 0  | 0  | 0   |
| 0  | 0  | 1  | 1   |
| 0  | 1  | 0  | 1   |
| 0  | 1  | 1  | 0   |
| 1  | 0  | 0  | 0   |
| 1  | 0  | 1  | 1   |
| 1  | 1  | 0  | 1   |
| 1  | 1  | 1  | 0   |

* 2 input LUT build with transistors:
![](https://d3i71xaburhd42.cloudfront.net/85f2b6159e27360d1e0ba695f49501f75e64e49d/1-Figure1-1.png)
>> a) truth table b) implementation c) optimized implementation

### Transistors

* elektrisch regelbarer Widerstand
  
![](https://www.electronics-tutorials.ws/wp-content/uploads/2018/05/logic-log43.gif)
>> npn-Transistor



---

Sources: 
* [rapidwright.io](https://www.rapidwright.io/docs/FPGA_Architecture.html)

### Emulation -- Building on real hardware limits the reach of this course. Using something like Verilator will allow anyone with a computer to play.
