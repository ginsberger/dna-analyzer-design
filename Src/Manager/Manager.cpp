
#include <sstream>
#include "Manager.h"
#include "../Reader/ConsolReader/ConsoleReader.h"
#include "../Writer/ConsolWriter/ConsoleWriter.h"
#include "../Writer/IWriter.h"
#include "../CLI/Factory/CommandsFactory/CommandFactory.h"
#include "../CLI/Factory/ParamsFactory/ParamsFactory.h"
#include "../Exeptions/InValidCommandName.h"
#include "../Exeptions/InValidParams.h"
#include "../Exeptions/OpenFileError.h"

void Manager::doAction()
{
    IReader* reader = new ConsoleReader;
    IWriter * writer = new ConsoleWriter;
    std::string commandLine;
while (commandLine != "exit")
{
    std::cout << "> cmd >>> ";

    try {
        commandLine = reader->read();
        std::stringstream ss(commandLine);
        std::string commandName;
        std::getline(ss, commandName, ' ');
        ICommand* command = CommandFactory::createCommand(commandName);
        IParams * parser = ParamsFactory::createParam(commandLine);
        std::string output = command->run(parser);
        writer->write(output.c_str());
    }
    catch (OpenFileError& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (InValidCommandName& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (InValidParams& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::invalid_argument& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

}

