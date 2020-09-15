
#include <sstream>
#include "NewParams.h"
#include "../../../../Exeptions/InValidParam/InValidNamePrefix.h"
#include "../../../../Exeptions/InValidParam/TooFewArguments.h"
#include "../../../../Exeptions/InValidParam/InValidIdPrefix.h"

NewParams::NewParams(const std::string& commandLine)
{
    IParams::parseCommand(commandLine);
    validetParams();
//    if(!validetParams())
//    {
//        throw InValidParams();
//    }
}

void NewParams::validetParams()
{
    sequenceNameMap& nameCounter = IParams::getNameCounter();

    if(IParams::getParams().empty())
    {
        throw TooFewArguments();
    }

    if(2 == IParams::getParams().size())
    {
        if(IParams::getParams()[1][0] != '@')
        {
            throw InValidNamePrefix();
        }

    }

    if(1 == IParams::getParams().size())
    {
        std::stringstream name;
        name << "seq" << ++nameCounter["seq"];
        nameCounter[name.str()] = 1; // add the new name to the list
        IParams::addParam(name.str());
    }

}


