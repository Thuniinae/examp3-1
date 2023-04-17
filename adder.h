#ifndef ADDER_H
#define ADDER_H

#include <systemc>
#include <tlm>
#include <tlm_utils/simple_target_socket.h>
#include"param.h"

//using namespace std;
//using namespace sc_core;
//using namespace sc_dt;

class ADDER : public sc_module{
public:
    tlm_utils::simple_target_socket<ADDER> t_skt;
    SC_CTOR(ADDER){
        SC_THREAD(my_thread);
        sensitive << clk.pos();
        dont_initialize();
        t_skt.register_b_transport(this, &ADDER::blocking_transport);
    }
    sc_in_clk clk;
private:
    
    void my_thread(void);
    void blocking_transport(tlm::tlm_generic_payload &payload, sc_core::sc_time &delay);
    sc_fifo<int> a, b, s;
    sc_ufixed_fast<53,10> bufferF[3];
    sc_ufixed_fast<53,10> _a, _b, _r;
};

void ADDER::my_thread(){
    bufferF[0] = 0;
    bufferF[1] = a.read();
    bufferF[2] = a.read();
    for(int i = 0; i < 63; i++){
        _r = bufferF[2]*1/2 + bufferF[1]*1/3 + bufferF[0]*1/6;
        wait(3, SC_NS);
        r.write(_r);
        bufferF[0] = bufferF[2];
        bufferF[1] = a.read();
        bufferF[2] = a.read();
    }
    _r = buffer[2]*1/2 + buffer[1]*1/3 + buffer[0]*1/6;
    wait(3, SC_NS);
    r.write(_r);
}



void ADDER::blocking_transport(tlm::tlm_generic_payload &payload, sc_core::sc_time &delay){
    sc_dt::uint64 addr = payload.get_address();
    unsigned char *data_ptr = payload.get_data_ptr();
    //unsigned int data_length = payload.get_data_length();
    //unsigned char *mask_ptr = payload.get_byte_enable_ptr();
    //unsigned int masked_length = payload.get_byte_enable_length();
    switch (payload.get_command()) {
        case tlm::TLM_READ_COMMAND:
            delay = sc_time(1, SC_NS); // read delay
            switch(addr){
                case ADDER_OUTPUT:
                    _s = s.read();
                    // buffer.uc[0] = s; // if data s has size of unsigned char
                    break;
                default: 
                    cout << "invalid read address: " << addr << endl;
                    break;
            }
            memcpy(data_ptr, &_s, 4);
            break;
        case tlm::TLM_WRITE_COMMAND:
            delay = sc_time(1, SC_NS); //write delay
            switch(addr){
                case ADDER_INPUT:
                    memcpy(&_a, data_ptr, 4);
                    a.write(_a);
                    break;
                default: 
                    cout << "invalid write address: " << addr << endl;
                    break;
            }
            break;
        case tlm::TLM_IGNORE_COMMAND:
            payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
            return;
        default:
            payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
            return;
    }

}

#endif