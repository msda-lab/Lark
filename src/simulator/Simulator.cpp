#include "Simulator.h"

Simulator::Simulator(const string &_name)
{
    ckt = new Circuit(_name);
}

Simulator::~Simulator()
{

}

void Simulator::ParseDCAnalysis(const string &_src, double _start, double _end, double _incr)
{
    cout << "DC analysis: src is " << _src << " start=" << _start << " end=" << _end << " incr=" << _incr << endl;
}

void Simulator::ParseDCAnalysis(const string &_src1, double _start1, double _end1, double _incr1,
                               const string &_src2, double _start2, double _end2, double _incr2)
{

}

void Simulator::ParsePrint(int _anaType, const map<int, string> &_output)
{
    DisplayAnalysis(_anaType, _output);
}

void Simulator::ParsePlot(int _anaType, const map<int, string> &_output)
{
    DisplayAnalysis(_anaType, _output);
}

Circuit *Simulator::GetCktPtr() const
{
    return ckt;
}


void Simulator::Simulate()
{

}




