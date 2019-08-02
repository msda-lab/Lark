#include "Capacitor.h"

Capacitor::Capacitor(const string &_name, Node *_n1, Node *_n2, double _c)
    : Device(_name)
{
    n1 = _n1;
    n2 = _n2;
    c = _c;
    SetType(CAPACITOR_TYPE);
}

Capacitor::~Capacitor()
{

}

void Capacitor::SetupDC(Numeric *_numeric)
{
    // do nothing

}

void Capacitor::SetupAC(Numeric *_numeric)
{
    // has to allocate new memory

}

void Capacitor::SetupTran(Numeric *_numeric)
{

}

void Capacitor::Load()
{

}

void Capacitor::LoadAC()
{

}

void Capacitor::LoadTran()
{

}

void Capacitor::SetACVoltage(Complex _ac_voltage)
{
    ac_voltage = _ac_voltage;
}

Complex Capacitor::GetACVoltage() const
{
    return ac_voltage;
}

void Capacitor::SetACCurrent(Complex _ac_current)
{
    ac_current = _ac_current;
}

Complex Capacitor::GetACCurrent() const
{
    return ac_current;
}
