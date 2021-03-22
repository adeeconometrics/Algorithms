
#pragma once
#include <iostream>
#include <string>
// check if comparable type
template <typename T> class BalancedTree {
private:
  struct Node {
    const T &value;
    int balance_factor;
    int height;
    Node *left;
    Node *right;
  };

  Node *_root;

public:
  explicit BalancedTree() { _root = NULL; }

  void insert_node(Node *node);
  void insert_element(const T &element);

  void traverse_inorder(Node *node);
  void traverse_inverse(Node *node);
  void traverse_postorder(Node *node);
  void traverse_preorder(Node *node);

  void right_rotate(Node *node);
  void left_rotate(Node *node);

  void show_inorder() { BalancedTree::traverse_inorder(_root); }
  void show_preorder() { BalancedTree::traverse_preorder(_root); }
  void show_postorder() { BalancedTree::traverse_postorder(_root); }
  void print_sibling(Node *node) {
    std::cout << "{" << node->left << " , " << node->right << "}";
  }
  void display() { BalancedTree::print_tree(_root, nullptr, false); }

  Node *delete_element(Node *ptr, const T &element);
  Node *find_max(Node *ptr);
  Node *find_min(Node *ptr);
  Node *root() { return _root; }

  bool find_node(const T &element);

  int height(Node *node = _root);
  int balanced_factor(Node *node);
  int depth(Node *node = _root);
  int level(Node *node = _root);
  int path_lenght(Node *terminal_node, Node *initial_node = _root);

private:
  struct Trunk {
    Trunk *prev;
    std::string str;

    Trunk(Trunk *prev, const std::string &str) {
      this->prev = prev;
      this->str = str;
    }
  };

  void show_trunks(Trunk *p) {
    if (p == NULL)
      return;
    show_trunks(p->prev);
    std::cout << p->str;
  }

  void print_tree(Node *node, Trunk *prev, bool is_left) {
    if (node == NULL)
      return;
    std::string prev_str = "    ";
    print_tree(node->right, Trunk, true);

    if (!prev)
      Trunk->str = "———";
    else if (is_left) {
      Trunk->str = ".———";
      prev_str = "   |";
    } else {
      Trunk->str = "`———";
      prev->str = prev_str;
    }

    show_trunks(Trunk);
    cout << node->value << endl;

    if (prev)
      prev->str = prev_str;

    Trunk->str = "   |";

    print_tree(node->left, Trunk, false);
  }
};

template <typename T> void BalancedTree<T>::insert_element(const T &element) {
  Node *node = new Node;
  node->value = element;
  node->left = node->right = NULL;

  if (_root == NULL)
    _root = node;
  else {
    Node *ptr = _root;
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

template <typename T> void BalancedTree<T>::insert_node(Node *node) {
  if (_root == NULL)
    _root = node;
  else {
    Node *ptr = _root;
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

template <typename T> void BalancedTree<T>::traverse_inorder(Node *node) {
  if (node) {
    traverse_inorder(node->left);
    std::cout << node->value << std::endl;
    traverse_inorder(node->right);
  }
}

template <typename T> void BalancedTree<T>::traverse_inverse(Node *node) {
  if (node) {
    traverse_inverse(node->right);
    std::cout << node->value << std::endl;
    traverse_inverse(node->left);
  }
}

template <typename T> void BalancedTree<T>::traverse_preorder(Node *node) {
  if (node) {
    std::cout << node->value << std::endl;
    traverse_preorder(node->right);
    traverse_preorder(node->left);
  }
}

template <typename T> void BalancedTree<T>::traverse_postorder(Node *node) {
  if (node) {
    traverse_postorder(node->right);
    traverse_postorder(node->left);
    std::cout << node->value << std::endl;
  }
}

template <typename T> void BalancedTree<T>::right_rotate(Node *node) {
  if (node) {
    Node *prev = node;
    right_rotate(node->left);
    right_rotate(node->right);
  }
}

template <typename T> void BalancedTree<T>::left_rotate(Node *node) {}

template <typename T>
BalancedTree<T>::Node *BalancedTree<T>::delete_element(Node *ptr,
                                                       const T &element) {
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
    if (ptr->left == NULL) {
      Node *temp = ptr;
      ptr = ptr->right;
      delete temp;
      temp = NULL;
    }
    if (ptr->right == NULL) {
      Node *temp = ptr;
      ptr = ptr->left;
      delete temp;
      temp = NULL;
    }
    // case 3: 2 child
    if (ptr->left != NULL && ptr->right != NULL) {
      Node *temp = find_min(ptr->right);
      ptr->value = temp->value;
      ptr->right = delete_element(ptr->right, temp->value);
    }

    return ptr;
  }
}

template <typename T>
BalancedTree<T>::Node *BalancedTree<T>::find_max(Node *ptr) {
  // finds min value of right child rightmost
  while (ptr->right != NULL)
    ptr = ptr->right;
  return ptr;
}

template <typename T>
BalancedTree<T>::Node *BalancedTree<T>::find_min(Node *ptr) {
  // finds min value of right child leftmost
  while (ptr->left != NULL)
    ptr = ptr->left;
  return ptr;
}

template <typename T> bool BalancedTree<T>::find_node(const T &element) {
  bool flag = false;

  if (_root == NULL) {
    //		std::cout<<"the BalancedTree is empty."<<std::endl;
    return flag;
  } else {
    Node *ptr = _root;
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

template <typename T> int BalancedTree<T>::height(Node *node) {
  int counter;
  if (node) {
    height(node->left);
    height(node->right);
    counter += 1;
  } else
    return counter;
}