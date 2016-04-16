#include "Node.h"
Node::                  Node(Requirement r){require = r; next = 0;}
void Node::             setData(Requirement r)   { require = r; }
Requirement Node::      getData()               { return require; }
void Node::             setNext(Node* r)        { next= r; }
Node* Node::            getNext()               { return next; }
