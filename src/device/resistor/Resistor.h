#ifndef RESISTOR_H
#define RESISTOR_H

#include "DeviceBase.h"

class Resistor : public Device
{
    public: 
        Resistor(const string &_name, Node *_n1, Node *_n2, double _r);
        ~Resistor();
    public:  
        void SetupDC();
        void SetupAC();
        void SetupTRAN();

        void LoadDC();
        void LoadAC();
        void LoadTRAN();

        void SetDCVoltage(double _dc_voltage);
        double GetDCVoltage() const;
        void SetDCCurrent(double _dc_current);
        double GetDCCurrent() const;
        void SetACVoltage(Complex _ac_voltage);
        Complex GetACVoltage() const;
        void SetACCurrent(Complex _ac_current);
        Complex GetACCurrent() const;
        

    private:  
        double r;
        Node *n1;
        Node *n2;
        double dc_voltage;
        double dc_current;
        Complex ac_voltage;
        Complex ac_current;
};

#endif // RESISTOR_H