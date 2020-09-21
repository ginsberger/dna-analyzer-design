//
// Created by a on 6/30/20.
//

#ifndef DNASEQUENCE_IWRITER_H
#define DNASEQUENCE_IWRITER_H


class IWriter {
public:
    virtual void write(const char* data)const = 0 ;
    virtual ~IWriter(){}
};


#endif //DNASEQUENCE_IWRITER_H
