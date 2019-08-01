#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <vector>

#include "DeviceBase.h"
#include "Circuit.h"

using std::vector;

class Analysis
{
    public: 
        Analysis(int _analysis_type);
        ~Analysis();
    
    public:
        virtual void DoAnalysis() = 0;
        int GetAnalysisType() const;
        void SetCktPtr(Circuit *_ckt);
    
    protected: 
        double tolerance;
        int analysis_type;
        int max_iteration;

        Circuit *ckt;
};

#endif //ANALYSIS_H
