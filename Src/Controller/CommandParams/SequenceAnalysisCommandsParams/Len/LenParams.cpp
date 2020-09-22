
#include "LenParams.h"
#include "../../../Exeptions/InValidParam/TooFewArguments.h"
#include "../../../Exeptions/InValidParam/InValidIdPrefix.h"
#include "../../../Exeptions/InValidParam/IdError.h"
#include "../../../../Model/Container/DNAContainer.h"


LenParams::LenParams(const std::vector<std::string> &params) : IParams(params)
{
    validetParams();
}

void LenParams::validetParams()
{
    if(1 > IParams::getParams().size())
    {
        throw TooFewArguments();
    }

    if(1 == IParams::getParams().size())
    {
        if(IParams::getParams()[0][0] != '#')
        {
            throw InValidIdPrefix();
        }

        IParams::getParams()[0] = IParams::getParams()[0].substr(1); // Extract the id without the #
        const DNAMetaData *dnaMetaData = DNAContainer::getDnaData().operator[](
                atoi(IParams::getParams()[0].c_str()));

        if (!dnaMetaData)
        {
            throw IdError();
        }
    }
}
