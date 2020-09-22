
#include "LenCommand.h"
#include <sstream>


std::string LenCommand::run(const IParams *params) {
    size_t id = atoi((params->getParams()[0].c_str()));
    DNAMetaData* dnaMetaData = DNAContainer::getDnaData().operator[](id);

    std::stringstream ss;
    ss << dnaMetaData->getDNA().getLength();
    return ss.str();
}
