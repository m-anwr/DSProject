#include "elevator.h"

Elevator::Elevator(QSet<Request> set)
{
    floorsNo = 5;
    initialFloor = 0;

    QSetIterator<Request> i(set);
    while (i.hasNext())
    {
        this->set(i.next());
    }
}

Elevator::Elevator(QSet<Request> set,int x)
{
    floorsNo = 5;
    initialFloor = x;

    QSetIterator<Request> i(set);
    while (i.hasNext())
    {
        this->set(i.next());
    }
}

Elevator::~Elevator()
{

}

void Elevator::set(Request r)
{
    /*//converting queue into priority queue//*/
    bool repeated = false;
    if(r.getDirection() == 0) //up direction
    {
        //check if element is repeated
        for(int i=0;i<upQ.size();i++)
        {if(r == upQ[i]){repeated = true; break;}}

        //inserting elements with priority
        for(int i = 0 ; i < upQ.count() ; ++i ) {
            if(repeated) return;
            if( r.time() < upQ[i].time())  {
                upQ.insert(i,r);
                return;
            }
        }
        upQ.enqueue(r);
    }

    else if(r.getDirection() == 1) //down direction
    {
        for(int i=0;i<downQ.size();i++)
        {if(r == downQ[i]){repeated = true; break;}}

        for(int i = 0 ; i < downQ.count() ; ++i ) {
            if(repeated) return;
            if( r.time() < downQ[i].time())  {
                downQ.insert(i,r);
                return;
            }
        }
        downQ.enqueue(r);
    }
}

QQueue<pair> Elevator::simulate()
{
    realTime = 0; //to simulate real time
    floor = initialFloor; //whick floor the elevator is on
    upServed = 0; //indicating that all up requests are served
    downServed = 0;//indicating that all down requests are served
    //bool ini = true;

    while(upServed!=upQ.size() || downServed !=downQ.size())
    {
//        if(ini)
//        {
//            if(!upQ.isEmpty() && !downQ.isEmpty())
//            {
//                if(upQ[0].time() <= downQ[0].time())
//                {
//                    if(floor > upQ[0].from())
//                    {
//                        realTime += floor-upQ[0].from();
//                        floor = upQ[0].from();
//                    }
//                }
//                else
//                {
//                    if(floor < downQ[0].from())
//                    {
//                        realTime += downQ[0].from()-floor;
//                        floor = downQ[0].from();
//                        moveDown();
//                        moveUp();
//                        appendElevatorMovement();
//                    }
//                }
//            }
//            else if (!upQ.isEmpty() && downQ.isEmpty()) {
//                realTime += floor-upQ[0].from();
//                floor = upQ[0].from();
//            }
//            else if (upQ.isEmpty() && !downQ.isEmpty()) {
//                realTime += downQ[0].from()-floor;
//                floor = downQ[0].from();
//                moveDown();
//                moveUp();
//                appendElevatorMovement();
//            }
//            ini = false;
//        }

        moveUp();
        moveDown();
        appendElevatorMovement();
    }

    for(int i=0;i<sim.size();i++)
        qDebug()<<sim[i].getFloor()<<sim[i].getTime();
    return sim;
}

void Elevator::acceptRequest(int i, int dir)
{
    if(dir == 0) {
        pair p1(upQ[i].from(),realTime+(upQ[i].from()-floor));
        pair p2(upQ[i].to(),realTime+(upQ[i].to()-upQ[i].from())+(upQ[i].from()-floor));
        enQPair(sim1,p1);
        enQPair(sim1,p2);
        upQ[i].setState(true);
        upServed++;
    }
    else if (dir == 1) {
        pair p1(downQ[i].from(),realTime+(-downQ[i].from()+floor));
        pair p2(downQ[i].to(),realTime+(downQ[i].from()-downQ[i].to())+(-downQ[i].from()+floor));
        enQPair(sim2,p1);
        enQPair(sim2,p2);
        downQ[i].setState(true);
        downServed++;
    }
}

void Elevator::appendElevatorMovement()
{
    for(int i=0;i<sim1.size();i++)
        sim.enqueue(sim1[i]);
    sim1.clear();

    for(int i=0;i<sim2.size();i++)
        sim.enqueue(sim2[i]);
    sim2.clear();
}

void Elevator::moveUp()
{
    if(upServed != upQ.size())
    {
        size = upQ.size();
        for(int i=0;i<size;i++)
        {
            if(!upQ[i].getState())
            {
                int t=realTime;
                while(upQ[i].time()>t)
                {
                    t++;
                    floor++;
                    if(floor>floorsNo-1) floor=floorsNo-1;
                }
                realTime = t;
                if(upQ[i].from()>=floor)
                {
                    acceptRequest(i,0);
                }
            }
        }
        if(!sim1.isEmpty())
        {
            floor = sim1[sim1.size()-1].getFloor();
            realTime = sim1[sim1.size()-1].getTime();
        }
    }
    else
    {
        realTime += 4-floor;
        floor=4;
    }
}

void Elevator::moveDown()
{
    if(downServed!=downQ.size())
    {
        size = downQ.size();
        for(int i=0;i<size;i++)
        {
            if(!downQ[i].getState())
            {
                int t=realTime;
                while(downQ[i].time()>t)
                {
                    t++;
                    floor--;
                    if(floor<0) floor=0;
                }
                realTime = t;
                if(downQ[i].from()<=floor)
                {
                    acceptRequest(i,1);
                }
            }
        }
        if(!sim2.isEmpty())
        {
            floor = sim2[sim2.size()-1].getFloor();
            realTime = sim2[sim2.size()-1].getTime();
        }
    }
    else
    {
        realTime += floor;
        floor=0;
    }
}

//priority queue
void Elevator::enQPair(QQueue<pair> &Q, pair r)
{
    bool repeated = false;
    for(int i=0;i<Q.size();i++)
    {if(r == Q[i]){repeated = true; break;}}

    for(int i = 0 ; i < Q.count() ; ++i ) {
        if(repeated) return;
        if( r.getTime() < Q[i].getTime())  {
            Q.insert(i,r);
            return;
        }
    }
    Q.enqueue(r);
}
