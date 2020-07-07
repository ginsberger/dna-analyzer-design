//#include "../DNA/DNAData.h" // until implementation of ICommand

#ifndef DNASEQUENCE_ICOMMAND_H
#define DNASEQUENCE_ICOMMAND_H

#include "../Params/IParams.h"
#include "../DNA/DNAContainer.h"

class ICommand {
public:
    virtual std::string run(const IParams* params)=0;
    virtual ~ICommand(){}
};


#endif //DNASEQUENCE_ICOMMAND_H
