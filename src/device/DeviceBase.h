#ifndef DEVICE_BASE_H
#define DEVICE_BASE_H

#include <iostream>
#include <string>

#include "Global.h"
#include "MainMessage.h"

using std::string;

class Device
{
    public: 
        Device(const string &_name);
        Device(const string &_name, int _type);
        virtual ~Device();
    public: 
        void SetName(const string &_name);
        string GetName() const;
        void SetType(int _type);
        int GetType() const;

        static bool Equal(const string &_name, Device *_dev);

        virtual void Setup() = 0;
        virtual void Load() = 0;

    protected: 
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


    
    protected: 
        int location;
        double dc_voltage;
        Complex ac_voltage;
        string name;
        int type;

};


class Model
{
    public: 
        Model(const string &_model_type);
        virtual ~Model();
    
    public: 
        string GetModelType() const;
        int GetDeviceCount() const;

        static bool Equal(const string &_model_type, Model *_model_ptr);
        
        virtual void LoadDC() = 0;
        virtual void LoadAC(double _omega) = 0;
        virtual void LoadTran(double _t, double _h, bool _iter) = 0;

    protected: 
        string model_type;
        int device_count;
};

#endif // DEVICE_BASE_H
