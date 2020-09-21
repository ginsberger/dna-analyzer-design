
#ifndef DNASEQUENCE_LOADPARAMS_H
#define DNASEQUENCE_LOADPARAMS_H

#include "../../IParams.h"

class LoadParams: public IParams {
public:
    LoadParams(const std::vector<std::string>& params);

protected:
    void validetParams();

};



#endif //DNASEQUENCE_LOADPARAMS_H
