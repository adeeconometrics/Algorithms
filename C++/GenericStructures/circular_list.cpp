#include <initializer_list>
#include <iostream>
#include <stdexcept>

template <typename T> struct Node final {
  T data;
  Node<T> *next{nullptr};
  Node<T> *prev{nullptr};
  Node(const T &i_data) : data(i_data) {}
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
  pointer_type m_ptr{nullptr};
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
  pointer_type m_ptr{nullptr};
};

template <typename T> class Circular_List {
private:
  friend list_iterator<T>;
  friend clist_iterator<T>;

  typedef Node<T> Node;

private:
  Node *m_front{nullptr};
  Node *m_back{nullptr};
  size_t m_size{0};

public:
  typedef clist_iterator<T> const_iterator;
  typedef list_iterator<T> iterator;

public:
  Circular_List() = default;
  ~Circular_List() {
    if (!is_empty())
      clear();
  }

  void add(const T &data) {
    Node *node = new Node(data);
    if (is_empty()) {
      m_front = node;
      m_back = node;
    } else {
      node->next = m_front;
      m_front->prev = node;
      m_front = node;
    }
    m_back->next = m_front;
    m_front->prev = m_back;
    m_size += 1;
  }

  void remove(const T &data) {
    try {
      Node *ptr = m_front;
      Node *prev = ptr;

      while (ptr->next != m_back) {
        if (ptr->data == data) {
          prev->next = ptr->next;
          delete ptr;
          ptr = nullptr;

          m_size -= 1;
          return;
        }
        prev = ptr;
        ptr = ptr->next;
      }

    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      exit(1);
    } catch (const char *msg) {
      std::cerr << msg << '\n';
      exit(1);
    }
  }

  void display() const {
    Node *ptr = m_front;
    while (ptr != m_back) {
      std::cout << ptr->data << " ";
      ptr = ptr->next;
    }
    std::cout << m_back->data;
  }

  void display_reverse() const {
    Node *ptr = m_back;
    while (ptr != m_front) {
      std::cout << ptr->data << " ";
      ptr = ptr->prev;
    }
    std::cout << m_front->data;
  }

  void clear() {
    Node *ptr = m_front;
    Node *temp{nullptr};
    while (ptr->next != nullptr) {
      temp = ptr;
      ptr = ptr->next;
      delete temp;
      temp = nullptr;
    }
    m_front = nullptr;
  }

  size_t size() const { return m_size; }

  const T top() const { return m_front->data; }

  const T bottom() const { return m_back->data; }

  iterator begin() { return iterator(front); }

  iterator end() { return iterator(back); }

  const_iterator cbegin() { return const_iterator(front); }

  const_iterator cend() { return const_iterator(back); }

  bool is_empty() const { return m_front == nullptr; }
};

int main() {
  Circular_List<int> cl;
  for (size_t i = 0; i < 10; ++i)
    cl.add(i);
  std::cout << "\nsize: " << cl.size();
  std::cout << "\nfront: " << cl.top() << "\nback: " << cl.bottom();
  //	size_t a = 0;
  //	std::cout << a;
}