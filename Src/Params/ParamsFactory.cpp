
#include <sstream>
#include "ParamsFactory.h"
#include "../Exeptions/InValidCommandName.h"
#include "NewParams.h"
#include "LoadParams.h"

IParams* ParamsFactory::createParam(const std::string& commandLine)
{
    std::stringstream ss(commandLine);
    std::string arg;
    std::getline(ss, arg, ' ');

    if(arg =="new")
    {
        return new NewParams(commandLine);
    }
    if(arg =="load")
    {
        return new LoadParams(commandLine);
    }

    throw InValidCommandName();
}
