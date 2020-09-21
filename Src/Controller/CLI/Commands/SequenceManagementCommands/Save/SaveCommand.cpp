
#include "SaveCommand.h"
#include <sstream>
#include "../../../../../Model/Container/DNAContainer.h"
#include "../../../../../View/Writer/FileWriter/FileWriter.h"


std::string SaveCommand::run(const IParams *params) {

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

    FileWriter writer(params->getParams()[1].c_str());
    writer.write(dnaMetaData->getDNA().getDnaSequence().c_str());
    dnaMetaData->setStatus(E_UpToDate);

    std::stringstream ss;
    ss <<"[" << id << "] ";
    ss << dnaMetaData->getName() << ": "; // name
    ss << dnaMetaData->getDNA().getDnaSequence(); // dna

    return ss.str();
}

