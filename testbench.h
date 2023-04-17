#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc>
#include"initiator.h"
#include "param.h"

using namespace std;
using namespace sc_core; 
using namespace sc_dt; 

union word {
  int sint;
  unsigned int uint;
  unsigned char uc[4];
};

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
    for (int i = 0; i < 128; i++){
        initiator.write_to_socket(ADDER_INPUT, NULL, &x_input_signal[i] , 4);
        wait();
    }
}

void TESTBENCH::sink(){
    cout << "y_downsample_by2 = " << endl;
    for (int i = 0; i < 64; i++){
        initiator.write_to_socket(ADDER_INPUT, NULL, &_r , 4);
        //cout <<  i <<": ";
        printf("%.3f, ", (double)_r);
        wait();
    }
    cout << "\ntotal cycles: " ;
    cout << sc_time_stamp() <<  "/1ns" <<endl ;
    sc_stop();
}


#endif