#include <cstddef>
#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int value) {
    data = value;
    left = NULL;
    right = NULL;
  }
};

class BinaryTree {
private:
  Node *root;

public:
  BinaryTree() { root = NULL; }
  Node *getRoot() { return root; }

  void setRoot(Node *node) {
    if (root == NULL) {
      root = node;
    } else {
      cout << "WARNING: Root is set as " << root->data << endl;
    }
  }

  void insertLeft(Node *parent, Node *child) {
    if (parent->left == NULL) {
      parent->left = child;
      cout << "Added " << child->data << " left of " << parent->data << endl;
    } else {
      cout << "WARNING: Left child already exists";
    }
  }

  void insertRight(Node *parent, Node *child) {
    if (parent->right == NULL) {
      parent->right = child;
      cout << "Added " << child->data << " right of " << parent->data << endl;
    } else {
      cout << "WARNING: Right child already exists" << endl;
    }
  }

  // In-order traversal (Left, Root, Right)
  void inorder(Node *node) {
    if (node == nullptr)
      return;                  // Base case
    inorder(node->left);       // Visit left subtree
    cout << node->data << " "; // Visit node
    inorder(node->right);      // Visit right subtree
  }

  // Pre-order traversal (Root, Left, Right)
  void preorder(Node *node) {
    if (node == nullptr)
      return;                  // Base case
    cout << node->data << " "; // Visit node
    preorder(node->left);      // Visit left subtree
    preorder(node->right);     // Visit right subtree
  }

  // Post-order traversal (Left, Right, Root)
  void postorder(Node *node) {
    if (node == nullptr)
      return;                  // Base case
    postorder(node->left);     // Visit left subtree
    postorder(node->right);    // Visit right subtree
    cout << node->data << " "; // Visit node
  }
};

int main() {
  BinaryTree tree;

  // Manually creating nodes
  Node *root = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);
  Node *node5 = new Node(5);
  Node *node6 = new Node(6);
  Node *node7 = new Node(7);

  // Set the root of the tree
  tree.setRoot(root);

  // Inserting nodes manually
  tree.insertLeft(root, node2);
  tree.insertRight(root, node3);
  tree.insertLeft(node2, node4);
  tree.insertRight(node2, node5);
  tree.insertLeft(node3, node6);
  tree.insertRight(node3, node7);

  // Performing different traversals
  cout << "In-order traversal: ";
  tree.inorder(root); // Should print: 4 2 5 1 6 3 7
  cout << endl;

  cout << "Pre-order traversal: ";
  tree.preorder(root); // Should print: 1 2 4 5 3 6 7
  cout << endl;

  cout << "Post-order traversal: ";
  tree.postorder(root); // Should print: 4 5 2 6 7 3 1
  cout << endl;

  return 0;
}
