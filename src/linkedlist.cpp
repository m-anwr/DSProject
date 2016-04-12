#include "linkedlist.h"
#include <string>
using namespace std;
linkedList::linkedList()
{
	head = 0;
}
Node* linkedList::getHead()
{
	return head;
}
bool linkedList::isEmpty()
{
	if (head == 0)
		return true;
	return false;
}
void linkedList::Add(Requirement item)
{
	if (isEmpty())
	{
		Node* nw = new Node(item);
		nw->next = head;
		head = nw;

	}
	else
	{
		Node* tmp = head;
		while (tmp->get_next() != 0)
		{
			tmp = tmp->get_next();
		}
		Node* nw = new Node(item);
		tmp->set_next(nw);
	}
}
void linkedList:: printAll() // not complete > wait the require class
{
	Node* tmp = head;
	while (tmp != 0)
	{
	// cout << tmp->proc.get_require() <<endl;
	tmp = tmp->get_next();
	}
}

