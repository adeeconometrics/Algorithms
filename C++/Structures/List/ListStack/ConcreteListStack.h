/**
 * @file ConcreteListStack.h
 * @author ddamiana
 * @brief Concrete implementation of ListStack.
 * @version 0.1
 * @date 2021-09-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once
#include "IteratorConcreteListStack.h"
#include <initializer_list>
#include <iostream>
#include <stdexcept>

class ListStack {
public:
  typedef int value_type;
  typedef int *pointer_type;
  typedef int &reference_type;
  typedef size_t size_type;
  typedef ListStack_Iterator iterator;
  typedef cListStack_Iterator const_iterator;

private:
  pointer_type m_ptr{nullptr};
  size_type m_size{0}, m_idx{0};

public:
  explicit ListStack() = delete;
  explicit ListStack(size_t i_size);
  explicit ListStack(const std::initializer_list<int> &i_list);
  explicit ListStack(const ListStack &rhs);
  explicit ListStack(ListStack &&rhs) noexcept;

  ~ListStack();

  ListStack &operator=(const ListStack &rhs);
  ListStack &operator=(ListStack &&rhs);

  void push(int element);
  void pop();
  void clear();

  value_type top() const;
  value_type bottom() const;
  size_type size() const;

  bool is_empty() const;
  bool is_full() const;

  const_iterator cbegin();
  const_iterator cend();
  iterator begin();
  iterator end();

  friend std::ostream operator<<(std::ostream& ss, const ListStack& ls);

private:
  void swap(ListStack &other) noexcept;
};