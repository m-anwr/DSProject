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
	Node* getTail();
	void addFront(Requirement item);
	void addEnd (Requirement item);
	void removeFront();
	void printAll();
	bool isEmpty();
	int getSize();

};
#endif
