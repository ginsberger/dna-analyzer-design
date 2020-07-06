
#include "Parsing.h"

Parsing::Parsing(std::string string)
{
    size_t prevFind = 0;
    while (size_t i=string.find(' ',prevFind) != std::string::npos)
    {
        m_params.push_back(string.substr(prevFind,prevFind+ i));
        prevFind = prevFind+i+1;
    }

}
