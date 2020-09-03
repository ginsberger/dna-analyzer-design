
#include "Status.h"

const char* Status::s_statuses [] = {"new","modified","up to date"};


Status::Status():m_status(s_statuses[E_New]){}


void Status::setStatus(EStatus status)
{
    m_status = s_statuses[status];
}

