
#ifndef DNASEQUENCE_PARSER_H
#define DNASEQUENCE_PARSER_H

#include <iostream>
#include <vector>

class Parser {
public:
    void parseCommandLine(const std::string& commandLine);
    std::string getName();
    std::vector<std::string> getParams();

private:
    std::vector<std::string> m_parse;
};


#endif //DNASEQUENCE_PARSER_H
