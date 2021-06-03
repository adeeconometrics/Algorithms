#include <iostream>

struct Node final {
  Node *left{nullptr};
  Node *right{nullptr};
  size_t height{0};
  int data;
  explicit Node(const int &_data) : data(_data) {}
  explicit Node() = default;
};

class AVL {
  Node *m_root{nullptr};
  size_t m_size{0};
  int m_bf{0};

public:
  AVL() {}

  void add(const int &data) {}
  void remove(const int &data);

  int8_t
  height(const Node *ptr) const; // height of node x, H(x) is the number of
                                 // edges between x and the furthest leaf

  // cases:
  // left-left case (left heavy i.e. two left child node) - right rotation
  // left-right case - left rotation (left_child) + right rotation
  // right-right case - left rotation()
  // right-left case - right rotation + left rotation

private:
  void left_rotation();
  void right_rotation();
  int8_t balance_factor(const Node *node); // always either -1, 0, 1
  bool contains(Node *ptr, const int &value);
};