#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <vector>

#include "DeviceBase.h"
#include "Circuit.h"
#include "SimulationResult.h"

using std::vector;

class Analysis
{
    public: 
        Analysis(int _analysis_type);
        virtual ~Analysis();
    
    public:
        virtual void    DoAnalysis() = 0;
        int             GetAnalysisType() const;
        void            SetCktPtr(Circuit *_ckt);
    
    protected: 
        double          tolerance;
        int             analysis_type;
        int             max_iteration;

        Circuit         *ckt;
        SimulationResult *sim_res;

};

#endif //ANALYSIS_H
