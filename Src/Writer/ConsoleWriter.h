
#ifndef DNASEQUENCE_CONSOLWRITER_H
#define DNASEQUENCE_CONSOLWRITER_H

#include "IWriter.h"

class ConsoleWriter: public IWriter {
public:
    /*virtual*/ void write(const char* data)const ;
};


#endif //DNASEQUENCE_CONSOLWRITER_H
