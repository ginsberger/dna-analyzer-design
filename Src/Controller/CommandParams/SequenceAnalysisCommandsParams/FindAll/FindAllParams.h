
#ifndef DNASEQUENCE_FINDALLPARAMS_H
#define DNASEQUENCE_FINDALLPARAMS_H

#include "../../IParams.h"


class FindAllParams :public IParams{
public:
   FindAllParams(const std::vector<std::string>& params);

protected:
    void validetParams();
};



#endif //DNASEQUENCE_FINDALLPARAMS_H
