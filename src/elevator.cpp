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
            if( r.getTime() < upQ[i].getTime())  {
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
    int realTime = 0; //to simulate real time
    int floor = 0; //whick floor the elevator is on
    int upServed = 0; //indicating that all up requests are served
    int downServed = 0;//indicating that all down requests are served
    QQueue<pair> sim1; //holds up requests before changing direction
    QQueue<pair> sim2; //holds down requests before changing direction
    int size;

    //if there are still pending requests
    while(upServed!=upQ.size() || downServed !=downQ.size())
    {
        //if there are still pending requests in up queue
        if(upServed != upQ.size())
        {
            size = upQ.size();
            //loop on the up queue
            for(int i=0;i<size;i++)
            {
                //if request is still pending
                if(!upQ[i].getState())
                {
                    //it the request has not arrived yet
                    while(upQ[i].getTime()>realTime)
                    {
                        //increase time and floor
                        realTime++;
                        floor++;
                        if(floor>floorsNo-1) floor = floorsNo-1; //if floors more than max stop
                    }
                    //if request has arrived
                    if(upQ[i].getFrom()>=floor)
                    {
                        //add both floors with their times in order
                        pair p1(upQ[i].getFrom(),realTime+(upQ[i].getFrom()-floor));
                        pair p2(upQ[i].getTo(),realTime+(upQ[i].getTo()-upQ[i].getFrom())+(upQ[i].getFrom()-floor));
                        enQPair(sim1,p1);
                        enQPair(sim1,p2);
                        upQ[i].setState(true); //served
                        upServed++;
                    }
                }
            }
            //set last floor as the last served floor before changing direction
            if(!sim1.isEmpty()) floor = sim1[sim1.size()-1].getFloor();
        }
        //if the up queue is empty go to floor foor before starting to go down
        else
        {
            realTime += 4-floor;
            floor=4;
        }
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
                        pair p1(downQ[i].getFrom(),realTime+(-downQ[i].getFrom()+floor));
                        pair p2(downQ[i].getTo(),realTime+(downQ[i].getFrom()-downQ[i].getTo())+(-downQ[i].getFrom()+floor));
                        enQPair(sim2,p1);
                        enQPair(sim2,p2);
                        downQ[i].setState(true);
                        downServed++;
                    }
                }
            }
            if(!sim2.isEmpty()) floor = sim2[sim2.size()-1].getFloor();
        }
        else
        {
            realTime += floor;
            floor=0;
        }

        //append both queues in the final queue "not sorted"
        for(int i=0;i<sim1.size();i++)
            sim.enqueue(sim1[i]);
        sim1.clear();

        for(int i=0;i<sim2.size();i++)
            sim.enqueue(sim2[i]);
        sim2.clear();
    }

    //just for testing
    for(int i=0;i<sim.size();i++)
        qDebug()<<sim[i].getFloor()<<sim[i].getTime();
    return sim;
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
