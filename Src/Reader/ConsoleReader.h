
#ifndef DNASEQUENCE_CONSOLEREADER_H
#define DNASEQUENCE_CONSOLEREADER_H

#include <string>
#include "IReader.h"

class ConsoleReader : public IReader{
    /*virtual*/ std::string read()const;
};


#endif //DNASEQUENCE_CONSOLEREADER_H
