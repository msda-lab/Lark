#include "ISource.h"

#include "Util.h"

ISource::ISource(const string &_name, Node *_n1, Node *_n2)
    : Device(_name)
{
    n1 = _n1;
    n2 = _n2;
    n_pos = n1->GetLocation();
    n_neg = n2->GetLocation();
    SetType(ISOURCE_TYPE);
}

ISource::~ISource()
{

}

void ISource::SetupDC(Numeric *_numeric)
{
    // do nothing
    numeric = _numeric;

}

void ISource::SetupAC(Numeric *_numeric)
{
    numeric = _numeric;

}

void ISource::SetupTran(Numeric *_numeric)
{
    numeric = _numeric;
}

void ISource::LoadDC()
{
    /*          RHS
     *
     * N+       -I
     *
     * N-        I
     *
     */

    numeric->AddVectorValue(n_pos, -1 * dc_value);
    numeric->AddVectorValue(n_neg,  1 * dc_value);
}

void ISource::LoadSweepDC(double _value)
{
    numeric->AddVectorValue(n_pos, -1 * (_value - dc_value));
    numeric->AddVectorValue(n_neg,  1 * (_value - dc_value));
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







