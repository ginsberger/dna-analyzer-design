
#include "LoadParams.h"

#include <sstream>
#include "../../../../../Controller/Exeptions/InValidParam/TooFewArguments.h"
#include "../../../../../Controller/Exeptions/InValidParam/InValidNamePrefix.h"


LoadParams::LoadParams(const std::string& commandLine)
{
    IParams::parseCommand(commandLine);
    validetParams();
}

void LoadParams::validetParams()
{
    sequenceNameMap& nameCounter = IParams::getNameCounter();

    if(IParams::getParams().empty())
    {
        throw TooFewArguments();
    }

    if(2 == IParams::getParams().size()) //with name
    {
        if(IParams::getParams()[1][0] != '@')
        {
            throw InValidNamePrefix();
        }

        IParams::getParams()[1] = IParams::getParams()[1].substr(1); // Extract the name without the @
        std::string name = IParams::getParams()[1];
        if(0 != nameCounter[name])
        {
            std::stringstream newName;
            newName << name << ++nameCounter[name];
            nameCounter[newName.str()] = 1;// add the new name to the list
            IParams::getParams()[1] = newName.str();
        }

    }

    if(1 == IParams::getParams().size()) //without name
    {
        std::stringstream filenName(IParams::getParams()[0]);
        std::string name;
        std::getline(filenName, name,'.');
        std::stringstream Name;
        Name << name;
        std::cout << name <<std::endl;
        if(0 != nameCounter[name])
        {
            Name << ++nameCounter[name];
            nameCounter[Name.str()] = 1; // add the new name to the list
        }

        IParams::addParam(Name.str());
    }

}
