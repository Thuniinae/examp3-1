// modify from ee6470 lab4
#ifndef INITIATOR_H_
#define INITIATOR_H_
#include <systemc>
using namespace sc_core;

#include <tlm>
#include <tlm_utils/simple_initiator_socket.h>
#include "tlm_utils/tlm_quantumkeeper.h"

class Initiator : public sc_module {
public:
  tlm_utils::simple_initiator_socket<Initiator> i_skt;
  tlm_utils::tlm_quantumkeeper m_qk;

  SC_HAS_PROCESS(Initiator);
  Initiator(sc_module_name n);

  int read_from_socket(unsigned long int addr, unsigned char mask[],
                       unsigned char rdata[], int dataLen);

  int write_to_socket(unsigned long int addr, unsigned char mask[],
                      unsigned char wdata[], int dataLen);

  void do_trans(tlm::tlm_generic_payload &trans);
  tlm::tlm_generic_payload trans;
  
};

Initiator::Initiator(sc_module_name n) : sc_module(n), i_skt("i_skt") {
  m_qk.set_global_quantum(sc_time(3, SC_NS) );
  m_qk.reset();
}

int Initiator::read_from_socket(unsigned long int addr, unsigned char mask[],
                                unsigned char rdata[], int dataLen) {
  // Set up the payload fields. Assume everything is 4 bytes.
  trans.set_read();
  trans.set_address((sc_dt::uint64)addr);

  trans.set_byte_enable_length((const unsigned int)dataLen);
  trans.set_byte_enable_ptr((unsigned char *)mask);

  trans.set_data_length((const unsigned int)dataLen);
  trans.set_data_ptr((unsigned char *)rdata);

  // Transport.
  do_trans(trans);

  /* For now just simple non-zero return code on error */
  return trans.is_response_ok() ? 0 : -1;

} // read_from_socket()

int Initiator::write_to_socket(unsigned long int addr, unsigned char mask[],
                               unsigned char wdata[], int dataLen) {
  // Set up the payload fields. Assume everything is 4 bytes.
  trans.set_write();
  trans.set_address((sc_dt::uint64)addr);

  trans.set_byte_enable_length((const unsigned int)dataLen);
  trans.set_byte_enable_ptr((unsigned char *)mask);

  trans.set_data_length((const unsigned int)dataLen);
  trans.set_data_ptr((unsigned char *)wdata);

  // Transport.
  do_trans(trans);

  /* For now just simple non-zero return code on error */
  return trans.is_response_ok() ? 0 : -1;

} // writeUpcall()

void Initiator::do_trans(tlm::tlm_generic_payload &trans) {
  sc_core::sc_time Delay = sc_core::SC_ZERO_TIME;

  // Call the transport and wait for no time, which allows the thread to yield
  // and others to get a look in!

  i_skt->b_transport(trans, Delay);
  m_qk.inc(Delay);
  if (m_qk.need_sync()) m_qk.sync();
} // do_trans()

#endif
