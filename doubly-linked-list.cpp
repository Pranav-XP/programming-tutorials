#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;  // Pointer to the previous node
};

class DoublyLinkedList {
private:
  Node *head = nullptr; // Pointer to the head of the list

public:
  void insertNodeFront(int n);
  void insertNodeEnd(int n);
  void insertNodeMiddle(int position, int n);
  void deleteNodeFront();
  void deleteNodeEnd();
  void deleteNodeMiddle(int key);
  void display();
};

void DoublyLinkedList::insertNodeFront(int n) {
  Node *newNode = new Node;
  newNode->data = n;
  newNode->next = head;
  newNode->prev = nullptr; // The previous node of new head is always null
  if (head != nullptr) {
    head->prev = newNode; // Old head's prev will now point to new node
  }
  head = newNode
