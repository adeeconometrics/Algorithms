/**
 * @file Vector_Iterator.h
 * @author ddamiana
 * @brief Contains iterator types for Vector
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once 
#include "Vector.h"

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

template <typename Vector> class cvector_iterator {
public:
  using value_type = typename Vector::value_type;
  typedef value_type *pointer_type;
  typedef value_type &reference_type;

public:
  cvector_iterator(pointer_type ptr) : m_ptr(ptr) {}

  cvector_iterator &operator++() {
    m_ptr++;
    return *this;
  }

  cvector_iterator operator++(int) {
    cvector_iterator iterator = *this;
    ++(*this);
    return iterator;
  }

  cvector_iterator &operator--() {
    m_ptr--;
    return *this;
  }

  cvector_iterator operator--(int) {
    cvector_iterator iterator = *this;
    --(*this);
    return iterator;
  }

  const reference_type operator[](int index) const { return m_ptr[index]; }

  const reference_type operator*() const { return *m_ptr; }

  const pointer_type operator->() const { return m_ptr; }

  bool operator==(const cvector_iterator &other) const {
    return m_ptr == other.m_ptr;
  }

  bool operator!=(const cvector_iterator &other) const {
    return !(*this == other);
  }

private:
  pointer_type m_ptr;
};
