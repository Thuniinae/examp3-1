#ifndef PARAM_H
#define PARAM_H

const int ADDER_INPUT = 0x00000000;  // two integer
const int ADDER_OUTPUT = 0x00000008; // one integers
const int ADDER_SIZE = 0x0000000c;   // total of three integers 

union word {
  int sint;
  unsigned int uint;
  unsigned char uc[4];
};

#endif