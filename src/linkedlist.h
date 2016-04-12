#ifndef linkedlist_l
#define linkedlist_l
#include "Node.h"
#include "Requirement.h"
class linkedList
{
private:
	Node* head;

public:
	linkedList();
	Node* getHead();
	bool isEmpty();
	void Add(Requirement item);
	void printAll();

};
#endif
