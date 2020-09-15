
#include "SliceParams.h"
#include "../../../../Exeptions/InValidParam/TooFewArguments.h"
#include "../../../../Exeptions/InValidParam/InValidPrefix.h"
#include "../../../../Exeptions/InValidParam/IdOrNameError.h"
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
        if (IParams::getParams()[0][0] != '#' && IParams::getParams()[0][0] != '@') {
            throw InValidPrefix();
        }

        const DNAMetaData *dnaMetaDataById = DNAContainer::getDnaData().operator[](
                atoi(IParams::getParams()[0].substr(1).c_str()));
        size_t dnaMetaDataByName = DNAContainer::getDnaData().operator[](IParams::getParams()[0].substr(1));
        if (!dnaMetaDataById && !dnaMetaDataByName) {
            throw IdOrNameError();
        }
    }
}