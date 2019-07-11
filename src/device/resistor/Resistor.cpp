#include "Resistor.h"

Resistor::Resistor(const string &_name, Node *_n1, Node *_n2, double _r)
    : Device(_name)
{
    this->r = _r;
    this->n1 = _n1;
    this->n2 = _n2;
}

Resistor::~Resistor()
{

}

void Resistor::setupDC()
{

}

void Resistor::setupAC()
{

}

void Resistor::setupTRAN()
{

}

void Resistor::loadDC()
{

}

void Resistor::loadAC()
{

}

void Resistor::loadTRAN()
{

}

void Resistor::setDCVoltage(double _dcVoltage)
{
    dcVoltage = _dcVoltage;
}

double Resistor::getDCVoltage() const
{
    return dcVoltage;
}

void Resistor::setDCCurrent(double _dcCurrent)
{
    dcCurrent = _dcCurrent;
}

double Resistor::getDCCurrent() const
{
    return dcCurrent;
}

void Resistor::setACVoltage(Complex _acVoltage)
{
    acVoltage = _acVoltage;
}

Complex Resistor::getACVoltage() const
{
    return acVoltage;
}

void Resistor::setACCurrent(Complex _acCurrent)
{
    acCurrent = _acCurrent;
}

Complex Resistor::getACCurrent() const
{
    return acCurrent;
}
