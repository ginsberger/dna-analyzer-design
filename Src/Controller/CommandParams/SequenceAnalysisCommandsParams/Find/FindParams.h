
#ifndef DNASEQUENCE_FINDPARAMS_H
#define DNASEQUENCE_FINDPARAMS_H

#include "../../IParams.h"


class FindParams :public IParams{
public:
    FindParams(const std::vector<std::string>& params);

protected:
    void validetParams();
};

#endif //DNASEQUENCE_FINDPARAMS_H
