
#ifndef DNASEQUENCE_NAMEALREADYEXISTS_H
#define DNASEQUENCE_NAMEALREADYEXISTS_H

#include "InValidParams.h"

class NameAlreadyExists: public InValidParams {
public:
    virtual const char *what() const throw()
    {
        return "Invalid params, the new name already exists";

    }
};

#endif //DNASEQUENCE_NAMEALREADYEXISTS_H
