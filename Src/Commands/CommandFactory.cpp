

#include "CommandFactory.h"
#include "NewCommand.h"
#include <string.h>

ICommand* CommandFactory::createCommand(const std::string& command)
{
    if(command=="new")
    {
        return new NewCommand;
    }
    throw std::bad_alloc(); // change to specific error
}
