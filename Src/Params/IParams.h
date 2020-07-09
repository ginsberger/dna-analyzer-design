
#ifndef DNASEQUENCE_IPARAMS_H
#define DNASEQUENCE_IPARAMS_H

#include <iostream>
#include <vector>
#include "../Utils/stringHash.h"


class IParams {
    typedef std::vector<std::string> args;
public:
    void parseCommand(const std::string& commandLine);
    args getParams()const { return m_argsList;}
    void addParam(const std::string& param){m_argsList.push_back(param);}
    virtual bool isValidParams()=0;
    virtual ~IParams(){}
    static __gnu_cxx::hash_map<std::string, size_t>* getNameCounter() { return &nameCounter;}

private:
    args m_argsList;
    static __gnu_cxx::hash_map<std::string, size_t> nameCounter;

};



#endif //DNASEQUENCE_IPARAMS_H
