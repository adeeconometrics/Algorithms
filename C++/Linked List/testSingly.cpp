// test singly sorting

#include <iostream>

class List {
private:
  struct Node {
    int value;
    struct Node *next;
  };
  Node *head, *front, *back;
  int current_size;

public:
  List() {
    head = NULL;
    front = head;
    back = front;
    current_size = 0;
  }

  ~List() { clear(); }

  void append(int &data) {
    Node *newNode = new Node();
    newNode->value = data;

    if (isEmpty()) {
      head = newNode;
    } else {
      Node *ptr;
      ptr = head;

      while (ptr->next != NULL) {
        ptr = ptr->next;
      }
      ptr->next = newNode;
      current_size += 1;
    }
  }

  void remove(int &data) {
    if (isEmpty())
      std::cout << "list is already empty." << std::endl;

    if (isElement(data)) {
      Node *ptr, *temp, *prev;
      ptr = head;

      if (ptr->next->value == data) {
        removeFront();
        //					temp = ptr;
        //					head = head->next;
        //					delete temp;
      } else {
        while (ptr->next != NULL && ptr->value != data) {
          prev = ptr;
          ptr = ptr->next;
        }
        temp = ptr;
        ptr = ptr->next;
        delete temp;
        prev->next = ptr;
        current_size -= 1;
      }

    } else
      std::cout << data << " is not an element of the list." << std::endl;
  }

  void removeFront() {
    Node *ptr;
    ptr = head;
    front = ptr->next;
    head = ptr->next;
    delete ptr;
  }

  // insertion sort
  void sort() {
    if (isEmpty()) {
      std::cout << "list is empty" << std::endl;
      return;
    }
    Node *i = head;
    Node *j = head;

    while (i->next != NULL) {
      j = i->next;
      while (j->next != NULL) {
        if (i->value > j->value) {
          // swap
          swap(i, j);
        }
        j = j->next;
      }
      i = i->next;
    }
  }

  void display() {
    Node *ptr;
    ptr = head;

    if (isEmpty())
      std::cout << "list is empty." << std::endl;
    else {
      while (ptr->next != NULL) {
        std::cout << ptr->value << " ";
        ptr = ptr->next;
      }
    }
  }

  void clear() {
    Node *ptr, *temp;
    ptr = head;

    while (ptr->next != NULL) {

      temp = ptr;
      ptr = ptr->next;
      delete temp;
      temp = ptr;
    }
    head = NULL;
    current_size = 0;
  }

  int size() { return current_size; }

  bool isElement(int &data) {
    Node *ptr;
    ptr = head;

    while (ptr->next != NULL) {
      if (ptr->value == data)
        return true;
      ptr = ptr->next;
    }
    return false;
  }

  bool isEmpty() {
    if (head == NULL && current_size == 0)
      return true;
    return false;
  }

  void swap(Node *&ref1, Node *&ref2) {
    auto temp = ref1->value;
    ref1->value = ref2->value;
    ref2->value = temp;
  }
};

int main() {
  List list;
  int temp;
  for (int i = 2; i < 10; i++) {
    temp = 10 - i;
    list.append(temp);
  }
  list.append(temp);
  list.append(temp);
  list.display();
  //	list.clear();
  //	temp = 3;
  //	list.removeAll(temp); -- not working properly

  std::cout << "\n";
  list.sort();
  list.display();
  std::cout << "\n";

  //	list.remove(temp);
  temp = 1;
  list.remove(temp);
  list.display();
  std::cout << "\n";
  std::cout << list.size();
}
