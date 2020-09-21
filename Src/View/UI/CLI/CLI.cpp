
#include "CLI.h"
#include <sstream>
#include "../../Writer/ConsolWriter/ConsoleWriter.h"
#include "../../Reader/ConsolReader/ConsoleReader.h"
#include "../../../Controller/Factory/ParamsFactory/ParamsFactory.h"
#include "../../../Controller/Factory/CommandsFactory/CommandFactory.h"
#include "../../../Controller/Exeptions/OpenFileError.h"
#include "../../../Controller/Exeptions/InValidCommandName.h"
#include "../../../Controller/Exeptions/InValidParam/InValidParams.h"


void CLI::run() const{
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
