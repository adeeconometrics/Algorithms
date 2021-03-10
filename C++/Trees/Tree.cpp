// tree

#include <iostream>

class Tree {
public:
  struct Node {
    int value;
    Node *left;
    Node *right;
  };

  Node *root;
  explicit Tree() { root = NULL; }

  void destroySubtree(Node *);
  void deleteNode(int, Node *&);
  void makeDeletion(Node *&);
  void displayInOrder(Node *);
  void displayInverse(Node *);
  void displayPreOrder(Node *);
  void displayPostOrder(Node *);
};

// insertions

// traversals
void Tree::displayInOrder(Node *_ptr) {
  if (_ptr != NULL) {
    displayInOrder(_ptr->left);
    std::cout << _ptr->value << std::endl;
    displayInOrder(_ptr->right);
  }
}

// inverse
void Tree::displayInverse(Node *_ptr) {
  if (_ptr != NULL) {
    displayInverse(_ptr->right);
    std::cout << _ptr->value << std::endl;
    displayInverse(_ptr->left);
  }
}

// post oder
void Tree::displayPostOrder(Node *_ptr) {
  if (_ptr != NULL) {
    displayInOrder(_ptr->left);
    std::cout << _ptr->value << std::endl;
    displayInOrder(_ptr->right);
  }
}
