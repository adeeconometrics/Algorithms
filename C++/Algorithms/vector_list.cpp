// vector list
#include <initializer_list>
#include <iostream>

class vector_list {
private:
  int size;
  struct Node {
    int *ptr;
    int size;
    Node *prev, *next;

    Node(const int &_size) {
      size = _size;
      ptr = new int[size];
      prev = nullptr;
      next = nullptr;
    }
  } * front, *back;

public:
  explicit vector_list() {
    front = nullptr;
    back = nullptr;
    size = 1;
  }

  explicit vector_list(const int &_size) {
    front = nullptr;
    back = nullptr;
    size = _size;
  }

  explicit vector_list(std::initializer_list<int> list) {
    front = nullptr;
    back = nullptr;
    for (std::initializer_list<int>::iterator it = list.begin();
         it != list.end(); ++it)
      add(*it);
  }
  // copy constructor
  explicit vector_list(const vector_list &other) {}

  // move constructor
  explicit vector_list(vector_list &&other) {}

  int &operator[](int) {}

  void add(const int &data);
  void remove(const int &data);
  void sort();
  void display();
  void clear();

private:
  void grow();
  void shrink();
};
