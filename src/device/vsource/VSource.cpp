#include "VSource.h"
#include "Util.h"

VSource::VSource(const string &_name, Node *_n1, Node *_n2)
    : Device(_name)
{
    n1 = _n1;
    n2 = _n2;
    n_pos = n1->GetLocation();
    n_neg = n2->GetLocation();
    SetType(VSOURCE_TYPE);
    branch_id = 0;
}

VSource::~VSource()
{

}

void VSource::SetupDC(Numeric *_numeric)
{
    // Set branch id to the last index of matrix
    numeric = _numeric;

    branch_id = numeric->GetDimension();

    numeric->AddMatrixRow(1);
    numeric->AddMatrixColumn(1);
    numeric->AddVectorRow(1);

    numeric->AddDimension(1);
}

void VSource::SetupAC(Numeric *_numeric)
{
    numeric = _numeric;
}

void VSource::SetupTran(Numeric *_numeric)
{
    numeric = _numeric;

}

void VSource::LoadDC()
{
    /*          N+         N-         Branch           RHS
     *
     * N+       0          0            1               0
     *
     * N-       0          0            -1              0
     *
     * Branch   1          -1           0               V
     *
     */

    numeric->AddMatrixValue(n_pos, branch_id, 1);
    numeric->AddMatrixValue(n_neg, branch_id, -1);
    numeric->AddMatrixValue(branch_id, n_pos, 1);
    numeric->AddMatrixValue(branch_id, n_neg, -1);

    numeric->AddVectorValue(branch_id, dc_value);
}

void VSource::LoadSweepDC(double _value)
{
    numeric->AddVectorValue(branch_id, _value - dc_value);
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
