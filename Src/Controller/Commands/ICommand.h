
#ifndef DNASEQUENCE_ICOMMAND_H
#define DNASEQUENCE_ICOMMAND_H

#include "../CommandParams/IParams.h"
#include "../../Model/Container/DNAContainer.h"

class ICommand {
public:
    virtual std::string run(const IParams* params)=0;
    virtual ~ICommand(){}
};


#endif //DNASEQUENCE_ICOMMAND_H
