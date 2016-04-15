#include "Node.h"
Node::                  Node(Requirement r){require = r; next = 0;}
void Node::             set_data(Requirement r)   { require = r; }
Requirement Node::      get_data()               { return require; }
void Node::             set_next(Node* r)        { next= r; }
Node* Node::            get_next()               { return next; }
