
#ifndef DNASEQUENCE_IDORNAMEERROR_H
#define DNASEQUENCE_IDORNAMEERROR_H

#include "InValidParams.h"

class IdOrNameError: public InValidParams{
public:
    virtual const char* what() const throw()
    {
        return "Invalid params, There is no such ID/name in the app right now\n\t please try again with first argument like @seq_name or #Id";
    }
};
#endif //DNASEQUENCE_IDORNAMEERROR_H
