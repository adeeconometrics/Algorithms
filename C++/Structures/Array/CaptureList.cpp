/**
 * @file AccessibleList.cpp
 * @author ddamiana
 * @brief An randomizeable interface of List.
 * @version 0.1 - concrete version
 * @date 2021-07-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>

class AccessibleList {
private:
  struct Node {
    Node *next{nullptr};
    int value;

    Node(int i_value) : value(i_value) {}
  };

  Node *m_head{nullptr};
  Node **m_array{nullptr};
  size_t m_index{0};
  size_t m_size{0};

public:
  AccessibleList() noexcept {}
  AccessibleList(size_t size) : m_size(size) {
    // resolve this when size is an initial size
    m_array = new Node *[size];
  }
};