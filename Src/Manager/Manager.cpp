
#include <sstream>
#include "Manager.h"
#include "../Reader/ConsoleReader.h"
#include "../Writer/ConsoleWriter.h"
#include "../Writer/IWriter.h"
#include "../Commands/CommandFactory.h"
#include "../Params/ParamsFactory.h"
#include "../Exeptions/InValidCommandName.h"
#include "../Exeptions/InValidParams.h"


void Manager::doAction()
{
    IReader* reader = new ConsoleReader;
    IWriter * writer = new ConsoleWriter;
    std::string commandLine;
while (commandLine != "exit")
{
    std::cout << "> cmd >>> ";
    commandLine = reader->read();
    std::stringstream ss(commandLine);
    std::string commandName;
    std::getline(ss, commandName, ' ');
    try {
        ICommand* command = CommandFactory::createCommand(commandName);
        IParams * parser = ParamsFactory::createParam(commandLine);
        std::string output = command->run(parser);
        writer->write(output.c_str());
    }
    catch (InValidCommandName& ex)
    {
        std::cout << ex.what();
    }
    catch (InValidParams& ex)
    {
        std::cout << ex.what();
    }
    catch (std::invalid_argument& ex)
    {
        std::cout << ex.what();
    }
}

}

