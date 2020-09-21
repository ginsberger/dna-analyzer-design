
#ifndef DNASEQUENCE_FILEWRITER_H
#define DNASEQUENCE_FILEWRITER_H

#include "../IWriter.h"
#include "../../../Controller/Exeptions/OpenFileError.h"

class FileWriter: public IWriter {
public:
    FileWriter(const char* fileName);
    /*virtual*/ void write(const char* data)const ;
private:
    const char* m_fileName;
};


#endif //DNASEQUENCE_FILEWRITER_H
