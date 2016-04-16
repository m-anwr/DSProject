#include "queue.h"
Queue::Queue() {;}
void Queue::enqueue(Requirement item)
{
    addEnd(item);
}
Requirement Queue::dequeue()
{
    if (isEmpty())
    {;}//return NULL;}// not complete as the code blocks don't support the NULL
    else
    {
        Requirement temp = getDataOfHead();
        removeFront();
        return temp;
    }
}
Requirement Queue:: getDataOfHead()
{
    if (isEmpty())
        {;}//return NULL;}//NOT COMPLETE
    else
        {return getHead()->getData();}
}
Requirement Queue::getDataOfTail()
{
    if (isEmpty())
        {;}//return NULL;}
    else
        {return getTail()->getData();}
}

