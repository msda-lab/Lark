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

void VSourceModel::AddInst(VSource *_vsrc)
{
    vsrc_list.push_back(_vsrc);
    ++ device_count;
}

void VSourceModel::Setup(Numeric *_numeric, int _analysis_type)
{
    switch(_analysis_type)
    {
        case DC_ANALYSIS_TYPE:
            for(size_t i = 0; i < vsrc_list.size(); ++ i)
                vsrc_list[i]->SetupDC(_numeric);
            break;

        case AC_ANALYSIS_TYPE:
            for(size_t i = 0; i < vsrc_list.size(); ++ i)
                vsrc_list[i]->SetupAC(_numeric);
            break;

        case TRAN_ANALYSIS_TYPE:
            for(size_t i = 0; i < vsrc_list.size(); ++ i)
                vsrc_list[i]->SetupTran(_numeric);
            break;

        default:
            cout << "Unknown analysis type" << endl;
    }
}
