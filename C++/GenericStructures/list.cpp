#include <initializer_list>
#include <iostream>
#include <list>
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

template <typename T> class list_iterator {
public:
  typedef Node<T> value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr list_iterator(pointer_type ptr) : m_ptr(ptr) {}

  list_iterator &operator++() {
    m_ptr = m_ptr->next;
    return *this;
  }

  list_iterator &operator++(int) {
    list_iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  list_iterator &operator--() {
    m_ptr = m_ptr->prev;
    return *this;
  }

  list_iterator &operator--(int) {
    list_iterator temp = *this;
    m_ptr = m_ptr->prev;
    return temp;
  }

  reference_type operator*() { return m_ptr->next->data; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const list_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const list_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};

template <typename T> class clist_iterator {
public:
  typedef Node<T> value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr clist_iterator(pointer_type ptr) : m_ptr(ptr) {}

  clist_iterator &operator++() {
    m_ptr = m_ptr->next;
    return *this;
  }

  clist_iterator &operator++(int) {
    clist_iterator temp = *this;
    m_ptr = m_ptr->next;
    return temp;
  }

  clist_iterator &operator--() {
    m_ptr = m_ptr->prev;
    return *this;
  }

  clist_iterator &operator--(int) {
    clist_iterator temp = *this;
    m_ptr = m_ptr->prev;
    return temp;
  }

  const reference_type operator*() const { return m_ptr->next->data; }

  const pointer_type operator->() const { return m_ptr; }

  bool operator==(const clist_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const clist_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};

/**
 * Summary of complexity on List:
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
template <typename T> class List {
private:
  friend list_iterator<T>;
  friend clist_iterator<T>;

  Node<T> *front{nullptr}, *back{nullptr}, *m_ptr{nullptr};
  size_t m_size{0};

public:
  typedef clist_iterator<T> const_iterator;
  typedef list_iterator<T> iterator;

public:
  explicit List() { front = back = m_ptr = new Node<T>(); }

  explicit List(std::initializer_list<T> _list) {
    for (auto i : _list) {
      add(i);
      m_size += 1;
    }
  }
  // move constructor
  List(List<T> &&other) = delete;
  // copy constructor
  List(const List<T> &other) = delete;
  // move assignment
  List<T> &operator=(List<T> &&other) = delete;
  // copy assignment
  List<T> &operator=(const List<T> &other) = delete;

  ~List() {
    if (!is_empty())
      clear();
  }

  void add(const T &data) {
    Node<T> *node = new Node<T>(data);
    if (is_empty()) {
      front = node;
      m_ptr = node;
    } else {
      node->prev = back;
      back->next = node;
      back = node;
    }
    ++m_size;
  }

  void add_front(const T &data) {
    Node<T> *node = new Node<T>(data);
    front->prev = node;
    node->next = front;
    front = node;

    ++m_size;
  }

  void add_back(const T &data) {
    Node<T> *node = new Node<T>(data);
    back->next = node;
    node->prev = back;
    back = node;

    ++m_size;
  }

  void remove(const T &data) {
    try {
      if (is_empty())
        throw "Error: list is already empty.";

      else if (front->data == data) {
        remove_front();
        return;
      } else if (back->data == data) {
        remove_back();
        return;
      } else {
        Node<T> *ptr = front;
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
    Node<T> *ptr = front;
    while (ptr->next != nullptr) {
      std::cout << ptr->data << " \n";
      ptr = ptr->next;
    }
  }

  void clear() {
    if (is_empty())
      return;
    Node<T> *ptr = front;
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

  const T top() const { return front->data; }

  const T bottom() const { return back->data; }

  iterator begin() { return iterator(front); }

  iterator end() { return iterator(back); }

  const_iterator cbegin() { return const_iterator(front); }

  const_iterator cend() { return const_iterator(back); }

  bool is_empty() const { return front == nullptr && m_size == 0; }

private:
  void remove_front() {
    Node<T> *ptr = front;
    front = front->next;

    delete ptr;
    ptr = nullptr;
    m_size -= 1;
  }

  void remove_back() {
    Node<T> *ptr = back;
    back = back->prev;

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
  List<A> v;
  int x{0};

  for (size_t i = 0; i < 5; i++)
    v.add(A(i + 1, i * 2));

  //   v.display();
  //   std::cout << "top: " << v.top() << std::endl;
  //   std::cout << "bottom: "<< v.bottom() << std::endl;
  for (List<A>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << x << "\n";
    x += 1;
  }

  // std::cout << v.begin() << ", end: " << v.end() << "\n";
  v.display();
}