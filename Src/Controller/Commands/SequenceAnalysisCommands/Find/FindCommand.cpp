
#include "FindCommand.h"
#include "../../../../Utils/ConversionFunctions.h"


std::string FindCommand::run(const IParams *params) {
    size_t id = stringToNum((params->getParams()[0]));
    size_t findIndex = DNAContainer::getDnaData()[id]->getDNA().find(params->getParams()[1]);
    std::stringstream ss;
    ss << findIndex;

    return ss.str();
}
