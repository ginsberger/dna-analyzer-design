

#include "CommandFactory.h"
#include "../../Commands/SequenceCreationCommands/New/NewCommand.h"
#include "../../Commands/SequenceCreationCommands/Load/LoadCommand.h"
#include "../../Commands/SequenceCreationCommands/Dup/DupCommand.h"
#include "../../Commands/SequenceManipulationCommands/Slice/SliceCommand.h"
#include "../../Commands/SequenceManagementCommands/Rename/RenameCommand.h"
#include "../../Commands/SequenceManagementCommands/Save/SaveCommand.h"
#include "../../Commands/ControlCommands/Show/ShowCommand.h"
#include "../../Commands/SequenceAnalysisCommands/Len/LenCommand.h"
#include "../../Commands/EmptyCommand/EmptyCommand.h"
#include "../../Exeptions/InValidCommandName.h"


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
    if(command == "save")
    {
        return new SaveCommand;
    }
    if(command == "show")
    {
        return new ShowCommand;
    }
    if(command == "len")
    {
        return new LenCommand;
    }
    if(command.empty())
    {
        return new EmptyCommand;
    }

    throw InValidCommandName();
}
