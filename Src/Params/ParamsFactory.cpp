
#include <sstream>
#include "ParamsFactory.h"
#include "NewParams.h"
#include "../Exeptions/InValidCommandName.h"

IParams* ParamsFactory::createParam(const std::string& commandLine)
{
    std::stringstream ss(commandLine);
    std::string arg;
    std::getline(ss, arg, ' ');

    if(arg =="new")
    {
        return new NewParams(commandLine);
    }
    throw InValidCommandName();
}
