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

void CapacitorModel::Setup(Numeric *_numeric, int _analysis_type)
{
    switch(_analysis_type)
    {
        case DC_ANALYSIS_TYPE:
            for(size_t i = 0; i < cap_list.size(); ++ i)
                cap_list[i]->SetupDC(_numeric);
            break;

        case AC_ANALYSIS_TYPE:
            for(size_t i = 0; i < cap_list.size(); ++ i)
                cap_list[i]->SetupAC(_numeric);
            break;

        case TRAN_ANALYSIS_TYPE:
            for(size_t i = 0; i < cap_list.size(); ++ i)
                cap_list[i]->SetupTran(_numeric);
            break;

        default:
            cout << "Unknown analysis type" << endl;
    }
}
