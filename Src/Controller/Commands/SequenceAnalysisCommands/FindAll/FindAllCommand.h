
#ifndef DNASEQUENCE_FINDALLCOMMAND_H
#define DNASEQUENCE_FINDALLCOMMAND_H

#include "../ISequenceAnalysisCommand.h"


class FindAllCommand : public ISequenceAnalysisCommand{
public:
    std::string run(const IParams* params);
};

#endif //DNASEQUENCE_FINDALLCOMMAND_H
