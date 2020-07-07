
#ifndef DNASEQUENCE_INVALIDPARAMS_H
#define DNASEQUENCE_INVALIDPARAMS_H

#include <exception>

class InValidParams: public std::exception{
public:
    virtual const char* what() const throw()
    {
        return "invalid params";
    }
};

#endif //DNASEQUENCE_INVALIDPARAMS_H
