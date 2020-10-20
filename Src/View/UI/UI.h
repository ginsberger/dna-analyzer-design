
#ifndef DNASEQUENCE_UI_H
#define DNASEQUENCE_UI_H

#include "../../CallBack/CallBack.h"

class Manager;


class UI {
public:
    virtual void run(const CallBack<Manager>& callBack)const =0;
    virtual ~UI(){};
};


#endif //DNASEQUENCE_UI_H
