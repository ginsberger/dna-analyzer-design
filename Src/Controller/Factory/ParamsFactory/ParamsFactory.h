
#ifndef DNASEQUENCE_PARAMSFACTORY_H
#define DNASEQUENCE_PARAMSFACTORY_H

#include <string>
#include "../../CommandParams/IParams.h"

class ParamsFactory {
public:
    static IParams* createParam(const std::string& commandName, const std::vector<std::string>& params);
};


#endif //DNASEQUENCE_PARAMSFACTORY_H
