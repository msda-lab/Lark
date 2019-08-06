#include "ISourceModel.h"

ISourceModel::ISourceModel()
    : Model(ISRC_MODEL_TYPE)
{

}

ISourceModel::~ISourceModel()
{

}

void ISourceModel::LoadDC()
{

}

void ISourceModel::LoadAC(double _omega)
{

}

void ISourceModel::LoadTran(double _t, double _h, bool _iter)
{

}

void ISourceModel::AddInst(ISource *_isrc)
{
    isrc_list.push_back(_isrc);
    ++ device_count;
}

void ISourceModel::SetupDC(Numeric *_numeric)
{
    for(size_t i = 0; i < isrc_list.size(); ++i)
        isrc_list[i]->SetupDC(_numeric);
}

void ISourceModel::SetupAC(Numeric *_numeric)
{
    for(size_t i = 0; i < isrc_list.size(); ++i)
        isrc_list[i]->SetupAC(_numeric);
}

void ISourceModel::SetupTran(Numeric *_numeric)
{
    for(size_t i = 0; i < isrc_list.size(); ++i)
        isrc_list[i]->SetupTran(_numeric);
}
