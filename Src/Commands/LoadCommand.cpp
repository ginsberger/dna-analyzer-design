
#include "LoadCommand.h"
#include "../Reader/StringReader.h"
#include <sstream>
#include "../Reader/FileReader.h"

std::string LoadCommand::run(const IParams* params)
{
    std::cout<<params->getParams()[0].c_str() << std::endl;
    FileReader reader(params->getParams()[0].c_str());
    StringReader s(reader.read());
//    std::cout << "aaaaaaa" << reader.read() << " bbbbbb" << s.read();
    DNAMetaData* dna = new DNAMetaData(params->getParams()[1],s);
    (DNAContainer::getDnaData()).insert(dna);

    std::stringstream ss;
    size_t id = DNAContainer::getDnaData().getIdByName(params->getParams()[1]);
    ss <<"[" << id << "] ";
    ss << params->getParams()[1] << ": "; // name
    ss << DNAContainer::getDnaData().find(id)->getDNA().getDnaSequence();
//    ss << reader.read(); // dna
    return ss.str();
}

