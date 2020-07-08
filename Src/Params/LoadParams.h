
#ifndef DNASEQUENCE_LOADPARAMS_H
#define DNASEQUENCE_LOADPARAMS_H

#include "IParams.h"
#include "../Utils/stringHash.h"

class LoadParams: public IParams {
public:
    LoadParams(const std::string& commandLine);
    /*virtual*/ bool isValidParams();
private:
    __gnu_cxx::hash_map<std::string, size_t> nameCounter;
};



#endif //DNASEQUENCE_LOADPARAMS_H
