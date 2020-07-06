
#include "ConsolReader.h"
#include <iostream>

const char* ConsolReader::read()const
{
    std::string line;
    std::getline(std::cin, line);
    return line.c_str();
}
