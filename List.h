#ifndef INC_2__XOR_LINKED_LIST_LIST_H
#define INC_2__XOR_LINKED_LIST_LIST_H
#include "Node.h"
#include "main.h"

class List {
protected:
  Node* head;
  Node* tail;
  Node* curr;
  Node* prev;
  static void Traverse(Node* act, Node* pre);
public:
  List();
  void AddFirstNode(int value);
  void AddAtStart(int value);
  void AddAtEnd(int value);
  void AddAtPrev(int value);

  void RemoveFromStart();
  void RemoveFromEnd();
  void RemoveValues(int query);
  void RemoveCurr();

  void TraverseForward() const;
  void TraverseBackward() const;
  void Head() const;
  void Tail() const;
  void Curr() const;
  void Prev();
  void Next();
  void ResetList();
  ~List();
};

#endif
