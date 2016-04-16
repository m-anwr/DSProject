#include "linkedlist.h"
#include <string>
using namespace std;
linkedList::linkedList()
{
	head = 0;
}
bool linkedList::isEmpty()
{   if (head ==0) return true;
    else          return false;
}

Node* linkedList::getHead()
{
	return head;
}
Node* linkedList::getTail()
{
    Node* temp = head;
    while (temp->next!=0)
    {
        temp= temp->next;
    }
    return temp;
}

void linkedList::addFront(Requirement item)
{
    Node* nw = new Node (item);
    nw->next = head;
    head = nw;
}
void linkedList::addEnd(Requirement item)
{
    if (isEmpty())
    {
        addFront(item);
    }
    else
    {
        Node* temp = head;
        while (temp->next!=0)
        {
            temp = temp->next ;
        }
        Node* nw = new Node (item);
       temp->next=nw;
    }

}
void linkedList:: removeFront ()
{
    if (isEmpty())
    {return;}
    else
    {
    Node* temp = head;
    head = head->getNext();
    delete temp;
    }
}
int linkedList:: getSize()
{

    int count_ = 0;
    Node* temp =head;
    while (temp !=0)
    {
        count_++;
        temp= temp->next;
    }
    return count_;
}
void linkedList:: printAll() // not complete > wait the require class
{
	Node* tmp = head;
	while (tmp != 0)
	{
	// cout << tmp->proc.get_require() <<endl;
	tmp = tmp->getNext();
	}
}

