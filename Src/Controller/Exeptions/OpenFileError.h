
#ifndef DNASEQUENCE_OPENFILEERROR_H
#define DNASEQUENCE_OPENFILEERROR_H

//#include "../Model/DnaSequence.h"
#include <exception>

class OpenFileError: public std::exception{
public:
    virtual const char* what() const throw()
    {
        return "Unable to open file";
    }
};


#endif //DNASEQUENCE_OPENFILEERROR_H
