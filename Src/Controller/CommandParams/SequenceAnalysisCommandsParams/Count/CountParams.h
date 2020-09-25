
#ifndef DNASEQUENCE_COUNTPARAMS_H
#define DNASEQUENCE_COUNTPARAMS_H

#include "../../IParams.h"


class CountParams :public IParams{
public:
    CountParams(const std::vector<std::string>& params);

protected:
    void validetParams();
};

#endif //DNASEQUENCE_COUNTPARAMS_H
