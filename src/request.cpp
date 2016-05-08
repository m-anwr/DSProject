#include "request.h"

Request::Request(int time_, int from_, int to_)
{
    time = time_;
    from = from_;
    to = to_;
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

bool Request::operator ==(Request &req)
{
    return ((this->getTime() == req.getTime()) && (this->getFrom() == req.getFrom()) && (this->getTo() == req.getTo()));
}


