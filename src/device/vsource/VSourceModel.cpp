#include "VSourceModel.h"

VSourceModel::VSourceModel()
    : Model(VSRC_MODEL_TYPE)
{

}

VSourceModel::~VSourceModel()
{

}

void VSourceModel::LoadDC()
{

}

void VSourceModel::LoadAC(double _omega)
{

}

void VSourceModel::LoadTran(double _t, double _h, bool _iter)
{

}

void VSourceModel::AddVnst(VSource *_vsrc)
{
    vsrc_list.push_back(_vsrc);
    ++ device_count;
}
