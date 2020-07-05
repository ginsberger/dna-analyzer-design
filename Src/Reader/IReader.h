
#ifndef DNASEQUENCE_IREADER_H
#define DNASEQUENCE_IREADER_H


class IReader {
public:
    virtual const char* read()const = 0 ;
    virtual ~IReader(){}
};


#endif //DNASEQUENCE_IREADER_H
