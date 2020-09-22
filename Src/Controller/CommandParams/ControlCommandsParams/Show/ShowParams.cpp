
#include "ShowParams.h"
#include "../../../Exeptions/InValidParam/TooFewArguments.h"
#include "../../../Exeptions/InValidParam/IdOrNameError.h"
#include "../../../../Model/Container/DNAContainer.h"

ShowParams::ShowParams(const std::vector<std::string> &params) :IParams(params)
{
    validetParams();
}

//ShowParams::ShowParams(const std::vector<std::string> &params): IParams(params)
//{
//    validetParams();
//}

void ShowParams::validetParams()
{
    if(IParams::getParams().empty())
    {
        throw TooFewArguments();
    }

    DNAMetaData* dnaMetaData = checkExistingIdOrName();

    if(1 == IParams::getParams().size()) // without filename
    {
        IParams::addParam("99");
    }
}


DNAMetaData *ShowParams::checkExistingIdOrName() {
    DNAMetaData *dnaMetaDataById = DNAContainer::getDnaData().operator[](
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

    return dnaMetaDataById;
}
