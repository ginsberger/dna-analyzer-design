
#include "CountCommand.h"
#include "../../../../Utils/ConversionFunctions.h"


std::string CountCommand::run(const IParams *params) {
    size_t id = stringToNum((params->getParams()[0]));
    size_t count = DNAContainer::getDnaData()[id]->getDNA().count(params->getParams()[1]);
    std::stringstream ss;
    ss << count;

    return ss.str();
}
