
#ifndef DNASEQUENCE_NEWPARAMS_H
#define DNASEQUENCE_NEWPARAMS_H

#include "IParams.h"

class NewParams: public IParams {
public:
    NewParams(const std::string& commandLine);

protected:
    bool isValidParams();
};


#endif //DNASEQUENCE_NEWPARAMS_H
