#pragma
/**
 * @file Pointers.h
 * @author ddamiana
 * @brief Simple implementation of smart pointers.
 * @version 0.1
 * @date 2021-08-3
 *
 * @copyright Copyright (c) 2021
 *
 */

template <typename T> class unique_pointer {
  T *m_ptr{nullptr};

public:
  unique_pointer() = default;
  explicit unique_pointer(const T &Type) : m_ptr(Type) {}
  explicit unique_pointer(T *Type) : m_ptr(Type) {}
  unique_pointer(T &&Type) = delete;
  unique_pointer &operator=(const T &Type) = delete;
  unique_pointer &operator=(T &&Type) = delete;
  ~unique_pointer() { delete m_ptr; }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(unique_pointer<T> &other) { return other.m_ptr; }
};

template <typename T> class unique_pointer<T[]> {
  T *m_ptr{nullptr};

public:
  explicit unique_pointer() = default;
  explicit unique_pointer(T *Type) : m_ptr(Type) {}

  unique_pointer(T &&Type) = delete;
  unique_pointer &operator=(const T &Type) = delete;
  unique_pointer &operator=(T &&Type) = delete;
  ~unique_pointer() {
    if (m_ptr != nullptr)
      delete[] m_ptr;
  }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(unique_pointer<T> &other) { return other.m_ptr; }
  T &operator[](size_t idx) { return this->m_ptr[idx]; }
};

template <typename T> class shared_pointer {
  int m_counter{0};
  T *m_ptr{nullptr};

public:
  shared_pointer() = default;
  shared_pointer(T *i_ptr) : m_counter(1), m_ptr(i_ptr) {}

  shared_pointer(const T &) = delete;
  shared_pointer(T &&) = delete;
  shared_pointer &operator=(T &&) = delete;
  shared_pointer &operator=(const T &Type) = delete;

  shared_pointer &operator=(shared_pointer<T> other) noexcept {
    m_counter += 1;
    other.m_ptr = m_ptr;
  }

  ~shared_pointer() {
    if (m_counter == 0)
      delete m_ptr;
    else
      m_counter -= 1;
  }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(shared_pointer<T> &other) { return other.m_ptr; }
  T *get(void) { return this->m_ptr; }

  int virtual count() const { return m_counter; }
};

template <typename T> class shared_pointer<T[]> {
  int m_counter{0};
  T *m_ptr{nullptr};

public:
  shared_pointer() = default;
  shared_pointer(T *i_ptr) : m_counter(1), m_ptr(i_ptr) {}

  shared_pointer(const T &) = delete;
  shared_pointer(T &&) = delete;
  shared_pointer &operator=(T &&) = delete;
  shared_pointer &operator=(const T &Type) = delete;

  shared_pointer &operator=(shared_pointer<T> other) noexcept {
    m_counter += 1;
    other.m_ptr = m_ptr;
  }

  ~shared_pointer() {
    if (m_counter == 0)
      delete[] m_ptr;
    else
      m_counter -= 1;
  }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(shared_pointer<T> &other) { return other.m_ptr; }
  T &operator[](size_t idx) { return this->m_ptr[idx]; }

  T &get(void) { return *(this->m_ptr); }
};

template <typename T> class weak_pointer : public shared_pointer<T> {
  T *m_ptr{nullptr};

public:
  explicit weak_pointer(shared_pointer<T> &i_ptr) : m_ptr(i_ptr.get()) {}

  weak_pointer() = delete;
  weak_pointer(const T &) = delete;
  weak_pointer(T &&) = delete;
  weak_pointer &operator=(T &&) = delete;
  weak_pointer &operator=(const T &Type) = delete;
  ~weak_pointer() { m_ptr = nullptr; };

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(weak_pointer<T> &other) { return other.m_ptr; }

  T &get(void) { return *(this->m_ptr); }

  void release(void) noexcept { m_ptr = nullptr; }
  bool is_expired(void) noexcept { return m_ptr == nullptr; }
};