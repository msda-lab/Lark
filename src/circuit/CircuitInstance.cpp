#include "CircuitInstance.h"

CircuitInstance::CircuitInstance()
{
}

CircuitInstance::~CircuitInstance()
{
#ifdef DEBUG
    PRINT_LINE
#endif

    map<string, Device*>::iterator dit;
    for(dit = device_list.begin(); dit != device_list.end(); ++ dit)
    {
        delete dit->second;
        dit->second = NULL;
    }
    device_list.clear();

    map<string, Model*>::iterator mit;
    for(mit = model_list.begin(); mit != model_list.end(); ++ mit)
    {
        delete mit->second;
        mit->second = NULL;
    }
    model_list.clear();

    map<string, Node*>::iterator nit;
    for(nit = node_list.begin(); nit != node_list.end(); ++ nit)
    {
        delete nit->second;
        nit->second = NULL;
    }
    node_list.clear();
}

void CircuitInstance::AddDevice(const string &_device_name, Device *_device)
{
    bool is_exist = IsDeviceExist(_device_name);
    if(!is_exist)
    {
        device_list[_device_name] = _device;
    }
}

void CircuitInstance::AddModel(const string &_model_name, Model *_model)
{
    bool is_exist = IsModelExist(_model_name);
    if(!is_exist)
    {
        model_list[_model_name] = _model;
    }
}

void CircuitInstance::AddNode(const string &_node_name, Node *_node)
{
    bool is_exist = IsNodeExist(_node_name);
    if(!is_exist)
    {
        node_list[_node_name] = _node;
    }
}

bool CircuitInstance::IsDeviceExist(const string &_device_name) const
{
    map<string, Device*>::const_iterator it;
    it = device_list.find(_device_name);
    if(it == device_list.cend())
        return false;
    else
        return true;
}

bool CircuitInstance::IsModelExist(const string &_model_name) const
{
    map<string, Model*>::const_iterator it;
    it = model_list.find(_model_name);
    if(it == model_list.cend())
        return false;
    else
        return true;
}

bool CircuitInstance::IsNodeExist(const string &_node_name) const
{
    map<string, Node*>::const_iterator it;
    it = node_list.find(_node_name);
    if(it == node_list.cend())
        return false;
    else
        return true;
}

Device* CircuitInstance::GetDevice(const string &_device_name) const
{
    map<string, Device*>::const_iterator it;
    it = device_list.find(_device_name);
    if(it == device_list.cend())
        return NULL;
    else 
        return it->second;
}

Model* CircuitInstance::GetModel(const string &_model_name) const
{
    map<string, Model*>::const_iterator it;
    it = model_list.find(_model_name);
    if(it == model_list.cend())
        return NULL;
    else
        return it->second;
}

Node* CircuitInstance::GetNode(const string &_node_name) const
{
    map<string, Node*>::const_iterator it;
    it = node_list.find(_node_name);
    if(it == node_list.cend())
        return NULL;
    else
        return it->second;
}

void CircuitInstance::PrintAllDevice() const
{
    map<string, Device*>::const_iterator cit;
    for(cit = device_list.cbegin(); cit != device_list.cend(); ++ cit)
    {
        cout << "Device name: " << cit->first << " address: " << cit->second << endl;
    }
}

void CircuitInstance::PrintAllModel() const
{
    map<string, Model*>::const_iterator cit;
    for(cit = model_list.cbegin(); cit != model_list.cend(); ++ cit)
    {
        cout << "Model name: " << cit->first << " address: " << cit->second << endl;
    }

}

void CircuitInstance::PrintAllNode() const
{
    map<string, Node*>::const_iterator cit;
    for(cit = node_list.cbegin(); cit != node_list.cend(); ++ cit)
    {
        cout << "Node name: " << cit->first << " address: " << cit->second << endl;
    }
}

