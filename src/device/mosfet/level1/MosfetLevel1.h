#ifndef MOSFETLEVEL1_H
#define MOSFETLEVEL1_H

#include "DeviceBase.h"

class MosfetLevel1
{
public:
    MosfetLevel1();
    ~MosfetLevel1();
private:
    double width;
    double length;
    Node *drain;
    Node *gate;
    Node *source;
    Node *base;
};

#endif // MOSFETLEVEL1_H
