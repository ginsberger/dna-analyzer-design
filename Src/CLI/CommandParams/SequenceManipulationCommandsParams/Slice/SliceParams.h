
#ifndef DNASEQUENCE_SLICEPARAMS_H
#define DNASEQUENCE_SLICEPARAMS_H

#include "../../IParams.h"


class SliceParams :public IParams{
public:
    SliceParams(const std::string& commandLine);

protected:
    void validetParams();
};


#endif //DNASEQUENCE_SLICEPARAMS_H
