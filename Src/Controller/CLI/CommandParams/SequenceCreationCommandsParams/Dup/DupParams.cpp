
#include "DupParams.h"

#include <sstream>
//#include "NewParams.h"
#include "../../../../../Controller/Exeptions/InValidParam/TooFewArguments.h"
#include "../../../../../Controller/Exeptions/InValidParam/InValidIdPrefix.h"
#include "../../../../../Controller/Exeptions/InValidParam/InValidNamePrefix.h"
#include "../../../../../Controller/Exeptions/InValidParam/IdError.h"
#include "../../../../../Model/Container/DNAContainer.h"


DupParams::DupParams(const std::string& commandLine)
{
    IParams::parseCommand(commandLine);

    validetParams();
}


void DupParams::validetParams()
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

        if(IParams::getParams()[0][0] != '#')
        {
            throw InValidIdPrefix();
        }

        IParams::getParams()[0] = IParams::getParams()[0].substr(1); // Extract the ID without the #
        IParams::getParams()[1] = IParams::getParams()[1].substr(1); // Extract the name without the @

        std::string name = IParams::getParams()[1];
        if (0 != nameCounter[name])
        {
            std::stringstream newName;
            newName << name << ++nameCounter[name];
            nameCounter[newName.str()] = 1;// add the new name to the list
            IParams::getParams()[1] = newName.str();
        }
    }

    if(1 == IParams::getParams().size()) //without name
    {
        if(IParams::getParams()[0][0] != '#')
        {
            throw InValidIdPrefix();
        }

        IParams::getParams()[0] = IParams::getParams()[0].substr(1); // Extract the ID without the #
        const DNAMetaData* dnaMetaData = DNAContainer::getDnaData().operator[](atoi(IParams::getParams()[0].c_str()));
        if (!dnaMetaData)
        {
            throw IdError();
        }

        std::string prevName = dnaMetaData->getName();
        std::stringstream name;
        name << prevName << '_' << nameCounter[prevName]++;
        nameCounter[name.str()] = 1; // add the new name to the list
        IParams::addParam(name.str());
    }

}
