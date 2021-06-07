#include <initializer_list>
#include <iostream>

class ordered_list {
private:
  struct Node {
    Node *next{nullptr};
    int data;
    Node(int arg_data) : data(arg_data) {}
    Node() = default;
  };

  Node *front{nullptr};
  Node *back{nullptr};
  size_t m_size{0};

public:
  explicit ordered_list() = default;
  explicit ordered_list(std::initializer_list<int> _list) {}

  ~ordered_list() {
    if (!is_empty())
      clear();
  }

  void add(int data) {
    Node *node = new Node(data);
    if (is_empty) {
      front = node;
      back = node;
    } else if (data < front->data) {
      add_front(node);
    } else if (data < back->data) {
      add_back(node);
    } else {
      Node *ptr = front;
      while (ptr->next != nullptr) {
        if (ptr->data < data)
          break;
      }
      ptr->next = node;
    }
    m_size += 1;
  }

  void remove(int data) {
    try {
      if (is_empty())
        throw std::exception();

      Node *ptr = front;
      Node *prev = ptr;
      while (ptr->next != nullptr) {
        prev = ptr;
        if (ptr->data == data) {
          prev = ptr->next;
          delete ptr;
          ptr = nullptr;

          m_size -= 1;
          return;
        }
        ptr = ptr->next;
      }

      throw "data not found in the list.";
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      exit(1);
    } catch (const char *str) {
      std::cerr << str << '\n';
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

  void clear() {
    Node *ptr = front;
    Node *prev = ptr;
    while (ptr->next != nullptr) {
      prev = ptr;
      delete prev;
      prev = nullptr;
      ptr = ptr->next;
    }
    m_size = 0;
  }

  bool is_empty() const { return front == nullptr && back == nullptr; }

private:
  void add_back(Node *node) {
    back->next = node;
    back = node;
  }

  void add_front(Node *node) {
    node->next = front;
    front = node;
  }

  // improve these!
  //   void remove_front() {
  //     Node *temp = front;
  //     front = front->next;

  //     delete temp;
  //     temp = nullptr;
  //   }

  //   void remove_back(Node *ptr) {
  //       Node* temp = back;
  //       back = ptr;

  //       delete temp;
  //       temp = nullptr;
  //   }
};