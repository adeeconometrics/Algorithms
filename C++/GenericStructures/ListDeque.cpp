#include <initializer_list>
#include <iostream>

template <typename T> struct Node final {
  T data;
  Node *next{nullptr}, *prev{nullptr};

  explicit Node(){};
  explicit Node(const T &_data) : data(_data) {}
};

template <typename ListDeque> class ListDeque_Iterator {

public:
  typedef Node<T> value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr ListDeque_Iterator(pointer_type ptr) : m_ptr(ptr) {}

  ListDeque_Iterator &operator++() {
    m_ptr = m_ptr->next;
    return *this;
  }

  ListDeque_Iterator &operator++(int) {
    ListDeque_Iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  ListDeque_Iterator &operator--() {
    m_ptr = m_ptr->prev;
    return *this;
  }

  ListDeque_Iterator &operator--(int) {
    ListDeque_Iterator temp = *this;
    m_ptr = m_ptr->prev;
    return temp;
  }

  reference_type operator*() { return m_ptr->next->data; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const ListDeque_Iterator &rhs) { return m_ptr == rhs.m_ptr; }

  bool operator!=(const ListDeque_Iterator &rhs) { return !(*this == rhs); }

private:
  pointer_type m_ptr;
};

template <typename ListDeque> class cListDeque_Iterator {

public:
  typedef Node<T> value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr cListDeque_Iterator(pointer_type ptr) : m_ptr(ptr) {}

  cListDeque_Iterator &operator++() {
    m_ptr = m_ptr->next;
    return *this;
  }

  cListDeque_Iterator &operator++(int) {
    cListDeque_Iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  cListDeque_Iterator &operator--() {
    m_ptr = m_ptr->prev;
    return *this;
  }

  cListDeque_Iterator &operator--(int) {
    cListDeque_Iterator temp = *this;
    m_ptr = m_ptr->prev;
    return temp;
  }

  const reference_type operator*() const { return m_ptr->next->data; }

  const pointer_type operator->() const { return m_ptr; }

  bool operator==(const cListDeque_Iterator &rhs) { return m_ptr == rhs.m_ptr; }

  bool operator!=(const cListDeque_Iterator &rhs) { return !(*this == rhs); }

private:
  pointer_type m_ptr;
};

/**
 * Summary of complexity on ListDeque:
 * - void push_front(const T& data) = O(1)
 * - void push_back(const T& data) = O(1)
 * - void pop_front() = O(1)
 * - void pop_back() = O(1)
 * - void display() = O(n)
 * - void display_reverse() = O(n)
 * - void clear() = O(n)
 * - size_t size() = O(1)
 * - iterator begin() = O(1)
 * - iterator end() = O(1)
 * - const_iterator cbegin() = O(1)
 * - const_iterator cend() = O(1)
 */
template <typename T> class ListDeque {
private:
  friend ListDeque_Iterator<T>;
  friend cListDeque_Iterator<T>;

  Node<T> *front{nullptr}, *back{nullptr};
  size_t m_size{0};

public:
  typedef ListDeque_Iterator<T> iterator;
  typedef cListDeque_Iterator<T> const_iterator;

public:
  explicit ListDeque() {}

  explicit ListDeque(std::initializer_list<T> _list) {
    // stacked
    for (auto i : list)
      push_front(i);
  }

  ~ListDeque() {
    if (!is_empty())
      clear();
  }

  void push_front(const T &data) {
    Node<T> *node = new Node(data);
    if (is_empty()) {
      front = node;
      back = node;
    } else {
      node->next = front;
      node->prev = front->prev;
      front = node;
    }
    ++m_size;
  }

  void push_back(const T &data) {
    Node<T> *node = new Node(data);
    if (is_empty()) {
      front = node;
      back = node;
    } else {
      back->next = node;
      node->prev = back;
      back = node;
    }
    ++m_size;
  }

  void pop_front() {
    try {
      if (is_empty())
        throw std::exception(); // null value exception

      Node<T> *ptr = front;
      front = front->next;

      delete ptr;
      ptr = nullptr;
      --m_size;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      exit(1);
    }
  }

  void pop_back() {
    try {
      if (is_empty())
        throw std::exception();

      Node<T> *ptr = back;
      back = back->prev;
      delete ptr;
      ptr = nullptr;

      --m_size;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      exit(1);
    }
  }

  void display() const {
    Node<T> *ptr = front;
    while (ptr->next != nullptr) {
      std::cout << ptr->data << std::endl;
      ptr = ptr->next;
    }
  }

  void display_reverse() const {
    Node<T> *ptr = back;
    while (ptr->prev != nullptr) {
      ptr = ptr->prev;
      std::cout << ptr->data << std::endl;
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

  size_t size() const { return m_size; }

  iterator begin() { return iterator(front); }

  iterator end() { return iterator(back); }

  const_iterator cbegin() { return const_iterator(begin); }

  const_iterator cend() { return const_iterator(end); }

private:
  bool is_empty() const { return front = nullptr && back == nullptr; }
};

int main() {}