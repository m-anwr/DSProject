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
	Node* get_head();
	Node* get_tail();
	void add_front(Requirement item);
	void add_end (Requirement item);
	void remove_front();
	void printAll();
	bool isEmpty();
	int get_size();

};
#endif
