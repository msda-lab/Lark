#include "Analyser.h"

Analyser::Analyser(const string &name)
{
    ckt = new Circuit(name);
}

Analyser::~Analyser()
{

}

void Analyser::parseDCAnalysis(const string &src, double start, double end, double incr)
{
    cout << "DC analysis: src is " << src << " start=" << start << " end=" << end << " incr=" << incr << endl;
}

void Analyser::parseDCAnalysis(const string &src1, double start1, double end1, double incr1,
                               const string &src2, double start2, double end2, double incr2)
{

}

void Analyser::parsePrint(int anaType, const map<int, string> &output)
{
    displayAnalysis(anaType, output);
}

void Analyser::parsePlot(int anaType, const map<int, string> &output)
{
    displayAnalysis(anaType, output);
}

Circuit *Analyser::getCktPtr() const
{
    return ckt;
}


void Analyser::analyse()
{

}




