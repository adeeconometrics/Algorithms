#pragma
#include <initialzier_list>
#include <stdexcept>

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

template <typename T> class unique_reference {
  T *m_ptr{nullptr};

public:
  explicit unique_reference() = default;
  explicit unique_reference(const unique_reference<T> &Type) = delete;

  explicit unique_reference(T *Type) : m_ptr(Type) {}
  explicit unique_reference(unique_reference<T> &&other) noexcept {
    other.swap(*this);
  }

  unique_reference &operator=(const unique_reference<T> &other) = delete;
  unique_reference &operator=(unique_reference<T> &&other) noexcept {
    other.swap(*this);
  }

  ~unique_reference() {
    if (m_ptr != nullptr) {
      m_ptr->~T();
      m_ptr = nullptr;
    }
  }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(unique_reference<T> &other) { return other.m_ptr; }

private:
  void swap(unique_reference<T> &other) noexcept {
    std::swap(m_ptr, other.m_ptr);
  }
};

template <typename T, size_t Size> class unique_reference {
  T *m_ptr{new T[Size]};
  size_t m_index{0};

public:
  explicit unique_reference() = default;
  explicit unique_reference(const unique_reference<T, Size> &) = delete;

  explicit unique_reference(const std::initializer_list<T> &list) {
    if (list.size > Size)
      throw new std::invalid_argument("");

    for (const T &it : list) {
      m_ptr[i] = it;
      m_index += 1;
    }
  }

  explicit unique_reference(unique_reference<T, Size> &&other) noexcept {
    other.swap(*this);
  }

  unique_reference<T, Size> &
  operator=(const unique_reference<T, Size> &) = delete;
  unique_reference<T, Size> &
  operator=(unique_reference<T, Size> &&other) noexcept {
    other.swap(*this);
  }

  ~unique_reference() {
    if (m_ptr != nullptr) {
      for (size_t i = 0; i < m_index; ++i)
        m_ptr[i]->~T(); // calls the destructor of T.
      delete[] m_ptr;   // deallocates memory block.
    }
  }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(unique_reference<T> &other) { return other.m_ptr; }

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
  void swap(unique_reference<T, Size> &other) noexcept {
    std::swap(m_size, other.m_size);
    std::swap(m_ptr, other.m_ptr);
  }
};

template <typename T> class shared_reference {
  int m_counter{0};
  T *m_ptr{nullptr};

public:
  explicit shared_reference() = default;
  explicit shared_reference(const shared_reference<T> &other) = delete;

  explicit shared_reference(T *i_ptr)
      : m_counter(m_counter + 1), m_ptr(i_ptr) {}
  explicit shared_reference(shared_reference<T> &&other) noexcept {
    other.swap(*this);
  }

  shared_reference &operator=(shared_reference<T> &&other) noexcept {
    other.swap(*this);
  }
  shared_reference &operator=(const shared_reference<T> &other) = delete;

  shared_reference &operator=(shared_reference<T> other) noexcept {
    m_counter += 1;
    other.m_ptr = m_ptr;
  }

  ~shared_reference() {
    m_counter -= 1;
    if (m_counter == 0) {
      m_ptr->~T();
      m_ptr = nullptr;
    }
  }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(shared_reference<T> &other) { return other.m_ptr; }
  T *get(void) { return this->m_ptr; }

  virtual int count() const { return m_counter; }

private:
  void swap(shared_reference<T> &other) noexcept {
    std::swap(m_ptr, other.m_ptr);
  }
};

template <typename T> class shared_reference<T[]> {
  int m_counter{0};
  size_t m_size;
  T *m_ptr{nullptr};

public:
  explicit shared_reference() = default;
  explicit shared_reference(T *i_ptr, size_t i_size)
      : m_counter(m_counter + 1), m_ptr(i_ptr), m_size(i_size) {}

  explicit shared_reference(const shared_reference<T> &other) = delete;
  explicit shared_reference(shared_reference<T> &&other) noexcept {
    other.swap(*this);
  }

  shared_reference &operator=(shared_reference<T> &&other) noexcept {
    other.swap(*this);
  }
  shared_reference &operator=(const shared_reference<T> &other) = delete;

  shared_reference &operator=(shared_reference<T> other) noexcept {
    m_counter += 1;
    other.m_ptr = m_ptr;
  }

  ~shared_reference() {
    m_counter -= 1;
    if (m_counter == 0) {
      for (size_t i = 0; i < m_size; ++i)
        m_ptr[i]->~T(); // calls the destructor of T.
      delete[] m_ptr;   // deallocates memory block.
    }
  }

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(shared_reference<T> &other) { return other.m_ptr; }
  T &operator[](size_t idx) { return this->m_ptr[idx]; }

  T &get(void) { return *(this->m_ptr); }

private:
  void swap(shared_reference<T[]> &other) noexcept {
    std::swap(m_counter, other.m_counter);
    std::swap(m_ptr, other.m_ptr);
    std::swap(m_size, other.m_size);
  }
};

template <typename T> class weak_reference : public shared_reference<T> {
  T *m_ptr{nullptr};

public:
  explicit weak_reference(shared_reference<T> &i_ptr) : m_ptr(i_ptr.get()) {}

  weak_reference() = delete;
  weak_reference(const T &) = delete;
  weak_reference(T &&) = delete;
  weak_reference &operator=(T &&) = delete;
  weak_reference &operator=(const T &Type) = delete;
  ~weak_reference() { m_ptr = nullptr; };

  T &operator*(void) { return *(this->m_ptr); }
  T *operator->(void) { return this->m_ptr; }
  T &operator&(weak_reference<T> &other) { return other.m_ptr; }

  T *get(void) { return (this->m_ptr); }

  void release(void) noexcept { m_ptr = nullptr; }
  bool is_expired(void) noexcept { return m_ptr == nullptr; }
};