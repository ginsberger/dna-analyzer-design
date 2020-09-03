//#include "../DNA/DNAData.h" // until implementation of ICommand

#ifndef DNASEQUENCE_ICOMMAND_H
#define DNASEQUENCE_ICOMMAND_H

#include "../CommandParams/IParams.h"
#include "../../DNA/Container/DNAContainer.h"

class ICommand {
public:
    virtual std::string run(const IParams* params)=0;
    virtual ~ICommand(){}
};


#endif //DNASEQUENCE_ICOMMAND_H
