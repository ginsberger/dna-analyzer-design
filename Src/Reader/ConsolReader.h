
#ifndef DNASEQUENCE_CONSOLREADER_H
#define DNASEQUENCE_CONSOLREADER_H

#include "IReader.h"

class ConsolReader :public IReader{
    /*virtual*/ const char* read()const;
};


#endif //DNASEQUENCE_CONSOLREADER_H
