# Section 1: Intro: Cheating our way past the transistor -- 0.5 weeks

# So about those transistors -- Course overview. 

### Describe how FPGAs are buildable using transistors, and that ICs are just collections of transistors in a nice reliable package. Understand the LUTs and stuff. Talk briefly about the theory of transistors, but all projects must build on each other so we can’t build one.

---

## FPGAs
>> [Read](https://www.rapidwright.io/docs/FPGA_Architecture.html) "What is an FPGA?", "CPU vs. FPGA", "Lookup Tables (LUTs)"
* modern FPGAs have a wide variety of components, at <b><u>their heart is a large array of replicated programmable LUTs, [flipflops](https://de.wikipedia.org/wiki/Flipflop) and programmable wires</u></b>
  ![](https://www.rapidwright.io/docs/_images/logic_array.png)
  ![](https://www.rapidwright.io/docs/_images/logic_array_closeup.png) 

---

## LUTs

* has single bit output that is calculated based on the input signal values and the configuration table (or memory)
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

## Transistors
>>Read [Summary](https://homepages.uni-regensburg.de/~erc24492/Transistorkunde/Transistorkunde.html) from Uni Regensburg.

<u>Logik Gatter aus Transistoren</u>  
![](https://www.electronics-tutorials.ws/wp-content/uploads/2018/05/logic-log43.gif) 
>>npn-Transistor (AND)

![](https://www.electronics-tutorials.ws/wp-content/uploads/2018/05/logic-log44.gif)
>> OR
![](https://www.electronics-tutorials.ws/wp-content/uploads/2018/05/logic-log47.gif)
>> NOT

Read more at [electroics tutorials](https://www.electronics-tutorials.ws/de/category/logisc


## Beispiel: Volladdierer

### Wahrheitstabelle
| x | y | c<sub>in</sub> | c<sub>out</sub> | s |
|---|---|---|---|---|
| 1  | 1  | 0  | 1  | 0  |
| 1  | 1  | 1  | 1  | 1  |
| 1  | 0  | 0  | 0  | 1  |
| 1  | 0  | 1  | 1  | 0  |
| 0  | 1  | 0  | 0  | 1  |
| 0  | 1  | 1  | 1  | 0  |
| 0  | 0  | 0  | 0  | 0  |
| 0  | 0  | 1  | 0  | 1  |

### $\rightarrow$ Disjunktive Normalform aus Wahrheitstablle
>> Zeilen sind Disjunktionen und Spalten Konjunktionen.

s = x XOR y XOR c<sub>in</sub>

c<sub>out</sub> = ...

### Kanonische Disjunktive Normalform 
>> siehe google

---

Sources: 
* [rapidwright.io](https://www.rapidwright.io/docs/FPGA_Architecture.html) (FPGAs)
* [electronic tutorials](https://www.electronics-tutorials.ws/de/logische/oder-gatter.html) (Gates)


--- 

## Emulation -- Building on real hardware limits the reach of this course. Using something like Verilator will allow anyone with a computer to play.

>> See [Verilator](https://github.com/verilator/verilator/blob/master/docs/install.adoc) for install instrucitons.
