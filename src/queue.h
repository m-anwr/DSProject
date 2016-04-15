#ifndef queue_q
#define queue_q
class Queue : public linkedList
{
private :
    Requirement require;
public :
    Queue( );
    void enqueue(Requirement item);
    Requirement dequeue( );
    Requirement get_data_of_head( );
    Requirement get_data_of_tail( );


};
#endif // queue_q

