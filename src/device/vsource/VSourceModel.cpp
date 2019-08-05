#include "VSourceModel.h"

VSourceModel::VSourceModel()
    : Model(VSRC_MODEL_TYPE)
{

}

VSourceModel::~VSourceModel()
{

}

void VSourceModel::LoadDC(Numeric *_numeric)
{

}

void VSourceModel::LoadAC(double _omega)
{

}

void VSourceModel::LoadTran(double _t, double _h, bool _iter)
{

}

void VSourceModel::AddInst(VSource *_vsrc)
{
    vsrc_list.push_back(_vsrc);
    ++ device_count;
}

void VSourceModel::SetupDC(Numeric *_numeric)
{
    for(size_t i = 0; i < vsrc_list.size(); ++ i)
        vsrc_list[i]->SetupDC(_numeric);
}

void VSourceModel::SetupAC(Numeric *_numeric)
{
    for(size_t i = 0; i < vsrc_list.size(); ++ i)
        vsrc_list[i]->SetupDC(_numeric);
}

void VSourceModel::SetupTran(Numeric *_numeric)
{
    for(size_t i = 0; i < vsrc_list.size(); ++ i)
        vsrc_list[i]->SetupDC(_numeric);
}
