#include "elevator.h"

Elevator::Elevator()
{
    floorsNo = 5;
}

Elevator::~Elevator()
{

}

void Elevator::set(Request r)
{
    bool repeated = false;
    if(r.getDirection() == 0)
    {
        for(int i=0;i<upQ.size();i++)
        {if(r == upQ[i]){repeated = true; break;}}

        for(int i = 0 ; i < upQ.count() ; ++i ) {
            if(repeated) return;
            if( r.getTime() < upQ[i].getTime())  {
                upQ.insert(i,r);
                return;
            }
        }
        upQ.enqueue(r);
    }

    else if(r.getDirection() == 1)
    {
        for(int i=0;i<downQ.size();i++)
        {if(r == downQ[i]){repeated = true; break;}}

        for(int i = 0 ; i < downQ.count() ; ++i ) {
            if(repeated) return;
            if( r.getTime() < downQ[i].getTime())  {
                downQ.insert(i,r);
                return;
            }
        }
        downQ.enqueue(r);
    }
}

QQueue<pair> Elevator::simulate()
{
    int realTime = 0;
    int floor = 0;
    int size;
    int upServed = 0;
    int downServed = 0;

    while(upServed!=upQ.size() && downServed !=downQ.size())
    {
        if(upServed != upQ.size())
        {
            size = upQ.size();
            for(int i=0;i<size;i++)
            {
                if(!upQ[i].getState())
                {
                    while(upQ[i].getTime()>realTime)
                    {
                        realTime++;
                        floor++;
                        if(floor>floorsNo-1) floor = floorsNo-1;
                    }
                    if(upQ[i].getFrom()>=floor)
                    {
                        sim.enqueue(pair(upQ[i].getFrom(),realTime));
                        sim.enqueue(pair(upQ[i].getTo(),realTime+(upQ[i].getTo()-upQ[i].getFrom())));
                        upQ[i].setState(true);
                        upServed++;
                    }
                }
            }
        }
        floor = sim[sim.size()-1].getFloor();
        realTime = sim[sim.size()-1].getTime();
        if(downServed!=downQ.size())
        {
            size = downQ.size();
            for(int i=0;i<size;i++)
            {
                if(!downQ[i].getState())
                {
                    while(downQ[i].getTime()>realTime)
                    {
                        realTime++;
                        floor--;
                        if(floor<0) floor = 0;
                    }
                    if(downQ[i].getFrom()<=floor)
                    {
                        sim.enqueue(pair(downQ[i].getFrom(),realTime));
                        sim.enqueue(pair(downQ[i].getTo(),realTime+(upQ[i].getTo()-upQ[i].getFrom())));
                        downQ[i].setState(true);
                        downServed++;
                    }
                }
            }
        }
        floor = sim[sim.size()-1].getFloor();
        realTime = sim[sim.size()-1].getTime();

        for(int i=0;i<sim.size();i++)
        qDebug()<<sim[i].getFloor()<<sim[i].getTime();
    }
    return sim;
}
