#include "ResistorModel.h"

ResistorModel::ResistorModel()
    : Model(RES_MODEL_TYPE)
{

}

ResistorModel::~ResistorModel()
{
#ifdef DEBUG
    PRINT_LINE
#endif
    res_list.clear();
}

void ResistorModel::LoadDC()
{

}

void ResistorModel::LoadAC(double _omega)
{

}

void ResistorModel::LoadTran(double _t, double _h, bool _iter)
{

}

void ResistorModel::AddInst(Resistor *_res)
{
    res_list.push_back(_res);
    ++ device_count;
}

