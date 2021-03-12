// modified tree -- format and implement level-order traversal

#include <iostream>

class Tree {
private:
  struct Node {
    int value;
    Node *left;
    Node *right;
  };

  Node *root;

public:
  explicit Tree() { root = NULL; }

  void insert_node(Node *node);
  void insert_element(int element);
  void traverse_inorder(Node *node);
  void traverse_inverse(Node *node);
  void traverse_postorder(Node *node);
  void traverse_preorder(Node *node);

  void show_in_order() { Tree::traverse_inorder(root); }
  Node *delete_element(Node *ptr, int element);
  Node *find_max(Node *ptr);
  Node *find_min(Node *ptr);

  bool find_node(int element);
  Node *_root() { return root; }
  Node *parent(Node *child);
  Node *child(Node *parent) {
    if (parent->left == NULL && parent->right == NULL)
      return nullptr;
    else if (parent->left == NULL)
      return parent->right;
    else if (parent->right == NULL)
      return parent->left;
    else {
      return parent;
    }
  }
};

void Tree::insert_element(int element) {
  Node *node = new Node;
  node->value = element;
  node->left = node->right = NULL;

  if (root == NULL)
    root = node;
  else {
    Node *ptr = root;
    while (ptr != NULL) {
      if (element < ptr->value) {
        if (ptr->left)
          ptr = ptr->left;
        else {
          ptr->left = node;
          break;
        }
      } else if (element > ptr->value) {
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
    if (ptr->value < element)
      node = ptr->right;
    if (ptr->value > element)
      node = ptr->left;
  }
}

void Tree::insert_node(Node *node) {
  if (root == NULL)
    root = node;
  else {
    Node *ptr = root;
    while (ptr != NULL) {
      if (ptr->value < node->value)
        ptr = ptr->right;
      if (ptr->value > node->value)
        ptr = ptr->left;
      if (ptr->value == node->value) {
        std::cout << "there exist a duplicate." << std::endl;
        return;
      }
    }

    if (ptr->value < node->value)
      ptr->right = node;
    if (ptr->value > node->value)
      ptr->left = node;
  }
  if (node) {
    traverse_inorder(node->left);
    std::cout << node->value << std::endl;
    traverse_inorder(node->right);
  }
}

void Tree::traverse_inorder(Node *node) {
  if (node) {
    traverse_inorder(node->left);
    std::cout << node->value << std::endl;
    traverse_inorder(node->right);
  }
}

void Tree::traverse_inverse(Node *node) {
  if (node) {
    traverse_inverse(node->right);
    std::cout << node->value << std::endl;
    traverse_inverse(node->left);
  }
}

void Tree::traverse_preorder(Node *node) {
  if (node) {
    std::cout << node->value << std::endl;
    traverse_preorder(node->right);
    traverse_preorder(node->left);
  }
}

void Tree::traverse_postorder(Node *node) {
  if (node) {
    traverse_postorder(node->right);
    traverse_postorder(node->left);
    std::cout << node->value << std::endl;
  }
}

bool Tree::find_node(int element) {
  bool flag = false;

  if (root == NULL) {
    //		std::cout<<"the tree is empty."<<std::endl;
    return flag;
  } else {
    Node *ptr = root;
    while (ptr != NULL) {
      if (element < ptr->value)
        ptr = ptr->left;
      if (element > ptr->value)
        ptr = ptr->right;
      if (element == ptr->value) {
        flag = true;
        return flag;
      }
    }
    return flag;
  }
}

Tree::Node *Tree::delete_element(Node *ptr, int element) {
  if (ptr == NULL)
    return ptr;
  else if (element < ptr->value)
    ptr->left = delete_element(ptr->left, element);
  else if (element > ptr->value)
    ptr->right = delete_element(ptr->right, element);
  else {
    // case 1: leaf node
    if (ptr->left == NULL && ptr->right == NULL) {
      delete ptr;
      ptr = NULL;
    }
    // case 2: one child
    else if (ptr->left == NULL) {
      Node *temp = ptr;
      ptr = ptr->right;
      delete temp;
    } else if (ptr->right == NULL) {
      Node *temp = ptr;
      ptr = ptr->left;
      delete temp;
    }
    // case 3: 2 child
    else {
      Node *temp = find_min(ptr->right);
      ptr->value = temp->value;
      ptr->right = delete_element(ptr->right, temp->value);
    }

    return ptr;
  }
}

Tree::Node *Tree::find_min(Node *ptr) {
  // finds min value of right child leftmost
  while (ptr->left != NULL)
    ptr = ptr->left;
  return ptr;
}

Tree::Node *Tree::find_max(Node *ptr) {
  // finds min value of right child leftmost
  while (ptr->right != NULL)
    ptr = ptr->left;
  return ptr;
}

int main() {
  Tree tree;
  tree.insert_element(10);
  tree.insert_element(11);
  tree.insert_element(9);
  tree.insert_element(7);
  tree.insert_element(15);
  tree.insert_element(6);
  tree.insert_element(5);
  tree.show_in_order();

  std::cout << "inverse" << std::endl;
  tree.traverse_inverse(tree._root());
  std::cout << "post order" << std::endl;
  tree.traverse_postorder(tree._root());
  std::cout << "pre-order" << std::endl;
  tree.traverse_preorder(tree._root());

  std::cout << "10 deleted" << std::endl;
  tree.delete_element(tree._root(), 10);
  tree.traverse_inorder(tree._root());
}
