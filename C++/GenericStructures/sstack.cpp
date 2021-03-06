#include <initializer_list>
#include <iostream>
#include <stdexcept>

template <typename T> class sstack_iterator {
public:
  typedef typename T::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr sstack_iterator(pointer_type ptr) : m_ptr(ptr) {}

  sstack_iterator &operator++() {
    m_ptr++;
    return *this;
  }

  sstack_iterator operator++(int) {
    sstack_iterator iterator = *this;
    ++(*this);
    return iterator;
  }

  reference_type operator*() { return *m_ptr; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const sstack_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const sstack_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr{nullptr};
};

template <typename T> class csstack_iterator {
public:
  typedef typename T::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr csstack_iterator(pointer_type ptr) : m_ptr(ptr) {}

  csstack_iterator &operator++() {
    m_ptr++;
    return *this;
  }

  csstack_iterator operator++(int) {
    sstack_iterator iterator = *this;
    ++(*this);
    return iterator;
  }

  const reference_type operator*() const { return *m_ptr; }

  const pointer_type operator->() const { return m_ptr; }

  bool operator==(const csstack_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const csstack_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr{nullptr};
};

/**
 * Summary of complexity on SStack:
 * - void push(const T& data) = O(1)
 * - void pop() = O(1)
 * - void initialize() = O(n)
 * - void display() = O(n)
 * - void clear() = O(n)
 * - size_t size() = O(1)
 * - T top() = O(1)
 * - T bottom() = O(1)
 * - bool is_full() = O(1)
 * - bool is_empty() = O(1)
 * - iterator begin() = O(1)
 * - iterator end() = O(1)
 * - const_iterator cbegin() = O(1)
 * - const_iterator cend() = O(1)
 */
template <typename T, size_t Size> class SStack {
public:
  typedef T value_type;
  typedef sstack_iterator<SStack<T, Size>> iterator;
  typedef csstack_iterator<SStack<T, Size>> const_iterator;

private:
  friend sstack_iterator<T>;
  friend csstack_iterator<T>;

  T *m_ptr{nullptr};
  size_t m_index{0};

public:
  SStack() {
    try {
      if (Size < 0)
        throw std::bad_alloc;
      initialize();
    } catch (const std::bad_alloc &e) {
      std::cerr << "Allocation failed: " << e.what
                << ". Size must be positive." std::endl;
      exit(1);
    }
  }

  SStack(std::initializer_list<T> list) {
    try {
      if (Size < 0)
        throw std::bad_alloc();
      if (list.size() > Size)
        throw std::bad_alloc();

      m_ptr = new T[Size];

      initialize();

      for (auto i : list)
        push(i);

    } catch (const std::exception &e) {
      std::cerr << e.what << '\n';
      exit(1);
    }
  }

  ~SStack() {
    if (!is_empty())
      clear();
  }

  void push(const T &element) {
    try {
      if (is_full())
        throw std::length_error();

      m_ptr[m_front] = data;
      ++m_front;
    } catch (const std::exception &e) {
      std::cerr << e.what << '\n';
      exit(1);
    }
  }

  void pop() {
    try {
      if (is_empty())
        throw std::bad_exception();

      m_ptr[m_index] = 0;
      m_index -= 1;

    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      exit(1);
    }
  }

  void initialize() {
    for (size_t i = 0; i < Size; ++i)
      m_ptr[i] = 0;
  }

  void display() const {
    T *ptr = m_ptr[0];
    for (size_t i = 0; i < Size; ++i)
      std::cout << ptr[i] << '\n';
  }

  void clear() {
    delete[] m_ptr;
    m_ptr = nullptr;
  }

  T top() const { return m_ptr[m_index]; }

  T bottom() const { return m_ptr[0]; }

  // iterator begin() { return iterator(m_ptr); }

  // iterator end() { return iterator(m_ptr + Size); }

  // const_iterator cbegin() { return const_iterator(m_ptr); }

  // const_iterator cend() { return const_iterator(m_ptr + Size); }

  bool is_full() const { return Size == m_index; }

  bool is_empty() const { return m_ptr == nullptr; }
};