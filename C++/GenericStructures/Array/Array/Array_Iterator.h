/**
 * @file Array_Iterator.h
 * @author ddamiana
 * @brief Contains iterator types for Array
 * @version 0.1
 * @date 2021-09-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include "Array.h"
#include <type_traits>

template <typename Array> class Array_Iterator {

public:
  typedef typename Array::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  Array_Iterator(pointer_type ptr) : m_ptr(ptr) {}

  Array_Iterator &operator++() {
    m_ptr++;
    return *this;
  }

  Array_Iterator operator++(int) {
    Array_Iterator temp = *this;
    ++(*this);
    return temp;
  }

  Array_Iterator &operator--() {
    m_ptr--;
    return *this;
  }

  Array_Iterator operator--(int) {
    Array_Iterator temp = *this;
    --(*this);
    return temp;
  }

  reference_type operator[](int index) { return m_ptr[index]; }

  reference_type operator*() { return *m_ptr; }

  pointer_type operator->() { return m_ptr; }

  bool operator==(const Array_Iterator &other) const noexcept{
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const Array_Iterator &other) const noexcept{
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};

template <typename Array> class cArray_Iterator {

public:
  typedef typename Array::value_type value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  cArray_Iterator(pointer_type ptr) : m_ptr(ptr) {}

  cArray_Iterator &operator++() {
    m_ptr++;
    return *this;
  }

  cArray_Iterator operator++(int) {
    Array_Iterator temp = *this;
    ++(*this);
    return temp;
  }

  cArray_Iterator &operator--() {
    m_ptr--;
    return *this;
  }

  cArray_Iterator operator--(int) {
    cArray_Iterator temp = *this;
    --(*this);
    return temp;
  }

  reference_type operator[](int index) const noexcept { return m_ptr[index]; }

  reference_type operator*() const noexcept { return *m_ptr; }

  pointer_type operator->() const noexcept { return m_ptr; }

  bool operator==(const cArray_Iterator &other) const noexcept{
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const cArray_Iterator &other) const noexcept{
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};