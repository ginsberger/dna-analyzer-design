
#include "IParams.h"
#include <sstream>


IParams& IParams::operator=(std::string &commandLine) {
    if(!m_argsList.empty()) {
        m_argsList.clear();
    }

    std::stringstream ss(commandLine);
    std::string arg;
    while(std::getline(ss, arg, ' ')) {
        m_argsList.push_back(arg);
    }
    return *this;
}
