#include <iostream>

class Deque {
private:
  struct Node {
    int data;
    Node *next, *prev;
    Node(const int &_data) {
      data = _data;
      prev = nullptr;
      next = nullptr;
    }
  } * front, *rear;
  int size;

public:
  explicit Deque() {
    size = 0;
    front = nullptr;
    rear = nullptr;
  }
  ~Deque() { clear(); }

  void push_front(const int &data);
  void push_back(const int &data);
  void pop_front();
  void pop_back();
  void display();
  void display_reverse();
  void clear();

private:
  bool is_empty();
};

int main() {}