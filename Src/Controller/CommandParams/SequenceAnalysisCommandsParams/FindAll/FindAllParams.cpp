
#include "FindAllParams.h"
#include "../../../Exeptions/InValidParam/TooFewArguments.h"
#include "../../../../Model/Container/DNAContainer.h"
#include "../../../../Utils/ConversionFunctions.h"
#include "../../../Exeptions/InValidParam/IdOrNameError.h"


FindAllParams::FindAllParams(const std::vector<std::string> &params) : IParams(params)
{
    validetParams();
}

void FindAllParams::validetParams()
{
    if(2 > IParams::getParams().size())
    {
        throw TooFewArguments();
    }

    if(2 == IParams::getParams().size())
    {
        // validate the firs param
        const DNAMetaData *dnaMetaData = DNAContainer::getDnaData()[stringToNum(IParams::getParams()[0].substr(1))];
        size_t id = DNAContainer::getDnaData()[IParams::getParams()[0].substr(1)];

        bool isId = dnaMetaData && IParams::getParams()[0][0] == '#';
        bool isName = id && IParams::getParams()[0][0] == '@';

        if (!isId && !isName)
        {
            throw IdOrNameError();
        }

        // if the first param is sequence name, change to be the id
        if(isName)
        {
            IParams::getParams()[0] = numToString(id);
        }
        else
        {
            IParams::getParams()[0] = IParams::getParams()[0].substr(1); // Extract the id without the #
        }

        //prepare the second param
        const DNAMetaData *dnaMetaData2 = DNAContainer::getDnaData()[stringToNum(IParams::getParams()[1].substr(1))];
        size_t id2 = DNAContainer::getDnaData()[IParams::getParams()[1].substr(1)];

        bool isId2 = dnaMetaData2 && IParams::getParams()[1][0] == '#';
        bool isName2 = id && IParams::getParams()[1][0] == '@';

        if (isId2)
        {
            IParams::getParams()[1] = DNAContainer::getDnaData()[id2]->getDNA().getDnaSequence();
        }
        if(isName2)
        {
            IParams::getParams()[1] = dnaMetaData2->getDNA().getDnaSequence();
        }
        // else the second param is already expressed sub-sequence
    }
}
