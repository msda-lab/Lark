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

void ResistorModel::Setup(Numeric *_numeric, int _analysis_type)
{
    switch(_analysis_type)
    {
        case DC_ANALYSIS_TYPE:
            for(size_t i = 0; i < res_list.size(); ++ i)
                res_list[i]->SetupDC(_numeric);
            break;

        case AC_ANALYSIS_TYPE:
            for(size_t i = 0; i < res_list.size(); ++ i)
                res_list[i]->SetupAC(_numeric);
            break;

        case TRAN_ANALYSIS_TYPE:
            for(size_t i = 0; i < res_list.size(); ++ i)
                res_list[i]->SetupTran(_numeric);
            break;

        default:
            cout << "Unknown analysis type" << endl;
    }
}


