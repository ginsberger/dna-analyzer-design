
#include "Parser.h"
#include <sstream>


void Parser::parseCommandLine(const std::string &commandLine) {
    std::stringstream ss(commandLine);
    std::string arg;

    if(!m_parse.empty())
    {
        m_parse.clear();
    }
    
    while(std::getline(ss, arg, ' ')) {
        if (arg.empty())
            continue;
        m_parse.push_back(arg);
    }
}

std::string Parser::getName() {
    return m_parse[0];
}

std::vector<std::string> Parser::getParams() {
    return std::vector<std::string>(m_parse.begin() + 1, m_parse.end());
}




