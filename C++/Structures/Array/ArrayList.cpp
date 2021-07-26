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

// ragged matrix
#include <iostream>

class ArrayList {
  struct Node {
    Node *next{nullptr};
    int value;

    Node(int i_value) : value(i_value) {}
    Node() = default;

  } * m_front{nullptr}, *m_back{nullptr};

  size_t m_size{0};
  size_t m_index{0};
  Node **m_array{nullptr};
  bool m_captured{false};

public:
  ArrayList() = default;
  ~ArrayList() { clear(); }

  void add(int value) {
    Node *node = new Node(value);

    if (m_front == nullptr) {
      m_front = node;
      m_back = node;
    } else {
      m_back->next = node;
      m_back = node;
    }
    m_size += 1;
  }

  void remove(int value) {
    try {
      if (is_empty())
        throw std::exception();

      Node *ptr{nullptr};
      if (m_front->value == value) {
        ptr = m_front;
        m_front = m_front->next;
        delete ptr;
        ptr = nullptr;
        m_size -= 1;
      } else {
        Node *prev{nullptr};
        ptr = m_front;

        while (ptr->next != nullptr) {
          prev = ptr;
          ptr = ptr->next;
          if (ptr->value == value) {
            prev->next = ptr->next;
            delete ptr;
            ptr = nullptr;
            m_size -= 1;
            break;
          }
        }
      }
      std::cerr << "value is not found ";
    } catch (const std::exception &except) {
      std::cerr << "list is already empty.";
      exit(1);
    }
  }

  void clear() {
    if (m_array != nullptr) {
      release();
    }

    Node *ptr{m_front};
    Node *temp{nullptr};

    while (ptr->next != nullptr) {
      temp = ptr;
      delete temp;
      temp = nullptr;
      ptr = ptr->next;
    }
    m_size = 0;
  }

  void capture() {
    m_captured = true;
    m_array = new Node *[m_size];

    Node *ptr = m_front;
    for (size_t i = 0; i < m_size; ++i, ptr = ptr->next) {
      m_array[i] = ptr;
    }
  }

  void release() {
    delete[] m_array;
    m_array = nullptr;
  }

  int &operator[](size_t index) {
    if (m_captured == false) {
      capture();
    }
    return *&m_array[index]->value;
  }

  void display() const {
    Node *ptr = m_front;
    while (ptr->next != nullptr) {
      std::cout << ptr->value << " ";
      ptr = ptr->next;
    }
    std::cout << ptr->value << '\n';
  }

  bool is_empty() const { return m_front == nullptr; }
};

int main() {
  ArrayList list;
  for (size_t i = 0; i < 10; ++i)
    list.add(i);
  list.display();
  std::cout << "\n";

  list.capture();
  for (size_t i = 0; i < 10; ++i) {
    if (list[i] % 2 == 0)
      list[i] = 0;
  }
  list.display();
  list.release();
}