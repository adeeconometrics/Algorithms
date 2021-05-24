// doubly linked list
#include <initializer_list>
#include <iostream>

class List {
private:
  struct Node {
    int data;
    Node *next, *prev;
    Node(int _data) : data{data} {
      next = nullptr;
      prev = nullptr;
    }
  } * head, *back;
  int size;

public:
  explicit List() {
    size = 0;
    head = nullptr;
    back = nullptr;
  }

  ~List() { clear(); }

  void add(const int &data) {
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
    ++size;
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
      return;
    }
  }

  void display() const {
    Node *ptr = head;
    while (ptr->next != nullptr) {
      std::cout << ptr->data << " ";
      ptr = ptr->next;
    }
  }

  void sort() {} // implement quick sort in linked list

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

  int top() { return head->data; }
  int bottom() { return back->data; }

  bool is_empty() { return head == nullptr && size == 0; }

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

  void swap(const int &a, const int &b);
};

int main() {}