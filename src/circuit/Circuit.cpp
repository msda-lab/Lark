#include "Circuit.h"

Circuit::Circuit(const string &_name)
{
    name = _name;
    node_count = 0;
    has_gnd = false;
    ckt_inst = new CircuitInstance();
}

Circuit::~Circuit()
{
#ifdef DEBUG
    PRINT_LINE
#endif

    if(ckt_inst)
    {
        delete ckt_inst;
        ckt_inst = NULL;
    }

    if(numeric)
    {
        delete numeric;
        numeric = NULL;
    }
}

/******************************** Parse and Build Instance ********************************/

void Circuit::ParseRes(const string &_name, const string &_n1, const string &_n2, double _r)
{
    bool is_exist = ckt_inst->IsDeviceExist(_name);
    if(!is_exist)
    {
        Node *n1 = GetParseNode(_n1);
        Node *n2 = GetParseNode(_n2);
        Resistor *res = new Resistor(_name, n1, n2, _r);
        ckt_inst->AddDevice(_name, res);

        ResistorModel *res_model = (ResistorModel*)ckt_inst->GetModel(RES_MODEL_TYPE);
        if(res_model == NULL)
        {
            res_model = new ResistorModel();
            ckt_inst->AddModel(RES_MODEL_TYPE, res_model);
        }
        res_model->AddInst(res);
    }
    else
    {
        cout << "[ERROR! Redifine resistor of " << _name << "]" << endl;
    }
}

void Circuit::ParseCap(const string &_name, const string &_n1, const string &_n2, double _c)
{
    bool is_exist = ckt_inst->IsDeviceExist(_name);
    if(!is_exist)
    {
        Node *n1 = GetParseNode(_n1);
        Node *n2 = GetParseNode(_n2);
        Capacitor *cap = new Capacitor(_name, n1, n2, _c);
        ckt_inst->AddDevice(_name, cap);

        CapacitorModel *cap_model = (CapacitorModel*)ckt_inst->GetDevice(CAP_MODEL_TYPE);
        if(cap_model == NULL)
        {
            cap_model = new CapacitorModel();
            ckt_inst->AddModel(CAP_MODEL_TYPE, cap_model);
        }
        cap_model->AddInst(cap);
    }
    else
    {
        cout << "[ERROR! Redifine capacitor of " << _name << "]" << endl;
    }

}

void Circuit::ParseInd(const string &_name, const string &_n1, const string &_n2, double _l)
{
    cout << "Ind " << _name << ": n1=" << _n1 << " n2=" << _n2 << " value=" << _l << endl;

}

void Circuit::ParseVSource(const string &_name, const string &_n1, const string &_n2, double _dc, Complex _ac)
{
    bool is_exist = ckt_inst->IsDeviceExist(_name);
    if(!is_exist)
    {
        Node *n1 = GetParseNode(_n1);
        Node *n2 = GetParseNode(_n2);
        VSource *vsrc = new VSource(_name, n1, n2);
        vsrc->SetDCValue(_dc);
        vsrc->SetACValue(_ac);
        ckt_inst->AddDevice(_name, vsrc);

        VSourceModel *vsrc_model = (VSourceModel*)ckt_inst->GetModel(VSRC_MODEL_TYPE);
        if(vsrc_model == NULL)
        {
            vsrc_model = new VSourceModel();
            ckt_inst->AddModel(VSRC_MODEL_TYPE, vsrc_model);
        }
        vsrc_model->AddInst(vsrc);
    }
    else
    {
        cout << "[ERROR! Redifine voltage source of " << _name << "]" << endl;
    }

}


void Circuit::ParseISource(const string &_name, const string &_n1, const string &_n2, double _dc, Complex _ac)
{
    bool is_exist = ckt_inst->IsDeviceExist(_name);
    if(!is_exist)
    {
        Node *n1 = GetParseNode(_n1);
        Node *n2 = GetParseNode(_n2);
        ISource *isrc = new ISource(_name, n1, n2);
        isrc->SetDCValue(_dc);
        isrc->SetACValue(_ac);
        ckt_inst->AddDevice(_name, isrc);

        ISourceModel *isrc_model = (ISourceModel*)ckt_inst->GetModel(ISRC_MODEL_TYPE);
        if(isrc_model == NULL)
        {
            isrc_model = new ISourceModel();
            ckt_inst->AddModel(ISRC_MODEL_TYPE, isrc_model);
        }
        isrc_model->AddInst(isrc);
    }
    else
    {
        cout << "[ERROR! Redifine current source of " << _name << "]" << endl;
    }
}

Node* Circuit::GetParseNode(const string &_name)
{
    Node *node = ckt_inst->GetNode(_name);
    if(node == NULL)
    {
        if(_name == "GND" || _name == "gnd" || _name == "0")
        {
            has_gnd = true;
            node = new Node(_name);
            node->SetType(GND_TYPE);
            node->SetLocation(0);
        }
        else 
        {
            node = new Node(_name);
            node->SetType(NORMAL_TYPE);
            ++ node_count;
            node->SetLocation(node_count);
        }
        ckt_inst->AddNode(_name, node);
    }
    return node;
}

Device *Circuit::GetDevice(const string &_name) const
{
    Device *device = ckt_inst->GetDevice(_name);
    if(device == NULL)
    {
        cout << "Cannot find " << _name << endl;
    }
    return device;
}

/********************************** Setup and Load Operations ******************************/

void Circuit::LoadSweepDC(Device *_src, double _src_value)
{
    _src->LoadSweepDC(_src_value);
}

void Circuit::LoadDC()
{
    for(auto it = ckt_inst->GetModelList().begin(); it != ckt_inst->GetModelList().end(); ++ it)
        it->second->LoadDC();
}

void Circuit::Setup(int _analysis_type)
{
    numeric = new Numeric(node_count, _analysis_type);
    for(auto it = ckt_inst->GetModelList().begin(); it != ckt_inst->GetModelList().end(); ++ it)
    {
        switch(_analysis_type)
        {
            case DC_ANALYSIS_TYPE:
                it->second->SetupDC(numeric);
                break;
            case AC_ANALYSIS_TYPE:
                it->second->SetupAC(numeric);
                break;
            case TRAN_ANALYSIS_TYPE:
                it->second->SetupTran(numeric);
                break;
            default: 
                cout << "Unknown analysis type" << endl;
        }
    }
}

void Circuit::Reset()
{
    ResetMatrix();
    ResetVector();
}

void Circuit::ResetMatrix()
{
    numeric->ResetMatrix();
}

void Circuit::ResetVector()
{
    numeric->ResetVector();
}

// do some operations before simulation

void Circuit::FinishParsing()
{
    // add one row and column to Matrix and Vector whether gnd exist
    node_count ++;
}

/******************************** Print and Destroy *****************************/

Numeric *Circuit::GetNumericPtr() const
{
    return numeric;
}

void Circuit::DestroyMatrixAndVector()
{
    if(numeric)
    {
        delete numeric;
        numeric = NULL;
    }
}

void Circuit::PrintAllDevice() const
{
    ckt_inst->PrintAllDevice();
}

void Circuit::PrintAllNode() const
{
    ckt_inst->PrintAllModel();
}

void Circuit::PrintAllModel() const
{
    ckt_inst->PrintAllNode();
}
