#include "Resistor.h"

Resistor::Resistor(const string &_name, Node *_n1, Node *_n2, double _r)
    : Device(_name)
{
    r = _r;
    n1 = _n1;
    n2 = _n2;
}

Resistor::~Resistor()
{

}

void Resistor::SetupDC()
{

}

void Resistor::SetupAC()
{

}

void Resistor::SetupTRAN()
{

}

void Resistor::LoadDC()
{

}

void Resistor::LoadAC()
{

}

void Resistor::LoadTRAN()
{

}

void Resistor::SetDCVoltage(double _dc_voltage)
{
    dc_voltage = _dc_voltage;
}

double Resistor::GetDCVoltage() const
{
    return dc_voltage;
}

void Resistor::SetDCCurrent(double _dc_current)
{
    dc_current = _dc_current;
}

double Resistor::GetDCCurrent() const
{
    return dc_current;
}

void Resistor::SetACVoltage(Complex _ac_voltage)
{
    ac_voltage = _ac_voltage;
}

Complex Resistor::GetACVoltage() const
{
    return ac_voltage;
}

void Resistor::SetACCurrent(Complex _ac_current)
{
    ac_current = _ac_current;
}

Complex Resistor::GetACCurrent() const
{
    return ac_current;
}
