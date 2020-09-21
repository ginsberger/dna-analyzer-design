#include "Controller/Manager/Manager.h"
#include "View/UI/CLI/CLI.h"
#include "Utils/SharedPointer/SharedPtr.h"


int main() {
    SharedPtr<UI> ui(new CLI);
    Manager manager(ui);
    manager.doAction();
    return 0;
}
