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
        Device(const string &_name, int _type);
        ~Device();
    public: 
        void SetName(const string &_name);
        string GetName() const;
        void SetType(int _type);
        int GetType() const;

        static bool Equal(const string &_name, Device *_dev);

        virtual void Setup() = 0;
        virtual void Load() = 0;

    private: 
        string name;
        int type;
        

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

        void SetType(int _type);
        int GetType() const;

        void SetLocation(int _location);
        int GetLocation() const;


    
    private: 
        int location;
        double dc_voltage;
        Complex ac_voltage;
        string name;
        int type;

};

#endif // DEVICE_BASE_H
