#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "DeviceBase.h"

class Capacitor : public Device 
{
    public: 
        Capacitor(const string &_name, Node *_n1, Node *_n2, double _c);
        ~Capacitor();
    
    public: 
        void SetupDC(Numeric *_numeric);
        void SetupTran(Numeric *_numeric);
        void SetupAC(Numeric *_numeric);

        void Load();
        void LoadAC();
        void LoadTran();

        void SetACVoltage(Complex _ac_voltage);
        Complex GetACVoltage() const;
        void SetACCurrent(Complex _ac_current);
        Complex GetACCurrent() const;

    private: 
        double c;
        Node *n1;
        Node *n2;
        Complex ac_voltage;
        Complex ac_current;

};


#endif //CAPACITOR
