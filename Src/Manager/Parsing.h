
#ifndef DNASEQUENCE_PARSING_H
#define DNASEQUENCE_PARSING_H

#include <iostream>
#include <vector>

class Parsing {
public:
    Parsing(std::string string);
    std::vector<std::string> getParams()const { return m_params;}
private:
    std::vector<std::string> m_params;
};


#endif //DNASEQUENCE_PARSING_H
