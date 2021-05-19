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
  } public : explicit List() {
  }
};

int main() {}