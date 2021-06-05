#include <initializer_list>
#include <iostream>
#include <stdexcept>

template <typename T> class Node final {
  T data;
  Node *next{nullptr};

  explicit Node() {}
  explicit Node(const T &_data) : data(_data) {}
};

template <typename T> class stack_iterator {
public:
  typedef Node<T> value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr stack_iterator(pointer_type ptr) : m_ptr(ptr) {}

  stack_iterator &operator++() {
    m_ptr = m_ptr->next;
    return *this;
  }

  stack_iterator &operator++(int) {
    stack_iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  reference_type operator*() { return m_ptr->next->data; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const stack_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const stack_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};

template <typename T> class cstack_iterator {
public:
  typedef Node<T> value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr cstack_iterator(pointer_type ptr) : m_ptr(ptr) {}

  cstack_iterator &operator++() {
    m_ptr = m_ptr->next;
    return *this;
  }

  cstack_iterator &operator++(int) {
    cstack_iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  const reference_type operator*() const { return m_ptr->next->data; }

  const pointer_type operator->() const { return m_ptr; }

  bool operator==(const cstack_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const cstack_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};

template <typename T> class Stack {
private:
  friend stack_iterator<T>;
  friend cstack_iterator<T>;

  Node<T> *front{nullptr}, *back{nullptr};
  size_t m_size{0};

public:
  typedef stack_iterator<T> iterator;
  typedef stack_iterator<T> const_iterator;

public:
  explicit Stack(){};

  explicit Stack(std::initializer_list<T> list) {
    for (auto i : list)
      push(i);
  };

  ~Stack() {
    if (!is_empty())
      clear();
  };

  void push(const T &data) {
    Node<T> *node = new Node(data);
    if (is_empty()) {
      front = node;
      back = node;
    } else {
      node->next = front;
      front = node;
    }
    ++m_size;
  }

  void pop() {
    if (is_empty()) {
      throw std::exception();
    } else {
      front = front->next;
      --m_size;
    }
  }

  void clear() {
    Node<T> *ptr = front;
    Node<T> *temp = ptr;
    while (ptr->next != nullptr) {
      temp = ptr;
      delete temp;
      temp = nullptr;
      ptr = ptr->next;
    }

    m_size = 0;
  }

  void display() {
    Node<T> *ptr = front;
    while (ptr->next != nullptr) {
      std::cout << ptr->data << std::endl;
      ptr = ptr->next;
    }
  }

  size_t size() { return m_size; }

  T top() { return front->data; }

  T bottom() { return back->data; }

  iterator begin() { return iterator(front); }

  iterator end() { return iterator(back); }

  const_iterator cbegin() { return const_iterator(front); }

  const_iterator cend() { return const_iterator(back); }

private:
  bool is_empty() { return front == nullptr && back == nullptr; }
};
