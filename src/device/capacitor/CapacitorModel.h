#ifndef CAPACITOR_MODEL_H
#define CAPACITOR_MODEL_H

#include "DeviceBase.h"
#include "Capacitor.h"

#include <vector>

using std::vector;

class CapacitorModel : public Model 
{
    public: 
        CapacitorModel();
        ~CapacitorModel();
    
    public: 
        void SetupDC(Numeric *_numeric);
        void SetupAC(Numeric *_numeric);
        void SetupTran(Numeric *_numeric);

        void LoadDC();
        void LoadAC(double _omega);
        void LoadTran(double _t, double _h, bool _iter);

        void AddInst(Capacitor *_cap);
    private: 
        vector<Capacitor*> cap_list;

};

#endif // CAPACITOR_MODEL_H
