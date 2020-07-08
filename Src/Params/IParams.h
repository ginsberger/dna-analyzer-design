
#ifndef DNASEQUENCE_IPARAMS_H
#define DNASEQUENCE_IPARAMS_H

#include <iostream>
#include <vector>


class IParams {
    typedef std::vector<std::string> args;
public:
    void parseCommand(const std::string& commandLine);
    args getParams()const { return m_argsList;}
    void addParam(const std::string& param){m_argsList.push_back(param);}
    virtual bool isValidParams()=0;
    virtual ~IParams(){}
private:
    args m_argsList;
};



#endif //DNASEQUENCE_IPARAMS_H
