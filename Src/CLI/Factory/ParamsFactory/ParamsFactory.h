
#ifndef DNASEQUENCE_PARAMSFACTORY_H
#define DNASEQUENCE_PARAMSFACTORY_H

#include <string>
#include "../../CommandParams/IParams.h"

class ParamsFactory {
public:
    static IParams* createParam(const std::string& commandLine);
};


#endif //DNASEQUENCE_PARAMSFACTORY_H
