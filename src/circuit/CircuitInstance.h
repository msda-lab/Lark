#ifndef CIRCUIT_INSTANCE_H
#define CIRCUIT_INSTANCE_H

#include "AllDevice.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::map;
using std::vector;
using std::string;
using std::pair;
using std::cout;
using std::endl;

class CircuitInstance
{
    public: 
        CircuitInstance();
        ~CircuitInstance();

    public:
        void AddDevice(const string &_device_name, Device *_device);
        void AddModel(const string &_model_name, Model *_model);
        void AddNode(const string &_node_name, Node*_node);

        bool IsDeviceExist(const string &_device_name) const;
        bool IsModelExist(const string &_model_name) const;
        bool IsNodeExist(const string &_node_name) const;

        Device* GetDevice(const string &_device_name) const;
        Model* GetModel(const string &_model_name) const;
        Node* GetNode(const string &_node_name) const;

        void PrintAllDevice() const;
        void PrintAllModel() const;
        void PrintAllNode() const;
    
    private: 
        map<string, Device*> device_list;
        map<string, Model*> model_list;
        map<string, Node*> node_list;
};

#endif // CIRCUIT_INSTANCE_H