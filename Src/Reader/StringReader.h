
#ifndef DNASEQUENCE_STRINGREADER_H
#define DNASEQUENCE_STRINGREADER_H

#include <string>
#include "IReader.h"

class StringReader : public IReader{
public:
    StringReader(std::string data):m_data(data){}
    /*virtual*/ std::string read()const{ return m_data;}
private:
    std::string m_data;
};

#endif //DNASEQUENCE_STRINGREADER_H
