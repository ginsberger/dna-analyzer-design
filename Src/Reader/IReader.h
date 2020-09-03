
#ifndef DNASEQUENCE_IREADER_H
#define DNASEQUENCE_IREADER_H

#include <iostream>

class IReader {
public:
    virtual std::string read()const = 0 ;
    virtual ~IReader(){}
};


#endif //DNASEQUENCE_IREADER_H
