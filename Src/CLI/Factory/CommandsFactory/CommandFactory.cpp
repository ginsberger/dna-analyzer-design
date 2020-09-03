

#include "CommandFactory.h"
#include "../../Commands/SequenceCreationCommands/New/NewCommand.h"
#include "../../Commands/SequenceCreationCommands/Load/LoadCommand.h"
#include "../../Commands/SequenceCreationCommands/Dup/DupCommand.h"
#include "../../../Exeptions/InValidCommandName.h"
#include <string.h>

ICommand* CommandFactory::createCommand(const std::string& command)
{
    if(command=="new")
    {
        return new NewCommand;
    }
    if(command=="load")
    {
        return new LoadCommand;
    }
    if(command=="dup")
    {
        return new DupCommand;
    }
    throw InValidCommandName();
}
