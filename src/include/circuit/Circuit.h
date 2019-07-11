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
        void parseRes(const string &_name, const string &_n1, const string &_n2, double _r);
        void parseCap(const string &_name, const string &_n1, const string &_n2, double _c);
        void parseInd(const string &_name, const string &_n1, const string &_n2, double _l);
        void parseVSource(const string &_name, const string &_n1, const string &_n2, double _dc);
        void parseISource(const string &_name, const string &_n1, const string &_n2, double _dc);
        void parseNode(const string &_name);
    
    private: 
        SymbTable<string, Node*> *nodeTable;
        //SymbTable<string, Device*> *deviceTable;

        string name;
        
};

#endif // CIRCUIT_H
