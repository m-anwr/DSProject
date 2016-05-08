#include "pair.h"

pair::pair(int f,int t)
{
    floor = f;
    time = t;
}

pair::~pair()
{

}

bool pair::operator ==(pair &pair)
{
    return ((this->getTime() == pair.getTime()) && (this->getFloor() == pair.getFloor()));
}


