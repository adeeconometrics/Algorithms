#pragma
/**
 * @file Pointers.h
 * @author ddamiana
 * @brief Simple implementation of smart pointers.
 * @version 0.2
 * @date 2021-08-3
 *
 * @copyright Copyright (c) 2021
 *
 */

template <typename T> class unique_pointer {

public:
  T *m_ptr{nullptr};
  explicit unique_pointer() = default;
  explicit unique_pointer(const unique_pointer<T> &Type) = delete;

  explicit unique_pointer(T *Type) : m_ptr(Type) {}
  explicit unique_pointer(unique_pointer<T> &&other) noexcept {
    other.swap(*this);
  }

  unique_pointer &operator=(const unique_pointer<T> &other) = delete;
  unique_pointer &operator=(unique_pointer<T> &&other) noexcept {
    other.swap(*this);
  }

  ~unique_pointer() {
    m_ptr->~T();
    m_ptr = nullptr;
  }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(unique_pointer<T> &other) { return other.m_ptr; }

private:
  void swap(unique_pointer<T> &other) noexcept {
    std::swap(m_ptr, other.m_ptr);
  }
};

template <typename T> class unique_pointer<T[]> {
  T *m_ptr{nullptr};
  size_t m_size{0};

public:
  explicit unique_pointer() = default;
  explicit unique_pointer(const unique_pointer<T> &other) = delete;

  explicit unique_pointer(T *Type, size_t i_size)
      : m_ptr(Type), m_size(i_size) {}
  explicit unique_pointer(unique_pointer<T> &&other) noexcept {
    other.swap(*this);
  }

  unique_pointer &operator=(const unique_pointer<T> &other) = delete;
  unique_pointer &operator=(unique_pointer<T> &&other) noexcept {
    other.swap(*this);
  }

  ~unique_pointer() {
    if (m_ptr != nullptr) {
      for (size_t i = 0; i < m_size; ++i)
        m_ptr[i]->~T(); // calls the destructor of T.
      delete[] m_ptr;   // deallocates memory block.
    }
  }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(unique_pointer<T> &other) { return other.m_ptr; }

  T &operator[](size_t idx) {
    if (idx > m_size)
      throw new std::invalid_argument("invalid index.");
    return this->m_ptr[idx];
  }

  T &operator[](size_t idx) const {
    if (idx > m_size)
      throw new std::invalid_argument("invalid index.");
    return this->m_ptr[idx];
  }

private:
  void swap(unique_pointer<T> &other) noexcept {
    std::swap(m_size, other.m_size);
    std::swap(m_ptr, other.m_ptr);
  }
};

template <typename T> class shared_pointer {
  int m_counter{0};
  T *m_ptr{nullptr};

public:
  explicit shared_pointer() = default;
  explicit shared_pointer(const shared_pointer<T> &other) = delete;

  explicit shared_pointer(T *i_ptr) : m_counter(m_counter + 1), m_ptr(i_ptr) {}
  explicit shared_pointer(shared_pointer<T> &&other) noexcept {
    other.swap(*this);
  }

  shared_pointer &operator=(shared_pointer<T> &&other) noexcept {
    other.swap(*this);
  }
  shared_pointer &operator=(const shared_pointer<T> &other) = delete;

  shared_pointer &operator=(shared_pointer<T> other) noexcept {
    m_counter += 1;
    other.m_ptr = m_ptr;
  }

  ~shared_pointer() {
    m_counter -= 1;
    if (m_counter == 0) {
      m_ptr->~T();
      m_ptr = nullptr;
    }
  }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(shared_pointer<T> &other) { return other.m_ptr; }
  T *get(void) { return this->m_ptr; }

  virtual int count() const { return m_counter; }

private:
  void swap(shared_pointer<T> &other) noexcept {
    std::swap(m_ptr, other.m_ptr);
  }
};

template <typename T> class shared_pointer<T[]> {
  int m_counter{0};
  size_t m_size;
  T *m_ptr{nullptr};

public:
  explicit shared_pointer() = default;
  explicit shared_pointer(T *i_ptr, size_t i_size)
      : m_counter(m_counter + 1), m_ptr(i_ptr), m_size(i_size) {}

  explicit shared_pointer(const shared_pointer<T> &other) = delete;
  explicit shared_pointer(shared_pointer<T> &&other) noexcept {
    other.swap(*this);
  }

  shared_pointer &operator=(shared_pointer<T> &&other) noexcept {
    other.swap(*this);
  }
  shared_pointer &operator=(const shared_pointer<T> &other) = delete;

  shared_pointer &operator=(shared_pointer<T> other) noexcept {
    m_counter += 1;
    other.m_ptr = m_ptr;
  }

  ~shared_pointer() {
    m_counter -= 1;
    if (m_counter == 0) {
      for (size_t i = 0; i < m_size; ++i)
        m_ptr[i]->~T(); // calls the destructor of T.
      delete[] m_ptr;   // deallocates memory block.
    }
  }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(shared_pointer<T> &other) { return other.m_ptr; }
  T &operator[](size_t idx) { return this->m_ptr[idx]; }

  T &get(void) { return *(this->m_ptr); }

private:
  void swap(shared_pointer<T[]> &other) noexcept {
    std::swap(m_counter, other.m_counter);
    std::swap(m_ptr, other.m_ptr);
    std::swap(m_size, other.m_size);
  }
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

  T *get(void) { return (this->m_ptr); }

  void release(void) noexcept { m_ptr = nullptr; }
  bool is_expired(void) noexcept { return m_ptr == nullptr; }
};