
#ifndef DNASEQUENCE_MANAGER_H
#define DNASEQUENCE_MANAGER_H

#include "../../View/UI/UI.h"
#include "../../View/CallBack/CallBack.h"
#include "../../Utils/SharedPointer/SharedPtr.h"
#include "../../Factory/ParamsFactory/ParamsFactory.h"
#include "../../Factory/CommandsFactory/CommandFactory.h"
#include <vector>


class Manager {
public:
    Manager(const SharedPtr<UI>& ui);
    void doAction();
    std::string execCommand(const std::string& commandName, std::vector<std::string>& params) const;
private:
    const SharedPtr<UI> m_ui;

};


inline Manager::Manager(const SharedPtr<UI>& ui) :m_ui(ui){}

inline void Manager::doAction()
{
    CallBack<Manager> callBack = makeCallBack(*this, &Manager::execCommand);
    m_ui->run(callBack);
}

inline std::string Manager::execCommand(const std::string& commandName, std::vector<std::string> &params) const {
    SharedPtr<ICommand> command = CommandFactory::getCommand(commandName);
    IParams * parser = ParamsFactory::createParam(commandName, params);
    return command->run(parser);
}


#endif //DNASEQUENCE_MANAGER_H
