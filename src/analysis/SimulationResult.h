#ifndef SIMULATION_RESULT_H
#define SIMULATION_RESULT_H

class SimulationResult
{
    public:
        SimulationResult();
        SimulationResult(int _analysis_type);
        ~SimulationResult();

    public:
        void    SetAnalysisType(int _analysis_type);
        int     GetAnalysisType() const; 

    private:
        int     analysis_type;
};

#endif
