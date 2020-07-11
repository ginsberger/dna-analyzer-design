
#include "DupCommand.h"
#include "../Reader/StringReader.h"
#include <sstream>
#include "../Reader/FileReader.h"

std::string DupCommand::run(const IParams* params)
{

    StringReader s(DNAContainer::getDnaData().find(atoi(params->getParams()[0].c_str()))->getDNA().getDnaSequence());
    DNAMetaData* dna = new DNAMetaData(params->getParams()[1],s);
    (DNAContainer::getDnaData()).insert(dna);

    std::stringstream ss;
    size_t id = DNAContainer::getDnaData().getIdByName(params->getParams()[1]);
    ss <<"[" << id << "] ";
    ss << params->getParams()[1] << ": "; // name
    ss << DNAContainer::getDnaData().find(id)->getDNA().getDnaSequence(); // dna
    return ss.str();
}

