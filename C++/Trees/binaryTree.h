
# pragma once
#include <iostream>

template<typename T>
class Tree {
private:
  struct Node {
    const T &value;
    Node *left;
    Node *right;
  };

  Node *_root;

public:
  explicit Tree() { _root = NULL; }

  void insert_node(Node *node);
  void insert_element(const T &element);
  void traverse_inorder(Node *node);
  void traverse_inverse(Node *node);
  void traverse_postorder(Node *node);
  void traverse_preorder(Node *node);

  void show_in_order() { Tree::traverse_inorder(_root); }
  Node *delete_element(const T &element, Node *ptr);
  Node *find_max(Node *ptr);
  Node *find_min(Node *ptr);

  bool find_node(const T &element);
  Node* root(){
  	return _root;
  }
};

template <typename T>
void Tree<T>::insert_element(const T &element) {
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

template <typename T>
void Tree<T>::insert_node(Node *node) {
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

template <typename T>
void Tree<T>::traverse_inorder(Node *node) {
  if (node) {
    traverse_inorder(node->left);
    std::cout << node->value << std::endl;
    traverse_inorder(node->right);
  }
}

template <typename T>
void Tree<T>::traverse_inverse(Node *node) {
  if (node) {
    traverse_inverse(node->right);
    std::cout << node->value << std::endl;
    traverse_inverse(node->left);
  }
}

template <typename T>
void Tree<T>::traverse_preorder(Node *node) {
  if (node) {
    std::cout << node->value << std::endl;
    traverse_preorder(node->right);
    traverse_preorder(node->left);
  }
}

template <typename T>
void Tree<T>::traverse_postorder(Node *node) {
  if (node) {
    traverse_postorder(node->right);
    traverse_postorder(node->left);
    std::cout << node->value << std::endl;
  }
}

template <typename T>
bool Tree<T>::find_node(const T &element) {
  bool flag = false;

  if (_root == NULL) {
    //		std::cout<<"the tree is empty."<<std::endl;
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

template <typename T>
Tree<T>::Node *Tree<T>::delete_element(const T &element, Node *ptr) {
  if (ptr == NULL)
    return ptr;
  else if (element < ptr->value)
    ptr->left = delete_element(element, ptr->left);
  else if (element > ptr->value)
    ptr->right = delete_element(element, ptr->right);
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
      ptr->right = delete_element(temp->value, ptr->right);
    }
    
    return ptr;
  }
}

template <typename T>
Tree<T>::Node *Tree<T>::find_min(Node *ptr) {
  // finds min value of right child leftmost
  while (ptr->left != NULL) ptr = ptr->left;
  return ptr;
}

template <typename T>
Tree<T>::Node *Tree<T>::find_max(Node *ptr) {
  // finds min value of right child leftmost
  if (ptr == NULL)
    return ptr;
  if (ptr->right != NULL)
    ptr->right = find_min(ptr->right);
  if (ptr->left != NULL)
    ptr->left = find_min(ptr->left);
}
