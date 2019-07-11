#include "Circuit.h"

Circuit::Circuit(const string &_name)
{
    name = _name;
    nodeTable = new SymbTable<string, Node*>(&HashFunctions::StringHash, &Node::Equal);
    // deviceTable = new SymbTable<string, Device*>(&HashFunctions::StringHash, &Device::Equal);
}

Circuit::~Circuit()
{

}

void Circuit::parseRes(const string &_name, const string &_n1, const string &_n2, double _r)
{
    cout << "Res " << _name << ": n1=" << _n1 << " n2=" << _n2 << " value=" << _r << endl;

}

void Circuit::parseCap(const string &_name, const string &_n1, const string &_n2, double _c)
{
    cout << "Cap " << _name << ": n1=" << _n1 << " n2=" << _n2 << " value=" << _c << endl;

}

void Circuit::parseInd(const string &_name, const string &_n1, const string &_n2, double _l)
{
    cout << "Ind " << _name << ": n1=" << _n1 << " n2=" << _n2 << " value=" << _l << endl;

}

void Circuit::parseVSource(const string &_name, const string &_n1, const string &_n2, double _dc)
{
    cout << "VSource name=" << _name << " n1=" << _n1 << " n2=" << _n2 << " dc=" << _dc << endl;
}

void Circuit::parseISource(const string &_name, const string &_n1, const string &_n2, double _dc)
{
    cout << "ISource name=" << _name << " n1=" << _n1 << " n2=" << _n2 << " dc=" << _dc << endl;
}

void Circuit::parseNode(const string &_name)
{

}
