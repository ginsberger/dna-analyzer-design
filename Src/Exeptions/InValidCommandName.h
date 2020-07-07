
#ifndef DNASEQUENCE_INVALIDCOMMANDNAME_H
#define DNASEQUENCE_INVALIDCOMMANDNAME_H
#include <exception>

class InValidCommandName: public std::exception{
public:
    virtual const char* what() const throw()
    {
        return "invalid command name";
    }
};

#endif //DNASEQUENCE_INVALIDCOMMANDNAME_H
