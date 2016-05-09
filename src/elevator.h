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
    QQueue<pair> sim,sim1,sim2;
    QQueue<pair> draw;
    int floorsNo,time,initialFloor;
    int realTime,floor;
    int upServed,downServed;
    int size;

private:
    void acceptRequest(int i,int dir);
    void appendElevatorMovement();
    void moveUp();
    void moveDown();
    void enQPair(QQueue<pair> &Q, pair r);
    void Draw();
};

#endif // ELEVATOR_H
