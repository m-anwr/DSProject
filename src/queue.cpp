#include "queue.h"
Queue::Queue() {;}
void Queue::enqueue(Requirement item)
{
    add_end(item);
}
Requirement Queue::dequeue()
{
    if (isEmpty())
    {return NULL;}
    else
    {
        Requirement temp = get_data_of_head();
        remove_front();
        return temp;
    }
}
Requirement Queue:: get_data_of_head()
{
    if (isEmpty())
        {return NULL;}
    else
        {return get_head()->get_data();}
}
Requirement Queue::get_data_of_tail()
{
    if (isEmpty())
        {return NULL;}
    else
        {return get_tail()->get_data();}
}

