
#ifndef DNASEQUENCE_SHOWCOMMAND_H
#define DNASEQUENCE_SHOWCOMMAND_H

#include "../IControlCommand.h"


class ShowCommand : public IControlCommand{
public:
    std::string run(const IParams* params);
};


#endif //DNASEQUENCE_SHOWCOMMAND_H
