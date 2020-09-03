
#include "DupParams.h"

#include <sstream>
//#include "NewParams.h"
#include "../../../../Exeptions/InValidParams.h"
#include "../../../../DNA/Container/DNAContainer.h"


DupParams::DupParams(const std::string& commandLine)
{
    IParams::parseCommand(commandLine);

    if(!isValidParams())
    {
        throw InValidParams();
    }
}


bool DupParams::isValidParams()
{
    sequenceNameMap& nameCounter = IParams::getNameCounter();
    if(1 < IParams::getParams().size())
    {
        return false;
    }
    if(1 == IParams::getParams().size()) //without name
    {
        std::string prevName = DNAContainer::getDnaData().find(atoi(IParams::getParams()[0].c_str()))->getName();
        std::stringstream name;
        name << prevName << '_' << nameCounter[prevName]++;
        nameCounter[name.str()] = 1; // add the new name to the list
        IParams::addParam(name.str());
        return true;
    }

    if(2 == IParams::getParams().size()) //with name
    {
        std::string name = IParams::getParams()[1];
        if('@' == name[0])
            if(0 != nameCounter[name])
            {
                std::stringstream newName;
                newName << name << ++nameCounter[name];
                nameCounter[newName.str()] = 1;// add the new name to the list
                IParams::getParams()[1] = newName.str();
            }
        return true;
    }
    return false;
}
