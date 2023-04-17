#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc>
#include"initiator.h"
#include "param.h"

using namespace std;
using namespace sc_core; 
using namespace sc_dt; 

class TESTBENCH : public sc_module{
public:
    SC_CTOR(TESTBENCH):initiator("initiator"){
        SC_THREAD(source);
        dont_initialize();
        sensitive << clk.pos();
        SC_THREAD(sink);
        dont_initialize();
        sensitive << clk.pos();
    }
    Initiator initiator;
    sc_in_clk clk;
private:
    void source(void);
    void sink(void);
    sc_ufixed_fast<32,10> _a, _b, _r;
};

void TESTBENCH::source(){
    word mask;
    mask.uint = 0xffff;
    for (int i = 0; i < 128; i++){
        initiator.write_to_socket(ADDER_INPUT, mask.uc, &x_input_signal[i] , 4);
        wait();
    }
}

void TESTBENCH::sink(){
    word buffer;
    word mask;
    mask.uint = 0xffff;
    cout << "y_downsample_by2 = " << endl;
    for (int i = 0; i < 64; i++){
        initiator.write_to_socket(ADDER_INPUT, mask.uc, &_r , 4);
        //cout <<  i <<": ";
        printf("%.3f, ", (double)_r);
        wait();
    }
    cout << "\ntotal cycles: " ;
    cout << sc_time_stamp() <<  "/1ns" <<endl ;
    sc_stop();
}


#endif