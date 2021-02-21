#include <iostream>

template <class T> class Stack {
public:
  Stack(int size) {
    stackArray = new T[size];
    stackSize = size;
    _top = -1;
  }
  ~Stack() { delete[] stackArray; }

  void push(T &data) {
    if (isFull())
      std::cout << "stack is full";
    else {
      stackArray[_top] = data;

      // add
      std::cout << stackArray[_top];
      _top += 1;
    }
  }

  void pop() {
    if (isEmpty())
      std::cout << "stack is empty";
    else {
      T num = stackArray[_top];
      _top -= 1;
    }
  }

  T top() { return stackArray[_top - 1]; }
  T* top_reference() { return stackArray + (_top - 1); }
  bool isFull() {
    if (_top == stackSize - 1)
      return true;
    else
      return false;
  }

  bool isEmpty() {
    if (_top == -1)
      return true;
    else
      return false;
  }

private:
  T *stackArray;
  int stackSize;
  int _top;
};

int main() {
  Stack<int> s(10);
  for (int i = 0; i < 10; i++) {
    s.push(i);
    std::cout << " ";
    //    std::cout << s.top();
  }
  std::cout << "\n";
  for (int i = 0; i < 10; i++) {
    std::cout << *s.top_reference() << " ";
    s.pop();
  }
}
