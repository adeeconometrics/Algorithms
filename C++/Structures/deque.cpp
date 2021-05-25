#include <initalizer_list>
#include <iostream>

template <typename Deque> class deque_iterator {
private:
  front_pointer_type m_ptr;

public:
  typedef Deque::front_type front_type;
  typedef front_type *front_pointer_type;
  typedef front_type &front_reference_type;
  typedef Deque::rear_type rear_type;
  typedef rear_type *rear_pointer_type;
  typedef rear_type &rear_reference_type;

public:
  deque_iterator(pointer_type ptr) : m_ptr(ptr) {}
};
template <typename T> class Deque {
public:
  typedef front front_type;
  typedef rear rear_type;
  typedef deque_iterator<Deque<T>> iterator;

private:
  struct Node {
    T data;
    Node *next, *prev;
    Node(const T &_data) : data(_data) {
      prev = nullptr;
      next = nullptr;
    }
  } * front, *rear;
  size_t size;

public:
  explicit Deque() {
    size = 0;
    front = nullptr;
    rear = nullptr;
  }

  explicit Deque(std::initializer_list<T> _list) {
    size = 0;
    front = nullptr;
    rear = nullptr;

    for (auto i : list)
      push_front(i);
  }

  ~Deque() { clear(); }

  void push_front(const T &data);
  void push_back(const T &data);
  void pop_front();
  void pop_back();
  void display();
  void display_reverse();
  void clear();

  iterator begin();
  iterator end();

private:
  bool is_empty();
};

int main() {}