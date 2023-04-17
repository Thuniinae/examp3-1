// template
// CHENG-HAN YU
// 2023/04/17
#include <systemc>
#include <iomanip> // for std::setw
#include "sysc/datatypes/fx/fx.h" // for sc_fixed
using namespace std;
using namespace sc_core; // for sc_start(), SC_MODULE, ...
using namespace sc_dt; // for system-c datatypes

#include"param.h"
#include "testbench.h"
#include "adder.h"



int sc_main(int argc, char *argv[]){

    TESTBENCH tb("tb");
    ADDER adder("adder");
    sc_clock clk("clk", 1, SC_NS);

    adder.clk(clk);
    tb.clk(clk);
    tb.initiator.i_skt(adder.t_skt);
    sc_start(20, SC_NS);
    return 0;
}