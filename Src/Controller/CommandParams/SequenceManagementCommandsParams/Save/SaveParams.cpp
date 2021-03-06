
#include "SaveParams.h"
#include "../../../Exeptions/InValidParam/TooFewArguments.h"
#include "../../../Exeptions/InValidParam/IdOrNameError.h"
#include "../../../../Model/Container/DNAContainer.h"


SaveParams::SaveParams(const std::vector<std::string>& params):IParams(params)
{
    validetParams();
}


void SaveParams::validetParams()
{
    sequenceNameMap& nameCounter = IParams::getNameCounter();
    if(IParams::getParams().empty())
    {
        throw TooFewArguments();
    }

    if(2 == IParams::getParams().size()) // with filename
    {
        getMetaDataByIdOrName();
        IParams::getParams()[1] = IParams::getParams()[1].substr(1) + ".rawdna";
    }

    if(1 == IParams::getParams().size()) // without filename
    {
        DNAMetaData* dnaMetaDataById = getMetaDataByIdOrName();
        IParams::addParam(dnaMetaDataById->getName() + ".rawdna");
    }
}


DNAMetaData *SaveParams::getMetaDataByIdOrName() {
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
