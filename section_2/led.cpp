#include <stdio.h>
#include <stdlib.h>
#include "Vled.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

void    tick(Vled *tb) {
        tb->eval();
        tb->i_clk = 1;
        tb->eval();
        tb->i_clk = 0;
        tb->eval();
}

int main(int argc, char **argv) {
        int     last_led;

        // Call commandArgs first!
        Verilated::commandArgs(argc, argv);

        // Instantiate our design
        Vled *tb = new Vled;

        last_led = tb->o_led;
        for(int k=0; k<(1<<15); k++) {
                tick(tb);

                // Now let's print our results
                if (last_led != tb->o_led) {
                        printf("k = %7d, ", k);
                        printf("led = %d\n", tb->o_led);
                } last_led = tb->o_led;
        }
}

