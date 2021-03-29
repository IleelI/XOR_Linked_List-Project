#ifndef INC_2__XOR_LINKED_LIST_NODE_H
#define INC_2__XOR_LINKED_LIST_NODE_H
#include "main.h"

class Node {
private:
  Node* npx;
  int data;
public:
  explicit Node(int value);
  void SetNpx(Node* newNpx);
  Node* GetNpx() const;
  int GetData() const;
  ~Node();
};

Node* XOR(Node* prev, Node* next);

#endif
