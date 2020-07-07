
#include <sstream>
#include "Manager.h"
#include "../Reader/ConsoleReader.h"
#include "../Writer/ConsoleWriter.h"
#include "../Writer/IWriter.h"
#include "../Commands/CommandFactory.h"
#include "../Params/ParamsFactory.h"


void Manager::doAction()
{
    IReader* reader = new ConsoleReader;
    IWriter * writer = new ConsoleWriter;
while (true)
{
    std::cout << "> cmd >>> ";
    std::string commandLine = reader->read();
    std::stringstream ss(commandLine);
    std::string commandName;
    std::getline(ss, commandName, ' ');
    ICommand* command = CommandFactory::createCommand(commandName);
    IParams * parser = ParamsFactory::createParam(commandLine);
    std::string output = command->run(parser);
    writer->write(output.c_str());
}


}

