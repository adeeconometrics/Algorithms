#include <initializer_list>
#include <iostream>
#include <iterator>

class Vector {
private:
  int size;
  int index;
  int *ptr = nullptr;

public:
  explicit Vector(const int &_size) {
    index = 0;
    size = _size;
    ptr = new int[size];
  }

  explicit Vector() {
    index = 0;
    size = 1;
    ptr = new int[size];
  }

  explicit Vector(std::initializer_list<int> list) {
    index = 0;
    size = 1;
    for (auto i : list)
      add(i);
  }

  ~Vector() { clear(); }
  void operator++() { ++index; }

  void operator++(int) { index++; }

  void operator--() { --index; }

  void operator--(int) { index--; }

  int &operator[](int idx) {
    try {
      if (idx < 0)
        throw "Error.";

      if (idx >= size)
        grow();

      return ptr[idx];
    } catch (const char *str) {
      std::cerr << str << std::endl;
      exit(0);
    }
  }

  void add(const int &a) {
    if (index >= size)
      grow();

    ptr[index] = a;
    ++index;
  }

  void clear() {
    delete[] ptr;
    ptr = nullptr;
  }

  void display() const {
    for (int i = 0; i < index; ++i)
      std::cout << "a[" << i << "]: " << ptr[i] << std::endl;
  }

  void peek() const {
    for (int i = 0; i < size; ++i)
      std::cout << "a[" << i << "]: " << ptr[i] << std::endl;
  }

  void grow() {
    int *temp = new int[size * 2];
    for (int i = 0; i < index; ++i)
      temp[i] = ptr[i];

    delete[] ptr;
    ptr = nullptr;
    ptr = temp;
    // temp = nullptr;

    size *= 2;
  }

  void fit() {
    int *temp = new int[index];
    for (int i = 0; i < index; ++i)
      temp[i] = ptr[i];

    delete[] ptr;
    ptr = nullptr;
    ptr = temp;
    temp = nullptr;

    size = index;
  }
  /**
   * todo:
   *  - move semantics
   *  - implementation of initializer list
   *  - copy constructor
   *  - move constructor
   *  - error handling
   *  - templates
   */
};

int main() {
  Vector v;

  for (int i = 0; i < 10; ++i)
    v[i] = i;

  v.peek();
}