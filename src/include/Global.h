#ifndef GLOBAL_DEF_H
#define GLOBAL_DEF_H

#include <string>
#include <complex>

// symbol table define
const int HASH_LEN = 1024;
const float LOAD_FACTOR = 0.75;
const int MAX_LINKED_LIST = 8;


// analysis type define
const int DC_ANALYSIS_TYPE = 1000;
const int AC_ANALYSIS_TYPE = 1001;
const int TRAN_ANALYSIS_TYPE = 1002;
const int V_TYPE = 1003;
const int I_TYPE = 1004;
const int VM_TYPE = 1005;
const int VR_TYPE = 1006;
const int VP_TYPE = 1007;

// device type define
const int RESISTOR_TYPE = 2000;
const int CAPACITOR_TYPE = 2001;
const int INDUCTOR_TYPE = 2002;
const int ISOURCE_TYPE = 2003;
const int VSOURCE_TYPE = 2004;

// node type define
const int GND_TYPE = 3000;
const int NORMAL_TYPE = 3001;

// model type define
const std::string RES_MODEL_TYPE = "RES";
const std::string CAP_MODEL_TYPE = "CAP";
const std::string IND_MODEL_TYPE = "IND";
const std::string VSRC_MODEL_TYPE = "VSRC";
const std::string ISRC_MODEL_TYPE = "ISRC";


// used by AC simulation.
typedef std::complex<double> Complex;

// used by calculating complex value
const double PI = 3.141592653;


#endif //GLOBAL_DEF_H
