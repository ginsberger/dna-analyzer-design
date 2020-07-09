
#ifndef DNASEQUENCE_LOADPARAMS_H
#define DNASEQUENCE_LOADPARAMS_H

#include "IParams.h"

class LoadParams: public IParams {
public:
    LoadParams(const std::string& commandLine);

protected:
    bool isValidParams();

};



#endif //DNASEQUENCE_LOADPARAMS_H
