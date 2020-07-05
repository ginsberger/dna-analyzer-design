#include <fstream>
#include "FileReader.h"

FileReader::FileReader(const char* fileName):m_fileName(fileName)
{

}


const char* FileReader::read()const
{
    std::ifstream file(m_fileName);
    std::string line;
    if(file.is_open())
    {
        file >> line;
        file.close();
    }

    else{
        throw OpenFileError();
    }
    return line.c_str();
}

