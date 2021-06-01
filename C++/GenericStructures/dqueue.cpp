#include <initalizer_list>
#include <iostream>
#include <stdexcept>

template <typename T> class Node final {
public:
  T data;
  Node *next{nullptr};
  explicit Node() {}
  explicit Node(const T &_data) : data(_data) {}
};

template <typename T> class queue_iterator {
private:
  pointer_type m_ptr;

public:
  typedef Queue::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr queue_iterator(pointer_type ptr) : m_ptr(ptr) {}

  queue_iterator &operator++() {
    m_ptr = m_ptr->next;
    return m_ptr;
  }

  queue_iterator operator++(int) {
    queue_iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  reference_type operator*() { return *m_ptr; }

  pointer_type operator->() { return mm_ptr; }

  bool operator==(const queue_iterator &other) { return m_ptr == other.m_ptr; }

  bool operator!=(const queue_iterator &other) {
    return !(m_ptr == other.m_ptr);
  }
};

template <typename T> class cqueue_iterator {
private:
  pointer_type m_ptr;

public:
  typedef Queue::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr cqueue_iterator(pointer_type ptr) : m_ptr(ptr) {}

  cqueue_iterator &operator++() {
    m_ptr = m_ptr->next;
    return m_ptr;
  }

  cqueue_iterator operator++(int) {
    cqueue_iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  const reference_type operator*() const { return *m_ptr; }

  const pointer_type operator->() const { return mm_ptr; }

  bool operator==(const cqueue_iterator &other) { return m_ptr == other.m_ptr; }

  bool operator!=(const cqueue_iterator &other) {
    return !(m_ptr == other.m_ptr);
  }
};

template <typename T> class Queue {
private:
  friend queue_iterator<T>;
  friend cqueue_iterator<T>;

  Node<T> *front{nullptr}, *back{nullptr}, *m_ptr{nullptr};
  size_t m_size{0};

public:
  typedef queue_iterator<T> iterator;
  typedef cqueue_iterator<T> const_iterator;

public:
  explicit Queue() {}

  explicit Queue(std::initializer_list<T> list) {
    for (std::initializer_list<T>::iterator it = list.begin(); it != list.end();
         ++it)
      enqueue(*it);
  }

  ~Queue() {
    if (!is_empty())
      clear();
  }

  void equeue(const T &element) {
    Node *node = new Node(element);
    if (is_empty()) {
      m_ptr = node;
      front = node;
      back = node;
    } else {
      node->next = back;
      back = node;
    }
    m_size += 1;
  }

  void push(const T &element) {
    Node *node = new Node(element);
    if (is_empty()) {
      m_ptr = node;
      front = node;
      back = node;
    } else {
      node->next = back;
      back = node;
    }
    m_size += 1;
  }

  void add(const T &element) {
    Node *node = new Node(element);
    if (is_empty()) {
      m_ptr = node;
      front = node;
      back = node;
    } else {
      node->next = back;
      back = node;
    }
    m_size += 1;
  }

  void pop() {
    try {
      if (is_empty())
        throw std::exception;

      Node *temp = front;
      front = front->next;
      temp = nullptr;

      m_size -= 1;

    } catch (const std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }

  void dequeue() {
    try {
      if (is_empty())
        throw std::exception;

      Node *temp = front;
      front = front->next;
      temp = nullptr;

      m_size -= 1;

    } catch (const std::exception &e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }

  void display() const {
    Node *ptr = front;
    std::cout << "[ ";
    while (ptr->next != nullptr) {
      std::cout << ptr->data << ", ";
      ptr = ptr->next;
    }
    std::cout << "] " << std::endl;
  }

  void clear() {
    Node *ptr = front;
    Node *temp = ptr;

    while (ptr->next != nullptr) {
      temp = ptr;
      delete temp;
      temp = nullptr;
      ptr = ptr->next;
    }

    back = nullptr;
    m_ptr = nullptr;
    m_size = 0;
  }

  size_t size() const { return m_size; }

  T top() const { return front->data; }

  T bottom() const { return back->data; }

  iterator begin() { return queue_iterator(front); }

  iterator end() { return queue_iterator(back); }

  const_iterator cbegin() { return const_iterator(front); }

  const_iterator back() { return const_iterator(back); }

private:
  bool is_empty() const { return front == nullptr && m_size == 0; }
};