
#ifndef DNASEQUENCE_DUPPARAMS_H
#define DNASEQUENCE_DUPPARAMS_H

#include "../../IParams.h"


class DupParams: public IParams {
public:
    DupParams(const std::string& commandLine);

protected:
    void validetParams();

};


#endif //DNASEQUENCE_DUPPARAMS_H
