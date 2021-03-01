// dynamic stack ADT -- build on a linked list
// the dynamic stack will never be full(theoretically), but it is limted by your memory
# pragma once
# define _DYNAMICSTACK_H
# ifndef _DYNAMICSTACK_H
# include <iostream>

template <class T> 
class Stack {
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

# endif