
#ifndef DNASEQUENCE_NEWPARAMS_H
#define DNASEQUENCE_NEWPARAMS_H

#include "../../IParams.h"

class NewParams: public IParams {
public:
    NewParams(const std::vector<std::string>& params);

protected:
    void validetParams();
};


#endif //DNASEQUENCE_NEWPARAMS_H
