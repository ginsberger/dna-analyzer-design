
#ifndef DNASEQUENCE_IDORNAMEERROR_H
#define DNASEQUENCE_IDORNAMEERROR_H

class IdOrNameError: public InValidParams{
public:
    virtual const char* what() const throw()
    {
        return "Invalid params, There is no such ID/name in the app right now";
    }
};
#endif //DNASEQUENCE_IDORNAMEERROR_H
