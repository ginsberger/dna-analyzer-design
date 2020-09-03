
#ifndef DNASEQUENCE_CONSOLEREADER_H
#define DNASEQUENCE_CONSOLEREADER_H

#include <string>
#include "../IReader.h"

class ConsoleReader : public IReader{
public:
    /*virtual*/ std::string read()const;
};


#endif //DNASEQUENCE_CONSOLEREADER_H
