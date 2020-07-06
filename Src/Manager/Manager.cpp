
#include "Manager.h"
#include "../Reader/ConsolReader.h"
#include "Parsing.h"
#include "../Commands/NewCommand.h"

void Manager::doAction()
{
    IReader* reader = new ConsolReader;
    std::string commandLine = reader->read();
    Parsing params(commandLine.substr(commandLine.find(' ')+1));
    NewCommand newCommand(params);
    newCommand.run(params);
}

