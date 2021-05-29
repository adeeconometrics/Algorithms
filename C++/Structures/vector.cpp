#include <initializer_list>
#include <iostream>
// #include <iterator> // look at const and non const iterator

template <typename Vector> class vector_iterator {
public:
  using value_type = typename Vector::value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  vector_iterator(pointer_type ptr) : m_ptr(ptr) {}

  vector_iterator &operator++() {
    m_ptr++;
    return *this;
  }

  vector_iterator operator++(int) {
    vector_iterator iterator = *this;
    ++(*this);
    return iterator;
  }

  vector_iterator &operator--() {
    m_ptr--;
    return *this;
  }

  vector_iterator operator--(int) {
    vector_iterator iterator = *this;
    --(*this);
    return iterator;
  }

  reference_type operator[](int index) { return m_ptr[index]; }

  reference_type operator*() { return *m_ptr; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const vector_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const vector_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};

template <typename T> class Vector {
public:
  typedef T value_type;
  typedef vector_iterator<Vector<T>> iterator;

private:
  size_t m_size;
  size_t m_index;
  T *m_ptr = nullptr;

public:
  explicit Vector(const size_t &_m_size) {
    if (_m_size)
      throw std::length_error();

    m_index = 0;
    m_size = _m_size;
    m_ptr = new T[m_size];
  }

  explicit Vector() {
    m_index = 0;
    m_size = 1;
    m_ptr = new T[m_size];
  }

  explicit Vector(std::initializer_list<T> list) {
    m_index = 0;
    m_size = 1;
    m_ptr = new T[list.size()];

    for (auto i : list)
      push_back(i);
    m_index += 1;
  }

  ~Vector() {
    clear(); // this will call all of our destructors
    ::operator delete(
        m_ptr, m_size * 2 * sizeof(T)); // this will not call any destructors
  }

  void operator++() { ++m_index; }

  void operator++(int) { m_index++; }

  void operator--() { --m_index; }

  void operator--(int) { m_index--; }

  const T &operator[](size_t idx) const { // only returns elements
    try {
      if (idx < 0)
        throw "Error.";

      if (idx >= m_size)
        grow();

      return m_ptr[idx];
    } catch (const char *str) {
      std::cerr << str << std::endl;
      exit(0);
    }
  }

  T &operator[](size_t idx) { // allows user to modify elements
    try {
      if (idx < 0)
        throw "Error.";

      if (idx >= m_size)
        grow();

      return m_ptr[idx];
    } catch (const char *str) {
      std::cerr << str << std::endl;
      exit(0);
    }
  }

  void push_back(const T &a) {
    if (m_index >= m_size)
      grow();

    m_ptr[m_index] = a;
    ++m_index;
  }

  void push_back(T &&value) {
    if (m_index >= m_size)
      grow();

    m_ptr[m_index] = std::move(value);
    ++m_index;
  }

  void pop_back() {
    if (m_size > 0) {
      m_ptr[m_size].~T(); // can we do this for primitives? -- this still works
                          // with primities
      m_size -= 1;
    }
  }

  template <typename... Args> T &emplace_back(Args &&...args) {
    if (m_index >= m_size)
      grow();

    new (&m_ptr[size]) T(std::forward<Args>(args)...); // placement new
    return m_ptr[m_size++];
  }

  void clear() {
    for (size_t i = 0; i < m_size; ++i)
      m_ptr[i].~T();

    m_size = 0;
  }

  void display() const {
    for (size_t i = 0; i < m_index; ++i)
      std::cout << "a[" << i << "]: " << m_ptr[i] << std::endl;
  }

  void peek() const {
    for (size_t i = 0; i < m_size; ++i)
      std::cout << "a[" << i << "]: " << m_ptr[i] << std::endl;
  }

  iterator begin() {
    return iterator(m_ptr); // return iterator at a particular offset
  }

  iterator end() { return iterator(m_ptr + m_size); }

  size_t size() { return m_size; }

  void fit() {
    size_t t_size = m_size * 2;
    T *temp = (T *)::operator new(t_size * sizeof(T));
    for (size_t i = 0; i < m_index; ++i)
      temp[i] = std::move(m_ptr[i]);

    ::operator delete(m_ptr, t_size * sizeof(T));
    m_ptr = nullptr;
    m_ptr = temp;
    m_size = m_index;
  }

private:
  void grow() {
    size_t t_size = m_size * 2;
    T *temp = (T *)::operator new(t_size * sizeof(T));

    for (size_t i = 0; i < m_index; ++i)
      temp[i] = std::move(m_ptr[i]);

    for (size_t i = 0; i < m_size; ++i)
      m_ptr[i].~T();

    ::operator delete(m_ptr, t_size * sizeof(T));
    m_ptr = nullptr;
    m_ptr = temp;
    m_size = t_size;
  }
};

int main() {
  Vector<size_t> v{1, 2, 3};

  for (size_t i = 0; i < 16; ++i)
    v.push_back(i + 2);

  v.fit();

  for (Vector<size_t>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << "\n";
}