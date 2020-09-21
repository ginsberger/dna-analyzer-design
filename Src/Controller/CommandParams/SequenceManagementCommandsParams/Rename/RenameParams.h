
#ifndef DNASEQUENCE_RENAMEPARAMS_H
#define DNASEQUENCE_RENAMEPARAMS_H

#include "../../IParams.h"

class RenameParams :public IParams{
public:
    RenameParams(const std::vector<std::string>& params);

protected:
    void validetParams();
};


#endif //DNASEQUENCE_RENAMEPARAMS_H
