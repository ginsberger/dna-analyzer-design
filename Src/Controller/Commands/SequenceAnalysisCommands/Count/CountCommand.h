
#ifndef DNASEQUENCE_COUNTCOMMAND_H
#define DNASEQUENCE_COUNTCOMMAND_H

#include "../ISequenceAnalysisCommand.h"


class CountCommand : public ISequenceAnalysisCommand{
public:
    std::string run(const IParams* params);
};

#endif //DNASEQUENCE_COUNTCOMMAND_H
