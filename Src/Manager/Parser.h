
#ifndef DNASEQUENCE_PARSER_H
#define DNASEQUENCE_PARSER_H

#include <iostream>
#include <vector>

typedef std::vector<std::string> args;

class Parser {
public:
    Parser& operator=(std::string& command);
    args getParams()const { return m_argsList;}
private:
    args m_argsList;
};






#endif //DNASEQUENCE_PARSER_H
