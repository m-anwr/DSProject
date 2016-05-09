#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <QQueue>
#include <QDebug>
#include <QSet>

//local includes
#include "request.h"
#include "pair.h"

class Elevator
{
public:
    Elevator(QSet<Request> set);
    Elevator(QSet<Request> set,int x);
    ~Elevator();
    void set(Request r);
    void setFloors(int f){floorsNo = f;}
    QQueue<pair> simulate();

private:
    QQueue<Request> upQ;
    QQueue<Request> downQ;
    QQueue<pair> sim;
    int floorsNo,time,initialFloor;

private:
    void enQPair(QQueue<pair> &Q, pair r);
};

#endif // ELEVATOR_H
