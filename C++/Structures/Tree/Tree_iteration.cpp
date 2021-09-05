#include <initializer_list>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <type_traits>

struct Node {
  Node *left{nullptr};
  Node *right{nullptr};
  int data;

  Node(const int &data) : data(data) {}
  Node() = default;
};

// bidirectional iterator
// template <typename T> class tree_iterator {
//   friend class Tree<T>;

// public:
//   typedef Node<T> value_type;
//   typedef value_type *pointer_type;
//   typedef value_type &reference_type;

// public:
//   constexpr tree_iterator(pointer_type ptr) : m_ptr(ptr) {}

//   tree_iterator &operator++(){
//     Node<T> *ptr{nullptr};
//     if(m_ptr == nullptr){
//       // m_ptr =
//     }
//   }
//   tree_iterator &operator++(int);
//   tree_iterator &operator--();
//   tree_iterator &operator--(int);

//   reference_type operator*();
//   pointer_type operator->();
//   pointer_type begin();
//   pointer_type end();

//   bool operator==(const tree_iterator &rhs) const;
//   bool operator!=(const tree_iterator &rhs) const;

// private:
//   pointer_type m_ptr{nullptr};
// };

class Tree {
private:
  Node *m_root{nullptr};
  size_t m_size{0};

public:
  explicit Tree() = default;
  explicit Tree(std::initializer_list<int> list) {
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
    if (node == nullptr)
      return;

    if (node != nullptr) {
      traverse_inorder(node->left);
      std::cout << node->data << " ";
      traverse_inorder(node->right);
    }
  }

  void traverse_preorder(Node *node) {
    if (node == nullptr)
      return;

    std::stack<Node *> n_stack;
    n_stack.push(node);

    Node *ptr = nullptr;
    while (!n_stack.empty()) {
      ptr = n_stack.top();
      n_stack.pop();
      std::cout << ptr->data << " ";

      if (ptr->left) {
        n_stack.push(ptr->left);
      }
      if (ptr->right) {
        n_stack.push(ptr->right);
      }
    }
  }

  void traverse_postorder(Node *node) {
    if (node == nullptr)
      return;

    std::stack<Node *> n_stack;
    std::queue<Node *> n_queue;

    n_stack.push(node);

    Node *ptr = nullptr;

    ptr = n_stack.top();
    n_queue.push(ptr);
    n_stack.pop();
    std::cout << ptr->data << " ";
    while (!n_stack.empty()) {
      if (ptr->left) {
        n_stack.push(ptr->left);
      }
      if (ptr->right) {
        n_stack.push(ptr->right);
      }

      ptr = n_stack.top();
      n_queue.push(ptr);
      n_stack.pop();

      std::cout << n_queue.front()->data << " ";
      n_queue.pop();
    }
  }

  Node *delete_element(Node *ptr, const int &data) {
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
};