/**
 * @file ConcreteArrayStack.h
 * @author ddamiana
 * @brief Concrete implementation of Array Stack.
 * @version 0.1
 * @date 2021-09-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once
#include "IteratorConcreteArrayStack.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>

class ArrayStack {
public:
  typedef int value_type;
  typedef int *pointer_type;
  typedef int &reference_type;
  typedef size_t size_type;
  typedef ArrayStack_Iterator iterator;
  typedef cArrayStack_Iterator const_iterator;

private:
  pointer_type m_ptr{nullptr};
  size_type m_size{0}, m_idx{0};

public:
  explicit ArrayStack() = delete;
  explicit ArrayStack(size_t i_size);
  explicit ArrayStack(const std::initializer_list<int> &i_list);
  explicit ArrayStack(const ArrayStack &rhs);
  explicit ArrayStack(ArrayStack &&rhs) noexcept;

  ~ArrayStack();

  ArrayStack &operator=(const ArrayStack &rhs);
  ArrayStack &operator=(ArrayStack &&rhs);
  value_type operator[](size_t idx) const;

  void push(int element);
  void pop();
  void clear();
  
  bool is_empty() const;
  bool is_full() const;

  const_iterator cbegin();
  const_iterator cend();
  iterator begin();
  iterator end();

  friend std::ostream &operator<<(std::ostream &ss, const ArrayStack &array);

private:
  void swap(ArrayStack &other) noexcept;
};