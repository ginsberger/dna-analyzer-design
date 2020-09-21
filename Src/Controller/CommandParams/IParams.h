
#ifndef DNASEQUENCE_IPARAMS_H
#define DNASEQUENCE_IPARAMS_H

#include <iostream>
#include <vector>
#include "../../Utils/stringHash.h"


class IParams {
    typedef std::vector<std::string> args;
protected:
    typedef __gnu_cxx::hash_map<std::string, size_t> sequenceNameMap;

public:
    void parseCommand(const std::string& commandLine);
    args& getParams() { return m_argsList;}
    args getParams() const { return m_argsList;}
    void addParam(const std::string& param){m_argsList.push_back(param);}
    virtual void validetParams()=0;
    virtual ~IParams(){}
    static sequenceNameMap& getNameCounter() { return nameCounter;}

private:
    args m_argsList;
    static sequenceNameMap nameCounter;
};



#endif //DNASEQUENCE_IPARAMS_H
