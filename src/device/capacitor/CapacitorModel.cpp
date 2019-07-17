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

