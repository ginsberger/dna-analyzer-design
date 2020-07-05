
#ifndef DNASEQUENCE_DNADATA_H
#define DNASEQUENCE_DNADATA_H

#include "DNAHash.h"

class DNAData {
    static DNAHash& getDnaData(){
        static DNAHash dnaHash;
        return dnaHash;
    }
};


#endif //DNASEQUENCE_DNADATA_H
