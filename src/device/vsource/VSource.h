#ifndef VSOURCE_H
#define VSOURCE_H

#include "DeviceBase.h"

class VSource : public Device 
{
    public: 
        VSource(const string &_name, Node *_n1, Node *_n2);
        ~VSource();
    
    public: 
        void SetupDC(Numeric *_numeric);
        void SetupAC(Numeric *_numeric);
        void SetupTran(Numeric *_numeric);

        void LoadDC();
        void LoadSweepDC(double _value);
        void LoadAC();
        void LoadTran();

        void SetDCValue(double _dc_value);
        double GetDCValue() const;
        void SetACValue(Complex _ac_value);
        Complex GetACValue() const;
    
    private: 
        double dc_value;
        Complex ac_value;
        int n_pos;
        int n_neg;
        int branch_id;

        Node *n1;
        Node *n2;
};

#endif // VSOURCE_H
