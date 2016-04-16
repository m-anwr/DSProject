#ifndef Node_n
#define Node_n
#include "Requirement.h"

class Node
{
private:
	Requirement require;
	Node* next;

public:
	Node(Requirement r);
	void setData(Requirement r);
	Requirement getData();
	void setNext(Node* n);
	Node* getNext();
	friend class linkedList;


};
class Requirement;
#endif
