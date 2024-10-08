#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev; // Pointer to the previous node
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
  newNode->prev = nullptr;
  
  if (head != nullptr) {
    head->prev = newNode;
  }
  head = newNode;
  cout << "Address: " << head << " Added node " << n << endl;
}

void DoublyLinkedList::insertNodeEnd(int n) {
  Node *newNode = new Node;
  newNode->data = n;
  newNode->next = nullptr;
  if (head == nullptr) {
    newNode->prev = nullptr;
    head = newNode;
  } else {
    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
  cout << "Address: " << newNode << " Added node: " << newNode->data << endl;
}

void DoublyLinkedList::insertNodeMiddle(int position, int n) {
  Node *newNode = new Node;
  newNode->data = n;
  newNode->next = nullptr;
  newNode->prev = nullptr;

  if (head == nullptr) {
    head = newNode;
  } else if (position <= 1) {
    delete newNode;
    DoublyLinkedList::insertNodeFront(n);
  } else {
    Node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
      temp = temp->next;
    }
    newNode->next = temp->next;
    if (temp->next != nullptr) {
      temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    cout << "Address: " << newNode << " Added node: " << newNode->data << endl;
  }
}

void DoublyLinkedList::display() {
  Node *temp = head;
  cout << "Address of first Node: " << head << " ";
  cout << "HEAD->";
  while (temp != nullptr) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

void DoublyLinkedList::deleteNodeFront() {
  if (head == nullptr) {
    cout << "List is empty" << endl;
    return;
  }

  Node *temp = head;
  head = head->next;

  if (head != nullptr) {
    head->prev = nullptr;
  }

  delete temp;
  cout << "Deleted node at the front\n";
}

void DoublyLinkedList::deleteNodeEnd() {
  if (head == nullptr) {
    cout << "List is empty" << endl;
    return;
  }

  Node *temp = head;
  if (temp->next == nullptr) {
    delete temp;
    head = nullptr;
    cout << "Deleted last node" << endl;
    return;
  }

  while (temp->next != nullptr) {
    temp = temp->next;
  }

  temp->prev->next = nullptr;
  delete temp;
  cout << "Deleted node at the end" << endl;
}

// Implement deleteNodeMiddle
void DoublyLinkedList::deleteNodeMiddle(int key) {
  if (head == nullptr) {
    cout << "List is empty" << endl;
    return;
  }

  Node *temp = head;
  while (temp != nullptr && temp->data != key) {
    temp = temp->next;
  }

  if (temp == nullptr) {
    cout << "Node not found" << endl;
    return;
  }

  if (temp->prev != nullptr) {
    temp->prev->next = temp->next;
  } else {
    head = temp->next; // If the node to delete is the head
  }

  if (temp->next != nullptr) {
    temp->next->prev = temp->prev;
  }

  delete temp;
  cout << "Deleted node with key: " << key << endl;
}

int main() {
  DoublyLinkedList list;
  
  // Inserting nodes into the list
  list.insertNodeEnd(1);
  list.insertNodeEnd(3);
  list.insertNodeEnd(5);
  list.insertNodeEnd(54);
  list.insertNodeEnd(7);
  list.insertNodeEnd(6);
  list.display();
  
  // Deleting a node from the list
  list.deleteNodeFront();
  list.deleteNodeEnd();
  list.deleteNodeMiddle(5);
  
  list.display();
  return 0;
}
