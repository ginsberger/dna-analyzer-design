
#ifndef DNASEQUENCE_LENCOMMAND_H
#define DNASEQUENCE_LENCOMMAND_H

#include "../ISequenceAnalysisCommand.h"


class LenCommand : public ISequenceAnalysisCommand{
public:
    std::string run(const IParams* params);
};



#endif //DNASEQUENCE_LENCOMMAND_H
