
#include <sstream>
#include "NewParams.h"
#include "../Exeptions/InValidParams.h"

size_t NewParams::nameCounter = 1;
//:IParams(commandLine)
NewParams::NewParams(const std::string& commandLine)
{
    IParams::parseCommand(commandLine);
    if(!isValidParams())
    {
        throw InValidParams();
    }
}

bool NewParams::isValidParams()
{
    if(1 == IParams::getParams().size())
    {
        std::stringstream name;
        name << "seq" << nameCounter++;
        IParams::addParam(name.str());
        return true;
    }

    if(2 == IParams::getParams().size())
    {
        if('@' == IParams::getParams()[1][0])
            return true;
    }
    return false;
}


