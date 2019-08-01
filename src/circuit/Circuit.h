#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <iostream>
#include <string>
#include <map>

#include "CircuitInstance.h"
#include "AllDevice.h"
#include "Numeric.h"

using std::string;
using std::cout;
using std::endl;

class Circuit
{
    public: 
        Circuit(const string &_name);
        ~Circuit();
    
    public:
        void ParseRes(const string &_name, const string &_n1, const string &_n2, double _r);
        void ParseCap(const string &_name, const string &_n1, const string &_n2, double _c);
        void ParseInd(const string &_name, const string &_n1, const string &_n2, double _l);
        void ParseVSource(const string &_name, const string &_n1, const string &_n2, double _dc, Complex _ac);
        void ParseISource(const string &_name, const string &_n1, const string &_n2, double _dc, Complex _ac);

        Node* GetParseNode(const string &_name);

        Device *GetDevice(const string &_name) const;

        void LoadSweepDC(Device *_src, double _src_value);
        void LoadDC();

        void Reset();
        void ResetMatrix();
        void ResetRHS();
        void Setup(int _analysis_type);

        void PrintAllDevice() const;
        void PrintAllNode() const;
        void PrintAllModel() const;
    
    private: 
        CircuitInstance *ckt_instance;

        string name;
        bool has_gnd;
        long int node_count;
};

#endif // CIRCUIT_H
