#include "SimulationResult.h"

#include <iostream>

#include "MainMessage.h"

SimulationResult::SimulationResult()
{
}

SimulationResult::SimulationResult(int _analysis_type)
{
    analysis_type = _analysis_type;
}

SimulationResult::~SimulationResult()
{
#ifdef DEBUG
    PRINT_LINE
#endif
}

void SimulationResult::SetAnalysisType(int _analysis_type)
{
    analysis_type = _analysis_type;
}

int SimulationResult::GetAnalysisType() const
{
    return analysis_type;
}

