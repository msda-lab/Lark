#include "Analyser.h"

Analyser::Analyser(const string &_name)
{
    ckt = new Circuit(_name);
}

Analyser::~Analyser()
{

}

void Analyser::ParseDCAnalysis(const string &_src, double _start, double _end, double _incr)
{
    cout << "DC analysis: src is " << _src << " start=" << _start << " end=" << _end << " incr=" << _incr << endl;
}

void Analyser::ParseDCAnalysis(const string &_src1, double _start1, double _end1, double _incr1,
                               const string &_src2, double _start2, double _end2, double _incr2)
{

}

void Analyser::ParsePrint(int _anaType, const map<int, string> &_output)
{
    DisplayAnalysis(_anaType, _output);
}

void Analyser::ParsePlot(int _anaType, const map<int, string> &_output)
{
    DisplayAnalysis(_anaType, _output);
}

Circuit *Analyser::GetCktPtr() const
{
    return ckt;
}


void Analyser::Analyse()
{

}




