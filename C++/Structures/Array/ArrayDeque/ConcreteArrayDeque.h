/**
 * @file ConcreteArrayDeque.h
 * @author ddamiana
 * @brief Concrete implementation of Array.
 * @version 0.1
 * @date 2021-09-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include "IteratorConcreteArrayDeque.h"
#include <initializer_list>
#include <stdexcept>
#include <iostream>

class ArrayDeque {
public:
  typedef int value_type;
  typedef int *pointer_type;
  typedef int &reference_type;
  typedef size_t size_type;

  typedef ArrayDeque_Iterator iterator;
  typedef cArrayDeque_Iterator const_iterator;
  typedef rArrayDeque_Iterator reverse_iterator;
  typedef crArrayDeque_Iterator const_reverse;

private:
  pointer_type m_ptr{nullptr};
  size_type m_size{0}, m_idx{0};

public:
  explicit ArrayDeque() = delete;
  explicit ArrayDeque(size_t i_size);
  explicit ArrayDeque(const std::initializer_list<int> &i_list);
  explicit ArrayDeque(const ArrayDeque &rhs);
  explicit ArrayDeque(ArrayDeque &&rhs) noexcept;

  ~ArrayDeque();

  ArrayDeque &operator=(const ArrayDeque &rhs);
  ArrayDeque &operator=(ArrayDeque &&rhs);
  value_type operator[](size_t idx) const;

  void push_first(int element);
  void push_last(int element);
  void pop_first();
  void pop_last();

  void enqueue(int element);
  void push(int element);
  void deque();
  void pop();
  void clear();

  bool is_empty() const;
  bool is_full() const;

  const_iterator cbegin();
  const_iterator cend();
  iterator begin();
  iterator end();

  friend std::ostream &operator<<(std::ostream &ss, const ArrayDeque &array);

private:
  void swap(ArrayDeque &other) noexcept;
};