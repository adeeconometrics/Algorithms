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

// std::enable_if<is_base_of<Comparable>::value>
template <typename T, typename Node = Node<T>> class Tree {
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

  void insert_element(const T &data) {
    Node *node = new Node(data);
    insert_node(node);
  }

  void remove_element(const T &data) {
    if (is_empty())
      return;
    delete_element(m_root, data);
    --m_size;
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

  Node *find_max(const Node *ptr) const {
    while (ptr->right != nullptr)
      ptr = ptr->left;
    return ptr;
  }

  Node *find_min(const Node *ptr) const {
    while (ptr->left != nullptr)
      ptr = ptr->left;
    return ptr;
  }

  T &min(const Node *ptr) const {
    Node *min_val = find_min(ptr);
    return min_val->data;
  }

  T &min(const Node *ptr) const {
    Node *max_val = find_max(ptr);
    return max_val->data;
  }

  const Node *root() const { return m_root; }

  const T &root_val() const { return m_root->data; }

  bool is_element(const int &data) const;

  bool is_empty() const { return m_root == nullptr; }

  size_t size() const { return m_size; }

private:
  Node *delete_element(Node *ptr, const T &data) { // minus m_size
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
  // enable find max, find min values
  // void print_tree
  // const Node* child_of
  // const Node* parent_of
  // size_t height
  // size_t level
  // exceptions
  // iterators
};