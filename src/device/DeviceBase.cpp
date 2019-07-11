#include "DeviceBase.h"

/**************************Device class***************** */

Device::Device(const string &_name)
{

}

Device::~Device()
{

}

void Device::setName(const string &_name)
{
    this->name = _name;
}

string Device::getName() const 
{
    return name;
}

bool Device::Equal(const string &_name, const Device *_dev)
{
    return _name == _dev->name;
}

void Device::setup()
{
    setupDC();
    // setupAC();
    // setuoTRAN();
}

void Device::load()
{
    loadDC();
    // loadAC();
    // loadTRAN();

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

void Node::setDCVoltage(double _dc)
{
    dcVoltage = _dc;
}

double Node::getDCVoltage() const
{
    return dcVoltage;
}

void Node::setACVoltage(Complex _ac)
{
    acVoltage = _ac;
}

Complex Node::getACVoltage() const
{
    return acVoltage;
}

void Node::setName(const string &_name)
{
    this->name = _name;
}

string Node::getName() const{
    return name;
}
