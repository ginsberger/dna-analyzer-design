
#include "SliceCommand.h"
#include "../../../../Reader/StringReader/StringReader.h"
#include <sstream>


std::string SliceCommand::run(const IParams *params) {

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

    size_t start = atoi(params->getParams()[1].c_str());
    size_t end = atoi(params->getParams()[2].c_str());
    StringReader s(dnaMetaData->getDNA().getDnaSequence().substr(start, end));
    dnaMetaData->setDna(s);
//    dnaMetaData->slice(start, end);

    std::stringstream ss;
    ss <<"[" << id << "] ";
    ss << dnaMetaData->getName() << ": "; // name
    ss << dnaMetaData->getDNA().getDnaSequence(); // dna
    return ss.str();
}
