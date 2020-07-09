
#ifndef DNASEQUENCE_DUPCOMMAND_H
#define DNASEQUENCE_DUPCOMMAND_H


#include "ICreationCommand.h"

class DupCommand :public ICreationCommand{
public:
    std::string run(const IParams* params);
};


#endif //DNASEQUENCE_DUPCOMMAND_H
