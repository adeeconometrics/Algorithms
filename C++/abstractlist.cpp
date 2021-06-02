#include <iostream>

template <typename T> class Node {
public:
  T data;
  Node<T> *next{nullptr};
  Node(const T &m_data) : data(m_data) {}
  Node() = default;
  ~Node() = default;
};

template <typename T, typename U = Node<T>> class list {
  U *head{nullptr};
  U *tail{nullptr};
  size_t m_size{0};

public:
  list() = default;
  ~list() = default;

  void add(const T &data) {
    U *node = new U(data);
    if (is_empty()) {
      head = node;
      tail = node;
    } else {
      Node<T> *ptr = head;
      while (ptr->next != nullptr) {
        ptr = ptr->next;
      }
      ptr->next = node;
      tail = node;
    }
    m_size += 1;
  }

  void display() const {
    U *ptr = head;
    while (ptr->next != nullptr) {
      std::cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }

  bool is_empty() { return head == nullptr; }

  size_t size() { return m_size; }
};

int main() {
  list<float> l;
  for (size_t i = 0; i < 10; ++i)
    l.add(i);

  l.display();
}