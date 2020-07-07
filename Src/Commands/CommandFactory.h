
#ifndef DNASEQUENCE_COMMANDFACTORY_H
#define DNASEQUENCE_COMMANDFACTORY_H

#include <string>
#include "ICommand.h"

class CommandFactory {
public:
    static ICommand* createCommand(const std::string& command);
};


#endif //DNASEQUENCE_COMMANDFACTORY_H
