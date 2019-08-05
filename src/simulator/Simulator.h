/*************************************************************************************
                     Top layer of the simulator
**************************************************************************************/

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Circuit.h"
#include "Analysis.h"
#include "DCAnalysis.h"
#include "Util.h"

using std::string;
using std::cout;
using std::endl;
using std::map;
using std::vector;

class Simulator
{
    public:
        Simulator(const string &_name);
        ~Simulator();

    public: 
        void ParseDCAnalysis(const string &_src, double _start, double _end, double _incr);
        void ParseDCAnalysis(const string &_src1, double _start1, double _end1, double _incr1, const string &_src2, double _start2, double _end2, double _incr2);
        void ParsePrint(int _anaType, const map<int, string> &_output);
        void ParsePlot(int _anaType, const map<int, string> &_output);

        Circuit *GetCktPtr() const;

        void FinishParsing();
        void Simulate();

    
    private:
        void AddAnalysisTask(Analysis *_analysis);

        Circuit *ckt;
        vector<Analysis*> analysis_list;

};

#endif // SIMULATOR_H
