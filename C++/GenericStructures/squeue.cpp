#include <initializer_list>
#include <iostream>
#include <stdexcept>

template <typename T> class squeue_iterator {
public:
  typedef typename T::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr squeue_iterator(pointer_type ptr) : m_ptr(ptr) {}

  squeue_iterator &operator++() {
    m_ptr++;
    return *this;
  }

  squeue_iterator operator++(int) {
    squeue_iterator iterator = *this;
    ++(*this);
    return iterator;
  }

  squeue_iterator &operator--() {
    m_ptr--;
    return *this;
  }

  squeue_iterator operator--(int) {
    squeue_iterator iterator = *this;
    --(*this);
    return iterator;
  }

  reference_type operator*() { return *m_ptr; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const squeue_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const squeue_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr{nullptr};
};

template <typename T> class csqueue_iterator {
public:
  typedef typename T::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  explicit csqueue_iterator(pointer_type ptr) : m_ptr(ptr) {}

  csqueue_iterator &operator++() {
    m_ptr++;
    return *this;
  }

  csqueue_iterator operator++(int) {
    csqueue_iterator iterator = *this;
    ++(*this);
    return iterator;
  }

  csqueue_iterator &operator--() {
    m_ptr--;
    return *this;
  }

  csqueue_iterator operator--(int) {
    csqueue_iterator iterator = *this;
    --(*this);
    return iterator;
  }

  const reference_type operator*() const { return *m_ptr; }

  const pointer_type operator->() const { return m_ptr; }

  bool operator==(const csqueue_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const csqueue_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr{nullptr};
};

template <typename T, size_t Size> class SQueue {

public:
  typedef T value_type;
  typedef squeue_iterator<SQueue<T, Size>> iterator;
  typedef csqueue_iterator<SQueue<T, Size>> const_iterator;

private:
  friend squeue_iterator<T>;
  friend csqueue_iterator<T>;

  T *m_ptr{nullptr};
  size_t m_index{0};

public:
  explicit SQueue() {
    m_ptr = new T[Size];
    initialize();
  }

  // explicit SQueue(std::initalizer_list<T> list) {
  // for (size_t i = 0; i < Size; ++i)
  //   m_ptr[i] = 0;
  //   try {
  //     if (list.size() > Size)
  //       throw std::exception;

  //     m_ptr = new T[Size];
  //     for (auto i : list)
  //       enqueue(i);
  //   } catch (const std::exception &e) {
  //     std::cerr << e.what() << '\n';
  //     exit(0);
  //   }
  // }

  ~SQueue() {
    if (!is_empty())
      clear();
  }

  const T &operator[](size_t idx) const {
    try {
      if (idx < 0)
        throw "Error.";

      return m_ptr[idx];
    } catch (const char *str) {
      std::cerr << str << std::endl;
      exit(0);
    }
  }

  void push(const T &element) {
    try {
      if (is_full())
        throw std::length_error();

      if (m_index < Size) {
        m_ptr[m_index] = element;
        ++m_index;
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      exit(0);
    }
  }

  void enqueue(const T &element) {
    try {
      if (is_full())
        throw std::length_error();

      if (m_index < Size) {
        m_ptr[m_index] = element;
        ++m_index;
      }
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      exit(0);
    }
  }

  void dequeue() {
    try {
      if (is_empty())
        throw std::exception();
      m_ptr[m_index - 1] = 0;
      --m_index;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      exit(0);
    }
  }

  void pop() {
    try {
      if (is_empty())
        throw std::exception();
      m_ptr[m_index - 1] = 0;
      --m_index;
    } catch (const std::exception &e) {
      std::cerr << e.what() << '\n';
      exit(0);
    }
  }

  void initialize() {
    for (size_t i = 0; i < Size; ++i)
      m_ptr[i] = 0;
  }

  void display() {
    T *ptr = m_ptr[0];
    for (size_t i = 0; i < Size; ++i)
      std::cout << ptr[i] << '\n';
  }

  void clear() {
    delete[] m_ptr;
    m_ptr = nullptr;
  }

  T top() { return m_ptr[0]; }

  T bottom() { return m_ptr[Size - 1]; }

  iterator begin() { return iterator(m_ptr); }

  iterator end() { return iterator(m_ptr + Size); }

  const_iterator cbegin() { return const_iterator(m_ptr); }

  const_iterator cend() { return const_iterator(m_ptr + Size); }

  bool is_empty() {
    for (size_t i = 0; i < Size; ++i) {
      if (m_ptr[i] != 0)
        return false;
    }
    return true;
  }

  bool is_full() { return m_index == Size; }
};

int main() {
  SQueue<int, 3> s;
  s.push(1);
  s.enqueue(2);
  s.push(3);
  s.pop();
  for (SQueue<int, 3>::iterator it = s.begin(); it != s.end(); ++it)
    std::cout << *it << " ";

  std::cout << "\n";
  std::cout << "top : " << s.top() << '\n';
  std::cout << "bottom : " << s.bottom() << '\n';
}