
#ifndef DNASEQUENCE_LOADCOMMAND_H
#define DNASEQUENCE_LOADCOMMAND_H

#include "ICreationCommand.h"

class LoadCommand :public ICreationCommand{
public:
    std::string run(const IParams* params);
};



#endif //DNASEQUENCE_LOADCOMMAND_H
