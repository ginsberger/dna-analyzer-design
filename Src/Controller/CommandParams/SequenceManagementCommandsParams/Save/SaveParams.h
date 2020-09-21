
#ifndef DNASEQUENCE_SAVEPARAMS_H
#define DNASEQUENCE_SAVEPARAMS_H

#include "../../IParams.h"
#include "../../../../Model/Container/DNAContainer.h"


class SaveParams :public IParams{
public:
    SaveParams(const std::string& commandLine);

protected:
    void validetParams();

private:
    DNAMetaData* getMetaDataByIdOrName();
};


#endif //DNASEQUENCE_SAVEPARAMS_H
