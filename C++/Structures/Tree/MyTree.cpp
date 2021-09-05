// modified tree -- format and implement level-order traversal

#include <iostream>

class Tree {
private:
  struct Node {
    int value;
    Node *left{nullptr};
    Node *right{nullptr};
  };

  Node *m_root{nullptr};

public:
  explicit Tree() = default;
  ~Tree() = default; // is this okay?

  void insert_node(Node *node);
  void insert_element(const int &element);
  void traverse_inorder(Node *node);
  void traverse_inverse(Node *node);
  void traverse_postorder(Node *node);
  void traverse_preorder(Node *node);

  void show_in_order() { Tree::traverse_inorder(m_root); }
  Node *delete_element(Node *ptr, const int &element);
  Node *find_max(Node *ptr);
  Node *find_min(Node *ptr);

  bool find_node(const int &element);
  Node *root() { return m_root; }
  Node *parent(Node *child);
  Node *child(Node *parent) {
    if (parent->left == nullptr && parent->right == nullptr)
      return nullptr;
    else if (parent->left == nullptr)
      return parent->right;
    else if (parent->right == nullptr)
      return parent->left;
    else {
      return parent;
    }
  }
};

void Tree::insert_element(const int &element) {
  Node *node = new Node;
  node->value = element;

  if (m_root == nullptr)
    m_root = node;
  else {
    Node *ptr = m_root;
    while (ptr != nullptr) {
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
      }
      break;
    }
    if (ptr->value < element)
      node = ptr->right;
    if (ptr->value > element)
      node = ptr->left;
  }
}

void Tree::insert_node(Node *node) {
  if (m_root == nullptr)
    m_root = node;
  else {
    Node *ptr = m_root;
    while (ptr != nullptr) {
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

bool Tree::find_node(const int &element) {
  bool flag = false;

  if (m_root == nullptr) {
    //		std::cout<<"the tree is empty."<<std::endl;
    return flag;
  } else {
    Node *ptr = m_root;
    while (ptr != nullptr) {
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

Tree::Node *Tree::delete_element(Node *ptr, const int &element) {
  if (ptr == nullptr)
    return ptr;
  else if (element < ptr->value)
    ptr->left = delete_element(ptr->left, element);
  else if (element > ptr->value)
    ptr->right = delete_element(ptr->right, element);
  else {
    // case 1: leaf node
    if (ptr->left == nullptr && ptr->right == nullptr) {
      delete ptr;
      ptr = nullptr;
    }
    // case 2: one child
    else if (ptr->left == nullptr) {
      Node *temp = ptr;
      ptr = ptr->right;
      delete temp;
    } else if (ptr->right == nullptr) {
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
  while (ptr->left != nullptr)
    ptr = ptr->left;
  return ptr;
}

Tree::Node *Tree::find_max(Node *ptr) {
  // finds min value of right child leftmost
  while (ptr->right != nullptr)
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
  tree.traverse_inverse(tree.root());
  std::cout << "post order" << std::endl;
  tree.traverse_postorder(tree.root());
  std::cout << "pre-order" << std::endl;
  tree.traverse_preorder(tree.root());

  std::cout << "10 deleted" << std::endl;
  tree.delete_element(tree.root(), 10);
  tree.traverse_inorder(tree.root());
}
