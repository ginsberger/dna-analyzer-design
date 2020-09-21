
#ifndef DNASEQUENCE_INVALIDIDPREFIX_H
#define DNASEQUENCE_INVALIDIDPREFIX_H

#include "InValidParams.h"

class InValidIdPrefix: public InValidParams{
public:
    virtual const char* what() const throw()
    {
        return "Invalid params, invalid id prefix\n\tplease press again with # before the id";
    }
};

#endif //DNASEQUENCE_INVALIDIDPREFIX_H
