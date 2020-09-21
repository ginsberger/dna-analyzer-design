
#ifndef DNASEQUENCE_EMPTYCOMMAND_H
#define DNASEQUENCE_EMPTYCOMMAND_H

#include "../ICommand.h"


class EmptyCommand: public ICommand {
public:
    std::string run(const IParams* params){ return "";}
};


#endif //DNASEQUENCE_EMPTYCOMMAND_H
