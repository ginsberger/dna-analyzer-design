
#ifndef DNASEQUENCE_LOADPARAMS_H
#define DNASEQUENCE_LOADPARAMS_H

#include "../../IParams.h"

class LoadParams: public IParams {
public:
    LoadParams(const std::string& commandLine);

protected:
    void validetParams();

};



#endif //DNASEQUENCE_LOADPARAMS_H
