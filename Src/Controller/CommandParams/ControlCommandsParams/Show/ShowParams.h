
#ifndef DNASEQUENCE_SHOWPARAMS_H
#define DNASEQUENCE_SHOWPARAMS_H
#include "../../IParams.h"

class DNAMetaData;

class ShowParams : public IParams{
public:
    ShowParams(const std::vector<std::string>& params);

protected:
    void validetParams();

private:
    DNAMetaData* checkExistingIdOrName();
};


#endif //DNASEQUENCE_SHOWPARAMS_H
