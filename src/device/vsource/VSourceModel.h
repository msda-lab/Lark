#ifndef VSOURCE_MODEL_H
#define VSOURCE_MODEL_H

#include "DeviceBase.h"
#include "VSource.h"

#include <vector>

using std::vector;

class VSourceModel : public Model
{
    public: 
        VSourceModel();
        ~VSourceModel();
    
    public: 
        void SetupDC(Numeric *numeric);
        void SetupAC(Numeric *numeric);
        void SetupTran(Numeric *numeric);

        void LoadDC(Numeric *_numeric);
        void LoadAC(double _omega);
        void LoadTran(double _t, double _h, bool _iter);

        void AddInst(VSource *_vsrc);
    private: 
        vector<VSource*> vsrc_list;
};

#endif // VSOURCE_MODEL_H
