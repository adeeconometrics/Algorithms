#include <initializer_list>
#include <iostream>
/**
 * featues to implement
 * - move semantics
 * - emplace feature
 * - proper implementation of destructors
 * - insert method
 */

template <typename T> struct Node final {
  T data;
  Node *next{nullptr}, *prev{nullptr};
  Node(const T &m_data) : data(m_data) {}
  Node() = default;
};

template <typename T> class DoublyList_Iterator {
public:
  typedef Node<T> value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr DoublyList_Iterator(pointer_type ptr) : m_ptr(ptr) {}

  DoublyList_Iterator &operator++() {
    m_ptr = m_ptr->next;
    return *this;
  }

  DoublyList_Iterator &operator++(int) {
    DoublyList_Iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  DoublyList_Iterator &operator--() {
    m_ptr = m_ptr->prev;
    return *this;
  }

  DoublyList_Iterator &operator--(int) {
    DoublyList_Iterator temp = *this;
    m_ptr = m_ptr->prev;
    return temp;
  }

  reference_type operator*() { return m_ptr->next->data; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const DoublyList_Iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const DoublyList_Iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};

template <typename T> class cDoublyList_Iterator {
public:
  typedef Node<T> value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr cDoublyList_Iterator(pointer_type ptr) : m_ptr(ptr) {}

  cDoublyList_Iterator &operator++() {
    m_ptr = m_ptr->next;
    return *this;
  }

  cDoublyList_Iterator &operator++(int) {
    cDoublyList_Iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  cDoublyList_Iterator &operator--() {
    m_ptr = m_ptr->prev;
    return *this;
  }

  cDoublyList_Iterator &operator--(int) {
    cDoublyList_Iterator temp = *this;
    m_ptr = m_ptr->prev;
    return temp;
  }

  const reference_type operator*() const { return m_ptr->next->data; }

  const pointer_type operator->() const { return m_ptr; }

  bool operator==(const cDoublyList_Iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const cDoublyList_Iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};

/**
 * Summary of complexity on DoublyList:
 * - void add(const T& data) = O(1)
 * - void add_front(const T& data) = O(1)
 * - void add_back(const T& data) = O(1)
 * - void remove(const T& data)
 * - void display() = O(n)
 * - void clear() = O(n)
 * - size_t size() = O(1)
 * - T top() = O(1)
 * - T bottom() = O(1)
 * - iterator begin() = O(1)
 * - iterator end() = O(1)
 * - const_iterator cbegin() = O(1)
 * - const_iterator cend() = O(1)
 * - bool is_empty() = O(1)
 */
template <typename T> class DoublyList {
private:
  friend DoublyList_Iterator<T>;
  friend cDoublyList_Iterator<T>;

  Node<T> *front{nullptr}, *m_back{nullptr}, *m_ptr{nullptr};
  size_t m_size{0};

public:
  typedef cDoublyList_Iterator<T> const_iterator;
  typedef DoublyList_Iterator<T> iterator;

public:
  explicit DoublyList() { m_front = m_back = m_ptr = new Node<T>(); }

  explicit DoublyList(std::initializer_list<T> _DoublyList) {
    for (auto i : _DoublyList) {
      add(i);
      m_size += 1;
    }
  }
  // move constructor
  DoublyList(DoublyList<T> &&other) {
    m_size = other.size();
    m_front = other.m_front;
    m_back = other.m_back;
  }
  // copy constructor
  DoublyList(const DoublyList<T> &other) {
    m_size = other.size();
    m_front = other.m_front;
    m_back = other.m_back;
  };
  // move assignment
  DoublyList<T> &operator=(DoublyList<T> &&other) = delete;
  // copy assignment
  DoublyList<T> &operator=(const DoublyList<T> &other) = delete;

  ~DoublyList() {
    if (!is_empty())
      clear();
  }

  void add(const T &data) {
    Node<T> *node = new Node<T>(data);
    if (is_empty()) {
      m_front = node;
      m_ptr = node;
    } else {
      node->prev = m_back;
      m_back->next = node;
      m_back = node;
    }
    ++m_size;
  }

  void add_front(const T &data) {
    Node<T> *node = new Node<T>(data);
    m_front->prev = node;
    node->next = m_front;
    m_front = node;

    ++m_size;
  }

  void add_back(const T &data) {
    Node<T> *node = new Node<T>(data);
    m_back->next = node;
    node->prev = m_back;
    m_back = node;

    ++m_size;
  }

  void remove(const T &data) {
    try {
      if (is_empty())
        throw "Error: DoublyList is already empty.";

      else if (front->data == data) {
        remove_front();
        return;
      } else if (m_back->data == data) {
        remove_back();
        return;
      } else {
        Node<T> *ptr = m_front;
        Node<T> *prev = ptr;
        while (ptr->next != nullptr) {
          if (ptr->data == data) {
            prev->next = ptr->next;
            ptr->prev = prev;

            delete ptr;
            ptr = nullptr;
            m_size -= 1;
            return;
          }
          prev = ptr;
          ptr = ptr->next;
        }
        throw "Error: element not found";
      }

    } catch (const char *error_msg) {
      std::cerr << error_msg << std::endl;
      exit(1);
    }
  }

  void display() const {
    Node<T> *ptr = m_front;
    while (ptr->next != nullptr) {
      std::cout << ptr->data << " \n";
      ptr = ptr->next;
    }
  }

  void clear() {
    if (is_empty())
      return;
    Node<T> *ptr = m_front;
    Node<T> *temp = ptr;

    while (ptr->next != nullptr) {
      temp = ptr;
      delete temp;
      temp = nullptr;

      ptr = ptr->next;
    }
    delete ptr;
    ptr = nullptr;
    m_size = 0;
  }

  size_t size() const { return m_size; }

  const T top() const { return m_front->data; }

  const T bottom() const { return m_back->data; }

  iterator begin() { return iterator(m_front); }

  iterator end() { return iterator(m_back); }

  const_iterator cbegin() { return const_iterator(m_front); }

  const_iterator cend() { return const_iterator(m_back); }

  bool is_empty() const { return m_front == nullptr && m_size == 0; }

private:
  void remove_front() {
    Node<T> *ptr = m_front;
    m_front = m_front->next;

    delete ptr;
    ptr = nullptr;
    m_size -= 1;
  }

  void remove_back() {
    Node<T> *ptr = m_back;
    m_back = m_back->prev;

    delete ptr;
    ptr = nullptr;
    m_size -= 1;
  }
};

class A {
  int a, b;

public:
  A(const int &_a, const int &_b) : a(_a), b(_b) {}

  A() : a(0), b(0) {}

  ~A() {}

  friend std::ostream &operator<<(std::ostream &ss, const A &obj);
};

std::ostream &operator<<(std::ostream &ss, const A &obj) {
  ss << obj.a << ", " << obj.b;
  return ss;
}

int main() {
  DoublyList<A> v;
  int x{0};

  for (size_t i = 0; i < 5; i++)
    v.add(A(i + 1, i * 2));

  //   v.display();
  //   std::cout << "top: " << v.top() << std::endl;
  //   std::cout << "bottom: "<< v.bottom() << std::endl;
  for (DoublyList<A>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << x << "\n";
    x += 1;
  }

  // std::cout << v.begin() << ", end: " << v.end() << "\n";
  v.display();
}