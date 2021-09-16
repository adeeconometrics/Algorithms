/**
 * @file Array.cpp
 * @author ddamiana
 * @brief Array implementation with move semantics.
 * @version 0.3
 * @date 2021-07-29
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include "Array_Iterator.h"
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
  typedef T value_type; 
  typedef Array_Iterator<Array<T, Size>> iterator;
  typedef cArray_Iterator<Array<T, Size>> const_iterator;

private:
  T *m_ptr{nullptr};
  size_t m_size{Size};

public:
  explicit Array() {
      m_ptr = static_cast<T*>(::operator new(Size * sizeof(T)));
  }

  explicit Array(const Array &other) {
    m_ptr = static_cast<T*>(::operator new(Size * sizeof(T)));
    m_size = other.size();
    std::copy(other.begin(), other.end(), m_ptr);
  }

  explicit Array(Array &&other) noexcept { other.swap(*this); }

  explicit Array(std::initializer_list<T> list) {
    try {
      if (list.size() > m_size)
        throw std::exception();

      m_ptr = static_cast<T*>(::operator new(m_size * sizeof(T)));
      
      size_t i = 0;
      for(auto item: list){
        m_ptr[i] = item;
        ++i;
      }

    } catch (const std::exception &be) {
      std::cerr << be.what() << '\n';
      exit(1);
    }
  }

  Array &operator=(const Array &other) {
    Array copy(other);
    return *this;
  }

  Array &operator=(Array &&other) noexcept {
    other.swap(*this);
    return *this;
  }

  ~Array() {
    if (!is_empty()){
      ::operator delete(m_ptr);
      m_ptr = nullptr;
      m_size = 0;
    }
  }

  T &operator[](size_t idx) const {
    if (idx > m_size)
      throw std::out_of_range("Array index out of bound");
    return m_ptr[idx];
  }

  T &operator[](size_t idx) {
    if (idx > m_size)
      throw std::out_of_range("Array index out of bound");
    return m_ptr[idx];
  }

  void add(const T &element) {
    m_ptr[index] = element;
    index += 1;
  }

  size_t size() noexcept { return m_size; }
  bool is_empty() const noexcept { return m_ptr == nullptr && m_size == 0; }
  void initialize(const T& element) {
    for (size_t i = 0; i < m_size; ++i)
      m_ptr[i] = element;
  }

  iterator begin() noexcept { return iterator(m_ptr); }

  iterator end() noexcept { return iterator(m_ptr + m_size); }

  const_iterator cbegin() const noexcept{ return const_iterator(m_ptr); }

  const_iterator cend() const noexcept{ return const_iterator(m_ptr + m_size); }

private:
  void swap(Array &other) noexcept {
    std::swap(m_ptr, other.m_ptr);
    std::swap(m_size, other.m_size);
  }
};