
#include "Parser.h"
#include <sstream>


Parser& Parser::operator=(std::string &command) {
    if(!m_argsList.empty()) {
        m_argsList.clear();
    }

    std::stringstream ss(command);
    std::string arg;
    while(std::getline(ss, arg, ' ')) {
        m_argsList.push_back(arg);
    }
    return *this;
}
