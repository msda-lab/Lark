#ifndef ISOURCE_H
#define ISOURCE_H

#include "DeviceBase.h"

class ISource : public Device 
{
    public: 
        ISource(const string &_name, Node *_n1, Node *_n2);
        ~ISource();
    
    public: 
        void Setup();
        void SetupDC();
        void SetupAC();
        void SetupTRAN();

        void Load();
        void LoadDC();
        void LoadAC();
        void LoadTRAN();

        void SetDCValue(double _dc_value);
        double GetDCValue() const;
        void SetACValue(Complex _ac_value);
        Complex GetACValue() const;

    private: 
        double dc_value;
        Complex ac_value;

        Node *n1;
        Node *n2;


};

#endif //ISOURCE_H