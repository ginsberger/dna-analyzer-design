
#include "NewCommand.h"
#include "../Reader/StringReader.h"
#include <sstream>

std::string NewCommand::run(const IParams* params)
{
    StringReader s(params->getParams()[0]);
    DNAMetaData dna(params->getParams()[1],s);
    (DNAContainer::getDnaData()).insert(dna);

    std::stringstream ss;
    size_t id = DNAContainer::getDnaData().getIdByName(params->getParams()[1]);
    ss <<"[" << id << "] ";
    ss << params->getParams()[1]; // name
    ss << params->getParams()[0]; // dna
    return ss.str();
}


