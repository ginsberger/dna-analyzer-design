#include <fstream>
#include "FileWriter.h"

FileWriter::FileWriter(const char* fileName):m_fileName(fileName)
{

}


void FileWriter::write(const char* data)const
{
    std::ofstream file(m_fileName);
    if(file.is_open())
    {
        file << data;
        file.close();
    }

    else{
        throw OpenFileError();
    }
}