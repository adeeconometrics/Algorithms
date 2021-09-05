// test tree

#include <iostream>

class Tree {
  struct Node {
    int val;
    Node *left, *right;
  };

  Node *root;

public:
  Tree() {}

  void insert_element(int num) {
    Node *node = new Node;
    node->val = num;
    node->left = node->right = NULL;

    if (root == NULL)
      root = node;
    else {
      Node *ptr = root;
      while (ptr != NULL) {
        if (num < ptr->val) {
          if (ptr->left)
            ptr = ptr->left;
          else {
            ptr->left = node;
            break;
          }
        } else if (num > ptr->val) {
          if (ptr->right)
            ptr = ptr->right;
          else {
            ptr->right = node;
            break;
          }
        } else {
          break;
        }
      }
      if (ptr->val < num)
        node = ptr->right;
      if (ptr->val > num)
        node = ptr->left;
    }
  }

  void inorder(Node *node) {
    if (node == NULL)
      return;
    inorder(node->left);
    std::cout << node->val << " ";
    inorder(node->right);
  }

  void display() { inorder(root); }
};

int main() {
  Tree t;
  t.insert_element(5);
  t.insert_element(8);
  t.insert_element(3);
  t.insert_element(12);
  t.insert_element(9);
  t.display();
}