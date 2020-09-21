
#include "NewCommand.h"
#include "../../../../Model/Container/DNAContainer.h"
#include "../../../../View/Reader/StringReader/StringReader.h"
#include <sstream>

std::string NewCommand::run(const IParams* params)
{
    StringReader s(params->getParams()[0]);
    DNAMetaData* dna = new DNAMetaData(params->getParams()[1],s);
    (DNAContainer::getDnaData()).insert(dna);

    std::stringstream ss;
    size_t id = DNAContainer::getDnaData().getIdByName(params->getParams()[1]);
    ss <<"[" << id << "] ";
    ss << params->getParams()[1] << ": "; // name
    ss << DNAContainer::getDnaData()[id]->getDNA().getDnaSequence(); // dna
    return ss.str();
}


