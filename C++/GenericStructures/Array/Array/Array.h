/**
 * @file Array.cpp
 * @author ddamiana
 * @brief Array implementation with move semantics.
 * @version 1.1
 * @date 2021-07-29
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include "ArrayList_Iterator.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>

/**
 * Summary of complexity on Array:
 * - void add(const T& element) = O(1)
 * - void initialize() = O(n)
 * - void display() = O(n)
 * - size_t size() = O(1)
 * - iterator begin() = O(1)
 * - iterator end() = O(1)
 * - const_iterator cbegin() = O(1)
 * - const_iterator cend() = O(1)
 */
template <typename T, size_t Size> class Array {
public:
  typedef m_ptr value_type; // not sure why this is not T.
  typedef Array_Iterator<Array<T, Size>> iterator;
  typedef cArray_Iterator<Array<T, Size>> const_iterator;

private:
  T *m_ptr{nullptr};
  size_t m_size{Size};
  size_t index{0};

public:
  explicit Array() {
    try {
      if (Size < 0)
        throw std::bad_alloc();

      index = 0;
      m_ptr = new T[size];

    } catch (const std::bad_alloc &ba) {
      std::cerr << ba.what() << '\n';
      exit(1);
    }
  }

  explicit Array(const Array<T> &other) {
    m_ptr = new T[other.size()];
    m_size = other.size();
    std::copy(other.begin(), other.end(), m_ptr);
  }

  explicit Array(Array &&other) noexcept { other.swap(*this); }

  explicit Array(std::initializer_list<T> list) {
    try {
      if (Size < 0)
        throw std::bad_alloc;

      if (list.size() > Size)
        throw std::bad_alloc("Allocation failed: Input size went beyond array size.");

      for (const T& i: list)
        add(i);

    } catch (const std::bad_alloc &be) {
      std::cerr << be.what() << '\n';
      exit(1);
    }
  }

  Array &operator=(const Array &other) {
    Array<T> copy(other).swap(other);
    return *this;
  }

  Array &operator=(Array &&other) noexcept {
    other.swap(*this);
    return *this;
  }

  ~Array() {
    if (m_ptr != nullptr){
      for(size_t i = 0; i < m_size; ++i){
        m_ptr[i]->~T();
      }

      delete[] m_ptr;
      m_ptr = nullptr;
    }
  }

  Array &operator=(std::initializer_list<T> list) {
    index = 0;
    m_size = list.size();

    for (const T& i: list)
      add(i);
  }

  // find out a reason for using this 
  void operator++() { m_ptr[++index]; }

  void operator++(int) { m_ptr[index++]; }

  void operator--() { m_ptr[--index]; }

  void operator--(int) { m_ptr[index--]; }

  T operator[](size_t idx) const {
    if (idx < 0 || idx < size)
      throw std::out_of_range("Array index out of bound");
    return m_ptr[idx];
  }

  T &operator[](size_t idx) {
    if (idx < 0 || idx < size)
      throw std::out_of_range("Array index out of bound");

    return m_ptr[idx];
  }

  void add(const T &element) {
    if (idx < 0 || idx < size)
      throw std::out_of_range("Array index out of bound");

    m_ptr[index] = element;
    index += 1;
  }

  void initialize(const T& element) {
    for (size_t i = 0; i < Size; ++i)
      m_ptr[i] = element;
  }
  // test for multidimensional array
  void display() const {
    for (size_t i = 0; i < size; ++i)
      std::cout << "a[" << i << "] " << m_ptr[i] << "\n";
  }

  size_t size() noexcept { return Size; }

  bool is_empty() const noexcept { return m_ptr == nullptr && size == 0; }

  iterator begin() { return Array_Iterator(m_ptr); }

  iterator end() { return Array_Iterator(m_ptr + Size); }

  const_iterator cbegin() { return const_iterator(m_ptr); }

  const_iterator cend() { return const_iterator(m_ptr + m_size); }

private:
  void swap(Array<T> &other) noexcept {
    std::swap(m_ptr, other.m_ptr);
    std::swap(m_size, other.m_size);
    std::swap(index, other.index);
  }
};