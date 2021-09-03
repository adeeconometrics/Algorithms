/**
 * @file IteratorConcreteArrayStack.h
 * @author ddamiana
 * @brief Contains iterator types for Conrete ArrayStack
 * @version 0.1
 * @date 2021-09-02
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include "ConcreteArrayStack.h"

class ArrayStack_Iterator {
public:
  typedef typename ArrayStack::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr ArrayStack_Iterator(pointer_type ptr) : m_ptr(ptr) {}

  ArrayStack_Iterator &operator++() {
    m_ptr++;
    return *this;
  }

  ArrayStack_Iterator operator++(int) {
    ArrayStack_Iterator iterator = *this;
    ++(*this);
    return iterator;
  }

  reference_type operator*() { return *m_ptr; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const ArrayStack_Iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const ArrayStack_Iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr{nullptr};
};

class cArrayStack_Iterator {
public:
  typedef ArrayStack::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  constexpr cArrayStack_Iterator(pointer_type ptr) : m_ptr(ptr) {}

  cArrayStack_Iterator &operator++() {
    m_ptr++;
    return *this;
  }

  cArrayStack_Iterator operator++(int) {
    cArrayStack_Iterator iterator = *this;
    ++(*this);
    return iterator;
  }

  const reference_type operator*() const { return *m_ptr; }

  const pointer_type operator->() const { return m_ptr; }

  bool operator==(const cArrayStack_Iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const cArrayStack_Iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr{nullptr};
};