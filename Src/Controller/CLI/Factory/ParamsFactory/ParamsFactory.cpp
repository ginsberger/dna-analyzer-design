
#include <sstream>
#include "ParamsFactory.h"
#include "../../../../Controller/Exeptions/InValidCommandName.h"
#include "../../CommandParams/SequenceCreationCommandsParams/New/NewParams.h"
#include "../../CommandParams/SequenceCreationCommandsParams/Load/LoadParams.h"
#include "../../CommandParams/SequenceCreationCommandsParams/Dup/DupParams.h"
#include "../../CommandParams/SequenceManipulationCommandsParams/Slice/SliceParams.h"
#include "../../CommandParams/SequenceManagementCommandsParams/Rename/RenameParams.h"
#include "../../CommandParams/SequenceManagementCommandsParams/Save/SaveParams.h"


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
    if(arg =="dup")
    {
        return new DupParams(commandLine);
    }
    if(arg == "slice")
    {
        return new SliceParams(commandLine);
    }
    if(arg == "rename")
    {
        return new RenameParams(commandLine);
    }
    if(arg == "save")
    {
        return new SaveParams(commandLine);
    }

    throw InValidCommandName();
}