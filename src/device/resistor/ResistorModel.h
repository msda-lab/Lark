#ifndef RESISTOR_MODEL_H
#define RESISTOR_MODEL_H

#include "DeviceBase.h"
#include "Resistor.h"

#include <vector>

using std::vector;

class ResistorModel : public Model
{
    public: 
        ResistorModel();
        ~ResistorModel();
    
    public: 
        void Setup(Numeric *_numeric, int _analysis_type);
        void LoadDC();
        void LoadAC(double _omega);
        void LoadTran(double _t, double _h, bool _iter);

        void AddInst(Resistor *_res);
    private: 
        vector<Resistor*> res_list;
};

#endif //RESISTOR_MODEL_H
