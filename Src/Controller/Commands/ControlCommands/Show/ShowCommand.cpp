
#include "ShowCommand.h"
#include <sstream>


std::string ShowCommand::run(const IParams *params) {
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

    std::string name = dnaMetaData->getName();
    std::string status = dnaMetaData->getStatus();
    std::string dna = DNAContainer::getDnaData().operator[](id)->getDNA().getDnaSequence();

    std::stringstream ss;
    ss << "[" << id << "] " << name << " " << status << std::endl;

    int num_chars = atoi(params->getParams()[1].c_str());
    std::string::iterator it = dna.begin();
    while (it != dna.end())
    {
        for(int i = 0 ; i < num_chars && it != dna.end() ; ++i, ++it)
        {
            ss << *it;
        }

        ss << std::endl;
    }

    return ss.str();
}
