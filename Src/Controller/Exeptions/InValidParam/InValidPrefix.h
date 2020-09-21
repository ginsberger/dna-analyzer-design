
#ifndef DNASEQUENCE_INVALIDPREFIX_H
#define DNASEQUENCE_INVALIDPREFIX_H

class InValidPrefix: public InValidParams{
public:
    virtual const char* what() const throw()
    {
        return "Invalid params, first argument is @name or #Id, please try again ";
    }
};
#endif //DNASEQUENCE_INVALIDPREFIX_H
