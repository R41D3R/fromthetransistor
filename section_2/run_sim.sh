verilator -Wall -cc led.v
cd obj_dir/
make -f Vled.mk
cd ..
g++ -I /usr/share/verilator/include -I obj_dir/ /usr/share/verilator/include/verilated.cpp led.cpp obj_dir/Vled__ALL.a -o led
./led
