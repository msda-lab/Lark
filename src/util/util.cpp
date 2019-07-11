#include "util.h"

double str2val(char *s)
{
    double value;
    value = atof(s);
    int len = strlen(s);
    char u = s[len - 1];
    if(u == 'F' || u == 'f')
        value = value * 1e-15;
    else if(u == 'P' || u == 'p')
        value = value * 1e-12;
    else if(u == 'N' || u == 'n')
        value = value * 1e-9;
    else if(u == 'M' || u == 'm')
        value = value * 1e-6;
    else if(u == 'K' || u == 'k')
        value = value * 1e3;
    else if(u == 'G' || u == 'g')
    {
        if(s[len - 2] == 'E' || s[len - 2] == 'e')
            value = value * 1e6;
        else
            value = value * 1e9;
    }
    else if(u == 'T' || u == 't')
        value = value * 1e12;
    return value;
}

void displayAnalysis(int anaType, const map<int, string> &output)
{
    cout << "----------------------------------------------------" << endl;
    cout << "Analysis Task List" << endl;
    
    switch(anaType)
    {
        case DC_TYPE: cout << "Type: DC" << endl; break;
        case AC_TYPE: cout << "Type: AC" << endl; break;
        case TRAN_TYPE: cout << "Type: TRAN" << endl; break;
        default: cout << "Type: Unknown" << endl; break;
    }

    for(auto pos = output.cbegin(); pos != output.cend(); ++ pos)
    {
        int type = pos->first;
        string task = pos->second;
        switch(type)
        {
            case V_TYPE: cout << "V "; break;
            case I_TYPE: cout << "I "; break;
            case VM_TYPE: cout << "VM "; break;
            case VR_TYPE: cout << "VR "; break;
            case VP_TYPE: cout << "VP "; break;
        }
        cout << task << endl;
    }
    cout << "----------------------------------------------------" << endl;
}
