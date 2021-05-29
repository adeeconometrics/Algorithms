#include <initializer_list>
#include <iostream>

template <typename Array> class array_iterator {

public:
  typedef typename Array::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  array_iterator(pointer_type ptr) : m_ptr(ptr) {}

  array_iterator &operator++() {
    m_ptr++;
    return *this;
  }

  array_iterator &operator++(int) {
    array_iterator temp = *this;
    ++(*this);
    return temp;
  }

  array_iterator &operator--() {
    m_ptr--;
    return *this;
  }

  array_iterator &operator--(int) {
    array_iterator temp = *this;
    --(*this);
    return temp;
  }

  reference_type operator[](int index) { return m_ptr[index]; }
  reference_type operator*() { return *m_ptr; }
  pointer_type operator->() { return m_ptr; }

  bool operator==(const array_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const array_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};

template <typename T, size_t Size> class Array {
public:
  typedef m_ptr value_type;
  typedef array_iterator<Array<T, Size>> iterator;

private:
  T *m_ptr;
  size_t m_size;
  size_t index;

public:
  explicit Array() {
    try {
      if (Size < 0)
        throw std::bad_alloc();
      m_size = Size;
      m_ptr = nullptr;
      index = 0;
      m_ptr = new T[size];

    } catch (const std::bad_alloc &e) {
      std::cerr << "Allocation failed: " << e.what
                << ". Size must be positive." std::endl;
      exit(0);
    }
  }

  explicit Array(std::initializer_list<T> list) {
    try {
      if (list.size() > Size)
        throw std::bad_alloc();

      m_size = Size;
      m_ptr = nullptr;
      index = 0;
      for (std::list_initalizer<T>::iterator it = list.begin();
           it != list.end(); ++it) {
        add(*it);
        index += 1;
      }

    } catch (const std::bad_alloc &e) {
      std::cerr << "Allocation failed: " << e.what()
                << ". Input size goes beyond array size." << std::endl;
      exit(0);
    }
  }

  ~Array() {
    delete[] m_ptr;
    m_ptr = nullptr;
  }

  Array &operator=(std::initializer_list<T> list) {
    index = 0;
    m_size = list.size();

    for (std::initializer_list<T>::iterator it = list.begin(); it != list.end();
         ++it) {
      add(*it);
      index += 1;
    }
  }

  // copy assingment
  // move assingment

  void operator++() { m_ptr[++index]; }

  void operator++(int) { m_ptr[index++]; }

  void operator--() { m_ptr[--index]; }

  void operator--(int) { m_ptr[index--]; }

  const T &operator[](size_t idx) const {
    try {
      if (idx < 0 || idx < size)
        throw std::exception();

      return m_ptr[idx];
    } catch (const std::exception &e) {
      std::cerr << str << std::endl;
      exit(0);
    }
  }

  T &operator[](size_t idx) {
    try {
      if (idx < 0 || idx < size)
        throw std::exception();

      return m_ptr[idx];
    } catch (const std::exception &e) {
      std::cerr << str << std::endl;
      exit(0);
    }
  }

  void add(const T &element) {
    m_ptr[index] = element;
    index += 1;
  }

  // void remove(const T &element);

  void display() {
    for (size_t i = 0; i < size; ++i)
      std::cout << "a[" << i << "] " << m_ptr[i] << "\n";
  }

  size_t size() { return Size; }

  iterator begin() { return array_iterator(m_ptr); }

  iterator end() { return array_iterator(m_ptr + Size); }

private:
  bool is_empty() { return m_ptr == nullptr && size == 0; }
};