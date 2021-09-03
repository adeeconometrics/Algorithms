/**
 * @file ConcreteArrayQueue.h
 * @author ddamiana
 * @brief Concrete implementation of ArrayQueue.
 * @version 0.1
 * @date 2021-09-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include "IteratorConcreteArrayQueue.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>

class ArrayQueue {
public:
  typedef size_t size_type;
  typedef int value_type;
  typedef int *pointer_type;
  typedef int &reference_type;

  typedef ArrayQueue_Iterator iterator;
  typedef cArrayQueue_Iterator const_iterator;

private:
  pointer_type m_ptr{nullptr};
  size_type m_idx{0};
  size_type m_size{0};

public:
  ArrayQueue() = delete;

  explicit ArrayQueue(size_t i_size) : m_size(i_size) {
    m_ptr = new int[i_size];
  }

  explicit ArrayQueue(const std::initializer_list<int>& i_list) noexcept
      : m_size(i_list.size()) {
    m_ptr = new int[i_list.size()];
    for (const int &it : i_list) {
      enqueue(it);
    }
  }

  explicit ArrayQueue(const ArrayQueue &rhs) {
    m_ptr = new int[rhs.size()];
    m_size = rhs.m_size;
    std::copy(rhs.begin(), rhs.end(), m_ptr);
  }

  explicit ArrayQueue(ArrayQueue &&rhs) noexcept { rhs.swap(*this); }

  ~ArrayQueue() {
    if (!is_empty())
      clear();
  }

  ArrayQueue &operator=(const ArrayQueue &rhs){
    m_ptr = new int[rhs.size()];
    m_size = rhs.m_size;
    std::copy(rhs.begin(), rhs.end(), m_ptr);
  }

  ArrayQueue &operator=(ArrayQueue &&rhs) noexcept {
    rhs.swap(*this);
    return *this;
  }

  value_type operator[](size_t idx) const {
    try {
      if (m_size < idx)
        throw std::domain_error("Queue index out of bound.");

      return m_ptr[idx];
    } catch (const std::domain_error &de) {
      std::cerr << de.what() << '\n';
      exit(1);
    }
  }

  void enqueue(int element) {
    try {
      if (is_full())
        throw std::length_error("Queue is already full.");

      if (m_idx < m_size) {
        m_ptr[m_idx] = element;
        ++m_idx;
      }
    } catch (const std::length_error &le) {
      std::cerr << le.what() << '\n';
      exit(1);
    }
  }

  void push(int element) {
    try {
      if (is_full())
        throw std::length_error("Queue is already full.");

      if (m_idx < m_size) {
        m_ptr[m_idx] = element;
        ++m_idx;
      }
    } catch (const std::length_error &le) {
      std::cerr << le.what() << '\n';
      exit(1);
    }
  }

  void dequeue() {
    try {
      if (is_empty())
        throw std::out_of_range("Cannot proceed to request: Out of range.");
      m_ptr[m_idx - 1] = 0;
      --m_idx;
    } catch (const std::out_of_range &ore) {
      std::cerr << ore.what() << '\n';
      exit(1);
    }
  }

  void pop() {
    try {
      if (is_empty())
        throw std::out_of_range("Cannot proceed to request: Out of range.");
      m_ptr[m_idx - 1] = 0;
      --m_idx;
    } catch (const std::out_of_range &ore) {
      std::cerr << ore.what() << '\n';
      exit(1);
    }
  }

  void clear() {
    try {
      if (is_empty())
        throw std::domain_error("Queue is already empty.");
      delete[] m_ptr;
      m_ptr = nullptr;
    } catch (const std::domain_error &de) {
      std::cerr << de.what() << '\n';
      exit(1);
    }
  }

  value_type top() const { return m_ptr[0]; }
  value_type bottom() const { return m_ptr[m_size - 1]; }

  size_type size() const { return m_size; }
  
  bool is_full() const { m_idx == m_size; }
  bool is_empty() const { m_idx == 0 && m_ptr == nullptr; }

  iterator begin() noexcept { return iterator(m_ptr); }
  iterator end() noexcept { return iterator(m_ptr + m_size); }

  friend std::ostream &operator<<(std::ostream &ss, const ArrayQueue &other);

private:
  void swap(ArrayQueue &other) noexcept {
    std::swap(m_ptr, other.m_ptr);
    std::swap(m_size, other.m_size);
    std::swap(m_idx, other.m_idx);
  }
};