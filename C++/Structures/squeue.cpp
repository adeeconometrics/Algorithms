#include <initializer_list>
#include <iostream>
#include <stdexcept>

template <typename T> class squeue_iterator {};

template <typename T, size_t Size> class SQueue {
private:
  T *m_ptr;
  size_t index;

public:
  explicit SQueue() {
    m_ptr = new T[Size];
    index = 0;
  }

  explicit SQueue(std::initalizer_list<T> list) {
    m_ptr = new T[Size];
    index = 0;
    for (auto i : list) {
      enqueue(i);
      index += 1;
    }
  }

  ~SQueue() {
    if (!is_empty())
      clear();
  }

  void push(const T &element);

  void enqueue(cosnt T &element);

  void add(const T &element);

  void dequeue();

  void pop();

  void display();

  void clear();

  bool is_empty();

  bool is_full();
};