#include "Node.h"
#define ptrXOR(NodePtr) reinterpret_cast<uintptr_t>(NodePtr)
//Constructor
Node::Node(int value) {
  this->data = value;
  this->npx = nullptr;
}
//Setters
void Node::SetNpx(Node* newNpx) {
  this->npx = newNpx;
}
//Getters
Node* Node::GetNpx() const {
  return this->npx;
}
int Node::GetData() const {
  return this->data;
}
//Deconstructor
Node::~Node() {
  this->npx = nullptr;
  this->data = NULL;
}
//Helper Functions
Node* XOR(Node* prev, Node* next) {
  Node* XOR = reinterpret_cast<Node*>(ptrXOR(prev)^ptrXOR(next));
  return XOR;
}