#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
};

class LinkedList {
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

void LinkedList::insertNodeFront(int n) {
  Node *newNode = new Node;
  newNode->data = n;
  newNode->next = head;
  head = newNode;
  cout << "Address: " << head << " Added node " << n << endl;
}

void LinkedList::insertNodeEnd(int n) {
  Node *newNode = new Node;
  newNode->data = n;
  newNode->next = nullptr;
  if (head == nullptr) {
    head = newNode;
  } else {
    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  cout << "Address: " << newNode << " Added node: " << newNode->data << endl;
}

// IMPLEMENT THIS.
void LinkedList::insertNodeMiddle(int position, int n) {
  Node *newNode = new Node;
  newNode->data = n;
  newNode->next = nullptr;
  if (head == nullptr) {
    head = newNode;
  } else if (position <= 1) {
    delete newNode;
    LinkedList::insertNodeFront(n);
  } else {
    Node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Address: " << newNode << " Added node: " << newNode->data << endl;
  }
}

void LinkedList::display() {
  Node *temp = head;
  cout << "Address of first Node: " << head << " ";
  cout << "HEAD->";
  while (temp != nullptr) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

// IMPLEMENT THIS
void LinkedList::deleteNodeMiddle(int key) {}

void LinkedList::deleteNodeFront() {
  // Check if List is empty
  if (head == nullptr) {
    cout << "List is empty" << endl;
    return;
  }
  // store head node. set head to the next node. delete the old start.
  Node *temp = head;
  head = head->next;
  delete temp;
  cout << "Deleted node at the front\n";
}

void LinkedList::deleteNodeEnd() {
  // Check if list is empty
  if (head == nullptr) {
    cout << "List is empty" << endl;
  }

  Node *newEnd = head;
  while (newEnd->next->next != nullptr) {
    newEnd = newEnd->next;
  }

  delete newEnd->next;
  newEnd->next = nullptr;
  cout << "Deleted at end" << endl;
}

int main(int argc, char *argv[]) {
  LinkedList list;
  // Creating Linked List
  list.insertNodeEnd(1);
  list.insertNodeEnd(3);
  list.insertNodeEnd(5);
  list.insertNodeEnd(54);
  list.insertNodeEnd(7);
  list.insertNodeEnd(6);
  list.display();
  return 0;
}
