#include "DeviceBase.h"

/**************************Device class***************** */

Device::Device(const string &_name)
{

}

Device::~Device()
{

}

void Device::SetName(const string &_name)
{
    this->name = _name;
}

string Device::GetName() const 
{
    return name;
}

bool Device::Equal(const string &_name, const Device *_dev)
{
    return _name == _dev->name;
}

void Device::Setup()
{
    SetupDC();
    // SetupAC();
    // SetuoTRAN();
}

void Device::Load()
{
    LoadDC();
    // LoadAC();
    // LoadTRAN();

}

/***************************Node class********************** */

Node::Node(const string &_name)
{
    this->name = _name;
    location = 0;
}

Node::~Node()
{

}

bool Node::Equal(const string &_name, Node *_node)
{
    return _name == _node->name;

}

void Node::SetDCVoltage(double _dc)
{
    dc_voltage = _dc;
}

double Node::GetDCVoltage() const
{
    return dc_voltage;
}

void Node::SetACVoltage(Complex _ac)
{
    ac_voltage = _ac;
}

Complex Node::GetACVoltage() const
{
    return ac_voltage;
}

void Node::SetName(const string &_name)
{
    name = _name;
}

string Node::GetName() const{
    return name;
}
