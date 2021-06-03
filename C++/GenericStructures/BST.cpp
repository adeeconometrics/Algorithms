#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <type_traits>

template <typename T> class Node final {
public:
  Node *left{nullptr};
  Node *right{nullptr};
  T data;

  Node(const T &data) : data(data) {}
  Node() = default;
  ~Node() = default;
};

template <typename T, Node<T>> class Tree {
private:
  Node *m_root{nullptr};
  size_t m_size{0};

public:
  explicit Tree() = default;
  explicit Tree(std::initializer_list<T> list) {
    for (auto i : list) {
      insert_element(i);
    }
  }

  ~Tree() = default;

  void insert_node(Node *node) {
    if (is_empty())
      m_root = node;
    else {
      Node *ptr = m_root;
      while (ptr != nullptr) {
        if (node->data < ptr->data)
          ptr = ptr->left;
        else if (node->data > ptr->data)
          ptr = ptr->right;
        else
          return;
      }
      if (node->data < ptr->data)
        ptr->left = node;
      if (node->data > ptr->data)
        ptr->right = node;
    }
    ++m_size;
  }

  void insert_element(const int &data) {
    Node *node = new Node(data);
    insert_node(node);
  }

  void traverse_inorder(Node *node) {
    if (node != nullptr) {
      traverse_inorder(node->left);
      std::cout << node->data << " ";
      traverse_inorder(node->right);
    }
  }

  void traverse_preorder(Node *node) {
    if (node != nullptr) {
      std::cout << node->data << " ";
      traverse_preorder(node->left);
      traverse_postorder(node->right);
    }
  }

  void traverse_postorder(Node *node) {
    if (node != nullptr) {
      traverse_postorder(node->left);
      traverse_postorder(node->right);
      std::cout << node->data << " ";
    }
  }

  Node *delete_element(Node *ptr, const int &data) { // minus m_size
    if (ptr == nullptr)
      return ptr;
    else if (data < ptr->data)
      ptr->left = delete_element(ptr->left, data);
    else if (data > ptr->data)
      ptr->right = delete_element(ptr->right, data);
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
        ptr->data = temp->data;
        ptr->right = delete_element(ptr->right, temp->data);
      }

      return ptr;
    }
  }

  Node *find_max(Node *ptr) const {
    while (ptr->right != nullptr)
      ptr = ptr->left;
    return ptr;
  }

  Node *find_min(Node *ptr) const {
    while (ptr->left != nullptr)
      ptr = ptr->left;
    return ptr;
  }

  const Node *root() const { return m_root; }

  bool find_node(const int &data);

  bool is_empty() const { return m_root == nullptr; }

  size_t size() const { return m_size; }

  // enable find max, find min values
  // count m_size
};