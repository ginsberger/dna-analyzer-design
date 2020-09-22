
#ifndef DNASEQUENCE_LENPARAMS_H
#define DNASEQUENCE_LENPARAMS_H

#include "../../IParams.h"


class LenParams :public IParams{
public:
    LenParams(const std::vector<std::string>& params);

protected:
    void validetParams();
};

#endif //DNASEQUENCE_LENPARAMS_H
