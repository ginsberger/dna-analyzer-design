
#ifndef DNASEQUENCE_IDERROR_H
#define DNASEQUENCE_IDERROR_H

#include "InValidParams.h"

class IdError: public InValidParams{
public:
    virtual const char* what() const throw()
    {
        return "Invalid params, There is no such ID in the app right now";
    }
};

#endif //DNASEQUENCE_IDERROR_H
