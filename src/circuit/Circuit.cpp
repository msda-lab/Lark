#include "Circuit.h"

Circuit::Circuit(const string &_name)
{
    name = _name;
    node_count = 0;
    has_gnd = false;
    ckt_instance = new CircuitInstance();
}

Circuit::~Circuit()
{
#ifdef DEBUG
    PRINT_LINE
#endif

    if(ckt_instance)
        delete ckt_instance;
}

void Circuit::ParseRes(const string &_name, const string &_n1, const string &_n2, double _r)
{
    bool is_exist = ckt_instance->IsDeviceExist(_name);
    if(!is_exist)
    {
        Node *n1 = GetParseNode(_n1);
        Node *n2 = GetParseNode(_n2);
        Resistor *res = new Resistor(_name, n1, n2, _r);
        ckt_instance->AddDevice(_name, res);

        ResistorModel *res_model = (ResistorModel*)ckt_instance->GetModel(RES_MODEL_TYPE);
        if(res_model == NULL)
        {
            res_model = new ResistorModel();
            ckt_instance->AddModel(RES_MODEL_TYPE, res_model);
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
    bool is_exist = ckt_instance->IsDeviceExist(_name);
    if(!is_exist)
    {
        Node *n1 = GetParseNode(_n1);
        Node *n2 = GetParseNode(_n2);
        Capacitor *cap = new Capacitor(_name, n1, n2, _c);
        ckt_instance->AddDevice(_name, cap);

        CapacitorModel *cap_model = (CapacitorModel*)ckt_instance->GetDevice(CAP_MODEL_TYPE);
        if(cap_model == NULL)
        {
            cap_model = new CapacitorModel();
            ckt_instance->AddModel(CAP_MODEL_TYPE, cap_model);
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
    bool is_exist = ckt_instance->IsDeviceExist(_name);
    if(!is_exist)
    {
        Node *n1 = GetParseNode(_n1);
        Node *n2 = GetParseNode(_n2);
        VSource *vsrc = new VSource(_name, n1, n2);
        vsrc->SetDCValue(_dc);
        vsrc->SetACValue(_ac);
        ckt_instance->AddDevice(_name, vsrc);

        VSourceModel *vsrc_model = (VSourceModel*)ckt_instance->GetModel(VSRC_MODEL_TYPE);
        if(vsrc_model == NULL)
        {
            vsrc_model = new VSourceModel();
            ckt_instance->AddModel(VSRC_MODEL_TYPE, vsrc_model);
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
    bool is_exist = ckt_instance->IsDeviceExist(_name);
    if(!is_exist)
    {
        Node *n1 = GetParseNode(_n1);
        Node *n2 = GetParseNode(_n2);
        ISource *isrc = new ISource(_name, n1, n2);
        isrc->SetDCValue(_dc);
        isrc->SetACValue(_ac);
        ckt_instance->AddDevice(_name, isrc);

        ISourceModel *isrc_model = (ISourceModel*)ckt_instance->GetModel(ISRC_MODEL_TYPE);
        if(isrc_model == NULL)
        {
            isrc_model = new ISourceModel();
            ckt_instance->AddModel(ISRC_MODEL_TYPE, isrc_model);
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
    Node *node = ckt_instance->GetNode(_name);
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
        ckt_instance->AddNode(_name, node);
    }
    return node;
}

Device *Circuit::GetDevice(const string &_name) const
{
    Device *device = ckt_instance->GetDevice(_name);
    if(device == NULL)
    {
        cout << "Cannot find " << _name << endl;
    }
    return device;
}

void Circuit::LoadSweepDC(Device *_src, double _src_value)
{

}

void Circuit::LoadDC()
{

}

void Circuit::Setup(int _analysis_type)
{
    switch(_analysis_type)
    {
        case DC_ANALYSIS_TYPE:
            break;
        case AC_ANALYSIS_TYPE:
            break;
        case TRAN_ANALYSIS_TYPE: 
            break;
        default:
            break;
    }
    

}

void Circuit::Reset()
{

}

void Circuit::ResetMatrix()
{

}

void Circuit::ResetRHS()
{

}

void Circuit::PrintAllDevice() const
{
    ckt_instance->PrintAllDevice();
}

void Circuit::PrintAllNode() const
{
    ckt_instance->PrintAllModel();
}

void Circuit::PrintAllModel() const
{
    ckt_instance->PrintAllNode();
}
