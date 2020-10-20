
#include "CLI.h"
#include <sstream>
#include "../../Writer/ConsolWriter/ConsoleWriter.h"
#include "../../Reader/ConsolReader/ConsoleReader.h"
#include "../../../Controller/Factory/ParamsFactory/ParamsFactory.h"
#include "../../../Controller/Factory/CommandsFactory/CommandFactory.h"
#include "../../../Controller/Exeptions/OpenFileError.h"
#include "../../../Controller/Exeptions/InValidCommandName.h"
#include "../../../Controller/Exeptions/InValidParam/InValidParams.h"

void CLI::run(const CallBack<Manager>& callBack) const
{
    IReader* reader = new ConsoleReader;
    IWriter * writer = new ConsoleWriter;
    std::string commandLine;
    while (commandLine != "exit")
    {
        std::cout << "> cmd >>> ";

        try {
            commandLine = reader->read();
            m_parser->parseCommandLine(commandLine);
            /**/
            /*ICommand* command = CommandFactory::createCommand(m_parser->getName());
            IParams * parser = ParamsFactory::createParam(m_parser->getName(), m_parser->getParams());
            std::string output = command->run(parser);*/
            /*std::string output = callBack(commandName, commandParams)*/
            std::string commandName = m_parser->getName();
            std::vector<std::string> params = m_parser->getParams();
            std::string output = callBack(commandName, params);
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

