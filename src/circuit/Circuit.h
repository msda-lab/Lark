#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <iostream>
#include <string>

#include "SymbTable.h"
#include "DeviceBase.h"

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
        void ParseVSource(const string &_name, const string &_n1, const string &_n2, double _dc);
        void ParseISource(const string &_name, const string &_n1, const string &_n2, double _dc);
        void ParseNode(const string &_name);
    
    private: 
        SymbTable<string, Node*> *node_table;
        //SymbTable<string, Device*> *device_table;

        string name;
        
};

#endif // CIRCUIT_H
