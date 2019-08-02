#include "Simulator.h"

Simulator::Simulator(const string &_name)
{
    ckt = new Circuit(_name);
}

Simulator::~Simulator()
{
#ifdef DEBUG
    PRINT_LINE
#endif

    if(ckt)
    {
        delete ckt;
        ckt = NULL;
    }
    vector<Analysis*>::iterator ait;
    for(ait = analysis_list.begin(); ait != analysis_list.end(); ++ ait)
    {
        delete (*ait);
        (*ait) = NULL;
    }
    analysis_list.clear();
}

void Simulator::ParseDCAnalysis(const string &_src, double _start, double _end, double _incr)
{
    //cout << "DC analysis: src is " << _src << " start=" << _start << " end=" << _end << " incr=" << _incr << endl;
    DCAnalysis *dc_analysis = new DCAnalysis(_start, _end, _incr);
    dc_analysis->SetCktPtr(ckt);
    Device *device = ckt->GetDevice(_src);
    if(device)
    {
        dc_analysis->SetSweepSrc(device);
        analysis_list.push_back(dc_analysis);
    }
}

void Simulator::ParseDCAnalysis(const string &_src1, double _start1, double _end1, double _incr1,
                               const string &_src2, double _start2, double _end2, double _incr2)
{

}

void Simulator::ParsePrint(int _anaType, const map<int, string> &_output)
{
    //DisplayAnalysis(_anaType, _output);
}

void Simulator::ParsePlot(int _anaType, const map<int, string> &_output)
{
    //DisplayAnalysis(_anaType, _output);
}

Circuit *Simulator::GetCktPtr() const
{
    return ckt;
}


void Simulator::Simulate()
{
    vector<Analysis*>::const_iterator task;
    for(task = analysis_list.cbegin(); task != analysis_list.cend(); ++ task)
    {
        (*task)->DoAnalysis();
    }
}

void Simulator::AddAnalysisTask(Analysis *_analysis)
{
    analysis_list.push_back(_analysis);
}
