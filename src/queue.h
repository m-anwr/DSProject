#ifndef queue_q
#define queue_q
#include "linkedlist.h"
class Queue : public linkedList
{
private :
    Requirement require;
public :
    Queue( );
    void enqueue(Requirement item);
    Requirement dequeue( );
    Requirement getDataOfHead( );
    Requirement getDataOfTail( );


};
#endif // queue_q

