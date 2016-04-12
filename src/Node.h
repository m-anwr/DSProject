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
	void set_data(Requirement r);
	Requirement get_data();
	void set_next(Node* n);
	Node* get_next();
	friend class linkedList;


};
class Requirement;
#endif
