#include "request.h"

Request::Request(int time_, int from_, int to_)
{
    time = time_;
    from = from_;
    to = to_;
    state = false;
}

int Request::getTime()
{
    return time;
}

int Request::getFrom()
{
    return from;
}

int Request::getTo()
{
    return to;
}

int Request::getDirection()
{
    if(from < to) return 0;
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

bool Request::operator ==(Request &req)
{
    return ((this->getTime() == req.getTime()) && (this->getFrom() == req.getFrom()) && (this->getTo() == req.getTo()));
}


