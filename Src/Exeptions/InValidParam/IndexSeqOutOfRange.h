
#ifndef DNASEQUENCE_INDEXSEQOUTOFRANGE_H
#define DNASEQUENCE_INDEXSEQOUTOFRANGE_H

#include "InValidParams.h"

class IndexSeqOutOfRange: public InValidParams{
public:
    virtual const char* what() const throw()
    {
        return "Invalid params, Index sequence out of range, please try again";
    }
};

#endif //DNASEQUENCE_INDEXSEQOUTOFRANGE_H
