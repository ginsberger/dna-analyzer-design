#ifndef DNASEQUENCE_TOOFEWARGUMENTS_H
#define DNASEQUENCE_TOOFEWARGUMENTS_H

#include "InValidParams.h"

class TooFewArguments: public InValidParams{
public:
    virtual const char* what() const throw()
    {
        return "Invalid params, too few arguments were sent";
    }
};

#endif //DNASEQUENCE_TOOFEWARGUMENTS_H
