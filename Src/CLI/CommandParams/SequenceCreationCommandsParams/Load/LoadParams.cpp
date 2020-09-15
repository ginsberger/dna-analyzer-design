
#include "LoadParams.h"


#include <sstream>
//#include "NewParams.h"
#include "../../../../Exeptions/InValidParam/InValidIdPrefix.h"
#include "../../../../Exeptions/InValidParam/TooFewArguments.h"
#include "../../../../Exeptions/InValidParam/InValidNamePrefix.h"



LoadParams::LoadParams(const std::string& commandLine)
{
    IParams::parseCommand(commandLine);
//    std::stringstream ss(commandLine);
//    std::string arg;
//    std::getline(ss, arg, ' '); // No need for command name
//    std::getline(ss, arg, ' ');
//    FileReader reader(arg.c_str());
//    std::stringstream s;
//    s << std::getline(ss, arg, ' ') << " " << reader.read();
//    IParams::parseCommand(s.str());
    validetParams();

//    if(!validetParams())
//    {
//        throw InValidParams();
//    }
}

void LoadParams::validetParams()
{
    sequenceNameMap& nameCounter = IParams::getNameCounter();

    if(1 < IParams::getParams().size())
    {
        throw TooFewArguments();
    }

    if(1 == IParams::getParams().size()) //without name
    {
        if(IParams::getParams()[0][0] != '#')
        {
            throw InValidIdPrefix();
        }

        std::stringstream filenName(IParams::getParams()[0]);
        std::string name;
        std::getline(filenName, name,'.');
        std::stringstream Name;
        Name << name;
        std::cout << name <<std::endl;
        if(0 != nameCounter[name])
//        if(0 != (*nameCounter1)[name])
        {
            Name << ++nameCounter[name];
            nameCounter[Name.str()] = 1; // add the new name to the list
        }

        IParams::addParam(Name.str());
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

        std::string name = IParams::getParams()[1];
        if('@' == name[0])
        {
            if(0 != nameCounter[name])
            {
                std::stringstream newName;
                newName << name << ++nameCounter[name];
                nameCounter[newName.str()] = 1;// add the new name to the list
                IParams::getParams()[1] = newName.str();
            }
        }
    }
}
