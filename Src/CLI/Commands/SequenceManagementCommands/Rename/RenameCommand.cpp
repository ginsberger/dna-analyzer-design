
#include "RenameCommand.h"
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

    dnaMetaData->setName(params->getParams()[1]);

    std::stringstream ss;
    ss <<"[" << id << "] ";
    ss << dnaMetaData->getName() << ": "; // name
    ss << dnaMetaData->getDNA().getDnaSequence(); // dna

    return ss.str();
}