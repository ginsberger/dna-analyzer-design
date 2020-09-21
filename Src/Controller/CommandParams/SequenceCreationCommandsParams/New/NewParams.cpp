
#include <sstream>
#include "NewParams.h"
#include "../../../Exeptions/InValidParam/InValidNamePrefix.h"
#include "../../../Exeptions/InValidParam/TooFewArguments.h"

NewParams::NewParams(const std::vector<std::string>& params): IParams(params)
{
    validetParams();
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

        IParams::getParams()[1] = IParams::getParams()[1].substr(1); // Extract the name without the @
        if(nameCounter[IParams::getParams()[1]])
        {
            std::stringstream newName;
            newName << IParams::getParams()[1] << nameCounter[IParams::getParams()[1]]++;
            nameCounter[newName.str()] = 1;// add the new name to the list
            IParams::getParams()[1] = newName.str();
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


