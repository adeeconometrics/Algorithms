// sort doubly linked list

#include <iostream>

class List {
private:
  struct Node {
    int value;
    Node *next, *prev;
  };
  Node *head;
  Node *front, *back;
  int current_size;

public:
  List() {
    head = nullptr;
    front = head;
    back = front;
    current_size = 0;
  }

  ~List() { clear(); }

  void clear() {
    Node *ptr, *temp;
    ptr = head;
    // deletes nodes form the head == front
    while (ptr->next != nullptr) {
      temp = ptr;
      ptr = ptr->next;
      delete temp;
    }
  }
  // adds nodes from front
  void append(const int &data) {
    Node *newNode = new Node();
    newNode->value = data;

    if (isEmpty()) {
      head = newNode;
      current_size += 1;
    } else {
      Node *ptr_next, *ptr_prev;
      ptr_next = head;

      while (ptr_next->next != nullptr) {
        ptr_prev = ptr_next;
        ptr_next = ptr_next->next;
      }

      ptr_next->next = newNode;
      newNode->prev = ptr_prev;

      current_size += 1;
      back = newNode;
    }
  }
  // remove specified element if found
  void removeAll(int &data) {
    if (isEmpty()) {
      std::cout << "list is empty.";
    } else {
      bool found = false;

      Node *ptr_next, *ptr_prev;
      ptr_next = head;

      while (ptr_next->next != nullptr) {
        ptr_prev =
            ptr_next; // what about the case where the fist element is found?
        ptr_next = ptr_next->next;

        if (data == ptr_prev->value) {
          // remove element containing the data specified
          Node *temp;
          temp = ptr_next;
          ptr_next = ptr_next->next;

          delete temp;
          ptr_next->prev = ptr_prev;
          ptr_prev->next = ptr_next;
          current_size -= 1;
          found = true;
        }

        try {
          if (!found)
            throw data;
        } catch (int &data) {
          std::cout << data << " is not found";
        }
      }
    }
  }

  //  void sort() { // this seems to not work well
  //    Node *i, *j;
  //    i = head;
  //    for (i = head; i != nullptr; i->next) {
  //      for (j = i->next; j != nullptr; j->next) {
  //        if (i->value > j->value) {
  //          // swap
  //          int temp = i->value;
  //          i->value = j->value;
  //          j->value = temp;
  //          // or swap(i->next, j->next)
  //        }
  //      }
  //    }
  //  }

  void sort() {
    Node *i = head, *j = head;
    while (i->next != nullptr) {
      j = i->next;
      while (j->next != nullptr) {
        if (i->value > j->value) {
          int temp = i->value;
          i->value = i->value;
          j->value = temp;
        }
        j = j->next;
      }
      i = i->next;
    }
  }

  void display() {
    Node *ptr;
    ptr = head;

    while (ptr->next != nullptr) {
      std::cout << ptr->value << std::endl;
      ptr = ptr->next;
    }
  }

  void displayAscending() {
    sort();

    Node *ptr = head;

    while (ptr->next != nullptr) {
      std::cout << ptr->value << std::endl;
      ptr = ptr->next;
    }
  }

  void displayDescending() {
    sort();

    Node *ptr = back;

    while (ptr->prev != nullptr) {
      std::cout << ptr->value << std::endl;
      ptr = ptr->next;
    }
  }

  bool isEmpty() {
    if (head == nullptr && current_size == 0)
      return true;
    return false;
  }
};

int main() {
  List list;
  int temp;
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      temp = i + 3;
      list.append(temp);
    } else {
      list.append(i);
    }
  }
  list.display();

  std::cout << "----------------\n";
  list.sort();
  list.display();
}
