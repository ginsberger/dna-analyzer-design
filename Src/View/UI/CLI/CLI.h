
#ifndef DNASEQUENCE_TERMINAL_H
#define DNASEQUENCE_TERMINAL_H

#include "../UI.h"
#include "../../../Utils/SharedPointer/SharedPtr.h"
#include "Parser.h"


class CLI : public UI{
public:
    CLI(): m_parser(SharedPtr<Parser>(new Parser)){}
    /*virtual*/ void run(const CallBack<Manager>& callBack) const;

private:
    SharedPtr<Parser> m_parser;
};


#endif //DNASEQUENCE_TERMINAL_H
