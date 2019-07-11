#ifndef RESISTOR_H
#define RESISTOR_H

#include "DeviceBase.h"

class Resistor : public Device
{
    public: 
        Resistor(const string &_name, Node *_n1, Node *_n2, double _r);
        ~Resistor();
    public:  
        void setupDC();
        void setupAC();
        void setupTRAN();

        void loadDC();
        void loadAC();
        void loadTRAN();

        void setDCVoltage(double _dcVoltage);
        double getDCVoltage() const;
        void setDCCurrent(double _dcCurrent);
        double getDCCurrent() const;
        void setACVoltage(Complex _acVoltage);
        Complex getACVoltage() const;
        void setACCurrent(Complex _acCurrent);
        Complex getACCurrent() const;
        

    private:  
        double r;
        Node *n1;
        Node *n2;
        double dcVoltage;
        double dcCurrent;
        Complex acVoltage;
        Complex acCurrent;
};

#endif // RESISTOR_H