//
// Created by a on 7/5/20.
//

#ifndef DNASEQUENCE_NEWCOMMAND_H
#define DNASEQUENCE_NEWCOMMAND_H

#include "../Manager/Parsing.h"

class NewCommand {
public:
    NewCommand(const Parsing& params);
    char* run(const Parsing& params);

private:
    Parsing m_params;
};


#endif //DNASEQUENCE_NEWCOMMAND_H
