
#include <sstream>
#include "NewParams.h"
#include "../../../../Exeptions/InValidParams.h"

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
    sequenceNameMap& nameCounter = IParams::getNameCounter();
    if(1 == IParams::getParams().size())
    {
        std::stringstream name;
        name << "seq" << ++nameCounter["seq"];
        nameCounter[name.str()] = 1; // add the new name to the list
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


