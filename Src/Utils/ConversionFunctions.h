
#ifndef DNASEQUENCE_CONVERSIONFUNCTIONS_H
#define DNASEQUENCE_CONVERSIONFUNCTIONS_H

#include <iostream>
#include <sstream>

inline std::string numToString(size_t num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

inline size_t stringToNum(const std::string& string)
{
    std::stringstream ss(string);
    size_t num;
    ss >> num;
    return num;
}


#endif //DNASEQUENCE_CONVERSIONFUNCTIONS_H
