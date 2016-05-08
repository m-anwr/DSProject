#include "request.h"

Request::Request(int time, int from, int to)
{
    m_time = time;
    m_from = from;
    m_to = to;
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
