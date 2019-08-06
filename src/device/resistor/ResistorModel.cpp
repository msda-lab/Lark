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
    for(size_t i = 0; i < res_list.size(); ++ i)
        res_list[i]->LoadDC();
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

void ResistorModel::SetupDC(Numeric *_numeric)
{
    for(size_t i = 0; i < res_list.size(); ++ i)
        res_list[i]->SetupDC(_numeric);
}

void ResistorModel::SetupAC(Numeric *_numeric)
{
    for(size_t i = 0; i < res_list.size(); ++ i)
        res_list[i]->SetupAC(_numeric);
}

void ResistorModel::SetupTran(Numeric *_numeric)
{
    for(size_t i = 0; i < res_list.size(); ++ i)
        res_list[i]->SetupTran(_numeric);
}


