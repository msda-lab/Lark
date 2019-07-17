#include "VSource.h"
#include "Util.h"

VSource::VSource(const string &_name, Node *_n1, Node *_n2)
    : Device(_name)
{
    n1 = _n1;
    n2 = _n2;
    SetType(VSOURCE_TYPE);
}

VSource::~VSource()
{

}

void VSource::Setup()
{

}

void VSource::SetupDC()
{

}

void VSource::SetupAC()
{

}

void VSource::SetupTran()
{

}

void VSource::Load()
{

}

void VSource::LoadDC()
{

}

void VSource::LoadAC()
{

}

void VSource::LoadTran()
{

}

void VSource::SetDCValue(double _dc_value)
{
    dc_value = _dc_value;
}

double VSource::GetDCValue() const
{
    return dc_value;
}

void VSource::SetACValue(Complex _ac_value)
{
    ac_value = _ac_value;
}

Complex VSource::GetACValue() const
{
    return ac_value;
}
