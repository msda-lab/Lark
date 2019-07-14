/*************************************************************************************
                     Top layer of the simulator
**************************************************************************************/

#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <map>

#include "Circuit.h"
#include "Util.h"

using std::string;
using std::cout;
using std::endl;
using std::map;

class Manager
{
    public:
        Manager(const string &_name);
        ~Manager();

    public: 
        void ParseDCAnalysis(const string &_src, double _start, double _end, double _incr);
        void ParseDCAnalysis(const string &_src1, double _start1, double _end1, double _incr1, const string &_src2, double _start2, double _end2, double _incr2);
        void ParsePrint(int _anaType, const map<int, string> &_output);
        void ParsePlot(int _anaType, const map<int, string> &_output);
        Circuit *GetCktPtr() const;
        void Analyse();
    
    private:
        Circuit *ckt;
};

#endif // MANAGER_H