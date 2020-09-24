
#ifndef DNASEQUENCE_FINDCOMMAND_H
#define DNASEQUENCE_FINDCOMMAND_H

#include "../ISequenceAnalysisCommand.h"


class FindCommand : public ISequenceAnalysisCommand{
public:
    std::string run(const IParams* params);
};

#endif //DNASEQUENCE_FINDCOMMAND_H
