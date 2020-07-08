
#include "LoadParams.h"


#include <sstream>
#include "NewParams.h"
#include "../Exeptions/InValidParams.h"


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

    if(!isValidParams())
    {
        throw InValidParams();
    }
}

bool LoadParams::isValidParams()
{
    if(1 < IParams::getParams().size())
    {
        return false;
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
        }

        IParams::addParam(Name.str());
        return true;
    }

    if(2 == IParams::getParams().size()) //with name
    {
        std::string name = IParams::getParams()[1];
        if('@' == name[0])
        {
            if(0 != nameCounter[name])
            {
                std::stringstream newName;
                newName << name << nameCounter[name];
                nameCounter[newName.str()] = 1;
                IParams::getParams()[1] = newName.str();
            }
            return true;
        }
    }
    return false;
}
