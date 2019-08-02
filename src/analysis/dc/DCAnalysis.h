#ifndef DC_ANALYSIS_H
#define DC_ANALYSIS_H

#include "Analysis.h"

class DCAnalysis : public Analysis 
{
    public: 
        DCAnalysis(double _start, double _end, double _incr);
        ~DCAnalysis();
    
    public: 
        void DoAnalysis();
        void DoSinglePointAnalysis();
        void SetSweepSrc(Device *_src);
    
    private: 
        void Reload(double _src_value);

        double start;
        double end;
        double incr;
        Device *sweep_src;

};

#endif // DC_ANALYSIS_H
