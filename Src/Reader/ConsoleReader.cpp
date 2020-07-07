
#include "ConsoleReader.h"
#include <iostream>

std::string ConsoleReader::read()const
{
    std::string line;
    std::getline(std::cin, line);
    return line;
}
