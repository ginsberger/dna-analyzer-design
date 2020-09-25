
#include "FindAllCommand.h"
#include "../../../../Utils/ConversionFunctions.h"


std::string FindAllCommand::run(const IParams *params) {
    size_t id = stringToNum((params->getParams()[0]));
    std::list<size_t> findIndexes= DNAContainer::getDnaData()[id]->getDNA().findAll(params->getParams()[1]);
    std::stringstream ss;

    for (std::list<size_t>::iterator itr = findIndexes.begin() ; itr != findIndexes.end() ; ++itr)
    {
        ss << *itr << " ";
    }

    return ss.str();
}
