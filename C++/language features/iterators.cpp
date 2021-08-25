#include <iostream>
#include <list>
#include <string>
// iterators
template <typename type> class iterator {
private:
  pointer_t m_ptr;

public:
  typedef typename type::value_type value_type;
  typedef value_type *pointer_t;
  typedef value_type &reference_t;

public:
  iterator(pointer_t ptr) : m_ptr(ptr) {}

  iterator &operator++() {
    m_ptr++;
    return *this;
  }

  iterator operator++(int) { // why use int here
    iterator iter = *this;
    ++(*this);
    return iter;
  }

  reference_t operator[](int index) { return *(m_ptr + index); }

  pointer_t operator->() { return m_ptr; }

  reference_t operator*() { return *m_ptr; }

  bool operator==(const iterator &other) const { return m_ptr == other.m_ptr; }

  bool operator!=(const iterator &other) const { return !(*this == other); }
};

class List {
private:
  typedef iterator<List> Iterator;

  struct Node {
    std::string title;
    std::string production;
    std::string genre;
    Node *next;
  };

  Node *head, *_end;
  int count = -1;

public:
  explicit List() {
    head = NULL;
    _end = head;
    count += 1;
  }

  void add(std::string _title, std::string _production, std::string _genre) {
    Node *node = new Node;
    node->title = _title;
    node->production = _production;
    node->genre = _genre;

    if (isEmpty()) {
      head = node;
    } else {
      Node *ptr = head;
      while (ptr->next != NULL) {
        ptr = ptr->next;
      }
      ptr->next = node;
      _end = node;
      count += 1;
    }
  }

  void remove(std::string _title) {
    if (isFound(_title)) {
      Node *ptr = head;
      Node *temp;
      while (ptr->next != NULL) {
        temp = ptr;
        ptr = ptr->next;
      }
    }
  }

  void display() {
    Node *ptr = head;
    while (ptr != NULL) {
      std::cout << "title : " << ptr->title << std::endl;
      std::cout << "production : " << ptr->production << std::endl;
      std::cout << "genre : " << ptr->genre << std::endl;
      ptr = ptr->next;
    }
  }

  Iterator begin() { return head; }

  Iterator end() { return _end; }

  bool isFound(std::string _title) {
    bool flag = false;
    Node *ptr = head;

    while (ptr->next != NULL) {
      if (ptr->title == _title) {
        flag = true;
        return flag;
      }
    }
    return flag;
  }

  bool isEmpty() {
    if (head == NULL)
      return true;
    return false;
  }
};

int main() {
  List list;
  list.add("the man", "red films", "horror");
  list.add("shake a baby", "shaka-lak", "comedy");
  // std::cout<<list.begin()<<std::endl;
}