
#include <sstream>
#include "ParamsFactory.h"
#include "../../Exeptions/InValidCommandName.h"
#include "../../CommandParams/SequenceCreationCommandsParams/New/NewParams.h"
#include "../../CommandParams/SequenceCreationCommandsParams/Load/LoadParams.h"
#include "../../CommandParams/SequenceCreationCommandsParams/Dup/DupParams.h"
#include "../../CommandParams/SequenceManipulationCommandsParams/Slice/SliceParams.h"
#include "../../CommandParams/SequenceManagementCommandsParams/Rename/RenameParams.h"
#include "../../CommandParams/SequenceManagementCommandsParams/Save/SaveParams.h"
#include "../../CommandParams/ControlCommandsParams/Show/ShowParams.h"
#include "../../CommandParams/SequenceAnalysisCommandsParams/Len/LenParams.h"
#include "../../CommandParams/SequenceAnalysisCommandsParams/Find/FindParams.h"
#include "../../CommandParams/EmptyParam/EmptyParam.h"


IParams* ParamsFactory::createParam(const std::string& commandName, const std::vector<std::string>& params)
{
    if(commandName =="new")
    {
        return new NewParams(params);
    }
    if(commandName =="load")
    {
        return new LoadParams(params);
    }
    if(commandName =="dup")
    {
        return new DupParams(params);
    }
    if(commandName == "slice")
    {
        return new SliceParams(params);
    }
    if(commandName == "rename")
    {
        return new RenameParams(params);
    }
    if(commandName == "save")
    {
        return new SaveParams(params);
    }
    if(commandName == "show")
    {
        return new ShowParams(params);
    }
    if(commandName == "len")
    {
        return new LenParams(params);
    }
    if(commandName == "find")
    {
        return new FindParams(params);
    }
    if(commandName.empty())
    {
        return new EmptyParam(params);
    }

    throw InValidCommandName();
}
