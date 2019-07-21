#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <iostream>
#include <string>

#include "SymbTable.h"
#include "AllDevice.h"

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

        void PrintAllDevice() const;
        void PrintAllNode() const;
    
    private: 
        SymbTable<string, Node*> *node_table;
        SymbTable<string, Device*> *device_table;
        SymbTable<string, Model*> *model_table;

        string name;
        bool has_gnd;
        long int node_count;
        
};

#endif // CIRCUIT_H
