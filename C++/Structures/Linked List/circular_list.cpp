#include <initializer_list>
#include <iostream>
#include <stdexcept>

struct Node final {
  int data;
  Node *next{nullptr};
  Node *prev{nullptr};
  Node(int i_data) : data(i_data) {}
  Node() = default;
};

class Circular_List {
private:
  Node *m_front{nullptr};
  Node *m_back{nullptr};
  size_t m_size{0};

public:
  Circular_List() = default;
  ~Circular_List() {
    if (!is_empty())
      clear();
  }

  void add(int data) {
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

  void remove(int data) {
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

  int front() const { return m_front->data; }

  int back() const { return m_back->data; }

  size_t size() const { return m_size; }

  bool is_empty() const { return m_front == nullptr; }
};

int main() {
  Circular_List cl;
  for (size_t i = 0; i < 10; ++i)
    cl.add(i);

  cl.display();
  std::cout << "\nreversed: \n";
  cl.display_reverse();
  std::cout << "\nsize: " << cl.size();
  std::cout << "\nfront: " << cl.front() << "\nback: " << cl.back();
  //	size_t a = 0;
  //	std::cout << a;
}