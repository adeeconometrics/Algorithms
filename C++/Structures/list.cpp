// doubly linked list
#include <initializer_list>
#include <iostream>
#include <list>
template <typename List> class list_iterator {
private:
  pointer_type m_ptr;

public:
  typedef typename List::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  list_iterator(pointer_type ptr) : m_ptr(ptr) {}

  list_iterator &operator++() {
    m_ptr = m_ptr->next;
    return *this;
  }

  list_iterator &operator++(int) {
    list_iterator iterator = *this;
    m_ptr = m_ptr->next;
    return iterator;
  }

  list_iterator &operator--() {
    m_ptr = m_ptr->prev;
    return *this;
  }

  list_iterator &operator--(int) {
    list_iterator iterator = *this;
    m_ptr = m_ptr->prev;
    return iterator;
  }

  reference_type operator*() { return *m_ptr; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const list_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const list_iterator &other) const {
    return !(*this == other);
  }
};
template <typename T> class List {
public:
  typedef head value_type;
  typedef list_iterator<List<T>> iterator;

private:
  struct Node {
    T data;
    Node *next, *prev;
    Node(const T &_data) : data{_data} {
      next = nullptr;
      prev = nullptr;
    }
  } * head, *back;
  size_t m_size;

public:
  explicit List() {
    m_size = 0;
    head = nullptr;
    back = nullptr;
  }

  explicit List(std::initializer_list<T> _list) {
    m_size = 0;
    head = nullptr;
    back = nullptr;

    for (auto i : list)
      add(i);
  }
  // move constructor
  // copy constructor
  // move assignment
  // copy assignment

  ~List() { clear(); }

  void add(const T &data) {
    Node *node = new Node(data);
    if (is_empty())
      head = node;
    else {
      Node *ptr = head;
      while (ptr->next != nullptr)
        ptr = ptr->next;

      ptr->next = node;
      node->prev = ptr;
      back = node;
    }
    ++m_size;
  }

  void remove(const int &data) {
    try {
      if (is_empty())
        throw "Error: list is already empty.";

      if (head->data == data)
        remove_head();
      if (back->data == data)
        remove_back();

      Node *ptr = head;
      Node *prev = ptr;
      while (ptr->next != nullptr) {
        if (ptr->data == data) {
          prev->next = ptr->next;
          ptr->prev = prev;

          delete ptr;
          ptr = nullptr;
          return;
        }
        prev = ptr;
        ptr = ptr->next;
      }
      throw "Error: element not found";

    } catch (const char *error_msg) {
      std::cerr << error_msg << std::endl;
      exit(0);
    }
  }

  void display() const {
    Node *ptr = head;
    while (ptr->next != nullptr) {
      std::cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }

  void clear() {
    if (is_empty())
      return;
    Node *ptr = head;
    Node *temp = ptr;

    while (ptr->next != nullptr) {
      temp = ptr;
      delete temp;
      temp = nullptr;

      ptr = ptr->next;
    }
    delete ptr;
    ptr = nullptr;
  }

  size_t size() { return m_size; }

  T top() { return head->data; }
  T bottom() { return back->data; }

  iterator begin() { return iterator(m_ptr); }
  iterator end() { return iterator(m_ptr + m_size); }

  bool is_empty() { return head == nullptr && m_size == 0; }

private:
  void remove_head() {
    Node *ptr = head;
    head = head->next;

    delete ptr;
    ptr = nullptr;

    return;
  }

  void remove_back() {
    Node *ptr = back;
    back = back->prev;

    delete ptr;
    ptr = nullptr;

    return;
  }
};

int main() {}