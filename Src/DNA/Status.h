
#ifndef DNA_DESIGN_STATUS_H
#define DNA_DESIGN_STATUS_H

#include <string>

enum EStatus{
    E_New,
    E_Modified,
    E_UpToDate
};

class Status {

public:
    Status();
    std::string getStatus()const { return m_status;}
    void setStatus(EStatus status);

private:
    static const char* s_statuses [];
    const char* m_status;
};


#endif //DNA_DESIGN_STATUS_H
