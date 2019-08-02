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

void ISourceModel::Setup(Numeric *_numeric, int _analysis_type)
{
}
