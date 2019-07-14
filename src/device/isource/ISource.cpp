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

void ISource::Setup()
{

}

void ISource::SetupDC()
{

}

void ISource::SetupAC()
{

}

void ISource::SetupTRAN()
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

void ISource::LoadTRAN()
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







