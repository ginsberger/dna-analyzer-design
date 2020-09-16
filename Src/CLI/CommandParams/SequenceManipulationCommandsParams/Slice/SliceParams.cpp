
#include "SliceParams.h"
#include "../../../../Exeptions/InValidParam/TooFewArguments.h"
#include "../../../../Exeptions/InValidParam/IndexSeqOutOfRange.h"
#include "../../../../Exeptions/InValidParam/IdOrNameError.h"
#include "../../../../Exeptions/InValidParam/InValidParamsOrder.h"
#include "../../../../DNA/Container/DNAContainer.h"


SliceParams::SliceParams(const std::string& commandLine)
{
    IParams::parseCommand(commandLine);

    validetParams();
}


void SliceParams::validetParams()
{
    sequenceNameMap& nameCounter = IParams::getNameCounter();
    if(3 > IParams::getParams().size())
    {
        throw TooFewArguments();
    }

    if(3 == IParams::getParams().size()) //with name
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

        size_t len = dnaMetaDataById->getDNA().getLength();
        int start = atoi(IParams::getParams()[1].c_str());
        int end = atoi(IParams::getParams()[2].c_str());
        if(start < 0 || end >= len)
        {
            throw IndexSeqOutOfRange();
        }

        if(start > end)
        {
            throw InValidParamsOrder();
        }
    }
}
