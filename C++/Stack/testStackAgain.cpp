#include <iostream>

using namespace std;

template <class T> class Stack {
  struct Node {
    T data;
    Node *next;
  };

  Node *_top;
  int stackSize;

public:
  Stack() {
    _top = NULL;
    stackSize = 0;
  }

  bool isEmpty() {
    if (_top == NULL)
      return true;
    else
      return false;
  }

  void push(T &value) {
    Node *ptr = new Node();
    ptr->data = value;
    ptr->next = _top;
    _top = ptr;
    ++stackSize;
  }

  void pop() {
    if (isEmpty()) {
      cout << "empty";
    } else {
      Node *ptr = _top;
      _top = _top->next;
      --stackSize;
      delete (ptr);
    }
  }

  T top() { return _top->data; }

  int size() { return stackSize; }

  Node *top_reference() { return _top; }
};

int main() {
  Stack<int> s;
  for (int i = 0; i < 10; i++) {
    s.push(i);
    cout << s.top();
    cout << " ";
  }
  cout << endl;
  for (int i = 0; i < 10; i++) {
    cout << s.top();
    s.pop();
    cout << " ";
  }
}
