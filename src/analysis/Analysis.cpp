#include "Analysis.h"
#include "Global.h"

Analysis::Analysis(int _analysis_type)
{
    analysis_type = _analysis_type;
    sim_res = new SimulationResult(_analysis_type);
}

Analysis::~Analysis()
{
#ifdef DEBUG
    PRINT_LINE
#endif
    if(sim_res)
    {
        delete sim_res;
        sim_res = NULL;
    }
}

void Analysis::DoAnalysis()
{

}

int Analysis::GetAnalysisType() const
{
    return analysis_type;
}

void Analysis::SetCktPtr(Circuit *_ckt)
{
    ckt = _ckt;
}

