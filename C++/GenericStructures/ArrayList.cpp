/**
 * @file ArrayList.cpp
 * @author ddamiana
 * @brief  Randomizeable list
 * @version 0.3 -- with array iterator
 * @date 2021-07-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>

template <typename Node> class ArrayList_Iterator {

public:
  typedef Node value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  ArrayList_Iterator(pointer_type front, size_t size) {
    m_array = new value_type *[size];
    for (size_t i = 0, m_ptr = front; i < size; ++i) {
      m_array[i] = m_ptr;
      m_ptr = m_ptr->next;
    }
  }

  ~ArrayList_Iterator() {
    delete[] m_array;
    m_array = nullptr;
  }

  ArrayList_Iterator &operator++() {
    m_array++;
    return *this;
  }

  ArrayList_Iterator &operator++(int) {
    value_type temp = m_array;
    ++m_array;
    return temp;
  }

  ArrayList_Iterator &operator--() {
    m_array--;
    return *this;
  }

  ArrayList_Iterator &operator--(int) {
    value_type temp = m_array;
    --m_array;
    return temp;
  }

  reference_type operator[](int index) { return *&m_array[index]->value; }

  reference_type operator*() { return *m_array; }

  pointer_type operator->() { return m_array; }

  bool operator==(const ArrayList_Iterator &other) const {
    return m_array == other.m_array;
  }

  bool operator!=(const ArrayList_Iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_array;
  pointer_type m_ptr;
};

template <typename T> class ArrayList {
public:
  typedef ArrayList_Iterator<Node> iterator;

private:
  struct Node {
    Node *next{nullptr};
    T value;

    Node(T i_value) : value(i_value) {}
    Node() = default;
  };
  friend ArrayList_Iterator<Node>;
  Node *m_front{nullptr}, *m_back{nullptr};
  Node **m_array{nullptr};

  size_t m_size{0};
  size_t m_index{0};
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
    for (Node *ptr = m_front; ptr->next != nullptr; ptr = ptr->next) {
      std::cout << ptr->value << " ";
    }
  }

  size_t size() const { return m_size; }
  iterator begin() {
    if (m_captured == false)
      capture();
    return iterator(m_array);
  }

  iterator end() {
    if (m_captured == false)
      capture();
    return iterator(m_array);
  }

  bool is_empty() const { return m_front == nullptr; }
};

int main() {
  ArrayList<int> list;
  for (size_t i = 0; i < 10; ++i)
    list.add(i);
  list.display();
  std::cout << "\n";

  list.capture();
  for (size_t i = 0; i < 10; ++i) {
    if (list[i] % 2 == 0)
      list[i] = 0;
  }
  // for (auto i : list)
  //   std::cout << i << " ";

  list.release();
}