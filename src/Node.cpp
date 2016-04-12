#include "Node.h"
Node :: Node(Requirement r)
{
	require = r; next = nullptr;
}
void Node::             setData(Requirement r)   { require = r; }
Requirement Node::        get_data()               { return require; }
void Node::             set_next(node* n)        { next = r; }
Node* Node::            get_next()               { return next; }
