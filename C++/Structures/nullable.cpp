#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T> class nullable final {
public:
  nullable() {}

  nullable(const T &value) : Value(value) {}

  nullable(std::nullptr_t null_pointer) { (void)null_pointer; }

  const nullable<T> &operator=(const nullable<T> &value) {
    NValue.m_has_value = value.NValue.m_has_value;
    value.m_value = value.NValue.m_value;
    return *this;
  }

  const nullable<T> &operator=(const T &value);

  const nullable<T> &operator=(std::nullptr_t null_pointer);

  bool has_value() const { return value.m_has_value; }

  bool try_get_value(T &value) const {
    value = NValue.m_value;
    return NValue.has_value;
  }

  const T &get_value() const { return NValue.m_value; }

  const T &get_value(const T &def) const {
    if (NValue.m_has_value)
      return NValue.m_value;
    return def;
  }

  T *operator->() const;
  const T *operator->() const;
  T &operator*() const;
  const T &operator*() const;

  nullable_value NValue;

public:
  class nullable_value final {
  private:
    nullable_value() : m_has_value(false), m_value(T()) {}

    nullable_value(const T &value) : m_has_value(true), m_value(value) {}

    bool m_has_value;
    T m_value;

    void check_has_value() const {
      if (!m_has_value)
        throw std::runtime_error(
            "nullable object must have a value"); // does not return anything if
                                                  // otherwise, only purpose is
                                                  // to check.
    }

  public:
    friend class nullable;

    nullable_value &
    operator=(const nullable_value &) = delete; // restric copy constructor;

    operator const T &() const {
      check_has_value();
      return m_value;
    }

    const T &operator*() const {
      check_has_value();
      return m_value;
    }

    const T *operator&() const {
      check_has_value();
      return &m_value;
    }

    const T *operator->() const {
      check_has_value();
      return &m_value;
    }

    template <typename E>
    friend bool operator==(const nullable<E> &op1, const nullable<E> &op2) {
      if (op1.value.m_has_value != op1.value.m_has_value)
        return false;
      if (op1.value.m_has_value)
        return op1.value.m_value == op2.value.m_value;

      return true;
    }

    template <typename E>
    friend bool operator==(const E &value, const nullable<E> &op) {
      if (op.value.m_has_value)
        return false;
      return op.value.m_value == value;
    }

    template <typename E>
    friend bool operator==(const nullable<E> &op, const E &value) {
      if (op.value.m_has_value)
        return false;
      return op.value.m_value == value;
    }

    template <typename E>
    friend bool operator==(const nullable<E> &op, std::nullptr_t null_pointer) {
      (void)null_pointer;
      return !op.value.m_has_value;
    }

    template <typename E>
    friend bool operator==(std::nullptr_t null_pointer, const nullable<E> &op) {
      (void)null_pointer;
      return !op.value.m_has_value;
    }

    template <typename E>
    friend bool operator!=(const nullable<E> &op1, const nullable<E> &op2) {
      if (op1.value.m_has_value != op2.value.m_has_value)
        return true;
      if (op1.value.m_has_value)
        return op1.value.m_value != op2.value.m_value;

      return false;
    }

    template <typename E>
    friend bool operator!=(const nullable<E> &op, const E &value) {
      if (!op.value.m_has_value)
        return true;

      return op.value.m_value != value;
    }

    template <typename E>
    friend bool operator!=(const E &value, const nullable<E> &op) {
      if (!op.value.m_has_value)
        return false; // questionable

      return op.value.m_value != value;
    }

    template <typename E>
    friend bool operator!=(const nullable<E> &op, std::nullptr_t null_pointer) {
      (void)null_pointer;
      return op.value.m_has_value;
    }

    template <typename E>
    friend bool operator!=(std::nullptr_t null_pointer, const nullable<E> &op) {
      (void)null_pointer;
      return op.value.m_has_value;
    }
  }
};