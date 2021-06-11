#include <initializer_list>
#include <iostream>
#include <list>

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

template <typename Array> class carray_iterator {

public:
  typedef typename Array::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  carray_iterator(pointer_type ptr) : m_ptr(ptr) {}

  carray_iterator &operator++() {
    m_ptr++;
    return *this;
  }

  carray_iterator &operator++(int) {
    array_iterator temp = *this;
    ++(*this);
    return temp;
  }

  carray_iterator &operator--() {
    m_ptr--;
    return *this;
  }

  carray_iterator &operator--(int) {
    carray_iterator temp = *this;
    --(*this);
    return temp;
  }

  const reference_type operator[](int index) const { return m_ptr[index]; }

  const reference_type operator*() const { return *m_ptr; }

  const pointer_type operator->() const { return m_ptr; }

  bool operator==(const carray_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const carray_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};

/**
 * Summary of complexity on Array:
 * - void add(const T& element) = O(1)
 * - void initialize() = O(n)
 * - void display() = O(n)
 * - size_t size() = O(1)
 * - iterator begin() = O(1)
 * - iterator end() = O(1)
 * - const_iterator cbegin() = O(1)
 * - const_iterator cend() = O(1)
 */
template <typename T, size_t Size> class Array {
public:
  typedef m_ptr value_type;
  typedef array_iterator<Array<T, Size>> iterator;
  typedef carray_iterator<Array<T, Size>> const_iterator;

private:
  T *m_ptr{nullptr};
  size_t m_size{Size};
  size_t index{0};

public:
  explicit Array() {
    try {
      if (Size < 0)
        throw std::bad_alloc();

      index = 0;
      m_ptr = new T[size];

      initialize();

    } catch (const std::bad_alloc &e) {
      std::cerr << "Allocation failed: " << e.what
                << ". Size must be positive." std::endl;
      exit(1);
    }
  }

  explicit Array(const Array<T> &rhs) {
    m_ptr = new T[rhs.size()];
    m_size = rhs.size();
    std::copy(rhs.begin(), rhs.end(), m_ptr);
  }

  explicit Array(Array &&rhs);

  explicit Array(std::initializer_list<T> list) {
    try {
      if (Size < 0)
        throw std::bad_alloc;

      if (list.size() > Size)
        throw std::bad_alloc();

      initialize();

      for (std::list_initalizer<T>::iterator it = list.begin();
           it != list.end(); ++it)
        add(*it);

    } catch (const std::bad_alloc &e) {
      std::cerr << "Allocation failed: " << e.what()
                << ". Input size goes beyond array size." << std::endl;
      exit(1);
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
         ++it)
      add(*it);
  }

  Array &operator=(const Array &rhs) {
    Array<T> copy(rhs);
    copy.swap(rhs);
    return *this;
  }

  Array &operator=(Array &&rhs);

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
      exit(1);
    }
  }

  T &operator[](size_t idx) {
    try {
      if (idx < 0 || idx < size)
        throw std::exception();

      return m_ptr[idx];
    } catch (const std::exception &e) {
      std::cerr << str << std::endl;
      exit(1);
    }
  }

  void add(const T &element) {
    m_ptr[index] = element;
    index += 1;
  }

  void initialize() {
    // initalize elements to 0
    for (size_t i = 0; i < Size; ++i)
      m_ptr[i] = 0;
  }

  // void remove(const T &element);

  void display() const {
    for (size_t i = 0; i < size; ++i)
      std::cout << "a[" << i << "] " << m_ptr[i] << "\n";
  }

  void swap(Array &array) {
    std::swap(*this, array);
    return;
  }

  size_t size() { return Size; }

  iterator begin() { return array_iterator(m_ptr); }

  iterator end() { return array_iterator(m_ptr + Size); }

  const_iterator cbegin() { return const_iterator(m + ptr); }

  const_iterator cend() { return const_iterator(m + ptr + m_size); }

private:
  bool is_empty() const { return m_ptr == nullptr && size == 0; }
};