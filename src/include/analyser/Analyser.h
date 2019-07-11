/*************************************************************************************
                     Top layer of the simulator
**************************************************************************************/

#ifndef ANALYSER_H
#define ANALYSER_H

#include <iostream>
#include <string>
#include <map>

#include "Circuit.h"
#include "util.h"

using std::string;
using std::cout;
using std::endl;
using std::map;

class Analyser
{
    public:
        Analyser(const string &name);
        ~Analyser();

    public: 
        void parseDCAnalysis(const string &src, double start, double end, double incr);
        void parseDCAnalysis(const string &src1, double start1, double end1, double incr1, const string &src2, double start2, double end2, double incr2);
        void parsePrint(int anaType, const map<int, string> &output);
        void parsePlot(int anaType, const map<int, string> &output);
        Circuit *getCktPtr() const;
        void analyse();
    
    private:
        Circuit *ckt;
};

#endif // ANALYSER_H