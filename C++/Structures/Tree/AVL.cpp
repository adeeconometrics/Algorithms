#include <iostream>

struct Node final {
  Node *left{nullptr};
  Node *right{nullptr};
  size_t height{0};
  int bf{0};

  int data;
  explicit Node(const int &_data) : data(_data) {}
  explicit Node() = default;
};

class AVL {
  Node *m_root{nullptr};
  size_t m_size{0};
  int lh{0}, rh{0};

public:
  AVL() = default;
  ~AVL() = default;

  void add_node(Node *node) {
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

  void add_element(const int &data) {
    Node *node = new Node(data);
    add_node(node);
  }

  void remove_element(const int &data) { remove(m_root, data); }

  void remove_node(Node &node) { remove(m_root, node.data); }

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

  int height(const Node *ptr) const;

  int size() const { return m_size; }

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

  bool has_element(Node *root, const int &value) const {
    if (root == nullptr)
      return false;
    if (root->data < value)
      return has_element(root->left, value);
    if (root->data > value)
      return has_element(root->right, value);

    return true;
  }

  bool is_empty() const { return m_root == nullptr; }

  const Node *root() const { return m_root; }

private:
  Node *remove(Node *ptr, const int &data) {
    if (ptr == nullptr)
      return ptr;
    else if (data < ptr->data)
      ptr->left = remove(ptr->left, data);
    else if (data > ptr->data)
      ptr->right = remove(ptr->right, data);
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
        ptr->right = remove(ptr->right, temp->data);
      }

      update(ptr);
      balance(ptr);
      return ptr;
    }
  }

  Node *left_rotation(Node *A) {
    Node *B = A->right;
    A->left = B->right;
    B->left = A;

    update(A);
    update(B);

    return B;
  }

  Node *right_rotation(Node *A) {
    Node *B = A->left;
    A->left = B->right;
    B->right = A;

    update(A);
    update(B);

    return B;
  }

  Node *left_right_case(Node *node) {
    node->left = left_rotation(node);
    return left_left_case(node);
  }

  Node *left_left_case(Node *node) { right_rotation(node); }

  Node *right_left_case(Node *node) {
    node->right = right_rotation(node);
    return right_right_case(node);
  }

  Node *right_right_case(Node *node) { left_rotation(node); }

  void update(Node *node) {
    lh = -1;
    rh = -1;

    if (node->left == nullptr)
      lh = node->left->height;
    if (node->right == nullptr)
      rh = node->right->height;

    node->height = 1 + max(lh, rh);
    node->bf = rh - lh;
  }

  int max(const int &a, const int &b) {
    if (a < b)
      return b;
    return a;
  }

  Node *balance(Node *node) {
    if (node->bf == -2)
      if (node->left->bf <= 0)
        return left_left_case(node);
      else
        return left_right_case(node);

    else if (node->bf == 2)
      if (node->right->bf >= 0)
        return right_right_case(node);
      else
        return right_left_case(node);

    else
      return node;
  }
};