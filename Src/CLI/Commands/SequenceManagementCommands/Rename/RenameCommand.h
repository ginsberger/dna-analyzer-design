
#ifndef DNASEQUENCE_RENAMECOMMAND_H
#define DNASEQUENCE_RENAMECOMMAND_H

#include "../IManagementCommand.h"

class RenameCommand : public IManagementCommand{
public:
    std::string run(const IParams* params);
};


#endif //DNASEQUENCE_RENAMECOMMAND_H
