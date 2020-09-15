
#ifndef DNASEQUENCE_INVALIDNAMEPREFIX_H
#define DNASEQUENCE_INVALIDNAMEPREFIX_H

#include "InValidParams.h"
#include <iostream>

class InValidNamePrefix: public InValidParams{
public:
    virtual const char* what() const throw()
    {
        return "Invalid params, invalid name prefix\n\tplease press again with @ before the name";
    }
};

#endif //DNASEQUENCE_INVALIDNAMEPREFIX_H
