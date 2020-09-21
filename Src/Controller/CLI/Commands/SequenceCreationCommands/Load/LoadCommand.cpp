
#include "LoadCommand.h"
#include <sstream>
#include "../../../../../Model/Container/DNAContainer.h"
#include "../../../../../View/Reader/StringReader/StringReader.h"
#include "../../../../../View/Reader/FileReader/FileReader.h"

std::string LoadCommand::run(const IParams* params)
{
    std::cout<<params->getParams()[0].c_str() << std::endl;
    FileReader reader(params->getParams()[0].c_str());
    StringReader s(reader.read());
    DNAMetaData* dna = new DNAMetaData(params->getParams()[1],s);
    (DNAContainer::getDnaData()).insert(dna);

    std::stringstream ss;
    size_t id = DNAContainer::getDnaData().getIdByName(params->getParams()[1]);
    std::string name = params->getParams()[1];
    std::string DNA = DNAContainer::getDnaData()[id]->getDNA().getDnaSequence();
    size_t len = DNA.size();
    if(len >= 40)
    {
        DNA =  DNA.substr(0, 32) + "..." + DNA.substr(len - 3, len);
    }
    ss <<"[" << id << "] " << name << ": " << DNA;

    return ss.str();
}


