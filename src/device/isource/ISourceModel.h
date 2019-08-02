#ifndef ISOURCE_MODEL_H
#define ISOURCE_MODEL_H

#include "DeviceBase.h"
#include "ISource.h"

#include <vector>

using std::vector;

class ISourceModel : public Model
{
    public: 
        ISourceModel();
        ~ISourceModel();
    
    public: 
        void Setup(Numeric *_numeric, int _analysis_type);
        void LoadDC();
        void LoadAC(double _omega);
        void LoadTran(double _t, double _h, bool _iter);

        void AddInst(ISource *_isrc);
    private: 
        vector<ISource*> isrc_list;
};

#endif // ISOURCE_MODEL_H
