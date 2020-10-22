
#ifndef DNASEQUENCE_COMMANDFACTORY_H
#define DNASEQUENCE_COMMANDFACTORY_H

#include <string>
#include "../../Commands/ICommand.h"
#include <map>
#include "../../../Utils/SharedPointer/SharedPtr.h"


class CommandFactory {
public:
    static SharedPtr<ICommand> getCommand(const std::string &command);
private:
    static std::map<std::string, SharedPtr<ICommand> > m_commandsMap;
    static std::map<std::string, SharedPtr<ICommand>> init();
};


#endif //DNASEQUENCE_COMMANDFACTORY_H
