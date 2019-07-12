#include "Circuit.h"

Circuit::Circuit(const string &_name)
{
    name = _name;
    node_count = 0;
    has_gnd = false;
    node_table = new SymbTable<string, Node*>(&HashFunctions::StringHash, &Node::Equal);
    device_table = new SymbTable<string, Device*>(&HashFunctions::StringHash, &Device::Equal);
}

Circuit::~Circuit()
{

}

void Circuit::ParseRes(const string &_name, const string &_n1, const string &_n2, double _r)
{
    // cout << "Res " << _name << ": n1=" << _n1 << " n2=" << _n2 << " value=" << _r << endl;
    bool is_exist = device_table->Contains(_name);
    if(!is_exist)
    {
        Node *n1 = GetParseNode(_n1);
        Node *n2 = GetParseNode(_n2);
        Resistor *res = new Resistor(_name, n1, n2, _r);
        device_table->Insert(_name, res);
    }
    else
    {
        cout << "[ERROR! Redifine resistor of " << _name << "]" << endl;
    }
}

void Circuit::ParseCap(const string &_name, const string &_n1, const string &_n2, double _c)
{
    // cout << "Cap " << _name << ": n1=" << _n1 << " n2=" << _n2 << " value=" << _c << endl;
    bool is_exist = device_table->Contains(_name);
    if(!is_exist)
    {
        Node *n1 = GetParseNode(_n1);
        Node *n2 = GetParseNode(_n2);
        Capacitor *cap = new Capacitor(_name, n1, n2, _c);
        device_table->Insert(_name, cap);
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
    // cout << "VSource name=" << _name << " n1=" << _n1 << " n2=" << _n2 << " dc=" << _dc << endl;
    bool is_exist = device_table->Contains(_name);
    if(!is_exist)
    {
        Node *n1 = GetParseNode(_n1);
        Node *n2 = GetParseNode(_n2);
        VSource *vsrc = new VSource(_name, n1, n2);
        vsrc->SetDCValue(_dc);
        vsrc->SetACValue(_ac);
        device_table->Insert(_name, vsrc);
    }
    else
    {
        cout << "[ERROR! Redifine voltage source of " << _name << "]" << endl;
    }

}


void Circuit::ParseISource(const string &_name, const string &_n1, const string &_n2, double _dc)
{
    cout << "ISource name=" << _name << " n1=" << _n1 << " n2=" << _n2 << " dc=" << _dc << endl;
}

Node* Circuit::GetParseNode(const string &_name)
{

    Node *node = (Node*)node_table->Find(_name);
    if(node == NULL)
    {
        if(_name == "GND" || _name == "gnd" || _name == "0")
        {
            has_gnd = true;
            node = new Node(_name);
            node->SetType(GND_TYPE);
            node->SetLocation(0);
        }
        else{
            node = new Node(_name);
            node->SetType(NORMAL_TYPE);
            ++ node_count;
            node->SetLocation(node_count);
        }
        node_table->Insert(_name, node);
    }
    return node;
}


void Circuit::PrintAllDevice() const
{
    device_table->Print();
}

void Circuit::PrintAllNode() const
{
    node_table->Print();
}
