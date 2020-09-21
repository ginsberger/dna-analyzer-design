
#include "RenameCommand.h"
#include "../../../../Model/Container/DNAContainer.h"
#include <sstream>


std::string RenameCommand::run(const IParams *params) {

    DNAMetaData* dnaMetaData;
    size_t id;

    if (params->getParams()[0][0] == '#')
    {
        id = atoi((params->getParams()[0].substr(1).c_str()));
        dnaMetaData = DNAContainer::getDnaData().operator[](id);
    }

    else
    {
        id = DNAContainer::getDnaData().operator[](params->getParams()[0].substr(1));
        dnaMetaData = DNAContainer::getDnaData().operator[](id);
    }

    std::string prevName = dnaMetaData->getName();
    dnaMetaData->setName(params->getParams()[1]);
    dnaMetaData->setStatus(E_Modified);
    DNAContainer::getDnaData().setNameMap(prevName, dnaMetaData->getName()); // set the hashMap

    std::stringstream ss;
    ss <<"[" << id << "] ";
    ss << dnaMetaData->getName() << ": "; // name
    ss << dnaMetaData->getDNA().getDnaSequence(); // dna

    return ss.str();
}
