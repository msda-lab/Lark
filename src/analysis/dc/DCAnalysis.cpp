#include "DCAnalysis.h"

#include "Global.h"

DCAnalysis::DCAnalysis(double _start, double _end, double _incr)
    : Analysis(DC_ANALYSIS_TYPE)
{
    start = _start;
    end = _end;
    incr = _incr;
}

DCAnalysis::~DCAnalysis()
{
#ifdef DEBUG
    PRINT_LINE
#endif
}

void DCAnalysis::DoAnalysis()
{
    double current_value;
    ckt->Setup(analysis_type);
    for(current_value = start; current_value <= end; current_value += incr)
    {
        cout << "current_value : " << current_value << endl;
        Reload(current_value);
        DoSinglePointAnalysis();
    }

    ckt->DestroyMatrixAndVector();
}

void DCAnalysis::DoSinglePointAnalysis()
{
    ckt->GetNumericPtr()->GetSolution();
}

void DCAnalysis::Reload(double _src_value)
{
    ckt->Reset();
    ckt->LoadSweepDC(sweep_src, _src_value);
    ckt->LoadDC();
}

void DCAnalysis::SetSweepSrc(Device *_src)
{
    sweep_src = _src;
}
