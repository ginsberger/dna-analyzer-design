
#ifndef DNASEQUENCE_SLICECOMMAND_H
#define DNASEQUENCE_SLICECOMMAND_H

#include "../IManipulationCommand.h"

class SliceCommand :public IManipulationCommand{
public:
    std::string run(const IParams* params);
};

#endif //DNASEQUENCE_SLICECOMMAND_H
