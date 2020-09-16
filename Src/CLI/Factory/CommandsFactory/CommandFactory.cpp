

#include "CommandFactory.h"
#include "../../Commands/SequenceCreationCommands/New/NewCommand.h"
#include "../../Commands/SequenceCreationCommands/Load/LoadCommand.h"
#include "../../Commands/SequenceCreationCommands/Dup/DupCommand.h"
#include "../../Commands/SequenceManipulationCommands/Slice/SliceCommand.h"
#include "../../Commands/SequenceManagementCommands/Rename/RenameCommand.h"
#include "../../../Exeptions/InValidCommandName.h"


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
    if(command == "slice")
    {
        return new SliceCommand;
    }
    if(command == "rename")
    {
        return new RenameCommand;
    }

    throw InValidCommandName();
}
