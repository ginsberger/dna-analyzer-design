
#include "RenameParams.h"
#include "../../../../Exeptions/InValidParam/TooFewArguments.h"
#include "../../../../DNA/Container/DNAContainer.h"
#include "../../../../Exeptions/InValidParam/IdOrNameError.h"
#include "../../../../Exeptions/InValidParam/NameAlreadyExists.h"
#include "../../../../Exeptions/InValidParam/InValidNamePrefix.h"


RenameParams::RenameParams(const std::string& commandLine)
{
    IParams::parseCommand(commandLine);

    validetParams();
}

void RenameParams::validetParams()
{
    sequenceNameMap& nameCounter = IParams::getNameCounter();
    if(2 > IParams::getParams().size())
    {
        throw TooFewArguments();
    }

    if(2 == IParams::getParams().size())
    {
        const DNAMetaData *dnaMetaDataById = DNAContainer::getDnaData().operator[](
                atoi(IParams::getParams()[0].substr(1).c_str()));
        size_t id = DNAContainer::getDnaData().operator[](IParams::getParams()[0].substr(1));

        bool isId = dnaMetaDataById && IParams::getParams()[0][0] == '#';
        bool isName = id && IParams::getParams()[0][0] == '@';

        if (!isId && !isName)
        {
            throw IdOrNameError();
        }

        if(isName)
        {
            dnaMetaDataById = DNAContainer::getDnaData().operator[](id);
        }

        if(IParams::getParams()[1][0] != '@')
        {
            throw InValidNamePrefix();
        }

        if(nameCounter[IParams::getParams()[1]])
        {
            throw NameAlreadyExists();
        }
    }
}
