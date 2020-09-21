//
// Created by a on 7/5/20.
//

#ifndef DNASEQUENCE_NEWCOMMAND_H
#define DNASEQUENCE_NEWCOMMAND_H

#include "../ICreationCommand.h"

class NewCommand :public ICreationCommand{
public:
    std::string run(const IParams* params);
};


#endif //DNASEQUENCE_NEWCOMMAND_H
