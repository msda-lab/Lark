#ifndef DEVICE_BASE_H
#define DEVICE_BASE_H

#include <iostream>
#include <string>

#include "Global.h"

using std::string;

class Device
{
    public: 
        Device(const string &_name);
        ~Device();
    public: 
        void SetName(const string &_name);
        string GetName() const;

        static bool Equal(const string &_name, const Device *_dev);

        void Setup();
        void Load();

        virtual void SetupDC() = 0;
        virtual void SetupAC() = 0;
        virtual void SetupTRAN() = 0;

        virtual void LoadDC() = 0;
        virtual void LoadAC() = 0;
        virtual void LoadTRAN() = 0;

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
        void SetDCVoltage(double _dc);
        double GetDCVoltage() const;
        void SetACVoltage(Complex _ac);
        Complex GetACVoltage() const;
        void SetName(const string &_name);
        string GetName() const;
    
    private: 
        int location;
        double dc_voltage;
        Complex ac_voltage;
        string name;

};

#endif // DEVICE_BASE_H
