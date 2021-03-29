#include "List.h"

List::List() {
  head = tail = curr = prev = nullptr;
}

void List::AddFirstNode(int value) {
  Node* newNode = new Node(value);
  this->head = this->tail = this->curr = newNode;
}
void List::AddAtStart(int value) {
  if (this->head == nullptr)
    AddFirstNode(value);
  else {
    Node* newNode = new Node(value);
    newNode->SetNpx(XOR(nullptr,head));
    head->SetNpx(XOR(newNode,head->GetNpx()));
    if (head == curr)
      prev = newNode;
    std::swap(head,newNode);
  }
}
void List::AddAtEnd(int value) {
  if (head == nullptr)
    AddFirstNode(value);
  else {
    Node* newNode = new Node(value);
    newNode->SetNpx(XOR(tail, nullptr));
    tail->SetNpx(XOR(tail->GetNpx(),newNode));
    tail = newNode;
  }
}
void List::AddAtPrev(int value) {
  if (head == nullptr)
    AddFirstNode(value);
  else {
    if (curr == head)
      AddAtStart(value);
    else if (curr == tail) {
      Node *newNode = new Node(value);
      Node* oldPrev = XOR(tail->GetNpx(), nullptr);
      newNode->SetNpx(XOR(oldPrev,tail));
      Node* clearPrevNpx = XOR(oldPrev->GetNpx(),tail);
      oldPrev->SetNpx(XOR(clearPrevNpx,newNode));
      Node* clearCurrNpx = XOR(oldPrev,tail->GetNpx());
      tail->SetNpx(XOR(clearCurrNpx,newNode));
      prev = newNode;
    }
    else {
      Node* newNode = new Node(value);
      newNode->SetNpx(XOR(prev,curr));
      curr->SetNpx(XOR(XOR(prev,curr->GetNpx()),newNode));
      prev->SetNpx(XOR(XOR(prev->GetNpx(),curr),newNode));
      prev = newNode;
    }
  }
}

void List::RemoveFromStart() {
  if (head == nullptr)
    return;
  else {
    if (head == tail) // <- If list has only 1 node.
      ResetList();
    else {
      Node* nextNode = XOR(head->GetNpx(), nullptr);
      nextNode->SetNpx(XOR(nullptr,XOR(nextNode->GetNpx(),head)));
      if (head == curr) {
        curr = tail;
        prev = XOR(curr->GetNpx(), nullptr);
      }
      else if (head == prev)
        prev = nullptr;
      head = nextNode;
    }
  }
}
void List::RemoveFromEnd() {
  if (head == nullptr)
    return;
  else {
    if (head == tail)
      ResetList();
    else {
      Node* prevNode = XOR(tail->GetNpx(), nullptr);
      prevNode->SetNpx(XOR(XOR(prevNode->GetNpx(),tail), nullptr));
      if (tail == curr) {
        curr = prevNode;
        prev = XOR(prevNode->GetNpx(), nullptr);
      }
      tail = prevNode;
    }
  }
}
void List::RemoveCurr() {
  if (head == nullptr)
    return;
  else {
    if (curr == head)
      RemoveFromStart();
    else if (curr == tail)
      RemoveFromEnd();
    else {
      Node* nextNode = XOR(prev,curr->GetNpx());
      prev->SetNpx(XOR(XOR(prev->GetNpx(),curr),nextNode));
      nextNode->SetNpx(XOR(prev,XOR(curr,nextNode->GetNpx())));
      curr = prev;
      prev = XOR(curr->GetNpx(),nextNode);
    }
  }
}
void List::RemoveValues(int query) {
  if (head == nullptr)
    return;
  else {
    if (head == tail && head->GetData() == query) {
      ResetList();
      return;
    }
    Node* act = head;
    Node* pre = nullptr;
    do {
      if (act->GetData() == query) {
        Node* next = XOR(act->GetNpx(),pre);
        if (act == head)
          RemoveFromStart();
        else if (act == tail)
          RemoveFromEnd();
        else {
          pre->SetNpx(XOR(XOR(pre->GetNpx(),act),next));
          next->SetNpx(XOR(XOR(next->GetNpx(),act),pre));
          if (act == curr)
            curr = pre;
          else if (act == prev)
            prev = pre;
        }
        act = next;
      }
      else {
        Node* tmp = act;
        act  = XOR(act->GetNpx(),pre);
        pre = tmp;
      }
    } while (act != nullptr);
  }
}

void List::Traverse(Node* act, Node* pre) {
  do {
    printf("%d ", act->GetData());
    Node* tmp = act;
    act = XOR(pre, act->GetNpx());
    pre = tmp;
  } while (act != nullptr);
 printf("\n");
}
void List::TraverseForward() const {
  if (head == nullptr) {
    printf("NULL\n");
    return;
  }
  Node* act = head;
  Node* pre = nullptr;
  Traverse(act,pre);
}
void List::TraverseBackward() const {
  if (head == nullptr || tail == nullptr) {
    printf("NULL\n");
    return;
  }
  Node* act = tail;
  Node* pre = nullptr;
  Traverse(act,pre);
}

void List::ResetList() {
  this->head = nullptr;
  this->tail = nullptr;
  this->curr = nullptr;
  this->prev = nullptr;
}
List::~List() {
  this->ResetList();
  delete head;
  delete tail;
  delete curr;
  delete prev;
}

void List::Head() const {
  if (this->head == nullptr) {
    std::cout << "NULL" << std::endl;
    return;
  }
  std::cout << this->head->GetData() << std::endl;
}
void List::Tail() const {
  if (this->tail == nullptr) {
    std::cout << "NULL" << std::endl;
    return;
  }
  std::cout << this->tail->GetData() << std::endl;
}
void List::Curr() const {
  if (curr == nullptr) {
    printf("NULL\n");
    return;
  }
  printf("%d\n",curr->GetData());
}
void List::Prev() {
  if (curr == nullptr)
    printf("NULL\n");
  else {
    if (head == tail)
      printf("%d\n",head->GetData());
    else {
      if (prev == head) {
        curr = prev;
        prev = nullptr;
        printf("%d\n",curr->GetData());
      }
      else if (curr == head) {
        curr = tail;
        prev = XOR(tail->GetNpx(), nullptr);
        printf("%d\n",tail->GetData());
      }
      else {
        Node *next = curr;
        curr = prev;
        prev = XOR(curr->GetNpx(), next);
        printf("%d\n",curr->GetData());
      }
    }
  }
}
void List::Next() {
  if (curr == nullptr) {
    printf("NULL\n");
    return;
  }
  else {
    if (head == tail) // Only 1 element
      printf("%d\n",head->GetData());
    else {
      Node *next = XOR(prev, curr->GetNpx());
      if (curr == tail) {
        printf("%d\n",head->GetData());
        curr = head;
        prev = nullptr;
      }
      else {
        prev = curr;
        curr = next;
        printf("%d\n",next->GetData());
      }
    }
  }
}