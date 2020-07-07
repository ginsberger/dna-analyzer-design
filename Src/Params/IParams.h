
#ifndef DNASEQUENCE_IPARAMS_H
#define DNASEQUENCE_IPARAMS_H

#include <iostream>
#include <vector>


class IParams {
    typedef std::vector<std::string> args;
public:
    IParams(const std::string& commandLine);
//    IParams& operator=(std::string& commandLine);
    args getParams()const { return m_argsList;}
    virtual bool isValidParams()=0;
private:
    args m_argsList;
};






#endif //DNASEQUENCE_IPARAMS_H
