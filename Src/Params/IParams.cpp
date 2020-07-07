
#include "IParams.h"
#include <sstream>

IParams::IParams(const std::string &commandLine)
{
    if(!m_argsList.empty()) {
        m_argsList.clear();
    }

    std::stringstream ss(commandLine);
    std::string arg;
    std::getline(ss, arg, ' '); // No need for command name
    while(std::getline(ss, arg, ' ')) {
        m_argsList.push_back(arg);
    }
}


//IParams& IParams::operator=(std::string &commandLine) {
//
//}
