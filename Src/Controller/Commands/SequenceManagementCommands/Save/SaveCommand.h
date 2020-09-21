
#ifndef DNASEQUENCE_SAVECOMMAND_H
#define DNASEQUENCE_SAVECOMMAND_H

#include "../IManagementCommand.h"

class SaveCommand : public IManagementCommand{
public:
    std::string run(const IParams* params);
};

#endif //DNASEQUENCE_SAVECOMMAND_H
