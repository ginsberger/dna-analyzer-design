
#ifndef DNASEQUENCE_FILEREADER_H
#define DNASEQUENCE_FILEREADER_H

#include "IReader.h"
#include "../Exeptions/OpenFileError.h"

class FileReader: public IReader{
public:
    FileReader(const char* fileName);
    /*virtual*/ const char* read()const;

private:
    const char* m_fileName;
};


#endif //DNASEQUENCE_FILEREADER_H
