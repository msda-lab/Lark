#ifndef VSOURCE_H

#include "DeviceBase.h"

class VSource : public Device 
{
    public: 
        VSource(const string &_name, Node *_n1, Node *_n2);
        ~VSource();
    
    public: 
        void Setup();
        void SetupDC();
        void SetupAC();
        void SetupTRAN();

        void Load();
        void LoadDC();
        void LoadAC();
        void LoadTRAN();

        void SetDCValue(double _dc_value);
        double GetDCValue() const;
        void SetACValue(Complex _ac_value);
        Complex GetACValue() const;
    
    private: 
        double dc_value;
        Complex ac_value;

        Node *n1;
        Node *n2;
};

#define VSOURCE_H
#endif // VSOURCE_H
