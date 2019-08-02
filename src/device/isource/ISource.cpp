#include "ISource.h"

#include "Util.h"

ISource::ISource(const string &_name, Node *_n1, Node *_n2)
    : Device(_name)
{
    n1 = _n1;
    n2 = _n2;
    SetType(ISOURCE_TYPE);
}

ISource::~ISource()
{

}

void ISource::SetupDC(Numeric *_numeric)
{

}

void ISource::SetupAC(Numeric *_numeric)
{

}

void ISource::SetupTran(Numeric *_numeric)
{

}

void ISource::Load()
{

}

void ISource::LoadDC()
{

}

void ISource::LoadAC()
{

}

void ISource::LoadTran()
{

}

void ISource::SetDCValue(double _dc_value)
{
    dc_value = _dc_value;
}

double ISource::GetDCValue() const
{
    return dc_value;
}

void ISource::SetACValue(Complex _ac_value)
{
    ac_value = _ac_value;
}

Complex ISource::GetACValue() const
{
    return ac_value;
}







