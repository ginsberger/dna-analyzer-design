

#include "CommandFactory.h"
#include "../../Commands/SequenceCreationCommands/New/NewCommand.h"
#include "../../Commands/SequenceCreationCommands/Load/LoadCommand.h"
#include "../../Commands/SequenceCreationCommands/Dup/DupCommand.h"
#include "../../Commands/SequenceManipulationCommands/Slice/SliceCommand.h"
#include "../../Commands/SequenceManagementCommands/Rename/RenameCommand.h"
#include "../../Commands/SequenceManagementCommands/Save/SaveCommand.h"
#include "../../Commands/ControlCommands/Show/ShowCommand.h"
#include "../../Commands/SequenceAnalysisCommands/Len/LenCommand.h"
#include "../../Commands/SequenceAnalysisCommands/Find/FindCommand.h"
#include "../../Commands/SequenceAnalysisCommands/FindAll/FindAllCommand.h"
#include "../../Commands/SequenceAnalysisCommands/Count/CountCommand.h"
#include "../../Commands/EmptyCommand/EmptyCommand.h"
#include "../../Exeptions/InValidCommandName.h"


std::map<std::string, SharedPtr<ICommand> > CommandFactory::init()
{
    std::map<std::string, SharedPtr<ICommand> > tmp;
    tmp["new"] = SharedPtr<ICommand>(new NewCommand);
    tmp["load"] = SharedPtr<ICommand>(new LoadCommand());
    tmp["dup"] = SharedPtr<ICommand>(new DupCommand());
    tmp["slice"] = SharedPtr<ICommand>(new SliceCommand());
    tmp["rename"] = SharedPtr<ICommand>(new RenameCommand());
    tmp["save"] = SharedPtr<ICommand>(new SaveCommand());
    tmp["show"] = SharedPtr<ICommand>(new ShowCommand());
    tmp["len"] = SharedPtr<ICommand>(new LenCommand());
    tmp["find"] = SharedPtr<ICommand>(new FindCommand());
    tmp["findall"] = SharedPtr<ICommand>(new FindAllCommand());
    tmp["count"] = SharedPtr<ICommand>(new CountCommand());
    tmp["show"] = SharedPtr<ICommand>(new ShowCommand());
    tmp[""] = SharedPtr<ICommand>(new EmptyCommand());
    tmp["show"] = SharedPtr<ICommand>(new ShowCommand());
    return tmp;
}

std::map<std::string, SharedPtr<ICommand>> CommandFactory::m_commandsMap = CommandFactory::init();

SharedPtr<ICommand> CommandFactory::getCommand(const std::string &command)
{
    try {
        return m_commandsMap[command];
    }
    catch(const std::exception& e)
    {
        throw InValidCommandName();
    }
}



