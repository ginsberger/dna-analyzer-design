//
// Created by a on 7/7/20.
//

#ifndef DNASEQUENCE_CHARPREADER_H
#define DNASEQUENCE_CHARPREADER_H
#include <string>
#include "IReader.h"

class charPReader : public IReader{
public:
    charPReader(const char* data):m_data(data){}
    /*virtual*/ std::string read()const{ return m_data;}
private:
    const char* m_data;
};



#endif //DNASEQUENCE_CHARPREADER_H
