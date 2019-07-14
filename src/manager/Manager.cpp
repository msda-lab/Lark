#include "Manager.h"

Manager::Manager(const string &_name)
{
    ckt = new Circuit(_name);
}

Manager::~Manager()
{

}

void Manager::ParseDCAnalysis(const string &_src, double _start, double _end, double _incr)
{
    cout << "DC analysis: src is " << _src << " start=" << _start << " end=" << _end << " incr=" << _incr << endl;
}

void Manager::ParseDCAnalysis(const string &_src1, double _start1, double _end1, double _incr1,
                               const string &_src2, double _start2, double _end2, double _incr2)
{

}

void Manager::ParsePrint(int _anaType, const map<int, string> &_output)
{
    DisplayAnalysis(_anaType, _output);
}

void Manager::ParsePlot(int _anaType, const map<int, string> &_output)
{
    DisplayAnalysis(_anaType, _output);
}

Circuit *Manager::GetCktPtr() const
{
    return ckt;
}


void Manager::Analyse()
{

}




