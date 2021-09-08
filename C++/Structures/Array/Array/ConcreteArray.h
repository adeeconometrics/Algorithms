/**
 * @file Array.h
 * @author ddamiana
 * @brief Concrete implementation of an Array
 * @version 0.1
 * @date 2021-09-01
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include "IteratorConcreteArray.h"
#include <array>
#include <initializer_list>
#include <iostream>
#include <stdexcept>

class Array {

public:
  typedef int value_type;
  typedef int *pointer_type;
  typedef int &reference_type;
  typedef size_t size_type;

  typedef Array_Iterator iterator;
  typedef cArray_Iterator const_iterator;

private:
  pointer_type m_ptr = nullptr;
  size_type m_size{0};

public:
  Array() = default;

  Array(size_type size) : m_size(size) { m_ptr = new value_type[size]; }

  Array(const std::initializer_list<int> &i_list) {
    m_size = i_list.size();
    m_ptr = new int[m_size];
    size_t m_idx = 0;

    for (const int &it : i_list) {
      m_ptr[m_idx] = it;
      m_idx += 1;
    }
  }

  Array(const Array &rhs) {
    m_size = rhs.m_size;
    m_ptr = new int[rhs.size()];
    for (size_type i = 0; i < rhs.size(); i++)
      m_ptr[i] = rhs[i];
  }

  Array(Array &&rhs) noexcept { rhs.swap(*this); }

  ~Array() {
    delete[] m_ptr;
    m_ptr = nullptr;
  }

  Array &operator=(const Array &rhs) {
    m_size = rhs.m_size;
    m_ptr = new int[rhs.size()];
    for (size_type i = 0; i < rhs.size(); i++)
      m_ptr[i] = rhs[i];
    return *this;
  }

  Array &operator=(Array &&rhs) noexcept {
    rhs.swap(*this);
    return *this;
  }

  int operator[](size_type idx) const {
    if (idx > m_size)
      throw std::domain_error("Array index is out of bound.");
    return m_ptr[idx];
  }

  int &operator[](size_type idx) {
    if (idx > m_size)
      throw std::domain_error("Array index is out of bound.");
    return m_ptr[idx];
  }

  size_type size() const { return m_size; }
  bool is_empty() const { return m_ptr == nullptr && m_size == 0; }

  void initialize(int element) {
    for (size_t i = 0; i < m_size; ++i)
      m_ptr[i] = element;
  }

  const_iterator cbegin() const noexcept { return const_iterator(m_ptr); }
  const_iterator cend() const noexcept {
    return const_iterator(m_ptr + m_size);
  }
  iterator begin() noexcept { return iterator(m_ptr); }
  iterator end() noexcept { return iterator(m_ptr + m_size); }

  friend std::ostream &operator<<(std::ostream &ss, const Array &array) {
    ss << '[';
    for (size_type i = 0; i < array.size(); ++i)
      ss << array[i] << ' ';
    return ss << ']' << '\n';
  }

private:
  void swap(Array &other) noexcept {
    std::swap(other.m_ptr, m_ptr);
    std::swap(other.m_size, m_size);
  }
};