
#ifndef DNASEQUENCE_INVALIDPARAMSORDER_H
#define DNASEQUENCE_INVALIDPARAMSORDER_H

#include "InValidParams.h"

class InValidParamsOrder: public InValidParams{
public:
    virtual const char* what() const throw()
    {
        return "Invalid params, incorrect params order, please press first the start index and then the end index";
    }
};

#endif //DNASEQUENCE_INVALIDPARAMSORDER_H
