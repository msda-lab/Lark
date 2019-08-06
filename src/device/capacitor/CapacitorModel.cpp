#include "CapacitorModel.h"

CapacitorModel::CapacitorModel()
    : Model(CAP_MODEL_TYPE)
{

}

CapacitorModel::~CapacitorModel()
{

}

void CapacitorModel::LoadDC()
{

}

void CapacitorModel::LoadAC(double _omega)
{

}

void CapacitorModel::LoadTran(double _t, double _h, bool _iter)
{

}

void CapacitorModel::AddInst(Capacitor *_cap)
{
    cap_list.push_back(_cap);
    ++ device_count;
}

void CapacitorModel::SetupDC(Numeric *_numeric)
{
    for(size_t i = 0; i < cap_list.size(); ++ i)
        cap_list[i]->SetupDC(_numeric);
}

void CapacitorModel::SetupAC(Numeric *_numeric)
{
    for(size_t i = 0; i < cap_list.size(); ++ i)
        cap_list[i]->SetupAC(_numeric);
}

void CapacitorModel::SetupTran(Numeric *_numeric)
{
    for(size_t i = 0; i < cap_list.size(); ++ i)
        cap_list[i]->SetupTran(_numeric);
}
