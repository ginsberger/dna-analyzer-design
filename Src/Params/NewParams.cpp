
#include "NewParams.h"

NewParams::NewParams(const std::string& commandLine):IParams(commandLine)
{
    if(!isValidParams())
    {
        throw std::bad_alloc();// 1. create a specifice error
    }
}

