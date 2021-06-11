// dlist
#include <iostream>

struct Node final {
  int data;
  Node *next{nullptr};
  Node *prev{nullptr};
  Node(int i_data) : data(i_data) {}
  Node() = default;
};

class List {
  Node *front{nullptr};
  Node *back{nullptr};
  size_t m_size{0};

public:
  List() = default;
  ~List() {
    if (!is_empty())
      clear();
  }

  void add(int data) {
    Node *node = new Node(data);
    if (is_empty()) {
      front = node;
      back = node;
    } else {
      Node *ptr = front;
      while (ptr->next != nullptr)
        ptr = ptr->next;

      ptr->next = node;
      node->prev = ptr;
      back = node;
    }
    m_size += 1;
  }

  void remove(int data) {
    try {
      if (is_empty())
        throw std::exception();

      else if (data == front->data) {
        remove_front();
        return;
      } else if (data == back->data) {
        remove_back();
        return;
      } else {
        Node *ptr = front;
        Node *prev = ptr;
        while (ptr->next != nullptr) {
          if (ptr->data == data) {
            prev->next = ptr->next;
            ptr->next->prev = prev;

            delete ptr;
            ptr = nullptr;

            m_size -= 1;
            return;
          }
          prev = ptr;
          ptr = ptr->next;
        }
        throw std::exception();
      }

    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      exit(1);
    }
  }

  void display() const {
    Node *ptr = front;
    while (ptr->next != nullptr) {
      std::cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }

  void display_reverse() const {
    Node *_back = back;
    while (_back->prev != nullptr) {
      _back = _back->prev;
      std::cout << _back->data << " ";
    }
  }

  void clear() {
    Node *ptr = front;
    while (ptr->next != nullptr) {
    }
  }

  int top() const { return front->data; }

  int bottom() const { return back->prev->data; }

  size_t size() const { return m_size; }

  bool is_empty() const { return front == nullptr && back == nullptr; }

private:
  void remove_back() {
    Node *temp = back;
    back = back->prev;

    delete temp;
    temp = nullptr;
    m_size -= 1;
  }

  void remove_front() {
    Node *temp = front;
    front = front->next;

    delete temp;
    temp = nullptr;
    m_size -= 1;
  }
};

int main() {
  List l;

  for (size_t i = 0; i < 10; ++i)
    l.add(i);

  l.remove(10);

  l.display();
  std::cout << "\nreversed: \n";
  l.display_reverse();
  std::cout << "\ntop: " << l.top() << "\nbottom: " << l.bottom();
}