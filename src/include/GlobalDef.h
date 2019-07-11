#ifndef GLOBAL_DEF_H
#define GLOBAL_DEF_H

#include <complex>

// symbol table define
const int HASH_LEN = 1024;
const float LOAD_FACTOR = 0.75;
const int MAX_LINKED_LIST = 8;


// analysis type define
const int DC_TYPE = 0;
const int AC_TYPE = 1;
const int TRAN_TYPE = 2;
const int V_TYPE = 3;
const int I_TYPE = 4;
const int VM_TYPE = 5;
const int VR_TYPE = 6;
const int VP_TYPE = 7;

// used by AC simulation.
typedef std::complex<double> Complex;


#endif //GLOBAL_DEF_H
