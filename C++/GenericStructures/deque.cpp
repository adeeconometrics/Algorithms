#include <initalizer_list>
#include <iostream>

template <typaname T> struct Node final {
  T data;
  Node *next{nullptr}, *prev{nullptr};

  explicit Node(){};
  explicit Node(const T &_data) : data(_data) {}
};

template <typename Deque> class deque_iterator {

public:
  typedef Node<T> value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr deque_iterator(pointer_type ptr) : m_ptr(ptr) {}

  deque_iterator &operator++() {
    m_ptr = m_ptr->next;
    return *this;
  }

  deque_iterator &operator++(int) {
    deque_iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  deque_iterator &operator--() {
    m_ptr = m_ptr->prev;
    return *this;
  }

  deque_iterator &operator--(int) {
    deque_iterator temp = *this;
    m_ptr = m_ptr->prev;
    return temp;
  }

  reference_type operator*() { return m_ptr->next->data; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const deque_iterator &rhs) { return m_ptr == rhs.m_ptr; }

  bool operator!=(const deque_iterator &rhs) { return !(*this == rhs); }

private:
  pointer_type m_ptr;
};

template <typename Deque> class cdeque_iterator {

public:
  typedef Node<T> value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr cdeque_iterator(pointer_type ptr) : m_ptr(ptr) {}

  cdeque_iterator &operator++() {
    m_ptr = m_ptr->next;
    return *this;
  }

  cdeque_iterator &operator++(int) {
    cdeque_iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  cdeque_iterator &operator--() {
    m_ptr = m_ptr->prev;
    return *this;
  }

  cdeque_iterator &operator--(int) {
    cdeque_iterator temp = *this;
    m_ptr = m_ptr->prev;
    return temp;
  }

  const reference_type operator*() const { return m_ptr->next->data; }

  const pointer_type operator->() const { return m_ptr; }

  bool operator==(const cdeque_iterator &rhs) { return m_ptr == rhs.m_ptr; }

  bool operator!=(const cdeque_iterator &rhs) { return !(*this == rhs); }

private:
  pointer_type m_ptr;
};

template <typename T> class Deque {
private:
  friend deque_iterator<T>;
  friend cdeque_iterator<T>;

  Node<T> *front{nullptr}, *back{nullptr};
  size_t m_size{0};

public:
  typedef deque_iterator<T> iterator;
  typedef cdeque_iterator<T> const_iterator;

public:
  explicit Deque() {}

  explicit Deque(std::initializer_list<T> _list) {
    // stacked
    for (auto i : list)
      push_front(i);
  }

  ~Deque() {
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