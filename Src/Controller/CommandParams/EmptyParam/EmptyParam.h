
#ifndef DNASEQUENCE_EMPTYPARAM_H
#define DNASEQUENCE_EMPTYPARAM_H

#include "../IParams.h"

class EmptyParam: public IParams {
public:
    EmptyParam(const std::vector<std::string>& params):IParams(params){};
    void validetParams(){}
};


#endif //DNASEQUENCE_EMPTYPARAM_H
