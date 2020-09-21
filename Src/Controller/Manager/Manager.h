
#ifndef DNASEQUENCE_MANAGER_H
#define DNASEQUENCE_MANAGER_H

#include "../../View/UI/UI.h"
#include "../../Utils/SharedPointer/SharedPtr.h"

class Manager {
public:
    Manager(const SharedPtr<UI>& ui);
    void doAction();

private:
    const SharedPtr<UI> m_ui;

};


inline Manager::Manager(const SharedPtr<UI>& ui) :m_ui(ui){}

inline void Manager::doAction()
{
    m_ui->run();
}


#endif //DNASEQUENCE_MANAGER_H
