/**
 * @file ArrayQueue_Iterator.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include "ArrayQueue.h"


template <typename T, size_t Size> class ArrayQueue_Iterator {
public:
  typedef typename T::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr ArrayQueue_Iterator(pointer_type ptr) : m_ptr(ptr) {}

  ArrayQueue_Iterator &operator++() {
    m_ptr++;
    return *this;
  }

  ArrayQueue_Iterator operator++(int) {
    ArrayQueue_Iterator iterator = *this;
    ++(*this);
    return iterator;
  }

  ArrayQueue_Iterator &operator--() {
    m_ptr--;
    return *this;
  }

  ArrayQueue_Iterator operator--(int) {
    ArrayQueue_Iterator iterator = *this;
    --(*this);
    return iterator;
  }

  reference_type operator*() { return *m_ptr; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const ArrayQueue_Iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const ArrayQueue_Iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr{nullptr};
};

template <typename T, size_t Size> class cArrayQueue_Iterator {
public:
  typedef typename T::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  explicit cArrayQueue_Iterator(pointer_type ptr) : m_ptr(ptr) {}

  cArrayQueue_Iterator &operator++() {
    m_ptr++;
    return *this;
  }

  cArrayQueue_Iterator operator++(int) {
    cArrayQueue_Iterator iterator = *this;
    ++(*this);
    return iterator;
  }

  cArrayQueue_Iterator &operator--() {
    m_ptr--;
    return *this;
  }

  cArrayQueue_Iterator operator--(int) {
    cArrayQueue_Iterator iterator = *this;
    --(*this);
    return iterator;
  }

  const reference_type operator*() const { return *m_ptr; }

  const pointer_type operator->() const { return m_ptr; }

  bool operator==(const cArrayQueue_Iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const cArrayQueue_Iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr{nullptr};
};