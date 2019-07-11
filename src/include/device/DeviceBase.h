#ifndef DEVICE_BASE_H
#define DEVICE_BASE_H

#include <iostream>
#include <string>

#include "GlobalDef.h"

using std::string;

class Device
{
    public: 
        Device(const string &_name);
        ~Device();
    public: 
        void setName(const string &_name);
        string getName() const;

        static bool Equal(const string &_name, const Device *_dev);

        void setup();
        void load();

        virtual void setupDC() = 0;
        virtual void setupAC() = 0;
        virtual void setupTRAN() = 0;

        virtual void loadDC() = 0;
        virtual void loadAC() = 0;
        virtual void loadTRAN() = 0;

    private: 
        string name;
        

};

class Node
{
    public:
        Node(const string &_name);
        ~Node();
    public: 
        static bool Equal(const string &_name, Node *_node);
        void setDCVoltage(double _dc);
        double getDCVoltage() const;
        void setACVoltage(Complex _ac);
        Complex getACVoltage() const;
        void setName(const string &_name);
        string getName() const;
    
    private: 
        int location;
        double dcVoltage;
        Complex acVoltage;
        string name;

};

#endif // DEVICE_BASE_H
