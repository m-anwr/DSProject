#include "request.h"


Request::Request(int time, int from, int to)
{
    m_time = time;
    m_from = from;
    m_to = to;
    state = false;
}

int Request::time() const
{
    return m_time;
}

int Request::from() const
{
    return m_from;
}

int Request::to() const
{
    return m_to;
}

int Request::getDirection()
{
    if(m_from < m_to) return 0;
    else return 1;
}

bool Request::getState()
{
    return state;
}

void Request::setState(bool s)
{
    state = s;
}


